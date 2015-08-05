/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2010 Intel Corporation
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
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
 * The Initial Developer of the Original Code is Intel Corporation
 *
 * Contributor(s):
 *	Chris Wilson <chris@chris-wilson.co.uk>
 */

/*
 * Implement an X Acceleration Architecture using the cairo-drm
 * backends.
 */

#include "cairoint.h"
#include "cairo-drm-private.h"

#ifdef HAVE_DIX_CONFIG_H
#include <dix-config.h>
#else
#include <xorg-server.h>
#endif

#include "xf86.h"
#include "gcstruct.h"
#include "scrnintstr.h"
#include "pixmapstr.h"
#include "windowstr.h"
#include "picturestr.h"
#include "mi.h"
#include "fb.h"
#ifdef MITSHM
#include <X11/extensions/shm.h>
#endif
#ifdef RENDER
#include "fbpict.h"
#include "glyphstr.h"
#endif

#include "cairo-drm-xr.h"

struct _xr_screen {
    cairo_device_t *device;

    CreateGCProcPtr SavedCreateGC;
    CloseScreenProcPtr SavedCloseScreen;
    GetImageProcPtr SavedGetImage;
    GetSpansProcPtr SavedGetSpans;
    CreatePixmapProcPtr SavedCreatePixmap;
    DestroyPixmapProcPtr SavedDestroyPixmap;
    CopyWindowProcPtr SavedCopyWindow;
    ChangeWindowAttributesProcPtr SavedChangeWindowAttributes;
    BitmapToRegionProcPtr SavedBitmapToRegion;

#ifdef RENDER
    CompositeProcPtr SavedComposite;
    GlyphsProcPtr SavedGlyphs;
    CompositeRectsProcPtr SavedCompositeRects;
    TrapezoidsProcPtr SavedTrapezoids;
    TrianglesProcPtr SavedTriangles;
    TriStripProcPtr SavedTriStrip;
    TriFanProcPtr SavedTriFan;
    AddTrianglesProcPtr SavedAddTriangles;
    AddTrapsProcPtr SavedAddTraps;

    RealizeGlyphProcPtr SavedRealizeGlyph;
    UnrealizeGlyphProcPtr SavedUnrealizeGlyph;
#endif
};

struct xr_access_gc {
    cairo_surface_t *stipple;
    cairo_surface_t *tile;
};

struct xr_access_window {
    cairo_surface_t *background;
    cairo_surface_t *border;
};

static int xr_screen_index;
static int xr_pixmap_index;

static inline xr_screen_t *
xr_get_screen (ScreenPtr screen)
{
    return dixLookupPrivate (&screen->devPrivates, &xr_screen_index);
}

static inline PixmapPtr
xr_drawable_get_pixmap (DrawablePtr drawable)
{
    if (drawable->type == DRAWABLE_WINDOW)
	return drawable->pScreen->GetWindowPixmap ((WindowPtr) drawable);
    else
	return (PixmapPtr) drawable;
}

static inline cairo_drm_surface_t *
xr_pixmap_get_drm_surface (PixmapPtr pixmap)
{
    return dixLookupPrivate (&pixmap->devPrivates, &xr_pixmap_index);
}

static cairo_drm_surface_t *
xr_drawable_get_drm_surface (DrawablePtr drawable)
{
    return xr_pixmap_get_drm_surface (xr_drawable_get_pixmap (drawable));
}

static cairo_format_t
xr_format_for_depth (int depth)
{
    switch (depth) {
    case 1:
	return CAIRO_FORMAT_A1;
    case 8:
	return CAIRO_FORMAT_A8;
    case 16:
	return CAIRO_FORMAT_RGB16_565;
    case 24:
	return CAIRO_FORMAT_RGB24;
    default:
    case 32:
	return CAIRO_FORMAT_ARGB32;
    }
}

static cairo_surface_t *
xr_pixmap_get_surface (PixmapPtr pixmap)
{
    cairo_drm_surface_t *drm;

    drm = xr_pixmap_get_drm_surface (pixmap);
    if (drm != NULL)
	return cairo_surface_reference (&drm->base);

    return cairo_image_surface_create_for_data (pixmap->devPrivate.ptr,
						xr_format_for_depth (pixmap->drawable.depth),
						pixmap->drawable.width,
						pixmap->drawable.height,
						pixmap->devKind);
}

static cairo_surface_t *
xr_drawable_get_surface (DrawablePtr drawable)
{
    return xr_pixmap_get_surface (xr_drawable_get_pixmap (drawable));
}

static cairo_bool_t
xr_prepare_access (DrawablePtr drawable,
		   cairo_surface_t **image)
{
    PixmapPtr pixmap;
    cairo_drm_surface_t *drm;

    *image = NULL;

    pixmap = xr_drawable_get_pixmap (drawable);
    drm = xr_pixmap_get_drm_surface (pixmap);
    if (drm == NULL)
	return TRUE;

    *image = cairo_drm_surface_map_to_image (&drm->base);
    if ((*image)->status)
	return FALSE;

    pixmap->devPrivate.ptr =
	((cairo_image_surface_t *) *image)->data;

    return TRUE;
}

static void
xr_finish_access (DrawablePtr drawable,
		  cairo_surface_t *image)
{
    if (image != NULL) {
	cairo_drm_surface_unmap (&xr_drawable_get_drm_surface (drawable)->base,
				 image);
    }
}

static cairo_bool_t
xr_prepare_access_gc (GCPtr gc,
		      struct xr_access_gc *local)
{
    local->stipple = NULL;
    local->tile = NULL;

    if (gc->stipple) {
	if (! xr_prepare_access (&gc->stipple->drawable, &local->stipple))
	    return FALSE;
    }

    if (gc->fillStyle == FillTiled) {
	if (! xr_prepare_access (&gc->tile.pixmap->drawable,
				  &local->tile))
	{
	    if (local->stipple) {
		xr_finish_access (&gc->stipple->drawable,
				   local->stipple);
	    }

	    return FALSE;
	}
    }

    return TRUE;
}

static void
xr_finish_access_gc (GCPtr gc,
		     struct xr_access_gc *local)
{
    if (local->tile) {
	xr_finish_access(&gc->tile.pixmap->drawable,
			  local->tile);
    }

    if (local->stipple) {
	xr_finish_access(&gc->stipple->drawable,
			  local->stipple);
    }
}

static void
xr_fill_spans (DrawablePtr drawable,
	       GCPtr gc,
	       int nspans,
	       DDXPointPtr ppt,
	       int *pwidth,
	       int fSorted)
{
    cairo_surface_t *image;
    struct xr_access_gc access_gc;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	if (xr_prepare_access_gc (gc, &access_gc)) {
	    fbFillSpans (drawable, gc,
			 nspans, ppt, pwidth,
			 fSorted);
	    xr_finish_access_gc(gc, &access_gc);
	}
	xr_finish_access (drawable, image);
    }
}

static void
xr_set_spans (DrawablePtr drawable,
	      GCPtr gc,
	      char *psrc,
	      DDXPointPtr ppt,
	      int *pwidth,
	      int nspans,
	      int fSorted)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	fbSetSpans (drawable, gc, psrc, ppt, pwidth, nspans, fSorted);
	xr_finish_access (drawable, image);
    }
}

#define XR_PM_IS_SOLID(_pDrawable, _pm) \
	(((_pm) & FbFullMask((_pDrawable)->depth)) == \
	 FbFullMask((_pDrawable)->depth))

static cairo_clip_t *
xr_gc_get_clip (GCPtr gc, int xoff, int yoff)
{
    return NULL;
}

static cairo_bool_t
xr_do_put_image (DrawablePtr drawable,
		 GCPtr gc,
		 int depth,
		 int x, int y,
		 int width, int height,
		 int format,
		 char *bits, int src_stride)
{
    cairo_surface_t *surface;
    cairo_clip_t *clip;
    cairo_surface_t *image;
    cairo_surface_pattern_t pattern;
    cairo_status_t status;
    cairo_path_fixed_t path;
    cairo_fixed_t x1, y1, x2, y2;

    if (format != ZPixmap || drawable->bitsPerPixel < 8)
	return FALSE;

    if (! XR_PM_IS_SOLID (drawable, gc->planemask) || gc->alu != GXcopy)
	return FALSE;

    clip = xr_gc_get_clip (gc, drawable->x, drawable->y);
    x1 = _cairo_fixed_from_int (x + drawable->x);
    y1 = _cairo_fixed_from_int (y + drawable->y);
    x2 = x1 + _cairo_fixed_from_int (width);
    y2 = y1 + _cairo_fixed_from_int (height);
    _cairo_path_fixed_init (&path);
    if (_cairo_path_fixed_move_to (&path, x1, y1) ||
	_cairo_path_fixed_line_to (&path, x2, y1) ||
	_cairo_path_fixed_line_to (&path, x2, y2) ||
	_cairo_path_fixed_line_to (&path, x1, y2) ||
	_cairo_path_fixed_close_path (&path))
    {
	goto err_path;
    }

    image = cairo_image_surface_create_for_data ((uint8_t *) bits,
						 xr_format_for_depth (depth),
						 width, height, src_stride);
    _cairo_pattern_init_for_surface (&pattern, image);
    cairo_surface_destroy (image);
    pattern.base.filter = CAIRO_FILTER_NEAREST;
    cairo_matrix_init_translate (&pattern.base.matrix,
				 -x - drawable->x,
				 -y - drawable->x);

    surface = xr_drawable_get_surface (drawable);
    status = _cairo_surface_fill (surface,
				  CAIRO_OPERATOR_SOURCE,
				  &pattern.base,
				  &path,
				  CAIRO_FILL_RULE_WINDING,
				  CAIRO_ANTIALIAS_DEFAULT,
				  CAIRO_GSTATE_TOLERANCE_DEFAULT,
				  clip);
    cairo_surface_destroy (surface);
    _cairo_pattern_fini (&pattern.base);
err_path:
    _cairo_path_fixed_fini (&path);

    (void) status;
    return TRUE;
}

