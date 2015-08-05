/* -*- Mode: c++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 8; -*- */
/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2007 Mozilla Corporation
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
 * The Initial Developer of the Original Code is Mozilla Corporation.
 *
 * Contributor(s):
 *	Vladimir Vukicevic <vladimir@mozilla.com>
 */

#include "cairoint.h"

#include "cairo-skia.h"

#include "cairo-surface-clipper-private.h"

#include <SkBitmap.h>
#include <SkCanvas.h>
#include <SkPaint.h>
#include <SkPath.h>

#include <SkColorShader.h>

#include <SkGradientShader.h>
#include <SkDashPathEffect.h>

#if (CAIRO_FIXED_BITS == 32) && (CAIRO_FIXED_FRAC_BITS == 16) && defined(SK_SCALAR_IS_FIXED)
# define CAIRO_FIXED_TO_SK_SCALAR(x)  (x)
#elif defined(SK_SCALAR_IS_FIXED)
/* This can be done better, but this will do for now */
# define CAIRO_FIXED_TO_SK_SCALAR(x)  SkFloatToScalar(_cairo_fixed_to_double(x))
#else
# define CAIRO_FIXED_TO_SK_SCALAR(x)  SkFloatToScalar(_cairo_fixed_to_double(x))
#endif

#ifndef CAIRO_INT_STATUS_SUCCESS
# define CAIRO_INT_STATUS_SUCCESS ((cairo_int_status_t) CAIRO_STATUS_SUCCESS)
#endif

#define CAIRO_MAYBE_UNSUPPORTED CAIRO_INT_STATUS_UNSUPPORTED
//#define CAIRO_MAYBE_UNSUPPORTED _skia_unsupported ()

static cairo_int_status_t _skia_unsupported () {
    printf ("unsupported!\n");
    return CAIRO_INT_STATUS_UNSUPPORTED;
}

typedef struct cairo_skia_surface {
    cairo_surface_t base;

    SkBitmap *bitmap;
    SkCanvas *canvas;

    cairo_surface_clipper_t clipper;

    cairo_image_surface_t *_image_surface; /* wrapper around bitmap */
} cairo_skia_surface_t;

static cairo_skia_surface_t *
_cairo_skia_surface_create_internal (SkBitmap::Config config,
				     bool opaque,
				     unsigned char *data,
				     int width,
				     int height,
				     int stride);

/*
 * conversion methods
 */

/*
 * format conversion
 */
static inline bool
format_to_sk_config (cairo_format_t format,
		     SkBitmap::Config& config,
		     bool& opaque)
{
    opaque = false;

    switch (format) {
    case CAIRO_FORMAT_ARGB32:
	config = SkBitmap::kARGB_8888_Config;
	break;
    case CAIRO_FORMAT_RGB24:
	config = SkBitmap::kARGB_8888_Config;
	opaque = true;
	break;
    case CAIRO_FORMAT_A8:
	config = SkBitmap::kA8_Config;
	break;
    case CAIRO_FORMAT_A1:
	config = SkBitmap::kA1_Config;
	break;
    default:
	return false;
    }

    return true;
}

static inline cairo_format_t
sk_config_to_format (SkBitmap::Config config,
		     bool opaque)
{
    switch (config) {
    case SkBitmap::kARGB_8888_Config:
	if (opaque)
	    return CAIRO_FORMAT_RGB24;
	return CAIRO_FORMAT_ARGB32;

    case SkBitmap::kA8_Config:
	return CAIRO_FORMAT_A8;

    case SkBitmap::kA1_Config:
	return CAIRO_FORMAT_A1;

    case SkBitmap::kNo_Config:
    case SkBitmap::kIndex8_Config:
    case SkBitmap::kRLE_Index8_Config:
    case SkBitmap::kRGB_565_Config:
    case SkBitmap::kARGB_4444_Config:
    case SkBitmap::kConfigCount:
    default:
	return (cairo_format_t) -1;
    }
}

/*
 * image surface wrapping
 */
static inline bool
surface_to_sk_bitmap (cairo_surface_t *surface, SkBitmap& bitmap)
{
    cairo_image_surface_t *img = (cairo_image_surface_t *) surface;
    SkBitmap::Config config;
    bool opaque;

    if (unlikely (! format_to_sk_config (img->format, config, opaque)))
	return false;

    bitmap.reset ();
    bitmap.setConfig (config, img->width, img->height, img->stride);
    bitmap.setIsOpaque (opaque);
    bitmap.setPixels (img->data);

    return true;
}

/*
 * operator conversion
 */

