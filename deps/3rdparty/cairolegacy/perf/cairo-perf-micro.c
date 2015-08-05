/* -*- Mode: c; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 8; -*- */
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

#define _GNU_SOURCE 1	/* for sched_getaffinity() */

#include "../cairo-version.h" /* for the real version */

#include "cairo-perf.h"
#include "cairo-stats.h"

#include "cairo-boilerplate-getopt.h"

/* For basename */
#ifdef HAVE_LIBGEN_H
#include <libgen.h>
#endif

#if HAVE_FCFINI
#include <fontconfig/fontconfig.h>
#endif

#ifdef HAVE_SCHED_H
#include <sched.h>
#endif

#define CAIRO_PERF_ITERATIONS_DEFAULT		100
#define CAIRO_PERF_LOW_STD_DEV			0.03
#define CAIRO_PERF_STABLE_STD_DEV_COUNT 	5
#define CAIRO_PERF_ITERATION_MS_DEFAULT 	2000
#define CAIRO_PERF_ITERATION_MS_FAST		5

typedef struct _cairo_perf_case {
    CAIRO_PERF_DECL (*run);
    unsigned int min_size;
    unsigned int max_size;
} cairo_perf_case_t;

const cairo_perf_case_t perf_cases[];

static const char *
_content_to_string (cairo_content_t content,
		    cairo_bool_t    similar)
{
    switch (content|similar) {
    case CAIRO_CONTENT_COLOR:
	return "rgb";
    case CAIRO_CONTENT_COLOR|1:
	return "rgb&";
    case CAIRO_CONTENT_ALPHA:
	return "a";
    case CAIRO_CONTENT_ALPHA|1:
	return "a&";
    case CAIRO_CONTENT_COLOR_ALPHA:
	return "rgba";
    case CAIRO_CONTENT_COLOR_ALPHA|1:
	return "rgba&";
    default:
	return "<unknown_content>";
    }
}

static cairo_bool_t
cairo_perf_has_similar (cairo_perf_t *perf)
{
    cairo_surface_t *target;

    if (getenv ("CAIRO_TEST_SIMILAR") == NULL)
	return FALSE;

    /* exclude the image backend */
    target = cairo_get_target (perf->cr);
    if (cairo_surface_get_type (target) == CAIRO_SURFACE_TYPE_IMAGE)
	return FALSE;

    return TRUE;
}

cairo_bool_t
cairo_perf_can_run (cairo_perf_t *perf,
		    const char	 *name,
		    cairo_bool_t *is_explicit)
{
    unsigned int i;

    if (is_explicit)
	*is_explicit = FALSE;

    if (perf->num_names == 0)
	return TRUE;

    for (i = 0; i < perf->num_names; i++) {
	if (strstr (name, perf->names[i])) {
	    if (is_explicit)
		*is_explicit = FALSE;
	    return TRUE;
	}
    }

    return FALSE;
}

static unsigned
cairo_perf_calibrate (cairo_perf_t	*perf,
		      cairo_perf_func_t  perf_func)
{
    cairo_perf_ticks_t calibration, calibration_max;
    unsigned loops, min_loops;

    min_loops = 1;
    calibration = perf_func (perf->cr, perf->size, perf->size, min_loops);

    if (!perf->fast_and_sloppy) {
	calibration_max = perf->ms_per_iteration * 0.0001 / 4 * cairo_perf_ticks_per_second ();
	while (calibration < calibration_max) {
	    min_loops *= 2;
	    calibration = perf_func (perf->cr, perf->size, perf->size, min_loops);
	}
    }

    /* XXX
     * Compute the number of loops required for the timing
     * interval to be perf->ms_per_iteration milliseconds. This
     * helps to eliminate sampling variance due to timing and
     * other systematic errors.  However, it also hides
     * synchronisation overhead as we attempt to process a large
     * batch of identical operations in a single shot. This can be
     * considered both good and bad... It would be good to perform
     * a more rigorous analysis of the synchronisation overhead,
     * that is to estimate the time for loop=0.
     */
    loops = perf->ms_per_iteration * 0.001 * cairo_perf_ticks_per_second () * min_loops / calibration;
    min_loops = perf->fast_and_sloppy ? 1 : 10;
    if (loops < min_loops)
	loops = min_loops;

    return loops;
}