static void
xr_put_image(DrawablePtr drawable,
	      GCPtr gc, int depth,
	      int x, int y,
	      int w, int h,
	      int leftPad,
	      int format,
	      char *bits)
{
    if (! xr_do_put_image (drawable,
			   gc,
			   depth,
			   x, y, w, h,
			   format,
			   bits,
			   PixmapBytePad (w, drawable->depth)))
    {
	cairo_surface_t *image;

	//ErrorF ("fallback: %s\n", __FUNCTION__);
	if (xr_prepare_access (drawable, &image)) {
	    fbPutImage (drawable, gc, depth,
			x, y, w, h,
			leftPad, format, bits);
	    xr_finish_access (drawable, image);
	}
    }
}

static void
xr_pattern_init_for_drawable (cairo_surface_pattern_t *pattern,
			      DrawablePtr drawable)
{
    cairo_surface_t *surface;

    surface = xr_drawable_get_surface (drawable);
    _cairo_pattern_init_for_surface (pattern, surface);
    cairo_surface_destroy (surface);

    pattern->base.filter = CAIRO_FILTER_NEAREST;
    pattern->base.extend = CAIRO_EXTEND_NONE;
    cairo_matrix_init_translate (&pattern->base.matrix,
				 drawable->x,
				 drawable->y);
}

static RegionPtr
xr_copy_area (DrawablePtr src,
	      DrawablePtr dst,
	      GCPtr gc,
	      int src_x, int src_y,
	      int width, int height,
	      int dst_x, int dst_y)
{
    cairo_surface_pattern_t pattern;
    cairo_clip_t *clip;
    cairo_surface_t *surface;
    cairo_status_t status;
    cairo_path_fixed_t path;
    cairo_fixed_t x1, x2, y1, y2;

    xr_pattern_init_for_drawable (&pattern, src);
    cairo_matrix_translate (&pattern.base.matrix,
			    src->x + src_x - dst_x - dst->x,
			    src->y + src_y - dst_y - dst->y);

    clip = xr_gc_get_clip (gc, dst->x, dst->y);
    surface = xr_drawable_get_surface (dst);

    x1 = _cairo_fixed_from_int (dst_x + dst->x);
    y1 = _cairo_fixed_from_int (dst_y + dst->y);
    x2 = x1 + _cairo_fixed_from_int (width);
    y2 = y1 + _cairo_fixed_from_int (height);
    _cairo_path_fixed_init (&path);
    if (_cairo_path_fixed_move_to (&path, x1, y1) ||
	_cairo_path_fixed_line_to (&path, x2, y1) ||
	_cairo_path_fixed_line_to (&path, x2, y2) ||
	_cairo_path_fixed_line_to (&path, x1, y2) ||
	_cairo_path_fixed_close_path (&path))
    {
	goto err_path;
    }

    status = _cairo_surface_fill (surface,
				  CAIRO_OPERATOR_SOURCE,
				  &pattern.base,
				  &path,
				  CAIRO_FILL_RULE_WINDING,
				  CAIRO_ANTIALIAS_DEFAULT,
				  CAIRO_GSTATE_TOLERANCE_DEFAULT,
				  clip);
    (void) status;

err_path:
    _cairo_path_fixed_fini (&path);
    _cairo_pattern_fini (&pattern.base);
    cairo_surface_destroy (surface);

    return miGetCompositeClip (gc);
}

static RegionPtr
xr_copy_plane (DrawablePtr src,
	       DrawablePtr dst,
	       GCPtr gc,
	       int src_x, int src_y,
	       int w, int h,
	       int dst_x, int dst_y,
	       unsigned long bitPlane)
{
    RegionPtr ret = NULL;
    cairo_surface_t *src_image, *dst_image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (dst, &dst_image)) {
	if (xr_prepare_access (src, &src_image)) {
	    ret = fbCopyPlane (src, dst, gc,
			       src_x, src_y,
			       w, h,
			       dst_x, dst_y,
			       bitPlane);
	    xr_finish_access (src, src_image);
	}
	xr_finish_access (dst, dst_image);
    }
    return ret;
}

static void
xr_poly_point (DrawablePtr drawable,
	       GCPtr gc,
	       int mode,
	       int npt,
	       DDXPointPtr ppt)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	fbPolyPoint (drawable, gc, mode, npt, ppt);
	xr_finish_access (drawable, image);
    }
}

static void
xr_poly_line (DrawablePtr drawable,
	      GCPtr gc,
	      int mode,
	      int npt,
	      DDXPointPtr ppt)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	fbPolyLine (drawable, gc, mode, npt, ppt);
	xr_finish_access (drawable, image);
    }
}

static void
xr_poly_segment (DrawablePtr drawable,
		 GCPtr gc,
		 int nseg,
		 xSegment *pSeg)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	fbPolySegment (drawable, gc, nseg, pSeg);
	xr_finish_access (drawable, image);
    }
}

static void
xr_poly_rectangle (DrawablePtr drawable,
		    GCPtr gc,
		    int nrect,
		    xRectangle *pRects)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	fbPolyRectangle (drawable, gc, nrect, pRects);
	xr_finish_access (drawable, image);
    }
}

static void
xr_poly_arc (DrawablePtr drawable,
	     GCPtr gc,
	     int narcs,
	     xArc *pArcs)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	fbPolyArc (drawable, gc, narcs, pArcs);
	xr_finish_access (drawable, image);
    }
}

static void
xr_poly_fill (DrawablePtr drawable,
	      GCPtr gc,
	      int shape,
	      int mode,
	      int count,
	      DDXPointPtr pPts)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	fbFillPolygon (drawable, gc, shape, mode, count, pPts);
	xr_finish_access (drawable, image);
    }
}

static void
xr_poly_fill_rect_fallback (DrawablePtr drawable,
			    GCPtr gc,
			    int nrect,
			    xRectangle *prect)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	miPolyFillRect (drawable, gc, nrect, prect);
	xr_finish_access (drawable, image);
    }
}


static void
xr_poly_fill_rect (DrawablePtr drawable,
		   GCPtr gc,
		   int nrect,
		   xRectangle *rect)
{
    cairo_clip_t *clip;
    cairo_surface_t *surface;
    cairo_status_t status;
    int n;

    if (gc->alu != GXcopy && gc->alu != GXclear) {
	xr_poly_fill_rect_fallback (drawable, gc, nrect, rect);
	return;
    }

    if (gc->fillStyle != FillSolid &&
	!(gc->tileIsPixel && gc->fillStyle == FillTiled))
    {
	xr_poly_fill_rect_fallback (drawable, gc, nrect, rect);
	return;
    }

    surface = xr_drawable_get_surface (drawable);
    clip = xr_gc_get_clip (gc, drawable->x, drawable->y);
    if (clip == NULL && nrect == 1 &&
	rect->x <= 0 &&
	rect->y <= 0 &&
	rect->width >= drawable->width &&
	rect->height >= drawable->height &&
	(gc->alu == GXclear || (gc->fgPixel & 0x00ffffff) == 0))
    {
	status = _cairo_surface_paint (surface,
				       CAIRO_OPERATOR_CLEAR,
				       &_cairo_pattern_clear.base,
				       NULL);
    }
    else
    {
	cairo_path_fixed_t path;
	cairo_fixed_t x_off, y_off;
	cairo_solid_pattern_t pattern;
	cairo_color_t color;

	x_off = _cairo_fixed_from_int (drawable->x);
	y_off = _cairo_fixed_from_int (drawable->y);
	_cairo_path_fixed_init (&path);
	for (n = 0; n < nrect; n++) {
	    cairo_fixed_t x1 = x_off + _cairo_fixed_from_int (rect[n].x);
	    cairo_fixed_t x2 = x1 + _cairo_fixed_from_int (rect[n].width);
	    cairo_fixed_t y1 = y_off + _cairo_fixed_from_int (rect[n].y);
	    cairo_fixed_t y2 = y1 + _cairo_fixed_from_int (rect[n].height);

	    if (_cairo_path_fixed_move_to (&path, x1, y1) ||
		_cairo_path_fixed_line_to (&path, x2, y1) ||
		_cairo_path_fixed_line_to (&path, x2, y2) ||
		_cairo_path_fixed_line_to (&path, x1, y2) ||
		_cairo_path_fixed_close_path (&path))
	    {
		goto err_path;
	    }
	}

	_cairo_color_init_rgb (&color,
			       ((gc->fgPixel & 0x00ff0000) >> 16) / 255.,
			       ((gc->fgPixel & 0x0000ff00) >> 8) / 255.,
			       ((gc->fgPixel & 0x000000ff) >> 0) / 255.);
	_cairo_pattern_init_solid (&pattern, &color, CAIRO_CONTENT_COLOR);

	status = _cairo_surface_fill (surface,
				      gc->alu == GXcopy ? CAIRO_OPERATOR_SOURCE : CAIRO_OPERATOR_CLEAR,
				      &pattern.base,
				      &path,
				      CAIRO_FILL_RULE_WINDING,
				      1.,
				      CAIRO_ANTIALIAS_DEFAULT,
				      clip);
err_path:
	_cairo_path_fixed_fini (&path);
    }

    cairo_surface_destroy (surface);
    (void) status;
}

