/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2010 Linaro Limited
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
 *      Alexandros Frantzis <alexandros.frantzis@linaro.org>
 */

#include "cairoint.h"
#include "cairo-gl-private.h"
#include "cairo-gl-dispatch-private.h"

static void
_cairo_gl_dispatch_init_entries (cairo_gl_dispatch_t *dispatch,
				 cairo_gl_get_proc_addr_func_t get_proc_addr,
				 cairo_gl_dispatch_entry_t *entries,
				 cairo_bool_t use_ext)
{
    cairo_gl_dispatch_entry_t *entry = entries;

    while (entry->name_core != NULL) {
	void *dispatch_ptr = &((char *) dispatch)[entry->offset];
	const char *name = use_ext ? entry->name_ext :
				     entry->name_core;

	cairo_gl_generic_func_t func = get_proc_addr (name);

	*((cairo_gl_generic_func_t *) dispatch_ptr) = func;

	++entry;
    }

}

static cairo_status_t
_cairo_gl_dispatch_init_buffers (cairo_gl_dispatch_t *dispatch,
				 cairo_gl_get_proc_addr_func_t get_proc_addr,
				 int gl_version)
{
    cairo_bool_t use_ext;

    if (gl_version >= CAIRO_GL_VERSION_ENCODE (1, 5))
	use_ext = 0;
    else if (_cairo_gl_has_extension ("GL_ARB_vertex_buffer_object"))
	use_ext = 1;
    else
	return CAIRO_STATUS_DEVICE_ERROR;

    _cairo_gl_dispatch_init_entries (dispatch, get_proc_addr,
				     dispatch_buffers_entries, use_ext);

    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_cairo_gl_dispatch_init_shaders (cairo_gl_dispatch_t *dispatch,
				 cairo_gl_get_proc_addr_func_t get_proc_addr,
				 int gl_version)
{
    cairo_bool_t use_ext;

    /* Note: shader support is not necessary at the moment */
    if (gl_version >= CAIRO_GL_VERSION_ENCODE (2, 0))
	use_ext = 0;
    else if (_cairo_gl_has_extension ("GL_ARB_shader_objects"))
	use_ext = 1;
    else
	return CAIRO_STATUS_SUCCESS;

    _cairo_gl_dispatch_init_entries (dispatch, get_proc_addr,
				     dispatch_shaders_entries, use_ext);

    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_cairo_gl_dispatch_init_fbo (cairo_gl_dispatch_t *dispatch,
			     cairo_gl_get_proc_addr_func_t get_proc_addr,
			     int gl_version)
{
    cairo_bool_t use_ext;

    if (gl_version >= CAIRO_GL_VERSION_ENCODE (3, 0) ||
	_cairo_gl_has_extension ("GL_ARB_framebuffer_object"))
	use_ext = 0;
    else if (_cairo_gl_has_extension ("GL_EXT_framebuffer_object"))
	use_ext = 1;
    else
	return CAIRO_STATUS_DEVICE_ERROR;

    _cairo_gl_dispatch_init_entries (dispatch, get_proc_addr,
				     dispatch_fbo_entries, use_ext);

    return CAIRO_STATUS_SUCCESS;
}

cairo_status_t
_cairo_gl_dispatch_init (cairo_gl_dispatch_t *dispatch,
			 cairo_gl_get_proc_addr_func_t get_proc_addr)
{
    cairo_status_t status;
    int gl_version;

    gl_version = _cairo_gl_get_version ();

    status = _cairo_gl_dispatch_init_buffers (dispatch, get_proc_addr,
					      gl_version);
    if (status != CAIRO_STATUS_SUCCESS)
	return status;

    status = _cairo_gl_dispatch_init_shaders (dispatch, get_proc_addr,
					      gl_version);
    if (status != CAIRO_STATUS_SUCCESS)
	return status;

    status = _cairo_gl_dispatch_init_fbo (dispatch, get_proc_addr,
					  gl_version);
    if (status != CAIRO_STATUS_SUCCESS)
	return status;

    return CAIRO_STATUS_SUCCESS;
}
