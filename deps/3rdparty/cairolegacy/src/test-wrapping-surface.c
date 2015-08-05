/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2005 Red Hat, Inc
 * Copyright © Chris Wilson
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

/* Another mythical surface that exists to simply wrap another - do nothing
 * itself but forward the calls onto a target surface.
 */

#include "cairoint.h"

#include "test-wrapping-surface.h"

#include "cairo-error-private.h"
#include "cairo-surface-wrapper-private.h"

typedef struct _test_wrapping_surface {
    cairo_surface_t base;
    cairo_surface_wrapper_t wrapper;
} test_wrapping_surface_t;

static const cairo_surface_backend_t test_wrapping_surface_backend;

slim_hidden_proto (_cairo_test_wrapping_surface_create);

cairo_surface_t *
_cairo_test_wrapping_surface_create (cairo_surface_t *target)
{
    test_wrapping_surface_t *surface;

    if (unlikely (target->status))
	return _cairo_surface_create_in_error (target->status);

    surface = malloc (sizeof (test_wrapping_surface_t));
    if (unlikely (surface == NULL))
	return _cairo_surface_create_in_error (_cairo_error (CAIRO_STATUS_NO_MEMORY));

    _cairo_surface_init (&surface->base,
			 &test_wrapping_surface_backend,
			 NULL, /* device */
			 target->content);

    _cairo_surface_wrapper_init (&surface->wrapper, target);

    return &surface->base;
}
slim_hidden_def (_cairo_test_wrapping_surface_create);

static cairo_surface_t *
_test_wrapping_surface_create_similar (void		*abstract_surface,
				       cairo_content_t	 content,
				       int		 width,
				       int		 height)
{

    test_wrapping_surface_t *surface = abstract_surface;

    return _cairo_test_wrapping_surface_create (
	_cairo_surface_wrapper_create_similar (&surface->wrapper,
					       content, width, height));
}

