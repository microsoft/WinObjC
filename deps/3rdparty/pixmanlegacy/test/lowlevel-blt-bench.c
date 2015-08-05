/*
 * Copyright © 2009 Nokia Corporation
 * Copyright © 2010 Movial Creative Technologies Oy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "pixman-private.h"
#include "utils.h"

#define SOLID_FLAG 1
#define CA_FLAG    2

#define L1CACHE_SIZE (8 * 1024)
#define L2CACHE_SIZE (128 * 1024)

#define WIDTH  1920
#define HEIGHT 1080
#define BUFSIZE (WIDTH * HEIGHT * 4)
#define XWIDTH 256
#define XHEIGHT 256
#define TILEWIDTH 32
#define TINYWIDTH 8

#define EXCLUDE_OVERHEAD 1

uint32_t *dst;
uint32_t *src;
uint32_t *mask;

double bandwidth = 0;

double
bench_memcpy ()
{
    int64_t n = 0, total;
    double  t1, t2;
    int     x = 0;

    t1 = gettime ();
    while (1)
    {
	memcpy (dst, src, BUFSIZE - 64);
	memcpy (src, dst, BUFSIZE - 64);
	n += 4 * (BUFSIZE - 64);
	t2 = gettime ();
	if (t2 - t1 > 0.5)
	    break;
    }
    n = total = n * 5;
    t1 = gettime ();
    while (n > 0)
    {
	if (++x >= 64)
	    x = 0;
	memcpy ((char *)dst + 1, (char *)src + x, BUFSIZE - 64);
	memcpy ((char *)src + 1, (char *)dst + x, BUFSIZE - 64);
	n -= 4 * (BUFSIZE - 64);
    }
    t2 = gettime ();
    return (double)total / (t2 - t1);
}

static void
pixman_image_composite_wrapper (pixman_implementation_t *impl,
                                pixman_op_t              op,
                                pixman_image_t *         src_image,
                                pixman_image_t *         mask_image,
                                pixman_image_t *         dst_image,
                                int32_t                  src_x,
                                int32_t                  src_y,
                                int32_t                  mask_x,
                                int32_t                  mask_y,
                                int32_t                  dest_x,
                                int32_t                  dest_y,
                                int32_t                  width,
                                int32_t                  height)
{
    pixman_image_composite (op, src_image, mask_image, dst_image, src_x,
                            src_y, mask_x, mask_y, dest_x, dest_y, width, height);
}

static void
pixman_image_composite_empty (pixman_implementation_t *impl,
                              pixman_op_t              op,
                              pixman_image_t *         src_image,
                              pixman_image_t *         mask_image,
                              pixman_image_t *         dst_image,
                              int32_t                  src_x,
                              int32_t                  src_y,
                              int32_t                  mask_x,
                              int32_t                  mask_y,
                              int32_t                  dest_x,
                              int32_t                  dest_y,
                              int32_t                  width,
                              int32_t                  height)
{
    pixman_image_composite (op, src_image, mask_image, dst_image, 0,
                            0, 0, 0, 0, 0, 1, 1);
}

void
noinline
bench_L  (pixman_op_t              op,
          pixman_image_t *         src_img,
          pixman_image_t *         mask_img,
          pixman_image_t *         dst_img,
          int64_t                  n,
          pixman_composite_func_t  func,
          int                      width,
          int                      lines_count)
{
    int64_t      i, j;
    int          x = 0;
    int          q = 0;
    volatile int qx;

    for (i = 0; i < n; i++)
    {
	/* touch destination buffer to fetch it into L1 cache */
	for (j = 0; j < width + 64; j += 16) {
	    q += dst[j];
	    q += src[j];
	}
	if (++x >= 64)
	    x = 0;
	func (0, op, src_img, mask_img, dst_img, x, 0, x, 0, 63 - x, 0, width, lines_count);
    }
    qx = q;
}

