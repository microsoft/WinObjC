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

#include "cairo-boxes-private.h"
#include "cairo-clip-private.h"
#include "cairo-composite-rectangles-private.h"
#include "cairo-region-private.h"
#include "cairo-surface-offset-private.h"
#include "cairo-surface-snapshot-private.h"
#include "cairo-surface-subsurface-private.h"
#include "cairo-xcb-private.h"

#if CAIRO_HAS_XCB_DRM_FUNCTIONS && CAIRO_HAS_DRM_SURFACE
#include "drm/cairo-drm-private.h"
#endif

#define PIXMAN_MAX_INT ((pixman_fixed_1 >> 1) - pixman_fixed_e) /* need to ensure deltas also fit */

/**
 * SECTION:cairo-xcb-xrender
 * @Title: XCB Surfaces
 * @Short_Description: X Window System rendering using the XCB library and the X Render extension
 * @See_Also: #cairo_surface_t
 *
 * The XCB surface is used to render cairo graphics to X Window System
 * windows and pixmaps using the XCB library and its X Render extension.
 *
 * Note that the XCB surface automatically takes advantage of the X Render
 * extension if it is available.
 */

typedef struct _cairo_xcb_picture {
    cairo_surface_t base;

    cairo_surface_t *owner;

    cairo_xcb_screen_t *screen;
    xcb_render_picture_t picture;
    xcb_render_pictformat_t xrender_format;
    pixman_format_code_t pixman_format;

    int width, height;

    cairo_extend_t extend;
    cairo_filter_t filter;
    cairo_bool_t has_component_alpha;
    xcb_render_transform_t transform;

    int x0, y0;
    int x, y;
} cairo_xcb_picture_t;

static inline cairo_xcb_connection_t *
_picture_to_connection (cairo_xcb_picture_t *picture)
{
    return (cairo_xcb_connection_t *) picture->base.device;
}

static void
_cairo_xcb_surface_ensure_picture (cairo_xcb_surface_t *surface);

static uint32_t
hars_petruska_f54_1_random (void)
{
#define rol(x,k) ((x << k) | (x >> (32-k)))
    static uint32_t x;
    return x = (x ^ rol (x, 5) ^ rol (x, 24)) + 0x37798849;
#undef rol
}

static cairo_status_t
_cairo_xcb_picture_finish (void *abstract_surface)
{
    cairo_xcb_picture_t *surface = abstract_surface;
    cairo_xcb_connection_t *connection = _picture_to_connection (surface);
    cairo_status_t status;

    if (surface->owner != NULL)
	cairo_surface_destroy (surface->owner);

    status = _cairo_xcb_connection_acquire (connection);
    if (unlikely (status))
	return status;

    _cairo_xcb_screen_remove_surface_picture (surface->screen, &surface->base);

    if (surface->owner == NULL) {
	if (_cairo_xcb_connection_take_socket (connection) == CAIRO_STATUS_SUCCESS)
	    _cairo_xcb_connection_render_free_picture (connection, surface->picture);
    }

    _cairo_xcb_connection_release (connection);

    return CAIRO_STATUS_SUCCESS;
}

static const cairo_surface_backend_t _cairo_xcb_picture_backend = {
    CAIRO_SURFACE_TYPE_XCB,
    NULL,
    _cairo_xcb_picture_finish,
};

static const struct xcb_render_transform_t identity_transform = {
    1 << 16, 0, 0,
    0, 1 << 16, 0,
    0, 0, 1 << 16,
};

static cairo_xcb_picture_t *
_cairo_xcb_picture_create (cairo_xcb_screen_t *screen,
			   pixman_format_code_t pixman_format,
			   xcb_render_pictformat_t xrender_format,
			   int width, int height)
{
    cairo_xcb_picture_t *surface;

    surface = malloc (sizeof (cairo_xcb_picture_t));
    if (unlikely (surface == NULL))
	return (cairo_xcb_picture_t *)
	    _cairo_surface_create_in_error (_cairo_error (CAIRO_STATUS_NO_MEMORY));

    _cairo_surface_init (&surface->base,
			 &_cairo_xcb_picture_backend,
			 &screen->connection->device,
			 _cairo_content_from_pixman_format (pixman_format));

    surface->screen = screen;
    surface->owner = NULL;
    surface->picture = _cairo_xcb_connection_get_xid (screen->connection);
    surface->pixman_format = pixman_format;
    surface->xrender_format = xrender_format;

    surface->x0 = surface->y0 = 0;
    surface->x = surface->y = 0;
    surface->width = width;
    surface->height = height;

    surface->transform = identity_transform;
    surface->extend = CAIRO_EXTEND_NONE;
    surface->filter = CAIRO_FILTER_NEAREST;
    surface->has_component_alpha = FALSE;

    return surface;
}

static cairo_xcb_picture_t *
_cairo_xcb_picture_copy (cairo_xcb_surface_t *target)
{
    cairo_xcb_picture_t *surface;

    surface = malloc (sizeof (cairo_xcb_picture_t));
    if (unlikely (surface == NULL))
	return (cairo_xcb_picture_t *)
	    _cairo_surface_create_in_error (_cairo_error (CAIRO_STATUS_NO_MEMORY));

    _cairo_surface_init (&surface->base,
			 &_cairo_xcb_picture_backend,
			 target->base.device,
			 target->base.content);

    surface->screen = target->screen;
    surface->owner = cairo_surface_reference (&target->base);
    _cairo_xcb_surface_ensure_picture (target);
    surface->picture = target->picture;
    surface->pixman_format = target->pixman_format;
    surface->xrender_format = target->xrender_format;

    surface->x0 = surface->y0 = 0;
    surface->x = surface->y = 0;
    surface->width = target->width;
    surface->height = target->height;

    surface->transform = identity_transform;
    surface->extend = CAIRO_EXTEND_NONE;
    surface->filter = CAIRO_FILTER_NEAREST;
    surface->has_component_alpha = FALSE;

    return surface;
}

static inline cairo_bool_t
_operator_is_supported (uint32_t flags, cairo_operator_t op)
{
    if (op <= CAIRO_OPERATOR_SATURATE)
	return TRUE;

    return flags & CAIRO_XCB_RENDER_HAS_PDF_OPERATORS;
}

static int
_render_operator (cairo_operator_t op)
{
#define C(x,y) case CAIRO_OPERATOR_##x: return XCB_RENDER_PICT_OP_##y
    switch (op) {
    C(CLEAR, CLEAR);
    C(SOURCE, SRC);

    C(OVER, OVER);
    C(IN, IN);
    C(OUT, OUT);
    C(ATOP, ATOP);

    C(DEST, DST);
    C(DEST_OVER, OVER_REVERSE);
    C(DEST_IN, IN_REVERSE);
    C(DEST_OUT, OUT_REVERSE);
    C(DEST_ATOP, ATOP_REVERSE);

    C(XOR, XOR);
    C(ADD, ADD);
    C(SATURATE, SATURATE);

    case CAIRO_OPERATOR_MULTIPLY:
    case CAIRO_OPERATOR_SCREEN:
    case CAIRO_OPERATOR_OVERLAY:
    case CAIRO_OPERATOR_DARKEN:
    case CAIRO_OPERATOR_LIGHTEN:
    case CAIRO_OPERATOR_COLOR_DODGE:
    case CAIRO_OPERATOR_COLOR_BURN:
    case CAIRO_OPERATOR_HARD_LIGHT:
    case CAIRO_OPERATOR_SOFT_LIGHT:
    case CAIRO_OPERATOR_DIFFERENCE:
    case CAIRO_OPERATOR_EXCLUSION:
    case CAIRO_OPERATOR_HSL_HUE:
    case CAIRO_OPERATOR_HSL_SATURATION:
    case CAIRO_OPERATOR_HSL_COLOR:
    case CAIRO_OPERATOR_HSL_LUMINOSITY:
    default:
	ASSERT_NOT_REACHED;
	return XCB_RENDER_PICT_OP_OVER;
    }
}

static void
_cairo_xcb_surface_set_clip_region (cairo_xcb_surface_t *surface,
				    cairo_region_t	*region)
{
    xcb_rectangle_t rects[CAIRO_STACK_ARRAY_LENGTH (xcb_rectangle_t)];
    int i, num_rects;

    num_rects = cairo_region_num_rectangles (region);
    assert (num_rects < ARRAY_LENGTH (rects)); /* XXX somebody will! */

    for (i = 0; i < num_rects; i++) {
	cairo_rectangle_int_t rect;

	cairo_region_get_rectangle (region, i, &rect);

	rects[i].x = rect.x;
	rects[i].y = rect.y;
	rects[i].width  = rect.width;
	rects[i].height = rect.height;
    }

    _cairo_xcb_connection_render_set_picture_clip_rectangles (surface->connection,
							      surface->picture,
							      0, 0,
							      num_rects, rects);
}

static void
_cairo_xcb_surface_clear_clip_region (cairo_xcb_surface_t *surface)
{
    uint32_t values[] = { XCB_NONE };
    _cairo_xcb_connection_render_change_picture (surface->connection,
						 surface->picture,
						 XCB_RENDER_CP_CLIP_MASK, values);
}

static void
_cairo_xcb_surface_ensure_picture (cairo_xcb_surface_t *surface)
{
    if (surface->picture == XCB_NONE) {
	surface->picture = _cairo_xcb_connection_get_xid (surface->connection);
	_cairo_xcb_connection_render_create_picture (surface->connection,
						     surface->picture,
						     surface->drawable,
						     surface->xrender_format,
						     0, NULL);
    }
}

static cairo_xcb_picture_t *
_picture_from_image (cairo_xcb_surface_t *target,
		     xcb_render_pictformat_t format,
		     cairo_image_surface_t *image,
		     cairo_xcb_shm_info_t *shm_info)
{
    xcb_pixmap_t pixmap;
    xcb_gcontext_t gc;
    cairo_xcb_picture_t *picture;

    pixmap = _cairo_xcb_connection_create_pixmap (target->connection,
						  image->depth,
						  target->drawable,
						  image->width, image->height);

    gc = _cairo_xcb_screen_get_gc (target->screen, pixmap, image->depth);

    if (shm_info != NULL) {
	shm_info->seqno =
	    _cairo_xcb_connection_shm_put_image (target->connection,
						 pixmap, gc,
						 image->width, image->height,
						 0, 0,
						 image->width, image->height,
						 0, 0,
						 image->depth,
						 shm_info->shm,
						 shm_info->offset);
    } else {
	int len;

	/* Do we need to trim the image? */
	len = CAIRO_STRIDE_FOR_WIDTH_BPP (image->width, PIXMAN_FORMAT_BPP (image->pixman_format));
	if (len == image->stride) {
	    _cairo_xcb_connection_put_image (target->connection,
					     pixmap, gc,
					     image->width, image->height,
					     0, 0,
					     image->depth,
					     image->stride,
					     image->data);
	} else {
	    _cairo_xcb_connection_put_subimage (target->connection,
						pixmap, gc,
						0, 0,
						image->width, image->height,
						PIXMAN_FORMAT_BPP (image->pixman_format) / 8,
						image->stride,
						0, 0,
						image->depth,
						image->data);

	}
    }

    _cairo_xcb_screen_put_gc (target->screen, image->depth, gc);

    picture = _cairo_xcb_picture_create (target->screen,
					 image->pixman_format, format,
					 image->width, image->height);
    if (likely (picture->base.status == CAIRO_STATUS_SUCCESS)) {
	_cairo_xcb_connection_render_create_picture (target->connection,
						     picture->picture, pixmap, format,
						     0, 0);
    }

    _cairo_xcb_connection_free_pixmap (target->connection, pixmap);

    return picture;
}

static cairo_bool_t
_pattern_is_supported (uint32_t flags,
		       const cairo_pattern_t *pattern)

{
    if (pattern->type == CAIRO_PATTERN_TYPE_SOLID)
	return TRUE;

    if (! _cairo_matrix_is_integer_translation (&pattern->matrix, NULL, NULL)) {
	if ((flags & CAIRO_XCB_RENDER_HAS_PICTURE_TRANSFORM) == 0)
	    return FALSE;
    }

    switch (pattern->extend) {
    default:
	ASSERT_NOT_REACHED;
    case CAIRO_EXTEND_NONE:
    case CAIRO_EXTEND_REPEAT:
	break;
    case CAIRO_EXTEND_PAD:
    case CAIRO_EXTEND_REFLECT:
	if ((flags & CAIRO_XCB_RENDER_HAS_EXTENDED_REPEAT) == 0)
	    return FALSE;
    }

    if (pattern->type == CAIRO_PATTERN_TYPE_SURFACE) {
	cairo_filter_t filter;

	filter = pattern->filter;
	if (_cairo_matrix_has_unity_scale (&pattern->matrix) &&
	    _cairo_matrix_is_integer_translation (&pattern->matrix, NULL, NULL))
	{
	    filter = CAIRO_FILTER_NEAREST;
	}

	if (! (filter == CAIRO_FILTER_NEAREST || filter == CAIRO_FILTER_FAST)) {
	    if ((flags & CAIRO_XCB_RENDER_HAS_FILTERS) == 0)
		return FALSE;
	}
    } else { /* gradient */
	if ((flags & CAIRO_XCB_RENDER_HAS_GRADIENTS) == 0)
	    return FALSE;
    }

    return TRUE;
}

static double
_pixman_nearest_sample (double d)
{
    return ceil (d - .5);
}

static cairo_bool_t
_nearest_sample (const cairo_matrix_t *m,
		 cairo_filter_t filter,
		 double *tx, double *ty)
{
    *tx = m->x0;
    *ty = m->y0;
    if ((filter == CAIRO_FILTER_FAST || filter == CAIRO_FILTER_NEAREST)
       && _cairo_matrix_has_unity_scale (m))
    {
	*tx = _pixman_nearest_sample (*tx);
	*ty = _pixman_nearest_sample (*ty);
    }
    else
    {
	if (*tx != floor (*tx) || *ty != floor (*ty))
	    return FALSE;
    }
    return fabs (*tx) < PIXMAN_MAX_INT && fabs (*ty) < PIXMAN_MAX_INT;
}

static void
_cairo_xcb_picture_set_matrix (cairo_xcb_picture_t *picture,
			       const cairo_matrix_t *matrix,
			       cairo_filter_t filter,
			       double xc, double yc)
{
    cairo_matrix_t m;
    double tx, ty;

    m = *matrix;
    if (_nearest_sample (&m, filter, &tx, &ty))
	m.x0 = m.y0 = 0;
    else
	tx = ty = 0;

    if (! _cairo_matrix_is_identity (&m)) {
	xcb_render_transform_t transform;
	cairo_matrix_t inv;
	cairo_status_t status;

	inv = m;
	status = cairo_matrix_invert (&inv);
	assert (status == CAIRO_STATUS_SUCCESS);

	if (m.x0 != 0. || m.y0 != 0.) {
	    double x, y;

	    /* pixman also limits the [xy]_offset to 16 bits so evenly
	     * spread the bits between the two.
	     */
	    x = floor (inv.x0 / 2);
	    y = floor (inv.y0 / 2);
	    tx = -x;
	    ty = -y;
	    cairo_matrix_init_translate (&inv, x, y);
	    cairo_matrix_multiply (&m, &inv, &m);
	} else {
	    if (tx != 0. || ty != 0.)
		cairo_matrix_transform_point (&inv, &tx, &ty);
	}

	/* Casting between pixman_transform_t and XTransform is safe because
	 * they happen to be the exact same type.
	 */
	_cairo_matrix_to_pixman_matrix (&m,
					(pixman_transform_t *) &transform, xc, yc);

	if (memcmp (&picture->transform, &transform, sizeof (xcb_render_transform_t))) {
	    _cairo_xcb_connection_render_set_picture_transform (_picture_to_connection(picture),
								picture->picture,
								&transform);

	    picture->transform = transform;
	}
    }

    picture->x = picture->x0 + tx;
    picture->y = picture->y0 + ty;
}

static void
_cairo_xcb_picture_set_filter (cairo_xcb_picture_t *picture,
			       cairo_filter_t filter)
{
    const char *render_filter;
    int len;

    if (picture->filter == filter)
	return;

    switch (filter) {
    case CAIRO_FILTER_FAST:
	render_filter = "fast";
	len = strlen ("fast");
	break;

    case CAIRO_FILTER_GOOD:
	render_filter = "good";
	len = strlen ("good");
	break;

    case CAIRO_FILTER_BEST:
	render_filter = "best";
	len = strlen ("best");
	break;

    case CAIRO_FILTER_NEAREST:
	render_filter = "nearest";
	len = strlen ("nearest");
	break;

    case CAIRO_FILTER_BILINEAR:
	render_filter = "bilinear";
	len = strlen ("bilinear");
	break;

    default:
	ASSERT_NOT_REACHED;
    case CAIRO_FILTER_GAUSSIAN:
	render_filter = "best";
	len = strlen ("best");
	break;
    }

    _cairo_xcb_connection_render_set_picture_filter (_picture_to_connection (picture),
						     picture->picture,
						     len, (char *) render_filter);
    picture->filter = filter;
}

static void
_cairo_xcb_picture_set_extend (cairo_xcb_picture_t *picture,
			       cairo_extend_t extend)
{
    uint32_t pa[1];

    if (picture->extend == extend)
	return;

    switch (extend) {
    default:
	ASSERT_NOT_REACHED;
    case CAIRO_EXTEND_NONE:
	pa[0] = XCB_RENDER_REPEAT_NONE;
	break;

    case CAIRO_EXTEND_REPEAT:
	pa[0] = XCB_RENDER_REPEAT_NORMAL;
	break;

    case CAIRO_EXTEND_REFLECT:
	pa[0] = XCB_RENDER_REPEAT_REFLECT;
	break;

    case CAIRO_EXTEND_PAD:
	pa[0] = XCB_RENDER_REPEAT_PAD;
	break;
    }

    _cairo_xcb_connection_render_change_picture (_picture_to_connection (picture),
						 picture->picture,
						 XCB_RENDER_CP_REPEAT, pa);
    picture->extend = extend;
}

static void
_cairo_xcb_picture_set_component_alpha (cairo_xcb_picture_t *picture,
					cairo_bool_t ca)
{
    uint32_t pa[1];

    if (picture->has_component_alpha == ca)
	return;

    pa[0] = ca;

    _cairo_xcb_connection_render_change_picture (_picture_to_connection (picture),
						 picture->picture,
						 XCB_RENDER_CP_COMPONENT_ALPHA,
						 pa);
    picture->has_component_alpha = ca;
}

static cairo_xcb_picture_t *
_solid_picture (cairo_xcb_surface_t *target,
		const cairo_color_t *color)
{
    xcb_render_color_t xcb_color;
    xcb_render_pictformat_t xrender_format;
    cairo_xcb_picture_t *picture;

    xcb_color.red   = color->red_short;
    xcb_color.green = color->green_short;
    xcb_color.blue  = color->blue_short;
    xcb_color.alpha = color->alpha_short;

    xrender_format = target->screen->connection->standard_formats[CAIRO_FORMAT_ARGB32];
    picture = _cairo_xcb_picture_create (target->screen,
					 PIXMAN_a8r8g8b8,
					 xrender_format,
					 -1, -1);
    if (unlikely (picture->base.status))
	return picture;

    if (target->flags & CAIRO_XCB_RENDER_HAS_GRADIENTS) {
	_cairo_xcb_connection_render_create_solid_fill (target->connection,
							picture->picture,
							xcb_color);
    } else {
	xcb_pixmap_t pixmap;
	uint32_t values[] = { XCB_RENDER_REPEAT_NORMAL };

	pixmap = _cairo_xcb_connection_create_pixmap (target->connection,
						      32, target->drawable, 1, 1);
	_cairo_xcb_connection_render_create_picture (target->connection,
						     picture->picture,
						     pixmap,
						     xrender_format,
						     XCB_RENDER_CP_REPEAT,
						     values);
	if (target->flags & CAIRO_XCB_RENDER_HAS_FILL_RECTANGLES) {
	    xcb_rectangle_t rect;

	    rect.x = rect.y = 0;
	    rect.width = rect.height = 1;

	    _cairo_xcb_connection_render_fill_rectangles (_picture_to_connection (picture),
							  XCB_RENDER_PICT_OP_SRC,
							  picture->picture,
							  xcb_color, 1, &rect);
	} else {
	    xcb_gcontext_t gc;
	    uint32_t pixel;

	    gc = _cairo_xcb_screen_get_gc (target->screen, pixmap, 32);

	    /* XXX byte ordering? */
	    pixel = ((color->alpha_short >> 8) << 24) |
		    ((color->red_short   >> 8) << 16) |
		    ((color->green_short >> 8) << 8) |
		    ((color->blue_short  >> 8) << 0);

	    _cairo_xcb_connection_put_image (target->connection,
					     pixmap, gc,
					     1, 1, 0, 0,
					     32, 4, &pixel);

	    _cairo_xcb_screen_put_gc (target->screen, 32, gc);
	}

	_cairo_xcb_connection_free_pixmap (target->connection, pixmap);
    }

    return picture;
}

