/*
 * Copyright © 2006 Red Hat, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without
 * fee, provided that the above copyright notice appear in all copies
 * and that both that copyright notice and this permission notice
 * appear in supporting documentation, and that the name of
 * the authors not be used in advertising or publicity pertaining to
 * distribution of the software without specific, written prior
 * permission. The authors make no representations about the
 * suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE AUTHORS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY SPECIAL,
 * INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
 * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Authors: Carl Worth <cworth@cworth.org>
 */

#include "cairo-stats.h"

static int
_cairo_perf_ticks_cmp (const void *_a,
		       const void *_b)
{
    const cairo_perf_ticks_t *a = _a;
    const cairo_perf_ticks_t *b = _b;

    if (*a > *b)
	return 1;
    if (*a < *b)
	return -1;
    return 0;
}

void
_cairo_stats_compute (cairo_stats_t	 *stats,
		      cairo_perf_ticks_t *values,
		      int		  num_values)
{
    int i;
    double sum, mean, delta, q1, q3, iqr;
    double outlier_min, outlier_max;
    int min_valid, num_valid;

    /* First, identify any outliers, using the definition of "mild
     * outliers" from:
     *
     *		http://en.wikipedia.org/wiki/Outliers
     *
     * Which is that outliers are any values less than Q1 - 1.5 * IQR
     * or greater than Q3 + 1.5 * IQR where Q1 and Q3 are the first
     * and third quartiles and IQR is the inter-quartile range (Q3 -
     * Q1).
     */
    qsort (values, num_values,
	   sizeof (cairo_perf_ticks_t), _cairo_perf_ticks_cmp);

    q1		= values[(1*num_values)/4];
    q3		= values[(3*num_values)/4];

    iqr = q3 - q1;

    outlier_min = q1 - 1.5 * iqr;
    outlier_max = q3 + 1.5 * iqr;

    min_valid = 0;
    while (min_valid < num_values && values[min_valid] < outlier_min)
	min_valid++;

    i = min_valid;
    num_valid = 0;
    while (i + num_valid < num_values && values[i+num_valid] <= outlier_max)
	num_valid++;

    stats->iterations = num_valid;
    stats->min_ticks = values[min_valid];

    sum = 0.0;
    for (i = min_valid; i < min_valid + num_valid; i++) {
	sum += values[i];
	if (values[i] < stats->min_ticks)
	    stats->min_ticks = values[i];
    }

    mean = sum / num_valid;
    stats->median_ticks = values[min_valid + num_valid / 2];

    sum = 0.0;
    for (i = min_valid; i < min_valid + num_valid; i++) {
	delta = values[i] - mean;
	sum += delta * delta;
    }

    /* Let's use a std. deviation normalized to the mean for easier
     * comparison. */
    stats->std_dev = sqrt(sum / num_valid) / mean;
}