void
noinline
bench_M (pixman_op_t              op,
         pixman_image_t *         src_img,
         pixman_image_t *         mask_img,
         pixman_image_t *         dst_img,
         int64_t                  n,
         pixman_composite_func_t  func)
{
    int64_t i;
    int     x = 0;

    for (i = 0; i < n; i++)
    {
	if (++x >= 64)
	    x = 0;
	func (0, op, src_img, mask_img, dst_img, x, 0, x, 0, 1, 0, WIDTH - 64, HEIGHT);
    }
}

double
noinline
bench_HT (pixman_op_t              op,
          pixman_image_t *         src_img,
          pixman_image_t *         mask_img,
          pixman_image_t *         dst_img,
          int64_t                  n,
          pixman_composite_func_t  func)
{
    double  pix_cnt = 0;
    int     x = 0;
    int     y = 0;
    int64_t i;

    srand (0);
    for (i = 0; i < n; i++)
    {
	int w = (rand () % (TILEWIDTH * 2)) + 1;
	int h = (rand () % (TILEWIDTH * 2)) + 1;
	if (x + w > WIDTH)
	{
	    x = 0;
	    y += TILEWIDTH * 2;
	}
	if (y + h > HEIGHT)
	{
	    y = 0;
	}
	func (0, op, src_img, mask_img, dst_img, x, y, x, y, x, y, w, h);
	x += w;
	pix_cnt += w * h;
    }
    return pix_cnt;
}

double
noinline
bench_VT (pixman_op_t              op,
          pixman_image_t *         src_img,
          pixman_image_t *         mask_img,
          pixman_image_t *         dst_img,
          int64_t                  n,
          pixman_composite_func_t  func)
{
    double  pix_cnt = 0;
    int     x = 0;
    int     y = 0;
    int64_t i;

    srand (0);
    for (i = 0; i < n; i++)
    {
	int w = (rand () % (TILEWIDTH * 2)) + 1;
	int h = (rand () % (TILEWIDTH * 2)) + 1;
	if (y + h > HEIGHT)
	{
	    y = 0;
	    x += TILEWIDTH * 2;
	}
	if (x + w > WIDTH)
	{
	    x = 0;
	}
	func (0, op, src_img, mask_img, dst_img, x, y, x, y, x, y, w, h);
	y += h;
	pix_cnt += w * h;
    }
    return pix_cnt;
}

double
noinline
bench_R (pixman_op_t              op,
         pixman_image_t *         src_img,
         pixman_image_t *         mask_img,
         pixman_image_t *         dst_img,
         int64_t                  n,
         pixman_composite_func_t  func,
         int                      maxw,
         int                      maxh)
{
    double  pix_cnt = 0;
    int64_t i;

    if (maxw <= TILEWIDTH * 2 || maxh <= TILEWIDTH * 2)
    {
	printf("error: maxw <= TILEWIDTH * 2 || maxh <= TILEWIDTH * 2\n");
        return 0;
    }

    srand (0);
    for (i = 0; i < n; i++)
    {
	int w = (rand () % (TILEWIDTH * 2)) + 1;
	int h = (rand () % (TILEWIDTH * 2)) + 1;
	int sx = rand () % (maxw - TILEWIDTH * 2);
	int sy = rand () % (maxh - TILEWIDTH * 2);
	int dx = rand () % (maxw - TILEWIDTH * 2);
	int dy = rand () % (maxh - TILEWIDTH * 2);
	func (0, op, src_img, mask_img, dst_img, sx, sy, sx, sy, dx, dy, w, h);
	pix_cnt += w * h;
    }
    return pix_cnt;
}

