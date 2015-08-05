# $Id$

DISTCLEANFILES = *~ *.~*

noinst_LIBRARIES = libteges.a

libteges_a_SOURCES = \
	logger.h \
	teges_object.h teges_object.cc \
	model.h        model.cc \
	interactive.h  interactive.cc \
	manager.h      manager.cc \
	dj.h           dj.cc \
	texturer.h     texturer.cc \
	scriber.h      scriber.cc \
	shadower.h     shadower.cc \
	objector.h     objector.cc \
	               teges_gameinterface.cc \
	               teges_loop.cc \
	teges.h        teges.cc

INCLUDES = -I@top_srcdir@/ -DGL_GLEXT_PROTOTYPES
