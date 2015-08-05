/* -*- Mode: c; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 8; -*- */
/*
 * Copyright © 2004,2006 Red Hat, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without
 * fee, provided that the above copyright notice appear in all copies
 * and that both that copyright notice and this permission notice
 * appear in supporting documentation, and that the name of
 * Red Hat, Inc. not be used in advertising or publicity pertaining to
 * distribution of the software without specific, written prior
 * permission. Red Hat, Inc. makes no representations about the
 * suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * RED HAT, INC. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL RED HAT, INC. BE LIABLE FOR ANY SPECIAL,
 * INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
 * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Author: Carl D. Worth <cworth@cworth.org>
 */

#include "cairo-boilerplate-private.h"

#include <cairo-xcb.h>

#include <assert.h>

/* Errors have response_type == 0 */
#define CAIRO_XCB_ERROR 0

static const cairo_user_data_key_t xcb_closure_key;

typedef struct _xcb_target_closure {
    xcb_connection_t *c;
    cairo_device_t *device;
    uint32_t drawable;
    cairo_bool_t is_pixmap;
    cairo_surface_t *surface;
} xcb_target_closure_t;

static cairo_status_t
_cairo_boilerplate_xcb_handle_errors (xcb_target_closure_t *xtc)
{
    xcb_generic_event_t *ev;

    if ((ev = xcb_poll_for_event (xtc->c)) != NULL) {
	if (ev->response_type == CAIRO_XCB_ERROR) {
	    xcb_generic_error_t *error = (xcb_generic_error_t *) ev;

#if XCB_GENERIC_ERROR_HAS_MAJOR_MINOR_CODES
	    fprintf (stderr,
		     "Detected error during xcb run: %d major=%d, minor=%d\n",
		     error->error_code, error->major_code, error->minor_code);
#else
	    fprintf (stderr,
		     "Detected error during xcb run: %d\n",
		     error->error_code);
#endif
	} else {
	    fprintf (stderr,
		     "Detected unexpected event during xcb run: %d\n",
		     ev->response_type);
	}
	free (ev);

	/* Silently discard all following errors */
	while ((ev = xcb_poll_for_event (xtc->c)) != NULL)
	    free (ev);

	return CAIRO_STATUS_WRITE_ERROR;
    }

    return CAIRO_STATUS_SUCCESS;
}

static void
_cairo_boilerplate_xcb_sync_server (xcb_target_closure_t *xtc)
{
    free (xcb_get_input_focus_reply (xtc->c,
				     xcb_get_input_focus (xtc->c), NULL));
}

static void
_cairo_boilerplate_xcb_cleanup (void *closure)
{
    xcb_target_closure_t *xtc = closure;
    cairo_status_t status;

    cairo_surface_finish (xtc->surface);
    if (xtc->is_pixmap)
	xcb_free_pixmap (xtc->c, xtc->drawable);
    else
	xcb_destroy_window (xtc->c, xtc->drawable);
    cairo_surface_destroy (xtc->surface);

    cairo_device_finish (xtc->device);
    cairo_device_destroy (xtc->device);

    /* First synchronize with the X server to make sure there are no more errors
     * in-flight which we would miss otherwise */
    _cairo_boilerplate_xcb_sync_server (xtc);
    status = _cairo_boilerplate_xcb_handle_errors (xtc);
    assert (status == CAIRO_STATUS_SUCCESS);

    xcb_disconnect (xtc->c);

    free (xtc);
}

static void
_cairo_boilerplate_xcb_synchronize (void *closure)
{
    xcb_target_closure_t *xtc = closure;
    cairo_status_t status;
    free (xcb_get_image_reply (xtc->c,
		xcb_get_image (xtc->c, XCB_IMAGE_FORMAT_Z_PIXMAP,
		    xtc->drawable, 0, 0, 1, 1, /* AllPlanes */ -1),
		0));

    status = _cairo_boilerplate_xcb_handle_errors (xtc);
    assert (status == CAIRO_STATUS_SUCCESS);
}

static xcb_render_pictforminfo_t *
find_depth (xcb_connection_t  *connection,
	    int 	       depth,
	    void	     **formats_out)
{
    xcb_render_query_pict_formats_reply_t *formats;
    xcb_render_query_pict_formats_cookie_t cookie;
    xcb_render_pictforminfo_iterator_t i;

    cookie = xcb_render_query_pict_formats (connection);
    xcb_flush (connection);

    formats = xcb_render_query_pict_formats_reply (connection, cookie, 0);
    if (formats == NULL)
	return NULL;

    for (i = xcb_render_query_pict_formats_formats_iterator (formats);
	 i.rem;
	 xcb_render_pictforminfo_next (&i))
    {
	if (XCB_RENDER_PICT_TYPE_DIRECT != i.data->type)
	    continue;

	if (depth != i.data->depth)
	    continue;

	*formats_out = formats;
	return i.data;
    }

    free (formats);
    return NULL;
}

