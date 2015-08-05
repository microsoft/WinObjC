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

#define X_RenderSpans 99
#define XLIB_COORD_MAX 32767

void
_cairo_xcb_connection_render_create_picture (cairo_xcb_connection_t  *connection,
					     xcb_render_picture_t     picture,
					     xcb_drawable_t           drawable,
					     xcb_render_pictformat_t  format,
					     uint32_t                 value_mask,
					     uint32_t	             *value_list)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
	uint32_t drawable;
	uint32_t format;
	uint32_t mask;
    } req;
    struct iovec vec[2];
    int len = _cairo_popcount (value_mask) * 4;

    COMPILE_TIME_ASSERT (sizeof (req) == 20);

    req.major = connection->render->major_opcode;
    req.minor = 4;
    req.length = (sizeof (req) + len) >> 2;
    req.picture = picture;
    req.drawable = drawable;
    req.format = format;
    req.mask = value_mask;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = value_list;
    vec[1].iov_len = len;

    _cairo_xcb_connection_write (connection, vec, 1 + (len != 0));
}

void
_cairo_xcb_connection_render_change_picture (cairo_xcb_connection_t     *connection,
					     xcb_render_picture_t  picture,
					     uint32_t              value_mask,
					     uint32_t             *value_list)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
	uint32_t mask;
    } req;
    struct iovec vec[2];
    int len = _cairo_popcount (value_mask) * 4;

    COMPILE_TIME_ASSERT (sizeof (req) == 12);

    req.major = connection->render->major_opcode;
    req.minor = 5;
    req.length = (sizeof (req) + len) >> 2;
    req.picture = picture;
    req.mask = value_mask;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = value_list;
    vec[1].iov_len = len;

    _cairo_xcb_connection_write (connection, vec, 2);
}

void
_cairo_xcb_connection_render_set_picture_clip_rectangles (cairo_xcb_connection_t      *connection,
							  xcb_render_picture_t   picture,
							  int16_t                clip_x_origin,
							  int16_t                clip_y_origin,
							  uint32_t               rectangles_len,
							  xcb_rectangle_t *rectangles)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
	uint16_t x;
	uint16_t y;
    } req;
    struct iovec vec[2];
    int len = sizeof (xcb_rectangle_t) * rectangles_len;

    COMPILE_TIME_ASSERT (sizeof (req) == 12);
    assert ((len + sizeof (req)) >> 2 < connection->root->maximum_request_length);

    req.major = connection->render->major_opcode;
    req.minor = 6;
    req.length = (sizeof (req) + len) >> 2;
    req.picture = picture;
    req.x = clip_x_origin;
    req.y = clip_y_origin;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = rectangles;
    vec[1].iov_len = len;

    _cairo_xcb_connection_write (connection, vec, 2);
}

void
_cairo_xcb_connection_render_free_picture (cairo_xcb_connection_t *connection,
					   xcb_render_picture_t  picture)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
    } req;
    struct iovec vec[1];

    COMPILE_TIME_ASSERT (sizeof (req) == 8);

    req.major = connection->render->major_opcode;
    req.minor = 7;
    req.length = sizeof (req) >> 2;
    req.picture = picture;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
    _cairo_xcb_connection_put_xid (connection, picture);
}

void
_cairo_xcb_connection_render_composite (cairo_xcb_connection_t     *connection,
					uint8_t               op,
					xcb_render_picture_t  src,
					xcb_render_picture_t  mask,
					xcb_render_picture_t  dst,
					int16_t               src_x,
					int16_t               src_y,
					int16_t               mask_x,
					int16_t               mask_y,
					int16_t               dst_x,
					int16_t               dst_y,
					uint16_t              width,
					uint16_t              height)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint8_t op;
	uint8_t pad1;
	uint16_t pad2;
	uint32_t src;
	uint32_t mask;
	uint32_t dst;
	int16_t src_x;
	int16_t src_y;
	int16_t mask_x;
	int16_t mask_y;
	int16_t dst_x;
	int16_t dst_y;
	uint16_t width;
	uint16_t height;
    } req;
    struct iovec vec[1];

    COMPILE_TIME_ASSERT (sizeof (req) == 36);

    req.major = connection->render->major_opcode;
    req.minor = 8;
    req.length = sizeof (req) >> 2;
    req.op = op;
    req.src = src;
    req.mask = mask;
    req.dst = dst;
    req.src_x = src_x;
    req.src_y = src_y;
    req.mask_x = mask_x;
    req.mask_y = mask_y;
    req.dst_x = dst_x;
    req.dst_y = dst_y;
    req.width = width;
    req.height = height;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
}

