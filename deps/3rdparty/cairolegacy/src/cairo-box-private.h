/* -*- Mode: c; tab-width: 8; c-basic-offset: 4; indent-tabs-mode: t; -*- */
/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2010 Andrea Canciani
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
 * Contributor(s):
 *	Andrea Canciani <ranma42@gmail.com>
 */

#ifndef CAIRO_BOX_H
#define CAIRO_BOX_H

#include "cairo-types-private.h"
#include "cairo-compiler-private.h"

static inline void
_cairo_box_set (cairo_box_t *box,
		const cairo_point_t *p1,
		const cairo_point_t *p2)
{
    box->p1 = *p1;
    box->p2 = *p2;
}

/* assumes box->p1 is top-left, p2 bottom-right */
static inline void
_cairo_box_add_point (cairo_box_t *box,
		      const cairo_point_t *point)
{
    if (point->x < box->p1.x)
	box->p1.x = point->x;
    else if (point->x > box->p2.x)
	box->p2.x = point->x;

    if (point->y < box->p1.y)
	box->p1.y = point->y;
    else if (point->y > box->p2.y)
	box->p2.y = point->y;
}

/* assumes box->p1 is top-left, p2 bottom-right */
static inline cairo_bool_t
_cairo_box_contains_point (cairo_box_t *box,
			   const cairo_point_t *point)
{
    return box->p1.x <= point->x  && point->x <= box->p2.x &&
	box->p1.y <= point->y  && point->y <= box->p2.y;
}

#endif /* CAIRO_BOX_H */