static void
xr_poly_fill_arc (DrawablePtr drawable,
		  GCPtr gc,
		  int narc,
		  xArc *arc)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	miPolyFillArc (drawable, gc, narc, arc);
	xr_finish_access (drawable, image);
    }
}

static void
xr_image_glyph_blt (DrawablePtr drawable, GCPtr gc,
			  int x, int y, unsigned int nglyph,
			  CharInfoPtr * ppci, pointer pglyphBase)
{
    cairo_surface_t *image;
    struct xr_access_gc local_gc;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	if (xr_prepare_access_gc (gc, &local_gc)) {
	    fbImageGlyphBlt (drawable, gc,
			     x, y,
			     nglyph,
			     ppci,
			     pglyphBase);
	    xr_finish_access_gc (gc, &local_gc);
	}
	xr_finish_access (drawable, image);
    }
}

static void
xr_poly_glyph_blt (DrawablePtr drawable,
		   GCPtr gc,
		   int x, int y,
		   unsigned int nglyph,
		   CharInfoPtr *ppci,
		   pointer pglyphBase)
{
    cairo_surface_t *image;
    struct xr_access_gc local_gc;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	if (xr_prepare_access_gc (gc, &local_gc)) {
	    fbPolyGlyphBlt (drawable, gc,
			    x, y,
			    nglyph,
			    ppci,
			    pglyphBase);
	    xr_finish_access_gc (gc, &local_gc);
	}
	xr_finish_access (drawable, image);
    }
}

static void
xr_push_pixels (GCPtr gc,
		PixmapPtr src,
		DrawablePtr dst,
		int w, int h, int x, int y)
{
    cairo_surface_t *src_image, *dst_image;
    struct xr_access_gc local_gc;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (dst, &dst_image)) {
	if (xr_prepare_access (&src->drawable, &src_image)) {
	    if (xr_prepare_access_gc (gc, &local_gc)) {
		fbPushPixels (gc, src, dst,
			     w, h, x, y);
		xr_finish_access_gc (gc, &local_gc);
	    }
	    xr_finish_access (&src->drawable, src_image);
	}
	xr_finish_access (dst, dst_image);
    }
}

static void
xr_validate_gc (GCPtr gc,
		unsigned long changes,
		DrawablePtr drawable)
{
    static const GCOps xr_ops = {
	xr_fill_spans,
	xr_set_spans,
	xr_put_image,
	xr_copy_area,
	xr_copy_plane,
	xr_poly_point,
	xr_poly_line,
	xr_poly_segment,
	xr_poly_rectangle,
	xr_poly_arc,
	xr_poly_fill,
	xr_poly_fill_rect,
	xr_poly_fill_arc,
	miPolyText8,
	miPolyText16,
	miImageText8,
	miImageText16,
	xr_image_glyph_blt,
	xr_poly_glyph_blt,
	xr_push_pixels,
    };

    /* fbValidateGC will do direct access to pixmaps if the tiling has
     * changed.  Preempt fbValidateGC by doing its work and masking the
     * change out, so that we can do the prepare/finish access.
     */
#ifdef FB_24_32BIT
    if (changes & GCTile && fbGetRotatedPixmap (gc)) {
	gc->pScreen->DestroyPixmap (fbGetRotatedPixmap (gc));
	fbGetRotatedPixmap (gc) = 0;
    }

    if (gc->fillStyle == FillTiled) {
	PixmapPtr old;

	old = gc->tile.pixmap;
	if (old->drawable.bitsPerPixel != drawable->bitsPerPixel) {
	    PixmapPtr new = fbGetRotatedPixmap (gc);
	    if (new == NULL ||
		new->drawable.bitsPerPixel != drawable->bitsPerPixel)
	    {
		cairo_surface_t *image;

		if (new)
		    gc->pScreen->DestroyPixmap (new);

		/* fb24_32ReformatTile will do direct access
		 * of a newly-allocated pixmap.  This isn't a
		 * problem yet, since we don't put pixmaps in
		 * FB until at least one accelerated UXA op.
		 */
		if (xr_prepare_access (&old->drawable, &image)) {
		    new = fb24_32ReformatTile (old,
					       drawable->bitsPerPixel);
		    xr_finish_access (&old->drawable, image);
		}
	    }

	    if (new) {
		fbGetRotatedPixmap (gc) = old;
		gc->tile.pixmap = new;
		changes |= GCTile;
	    }
	}
    }
#endif

    if (changes & GCTile) {
	if (! gc->tileIsPixel &&
	    FbEvenTile (gc->tile.pixmap->drawable.width *
			drawable->bitsPerPixel))
	{
	    cairo_surface_t *image;

	    if (xr_prepare_access (&gc->tile.pixmap->drawable,
				    &image))
	    {
		fbPadPixmap(gc->tile.pixmap);
		xr_finish_access(&gc->tile.pixmap->drawable, image);
	    }
	}

	/* Mask out the GCTile change notification, now that we've
	 * done FB's job for it.
	 */
	changes &= ~GCTile;
    }

    if (changes & GCStipple && gc->stipple) {
	cairo_surface_t *image;

	/* We can't inline stipple handling like we do for GCTile
	 * because it sets fbgc privates.
	 */
	if (xr_prepare_access (&gc->stipple->drawable, &image)) {
	    fbValidateGC (gc, changes, drawable);
	    xr_finish_access (&gc->stipple->drawable, image);
	}
    } else {
	fbValidateGC(gc, changes, drawable);
    }

    gc->ops = (GCOps *) & xr_ops;
}

static void
xr_change_gc (GCPtr gc, unsigned long mask)
{
}

static void
xr_copy_gc (GCPtr src, unsigned long changes, GCPtr dst)
{
}

static void
xr_destroy_gc (GCPtr gc)
{
    miDestroyGC (gc);
}

static void
xr_destroy_clip (GCPtr gc)
{
    miDestroyClip (gc);
}

static void
xr_change_clip (GCPtr gc, int type, pointer value, int nrects)
{
    xr_destroy_clip (gc);

    miChangeClip (gc, type, value, nrects);
}

static void
xr_copy_clip (GCPtr dst, GCPtr src)
{
    miCopyClip (dst, src);
}

static int xr_create_gc (GCPtr gc)
{
    static GCFuncs funcs = {
	xr_validate_gc,
	xr_change_gc,
	xr_copy_gc,
	xr_destroy_gc,
	xr_change_clip,
	xr_destroy_clip,
	xr_copy_clip,
    };

    if (! fbCreateGC (gc))
	return FALSE;

    gc->funcs = &funcs;
    return TRUE;
}

static void
xr_get_image (DrawablePtr drawable,
	      int x, int y, int w, int h,
	      unsigned int format, unsigned long planeMask,
	      char *d)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	fbGetImage (drawable, x, y, w, h, format, planeMask, d);
	xr_finish_access (drawable, image);
    }
}

static void
xr_get_spans (DrawablePtr drawable,
	      int wMax,
	      DDXPointPtr ppt,
	      int *pwidth,
	      int nspans,
	      char *pdstStart)
{
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (drawable, &image)) {
	fbGetSpans (drawable, wMax, ppt, pwidth, nspans, pdstStart);
	xr_finish_access (drawable, image);
    }
}

static void
xr_copy_window (WindowPtr win,
		DDXPointRec origin,
		RegionPtr src_region)
{
    //ErrorF ("fallback: %s\n", __FUNCTION__);
#if 0
    RegionRec dst_region;
    PixmapPtr pixmap;
    int dx, dy;

    dx = origin.x - win->drawable.x;
    dy = origin.y - win->drawable.y;
    REGION_TRANSLATE (win->drawable.pScreen, src_region, -dx, -dy);

    REGION_INIT (win->drawable.pScreen, &dst_region, NullBox, 0);

    REGION_INTERSECT (win->drawable.pScreen,
		      &dst_region, &win->borderClip,
		     src_region);
    pixmap = win->drawable.pScreen->GetWindowPixmap (win);
#ifdef COMPOSITE
    if (pixmap->screen_x || pixmap->screen_y)
	REGION_TRANSLATE (win->drawable.pScreen, &dst_region,
			  -pixmap->screen_x, -pixmap->screen_y);
#endif

    miCopyRegion (&pixmap->drawable, &pixmap->drawable,
		  NULL, &dst_region, dx, dy,
		  xr_copy_n_to_n, 0, NULL);

    REGION_UNINIT (win->drawable.pScreen, &dst_region);
#endif
}

