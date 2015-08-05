/*
 * Copyright © 2005 Eric Anholt
 * Copyright © 2009 Chris Wilson
 * Copyright © 2010 Soeren Sandmann
 * Copyright © 2010 Red Hat, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Eric Anholt not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  Eric Anholt makes no
 * representations about the suitability of this software for any purpose.  It
 * is provided "as is" without express or implied warranty.
 *
 * ERIC ANHOLT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL ERIC ANHOLT BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
#define PIXMAN_USE_INTERNAL_API
#include <pixman.h>
#include <stdio.h>
#include <stdlib.h> /* abort() */
#include <math.h>
#include <config.h>
#include <time.h>
#include "utils.h"

typedef struct color_t color_t;
typedef struct format_t format_t;
typedef struct image_t image_t;
typedef struct operator_t operator_t;

struct color_t
{
    double r, g, b, a;
};

struct format_t
{
    pixman_format_code_t format;
    const char *name;
};

static const color_t colors[] =
{
    { 1.0, 1.0, 1.0, 1.0 },
    { 1.0, 1.0, 1.0, 0.0 },
    { 0.0, 0.0, 0.0, 1.0 },
    { 0.0, 0.0, 0.0, 0.0 },
    { 1.0, 0.0, 0.0, 1.0 },
    { 0.0, 1.0, 0.0, 1.0 },
    { 0.0, 0.0, 1.0, 1.0 },
    { 0.5, 0.0, 0.0, 0.5 },
};

static uint16_t
_color_double_to_short (double d)
{
    uint32_t i;

    i = (uint32_t) (d * 65536);
    i -= (i >> 16);

    return i;
}

static void
compute_pixman_color (const color_t *color,
		      pixman_color_t *out)
{
    out->red   = _color_double_to_short (color->r);
    out->green = _color_double_to_short (color->g);
    out->blue  = _color_double_to_short (color->b);
    out->alpha = _color_double_to_short (color->a);
}

#define REPEAT 0x01000000
#define FLAGS  0xff000000

static const int sizes[] =
{
    0,
    1,
    1 | REPEAT,
    10
};

static const format_t formats[] =
{
#define P(x) { PIXMAN_##x, #x }

    /* 32 bpp formats */
    P(a8r8g8b8),
    P(x8r8g8b8),
    P(a8b8g8r8),
    P(x8b8g8r8),
    P(b8g8r8a8),
    P(b8g8r8x8),
    P(r8g8b8a8),
    P(r8g8b8x8),
    P(x2r10g10b10),
    P(x2b10g10r10),
    P(a2r10g10b10),
    P(a2b10g10r10),

    /* 24 bpp formats */
    P(r8g8b8),
    P(b8g8r8),
    P(r5g6b5),
    P(b5g6r5),

    /* 16 bpp formats */
    P(x1r5g5b5),
    P(x1b5g5r5),
    P(a1r5g5b5),
    P(a1b5g5r5),
    P(a4b4g4r4),
    P(x4b4g4r4),
    P(a4r4g4b4),
    P(x4r4g4b4),

    /* 8 bpp formats */
    P(a8),
    P(r3g3b2),
    P(b2g3r3),
    P(a2r2g2b2),
    P(a2b2g2r2),
    P(x4a4),

    /* 4 bpp formats */
    P(a4),
    P(r1g2b1),
    P(b1g2r1),
    P(a1r1g1b1),
    P(a1b1g1r1),

    /* 1 bpp formats */
    P(a1)
#undef P
};

struct image_t
{
    pixman_image_t *image;
    const format_t *format;
    const color_t *color;
    pixman_repeat_t repeat;
    int size;
};

struct operator_t
{
    pixman_op_t op;
    const char *name;
};

