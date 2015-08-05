/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2009 Intel Corporation
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
 * Contributor(s):
 *	Chris Wilson <chris@chris-wilson.co.uk>
 */

#include "cairoint.h"

#include "cairo-clip-private.h"
#include "cairo-xcb-private.h"

cairo_int_status_t
_cairo_xcb_surface_cairo_paint (cairo_xcb_surface_t	*surface,
				cairo_operator_t	 op,
				const cairo_pattern_t	*source,
				cairo_clip_t		*clip)
{
    return CAIRO_INT_STATUS_UNSUPPORTED;
}

cairo_int_status_t
_cairo_xcb_surface_cairo_mask (cairo_xcb_surface_t	*surface,
			       cairo_operator_t		 op,
			       const cairo_pattern_t	*source,
			       const cairo_pattern_t	*mask,
			       cairo_clip_t		*clip)
{
    return CAIRO_INT_STATUS_UNSUPPORTED;
}

cairo_int_status_t
_cairo_xcb_surface_cairo_stroke (cairo_xcb_surface_t	*surface,
				 cairo_operator_t	 op,
				 const cairo_pattern_t	*source,
				 cairo_path_fixed_t	*path,
				 const cairo_stroke_style_t	*style,
				 const cairo_matrix_t		*ctm,
				 const cairo_matrix_t		*ctm_inverse,
				 double			 tolerance,
				 cairo_antialias_t	 antialias,
				 cairo_clip_t		*clip)
{
    return CAIRO_INT_STATUS_UNSUPPORTED;
}

cairo_int_status_t
_cairo_xcb_surface_cairo_fill (cairo_xcb_surface_t	*surface,
			       cairo_operator_t		 op,
			       const cairo_pattern_t	*source,
			       cairo_path_fixed_t	*path,
			       cairo_fill_rule_t	 fill_rule,
			       double			 tolerance,
			       cairo_antialias_t	 antialias,
			       cairo_clip_t		*clip)
{
    return CAIRO_INT_STATUS_UNSUPPORTED;
}

cairo_int_status_t
_cairo_xcb_surface_cairo_glyphs (cairo_xcb_surface_t	*surface,
				 cairo_operator_t		 op,
				 const cairo_pattern_t	*source,
				 cairo_scaled_font_t	*scaled_font,
				 cairo_glyph_t		*glyphs,
				 int			 num_glyphs,
				 cairo_clip_t		*clip)
{
    return CAIRO_INT_STATUS_UNSUPPORTED;
}
