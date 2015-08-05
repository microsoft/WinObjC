/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2009 Intel Corporation
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
 *	Chris Wilson <chris@chris-wilson.co.uk>
 */

#include "cairoint.h"

#include "cairo-xcb-private.h"

#include <xcb/xcbext.h>

xcb_pixmap_t
_cairo_xcb_connection_create_pixmap (cairo_xcb_connection_t *connection,
				     uint8_t depth,
				     xcb_drawable_t drawable,
				     uint16_t width,
				     uint16_t height)
{
    struct {
	uint8_t req;
	uint8_t depth;
	uint16_t len;
	uint32_t pixmap;
	uint32_t drawable;
	uint16_t width, height;
    } req;
    struct iovec vec[1];

    req.req = 53;
    req.depth = depth;
    req.len = sizeof (req) >> 2;

    req.pixmap = _cairo_xcb_connection_get_xid (connection);
    req.drawable = drawable;
    req.width = width;
    req.height = height;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);

    return req.pixmap;
}

void
_cairo_xcb_connection_free_pixmap (cairo_xcb_connection_t *connection,
				   xcb_pixmap_t pixmap)
{
    struct {
	uint8_t req;
	uint8_t pad;
	uint16_t len;
	uint32_t pixmap;
    } req;
    struct iovec vec[1];

    req.req = 54;
    req.len = sizeof (req) >> 2;
    req.pixmap = pixmap;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
    _cairo_xcb_connection_put_xid (connection, pixmap);
}

xcb_gcontext_t
_cairo_xcb_connection_create_gc (cairo_xcb_connection_t *connection,
				 xcb_drawable_t drawable,
				 uint32_t value_mask,
				 uint32_t *values)
{
    struct {
	uint8_t req;
	uint8_t pad;
	uint16_t len;
	uint32_t gc;
	uint32_t drawable;
	uint32_t mask;
    } req;
    struct iovec vec[2];
    int len = _cairo_popcount (value_mask) * 4;

    req.req = 55;
    req.len = (sizeof (req) + len) >> 2;
    req.gc = _cairo_xcb_connection_get_xid (connection);
    req.drawable = drawable;
    req.mask = value_mask;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = values;
    vec[1].iov_len = len;

    _cairo_xcb_connection_write (connection, vec, 2);

    return req.gc;
}

void
_cairo_xcb_connection_free_gc (cairo_xcb_connection_t *connection,
			       xcb_gcontext_t gc)
{
    struct {
	uint8_t req;
	uint8_t pad;
	uint16_t len;
	uint32_t gc;
    } req;
    struct iovec vec[1];

    req.req = 60;
    req.len = sizeof (req) >> 2;
    req.gc = gc;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
    _cairo_xcb_connection_put_xid (connection, gc);
}

void
_cairo_xcb_connection_change_gc (cairo_xcb_connection_t *connection,
				 xcb_gcontext_t gc,
				 uint32_t value_mask,
				 uint32_t *values)
{
    struct {
	uint8_t req;
	uint8_t pad;
	uint16_t len;
	uint32_t gc;
	uint32_t mask;
    } req;
    struct iovec vec[2];
    int len = _cairo_popcount (value_mask) * 4;

    req.req = 56;
    req.len = (sizeof (req) + len) >> 2;
    req.gc = gc;
    req.mask = value_mask;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = values;
    vec[1].iov_len = len;

    _cairo_xcb_connection_write (connection, vec, 2);
}