static const operator_t operators[] =
{
#define P(x) { PIXMAN_OP_##x, #x }
    P(CLEAR),
    P(SRC),
    P(DST),
    P(OVER),
    P(OVER_REVERSE),
    P(IN),
    P(IN_REVERSE),
    P(OUT),
    P(OUT_REVERSE),
    P(ATOP),
    P(ATOP_REVERSE),
    P(XOR),
    P(ADD),
    P(SATURATE),

    P(DISJOINT_CLEAR),
    P(DISJOINT_SRC),
    P(DISJOINT_DST),
    P(DISJOINT_OVER),
    P(DISJOINT_OVER_REVERSE),
    P(DISJOINT_IN),
    P(DISJOINT_IN_REVERSE),
    P(DISJOINT_OUT),
    P(DISJOINT_OUT_REVERSE),
    P(DISJOINT_ATOP),
    P(DISJOINT_ATOP_REVERSE),
    P(DISJOINT_XOR),

    P(CONJOINT_CLEAR),
    P(CONJOINT_SRC),
    P(CONJOINT_DST),
    P(CONJOINT_OVER),
    P(CONJOINT_OVER_REVERSE),
    P(CONJOINT_IN),
    P(CONJOINT_IN_REVERSE),
    P(CONJOINT_OUT),
    P(CONJOINT_OUT_REVERSE),
    P(CONJOINT_ATOP),
    P(CONJOINT_ATOP_REVERSE),
    P(CONJOINT_XOR),
#undef P
};

