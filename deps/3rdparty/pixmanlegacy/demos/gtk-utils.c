#include <gtk/gtk.h>
#include <config.h>
#include "pixman-private.h"	/* For image->bits.format
				 * FIXME: there should probably be public API for this
				 */
#include "gtk-utils.h"

GdkPixbuf *
pixbuf_from_argb32 (uint32_t *bits,
		    gboolean has_alpha,
		    int width,
		    int height,
		    int stride)
{
    GdkPixbuf *pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, TRUE,
					8, width, height);
    int p_stride = gdk_pixbuf_get_rowstride (pixbuf);
    guint32 *p_bits = (guint32 *)gdk_pixbuf_get_pixels (pixbuf);
    int w, h;
    
    for (h = 0; h < height; ++h)
    {
	for (w = 0; w < width; ++w)
	{
	    uint32_t argb = bits[h * (stride / 4) + w];
	    guint r, g, b, a;
	    char *pb = (char *)p_bits;

	    pb += h * p_stride + w * 4;

	    r = (argb & 0x00ff0000) >> 16;
	    g = (argb & 0x0000ff00) >> 8;
	    b = (argb & 0x000000ff) >> 0;
	    a = has_alpha? (argb & 0xff000000) >> 24 : 0xff;

	    if (a)
	    {
		r = (r * 255) / a;
		g = (g * 255) / a;
		b = (b * 255) / a;
	    }

	    if (r > 255) r = 255;
	    if (g > 255) g = 255;
	    if (b > 255) b = 255;
	    
	    pb[0] = r;
	    pb[1] = g;
	    pb[2] = b;
	    pb[3] = a;
	}
    }
    
    return pixbuf;
}


static gboolean
on_expose (GtkWidget *widget, GdkEventExpose *expose, gpointer data)
{
    GdkPixbuf *pixbuf = data;
    
    gdk_draw_pixbuf (widget->window, NULL,
		     pixbuf, 0, 0, 0, 0,
		     gdk_pixbuf_get_width (pixbuf),
		     gdk_pixbuf_get_height (pixbuf),
		     GDK_RGB_DITHER_NONE,
		     0, 0);
    
    return TRUE;
}

void
show_image (pixman_image_t *image)
{
    GtkWidget *window;
    GdkPixbuf *pixbuf;
    int width, height, stride;
    int argc;
    char **argv;
    char *arg0 = g_strdup ("pixman-test-program");
    gboolean has_alpha;
    pixman_format_code_t format;

    argc = 1;
    argv = (char **)&arg0;

    gtk_init (&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    width = pixman_image_get_width (image);
    height = pixman_image_get_height (image);
    stride = pixman_image_get_stride (image);

    gtk_window_set_default_size (GTK_WINDOW (window), width, height);
    
    format = image->bits.format;
    
    if (format == PIXMAN_a8r8g8b8)
	has_alpha = TRUE;
    else if (format == PIXMAN_x8r8g8b8)
	has_alpha = FALSE;
    else
	g_error ("Can't deal with this format: %x\n", format);
    
    pixbuf = pixbuf_from_argb32 (pixman_image_get_data (image), has_alpha,
				 width, height, stride);
    
    g_signal_connect (window, "expose_event", G_CALLBACK (on_expose), pixbuf);
    g_signal_connect (window, "delete_event", G_CALLBACK (gtk_main_quit), NULL);
    
    gtk_widget_show (window);
    
    gtk_main ();
}
