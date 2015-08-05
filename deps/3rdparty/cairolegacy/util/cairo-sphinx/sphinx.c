#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <sys/un.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>
#include <pthread.h>

#include <cairo.h>
#include <cairo-script.h>
#include <cairo-script-interpreter.h>
#include <cairo-boilerplate.h>

#include <glib.h> /* for checksumming */

#ifndef CAIRO_HAS_REAL_PTHREAD
# error "cairo-sphinx needs real pthreads"
#endif

#define DATA_SIZE (256 << 20)
#define SHM_PATH_XXX "/shmem-cairo-sphinx"

struct client {
    int sk;
    const cairo_boilerplate_target_t *target;
    cairo_surface_t *surface;
    void *base;

    cairo_script_interpreter_t *csi;
    struct context_closure {
	struct context_closure *next;
	unsigned long id;
	cairo_t *context;
	cairo_surface_t *surface;
	cairo_surface_t *original;
    } *contexts;

    unsigned long context_id;
};

struct surface_tag {
    long width, height;
};
static const cairo_user_data_key_t surface_tag;

static int
client_socket (const char *socket_path);

static int
writen (int fd, const void *ptr, int len)
{
#if 1
    const uint8_t *data = ptr;
    while (len) {
	int ret = write (fd, data, len);
	if (ret < 0) {
	    switch (errno) {
	    case EAGAIN:
	    case EINTR:
		continue;
	    default:
		return FALSE;
	    }
	} else if (ret == 0) {
	    return FALSE;
	} else {
	    data += ret;
	    len -= ret;
	}
    }
    return TRUE;
#else
    int ret = send (fd, ptr, len, 0);
    return ret == len;
#endif
}

static int
readn (int fd, void *ptr, int len)
{
#if 0
    uint8_t *data = ptr;
    while (len) {
	int ret = read (fd, data, len);
	if (ret < 0) {
	    switch (errno) {
	    case EAGAIN:
	    case EINTR:
		continue;
	    default:
		return FALSE;
	    }
	} else if (ret == 0) {
	    return FALSE;
	} else {
	    data += ret;
	    len -= ret;
	}
    }
    return TRUE;
#else
    int ret = recv (fd, ptr, len, MSG_WAITALL);
    return ret == len;
#endif
}
static int
open_devnull_to_fd (int want_fd, int flags)
{
    int error;
    int got_fd;

    close (want_fd);

    got_fd = open("/dev/null", flags | O_CREAT, 0700);
    if (got_fd == -1)
        return -1;

    error = dup2 (got_fd, want_fd);
    close (got_fd);

    return error;
}

static int
daemonize (void)
{
    void (*oldhup) (int);

    /* Let the parent go. */
    switch (fork ()) {
    case -1: return -1;
    case  0: break;
    default: _exit (0);
    }

    /* Become session leader. */
    if (setsid () == -1)
	return -1;

    /* Refork to yield session leadership. */
    oldhup = signal (SIGHUP, SIG_IGN);
    switch (fork ()) {
    case -1: return -1;
    case  0: break;
    default: _exit (0);
    }
    signal (SIGHUP, oldhup);

    /* Establish stdio. */
    if (open_devnull_to_fd (0, O_RDONLY) == -1)
	return -1;
    if (open_devnull_to_fd (1, O_WRONLY | O_APPEND) == -1)
	return -1;
    if (dup2 (1, 2) == -1)
	return -1;

    return 0;
}

static int
server_socket (const char *socket_path)
{
    long flags;
    struct sockaddr_un addr;
    int sk;

    unlink (socket_path);

    sk = socket (PF_UNIX, SOCK_STREAM, 0);
    if (sk == -1)
	return -1;

    memset (&addr, 0, sizeof (addr));
    addr.sun_family = AF_UNIX;
    strcpy (addr.sun_path, socket_path);
    if (bind (sk, (struct sockaddr *) &addr, sizeof (addr)) == -1) {
	close (sk);
	return -1;
    }

    flags = fcntl (sk, F_GETFL);
    if (flags == -1 || fcntl (sk, F_SETFL, flags | O_NONBLOCK) == -1) {
	close (sk);
	return -1;
    }

    if (listen (sk, 5) == -1) {
	close (sk);
	return -1;
    }

    return sk;
}

static int
readline (int fd, char *line, int max)
{
    int len = 0;
    do {
	int ret = read (fd, &line[len], 1);
	if (ret <= 0)
	    return -1;
    } while (line[len] != '\n' && ++len < max);
    line[len] = '\0';
    return len;
}

struct clients {
    int count, size;
    int complete;

    cairo_surface_t *recording;
    unsigned long serial;

    struct client_info {
	int sk;
	int trace;
	unsigned long image_serial;
	cairo_surface_t *image;
	char *name;
	char *target;
	char *reference;

