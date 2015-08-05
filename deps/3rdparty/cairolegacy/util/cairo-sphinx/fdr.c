/* cairo-fdr - a 'flight data recorder', a black box, for cairo
 *
 * Copyright © 2009 Chris Wilson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _GNU_SOURCE

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <cairo.h>
#include <cairo-script.h>
#include <cairo-tee.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>

#include <dlfcn.h>

static void *_dlhandle = RTLD_NEXT;
#define DLCALL(name, args...) ({ \
    static typeof (&name) name##_real; \
    if (name##_real == NULL) { \
	name##_real = dlsym (_dlhandle, #name); \
	if (name##_real == NULL && _dlhandle == RTLD_NEXT) { \
	    _dlhandle = dlopen ("libcairo.so", RTLD_LAZY); \
	    name##_real = dlsym (_dlhandle, #name); \
	    assert (name##_real != NULL); \
	} \
    } \
    (*name##_real) (args);  \
})

static cairo_device_t *fdr_context;
static const cairo_user_data_key_t fdr_key;

static void
fdr_get_extents (cairo_surface_t *surface,
		 cairo_rectangle_t *extents)
{
    cairo_t *cr;

    cr = DLCALL (cairo_create, surface);
    DLCALL (cairo_clip_extents, cr,
	    &extents->x, &extents->y, &extents->width, &extents->height);
    DLCALL (cairo_destroy, cr);

    extents->width -= extents->x;
    extents->height -= extents->y;
}

static void
fdr_surface_destroy (void *surface)
{
    DLCALL (cairo_surface_destroy, surface);
}

static void
fdr_surface_reference (void *surface)
{
    DLCALL (cairo_surface_reference, surface);
}

static cairo_surface_t *
fdr_surface_get_tee (cairo_surface_t *surface)
{
    return DLCALL (cairo_surface_get_user_data, surface, &fdr_key);
}

static cairo_surface_t *
fdr_tee_surface_index (cairo_surface_t *surface, int index)
{
    return DLCALL (cairo_tee_surface_index, surface, index);
}

static cairo_status_t
fdr_write (void *closure, const unsigned char *data, unsigned int len)
{
    int fd = (int) (intptr_t) closure;
    while (len) {
	int ret = write (fd, data, len);
	if (ret < 0) {
	    switch (errno) {
	    case EAGAIN:
	    case EINTR:
		continue;
	    default:
		return CAIRO_STATUS_WRITE_ERROR;
	    }
	} else if (ret == 0) {
	    return CAIRO_STATUS_WRITE_ERROR;
	} else {
	    data += ret;
	    len -= ret;
	}
    }
    return CAIRO_STATUS_SUCCESS;
}

cairo_t *
cairo_create (cairo_surface_t *surface)
{
    cairo_surface_t *tee;

    tee = fdr_surface_get_tee (surface);
    if (tee == NULL) {
	cairo_surface_t *script;
	cairo_rectangle_t extents;
	cairo_content_t content;

	if (fdr_context == NULL) {
	    const char *env = getenv ("CAIRO_SPHINX_FD");
	    int fd = env ? atoi (env) : 1;
	    fdr_context = DLCALL (cairo_script_create_for_stream,
				  fdr_write, (void *) (intptr_t) fd);
	}

	fdr_get_extents (surface, &extents);
	content = DLCALL (cairo_surface_get_content, surface);

	tee = DLCALL (cairo_tee_surface_create, surface);
	script = DLCALL (cairo_script_surface_create,
			 fdr_context, content, extents.width, extents.height);
	DLCALL (cairo_tee_surface_add, tee, script);

	DLCALL (cairo_surface_set_user_data, surface,
		&fdr_key, tee, fdr_surface_destroy);
    }

    return DLCALL (cairo_create, tee);
}

static void
fdr_remove_tee (cairo_surface_t *surface)
{
    fdr_surface_reference (surface);
    DLCALL (cairo_surface_set_user_data, surface, &fdr_key, NULL, NULL);
    fdr_surface_destroy (surface);
}

void
cairo_destroy (cairo_t *cr)
{
    cairo_surface_t *tee;

    tee = DLCALL (cairo_get_target, cr);
    DLCALL (cairo_destroy, cr);

    if (DLCALL (cairo_surface_get_reference_count, tee) == 1)
	fdr_remove_tee (fdr_tee_surface_index (tee, 0));
}

void
cairo_pattern_destroy (cairo_pattern_t *pattern)
{
    if (DLCALL (cairo_pattern_get_type, pattern) == CAIRO_PATTERN_TYPE_SURFACE) {
	cairo_surface_t *surface;

	if (DLCALL (cairo_pattern_get_surface, pattern, &surface) == CAIRO_STATUS_SUCCESS &&
	    DLCALL (cairo_surface_get_type, surface) == CAIRO_SURFACE_TYPE_TEE &&
	    DLCALL (cairo_surface_get_reference_count, surface) == 2)
	{
	    fdr_remove_tee (fdr_tee_surface_index (surface, 0));
	}
    }

    DLCALL (cairo_pattern_destroy, pattern);
}

cairo_surface_t *
cairo_get_target (cairo_t *cr)
{
    cairo_surface_t *tee;

    tee = DLCALL (cairo_get_target, cr);
    return fdr_tee_surface_index (tee, 0);
}

cairo_surface_t *
cairo_get_group_target (cairo_t *cr)
{
    cairo_surface_t *tee;

    tee = DLCALL (cairo_get_group_target, cr);
    return fdr_tee_surface_index (tee, 0);
}

cairo_pattern_t *
cairo_pattern_create_for_surface (cairo_surface_t *surface)
{
    cairo_surface_t *tee;

    tee = fdr_surface_get_tee (surface);
    if (tee != NULL)
	surface = tee;

    return DLCALL (cairo_pattern_create_for_surface, surface);
}

cairo_status_t
cairo_pattern_get_surface (cairo_pattern_t *pattern,
			   cairo_surface_t **surface)
{
    cairo_status_t status;
    cairo_surface_t *tee;

    status = DLCALL (cairo_pattern_get_surface, pattern, surface);
    if (status != CAIRO_STATUS_SUCCESS)
	return status;

    tee = fdr_surface_get_tee (*surface);
    if (tee != NULL)
	*surface = tee;

    return CAIRO_STATUS_SUCCESS;
}

void
cairo_set_source_surface (cairo_t *cr,
			  cairo_surface_t *surface,
			  double x, double y)
{
    cairo_surface_t *tee;

    tee = fdr_surface_get_tee (surface);
    if (tee != NULL)
	surface = tee;

    DLCALL (cairo_set_source_surface, cr, surface, x, y);
}

cairo_surface_t *
cairo_surface_create_similar (cairo_surface_t *surface,
			      cairo_content_t content,
			      int width, int height)
{
    cairo_surface_t *tee;

    tee = fdr_surface_get_tee (surface);
    if (tee != NULL)
	surface = tee;

    return DLCALL (cairo_surface_create_similar,
		   surface, content, width, height);
}
