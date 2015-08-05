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
#include "cairo-gl-private.h"

static cairo_int_status_t
_cairo_gl_create_gradient_texture (cairo_gl_surface_t *dst,
				   const cairo_gradient_pattern_t *pattern,
                                   cairo_gl_gradient_t **gradient)
{
    cairo_gl_context_t *ctx;
    cairo_status_t status;

    status = _cairo_gl_context_acquire (dst->base.device, &ctx);
    if (unlikely (status))
	return status;

    status = _cairo_gl_gradient_create (ctx, pattern->n_stops, pattern->stops, gradient);

    return _cairo_gl_context_release (ctx, status);
}

/*
 * Like cairo_pattern_acquire_surface(), but returns a matrix that transforms
 * from dest to src coords.
 */
static cairo_status_t
_cairo_gl_pattern_texture_setup (cairo_gl_operand_t *operand,
				 const cairo_pattern_t *src,
				 cairo_gl_surface_t *dst,
				 int src_x, int src_y,
				 int dst_x, int dst_y,
				 int width, int height)
{
    cairo_status_t status;
    cairo_matrix_t m;
    cairo_gl_surface_t *surface;
    cairo_surface_attributes_t *attributes;
    attributes = &operand->texture.attributes;

    status = _cairo_pattern_acquire_surface (src, &dst->base,
					     src_x, src_y,
					     width, height,
					     CAIRO_PATTERN_ACQUIRE_NONE,
					     (cairo_surface_t **)
					     &surface,
					     attributes);
    if (unlikely (status))
	return status;

    if (_cairo_gl_device_requires_power_of_two_textures (dst->base.device) &&
	(attributes->extend == CAIRO_EXTEND_REPEAT ||
	 attributes->extend == CAIRO_EXTEND_REFLECT))
    {
	_cairo_pattern_release_surface (src,
					&surface->base,
					attributes);
	return UNSUPPORTED ("EXT_texture_rectangle with repeat/reflect");
    }

    assert (surface->base.backend == &_cairo_gl_surface_backend);
    assert (_cairo_gl_surface_is_texture (surface));

    operand->type = CAIRO_GL_OPERAND_TEXTURE;
    operand->texture.surface = surface;
    operand->texture.tex = surface->tex;
    /* Translate the matrix from
     * (unnormalized src -> unnormalized src) to
     * (unnormalized dst -> unnormalized src)
     */
    cairo_matrix_init_translate (&m,
				 src_x - dst_x + attributes->x_offset,
				 src_y - dst_y + attributes->y_offset);
    cairo_matrix_multiply (&attributes->matrix,
			   &m,
			   &attributes->matrix);


    /* Translate the matrix from
     * (unnormalized dst -> unnormalized src) to
     * (unnormalized dst -> normalized src)
     */
    if (_cairo_gl_device_requires_power_of_two_textures (dst->base.device)) {
	cairo_matrix_init_scale (&m,
				 1.0,
				 1.0);
    } else {
	cairo_matrix_init_scale (&m,
				 1.0 / surface->width,
				 1.0 / surface->height);
    }
    cairo_matrix_multiply (&attributes->matrix,
			   &attributes->matrix,
			   &m);

    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_cairo_gl_solid_operand_init (cairo_gl_operand_t *operand,
	                      const cairo_color_t *color)
{
    operand->type = CAIRO_GL_OPERAND_CONSTANT;
    operand->constant.color[0] = color->red   * color->alpha;
    operand->constant.color[1] = color->green * color->alpha;
    operand->constant.color[2] = color->blue  * color->alpha;
    operand->constant.color[3] = color->alpha;
    return CAIRO_STATUS_SUCCESS;
}

static cairo_status_t
_cairo_gl_gradient_operand_init (cairo_gl_operand_t *operand,
				 cairo_gl_surface_t *dst,
                                 const cairo_pattern_t *pattern)
{
    const cairo_gradient_pattern_t *gradient = (const cairo_gradient_pattern_t *)pattern;
    cairo_status_t status;

    if (! _cairo_gl_device_has_glsl (dst->base.device))
	return CAIRO_INT_STATUS_UNSUPPORTED;

    if (gradient->base.type == CAIRO_PATTERN_TYPE_LINEAR) {
	cairo_linear_pattern_t *linear = (cairo_linear_pattern_t *) gradient;
        double x0, y0, x1, y1;

	x0 = _cairo_fixed_to_double (linear->p1.x);
	x1 = _cairo_fixed_to_double (linear->p2.x);
	y0 = _cairo_fixed_to_double (linear->p1.y);
	y1 = _cairo_fixed_to_double (linear->p2.y);

        status = _cairo_gl_create_gradient_texture (dst,
                                                    gradient,
                                                    &operand->linear.gradient);
        if (unlikely (status))
            return status;

	/* Translation matrix from the destination fragment coordinates
	 * (pixels from lower left = 0,0) to the coordinates in the
	 */
	cairo_matrix_init_translate (&operand->linear.m, -x0, -y0);
	cairo_matrix_multiply (&operand->linear.m,
			       &pattern->matrix,
			       &operand->linear.m);
	cairo_matrix_translate (&operand->linear.m, 0, dst->height);
	cairo_matrix_scale (&operand->linear.m, 1.0, -1.0);

	operand->linear.segment_x = x1 - x0;
	operand->linear.segment_y = y1 - y0;

        operand->linear.extend = pattern->extend;

	operand->type = CAIRO_GL_OPERAND_LINEAR_GRADIENT;
        return CAIRO_STATUS_SUCCESS;
    } else {
	cairo_radial_pattern_t *radial = (cairo_radial_pattern_t *) gradient;
        double x0, y0, r0, x1, y1, r1;

	x0 = _cairo_fixed_to_double (radial->c1.x);
	x1 = _cairo_fixed_to_double (radial->c2.x);
	y0 = _cairo_fixed_to_double (radial->c1.y);
	y1 = _cairo_fixed_to_double (radial->c2.y);
	r0 = _cairo_fixed_to_double (radial->r1);
	r1 = _cairo_fixed_to_double (radial->r2);

        status = _cairo_gl_create_gradient_texture (dst,
                                                    gradient,
                                                    &operand->radial.gradient);
        if (unlikely (status))
            return status;

	/* Translation matrix from the destination fragment coordinates
	 * (pixels from lower left = 0,0) to the coordinates in the
	 */
	cairo_matrix_init_translate (&operand->radial.m, -x0, -y0);
	cairo_matrix_multiply (&operand->radial.m,
			       &pattern->matrix,
			       &operand->radial.m);
	cairo_matrix_translate (&operand->radial.m, 0, dst->height);
	cairo_matrix_scale (&operand->radial.m, 1.0, -1.0);

	operand->radial.circle_1_x = x1 - x0;
	operand->radial.circle_1_y = y1 - y0;
	operand->radial.radius_0 = r0;
	operand->radial.radius_1 = r1;

        operand->radial.extend = pattern->extend;

	operand->type = CAIRO_GL_OPERAND_RADIAL_GRADIENT;
        return CAIRO_STATUS_SUCCESS;
    }

    return CAIRO_INT_STATUS_UNSUPPORTED;
}

static void
_cairo_gl_operand_destroy (cairo_gl_operand_t *operand)
{
    switch (operand->type) {
    case CAIRO_GL_OPERAND_CONSTANT:
	break;
    case CAIRO_GL_OPERAND_LINEAR_GRADIENT:
	_cairo_gl_gradient_destroy (operand->linear.gradient);
	break;
    case CAIRO_GL_OPERAND_RADIAL_GRADIENT:
	_cairo_gl_gradient_destroy (operand->radial.gradient);
	break;
    case CAIRO_GL_OPERAND_TEXTURE:
        _cairo_pattern_release_surface (NULL, /* XXX */
                                        &operand->texture.surface->base,
                                        &operand->texture.attributes);
	break;
    default:
    case CAIRO_GL_OPERAND_COUNT:
        ASSERT_NOT_REACHED;
    case CAIRO_GL_OPERAND_NONE:
    case CAIRO_GL_OPERAND_SPANS:
        break;
    }

    operand->type = CAIRO_GL_OPERAND_NONE;
}

static cairo_int_status_t
_cairo_gl_operand_init (cairo_gl_operand_t *operand,
		        const cairo_pattern_t *pattern,
		        cairo_gl_surface_t *dst,
		        int src_x, int src_y,
		        int dst_x, int dst_y,
		        int width, int height)
{
    cairo_status_t status;

    switch (pattern->type) {
    case CAIRO_PATTERN_TYPE_SOLID:
	return _cairo_gl_solid_operand_init (operand,
		                             &((cairo_solid_pattern_t *) pattern)->color);
    case CAIRO_PATTERN_TYPE_LINEAR:
    case CAIRO_PATTERN_TYPE_RADIAL:
	status = _cairo_gl_gradient_operand_init (operand, dst, pattern);
	if (status != CAIRO_INT_STATUS_UNSUPPORTED)
	    return status;

	/* fall through */

    default:
    case CAIRO_PATTERN_TYPE_SURFACE:
	return _cairo_gl_pattern_texture_setup (operand,
						pattern, dst,
						src_x, src_y,
						dst_x, dst_y,
						width, height);
    }
}

cairo_int_status_t
_cairo_gl_composite_set_source (cairo_gl_composite_t *setup,
			        const cairo_pattern_t *pattern,
                                int src_x, int src_y,
                                int dst_x, int dst_y,
                                int width, int height)
{
    _cairo_gl_operand_destroy (&setup->src);
    return _cairo_gl_operand_init (&setup->src, pattern,
                                   setup->dst,
                                   src_x, src_y,
                                   dst_x, dst_y,
                                   width, height);
}

cairo_int_status_t
_cairo_gl_composite_set_mask (cairo_gl_composite_t *setup,
			      const cairo_pattern_t *pattern,
                              int src_x, int src_y,
                              int dst_x, int dst_y,
                              int width, int height)
{
    _cairo_gl_operand_destroy (&setup->mask);
    if (pattern == NULL)
        return CAIRO_STATUS_SUCCESS;

    return _cairo_gl_operand_init (&setup->mask, pattern,
                                   setup->dst,
                                   src_x, src_y,
                                   dst_x, dst_y,
                                   width, height);
}

void
_cairo_gl_composite_set_mask_spans (cairo_gl_composite_t *setup)
{
    _cairo_gl_operand_destroy (&setup->mask);
    setup->mask.type = CAIRO_GL_OPERAND_SPANS;
}

void
_cairo_gl_composite_set_clip_region (cairo_gl_composite_t *setup,
                                     cairo_region_t *clip_region)
{
    setup->clip_region = clip_region;
}

static void
_cairo_gl_operand_bind_to_shader (cairo_gl_context_t *ctx,
                                  cairo_gl_operand_t *operand,
                                  cairo_gl_tex_t      tex_unit)
{
    char uniform_name[50];
    char *custom_part;
    static const char *names[] = { "source", "mask" };

    strcpy (uniform_name, names[tex_unit]);
    custom_part = uniform_name + strlen (names[tex_unit]);

    switch (operand->type) {
    default:
    case CAIRO_GL_OPERAND_COUNT:
        ASSERT_NOT_REACHED;
    case CAIRO_GL_OPERAND_NONE:
    case CAIRO_GL_OPERAND_SPANS:
        break;
    case CAIRO_GL_OPERAND_CONSTANT:
        strcpy (custom_part, "_constant");
	_cairo_gl_shader_bind_vec4 (ctx,
                                    uniform_name,
                                    operand->constant.color[0],
                                    operand->constant.color[1],
                                    operand->constant.color[2],
                                    operand->constant.color[3]);
        break;
    case CAIRO_GL_OPERAND_LINEAR_GRADIENT:
        strcpy (custom_part, "_matrix");
	_cairo_gl_shader_bind_matrix (ctx,
                                      uniform_name,
				      &operand->linear.m);
        strcpy (custom_part, "_segment");
	_cairo_gl_shader_bind_vec2   (ctx,
                                      uniform_name,
				      operand->linear.segment_x,
				      operand->linear.segment_y);
        strcpy (custom_part, "_sampler");
	_cairo_gl_shader_bind_texture(ctx,
                                      uniform_name,
                                      tex_unit);
        break;
    case CAIRO_GL_OPERAND_RADIAL_GRADIENT:
        strcpy (custom_part, "_matrix");
        _cairo_gl_shader_bind_matrix (ctx,
                                      uniform_name,
                                      &operand->radial.m);
        strcpy (custom_part, "_circle_1");
        _cairo_gl_shader_bind_vec2   (ctx,
                                      uniform_name,
                                      operand->radial.circle_1_x,
                                      operand->radial.circle_1_y);
        strcpy (custom_part, "_radius_0");
        _cairo_gl_shader_bind_float  (ctx,
                                      uniform_name,
                                      operand->radial.radius_0);
        strcpy (custom_part, "_radius_1");
        _cairo_gl_shader_bind_float  (ctx,
                                      uniform_name,
                                      operand->radial.radius_1);
        strcpy (custom_part, "_sampler");
	_cairo_gl_shader_bind_texture(ctx,
                                      uniform_name,
                                      tex_unit);
        break;
    case CAIRO_GL_OPERAND_TEXTURE:
        strcpy (custom_part, "_sampler");
	_cairo_gl_shader_bind_texture(ctx,
                                      uniform_name,
                                      tex_unit);
        break;
    }
}

static void
_cairo_gl_composite_bind_to_shader (cairo_gl_context_t   *ctx,
				    cairo_gl_composite_t *setup)
{
    if (ctx->current_shader == NULL)
        return;

    _cairo_gl_operand_bind_to_shader (ctx, &setup->src,  CAIRO_GL_TEX_SOURCE);
    _cairo_gl_operand_bind_to_shader (ctx, &setup->mask, CAIRO_GL_TEX_MASK);
}

static void
_cairo_gl_texture_set_extend (cairo_gl_context_t *ctx,
                              GLuint              target,
                              cairo_extend_t      extend)
{
    assert (! _cairo_gl_device_requires_power_of_two_textures (&ctx->base) ||
            (extend != CAIRO_EXTEND_REPEAT && extend != CAIRO_EXTEND_REFLECT));

    switch (extend) {
    case CAIRO_EXTEND_NONE:
	glTexParameteri (target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri (target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	break;
    case CAIRO_EXTEND_PAD:
	glTexParameteri (target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri (target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	break;
    case CAIRO_EXTEND_REPEAT:
	glTexParameteri (target, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (target, GL_TEXTURE_WRAP_T, GL_REPEAT);
	break;
    case CAIRO_EXTEND_REFLECT:
	glTexParameteri (target, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri (target, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	break;
    }
}

static void
_cairo_gl_texture_set_filter (cairo_gl_context_t *ctx,
                              GLuint              target,
                              cairo_filter_t      filter)
{
    switch (filter) {
    case CAIRO_FILTER_FAST:
    case CAIRO_FILTER_NEAREST:
	glTexParameteri (target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri (target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	break;
    case CAIRO_FILTER_GOOD:
    case CAIRO_FILTER_BEST:
    case CAIRO_FILTER_BILINEAR:
	glTexParameteri (target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri (target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	break;
    default:
    case CAIRO_FILTER_GAUSSIAN:
	ASSERT_NOT_REACHED;
    }
}

static void
_cairo_gl_operand_setup_fixed (cairo_gl_operand_t *operand,
                               cairo_gl_tex_t tex_unit)
{
    switch (operand->type) {
    case CAIRO_GL_OPERAND_CONSTANT:
        glTexEnvfv (GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, operand->constant.color);
        glTexEnvi (GL_TEXTURE_ENV, GL_SRC0_RGB, GL_CONSTANT);
        glTexEnvi (GL_TEXTURE_ENV, GL_SRC0_ALPHA, GL_CONSTANT);
        break;
    case CAIRO_GL_OPERAND_TEXTURE:
        glTexEnvi (GL_TEXTURE_ENV, GL_SRC0_RGB, GL_TEXTURE0 + tex_unit);
        glTexEnvi (GL_TEXTURE_ENV, GL_SRC0_ALPHA, GL_TEXTURE0 + tex_unit);
        break;
    case CAIRO_GL_OPERAND_SPANS:
        glTexEnvi (GL_TEXTURE_ENV, GL_SRC0_RGB, GL_PRIMARY_COLOR);
        glTexEnvi (GL_TEXTURE_ENV, GL_SRC0_ALPHA, GL_PRIMARY_COLOR);
        break;
    case CAIRO_GL_OPERAND_COUNT:
    default:
        ASSERT_NOT_REACHED;
    case CAIRO_GL_OPERAND_LINEAR_GRADIENT:
    case CAIRO_GL_OPERAND_RADIAL_GRADIENT:
    case CAIRO_GL_OPERAND_NONE:
        return;
    }

    switch (tex_unit) {
    case CAIRO_GL_TEX_TEMP:
    default:
        ASSERT_NOT_REACHED;
        break;
    case CAIRO_GL_TEX_SOURCE:
        glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
        glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_REPLACE);
        glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_REPLACE);
        glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
        glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_ALPHA, GL_SRC_ALPHA);
        break;

    case CAIRO_GL_TEX_MASK:
        glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
        glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_MODULATE);
        glTexEnvi (GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_MODULATE);

        glTexEnvi (GL_TEXTURE_ENV, GL_SRC1_RGB, GL_PREVIOUS);
        glTexEnvi (GL_TEXTURE_ENV, GL_SRC1_ALPHA, GL_PREVIOUS);
        glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_SRC_COLOR);
        glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND1_ALPHA, GL_SRC_ALPHA);

        if (operand->type == CAIRO_GL_OPERAND_TEXTURE &&
            operand->texture.attributes.has_component_alpha)
            glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
        else
            glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_ALPHA);
        glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_ALPHA, GL_SRC_ALPHA);
        break;
    }
}

static cairo_bool_t
_cairo_gl_operand_needs_setup (cairo_gl_operand_t *dest,
                               cairo_gl_operand_t *source,
                               unsigned int        vertex_offset)
{
    if (dest->type != source->type)
        return TRUE;
    if (dest->vertex_offset != vertex_offset)
        return TRUE;

    switch (source->type) {
    case CAIRO_GL_OPERAND_NONE:
    case CAIRO_GL_OPERAND_SPANS:
        return FALSE;
    case CAIRO_GL_OPERAND_CONSTANT:
        return dest->constant.color[0] != source->constant.color[0] ||
               dest->constant.color[1] != source->constant.color[1] ||
               dest->constant.color[2] != source->constant.color[2] ||
               dest->constant.color[3] != source->constant.color[3];
    case CAIRO_GL_OPERAND_TEXTURE:
        return dest->texture.surface != source->texture.surface ||
               dest->texture.attributes.extend != source->texture.attributes.extend ||
               dest->texture.attributes.filter != source->texture.attributes.filter ||
               dest->texture.attributes.has_component_alpha != source->texture.attributes.has_component_alpha;
    case CAIRO_GL_OPERAND_LINEAR_GRADIENT:
    case CAIRO_GL_OPERAND_RADIAL_GRADIENT:
        /* XXX: improve this */
        return TRUE;
    default:
    case CAIRO_GL_OPERAND_COUNT:
        ASSERT_NOT_REACHED;
        break;
    }
    return TRUE;
}

static void
_cairo_gl_context_setup_operand (cairo_gl_context_t *ctx,
                                 cairo_gl_tex_t      tex_unit,
                                 cairo_gl_operand_t *operand,
                                 unsigned int        vertex_size,
                                 unsigned int        vertex_offset,
                                 cairo_bool_t        use_shaders)
{
    cairo_bool_t needs_setup;

    /* XXX: we need to do setup when switching from shaders
     * to no shaders (or back) */
    needs_setup = ctx->vertex_size != vertex_size;
    needs_setup |= _cairo_gl_operand_needs_setup (&ctx->operands[tex_unit],
                                                 operand,
                                                 vertex_offset);

    if (needs_setup) {
        _cairo_gl_composite_flush (ctx);
        _cairo_gl_context_destroy_operand (ctx, tex_unit);
    }

    memcpy (&ctx->operands[tex_unit], operand, sizeof (cairo_gl_operand_t));
    ctx->operands[tex_unit].vertex_offset = vertex_offset;

    if (! needs_setup)
        return;

    switch (operand->type) {
    default:
    case CAIRO_GL_OPERAND_COUNT:
        ASSERT_NOT_REACHED;
    case CAIRO_GL_OPERAND_NONE:
        break;
    case CAIRO_GL_OPERAND_SPANS:
	glColorPointer (4, GL_UNSIGNED_BYTE, vertex_size,
                        (void *) (uintptr_t) vertex_offset);
	glEnableClientState (GL_COLOR_ARRAY);
        /* fall through */
    case CAIRO_GL_OPERAND_CONSTANT:
        if (! use_shaders) {
            glActiveTexture (GL_TEXTURE0 + tex_unit);
            /* Have to have a dummy texture bound in order to use the combiner unit. */
            glBindTexture (ctx->tex_target, ctx->dummy_tex);
            glEnable (ctx->tex_target);
        }
        break;
    case CAIRO_GL_OPERAND_TEXTURE:
        glActiveTexture (GL_TEXTURE0 + tex_unit);
        glBindTexture (ctx->tex_target, operand->texture.tex);
        glEnable (ctx->tex_target);
        _cairo_gl_texture_set_extend (ctx, ctx->tex_target,
                                      operand->texture.attributes.extend);
        _cairo_gl_texture_set_filter (ctx, ctx->tex_target,
                                      operand->texture.attributes.filter);

	glClientActiveTexture (GL_TEXTURE0 + tex_unit);
	glTexCoordPointer (2, GL_FLOAT, vertex_size,
                           (void *) (uintptr_t) vertex_offset);
	glEnableClientState (GL_TEXTURE_COORD_ARRAY);
        break;
    case CAIRO_GL_OPERAND_LINEAR_GRADIENT:
        _cairo_gl_gradient_reference (operand->linear.gradient);
        glActiveTexture (GL_TEXTURE0 + tex_unit);
        glBindTexture (GL_TEXTURE_1D, operand->linear.gradient->tex);
        _cairo_gl_texture_set_extend (ctx, GL_TEXTURE_1D, operand->linear.extend);
        _cairo_gl_texture_set_filter (ctx, GL_TEXTURE_1D, CAIRO_FILTER_BILINEAR);
        glEnable (GL_TEXTURE_1D);
        break;
    case CAIRO_GL_OPERAND_RADIAL_GRADIENT:
        _cairo_gl_gradient_reference (operand->radial.gradient);
        glActiveTexture (GL_TEXTURE0 + tex_unit);
        glBindTexture (GL_TEXTURE_1D, operand->radial.gradient->tex);
        _cairo_gl_texture_set_extend (ctx, GL_TEXTURE_1D, operand->radial.extend);
        _cairo_gl_texture_set_filter (ctx, GL_TEXTURE_1D, CAIRO_FILTER_BILINEAR);
        glEnable (GL_TEXTURE_1D);
        break;
    }

    if (! use_shaders)
        _cairo_gl_operand_setup_fixed (operand, tex_unit);
}

void
_cairo_gl_context_destroy_operand (cairo_gl_context_t *ctx,
                                   cairo_gl_tex_t tex_unit)
{
    assert (_cairo_gl_context_is_flushed (ctx));

    switch (ctx->operands[tex_unit].type) {
    default:
    case CAIRO_GL_OPERAND_COUNT:
        ASSERT_NOT_REACHED;
    case CAIRO_GL_OPERAND_NONE:
        break;
    case CAIRO_GL_OPERAND_SPANS:
        glDisableClientState (GL_COLOR_ARRAY);
        /* fall through */
    case CAIRO_GL_OPERAND_CONSTANT:
        if (ctx->current_shader == NULL) {
            glActiveTexture (GL_TEXTURE0 + tex_unit);
            glDisable (ctx->tex_target);
        }
        break;
    case CAIRO_GL_OPERAND_TEXTURE:
        glActiveTexture (GL_TEXTURE0 + tex_unit);
        glDisable (ctx->tex_target);
        glClientActiveTexture (GL_TEXTURE0 + tex_unit);
        glDisableClientState (GL_TEXTURE_COORD_ARRAY);
        break;
    case CAIRO_GL_OPERAND_LINEAR_GRADIENT:
        _cairo_gl_gradient_destroy (ctx->operands[tex_unit].linear.gradient);
        glActiveTexture (GL_TEXTURE0 + tex_unit);
        glDisable (GL_TEXTURE_1D);
        break;
    case CAIRO_GL_OPERAND_RADIAL_GRADIENT:
        _cairo_gl_gradient_destroy (ctx->operands[tex_unit].radial.gradient);
        glActiveTexture (GL_TEXTURE0 + tex_unit);
        glDisable (GL_TEXTURE_1D);
        break;
    }

    memset (&ctx->operands[tex_unit], 0, sizeof (cairo_gl_operand_t));
}

/* Swizzles the source for creating the "source alpha" value
 * (src.aaaa * mask.argb) required by component alpha rendering.
 */
static void
_cairo_gl_set_src_alpha (cairo_gl_context_t *ctx,
                         cairo_bool_t activate)
{
    if (ctx->current_shader)
        return;

    glActiveTexture (GL_TEXTURE0);

    glTexEnvi (GL_TEXTURE_ENV, GL_OPERAND0_RGB, activate ? GL_SRC_ALPHA : GL_SRC_COLOR);
}

static void
_cairo_gl_set_operator (cairo_gl_context_t *ctx,
                        cairo_operator_t    op,
			cairo_bool_t        component_alpha)
{
    struct {
	GLenum src;
	GLenum dst;
    } blend_factors[] = {
	{ GL_ZERO, GL_ZERO }, /* Clear */
	{ GL_ONE, GL_ZERO }, /* Source */
	{ GL_ONE, GL_ONE_MINUS_SRC_ALPHA }, /* Over */
	{ GL_DST_ALPHA, GL_ZERO }, /* In */
	{ GL_ONE_MINUS_DST_ALPHA, GL_ZERO }, /* Out */
	{ GL_DST_ALPHA, GL_ONE_MINUS_SRC_ALPHA }, /* Atop */

	{ GL_ZERO, GL_ONE }, /* Dest */
	{ GL_ONE_MINUS_DST_ALPHA, GL_ONE }, /* DestOver */
	{ GL_ZERO, GL_SRC_ALPHA }, /* DestIn */
	{ GL_ZERO, GL_ONE_MINUS_SRC_ALPHA }, /* DestOut */
	{ GL_ONE_MINUS_DST_ALPHA, GL_SRC_ALPHA }, /* DestAtop */

	{ GL_ONE_MINUS_DST_ALPHA, GL_ONE_MINUS_SRC_ALPHA }, /* Xor */
	{ GL_ONE, GL_ONE }, /* Add */
    };
    GLenum src_factor, dst_factor;

    assert (op < ARRAY_LENGTH (blend_factors));
    /* different dst and component_alpha changes cause flushes elsewhere */
    if (ctx->current_operator != op)
        _cairo_gl_composite_flush (ctx);
    ctx->current_operator = op;

    src_factor = blend_factors[op].src;
    dst_factor = blend_factors[op].dst;

    /* Even when the user requests CAIRO_CONTENT_COLOR, we use GL_RGBA
     * due to texture filtering of GL_CLAMP_TO_BORDER.  So fix those
     * bits in that case.
     */
    if (ctx->current_target->base.content == CAIRO_CONTENT_COLOR) {
	if (src_factor == GL_ONE_MINUS_DST_ALPHA)
	    src_factor = GL_ZERO;
	if (src_factor == GL_DST_ALPHA)
	    src_factor = GL_ONE;
    }

    if (component_alpha) {
	if (dst_factor == GL_ONE_MINUS_SRC_ALPHA)
	    dst_factor = GL_ONE_MINUS_SRC_COLOR;
	if (dst_factor == GL_SRC_ALPHA)
	    dst_factor = GL_SRC_COLOR;
    }

    if (ctx->current_target->base.content == CAIRO_CONTENT_ALPHA) {
        glBlendFuncSeparate (GL_ZERO, GL_ZERO, src_factor, dst_factor);
    } else if (ctx->current_target->base.content == CAIRO_CONTENT_COLOR) {
        glBlendFuncSeparate (src_factor, dst_factor, GL_ONE, GL_ONE);
    } else {
        glBlendFunc (src_factor, dst_factor);
    }
}

static unsigned int
_cairo_gl_operand_get_vertex_size (cairo_gl_operand_type_t type)
{
    switch (type) {
    default:
    case CAIRO_GL_OPERAND_COUNT:
        ASSERT_NOT_REACHED;
    case CAIRO_GL_OPERAND_NONE:
    case CAIRO_GL_OPERAND_CONSTANT:
    case CAIRO_GL_OPERAND_LINEAR_GRADIENT:
    case CAIRO_GL_OPERAND_RADIAL_GRADIENT:
        return 0;
    case CAIRO_GL_OPERAND_SPANS:
        return 4 * sizeof (GLbyte);
    case CAIRO_GL_OPERAND_TEXTURE:
        return 2 * sizeof (GLfloat);
    }
}

static cairo_status_t
_cairo_gl_composite_begin_component_alpha  (cairo_gl_context_t *ctx,
                                            cairo_gl_composite_t *setup)
{
    cairo_gl_shader_t *pre_shader = NULL;
    cairo_status_t status;

    /* For CLEAR, cairo's rendering equation (quoting Owen's description in:
     * http://lists.cairographics.org/archives/cairo/2005-August/004992.html)
     * is:
     *     mask IN clip ? src OP dest : dest
     * or more simply:
     *     mask IN CLIP ? 0 : dest
     *
     * where the ternary operator A ? B : C is (A * B) + ((1 - A) * C).
     *
     * The model we use in _cairo_gl_set_operator() is Render's:
     *     src IN mask IN clip OP dest
     * which would boil down to:
     *     0 (bounded by the extents of the drawing).
     *
     * However, we can do a Render operation using an opaque source
     * and DEST_OUT to produce:
     *    1 IN mask IN clip DEST_OUT dest
     * which is
     *    mask IN clip ? 0 : dest
     */
    if (setup->op == CAIRO_OPERATOR_CLEAR) {
        _cairo_gl_solid_operand_init (&setup->src, CAIRO_COLOR_WHITE);
	setup->op = CAIRO_OPERATOR_DEST_OUT;
    }

    /*
     * implements component-alpha %CAIRO_OPERATOR_OVER using two passes of
     * the simpler operations %CAIRO_OPERATOR_DEST_OUT and %CAIRO_OPERATOR_ADD.
     *
     * From http://anholt.livejournal.com/32058.html:
     *
     * The trouble is that component-alpha rendering requires two different sources
     * for blending: one for the source value to the blender, which is the
     * per-channel multiplication of source and mask, and one for the source alpha
     * for multiplying with the destination channels, which is the multiplication
     * of the source channels by the mask alpha. So the equation for Over is:
     *
     * dst.A = src.A * mask.A + (1 - (src.A * mask.A)) * dst.A
     * dst.R = src.R * mask.R + (1 - (src.A * mask.R)) * dst.R
     * dst.G = src.G * mask.G + (1 - (src.A * mask.G)) * dst.G
     * dst.B = src.B * mask.B + (1 - (src.A * mask.B)) * dst.B
     *
     * But we can do some simpler operations, right? How about PictOpOutReverse,
     * which has a source factor of 0 and dest factor of (1 - source alpha). We
     * can get the source alpha value (srca.X = src.A * mask.X) out of the texture
     * blenders pretty easily. So we can do a component-alpha OutReverse, which
     * gets us:
     *
     * dst.A = 0 + (1 - (src.A * mask.A)) * dst.A
     * dst.R = 0 + (1 - (src.A * mask.R)) * dst.R
     * dst.G = 0 + (1 - (src.A * mask.G)) * dst.G
     * dst.B = 0 + (1 - (src.A * mask.B)) * dst.B
     *
     * OK. And if an op doesn't use the source alpha value for the destination
     * factor, then we can do the channel multiplication in the texture blenders
     * to get the source value, and ignore the source alpha that we wouldn't use.
     * We've supported this in the Radeon driver for a long time. An example would
     * be PictOpAdd, which does:
     *
     * dst.A = src.A * mask.A + dst.A
     * dst.R = src.R * mask.R + dst.R
     * dst.G = src.G * mask.G + dst.G
     * dst.B = src.B * mask.B + dst.B
     *
     * Hey, this looks good! If we do a PictOpOutReverse and then a PictOpAdd right
     * after it, we get:
     *
     * dst.A = src.A * mask.A + ((1 - (src.A * mask.A)) * dst.A)
     * dst.R = src.R * mask.R + ((1 - (src.A * mask.R)) * dst.R)
     * dst.G = src.G * mask.G + ((1 - (src.A * mask.G)) * dst.G)
     * dst.B = src.B * mask.B + ((1 - (src.A * mask.B)) * dst.B)
     *
     * This two-pass trickery could be avoided using a new GL extension that
     * lets two values come out of the shader and into the blend unit.
     */
    if (setup->op == CAIRO_OPERATOR_OVER) {
	setup->op = CAIRO_OPERATOR_ADD;
	status = _cairo_gl_get_shader_by_type (ctx,
                                               setup->src.type,
                                               setup->mask.type,
                                               CAIRO_GL_SHADER_IN_CA_SOURCE_ALPHA,
                                               &pre_shader);
        if (unlikely (status))
            return status;
    }

    if (ctx->pre_shader != pre_shader)
        _cairo_gl_composite_flush (ctx);
    ctx->pre_shader = pre_shader;

    return CAIRO_STATUS_SUCCESS;
}

cairo_status_t
_cairo_gl_composite_begin (cairo_gl_composite_t *setup,
                           cairo_gl_context_t **ctx_out)
{
    unsigned int dst_size, src_size, mask_size, vertex_size;
    cairo_gl_context_t *ctx;
    cairo_status_t status;
    cairo_bool_t component_alpha;
    cairo_gl_shader_t *shader;

    assert (setup->dst);

    status = _cairo_gl_context_acquire (setup->dst->base.device, &ctx);
    if (unlikely (status))
	return status;

    glEnable (GL_BLEND);

    component_alpha = ((setup->mask.type == CAIRO_GL_OPERAND_TEXTURE) &&
                       setup->mask.texture.attributes.has_component_alpha);

    /* Do various magic for component alpha */
    if (component_alpha) {
        status = _cairo_gl_composite_begin_component_alpha (ctx, setup);
        if (unlikely (status))
            goto FAIL;
    } else {
        if (ctx->pre_shader) {
            _cairo_gl_composite_flush (ctx);
            ctx->pre_shader = NULL;
        }
    }

    status = _cairo_gl_get_shader_by_type (ctx,
                                           setup->src.type,
                                           setup->mask.type,
                                           component_alpha ? CAIRO_GL_SHADER_IN_CA_SOURCE
                                                           : CAIRO_GL_SHADER_IN_NORMAL,
                                           &shader);
    if (unlikely (status)) {
        ctx->pre_shader = NULL;
        goto FAIL;
    }
    if (ctx->current_shader != shader)
        _cairo_gl_composite_flush (ctx);

    status = CAIRO_STATUS_SUCCESS;

    dst_size  = 2 * sizeof (GLfloat);
    src_size  = _cairo_gl_operand_get_vertex_size (setup->src.type);
    mask_size = _cairo_gl_operand_get_vertex_size (setup->mask.type);

    vertex_size = dst_size + src_size + mask_size;
    if (ctx->vertex_size != vertex_size) {
        _cairo_gl_composite_flush (ctx);
    }

    _cairo_gl_context_set_destination (ctx, setup->dst);

    if (_cairo_gl_context_is_flushed (ctx)) {
        glBindBufferARB (GL_ARRAY_BUFFER_ARB, ctx->vbo);

        glVertexPointer (2, GL_FLOAT, vertex_size, NULL);
        glEnableClientState (GL_VERTEX_ARRAY);
    }

    _cairo_gl_context_setup_operand (ctx, CAIRO_GL_TEX_SOURCE, &setup->src, vertex_size, dst_size, shader != NULL);
    _cairo_gl_context_setup_operand (ctx, CAIRO_GL_TEX_MASK, &setup->mask, vertex_size, dst_size + src_size, shader != NULL);

    _cairo_gl_set_operator (ctx,
                            setup->op,
                            component_alpha);

    ctx->vertex_size = vertex_size;

    if (_cairo_gl_context_is_flushed (ctx)) {
        if (ctx->pre_shader) {
            _cairo_gl_set_shader (ctx, ctx->pre_shader);
            _cairo_gl_composite_bind_to_shader (ctx, setup);
        }
        _cairo_gl_set_shader (ctx, shader);
        _cairo_gl_composite_bind_to_shader (ctx, setup);
    }

    if (! _cairo_gl_context_is_flushed (ctx) &&
        ! cairo_region_equal (ctx->clip_region, setup->clip_region))
        _cairo_gl_composite_flush (ctx);
    cairo_region_destroy (ctx->clip_region);
    ctx->clip_region = cairo_region_reference (setup->clip_region);
    if (ctx->clip_region)
	glEnable (GL_SCISSOR_TEST);
    else
	glDisable (GL_SCISSOR_TEST);

    *ctx_out = ctx;

FAIL:
    if (unlikely (status))
        status = _cairo_gl_context_release (ctx, status);

    return status;
}

static inline void
_cairo_gl_composite_draw (cairo_gl_context_t *ctx,
			  unsigned int count)
{
    if (! ctx->pre_shader) {
        glDrawArrays (GL_TRIANGLES, 0, count);
    } else {
        cairo_gl_shader_t *prev_shader = ctx->current_shader;

        _cairo_gl_set_shader (ctx, ctx->pre_shader);
        _cairo_gl_set_operator (ctx, CAIRO_OPERATOR_DEST_OUT, TRUE);
        _cairo_gl_set_src_alpha (ctx, TRUE);
        glDrawArrays (GL_TRIANGLES, 0, count);
        _cairo_gl_set_src_alpha (ctx, FALSE);

        _cairo_gl_set_shader (ctx, prev_shader);
        _cairo_gl_set_operator (ctx, CAIRO_OPERATOR_ADD, TRUE);
        glDrawArrays (GL_TRIANGLES, 0, count);
    }
}

void
_cairo_gl_composite_flush (cairo_gl_context_t *ctx)
{
    unsigned int count;

    if (_cairo_gl_context_is_flushed (ctx))
        return;

    count = ctx->vb_offset / ctx->vertex_size;

    glUnmapBufferARB (GL_ARRAY_BUFFER_ARB);
    ctx->vb = NULL;
    ctx->vb_offset = 0;

    if (ctx->clip_region) {
	int i, num_rectangles = cairo_region_num_rectangles (ctx->clip_region);

	for (i = 0; i < num_rectangles; i++) {
	    cairo_rectangle_int_t rect;

	    cairo_region_get_rectangle (ctx->clip_region, i, &rect);

	    glScissor (rect.x, rect.y, rect.width, rect.height);
            _cairo_gl_composite_draw (ctx, count);
	}
    } else {
        _cairo_gl_composite_draw (ctx, count);
    }
}

static void
_cairo_gl_composite_prepare_buffer (cairo_gl_context_t *ctx,
                                    unsigned int n_vertices)
{
    if (ctx->vb_offset + n_vertices * ctx->vertex_size > CAIRO_GL_VBO_SIZE)
	_cairo_gl_composite_flush (ctx);

    if (ctx->vb == NULL) {
	glBufferDataARB (GL_ARRAY_BUFFER_ARB, CAIRO_GL_VBO_SIZE,
			 NULL, GL_STREAM_DRAW_ARB);
	ctx->vb = glMapBufferARB (GL_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
    }
}

static inline void
_cairo_gl_operand_emit (cairo_gl_operand_t *operand,
                        GLfloat ** vb,
                        GLfloat x,
                        GLfloat y,
                        uint8_t alpha)
{
    switch (operand->type) {
    default:
    case CAIRO_GL_OPERAND_COUNT:
        ASSERT_NOT_REACHED;
    case CAIRO_GL_OPERAND_NONE:
    case CAIRO_GL_OPERAND_CONSTANT:
    case CAIRO_GL_OPERAND_LINEAR_GRADIENT:
    case CAIRO_GL_OPERAND_RADIAL_GRADIENT:
        break;
    case CAIRO_GL_OPERAND_SPANS:
        {
            union fi {
                float f;
                GLbyte bytes[4];
            } fi;

            fi.bytes[0] = 0;
            fi.bytes[1] = 0;
            fi.bytes[2] = 0;
            fi.bytes[3] = alpha;
            *(*vb)++ = fi.f;
        }
        break;
    case CAIRO_GL_OPERAND_TEXTURE:
        {
            cairo_surface_attributes_t *src_attributes = &operand->texture.attributes;
            double s = x;
            double t = y;

            cairo_matrix_transform_point (&src_attributes->matrix, &s, &t);
            *(*vb)++ = s;
            *(*vb)++ = t;
        }
        break;
    }
}

static inline void
_cairo_gl_composite_emit_vertex (cairo_gl_context_t *ctx,
                                 GLfloat x,
                                 GLfloat y,
                                 uint8_t alpha)
{
    GLfloat *vb = (GLfloat *) (void *) &ctx->vb[ctx->vb_offset];

    *vb++ = x;
    *vb++ = y;

    _cairo_gl_operand_emit (&ctx->operands[CAIRO_GL_TEX_SOURCE], &vb, x, y, alpha);
    _cairo_gl_operand_emit (&ctx->operands[CAIRO_GL_TEX_MASK  ], &vb, x, y, alpha);

    ctx->vb_offset += ctx->vertex_size;
}

void
_cairo_gl_composite_emit_rect (cairo_gl_context_t *ctx,
                               GLfloat x1,
                               GLfloat y1,
                               GLfloat x2,
                               GLfloat y2,
                               uint8_t alpha)
{
    _cairo_gl_composite_prepare_buffer (ctx, 6);

    _cairo_gl_composite_emit_vertex (ctx, x1, y1, alpha);
    _cairo_gl_composite_emit_vertex (ctx, x2, y1, alpha);
    _cairo_gl_composite_emit_vertex (ctx, x1, y2, alpha);

    _cairo_gl_composite_emit_vertex (ctx, x2, y1, alpha);
    _cairo_gl_composite_emit_vertex (ctx, x2, y2, alpha);
    _cairo_gl_composite_emit_vertex (ctx, x1, y2, alpha);
}

static inline void
_cairo_gl_composite_emit_glyph_vertex (cairo_gl_context_t *ctx,
                                       GLfloat x,
                                       GLfloat y,
                                       GLfloat glyph_x,
                                       GLfloat glyph_y)
{
    GLfloat *vb = (GLfloat *) (void *) &ctx->vb[ctx->vb_offset];

    *vb++ = x;
    *vb++ = y;

    _cairo_gl_operand_emit (&ctx->operands[CAIRO_GL_TEX_SOURCE], &vb, x, y, 0);

    *vb++ = glyph_x;
    *vb++ = glyph_y;

    ctx->vb_offset += ctx->vertex_size;
}

void
_cairo_gl_composite_emit_glyph (cairo_gl_context_t *ctx,
                                GLfloat x1,
                                GLfloat y1,
                                GLfloat x2,
                                GLfloat y2,
                                GLfloat glyph_x1,
                                GLfloat glyph_y1,
                                GLfloat glyph_x2,
                                GLfloat glyph_y2)
{
    _cairo_gl_composite_prepare_buffer (ctx, 6);

    _cairo_gl_composite_emit_glyph_vertex (ctx, x1, y1, glyph_x1, glyph_y1);
    _cairo_gl_composite_emit_glyph_vertex (ctx, x2, y1, glyph_x2, glyph_y1);
    _cairo_gl_composite_emit_glyph_vertex (ctx, x1, y2, glyph_x1, glyph_y2);

    _cairo_gl_composite_emit_glyph_vertex (ctx, x2, y1, glyph_x2, glyph_y1);
    _cairo_gl_composite_emit_glyph_vertex (ctx, x2, y2, glyph_x2, glyph_y2);
    _cairo_gl_composite_emit_glyph_vertex (ctx, x1, y2, glyph_x1, glyph_y2);
}

void
_cairo_gl_composite_fini (cairo_gl_composite_t *setup)
{
    _cairo_gl_operand_destroy (&setup->src);
    _cairo_gl_operand_destroy (&setup->mask);
}

cairo_status_t
_cairo_gl_composite_init (cairo_gl_composite_t *setup,
                          cairo_operator_t op,
                          cairo_gl_surface_t *dst,
                          cairo_bool_t assume_component_alpha,
                          const cairo_rectangle_int_t *rect)
{
    memset (setup, 0, sizeof (cairo_gl_composite_t));

    if (assume_component_alpha) {
        if (op != CAIRO_OPERATOR_CLEAR &&
            op != CAIRO_OPERATOR_OVER &&
            op != CAIRO_OPERATOR_ADD)
            return UNSUPPORTED ("unsupported component alpha operator");
    } else {
        if (! _cairo_gl_operator_is_supported (op))
            return UNSUPPORTED ("unsupported operator");
    }

    setup->dst = dst;
    setup->op = op;

    return CAIRO_STATUS_SUCCESS;
}