void
cairo_perf_run (cairo_perf_t	   *perf,
		const char	   *name,
		cairo_perf_func_t   perf_func,
		cairo_count_func_t  count_func)
{
    static cairo_bool_t first_run = TRUE;
    unsigned int i, similar, has_similar;
    cairo_perf_ticks_t *times;
    cairo_stats_t stats = {0.0, 0.0};
    int low_std_dev_count;

    if (perf->list_only) {
	printf ("%s\n", name);
	return;
    }

    if (first_run) {
	if (perf->raw) {
	    printf ("[ # ] %s.%-s %s %s %s ...\n",
		    "backend", "content", "test-size", "ticks-per-ms", "time(ticks)");
	}

	if (perf->summary) {
	    fprintf (perf->summary,
		     "[ # ] %8s.%-4s %28s %8s %8s %5s %5s %s %s\n",
		     "backend", "content", "test-size", "min(ticks)", "min(ms)", "median(ms)",
		     "stddev.", "iterations", "overhead");
	}
	first_run = FALSE;
    }

    times = perf->times;

    if (getenv ("CAIRO_PERF_OUTPUT") != NULL) { /* check output */
	char *filename;
	cairo_status_t status;

	xasprintf (&filename, "%s.%s.%s.%d.out.png",
		   name, perf->target->name,
		   _content_to_string (perf->target->content, 0),
		   perf->size);
	perf_func (perf->cr, perf->size, perf->size, 1);
	status = cairo_surface_write_to_png (cairo_get_target (perf->cr), filename);
	if (status) {
	    fprintf (stderr, "Failed to generate output check '%s': %s\n",
		     filename, cairo_status_to_string (status));
	    return;
	}

	free (filename);
    }

    has_similar = cairo_perf_has_similar (perf);
    for (similar = 0; similar <= has_similar; similar++) {
	unsigned loops;

	if (perf->summary) {
	    fprintf (perf->summary,
		     "[%3d] %8s.%-5s %26s.%-3d ",
		     perf->test_number, perf->target->name,
		     _content_to_string (perf->target->content, similar),
		     name, perf->size);
	    fflush (perf->summary);
	}

	/* We run one iteration in advance to warm caches and calibrate. */
	cairo_perf_yield ();
	if (similar)
	    cairo_push_group_with_content (perf->cr,
					   cairo_boilerplate_content (perf->target->content));
	perf_func (perf->cr, perf->size, perf->size, 1);
	loops = cairo_perf_calibrate (perf, perf_func);
	if (similar)
	    cairo_pattern_destroy (cairo_pop_group (perf->cr));

	low_std_dev_count = 0;
	for (i =0; i < perf->iterations; i++) {
	    cairo_perf_yield ();
	    if (similar)
		cairo_push_group_with_content (perf->cr,
					       cairo_boilerplate_content (perf->target->content));
	    times[i] = perf_func (perf->cr, perf->size, perf->size, loops) / loops;
	    if (similar)
		cairo_pattern_destroy (cairo_pop_group (perf->cr));

	    if (perf->raw) {
		if (i == 0)
		    printf ("[*] %s.%s %s.%d %g",
			    perf->target->name,
			    _content_to_string (perf->target->content, similar),
			    name, perf->size,
			    cairo_perf_ticks_per_second () / 1000.0);
		printf (" %lld", (long long) times[i]);
	    } else if (! perf->exact_iterations) {
		if (i > 0) {
		    _cairo_stats_compute (&stats, times, i+1);

		    if (stats.std_dev <= CAIRO_PERF_LOW_STD_DEV) {
			low_std_dev_count++;
			if (low_std_dev_count >= CAIRO_PERF_STABLE_STD_DEV_COUNT)
			    break;
		    } else {
			low_std_dev_count = 0;
		    }
		}
	    }
	}

	if (perf->raw)
	    printf ("\n");

	if (perf->summary) {
	    _cairo_stats_compute (&stats, times, i);
	    if (count_func != NULL) {
		double count = count_func (perf->cr, perf->size, perf->size);
		fprintf (perf->summary,
			 "%10lld %#8.3f %#8.3f %#5.2f%% %3d: %.2f\n",
			 (long long) stats.min_ticks,
			 (stats.min_ticks * 1000.0) / cairo_perf_ticks_per_second (),
			 (stats.median_ticks * 1000.0) / cairo_perf_ticks_per_second (),
			 stats.std_dev * 100.0, stats.iterations,
			 count * cairo_perf_ticks_per_second () / stats.min_ticks);
	    } else {
		fprintf (perf->summary,
			 "%10lld %#8.3f %#8.3f %#5.2f%% %3d\n",
			 (long long) stats.min_ticks,
			 (stats.min_ticks * 1000.0) / cairo_perf_ticks_per_second (),
			 (stats.median_ticks * 1000.0) / cairo_perf_ticks_per_second (),
			 stats.std_dev * 100.0, stats.iterations);
	    }
	    fflush (perf->summary);
	}

	perf->test_number++;
    }
}

