lib_LTLIBRARIES = libcairo-gobject.la

AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_builddir)/src

cairoincludedir=$(includedir)/cairo
cairoinclude_HEADERS = cairo-gobject.h
libcairo_gobject_la_SOURCES = \
	cairo-gobject-enums.c \
	cairo-gobject-structs.c \
	$(NULL)

libcairo_gobject_la_CFLAGS = $(CAIRO_CFLAGS) $(GOBJECT_CFLAGS)
libcairo_gobject_la_LDFLAGS = -version-info $(CAIRO_LIBTOOL_VERSION_INFO) -no-undefined $(export_symbols)
libcairo_gobject_la_LIBADD = $(top_builddir)/src/libcairo.la $(CAIRO_LIBS) $(GOBJECT_LIBS)