static double
calc_op (pixman_op_t op, double src, double dst, double srca, double dsta)
{
#define mult_chan(src, dst, Fa, Fb) MIN ((src) * (Fa) + (dst) * (Fb), 1.0)

    double Fa, Fb;

    switch (op)
    {
    case PIXMAN_OP_CLEAR:
    case PIXMAN_OP_DISJOINT_CLEAR:
    case PIXMAN_OP_CONJOINT_CLEAR:
	return mult_chan (src, dst, 0.0, 0.0);

    case PIXMAN_OP_SRC:
    case PIXMAN_OP_DISJOINT_SRC:
    case PIXMAN_OP_CONJOINT_SRC:
	return mult_chan (src, dst, 1.0, 0.0);

    case PIXMAN_OP_DST:
    case PIXMAN_OP_DISJOINT_DST:
    case PIXMAN_OP_CONJOINT_DST:
	return mult_chan (src, dst, 0.0, 1.0);

    case PIXMAN_OP_OVER:
	return mult_chan (src, dst, 1.0, 1.0 - srca);

    case PIXMAN_OP_OVER_REVERSE:
	return mult_chan (src, dst, 1.0 - dsta, 1.0);

    case PIXMAN_OP_IN:
	return mult_chan (src, dst, dsta, 0.0);

    case PIXMAN_OP_IN_REVERSE:
	return mult_chan (src, dst, 0.0, srca);

    case PIXMAN_OP_OUT:
	return mult_chan (src, dst, 1.0 - dsta, 0.0);

    case PIXMAN_OP_OUT_REVERSE:
	return mult_chan (src, dst, 0.0, 1.0 - srca);

    case PIXMAN_OP_ATOP:
	return mult_chan (src, dst, dsta, 1.0 - srca);

    case PIXMAN_OP_ATOP_REVERSE:
	return mult_chan (src, dst, 1.0 - dsta,  srca);

    case PIXMAN_OP_XOR:
	return mult_chan (src, dst, 1.0 - dsta, 1.0 - srca);

    case PIXMAN_OP_ADD:
	return mult_chan (src, dst, 1.0, 1.0);

    case PIXMAN_OP_SATURATE:
    case PIXMAN_OP_DISJOINT_OVER_REVERSE:
	if (srca == 0.0)
	    Fa = 1.0;
	else
	    Fa = MIN (1.0, (1.0 - dsta) / srca);
	return mult_chan (src, dst, Fa, 1.0);

    case PIXMAN_OP_DISJOINT_OVER:
	if (dsta == 0.0)
	    Fb = 1.0;
	else
	    Fb = MIN (1.0, (1.0 - srca) / dsta);
	return mult_chan (src, dst, 1.0, Fb);

    case PIXMAN_OP_DISJOINT_IN:
	if (srca == 0.0)
	    Fa = 0.0;
	else
	    Fa = MAX (0.0, 1.0 - (1.0 - dsta) / srca);
	return mult_chan (src, dst, Fa, 0.0);

    case PIXMAN_OP_DISJOINT_IN_REVERSE:
	if (dsta == 0.0)
	    Fb = 0.0;
	else
	    Fb = MAX (0.0, 1.0 - (1.0 - srca) / dsta);
	return mult_chan (src, dst, 0.0, Fb);

    case PIXMAN_OP_DISJOINT_OUT:
	if (srca == 0.0)
	    Fa = 1.0;
	else
	    Fa = MIN (1.0, (1.0 - dsta) / srca);
	return mult_chan (src, dst, Fa, 0.0);

    case PIXMAN_OP_DISJOINT_OUT_REVERSE:
	if (dsta == 0.0)
	    Fb = 1.0;
	else
	    Fb = MIN (1.0, (1.0 - srca) / dsta);
	return mult_chan (src, dst, 0.0, Fb);

    case PIXMAN_OP_DISJOINT_ATOP:
	if (srca == 0.0)
	    Fa = 0.0;
	else
	    Fa = MAX (0.0, 1.0 - (1.0 - dsta) / srca);
	if (dsta == 0.0)
	    Fb = 1.0;
	else
	    Fb = MIN (1.0, (1.0 - srca) / dsta);
	return mult_chan (src, dst, Fa, Fb);

    case PIXMAN_OP_DISJOINT_ATOP_REVERSE:
	if (srca == 0.0)
	    Fa = 1.0;
	else
	    Fa = MIN (1.0, (1.0 - dsta) / srca);
	if (dsta == 0.0)
	    Fb = 0.0;
	else
	    Fb = MAX (0.0, 1.0 - (1.0 - srca) / dsta);
	return mult_chan (src, dst, Fa, Fb);

    case PIXMAN_OP_DISJOINT_XOR:
	if (srca == 0.0)
	    Fa = 1.0;
	else
	    Fa = MIN (1.0, (1.0 - dsta) / srca);
	if (dsta == 0.0)
	    Fb = 1.0;
	else
	    Fb = MIN (1.0, (1.0 - srca) / dsta);
	return mult_chan (src, dst, Fa, Fb);

    case PIXMAN_OP_CONJOINT_OVER:
	if (dsta == 0.0)
	    Fb = 0.0;
	else
	    Fb = MAX (0.0, 1.0 - srca / dsta);
	return mult_chan (src, dst, 1.0, Fb);

    case PIXMAN_OP_CONJOINT_OVER_REVERSE:
	if (srca == 0.0)
	    Fa = 0.0;
	else
	    Fa = MAX (0.0, 1.0 - dsta / srca);
	return mult_chan (src, dst, Fa, 1.0);

    case PIXMAN_OP_CONJOINT_IN:
	if (srca == 0.0)
	    Fa = 1.0;
	else
	    Fa = MIN (1.0, dsta / srca);
	return mult_chan (src, dst, Fa, 0.0);

    case PIXMAN_OP_CONJOINT_IN_REVERSE:
	if (dsta == 0.0)
	    Fb = 1.0;
	else
	    Fb = MIN (1.0, srca / dsta);
	return mult_chan (src, dst, 0.0, Fb);

    case PIXMAN_OP_CONJOINT_OUT:
	if (srca == 0.0)
	    Fa = 0.0;
	else
	    Fa = MAX (0.0, 1.0 - dsta / srca);
	return mult_chan (src, dst, Fa, 0.0);

    case PIXMAN_OP_CONJOINT_OUT_REVERSE:
	if (dsta == 0.0)
	    Fb = 0.0;
	else
	    Fb = MAX (0.0, 1.0 - srca / dsta);
	return mult_chan (src, dst, 0.0, Fb);

    case PIXMAN_OP_CONJOINT_ATOP:
	if (srca == 0.0)
	    Fa = 1.0;
	else
	    Fa = MIN (1.0, dsta / srca);
	if (dsta == 0.0)
	    Fb = 0.0;
	else
	    Fb = MAX (0.0, 1.0 - srca / dsta);
	return mult_chan (src, dst, Fa, Fb);

    case PIXMAN_OP_CONJOINT_ATOP_REVERSE:
	if (srca == 0.0)
	    Fa = 0.0;
	else
	    Fa = MAX (0.0, 1.0 - dsta / srca);
	if (dsta == 0.0)
	    Fb = 1.0;
	else
	    Fb = MIN (1.0, srca / dsta);
	return mult_chan (src, dst, Fa, Fb);

    case PIXMAN_OP_CONJOINT_XOR:
	if (srca == 0.0)
	    Fa = 0.0;
	else
	    Fa = MAX (0.0, 1.0 - dsta / srca);
	if (dsta == 0.0)
	    Fb = 0.0;
	else
	    Fb = MAX (0.0, 1.0 - srca / dsta);
	return mult_chan (src, dst, Fa, Fb);

    case PIXMAN_OP_MULTIPLY:
    case PIXMAN_OP_SCREEN:
    case PIXMAN_OP_OVERLAY:
    case PIXMAN_OP_DARKEN:
    case PIXMAN_OP_LIGHTEN:
    case PIXMAN_OP_COLOR_DODGE:
    case PIXMAN_OP_COLOR_BURN:
    case PIXMAN_OP_HARD_LIGHT:
    case PIXMAN_OP_SOFT_LIGHT:
    case PIXMAN_OP_DIFFERENCE:
    case PIXMAN_OP_EXCLUSION:
    case PIXMAN_OP_HSL_HUE:
    case PIXMAN_OP_HSL_SATURATION:
    case PIXMAN_OP_HSL_COLOR:
    case PIXMAN_OP_HSL_LUMINOSITY:
    default:
	abort();
	return 0; /* silence MSVC */
    }
#undef mult_chan
}

