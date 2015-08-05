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

#include <cairo-qt.h>

#include <qapplication.h>
#include <X11/Xlib.h>

typedef struct _qt_closure {
    Display *dpy;
    QApplication *app;
} qt_closure_t;

static void
_cairo_boilerplate_qt_cleanup (void *closure)
{
    qt_closure_t *qtc = (qt_closure_t *) closure;

    delete qtc->app;
    XCloseDisplay (qtc->dpy);
    free (qtc);
}

static cairo_surface_t *
_cairo_boilerplate_qt_create_surface (const char		*name,
				      cairo_content_t		 content,
				      double			 width,
				      double			 height,
				      double			 max_width,
				      double			 max_height,
				      cairo_boilerplate_mode_t	 mode,
				      int			 id,
				      void		       **closure)
{
    qt_closure_t *qtc;

    qtc = (qt_closure_t *) xcalloc (1, sizeof (qt_closure_t));
    qtc->dpy = XOpenDisplay (NULL);
    if (qtc->dpy == NULL) {
	free (qtc);
	return NULL;
    }

    if (mode == CAIRO_BOILERPLATE_MODE_TEST)
	XSynchronize (qtc->dpy, True);

    qtc->app = new QApplication (qtc->dpy);
    *closure = qtc;
    return cairo_qt_surface_create_with_qpixmap (content, width, height);
}

static void
_cairo_boilerplate_qt_synchronize (void *closure)
{
    qt_closure_t *qtc = (qt_closure_t *) closure;

    qtc->app->flush (); /* not sure if this is sufficient */
}

static const cairo_boilerplate_target_t targets[] = {
    {
	"qt", "qt", NULL, NULL,
	CAIRO_SURFACE_TYPE_QT, CAIRO_CONTENT_COLOR_ALPHA, 0,
	"cairo_qt_surface_create",
	_cairo_boilerplate_qt_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_qt_cleanup
    },
    {
	"qt", "qt", NULL, NULL,
	CAIRO_SURFACE_TYPE_QT, CAIRO_CONTENT_COLOR, 0,
	"cairo_qt_surface_create",
	_cairo_boilerplate_qt_create_surface,
	NULL, NULL,
	_cairo_boilerplate_get_image_surface,
	cairo_surface_write_to_png,
	_cairo_boilerplate_qt_cleanup
    },
};
extern "C" {
CAIRO_BOILERPLATE (qt, targets)
}
