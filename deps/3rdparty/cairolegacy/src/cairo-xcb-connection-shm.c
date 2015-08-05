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
#include <xcb/shm.h>

uint32_t
_cairo_xcb_connection_shm_attach (cairo_xcb_connection_t *connection,
				  uint32_t id,
				  cairo_bool_t readonly)
{
    struct {
	uint8_t req;
	uint8_t shm_req;
	uint16_t length;
	uint32_t segment;
	uint32_t id;
	uint8_t readonly;
	uint8_t pad1;
	uint16_t pad2;
    } req;
    struct iovec vec[1];

    COMPILE_TIME_ASSERT (sizeof (req) == 16);

    req.req = connection->shm->major_opcode;
    req.shm_req = 1;
    req.length = sizeof (req) >> 2;
    req.segment = _cairo_xcb_connection_get_xid (connection);
    req.id = id;
    req.readonly = readonly;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
    return req.segment;
}

uint64_t
_cairo_xcb_connection_shm_put_image (cairo_xcb_connection_t *connection,
				     xcb_drawable_t dst,
				     xcb_gcontext_t gc,
				     uint16_t total_width,
				     uint16_t total_height,
				     int16_t src_x,
				     int16_t src_y,
				     uint16_t width,
				     uint16_t height,
				     int16_t dst_x,
				     int16_t dst_y,
				     uint8_t depth,
				     uint32_t shm,
				     uint32_t offset)
{
    struct {
	uint8_t req;
	uint8_t shm_req;
	uint16_t len;
	uint32_t dst;
	uint32_t gc;
	uint16_t total_width;
	uint16_t total_height;
	int16_t src_x;
	int16_t src_y;
	uint16_t src_width;
	uint16_t src_height;
	int16_t dst_x;
	int16_t dst_y;
	uint8_t depth;
	uint8_t format;
	uint8_t send_event;
	uint8_t pad;
	uint32_t shm;
	uint32_t offset;
    } req;
    struct iovec vec[2];

    req.req = connection->shm->major_opcode;
    req.shm_req = 3;
    req.len = sizeof (req) >> 2;
    req.dst = dst;
    req.gc = gc;
    req.total_width = total_width;
    req.total_height = total_height;
    req.src_x = src_x;
    req.src_y = src_y;
    req.src_width = width;
    req.src_height = height;
    req.dst_x = dst_x;
    req.dst_y = dst_y;
    req.depth = depth;
    req.format = XCB_IMAGE_FORMAT_Z_PIXMAP;
    req.send_event = 0;
    req.shm = shm;
    req.offset = offset;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
    return connection->seqno;
}

cairo_status_t
_cairo_xcb_connection_shm_get_image (cairo_xcb_connection_t *connection,
				     xcb_drawable_t src,
				     int16_t src_x,
				     int16_t src_y,
				     uint16_t width,
				     uint16_t height,
				     uint32_t shmseg,
				     uint32_t offset)
{
    xcb_shm_get_image_reply_t *reply;
    xcb_generic_error_t *error;

    reply = xcb_shm_get_image_reply (connection->xcb_connection,
				     xcb_shm_get_image (connection->xcb_connection,
							src,
							src_x, src_y,
							width, height,
							(uint32_t) -1,
							XCB_IMAGE_FORMAT_Z_PIXMAP,
							shmseg, offset),
				     &error);
    free (reply);

    if (error) {
	/* an error here should be impossible */
	free (error);
	return _cairo_error (CAIRO_STATUS_READ_ERROR);
    }

    return _cairo_xcb_connection_take_socket (connection);
}

void
_cairo_xcb_connection_shm_detach (cairo_xcb_connection_t *connection,
				  uint32_t segment)
{
    struct {
	uint8_t req;
	uint8_t shm_req;
	uint16_t length;
	uint32_t segment;
    } req;
    struct iovec vec[1];

    COMPILE_TIME_ASSERT (sizeof (req) == 8);

    req.req = connection->shm->major_opcode;
    req.shm_req = 2;
    req.length = sizeof (req) >> 2;
    req.segment = segment;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
    _cairo_xcb_connection_put_xid (connection, segment);
}
