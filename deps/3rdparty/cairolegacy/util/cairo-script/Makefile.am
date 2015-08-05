SUBDIRS = examples

lib_LTLIBRARIES = libcairo-script-interpreter.la
EXTRA_PROGRAMS = csi-replay csi-exec csi-bind

AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_builddir)/src

cairoincludedir=$(includedir)/cairo
cairoinclude_HEADERS = cairo-script-interpreter.h
libcairo_script_interpreter_la_SOURCES = \
	cairo-script-private.h \
	cairo-script-file.c \
	cairo-script-hash.c \
	cairo-script-interpreter.c \
	cairo-script-objects.c \
	cairo-script-operators.c \
	cairo-script-scanner.c \
	cairo-script-stack.c \
	$(NULL)
libcairo_script_interpreter_la_CFLAGS = $(CAIRO_CFLAGS)
libcairo_script_interpreter_la_LDFLAGS = -version-info $(CAIRO_LIBTOOL_VERSION_INFO) -no-undefined $(export_symbols)
libcairo_script_interpreter_la_LIBADD = $(top_builddir)/src/libcairo.la $(CAIRO_LIBS) -lz

csi_replay_SOURCES = csi-replay.c
csi_replay_CFLAGS = $(CAIRO_CFLAGS)
csi_replay_LDADD = libcairo-script-interpreter.la $(top_builddir)/src/libcairo.la $(CAIRO_LIBS)

csi_exec_SOURCES = csi-exec.c
csi_exec_LDADD = libcairo-script-interpreter.la $(top_builddir)/src/libcairo.la $(CAIRO_LIBS)

if CAIRO_HAS_SCRIPT_SURFACE
EXTRA_PROGRAMS += csi-trace
csi_trace_SOURCES = csi-trace.c
csi_trace_LDADD = libcairo-script-interpreter.la $(top_builddir)/src/libcairo.la $(CAIRO_LIBS)
endif

EXTRA_DIST = \
	COPYING
