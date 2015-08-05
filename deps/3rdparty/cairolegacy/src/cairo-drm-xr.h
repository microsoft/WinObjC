/* Cairo - a vector graphics library with display and print output
 *
 * Copyright © 2010 Intel Coropration
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
 * The Initial Developer of the Original Code is Chris Wilson.
 */

#ifndef CAIRO_DRM_XR_H
#define CAIRO_DRM_XR_H

#include "cairo.h"

#if CAIRO_HAS_DRM_XR_FUNCTIONS

CAIRO_BEGIN_DECLS

typedef struct _xr_screen xr_screen_t;

cairo_public xr_screen_t *
cairo_drm_xr_enable (ScreenPtr screen, int fd);

cairo_public void
cairo_drm_xr_pixmap_link_bo (xr_screen_t *xr,
			     PixmapPtr pixmap,
			     uint32_t name,
			     cairo_format_t format,
			     int width,
			     int height,
			     int stride);

cairo_public void
cairo_drm_xr_pixmap_unlink_bo (xr_screen_t *xr,
			       PixmapPtr pixmap);

CAIRO_END_DECLS

#else  /* CAIRO_HAS_DRM_XR_FUNCTIOSN */
# error Cairo was not compiled with support for the DRM Xr DDX functions
#endif /* CAIRO_HAS_DRM_XR_FUNCTIOSN */

#endif /* CAIRO_DRM_XR_H */