static void
usage (const char *argv0)
{
    fprintf (stderr,
"Usage: %s [-l] [-r] [-v] [-i iterations] [test-names ...]\n"
"       %s -l\n"
"\n"
"Run the cairo performance test suite over the given tests (all by default)\n"
"The command-line arguments are interpreted as follows:\n"
"\n"
"  -r	raw; display each time measurement instead of summary statistics\n"
"  -v	verbose; in raw mode also show the summaries\n"
"  -i	iterations; specify the number of iterations per test case\n"
"  -l	list only; just list selected test case names without executing\n"
"\n"
"If test names are given they are used as sub-string matches so a command\n"
"such as \"cairo-perf text\" can be used to run all text test cases.\n",
	     argv0, argv0);
}

static void
parse_options (cairo_perf_t *perf,
	       int	     argc,
	       char	    *argv[])
{
    int c;
    const char *iters;
    const char *ms = NULL;
    char *end;
    int verbose = 0;

    if ((iters = getenv("CAIRO_PERF_ITERATIONS")) && *iters)
	perf->iterations = strtol(iters, NULL, 0);
    else
	perf->iterations = CAIRO_PERF_ITERATIONS_DEFAULT;
    perf->exact_iterations = 0;

    perf->fast_and_sloppy = FALSE;
    perf->ms_per_iteration = CAIRO_PERF_ITERATION_MS_DEFAULT;
    if ((ms = getenv("CAIRO_PERF_ITERATION_MS")) && *ms) {
	perf->ms_per_iteration = atof(ms);
    }

    perf->raw = FALSE;
    perf->list_only = FALSE;
    perf->names = NULL;
    perf->num_names = 0;
    perf->summary = stdout;

    while (1) {
	c = _cairo_getopt (argc, argv, "i:lrvf");
	if (c == -1)
	    break;

	switch (c) {
	case 'i':
	    perf->exact_iterations = TRUE;
	    perf->iterations = strtoul (optarg, &end, 10);
	    if (*end != '\0') {
		fprintf (stderr, "Invalid argument for -i (not an integer): %s\n",
			 optarg);
		exit (1);
	    }
	    break;
	case 'l':
	    perf->list_only = TRUE;
	    break;
	case 'r':
	    perf->raw = TRUE;
	    perf->summary = NULL;
	    break;
	case 'f':
	    perf->fast_and_sloppy = TRUE;
	    if (ms == NULL)
		perf->ms_per_iteration = CAIRO_PERF_ITERATION_MS_FAST;
	    break;
	case 'v':
	    verbose = 1;
	    break;
	default:
	    fprintf (stderr, "Internal error: unhandled option: %c\n", c);
	    /* fall-through */
	case '?':
	    usage (argv[0]);
	    exit (1);
	}
    }

    if (verbose && perf->summary == NULL)
	perf->summary = stderr;

    if (optind < argc) {
	perf->names = &argv[optind];
	perf->num_names = argc - optind;
    }
}

