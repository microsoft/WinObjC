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

#include <cairo-gl.h>

static const cairo_user_data_key_t gl_closure_key;

typedef struct _egl_target_closure {
    EGLDisplay dpy;
    EGLContext ctx;

    cairo_device_t *device;
    cairo_surface_t *surface;
} egl_target_closure_t;

static void
_cairo_boilerplate_egl_cleanup (void *closure)
{
    egl_target_closure_t *gltc = closure;

    cairo_device_finish (gltc->device);
    cairo_device_destroy (gltc->device);

    eglDestroyContext (gltc->dpy, gltc->ctx);
    eglMakeCurrent (gltc->dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglTerminate (gltc->dpy);

    free (gltc);
}

static cairo_surface_t *
_cairo_boilerplate_egl_create_surface (const char		 *name,
				       cairo_content_t		  content,
				       double			  width,
				       double			  height,
				       double			  max_width,
				       double			  max_height,
				       cairo_boilerplate_mode_t   mode,
				       int			  id,
				       void			**closure)
{
    egl_target_closure_t *gltc;
    cairo_surface_t *surface;
    int major, minor;
    EGLConfig *configs;
    EGLint numConfigs;

    gltc = xcalloc (1, sizeof (egl_target_closure_t));
    *closure = gltc;

    gltc->dpy = eglGetDisplay (EGL_DEFAULT_DISPLAY);

    if (! eglInitialize (gltc->dpy, &major, &minor)) {
	free (gltc);
	return NULL;
    }

    eglGetConfigs (gltc->dpy, NULL, 0, &numConfigs);
    if (numConfigs == 0) {
	free (gltc);
	return NULL;
    }
    configs = xmalloc(sizeof(*configs) *numConfigs);
    eglGetConfigs (gltc->dpy, configs, numConfigs, &numConfigs);

    eglBindAPI (EGL_OPENGL_API);

    gltc->ctx = eglCreateContext (gltc->dpy, configs[0], EGL_NO_CONTEXT, NULL);
    if (gltc->ctx == EGL_NO_CONTEXT) {
	eglTerminate (gltc->dpy);
	free (gltc);
	return NULL;
    }

    gltc->device = cairo_egl_device_create (gltc->dpy, gltc->ctx);

    gltc->surface = surface = cairo_gl_surface_create (gltc->device,
						       content,
						       ceil (width),
						       ceil (height));
    if (cairo_surface_status (surface))
	_cairo_boilerplate_egl_cleanup (gltc);

    return surface;
}

static void
_cairo_boilerplate_egl_synchronize (void *closure)
{
    egl_target_closure_t *gltc = closure;

    if (cairo_device_acquire (gltc->device))
	return;

    glFinish ();

    cairo_device_release (gltc->device);
}

static const cairo_boilerplate_target_t targets[] = {
    {
	"egl", "gl", NULL, NULL,
	CAIRO_SURFACE_TYPE_GL, CAIRO_CONTENT_COLOR_ALPHA, 1,
	"cairo_egl_device_create",
	_cairo_boilerplate_egl_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_egl_cleanup,
	_cairo_boilerplate_egl_synchronize,
        NULL,
	TRUE, FALSE, FALSE
    }
};
CAIRO_BOILERPLATE (egl, targets)
