#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define WIDTH 100
#define HEIGHT 100

static const pixman_format_code_t formats[] =
{
    PIXMAN_a8r8g8b8,
    PIXMAN_a2r10g10b10,
    PIXMAN_a4r4g4b4,
    PIXMAN_a8
};

static const pixman_format_code_t alpha_formats[] =
{
    PIXMAN_null,
    PIXMAN_a8,
    PIXMAN_a2r10g10b10,
    PIXMAN_a4r4g4b4
};

static const int origins[] =
{
    0, 10, -100
};

static const char *
format_name (pixman_format_code_t format)
{
    if (format == PIXMAN_a8)
	return "a8";
    else if (format == PIXMAN_a2r10g10b10)
	return "a2r10g10b10";
    else if (format == PIXMAN_a8r8g8b8)
	return "a8r8g8b8";
    else if (format == PIXMAN_a4r4g4b4)
	return "a4r4g4b4";
    else if (format == PIXMAN_null)
	return "none";
    else
	assert (0);

    return "<unknown - bug in alphamap.c>";
}

static void
on_destroy (pixman_image_t *image, void *data)
{
    uint32_t *bits = pixman_image_get_data (image);

    fence_free (bits);
}

static pixman_image_t *
make_image (pixman_format_code_t format)
{
    uint32_t *bits;
    uint8_t bpp = PIXMAN_FORMAT_BPP (format) / 8;
    pixman_image_t *image;

    bits = (uint32_t *)make_random_bytes (WIDTH * HEIGHT * bpp);

    image = pixman_image_create_bits (format, WIDTH, HEIGHT, bits, WIDTH * bpp);

    if (image && bits)
	pixman_image_set_destroy_function (image, on_destroy, NULL);

    return image;
}

static pixman_image_t *
create_image (pixman_format_code_t format, pixman_format_code_t alpha_format,
	      int alpha_origin_x, int alpha_origin_y)
{
    pixman_image_t *image = make_image (format);

    if (alpha_format != PIXMAN_null)
    {
	pixman_image_t *alpha = make_image (alpha_format);

	pixman_image_set_alpha_map (image, alpha,
				    alpha_origin_x, alpha_origin_y);
	pixman_image_unref (alpha);
    }

    return image;
}

static uint8_t
get_alpha (pixman_image_t *image, int x, int y, int orig_x, int orig_y)
{
    uint8_t *bits;
    uint8_t r;

    if (image->common.alpha_map)
    {
	if (x - orig_x >= 0 && x - orig_x < WIDTH &&
	    y - orig_y >= 0 && y - orig_y < HEIGHT)
	{
	    image = (pixman_image_t *)image->common.alpha_map;

	    x -= orig_x;
	    y -= orig_y;
	}
	else
	{
	    return 0;
	}
    }

    bits = (uint8_t *)image->bits.bits;

    if (image->bits.format == PIXMAN_a8)
    {
	r = bits[y * WIDTH + x];
    }
    else if (image->bits.format == PIXMAN_a2r10g10b10)
    {
	r = ((uint32_t *)bits)[y * WIDTH + x] >> 30;
	r |= r << 2;
	r |= r << 4;
    }
    else if (image->bits.format == PIXMAN_a8r8g8b8)
    {
	r = ((uint32_t *)bits)[y * WIDTH + x] >> 24;
    }
    else if (image->bits.format == PIXMAN_a4r4g4b4)
    {
	r = ((uint16_t *)bits)[y * WIDTH + x] >> 12;
	r |= r << 4;
    }
    else
    {
	assert (0);
    }

    return r;
}

#define ARRAY_LENGTH(A) ((int) (sizeof (A) / sizeof ((A) [0])))