double
noinline
bench_RT (pixman_op_t              op,
          pixman_image_t *         src_img,
          pixman_image_t *         mask_img,
          pixman_image_t *         dst_img,
          int64_t                  n,
          pixman_composite_func_t  func,
          int                      maxw,
          int                      maxh)
{
    double  pix_cnt = 0;
    int64_t i;

    if (maxw <= TINYWIDTH * 2 || maxh <= TINYWIDTH * 2)
    {
	printf("error: maxw <= TINYWIDTH * 2 || maxh <= TINYWIDTH * 2\n");
        return 0;
    }

    srand (0);
    for (i = 0; i < n; i++)
    {
	int w = (rand () % (TINYWIDTH * 2)) + 1;
	int h = (rand () % (TINYWIDTH * 2)) + 1;
	int sx = rand () % (maxw - TINYWIDTH * 2);
	int sy = rand () % (maxh - TINYWIDTH * 2);
	int dx = rand () % (maxw - TINYWIDTH * 2);
	int dy = rand () % (maxh - TINYWIDTH * 2);
	func (0, op, src_img, mask_img, dst_img, sx, sy, sx, sy, dx, dy, w, h);
	pix_cnt += w * h;
    }
    return pix_cnt;
}

void
bench_composite (char * testname,
                 int    src_fmt,
                 int    src_flags,
                 int    op,
                 int    mask_fmt,
                 int    mask_flags,
                 int    dst_fmt,
                 double npix)
{
    pixman_image_t *                src_img;
    pixman_image_t *                dst_img;
    pixman_image_t *                mask_img;
    pixman_image_t *                xsrc_img;
    pixman_image_t *                xdst_img;
    pixman_image_t *                xmask_img;
    double                          t1, t2, t3, pix_cnt;
    int64_t                         n, l1test_width, nlines;
    double                             bytes_per_pix = 0;

    pixman_composite_func_t func = pixman_image_composite_wrapper;

    if (!(src_flags & SOLID_FLAG))
    {
        bytes_per_pix += (src_fmt >> 24) / 8.0;
        src_img = pixman_image_create_bits (src_fmt,
                                            WIDTH, HEIGHT,
                                            src,
                                            WIDTH * 4);
        xsrc_img = pixman_image_create_bits (src_fmt,
                                             XWIDTH, XHEIGHT,
                                             src,
                                             XWIDTH * 4);
    }
    else
    {
        src_img = pixman_image_create_bits (src_fmt,
                                            1, 1,
                                            src,
                                            4);
        xsrc_img = pixman_image_create_bits (src_fmt,
                                             1, 1,
                                             src,
                                             4);
        pixman_image_set_repeat (src_img, PIXMAN_REPEAT_NORMAL);
        pixman_image_set_repeat (xsrc_img, PIXMAN_REPEAT_NORMAL);
    }

    bytes_per_pix += (dst_fmt >> 24) / 8.0;
    dst_img = pixman_image_create_bits (dst_fmt,
                                        WIDTH, HEIGHT,
                                        dst,
                                        WIDTH * 4);

    mask_img = NULL;
    xmask_img = NULL;
    if (!(mask_flags & SOLID_FLAG) && mask_fmt != PIXMAN_null)
    {
        bytes_per_pix += (mask_fmt >> 24) / ((op == PIXMAN_OP_SRC) ? 8.0 : 4.0);
        mask_img = pixman_image_create_bits (mask_fmt,
                                             WIDTH, HEIGHT,
                                             mask,
                                             WIDTH * 4);
        xmask_img = pixman_image_create_bits (mask_fmt,
                                             XWIDTH, XHEIGHT,
                                             mask,
                                             XWIDTH * 4);
    }
    else if (mask_fmt != PIXMAN_null)
    {
        mask_img = pixman_image_create_bits (mask_fmt,
                                             1, 1,
                                             mask,
                                             4);
        xmask_img = pixman_image_create_bits (mask_fmt,
                                             1, 1,
                                             mask,
                                             4 * 4);
       pixman_image_set_repeat (mask_img, PIXMAN_REPEAT_NORMAL);
       pixman_image_set_repeat (xmask_img, PIXMAN_REPEAT_NORMAL);
    }
    if ((mask_flags & CA_FLAG) && mask_fmt != PIXMAN_null)
    {
       pixman_image_set_component_alpha (mask_img, 1);
    }
    xdst_img = pixman_image_create_bits (dst_fmt,
                                         XWIDTH, XHEIGHT,
                                         dst,
                                         XWIDTH * 4);


    printf ("%24s %c", testname, func != pixman_image_composite_wrapper ?
            '-' : '=');

    memcpy (src, dst, BUFSIZE);
    memcpy (dst, src, BUFSIZE);

    l1test_width = L1CACHE_SIZE / 8 - 64;
    if (l1test_width < 1)
	l1test_width = 1;
    if (l1test_width > WIDTH - 64)
	l1test_width = WIDTH - 64;
    n = 1 + npix / (l1test_width * 8);
    t1 = gettime ();
#if EXCLUDE_OVERHEAD
    bench_L (op, src_img, mask_img, dst_img, n, pixman_image_composite_empty, l1test_width, 1);
#endif
    t2 = gettime ();
    bench_L (op, src_img, mask_img, dst_img, n, func, l1test_width, 1);
    t3 = gettime ();
    printf ("  L1:%7.2f", (double)n * l1test_width * 1 /
            ((t3 - t2) - (t2 - t1)) / 1000000.);
    fflush (stdout);

    memcpy (src, dst, BUFSIZE);
    memcpy (dst, src, BUFSIZE);

    nlines = (L2CACHE_SIZE / l1test_width) /
	((PIXMAN_FORMAT_BPP(src_fmt) + PIXMAN_FORMAT_BPP(dst_fmt)) / 8);
    if (nlines < 1)
	nlines = 1;
    n = 1 + npix / (l1test_width * nlines);
    t1 = gettime ();
#if EXCLUDE_OVERHEAD
    bench_L (op, src_img, mask_img, dst_img, n, pixman_image_composite_empty, l1test_width, nlines);
#endif
    t2 = gettime ();
    bench_L (op, src_img, mask_img, dst_img, n, func, l1test_width, nlines);
    t3 = gettime ();
    printf ("  L2:%7.2f", (double)n * l1test_width * nlines /
            ((t3 - t2) - (t2 - t1)) / 1000000.);
    fflush (stdout);

    memcpy (src, dst, BUFSIZE);
    memcpy (dst, src, BUFSIZE);

    n = 1 + npix / (WIDTH * HEIGHT);
    t1 = gettime ();
#if EXCLUDE_OVERHEAD
    bench_M (op, src_img, mask_img, dst_img, n, pixman_image_composite_empty);
#endif
    t2 = gettime ();
    bench_M (op, src_img, mask_img, dst_img, n, func);
    t3 = gettime ();
    printf ("  M:%6.2f (%6.2f%%)",
        ((double)n * (WIDTH - 64) * HEIGHT / ((t3 - t2) - (t2 - t1))) / 1000000.,
        ((double)n * (WIDTH - 64) * HEIGHT / ((t3 - t2) - (t2 - t1)) * bytes_per_pix) * (100.0 / bandwidth) );
    fflush (stdout);

    memcpy (src, dst, BUFSIZE);
    memcpy (dst, src, BUFSIZE);

    n = 1 + npix / (8 * TILEWIDTH * TILEWIDTH);
    t1 = gettime ();
#if EXCLUDE_OVERHEAD
    pix_cnt = bench_HT (op, src_img, mask_img, dst_img, n, pixman_image_composite_empty);
#endif
    t2 = gettime ();
    pix_cnt = bench_HT (op, src_img, mask_img, dst_img, n, func);
    t3 = gettime ();
    printf ("  HT:%6.2f", (double)pix_cnt / ((t3 - t2) - (t2 - t1)) / 1000000.);
    fflush (stdout);

    memcpy (src, dst, BUFSIZE);
    memcpy (dst, src, BUFSIZE);

    n = 1 + npix / (8 * TILEWIDTH * TILEWIDTH);
    t1 = gettime ();
#if EXCLUDE_OVERHEAD
    pix_cnt = bench_VT (op, src_img, mask_img, dst_img, n, pixman_image_composite_empty);
#endif
    t2 = gettime ();
    pix_cnt = bench_VT (op, src_img, mask_img, dst_img, n, func);
    t3 = gettime ();
    printf ("  VT:%6.2f", (double)pix_cnt / ((t3 - t2) - (t2 - t1)) / 1000000.);
    fflush (stdout);

    memcpy (src, dst, BUFSIZE);
    memcpy (dst, src, BUFSIZE);

    n = 1 + npix / (8 * TILEWIDTH * TILEWIDTH);
    t1 = gettime ();
#if EXCLUDE_OVERHEAD
    pix_cnt = bench_R (op, src_img, mask_img, dst_img, n, pixman_image_composite_empty, WIDTH, HEIGHT);
#endif
    t2 = gettime ();
    pix_cnt = bench_R (op, src_img, mask_img, dst_img, n, func, WIDTH, HEIGHT);
    t3 = gettime ();
    printf ("  R:%6.2f", (double)pix_cnt / ((t3 - t2) - (t2 - t1)) / 1000000.);
    fflush (stdout);

    memcpy (src, dst, BUFSIZE);
    memcpy (dst, src, BUFSIZE);

    n = 1 + npix / (16 * TINYWIDTH * TINYWIDTH);
    t1 = gettime ();
#if EXCLUDE_OVERHEAD
    pix_cnt = bench_RT (op, src_img, mask_img, dst_img, n, pixman_image_composite_empty, WIDTH, HEIGHT);
#endif
    t2 = gettime ();
    pix_cnt = bench_RT (op, src_img, mask_img, dst_img, n, func, WIDTH, HEIGHT);
    t3 = gettime ();
    printf ("  RT:%6.2f (%4.0fKops/s)\n", (double)pix_cnt / ((t3 - t2) - (t2 - t1)) / 1000000., (double) n / ((t3 - t2) * 1000));

    if (mask_img) {
	pixman_image_unref (mask_img);
	pixman_image_unref (xmask_img);
    }
    pixman_image_unref (src_img);
    pixman_image_unref (dst_img);
    pixman_image_unref (xsrc_img);
    pixman_image_unref (xdst_img);
}

