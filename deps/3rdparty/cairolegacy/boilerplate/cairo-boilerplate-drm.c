/* Cairo - a vector graphics library with display and print output
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
 * The Initial Developer of the Original Code is Chris Wilson.
 */

#include "cairo-boilerplate-private.h"

#include <cairo-drm.h>

static cairo_surface_t *
_cairo_boilerplate_drm_create_surface (const char		 *name,
				       cairo_content_t		  content,
				       double			  width,
				       double			  height,
				       double			  max_width,
				       double			  max_height,
				       cairo_boilerplate_mode_t   mode,
				       int			  id,
				       void			**closure)
{
    cairo_device_t *device;
    cairo_format_t format;

    device = cairo_drm_device_default ();
    if (device == NULL)
	return NULL; /* skip tests if no supported h/w found */

    switch (content) {
    case CAIRO_CONTENT_ALPHA: format = CAIRO_FORMAT_A8; break;
    case CAIRO_CONTENT_COLOR: format = CAIRO_FORMAT_RGB24; break;
    default:
    case CAIRO_CONTENT_COLOR_ALPHA: format = CAIRO_FORMAT_ARGB32; break;
    }

    return *closure = cairo_drm_surface_create (device, format, width, height);
}

static void
_cairo_boilerplate_drm_synchronize (void *closure)
{
    cairo_surface_t *image;

    image = cairo_drm_surface_map_to_image (closure);
    if (cairo_surface_status (image) == CAIRO_STATUS_SUCCESS)
	cairo_drm_surface_unmap (closure, image);
}

static const cairo_boilerplate_target_t targets[] = {
    /* Acceleration architectures may make the results differ by a
     * bit, so we set the error tolerance to 1. */
    {
	"drm", "drm", NULL, NULL,
	CAIRO_SURFACE_TYPE_DRM, CAIRO_CONTENT_COLOR_ALPHA, 1,
	"cairo_drm_surface_create",
	_cairo_boilerplate_drm_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	NULL,
	_cairo_boilerplate_drm_synchronize,
        NULL,
	TRUE, FALSE, FALSE
    },
    {
	"drm", "drm", NULL, NULL,
	CAIRO_SURFACE_TYPE_DRM, CAIRO_CONTENT_COLOR, 1,
	"cairo_drm_surface_create",
	_cairo_boilerplate_drm_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	NULL,
	_cairo_boilerplate_drm_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
};
CAIRO_BOILERPLATE (drm, targets)
