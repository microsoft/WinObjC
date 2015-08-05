if HAVE_GTK

AM_CFLAGS = @OPENMP_CFLAGS@
AM_LDFLAGS = @OPENMP_CFLAGS@

LDADD = $(top_builddir)/pixman/libpixman-1.la -lm $(GTK_LIBS)
INCLUDES = -I$(top_srcdir)/pixman -I$(top_builddir)/pixman $(GTK_CFLAGS)

GTK_UTILS = gtk-utils.c gtk-utils.h

DEMOS =				\
	clip-test		\
	clip-in			\
	composite-test		\
	gradient-test		\
	radial-test		\
	alpha-test		\
	screen-test		\
	convolution-test	\
	trap-test		\
	tri-test

gradient_test_SOURCES = gradient-test.c $(GTK_UTILS)
alpha_test_SOURCES = alpha-test.c $(GTK_UTILS)
composite_test_SOURCES = composite-test.c $(GTK_UTILS)
clip_test_SOURCES = clip-test.c $(GTK_UTILS)
clip_in_SOURCES = clip-in.c $(GTK_UTILS)
trap_test_SOURCES = trap-test.c $(GTK_UTILS)
screen_test_SOURCES = screen-test.c $(GTK_UTILS)
convolution_test_SOURCES = convolution-test.c $(GTK_UTILS)
radial_test_SOURCES = radial-test.c ../test/utils.c ../test/utils.h $(GTK_UTILS)
tri_test_SOURCES = tri-test.c ../test/utils.c ../test/utils.h $(GTK_UTILS)

noinst_PROGRAMS = $(DEMOS)

endif