static cairo_xcb_picture_t *
_cairo_xcb_transparent_picture (cairo_xcb_surface_t *target)
{
    cairo_xcb_picture_t *picture;

    picture = (cairo_xcb_picture_t *) target->screen->stock_colors[CAIRO_STOCK_TRANSPARENT];
    if (picture == NULL) {
	picture = _solid_picture (target, CAIRO_COLOR_TRANSPARENT);
	target->screen->stock_colors[CAIRO_STOCK_TRANSPARENT] = &picture->base;
    }

    return (cairo_xcb_picture_t *) cairo_surface_reference (&picture->base);
}

static cairo_xcb_picture_t *
_cairo_xcb_black_picture (cairo_xcb_surface_t *target)
{
    cairo_xcb_picture_t *picture;

    picture = (cairo_xcb_picture_t *) target->screen->stock_colors[CAIRO_STOCK_BLACK];
    if (picture == NULL) {
	picture = _solid_picture (target, CAIRO_COLOR_BLACK);
	target->screen->stock_colors[CAIRO_STOCK_BLACK] = &picture->base;
    }

    return (cairo_xcb_picture_t *) cairo_surface_reference (&picture->base);
}

static cairo_xcb_picture_t *
_cairo_xcb_white_picture (cairo_xcb_surface_t *target)
{
    cairo_xcb_picture_t *picture;

    picture = (cairo_xcb_picture_t *) target->screen->stock_colors[CAIRO_STOCK_WHITE];
    if (picture == NULL) {
	picture = _solid_picture (target, CAIRO_COLOR_WHITE);
	target->screen->stock_colors[CAIRO_STOCK_WHITE] = &picture->base;
    }

    return (cairo_xcb_picture_t *) cairo_surface_reference (&picture->base);
}

static cairo_xcb_picture_t *
_cairo_xcb_solid_picture (cairo_xcb_surface_t *target,
			  const cairo_solid_pattern_t *pattern)
{
    cairo_xcb_picture_t *picture;
    cairo_xcb_screen_t *screen;
    int i, n_cached;

    if (pattern->color.alpha_short <= 0x00ff)
	return _cairo_xcb_transparent_picture (target);

    if (pattern->color.alpha_short >= 0xff00) {
	if (pattern->color.red_short <= 0x00ff &&
	    pattern->color.green_short <= 0x00ff &&
	    pattern->color.blue_short <= 0x00ff)
	{
	    return _cairo_xcb_black_picture (target);
	}

	if (pattern->color.red_short >= 0xff00 &&
	    pattern->color.green_short >= 0xff00 &&
	    pattern->color.blue_short >= 0xff00)
	{
	    return _cairo_xcb_white_picture (target);
	}
    }

    screen = target->screen;
    n_cached = screen->solid_cache_size;
    for (i = 0; i < n_cached; i++) {
	if (_cairo_color_equal (&screen->solid_cache[i].color, &pattern->color)) {
	    return (cairo_xcb_picture_t *) cairo_surface_reference (screen->solid_cache[i].picture);
	}
    }

    picture = _solid_picture (target, &pattern->color);
    if (unlikely (picture->base.status))
	return picture;

    if (screen->solid_cache_size < ARRAY_LENGTH (screen->solid_cache)) {
	i = screen->solid_cache_size++;
    } else {
	i = hars_petruska_f54_1_random () % ARRAY_LENGTH (screen->solid_cache);
	cairo_surface_destroy (screen->solid_cache[i].picture);
    }
    screen->solid_cache[i].picture = cairo_surface_reference (&picture->base);
    screen->solid_cache[i].color = pattern->color;

    return picture;
}

static cairo_status_t
_cairo_xcb_shm_image_create (cairo_xcb_connection_t *connection,
			     pixman_format_code_t pixman_format,
			     int width, int height,
			     cairo_image_surface_t **image_out,
			     cairo_xcb_shm_info_t **shm_info_out)
{
    cairo_surface_t *image = NULL;
    cairo_xcb_shm_info_t *shm_info = NULL;
    cairo_status_t status;

#if CAIRO_HAS_XCB_SHM_FUNCTIONS
    if ((connection->flags & CAIRO_XCB_HAS_SHM)) {
	size_t size, stride;

	stride = CAIRO_STRIDE_FOR_WIDTH_BPP (width, PIXMAN_FORMAT_BPP (pixman_format));
	size = stride * height;
	if (size > CAIRO_XCB_SHM_SMALL_IMAGE) {
	    status = _cairo_xcb_connection_allocate_shm_info (connection,
							      size, &shm_info);
	    if (unlikely (status))
		return status;

	    image = _cairo_image_surface_create_with_pixman_format (shm_info->mem,
								    pixman_format,
								    width, height,
								    stride);
	    status = image->status;
	    if (unlikely (status)) {
		_cairo_xcb_shm_info_destroy (shm_info);
		return status;
	    }

	    status = _cairo_user_data_array_set_data (&image->user_data,
						      (const cairo_user_data_key_t *) connection,
						      shm_info,
						      (cairo_destroy_func_t) _cairo_xcb_shm_info_destroy);
	    if (unlikely (status)) {
		cairo_surface_destroy (image);
		_cairo_xcb_shm_info_destroy (shm_info);
		return status;
	    }
	}
    }
#endif

    if (image == NULL) {
	image = _cairo_image_surface_create_with_pixman_format (NULL,
								pixman_format,
								width, height,
								0);
	status = image->status;
	if (unlikely (status))
	    return status;
    }

    *image_out = (cairo_image_surface_t *) image;
    *shm_info_out = shm_info;
    return CAIRO_STATUS_SUCCESS;
}

static cairo_xcb_picture_t *
_render_to_picture (cairo_xcb_surface_t *target,
		    const cairo_pattern_t *pattern,
		    const cairo_rectangle_int_t *extents)
{
    cairo_image_surface_t *image;
    cairo_xcb_shm_info_t *shm_info;
    cairo_pattern_union_t copy;
    cairo_status_t status;
    cairo_xcb_picture_t *picture;
    pixman_format_code_t pixman_format;
    xcb_render_pictformat_t xrender_format;

    /* XXX handle extend modes via tiling? */
    /* XXX alpha-only masks? */

    pixman_format = PIXMAN_a8r8g8b8;
    xrender_format = target->screen->connection->standard_formats[CAIRO_FORMAT_ARGB32];

    status = _cairo_xcb_shm_image_create (target->screen->connection,
					  pixman_format,
					  extents->width, extents->height,
					  &image, &shm_info);
    if (unlikely (status))
	return (cairo_xcb_picture_t *) _cairo_surface_create_in_error (status);

    _cairo_pattern_init_static_copy (&copy.base, pattern);
    cairo_matrix_translate (&copy.base.matrix, extents->x, extents->y);
    status = _cairo_surface_paint (&image->base,
				   CAIRO_OPERATOR_SOURCE,
				   &copy.base,
				   NULL);
    if (unlikely (status)) {
	cairo_surface_destroy (&image->base);
	return (cairo_xcb_picture_t *) _cairo_surface_create_in_error (status);
    }

    picture = _picture_from_image (target, xrender_format, image, shm_info);
    cairo_surface_destroy (&image->base);

    if (unlikely (picture->base.status))
	return picture;

    _cairo_xcb_picture_set_component_alpha (picture, pattern->has_component_alpha);
    picture->x = -extents->x;
    picture->y = -extents->y;

    return picture;
}

static xcb_render_fixed_t *
_gradient_to_xcb (const cairo_gradient_pattern_t *gradient,
		  char *buf, unsigned int buflen)
{
    xcb_render_fixed_t *stops;
    xcb_render_color_t *colors;
    unsigned int i;

    if (gradient->n_stops * (sizeof (xcb_render_fixed_t) + sizeof (xcb_render_color_t)) < buflen)
    {
	stops = (xcb_render_fixed_t *) buf;
    }
    else
    {
	stops =
	    _cairo_malloc_ab (gradient->n_stops,
			      sizeof (xcb_render_fixed_t) + sizeof (xcb_render_color_t));
	if (unlikely (stops == NULL))
	    return NULL;
    }

    colors = (xcb_render_color_t *) (stops + gradient->n_stops);
    for (i = 0; i < gradient->n_stops; i++) {
	stops[i] =
	    _cairo_fixed_16_16_from_double (gradient->stops[i].offset);

	colors[i].red   = gradient->stops[i].color.red_short;
	colors[i].green = gradient->stops[i].color.green_short;
	colors[i].blue  = gradient->stops[i].color.blue_short;
	colors[i].alpha = gradient->stops[i].color.alpha_short;
    }

    return stops;
}

static cairo_xcb_picture_t *
_cairo_xcb_linear_picture (cairo_xcb_surface_t *target,
			   const cairo_linear_pattern_t *pattern,
			   const cairo_rectangle_int_t *extents)
{
    char buf[CAIRO_STACK_BUFFER_SIZE];
    cairo_fixed_t xdim, ydim;
    xcb_render_fixed_t *stops;
    xcb_render_color_t *colors;
    xcb_render_pointfix_t p1, p2;
    cairo_matrix_t matrix = pattern->base.base.matrix;
    cairo_xcb_picture_t *picture;
    cairo_status_t status;

    picture = (cairo_xcb_picture_t *)
	_cairo_xcb_screen_lookup_linear_picture (target->screen, pattern);
    if (picture != NULL)
	goto setup_picture;

    stops = _gradient_to_xcb (&pattern->base, buf, sizeof (buf));
    if (unlikely (stops == NULL))
	return (cairo_xcb_picture_t *) _cairo_surface_create_in_error (CAIRO_STATUS_NO_MEMORY);

    picture = _cairo_xcb_picture_create (target->screen,
					 target->screen->connection->standard_formats[CAIRO_FORMAT_ARGB32],
					 PIXMAN_a8r8g8b8,
					 -1, -1);
    if (unlikely (picture->base.status)) {
	if (stops != (xcb_render_fixed_t *) buf)
	    free (stops);
	return picture;
    }
    picture->filter = CAIRO_FILTER_DEFAULT;

    xdim = pattern->p2.x - pattern->p1.x;
    ydim = pattern->p2.y - pattern->p1.y;

    /*
     * Transform the matrix to avoid overflow when converting between
     * cairo_fixed_t and pixman_fixed_t (without incurring performance
     * loss when the transformation is unnecessary).
     *
     * XXX: Consider converting out-of-range co-ordinates and transforms.
     * Having a function to compute the required transformation to
     * "normalize" a given bounding box would be generally useful -
     * cf linear patterns, gradient patterns, surface patterns...
     */
#define PIXMAN_MAX_INT ((pixman_fixed_1 >> 1) - pixman_fixed_e) /* need to ensure deltas also fit */
    if (unlikely (_cairo_fixed_integer_ceil (xdim) > PIXMAN_MAX_INT ||
		  _cairo_fixed_integer_ceil (ydim) > PIXMAN_MAX_INT))
    {
	double sf;

	if (xdim > ydim)
	    sf = PIXMAN_MAX_INT / _cairo_fixed_to_double (xdim);
	else
	    sf = PIXMAN_MAX_INT / _cairo_fixed_to_double (ydim);

	p1.x = _cairo_fixed_16_16_from_double (_cairo_fixed_to_double (pattern->p1.x) * sf);
	p1.y = _cairo_fixed_16_16_from_double (_cairo_fixed_to_double (pattern->p1.y) * sf);
	p2.x = _cairo_fixed_16_16_from_double (_cairo_fixed_to_double (pattern->p2.x) * sf);
	p2.y = _cairo_fixed_16_16_from_double (_cairo_fixed_to_double (pattern->p2.y) * sf);

	cairo_matrix_scale (&matrix, sf, sf);
    }
    else
    {
	p1.x = _cairo_fixed_to_16_16 (pattern->p1.x);
	p1.y = _cairo_fixed_to_16_16 (pattern->p1.y);
	p2.x = _cairo_fixed_to_16_16 (pattern->p2.x);
	p2.y = _cairo_fixed_to_16_16 (pattern->p2.y);
    }

    colors = (xcb_render_color_t *) (stops + pattern->base.n_stops);
    _cairo_xcb_connection_render_create_linear_gradient (target->connection,
							 picture->picture,
							 p1, p2,
							 pattern->base.n_stops,
							 stops, colors);

    if (stops != (xcb_render_fixed_t *) buf)
	free (stops);

    status = _cairo_xcb_screen_store_linear_picture (target->screen,
						     pattern,
						     &picture->base);
    if (unlikely (status)) {
	cairo_surface_destroy (&picture->base);
	return (cairo_xcb_picture_t *) _cairo_surface_create_in_error (status);
    }

setup_picture:
    _cairo_xcb_picture_set_matrix (picture, &matrix,
				   pattern->base.base.filter,
				   extents->x + extents->width/2.,
				   extents->y + extents->height/2.);
    _cairo_xcb_picture_set_filter (picture, pattern->base.base.filter);
    _cairo_xcb_picture_set_extend (picture, pattern->base.base.extend);
    _cairo_xcb_picture_set_component_alpha (picture,
					    pattern->base.base.has_component_alpha);

    return picture;
}

static cairo_xcb_picture_t *
_cairo_xcb_radial_picture (cairo_xcb_surface_t *target,
			   const cairo_radial_pattern_t *pattern,
			   const cairo_rectangle_int_t *extents)
{
    char buf[CAIRO_STACK_BUFFER_SIZE];
    xcb_render_fixed_t *stops;
    xcb_render_color_t *colors;
    xcb_render_pointfix_t c1, c2;
    xcb_render_fixed_t r1, r2;
    cairo_xcb_picture_t *picture;
    cairo_status_t status;

    picture = (cairo_xcb_picture_t *)
	_cairo_xcb_screen_lookup_radial_picture (target->screen, pattern);
    if (picture != NULL)
	goto setup_picture;

    stops = _gradient_to_xcb (&pattern->base, buf, sizeof (buf));
    if (unlikely (stops == NULL))
	return (cairo_xcb_picture_t *) _cairo_surface_create_in_error (CAIRO_STATUS_NO_MEMORY);

    picture = _cairo_xcb_picture_create (target->screen,
					 target->screen->connection->standard_formats[CAIRO_FORMAT_ARGB32],
					 PIXMAN_a8r8g8b8,
					 -1, -1);
    if (unlikely (picture->base.status)) {
	if (stops != (xcb_render_fixed_t *) buf)
	    free (stops);
	return picture;
    }
    picture->filter = CAIRO_FILTER_DEFAULT;

    c1.x = _cairo_fixed_to_16_16 (pattern->c1.x);
    c1.y = _cairo_fixed_to_16_16 (pattern->c1.y);
    r1 = _cairo_fixed_to_16_16 (pattern->r1);
    c2.x = _cairo_fixed_to_16_16 (pattern->c2.x);
    c2.y = _cairo_fixed_to_16_16 (pattern->c2.y);
    r2 = _cairo_fixed_to_16_16 (pattern->r2);

    colors = (xcb_render_color_t *) (stops + pattern->base.n_stops);
    _cairo_xcb_connection_render_create_radial_gradient (target->connection,
							 picture->picture,
							 c1, c2, r1, r2,
							 pattern->base.n_stops,
							 stops, colors);

    if (stops != (xcb_render_fixed_t *) buf)
	free (stops);

    status = _cairo_xcb_screen_store_radial_picture (target->screen,
						     pattern,
						     &picture->base);
    if (unlikely (status)) {
	cairo_surface_destroy (&picture->base);
	return (cairo_xcb_picture_t *) _cairo_surface_create_in_error (status);
    }

setup_picture:
    _cairo_xcb_picture_set_matrix (picture, &pattern->base.base.matrix,
				   pattern->base.base.filter,
				   extents->x + extents->width/2.,
				   extents->y + extents->height/2.);
    _cairo_xcb_picture_set_filter (picture, pattern->base.base.filter);
    _cairo_xcb_picture_set_extend (picture, pattern->base.base.extend);
    _cairo_xcb_picture_set_component_alpha (picture,
					    pattern->base.base.has_component_alpha);

    return picture;
}

static cairo_xcb_picture_t *
_copy_to_picture (cairo_xcb_surface_t *source,
		  cairo_bool_t force)
{
    cairo_xcb_picture_t *picture;
    uint32_t values[] = { 0, 1 };

    /* XXX two level device locking, ensure we release the xcb device mutex? */
    if (source->drm != NULL)
	cairo_surface_flush (source->drm);

    if (source->owns_pixmap && ! force) {
	picture = _cairo_xcb_picture_copy (source);
    } else {
	picture = _cairo_xcb_picture_create (source->screen,
					     source->xrender_format,
					     source->pixman_format,
					     source->width,
					     source->height);
	if (unlikely (picture->base.status))
	    return picture;

	_cairo_xcb_connection_render_create_picture (source->connection,
						     picture->picture,
						     source->drawable,
						     source->xrender_format,
						     XCB_RENDER_CP_GRAPHICS_EXPOSURE |
						     XCB_RENDER_CP_SUBWINDOW_MODE,
						     values);
    }

    return picture;
}