static void
do_composite (pixman_op_t op,
	      const color_t *src,
	      const color_t *mask,
	      const color_t *dst,
	      color_t *result,
	      pixman_bool_t component_alpha)
{
    color_t srcval, srcalpha;

    if (mask == NULL)
    {
	srcval = *src;

	srcalpha.r = src->a;
	srcalpha.g = src->a;
	srcalpha.b = src->a;
	srcalpha.a = src->a;
    }
    else if (component_alpha)
    {
	srcval.r = src->r * mask->r;
	srcval.g = src->g * mask->g;
	srcval.b = src->b * mask->b;
	srcval.a = src->a * mask->a;

	srcalpha.r = src->a * mask->r;
	srcalpha.g = src->a * mask->g;
	srcalpha.b = src->a * mask->b;
	srcalpha.a = src->a * mask->a;
    }
    else
    {
	srcval.r = src->r * mask->a;
	srcval.g = src->g * mask->a;
	srcval.b = src->b * mask->a;
	srcval.a = src->a * mask->a;

	srcalpha.r = src->a * mask->a;
	srcalpha.g = src->a * mask->a;
	srcalpha.b = src->a * mask->a;
	srcalpha.a = src->a * mask->a;
    }

    result->r = calc_op (op, srcval.r, dst->r, srcalpha.r, dst->a);
    result->g = calc_op (op, srcval.g, dst->g, srcalpha.g, dst->a);
    result->b = calc_op (op, srcval.b, dst->b, srcalpha.b, dst->a);
    result->a = calc_op (op, srcval.a, dst->a, srcalpha.a, dst->a);
}