static cairo_status_t
_test_wrapping_surface_finish (void *abstract_surface)
{
    test_wrapping_surface_t *surface = abstract_surface;

    _cairo_surface_wrapper_fini (&surface->wrapper);

    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_test_wrapping_surface_acquire_source_image (void	     *abstract_surface,
					     cairo_image_surface_t **image_out,
					     void		 **image_extra)
{
    test_wrapping_surface_t *surface = abstract_surface;

    return _cairo_surface_wrapper_acquire_source_image (&surface->wrapper,
							image_out, image_extra);
}

static void
_test_wrapping_surface_release_source_image (void	     *abstract_surface,
					     cairo_image_surface_t	*image,
					     void		  *image_extra)
{
    test_wrapping_surface_t *surface = abstract_surface;

    _cairo_surface_wrapper_release_source_image (&surface->wrapper,
						 image, image_extra);
}

static cairo_bool_t
_test_wrapping_surface_get_extents (void		  *abstract_surface,
				    cairo_rectangle_int_t *rectangle)
{
    test_wrapping_surface_t *surface = abstract_surface;

    return _cairo_surface_wrapper_get_extents (&surface->wrapper, rectangle);
}

static cairo_int_status_t
_test_wrapping_surface_paint (void		*abstract_surface,
			       cairo_operator_t	 op,
			       const cairo_pattern_t	*source,
			       cairo_clip_t		*clip)
{
    test_wrapping_surface_t *surface = abstract_surface;

    return _cairo_surface_wrapper_paint (&surface->wrapper, op, source, clip);
}

static cairo_int_status_t
_test_wrapping_surface_mask (void		*abstract_surface,
			      cairo_operator_t	 op,
			      const cairo_pattern_t	*source,
			      const cairo_pattern_t	*mask,
			      cairo_clip_t		*clip)
{
    test_wrapping_surface_t *surface = abstract_surface;

    return _cairo_surface_wrapper_mask (&surface->wrapper,
					op, source, mask, clip);
}

static cairo_int_status_t
_test_wrapping_surface_stroke (void				*abstract_surface,
				cairo_operator_t		 op,
				const cairo_pattern_t		*source,
				cairo_path_fixed_t		*path,
				const cairo_stroke_style_t		*style,
				const cairo_matrix_t			*ctm,
				const cairo_matrix_t			*ctm_inverse,
				double				 tolerance,
				cairo_antialias_t		 antialias,
				cairo_clip_t			*clip)
{
    test_wrapping_surface_t *surface = abstract_surface;

    return _cairo_surface_wrapper_stroke (&surface->wrapper,
					  op, source,
					  path, style,
					  ctm, ctm_inverse,
					  tolerance, antialias,
					  clip);
}

static cairo_int_status_t
_test_wrapping_surface_fill (void				*abstract_surface,
			      cairo_operator_t			 op,
			      const cairo_pattern_t		*source,
			      cairo_path_fixed_t		*path,
			      cairo_fill_rule_t			 fill_rule,
			      double				 tolerance,
			      cairo_antialias_t			 antialias,
			      cairo_clip_t			*clip)
{
    test_wrapping_surface_t *surface = abstract_surface;

    return _cairo_surface_wrapper_fill (&surface->wrapper,
					op, source,
					path, fill_rule,
					tolerance, antialias,
					clip);
}

static cairo_bool_t
_test_wrapping_surface_has_show_text_glyphs (void *abstract_surface)
{
    test_wrapping_surface_t *surface = abstract_surface;

    return _cairo_surface_wrapper_has_show_text_glyphs (&surface->wrapper);
}

static cairo_int_status_t
_test_wrapping_surface_show_text_glyphs (void			    *abstract_surface,
					  cairo_operator_t	     op,
					  const cairo_pattern_t	    *source,
					  const char		    *utf8,
					  int			     utf8_len,
					  cairo_glyph_t		    *glyphs,
					  int			     num_glyphs,
					  const cairo_text_cluster_t *clusters,
					  int			     num_clusters,
					  cairo_text_cluster_flags_t cluster_flags,
					  cairo_scaled_font_t	    *scaled_font,
					  cairo_clip_t		    *clip)
{
    test_wrapping_surface_t *surface = abstract_surface;

    return _cairo_surface_wrapper_show_text_glyphs (&surface->wrapper,
						    op, source,
						    utf8, utf8_len,
						    glyphs, num_glyphs,
						    clusters, num_clusters,
						    cluster_flags,
						    scaled_font,
						    clip);
}

static const cairo_surface_backend_t test_wrapping_surface_backend = {
    CAIRO_INTERNAL_SURFACE_TYPE_TEST_WRAPPING,
    _test_wrapping_surface_create_similar,
    _test_wrapping_surface_finish,
    _test_wrapping_surface_acquire_source_image,
    _test_wrapping_surface_release_source_image,
    NULL, NULL, /* dest_image */
    NULL, /* clone_similar */
    NULL, /* composite */
    NULL, /* fill_rectangles */
    NULL, /* composite_trapezoids */
    NULL, /* create_span_renderer */
    NULL, /* check_span_renderer */
    NULL, /* copy_page */
    NULL, /* show_page */
    _test_wrapping_surface_get_extents,
    NULL, /* old_show_glyphs */
    NULL, /* get_font_options */
    NULL, /* flush */
    NULL, /* mark_dirty_rectangle */
    NULL, /* scaled_font_fini */
    NULL, /* scaled_glyph_fini */

    _test_wrapping_surface_paint,
    _test_wrapping_surface_mask,
    _test_wrapping_surface_stroke,
    _test_wrapping_surface_fill,
    NULL, /* replaced by show_text_glyphs */

    NULL, /* snapshot */
    NULL, /* is_similar */
    NULL, /* fill_stroke */
    NULL, /* create_solid_pattern_surface */
    NULL, /* can_repaint_solid_pattern_surface */

    _test_wrapping_surface_has_show_text_glyphs,
    _test_wrapping_surface_show_text_glyphs

	/* XXX wrap fill-stroke and show_glyphs */
};