static cairo_xcb_picture_t *
_cairo_xcb_surface_picture (cairo_xcb_surface_t *target,
			    const cairo_surface_pattern_t *pattern,
			    const cairo_rectangle_int_t *extents)
{
    cairo_surface_t *source = pattern->surface;
    cairo_xcb_picture_t *picture;
    cairo_filter_t filter;
    cairo_extend_t extend;
    cairo_status_t status;

    if (source->is_clear) {
        if (source->content & CAIRO_CONTENT_ALPHA)
	    return _cairo_xcb_transparent_picture (target);
        else
            return _cairo_xcb_black_picture (target);
    }

    {
	cairo_xcb_surface_t *snapshot;

	snapshot = (cairo_xcb_surface_t *)
	    _cairo_surface_has_snapshot (source, &_cairo_xcb_surface_backend);
	if (snapshot != NULL) {
	    if (snapshot->screen == target->screen)
		source = &snapshot->base;
	}
    }

    picture = (cairo_xcb_picture_t *)
	_cairo_surface_has_snapshot (source, &_cairo_xcb_picture_backend);
    if (picture != NULL) {
	if (picture->screen == target->screen) {
	    picture = (cairo_xcb_picture_t *) cairo_surface_reference (&picture->base);
	    goto setup_picture;
	}
	picture = NULL;
    }

    if (source->type == CAIRO_SURFACE_TYPE_XCB)
    {
	if (source->backend->type == CAIRO_SURFACE_TYPE_XCB) {
	    if (((cairo_xcb_surface_t *) source)->screen == target->screen) {
		picture = _copy_to_picture ((cairo_xcb_surface_t *) source, FALSE);
		if (unlikely (picture->base.status))
		    return picture;
	    }
	} else if (source->backend->type == CAIRO_SURFACE_TYPE_SUBSURFACE) {
	    cairo_surface_subsurface_t *sub = (cairo_surface_subsurface_t *) source;
	    cairo_xcb_surface_t *xcb = (cairo_xcb_surface_t *) sub->target;

	    /* XXX repeat interval with source clipping? */
	    if (FALSE && xcb->screen == target->screen) {
		xcb_rectangle_t rect;

		picture = _copy_to_picture (xcb, TRUE);
		if (unlikely (picture->base.status))
		    return picture;

		rect.x = sub->extents.x;
		rect.y = sub->extents.y;
		rect.width  = sub->extents.width;
		rect.height = sub->extents.height;

		_cairo_xcb_connection_render_set_picture_clip_rectangles (xcb->connection,
									  picture->picture,
									  0, 0,
									  1, &rect);
		picture->x0 = rect.x;
		picture->y0 = rect.y;
		picture->width  = rect.width;
		picture->height = rect.height;
	    }
	} else if (source->backend->type == CAIRO_INTERNAL_SURFACE_TYPE_SNAPSHOT) {
	    cairo_surface_snapshot_t *snap = (cairo_surface_snapshot_t *) source;
	    cairo_xcb_surface_t *xcb = (cairo_xcb_surface_t *) snap->target;

	    if (xcb->screen == target->screen) {
		picture = _copy_to_picture (xcb, TRUE);
		if (unlikely (picture->base.status))
		    return picture;
	    }
	}
    }
#if CAIRO_HAS_XLIB_XCB_FUNCTIONS
    else if (source->type == CAIRO_SURFACE_TYPE_XLIB)
    {
	if (source->backend->type == CAIRO_SURFACE_TYPE_XLIB) {
	    if (((cairo_xlib_xcb_surface_t *) source)->xcb->screen == target->screen) {
		picture = _copy_to_picture (((cairo_xlib_xcb_surface_t *) source)->xcb,
					    FALSE);
		if (unlikely (picture->base.status))
		    return picture;
	    }
	} else if (source->backend->type == CAIRO_SURFACE_TYPE_SUBSURFACE) {
	    cairo_surface_subsurface_t *sub = (cairo_surface_subsurface_t *) source;
	    cairo_xcb_surface_t *xcb = ((cairo_xlib_xcb_surface_t *) sub->target)->xcb;

	    if (FALSE && xcb->screen == target->screen) {
		xcb_rectangle_t rect;

		picture = _copy_to_picture (xcb, TRUE);
		if (unlikely (picture->base.status))
		    return picture;

		rect.x = sub->extents.x;
		rect.y = sub->extents.y;
		rect.width  = sub->extents.width;
		rect.height = sub->extents.height;

		_cairo_xcb_connection_render_set_picture_clip_rectangles (xcb->connection,
									  picture->picture,
									  0, 0,
									  1, &rect);
		picture->x0 = rect.x;
		picture->y0 = rect.y;
		picture->width  = rect.width;
		picture->height = rect.height;
	    }
	} else if (source->backend->type == CAIRO_INTERNAL_SURFACE_TYPE_SNAPSHOT) {
	    cairo_surface_snapshot_t *snap = (cairo_surface_snapshot_t *) source;
	    cairo_xcb_surface_t *xcb = ((cairo_xlib_xcb_surface_t *) snap->target)->xcb;

	    if (xcb->screen == target->screen) {
		picture = _copy_to_picture (xcb, TRUE);
		if (unlikely (picture->base.status))
		    return picture;
	    }
	}
    }
#endif
#if CAIRO_HAS_XCB_DRM_FUNCTIONS && CAIRO_HAS_DRM_SURFACE
    else if (source->type == CAIRO_SURFACE_TYPE_DRM &&
	     target->drm != NULL &&
	     target->drm->device == source->device)
    {
	cairo_drm_surface_t *drm = (cairo_drm_surface_t *) source;
	cairo_xcb_surface_t *tmp;
	xcb_pixmap_t pixmap;
	pixman_format_code_t pixman_format;
	cairo_surface_pattern_t pattern;

	/* XXX XRenderCreatePictureForNative:
	 * Copy the source to a temporary pixmap if possible.
	 * Still cheaper than pushing the image via the CPU.
	 */

	switch (drm->format) {
	case CAIRO_FORMAT_A1:
	    pixman_format = PIXMAN_a1;
	    break;
	case CAIRO_FORMAT_A8:
	    pixman_format = PIXMAN_a8;
	    break;
	case CAIRO_FORMAT_RGB24:
	    pixman_format = PIXMAN_x8r8g8b8;
	    break;
	default:
	case CAIRO_FORMAT_ARGB32:
	    pixman_format = PIXMAN_a8r8g8b8;
	    break;
	}

	pixmap =
	    _cairo_xcb_connection_create_pixmap (target->connection,
						 PIXMAN_FORMAT_DEPTH (pixman_format),
						 target->drawable,
						 drm->width, drm->height);

	tmp = (cairo_xcb_surface_t *)
	    _cairo_xcb_surface_create_internal (target->screen,
						pixmap, TRUE,
						pixman_format,
						target->connection->standard_formats[drm->format],
						drm->width, drm->height);
	if (unlikely (tmp->base.status)) {
	    _cairo_xcb_connection_free_pixmap (target->connection, pixmap);
	    return (cairo_xcb_picture_t *) tmp;
	}

	_cairo_pattern_init_for_surface (&pattern, source);
	status = _cairo_surface_paint (&tmp->base,
				       CAIRO_OPERATOR_SOURCE,
				       &pattern.base,
				       NULL);
	_cairo_pattern_fini (&pattern.base);

	if (unlikely (status)) {
	    cairo_surface_destroy (&tmp->base);
	    return (cairo_xcb_picture_t *) _cairo_surface_create_in_error (status);
	}

	picture = _copy_to_picture (tmp, FALSE);
	cairo_surface_destroy (&tmp->base);

	if (unlikely (picture->base.status))
	    return picture;
    }
#endif
#if CAIRO_HAS_GL_FUNCTIONS
    else if (source->type == CAIRO_SURFACE_TYPE_GL)
    {
	/* pixmap from texture */
    }
#endif

    if (picture == NULL) {
	cairo_image_surface_t *image;
	void *image_extra;
	cairo_status_t status;

	status = _cairo_surface_acquire_source_image (source, &image, &image_extra);
	if (unlikely (status))
	    return (cairo_xcb_picture_t *) _cairo_surface_create_in_error (status);

	if (image->format != CAIRO_FORMAT_INVALID) {
	    xcb_render_pictformat_t format;

	    format = target->screen->connection->standard_formats[image->format];

	    picture = _picture_from_image (target, format, image, NULL);
	    _cairo_surface_release_source_image (source, image, image_extra);
	} else {
	    cairo_image_surface_t *conv;
	    xcb_render_pictformat_t render_format;

	    /* XXX XRenderPutImage! */

	    conv = _cairo_image_surface_coerce (image);
	    _cairo_surface_release_source_image (source, image, image_extra);
	    if (unlikely (conv->base.status))
		return (cairo_xcb_picture_t *) conv;

	    render_format = target->screen->connection->standard_formats[conv->format];
	    picture = _picture_from_image (target, render_format, conv, NULL);
	    cairo_surface_destroy (&conv->base);
	}

	if (unlikely (picture->base.status))
	    return picture;
    }

    status = _cairo_xcb_screen_store_surface_picture (target->screen,
						      &picture->base,
						      CAIRO_STRIDE_FOR_WIDTH_BPP (picture->width,
										  PIXMAN_FORMAT_BPP (picture->pixman_format))
						      * picture->height);
    if (unlikely (status)) {
	cairo_surface_destroy (&picture->base);
	return (cairo_xcb_picture_t *) _cairo_surface_create_in_error (status);
    }

    _cairo_surface_attach_snapshot (source,
				    &picture->base,
				    cairo_surface_finish);

setup_picture:
    filter = pattern->base.filter;
    if (filter != CAIRO_FILTER_NEAREST &&
	_cairo_matrix_has_unity_scale (&pattern->base.matrix) &&
	_cairo_fixed_is_integer (_cairo_fixed_from_double (pattern->base.matrix.x0)) &&
	_cairo_fixed_is_integer (_cairo_fixed_from_double (pattern->base.matrix.y0)))
    {
	filter = CAIRO_FILTER_NEAREST;
    }
    _cairo_xcb_picture_set_filter (picture, filter);

    _cairo_xcb_picture_set_matrix (picture,
				   &pattern->base.matrix, filter,
				   extents->x + extents->width/2.,
				   extents->y + extents->height/2.);


    extend = pattern->base.extend;
    if (extents->x >= 0 && extents->x + extents->width <= picture->width &&
	extents->y >= 0 && extents->y + extents->height <= picture->height)
    {
	extend = CAIRO_EXTEND_NONE;
    }
    _cairo_xcb_picture_set_extend (picture, extend);
    _cairo_xcb_picture_set_component_alpha (picture, pattern->base.has_component_alpha);

    return picture;
}

static cairo_xcb_picture_t *
_cairo_xcb_picture_for_pattern (cairo_xcb_surface_t *target,
				const cairo_pattern_t *pattern,
				const cairo_rectangle_int_t *extents)
{
    if (pattern == NULL)
	return _cairo_xcb_white_picture (target);

    if (! _pattern_is_supported (target->flags, pattern))
	return _render_to_picture (target, pattern, extents);

    switch (pattern->type) {
    case CAIRO_PATTERN_TYPE_SOLID:
	return _cairo_xcb_solid_picture (target, (cairo_solid_pattern_t *) pattern);

    case CAIRO_PATTERN_TYPE_LINEAR:
	return _cairo_xcb_linear_picture (target,
					  (cairo_linear_pattern_t *) pattern,
					  extents);

    case CAIRO_PATTERN_TYPE_RADIAL:
	return _cairo_xcb_radial_picture (target,
					  (cairo_radial_pattern_t *) pattern,
					  extents);

    case CAIRO_PATTERN_TYPE_SURFACE:
	return _cairo_xcb_surface_picture (target,
					   (cairo_surface_pattern_t *) pattern,
					   extents);
    default:
	ASSERT_NOT_REACHED;
	return _render_to_picture (target, pattern, extents);
    }
}

COMPILE_TIME_ASSERT (sizeof (xcb_rectangle_t) <= sizeof (cairo_box_t));

static cairo_status_t
_render_fill_boxes (void			*abstract_dst,
		    cairo_operator_t		 op,
		    const cairo_color_t		*color,
		    cairo_boxes_t		*boxes)
{
    cairo_xcb_surface_t *dst = abstract_dst;
    xcb_rectangle_t stack_xrects[CAIRO_STACK_ARRAY_LENGTH (sizeof (xcb_rectangle_t))];
    xcb_rectangle_t *xrects = stack_xrects;
    xcb_render_color_t render_color;
    int render_op = _render_operator (op);
    struct _cairo_boxes_chunk *chunk;
    int max_count;

    render_color.red   = color->red_short;
    render_color.green = color->green_short;
    render_color.blue  = color->blue_short;
    render_color.alpha = color->alpha_short;

    max_count = 0;
    for (chunk = &boxes->chunks; chunk != NULL; chunk = chunk->next) {
	if (chunk->count > max_count)
	    max_count = chunk->count;
    }
    if (max_count > ARRAY_LENGTH (stack_xrects)) {
	xrects = _cairo_malloc_ab (max_count, sizeof (xcb_rectangle_t));
	if (unlikely (xrects == NULL))
	    return _cairo_error (CAIRO_STATUS_NO_MEMORY);
    }

    for (chunk = &boxes->chunks; chunk != NULL; chunk = chunk->next) {
	int i, j;

	for (i = j = 0; i < chunk->count; i++) {
	    int x1 = _cairo_fixed_integer_round (chunk->base[i].p1.x);
	    int y1 = _cairo_fixed_integer_round (chunk->base[i].p1.y);
	    int x2 = _cairo_fixed_integer_round (chunk->base[i].p2.x);
	    int y2 = _cairo_fixed_integer_round (chunk->base[i].p2.y);

	    if (x2 > x1 && y2 > y1) {
		xrects[j].x = x1;
		xrects[j].y = y1;
		xrects[j].width  = x2 - x1;
		xrects[j].height = y2 - y1;
		j++;
	    }
	}

	if (j) {
	    _cairo_xcb_connection_render_fill_rectangles
		(dst->connection,
		 render_op, dst->picture,
		 render_color, j, xrects);
	}
    }

    if (xrects != stack_xrects)
	free (xrects);

    return CAIRO_STATUS_SUCCESS;
}

static cairo_int_status_t
_render_composite_boxes (cairo_xcb_surface_t	*dst,
			 cairo_operator_t	 op,
			 const cairo_pattern_t	*src_pattern,
			 const cairo_pattern_t	*mask_pattern,
			 const cairo_rectangle_int_t *extents,
			 const cairo_boxes_t *boxes)
{
    cairo_xcb_picture_t *src, *mask;
    const struct _cairo_boxes_chunk *chunk;
    int render_op;

    render_op = _render_operator (op);

    if (src_pattern == NULL) {
	src_pattern = mask_pattern;
	mask_pattern = NULL;
    }

    src = _cairo_xcb_picture_for_pattern (dst, src_pattern, extents);
    if (unlikely (src->base.status))
	return src->base.status;

    if (mask_pattern != NULL) {
	mask = _cairo_xcb_picture_for_pattern (dst, mask_pattern, extents);
	if (unlikely (mask->base.status)) {
	    cairo_surface_destroy (&src->base);
	    return mask->base.status;
	}

	for (chunk = &boxes->chunks; chunk != NULL; chunk = chunk->next) {
	    const cairo_box_t *box = chunk->base;
	    int i;

	    for (i = 0; i < chunk->count; i++) {
		int x = _cairo_fixed_integer_round (box[i].p1.x);
		int y = _cairo_fixed_integer_round (box[i].p1.y);
		int width  = _cairo_fixed_integer_round (box[i].p2.x) - x;
		int height = _cairo_fixed_integer_round (box[i].p2.y) - y;

		if (width && height) {
		    _cairo_xcb_connection_render_composite (dst->connection,
							    render_op,
							    src->picture,
							    mask->picture,
							    dst->picture,
							    x + src->x,
							    y + src->y,
							    x + mask->x,
							    y + mask->y,
							    x, y,
							    width, height);
		}
	    }
	}

	cairo_surface_destroy (&mask->base);
    } else {
	for (chunk = &boxes->chunks; chunk != NULL; chunk = chunk->next) {
	    const cairo_box_t *box = chunk->base;
	    int i;

	    for (i = 0; i < chunk->count; i++) {
		int x = _cairo_fixed_integer_round (box[i].p1.x);
		int y = _cairo_fixed_integer_round (box[i].p1.y);
		int width  = _cairo_fixed_integer_round (box[i].p2.x) - x;
		int height = _cairo_fixed_integer_round (box[i].p2.y) - y;

		if (width && height) {
		    _cairo_xcb_connection_render_composite (dst->connection,
							    render_op,
							    src->picture,
							    XCB_NONE,
							    dst->picture,
							    x + src->x,
							    y + src->y,
							    0, 0,
							    x, y,
							    width, height);
		}
	    }
	}
    }

    cairo_surface_destroy (&src->base);

    return CAIRO_STATUS_SUCCESS;
}


#define CAIRO_FIXED_16_16_MIN _cairo_fixed_from_int (-32768)
#define CAIRO_FIXED_16_16_MAX _cairo_fixed_from_int (32767)

static cairo_bool_t
_line_exceeds_16_16 (const cairo_line_t *line)
{
    return
	line->p1.x <= CAIRO_FIXED_16_16_MIN ||
	line->p1.x >= CAIRO_FIXED_16_16_MAX ||

	line->p2.x <= CAIRO_FIXED_16_16_MIN ||
	line->p2.x >= CAIRO_FIXED_16_16_MAX ||

	line->p1.y <= CAIRO_FIXED_16_16_MIN ||
	line->p1.y >= CAIRO_FIXED_16_16_MAX ||

	line->p2.y <= CAIRO_FIXED_16_16_MIN ||
	line->p2.y >= CAIRO_FIXED_16_16_MAX;
}

static void
_project_line_x_onto_16_16 (const cairo_line_t *line,
			    cairo_fixed_t top,
			    cairo_fixed_t bottom,
			    xcb_render_linefix_t *out)
{
    cairo_point_double_t p1, p2;
    double m;

    p1.x = _cairo_fixed_to_double (line->p1.x);
    p1.y = _cairo_fixed_to_double (line->p1.y);

    p2.x = _cairo_fixed_to_double (line->p2.x);
    p2.y = _cairo_fixed_to_double (line->p2.y);

    m = (p2.x - p1.x) / (p2.y - p1.y);
    out->p1.x = _cairo_fixed_16_16_from_double (p1.x + m * _cairo_fixed_to_double (top - line->p1.y));
    out->p2.x = _cairo_fixed_16_16_from_double (p1.x + m * _cairo_fixed_to_double (bottom - line->p1.y));
}

typedef struct {
    cairo_traps_t traps;
    cairo_antialias_t antialias;
} composite_traps_info_t;

COMPILE_TIME_ASSERT (sizeof (xcb_render_trapezoid_t) <= sizeof (cairo_trapezoid_t));

static cairo_status_t
_composite_traps (void *closure,
		  cairo_xcb_surface_t	*dst,
		  cairo_operator_t	 op,
		  const cairo_pattern_t	*pattern,
		  int dst_x, int dst_y,
		  const cairo_rectangle_int_t *extents,
		  cairo_region_t		*clip_region)
{
    composite_traps_info_t *info = closure;
    const cairo_traps_t *traps = &info->traps;
    cairo_xcb_picture_t *src;
    cairo_format_t format;
    xcb_render_pictformat_t xrender_format;
    xcb_render_trapezoid_t *xtraps;
    int render_reference_x, render_reference_y;
    int i;

    src = _cairo_xcb_picture_for_pattern (dst, pattern, extents);
    if (unlikely (src->base.status))
	return src->base.status;

    if (info->antialias == CAIRO_ANTIALIAS_NONE)
	format = CAIRO_FORMAT_A1;
    else
	format = CAIRO_FORMAT_A8;
    xrender_format = dst->screen->connection->standard_formats[format];

    xtraps = (xcb_render_trapezoid_t *) traps->traps;
    for (i = 0; i < traps->num_traps; i++) {
	cairo_trapezoid_t t = traps->traps[i];

	/* top/bottom will be clamped to surface bounds */
	xtraps[i].top = _cairo_fixed_to_16_16 (t.top);
	xtraps[i].top -= dst_y << 16;
	xtraps[i].bottom = _cairo_fixed_to_16_16 (t.bottom);
	xtraps[i].bottom -= dst_y << 16;

	/* However, all the other coordinates will have been left untouched so
	 * as not to introduce numerical error. Recompute them if they
	 * exceed the 16.16 limits.
	 */
	if (unlikely (_line_exceeds_16_16 (&t.left))) {
	    _project_line_x_onto_16_16 (&t.left,
					t.top,
					t.bottom,
					&xtraps[i].left);
	    xtraps[i].left.p1.y = xtraps[i].top;
	    xtraps[i].left.p2.y = xtraps[i].bottom;
	} else {
	    xtraps[i].left.p1.x = _cairo_fixed_to_16_16 (t.left.p1.x);
	    xtraps[i].left.p1.y = _cairo_fixed_to_16_16 (t.left.p1.y);
	    xtraps[i].left.p2.x = _cairo_fixed_to_16_16 (t.left.p2.x);
	    xtraps[i].left.p2.y = _cairo_fixed_to_16_16 (t.left.p2.y);
	}
	xtraps[i].left.p1.x -= dst_x << 16;
	xtraps[i].left.p1.y -= dst_y << 16;
	xtraps[i].left.p2.x -= dst_x << 16;
	xtraps[i].left.p2.y -= dst_y << 16;

	if (unlikely (_line_exceeds_16_16 (&t.right))) {
	    _project_line_x_onto_16_16 (&t.right,
					t.top,
					t.bottom,
					&xtraps[i].right);
	    xtraps[i].right.p1.y = xtraps[i].top;
	    xtraps[i].right.p2.y = xtraps[i].bottom;
	} else {
	    xtraps[i].right.p1.x = _cairo_fixed_to_16_16 (t.right.p1.x);
	    xtraps[i].right.p1.y = _cairo_fixed_to_16_16 (t.right.p1.y);
	    xtraps[i].right.p2.x = _cairo_fixed_to_16_16 (t.right.p2.x);
	    xtraps[i].right.p2.y = _cairo_fixed_to_16_16 (t.right.p2.y);
	}
	xtraps[i].right.p1.x -= dst_x << 16;
	xtraps[i].right.p1.y -= dst_y << 16;
	xtraps[i].right.p2.x -= dst_x << 16;
	xtraps[i].right.p2.y -= dst_y << 16;
    }

    if (xtraps[0].left.p1.y < xtraps[0].left.p2.y) {
	render_reference_x = xtraps[0].left.p1.x >> 16;
	render_reference_y = xtraps[0].left.p1.y >> 16;
    } else {
	render_reference_x = xtraps[0].left.p2.x >> 16;
	render_reference_y = xtraps[0].left.p2.y >> 16;
    }

    _cairo_xcb_connection_render_trapezoids (dst->connection,
					     _render_operator (op),
					     src->picture,
					     dst->picture,
					     xrender_format,
					     src->x + render_reference_x,
					     src->y + render_reference_y,
					     traps->num_traps, xtraps);

    cairo_surface_destroy (&src->base);

    return CAIRO_STATUS_SUCCESS;
}