static void
color_correct (pixman_format_code_t format,
	       color_t *color)
{
#define MASK(x) ((1 << (x)) - 1)
#define round_pix(pix, m)						\
    ((int)((pix) * (MASK(m)) + .5) / (double) (MASK(m)))

    if (PIXMAN_FORMAT_R (format) == 0)
    {
	color->r = 0.0;
	color->g = 0.0;
	color->b = 0.0;
    }
    else
    {
	color->r = round_pix (color->r, PIXMAN_FORMAT_R (format));
	color->g = round_pix (color->g, PIXMAN_FORMAT_G (format));
	color->b = round_pix (color->b, PIXMAN_FORMAT_B (format));
    }

    if (PIXMAN_FORMAT_A (format) == 0)
	color->a = 1.0;
    else
	color->a = round_pix (color->a, PIXMAN_FORMAT_A (format));

#undef round_pix
#undef MASK
}

static void
get_pixel (pixman_image_t *image,
	   pixman_format_code_t format,
	   color_t *color)
{
#define MASK(N) ((1UL << (N))-1)

    unsigned long rs, gs, bs, as;
    int a, r, g, b;
    unsigned long val;

    val = *(unsigned long *) pixman_image_get_data (image);
#ifdef WORDS_BIGENDIAN
    val >>= 8 * sizeof(val) - PIXMAN_FORMAT_BPP (format);
#endif

    /* Number of bits in each channel */
    a = PIXMAN_FORMAT_A (format);
    r = PIXMAN_FORMAT_R (format);
    g = PIXMAN_FORMAT_G (format);
    b = PIXMAN_FORMAT_B (format);

    switch (PIXMAN_FORMAT_TYPE (format))
    {
    case PIXMAN_TYPE_ARGB:
        bs = 0;
        gs = b + bs;
        rs = g + gs;
        as = r + rs;
	break;

    case PIXMAN_TYPE_ABGR:
        rs = 0;
        gs = r + rs;
        bs = g + gs;
        as = b + bs;
	break;

    case PIXMAN_TYPE_BGRA:
        as = 0;
	rs = PIXMAN_FORMAT_BPP (format) - (b + g + r);
        gs = r + rs;
        bs = g + gs;
	break;

    case PIXMAN_TYPE_RGBA:
	as = 0;
	bs = PIXMAN_FORMAT_BPP (format) - (b + g + r);
	gs = b + bs;
	rs = g + gs;
	break;

    case PIXMAN_TYPE_A:
        as = 0;
        rs = 0;
        gs = 0;
        bs = 0;
	break;

    case PIXMAN_TYPE_OTHER:
    case PIXMAN_TYPE_COLOR:
    case PIXMAN_TYPE_GRAY:
    case PIXMAN_TYPE_YUY2:
    case PIXMAN_TYPE_YV12:
    default:
	abort ();
        as = 0;
        rs = 0;
        gs = 0;
        bs = 0;
	break;
    }

    if (MASK (a) != 0)
	color->a = ((val >> as) & MASK (a)) / (double) MASK (a);
    else
	color->a = 1.0;

    if (MASK (r) != 0)
    {
	color->r = ((val >> rs) & MASK (r)) / (double) MASK (r);
	color->g = ((val >> gs) & MASK (g)) / (double) MASK (g);
	color->b = ((val >> bs) & MASK (b)) / (double) MASK (b);
    }
    else
    {
	color->r = 0.0;
	color->g = 0.0;
	color->b = 0.0;
    }

#undef MASK
}

static double
eval_diff (color_t *expected, color_t *test, pixman_format_code_t format)
{
    double rscale, gscale, bscale, ascale;
    double rdiff, gdiff, bdiff, adiff;

    rscale = 1.0 * ((1 << PIXMAN_FORMAT_R (format)) - 1);
    gscale = 1.0 * ((1 << PIXMAN_FORMAT_G (format)) - 1);
    bscale = 1.0 * ((1 << PIXMAN_FORMAT_B (format)) - 1);
    ascale = 1.0 * ((1 << PIXMAN_FORMAT_A (format)) - 1);

    rdiff = fabs (test->r - expected->r) * rscale;
    bdiff = fabs (test->g - expected->g) * gscale;
    gdiff = fabs (test->b - expected->b) * bscale;
    adiff = fabs (test->a - expected->a) * ascale;

    return MAX (MAX (MAX (rdiff, gdiff), bdiff), adiff);
}