void
_cairo_xcb_connection_render_trapezoids (cairo_xcb_connection_t *connection,
					 uint8_t                       op,
					 xcb_render_picture_t          src,
					 xcb_render_picture_t          dst,
					 xcb_render_pictformat_t       mask_format,
					 int16_t                       src_x,
					 int16_t                       src_y,
					 uint32_t                      traps_len,
					 xcb_render_trapezoid_t *traps)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint8_t op;
	uint8_t pad1;
	uint16_t pad2;
	uint32_t src;
	uint32_t dst;
	uint32_t mask_format;
	int16_t src_x;
	int16_t src_y;
    } req;
    struct iovec vec[3];
    uint32_t prefix[2];
    uint32_t len = (sizeof (req) + traps_len * sizeof (xcb_render_trapezoid_t)) >> 2;

    COMPILE_TIME_ASSERT (sizeof (req) == 24);

    req.major = connection->render->major_opcode;
    req.minor = 10;
    req.length = 0;
    req.op = op;
    req.src = src;
    req.dst = dst;
    req.mask_format = mask_format;
    req.src_x = src_x;
    req.src_y = src_y;

    if (len < connection->root->maximum_request_length) {
	req.length = len;

	vec[0].iov_base = &req;
	vec[0].iov_len = sizeof (req);
	vec[1].iov_base = traps;
	vec[1].iov_len = traps_len * sizeof (xcb_render_trapezoid_t);

	_cairo_xcb_connection_write (connection, vec, 2);
    } else {
	prefix[0] = *(uint32_t *) &req;
	prefix[1] = len + 1;
	vec[0].iov_base = prefix;
	vec[0].iov_len = sizeof (prefix);
	vec[1].iov_base = (uint32_t *) &req + 1;
	vec[1].iov_len = sizeof (req) - 4;
	vec[2].iov_base = traps;
	vec[2].iov_len = traps_len * sizeof (xcb_render_trapezoid_t);

	_cairo_xcb_connection_write (connection, vec, 3);
    }
}

void
_cairo_xcb_connection_render_spans (cairo_xcb_connection_t *connection,
				    xcb_render_picture_t dst,
				    int op,
				    xcb_render_picture_t src,
				    int16_t src_x, int16_t src_y,
				    int16_t dst_x, int16_t dst_y,
				    int16_t width, int16_t height,
				    uint32_t num_spans,
				    uint16_t *spans)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint8_t op;
	uint8_t pad1;
	uint16_t pad2;
	uint32_t src;
	uint32_t dst;
	int16_t src_x;
	int16_t src_y;
	int16_t dst_x;
	int16_t dst_y;
	uint16_t width;
	uint16_t height;
    } req;
    struct iovec vec[3];
    uint32_t prefix[2];
    uint32_t len = (sizeof (req) + num_spans * sizeof (uint16_t)) >> 2;

    req.major = connection->render->major_opcode;
    req.minor = X_RenderSpans;
    req.length = 0;

    req.dst = dst;
    req.op = op;
    req.src = src;
    req.src_x = src_x;
    req.src_y = src_y;
    req.dst_x = dst_x;
    req.dst_y = dst_y;
    req.width = width;
    req.height = height;

    if (len < connection->root->maximum_request_length) {
	req.length = len;

	vec[0].iov_base = &req;
	vec[0].iov_len = sizeof (req);
	vec[1].iov_base = spans;
	vec[1].iov_len = num_spans * sizeof (uint16_t);

	_cairo_xcb_connection_write (connection, vec, 2);
    } else {
	prefix[0] = *(uint32_t *) &req;
	prefix[1] = len + 1;
	vec[0].iov_base = prefix;
	vec[0].iov_len = sizeof (prefix);
	vec[1].iov_base = (uint32_t *) &req + 1;
	vec[1].iov_len = sizeof (req) - 4;
	vec[2].iov_base = spans;
	vec[2].iov_len = num_spans * sizeof (uint16_t);

	_cairo_xcb_connection_write (connection, vec, 3);
    }
}

