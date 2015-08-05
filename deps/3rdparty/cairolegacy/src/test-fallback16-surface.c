/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2005 Red Hat, Inc
 * Copyright © 2009 Chris Wilson
 *
 * This library is free software; you can redistribute it and/or
 * modify it either under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * (the "LGPL") or, at your option, under the terms of the Mozilla
 * Public License Version 1.1 (the "MPL"). If you do not alter this
 * notice, a recipient may use your version of this file under either
 * the MPL or the LGPL.
 *
 * You should have received a copy of the LGPL along with this library
 * in the file COPYING-LGPL-2.1; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA
 * You should have received a copy of the MPL along with this library
 * in the file COPYING-MPL-1.1
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY
 * OF ANY KIND, either express or implied. See the LGPL or the MPL for
 * the specific language governing rights and limitations.
 *
 * The Original Code is the cairo graphics library.
 *
 * The Initial Developer of the Original Code is Red Hat, Inc.
 *
 * Contributor(s):
 *	Carl Worth <cworth@cworth.org>
 *	Chris Wilson <chris@chris-wilson.co.uk>
 */

/* This isn't a "real" surface, but just something to be used by the
 * test suite to force use of a non-standard pixman image fallback - as
 * may be exposed by xlib fallbacks with weird xservers, for example.
 */

#include "cairoint.h"

#include "test-fallback16-surface.h"
#include "cairo-error-private.h"

typedef struct _test_fallback16_surface {
    cairo_surface_t base;

    /* This is a cairo_image_surface to hold the actual contents. */
    cairo_surface_t *backing;
} test_fallback16_surface_t;

static const cairo_surface_backend_t test_fallback16_surface_backend;

slim_hidden_proto (_cairo_test_fallback16_surface_create);

cairo_surface_t *
_cairo_test_fallback16_surface_create (cairo_content_t	content,
				       int		width,
				       int		height)
{
    test_fallback16_surface_t *surface;
    cairo_surface_t *backing;
    pixman_format_code_t format;

    format = content & CAIRO_CONTENT_ALPHA ?  PIXMAN_a1r5g5b5: PIXMAN_r5g6b5;

    backing = _cairo_image_surface_create_with_pixman_format (NULL, format,
							      width, height,
							      -1);
    if (cairo_surface_status (backing))
	return backing;

    surface = malloc (sizeof (test_fallback16_surface_t));
    if (unlikely (surface == NULL)) {
	cairo_surface_destroy (backing);
	return _cairo_surface_create_in_error (_cairo_error (CAIRO_STATUS_NO_MEMORY));
    }

    _cairo_surface_init (&surface->base,
			 &test_fallback16_surface_backend,
			 NULL, /* device */
			 content);

    surface->backing = backing;

    return &surface->base;
}
slim_hidden_def (_cairo_test_fallback16_surface_create);

static cairo_surface_t *
_test_fallback16_surface_create_similar (void		*abstract_surface,
					 cairo_content_t content,
					 int		 width,
					 int		 height)
{
    assert (CAIRO_CONTENT_VALID (content));

    return _cairo_test_fallback16_surface_create (content, width, height);
}

static cairo_status_t
_test_fallback16_surface_finish (void *abstract_surface)
{
    test_fallback16_surface_t *surface = abstract_surface;

    cairo_surface_destroy (surface->backing);

    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_test_fallback16_surface_acquire_source_image (void	     *abstract_surface,
					       cairo_image_surface_t **image_out,
					       void		 **image_extra)
{
    test_fallback16_surface_t *surface = abstract_surface;

    return _cairo_surface_acquire_source_image (surface->backing,
						image_out, image_extra);
}

static void
_test_fallback16_surface_release_source_image (void	     *abstract_surface,
					       cairo_image_surface_t	*image,
					       void		  *image_extra)
{
    test_fallback16_surface_t *surface = abstract_surface;

    _cairo_surface_release_source_image (surface->backing,
					 image, image_extra);
}

static cairo_status_t
_test_fallback16_surface_acquire_dest_image (void		           *abstract_surface,
					     cairo_rectangle_int_t   *interest_rect,
					     cairo_image_surface_t  **image_out,
					     cairo_rectangle_int_t   *image_rect_out,
					     void			  **image_extra)
{
    test_fallback16_surface_t *surface = abstract_surface;

    return _cairo_surface_acquire_dest_image (surface->backing,
					      interest_rect,
					      image_out,
					      image_rect_out,
					      image_extra);
}

static void
_test_fallback16_surface_release_dest_image (void			   *abstract_surface,
					     cairo_rectangle_int_t   *interest_rect,
					     cairo_image_surface_t   *image,
					     cairo_rectangle_int_t   *image_rect,
					     void			   *image_extra)
{
    test_fallback16_surface_t *surface = abstract_surface;

    _cairo_surface_release_dest_image (surface->backing,
				       interest_rect,
				       image,
				       image_rect,
				       image_extra);
}

static cairo_status_t
_test_fallback16_surface_clone_similar (void		  *abstract_surface,
					cairo_surface_t     *src,
					int                  src_x,
					int                  src_y,
					int                  width,
					int                  height,
					int                 *clone_offset_x,
					int                 *clone_offset_y,
					cairo_surface_t    **clone_out)
{
    test_fallback16_surface_t *surface = abstract_surface;

    if (src->backend == surface->base.backend) {
	*clone_offset_x = 0;
	*clone_offset_y = 0;
	*clone_out = cairo_surface_reference (src);

	return CAIRO_STATUS_SUCCESS;
    } else {
	return _cairo_surface_clone_similar (surface->backing, src,
					     src_x, src_y,
					     width, height,
					     clone_offset_x, clone_offset_y,
					     clone_out);
    }
}

static cairo_bool_t
_test_fallback16_surface_get_extents (void		  *abstract_surface,
				      cairo_rectangle_int_t *rectangle)
{
    test_fallback16_surface_t *surface = abstract_surface;

    return _cairo_surface_get_extents (surface->backing, rectangle);
}

static const cairo_surface_backend_t test_fallback16_surface_backend = {
    CAIRO_INTERNAL_SURFACE_TYPE_TEST_FALLBACK,
    _test_fallback16_surface_create_similar,
    _test_fallback16_surface_finish,
    _test_fallback16_surface_acquire_source_image,
    _test_fallback16_surface_release_source_image,
    _test_fallback16_surface_acquire_dest_image,
    _test_fallback16_surface_release_dest_image,
    _test_fallback16_surface_clone_similar,
    NULL, /* composite */
    NULL, /* fill_rectangles */
    NULL, /* composite_trapezoids */
    NULL, /* create_span_renderer */
    NULL, /* check_span_renderer */
    NULL, /* copy_page */
    NULL, /* show_page */
    _test_fallback16_surface_get_extents,
    NULL, /* old_show_glyphs */
    NULL, /* get_font_options */
    NULL, /* flush */
    NULL, /* mark_dirty_rectangle */
    NULL, /* scaled_font_fini */
    NULL, /* scaled_glyph_fini */
    NULL, /* paint */
    NULL, /* mask */
    NULL, /* stroke */
    NULL, /* fill */
    NULL, /* show_glyphs */
    NULL  /* snapshot */
};