static cairo_bool_t
xr_prepare_access_window (WindowPtr win,
			  struct xr_access_window *local)
{
    local->background = NULL;
    local->border = NULL;

    if (win->backgroundState == BackgroundPixmap) {
	if (! xr_prepare_access (&win->background.pixmap->drawable,
				 &local->background))
	{
	    return FALSE;
	}
    }

    if (win->borderIsPixel == FALSE) {
	if (! xr_prepare_access (&win->border.pixmap->drawable,
				 &local->border))
	{
	    if (local->background) {
		xr_finish_access (&win->background.pixmap->drawable,
				  local->background);
	    }
	    return FALSE;
	}
    }
    return TRUE;
}

static void
xr_finish_access_window (WindowPtr win,
			 struct xr_access_window *local)
{
    if (local->background) {
	xr_finish_access (&win->background.pixmap->drawable,
			  local->background);
    }

    if (local->border) {
	xr_finish_access (&win->border.pixmap->drawable,
			  local->border);
    }
}

static Bool
xr_change_window_attributes (WindowPtr win,
			     unsigned long mask)
{
    Bool ret = FALSE;
    struct xr_access_window local;

    if (xr_prepare_access_window (win, &local)) {
	ret = fbChangeWindowAttributes (win, mask);
	xr_finish_access_window (win, &local);
    }

    return ret;
}

static RegionPtr
xr_bitmap_to_region (PixmapPtr pPix)
{
    RegionPtr ret = NULL;
    cairo_surface_t *image;

    //ErrorF ("fallback: %s\n", __FUNCTION__);
    if (xr_prepare_access (&pPix->drawable, &image)) {
	ret = fbPixmapToRegion (pPix);
	xr_finish_access (&pPix->drawable, image);
    }

    return ret;
}

static void
_color_from_pixel (cairo_color_t *color, uint32_t pixel)
{
    color->alpha_short = (pixel & 0xff000000 >> 24);
    color->alpha_short |= color->alpha_short << 8;

    if (color->alpha_short == 0) {
	color->red_short = color->green_short = color->blue_short = 0;
	color->alpha = color->red = color->green = color->blue = 0.;
	return;
    }

    color->red_short = (pixel & 0x00ff0000 >> 16);
    color->red_short |= color->red_short << 8;

    color->green_short = (pixel & 0x0000ff00 >> 8);
    color->green_short |= color->green_short << 8;

    color->blue_short = (pixel & 0x000000ff >> 0);
    color->blue_short |= color->blue_short << 8;

    color->alpha = color->alpha_short / (double) 0xffff;
    color->red = color->red_short / (double) 0xffff / color->alpha;
    color->green = color->green_short / (double) 0xffff / color->alpha;
    color->blue = color->blue_short / (double) 0xffff / color->alpha;
}

static uint32_t
_pixmap_first_pixel (PixmapPtr pixmap)
{
    cairo_surface_t *image;
    uint32_t pixel;
    void *fb;

    if (! xr_prepare_access (&pixmap->drawable, &image))
	return 0;

    fb = pixmap->devPrivate.ptr;
    switch (pixmap->drawable.bitsPerPixel) {
    case 32:
	pixel = *(uint32_t *) fb;
	break;
    case 16:
	pixel = *(uint16_t *) fb;
	break;
    default:
	pixel = *(CARD8 *) fb;
	break;
    }
    xr_finish_access (&pixmap->drawable, image);

    return pixel;
}

static cairo_bool_t
_rgba_from_pixel (uint32_t pixel,
		  uint16_t *red,
		  uint16_t *green,
		  uint16_t *blue,
		  uint16_t *alpha,
		  uint32_t format)
{
    int rbits, bbits, gbits, abits;
    int rshift, bshift, gshift, ashift;

    rbits = PICT_FORMAT_R(format);
    gbits = PICT_FORMAT_G(format);
    bbits = PICT_FORMAT_B(format);
    abits = PICT_FORMAT_A(format);

    if (PICT_FORMAT_TYPE(format) == PICT_TYPE_A) {
	rshift = gshift = bshift = ashift = 0;
    } else if (PICT_FORMAT_TYPE(format) == PICT_TYPE_ARGB) {
	bshift = 0;
	gshift = bbits;
	rshift = gshift + gbits;
	ashift = rshift + rbits;
    } else if (PICT_FORMAT_TYPE(format) == PICT_TYPE_ABGR) {
	rshift = 0;
	gshift = rbits;
	bshift = gshift + gbits;
	ashift = bshift + bbits;
    } else {
	return FALSE;
    }

    if (rbits) {
	*red = ((pixel >> rshift) & ((1 << rbits) - 1)) << (16 - rbits);
	while (rbits < 16) {
	    *red |= *red >> rbits;
	    rbits <<= 1;
	}
    } else
	*red = 0;

    if (gbits) {
	*green = ((pixel >> gshift) & ((1 << gbits) - 1)) << (16 - gbits);
	while (gbits < 16) {
	    *green |= *green >> gbits;
	    gbits <<= 1;
	}
    } else
	*green = 0;

    if (bbits) {
	*blue = ((pixel >> bshift) & ((1 << bbits) - 1)) << (16 - bbits);
	while (bbits < 16) {
	    *blue |= *blue >> bbits;
	    bbits <<= 1;
	}
    } else
	*blue = 0;

    if (abits) {
	*alpha =
	    ((pixel >> ashift) & ((1 << abits) - 1)) << (16 - abits);
	while (abits < 16) {
	    *alpha |= *alpha >> abits;
	    abits <<= 1;
	}
    } else
	*alpha = 0xffff;

    return TRUE;
}

static cairo_bool_t
_color_from_pixmap (PixmapPtr	 pixmap,
		    uint32_t	 src_format,
		    cairo_color_t  *color)
{
    uint32_t pixel = _pixmap_first_pixel(pixmap);
    if (! _rgba_from_pixel (pixel,
			    &color->red_short,
			    &color->green_short,
			    &color->blue_short,
			    &color->alpha_short,
			    src_format))
    {
	return FALSE;
    }

    if (color->alpha_short == 0) {
	color->red_short = color->green_short = color->blue_short = 0;
	color->alpha = color->red = color->green = color->blue = 0.;
	return TRUE;
    }

    color->alpha = color->alpha_short / (double) 0xffff;
    color->red = color->red_short / (double) 0xffff / color->alpha;
    color->green = color->green_short / (double) 0xffff / color->alpha;
    color->blue = color->blue_short / (double) 0xffff / color->alpha;
    return TRUE;
}

static cairo_bool_t
xr_pattern_init_for_picture (cairo_pattern_union_t *pattern,
			     PicturePtr picture)
{
    cairo_color_t color;

    if (picture->pSourcePict) {
	SourcePict *source = picture->pSourcePict;
	switch (source->type) {
	case SourcePictTypeSolidFill:
	    _color_from_pixel (&color, source->solidFill.color);
	    _cairo_pattern_init_solid (&pattern->solid,
				       &color,
				       CAIRO_CONTENT_COLOR_ALPHA);
	    break;
	default:
	    return FALSE;
	}
    } else if (picture->pDrawable) {
	cairo_surface_t *surface;

	if (picture->alphaMap)
	    return FALSE;

	if (picture->pDrawable->width == 1 &&
	    picture->pDrawable->height == 1 &&
	    picture->repeat == 1)
	{
	    if (! _color_from_pixmap ((PixmapPtr) picture->pDrawable,
				      picture->format,
				      &color))
		goto use_surface;

	    _cairo_pattern_init_solid (&pattern->solid,
				       &color,
				       CAIRO_CONTENT_COLOR_ALPHA);
	}
	else
	{
use_surface:
	    surface = xr_drawable_get_surface (picture->pDrawable);
	    _cairo_pattern_init_for_surface (&pattern->surface,
					     surface);
	    cairo_surface_destroy (surface);
	}
    } else {
	return FALSE;
    }

    if (! picture->repeat) {
	pattern->base.extend = CAIRO_EXTEND_NONE;
    } else switch (picture->repeatType) {
    case RepeatNormal:
	pattern->base.extend = CAIRO_EXTEND_REPEAT;
	break;
    case RepeatPad:
	pattern->base.extend = CAIRO_EXTEND_PAD;
	break;
    case RepeatReflect:
	pattern->base.extend = CAIRO_EXTEND_REFLECT;
	break;
    default:
	goto fail;
    }

    switch (picture->filter) {
    case PictFilterNearest:
	pattern->base.filter = CAIRO_FILTER_NEAREST;
	break;
    case PictFilterBilinear:
	pattern->base.filter = CAIRO_FILTER_BILINEAR;
	break;
    case PictFilterFast:
	pattern->base.filter = CAIRO_FILTER_FAST;
	break;
    case PictFilterGood:
	pattern->base.filter = CAIRO_FILTER_GOOD;
	break;
    case PictFilterBest:
	pattern->base.filter = CAIRO_FILTER_BEST;
	break;
    default:
	goto fail;
    }

    return TRUE;

fail:
    _cairo_pattern_fini (&pattern->base);
    return FALSE;
}