void
_cairo_xcb_connection_render_create_glyph_set (cairo_xcb_connection_t	*connection,
					       xcb_render_glyphset_t	 id,
					       xcb_render_pictformat_t  format)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t gsid;
	uint32_t format;
    } req;
    struct iovec vec[1];

    COMPILE_TIME_ASSERT (sizeof (req) == 12);

    req.major = connection->render->major_opcode;
    req.minor = 17;
    req.length = sizeof (req) >> 2;
    req.gsid = id;
    req.format = format;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
}

void
_cairo_xcb_connection_render_free_glyph_set (cairo_xcb_connection_t      *connection,
					     xcb_render_glyphset_t  glyphset)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t gsid;
    } req;
    struct iovec vec[1];

    COMPILE_TIME_ASSERT (sizeof (req) == 8);

    req.major = connection->render->major_opcode;
    req.minor = 19;
    req.length = sizeof (req) >> 2;
    req.gsid = glyphset;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
    _cairo_xcb_connection_put_xid (connection, glyphset);
}

void
_cairo_xcb_connection_render_add_glyphs (cairo_xcb_connection_t             *connection,
					 xcb_render_glyphset_t         glyphset,
					 uint32_t                      num_glyphs,
					 uint32_t               *glyphs_id,
					 xcb_render_glyphinfo_t *glyphs,
					 uint32_t                      data_len,
					 uint8_t                *data)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t gsid;
	uint32_t num_glyphs;
    } req;
    struct iovec vec[5];
    uint32_t prefix[2];
    uint32_t len = (sizeof (req) + num_glyphs * (sizeof (uint32_t) + sizeof (xcb_render_glyphinfo_t)) + data_len) >> 2;
    int cnt;

    COMPILE_TIME_ASSERT (sizeof (req) == 12);

    req.major = connection->render->major_opcode;
    req.minor = 20;
    req.length = 0;
    req.gsid = glyphset;
    req.num_glyphs = num_glyphs;

    if (len < connection->root->maximum_request_length) {
	req.length = len;

	vec[0].iov_base = &req;
	vec[0].iov_len = sizeof (req);

	cnt = 1;
    } else {
	prefix[0] = *(uint32_t *) &req;
	prefix[1] = len + 1;
	vec[0].iov_base = prefix;
	vec[0].iov_len = sizeof (prefix);
	vec[1].iov_base = (uint32_t *) &req + 1;
	vec[1].iov_len = sizeof (req) - 4;

	cnt = 2;
    }

    vec[cnt].iov_base = glyphs_id;
    vec[cnt].iov_len = num_glyphs * sizeof (uint32_t);
    cnt++;

    vec[cnt].iov_base = glyphs;
    vec[cnt].iov_len = num_glyphs * sizeof (xcb_render_glyphinfo_t);
    cnt++;

    vec[cnt].iov_base = data;
    vec[cnt].iov_len = data_len;
    cnt++;

    _cairo_xcb_connection_write (connection, vec, cnt);
}

void
_cairo_xcb_connection_render_free_glyphs (cairo_xcb_connection_t         *connection,
					  xcb_render_glyphset_t     glyphset,
					  uint32_t                  num_glyphs,
					  xcb_render_glyph_t *glyphs)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t gsid;
    } req;
    struct iovec vec[2];

    COMPILE_TIME_ASSERT (sizeof (req) == 8);
    assert ( (sizeof (req) + num_glyphs * sizeof (uint32_t)) >> 2 < connection->root->maximum_request_length);

    req.major = connection->render->major_opcode;
    req.minor = 22;
    req.length = (sizeof (req) + num_glyphs * sizeof (uint32_t)) >> 2;
    req.gsid = glyphset;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = glyphs;
    vec[1].iov_len = num_glyphs * sizeof (uint32_t);

    _cairo_xcb_connection_write (connection, vec, 2);
}