	uint8_t *out_buf;
	int out_len;
	int out_size;
    } *clients;
    const char *shm_path;
    unsigned long offset;
    uint8_t *base;
};

static void *
clients_shm (const char *shm_path)
{
    void *base;
    int fd;

    shm_unlink (shm_path);
    fd = shm_open (shm_path, O_RDWR | O_EXCL | O_CREAT, 0777);
    if (fd == -1)
	return MAP_FAILED;

    if (ftruncate (fd, DATA_SIZE) == -1) {
	close (fd);
	return MAP_FAILED;
    }

    base = mmap (NULL, DATA_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close (fd);

    return base;
}

static int
clients_init (struct clients *clients)
{
    clients->count = 0;
    clients->complete = 0;
    clients->size = 4;
    clients->clients = xmalloc (clients->size * sizeof (struct client_info));

    clients->shm_path = SHM_PATH_XXX;
    clients->base = clients_shm (clients->shm_path);
    if (clients->base == MAP_FAILED)
	return -1;
    clients->offset = 0;

    clients->recording = NULL;
    clients->serial = 0;

    return 0;
}

static void
clients_add_command (struct clients *clients, int fd, char *info)
{
    struct client_info *c;
    char buf[1024];
    int len;
    char *str;

    if (clients->count == clients->size) {
	clients->size *= 2;
	clients->clients = xrealloc (clients->clients,
				     clients->size * sizeof (struct client_info));
    }

    c = &clients->clients[clients->count++];
    c->sk = fd;
    c->trace = -1;
    c->image_serial = 0;
    c->image = NULL;
    c->name = c->target = c->reference = NULL;

    c->out_size = 8192;
    c->out_buf = xmalloc (c->out_size);
    c->out_len = 0;

    str = strstr (info, "name=");
    if (str != NULL) {
	char *sp = strchr (str + 5, ' ');
	int len;
	if (sp)
	    len = sp - str - 5;
	else
	    len = strlen (str + 5);
	c->name = xmalloc (len + 1);
	memcpy (c->name, str + 5, len);
	c->name[len] = '\0';
    }

    str = strstr (info, "target=");
    if (str != NULL) {
	char *sp = strchr (str + 7, ' ');
	int len;
	if (sp)
	    len = sp - str - 7;
	else
	    len = strlen (str + 7);
	c->target = xmalloc (len + 1);
	memcpy (c->target, str + 7, len);
	c->target[len] = '\0';
    }

    str = strstr (info, "reference=");
    if (str != NULL) {
	char *sp = strchr (str + 10, ' ');
	int len;
	if (sp)
	    len = sp - str - 10;
	else
	    len = strlen (str + 10);
	c->reference = xmalloc (len + 1);
	memcpy (c->reference, str + 10, len);
	c->reference[len] = '\0';
    }

    len = sprintf (buf, "%s\n", clients->shm_path);
    writen (fd, buf, len);
}

static void
clients_add_trace (struct clients *clients, int fd, char *info)
{
    char *str, *sp;
    char *name;
    int i;

    str = strstr (info, "name=");
    assert (str != NULL);
    sp = strchr (str + 5, ' ');
    if (sp)
	i = sp - str - 5;
    else
	i = strlen (str + 5);

    name = xmalloc (i + 1);
    memcpy (name, str + 5, i);
    name[i] = '\0';

    for (i = 0; i < clients->count; i++) {
	struct client_info *c = &clients->clients[i];
	if (strcmp (name, c->name) == 0) {
	    c->trace = fd;
	    break;
	}
    }

    free (name);
}

static int
clients_image (struct clients *clients, int fd, char *info)
{
    struct client_info *c = NULL;
    int format, width, height, stride, size;
    int i;

    for (i = 0; i < clients->count; i++) {
	if (clients->clients[i].sk == fd) {
	    c = &clients->clients[i];
	    break;
	}
    }

    if (c == NULL)
	return 0;

    if (sscanf (info, "%lu %d %d %d %d",
		&c->image_serial, &format, &width, &height, &stride) != 5)
    {
	return 0;
    }

    size = height * stride;
    size = (size + 4095) & -4096;
    assert (clients->offset + size <= DATA_SIZE);

    c->image =
	cairo_image_surface_create_for_data (clients->base + clients->offset,
					     format, width, height, stride);

    if (! writen (fd, &clients->offset, sizeof (clients->offset)))
	return 0;

    clients->offset += size;

    return 1;
}

static int
u8_cmp (const void *A, const void *B)
{
    const uint8_t *a = A, *b = B;
    return (int) *a - (int) *b;
}

static uint8_t
median (uint8_t *values, int count)
{
    /* XXX could use a fast median here if we cared */
    qsort (values, count, 1, u8_cmp);
    return values[count/2];
}

static uint32_t
get_pixel32 (int x, int y, const uint8_t *data, int stride)
{
    return ((uint32_t *)(data + y * stride))[x];
}

static uint8_t
get_median_32 (int x, int y, int channel,
	       const uint8_t *data, int width, int height, int stride)
{
    uint8_t neighbourhood[25];
    int cnt = 0;
    int xx, yy;

    for (yy = y - 2; yy <= y + 2; yy++) {
	if (yy < 0)
	    continue;
	if (yy >= height)
	    continue;

	for (xx = x - 2; xx <= x + 2; xx++) {
	    if (xx < 0)
		continue;
	    if (xx >= width)
		continue;

	    neighbourhood[cnt++] = (get_pixel32 (xx, yy, data, stride) >> (channel*8)) & 0xff;
	}
    }

    return median (neighbourhood, cnt);
}

static uint8_t
get_pixel8 (int x, int y, const uint8_t *data, int stride)
{
    return data[y * stride + x];
}

static uint8_t
get_median_8 (int x, int y, const uint8_t *data, int width, int height, int stride)
{
    uint8_t neighbourhood[25];
    int cnt = 0;
    int xx, yy;

    for (yy = y - 2; yy <= y + 2; yy++) {
	if (yy < 0)
	    continue;
	if (yy >= height)
	    continue;

	for (xx = x - 2; xx <= x + 2; xx++) {
	    if (xx < 0)
		continue;
	    if (xx >= width)
		continue;

	    neighbourhood[cnt++] = get_pixel8 (xx, yy, data, stride);
	}
    }

    return median (neighbourhood, cnt);
}

static cairo_bool_t
compare_images (cairo_surface_t *a,
		cairo_surface_t *b)
{
    int width, height, stride;
    const uint8_t *aa, *bb;
    int x, y;

    if (cairo_surface_status (a) || cairo_surface_status (b))
	return FALSE;

    if (cairo_surface_get_type (a) != cairo_surface_get_type (b))
	return FALSE;

    if (cairo_image_surface_get_format (a) != cairo_image_surface_get_format (b))
	return FALSE;

    if (cairo_image_surface_get_width (a) != cairo_image_surface_get_width (b))
	return FALSE;

    if (cairo_image_surface_get_height (a) != cairo_image_surface_get_height (b))
	return FALSE;

    if (cairo_image_surface_get_stride (a) != cairo_image_surface_get_stride (b))
	return FALSE;


    width = cairo_image_surface_get_width (a);
    height = cairo_image_surface_get_height (a);
    stride = cairo_image_surface_get_stride (a);

    aa = cairo_image_surface_get_data (a);
    bb = cairo_image_surface_get_data (b);
    switch (cairo_image_surface_get_format (a)) {
    case CAIRO_FORMAT_ARGB32:
	for (y = 0; y < height; y++) {
	    const uint32_t *ua = (uint32_t *) aa;
	    const uint32_t *ub = (uint32_t *) bb;
	    for (x = 0; x < width; x++) {
		if (ua[x] != ub[x]) {
		    int channel;

		    for (channel = 0; channel < 4; channel++) {
			unsigned va, vb, diff;

			va = (ua[x] >> (channel*8)) & 0xff;
			vb = (ub[x] >> (channel*8)) & 0xff;
			diff = abs (va - vb);
			if (diff > 1) {
			    va = get_median_32 (x, y, channel, aa, width, height, stride);
			    vb = get_median_32 (x, y, channel, bb, width, height, stride);
			    diff = abs (va - vb);
			    if (diff > 1)
				return FALSE;
			}
		    }
		}
	    }
	    aa += stride;
	    bb += stride;
	}
	break;

    case CAIRO_FORMAT_RGB24:
	for (y = 0; y < height; y++) {
	    const uint32_t *ua = (uint32_t *) aa;
	    const uint32_t *ub = (uint32_t *) bb;
	    for (x = 0; x < width; x++) {
		if ((ua[x] & 0x00ffffff) != (ub[x] & 0x00ffffff)) {
		    int channel;

		    for (channel = 0; channel < 3; channel++) {
			unsigned va, vb, diff;

			va = (ua[x] >> (channel*8)) & 0xff;
			vb = (ub[x] >> (channel*8)) & 0xff;
			diff = abs (va - vb);
			if (diff > 1) {
			    va = get_median_32 (x, y, channel, aa, width, height, stride);
			    vb = get_median_32 (x, y, channel, bb, width, height, stride);
			    diff = abs (va - vb);
			    if (diff > 1)
				return FALSE;
			}
		    }
		}
	    }
	    aa += stride;
	    bb += stride;
	}
	break;

    case CAIRO_FORMAT_A8:
	for (y = 0; y < height; y++) {
	    for (x = 0; x < width; x++) {
		if (aa[x] != bb[x]) {
		    unsigned diff = abs (aa[x] - bb[x]);
		    if (diff > 1) {
			uint8_t va, vb;

			va = get_median_8 (x, y, aa, width, height, stride);
			vb = get_median_8 (x, y, bb, width, height, stride);
			diff = abs (va - vb);
			if (diff > 1)
			    return FALSE;
		    }

		}
	    }
	    aa += stride;
	    bb += stride;
	}
	break;

    case CAIRO_FORMAT_A1:
	width /= 8;
	for (y = 0; y < height; y++) {
	    if (memcmp (aa, bb, width))
		return FALSE;
	    aa += stride;
	    bb += stride;
	}
	break;

    case CAIRO_FORMAT_INVALID:
    case CAIRO_FORMAT_RGB16_565: /* XXX */
	break;
    }

    return TRUE;
}

static int
check_images (struct clients *clients)
{
    int i, j;

    for (i = 0; i < clients->count; i++) {
	struct client_info *c = &clients->clients[i];

	if (c->reference == NULL)
	    continue;

	for (j = 0; j < clients->count; j++) {
	    struct client_info *ref = &clients->clients[j];

	    if (strcmp (c->reference, ref->name))
		continue;

	    if (! compare_images (c->image, ref->image))
		return 0;
	}
    }

    return 1;
}

static gchar *
checksum (const char *filename)
{
    gchar *str = NULL;
    gchar *data;
    gsize len;

    if (g_file_get_contents (filename, &data, &len, NULL)) {
	str = g_compute_checksum_for_data (G_CHECKSUM_SHA1, (guchar *) data, len);
	g_free (data);
    }

    return str;
}

static void
write_trace (struct clients *clients)
{
    cairo_device_t *ctx;
    gchar *csum;
    char buf[4096];
    int i;

    mkdir ("output", 0777);

    ctx = cairo_script_create ("output/cairo-sphinx.trace");
    cairo_script_from_recording_surface (ctx, clients->recording);
    cairo_device_destroy (ctx);

    csum = checksum ("output/cairo-sphinx.trace");

    sprintf (buf, "output/%s.trace", csum);
    if (! g_file_test (buf, G_FILE_TEST_EXISTS)) {
	rename ("output/cairo-sphinx.trace", buf);

	sprintf (buf, "output/%s.recording.png", csum);
	cairo_surface_write_to_png (clients->recording, buf);

	for (i = 0; i < clients->count; i++) {
	    struct client_info *c = &clients->clients[i];
	    if (c->image != NULL) {
		sprintf (buf, "output/%s.%s.png", csum, c->name);
		cairo_surface_write_to_png (c->image, buf);
	    }
	}
    }
}

static void
clients_complete (struct clients *clients, int fd)
{
    int i;

    for (i = 0; i < clients->count; i++) {
	if (clients->clients[i].sk == fd) {
	    break;
	}
    }
    if (i == clients->count)
	return;

    if (++clients->complete != clients->count)
	return;

    clients->offset = 0;
    clients->complete = 0;

    if (! check_images (clients))
	write_trace (clients);

    /* ack */
    for (i = 0; i < clients->count; i++) {
	struct client_info *c = &clients->clients[i];

	cairo_surface_destroy (c->image);
	c->image = NULL;

	if (! writen (c->sk, &clients->serial, sizeof (clients->serial)))
	    continue;

	c->image_serial = 0;
    }

    clients->recording = NULL;
    clients->serial = 0;
}

static void
clients_recording (struct clients *clients, int fd, char *info)
{
    sscanf (info, "%p %lu", &clients->recording, &clients->serial);
    clients_complete (clients, fd);
}

static void
clients_remove (struct clients *clients, int fd)
{
    int i, j;

    for (i = 0; i < clients->count; i++) {
	struct client_info *c = &clients->clients[i];
	if (c->sk == fd) {
	    free (c->out_buf);
	    break;
	}
    }

    for (j = i++; i < clients->count; i++)
	clients->clients[j] = clients->clients[i];

    clients->count = j;
}

static void
clients_send_trace (struct clients *clients,
		    const char * const line, const int len)
{
    int i;

    for (i = 0; i < clients->count; i++) {
	struct client_info *c = &clients->clients[i];
	int ret, rem = len;

	if (c->trace == -1)
	    continue;

	if (c->out_len) {
	    ret = write (c->trace, c->out_buf, c->out_len);
	    if (ret > 0) {
		c->out_len -= ret;
		if (c->out_len)
		    memmove (c->out_buf, c->out_buf + ret, c->out_len);
	    }
	}

	if (! c->out_len) {
	    ret = write (c->trace, line, rem);
	    if (ret > 0)
		rem -= ret;
	}

	if (rem) {
	    if (c->out_len + rem > c->out_size) {
		c->out_size *= 2;
		c->out_buf = xrealloc (c->out_buf, c->out_size);
	    }

	    memcpy (c->out_buf + c->out_len, line, rem);
	    c->out_len += rem;
	}
    }
}

static void
clients_fini (struct clients *clients)
{
    shm_unlink (clients->shm_path);
    munmap (clients->base, DATA_SIZE);
    free (clients->clients);
}

static int
nonblocking (int fd)
{
    long flags;

    flags = fcntl (fd, F_GETFL);
    if (flags == -1)
	return -1;

    return fcntl (fd, F_SETFL, flags | O_NONBLOCK);
}

static void *
request_image (struct client *c,
	       struct context_closure *closure,
	       cairo_format_t format,
	       int width, int height, int stride)
{
    char buf[1024];
    unsigned long offset = -1;
    int len;

    assert (format != CAIRO_FORMAT_INVALID);

    len = sprintf (buf, ".image %lu %d %d %d %d\n",
		   closure->id, format, width, height, stride);
    writen (c->sk, buf, len);

    readn (c->sk, &offset, sizeof (offset));
    if (offset == (unsigned long) -1)
	return NULL;

    return (uint8_t *) c->base + offset;
}

static cairo_format_t
format_for_content (cairo_content_t content)
{
    switch (content) {
    case CAIRO_CONTENT_ALPHA:
	return CAIRO_FORMAT_A8;
    case CAIRO_CONTENT_COLOR:
	return CAIRO_FORMAT_RGB24;
    default:
    case CAIRO_CONTENT_COLOR_ALPHA:
	return CAIRO_FORMAT_ARGB32;
    }
}

static void
get_surface_size (cairo_surface_t *surface,
		  int *width, int *height,
		  cairo_format_t *format)
{
    if (cairo_surface_get_type (surface) == CAIRO_SURFACE_TYPE_IMAGE) {
	*width = cairo_image_surface_get_width (surface);
	*height = cairo_image_surface_get_height (surface);
	*format = cairo_image_surface_get_format (surface);
    } else {
	struct surface_tag *tag;

	tag = cairo_surface_get_user_data (surface, &surface_tag);
	if (tag != NULL) {
	    *width = tag->width;
	    *height = tag->height;
	} else {
	    double x0, x1, y0, y1;
	    cairo_t *cr;

	    /* presumably created using cairo_surface_create_similar() */
	    cr = cairo_create (surface);
	    cairo_clip_extents (cr, &x0, &y0, &x1, &y1);
	    cairo_destroy (cr);

	    tag = xmalloc (sizeof (*tag));
	    *width = tag->width = ceil (x1 - x0);
	    *height = tag->height = ceil (y1 - y0);

	    if (cairo_surface_set_user_data (surface, &surface_tag, tag, free))
		exit (-1);
	}
    }
}


static void
send_surface (struct client *c,
	      struct context_closure *closure)
{
    cairo_surface_t *source = closure->surface;
    cairo_surface_t *image;
    cairo_format_t format = CAIRO_FORMAT_INVALID;
    cairo_t *cr;
    int width, height, stride;
    void *data;
    unsigned long serial;

    get_surface_size (source, &width, &height, &format);
    if (format == CAIRO_FORMAT_INVALID)
	format = format_for_content (cairo_surface_get_content (source));

    stride = cairo_format_stride_for_width (format, width);

    data = request_image (c, closure, format, width, height, stride);
    if (data == NULL)
	exit (-1);

    image = cairo_image_surface_create_for_data (data,
						 format,
						 width, height,
						 stride);
    cr = cairo_create (image);
    cairo_surface_destroy (image);

    cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
    cairo_set_source_surface (cr, source, 0, 0);
    cairo_paint (cr);
    cairo_destroy (cr);

    /* signal completion */
    writen (c->sk, ".complete\n", strlen (".complete\n"));

    /* wait for image check */
    serial = 0;
    readn (c->sk, &serial, sizeof (serial));
    if (serial != closure->id)
	exit (-1);
}

static void
send_recording (struct client *c,
		struct context_closure *closure)
{
    cairo_surface_t *source = closure->surface;
    char buf[1024];
    int len;
    unsigned long serial;

    assert (cairo_surface_get_type (source) == CAIRO_SURFACE_TYPE_RECORDING);
    len = sprintf (buf, ".recording %p %lu\n", source, closure->id);
    writen (c->sk, buf, len);

    /* wait for image check */

    serial = 0;
    readn (c->sk, &serial, sizeof (serial));
    if (serial != closure->id)
	exit (-1);
}

static cairo_surface_t *
_surface_create (void *closure,
		 cairo_content_t content,
		 double width, double height,
		 long uid)
{
    struct client *c = closure;
    cairo_surface_t *surface;

    surface = cairo_surface_create_similar (c->surface,
					    content, width, height);
    if (cairo_surface_get_type (surface) != CAIRO_SURFACE_TYPE_IMAGE) {
	struct surface_tag *tag;

	tag = xmalloc (sizeof (*tag));
	tag->width = width;
	tag->height = height;
	if (cairo_surface_set_user_data (surface, &surface_tag, tag, free))
	    exit (-1);
    }

    return surface;
}

static cairo_t *
_context_create (void *closure, cairo_surface_t *surface)
{
    struct client *c = closure;
    struct context_closure *l;
    cairo_bool_t foreign = FALSE;

    l = xmalloc (sizeof (*l));
    l->next = c->contexts;
    l->surface = surface;
    l->original = cairo_surface_reference (surface);
    l->id = ++c->context_id;
    if (l->id == 0)
	l->id = ++c->context_id;
    c->contexts = l;

    /* record everything, including writes to images */
    if (c->target == NULL) {
	if (cairo_surface_get_type (surface) != CAIRO_SURFACE_TYPE_RECORDING) {
	    cairo_format_t format;
	    int width, height;

	    get_surface_size (surface, &width, &height, &format);
	    l->surface = cairo_surface_create_similar (c->surface,
						       cairo_surface_get_content (surface),
						       width, height);
	    foreign = TRUE;
	}
    }

    l->context = cairo_create (l->surface);
    if (foreign) {
	cairo_set_source_surface (l->context, surface, 0, 0);
	cairo_paint (l->context);
    }

    return l->context;
}

static void
_context_destroy (void *closure, void *ptr)
{
    struct client *c = closure;
    struct context_closure *l, **prev = &c->contexts;

    while ((l = *prev) != NULL) {
	if (l->context == ptr) {
	    if (cairo_surface_status (l->surface) == CAIRO_STATUS_SUCCESS) {
		if (c->target == NULL)
		    send_recording (c, l);
		else
		    send_surface (c, l);
            } else {
		exit (-1);
	    }

            cairo_surface_destroy (l->original);
            *prev = l->next;
            free (l);
            return;
        }
        prev = &l->next;
    }
}

static void *
recorder (void *arg)
{
    struct client client;
    const cairo_script_interpreter_hooks_t hooks = {
	.closure = &client,
	.surface_create = _surface_create,
	.context_create = _context_create,
	.context_destroy = _context_destroy,
    };
    char *buf;
    int buf_size;
    int len = 0, ret;
    struct pollfd pfd;

    client.target = NULL;
    client.sk = client_socket ("/tmp/cairo-sphinx");
    if (client.sk < 0)
	return NULL;

    buf_size = 65536;
    buf = xmalloc (buf_size);

    len = sprintf (buf, "client-command target=recording name=.recorder\n");
    if (! writen (client.sk, buf, len))
	return NULL;

    /* drain the shm_path */
    len = readline (client.sk, buf, buf_size);

    pfd.fd = client_socket ("/tmp/cairo-sphinx");
    if (pfd.fd < 0)
	return NULL;

    len = sprintf (buf, "client-trace name=.recorder\n");
    if (! writen (pfd.fd, buf, len))
	return NULL;

    client.surface = cairo_recording_surface_create (CAIRO_CONTENT_COLOR_ALPHA,
						     NULL);

    client.context_id = 0;
    client.csi = cairo_script_interpreter_create ();
    cairo_script_interpreter_install_hooks (client.csi, &hooks);

    nonblocking (pfd.fd);
    pfd.events = POLLIN;
    len = 0;
    while (poll (&pfd, 1, -1) > 0) {
	while ((ret = read (pfd.fd, buf + len, buf_size - len)) > 0) {
	    int end;

	    if (ret == buf_size - len) {
		buf_size *= 2;
		buf = xrealloc (buf, buf_size);
	    }
	    len += ret;

	    for (end = len; end > 0 && buf[--end] != '\n'; )
		;
	    if (end > 0) {
		buf[end] = '\0';
		cairo_script_interpreter_feed_string (client.csi, buf, end);

		len -= end + 1;
		if (len)
		    memmove (buf, buf + end + 1, len);
	    }
	}
	if (ret == 0)
	    break;
	if (! (errno == EAGAIN || errno == EINTR))
	    break;
    }

    cairo_script_interpreter_finish (client.csi);
    cairo_script_interpreter_destroy (client.csi);

    cairo_surface_destroy (client.surface);
    return NULL;
}

static int
do_server (const char *path)
{
    pthread_t thread;
    struct clients clients;
    char line[4096];
    struct pollfd *pfd;
    int num_pfd, size_pfd;
    int n, cnt, ret = 1;
    int sk, source = -1;
    int waiter = -1, waiter_count = 0;
    int len;

    signal (SIGPIPE, SIG_IGN);

    if (clients_init (&clients) < 0) {
	fprintf (stderr, "Failed to initialise clients structure\n");
	return -1;
    }

    sk = server_socket (path);
    if (sk < 0) {
	fprintf (stderr, "Failed to create server socket\n");
	return 1;
    }

    if (daemonize () < 0)
	return 1;

    if (pthread_create (&thread, NULL, recorder, NULL) < 0) {
	fprintf (stderr, "Failed to create spawn recording thread\n");
	return 1;
    }

    size_pfd = 4;
    pfd = xmalloc (sizeof (*pfd) * size_pfd);
    pfd[0].fd = sk;
    pfd[0].events = POLLIN;
    num_pfd = 1;

    while ((cnt = poll (pfd, num_pfd, -1)) > 0) {
	int have_source;

	if (pfd[0].revents) {
	    while ((sk = accept (pfd[0].fd, NULL, NULL)) != -1) {
		len = readline (sk, line, sizeof (line));
		if (strcmp (line, "source") == 0) {

		    if (source != -1)
			exit (1);

		    source = sk;
		    if (nonblocking (sk) < 0) {
			close (sk);
			continue;
		    }
		} else if (strncmp (line, "client-command", 14) == 0) {
		    if (source == -1)
			clients_add_command (&clients, sk, line);
		} else if (strncmp (line, "client-trace", 12) == 0) {
		    if (source == -1) {
			clients_add_trace (&clients, sk, line);
			if (nonblocking (sk) < 0) {
			    close (sk);
			    continue;
			}

			if (clients.count == waiter_count) {
			    for (n = 1; n < num_pfd; n++) {
				if (pfd[n].fd == waiter) {
				    pfd[n].fd = -1;
				    break;
				}
			    }
			    close (waiter);
			    waiter_count = -1;
			}
		    }
		} else if (strncmp (line, "wait", 4) == 0) {
		    int count = atoi (line + 5) + 1;
		    if (clients.count == count) {
			close (sk);
			continue;
		    } else {
			waiter = sk;
			waiter_count = count;
		    }
		}

		if (num_pfd == size_pfd) {
		    size_pfd *= 2;
		    pfd = xrealloc (pfd, sizeof (*pfd) * size_pfd);
		}

		pfd[num_pfd].fd = sk;
		pfd[num_pfd].events = POLLIN;
		pfd[num_pfd].revents = 0;
		num_pfd++;
	    }
	    cnt--;
	}

	have_source = 0;
	for (n = 1; cnt && n < num_pfd; n++) {
	    if (! pfd[n].revents)
		continue;
	    cnt--;

	    if (pfd[n].fd == -1)
		continue;

	    if (source == pfd[n].fd) {
		have_source = n;
	    } else {
		len = readline (pfd[n].fd, line, sizeof (line));
		if (len < 0) {
		    clients_remove (&clients, pfd[n].fd);
		    close (pfd[n].fd);
		    pfd[n].fd = -1;
		    continue;
		}

		 if (strncmp (line, ".image", 6) == 0) {
		    if (! clients_image (&clients, pfd[n].fd, line + 7)) {
			clients_remove (&clients, pfd[n].fd);
			close (pfd[n].fd);
			pfd[n].fd = -1;
			continue;
		    }
		} else if (strncmp (line, ".complete", 9) == 0) {
		    clients_complete (&clients, pfd[n].fd);
		} else if (strncmp (line, ".recording", 10) == 0) {
		    clients_recording (&clients, pfd[n].fd, line + 6);
		} else {
		    printf ("do_command (%s)\n", line);
		}
	    }
	}

	if (have_source) {
	    do {
		len = read (source, line, sizeof (line));
		if (len > 0) {
		    clients_send_trace (&clients, line, len);
		} else if (len == 0) {
		    close (source);
		    pfd[have_source].fd = source = -1;
		    goto done;
		} else
		    break;
	    } while (1);
	}

	for (n = cnt = 1; n < num_pfd; n++) {
	    if (pfd[n].fd != -1) {
		if (cnt != n)
		    pfd[cnt] = pfd[n];
		cnt++;
	    }
	}
	num_pfd = cnt;
    }

done:
    ret = 0;
    for (n = 0; n < num_pfd; n++) {
	if (pfd[n].fd != -1)
	    close (pfd[n].fd);
    }
    free (pfd);
    clients_fini (&clients);

    return ret;
}

static void *
client_shm (const char *shm_path)
{
    void *base;
    int fd;

    fd = shm_open (shm_path, O_RDWR, 0);
    if (fd == -1)
	return MAP_FAILED;

    base = mmap (NULL, DATA_SIZE,
		 PROT_READ | PROT_WRITE,
		 MAP_SHARED | MAP_NORESERVE,
		 fd, 0);
    close (fd);

    return base;
}

static int
client_socket (const char *socket_path)
{
    struct sockaddr_un addr;
    int sk;

    sk = socket (PF_UNIX, SOCK_STREAM, 0);
    if (sk == -1)
	return -1;

    memset (&addr, 0, sizeof (addr));
    addr.sun_family = AF_UNIX;
    strcpy (addr.sun_path, socket_path);

    if (connect (sk, (struct sockaddr *) &addr, sizeof (addr)) == -1)
	return -1;

    return sk;
}

static int
do_client (int fd,
	   const char *target,
	   const char *name,
	   const char *reference,
	   cairo_content_t content)
{
    struct client client;
    const cairo_script_interpreter_hooks_t hooks = {
	.closure = &client,
	.surface_create = _surface_create,
	.context_create = _context_create,
	.context_destroy = _context_destroy,
    };
    void *closure;
    char *buf;
    int buf_size;
    int len = 0, ret;
    struct pollfd pfd;

    client.sk = fd;
    client.target = cairo_boilerplate_get_target_by_name (target, content);
    client.context_id = 0;

    client.surface = client.target->create_surface (NULL, content, 1, 1, 1, 1,
						    CAIRO_BOILERPLATE_MODE_TEST,
						    0, &closure);
    if (client.surface == NULL) {
	fprintf (stderr, "Failed to create target surface: %s.\n",
		 client.target->name);
	return 1;
    }

    buf_size = 65536;
    buf = xmalloc (buf_size);

    if (reference != NULL) {
	len = sprintf (buf,
		       "client-command name=%s target=%s reference=%s\n",
		       name, target, reference);
    } else {
	len = sprintf (buf,
		       "client-command name=%s target=%s\n",
		       name, target);
    }
    if (! writen (fd, buf, len))
	return 1;

    len = readline (fd, buf, buf_size);
    client.base = client_shm (buf);
    if (client.base == MAP_FAILED) {
	fprintf (stderr, "Failed to map shared memory segment '%s'.\n", buf);
	return 1;
    }

    if (daemonize () < 0)
	return 1;

    pfd.fd = client_socket ("/tmp/cairo-sphinx");
    if (pfd.fd < 0)
	return 1;

    len = sprintf (buf, "client-trace name=%s\n", name);
    if (! writen (pfd.fd, buf, len))
	return 1;

    client.csi = cairo_script_interpreter_create ();
    cairo_script_interpreter_install_hooks (client.csi, &hooks);

    nonblocking (pfd.fd);
    pfd.events = POLLIN;
    len = 0;
    while (poll (&pfd, 1, -1) > 0) {
	while ((ret = read (pfd.fd, buf + len, buf_size - len)) > 0) {
	    int end;

	    if (ret == buf_size - len) {
		buf_size *= 2;
		buf = xrealloc (buf, buf_size);
	    }
	    len += ret;

	    for (end = len; end > 0 && buf[--end] != '\n'; )
		;
	    if (end > 0) {
		buf[end] = '\0';
		cairo_script_interpreter_feed_string (client.csi, buf, end);

		len -= end + 1;
		if (len)
		    memmove (buf, buf + end + 1, len);
	    }
	}
	if (ret == 0)
	    break;
	if (! (errno == EAGAIN || errno == EINTR))
	    break;
    }

    cairo_script_interpreter_finish (client.csi);
    cairo_script_interpreter_destroy (client.csi);

    cairo_surface_destroy (client.surface);
    close (fd);

    return 0;
}

static int
do_exec (int fd, char **argv)
{
    char buf[4096];

    if (*argv == NULL)
	return 0;

    snprintf (buf, sizeof (buf), "%s/cairo-trace.so", LIBDIR);
    setenv ("LD_PRELOAD", buf, 1);

    snprintf (buf, sizeof (buf), "0");
    setenv ("CAIRO_TRACE_LINE_INFO", buf, 1);

    snprintf (buf, sizeof (buf), "%d", fd);
    setenv ("CAIRO_TRACE_FD", buf, 1);
    putenv (buf);

    return execvp (argv[0], argv);
}

static int
do_wait (int fd)
{
    char buf;
    int ret = read (fd, &buf, 1);
    return ret != 0;
}

int
main (int argc, char **argv)
{
    char buf[4096];
    int len;
    int fd;

    if (argc == 1)
	return do_server ("/tmp/cairo-sphinx");

    fd = client_socket ("/tmp/cairo-sphinx");
    if (fd < 0)
	return 1;

    if (strcmp (argv[1], "client") == 0) {
	return do_client (fd, argv[2], argv[3], argv[4],
			  CAIRO_CONTENT_COLOR_ALPHA);
    }

    if (strcmp (argv[1], "wait") == 0) {
	len = snprintf (buf, sizeof (buf), "wait %s\n", argv[2]);
	if (! writen (fd, buf, len))
	    return 1;

	return do_wait (fd);
    }

    if (strcmp (argv[1], "exec") == 0) {
	len = snprintf (buf, sizeof (buf), "source\n");
	if (! writen (fd, buf, len))
	    return 1;

	return do_exec (fd, argv+2);
    }

    if (strcmp (argv[1], "replay") == 0) {
	len = snprintf (buf, sizeof (buf), "replay %s\n", argv[2]);
	return ! writen (fd, buf, len);
    }

    return 0;
}