#define PIXMAN_OP_OUT_REV (PIXMAN_OP_OUT_REVERSE)

struct
{
    char *testname;
    int   src_fmt;
    int   src_flags;
    int   op;
    int   mask_fmt;
    int   mask_flags;
    int   dst_fmt;
}
tests_tbl[] =
{
    { "add_8_8_8",             PIXMAN_a8,          0, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_a8 },
    { "add_n_8_8",             PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_a8 },
    { "add_n_8_8888",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_a8r8g8b8 },
    { "add_n_8_x888",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_x8r8g8b8 },
    { "add_n_8_0565",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_r5g6b5 },
    { "add_n_8_1555",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_a1r5g5b5 },
    { "add_n_8_4444",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_a4r4g4b4 },
    { "add_n_8_2222",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_a2r2g2b2 },
    { "add_n_8_2x10",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_x2r10g10b10 },
    { "add_n_8_2a10",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_a8,       0, PIXMAN_a2r10g10b10 },
    { "add_n_8",               PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a8 },
    { "add_n_8888",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a8r8g8b8 },
    { "add_n_x888",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_x8r8g8b8 },
    { "add_n_0565",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "add_n_1555",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a1r5g5b5 },
    { "add_n_4444",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a4r4g4b4 },
    { "add_n_2222",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a2r2g2b2 },
    { "add_n_2x10",            PIXMAN_a2r10g10b10, 1, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_x2r10g10b10 },
    { "add_n_2a10",            PIXMAN_a2r10g10b10, 1, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a2r10g10b10 },
    { "add_8_8",               PIXMAN_a8,          0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a8 },
    { "add_x888_x888",         PIXMAN_x8r8g8b8,    0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_x8r8g8b8 },
    { "add_8888_8888",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a8r8g8b8 },
    { "add_8888_0565",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "add_8888_1555",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a1r5g5b5 },
    { "add_8888_4444",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a4r4g4b4 },
    { "add_8888_2222",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a2r2g2b2 },
    { "add_0565_0565",         PIXMAN_r5g6b5,      0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "add_1555_1555",         PIXMAN_a1r5g5b5,    0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a1r5g5b5 },
    { "add_0565_2x10",         PIXMAN_r5g6b5,      0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_x2r10g10b10 },
    { "add_2a10_2a10",         PIXMAN_a2r10g10b10, 0, PIXMAN_OP_ADD,     PIXMAN_null,     0, PIXMAN_a2r10g10b10 },
    { "src_n_2222",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a2r2g2b2 },
    { "src_n_0565",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "src_n_1555",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a1r5g5b5 },
    { "src_n_4444",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a4r4g4b4 },
    { "src_n_x888",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_x8r8g8b8 },
    { "src_n_8888",            PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a8r8g8b8 },
    { "src_n_2x10",            PIXMAN_a2r10g10b10, 1, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_x2r10g10b10 },
    { "src_n_2a10",            PIXMAN_a2r10g10b10, 1, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a2r10g10b10 },
    { "src_8888_0565",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "src_8888_4444",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a4r4g4b4 },
    { "src_8888_2222",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a2r2g2b2 },
    { "src_8888_2x10",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_x2r10g10b10 },
    { "src_8888_2a10",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a2r10g10b10 },
    { "src_0888_0565",         PIXMAN_r8g8b8,      0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "src_0888_8888",         PIXMAN_r8g8b8,      0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a8r8g8b8 },
    { "src_0888_x888",         PIXMAN_r8g8b8,      0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_x8r8g8b8 },
    { "src_x888_x888",         PIXMAN_x8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_x8r8g8b8 },
    { "src_x888_8888",         PIXMAN_x8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a8r8g8b8 },
    { "src_8888_8888",         PIXMAN_a8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a8r8g8b8 },
    { "src_0565_0565",         PIXMAN_r5g6b5,      0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "src_1555_0565",         PIXMAN_a1r5g5b5,    0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "src_0565_1555",         PIXMAN_r5g6b5,      0, PIXMAN_OP_SRC,     PIXMAN_null,     0, PIXMAN_a1r5g5b5 },
    { "src_n_8_0565",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_r5g6b5 },
    { "src_n_8_1555",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_a1r5g5b5 },
    { "src_n_8_4444",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_a4r4g4b4 },
    { "src_n_8_2222",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_a2r2g2b2 },
    { "src_n_8_x888",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_x8r8g8b8 },
    { "src_n_8_8888",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_a8r8g8b8 },
    { "src_n_8_2x10",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_x2r10g10b10 },
    { "src_n_8_2a10",          PIXMAN_a8r8g8b8,    1, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_a2r10g10b10 },
    { "src_8888_8_0565",       PIXMAN_a8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_r5g6b5 },
    { "src_0888_8_0565",       PIXMAN_r8g8b8,      0, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_r5g6b5 },
    { "src_0888_8_8888",       PIXMAN_r8g8b8,      0, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_a8r8g8b8 },
    { "src_0888_8_x888",       PIXMAN_r8g8b8,      0, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_x8r8g8b8 },
    { "src_x888_8_x888",       PIXMAN_x8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_x8r8g8b8 },
    { "src_x888_8_8888",       PIXMAN_x8r8g8b8,    0, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_a8r8g8b8 },
    { "src_0565_8_0565",       PIXMAN_r5g6b5,      0, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_r5g6b5 },
    { "src_1555_8_0565",       PIXMAN_a1r5g5b5,    0, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_r5g6b5 },
    { "src_0565_8_1555",       PIXMAN_r5g6b5,      0, PIXMAN_OP_SRC,     PIXMAN_a8,       0, PIXMAN_a1r5g5b5 },
    { "over_n_x888",           PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_null,     0, PIXMAN_x8r8g8b8 },
    { "over_n_8888",           PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_null,     0, PIXMAN_a8r8g8b8 },
    { "over_n_0565",           PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "over_n_1555",           PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_null,     0, PIXMAN_a1r5g5b5 },
    { "over_8888_0565",        PIXMAN_a8r8g8b8,    0, PIXMAN_OP_OVER,    PIXMAN_null,     0, PIXMAN_r5g6b5 },
    { "over_8888_x888",        PIXMAN_a8r8g8b8,    0, PIXMAN_OP_OVER,    PIXMAN_null,     0, PIXMAN_x8r8g8b8 },
    { "over_x888_8_0565",      PIXMAN_x8r8g8b8,    0, PIXMAN_OP_OVER,    PIXMAN_a8,       0, PIXMAN_r5g6b5 },
    { "over_n_8_0565",         PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8,       0, PIXMAN_r5g6b5 },
    { "over_n_8_1555",         PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8,       0, PIXMAN_a1r5g5b5 },
    { "over_n_8_4444",         PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8,       0, PIXMAN_a4r4g4b4 },
    { "over_n_8_2222",         PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8,       0, PIXMAN_a2r2g2b2 },
    { "over_n_8_x888",         PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8,       0, PIXMAN_x8r8g8b8 },
    { "over_n_8_8888",         PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8,       0, PIXMAN_a8r8g8b8 },
    { "over_n_8_2x10",         PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8,       0, PIXMAN_x2r10g10b10 },
    { "over_n_8_2a10",         PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8,       0, PIXMAN_a2r10g10b10 },
    { "over_n_8888_8888_ca",   PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8r8g8b8, 2, PIXMAN_a8r8g8b8 },
    { "over_n_8888_x888_ca",   PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8r8g8b8, 2, PIXMAN_x8r8g8b8 },
    { "over_n_8888_0565_ca",   PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8r8g8b8, 2, PIXMAN_r5g6b5 },
    { "over_n_8888_1555_ca",   PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8r8g8b8, 2, PIXMAN_a1r5g5b5 },
    { "over_n_8888_4444_ca",   PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8r8g8b8, 2, PIXMAN_a4r4g4b4 },
    { "over_n_8888_2222_ca",   PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8r8g8b8, 2, PIXMAN_a2r2g2b2 },
    { "over_n_8888_2x10_ca",   PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8r8g8b8, 2, PIXMAN_x2r10g10b10 },
    { "over_n_8888_2a10_ca",   PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OVER,    PIXMAN_a8r8g8b8, 2, PIXMAN_a2r10g10b10 },
    { "over_8888_n_8888",      PIXMAN_a8r8g8b8,    0, PIXMAN_OP_OVER,    PIXMAN_a8,       1, PIXMAN_a8r8g8b8 },
    { "over_8888_n_x888",      PIXMAN_a8r8g8b8,    0, PIXMAN_OP_OVER,    PIXMAN_a8,       1, PIXMAN_x8r8g8b8 },
    { "over_8888_n_0565",      PIXMAN_a8r8g8b8,    0, PIXMAN_OP_OVER,    PIXMAN_a8,       1, PIXMAN_r5g6b5 },
    { "over_8888_n_1555",      PIXMAN_a8r8g8b8,    0, PIXMAN_OP_OVER,    PIXMAN_a8,       1, PIXMAN_a1r5g5b5 },
    { "outrev_n_8_0565",       PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OUT_REV, PIXMAN_a8,       0, PIXMAN_r5g6b5 },
    { "outrev_n_8_1555",       PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OUT_REV, PIXMAN_a8,       0, PIXMAN_a1r5g5b5 },
    { "outrev_n_8_x888",       PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OUT_REV, PIXMAN_a8,       0, PIXMAN_x8r8g8b8 },
    { "outrev_n_8_8888",       PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OUT_REV, PIXMAN_a8,       0, PIXMAN_a8r8g8b8 },
    { "outrev_n_8888_0565_ca", PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OUT_REV, PIXMAN_a8r8g8b8, 2, PIXMAN_r5g6b5 },
    { "outrev_n_8888_1555_ca", PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OUT_REV, PIXMAN_a8r8g8b8, 2, PIXMAN_a1r5g5b5 },
    { "outrev_n_8888_x888_ca", PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OUT_REV, PIXMAN_a8r8g8b8, 2, PIXMAN_x8r8g8b8 },
    { "outrev_n_8888_8888_ca", PIXMAN_a8r8g8b8,    1, PIXMAN_OP_OUT_REV, PIXMAN_a8r8g8b8, 2, PIXMAN_a8r8g8b8 },
};

