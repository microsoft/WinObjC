# $Id$

DISTCLEANFILES = *~ *.~*

bin_PROGRAMS = tegris
tegris_SOURCES = main.cc

SUBDIRS = engine game
tegris_LDADD = game/libtegris.a engine/libteges.a @GL_LIBS@

dist_pkgdata_DATA = res