void
_cairo_xcb_connection_render_composite_glyphs_8 (cairo_xcb_connection_t        *connection,
						 uint8_t                  op,
						 xcb_render_picture_t     src,
						 xcb_render_picture_t     dst,
						 xcb_render_pictformat_t  mask_format,
						 xcb_render_glyphset_t    glyphset,
						 int16_t                  src_x,
						 int16_t                  src_y,
						 uint32_t                 glyphcmds_len,
						 uint8_t           *glyphcmds)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint8_t op;
	uint8_t pad1;
	uint16_t pad2;
	uint32_t src;
	uint32_t dst;
	uint32_t mask_format;
	uint32_t glyphset;
	int16_t src_x;
	int16_t src_y;
    } req;
    struct iovec vec[3];
    uint32_t prefix[2];
    int len;

    COMPILE_TIME_ASSERT (sizeof (req) == 28);

    req.major = connection->render->major_opcode;
    req.minor = 23;
    req.length = 0;
    req.op = op;
    req.src = src;
    req.dst = dst;
    req.mask_format = mask_format;
    req.glyphset = glyphset;
    req.src_x = src_x;
    req.src_y = src_y;

    len = (sizeof (req) + glyphcmds_len) >> 2;
    if (len < connection->root->maximum_request_length) {
	req.length = len;

	vec[0].iov_base = &req;
	vec[0].iov_len = sizeof (req);

	len = 1;
    } else {
	prefix[0] = *(uint32_t *) &req;
	prefix[1] = len + 1;
	vec[0].iov_base = prefix;
	vec[0].iov_len = sizeof (prefix);
	vec[1].iov_base = (uint32_t *) &req + 1;
	vec[1].iov_len = sizeof (req) - 4;

	len = 2;
    }

    vec[len].iov_base = glyphcmds;
    vec[len].iov_len = glyphcmds_len;
    len++;

    _cairo_xcb_connection_write (connection, vec, len);
}

void
_cairo_xcb_connection_render_composite_glyphs_16 (cairo_xcb_connection_t        *connection,
						  uint8_t                  op,
						  xcb_render_picture_t     src,
						  xcb_render_picture_t     dst,
						  xcb_render_pictformat_t  mask_format,
						  xcb_render_glyphset_t    glyphset,
						  int16_t                  src_x,
						  int16_t                  src_y,
						  uint32_t                 glyphcmds_len,
						  uint8_t           *glyphcmds)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint8_t op;
	uint8_t pad1;
	uint16_t pad2;
	uint32_t src;
	uint32_t dst;
	uint32_t mask_format;
	uint32_t glyphset;
	int16_t src_x;
	int16_t src_y;
    } req;
    struct iovec vec[3];
    uint32_t prefix[2];
    int len;

    COMPILE_TIME_ASSERT (sizeof (req) == 28);

    req.major = connection->render->major_opcode;
    req.minor = 24;
    req.length = 0;
    req.op = op;
    req.src = src;
    req.dst = dst;
    req.mask_format = mask_format;
    req.glyphset = glyphset;
    req.src_x = src_x;
    req.src_y = src_y;

    len = (sizeof (req) + glyphcmds_len) >> 2;
    if (len < connection->root->maximum_request_length) {
	req.length = len;

	vec[0].iov_base = &req;
	vec[0].iov_len = sizeof (req);

	len = 1;
    } else {
	prefix[0] = *(uint32_t *) &req;
	prefix[1] = len + 1;
	vec[0].iov_base = prefix;
	vec[0].iov_len = sizeof (prefix);
	vec[1].iov_base = (uint32_t *) &req + 1;
	vec[1].iov_len = sizeof (req) - 4;

	len = 2;
    }

    vec[len].iov_base = glyphcmds;
    vec[len].iov_len = glyphcmds_len;
    len++;

    _cairo_xcb_connection_write (connection, vec, len);
}

void
_cairo_xcb_connection_render_composite_glyphs_32 (cairo_xcb_connection_t        *connection,
						  uint8_t                  op,
						  xcb_render_picture_t     src,
						  xcb_render_picture_t     dst,
						  xcb_render_pictformat_t  mask_format,
						  xcb_render_glyphset_t    glyphset,
						  int16_t                  src_x,
						  int16_t                  src_y,
						  uint32_t                 glyphcmds_len,
						  uint8_t           *glyphcmds)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint8_t op;
	uint8_t pad1;
	uint16_t pad2;
	uint32_t src;
	uint32_t dst;
	uint32_t mask_format;
	uint32_t glyphset;
	int16_t src_x;
	int16_t src_y;
    } req;
    struct iovec vec[2];
    uint32_t prefix[2];
    int len;

    COMPILE_TIME_ASSERT (sizeof (req) == 28);

    req.major = connection->render->major_opcode;
    req.minor = 25;
    req.length = 0;
    req.op = op;
    req.src = src;
    req.dst = dst;
    req.mask_format = mask_format;
    req.glyphset = glyphset;
    req.src_x = src_x;
    req.src_y = src_y;

    len = (sizeof (req) + glyphcmds_len) >> 2;
    if (len < connection->root->maximum_request_length) {
	req.length = len;

	vec[0].iov_base = &req;
	vec[0].iov_len = sizeof (req);

	len = 1;
    } else {
	prefix[0] = *(uint32_t *) &req;
	prefix[1] = len + 1;
	vec[0].iov_base = prefix;
	vec[0].iov_len = sizeof (prefix);
	vec[1].iov_base = (uint32_t *) &req + 1;
	vec[1].iov_len = sizeof (req) - 4;

	len = 2;
    }

    vec[len].iov_base = glyphcmds;
    vec[len].iov_len = glyphcmds_len;
    len++;

    _cairo_xcb_connection_write (connection, vec, len);
}