static int
run_test (int s, int d, int sa, int da, int soff, int doff)
{
    pixman_format_code_t sf = formats[s];
    pixman_format_code_t df = formats[d];
    pixman_format_code_t saf = alpha_formats[sa];
    pixman_format_code_t daf = alpha_formats[da];
    pixman_image_t *src, *dst, *orig_dst;
    pixman_transform_t t1;
    int j, k;
    int n_alpha_bits;

    soff = origins[soff];
    doff = origins[doff];

    n_alpha_bits = PIXMAN_FORMAT_A (df);
    if (daf != PIXMAN_null)
	n_alpha_bits = PIXMAN_FORMAT_A (daf);


    src = create_image (sf, saf, soff, soff);
    orig_dst = create_image (df, daf, doff, doff);
    dst = create_image (df, daf, doff, doff);

    /* Transformations, repeats and filters on destinations should be ignored,
     * so just set some random ones.
     */
    pixman_transform_init_identity (&t1);
    pixman_transform_scale (&t1, NULL, pixman_int_to_fixed (100), pixman_int_to_fixed (11));
    pixman_transform_rotate (&t1, NULL, pixman_double_to_fixed (0.5), pixman_double_to_fixed (0.11));
    pixman_transform_translate (&t1, NULL, pixman_int_to_fixed (11), pixman_int_to_fixed (17));

    pixman_image_set_transform (dst, &t1);
    pixman_image_set_filter (dst, PIXMAN_FILTER_BILINEAR, NULL, 0);
    pixman_image_set_repeat (dst, PIXMAN_REPEAT_REFLECT);

    pixman_image_composite (PIXMAN_OP_SRC, orig_dst, NULL, dst,
			    0, 0, 0, 0, 0, 0, WIDTH, HEIGHT);

    pixman_image_composite (PIXMAN_OP_ADD, src, NULL, dst,
			    0, 0, 0, 0, 0, 0, WIDTH, HEIGHT);

    for (j = MAX (doff, 0); j < MIN (HEIGHT, HEIGHT + doff); ++j)
    {
	for (k = MAX (doff, 0); k < MIN (WIDTH, WIDTH + doff); ++k)
	{
	    uint8_t sa, da, oda, ref;

	    sa = get_alpha (src, k, j, soff, soff);
	    da = get_alpha (dst, k, j, doff, doff);
	    oda = get_alpha (orig_dst, k, j, doff, doff);

	    if (sa + oda > 255)
		ref = 255;
	    else
		ref = sa + oda;

	    if (da >> (8 - n_alpha_bits) != ref >> (8 - n_alpha_bits))
	    {
		printf ("\nWrong alpha value at (%d, %d). Should be 0x%x; got 0x%x. Source was 0x%x, original dest was 0x%x\n",
			k, j, ref, da, sa, oda);

		printf ("src: %s, alpha: %s, origin %d %d\ndst: %s, alpha: %s, origin: %d %d\n\n",
			format_name (sf),
			format_name (saf),
			soff, soff,
			format_name (df),
			format_name (daf),
			doff, doff);
		return 1;
	    }
	}
    }

    pixman_image_set_alpha_map (src, NULL, 0, 0);
    pixman_image_set_alpha_map (dst, NULL, 0, 0);
    pixman_image_set_alpha_map (orig_dst, NULL, 0, 0);

    pixman_image_unref (src);
    pixman_image_unref (dst);
    pixman_image_unref (orig_dst);

    return 0;
}

int
main (int argc, char **argv)
{
    int i, j, a, b, x, y;

    for (i = 0; i < ARRAY_LENGTH (formats); ++i)
    {
	for (j = 0; j < ARRAY_LENGTH (formats); ++j)
	{
	    for (a = 0; a < ARRAY_LENGTH (alpha_formats); ++a)
	    {
		for (b = 0; b < ARRAY_LENGTH (alpha_formats); ++b)
		{
		    for (x = 0; x < ARRAY_LENGTH (origins); ++x)
		    {
			for (y = 0; y < ARRAY_LENGTH (origins); ++y)
			{
			    if (run_test (i, j, a, b, x, y) != 0)
				return 1;
			}
		    }
		}
	    }
	}
    }

    return 0;
}
