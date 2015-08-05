/*
 * Copyright © 2006 Mozilla Corporation
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
 * Authors: Vladimir Vukicevic <vladimir@pobox.com>
 *	    Carl Worth <cworth@cworth.org>
 */

/* Portions of this file come from liboil:
 *
 * LIBOIL - Library of Optimized Inner Loops
 * Copyright (c) 2003,2004 David A. Schleef <ds@schleef.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#define _XOPEN_SOURCE 600	/* for round() */

#include "config.h"

#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#ifdef _POSIX_PRIORITY_SCHEDULING
#include <sched.h>
#endif

#include "cairo-perf.h"

/* timers */

#if defined(HAVE_CLOCK_GETTIME)
#if defined(CLOCK_MONOTONIC_RAW)
#define CLOCK CLOCK_MONOTONIC_RAW
#elif defined(CLOCK_MONOTONIC)
#define CLOCK CLOCK_MONOTONIC
#endif
#endif

#if ! defined(CLOCK)
#if defined(__i386__) || defined(__amd64__)
static inline cairo_perf_ticks_t
oil_profile_stamp_rdtsc (void)
{
    unsigned a, d;
    __asm__ __volatile__("rdtsc" : "=a" (a), "=d" (d));
    return ((uint64_t)a) | (((uint64_t)d) << 32);
}
#define OIL_STAMP oil_profile_stamp_rdtsc
#endif

#if defined(__powerpc__) || defined(__PPC__) || defined(__ppc__)
static inline cairo_perf_ticks_t
oil_profile_stamp_tb (void)
{
    uint32_t junk;
    uint64_t ts;

    __asm__ __volatile__ (
	"1:     mftbu   %1;"
	"       mftb    %0+1;"
	"       mftbu   %0;"
	"       cmpw    %0,%1;"
	"       bne     1b" :
	"=r" (ts), "=r" (junk));

    return ts;
}
#define OIL_STAMP oil_profile_stamp_tb
#endif

#if defined(__alpha__)
static inline cairo_perf_ticks_t
oil_profile_stamp_alpha (void)
{
    unsigned int ts;
    __asm__ __volatile__ ("rpcc %0\n" : "=r"(ts));
    return ts;
}
#define OIL_STAMP oil_profile_stamp_alpha
#endif

#if defined(__s390__)
static cairo_perf_ticks_t
oil_profile_stamp_s390 (void)
{
    uint64_t ts;
    __asm__ __volatile__ ("STCK %0\n" : : "m" (ts));
    return ts;
}
#define OIL_STAMP oil_profile_stamp_s390
#endif
#endif

#if defined(__APPLE__)
#include <mach/mach_time.h>
#undef OIL_STAMP
#define OIL_STAMP mach_absolute_time
#endif


typedef struct _cairo_perf_timer {
#if defined(CLOCK)
    struct timespec tv_start;
    struct timespec tv_stop;
#elif defined(OIL_STAMP)
    cairo_perf_ticks_t start;
    cairo_perf_ticks_t stop;
#else
    struct timeval tv_start;
    struct timeval tv_stop;
#endif
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
cairo_perf_timer_start (void)
{
    if (cairo_perf_timer_synchronize)
	cairo_perf_timer_synchronize (cairo_perf_timer_synchronize_closure);

#if defined(CLOCK)
    clock_gettime (CLOCK, &timer.tv_start);
#elif defined(OIL_STAMP)
    timer.start = OIL_STAMP ();
#else
    gettimeofday (&timer.tv_start, NULL);
#endif
}

void
cairo_perf_timer_stop (void)
{
    if (cairo_perf_timer_synchronize)
	cairo_perf_timer_synchronize (cairo_perf_timer_synchronize_closure);

#if defined(CLOCK)
    clock_gettime (CLOCK, &timer.tv_stop);
#elif defined(OIL_STAMP)
    timer.stop = OIL_STAMP ();
#else
    gettimeofday (&timer.tv_stop, NULL);
#endif
}

cairo_perf_ticks_t
cairo_perf_timer_elapsed (void)
{
    cairo_perf_ticks_t ticks;

#if defined(CLOCK)
    ticks  = timer.tv_stop.tv_sec - timer.tv_start.tv_sec;
    ticks *= 1000000000;
    ticks += timer.tv_stop.tv_nsec - timer.tv_start.tv_nsec;
#elif defined(OIL_STAMP)
    ticks = timer.stop - timer.start;
#else
    ticks  = timer.tv_stop.tv_sec - timer.tv_start.tv_sec;
    ticks *= 1000000;
    ticks += timer.tv_stop.tv_usec - timer.tv_start.tv_usec;
#endif

    return ticks;
}

cairo_perf_ticks_t
cairo_perf_ticks_per_second (void)
{
#if defined(CLOCK)
    /* For clock_gettime() the units are nano-seconds */
    return 1000000000;
#elif defined(OIL_STAMP)
    static cairo_perf_ticks_t tps = 0;
    /* XXX: This is obviously not stable in light of changing CPU speed. */
    if (tps == 0) {
	struct timeval tv_start, tv_stop;
	double tv_elapsed;
	cairo_perf_timer_start ();
	gettimeofday (&tv_start, NULL);
	usleep (20000);
	cairo_perf_timer_stop ();
	gettimeofday (&tv_stop, NULL);
	tv_elapsed = ((tv_stop.tv_sec - tv_start.tv_sec) +
		      + (tv_stop.tv_usec - tv_start.tv_usec) / 1000000.0);
	tps = round (cairo_perf_timer_elapsed () / tv_elapsed);
    }
    return tps;
#else
    /* For gettimeofday() the units are micro-seconds */
    return 1000000;
#endif
}

/* yield */

void
cairo_perf_yield (void)
{
#ifdef _POSIX_PRIORITY_SCHEDULING
    sched_yield ();
#endif
}
