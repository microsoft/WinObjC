/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2009 Eric Anholt
 * Copyright © 2009 Chris Wilson
 * Copyright © 2005,2010 Red Hat, Inc
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
 * The Initial Developer of the Original Code is Red Hat, Inc.
 *
 * Contributor(s):
 *	Benjamin Otte <otte@gnome.org>
 *	Carl Worth <cworth@cworth.org>
 *	Chris Wilson <chris@chris-wilson.co.uk>
 *	Eric Anholt <eric@anholt.net>
 */

#include "cairoint.h"

#include "cairo-error-private.h"
#include "cairo-gl-gradient-private.h"
#include "cairo-gl-private.h"

static int
_cairo_gl_gradient_sample_width (unsigned int                 n_stops,
                                 const cairo_gradient_stop_t *stops)
{
    unsigned int n;
    int width;

    width = 8;
    for (n = 1; n < n_stops; n++) {
	double dx = stops[n].offset - stops[n-1].offset;
	double delta, max;
	int ramp;

	if (dx == 0)
	    continue;

	max = stops[n].color.red - stops[n-1].color.red;

	delta = stops[n].color.green - stops[n-1].color.green;
	if (delta > max)
	    max = delta;

	delta = stops[n].color.blue - stops[n-1].color.blue;
	if (delta > max)
	    max = delta;

	delta = stops[n].color.alpha - stops[n-1].color.alpha;
	if (delta > max)
	    max = delta;

	ramp = 128 * max / dx;
	if (ramp > width)
	    width = ramp;
    }

    width = (width + 7) & -8;
    return MIN (width, 1024);
}

static cairo_status_t
_cairo_gl_gradient_render (const cairo_gl_context_t    *ctx,
                           unsigned int                 n_stops,
                           const cairo_gradient_stop_t *stops,
                           void                        *bytes,
                           int                          width)
{
    pixman_image_t *gradient, *image;
    pixman_gradient_stop_t pixman_stops_stack[32];
    pixman_gradient_stop_t *pixman_stops;
    pixman_point_fixed_t p1, p2;
    unsigned int i;

    pixman_stops = pixman_stops_stack;
    if (unlikely (n_stops > ARRAY_LENGTH (pixman_stops_stack))) {
	pixman_stops = _cairo_malloc_ab (n_stops,
					 sizeof (pixman_gradient_stop_t));
	if (unlikely (pixman_stops == NULL))
	    return _cairo_error (CAIRO_STATUS_NO_MEMORY);
    }

    for (i = 0; i < n_stops; i++) {
	pixman_stops[i].x = _cairo_fixed_16_16_from_double (stops[i].offset);
	pixman_stops[i].color.red   = stops[i].color.red_short;
	pixman_stops[i].color.green = stops[i].color.green_short;
	pixman_stops[i].color.blue  = stops[i].color.blue_short;
	pixman_stops[i].color.alpha = stops[i].color.alpha_short;
    }

    p1.x = 0;
    p1.y = 0;
    p2.x = width << 16;
    p2.y = 0;

    gradient = pixman_image_create_linear_gradient (&p1, &p2,
						    pixman_stops,
						    n_stops);
    if (pixman_stops != pixman_stops_stack)
	free (pixman_stops);

    if (unlikely (gradient == NULL))
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);

    pixman_image_set_filter (gradient, PIXMAN_FILTER_BILINEAR, NULL, 0);
    pixman_image_set_repeat (gradient, PIXMAN_REPEAT_PAD);

    image = pixman_image_create_bits (PIXMAN_a8r8g8b8, width, 1,
				      bytes, sizeof(uint32_t)*width);
    if (unlikely (image == NULL)) {
	pixman_image_unref (gradient);
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);
    }

    pixman_image_composite32 (PIXMAN_OP_SRC,
                              gradient, NULL, image,
                              0, 0,
                              0, 0,
                              0, 0,
                              width, 1);

    pixman_image_unref (gradient);
    pixman_image_unref (image);
    return CAIRO_STATUS_SUCCESS;
}

static unsigned long
_cairo_gl_gradient_hash (unsigned int                  n_stops,
                         const cairo_gradient_stop_t  *stops)
{
    return _cairo_hash_bytes (n_stops,
                              stops,
                              sizeof (cairo_gradient_stop_t) * n_stops);
}

static cairo_gl_gradient_t *
_cairo_gl_gradient_lookup (cairo_gl_context_t           *ctx,
                           unsigned long                 hash,
                           unsigned int                  n_stops,
                           const cairo_gradient_stop_t  *stops)
{
    cairo_gl_gradient_t lookup;

    lookup.cache_entry.hash = hash,
    lookup.n_stops = n_stops;
    lookup.stops = stops;

    return _cairo_cache_lookup (&ctx->gradients, &lookup.cache_entry);
}