static int 
check_cpu_affinity (void)
{
#ifdef HAVE_SCHED_GETAFFINITY

    cpu_set_t affinity;
    int i, cpu_count;

    if (sched_getaffinity(0, sizeof(affinity), &affinity)) {
	perror("sched_getaffinity");
	return -1;
    }

    for(i = 0, cpu_count = 0; i < CPU_SETSIZE; ++i) {
	if (CPU_ISSET(i, &affinity))
	    ++cpu_count;
    }

    if (cpu_count > 1) {
	fputs(
	    "WARNING: cairo-perf has not been bound to a single CPU.\n",
	    stderr);
	return -1;
    }

    return 0;
#else
    fputs(
	"WARNING: Cannot check CPU affinity for this platform.\n",
	stderr);
    return -1;
#endif
}

static void
cairo_perf_fini (cairo_perf_t *perf)
{
    cairo_boilerplate_free_targets (perf->targets);
    cairo_boilerplate_fini ();

    free (perf->times);
    cairo_debug_reset_static_data ();
#if HAVE_FCFINI
    FcFini ();
#endif
}


int
main (int   argc,
      char *argv[])
{
    int i, j;
    cairo_perf_t perf;
    cairo_surface_t *surface;

    parse_options (&perf, argc, argv);

    if (check_cpu_affinity()) {
	fputs(
	    "NOTICE: cairo-perf and the X server should be bound to CPUs (either the same\n"
	    "or separate) on SMP systems. Not doing so causes random results when the X\n"
	    "server is moved to or from cairo-perf's CPU during the benchmarks:\n"
	    "\n"
	    "    $ sudo taskset -cp 0 $(pidof X)\n"
	    "    $ taskset -cp 1 $$\n"
	    "\n"
	    "See taskset(1) for information about changing CPU affinity.\n",
	    stderr);
    }

    perf.targets = cairo_boilerplate_get_targets (&perf.num_targets, NULL);
    perf.times = xmalloc (perf.iterations * sizeof (cairo_perf_ticks_t));

    for (i = 0; i < perf.num_targets; i++) {
	const cairo_boilerplate_target_t *target = perf.targets[i];

	if (! target->is_measurable)
	    continue;

	perf.target = target;
	perf.test_number = 0;

	for (j = 0; perf_cases[j].run; j++) {
	    const cairo_perf_case_t *perf_case = &perf_cases[j];

	    for (perf.size = perf_case->min_size;
		 perf.size <= perf_case->max_size;
		 perf.size *= 2)
	    {
		void *closure;

		surface = (target->create_surface) (NULL,
						    target->content,
						    perf.size, perf.size,
						    perf.size, perf.size,
						    CAIRO_BOILERPLATE_MODE_PERF,
						    0,
						    &closure);
		if (surface == NULL) {
		    fprintf (stderr,
			     "Error: Failed to create target surface: %s\n",
			     target->name);
		    continue;
		}

		cairo_perf_timer_set_synchronize (target->synchronize, closure);

		perf.cr = cairo_create (surface);

		perf_case->run (&perf, perf.cr, perf.size, perf.size);

		if (cairo_status (perf.cr)) {
		    fprintf (stderr, "Error: Test left cairo in an error state: %s\n",
			     cairo_status_to_string (cairo_status (perf.cr)));
		}

		cairo_destroy (perf.cr);
		cairo_surface_destroy (surface);

		if (target->cleanup)
		    target->cleanup (closure);
	    }
	}
    }

    cairo_perf_fini (&perf);

    return 0;
}

const cairo_perf_case_t perf_cases[] = {
    { paint,  64, 512},
    { paint_with_alpha,  64, 512},
    { fill,   64, 512},
    { stroke, 64, 512},
    { text,   64, 512},
    { glyphs, 64, 512},
    { mask,   64, 512},
    { tessellate, 100, 100},
    { subimage_copy, 16, 512},
    { pattern_create_radial, 16, 16},
    { zrusin, 415, 415},
    { world_map, 800, 800},
    { box_outline, 100, 100},
    { mosaic, 800, 800 },
    { long_lines, 100, 100},
    { unaligned_clip, 100, 100},
    { rectangles, 512, 512},
    { rounded_rectangles, 512, 512},
    { long_dashed_lines, 512, 512},
    { composite_checker, 16, 512},
    { twin, 800, 800},
    { dragon, 1024, 1024 },
    { pythagoras_tree, 768, 768 },
    { intersections, 512, 512 },
    { spiral, 512, 512 },
    { NULL }
};