static cairo_surface_t *
_cairo_boilerplate_xcb_create_surface (const char		 *name,
				       cairo_content_t		  content,
				       double			  width,
				       double			  height,
				       double			  max_width,
				       double			  max_height,
				       cairo_boilerplate_mode_t   mode,
				       int			  id,
				       void			**closure)
{
    xcb_screen_t *root;
    xcb_target_closure_t *xtc;
    xcb_connection_t *c;
    xcb_render_pictforminfo_t *render_format;
    int depth;
    xcb_void_cookie_t cookie;
    cairo_surface_t *surface;
    cairo_status_t status;
    void *formats;

    *closure = xtc = xmalloc (sizeof (xcb_target_closure_t));

    if (width == 0)
	width = 1;
    if (height == 0)
	height = 1;

    xtc->c = c = xcb_connect(NULL,NULL);
    if (c == NULL || xcb_connection_has_error(c)) {
	free (xtc);
	return NULL;
    }

    root = xcb_setup_roots_iterator(xcb_get_setup(c)).data;

    xtc->surface = NULL;
    xtc->is_pixmap = TRUE;
    xtc->drawable = xcb_generate_id (c);
    switch (content) {
    case CAIRO_CONTENT_COLOR:
	depth = 24;
	cookie = xcb_create_pixmap_checked (c, depth,
					    xtc->drawable, root->root,
					    width, height);
	break;

    case CAIRO_CONTENT_COLOR_ALPHA:
	depth = 32;
	cookie = xcb_create_pixmap_checked (c, depth,
					    xtc->drawable, root->root,
					    width, height);
	break;

    case CAIRO_CONTENT_ALPHA:  /* would be XCB_PICT_STANDARD_A_8 */
    default:
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    /* slow, but sure */
    if (xcb_request_check (c, cookie) != NULL) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    render_format = find_depth (c, depth, &formats);
    if (render_format == NULL) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    surface = cairo_xcb_surface_create_with_xrender_format (c, root,
							    xtc->drawable,
							    render_format,
							    width, height);
    free (formats);

    xtc->device = cairo_device_reference (cairo_surface_get_device (surface));
    status = cairo_surface_set_user_data (surface, &xcb_closure_key, xtc, NULL);
    if (status == CAIRO_STATUS_SUCCESS)
	return surface;

    cairo_surface_destroy (surface);

    _cairo_boilerplate_xcb_cleanup (xtc);
    return cairo_boilerplate_surface_create_in_error (status);
}

static xcb_visualtype_t *
lookup_visual (xcb_screen_t   *s,
	       xcb_visualid_t  visual)
{
    xcb_depth_iterator_t d;

    d = xcb_screen_allowed_depths_iterator (s);
    for (; d.rem; xcb_depth_next (&d)) {
	xcb_visualtype_iterator_t v = xcb_depth_visuals_iterator (d.data);
	for (; v.rem; xcb_visualtype_next (&v)) {
	    if (v.data->visual_id == visual)
		return v.data;
	}
    }

    return 0;
}

static cairo_surface_t *
_cairo_boilerplate_xcb_create_window (const char		*name,
				      cairo_content_t		 content,
				      double			 width,
				      double			 height,
				      double			 max_width,
				      double			 max_height,
				      cairo_boilerplate_mode_t	 mode,
				      int			 id,
				      void		       **closure)
{
    xcb_target_closure_t *xtc;
    xcb_connection_t *c;
    xcb_screen_t *s;
    xcb_void_cookie_t cookie;
    cairo_surface_t *surface;
    cairo_status_t status;
    uint32_t values[] = { 1 };

    *closure = xtc = xmalloc (sizeof (xcb_target_closure_t));

    if (width == 0)
	width = 1;
    if (height == 0)
	height = 1;

    xtc->c = c = xcb_connect(NULL,NULL);
    if (xcb_connection_has_error(c)) {
	free (xtc);
	return NULL;
    }

    xtc->surface = NULL;

    s = xcb_setup_roots_iterator (xcb_get_setup (c)).data;
    if (width > s->width_in_pixels || height > s->height_in_pixels) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    xtc->is_pixmap = FALSE;
    xtc->drawable = xcb_generate_id (c);
    cookie = xcb_create_window_checked (c,
					s->root_depth,
					xtc->drawable,
					s->root,
					0, 0, width, height, 0,
					XCB_WINDOW_CLASS_INPUT_OUTPUT,
					s->root_visual,
					XCB_CW_OVERRIDE_REDIRECT,
					values);
    xcb_map_window (c, xtc->drawable);

    /* slow, but sure */
    if (xcb_request_check (c, cookie) != NULL) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    surface = cairo_xcb_surface_create (c,
					xtc->drawable,
					lookup_visual (s, s->root_visual),
					width, height);

    xtc->device = cairo_device_reference (cairo_surface_get_device (surface));
    status = cairo_surface_set_user_data (surface, &xcb_closure_key, xtc, NULL);
    if (status == CAIRO_STATUS_SUCCESS)
	return surface;

    cairo_surface_destroy (surface);

    _cairo_boilerplate_xcb_cleanup (xtc);
    return cairo_boilerplate_surface_create_in_error (status);
}

static cairo_surface_t *
_cairo_boilerplate_xcb_create_window_db (const char		   *name,
					 cairo_content_t	    content,
					 double 		    width,
					 double 		    height,
					 double 		    max_width,
					 double 		    max_height,
					 cairo_boilerplate_mode_t   mode,
					 int			    id,
					 void			  **closure)
{
    xcb_target_closure_t *xtc;
    xcb_connection_t *c;
    xcb_screen_t *s;
    xcb_void_cookie_t cookie;
    cairo_surface_t *surface;
    cairo_status_t status;
    uint32_t values[] = { 1 };

    *closure = xtc = xmalloc (sizeof (xcb_target_closure_t));

    if (width == 0)
	width = 1;
    if (height == 0)
	height = 1;

    xtc->c = c = xcb_connect(NULL,NULL);
    if (xcb_connection_has_error(c)) {
	free (xtc);
	return NULL;
    }

    xtc->surface = NULL;

    s = xcb_setup_roots_iterator (xcb_get_setup (c)).data;
    if (width > s->width_in_pixels || height > s->height_in_pixels) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    xtc->is_pixmap = FALSE;
    xtc->drawable = xcb_generate_id (c);
    cookie = xcb_create_window_checked (c,
					s->root_depth,
					xtc->drawable,
					s->root,
					0, 0, width, height, 0,
					XCB_WINDOW_CLASS_INPUT_OUTPUT,
					s->root_visual,
					XCB_CW_OVERRIDE_REDIRECT,
					values);
    xcb_map_window (c, xtc->drawable);

    /* slow, but sure */
    if (xcb_request_check (c, cookie) != NULL) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    xtc->surface = cairo_xcb_surface_create (c,
					     xtc->drawable,
					     lookup_visual (s, s->root_visual),
					     width, height);
    surface = cairo_surface_create_similar (xtc->surface, content, width, height);

    xtc->device = cairo_device_reference (cairo_surface_get_device (surface));
    status = cairo_surface_set_user_data (surface, &xcb_closure_key, xtc, NULL);
    if (status == CAIRO_STATUS_SUCCESS)
	return surface;

    cairo_surface_destroy (surface);

    _cairo_boilerplate_xcb_cleanup (xtc);
    return cairo_boilerplate_surface_create_in_error (status);
}

static cairo_surface_t *
_cairo_boilerplate_xcb_create_render_0_0 (const char		    *name,
					  cairo_content_t	     content,
					  double		     width,
					  double		     height,
					  double		     max_width,
					  double		     max_height,
					  cairo_boilerplate_mode_t   mode,
					  int			     id,
					  void			   **closure)
{
    xcb_screen_t *root;
    xcb_target_closure_t *xtc;
    xcb_connection_t *c;
    xcb_render_pictforminfo_t *render_format;
    int depth;
    xcb_void_cookie_t cookie;
    cairo_surface_t *surface, *tmp;
    cairo_status_t status;
    void *formats;

    *closure = xtc = xmalloc (sizeof (xcb_target_closure_t));

    if (width == 0)
	width = 1;
    if (height == 0)
	height = 1;

    xtc->c = c = xcb_connect(NULL,NULL);
    if (xcb_connection_has_error(c)) {
	free (xtc);
	return NULL;
    }

    root = xcb_setup_roots_iterator(xcb_get_setup(c)).data;

    xtc->surface = NULL;
    xtc->is_pixmap = TRUE;
    xtc->drawable = xcb_generate_id (c);
    switch (content) {
    case CAIRO_CONTENT_COLOR:
	depth = 24;
	cookie = xcb_create_pixmap_checked (c, depth,
					    xtc->drawable, root->root,
					    width, height);
	break;

    case CAIRO_CONTENT_COLOR_ALPHA:
	depth = 32;
	cookie = xcb_create_pixmap_checked (c, depth,
					    xtc->drawable, root->root,
					    width, height);
	break;

    case CAIRO_CONTENT_ALPHA:  /* would be XCB_PICT_STANDARD_A_8 */
    default:
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    /* slow, but sure */
    if (xcb_request_check (c, cookie) != NULL) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    render_format = find_depth (c, depth, &formats);
    if (render_format == NULL) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    tmp = cairo_xcb_surface_create_with_xrender_format (c, root,
							xtc->drawable,
							render_format,
							width, height);
    if (cairo_surface_status (tmp)) {
	free (formats);
	xcb_disconnect (c);
	free (xtc);
	return tmp;
    }

    xtc->device = cairo_device_reference (cairo_surface_get_device (tmp));
    cairo_xcb_device_debug_cap_xrender_version (xtc->device, 0, 0);

    /* recreate with impaired connection */
    surface = cairo_xcb_surface_create_with_xrender_format (c, root,
							    xtc->drawable,
							    render_format,
							    width, height);
    free (formats);
    cairo_surface_destroy (tmp);

    assert (cairo_surface_get_device (surface) == xtc->device);

    status = cairo_surface_set_user_data (surface, &xcb_closure_key, xtc, NULL);
    if (status == CAIRO_STATUS_SUCCESS)
	return surface;

    cairo_surface_destroy (surface);

    _cairo_boilerplate_xcb_cleanup (xtc);
    return cairo_boilerplate_surface_create_in_error (status);
}

static cairo_surface_t *
_cairo_boilerplate_xcb_create_fallback (const char		  *name,
					cairo_content_t 	   content,
					double			   width,
					double			   height,
					double			   max_width,
					double			   max_height,
					cairo_boilerplate_mode_t   mode,
					int			   id,
					void			 **closure)
{
    xcb_target_closure_t *xtc;
    xcb_connection_t *c;
    xcb_screen_t *s;
    xcb_void_cookie_t cookie;
    cairo_surface_t *tmp, *surface;
    cairo_status_t status;
    uint32_t values[] = { 1 };

    *closure = xtc = xmalloc (sizeof (xcb_target_closure_t));

    if (width == 0)
	width = 1;
    if (height == 0)
	height = 1;

    xtc->c = c = xcb_connect (NULL,NULL);
    if (xcb_connection_has_error(c)) {
	free (xtc);
	return NULL;
    }

    s = xcb_setup_roots_iterator (xcb_get_setup (c)).data;
    if (width > s->width_in_pixels || height > s->height_in_pixels) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    xtc->surface = NULL;
    xtc->is_pixmap = FALSE;
    xtc->drawable = xcb_generate_id (c);
    cookie = xcb_create_window_checked (c,
					s->root_depth,
					xtc->drawable,
					s->root,
					0, 0, width, height, 0,
					XCB_WINDOW_CLASS_INPUT_OUTPUT,
					s->root_visual,
					XCB_CW_OVERRIDE_REDIRECT,
					values);
    xcb_map_window (c, xtc->drawable);

    /* slow, but sure */
    if (xcb_request_check (c, cookie) != NULL) {
	xcb_disconnect (c);
	free (xtc);
	return NULL;
    }

    tmp = cairo_xcb_surface_create (c,
				    xtc->drawable,
				    lookup_visual (s, s->root_visual),
				    width, height);
    if (cairo_surface_status (tmp)) {
	xcb_disconnect (c);
	free (xtc);
	return tmp;
    }

    cairo_xcb_device_debug_cap_xrender_version (cairo_surface_get_device (tmp),
						-1, -1);
    /* recreate with impaired connection */
    surface = cairo_xcb_surface_create (c,
					xtc->drawable,
					lookup_visual (s, s->root_visual),
					width, height);
    cairo_surface_destroy (tmp);

    xtc->device = cairo_device_reference (cairo_surface_get_device (surface));
    status = cairo_surface_set_user_data (surface, &xcb_closure_key, xtc, NULL);
    if (status == CAIRO_STATUS_SUCCESS)
	return surface;

    cairo_surface_destroy (surface);

    _cairo_boilerplate_xcb_cleanup (xtc);
    return cairo_boilerplate_surface_create_in_error (status);
}

static cairo_status_t
_cairo_boilerplate_xcb_finish_surface (cairo_surface_t *surface)
{
    xcb_target_closure_t *xtc = cairo_surface_get_user_data (surface,
							     &xcb_closure_key);
    cairo_status_t status;

    if (xtc->surface != NULL) {
	cairo_t *cr;

	cr = cairo_create (xtc->surface);
	cairo_surface_set_device_offset (surface, 0, 0);
	cairo_set_source_surface (cr, surface, 0, 0);
	cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
	cairo_paint (cr);
	cairo_destroy (cr);

	surface = xtc->surface;
    }

    cairo_surface_flush (surface);
    if (cairo_surface_status (surface))
	return cairo_surface_status (surface);

    /* First synchronize with the X server to make sure there are no more errors
     * in-flight which we would miss otherwise */
    _cairo_boilerplate_xcb_sync_server (xtc);
    status = _cairo_boilerplate_xcb_handle_errors (xtc);
    if (status)
	return status;

    if (xcb_connection_has_error (xtc->c))
	return CAIRO_STATUS_WRITE_ERROR;

    return CAIRO_STATUS_SUCCESS;
}

static const cairo_boilerplate_target_t targets[] = {
    /* Acceleration architectures may make the results differ by a
     * bit, so we set the error tolerance to 1. */
    {
	"xcb", "xlib", NULL, NULL,
	CAIRO_SURFACE_TYPE_XCB, CAIRO_CONTENT_COLOR_ALPHA, 1,
	"cairo_xcb_surface_create_with_xrender_format",
	_cairo_boilerplate_xcb_create_surface,
	NULL,
	_cairo_boilerplate_xcb_finish_surface,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_xcb_cleanup,
	_cairo_boilerplate_xcb_synchronize,
        NULL,
	TRUE, FALSE, FALSE
    },
    {
	"xcb", "xlib", NULL, NULL,
	CAIRO_SURFACE_TYPE_XCB, CAIRO_CONTENT_COLOR, 1,
	"cairo_xcb_surface_create_with_xrender_format",
	_cairo_boilerplate_xcb_create_surface,
	NULL,
	_cairo_boilerplate_xcb_finish_surface,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_xcb_cleanup,
	_cairo_boilerplate_xcb_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
    {
	"xcb-window", "xlib", NULL, NULL,
	CAIRO_SURFACE_TYPE_XCB, CAIRO_CONTENT_COLOR, 1,
	"cairo_xcb_surface_create_with_xrender_format",
	_cairo_boilerplate_xcb_create_window,
	NULL,
	_cairo_boilerplate_xcb_finish_surface,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_xcb_cleanup,
	_cairo_boilerplate_xcb_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
    {
	"xcb-window&", "xlib", NULL, NULL,
	CAIRO_SURFACE_TYPE_XCB, CAIRO_CONTENT_COLOR, 1,
	"cairo_xcb_surface_create_with_xrender_format",
	_cairo_boilerplate_xcb_create_window_db,
	NULL,
	_cairo_boilerplate_xcb_finish_surface,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_xcb_cleanup,
	_cairo_boilerplate_xcb_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
    {
	"xcb-render-0.0", "xlib-fallback", NULL, NULL,
	CAIRO_SURFACE_TYPE_XCB, CAIRO_CONTENT_COLOR_ALPHA, 1,
	"cairo_xcb_surface_create_with_xrender_format",
	_cairo_boilerplate_xcb_create_render_0_0,
	NULL,
	_cairo_boilerplate_xcb_finish_surface,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_xcb_cleanup,
	_cairo_boilerplate_xcb_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
    {
	"xcb-render-0.0", "xlib-fallback", NULL, NULL,
	CAIRO_SURFACE_TYPE_XCB, CAIRO_CONTENT_COLOR, 1,
	"cairo_xcb_surface_create_with_xrender_format",
	_cairo_boilerplate_xcb_create_render_0_0,
	NULL,
	_cairo_boilerplate_xcb_finish_surface,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_xcb_cleanup,
	_cairo_boilerplate_xcb_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
    {
	"xcb-fallback", "xlib-fallback", NULL, NULL,
	CAIRO_SURFACE_TYPE_XCB, CAIRO_CONTENT_COLOR, 1,
	"cairo_xcb_surface_create_with_xrender_format",
	_cairo_boilerplate_xcb_create_fallback,
	NULL,
	_cairo_boilerplate_xcb_finish_surface,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_xcb_cleanup,
	_cairo_boilerplate_xcb_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
};
CAIRO_BOILERPLATE (xcb, targets)