static inline SkXfermode::Mode
operator_to_sk (cairo_operator_t op)
{
    static const SkXfermode::Mode modeMap[] = {
	SkXfermode::kClear_Mode,

	SkXfermode::kSrc_Mode,
	SkXfermode::kSrcOver_Mode,
	SkXfermode::kSrcIn_Mode,
	SkXfermode::kSrcOut_Mode,
	SkXfermode::kSrcATop_Mode,

	SkXfermode::kDst_Mode,
	SkXfermode::kDstOver_Mode,
	SkXfermode::kDstIn_Mode,
	SkXfermode::kDstOut_Mode,
	SkXfermode::kDstATop_Mode,

	SkXfermode::kXor_Mode,
	SkXfermode::kPlus_Mode, // XXX Add?
	SkXfermode::kPlus_Mode, // XXX SATURATE

	SkXfermode::kPlus_Mode,
	SkXfermode::kMultiply_Mode,
	SkXfermode::kScreen_Mode,
	SkXfermode::kOverlay_Mode,
	SkXfermode::kDarken_Mode,
	SkXfermode::kLighten_Mode,
	SkXfermode::kColorDodge_Mode,
	SkXfermode::kColorBurn_Mode,
	SkXfermode::kHardLight_Mode,
	SkXfermode::kSoftLight_Mode,
	SkXfermode::kDifference_Mode,
	SkXfermode::kExclusion_Mode,

	SkXfermode::kSrcOver_Mode, // XXX: CAIRO_OPERATOR_HSL_HUE
	SkXfermode::kSrcOver_Mode, // XXX: CAIRO_OPERATOR_HSL_SATURATION,
	SkXfermode::kSrcOver_Mode, // XXX: CAIRO_OPERATOR_HSL_COLOR,
	SkXfermode::kSrcOver_Mode, // XXX: CAIRO_OPERATOR_HSL_LUMINOSITY
    };

    return modeMap[op];
}

/*
 * tiling mode conversion
 */
static SkShader::TileMode
extend_to_sk (cairo_extend_t extend)
{
    static const SkShader::TileMode modeMap[] = {
	SkShader::kClamp_TileMode,  // NONE behaves like PAD, because noone wants NONE
	SkShader::kRepeat_TileMode,
	SkShader::kMirror_TileMode,
	SkShader::kClamp_TileMode
    };

    return modeMap[extend];
}

/*
 * color conversion
 */
static inline SkColor
color_to_sk (const cairo_color_t& c)
{
    /* Need unpremultiplied 1-byte values */
    return SkColorSetARGB ((U8CPU) (c.alpha * 255),
			   (U8CPU) (c.red * 255),
			   (U8CPU) (c.green * 255),
			   (U8CPU) (c.blue * 255));
}

/*
 * matrix conversion
 */
static inline SkMatrix
matrix_to_sk (const cairo_matrix_t& mat)
{
    SkMatrix skm;

    skm.reset ();
    skm.set (SkMatrix::kMScaleX, SkFloatToScalar (mat.xx));
    skm.set (SkMatrix::kMSkewX,  SkFloatToScalar (mat.xy));
    skm.set (SkMatrix::kMTransX, SkFloatToScalar (mat.x0));
    skm.set (SkMatrix::kMSkewY,  SkFloatToScalar (mat.yx));
    skm.set (SkMatrix::kMScaleY, SkFloatToScalar (mat.yy));
    skm.set (SkMatrix::kMTransY, SkFloatToScalar (mat.y0));

    /*
    skm[6] = SkFloatToScalar (0.0);
    skm[7] = SkFloatToScalar (0.0);
    skm[8] = SkFloatToScalar (1.0); -- this isn't right, it wants a magic value in there that it'll set itself.  It wants Sk_Fract1 (2.30), not Sk_Scalar1
    */

    return skm;
}

static inline SkMatrix
matrix_inverse_to_sk (const cairo_matrix_t& mat)
{
    cairo_matrix_t inv = mat;
    cairo_status_t status = cairo_matrix_invert (&inv);
    assert (status == CAIRO_STATUS_SUCCESS);
    return matrix_to_sk (inv);
}

/*
 * pattern conversion
 */
static inline cairo_surface_t *
surface_from_pattern (const cairo_pattern_t *pattern)
{
    return (reinterpret_cast <const cairo_surface_pattern_t *> (pattern))->surface;
}