cairo_bool_t
_cairo_gl_gradient_equal (const void *key_a, const void *key_b)
{
    const cairo_gl_gradient_t *a = key_a;
    const cairo_gl_gradient_t *b = key_b;

    if (a->n_stops != b->n_stops)
        return FALSE;

    return memcmp (a->stops, b->stops, a->n_stops * sizeof (cairo_gradient_stop_t)) == 0;
}

cairo_int_status_t
_cairo_gl_gradient_create (cairo_gl_context_t           *ctx,
                           unsigned int                  n_stops,
                           const cairo_gradient_stop_t  *stops,
                           cairo_gl_gradient_t         **gradient_out)
{
    unsigned long hash;
    cairo_gl_gradient_t *gradient;
    cairo_status_t status;
    int tex_width;
    void *data;

    if ((unsigned int) ctx->max_texture_size / 2 <= n_stops)
        return CAIRO_INT_STATUS_UNSUPPORTED;

    hash = _cairo_gl_gradient_hash (n_stops, stops);
    
    gradient = _cairo_gl_gradient_lookup (ctx, hash, n_stops, stops);
    if (gradient) {
        *gradient_out = _cairo_gl_gradient_reference (gradient);
        return CAIRO_STATUS_SUCCESS;
    }

    gradient = malloc (sizeof (cairo_gl_gradient_t) + sizeof (cairo_gradient_stop_t) * (n_stops - 1));
    if (gradient == NULL)
        return _cairo_error (CAIRO_STATUS_NO_MEMORY);

    tex_width = _cairo_gl_gradient_sample_width (n_stops, stops);

    CAIRO_REFERENCE_COUNT_INIT (&gradient->ref_count, 1);
    gradient->cache_entry.hash = hash;
    gradient->cache_entry.size = tex_width;
    gradient->device = &ctx->base;
    gradient->n_stops = n_stops;
    gradient->stops = gradient->stops_embedded;
    memcpy (gradient->stops_embedded, stops, n_stops * sizeof (cairo_gradient_stop_t));

    glBindBufferARB (GL_PIXEL_UNPACK_BUFFER_ARB, ctx->texture_load_pbo);
    glBufferDataARB (GL_PIXEL_UNPACK_BUFFER_ARB, tex_width * sizeof (uint32_t), 0, GL_STREAM_DRAW);
    data = glMapBufferARB (GL_PIXEL_UNPACK_BUFFER_ARB, GL_WRITE_ONLY);

    status = _cairo_gl_gradient_render (ctx, n_stops, stops, data, tex_width);

    glUnmapBufferARB (GL_PIXEL_UNPACK_BUFFER_ARB);

    if (unlikely (status)) {
        glBindBufferARB (GL_PIXEL_UNPACK_BUFFER_ARB, 0);
        free (gradient);
        return status;
    }

    glGenTextures (1, &gradient->tex);
    _cairo_gl_context_activate (ctx, CAIRO_GL_TEX_TEMP);
    glBindTexture (GL_TEXTURE_1D, gradient->tex);
    glTexImage1D (GL_TEXTURE_1D, 0, GL_RGBA8, tex_width, 0,
                  GL_BGRA, GL_UNSIGNED_INT_8_8_8_8_REV, 0);

    glBindBufferARB (GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    /* we ignore errors here and just return an uncached gradient */
    if (likely (! _cairo_cache_insert (&ctx->gradients, &gradient->cache_entry)))
        _cairo_gl_gradient_reference (gradient);

    *gradient_out = gradient;
    return CAIRO_STATUS_SUCCESS;
}

cairo_gl_gradient_t *
_cairo_gl_gradient_reference (cairo_gl_gradient_t *gradient)
{
    assert (CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&gradient->ref_count));

    _cairo_reference_count_inc (&gradient->ref_count);

    return gradient;
}

void
_cairo_gl_gradient_destroy (cairo_gl_gradient_t *gradient)
{
    cairo_gl_context_t *ctx;
    cairo_status_t ignore;

    assert (CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&gradient->ref_count));

    if (! _cairo_reference_count_dec_and_test (&gradient->ref_count))
	return;

    if (_cairo_gl_context_acquire (gradient->device, &ctx) == CAIRO_STATUS_SUCCESS) {
        glDeleteTextures (1, &gradient->tex);
        ignore = _cairo_gl_context_release (ctx, CAIRO_STATUS_SUCCESS);
    }

    free (gradient);
}
