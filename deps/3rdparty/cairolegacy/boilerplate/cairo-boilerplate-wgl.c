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
 * The Initial Developer of the Original Code is Chris Wilson.
 *
 * Contributor(s):
 *	Zoxc <zoxc32@gmail.com>
 */

#include "cairo-boilerplate-private.h"

#include <cairo-gl.h>

static const cairo_user_data_key_t gl_closure_key;

typedef struct _wgl_target_closure {
    HWND wnd;
    HDC dc;
    HGLRC rc;
    cairo_device_t *device;
    cairo_surface_t *surface;
} wgl_target_closure_t;

static void
_cairo_boilerplate_wgl_cleanup (void *closure)
{
    wgl_target_closure_t *wgltc = closure;

    cairo_device_finish (wgltc->device);
    cairo_device_destroy (wgltc->device);

    wglDeleteContext(wgltc->rc);

    ReleaseDC(wgltc->wnd, wgltc->dc);
    DestroyWindow (wgltc->wnd);

    free (wgltc);
}

static void
_cairo_boilerplate_wgl_create_window (int		    width,
				      int		    height,
				      wgl_target_closure_t *wgltc)
{
    WNDCLASSEXA wincl;
    PIXELFORMATDESCRIPTOR pfd;
    int format;
    cairo_surface_t *surface;
    
    ZeroMemory (&wincl, sizeof (WNDCLASSEXA));
    wincl.cbSize = sizeof (WNDCLASSEXA);
    wincl.hInstance = GetModuleHandle (0);
    wincl.lpszClassName = "cairo_boilerplate_wgl_dummy";
    wincl.lpfnWndProc = DefWindowProcA;
    wincl.style = CS_OWNDC;

    RegisterClassExA (&wincl);
    
    wgltc->wnd = CreateWindow ("cairo_boilerplate_wgl_dummy", 0, WS_POPUP, 0, 0, width, height, 0, 0, 0, 0);
    wgltc->dc = GetDC (wgltc->wnd);

    ZeroMemory (&pfd, sizeof (PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof (PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    format = ChoosePixelFormat (wgltc->dc, &pfd);
    SetPixelFormat (wgltc->dc, format, &pfd);
    
    wgltc->rc = wglCreateContext (wgltc->dc);
    wgltc->device = cairo_wgl_device_create (wgltc->rc);
}

static cairo_surface_t *
_cairo_boilerplate_wgl_create_surface (const char		 *name,
				       cairo_content_t		  content,
				       double			  width,
				       double			  height,
				       double			  max_width,
				       double			  max_height,
				       cairo_boilerplate_mode_t   mode,
				       int			  id,
				       void			**closure)
{
    wgl_target_closure_t *wgltc;
    cairo_surface_t *surface;
    
    wgltc = calloc (1, sizeof (wgl_target_closure_t));
    
    *closure = wgltc;

    _cairo_boilerplate_wgl_create_window(0, 0, wgltc);
    
    if (width == 0)
	width = 1;
    if (height == 0)
	height = 1;
    
    wgltc->surface = surface = cairo_gl_surface_create (wgltc->device,
						       content,
						       ceil (width),
						       ceil (height));
    if (cairo_surface_status (surface)) {
	_cairo_boilerplate_wgl_cleanup (wgltc);
	return NULL;
    }

    return surface;
}

static cairo_surface_t *
_cairo_boilerplate_wgl_for_create_window (const char		    *name,
					  cairo_content_t	     content,
					  double		     width,
					  double		     height,
					  double		     max_width,
					  double		     max_height,
					  cairo_boilerplate_mode_t   mode,
					  int			     id,
					  void			   **closure)
{
    wgl_target_closure_t *wgltc;
    cairo_surface_t *surface;
    
    wgltc = calloc (1, sizeof (wgl_target_closure_t));
    
    *closure = wgltc;

     _cairo_boilerplate_wgl_create_window(width, height, wgltc);
    
    wgltc->surface = surface = cairo_gl_surface_create_for_dc (wgltc->device,
						       wgltc->dc,
						       ceil (width),
						       ceil (height));
    
    if (cairo_surface_status (surface)) {
	_cairo_boilerplate_wgl_cleanup (wgltc);
	return NULL;
    }

    return surface;
}

static cairo_status_t
_cairo_boilerplate_wgl_finish_window (cairo_surface_t *surface)
{
    wgl_target_closure_t *wgltc = cairo_surface_get_user_data (surface,
							     &gl_closure_key);

    if (wgltc != NULL && wgltc->surface != NULL) {
	cairo_t *cr;

	cr = cairo_create (wgltc->surface);
	cairo_surface_set_device_offset (surface, 0, 0);
	cairo_set_source_surface (cr, surface, 0, 0);
	cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
	cairo_paint (cr);
	cairo_destroy (cr);

	surface = wgltc->surface;
    }

    cairo_gl_surface_swapbuffers (surface);
    return CAIRO_STATUS_SUCCESS;
}

static void
_cairo_boilerplate_wgl_synchronize (void *closure)
{
    wgl_target_closure_t *wgltc = closure;

    if (cairo_device_acquire (wgltc->device))
	return;

    glFinish ();

    cairo_device_release (wgltc->device);
}

static const cairo_boilerplate_target_t targets[] = {
    {
	"gl", "gl", NULL, NULL,
	CAIRO_SURFACE_TYPE_GL, CAIRO_CONTENT_COLOR_ALPHA, 1,
	"cairo_gl_surface_create",
	_cairo_boilerplate_wgl_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_wgl_cleanup,
	_cairo_boilerplate_wgl_synchronize,
        NULL,
	TRUE, FALSE, FALSE
    },
    {
	"gl-dc", "gl", NULL, NULL,
	CAIRO_SURFACE_TYPE_GL, CAIRO_CONTENT_COLOR_ALPHA, 1,
	"cairo_gl_surface_create_for_dc",
	_cairo_boilerplate_wgl_for_create_window,
	NULL,
	_cairo_boilerplate_wgl_finish_window,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_wgl_cleanup,
	_cairo_boilerplate_wgl_synchronize,
        NULL,
	FALSE, FALSE, FALSE
    },
};

CAIRO_BOILERPLATE (wgl, targets)