static SkShader*
pattern_to_sk_shader (cairo_skia_surface_t *dst, const cairo_pattern_t *pattern,
		      cairo_image_surface_t **image, void **image_extra)
{
    SkShader *shader = NULL;

    if (pattern->type == CAIRO_PATTERN_TYPE_SOLID) {
	cairo_solid_pattern_t *solid = (cairo_solid_pattern_t *) pattern;
	return new SkColorShader (color_to_sk (solid->color));
    } else if (pattern->type == CAIRO_PATTERN_TYPE_SURFACE) {
	cairo_surface_t *surface = surface_from_pattern (pattern);

	if (surface->type == CAIRO_SURFACE_TYPE_SKIA) {
	    cairo_skia_surface_t *esurf = (cairo_skia_surface_t *) surface;

	    shader = SkShader::CreateBitmapShader (*esurf->bitmap,
						   extend_to_sk (pattern->extend),
						   extend_to_sk (pattern->extend));
	} else {
	    SkBitmap bitmap;

	    if (! _cairo_surface_is_image (surface)) {
		cairo_status_t status;

		status = _cairo_surface_acquire_source_image (surface,
							      image, image_extra);
		if (status)
		    return NULL;

		surface = &(*image)->base;
	    }


	    if (unlikely (! surface_to_sk_bitmap (surface, bitmap)))
		return NULL;

	    shader = SkShader::CreateBitmapShader (bitmap,
						   extend_to_sk (pattern->extend),
						   extend_to_sk (pattern->extend));
	}
    } else if (pattern->type == CAIRO_PATTERN_TYPE_LINEAR
	       /* || pattern->type == CAIRO_PATTERN_TYPE_RADIAL */)
    {
	cairo_gradient_pattern_t *gradient = (cairo_gradient_pattern_t *) pattern;
	SkColor colors_stack[10];
	SkScalar pos_stack[10];
	SkColor *colors = colors_stack;
	SkScalar *pos = pos_stack;

	if (gradient->n_stops > 10) {
	    colors = new SkColor[gradient->n_stops];
	    pos = new SkScalar[gradient->n_stops];
	}

	for (unsigned int i = 0; i < gradient->n_stops; i++) {
	    pos[i] = CAIRO_FIXED_TO_SK_SCALAR (gradient->stops[i].offset);
	    colors[i] = color_to_sk (gradient->stops[i].color);
	}

	if (pattern->type == CAIRO_PATTERN_TYPE_LINEAR) {
	    cairo_linear_pattern_t *linear = (cairo_linear_pattern_t *) gradient;
	    SkPoint points[2];

	    points[0].set (SkFloatToScalar (linear->pd1.x),
			   SkFloatToScalar (linear->pd1.y));
	    points[1].set (SkFloatToScalar (linear->pd2.x),
			   SkFloatToScalar (linear->pd2.y));
	    shader = SkGradientShader::CreateLinear (points, colors, pos, gradient->n_stops,
						     extend_to_sk (pattern->extend));
	} else {
	    // XXX todo -- implement real radial shaders in Skia
	}

	if (gradient->n_stops > 10) {
	    delete [] colors;
	    delete [] pos;
	}
    }

    if (shader && ! _cairo_matrix_is_identity (&pattern->matrix))
	shader->setLocalMatrix (matrix_inverse_to_sk (pattern->matrix));

    return shader;
}

static inline bool
pattern_filter_to_sk (const cairo_pattern_t *pattern)
{
    switch (pattern->filter) {
    case CAIRO_FILTER_GOOD:
    case CAIRO_FILTER_BEST:
    case CAIRO_FILTER_BILINEAR:
    case CAIRO_FILTER_GAUSSIAN:
	return true;
    default:
    case CAIRO_FILTER_FAST:
    case CAIRO_FILTER_NEAREST:
	return false;
    }
}

static inline bool
pattern_to_sk_color (const cairo_pattern_t *pattern, SkColor& color)
{
    if (pattern->type != CAIRO_PATTERN_TYPE_SOLID)
	return false;

    color = color_to_sk (((cairo_solid_pattern_t *) pattern)->color);
    return true;
}

/*
 * path conversion
 */

struct cpc {
    SkPath skPath;
    cairo_matrix_t *matrix;
};