void
_cairo_xcb_connection_render_fill_rectangles (cairo_xcb_connection_t      *connection,
					      uint8_t                op,
					      xcb_render_picture_t   dst,
					      xcb_render_color_t     color,
					      uint32_t               num_rects,
					      xcb_rectangle_t *rects)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint8_t op;
	uint8_t pad1;
	uint16_t pad2;
	uint32_t dst;
	xcb_render_color_t     color;
    } req;
    struct iovec vec[3];
    uint32_t prefix[2];
    uint32_t len;

    COMPILE_TIME_ASSERT (sizeof (req) == 20);

    req.major = connection->render->major_opcode;
    req.minor = 26;
    req.op = op;
    req.dst = dst;
    req.color = color;

    len = (sizeof (req) + num_rects * sizeof (xcb_rectangle_t)) >> 2;
    if (len < connection->root->maximum_request_length) {
	req.length = len;

	vec[0].iov_base = &req;
	vec[0].iov_len = sizeof (req);

	len = 1;
    } else {
	prefix[0] = *(uint32_t *) &req;
	prefix[1] = len + 1;
	vec[0].iov_base = prefix;
	vec[0].iov_len = sizeof (prefix);
	vec[1].iov_base = (uint32_t *) &req + 1;
	vec[1].iov_len = sizeof (req) - 4;

	len = 2;
    }

    vec[len].iov_base = rects;
    vec[len].iov_len = num_rects * sizeof (xcb_rectangle_t);
    len++;

    _cairo_xcb_connection_write (connection, vec, len);
}

void
_cairo_xcb_connection_render_set_picture_transform (cairo_xcb_connection_t       *connection,
						    xcb_render_picture_t    picture,
						    xcb_render_transform_t  *transform)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
    } req;
    struct iovec vec[2];

    req.major = connection->render->major_opcode;
    req.minor = 28;
    req.length = (sizeof (req) + sizeof (xcb_render_transform_t)) >> 2;
    req.picture = picture;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = transform;
    vec[1].iov_len = sizeof (xcb_render_transform_t);

    _cairo_xcb_connection_write (connection, vec, 2);
}

void
_cairo_xcb_connection_render_set_picture_filter (cairo_xcb_connection_t         *connection,
						 xcb_render_picture_t      picture,
						 uint16_t                  filter_len,
						 char               *filter)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
	uint16_t nbytes;
	uint16_t pad;
    } req;
    struct iovec vec[2];

    req.nbytes = filter_len;
    filter_len = (filter_len + 3) & ~3;

    req.major = connection->render->major_opcode;
    req.minor = 30;
    req.length = (sizeof (req) + filter_len) >> 2;
    req.picture = picture;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = filter;
    vec[1].iov_len = filter_len;

    _cairo_xcb_connection_write (connection, vec, 2);
}

void
_cairo_xcb_connection_render_create_solid_fill (cairo_xcb_connection_t     *connection,
						xcb_render_picture_t  picture,
						xcb_render_color_t    color)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
	xcb_render_color_t color;
    } req;
    struct iovec vec[1];

    COMPILE_TIME_ASSERT (sizeof (req) == 16);

    req.major = connection->render->major_opcode;
    req.minor = 33;
    req.length = sizeof (req) >> 2;
    req.picture = picture;
    req.color = color;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);

    _cairo_xcb_connection_write (connection, vec, 1);
}