void
_cairo_xcb_connection_copy_area (cairo_xcb_connection_t *connection,
				 xcb_drawable_t src,
				 xcb_drawable_t dst,
				 xcb_gcontext_t gc,
				 int16_t src_x,
				 int16_t src_y,
				 int16_t dst_x,
				 int16_t dst_y,
				 uint16_t width,
				 uint16_t height)
{
    struct {
	uint8_t req;
	uint8_t pad;
	uint16_t len;
	uint32_t src;
	uint32_t dst;
	uint32_t gc;
	int16_t src_x;
	int16_t src_y;
	int16_t dst_x;
	int16_t dst_y;
	uint16_t width;
	uint16_t height;
    } req;
    struct iovec vec[1];

    req.req = 62;
    req.len = sizeof (req) >> 2;
    req.src = src;
    req.dst = dst;
    req.gc = gc;
    req.src_x = src_x;
    req.src_y = src_y;
    req.dst_x = dst_x;
    req.dst_y = dst_y;
    req.width = width;
    req.height = height;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
}

void
_cairo_xcb_connection_poly_fill_rectangle (cairo_xcb_connection_t *connection,
					   xcb_drawable_t dst,
					   xcb_gcontext_t gc,
					   uint32_t num_rectangles,
					   xcb_rectangle_t *rectangles)
{
    struct {
	uint8_t req;
	uint8_t pad;
	uint16_t len;
	uint32_t dst;
	uint32_t gc;
    } req;
    struct iovec vec[2];

    req.req = 70;
    req.len = (sizeof (req) + num_rectangles * sizeof (xcb_rectangle_t)) >> 2;
    req.dst = dst;
    req.gc = gc;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = rectangles;
    vec[1].iov_len = num_rectangles * sizeof (xcb_rectangle_t);

    _cairo_xcb_connection_write (connection, vec, 2);
}

void
_cairo_xcb_connection_put_image (cairo_xcb_connection_t *connection,
				 xcb_drawable_t dst,
				 xcb_gcontext_t gc,
				 uint16_t width,
				 uint16_t height,
				 int16_t dst_x,
				 int16_t dst_y,
				 uint8_t depth,
				 uint32_t stride,
				 void *data)
{
    struct {
	uint8_t req;
	uint8_t format;
	uint16_t len;
	uint32_t dst;
	uint32_t gc;
	uint16_t width;
	uint16_t height;
	int16_t dst_x;
	int16_t dst_y;
	uint8_t left;
	uint8_t depth;
	uint16_t pad;
    } req;
    struct iovec vec[3];
    uint32_t prefix[2];
    uint32_t length = height * stride;
    uint32_t len = (sizeof (req) + length) >> 2;

    req.req = 72;
    req.format = XCB_IMAGE_FORMAT_Z_PIXMAP;
    req.len = 0;
    req.dst = dst;
    req.gc = gc;
    req.width = width;
    req.height = height;
    req.dst_x = dst_x;
    req.dst_y = dst_y;
    req.left = 0;
    req.depth = depth;

    if (len < connection->root->maximum_request_length) {
	req.len = len;

	vec[0].iov_base = &req;
	vec[0].iov_len = sizeof (req);
	vec[1].iov_base = data;
	vec[1].iov_len = length;

	_cairo_xcb_connection_write (connection, vec, 2);
    } else if (len < connection->maximum_request_length) {
	prefix[0] = *(uint32_t *) &req;
	prefix[1] = len + 1;
	vec[0].iov_base = prefix;
	vec[0].iov_len = sizeof (prefix);
	vec[1].iov_base = (uint32_t *) &req + 1;
	vec[1].iov_len = sizeof (req) - 4;
	vec[2].iov_base = data;
	vec[2].iov_len = length;

	_cairo_xcb_connection_write (connection, vec, 3);
    } else {
	int rows;

	rows = (connection->maximum_request_length - sizeof (req) - 4) / stride;
	if (rows > 0) {
	    do {
		if (rows > height)
		    rows = height;

		length = rows * stride;
		len = (sizeof (req) + 4 + length) >> 2;

		req.height = rows;

		prefix[0] = *(uint32_t *) &req;
		prefix[1] = len;

		vec[0].iov_base = prefix;
		vec[0].iov_len = sizeof (prefix);
		vec[1].iov_base = (uint32_t *) &req + 1;
		vec[1].iov_len = sizeof (req) - 4;
		vec[2].iov_base = data;
		vec[2].iov_len = length;

		/* note may modify vec */
		_cairo_xcb_connection_write (connection, vec, 3);

		height -= rows;
		req.dst_y += rows;
		data = (char *) data + length;
	    } while (height);
	} else {
	    ASSERT_NOT_REACHED;
	}
    }
}