static cairo_bool_t
_render_operator (CARD8 render_op, cairo_operator_t *op)
{
    switch (render_op) {
    case PictOpClear: *op = CAIRO_OPERATOR_CLEAR; break;
    case PictOpSrc: *op = CAIRO_OPERATOR_SOURCE; break;
    case PictOpOver: *op = CAIRO_OPERATOR_OVER; break;
    case PictOpIn: *op = CAIRO_OPERATOR_IN; break;
    case PictOpOut: *op = CAIRO_OPERATOR_OUT; break;
    case PictOpAtop: *op = CAIRO_OPERATOR_ATOP; break;
    case PictOpDst: *op = CAIRO_OPERATOR_DEST; break;
    case PictOpOverReverse: *op = CAIRO_OPERATOR_DEST_OVER; break;
    case PictOpInReverse: *op = CAIRO_OPERATOR_DEST_IN; break;
    case PictOpOutReverse: *op = CAIRO_OPERATOR_DEST_OUT; break;
    case PictOpAtopReverse: *op = CAIRO_OPERATOR_DEST_ATOP; break;
    case PictOpXor: *op = CAIRO_OPERATOR_XOR; break;
    case PictOpAdd: *op = CAIRO_OPERATOR_ADD; break;
    case PictOpSaturate: *op = CAIRO_OPERATOR_SATURATE; break;
    case PictOpMultiply: *op = CAIRO_OPERATOR_MULTIPLY; break;
    case PictOpScreen: *op = CAIRO_OPERATOR_SCREEN; break;
    case PictOpOverlay: *op = CAIRO_OPERATOR_OVERLAY; break;
    case PictOpDarken: *op = CAIRO_OPERATOR_DARKEN; break;
    case PictOpLighten: *op = CAIRO_OPERATOR_LIGHTEN; break;
    case PictOpColorDodge: *op = CAIRO_OPERATOR_COLOR_DODGE; break;
    case PictOpColorBurn: *op = CAIRO_OPERATOR_COLOR_BURN; break;
    case PictOpHardLight: *op = CAIRO_OPERATOR_HARD_LIGHT; break;
    case PictOpSoftLight: *op = CAIRO_OPERATOR_SOFT_LIGHT; break;
    case PictOpDifference: *op = CAIRO_OPERATOR_DIFFERENCE; break;
    case PictOpExclusion: *op = CAIRO_OPERATOR_EXCLUSION; break;
    case PictOpHSLHue: *op = CAIRO_OPERATOR_HSL_HUE; break;
    case PictOpHSLSaturation: *op = CAIRO_OPERATOR_HSL_SATURATION; break;
    case PictOpHSLColor: *op = CAIRO_OPERATOR_HSL_COLOR; break;
    case PictOpHSLLuminosity: *op = CAIRO_OPERATOR_HSL_LUMINOSITY; break;

    default: return FALSE;
    }

    return TRUE;
}

static void
xr_picture_get_clip (PicturePtr picture,
		     cairo_clip_t *clip)
{
    cairo_status_t status;

    _cairo_clip_init (clip);

    if (picture->pCompositeClip) {
	cairo_path_fixed_t path;
	BoxPtr pbox;
	int nbox;

	nbox = REGION_NUM_RECTS (picture->pCompositeClip);
	pbox = REGION_RECTS (picture->pCompositeClip);
	_cairo_path_fixed_init (&path);
	while (nbox--) {
	    if (_cairo_path_fixed_move_to (&path,
					   _cairo_fixed_from_int (pbox->x1),
					   _cairo_fixed_from_int (pbox->y1)) ||
		_cairo_path_fixed_line_to (&path,
					   _cairo_fixed_from_int (pbox->x2),
					   _cairo_fixed_from_int (pbox->y1)) ||
		_cairo_path_fixed_line_to (&path,
					   _cairo_fixed_from_int (pbox->x2),
					   _cairo_fixed_from_int (pbox->y2)) ||
		_cairo_path_fixed_line_to (&path,
					   _cairo_fixed_from_int (pbox->x1),
					   _cairo_fixed_from_int (pbox->y2)) ||
		_cairo_path_fixed_close_path (&path))
	    {
		goto err_path;
	    }
	}

	status = _cairo_clip_clip (clip,
				   &path,
				   CAIRO_FILL_RULE_WINDING,
				   1.0,
				   CAIRO_ANTIALIAS_DEFAULT);

err_path:
	_cairo_path_fixed_fini (&path);
    }

    (void) status;
}

static void
xr_composite (CARD8 render_op,
	      PicturePtr pSrc,
	      PicturePtr pMask,
	      PicturePtr pDst,
	      INT16 xSrc, INT16 ySrc,
	      INT16 xMask, INT16 yMask,
	      INT16 xDst, INT16 yDst,
	      CARD16 width, CARD16 height)
{
    cairo_pattern_union_t source, mask;
    cairo_operator_t op;
    cairo_surface_t *surface;
    cairo_clip_t clip;
    cairo_rectangle_int_t rect;
    cairo_bool_t mask_is_clipped = FALSE, source_is_clipped = FALSE;
    cairo_status_t status;

    if (! _render_operator (render_op, &op))
	goto fallback;

    if (! xr_pattern_init_for_picture (&source, pSrc))
	goto fallback;

    cairo_matrix_translate (&source.base.matrix,
			    xSrc - xDst, ySrc - yDst);

    if (pMask) {
	if (! xr_pattern_init_for_picture (&mask, pMask)) {
	    _cairo_pattern_fini (&source.base);
	    goto fallback;
	}

	cairo_matrix_translate (&mask.base.matrix,
				xMask - xDst, yMask - yDst);
    }

    xr_picture_get_clip (pDst, &clip);
    rect.x = xDst;
    rect.y = yDst;
    rect.width  = width;
    rect.height = height;
    status = _cairo_clip_rectangle (&clip, &rect);

#if 0
    {
	cairo_clip_t clip_source;

	xr_picture_get_clip (pSrc, &clip_source);
	if (clip_source.path != NULL) {
	    _cairo_clip_apply_clip (&clip, &clip_source);
	    source_is_clipped = TRUE;
	}
	_cairo_clip_fini (&clip_source);
    }
    if (pMask) {
	cairo_clip_t clip_mask;

	xr_picture_get_clip (pMask, &clip_mask);
	if (clip_mask.path != NULL) {
	    _cairo_clip_apply_clip (&clip, &clip_mask);
	    mask_is_clipped = TRUE;
	}
	_cairo_clip_fini (&clip_mask);
    }
#endif

    surface = xr_drawable_get_surface (pDst->pDrawable);
    if (! clip.all_clipped) {
	if (pMask) {
	    status = _cairo_surface_mask (surface, op,
					  &source.base,
					  &mask.base,
					  &clip);
	} else {
	    status = _cairo_surface_paint (surface, op,
					   &source.base,
					   &clip);
	}
    }

#if 0
    if (source_is_clipped) {
	/* clear areas in dst where source was clipped */
	cairo_surface_t *surface;
	cairo_clip_t clip_source;

	if (pMask) {
	    cairo_clip_t clip_mask;

	    xr_picture_get_clip (pMask, &clip_mask);
	    if (clip_mask.path != NULL) {
		_cairo_clip_apply_clip (&local_clip, &clip_mask);
		mask_is_clipped = TRUE;
	    }
	    _cairo_clip_fini (&clip_mask);
	}

	xr_picture_get_inverse_clip (pSrc, &clip_source);
	_cairo_clip_apply_clip (&clip_source, &clip);

	if (pMask) {
	    status = _cairo_surface_mask (surface,
					  CAIRO_OPERATOR_CLEAR,
					  &_cairo_pattern_clear.base,
					  &mask.base,
					  &clip_source);
	} else {
	    status = _cairo_surface_paint (surface,
					  CAIRO_OPERATOR_CLEAR,
					  &_cairo_pattern_clear.base,
					  &clip_source);
	}
	_cairo_clip_fini (&clip_source);
    }

    if (mask_is_clipped && ! _cairo_operator_bounded_by_mask (op)) {
	/* clear areas in dst where mask was clipped */
	cairo_surface_t *surface;
	cairo_clip_t clip_mask;

	xr_picture_get_inverse_clip (pMask, &clip_mask);
	_cairo_clip_apply_clip (&clip, &clip_mask);
	_cairo_clip_fini (&clip_mask);

	status = _cairo_surface_paint (surface,
				       CAIRO_OPERATOR_CLEAR,
				       &_cairo_pattern_clear.base,
				       &clip);
    }
#endif

    cairo_surface_destroy (surface);
    _cairo_clip_fini (&clip);

    if (pMask)
	_cairo_pattern_fini (&mask.base);
    _cairo_pattern_fini (&source.base);

    return;

fallback:
    {
	cairo_surface_t *dst_image, *src_image, *mask_image;
	//ErrorF ("fallback: %s\n", __FUNCTION__);
	if (xr_prepare_access (pDst->pDrawable, &dst_image)) {
	    if (pSrc->pDrawable == NULL ||
		xr_prepare_access (pSrc->pDrawable, &src_image))
	    {
		if (pMask == NULL || pMask->pDrawable == NULL ||
		    xr_prepare_access (pMask->pDrawable, &mask_image))
		{
		    fbComposite (op, pSrc, pMask, pDst,
				 xSrc, ySrc,
				 xMask, yMask,
				 xDst, yDst,
				 width, height);
		    if (pMask && pMask->pDrawable)
			xr_finish_access (pMask->pDrawable, mask_image);
		}
		if (pSrc->pDrawable)
		    xr_finish_access (pSrc->pDrawable, src_image);
	    }
	    xr_finish_access (pDst->pDrawable, dst_image);
	}
    }
}

