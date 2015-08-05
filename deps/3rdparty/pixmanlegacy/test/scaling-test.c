/*
 * Test program, which can detect some problems with nearest neighbour
 * and bilinear scaling in pixman. Testing is done by running lots
 * of random SRC and OVER compositing operations a8r8g8b8, x8a8r8g8b8
 * and r5g6b5 color formats.
 *
 * Script 'fuzzer-find-diff.pl' can be used to narrow down the problem in
 * the case of test failure.
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define MAX_SRC_WIDTH  48
#define MAX_SRC_HEIGHT 8
#define MAX_DST_WIDTH  48
#define MAX_DST_HEIGHT 8
#define MAX_STRIDE     4

/*
 * Composite operation with pseudorandom images
 */
uint32_t
test_composite (int      testnum,
		int      verbose)
{
    int                i;
    pixman_image_t *   src_img;
    pixman_image_t *   mask_img;
    pixman_image_t *   dst_img;
    pixman_transform_t transform;
    pixman_region16_t  clip;
    int                src_width, src_height;
    int                mask_width, mask_height;
    int                dst_width, dst_height;
    int                src_stride, mask_stride, dst_stride;
    int                src_x, src_y;
    int                mask_x, mask_y;
    int                dst_x, dst_y;
    int                src_bpp;
    int                mask_bpp = 1;
    int                dst_bpp;
    int                w, h;
    pixman_fixed_t     scale_x = 65536, scale_y = 65536;
    pixman_fixed_t     translate_x = 0, translate_y = 0;
    pixman_fixed_t     mask_scale_x = 65536, mask_scale_y = 65536;
    pixman_fixed_t     mask_translate_x = 0, mask_translate_y = 0;
    pixman_op_t        op;
    pixman_repeat_t    repeat = PIXMAN_REPEAT_NONE;
    pixman_repeat_t    mask_repeat = PIXMAN_REPEAT_NONE;
    pixman_format_code_t src_fmt, dst_fmt;
    uint32_t *         srcbuf;
    uint32_t *         dstbuf;
    uint32_t *         maskbuf;
    uint32_t           crc32;
    FLOAT_REGS_CORRUPTION_DETECTOR_START ();

    lcg_srand (testnum);

    src_bpp = (lcg_rand_n (2) == 0) ? 2 : 4;
    dst_bpp = (lcg_rand_n (2) == 0) ? 2 : 4;
    switch (lcg_rand_n (3))
    {
    case 0:
	op = PIXMAN_OP_SRC;
	break;
    case 1:
	op = PIXMAN_OP_OVER;
	break;
    default:
	op = PIXMAN_OP_ADD;
	break;
    }

    src_width = lcg_rand_n (MAX_SRC_WIDTH) + 1;
    src_height = lcg_rand_n (MAX_SRC_HEIGHT) + 1;

    if (lcg_rand_n (2))
    {
	mask_width = lcg_rand_n (MAX_SRC_WIDTH) + 1;
	mask_height = lcg_rand_n (MAX_SRC_HEIGHT) + 1;
    }
    else
    {
	mask_width = mask_height = 1;
    }

    dst_width = lcg_rand_n (MAX_DST_WIDTH) + 1;
    dst_height = lcg_rand_n (MAX_DST_HEIGHT) + 1;
    src_stride = src_width * src_bpp + lcg_rand_n (MAX_STRIDE) * src_bpp;
    mask_stride = mask_width * mask_bpp + lcg_rand_n (MAX_STRIDE) * mask_bpp;
    dst_stride = dst_width * dst_bpp + lcg_rand_n (MAX_STRIDE) * dst_bpp;

    if (src_stride & 3)
	src_stride += 2;

    if (mask_stride & 1)
	mask_stride += 1;
    if (mask_stride & 2)
	mask_stride += 2;

    if (dst_stride & 3)
	dst_stride += 2;

    src_x = -(src_width / 4) + lcg_rand_n (src_width * 3 / 2);
    src_y = -(src_height / 4) + lcg_rand_n (src_height * 3 / 2);
    mask_x = -(mask_width / 4) + lcg_rand_n (mask_width * 3 / 2);
    mask_y = -(mask_height / 4) + lcg_rand_n (mask_height * 3 / 2);
    dst_x = -(dst_width / 4) + lcg_rand_n (dst_width * 3 / 2);
    dst_y = -(dst_height / 4) + lcg_rand_n (dst_height * 3 / 2);
    w = lcg_rand_n (dst_width * 3 / 2 - dst_x);
    h = lcg_rand_n (dst_height * 3 / 2 - dst_y);

    srcbuf = (uint32_t *)malloc (src_stride * src_height);
    maskbuf = (uint32_t *)malloc (mask_stride * mask_height);
    dstbuf = (uint32_t *)malloc (dst_stride * dst_height);

    for (i = 0; i < src_stride * src_height; i++)
	*((uint8_t *)srcbuf + i) = lcg_rand_n (256);

    for (i = 0; i < mask_stride * mask_height; i++)
	*((uint8_t *)maskbuf + i) = lcg_rand_n (256);

    for (i = 0; i < dst_stride * dst_height; i++)
	*((uint8_t *)dstbuf + i) = lcg_rand_n (256);

    src_fmt = src_bpp == 4 ? (lcg_rand_n (2) == 0 ?
                              PIXMAN_a8r8g8b8 : PIXMAN_x8r8g8b8) : PIXMAN_r5g6b5;

    dst_fmt = dst_bpp == 4 ? (lcg_rand_n (2) == 0 ?
                              PIXMAN_a8r8g8b8 : PIXMAN_x8r8g8b8) : PIXMAN_r5g6b5;

    src_img = pixman_image_create_bits (
        src_fmt, src_width, src_height, srcbuf, src_stride);

    mask_img = pixman_image_create_bits (
        PIXMAN_a8, mask_width, mask_height, maskbuf, mask_stride);

    dst_img = pixman_image_create_bits (
        dst_fmt, dst_width, dst_height, dstbuf, dst_stride);

    image_endian_swap (src_img);
    image_endian_swap (dst_img);

    if (lcg_rand_n (4) > 0)
    {
	scale_x = -32768 * 3 + lcg_rand_N (65536 * 5);
	scale_y = -32768 * 3 + lcg_rand_N (65536 * 5);
	translate_x = lcg_rand_N (65536);
	translate_y = lcg_rand_N (65536);
	pixman_transform_init_scale (&transform, scale_x, scale_y);
	pixman_transform_translate (&transform, NULL, translate_x, translate_y);
	pixman_image_set_transform (src_img, &transform);
    }

    if (lcg_rand_n (2) > 0)
    {
	mask_scale_x = -32768 * 3 + lcg_rand_N (65536 * 5);
	mask_scale_y = -32768 * 3 + lcg_rand_N (65536 * 5);
	mask_translate_x = lcg_rand_N (65536);
	mask_translate_y = lcg_rand_N (65536);
	pixman_transform_init_scale (&transform, mask_scale_x, mask_scale_y);
	pixman_transform_translate (&transform, NULL, mask_translate_x, mask_translate_y);
	pixman_image_set_transform (mask_img, &transform);
    }

    switch (lcg_rand_n (4))
    {
    case 0:
	mask_repeat = PIXMAN_REPEAT_NONE;
	break;

    case 1:
	mask_repeat = PIXMAN_REPEAT_NORMAL;
	break;

    case 2:
	mask_repeat = PIXMAN_REPEAT_PAD;
	break;

    case 3:
	mask_repeat = PIXMAN_REPEAT_REFLECT;
	break;

    default:
        break;
    }
    pixman_image_set_repeat (mask_img, mask_repeat);

    switch (lcg_rand_n (4))
    {
    case 0:
	repeat = PIXMAN_REPEAT_NONE;
	break;

    case 1:
	repeat = PIXMAN_REPEAT_NORMAL;
	break;

    case 2:
	repeat = PIXMAN_REPEAT_PAD;
	break;

    case 3:
	repeat = PIXMAN_REPEAT_REFLECT;
	break;

    default:
        break;
    }
    pixman_image_set_repeat (src_img, repeat);

    if (lcg_rand_n (2))
	pixman_image_set_filter (src_img, PIXMAN_FILTER_NEAREST, NULL, 0);
    else
	pixman_image_set_filter (src_img, PIXMAN_FILTER_BILINEAR, NULL, 0);

    if (lcg_rand_n (2))
	pixman_image_set_filter (mask_img, PIXMAN_FILTER_NEAREST, NULL, 0);
    else
	pixman_image_set_filter (mask_img, PIXMAN_FILTER_BILINEAR, NULL, 0);

    if (verbose)
    {
	printf ("src_fmt=%08X, dst_fmt=%08X\n", src_fmt, dst_fmt);
	printf ("op=%d, scale_x=%d, scale_y=%d, repeat=%d\n",
	        op, scale_x, scale_y, repeat);
	printf ("translate_x=%d, translate_y=%d\n",
	        translate_x, translate_y);
	printf ("src_width=%d, src_height=%d, dst_width=%d, dst_height=%d\n",
	        src_width, src_height, dst_width, dst_height);
	printf ("src_x=%d, src_y=%d, dst_x=%d, dst_y=%d\n",
	        src_x, src_y, dst_x, dst_y);
	printf ("w=%d, h=%d\n", w, h);
    }

    if (lcg_rand_n (8) == 0)
    {
	pixman_box16_t clip_boxes[2];
	int            n = lcg_rand_n (2) + 1;

	for (i = 0; i < n; i++)
	{
	    clip_boxes[i].x1 = lcg_rand_n (src_width);
	    clip_boxes[i].y1 = lcg_rand_n (src_height);
	    clip_boxes[i].x2 =
		clip_boxes[i].x1 + lcg_rand_n (src_width - clip_boxes[i].x1);
	    clip_boxes[i].y2 =
		clip_boxes[i].y1 + lcg_rand_n (src_height - clip_boxes[i].y1);

	    if (verbose)
	    {
		printf ("source clip box: [%d,%d-%d,%d]\n",
		        clip_boxes[i].x1, clip_boxes[i].y1,
		        clip_boxes[i].x2, clip_boxes[i].y2);
	    }
	}

	pixman_region_init_rects (&clip, clip_boxes, n);
	pixman_image_set_clip_region (src_img, &clip);
	pixman_image_set_source_clipping (src_img, 1);
	pixman_region_fini (&clip);
    }

    if (lcg_rand_n (8) == 0)
    {
	pixman_box16_t clip_boxes[2];
	int            n = lcg_rand_n (2) + 1;

	for (i = 0; i < n; i++)
	{
	    clip_boxes[i].x1 = lcg_rand_n (mask_width);
	    clip_boxes[i].y1 = lcg_rand_n (mask_height);
	    clip_boxes[i].x2 =
		clip_boxes[i].x1 + lcg_rand_n (mask_width - clip_boxes[i].x1);
	    clip_boxes[i].y2 =
		clip_boxes[i].y1 + lcg_rand_n (mask_height - clip_boxes[i].y1);

	    if (verbose)
	    {
		printf ("mask clip box: [%d,%d-%d,%d]\n",
		        clip_boxes[i].x1, clip_boxes[i].y1,
		        clip_boxes[i].x2, clip_boxes[i].y2);
	    }
	}

	pixman_region_init_rects (&clip, clip_boxes, n);
	pixman_image_set_clip_region (mask_img, &clip);
	pixman_image_set_source_clipping (mask_img, 1);
	pixman_region_fini (&clip);
    }

    if (lcg_rand_n (8) == 0)
    {
	pixman_box16_t clip_boxes[2];
	int            n = lcg_rand_n (2) + 1;
	for (i = 0; i < n; i++)
	{
	    clip_boxes[i].x1 = lcg_rand_n (dst_width);
	    clip_boxes[i].y1 = lcg_rand_n (dst_height);
	    clip_boxes[i].x2 =
		clip_boxes[i].x1 + lcg_rand_n (dst_width - clip_boxes[i].x1);
	    clip_boxes[i].y2 =
		clip_boxes[i].y1 + lcg_rand_n (dst_height - clip_boxes[i].y1);

	    if (verbose)
	    {
		printf ("destination clip box: [%d,%d-%d,%d]\n",
		        clip_boxes[i].x1, clip_boxes[i].y1,
		        clip_boxes[i].x2, clip_boxes[i].y2);
	    }
	}
	pixman_region_init_rects (&clip, clip_boxes, n);
	pixman_image_set_clip_region (dst_img, &clip);
	pixman_region_fini (&clip);
    }

    if (lcg_rand_n (2) == 0)
	pixman_image_composite (op, src_img, NULL, dst_img,
                            src_x, src_y, 0, 0, dst_x, dst_y, w, h);
    else
	pixman_image_composite (op, src_img, mask_img, dst_img,
                            src_x, src_y, mask_x, mask_y, dst_x, dst_y, w, h);

    if (dst_fmt == PIXMAN_x8r8g8b8)
    {
	/* ignore unused part */
	for (i = 0; i < dst_stride * dst_height / 4; i++)
	    dstbuf[i] &= 0xFFFFFF;
    }

    image_endian_swap (dst_img);

    if (verbose)
    {
	int j;
	
	for (i = 0; i < dst_height; i++)
	{
	    for (j = 0; j < dst_stride; j++)
		printf ("%02X ", *((uint8_t *)dstbuf + i * dst_stride + j));

	    printf ("\n");
	}
    }

    pixman_image_unref (src_img);
    pixman_image_unref (mask_img);
    pixman_image_unref (dst_img);

    crc32 = compute_crc32 (0, dstbuf, dst_stride * dst_height);
    free (srcbuf);
    free (maskbuf);
    free (dstbuf);

    FLOAT_REGS_CORRUPTION_DETECTOR_FINISH ();
    return crc32;
}

int
main (int argc, const char *argv[])
{
    pixman_disable_out_of_bounds_workaround ();

    return fuzzer_test_main("scaling", 8000000, 0x80DF1CB2,
			    test_composite, argc, argv);
}