static char *
describe_image (image_t *info, char *buf)
{
    if (info->size)
    {
	sprintf (buf, "%s %dx%d%s",
		 info->format->name,
		 info->size, info->size,
		 info->repeat ? "R" :"");
    }
    else
    {
	sprintf (buf, "solid");
    }

    return buf;
}

/* Test a composite of a given operation, source, mask, and destination
 * picture.
 * Fills the window, and samples from the 0,0 pixel corner.
 */
static pixman_bool_t
composite_test (image_t *dst,
		const operator_t *op,
		image_t *src,
		image_t *mask,
		pixman_bool_t component_alpha)
{
    pixman_color_t fill;
    pixman_rectangle16_t rect;
    color_t expected, result, tdst, tsrc, tmsk;
    double diff;
    pixman_bool_t success = TRUE;

    compute_pixman_color (dst->color, &fill);
    rect.x = rect.y = 0;
    rect.width = rect.height = dst->size;
    pixman_image_fill_rectangles (PIXMAN_OP_SRC, dst->image,
				  &fill, 1, &rect);

    if (mask != NULL)
    {
	pixman_image_set_component_alpha (mask->image, component_alpha);
	pixman_image_composite (op->op, src->image, mask->image, dst->image,
				0, 0,
				0, 0,
				0, 0,
				dst->size, dst->size);

	tmsk = *mask->color;
	if (mask->size)
	{
	    color_correct (mask->format->format, &tmsk);

	    if (component_alpha &&
		PIXMAN_FORMAT_R (mask->format->format) == 0)
	    {
		/* Ax component-alpha masks expand alpha into
		 * all color channels.
		 */
		tmsk.r = tmsk.g = tmsk.b = tmsk.a;
	    }
	}
    }
    else
    {
	pixman_image_composite (op->op, src->image, NULL, dst->image,
				0, 0,
				0, 0,
				0, 0,
				dst->size, dst->size);
    }
    get_pixel (dst->image, dst->format->format, &result);

    tdst = *dst->color;
    color_correct (dst->format->format, &tdst);
    tsrc = *src->color;
    if (src->size)
	color_correct (src->format->format, &tsrc);
    do_composite (op->op, &tsrc, mask ? &tmsk : NULL, &tdst,
		  &expected, component_alpha);
    color_correct (dst->format->format, &expected);

    diff = eval_diff (&expected, &result, dst->format->format);

    /* FIXME: We should find out what deviation is acceptable. 3.0
     * is clearly absurd for 2 bit formats for example. On the other
     * hand currently 1.0 does not work.
     */
    if (diff > 3.0)
    {
	char buf[40];

	sprintf (buf, "%s %scomposite",
		 op->name,
		 component_alpha ? "CA " : "");

	printf ("%s test error of %.4f --\n"
		"           R    G    B    A\n"
		"got:       %.2f %.2f %.2f %.2f [%08lx]\n"
		"expected:  %.2f %.2f %.2f %.2f\n",
		buf, diff,
		result.r, result.g, result.b, result.a,
		*(unsigned long *) pixman_image_get_data (dst->image),
		expected.r, expected.g, expected.b, expected.a);

	if (mask != NULL)
	{
	    printf ("src color: %.2f %.2f %.2f %.2f\n"
		    "msk color: %.2f %.2f %.2f %.2f\n"
		    "dst color: %.2f %.2f %.2f %.2f\n",
		    src->color->r, src->color->g,
		    src->color->b, src->color->a,
		    mask->color->r, mask->color->g,
		    mask->color->b, mask->color->a,
		    dst->color->r, dst->color->g,
		    dst->color->b, dst->color->a);
	    printf ("src: %s, ", describe_image (src, buf));
	    printf ("mask: %s, ", describe_image (mask, buf));
	    printf ("dst: %s\n\n", describe_image (dst, buf));
	}
	else
	{
	    printf ("src color: %.2f %.2f %.2f %.2f\n"
		    "dst color: %.2f %.2f %.2f %.2f\n",
		    src->color->r, src->color->g,
		    src->color->b, src->color->a,
		    dst->color->r, dst->color->g,
		    dst->color->b, dst->color->a);
	    printf ("src: %s, ", describe_image (src, buf));
	    printf ("dst: %s\n\n", describe_image (dst, buf));
	}

	success = FALSE;
    }

    return success;
}