int
main (int argc, char *argv[])
{
    double x;
    int i;
    char *pattern = argc > 1 ? argv[1] : "all";

    src = aligned_malloc (4096, BUFSIZE * 3);
    memset (src, 0xCC, BUFSIZE * 3);
    dst = src + (BUFSIZE / 4);
    mask = dst + (BUFSIZE / 4);

    printf ("Benchmark for a set of most commonly used functions\n");
    printf ("---\n");
    printf ("All results are presented in millions of pixels per second\n");
    printf ("L1  - small Xx1 rectangle (fitting L1 cache), always blitted at the same\n");
    printf ("      memory location with small drift in horizontal direction\n");
    printf ("L2  - small XxY rectangle (fitting L2 cache), always blitted at the same\n");
    printf ("      memory location with small drift in horizontal direction\n");
    printf ("M   - large %dx%d rectangle, always blitted at the same\n",
            WIDTH - 64, HEIGHT);
    printf ("      memory location with small drift in horizontal direction\n");
    printf ("HT  - random rectangles with %dx%d average size are copied from\n",
            TILEWIDTH, TILEWIDTH);
    printf ("      one %dx%d buffer to another, traversing from left to right\n",
            WIDTH, HEIGHT);
    printf ("      and from top to bottom\n");
    printf ("VT  - random rectangles with %dx%d average size are copied from\n",
            TILEWIDTH, TILEWIDTH);
    printf ("      one %dx%d buffer to another, traversing from top to bottom\n",
            WIDTH, HEIGHT);
    printf ("      and from left to right\n");
    printf ("R   - random rectangles with %dx%d average size are copied from\n",
            TILEWIDTH, TILEWIDTH);
    printf ("      random locations of one %dx%d buffer to another\n",
            WIDTH, HEIGHT);
    printf ("RT  - as R, but %dx%d average sized rectangles are copied\n",
            TINYWIDTH, TINYWIDTH);
    printf ("---\n");
    bandwidth = x = bench_memcpy ();
    printf ("reference memcpy speed = %.1fMB/s (%.1fMP/s for 32bpp fills)\n",
            x / 1000000., x / 4000000);
    printf ("---\n");

    for (i = 0; i < sizeof(tests_tbl) / sizeof(tests_tbl[0]); i++)
    {
	if (strcmp (pattern, "all") == 0 || strstr (tests_tbl[i].testname, pattern))
	{
	    bench_composite (tests_tbl[i].testname,
			     tests_tbl[i].src_fmt,
			     tests_tbl[i].src_flags,
			     tests_tbl[i].op,
			     tests_tbl[i].mask_fmt,
			     tests_tbl[i].mask_flags,
			     tests_tbl[i].dst_fmt,
			     bandwidth/8);
	}
    }

    free (src);
    return 0;
}
