/*
 * Copyright © 2006 Red Hat, Inc.
 * Copyright © 2009 Chris Wilson
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without
 * fee, provided that the above copyright notice appear in all copies
 * and that both that copyright notice and this permission notice
 * appear in supporting documentation, and that the name of the
 * copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission. The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 *
 * Authors: Carl Worth <cworth@cworth.org>
 *	    Chris Wilson <chris@chris-wilson.co.uk>
 */

#include "cairo-perf.h"

#include <stdio.h>

static void
report_print (const cairo_perf_report_t *report)
{
    const test_report_t *tests;

    tests = report->tests;
    for (tests = report->tests; tests->name != NULL; tests++) {
	if (tests->stats.iterations == 0)
	    continue;

	if (tests->size) {
	    printf ("%5s-%-4s %26s-%-3d  %6.2f %4.2f%%\n",
		    tests->backend, tests->content,
		    tests->name, tests->size,
		    tests->stats.median_ticks / tests->stats.ticks_per_ms,
		    tests->stats.std_dev * 100);
	} else {
	    printf ("%5s %26s  %6.2f %4.2f%%\n",
		    tests->backend, tests->name,
		    tests->stats.median_ticks / tests->stats.ticks_per_ms,
		    tests->stats.std_dev * 100);
	}
    }
}

int
main (int	  argc,
      const char *argv[])
{
    int i;

    for (i = 1; i < argc; i++ ) {
	cairo_perf_report_t report;

	cairo_perf_report_load (&report, argv[i], NULL);
	report_print (&report);
    }

    return 0;
}
