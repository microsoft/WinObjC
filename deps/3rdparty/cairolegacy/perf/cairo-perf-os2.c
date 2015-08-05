/*
 * Copyright (c) 2007 Netlabs
 * Copyright (c) 2006 Mozilla Corporation
 * Copyright (c) 2006 Red Hat, Inc.
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
 * Authors: Peter Weilbacher <mozilla@weilbacher.org>
 *	    Vladimir Vukicevic <vladimir@pobox.com> (win32/linux code)
 *	    Carl Worth <cworth@cworth.org> (win32/linux code)
 */

#define INCL_BASE
#include <os2.h>

#include "cairo-perf.h"

/* timers */
typedef struct _cairo_perf_timer
{
    /* make them double so that they can store the full QWORD precision */
    double start;
    double stop;
} cairo_perf_timer_t;

static cairo_perf_timer_t timer;

static cairo_perf_timer_synchronize_t cairo_perf_timer_synchronize = NULL;
static void *cairo_perf_timer_synchronize_closure = NULL;
void
cairo_perf_timer_set_synchronize (cairo_perf_timer_synchronize_t  synchronize,
				  void				 *closure)
{
    cairo_perf_timer_synchronize = synchronize;
    cairo_perf_timer_synchronize_closure = closure;
}

void
cairo_perf_timer_start (void) {
    QWORD time;

    if (cairo_perf_timer_synchronize)
	cairo_perf_timer_synchronize (cairo_perf_timer_synchronize_closure);
    DosTmrQueryTime(&time);
    timer.start = (time.ulHi*4294967296.0 + time.ulLo);
}

void
cairo_perf_timer_stop (void) {
    QWORD time;

    if (cairo_perf_timer_synchronize)
	cairo_perf_timer_synchronize (cairo_perf_timer_synchronize_closure);
    DosTmrQueryTime(&time);
    timer.stop = (time.ulHi*4294967296.0 + time.ulLo);
}

cairo_perf_ticks_t
cairo_perf_timer_elapsed (void) {
    ULONG freq;

    DosTmrQueryFreq(&freq);
    /* return time difference in milliseconds */
    return (timer.stop - timer.start) / freq * 1000;
}

cairo_perf_ticks_t
cairo_perf_ticks_per_second (void) {
    return 1000; /* in ms */
}


/* yield */
void
cairo_perf_yield (void) {
    /* try to deactivate this thread until the scheduler calls it again */
    DosSleep (0);
}