/* low-level composite driver */

typedef cairo_status_t
(*xcb_draw_func_t) (void				*closure,
		    cairo_xcb_surface_t			*dst,
		    cairo_operator_t			 op,
		    const cairo_pattern_t		*src,
		    int					 dst_x,
		    int					 dst_y,
		    const cairo_rectangle_int_t		*extents,
		    cairo_region_t			*clip_region);

static cairo_xcb_surface_t *
_create_composite_mask (cairo_clip_t		*clip,
			xcb_draw_func_t		 draw_func,
			void			*draw_closure,
			cairo_xcb_surface_t	*dst,
			const cairo_rectangle_int_t*extents)
{
    cairo_xcb_surface_t *surface;
    cairo_bool_t clip_surface = FALSE;
    cairo_status_t status;

    if (clip != NULL) {
	cairo_region_t *clip_region;

	status = _cairo_clip_get_region (clip, &clip_region);
	assert (! _cairo_status_is_error (status));
	clip_surface = status == CAIRO_INT_STATUS_UNSUPPORTED;
    }

    surface = (cairo_xcb_surface_t *)
	_cairo_xcb_surface_create_similar (dst, CAIRO_CONTENT_ALPHA,
					   extents->width, extents->height);
    if (unlikely (surface->base.status))
	return surface;

    _cairo_xcb_surface_ensure_picture (surface);

    if (surface->flags & CAIRO_XCB_RENDER_HAS_FILL_RECTANGLES) {
	xcb_render_color_t clear;
	xcb_rectangle_t xrect;

	clear.red = clear.green = clear.blue = clear.alpha = 0;

	xrect.x = xrect.y = 0;
	xrect.width  = extents->width;
	xrect.height = extents->height;

	_cairo_xcb_connection_render_fill_rectangles (surface->connection,
						      XCB_RENDER_PICT_OP_CLEAR,
						      surface->picture,
						      clear, 1, &xrect);
    } else {
	status = _cairo_xcb_surface_render_paint (surface,
						  CAIRO_OPERATOR_CLEAR,
						  &_cairo_pattern_clear.base,
						  NULL);
	if (unlikely (status)) {
	    cairo_surface_destroy (&surface->base);
	    return (cairo_xcb_surface_t *) _cairo_surface_create_in_error (status);
	}
    }

    /* Is it worth setting the clip region here? */
    status = draw_func (draw_closure, surface,
			CAIRO_OPERATOR_ADD, NULL,
			extents->x, extents->y,
			extents, NULL);
    if (unlikely (status)) {
	cairo_surface_destroy (&surface->base);
	return (cairo_xcb_surface_t *) _cairo_surface_create_in_error (status);
    }

    if (clip_surface) {
	status = _cairo_clip_combine_with_surface (clip, &surface->base,
						   extents->x, extents->y);
	if (unlikely (status)) {
	    cairo_surface_destroy (&surface->base);
	    return (cairo_xcb_surface_t *) _cairo_surface_create_in_error (status);
	}
    }

    return surface;
}

/* Handles compositing with a clip surface when the operator allows
 * us to combine the clip with the mask
 */
static cairo_status_t
_clip_and_composite_with_mask (cairo_clip_t		*clip,
			       cairo_operator_t		 op,
			       const cairo_pattern_t	*pattern,
			       xcb_draw_func_t		 draw_func,
			       void			*draw_closure,
			       cairo_xcb_surface_t	*dst,
			       const cairo_rectangle_int_t*extents)
{
    cairo_xcb_surface_t *mask;
    cairo_xcb_picture_t *src;

    mask = _create_composite_mask (clip, draw_func, draw_closure, dst, extents);
    if (unlikely (mask->base.status))
	return mask->base.status;

    if (pattern != NULL || dst->base.content != CAIRO_CONTENT_ALPHA) {
	src = _cairo_xcb_picture_for_pattern (dst, pattern, extents);
	if (unlikely (src->base.status)) {
	    cairo_surface_destroy (&mask->base);
	    return src->base.status;
	}

	_cairo_xcb_connection_render_composite (dst->connection,
						_render_operator (op),
						src->picture,
						mask->picture,
						dst->picture,
						extents->x + src->x, extents->y + src->y,
						0, 0,
						extents->x,      extents->y,
						extents->width,  extents->height);

	cairo_surface_destroy (&src->base);
    } else {
	_cairo_xcb_connection_render_composite (dst->connection,
						_render_operator (op),
						mask->picture,
						XCB_NONE,
						dst->picture,
						0, 0,
						0, 0,
						extents->x,      extents->y,
						extents->width,  extents->height);
    }
    cairo_surface_destroy (&mask->base);

    return CAIRO_STATUS_SUCCESS;
}

/* Handles compositing with a clip surface when we have to do the operation
 * in two pieces and combine them together.
 */
static cairo_status_t
_clip_and_composite_combine (cairo_clip_t		*clip,
			     cairo_operator_t		 op,
			     const cairo_pattern_t	*pattern,
			     xcb_draw_func_t		 draw_func,
			     void			*draw_closure,
			     cairo_xcb_surface_t	*dst,
			     const cairo_rectangle_int_t*extents)
{
    cairo_xcb_surface_t *tmp;
    cairo_surface_t *clip_surface;
    int clip_x, clip_y;
    xcb_render_picture_t clip_picture;
    cairo_status_t status;

    tmp = (cairo_xcb_surface_t *)
	_cairo_xcb_surface_create_similar (dst, dst->base.content,
					   extents->width, extents->height);
    if (unlikely (tmp->base.status))
	return tmp->base.status;

    _cairo_xcb_surface_ensure_picture (tmp);

    if (pattern == NULL) {
	status = (*draw_func) (draw_closure, tmp,
			       CAIRO_OPERATOR_ADD, NULL,
			       extents->x, extents->y,
			       extents, NULL);
    } else {
	/* Initialize the temporary surface from the destination surface */
	if (! dst->base.is_clear ||
	    (dst->flags & CAIRO_XCB_RENDER_HAS_FILL_RECTANGLES) == 0)
	{
	    /* XCopyArea may actually be quicker here.
	     * A good driver should translate if appropriate.
	     */
	    _cairo_xcb_connection_render_composite (dst->connection,
						    XCB_RENDER_PICT_OP_SRC,
						    dst->picture,
						    XCB_NONE,
						    tmp->picture,
						    extents->x,      extents->y,
						    0, 0,
						    0, 0,
						    extents->width,  extents->height);
	}
	else
	{
	    xcb_render_color_t clear;
	    xcb_rectangle_t xrect;

	    clear.red = clear.green = clear.blue = clear.alpha = 0;

	    xrect.x = xrect.y = 0;
	    xrect.width  = extents->width;
	    xrect.height = extents->height;

	    _cairo_xcb_connection_render_fill_rectangles (dst->connection,
							  XCB_RENDER_PICT_OP_CLEAR,
							  dst->picture,
							  clear, 1, &xrect);
	}

	status = (*draw_func) (draw_closure, tmp, op, pattern,
			       extents->x, extents->y,
			       extents, NULL);
    }
    if (unlikely (status))
	goto CLEANUP_SURFACE;

    clip_surface = _cairo_clip_get_surface (clip, &dst->base, &clip_x, &clip_y);
    if (unlikely (clip_surface->status))
	goto CLEANUP_SURFACE;

    clip_picture = ((cairo_xcb_surface_t *) clip_surface)->picture;
    assert (clip_picture != XCB_NONE);

    if (dst->base.is_clear) {
	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_SRC,
						tmp->picture, clip_picture, dst->picture,
						0, 0,
						0, 0,
						extents->x,      extents->y,
						extents->width,  extents->height);
    } else {
	/* Punch the clip out of the destination */
	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_OUT_REVERSE,
						clip_picture, XCB_NONE, dst->picture,
						extents->x - clip_x,
						extents->y - clip_y,
						0, 0,
						extents->x,     extents->y,
						extents->width, extents->height);

	/* Now add the two results together */
	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_ADD,
						tmp->picture, clip_picture, dst->picture,
						0, 0,
						extents->x - clip_x,
						extents->y - clip_y,
						extents->x,     extents->y,
						extents->width, extents->height);
    }

 CLEANUP_SURFACE:
    cairo_surface_destroy (&tmp->base);

    return status;
}

/* Handles compositing for %CAIRO_OPERATOR_SOURCE, which is special; it's
 * defined as (src IN mask IN clip) ADD (dst OUT (mask IN clip))
 */
static cairo_status_t
_clip_and_composite_source (cairo_clip_t		*clip,
			    const cairo_pattern_t	*pattern,
			    xcb_draw_func_t		 draw_func,
			    void			*draw_closure,
			    cairo_xcb_surface_t		*dst,
			    const cairo_rectangle_int_t	*extents)
{
    cairo_xcb_surface_t *mask;
    cairo_xcb_picture_t *src;

    /* Create a surface that is mask IN clip */
    mask = _create_composite_mask (clip, draw_func, draw_closure, dst, extents);
    if (unlikely (mask->base.status))
	return mask->base.status;

    src = _cairo_xcb_picture_for_pattern (dst, pattern, extents);
    if (unlikely (src->base.status)) {
	cairo_surface_destroy (&mask->base);
	return src->base.status;
    }

    if (dst->base.is_clear) {
	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_SRC,
						src->picture,
						mask->picture,
						dst->picture,
						extents->x + src->x, extents->y + src->y,
						0, 0,
						extents->x,      extents->y,
						extents->width,  extents->height);
    } else {
	/* Compute dest' = dest OUT (mask IN clip) */
	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_OUT_REVERSE,
						mask->picture,
						XCB_NONE,
						dst->picture,
						0, 0, 0, 0,
						extents->x,     extents->y,
						extents->width, extents->height);

	/* Now compute (src IN (mask IN clip)) ADD dest' */
	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_ADD,
						src->picture,
						mask->picture,
						dst->picture,
						extents->x + src->x, extents->y + src->y,
						0, 0,
						extents->x,     extents->y,
						extents->width, extents->height);
    }

    cairo_surface_destroy (&src->base);
    cairo_surface_destroy (&mask->base);

    return CAIRO_STATUS_SUCCESS;
}

static cairo_bool_t
can_reduce_alpha_op (cairo_operator_t op)
{
    int iop = op;
    switch (iop) {
    case CAIRO_OPERATOR_OVER:
    case CAIRO_OPERATOR_SOURCE:
    case CAIRO_OPERATOR_ADD:
	return TRUE;
    default:
	return FALSE;
    }
}

static cairo_bool_t
reduce_alpha_op (cairo_surface_t *dst,
		 cairo_operator_t op,
		 const cairo_pattern_t *pattern)
{
    return dst->is_clear &&
	   dst->content == CAIRO_CONTENT_ALPHA &&
	   _cairo_pattern_is_opaque_solid (pattern) &&
	   can_reduce_alpha_op (op);
}

static cairo_status_t
_cairo_xcb_surface_fixup_unbounded (cairo_xcb_surface_t *dst,
				    const cairo_composite_rectangles_t *rects)
{
    xcb_rectangle_t xrects[4];
    int n;

    if (rects->bounded.width  == rects->unbounded.width &&
	rects->bounded.height == rects->unbounded.height)
    {
	return CAIRO_STATUS_SUCCESS;
    }

    n = 0;
    if (rects->bounded.width == 0 || rects->bounded.height == 0) {
	xrects[n].x = rects->unbounded.x;
	xrects[n].width = rects->unbounded.width;
	xrects[n].y = rects->unbounded.y;
	xrects[n].height = rects->unbounded.height;
	n++;
    } else {
	/* top */
	if (rects->bounded.y != rects->unbounded.y) {
	    xrects[n].x = rects->unbounded.x;
	    xrects[n].width = rects->unbounded.width;
	    xrects[n].y = rects->unbounded.y;
	    xrects[n].height = rects->bounded.y - rects->unbounded.y;
	    n++;
	}
	/* left */
	if (rects->bounded.x != rects->unbounded.x) {
	    xrects[n].x = rects->unbounded.x;
	    xrects[n].width = rects->bounded.x - rects->unbounded.x;
	    xrects[n].y = rects->bounded.y;
	    xrects[n].height = rects->bounded.height;
	    n++;
	}
	/* right */
	if (rects->bounded.x + rects->bounded.width != rects->unbounded.x + rects->unbounded.width) {
	    xrects[n].x = rects->bounded.x + rects->bounded.width;
	    xrects[n].width = rects->unbounded.x + rects->unbounded.width - xrects[n].x;
	    xrects[n].y = rects->bounded.y;
	    xrects[n].height = rects->bounded.height;
	    n++;
	}
	/* bottom */
	if (rects->bounded.y + rects->bounded.height != rects->unbounded.y + rects->unbounded.height) {
	    xrects[n].x = rects->unbounded.x;
	    xrects[n].width = rects->unbounded.width;
	    xrects[n].y = rects->bounded.y + rects->bounded.height;
	    xrects[n].height = rects->unbounded.y + rects->unbounded.height - xrects[n].y;
	    n++;
	}
    }

    if (dst->flags & CAIRO_XCB_RENDER_HAS_FILL_RECTANGLES) {
	xcb_render_color_t color;

	color.red   = 0;
	color.green = 0;
	color.blue  = 0;
	color.alpha = 0;

	_cairo_xcb_connection_render_fill_rectangles (dst->connection,
						      XCB_RENDER_PICT_OP_CLEAR,
						      dst->picture,
						      color, n, xrects);
    } else {
	int i;
	cairo_xcb_picture_t *src;

	src = _cairo_xcb_transparent_picture (dst);
	if (unlikely (src->base.status))
	    return src->base.status;

	for (i = 0; i < n; i++) {
	    _cairo_xcb_connection_render_composite (dst->connection,
						    XCB_RENDER_PICT_OP_CLEAR,
						    src->picture, XCB_NONE, dst->picture,
						    0, 0,
						    0, 0,
						    xrects[i].x, xrects[i].y,
						    xrects[i].width, xrects[i].height);
	}
	cairo_surface_destroy (&src->base);
    }

    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_cairo_xcb_surface_fixup_unbounded_with_mask (cairo_xcb_surface_t *dst,
					      const cairo_composite_rectangles_t *rects,
					      cairo_clip_t *clip)
{
    cairo_xcb_surface_t *mask;
    int mask_x, mask_y;

    mask = (cairo_xcb_surface_t *) _cairo_clip_get_surface (clip, &dst->base, &mask_x, &mask_y);
    if (unlikely (mask->base.status))
	return mask->base.status;

    /* top */
    if (rects->bounded.y != rects->unbounded.y) {
	int x = rects->unbounded.x;
	int y = rects->unbounded.y;
	int width = rects->unbounded.width;
	int height = rects->bounded.y - y;

	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_OUT_REVERSE,
						mask->picture, XCB_NONE, dst->picture,
						x - mask_x, y - mask_y,
						0, 0,
						x, y,
						width, height);
    }

    /* left */
    if (rects->bounded.x != rects->unbounded.x) {
	int x = rects->unbounded.x;
	int y = rects->bounded.y;
	int width = rects->bounded.x - x;
	int height = rects->bounded.height;

	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_OUT_REVERSE,
						mask->picture, XCB_NONE, dst->picture,
						x - mask_x, y - mask_y,
						0, 0,
						x, y,
						width, height);
    }

    /* right */
    if (rects->bounded.x + rects->bounded.width != rects->unbounded.x + rects->unbounded.width) {
	int x = rects->bounded.x + rects->bounded.width;
	int y = rects->bounded.y;
	int width = rects->unbounded.x + rects->unbounded.width - x;
	int height = rects->bounded.height;

	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_OUT_REVERSE,
						mask->picture, XCB_NONE, dst->picture,
						x - mask_x, y - mask_y,
						0, 0,
						x, y,
						width, height);
    }

    /* bottom */
    if (rects->bounded.y + rects->bounded.height != rects->unbounded.y + rects->unbounded.height) {
	int x = rects->unbounded.x;
	int y = rects->bounded.y + rects->bounded.height;
	int width = rects->unbounded.width;
	int height = rects->unbounded.y + rects->unbounded.height - y;

	_cairo_xcb_connection_render_composite (dst->connection,
						XCB_RENDER_PICT_OP_OUT_REVERSE,
						mask->picture, XCB_NONE, dst->picture,
						x - mask_x, y - mask_y,
						0, 0,
						x, y,
						width, height);
    }

    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_cairo_xcb_surface_fixup_unbounded_boxes (cairo_xcb_surface_t *dst,
					  const cairo_composite_rectangles_t *extents,
					  cairo_region_t *clip_region,
					  cairo_boxes_t *boxes)
{
    cairo_boxes_t clear;
    cairo_box_t box;
    cairo_status_t status;
    struct _cairo_boxes_chunk *chunk;
    int i;

    if (boxes->num_boxes <= 1 && clip_region == NULL)
	return _cairo_xcb_surface_fixup_unbounded (dst, extents);

    _cairo_boxes_init (&clear);

    box.p1.x = _cairo_fixed_from_int (extents->unbounded.x + extents->unbounded.width);
    box.p1.y = _cairo_fixed_from_int (extents->unbounded.y);
    box.p2.x = _cairo_fixed_from_int (extents->unbounded.x);
    box.p2.y = _cairo_fixed_from_int (extents->unbounded.y + extents->unbounded.height);

    if (clip_region == NULL) {
	cairo_boxes_t tmp;

	_cairo_boxes_init (&tmp);

	status = _cairo_boxes_add (&tmp, &box);
	assert (status == CAIRO_STATUS_SUCCESS);

	tmp.chunks.next = &boxes->chunks;
	tmp.num_boxes += boxes->num_boxes;

	status = _cairo_bentley_ottmann_tessellate_boxes (&tmp,
							  CAIRO_FILL_RULE_WINDING,
							  &clear);

	tmp.chunks.next = NULL;
    } else {
	pixman_box32_t *pbox;

	pbox = pixman_region32_rectangles (&clip_region->rgn, &i);
	_cairo_boxes_limit (&clear, (cairo_box_t *) pbox, i);

	status = _cairo_boxes_add (&clear, &box);
	assert (status == CAIRO_STATUS_SUCCESS);

	for (chunk = &boxes->chunks; chunk != NULL; chunk = chunk->next) {
	    for (i = 0; i < chunk->count; i++) {
		status = _cairo_boxes_add (&clear, &chunk->base[i]);
		if (unlikely (status)) {
		    _cairo_boxes_fini (&clear);
		    return status;
		}
	    }
	}

	status = _cairo_bentley_ottmann_tessellate_boxes (&clear,
							  CAIRO_FILL_RULE_WINDING,
							  &clear);
    }

    if (likely (status == CAIRO_STATUS_SUCCESS)) {
	status = _render_fill_boxes (dst,
				     CAIRO_OPERATOR_CLEAR,
				     CAIRO_COLOR_TRANSPARENT,
				     boxes);
    }

    _cairo_boxes_fini (&clear);

    return status;
}

