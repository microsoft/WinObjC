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

#include <cairo-vg.h>

 /* XXX Not sure how to handle library specific context initialization */
//#define USE_SHIVA
//#define USE_AMANITH

#if CAIRO_HAS_GLX_FUNCTIONS

#include <X11/Xlib.h>
#include <GL/glx.h>

typedef struct _vg_closure {
    Display *dpy;
    int screen;
    Window win;

    GLXContext ctx;
    cairo_surface_t *surface;
} vg_closure_glx_t;

static void
_cairo_boilerplate_vg_cleanup_glx (void *closure)
{
    vg_closure_glx_t *vgc = closure;

#ifdef USE_AMANITH
    vgDestroyContextAM ();
#endif
#ifdef USE_SHIVA
    vgDestroyContextSH ();
#endif

    glXDestroyContext (vgc->dpy, vgc->ctx);
    XDestroyWindow (vgc->dpy, vgc->win);
    XCloseDisplay (vgc->dpy);
    free (vgc);
}

static cairo_surface_t *
_cairo_boilerplate_vg_create_surface_glx (const char		    *name,
					  cairo_content_t	     content,
					  double		     width,
					  double		     height,
					  double		     max_width,
					  double		     max_height,
					  cairo_boilerplate_mode_t   mode,
					  int			     id,
					  void			   **closure)
{
    int rgba_attribs[] = {
	GLX_RGBA,
	GLX_RED_SIZE, 1,
	GLX_GREEN_SIZE, 1,
	GLX_BLUE_SIZE, 1,
	GLX_ALPHA_SIZE, 1,
	GLX_DOUBLEBUFFER,
	None
    };
    int rgb_attribs[] = {
	GLX_RGBA,
	GLX_RED_SIZE, 1,
	GLX_GREEN_SIZE, 1,
	GLX_BLUE_SIZE, 1,
	GLX_DOUBLEBUFFER,
	None
    };
    XVisualInfo *vi;
    Display *dpy;
    Colormap cmap;
    XSetWindowAttributes swa;
    cairo_surface_t *surface;
    cairo_vg_context_t *context;
    vg_closure_glx_t *vgc;

    vgc = malloc (sizeof (vg_closure_glx_t));
    *closure = vgc;

    if (width == 0)
	width = 1;
    if (height == 0)
	height = 1;

    dpy = XOpenDisplay (NULL);
    vgc->dpy = dpy;
    if (vgc->dpy == NULL) {
	fprintf (stderr, "Failed to open display: %s\n", XDisplayName(0));
	free (vgc);
	return NULL;
    }

    if (content == CAIRO_CONTENT_COLOR)
	vi = glXChooseVisual (dpy, DefaultScreen (dpy), rgb_attribs);
    else
	vi = glXChooseVisual (dpy, DefaultScreen (dpy), rgba_attribs);

    if (vi == NULL) {
	fprintf (stderr, "Failed to create RGB, double-buffered visual\n");
	XCloseDisplay (dpy);
	free (vgc);
	return NULL;
    }

    vgc->ctx = glXCreateContext (dpy, vi, NULL, True);
    cmap = XCreateColormap (dpy,
			    RootWindow (dpy, vi->screen),
			    vi->visual,
			    AllocNone);
    swa.colormap = cmap;
    swa.border_pixel = 0;
    vgc->win = XCreateWindow (dpy, RootWindow (dpy, vi->screen),
			      -1, -1, 1, 1, 0,
			      vi->depth,
			      InputOutput,
			      vi->visual,
			      CWBorderPixel | CWColormap, &swa);
    XFreeColormap (dpy, cmap);
    XFree (vi);

    XMapWindow (dpy, vgc->win);

    /* we need an active context to initialise VG */
    glXMakeContextCurrent (dpy, vgc->win, vgc->win, vgc->ctx);

#ifdef USE_AMANITH
    vgInitContextAM (width, height, VG_FALSE, VG_TRUE);
#endif
#ifdef USE_SHIVA
    vgCreateContextSH (width, height);
#endif

    context = cairo_vg_context_create_for_glx (dpy, vgc->ctx);
    vgc->surface = cairo_vg_surface_create (context, content, width, height);
    cairo_vg_context_destroy (context);

    surface = vgc->surface;
    if (cairo_surface_status (surface))
	_cairo_boilerplate_vg_cleanup_glx (vgc);

    return surface;
}
#endif

#if CAIRO_HAS_EGL_FUNCTIONS
typedef struct _vg_closure_egl {
    EGLDisplay *dpy;
    EGLContext *ctx;
    EGLSurface *dummy;
} vg_closure_egl_t;

static void
_cairo_boilerplate_vg_cleanup_egl (void *closure)
{
    vg_closure_egl_t *vgc = closure;

#ifdef USE_AMANITH
    vgDestroyContextAM ();
#endif
#ifdef USE_SHIVA
    vgDestroyContextSH ();
#endif

    eglDestroyContext (vgc->dpy, vgc->ctx);
    eglDestroySurface (vgc->dpy, vgc->dummy);
    eglTerminate (vgc->dpy);
    free (vgc);
}