void
_cairo_xcb_connection_put_subimage (cairo_xcb_connection_t *connection,
				    xcb_drawable_t dst,
				    xcb_gcontext_t gc,
				    int16_t src_x,
				    int16_t src_y,
				    uint16_t width,
				    uint16_t height,
				    uint16_t cpp,
				    uint16_t stride,
				    int16_t dst_x,
				    int16_t dst_y,
				    uint8_t depth,
				    void *_data)
{
    struct {
	uint8_t req;
	uint8_t format;
	uint16_t len;
	uint32_t dst;
	uint32_t gc;
	uint16_t width;
	uint16_t height;
	int16_t dst_x;
	int16_t dst_y;
	uint8_t left;
	uint8_t depth;
	uint16_t pad;
    } req;
    struct iovec vec_stack[CAIRO_STACK_ARRAY_LENGTH (struct iovec)];
    struct iovec *vec = vec_stack;
    uint32_t prefix[2];
    uint32_t len = (sizeof (req) + cpp*width*height) >> 2;
    uint8_t *data = _data;
    int n;

    req.req = 72;
    req.format = XCB_IMAGE_FORMAT_Z_PIXMAP;
    req.len = 0;
    req.dst = dst;
    req.gc = gc;
    req.width = width;
    req.height = height;
    req.dst_x = dst_x;
    req.dst_y = dst_y;
    req.left = 0;
    req.depth = depth;

    if (height + 2 > ARRAY_LENGTH (vec_stack)) {
	vec = _cairo_malloc_ab (height+2, sizeof (struct iovec));
	if (unlikely (vec == NULL)) {
	    /* XXX loop over ARRAY_LENGTH (vec_stack) */
	    return;
	}
    }

    data += src_y * stride + src_x * cpp;
    if (len < connection->root->maximum_request_length) {
	req.len = len;

	vec[0].iov_base = &req;
	vec[0].iov_len = sizeof (req);

	n = 1;
    } else if (len < connection->maximum_request_length) {
	prefix[0] = *(uint32_t *) &req;
	prefix[1] = len + 1;
	vec[0].iov_base = prefix;
	vec[0].iov_len = sizeof (prefix);
	vec[1].iov_base = (uint32_t *) &req + 1;
	vec[1].iov_len = sizeof (req) - 4;

	n = 2;
    } else {
	ASSERT_NOT_REACHED;
    }

    while (height--) {
	vec[n].iov_base = data;
	vec[n].iov_len = cpp * width;
	data += stride;
	n++;
    }

    _cairo_xcb_connection_write (connection, vec, n);

    if (vec != vec_stack)
	free (vec);
}

cairo_status_t
_cairo_xcb_connection_get_image (cairo_xcb_connection_t *connection,
				 xcb_drawable_t src,
				 int16_t src_x,
				 int16_t src_y,
				 uint16_t width,
				 uint16_t height,
				 xcb_get_image_reply_t **reply)
{
    xcb_generic_error_t *error;
    cairo_status_t status;

    *reply = xcb_get_image_reply (connection->xcb_connection,
				  xcb_get_image (connection->xcb_connection,
						 XCB_IMAGE_FORMAT_Z_PIXMAP,
						 src,
						 src_x, src_y,
						 width, height,
						 (uint32_t) -1),

				  &error);
    if (error) {
	free (error);

	if (*reply)
	    free (*reply);
	*reply = NULL;
    }

    status = _cairo_xcb_connection_take_socket (connection);
    if (unlikely (status)) {
	if (*reply)
	    free (*reply);
	*reply = NULL;
    }

    return status;
}
