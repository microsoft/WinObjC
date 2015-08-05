AM_CFLAGS = @OPENMP_CFLAGS@
AM_LDFLAGS = @OPENMP_CFLAGS@ @TESTPROGS_EXTRA_LDFLAGS@
LDADD = $(top_builddir)/pixman/libpixman-1.la -lm
INCLUDES = -I$(top_srcdir)/pixman -I$(top_builddir)/pixman

TESTPROGRAMS =			\
	a1-trap-test		\
	pdf-op-test		\
	region-test		\
	region-translate-test	\
	fetch-test		\
	oob-test		\
	trap-crasher		\
	alpha-loop		\
	scaling-crash-test	\
	scaling-helpers-test	\
	gradient-crash-test	\
	alphamap		\
	stress-test		\
	composite-traps-test	\
	blitters-test		\
	scaling-test		\
	affine-test		\
	composite

pdf_op_test_SOURCES = pdf-op-test.c utils.c utils.h
region_test_SOURCES = region-test.c utils.c utils.h
blitters_test_SOURCES = blitters-test.c utils.c utils.h
composite_traps_test_SOURCES = composite-traps-test.c utils.c utils.h
scaling_test_SOURCES = scaling-test.c utils.c utils.h
affine_test_SOURCES = affine-test.c utils.c utils.h
alphamap_SOURCES = alphamap.c utils.c utils.h
alpha_loop_SOURCES = alpha-loop.c utils.c utils.h
composite_SOURCES = composite.c utils.c utils.h
gradient_crash_test_SOURCES = gradient-crash-test.c utils.c utils.h
stress_test_SOURCES = stress-test.c utils.c utils.h
scaling_helpers_test_SOURCES = scaling-helpers-test.c utils.c utils.h

# Benchmarks

BENCHMARKS =			\
	lowlevel-blt-bench

lowlevel_blt_bench_SOURCES = lowlevel-blt-bench.c utils.c utils.h

noinst_PROGRAMS = $(TESTPROGRAMS) $(BENCHMARKS)

TESTS = $(TESTPROGRAMS)