static void
xr_glyphs (CARD8 op,
	   PicturePtr pSrc,
	   PicturePtr pDst,
	   PictFormatPtr maskFormat,
	   INT16 xSrc, INT16 ySrc,
	   int nlist,
	   GlyphListPtr list,
	   GlyphPtr *glyphs)
{
}

static cairo_bool_t
xr_do_fill (cairo_operator_t op,
	    PicturePtr pSrc,
	    PicturePtr pDst,
	    int		src_x,
	    int		src_y,
	    cairo_path_fixed_t *path)
{
    cairo_pattern_union_t source;
    cairo_clip_t clip;
    cairo_surface_t *surface;
    cairo_status_t status;

    if (! xr_pattern_init_for_picture (&source, pSrc))
	return FALSE;

    cairo_matrix_translate (&source.base.matrix, src_x, src_y);

    surface = xr_drawable_get_surface (pDst->pDrawable);
    xr_picture_get_clip (pDst, &clip);
    status = _cairo_surface_fill (surface, op, &source.base, path,
				  CAIRO_FILL_RULE_WINDING,
				  pDst->polyEdge == PolyEdgeSharp ? CAIRO_ANTIALIAS_NONE : CAIRO_ANTIALIAS_DEFAULT,
				  CAIRO_GSTATE_TOLERANCE_DEFAULT,
				  clip.path ? &clip : NULL);
    _cairo_clip_fini (&clip);
    cairo_surface_destroy (surface);
    _cairo_pattern_fini (&source.base);

    return TRUE;
}

static void
xr_composite_rects (CARD8		 render_op,
		    PicturePtr		 picture,
		    xRenderColor	*xColor,
		    int			 nrect,
		    xRectangle		*rect)
{
    cairo_operator_t op;
    cairo_clip_t clip;
    cairo_surface_t *surface;
    cairo_status_t status;

    if (! _render_operator (render_op, &op))
	goto fallback;

    surface = xr_drawable_get_surface (picture->pDrawable);
    xr_picture_get_clip (picture, &clip);
    if (clip.path == NULL && nrect == 1 &&
	rect->x <= 0 &&
	rect->y <= 0 &&
	rect->width >= picture->pDrawable->width &&
	rect->height >= picture->pDrawable->height &&
	(op == CAIRO_OPERATOR_CLEAR || (op == CAIRO_OPERATOR_SOURCE && xColor->alpha <= 0x00ff)))
    {
	status = _cairo_surface_paint (surface,
				       CAIRO_OPERATOR_CLEAR,
				       &_cairo_pattern_clear.base,
				       NULL);
    }
    else
    {
	cairo_path_fixed_t path;
	cairo_fixed_t x_off, y_off;
	cairo_solid_pattern_t pattern;
	cairo_color_t color;
	int n;

	x_off = _cairo_fixed_from_int (picture->pDrawable->x);
	y_off = _cairo_fixed_from_int (picture->pDrawable->y);
	_cairo_path_fixed_init (&path);
	for (n = 0; n < nrect; n++) {
	    cairo_fixed_t x1 = x_off + _cairo_fixed_from_int (rect[n].x);
	    cairo_fixed_t x2 = x1 + _cairo_fixed_from_int (rect[n].width);
	    cairo_fixed_t y1 = y_off + _cairo_fixed_from_int (rect[n].y);
	    cairo_fixed_t y2 = y1 + _cairo_fixed_from_int (rect[n].height);

	    if (_cairo_path_fixed_move_to (&path, x1, y1) ||
		_cairo_path_fixed_line_to (&path, x2, y1) ||
		_cairo_path_fixed_line_to (&path, x2, y2) ||
		_cairo_path_fixed_line_to (&path, x1, y2) ||
		_cairo_path_fixed_close_path (&path))
	    {
		goto err_path;
	    }
	}

	color.red_short   = xColor->red;
	color.green_short = xColor->green;
	color.blue_short  = xColor->blue;
	color.alpha_short = xColor->alpha;
	if (color.alpha_short <= 0x00ff) {
	    color.red_short = color.green_short = color.blue_short = 0;
	    color.alpha = color.red = color.green = color.blue = 0.;
	} else {
	    color.alpha = color.alpha_short / (double) 0xffff;
	    color.red   = color.red_short / (double) 0xffff / color.alpha;
	    color.green = color.green_short / (double) 0xffff / color.alpha;
	    color.blue  = color.blue_short / (double) 0xffff / color.alpha;
	}
	_cairo_pattern_init_solid (&pattern, &color, CAIRO_CONTENT_COLOR);

	status = _cairo_surface_fill (surface, op,
				      &pattern.base,
				      &path,
				      CAIRO_FILL_RULE_WINDING,
				      1.,
				      CAIRO_ANTIALIAS_DEFAULT,
				      clip.path ? &clip : NULL);
err_path:
	_cairo_path_fixed_fini (&path);
    }

    cairo_surface_destroy (surface);
    _cairo_clip_fini (&clip);

    (void) status;
    return;

fallback:
    //ErrorF ("fallback: %s\n", __FUNCTION__);
#if 0
    {
	cairo_surface_t *dst_image, *src_image;
	if (xr_prepare_access (pDst->pDrawable, &dst_image)) {
	    if (pSrc->pDrawable == NULL ||
		xr_prepare_access (pSrc->pDrawable, &src_image))
	    {
		fbTrapezoids (op, pSrc, pDst,
			      maskFormat,
			      xSrc, ySrc,
			      ntrap, traps);
		if (pSrc->pDrawable)
		    xr_finish_access (pSrc->pDrawable, src_image);
	    }
	    xr_finish_access (pDst->pDrawable, dst_image);
	}
    }
#endif
    return;
}

static void
xr_trapezoids (CARD8	    render_op,
	       PicturePtr   pSrc,
	       PicturePtr   pDst,
	       PictFormatPtr maskFormat,
	       INT16	    xSrc,
	       INT16	    ySrc,
	       int	    ntrap,
	       xTrapezoid   *traps)
{
    cairo_path_fixed_t path;
    cairo_operator_t op;
    int src_x, src_y;

    if (! _render_operator (render_op, &op))
	goto fallback;

    src_x = xSrc - (traps->left.p1.x >> 16);
    src_y = ySrc - (traps->left.p1.y >> 16);

    _cairo_path_fixed_init (&path);
    while (ntrap--) {
	if (traps->bottom > traps->top) {
	    cairo_fixed_t x1, x2;
	    cairo_fixed_t y1, y2;

	    if (traps->left.p1.y != traps->top) {
		double x;

		x = _cairo_fixed_16_16_to_double (traps->left.p1.x) +
		    _cairo_fixed_16_16_to_double (traps->left.p1.x - traps->left.p2.x) *
		    _cairo_fixed_16_16_to_double (traps->top - traps->left.p2.y) /
		    _cairo_fixed_16_16_to_double (traps->left.p1.y - traps->left.p2.y);

		x1 = _cairo_fixed_from_double (x);
	    } else {
		x1 = _cairo_fixed_from_16_16 (traps->left.p1.x);
	    }

	    if (traps->right.p1.y != traps->top) {
		double x;

		x = _cairo_fixed_16_16_to_double (traps->right.p1.x) +
		    _cairo_fixed_16_16_to_double (traps->right.p1.x - traps->right.p2.x) *
		    _cairo_fixed_16_16_to_double (traps->top - traps->right.p2.y) /
		    _cairo_fixed_16_16_to_double (traps->right.p1.y - traps->right.p2.y);

		x2 = _cairo_fixed_from_double (x);
	    } else {
		x2 = _cairo_fixed_from_16_16 (traps->left.p2.x);
	    }

	    y1 = _cairo_fixed_from_16_16 (traps->top);
	    y2 = _cairo_fixed_from_16_16 (traps->bottom);

	    if (_cairo_path_fixed_move_to (&path, x1, y1) ||
		_cairo_path_fixed_line_to (&path, x2, y1) ||
		_cairo_path_fixed_line_to (&path, x2, y2) ||
		_cairo_path_fixed_line_to (&path, x1, y2) ||
		_cairo_path_fixed_close_path (&path))
	    {
		goto err_path;
	    }
	}

	traps++;
    }

    if (! xr_do_fill (op, pSrc, pDst, src_x, src_y, &path)) {
	_cairo_path_fixed_fini (&path);
	goto fallback;
    }

err_path:
    _cairo_path_fixed_fini (&path);

    return;

fallback:
    //ErrorF ("fallback: %s\n", __FUNCTION__);
#if 0
    {
	cairo_surface_t *dst_image, *src_image;
	if (xr_prepare_access (pDst->pDrawable, &dst_image)) {
	    if (pSrc->pDrawable == NULL ||
		xr_prepare_access (pSrc->pDrawable, &src_image))
	    {
		fbTrapezoids (op, pSrc, pDst,
			      maskFormat,
			      xSrc, ySrc,
			      ntrap, traps);
		if (pSrc->pDrawable)
		    xr_finish_access (pSrc->pDrawable, src_image);
	    }
	    xr_finish_access (pDst->pDrawable, dst_image);
	}
    }
#endif
    return;
}