void
_cairo_xcb_connection_render_create_linear_gradient (cairo_xcb_connection_t         *connection,
						     xcb_render_picture_t      picture,
						     xcb_render_pointfix_t     p1,
						     xcb_render_pointfix_t     p2,
						     uint32_t                  num_stops,
						     xcb_render_fixed_t *stops,
						     xcb_render_color_t *colors)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
	xcb_render_pointfix_t p1, p2;
	uint32_t num_stops;
    } req;
    struct iovec vec[3];

    COMPILE_TIME_ASSERT (sizeof (req) == 28);
    assert((sizeof (req)  + num_stops * (sizeof (xcb_render_fixed_t) + sizeof (xcb_render_color_t))) >> 2 < connection->root->maximum_request_length);

    req.major = connection->render->major_opcode;
    req.minor = 34;
    req.length = (sizeof (req)  + num_stops * (sizeof (xcb_render_fixed_t) + sizeof (xcb_render_color_t))) >> 2;
    req.picture = picture;
    req.p1 = p1;
    req.p2 = p2;
    req.num_stops = num_stops;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = stops;
    vec[1].iov_len = num_stops * sizeof (xcb_render_fixed_t);
    vec[2].iov_base = colors;
    vec[2].iov_len = num_stops * sizeof (xcb_render_color_t);

    _cairo_xcb_connection_write (connection, vec, 3);
}

void
_cairo_xcb_connection_render_create_radial_gradient (cairo_xcb_connection_t         *connection,
						     xcb_render_picture_t      picture,
						     xcb_render_pointfix_t     inner,
						     xcb_render_pointfix_t     outer,
						     xcb_render_fixed_t        inner_radius,
						     xcb_render_fixed_t        outer_radius,
						     uint32_t                  num_stops,
						     xcb_render_fixed_t *stops,
						     xcb_render_color_t *colors)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
	xcb_render_pointfix_t     inner;
	xcb_render_pointfix_t     outer;
	xcb_render_fixed_t        inner_radius;
	xcb_render_fixed_t        outer_radius;
	uint32_t num_stops;
    } req;
    struct iovec vec[3];

    COMPILE_TIME_ASSERT (sizeof (req) == 36);
    assert((sizeof (req)  + num_stops * (sizeof (xcb_render_fixed_t) + sizeof (xcb_render_color_t))) >> 2 < connection->root->maximum_request_length);

    req.major = connection->render->major_opcode;
    req.minor = 35;
    req.length = (sizeof (req)  + num_stops * (sizeof (xcb_render_fixed_t) + sizeof (xcb_render_color_t))) >> 2;
    req.picture = picture;
    req.inner = inner;
    req.outer = outer;
    req.inner_radius = inner_radius;
    req.outer_radius = outer_radius;
    req.num_stops = num_stops;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = stops;
    vec[1].iov_len = num_stops * sizeof (xcb_render_fixed_t);
    vec[2].iov_base = colors;
    vec[2].iov_len = num_stops * sizeof (xcb_render_color_t);

    _cairo_xcb_connection_write (connection, vec, 3);
}

void
_cairo_xcb_connection_render_create_conical_gradient (cairo_xcb_connection_t         *connection,
						      xcb_render_picture_t      picture,
						      xcb_render_pointfix_t     center,
						      xcb_render_fixed_t        angle,
						      uint32_t                  num_stops,
						      xcb_render_fixed_t *stops,
						      xcb_render_color_t *colors)
{
    struct {
	uint8_t major;
	uint8_t minor;
	uint16_t length;
	uint32_t picture;
	xcb_render_pointfix_t     center;
	xcb_render_fixed_t        angle;
	uint32_t num_stops;
    } req;
    struct iovec vec[3];

    COMPILE_TIME_ASSERT (sizeof (req) == 24);
    assert((sizeof (req)  + num_stops * (sizeof (xcb_render_fixed_t) + sizeof (xcb_render_color_t))) >> 2 < connection->root->maximum_request_length);

    req.major = connection->render->major_opcode;
    req.minor = 36;
    req.length = (sizeof (req)  + num_stops * (sizeof (xcb_render_fixed_t) + sizeof (xcb_render_color_t))) >> 2;
    req.picture = picture;
    req.center = center;
    req.angle = angle;
    req.num_stops = num_stops;

    vec[0].iov_base = &req;
    vec[0].iov_len = sizeof (req);
    vec[1].iov_base = stops;
    vec[1].iov_len = num_stops * sizeof (xcb_render_fixed_t);
    vec[2].iov_base = colors;
    vec[2].iov_len = num_stops * sizeof (xcb_render_color_t);

    _cairo_xcb_connection_write (connection, vec, 3);
}