static cairo_status_t
cpc_move_to (void *closure, const cairo_point_t *point)
{
    struct cpc *cpc = static_cast <struct cpc *> (closure);
    if (cpc->matrix) {
	double x = _cairo_fixed_to_double (point->x);
	double y = _cairo_fixed_to_double (point->y);
	cairo_matrix_transform_point (cpc->matrix, &x, &y);
	cpc->skPath.moveTo (SkFloatToScalar (x), SkFloatToScalar (y));
    } else {
	cpc->skPath.moveTo (CAIRO_FIXED_TO_SK_SCALAR (point->x),
			    CAIRO_FIXED_TO_SK_SCALAR (point->y));
    }
    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
cpc_line_to (void *closure, const cairo_point_t *point)
{
    struct cpc *cpc = static_cast <struct cpc *> (closure);
    if (cpc->matrix) {
	double x = _cairo_fixed_to_double (point->x);
	double y = _cairo_fixed_to_double (point->y);
	cairo_matrix_transform_point (cpc->matrix, &x, &y);
	cpc->skPath.lineTo (SkFloatToScalar (x), SkFloatToScalar (y));
    } else {
	cpc->skPath.lineTo (CAIRO_FIXED_TO_SK_SCALAR (point->x),
			    CAIRO_FIXED_TO_SK_SCALAR (point->y));
    }
    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
cpc_curve_to (void *closure,
	      const cairo_point_t *p0,
	      const cairo_point_t *p1,
	      const cairo_point_t *p2)
{
    struct cpc *cpc = static_cast <struct cpc *> (closure);
    if (cpc->matrix) {
	double x0 = _cairo_fixed_to_double (p0->x);
	double y0 = _cairo_fixed_to_double (p0->y);
	double x1 = _cairo_fixed_to_double (p1->x);
	double y1 = _cairo_fixed_to_double (p1->y);
	double x2 = _cairo_fixed_to_double (p2->x);
	double y2 = _cairo_fixed_to_double (p2->y);
	cairo_matrix_transform_point (cpc->matrix, &x0, &y0);
	cairo_matrix_transform_point (cpc->matrix, &x1, &y1);
	cairo_matrix_transform_point (cpc->matrix, &x2, &y2);

	cpc->skPath.cubicTo (SkFloatToScalar (x0),
			     SkFloatToScalar (y0),
			     SkFloatToScalar (x1),
			     SkFloatToScalar (y1),
			     SkFloatToScalar (x2),
			     SkFloatToScalar (y2));
    } else {
	cpc->skPath.cubicTo (CAIRO_FIXED_TO_SK_SCALAR (p0->x),
			     CAIRO_FIXED_TO_SK_SCALAR (p0->y),
			     CAIRO_FIXED_TO_SK_SCALAR (p1->x),
			     CAIRO_FIXED_TO_SK_SCALAR (p1->y),
			     CAIRO_FIXED_TO_SK_SCALAR (p2->x),
			     CAIRO_FIXED_TO_SK_SCALAR (p2->y));
    }
    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
cpc_close_path (void *closure)
{
    struct cpc *cpc = static_cast <struct cpc *> (closure);
    cpc->skPath.close ();
    return CAIRO_STATUS_SUCCESS;
}

static inline SkPath
path_to_sk (cairo_path_fixed_t *path,
	    cairo_matrix_t *mat = NULL)
{
    struct cpc data;
    cairo_status_t status;

    if (mat && _cairo_matrix_is_identity (mat))
	mat = NULL;
    data.matrix = mat;

    status = _cairo_path_fixed_interpret (path,
					  cpc_move_to,
					  cpc_line_to,
					  cpc_curve_to,
					  cpc_close_path,
					  &data);
    assert (status == CAIRO_STATUS_SUCCESS);

    return data.skPath;
}

static inline SkPath
path_to_sk (cairo_path_fixed_t *path,
	    cairo_fill_rule_t fill_rule,
	    cairo_matrix_t *mat = NULL)
{
    SkPath skPath = path_to_sk (path, mat);

    if (fill_rule == CAIRO_FILL_RULE_EVEN_ODD)
	skPath.setFillType (SkPath::kEvenOdd_FillType);
    else
	skPath.setFillType (SkPath::kWinding_FillType);

    return skPath;
}

/*
 * cairo surface methods
 */

static cairo_surface_t *
_cairo_skia_surface_create_similar (void *asurface,
				    cairo_content_t content,
				    int width,
				    int height)
{
    SkBitmap::Config config;
    bool opaque;

    if (! format_to_sk_config (_cairo_format_from_content (content),
			       config, opaque))
    {
	_skia_unsupported ();
	return NULL;
    }

    return &_cairo_skia_surface_create_internal (config, opaque,
						 NULL,
						 width, height,
						 0)->base;
}

static cairo_status_t
_cairo_skia_surface_finish (void *asurface)
{
    cairo_skia_surface_t *surface = (cairo_skia_surface_t *) asurface;

    _cairo_surface_clipper_reset (&surface->clipper);
    cairo_surface_destroy (&surface->_image_surface->base);

    delete surface->canvas;
    delete surface->bitmap;

    return CAIRO_STATUS_SUCCESS;
}

static cairo_image_surface_t *
_get_image_surface (cairo_skia_surface_t *surface)
{
    if (! surface->_image_surface) {
	SkBitmap *bitmap = surface->bitmap;
	surface->_image_surface = (cairo_image_surface_t *)
	    cairo_image_surface_create_for_data ((unsigned char *) bitmap->getPixels (),
						 sk_config_to_format (bitmap->config (),
								      bitmap->isOpaque ()),
						 bitmap->width (),
						 bitmap->height (),
						 bitmap->rowBytes ());
    }

    return surface->_image_surface;
}

static cairo_status_t
_cairo_skia_surface_acquire_source_image (void *asurface,
					  cairo_image_surface_t **image_out,
					  void **image_extra)
{
    cairo_skia_surface_t *surface = (cairo_skia_surface_t *) asurface;
    cairo_image_surface_t *image = _get_image_surface (surface);

    if (unlikely (image->base.status))
	return image->base.status;

    surface->bitmap->lockPixels ();

    *image_out = image;
    *image_extra = NULL;
    return CAIRO_STATUS_SUCCESS;
}

static void
_cairo_skia_surface_release_source_image (void *asurface,
					  cairo_image_surface_t *image,
					  void *image_extra)
{
    cairo_skia_surface_t *surface = (cairo_skia_surface_t *) asurface;

    surface->bitmap->unlockPixels ();
}

static cairo_status_t
_cairo_skia_surface_acquire_dest_image (void *asurface,
					cairo_rectangle_int_t *interest_rect,
					cairo_image_surface_t **image_out,
					cairo_rectangle_int_t *image_rect,
					void **image_extra)
{
    cairo_skia_surface_t *surface = (cairo_skia_surface_t *) asurface;
    cairo_image_surface_t *image = _get_image_surface (surface);

    if (unlikely (image->base.status))
	return image->base.status;

    image_rect->x = 0;
    image_rect->y = 0;
    image_rect->width  = image->width;
    image_rect->height = image->height;

    surface->bitmap->lockPixels ();

    *image_out = image;
    *image_extra = NULL;
    return CAIRO_STATUS_SUCCESS;
}

static void
_cairo_skia_surface_release_dest_image (void *asurface,
					cairo_rectangle_int_t *interest_rect,
					cairo_image_surface_t *image,
					cairo_rectangle_int_t *image_rect,
					void *image_extra)
{
    cairo_skia_surface_t *surface = (cairo_skia_surface_t *) asurface;

    surface->bitmap->notifyPixelsChanged ();
    surface->bitmap->unlockPixels ();
}

#if 0
static cairo_status_t
_cairo_skia_surface_clone_similar (void *asurface,
				   cairo_surface_t *src,
				   cairo_content_t content,
				   int src_x,
				   int src_y,
				   int width,
				   int height,
				   int *clone_offset_x,
				   int *clone_offset_y,
				   cairo_surface_t **clone_out)
{
    if (src->type == CAIRO_SURFACE_TYPE_SKIA || _cairo_surface_is_image (src)) {
	*clone_offset_x = 0;
	*clone_offset_y = 0;
	*clone_out = cairo_surface_reference (src);
	return CAIRO_STATUS_SUCCESS;
    }

    return (cairo_status_t) CAIRO_INT_STATUS_UNSUPPORTED;
}
#endif

static cairo_status_t
_cairo_skia_surface_clipper_intersect_clip_path (cairo_surface_clipper_t *clipper,
						 cairo_path_fixed_t *path,
						 cairo_fill_rule_t fill_rule,
						 double tolerance,
						 cairo_antialias_t antialias)
{
    cairo_skia_surface_t *surface = cairo_container_of (clipper,
							cairo_skia_surface_t,
							clipper);

    if (path == NULL) {
	/* XXX TODO: teach Skia how to reset the clip path */
	surface->canvas->restore ();
	surface->canvas->save ();
    } else {
	surface->canvas->clipPath (path_to_sk (path, fill_rule));
    }

    return CAIRO_STATUS_SUCCESS;
}

static cairo_bool_t
_cairo_skia_surface_get_extents (void *asurface,
				 cairo_rectangle_int_t *extents)
{
    cairo_skia_surface_t *surface = (cairo_skia_surface_t *) asurface;

    extents->x = 0;
    extents->y = 0;
    extents->width  = surface->bitmap->width ();
    extents->height = surface->bitmap->height ();

    return TRUE;
}

/*
 * Core drawing operations
 */

static SkBitmap *
pattern_to_sk_bitmap (cairo_skia_surface_t *dst,
		      const cairo_pattern_t *pattern,
		      SkMatrix *matrix,
		      cairo_image_surface_t **image,
		      void **image_extra)
{
    if (pattern->type != CAIRO_PATTERN_TYPE_SURFACE)
	return NULL;

    if (pattern->extend != CAIRO_EXTEND_NONE)
	return NULL;

    cairo_surface_t *surface = surface_from_pattern (pattern);
    SkBitmap *bitmap;

    if (surface->type == CAIRO_SURFACE_TYPE_SKIA) {
	bitmap = new SkBitmap (*((cairo_skia_surface_t *) surface)->bitmap);
    } else {
	if (surface->type != CAIRO_SURFACE_TYPE_IMAGE) {
	    cairo_status_t status;

	    status = _cairo_surface_acquire_source_image (surface,
							  image, image_extra);
	    if (unlikely (status))
		return NULL;

	    surface = &(*image)->base;
	}

	bitmap = new SkBitmap;
	if (unlikely (! surface_to_sk_bitmap (surface, *bitmap)))
	    return NULL;
    }

    *matrix = matrix_inverse_to_sk (pattern->matrix);
    return bitmap;
}

static cairo_int_status_t
_cairo_skia_surface_paint (void *asurface,
			   cairo_operator_t op,
			   const cairo_pattern_t *source,
			   cairo_clip_t *clip)
{
    cairo_skia_surface_t *surface = (cairo_skia_surface_t *) asurface;
    cairo_image_surface_t *image = NULL;
    cairo_status_t status;
    void *image_extra;
    SkColor color;

    status = _cairo_surface_clipper_set_clip (&surface->clipper, clip);
    if (unlikely (status))
	return (cairo_int_status_t) status;

    if (pattern_to_sk_color (source, color)) {
	surface->canvas->drawColor (color, operator_to_sk (op));
	return CAIRO_INT_STATUS_SUCCESS;
    }

    SkMatrix bitmapMatrix;
    SkBitmap *bitmap = pattern_to_sk_bitmap (surface, source, &bitmapMatrix,
					     &image, &image_extra);
    SkShader *shader = NULL;
    if (!bitmap)
	shader = pattern_to_sk_shader (surface, source, &image, &image_extra);

    if (!bitmap && !shader)
	return CAIRO_MAYBE_UNSUPPORTED;

    SkPaint paint;
    paint.setFilterBitmap (pattern_filter_to_sk (source));
    paint.setXfermodeMode (operator_to_sk (op));

    if (shader) {
	paint.setShader (shader);
	surface->canvas->drawPaint (paint);
    } else {
	surface->canvas->drawBitmapMatrix (*bitmap, bitmapMatrix, &paint);
    }

    if (bitmap)
	delete bitmap;
    if (shader)
	shader->unref ();

    if (image != NULL) {
	_cairo_surface_release_source_image (&surface->base,
					     image, image_extra);
    }

    return CAIRO_INT_STATUS_SUCCESS;
}

static cairo_int_status_t
_cairo_skia_surface_stroke (void *asurface,
			    cairo_operator_t op,
			    const cairo_pattern_t *source,
			    cairo_path_fixed_t *path,
			    cairo_stroke_style_t *style,
			    cairo_matrix_t *ctm,
			    cairo_matrix_t *ctm_inverse,
			    double tolerance,
			    cairo_antialias_t antialias,
			    cairo_clip_t *clip)
{
    cairo_skia_surface_t *surface = (cairo_skia_surface_t *) asurface;
    cairo_image_surface_t *image = NULL;
    cairo_status_t status;
    void *image_extra;

    status = _cairo_surface_clipper_set_clip (&surface->clipper, clip);
    if (unlikely (status))
	return (cairo_int_status_t) status;

    SkPaint paint;
    paint.setStyle (SkPaint::kStroke_Style);

    SkColor color;
    if (pattern_to_sk_color (source, color)) {
	paint.setColor (color);
    } else {
	SkShader *shader = pattern_to_sk_shader (surface,
						 source, &image, &image_extra);
	if (shader == NULL)
	    return CAIRO_MAYBE_UNSUPPORTED;

	paint.setShader (shader);
	shader->unref ();

	paint.setFilterBitmap (pattern_filter_to_sk (source));
    }

    paint.setXfermodeMode (operator_to_sk (op));
    paint.setAntiAlias (antialias != CAIRO_ANTIALIAS_NONE);

    /* Convert the various stroke rendering bits */
    paint.setStrokeWidth (SkFloatToScalar (style->line_width));
    paint.setStrokeMiter (SkFloatToScalar (style->miter_limit));

    static const SkPaint::Cap capMap[] = {
	SkPaint::kButt_Cap,
	SkPaint::kRound_Cap,
	SkPaint::kSquare_Cap
    };
    paint.setStrokeCap (capMap[style->line_cap]);

    static const SkPaint::Join joinMap[] = {
	SkPaint::kMiter_Join,
	SkPaint::kRound_Join,
	SkPaint::kBevel_Join
    };
    paint.setStrokeJoin (joinMap[style->line_join]);

    /* If we have a dash pattern, we need to
     * create a SkDashPathEffect and set it on the Paint.
     */
    if (style->dash != NULL) {
	SkScalar intervals_static[20];
	SkScalar *intervals = intervals_static;

	int loop = 0;
	unsigned int dash_count = style->num_dashes;
	if ((dash_count & 1) != 0) {
	    loop = 1;
	    dash_count <<= 1;
	}

	if (dash_count > 20)
	    intervals = new SkScalar[dash_count];

	unsigned int i = 0;
	do {
	    for (unsigned int j = 0; i < style->num_dashes; j++)
		intervals[i++] = SkFloatToScalar (style->dash[j]);
	} while (loop--);

	SkDashPathEffect *dash = new SkDashPathEffect (intervals,
						       dash_count,
						       SkFloatToScalar (style->dash_offset));

	paint.setPathEffect (dash);
	dash->unref ();
    }

    surface->canvas->save (SkCanvas::kMatrix_SaveFlag);
    surface->canvas->concat (matrix_to_sk (*ctm));
    surface->canvas->drawPath (path_to_sk (path, ctm_inverse), paint);
    surface->canvas->restore ();

    if (image != NULL) {
	_cairo_surface_release_source_image (&surface->base,
					     image, image_extra);
    }

    return CAIRO_INT_STATUS_SUCCESS;
}

static cairo_int_status_t
_cairo_skia_surface_fill (void *asurface,
			  cairo_operator_t op,
			  const cairo_pattern_t *source,
			  cairo_path_fixed_t *path,
			  cairo_fill_rule_t fill_rule,
			  double tolerance,
			  cairo_antialias_t antialias,
			  cairo_clip_t *clip)
{
    cairo_skia_surface_t *surface = (cairo_skia_surface_t *) asurface;
    cairo_image_surface_t *image = NULL;
    cairo_status_t status;
    void *image_extra;

    status = _cairo_surface_clipper_set_clip (&surface->clipper, clip);
    if (unlikely (status))
	return (cairo_int_status_t) status;


    SkPaint paint;
    paint.setStyle (SkPaint::kFill_Style);

    SkColor color;
    if (pattern_to_sk_color (source, color)) {
	paint.setColor (color);
    } else {
	SkShader *shader = pattern_to_sk_shader (surface,
						 source, &image, &image_extra);
	if (shader == NULL)
	    return CAIRO_MAYBE_UNSUPPORTED;

	paint.setShader (shader);
	shader->unref ();

	paint.setFilterBitmap (pattern_filter_to_sk (source));
    }

    paint.setXfermodeMode (operator_to_sk (op));
    paint.setAntiAlias (antialias != CAIRO_ANTIALIAS_NONE);

    surface->canvas->drawPath (path_to_sk (path, fill_rule), paint);

    if (image != NULL) {
	_cairo_surface_release_source_image (&surface->base,
					     image, image_extra);
    }

    return CAIRO_INT_STATUS_SUCCESS;
}

static const struct _cairo_surface_backend
cairo_skia_surface_backend = {
    CAIRO_SURFACE_TYPE_SKIA,
    _cairo_skia_surface_create_similar,
    _cairo_skia_surface_finish,
    _cairo_skia_surface_acquire_source_image,
    _cairo_skia_surface_release_source_image,
    _cairo_skia_surface_acquire_dest_image,
    _cairo_skia_surface_release_dest_image,

    NULL, // _cairo_skia_surface_clone_similar,
    NULL, /* composite */
    NULL, /* fill_rectangles */
    NULL, /* composite_trapezoids */
    NULL, /* create_span_renderer */
    NULL, /* check_span_renderer */

    NULL, /* copy_page */
    NULL, /* show_page */

    _cairo_skia_surface_get_extents,
    NULL, /* old_show_glyphs */
    NULL, /* get_font_options */
    NULL, /* flush */
    NULL, /* mark_dirty_rectangle */
    NULL, /* scaled_font_fini */
    NULL, /* scaled_glyph_fini */

    _cairo_skia_surface_paint,
    NULL, /* mask? */
    _cairo_skia_surface_stroke,
    _cairo_skia_surface_fill,
    NULL, /* show_glyphs */

    NULL, /* snapshot */
    NULL, /* is_similar */
    NULL, /* reset */
};

/*
 * Surface constructors
 */

static cairo_skia_surface_t *
_cairo_skia_surface_create_internal (SkBitmap::Config config,
				     bool opaque,
				     unsigned char *data,
				     int width,
				     int height,
				     int stride)
{
    cairo_skia_surface_t *surface;
    cairo_format_t format;

    surface = (cairo_skia_surface_t *) malloc (sizeof (cairo_skia_surface_t));
    if (surface == NULL)
	return (cairo_skia_surface_t *) _cairo_surface_create_in_error (_cairo_error (CAIRO_STATUS_NO_MEMORY));

    memset (surface, 0, sizeof (cairo_skia_surface_t));

    format = sk_config_to_format (config, opaque);
    assert (format != -1);

    _cairo_surface_init (&surface->base,
			 &cairo_skia_surface_backend,
			 NULL, /* device */
			 _cairo_content_from_format (format));

    _cairo_surface_clipper_init (&surface->clipper,
				 _cairo_skia_surface_clipper_intersect_clip_path);

    surface->bitmap = new SkBitmap;
    if (data == NULL)
	stride = cairo_format_stride_for_width (format, width);
    surface->bitmap->setConfig (config, width, height, stride);
    surface->bitmap->setIsOpaque (opaque);
    if (data != NULL)
	surface->bitmap->setPixels (data);
    else
	surface->bitmap->allocPixels ();

    surface->canvas = new SkCanvas (*surface->bitmap);
    //surface->canvas->translate (SkIntToScalar (0), SkIntToScalar (height));
    //surface->canvas->scale (SkIntToScalar (1), SkIntToScalar (-1));
    surface->canvas->save ();

    return surface;
}

cairo_surface_t *
cairo_skia_surface_create (cairo_format_t format,
			   int width,
			   int height)
{
    SkBitmap::Config config;
    bool opaque;

    if (! CAIRO_FORMAT_VALID (format) ||
	! format_to_sk_config (format, config, opaque))
    {
	return _cairo_surface_create_in_error (_cairo_error (CAIRO_STATUS_INVALID_FORMAT));
    }

    return &_cairo_skia_surface_create_internal (config, opaque,
						 NULL,
						 width, height, 0)->base;
}

cairo_surface_t *
cairo_skia_surface_create_for_data (unsigned char *data,
				    cairo_format_t format,
				    int width,
				    int height,
				    int stride)
{
    SkBitmap::Config config;
    bool opaque;

    if (! CAIRO_FORMAT_VALID (format) ||
	! format_to_sk_config (format, config, opaque))
    {
	return _cairo_surface_create_in_error (_cairo_error (CAIRO_STATUS_INVALID_FORMAT));
    }

    return &_cairo_skia_surface_create_internal (config, opaque,
						data,
						width, height, stride)->base;
}

unsigned char *
cairo_skia_surface_get_data (cairo_surface_t *surface)
{
    if (surface->type != CAIRO_SURFACE_TYPE_SKIA)
	return NULL;

    cairo_skia_surface_t *esurf = (cairo_skia_surface_t *) surface;
    return (unsigned char *) esurf->bitmap->getPixels ();
}

cairo_format_t
cairo_skia_surface_get_format (cairo_surface_t *surface)
{
    if (surface->type != CAIRO_SURFACE_TYPE_SKIA)
	return (cairo_format_t) -1;

    cairo_skia_surface_t *esurf = (cairo_skia_surface_t *) surface;
    return sk_config_to_format (esurf->bitmap->config (),
				esurf->bitmap->isOpaque ());
}

int
cairo_skia_surface_get_width (cairo_surface_t *surface)
{
    if (surface->type != CAIRO_SURFACE_TYPE_SKIA)
	return 0;

    cairo_skia_surface_t *esurf = (cairo_skia_surface_t *) surface;
    return esurf->bitmap->width ();
}

int
cairo_skia_surface_get_height (cairo_surface_t *surface)
{
    if (surface->type != CAIRO_SURFACE_TYPE_SKIA)
	return 0;

    cairo_skia_surface_t *esurf = (cairo_skia_surface_t *) surface;
    return esurf->bitmap->height ();
}

int
cairo_skia_surface_get_stride (cairo_surface_t *surface)
{
    if (surface->type != CAIRO_SURFACE_TYPE_SKIA)
	return 0;

    cairo_skia_surface_t *esurf = (cairo_skia_surface_t *) surface;
    return esurf->bitmap->rowBytes ();
}

cairo_surface_t *
cairo_skia_surface_get_image (cairo_surface_t *surface)
{
    if (surface->type != CAIRO_SURFACE_TYPE_SKIA)
	return NULL;

    cairo_skia_surface_t *esurf = (cairo_skia_surface_t *) surface;
    return &_get_image_surface (esurf)->base;
}

/***

Todo:

*** Skia:

- mask()

*** Sk:

High:
- antialiased clipping?

Medium:
- implement clip path reset (to avoid restore/save)
- implement complex radial patterns (2 centers and 2 radii)

Low:
- implement EXTEND_NONE

***/