static void
xr_triangles (CARD8	    render_op,
	      PicturePtr	    pSrc,
	      PicturePtr	    pDst,
	      PictFormatPtr   maskFormat,
	      INT16	    xSrc,
	      INT16	    ySrc,
	      int	     ntriangles,
	      xTriangle	    *triangles)
{
    cairo_path_fixed_t path;
    cairo_operator_t op;
    int src_x, src_y;

    if (! _render_operator (render_op, &op))
	goto fallback;

    src_x = xSrc - (triangles->p1.x >> 16);
    src_y = ySrc - (triangles->p1.y >> 16);

    _cairo_path_fixed_init (&path);
    while (ntriangles--) {
	if (_cairo_path_fixed_move_to (&path,
				       _cairo_fixed_from_16_16 (triangles->p1.x),
				       _cairo_fixed_from_16_16 (triangles->p1.y)) ||
	    _cairo_path_fixed_line_to (&path,
				       _cairo_fixed_from_16_16 (triangles->p2.x),
				       _cairo_fixed_from_16_16 (triangles->p2.y)) ||
	    _cairo_path_fixed_line_to (&path,
				       _cairo_fixed_from_16_16 (triangles->p3.x),
				       _cairo_fixed_from_16_16 (triangles->p3.y)) ||
	    _cairo_path_fixed_close_path (&path))
	{
	    goto err_path;
	}

	triangles++;
    }

    if (! xr_do_fill (op, pSrc, pDst, src_x, src_y, &path)) {
	_cairo_path_fixed_fini (&path);
	goto fallback;
    }

err_path:
    _cairo_path_fixed_fini (&path);

    return;

fallback:
    //ErrorF ("fallback: %s\n", __FUNCTION__);
#if 0
    {
	cairo_surface_t *dst_image, *src_image;
	if (xr_prepare_access (pDst->pDrawable, &dst_image)) {
	    if (pSrc->pDrawable == NULL ||
		xr_prepare_access (pSrc->pDrawable, &src_image))
	    {
		fbTriangles (op, pSrc, pDst,
			     maskFormat,
			     xSrc, ySrc,
			     ntriangles, triangles);
		if (pSrc->pDrawable)
		    xr_finish_access (pSrc->pDrawable, src_image);
	    }
	    xr_finish_access (pDst->pDrawable, dst_image);
	}
    }
#endif
    return;
}

static void
xr_tristrip (CARD8	    op,
	     PicturePtr	    pSrc,
	     PicturePtr	    pDst,
	     PictFormatPtr    maskFormat,
	     INT16	    xSrc,
	     INT16	    ySrc,
	     int		    npoints,
	     xPointFixed	    *points)
{
    //ErrorF ("fallback: %s\n", __FUNCTION__);
#if 0
    {
	cairo_surface_t *dst_image, *src_image;
	if (xr_prepare_access (pDst->pDrawable, &dst_image)) {
	    if (pSrc->pDrawable == NULL ||
		xr_prepare_access (pSrc->pDrawable, &src_image))
	    {
		fbTriStrip (op, pSrc, pDst,
			     maskFormat,
			     xSrc, ySrc,
			     npoints, points);
		if (pSrc->pDrawable)
		    xr_finish_access (pSrc->pDrawable, src_image);
	    }
	    xr_finish_access (pDst->pDrawable, dst_image);
	}
    }
#endif
}

static void
xr_trifan (CARD8		render_op,
	   PicturePtr	pSrc,
	   PicturePtr	pDst,
	   PictFormatPtr	maskFormat,
	   INT16		xSrc,
	   INT16		ySrc,
	   int		npoints,
	   xPointFixed	*points)
{
    cairo_path_fixed_t path;
    cairo_operator_t op;
    int src_x, src_y;

    if (! _render_operator (render_op, &op))
	goto fallback;

    src_x = xSrc - (points->x >> 16);
    src_y = ySrc - (points->y >> 16);

    _cairo_path_fixed_init (&path);
    points++;
    while (--npoints) {
	if (_cairo_path_fixed_line_to (&path,
				       _cairo_fixed_from_16_16 (points->x),
				       _cairo_fixed_from_16_16 (points->y)))
	{
	    goto err_path;
	}

	points++;
    }
    if (_cairo_path_fixed_close_path (&path))
	goto err_path;

    if (! xr_do_fill (op, pSrc, pDst, src_x, src_y, &path)) {
	_cairo_path_fixed_fini (&path);
	goto fallback;
    }

err_path:
    _cairo_path_fixed_fini (&path);

    return;

fallback:
    //ErrorF ("fallback: %s\n", __FUNCTION__);
#if 0
    {
	cairo_surface_t *dst_image, *src_image;
	if (xr_prepare_access (pDst->pDrawable, &dst_image)) {
	    if (pSrc->pDrawable == NULL ||
		xr_prepare_access (pSrc->pDrawable, &src_image))
	    {
		fbTriFan (op, pSrc, pDst,
			     maskFormat,
			     xSrc, ySrc,
			     npoints, points);
		if (pSrc->pDrawable)
		    xr_finish_access (pSrc->pDrawable, src_image);
	    }
	    xr_finish_access (pDst->pDrawable, dst_image);
	}
    }
#endif
    return;
}

static void
xr_add_triangles (PicturePtr picture,
		  INT16 x_off, INT16 y_off,
		  int ntriangle, xTriangle *triangles)
{
    cairo_path_fixed_t path;
    cairo_clip_t clip;
    cairo_surface_t *surface;
    cairo_status_t status;
    int x, y;

    x = _cairo_fixed_from_int (x_off);
    y = _cairo_fixed_from_int (y_off);

    _cairo_path_fixed_init (&path);
    while (ntriangle--) {
	if (_cairo_path_fixed_move_to (&path,
				       x + _cairo_fixed_from_16_16 (triangles->p1.x),
				       y + _cairo_fixed_from_16_16 (triangles->p1.y)) ||
	    _cairo_path_fixed_line_to (&path,
				       x + _cairo_fixed_from_16_16 (triangles->p2.x),
				       y + _cairo_fixed_from_16_16 (triangles->p2.y)) ||
	    _cairo_path_fixed_line_to (&path,
				       x + _cairo_fixed_from_16_16 (triangles->p3.x),
				       y + _cairo_fixed_from_16_16 (triangles->p3.y)) ||
	    _cairo_path_fixed_close_path (&path))
	{
	    goto err_path;
	}

	triangles++;
    }

    surface = xr_drawable_get_surface (picture->pDrawable);
    xr_picture_get_clip (picture, &clip);
    status = _cairo_surface_fill (surface,
				  CAIRO_OPERATOR_ADD,
				  &_cairo_pattern_white.base,
				  &path,
				  CAIRO_FILL_RULE_WINDING,
				  picture->polyEdge == PolyEdgeSharp ? CAIRO_ANTIALIAS_NONE : CAIRO_ANTIALIAS_DEFAULT,
				  CAIRO_GSTATE_TOLERANCE_DEFAULT,
				  clip.path ? &clip : NULL);
    _cairo_clip_fini (&clip);
    cairo_surface_destroy (surface);

err_path:
    _cairo_path_fixed_fini (&path);
}

static void
xr_add_traps (PicturePtr picture,
	      INT16 x_off, INT16 y_off,
	      int ntrap, xTrap * traps)
{
    cairo_path_fixed_t path;
    cairo_clip_t clip;
    cairo_surface_t *surface;
    cairo_status_t status;
    int x, y;

    x = _cairo_fixed_from_int (x_off);
    y = _cairo_fixed_from_int (y_off);

    _cairo_path_fixed_init (&path);
    while (ntrap--) {
	if (_cairo_path_fixed_move_to (&path,
				       x + _cairo_fixed_from_16_16 (traps->top.l),
				       y + _cairo_fixed_from_16_16 (traps->top.y)) ||
	    _cairo_path_fixed_line_to (&path,
				       x + _cairo_fixed_from_16_16 (traps->top.r),
				       y + _cairo_fixed_from_16_16 (traps->top.y)) ||
	    _cairo_path_fixed_line_to (&path,
				       x + _cairo_fixed_from_16_16 (traps->bot.r),
				       y + _cairo_fixed_from_16_16 (traps->bot.y)) ||
	    _cairo_path_fixed_move_to (&path,
				       x + _cairo_fixed_from_16_16 (traps->bot.l),
				       y + _cairo_fixed_from_16_16 (traps->bot.y)) ||
	    _cairo_path_fixed_close_path (&path))
	{
	    goto err_path;
	}

	traps++;
    }

    surface = xr_drawable_get_surface (picture->pDrawable);
    xr_picture_get_clip (picture, &clip);
    status = _cairo_surface_fill (surface,
				  CAIRO_OPERATOR_ADD,
				  &_cairo_pattern_white.base,
				  &path,
				  CAIRO_FILL_RULE_WINDING,
				  picture->polyEdge == PolyEdgeSharp ? CAIRO_ANTIALIAS_NONE : CAIRO_ANTIALIAS_DEFAULT,
				  CAIRO_GSTATE_TOLERANCE_DEFAULT,
				  clip.path ? &clip : NULL);
    _cairo_clip_fini (&clip);
    cairo_surface_destroy (surface);

err_path:
    _cairo_path_fixed_fini (&path);
}

