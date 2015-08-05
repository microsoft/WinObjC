/* cairo - a vector graphics library with display and print output
 *
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
 * Contributor(s):
 *	Chris Wilson <chris@chris-wilson.co.uk>
 */

/* This isn't a "real" surface, but just something to be used by the
 * test suite to test a mythical backend that does nothing, i.e. it
 * solely useful for measuring the overhead of the cairo public API.
 */

#include "cairoint.h"

#include "test-null-surface.h"

#include "cairo-error-private.h"

slim_hidden_proto (_cairo_test_null_surface_create);

static cairo_int_status_t
_return_success (void)
{
    return CAIRO_STATUS_SUCCESS;
}

/* These typedefs are just to silence the compiler... */
typedef cairo_int_status_t
(*_paint_func)			(void			*surface,
			         cairo_operator_t	 op,
				 const cairo_pattern_t	*source,
				 cairo_clip_t		*clip);

typedef cairo_int_status_t
(*_mask_func)			(void			*surface,
			         cairo_operator_t	 op,
				 const cairo_pattern_t	*source,
				 const cairo_pattern_t	*mask,
				 cairo_clip_t		*clip);

typedef cairo_int_status_t
(*_stroke_func)			(void			*surface,
			         cairo_operator_t	 op,
				 const cairo_pattern_t	*source,
				 cairo_path_fixed_t	*path,
				 const cairo_stroke_style_t	*style,
				 const cairo_matrix_t		*ctm,
				 const cairo_matrix_t		*ctm_inverse,
				 double			 tolerance,
				 cairo_antialias_t	 antialias,
				 cairo_clip_t		*clip);

typedef cairo_int_status_t
(*_fill_func)			(void			*surface,
			         cairo_operator_t	 op,
				 const cairo_pattern_t	*source,
				 cairo_path_fixed_t	*path,
				 cairo_fill_rule_t	 fill_rule,
				 double			 tolerance,
				 cairo_antialias_t	 antialias,
				 cairo_clip_t		*clip);

typedef cairo_int_status_t
(*_show_glyphs_func)		(void			*surface,
			         cairo_operator_t	 op,
				 const cairo_pattern_t	*source,
				 cairo_glyph_t		*glyphs,
				 int			 num_glyphs,
				 cairo_scaled_font_t	*scaled_font,
				 cairo_clip_t		*clip,
				 int			*remaining_glyphs);

typedef cairo_int_status_t
(*_show_text_glyphs_func)	(void			    *surface,
				 cairo_operator_t	     op,
				 const cairo_pattern_t	    *source,
				 const char		    *utf8,
				 int			     utf8_len,
				 cairo_glyph_t		    *glyphs,
				 int			     num_glyphs,
				 const cairo_text_cluster_t *clusters,
				 int			     num_clusters,
				 cairo_text_cluster_flags_t  cluster_flags,
				 cairo_scaled_font_t	    *scaled_font,
				 cairo_clip_t		    *clip);

static cairo_surface_t *
_cairo_null_surface_create_similar (void *other,
				    cairo_content_t content,
				    int width, int height)
{
    return _cairo_test_null_surface_create (content);
}

static cairo_bool_t
_cairo_null_surface_get_extents (void *surface,
				 cairo_rectangle_int_t *extents)
{
    return FALSE;
}

static cairo_bool_t
_cairo_null_surface_has_show_text_glyphs (void *surface)
{
    return TRUE;
}

static const cairo_surface_backend_t null_surface_backend = {
    CAIRO_INTERNAL_SURFACE_TYPE_NULL,

    _cairo_null_surface_create_similar,
    NULL, /* finish */
    NULL, /* acquire_source_image */
    NULL, /* release_source_image */
    NULL, /* acquire_dest_image */
    NULL, /* release_dest_image */
    NULL, /* clone_similar */
    NULL, /* composite */
    NULL, /* fill_rectangles */
    NULL, /* composite_trapezoids */
    NULL, /* create_span_renderer */
    NULL, /* check_span_renderer */
    NULL, /* copy_page */
    NULL, /* show_page */
    _cairo_null_surface_get_extents,
    NULL, /* old_show_glyphs */
    NULL, /* get_font_options */
    NULL, /* flush */
    NULL, /* mark_dirty_rectangle */
    NULL, /* scaled_font_fini */
    NULL, /* scaled_glyph_fini */
    (_paint_func) _return_success,	    /* paint */
    (_mask_func) _return_success,	    /* mask */
    (_stroke_func) _return_success,	    /* stroke */
    (_fill_func) _return_success,	    /* fill */
    (_show_glyphs_func) _return_success,    /* show_glyphs */
    NULL, /* snapshot */
    NULL, /* is_similar */
    NULL, /* fill_stroke */
    NULL, /* create_solid_pattern_surface */
    NULL, /* can_repaint_solid_pattern_surface */
    _cairo_null_surface_has_show_text_glyphs,
    (_show_text_glyphs_func) _return_success,    /* show_text_glyphs */
};

cairo_surface_t *
_cairo_test_null_surface_create (cairo_content_t content)
{
    cairo_surface_t *surface;

    surface = malloc (sizeof (cairo_surface_t));
    if (unlikely (surface == NULL)) {
	return _cairo_surface_create_in_error (_cairo_error (CAIRO_STATUS_NO_MEMORY));
    }

    _cairo_surface_init (surface,
			 &null_surface_backend,
			 NULL, /* device */
			 content);

    return surface;
}
slim_hidden_def (_cairo_test_null_surface_create);
