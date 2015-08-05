cairolibdir = $(libdir)/cairo

#bin_SCRIPTS = cairo-fdr
cairolib_LTLIBRARIES = cairo-fdr.la

AM_CPPFLAGS = -I$(top_srcdir)/src \
	      -I$(top_builddir)/src

cairo_fdr_la_SOURCES = fdr.c
cairo_fdr_la_CPPFLAGS = $(AM_CPPFLAGS)
cairo_fdr_la_CFLAGS = $(CAIRO_CFLAGS)
cairo_fdr_la_LDFLAGS = -module -no-undefined
cairo_fdr_la_LIBADD = -ldl