static Bool
xr_realize_glyph (ScreenPtr screen, GlyphPtr glyph)
{
    return TRUE;
}

static void
xr_unrealize_glyph (ScreenPtr screen, GlyphPtr glyph)
{
}

static PixmapPtr
xr_create_pixmap (ScreenPtr screen,
		  int w, int h, int depth,
		  unsigned usage)
{
    xr_screen_t *xr = xr_get_screen (screen);
    PixmapPtr pixmap;

    if (w > 32767 || h > 32767)
	return NullPixmap;

    if (usage == CREATE_PIXMAP_USAGE_GLYPH_PICTURE)
	return fbCreatePixmap (screen, w, h, depth, usage);

    if (w && h) {
	cairo_surface_t *surface;
	cairo_format_t format;

	format = xr_format_for_depth (depth);
	surface = cairo_drm_surface_create (xr->device, format, w, h);
	if (unlikely (surface->status))
	    goto fallback;

	pixmap = fbCreatePixmap (screen, 0, 0, depth, usage);
	screen->ModifyPixmapHeader (pixmap, w, h, 0, 0,
				    cairo_drm_surface_get_stride (surface),
				    NULL);
	dixSetPrivate (&pixmap->devPrivates, &xr_pixmap_index, surface);
    } else {
fallback:
	pixmap = fbCreatePixmap (screen, w, h, depth, usage);
    }

    return pixmap;
}

static Bool
xr_destroy_pixmap (PixmapPtr pixmap)
{
	if (pixmap->refcnt == 1)
	    cairo_surface_destroy (&xr_pixmap_get_drm_surface (pixmap)->base);

	fbDestroyPixmap(pixmap);
	return TRUE;
}

static Bool
xr_close_screen (int i, ScreenPtr screen)
{
    xr_screen_t *xr = xr_get_screen(screen);

    screen->CreateGC = xr->SavedCreateGC;
    screen->CloseScreen = xr->SavedCloseScreen;
    screen->GetImage = xr->SavedGetImage;
    screen->GetSpans = xr->SavedGetSpans;
    screen->CreatePixmap = xr->SavedCreatePixmap;
    screen->DestroyPixmap = xr->SavedDestroyPixmap;
    screen->CopyWindow = xr->SavedCopyWindow;
    screen->ChangeWindowAttributes =
	xr->SavedChangeWindowAttributes;
    screen->BitmapToRegion = xr->SavedBitmapToRegion;
#ifdef RENDER
    {
	PictureScreenPtr ps = GetPictureScreenIfSet(screen);
	if (ps) {
	    ps->Composite = xr->SavedComposite;
	    ps->Glyphs = xr->SavedGlyphs;
	    ps->CompositeRects = xr->SavedCompositeRects;
	    ps->Trapezoids = xr->SavedTrapezoids;
	    ps->Triangles = xr->SavedTriangles;
	    ps->TriStrip = xr->SavedTriStrip;
	    ps->TriFan = xr->SavedTriFan;
	    ps->AddTriangles = xr->SavedAddTriangles;
	    ps->AddTraps = xr->SavedAddTraps;
	    ps->RealizeGlyph = xr->SavedRealizeGlyph;
	    ps->UnrealizeGlyph = xr->SavedUnrealizeGlyph;
	}
    }
#endif

    cairo_device_destroy (xr->device);
    xfree (xr);

    return screen->CloseScreen (i, screen);
}

static void
xr_block_handler (void *data, OSTimePtr timeout, void *last_select_mask)
{
    xr_screen_t *xr = data;

    cairo_device_flush (xr->device);
    cairo_drm_device_throttle (xr->device);
}

static void
xr_wakeup_handler (void *data, int result, void *last_select_mask)
{
}

xr_screen_t *
cairo_drm_xr_enable (ScreenPtr screen, int fd)
{
    xr_screen_t *xr;
    cairo_device_t *device;

    device = cairo_drm_device_get_for_fd (fd);
    if (device == NULL)
	return NULL;

    xr = malloc (sizeof (*xr));
    if (unlikely (xr == NULL))
	goto cleanup_device;

    xr->device = device;
    dixSetPrivate (&screen->devPrivates,
		   &xr_screen_index,
		   xr);

    if (! dixRequestPrivate(&xr_pixmap_index, 0))
	goto cleanup_driver;

    if (! RegisterBlockAndWakeupHandlers (xr_block_handler,
					  xr_wakeup_handler,
					  xr))
    {
	goto cleanup_driver;
    }

    /* wrap the screen interfaces */
    xr->SavedCloseScreen = screen->CloseScreen;
    screen->CloseScreen = xr_close_screen;

    xr->SavedCreateGC = screen->CreateGC;
    screen->CreateGC = xr_create_gc;

    xr->SavedGetImage = screen->GetImage;
    screen->GetImage = xr_get_image;

    xr->SavedGetSpans = screen->GetSpans;
    screen->GetSpans = xr_get_spans;

    xr->SavedCopyWindow = screen->CopyWindow;
    screen->CopyWindow = xr_copy_window;

    xr->SavedChangeWindowAttributes =
	screen->ChangeWindowAttributes;
    screen->ChangeWindowAttributes = xr_change_window_attributes;

    xr->SavedBitmapToRegion = screen->BitmapToRegion;
    screen->BitmapToRegion = xr_bitmap_to_region;

#ifdef RENDER
    {
	PictureScreenPtr ps = GetPictureScreenIfSet(screen);
	if (ps) {
	    xr->SavedComposite = ps->Composite;
	    ps->Composite = xr_composite;

	    xr->SavedGlyphs = ps->Glyphs;
	    ps->Glyphs = xr_glyphs;

	    xr->SavedCompositeRects = ps->CompositeRects;
	    ps->CompositeRects = xr_composite_rects;

	    xr->SavedTrapezoids = ps->Trapezoids;
	    ps->Trapezoids = xr_trapezoids;

	    xr->SavedTriangles = ps->Triangles;
	    ps->Triangles = xr_triangles;

	    xr->SavedTriStrip = ps->TriStrip;
	    ps->TriStrip = xr_tristrip;

	    xr->SavedTriFan = ps->TriFan;
	    ps->TriFan = xr_trifan;

	    xr->SavedAddTriangles = ps->AddTriangles;
	    ps->AddTriangles = xr_add_triangles;

	    xr->SavedAddTraps = ps->AddTraps;
	    ps->AddTraps = xr_add_traps;

	    xr->SavedRealizeGlyph = ps->RealizeGlyph;
	    ps->RealizeGlyph = xr_realize_glyph;

	    xr->SavedUnrealizeGlyph = ps->UnrealizeGlyph;
	    ps->UnrealizeGlyph = xr_unrealize_glyph;
	}
    }
#endif

#ifdef MITSHM
#if 0
    /* Re-register with the MI funcs, which don't allow shared pixmaps.
     * Shared pixmaps are almost always a performance loss for us, but this
     * still allows for SHM PutImage.
     */
    {
	static ShmFuncs xr_shm_funcs = { NULL, NULL };
	ShmRegisterFuncs (screen, &xr_shm_funcs);
    }
#endif
#endif

    screen->CreatePixmap = xr_create_pixmap;
    screen->DestroyPixmap = xr_destroy_pixmap;

    LogMessage (X_INFO,
		"XR(%d): Driver registered support.\n", screen->myNum);

    return xr;

cleanup_driver:
    free (xr);
cleanup_device:
    cairo_device_destroy (device);
    return NULL;
}

void
cairo_drm_xr_pixmap_link_bo (xr_screen_t *xr,
			     PixmapPtr pixmap,
			     uint32_t name,
			     cairo_format_t format,
			     int width,
			     int height,
			     int stride)
{
    cairo_surface_t *surface;

    cairo_surface_destroy (dixLookupPrivate (&pixmap->devPrivates,
					     &xr_pixmap_index));

    surface = cairo_drm_surface_create_for_name (xr->device, name, format,
						 width, height, stride);
    dixSetPrivate (&pixmap->devPrivates, &xr_pixmap_index, surface);
}

void
cairo_drm_xr_pixmap_unlink_bo (xr_screen_t *xr,
			       PixmapPtr pixmap)
{
    cairo_surface_destroy (dixLookupPrivate (&pixmap->devPrivates,
					     &xr_pixmap_index));

    dixSetPrivate (&pixmap->devPrivates, &xr_pixmap_index, NULL);
}