cairo_status_t
_cairo_xcb_surface_clear (cairo_xcb_surface_t *dst)
{
    xcb_gcontext_t gc;
    xcb_rectangle_t rect;
    cairo_status_t status;

    status = _cairo_xcb_connection_acquire (dst->connection);
    if (unlikely (status))
	return status;

    status = _cairo_xcb_connection_take_socket (dst->connection);
    if (unlikely (status)) {
	_cairo_xcb_connection_release (dst->connection);
	return status;
    }

    gc = _cairo_xcb_screen_get_gc (dst->screen, dst->drawable, dst->depth);

    rect.x = rect.y = 0;
    rect.width  = dst->width;
    rect.height = dst->height;

    _cairo_xcb_connection_poly_fill_rectangle (dst->connection,
					       dst->drawable, gc,
					       1, &rect);

    _cairo_xcb_screen_put_gc (dst->screen, dst->depth, gc);

    _cairo_xcb_connection_release (dst->connection);

    dst->deferred_clear = FALSE;
    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_clip_and_composite (cairo_xcb_surface_t	*dst,
		     cairo_operator_t		 op,
		     const cairo_pattern_t	*src,
		     xcb_draw_func_t		 draw_func,
		     void			*draw_closure,
		     cairo_composite_rectangles_t*extents,
		     cairo_clip_t		*clip)
{
    cairo_status_t status;
    cairo_region_t *clip_region = NULL;
    cairo_bool_t need_clip_surface = FALSE;

    if (clip != NULL) {
	status = _cairo_clip_get_region (clip, &clip_region);
	if (unlikely (status == CAIRO_INT_STATUS_NOTHING_TO_DO))
	    return CAIRO_STATUS_SUCCESS;

	assert (! _cairo_status_is_error (status));
	need_clip_surface = status == CAIRO_INT_STATUS_UNSUPPORTED;

	if (clip_region != NULL) {
	    cairo_rectangle_int_t rect;
	    cairo_bool_t is_empty;

	    cairo_region_get_extents (clip_region, &rect);
	    is_empty = ! _cairo_rectangle_intersect (&extents->unbounded, &rect);
	    if (unlikely (is_empty))
		return CAIRO_STATUS_SUCCESS;

	    is_empty = ! _cairo_rectangle_intersect (&extents->bounded, &rect);
	    if (unlikely (is_empty && extents->is_bounded))
		return CAIRO_STATUS_SUCCESS;

	    if (cairo_region_num_rectangles (clip_region) == 1)
		clip_region = NULL;
	}
    }

    status = _cairo_xcb_connection_acquire (dst->connection);
    if (unlikely (status))
	return status;

    status = _cairo_xcb_connection_take_socket (dst->connection);
    if (unlikely (status)) {
	_cairo_xcb_connection_release (dst->connection);
	return status;
    }

    if (dst->deferred_clear) {
	status = _cairo_xcb_surface_clear (dst);
	if (unlikely (status)) {
	    _cairo_xcb_connection_release (dst->connection);
	    return status;
	}
    }

    _cairo_xcb_surface_ensure_picture (dst);

    if (clip_region != NULL)
	_cairo_xcb_surface_set_clip_region (dst, clip_region);

    if (reduce_alpha_op (&dst->base, op, src)) {
	op = CAIRO_OPERATOR_ADD;
	src = NULL;
    }

    if (op == CAIRO_OPERATOR_SOURCE) {
	status = _clip_and_composite_source (clip, src,
					     draw_func, draw_closure,
					     dst, &extents->bounded);
    } else {
	if (op == CAIRO_OPERATOR_CLEAR) {
	    op = CAIRO_OPERATOR_DEST_OUT;
	    src = NULL;
	}

	if (need_clip_surface) {
	    if (extents->is_bounded) {
		status = _clip_and_composite_with_mask (clip, op, src,
							draw_func, draw_closure,
							dst, &extents->bounded);
	    } else {
		status = _clip_and_composite_combine (clip, op, src,
						      draw_func, draw_closure,
						      dst, &extents->bounded);
	    }
	} else {
	    status = draw_func (draw_closure,
				dst, op, src,
				0, 0,
				&extents->bounded,
				clip_region);
	}
    }

    if (status == CAIRO_STATUS_SUCCESS && ! extents->is_bounded) {
	if (need_clip_surface)
	    status = _cairo_xcb_surface_fixup_unbounded_with_mask (dst, extents, clip);
	else
	    status = _cairo_xcb_surface_fixup_unbounded (dst, extents);
    }

    if (clip_region != NULL)
	_cairo_xcb_surface_clear_clip_region (dst);

    _cairo_xcb_connection_release (dst->connection);

    return status;
}

static cairo_status_t
_core_boxes (cairo_xcb_surface_t *dst,
	     cairo_operator_t op,
	     const cairo_pattern_t *src,
	     cairo_boxes_t *boxes,
	     cairo_antialias_t antialias,
	     cairo_clip_t *clip,
	     const cairo_composite_rectangles_t *extents)
{
    if (antialias != CAIRO_ANTIALIAS_NONE) {
	if (! boxes->is_pixel_aligned)
	    return CAIRO_INT_STATUS_UNSUPPORTED;
    }

    if (clip != NULL) {
	cairo_region_t *clip_region;
	cairo_status_t status;

	status = _cairo_clip_get_region (clip, &clip_region);
	assert (status == CAIRO_STATUS_SUCCESS || CAIRO_INT_STATUS_UNSUPPORTED);

	if (status == CAIRO_INT_STATUS_UNSUPPORTED)
	    return CAIRO_INT_STATUS_UNSUPPORTED;
    }

    if (op == CAIRO_OPERATOR_CLEAR)
	return _cairo_xcb_surface_core_fill_boxes (dst, CAIRO_COLOR_TRANSPARENT, boxes);

    if (op == CAIRO_OPERATOR_OVER) {
	if (dst->base.is_clear || _cairo_pattern_is_opaque (src, &extents->bounded))
	    op = CAIRO_OPERATOR_SOURCE;
    }
    if (op != CAIRO_OPERATOR_SOURCE)
	return CAIRO_INT_STATUS_UNSUPPORTED;

    if (src->type == CAIRO_PATTERN_TYPE_SOLID) {
	return _cairo_xcb_surface_core_fill_boxes (dst,
						   &((cairo_solid_pattern_t *) src)->color,
						   boxes);
    }

    return _cairo_xcb_surface_core_copy_boxes (dst, src, &extents->bounded, boxes);
}

static cairo_status_t
_composite_boxes (cairo_xcb_surface_t *dst,
		  cairo_operator_t op,
		  const cairo_pattern_t *src,
		  cairo_boxes_t *boxes,
		  cairo_antialias_t antialias,
		  cairo_clip_t *clip,
		  const cairo_composite_rectangles_t *extents)
{
    cairo_bool_t need_clip_mask = FALSE;
    cairo_region_t *clip_region = NULL;
    cairo_status_t status;

    /* If the boxes are not pixel-aligned, we will need to compute a real mask */
    if (antialias != CAIRO_ANTIALIAS_NONE) {
	if (! boxes->is_pixel_aligned)
	    return CAIRO_INT_STATUS_UNSUPPORTED;
    }

    if (clip != NULL) {
	status = _cairo_clip_get_region (clip, &clip_region);
	assert (status == CAIRO_STATUS_SUCCESS || CAIRO_INT_STATUS_UNSUPPORTED);

	need_clip_mask = status == CAIRO_INT_STATUS_UNSUPPORTED;
	if (need_clip_mask &&
	    (! extents->is_bounded || op == CAIRO_OPERATOR_SOURCE))
	{
	    return CAIRO_INT_STATUS_UNSUPPORTED;
	}

	if (clip_region != NULL && cairo_region_num_rectangles (clip_region) == 1)
	    clip_region = NULL;
    }

    status = _cairo_xcb_connection_acquire (dst->connection);
    if (unlikely (status))
	return status;

    status = _cairo_xcb_connection_take_socket (dst->connection);
    if (unlikely (status)) {
	_cairo_xcb_connection_release (dst->connection);
	return status;
    }

    _cairo_xcb_surface_ensure_picture (dst);
    if (dst->flags & CAIRO_XCB_RENDER_HAS_FILL_RECTANGLES && ! need_clip_mask &&
	(op == CAIRO_OPERATOR_CLEAR || src->type == CAIRO_PATTERN_TYPE_SOLID))
    {
	const cairo_color_t *color;

	if (op == CAIRO_OPERATOR_CLEAR)
	    color = CAIRO_COLOR_TRANSPARENT;
	else
	    color = &((cairo_solid_pattern_t *) src)->color;

	if (! (op == CAIRO_OPERATOR_IN && color->alpha_short >= 0xff00))
	    status = _render_fill_boxes (dst, op, color, boxes);
    }
    else
    {
	cairo_surface_pattern_t mask;

	if (need_clip_mask) {
	    cairo_surface_t *clip_surface;
	    int clip_x, clip_y;

	    clip_surface = _cairo_clip_get_surface (clip, &dst->base, &clip_x, &clip_y);
	    if (unlikely (clip_surface->status))
		return clip_surface->status;

	    _cairo_pattern_init_for_surface (&mask, clip_surface);
	    mask.base.filter = CAIRO_FILTER_NEAREST;
	    cairo_matrix_init_translate (&mask.base.matrix,
					 -clip_x,
					 -clip_y);

	    if (op == CAIRO_OPERATOR_CLEAR) {
		src = NULL;
		op = CAIRO_OPERATOR_DEST_OUT;
	    }
	}

	status = _render_composite_boxes (dst, op, src,
					  need_clip_mask ? &mask.base : NULL,
					  &extents->bounded, boxes);

	if (need_clip_mask)
	    _cairo_pattern_fini (&mask.base);
    }

    if (status == CAIRO_STATUS_SUCCESS && ! extents->is_bounded) {
	status =
	    _cairo_xcb_surface_fixup_unbounded_boxes (dst, extents,
						      clip_region, boxes);
    }

    _cairo_xcb_connection_release (dst->connection);

    return status;
}

static cairo_status_t
_upload_image_inplace (cairo_xcb_surface_t *surface,
		       const cairo_pattern_t *source,
		       const cairo_rectangle_int_t *extents)
{
    const cairo_surface_pattern_t *pattern;
    cairo_image_surface_t *image;
    xcb_gcontext_t gc;
    cairo_status_t status;
    int tx, ty;
    int len, bpp;

    if (source->type != CAIRO_PATTERN_TYPE_SURFACE)
	return CAIRO_INT_STATUS_UNSUPPORTED;

    pattern = (const cairo_surface_pattern_t *) source;
    if (pattern->surface->type != CAIRO_SURFACE_TYPE_IMAGE)
	return CAIRO_INT_STATUS_UNSUPPORTED;

    {
	cairo_xcb_surface_t *snapshot;

	snapshot = (cairo_xcb_surface_t *)
	    _cairo_surface_has_snapshot (pattern->surface, &_cairo_xcb_surface_backend);
	if (snapshot != NULL) {
	    if (snapshot->screen == surface->screen)
		return CAIRO_INT_STATUS_UNSUPPORTED;
	}
    }

    {
	cairo_xcb_picture_t *snapshot;

	snapshot = (cairo_xcb_picture_t *)
	    _cairo_surface_has_snapshot (pattern->surface, &_cairo_xcb_picture_backend);
	if (snapshot != NULL) {
	    if (snapshot->screen == surface->screen)
		return CAIRO_INT_STATUS_UNSUPPORTED;
	}
    }

    image = (cairo_image_surface_t *) pattern->surface;
    if (image->format == CAIRO_FORMAT_INVALID)
	return CAIRO_INT_STATUS_UNSUPPORTED;

    if (image->depth != surface->depth)
	return CAIRO_INT_STATUS_UNSUPPORTED;

    if (! _cairo_matrix_is_integer_translation (&source->matrix, &tx, &ty))
	return CAIRO_INT_STATUS_UNSUPPORTED;

    image = (cairo_image_surface_t *) pattern->surface;
    if (source->extend != CAIRO_EXTEND_NONE &&
	(extents->x + tx < 0 ||
	 extents->y + ty < 0 ||
	 extents->x + tx + extents->width > image->width ||
	 extents->y + ty + extents->height > image->height))
    {
	return CAIRO_INT_STATUS_UNSUPPORTED;
    }

    status = _cairo_xcb_connection_acquire (surface->connection);
    if (unlikely (status))
	return status;

    status = _cairo_xcb_connection_take_socket (surface->connection);
    if (unlikely (status)) {
	_cairo_xcb_connection_release (surface->connection);
	return status;
    }
    gc = _cairo_xcb_screen_get_gc (surface->screen, surface->drawable, image->depth);

    /* Do we need to trim the image? */
    bpp = PIXMAN_FORMAT_BPP (image->pixman_format);
    len = CAIRO_STRIDE_FOR_WIDTH_BPP (extents->width, bpp);
    if (len == image->stride) {
	_cairo_xcb_connection_put_image (surface->connection,
					 surface->drawable, gc,
					 extents->width, extents->height,
					 extents->x, extents->y,
					 image->depth,
					 image->stride,
					 image->data +
					 (extents->y + ty) * image->stride +
					 (extents->x + tx) * bpp/8);
    } else {
	_cairo_xcb_connection_put_subimage (surface->connection,
					    surface->drawable, gc,
					    extents->x + tx, extents->y + ty,
					    extents->width, extents->height,
					    bpp / 8,
					    image->stride,
					    extents->x, extents->y,
					    image->depth,
					    image->data);

    }

    _cairo_xcb_screen_put_gc (surface->screen, image->depth, gc);
    _cairo_xcb_connection_release (surface->connection);

    if (surface->width == image->width && surface->height == image->height &&
	extents->width == image->width && extents->height == image->height)
    {
	_cairo_surface_attach_snapshot (&image->base, &surface->base, NULL);
    }

    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_clip_and_composite_boxes (cairo_xcb_surface_t *dst,
			   cairo_operator_t op,
			   const cairo_pattern_t *src,
			   cairo_boxes_t *boxes,
			   cairo_antialias_t antialias,
			   cairo_composite_rectangles_t *extents,
			   cairo_clip_t *clip)
{
    composite_traps_info_t info;
    cairo_status_t status;

    if (boxes->num_boxes == 0 && extents->is_bounded)
	return CAIRO_STATUS_SUCCESS;

    if (clip == NULL &&
	(op == CAIRO_OPERATOR_SOURCE || (op == CAIRO_OPERATOR_OVER && dst->base.is_clear)) &&
	boxes->num_boxes == 1 &&
	extents->bounded.width  == dst->width &&
	extents->bounded.height == dst->height)
    {
	op = CAIRO_OPERATOR_SOURCE;
	dst->deferred_clear = FALSE;

	status = _upload_image_inplace (dst, src, &extents->bounded);
	if (status != CAIRO_INT_STATUS_UNSUPPORTED)
	    return status;
    }

    if (dst->deferred_clear) {
	_cairo_xcb_surface_clear (dst);

	if (op == CAIRO_OPERATOR_OVER)
	    op = CAIRO_OPERATOR_SOURCE;
    }

    if (clip == NULL && op == CAIRO_OPERATOR_SOURCE && boxes->num_boxes == 1) {
	status = _upload_image_inplace (dst, src, &extents->bounded);
	if (status != CAIRO_INT_STATUS_UNSUPPORTED)
	    return status;
    }

    if ((dst->flags & CAIRO_XCB_RENDER_HAS_COMPOSITE) == 0)
	return _core_boxes (dst, op, src, boxes, antialias, clip, extents);

    if (dst->deferred_clear) {
	status = _cairo_xcb_surface_clear (dst);
	if (unlikely (status))
	    return status;
    }

    /* Use a fast path if the boxes are pixel aligned */
    status = _composite_boxes (dst, op, src, boxes, antialias, clip, extents);
    if (status != CAIRO_INT_STATUS_UNSUPPORTED)
	return status;

    if ((dst->flags & CAIRO_XCB_RENDER_HAS_COMPOSITE_TRAPEZOIDS) == 0)
	return CAIRO_INT_STATUS_UNSUPPORTED;

    /* Otherwise render via a mask and composite in the usual fashion.  */
    status = _cairo_traps_init_boxes (&info.traps, boxes);
    if (unlikely (status))
	return status;

    info.antialias = antialias;
    status = _clip_and_composite (dst, op, src,
				  _composite_traps, &info,
				  extents, clip);

    _cairo_traps_fini (&info.traps);
    return status;
}

static cairo_bool_t
_mono_edge_is_vertical (const cairo_line_t *line)
{
    return _cairo_fixed_integer_round (line->p1.x) == _cairo_fixed_integer_round (line->p2.x);
}

static cairo_bool_t
_traps_are_pixel_aligned (cairo_traps_t *traps,
			  cairo_antialias_t antialias)
{
    int i;

    if (antialias == CAIRO_ANTIALIAS_NONE) {
	for (i = 0; i < traps->num_traps; i++) {
	    if (! _mono_edge_is_vertical (&traps->traps[i].left)   ||
		! _mono_edge_is_vertical (&traps->traps[i].right))
	    {
		traps->maybe_region = FALSE;
		return FALSE;
	    }
	}
    } else {
	for (i = 0; i < traps->num_traps; i++) {
	    if (traps->traps[i].left.p1.x != traps->traps[i].left.p2.x   ||
		traps->traps[i].right.p1.x != traps->traps[i].right.p2.x ||
		! _cairo_fixed_is_integer (traps->traps[i].top)          ||
		! _cairo_fixed_is_integer (traps->traps[i].bottom)       ||
		! _cairo_fixed_is_integer (traps->traps[i].left.p1.x)    ||
		! _cairo_fixed_is_integer (traps->traps[i].right.p1.x))
	    {
		traps->maybe_region = FALSE;
		return FALSE;
	    }
	}
    }

    return TRUE;
}

static void
_boxes_for_traps (cairo_boxes_t *boxes,
		  cairo_traps_t *traps)
{
    int i;

    _cairo_boxes_init (boxes);

    boxes->num_boxes    = traps->num_traps;
    boxes->chunks.base  = (cairo_box_t *) traps->traps;
    boxes->chunks.count = traps->num_traps;
    boxes->chunks.size  = traps->num_traps;

    for (i = 0; i < traps->num_traps; i++) {
	cairo_fixed_t x1 = traps->traps[i].left.p1.x;
	cairo_fixed_t x2 = traps->traps[i].right.p1.x;
	cairo_fixed_t y1 = traps->traps[i].top;
	cairo_fixed_t y2 = traps->traps[i].bottom;

	boxes->chunks.base[i].p1.x = x1;
	boxes->chunks.base[i].p1.y = y1;
	boxes->chunks.base[i].p2.x = x2;
	boxes->chunks.base[i].p2.y = y2;

	if (boxes->is_pixel_aligned) {
	    boxes->is_pixel_aligned =
		_cairo_fixed_is_integer (x1) && _cairo_fixed_is_integer (y1) &&
		_cairo_fixed_is_integer (x2) && _cairo_fixed_is_integer (y2);
	}
    }
}

typedef struct _cairo_xcb_surface_span_renderer {
    cairo_span_renderer_t base;

    void *spans;
    unsigned len;
    unsigned size;
    uint16_t spans_embedded[1024];
} cairo_xcb_surface_span_renderer_t;

static cairo_status_t
_cairo_xcb_surface_span_renderer_accumulate (void	*abstract_renderer,
					     int	 y,
					     int	 height,
					     const cairo_half_open_span_t *spans,
					     unsigned	 num_spans)
{
    cairo_xcb_surface_span_renderer_t *renderer = abstract_renderer;
    uint16_t *u16;
    int len;

    len = 4 * (2 + num_spans);
    if (renderer->size < renderer->len + len) {
	char *new_spans;

	do {
	    renderer->size <<= 1;
	} while (renderer->size < renderer->len + len);

	if (renderer->spans == renderer->spans_embedded) {
	    new_spans = malloc (renderer->size);
	    if (unlikely (new_spans == NULL))
		return _cairo_error (CAIRO_STATUS_NO_MEMORY);

	    memcpy (new_spans, renderer->spans, renderer->len);
	} else {
	    new_spans = realloc (renderer->spans, renderer->size);
	    if (unlikely (new_spans == NULL))
		return _cairo_error (CAIRO_STATUS_NO_MEMORY);
	}

	renderer->spans = new_spans;
    }

    u16 = (uint16_t *) ((char *) renderer->spans + renderer->len);
    *u16++ = y;
    *u16++ = height;
    *u16++ = num_spans;
    *u16++ = 0;
    while (num_spans--) {
	*u16++ = spans->x;
	*u16++ = spans->coverage * 0x0101;
	spans++;
    }
    renderer->len += len;

    return CAIRO_STATUS_SUCCESS;
}

typedef struct {
    cairo_polygon_t		*polygon;
    cairo_fill_rule_t		 fill_rule;
    cairo_antialias_t		 antialias;
} composite_spans_info_t;

static cairo_status_t
_composite_spans (void *closure,
		  cairo_xcb_surface_t *dst,
		  cairo_operator_t op,
		  const cairo_pattern_t         *pattern,
		  int                            dst_x,
		  int                            dst_y,
		  const cairo_rectangle_int_t   *extents,
		  cairo_region_t		*clip_region)
{
    composite_spans_info_t *info = closure;
    cairo_xcb_surface_span_renderer_t renderer;
    cairo_scan_converter_t *converter;
    cairo_status_t status;
    cairo_xcb_picture_t *src;

    renderer.base.render_rows = _cairo_xcb_surface_span_renderer_accumulate;
    renderer.spans = renderer.spans_embedded;
    renderer.size = ARRAY_LENGTH (renderer.spans_embedded);
    renderer.len = 0;

    converter = _cairo_tor_scan_converter_create (extents->x,
						  extents->x + extents->width,
						  extents->y,
						  extents->y + extents->height,
						  info->fill_rule);
    status = converter->add_polygon (converter, info->polygon);
    if (unlikely (status))
	goto CLEANUP_RENDERER;

    status = converter->generate (converter, &renderer.base);
    if (unlikely (status))
	goto CLEANUP_CONVERTER;

    src = _cairo_xcb_picture_for_pattern (dst, pattern, extents);
    status = src->base.status;
    if (unlikely (status))
	goto CLEANUP_CONVERTER;

    _cairo_xcb_connection_render_spans (dst->connection,
					dst->picture,
					_render_operator (op),
					src->picture,
					extents->x + src->x, extents->y + src->y,
					extents->x + dst_x, extents->y + dst_y,
					extents->width, extents->height,
					renderer.len >> 1, renderer.spans);
    cairo_surface_destroy (&src->base);

 CLEANUP_CONVERTER:
    converter->destroy (converter);
 CLEANUP_RENDERER:
    if (renderer.spans != renderer.spans_embedded)
	free (renderer.spans);

    return status;
}

static cairo_status_t
_composite_mask (void				*closure,
		 cairo_xcb_surface_t		*dst,
		 cairo_operator_t		 op,
		 const cairo_pattern_t		*src_pattern,
		 int				 dst_x,
		 int				 dst_y,
		 const cairo_rectangle_int_t	*extents,
		 cairo_region_t			*clip_region)
{
    const cairo_pattern_t *mask_pattern = closure;
    cairo_xcb_picture_t *src, *mask = NULL;

    if (src_pattern != NULL) {
	src = _cairo_xcb_picture_for_pattern (dst, src_pattern, extents);
	if (unlikely (src->base.status))
	    return src->base.status;

	mask = _cairo_xcb_picture_for_pattern (dst, mask_pattern, extents);
	if (unlikely (mask->base.status)) {
	    cairo_surface_destroy (&src->base);
	    return mask->base.status;
	}

	_cairo_xcb_connection_render_composite (dst->connection,
						_render_operator (op),
						src->picture,
						mask->picture,
						dst->picture,
						extents->x + src->x,  extents->y + src->y,
						extents->x + mask->x, extents->y + mask->y,
						extents->x - dst_x,   extents->y - dst_y,
						extents->width,       extents->height);
	cairo_surface_destroy (&mask->base);
	cairo_surface_destroy (&src->base);
    } else {
	src = _cairo_xcb_picture_for_pattern (dst, mask_pattern, extents);
	if (unlikely (src->base.status))
	    return src->base.status;

	_cairo_xcb_connection_render_composite (dst->connection,
						_render_operator (op),
						src->picture,
						XCB_NONE,
						dst->picture,
						extents->x + src->x,  extents->y + src->y,
						0, 0,
						extents->x - dst_x,   extents->y - dst_y,
						extents->width,       extents->height);
	cairo_surface_destroy (&src->base);
    }

    return CAIRO_STATUS_SUCCESS;
}

/* high level rasteriser -> compositor */

static cairo_clip_path_t *
_clip_get_single_path (cairo_clip_t *clip)
{
    cairo_clip_path_t *iter = clip->path;
    cairo_clip_path_t *path = NULL;

    do {
	if ((iter->flags & CAIRO_CLIP_PATH_IS_BOX) == 0) {
	    if (path != NULL)
		return FALSE;

	    path = iter;
	}
	iter = iter->prev;
    } while (iter != NULL);

    return path;
}

cairo_int_status_t
_cairo_xcb_surface_render_paint (cairo_xcb_surface_t	*surface,
				 cairo_operator_t	 op,
				 const cairo_pattern_t	*source,
				 cairo_clip_t		*clip)
{
    cairo_composite_rectangles_t extents;
    cairo_boxes_t boxes;
    cairo_box_t *clip_boxes = boxes.boxes_embedded;
    cairo_clip_t local_clip;
    cairo_clip_path_t *clip_path;
    cairo_bool_t have_clip = FALSE;
    int num_boxes = ARRAY_LENGTH (boxes.boxes_embedded);
    cairo_status_t status;

    if (unlikely (! _operator_is_supported (surface->flags, op)))
	return CAIRO_INT_STATUS_UNSUPPORTED;

    if ((surface->flags & (CAIRO_XCB_RENDER_HAS_COMPOSITE_SPANS |
			   CAIRO_XCB_RENDER_HAS_COMPOSITE_TRAPEZOIDS |
			   CAIRO_XCB_RENDER_HAS_COMPOSITE)) == 0)
    {
	return CAIRO_INT_STATUS_UNSUPPORTED;
    }

    if (op == CAIRO_OPERATOR_CLEAR && clip == NULL) {
	surface->deferred_clear = TRUE;
	return CAIRO_STATUS_SUCCESS;
    }

    status = _cairo_composite_rectangles_init_for_paint (&extents,
							 surface->width,
							 surface->height,
							 op, source,
							 clip);
    if (unlikely (status))
	return status;

    if (_cairo_clip_contains_extents (clip, &extents))
	clip = NULL;

    if (clip != NULL) {
	clip = _cairo_clip_init_copy (&local_clip, clip);
	have_clip = TRUE;
    }

    status = _cairo_clip_to_boxes (&clip, &extents, &clip_boxes, &num_boxes);
    if (unlikely (status)) {
	if (have_clip)
	    _cairo_clip_fini (&local_clip);

	return status;
    }

    if (clip != NULL &&
	extents.is_bounded &&
	(clip_path = _clip_get_single_path (clip)) != NULL)
    {
	status = _cairo_xcb_surface_render_fill (surface, op, source,
						 &clip_path->path,
						 clip_path->fill_rule,
						 clip_path->tolerance,
						 clip_path->antialias,
						 NULL);
    }
    else
    {
	_cairo_boxes_init_for_array (&boxes, clip_boxes, num_boxes);
	status = _clip_and_composite_boxes (surface, op, source,
					    &boxes, CAIRO_ANTIALIAS_DEFAULT,
					    &extents, clip);
	if (clip_boxes != boxes.boxes_embedded)
	    free (clip_boxes);
    }

    if (have_clip)
	_cairo_clip_fini (&local_clip);

    return status;
}

cairo_int_status_t
_cairo_xcb_surface_render_mask (cairo_xcb_surface_t	*surface,
				cairo_operator_t	 op,
				const cairo_pattern_t	*source,
				const cairo_pattern_t	*mask,
				cairo_clip_t		*clip)
{
    cairo_composite_rectangles_t extents;
    cairo_clip_t local_clip;
    cairo_bool_t have_clip = FALSE;
    cairo_status_t status;

    if (unlikely (! _operator_is_supported (surface->flags, op)))
	return CAIRO_INT_STATUS_UNSUPPORTED;

    if ((surface->flags & CAIRO_XCB_RENDER_HAS_COMPOSITE) == 0)
	return CAIRO_INT_STATUS_UNSUPPORTED;

    status = _cairo_composite_rectangles_init_for_mask (&extents,
							surface->width, surface->height,
							op, source, mask, clip);
    if (unlikely (status))
	return status;

    if (_cairo_clip_contains_extents (clip, &extents))
	clip = NULL;

    if (clip != NULL && extents.is_bounded) {
	clip = _cairo_clip_init_copy (&local_clip, clip);
	status = _cairo_clip_rectangle (clip, &extents.bounded);
	if (unlikely (status)) {
	    _cairo_clip_fini (&local_clip);
	    return status;
	}
	have_clip = TRUE;
    }

    status = _clip_and_composite (surface, op, source,
				  _composite_mask, (void *) mask,
				  &extents, clip);

    if (have_clip)
	_cairo_clip_fini (&local_clip);

    return status;
}

typedef struct {
    cairo_polygon_t	polygon;
    cairo_fill_rule_t	fill_rule;
    cairo_antialias_t	antialias;
} composite_polygon_info_t;

static cairo_status_t
_cairo_xcb_surface_render_composite_polygon (cairo_xcb_surface_t *dst,
					     cairo_operator_t op,
					     const cairo_pattern_t *source,
					     cairo_polygon_t *polygon,
					     cairo_antialias_t antialias,
					     cairo_fill_rule_t fill_rule,
					     cairo_composite_rectangles_t *extents,
					     cairo_clip_t *clip)
{
    composite_traps_info_t traps;
    cairo_bool_t clip_surface = FALSE;
    cairo_status_t status;
    cairo_bool_t is_not_empty;

    if (polygon->num_edges == 0) {
	status = CAIRO_STATUS_SUCCESS;

	if (! extents->is_bounded) {
	    cairo_region_t *clip_region = NULL;

	    if (clip != NULL) {
		status = _cairo_clip_get_region (clip, &clip_region);
		clip_surface = status == CAIRO_INT_STATUS_UNSUPPORTED;

		if (clip_region != NULL && cairo_region_num_rectangles (clip_region) == 1)
		    clip_region = NULL;
	    }

	    if (clip_surface == FALSE) {
		if (clip_region != NULL)
		    _cairo_xcb_surface_set_clip_region (dst, clip_region);

		status = _cairo_xcb_surface_fixup_unbounded (dst, extents);

		if (clip_region != NULL)
		    _cairo_xcb_surface_clear_clip_region (dst);
	    } else {
		status = _cairo_xcb_surface_fixup_unbounded_with_mask (dst,
								       extents,
								       clip);
	    }
	}

	return status;
    }

    _cairo_box_round_to_rectangle (&polygon->extents, &extents->mask);
    is_not_empty = _cairo_rectangle_intersect (&extents->bounded, &extents->mask);
    if (extents->is_bounded && ! is_not_empty)
	return CAIRO_STATUS_SUCCESS;

    if (dst->flags & CAIRO_XCB_RENDER_HAS_COMPOSITE_SPANS) {
	composite_spans_info_t spans;

	spans.polygon = polygon;
	spans.fill_rule = CAIRO_FILL_RULE_WINDING;
	spans.antialias = antialias;

	return _clip_and_composite (dst, op, source,
				    _composite_spans, &spans,
				    extents, clip);
    }

    _cairo_traps_init (&traps.traps);

    status = _cairo_bentley_ottmann_tessellate_polygon (&traps.traps, polygon, fill_rule);
    if (unlikely (status))
	goto CLEANUP_TRAPS;

    if (clip != NULL) {
	cairo_region_t *clip_region;

	status = _cairo_clip_get_region (clip, &clip_region);
	clip_surface = status == CAIRO_INT_STATUS_UNSUPPORTED;
    }

    if (traps.traps.has_intersections) {
	if (traps.traps.is_rectangular)
	    status = _cairo_bentley_ottmann_tessellate_rectangular_traps (&traps.traps, CAIRO_FILL_RULE_WINDING);
	else if (traps.traps.is_rectilinear)
	    status = _cairo_bentley_ottmann_tessellate_rectilinear_traps (&traps.traps, CAIRO_FILL_RULE_WINDING);
	else
	    status = _cairo_bentley_ottmann_tessellate_traps (&traps.traps, CAIRO_FILL_RULE_WINDING);
	if (unlikely (status))
	    goto CLEANUP_TRAPS;
    }

    /* Use a fast path if the trapezoids consist of a simple region,
     * but we can only do this if we do not have a clip surface, or can
     * substitute the mask with the clip.
     */
    if (traps.traps.maybe_region &&
	_traps_are_pixel_aligned (&traps.traps, antialias) &&
	(! clip_surface ||
	 (extents->is_bounded && op != CAIRO_OPERATOR_SOURCE)))
    {
	cairo_boxes_t boxes;

	_boxes_for_traps (&boxes, &traps.traps);
	status = _clip_and_composite_boxes (dst, op, source,
					    &boxes, antialias,
					    extents, clip);
    }
    else
    {
	/* Otherwise render the trapezoids to a mask and composite in the usual
	 * fashion.
	 */
	traps.antialias = antialias;
	status = _clip_and_composite (dst, op, source,
				      _composite_traps, &traps,
				      extents, clip);
    }

CLEANUP_TRAPS:
    _cairo_traps_fini (&traps.traps);

    return status;
}

static cairo_int_status_t
_cairo_xcb_surface_render_stroke_as_polygon (cairo_xcb_surface_t	*dst,
					     cairo_operator_t		 op,
					     const cairo_pattern_t	*source,
					     cairo_path_fixed_t		*path,
					     const cairo_stroke_style_t	*stroke_style,
					     const cairo_matrix_t	*ctm,
					     const cairo_matrix_t	*ctm_inverse,
					     double			 tolerance,
					     cairo_antialias_t		 antialias,
					     cairo_clip_t		*clip,
					     const cairo_box_t		*clip_boxes,
					     int			 num_boxes,
					     cairo_composite_rectangles_t *extents)
{
    cairo_polygon_t polygon;
    cairo_status_t status;

    _cairo_polygon_init (&polygon);
    _cairo_polygon_limit (&polygon, clip_boxes, num_boxes);

    status = _cairo_path_fixed_stroke_to_polygon (path,
						  stroke_style,
						  ctm, ctm_inverse,
						  tolerance,
						  &polygon);
    if (likely (status == CAIRO_STATUS_SUCCESS)) {
	status = _cairo_xcb_surface_render_composite_polygon (dst, op, source,
							      &polygon, antialias,
							      CAIRO_FILL_RULE_WINDING,
							      extents, clip);
    }

    _cairo_polygon_fini (&polygon);

    return status;
}

static void
_clear_image (cairo_surface_t *surface)
{
    cairo_image_surface_t *image = (cairo_image_surface_t *) surface;
    memset (image->data, 0, image->stride * image->height);
    surface->is_clear = TRUE;
}

static cairo_status_t
_cairo_xcb_surface_render_stroke_via_mask (cairo_xcb_surface_t		*dst,
					   cairo_operator_t		 op,
					   const cairo_pattern_t	*source,
					   cairo_path_fixed_t		*path,
					   const cairo_stroke_style_t	*stroke_style,
					   const cairo_matrix_t		*ctm,
					   const cairo_matrix_t		*ctm_inverse,
					   double			 tolerance,
					   cairo_antialias_t		 antialias,
					   cairo_clip_t			*clip,
					   cairo_composite_rectangles_t *extents)
{
    cairo_surface_t *image;
    cairo_status_t status;
    int x, y;

    x = extents->bounded.x;
    y = extents->bounded.y;
    image = _cairo_xcb_surface_create_similar_image (dst, CAIRO_CONTENT_ALPHA,
						     extents->bounded.width,
						     extents->bounded.height);
    if (unlikely (image->status))
	return image->status;

    _clear_image (image);

    status = _cairo_surface_offset_stroke (image, x, y,
					   CAIRO_OPERATOR_ADD,
					   &_cairo_pattern_white.base,
					   path, stroke_style,
					   ctm, ctm_inverse,
					   tolerance, antialias,
					   NULL);
    if (likely (status == CAIRO_STATUS_SUCCESS)) {
	cairo_surface_pattern_t mask;

	_cairo_pattern_init_for_surface (&mask, image);
	mask.base.filter = CAIRO_FILTER_NEAREST;

	cairo_matrix_init_translate (&mask.base.matrix, -x, -y);
	status = _clip_and_composite (dst, op, source,
				      _composite_mask, (void *) &mask.base,
				      extents, clip);
	_cairo_pattern_fini (&mask.base);
    }

    cairo_surface_finish (image);
    cairo_surface_destroy (image);

    return status;
}

cairo_int_status_t
_cairo_xcb_surface_render_stroke (cairo_xcb_surface_t	*surface,
				  cairo_operator_t	 op,
				  const cairo_pattern_t	*source,
				  cairo_path_fixed_t	*path,
				  const cairo_stroke_style_t	*style,
				  const cairo_matrix_t	*ctm,
				  const cairo_matrix_t	*ctm_inverse,
				  double		 tolerance,
				  cairo_antialias_t	 antialias,
				  cairo_clip_t		*clip)
{
    cairo_composite_rectangles_t extents;
    cairo_box_t boxes_stack[32], *clip_boxes = boxes_stack;
    int num_boxes = ARRAY_LENGTH (boxes_stack);
    cairo_clip_t local_clip;
    cairo_bool_t have_clip = FALSE;
    cairo_status_t status;

    if (unlikely (! _operator_is_supported (surface->flags, op)))
	return CAIRO_INT_STATUS_UNSUPPORTED;

    if ((surface->flags & (CAIRO_XCB_RENDER_HAS_COMPOSITE_SPANS |
			   CAIRO_XCB_RENDER_HAS_COMPOSITE_TRAPEZOIDS |
			   CAIRO_XCB_RENDER_HAS_COMPOSITE)) == 0)
    {
	return CAIRO_INT_STATUS_UNSUPPORTED;
    }

    status = _cairo_composite_rectangles_init_for_stroke (&extents,
							  surface->width,
							  surface->height,
							  op, source,
							  path, style, ctm,
							  clip);
    if (unlikely (status))
	return status;

    if (_cairo_clip_contains_extents (clip, &extents))
	clip = NULL;

    if (clip != NULL) {
	clip = _cairo_clip_init_copy (&local_clip, clip);
	have_clip = TRUE;
    }

    status = _cairo_clip_to_boxes (&clip, &extents, &clip_boxes, &num_boxes);
    if (unlikely (status)) {
	if (have_clip)
	    _cairo_clip_fini (&local_clip);

	return status;
    }

    status = CAIRO_INT_STATUS_UNSUPPORTED;
    if (path->is_rectilinear) {
	cairo_boxes_t boxes;

	_cairo_boxes_init (&boxes);
	_cairo_boxes_limit (&boxes, clip_boxes, num_boxes);

	status = _cairo_path_fixed_stroke_rectilinear_to_boxes (path,
								style,
								ctm,
								&boxes);
	if (likely (status == CAIRO_STATUS_SUCCESS)) {
	    status = _clip_and_composite_boxes (surface, op, source,
						&boxes, antialias,
						&extents, clip);
	}

	_cairo_boxes_fini (&boxes);
    }

    if (status == CAIRO_INT_STATUS_UNSUPPORTED) {
	if (surface->flags & (CAIRO_XCB_RENDER_HAS_COMPOSITE_SPANS | CAIRO_XCB_RENDER_HAS_COMPOSITE_TRAPEZOIDS)) {
	    status = _cairo_xcb_surface_render_stroke_as_polygon (surface, op, source,
								  path, style,
								  ctm, ctm_inverse,
								  tolerance, antialias,
								  clip, clip_boxes, num_boxes,
								  &extents);
	} else if (surface->flags & CAIRO_XCB_RENDER_HAS_COMPOSITE) {
	    status = _cairo_xcb_surface_render_stroke_via_mask (surface, op, source,
								path, style,
								ctm, ctm_inverse,
								tolerance, antialias,
								have_clip ? &local_clip : NULL,
								&extents);
	} else {
	    ASSERT_NOT_REACHED;
	}
    }

    if (clip_boxes != boxes_stack)
	free (clip_boxes);

    if (have_clip)
	_cairo_clip_fini (&local_clip);

    return status;
}

static cairo_status_t
_cairo_xcb_surface_render_fill_as_polygon (cairo_xcb_surface_t	*dst,
					   cairo_operator_t	 op,
					   const cairo_pattern_t*source,
					   cairo_path_fixed_t	*path,
					   cairo_fill_rule_t	 fill_rule,
					   double		 tolerance,
					   cairo_antialias_t	 antialias,
					   cairo_clip_t		*clip,
					   cairo_box_t		*clip_boxes,
					   int			 num_boxes,
					   cairo_composite_rectangles_t *extents)
{
    cairo_polygon_t polygon;
    cairo_status_t status;

    _cairo_polygon_init (&polygon);
    _cairo_polygon_limit (&polygon, clip_boxes, num_boxes);

    status = _cairo_path_fixed_fill_to_polygon (path, tolerance, &polygon);
    if (likely (status == CAIRO_STATUS_SUCCESS)) {
	status = _cairo_xcb_surface_render_composite_polygon (dst, op, source,
							      &polygon, antialias,
							      fill_rule,
							      extents, clip);
    }

    _cairo_polygon_fini (&polygon);

    return status;
}

static cairo_status_t
_cairo_xcb_surface_render_fill_via_mask (cairo_xcb_surface_t	*dst,
					 cairo_operator_t	 op,
					 const cairo_pattern_t	*source,
					 cairo_path_fixed_t	*path,
					 cairo_fill_rule_t	 fill_rule,
					 double			 tolerance,
					 cairo_antialias_t	 antialias,
					 cairo_clip_t		*clip,
					 cairo_composite_rectangles_t *extents)
{
    cairo_surface_t *image;
    cairo_status_t status;
    int x, y;

    x = extents->bounded.x;
    y = extents->bounded.y;
    image = _cairo_xcb_surface_create_similar_image (dst,
						     CAIRO_CONTENT_ALPHA,
						     extents->bounded.width,
						     extents->bounded.height);
    if (unlikely (image->status))
	return image->status;

    _clear_image (image);

    status = _cairo_surface_offset_fill (image, x, y,
					 CAIRO_OPERATOR_ADD,
					 &_cairo_pattern_white.base,
					 path, fill_rule, tolerance, antialias,
					 NULL);
    if (likely (status == CAIRO_STATUS_SUCCESS)) {
	cairo_surface_pattern_t mask;

	_cairo_pattern_init_for_surface (&mask, image);
	mask.base.filter = CAIRO_FILTER_NEAREST;

	cairo_matrix_init_translate (&mask.base.matrix, -x, -y);
	status = _clip_and_composite (dst, op, source,
				      _composite_mask, (void *) &mask.base,
				      extents, clip);

	_cairo_pattern_fini (&mask.base);
    }

    cairo_surface_finish (image);
    cairo_surface_destroy (image);

    return status;
}

cairo_int_status_t
_cairo_xcb_surface_render_fill (cairo_xcb_surface_t	*surface,
			       cairo_operator_t		 op,
			       const cairo_pattern_t	*source,
			       cairo_path_fixed_t	*path,
			       cairo_fill_rule_t	 fill_rule,
			       double			 tolerance,
			       cairo_antialias_t	 antialias,
			       cairo_clip_t		*clip)
{
    cairo_composite_rectangles_t extents;
    cairo_box_t boxes_stack[32], *clip_boxes = boxes_stack;
    int num_boxes = ARRAY_LENGTH (boxes_stack);
    cairo_clip_t local_clip;
    cairo_bool_t have_clip = FALSE;
    cairo_status_t status;

    if (unlikely (! _operator_is_supported (surface->flags, op)))
	return CAIRO_INT_STATUS_UNSUPPORTED;

    if ((surface->flags & (CAIRO_XCB_RENDER_HAS_COMPOSITE_SPANS |
			   CAIRO_XCB_RENDER_HAS_COMPOSITE_TRAPEZOIDS |
			   CAIRO_XCB_RENDER_HAS_COMPOSITE)) == 0)
    {
	return CAIRO_INT_STATUS_UNSUPPORTED;
    }

    status = _cairo_composite_rectangles_init_for_fill (&extents,
							surface->width,
							surface->height,
							op, source, path,
							clip);
    if (unlikely (status))
	return status;

    if (_cairo_clip_contains_extents (clip, &extents))
	clip = NULL;

    if (clip != NULL) {
	clip = _cairo_clip_init_copy (&local_clip, clip);
	have_clip = TRUE;
    }

    status = _cairo_clip_to_boxes (&clip, &extents, &clip_boxes, &num_boxes);
    if (unlikely (status)) {
	if (have_clip)
	    _cairo_clip_fini (&local_clip);

	return status;
    }

    status = CAIRO_INT_STATUS_UNSUPPORTED;
    if (_cairo_path_fixed_is_rectilinear_fill (path)) {
	cairo_boxes_t boxes;

	_cairo_boxes_init (&boxes);
	_cairo_boxes_limit (&boxes, clip_boxes, num_boxes);

	status = _cairo_path_fixed_fill_rectilinear_to_boxes (path,
							      fill_rule,
							      &boxes);
	if (likely (status == CAIRO_STATUS_SUCCESS)) {
	    status = _clip_and_composite_boxes (surface, op, source,
						&boxes, antialias,
						&extents, clip);
	}

	_cairo_boxes_fini (&boxes);
    }

    if (status == CAIRO_INT_STATUS_UNSUPPORTED) {
	if (surface->flags & (CAIRO_XCB_RENDER_HAS_COMPOSITE_SPANS | CAIRO_XCB_RENDER_HAS_COMPOSITE_TRAPEZOIDS)) {
	    status = _cairo_xcb_surface_render_fill_as_polygon (surface, op, source, path,
								fill_rule, tolerance, antialias,
								clip, clip_boxes, num_boxes,
								&extents);
	} else if (surface->flags & CAIRO_XCB_RENDER_HAS_COMPOSITE) {
	    status = _cairo_xcb_surface_render_fill_via_mask (surface, op, source, path,
							      fill_rule, tolerance, antialias,
							      have_clip ? &local_clip : NULL,
							      &extents);
	} else {
	    ASSERT_NOT_REACHED;
	}
    }

    if (clip_boxes != boxes_stack)
	free (clip_boxes);

    if (have_clip)
	_cairo_clip_fini (&local_clip);

    return status;
}

static cairo_status_t
_cairo_xcb_surface_render_glyphs_via_mask (cairo_xcb_surface_t		*dst,
					   cairo_operator_t		 op,
					   const cairo_pattern_t	*source,
					   cairo_scaled_font_t		*scaled_font,
					   cairo_glyph_t		*glyphs,
					   int				 num_glyphs,
					   cairo_clip_t			*clip,
					   cairo_composite_rectangles_t *extents)
{
    cairo_surface_t *image;
    cairo_content_t content;
    cairo_status_t status;
    int x, y;

    content = CAIRO_CONTENT_ALPHA;
    if (scaled_font->options.antialias == CAIRO_ANTIALIAS_SUBPIXEL)
	content = CAIRO_CONTENT_COLOR_ALPHA;

    x = extents->bounded.x;
    y = extents->bounded.y;
    image = _cairo_xcb_surface_create_similar_image (dst, content,
						     extents->bounded.width,
						     extents->bounded.height);
    if (unlikely (image->status))
	return image->status;

    _clear_image (image);

    status = _cairo_surface_offset_glyphs (image, x, y,
					   CAIRO_OPERATOR_ADD,
					   &_cairo_pattern_white.base,
					   scaled_font, glyphs, num_glyphs,
					   NULL);
    if (likely (status == CAIRO_STATUS_SUCCESS)) {
	cairo_surface_pattern_t mask;

	_cairo_pattern_init_for_surface (&mask, image);
	mask.base.filter = CAIRO_FILTER_NEAREST;
	if (content & CAIRO_CONTENT_COLOR)
	    mask.base.has_component_alpha = TRUE;

	cairo_matrix_init_translate (&mask.base.matrix, -x, -y);
	status = _clip_and_composite (dst, op, source,
				      _composite_mask, (void *) &mask.base,
				      extents, clip);

	_cairo_pattern_fini (&mask.base);
    }

    cairo_surface_finish (image);
    cairo_surface_destroy (image);

    return status;
}

/* Build a struct of the same size of #cairo_glyph_t that can be used both as
 * an input glyph with double coordinates, and as "working" glyph with
 * integer from-current-point offsets. */
typedef union {
    cairo_glyph_t d;
    unsigned long index;
    struct {
        unsigned long index;
        int x;
        int y;
    } i;
} cairo_xcb_glyph_t;

/* compile-time assert that #cairo_xcb_glyph_t is the same size as #cairo_glyph_t */
COMPILE_TIME_ASSERT (sizeof (cairo_xcb_glyph_t) == sizeof (cairo_glyph_t));

typedef struct {
    cairo_scaled_font_t *font;
    cairo_xcb_glyph_t *glyphs;
    int num_glyphs;
    cairo_bool_t use_mask;
} composite_glyphs_info_t;

static cairo_status_t
_can_composite_glyphs (cairo_xcb_surface_t *dst,
		       cairo_scaled_font_t *scaled_font,
		       cairo_glyph_t *glyphs,
		       int num_glyphs)
{
    unsigned long glyph_cache[64];
    cairo_status_t status;
    const int max_glyph_size = dst->connection->maximum_request_length - 64;
    int i;

    memset (glyph_cache, 0, sizeof (glyph_cache));

    /* first scan for oversized glyphs, and fallback in that case */
    for (i = 0; i < num_glyphs; i++) {
	cairo_scaled_glyph_t *scaled_glyph;
	int width, height, len;
	int g;

	g = glyphs[i].index % ARRAY_LENGTH (glyph_cache);
	if (glyph_cache[g] == glyphs[i].index)
	    continue;

	status = _cairo_scaled_glyph_lookup (scaled_font,
					     glyphs[i].index,
					     CAIRO_SCALED_GLYPH_INFO_METRICS,
					     &scaled_glyph);
	if (unlikely (status))
	    return status;

	/* XRenderAddGlyph does not handle a glyph surface larger than
	 * the extended maximum XRequest size.
	 */
	width  =
	    _cairo_fixed_integer_ceil (scaled_glyph->bbox.p2.x - scaled_glyph->bbox.p1.x);
	height =
	    _cairo_fixed_integer_ceil (scaled_glyph->bbox.p2.y - scaled_glyph->bbox.p1.y);
	len = CAIRO_STRIDE_FOR_WIDTH_BPP (width, 32) * height;
	if (len >= max_glyph_size)
	    return CAIRO_INT_STATUS_UNSUPPORTED;

	glyph_cache[g] = glyphs[i].index;
    }

    return CAIRO_STATUS_SUCCESS;
}

/* Start a new element for the first glyph,
 * or for any glyph that has unexpected position,
 * or if current element has too many glyphs
 * (Xrender limits each element to 252 glyphs, we limit them to 128)
 *
 * These same conditions need to be mirrored between
 * _cairo_xcb_surface_emit_glyphs and _emit_glyph_chunks
 */
#define _start_new_glyph_elt(count, glyph) \
    (((count) & 127) == 0 || (glyph)->i.x || (glyph)->i.y)

/* sz_xGlyphtElt required alignment to a 32-bit boundary, so ensure we have
 * enough room for padding */
typedef struct {
    uint8_t   len;
    uint8_t   pad1;
    uint16_t  pad2;
    int16_t   deltax;
    int16_t   deltay;
} x_glyph_elt_t;
#define _cairo_sz_x_glyph_elt_t (sizeof (x_glyph_elt_t) + 4)

static cairo_xcb_font_glyphset_info_t *
_cairo_xcb_scaled_glyph_get_glyphset_info (cairo_scaled_glyph_t *scaled_glyph)
{
    return scaled_glyph->surface_private;
}

static void
_cairo_xcb_scaled_glyph_set_glyphset_info (cairo_scaled_glyph_t            *scaled_glyph,
					   cairo_xcb_font_glyphset_info_t *glyphset_info)
{
    scaled_glyph->surface_private = glyphset_info;
}

static cairo_status_t
_cairo_xcb_surface_font_init (cairo_xcb_connection_t *connection,
			      cairo_scaled_font_t  *scaled_font)
{
    cairo_xcb_font_t	*font_private;
    int i;

    font_private = malloc (sizeof (cairo_xcb_font_t));
    if (unlikely (font_private == NULL))
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);

    font_private->scaled_font = scaled_font;
    font_private->connection = _cairo_xcb_connection_reference (connection);
    for (i = 0; i < NUM_GLYPHSETS; i++) {
	cairo_xcb_font_glyphset_info_t *glyphset_info = &font_private->glyphset_info[i];
	switch (i) {
	case GLYPHSET_INDEX_ARGB32: glyphset_info->format = CAIRO_FORMAT_ARGB32; break;
	case GLYPHSET_INDEX_A8:     glyphset_info->format = CAIRO_FORMAT_A8;     break;
	case GLYPHSET_INDEX_A1:     glyphset_info->format = CAIRO_FORMAT_A1;     break;
	default:                    ASSERT_NOT_REACHED;                          break;
	}
	glyphset_info->xrender_format = 0;
	glyphset_info->glyphset = XCB_NONE;
	glyphset_info->pending_free_glyphs = NULL;
    }

    scaled_font->surface_private = font_private;
    scaled_font->surface_backend = &_cairo_xcb_surface_backend;

    cairo_list_add (&font_private->link, &connection->fonts);

    return CAIRO_STATUS_SUCCESS;
}

static void
_cairo_xcb_font_destroy (cairo_xcb_font_t *font)
{
    int i;

    for (i = 0; i < NUM_GLYPHSETS; i++) {
	cairo_xcb_font_glyphset_info_t *glyphset_info;

	glyphset_info = &font->glyphset_info[i];

	if (glyphset_info->pending_free_glyphs != NULL)
	    free (glyphset_info->pending_free_glyphs);
    }

    cairo_list_del (&font->link);
    _cairo_xcb_connection_destroy (font->connection);

    free (font);
}

void
_cairo_xcb_font_finish (cairo_xcb_font_t *font)
{
    cairo_scaled_font_t	*scaled_font;

    scaled_font = font->scaled_font;

    CAIRO_MUTEX_LOCK (scaled_font->mutex);
    scaled_font->surface_private = NULL;
    _cairo_scaled_font_reset_cache (scaled_font);
    CAIRO_MUTEX_UNLOCK (scaled_font->mutex);

    _cairo_xcb_font_destroy (font);
}

void
_cairo_xcb_surface_scaled_font_fini (cairo_scaled_font_t *scaled_font)
{
    cairo_xcb_font_t *font_private;
    cairo_xcb_connection_t *connection;
    cairo_bool_t have_connection;
    cairo_status_t status;
    int i;

    font_private = scaled_font->surface_private;
    if (font_private == NULL)
	return;

    connection = font_private->connection;

    status = _cairo_xcb_connection_acquire (connection);
    have_connection = status == CAIRO_STATUS_SUCCESS;
    if (likely (have_connection))
	status = _cairo_xcb_connection_take_socket (connection);

    for (i = 0; i < NUM_GLYPHSETS; i++) {
	cairo_xcb_font_glyphset_info_t *glyphset_info;

	glyphset_info = &font_private->glyphset_info[i];
	if (glyphset_info->glyphset && status == CAIRO_STATUS_SUCCESS) {
	    _cairo_xcb_connection_render_free_glyph_set (connection,
							 glyphset_info->glyphset);
	}
    }

    if (have_connection)
	_cairo_xcb_connection_release (connection);


    _cairo_xcb_font_destroy (font_private);
}

static void
_cairo_xcb_render_free_glyphs (cairo_xcb_connection_t *connection,
			       cairo_xcb_font_glyphset_free_glyphs_t *to_free)
{
    _cairo_xcb_connection_render_free_glyphs (connection,
					      to_free->glyphset,
					      to_free->glyph_count,
					      to_free->glyph_indices);
}

void
_cairo_xcb_surface_scaled_glyph_fini (cairo_scaled_glyph_t *scaled_glyph,
				      cairo_scaled_font_t  *scaled_font)
{
    cairo_xcb_font_t *font_private;
    cairo_xcb_font_glyphset_info_t *glyphset_info;

    if (scaled_font->finished)
	return;

    font_private = scaled_font->surface_private;
    glyphset_info = _cairo_xcb_scaled_glyph_get_glyphset_info (scaled_glyph);
    if (font_private != NULL && glyphset_info != NULL) {
	cairo_xcb_font_glyphset_free_glyphs_t *to_free;

	to_free = glyphset_info->pending_free_glyphs;
	if (to_free != NULL &&
	    to_free->glyph_count == ARRAY_LENGTH (to_free->glyph_indices))
	{
	    _cairo_xcb_render_free_glyphs (font_private->connection, to_free);
	    to_free = glyphset_info->pending_free_glyphs = NULL;
	}

	if (to_free == NULL) {
	    to_free = malloc (sizeof (cairo_xcb_font_glyphset_free_glyphs_t));
	    if (unlikely (to_free == NULL)) {
		_cairo_error_throw (CAIRO_STATUS_NO_MEMORY);
		return; /* XXX cannot propagate failure */
	    }

	    to_free->glyphset = glyphset_info->glyphset;
	    to_free->glyph_count = 0;
	    glyphset_info->pending_free_glyphs = to_free;
	}

	to_free->glyph_indices[to_free->glyph_count++] =
	    _cairo_scaled_glyph_index (scaled_glyph);
    }
}

static cairo_bool_t
_native_byte_order_lsb (void)
{
    int	x = 1;

    return *((char *) &x) == 1;
}

static int
_cairo_xcb_get_glyphset_index_for_format (cairo_format_t format)
{
    if (format == CAIRO_FORMAT_A8)
        return GLYPHSET_INDEX_A8;
    if (format == CAIRO_FORMAT_A1)
        return GLYPHSET_INDEX_A1;

    assert (format == CAIRO_FORMAT_ARGB32);
    return GLYPHSET_INDEX_ARGB32;
}

static cairo_xcb_font_glyphset_info_t *
_cairo_xcb_scaled_font_get_glyphset_info_for_format (cairo_scaled_font_t *scaled_font,
						     cairo_format_t       format)
{
    cairo_xcb_font_t *font_private;
    cairo_xcb_font_glyphset_info_t *glyphset_info;
    int glyphset_index;

    glyphset_index = _cairo_xcb_get_glyphset_index_for_format (format);
    font_private = scaled_font->surface_private;
    glyphset_info = &font_private->glyphset_info[glyphset_index];
    if (glyphset_info->glyphset == XCB_NONE) {
	cairo_xcb_connection_t *connection = font_private->connection;

	glyphset_info->glyphset = _cairo_xcb_connection_get_xid (font_private->connection);
	glyphset_info->xrender_format =
	    connection->standard_formats[glyphset_info->format];

	_cairo_xcb_connection_render_create_glyph_set (font_private->connection,
						       glyphset_info->glyphset,
						       glyphset_info->xrender_format);
    }

    return glyphset_info;
}

static cairo_bool_t
_cairo_xcb_glyphset_info_has_pending_free_glyph (
				cairo_xcb_font_glyphset_info_t *glyphset_info,
				unsigned long glyph_index)
{
    if (glyphset_info->pending_free_glyphs != NULL) {
	cairo_xcb_font_glyphset_free_glyphs_t *to_free;
	int i;

	to_free = glyphset_info->pending_free_glyphs;
	for (i = 0; i < to_free->glyph_count; i++) {
	    if (to_free->glyph_indices[i] == glyph_index) {
		to_free->glyph_count--;
		memmove (&to_free->glyph_indices[i],
			 &to_free->glyph_indices[i+1],
			 (to_free->glyph_count - i) * sizeof (to_free->glyph_indices[0]));
		return TRUE;
	    }
	}
    }

    return FALSE;
}

static cairo_xcb_font_glyphset_info_t *
_cairo_xcb_scaled_font_get_glyphset_info_for_pending_free_glyph (
					       cairo_scaled_font_t *scaled_font,
					       unsigned long glyph_index,
					       cairo_image_surface_t *surface)
{
    cairo_xcb_font_t *font_private;
    int i;

    font_private = scaled_font->surface_private;
    if (font_private == NULL)
	return NULL;

    if (surface != NULL) {
        i = _cairo_xcb_get_glyphset_index_for_format (surface->format);

	if (_cairo_xcb_glyphset_info_has_pending_free_glyph (
						&font_private->glyphset_info[i],
						glyph_index))
	{
	    return &font_private->glyphset_info[i];
	}
    } else {
	for (i = 0; i < NUM_GLYPHSETS; i++) {
	    if (_cairo_xcb_glyphset_info_has_pending_free_glyph (
						&font_private->glyphset_info[i],
						glyph_index))
	    {
		return &font_private->glyphset_info[i];
	    }
	}
    }

    return NULL;
}
static cairo_status_t
_cairo_xcb_surface_add_glyph (cairo_xcb_connection_t *connection,
			       cairo_scaled_font_t   *scaled_font,
			       cairo_scaled_glyph_t **scaled_glyph_out)
{
    xcb_render_glyphinfo_t glyph_info;
    uint32_t glyph_index;
    uint8_t *data;
    cairo_status_t status = CAIRO_STATUS_SUCCESS;
    cairo_scaled_glyph_t *scaled_glyph = *scaled_glyph_out;
    cairo_image_surface_t *glyph_surface = scaled_glyph->surface;
    cairo_bool_t already_had_glyph_surface;
    cairo_xcb_font_glyphset_info_t *glyphset_info;

    glyph_index = _cairo_scaled_glyph_index (scaled_glyph);

    /* check to see if we have a pending XRenderFreeGlyph for this glyph */
    glyphset_info = _cairo_xcb_scaled_font_get_glyphset_info_for_pending_free_glyph (scaled_font, glyph_index, glyph_surface);
    if (glyphset_info != NULL) {
	_cairo_xcb_scaled_glyph_set_glyphset_info (scaled_glyph, glyphset_info);
	return CAIRO_STATUS_SUCCESS;
    }

    if (glyph_surface == NULL) {
	status = _cairo_scaled_glyph_lookup (scaled_font,
					     glyph_index,
					     CAIRO_SCALED_GLYPH_INFO_METRICS |
					     CAIRO_SCALED_GLYPH_INFO_SURFACE,
					     scaled_glyph_out);
	if (unlikely (status))
	    return status;

	scaled_glyph = *scaled_glyph_out;
	glyph_surface = scaled_glyph->surface;
	already_had_glyph_surface = FALSE;
    } else {
	already_had_glyph_surface = TRUE;
    }

    if (scaled_font->surface_private == NULL) {
	status = _cairo_xcb_surface_font_init (connection, scaled_font);
	if (unlikely (status))
	    return status;
    }

    glyphset_info = _cairo_xcb_scaled_font_get_glyphset_info_for_format (scaled_font,
									 glyph_surface->format);

    /* If the glyph surface has zero height or width, we create
     * a clear 1x1 surface, to avoid various X server bugs.
     */
    if (glyph_surface->width == 0 || glyph_surface->height == 0) {
	cairo_surface_t *tmp_surface;

	tmp_surface = cairo_image_surface_create (glyphset_info->format, 1, 1);
	status = tmp_surface->status;
	if (unlikely (status))
	    goto BAIL;

	tmp_surface->device_transform = glyph_surface->base.device_transform;
	tmp_surface->device_transform_inverse = glyph_surface->base.device_transform_inverse;

	glyph_surface = (cairo_image_surface_t *) tmp_surface;
    }

    /* If the glyph format does not match the font format, then we
     * create a temporary surface for the glyph image with the font's
     * format.
     */
    if (glyph_surface->format != glyphset_info->format) {
	glyph_surface = _cairo_image_surface_coerce_to_format (glyph_surface,
						               glyphset_info->format);
	status = glyph_surface->base.status;
	if (unlikely (status))
	    goto BAIL;
    }

    /* XXX: FRAGILE: We're ignore device_transform scaling here. A bug? */
    glyph_info.x = _cairo_lround (glyph_surface->base.device_transform.x0);
    glyph_info.y = _cairo_lround (glyph_surface->base.device_transform.y0);
    glyph_info.width  = glyph_surface->width;
    glyph_info.height = glyph_surface->height;
    glyph_info.x_off = scaled_glyph->x_advance;
    glyph_info.y_off = scaled_glyph->y_advance;

    data = glyph_surface->data;

    /* flip formats around */
    switch (_cairo_xcb_get_glyphset_index_for_format (scaled_glyph->surface->format)) {
    case GLYPHSET_INDEX_A1:
	/* local bitmaps are always stored with bit == byte */
	if (_native_byte_order_lsb() != (connection->root->bitmap_format_bit_order == XCB_IMAGE_ORDER_LSB_FIRST)) {
	    int		    c = glyph_surface->stride * glyph_surface->height;
	    const uint8_t *d;
	    uint8_t *new, *n;

	    new = malloc (c);
	    if (unlikely (new == NULL)) {
		status = _cairo_error (CAIRO_STATUS_NO_MEMORY);
		goto BAIL;
	    }

	    n = new;
	    d = data;
	    do {
		uint8_t b = *d++;
		b = ((b << 1) & 0xaa) | ((b >> 1) & 0x55);
		b = ((b << 2) & 0xcc) | ((b >> 2) & 0x33);
		b = ((b << 4) & 0xf0) | ((b >> 4) & 0x0f);
		*n++ = b;
	    } while (--c);
	    data = new;
	}
	break;

    case GLYPHSET_INDEX_A8:
	break;

    case GLYPHSET_INDEX_ARGB32:
	if (_native_byte_order_lsb() != (connection->root->image_byte_order == XCB_IMAGE_ORDER_LSB_FIRST)) {
	    unsigned int c = glyph_surface->stride * glyph_surface->height / 4;
	    const uint32_t *d;
	    uint32_t *new, *n;

	    new = malloc (4 * c);
	    if (unlikely (new == NULL)) {
		status = _cairo_error (CAIRO_STATUS_NO_MEMORY);
		goto BAIL;
	    }

	    n = new;
	    d = (uint32_t *) data;
	    do {
		*n++ = bswap_32 (*d);
		d++;
	    } while (--c);
	    data = (uint8_t *) new;
	}
	break;

    default:
	ASSERT_NOT_REACHED;
	break;
    }
    /* XXX assume X server wants pixman padding. Xft assumes this as well */

    _cairo_xcb_connection_render_add_glyphs (connection,
					     glyphset_info->glyphset,
					     1, &glyph_index, &glyph_info,
					     glyph_surface->stride * glyph_surface->height,
					     data);

    if (data != glyph_surface->data)
	free (data);

    _cairo_xcb_scaled_glyph_set_glyphset_info (scaled_glyph, glyphset_info);

 BAIL:
    if (glyph_surface != scaled_glyph->surface)
	cairo_surface_destroy (&glyph_surface->base);

    /* If the scaled glyph didn't already have a surface attached
     * to it, release the created surface now that we have it
     * uploaded to the X server.  If the surface has already been
     * there (e.g. because image backend requested it), leave it in
     * the cache
     */
    if (! already_had_glyph_surface)
	_cairo_scaled_glyph_set_surface (scaled_glyph, scaled_font, NULL);

    return status;
}

typedef void (*cairo_xcb_render_composite_text_func_t)
	      (cairo_xcb_connection_t       *connection,
	       uint8_t                          op,
	       xcb_render_picture_t src,
	       xcb_render_picture_t dst,
	       xcb_render_pictformat_t mask_format,
	       xcb_render_glyphset_t glyphset,
	       int16_t                          src_x,
	       int16_t                          src_y,
	       uint32_t                          len,
	       uint8_t                        *cmd);


static cairo_status_t
_emit_glyphs_chunk (cairo_xcb_surface_t *dst,
		    cairo_operator_t op,
		    cairo_xcb_picture_t *src,
		    /* info for this chunk */
		    cairo_xcb_glyph_t *glyphs,
		    int num_glyphs,
		    int width,
		    int estimated_req_size,
		    cairo_xcb_font_glyphset_info_t *glyphset_info,
		    xcb_render_pictformat_t mask_format)
{
    cairo_xcb_render_composite_text_func_t composite_text_func;
    uint8_t stack_buf[CAIRO_STACK_BUFFER_SIZE];
    uint8_t *buf = stack_buf;
    x_glyph_elt_t *elt = NULL; /* silence compiler */
    uint32_t len;
    int i;

    if (estimated_req_size > ARRAY_LENGTH (stack_buf)) {
	buf = malloc (estimated_req_size);
	if (unlikely (buf == NULL))
	    return _cairo_error (CAIRO_STATUS_NO_MEMORY);
    }

    len = 0;
    for (i = 0; i < num_glyphs; i++) {
      if (_start_new_glyph_elt (i, &glyphs[i])) {
	  if (len & 3)
	      len += 4 - (len & 3);

	  elt = (x_glyph_elt_t *) (buf + len);
	  elt->len = 0;
	  elt->deltax = glyphs[i].i.x;
	  elt->deltay = glyphs[i].i.y;
	  len += sizeof (x_glyph_elt_t);
      }

      switch (width) {
      case 1: *(uint8_t *) (buf + len) = glyphs[i].index; break;
      case 2: *(uint16_t *) (buf + len) = glyphs[i].index; break;
      default:
      case 4: *(uint32_t *) (buf + len) = glyphs[i].index; break;
      }
      len += width;
      elt->len++;
    }
    if (len & 3)
	len += 4 - (len & 3);

    switch (width) {
    case 1:
	composite_text_func = _cairo_xcb_connection_render_composite_glyphs_8;
	break;
    case 2:
	composite_text_func = _cairo_xcb_connection_render_composite_glyphs_16;
	break;
    default:
    case 4:
	composite_text_func = _cairo_xcb_connection_render_composite_glyphs_32;
	break;
    }
    composite_text_func (dst->connection,
			 _render_operator (op),
			 src->picture,
			 dst->picture,
			 mask_format,
			 glyphset_info->glyphset,
			 src->x + glyphs[0].i.x,
			 src->y + glyphs[0].i.y,
			 len, buf);

    if (buf != stack_buf)
      free (buf);

    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_composite_glyphs (void				*closure,
		  cairo_xcb_surface_t		*dst,
		  cairo_operator_t		 op,
		  const cairo_pattern_t		*pattern,
		  int				 dst_x,
		  int				 dst_y,
		  const cairo_rectangle_int_t	*extents,
		  cairo_region_t		*clip_region)
{
    composite_glyphs_info_t *info = closure;
    cairo_scaled_glyph_t *glyph_cache[64];
    cairo_status_t status = CAIRO_STATUS_SUCCESS;
    cairo_fixed_t x = 0, y = 0;
    cairo_xcb_font_glyphset_info_t *glyphset_info = NULL, *this_glyphset_info;
    const unsigned int max_request_size = dst->connection->maximum_request_length - 64;
    cairo_xcb_picture_t *src;

    unsigned long max_index = 0;
    int width = 1;

    unsigned int request_size = 0;
    int i;

    src = _cairo_xcb_picture_for_pattern (dst, pattern, extents);
    if (unlikely (src->base.status))
	return src->base.status;

    memset (glyph_cache, 0, sizeof (glyph_cache));

    for (i = 0; i < info->num_glyphs; i++) {
	cairo_scaled_glyph_t *scaled_glyph;
	unsigned long glyph_index = info->glyphs[i].index;
	int cache_index = glyph_index % ARRAY_LENGTH (glyph_cache);
	int old_width = width;
	int this_x, this_y;

	scaled_glyph = glyph_cache[cache_index];
	if (scaled_glyph == NULL ||
	    _cairo_scaled_glyph_index (scaled_glyph) != glyph_index)
	{
	    status = _cairo_scaled_glyph_lookup (info->font,
						 glyph_index,
						 CAIRO_SCALED_GLYPH_INFO_METRICS,
						 &scaled_glyph);
	    if (unlikely (status)) {
		cairo_surface_destroy (&src->base);
		return status;
	    }

	    /* Send unseen glyphs to the server */
	    if (_cairo_xcb_scaled_glyph_get_glyphset_info (scaled_glyph) == NULL) {
		status = _cairo_xcb_surface_add_glyph (dst->connection,
						       info->font,
						       &scaled_glyph);
		if (unlikely (status)) {
		    cairo_surface_destroy (&src->base);
		    return status;
		}
	    }

	    glyph_cache[cache_index] = scaled_glyph;
	}

	/* Glyph skipping:
	 *
	 * We skip any glyphs that have troublesome coordinates.  We want
	 * to make sure that (glyph2.x - (glyph1.x + glyph1.width)) fits in
	 * a signed 16bit integer, otherwise it will overflow in the render
	 * protocol.
	 * To ensure this, we'll make sure that (glyph2.x - glyph1.x) fits in
	 * a signed 15bit integer.  The trivial option would be to allow
	 * coordinates -8192..8192, but that's kinda dull.  It probably will
	 * take a decade or so to get monitors 8192x4096 or something.  A
	 * negative value of -8192 on the other hand, is absolutely useless.
	 * Note that we do want to allow some negative positions.  The glyph
	 * may start off the screen but part of it make it to the screen.
	 * Anyway, we will allow positions in the range -4096..122887.  That
	 * will buy us a few more years before this stops working.
	 */
	this_x = _cairo_lround (info->glyphs[i].d.x) - dst_x;
	this_y = _cairo_lround (info->glyphs[i].d.y) - dst_y;
	assert (! (((this_x+4096) | (this_y+4096)) & ~0x3fffu));

	this_glyphset_info = _cairo_xcb_scaled_glyph_get_glyphset_info (scaled_glyph);
	if (glyphset_info == NULL)
	    glyphset_info = this_glyphset_info;

	/* Update max glyph index */
	if (glyph_index > max_index) {
	    max_index = glyph_index;
	    if (max_index >= 65536)
		width = 4;
	    else if (max_index >= 256)
		width = 2;
	    if (width != old_width)
		request_size += (width - old_width) * i;
	}

	/* If we will pass the max request size by adding this glyph,
	 * flush current glyphs.  Note that we account for a
	 * possible element being added below.
	 *
	 * Also flush if changing glyphsets, as Xrender limits one mask
	 * format per request, so we can either break up, or use a
	 * wide-enough mask format.  We do the former.  One reason to
	 * prefer the latter is the fact that Xserver ADDs all glyphs
	 * to the mask first, and then composes that to final surface,
	 * though it's not a big deal.
	 */
	if (request_size + width > max_request_size - _cairo_sz_x_glyph_elt_t ||
	    this_glyphset_info != glyphset_info)
	{
	    status = _emit_glyphs_chunk (dst, op, src,
					 info->glyphs, i,
					 old_width, request_size,
					 glyphset_info,
					 info->use_mask ? glyphset_info->xrender_format : 0);
	    if (unlikely (status)) {
		cairo_surface_destroy (&src->base);
		return status;
	    }

	    info->glyphs += i;
	    info->num_glyphs -= i;
	    i = 0;

	    max_index = info->glyphs[0].index;
	    width = max_index < 256 ? 1 : max_index < 65536 ? 2 : 4;

	    request_size = 0;

	    x = y = 0;
	    glyphset_info = this_glyphset_info;
	}

	/* Convert absolute glyph position to relative-to-current-point
	 * position */
	info->glyphs[i].i.x = this_x - x;
	info->glyphs[i].i.y = this_y - y;

	/* Start a new element for the first glyph,
	 * or for any glyph that has unexpected position,
	 * or if current element has too many glyphs.
	 *
	 * These same conditions are mirrored in _emit_glyphs_chunk().
	 */
      if (_start_new_glyph_elt (i, &info->glyphs[i]))
	    request_size += _cairo_sz_x_glyph_elt_t;

	/* adjust current-position */
	x = this_x + scaled_glyph->x_advance;
	y = this_y + scaled_glyph->y_advance;

	request_size += width;
    }

    if (i) {
	status = _emit_glyphs_chunk (dst, op, src,
				     info->glyphs, i,
				     width, request_size,
				     glyphset_info,
				     info->use_mask ? glyphset_info->xrender_format : 0);
    }

    cairo_surface_destroy (&src->base);

    return status;
}

static cairo_bool_t
_surface_owns_font (cairo_xcb_surface_t *dst,
		    cairo_scaled_font_t *scaled_font)
{
    cairo_xcb_font_t *font_private;

    font_private = scaled_font->surface_private;
    if ((scaled_font->surface_backend != NULL &&
	 scaled_font->surface_backend != dst->base.backend) ||
	(font_private != NULL && font_private->connection != dst->connection))
    {
	return FALSE;
    }

    return TRUE;
}

cairo_int_status_t
_cairo_xcb_surface_render_glyphs (cairo_xcb_surface_t	*surface,
				  cairo_operator_t	 op,
				  const cairo_pattern_t	*source,
				  cairo_scaled_font_t	*scaled_font,
				  cairo_glyph_t		*glyphs,
				  int			 num_glyphs,
				  cairo_clip_t		*clip)
{
    cairo_composite_rectangles_t extents;
    cairo_clip_t local_clip;
    cairo_bool_t have_clip = FALSE;
    cairo_status_t status;
    cairo_bool_t overlap;

    if (unlikely (! _operator_is_supported (surface->flags, op)))
	return CAIRO_INT_STATUS_UNSUPPORTED;

    if ((surface->flags & (CAIRO_XCB_RENDER_HAS_COMPOSITE_GLYPHS | CAIRO_XCB_RENDER_HAS_COMPOSITE)) == 0)
	return CAIRO_INT_STATUS_UNSUPPORTED;

    status = _cairo_composite_rectangles_init_for_glyphs (&extents,
							  surface->width,
							  surface->height,
							  op, source,
							  scaled_font,
							  glyphs, num_glyphs,
							  clip, &overlap);
    if (unlikely (status))
	return status;

    if (_cairo_clip_contains_rectangle (clip, &extents.mask))
	clip = NULL;

    if (clip != NULL) {
	clip = _cairo_clip_init_copy (&local_clip, clip);
	if (extents.is_bounded) {
	    cairo_region_t *clip_region = NULL;

	    status = _cairo_clip_rectangle (clip, &extents.bounded);
	    if (unlikely (status)) {
		_cairo_clip_fini (&local_clip);
		return status;
	    }

	    status = _cairo_clip_get_region (clip, &clip_region);
	    if (unlikely (_cairo_status_is_error (status) ||
			  status == CAIRO_INT_STATUS_NOTHING_TO_DO))
	    {
		_cairo_clip_fini (&local_clip);
		return status;
	    }

	    if (clip_region != NULL) {
		cairo_rectangle_int_t rect;
		cairo_bool_t is_empty;

		cairo_region_get_extents (clip_region, &rect);
		is_empty = ! _cairo_rectangle_intersect (&extents.unbounded, &rect);
		if (unlikely (is_empty))
		    return CAIRO_STATUS_SUCCESS;

		is_empty = ! _cairo_rectangle_intersect (&extents.bounded, &rect);
		if (unlikely (is_empty && extents.is_bounded))
		    return CAIRO_STATUS_SUCCESS;

		if (cairo_region_num_rectangles (clip_region) == 1)
		    clip = NULL;
	    }
	}
	have_clip = TRUE;
    }

    status = CAIRO_INT_STATUS_UNSUPPORTED;
    if (surface->flags & CAIRO_XCB_RENDER_HAS_COMPOSITE_GLYPHS) {
	_cairo_scaled_font_freeze_cache (scaled_font);

	if (_surface_owns_font (surface, scaled_font)) {
	    status = _can_composite_glyphs (surface,
					    scaled_font, glyphs, num_glyphs);
	    if (likely (status == CAIRO_STATUS_SUCCESS)) {
		composite_glyphs_info_t info;

		info.font = scaled_font;
		info.glyphs = (cairo_xcb_glyph_t *) glyphs;
		info.num_glyphs = num_glyphs;
		info.use_mask = overlap || clip != NULL || ! extents.is_bounded;

		status = _clip_and_composite (surface, op, source,
					      _composite_glyphs, &info,
					      &extents, clip);
	    }
	}

	_cairo_scaled_font_thaw_cache (scaled_font);
    }

    if (status == CAIRO_INT_STATUS_UNSUPPORTED) {
	assert (surface->flags & CAIRO_XCB_RENDER_HAS_COMPOSITE);
	status =
	    _cairo_xcb_surface_render_glyphs_via_mask (surface, op, source,
						       scaled_font, glyphs, num_glyphs,
						       have_clip ? &local_clip : NULL,
						       &extents);
    }

    if (have_clip)
	_cairo_clip_fini (&local_clip);

    return status;
}
