include $(top_srcdir)/build/Makefile.am.common

SUBDIRS = .

if CAIRO_HAS_GOBJECT_FUNCTIONS
SUBDIRS += cairo-gobject
endif

if CAIRO_HAS_INTERPRETER
SUBDIRS += cairo-script
endif

if CAIRO_HAS_TRACE
SUBDIRS += cairo-trace
if CAIRO_HAS_SCRIPT_SURFACE
if CAIRO_HAS_TEE_SURFACE
SUBDIRS += cairo-fdr
endif
endif
endif

if BUILD_SPHINX
if CAIRO_HAS_SCRIPT_SURFACE
SUBDIRS += cairo-sphinx
endif
endif

AM_CPPFLAGS = -I$(top_srcdir)/src \
	      -I$(top_builddir)/src \
	      -I$(top_srcdir)/util/cairo-script	\
	      $(CAIRO_CFLAGS)

EXTRA_PROGRAMS += show-traps show-edges show-events
if CAIRO_HAS_INTERPRETER
EXTRA_PROGRAMS += trace-to-xml xml-to-trace
endif

trace_to_xml_LDADD = cairo-script/libcairo-script-interpreter.la $(top_builddir)/src/libcairo.la $(CAIRO_LDADD)

xml_to_trace_LDADD = -lexpat

show_traps_SOURCES = show-traps.c
show_traps_CFLAGS = $(gtk_CFLAGS)
#show_traps_LDADD = $(top_builddir)/src/libcairo.la $(gtk_LIBS)
show_traps_LDADD = $(gtk_LIBS)

show_edges_SOURCES = show-edges.c
show_edges_CFLAGS = $(gtk_CFLAGS)
#show_edges_LDADD = $(top_builddir)/src/libcairo.la $(gtk_LIBS)
show_edges_LDADD = $(gtk_LIBS)

show_events_SOURCES = show-events.c
show_events_CFLAGS = $(gtk_CFLAGS)
#show_events_LDADD = $(top_builddir)/src/libcairo.la $(gtk_LIBS)
show_events_LDADD = $(gtk_LIBS)

util: malloc-stats.so backtrace-symbols.so

.la.so:
	$(RM) $@
	$(LN_S) .libs/$*.so $@

CLEANFILES += *.so

# The -rpath is needed to build shared objects that are not installed,
# ie. with EXTRA_LTLIBRARIES
AM_LDFLAGS = -module -avoid-version -export-dynamic -rpath /dev/null

EXTRA_LTLIBRARIES += malloc-stats.la backtrace-symbols.la

backtrace_symbols_la_LIBADD = -lbfd -liberty

#malloc_stats_la_LIBADD  = $(backtrace_symbols_la_LIBADD) backtrace-symbols.lo

if HAVE_GTK
EXTRA_PROGRAMS += font-view
font_view_CFLAGS = $(gtk_CFLAGS)
font_view_LDADD = ../src/libcairo.la $(gtk_LIBS)
endif

EXTRA_DIST += \
	COPYING \
	xr2cairo \
	cairo-api-update \
	cairo-view \
	waterfall