static void
image_init (image_t *info,
	    int color,
	    int format,
	    int size)
{
    pixman_color_t fill;

    info->color = &colors[color];
    compute_pixman_color (info->color, &fill);

    info->format = &formats[format];
    info->size = sizes[size] & ~FLAGS;
    info->repeat = PIXMAN_REPEAT_NONE;

    if (info->size)
    {
	pixman_rectangle16_t rect;

	info->image = pixman_image_create_bits (info->format->format,
						info->size, info->size,
						NULL, 0);

	rect.x = rect.y = 0;
	rect.width = rect.height = info->size;
	pixman_image_fill_rectangles (PIXMAN_OP_SRC, info->image, &fill,
				      1, &rect);

	if (size & REPEAT)
	{
	    pixman_image_set_repeat (info->image, PIXMAN_REPEAT_NORMAL);
	    info->repeat = PIXMAN_REPEAT_NORMAL;
	}
    }
    else
    {
	info->image = pixman_image_create_solid_fill (&fill);
    }
}

static void
image_fini (image_t *info)
{
    pixman_image_unref (info->image);
}

static int
random_size (void)
{
    return lcg_rand_n (ARRAY_LENGTH (sizes));
}

static int
random_color (void)
{
    return lcg_rand_n (ARRAY_LENGTH (colors));
}

static int
random_format (void)
{
    return lcg_rand_n (ARRAY_LENGTH (formats));
}

static pixman_bool_t
run_test (uint32_t seed)
{
    image_t src, mask, dst;
    const operator_t *op;
    int ca;
    int ok;

    lcg_srand (seed);
    
    image_init (&dst, random_color(), random_format(), 1);
    image_init (&src, random_color(), random_format(), random_size());
    image_init (&mask, random_color(), random_format(), random_size());

    op = &(operators [lcg_rand_n (ARRAY_LENGTH (operators))]);

    ca = lcg_rand_n (3);

    switch (ca)
    {
    case 0:
	ok = composite_test (&dst, op, &src, NULL, FALSE);
	break;
    case 1:
	ok = composite_test (&dst, op, &src, &mask, FALSE);
	break;
    case 2:
	ok = composite_test (&dst, op, &src, &mask,
			     mask.size? TRUE : FALSE);
	break;
    default:
	ok = FALSE;
	break;
    }

    image_fini (&src);
    image_fini (&mask);
    image_fini (&dst);

    return ok;
}

int
main (int argc, char **argv)
{
#define N_TESTS (8 * 1024 * 1024)
    int result = 0;
    uint32_t i, seed;

    if (argc > 1)
    {
	char *end;
	
	i = strtol (argv[1], &end, 0);

	if (end != argv[1])
	{
	    if (!run_test (i))
		return 1;
	    else
		return 0;
	}
	else
	{
	    printf ("Usage:\n\n   %s <number>\n\n", argv[0]);
	    return -1;
	}
    }

    if (getenv ("PIXMAN_RANDOMIZE_TESTS"))
	seed = get_random_seed();
    else
	seed = 1;
    
#ifdef USE_OPENMP
#   pragma omp parallel for default(none) shared(result, argv, seed)
#endif
    for (i = 0; i <= N_TESTS; ++i)
    {
	if (!result && !run_test (i + seed))
	{
	    printf ("Test 0x%08X failed.\n", seed + i);
	    
	    result = seed + i;
	}
    }
    
    return result;
}