static cairo_surface_t *
_cairo_boilerplate_vg_create_surface_egl (const char		    *name,
					  cairo_content_t	     content,
					  double		     width,
					  double		     height,
					  double		     max_width,
					  double		     max_height,
					  cairo_boilerplate_mode_t   mode,
					  int			     id,
					  void			   **closure)
{
    int rgba_attribs[] = {
	EGL_RED_SIZE, 8,
	EGL_GREEN_SIZE, 8,
	EGL_BLUE_SIZE, 8,
	EGL_ALPHA_SIZE, 8,
	EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
	EGL_RENDERABLE_TYPE, EGL_OPENVG_BIT,
	None
    };
    int rgb_attribs[] = {
	EGL_RED_SIZE, 8,
	EGL_GREEN_SIZE, 8,
	EGL_BLUE_SIZE, 8,
	EGL_ALPHA_SIZE, 8,
	EGL_VG_ALPHA_FORMAT, EGL_VG_ALPHA_FORMAT_PRE_BIT,
	EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
	EGL_RENDERABLE_TYPE, EGL_OPENVG_BIT,
	None
    };
    int dummy_attribs[] = {
	EGL_WIDTH, 8, EGL_HEIGHT, 8,
	EGL_NONE
    };
    EGLDisplay *dpy;
    int major, minor;
    EGLConfig config;
    int num_configs;
    EGLContext *egl_context;
    EGLSurface *dummy;
    cairo_vg_context_t *context;
    cairo_surface_t *surface;
    vg_closure_egl_t *vgc;

    dpy = eglGetDisplay (EGL_DEFAULT_DISPLAY);

    if (! eglInitialize (dpy, &major, &minor))
	return NULL;

    eglBindAPI (EGL_OPENVG_API);

    if (! eglChooseConfig (dpy,
			   content == CAIRO_CONTENT_COLOR_ALPHA ?
			   rgba_attribs : rgb_attribs,
			   &config, 1, &num_configs) ||
	num_configs != 1)
    {
	return NULL;
    }

    egl_context = eglCreateContext (dpy, config, NULL, NULL);
    if (egl_context == NULL)
	return NULL;

    /* Create a dummy surface in order to enable a context to initialise VG */
    dummy = eglCreatePbufferSurface (dpy, config, dummy_attribs);
    if (dummy == NULL)
	return NULL;
    if (! eglMakeCurrent (dpy, dummy, dummy, egl_context))
	return NULL;

#ifdef USE_AMANITH
    vgInitContextAM (width, height, VG_FALSE, VG_TRUE);
#endif
#ifdef USE_SHIVA
    vgCreateContextSH (width, height);
#endif

    vgc = xmalloc (sizeof (vg_closure_egl_t));
    vgc->dpy = dpy;
    vgc->ctx = egl_context;
    vgc->dummy = dummy;
    *closure = vgc;

    context = cairo_vg_context_create_for_egl (vgc->dpy, vgc->ctx);
    surface = cairo_vg_surface_create (context, content, width, height);
    cairo_vg_context_destroy (context);

    if (cairo_surface_status (surface))
	_cairo_boilerplate_vg_cleanup_egl (vgc);

    return surface;
}
#endif

static void
_cairo_boilerplate_vg_synchronize (void *closure)
{
    vgFinish ();
}

static const cairo_boilerplate_target_t targets[] = {
#if CAIRO_HAS_GLX_FUNCTIONS
    {
	"vg-glx", "vg", NULL, NULL,
	CAIRO_SURFACE_TYPE_VG, CAIRO_CONTENT_COLOR_ALPHA, 1,
	"cairo_vg_context_create_for_glx",
	_cairo_boilerplate_vg_create_surface_glx,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_vg_cleanup_glx,
	_cairo_boilerplate_vg_synchronize,
        NULL,
	TRUE, FALSE, FALSE
    },
    {
	"vg-glx", "vg", NULL, NULL,
	CAIRO_SURFACE_TYPE_VG, CAIRO_CONTENT_COLOR, 1,
	"cairo_vg_context_create_for_glx",
	_cairo_boilerplate_vg_create_surface_glx,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_vg_cleanup_glx,
	_cairo_boilerplate_vg_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
#endif
#if CAIRO_HAS_EGL_FUNCTIONS
    {
	"vg-egl", "vg", NULL, NULL,
	CAIRO_SURFACE_TYPE_VG, CAIRO_CONTENT_COLOR_ALPHA, 1,
	"cairo_vg_context_create_for_egl",
	_cairo_boilerplate_vg_create_surface_egl,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_vg_cleanup_egl,
	_cairo_boilerplate_vg_synchronize,
        NULL,
	TRUE, FALSE, FALSE
    },
    {
	"vg-egl", "vg", NULL, NULL,
	CAIRO_SURFACE_TYPE_VG, CAIRO_CONTENT_COLOR, 1,
	"cairo_vg_context_create_for_egl",
	_cairo_boilerplate_vg_create_surface_egl,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_vg_cleanup_egl,
	_cairo_boilerplate_vg_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
#endif
};
CAIRO_BOILERPLATE (vg, targets)
