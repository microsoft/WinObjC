## $Id: Makefile.am,v 1.12 2000/03/12 21:57:01 gjb Exp $
## Process this file with automake to create Makefile.in

SUBDIRS = doc

if HAVE_GUILE
# This gets put in with libcassowary.a
lib_LIBRARIES = libconstraints.a

# While this gets put where guile will look for it
cassoguile_LTLIBRARIES = libconstraints.la
endif

AM_CPPFLAGS = $(CPPEXTRAFLAGS)

GUILE_INCLUDES = @GUILE_INCLUDES@

INCLUDES = -I. -I$(top_srcdir)/c++ -I$(prefix)/include -I$(exec_prefix)/include $(GUILE_INCLUDES)

EXTRA_DIST = cltests.scm

libconstraints_a_SOURCES = cassowary_scm.cc

libconstraints_la_SOURCES = cassowary_scm.cc

libconstraints_a_LIBADD = $(top_builddir)/c++/libcassowary.a

# Below does not -- get error:
# libtool: link: libtool library `libconstraints.la' may not depend on
# uninstalled libraries: ../c++/libcassowary.la
#libconstraints_la_LIBADD = $(top_builddir)/c++/libcassowary.la

# This works, but may require doing a make install from the ../c++ first
# also, guile doesn't load the module properly when I do this
#libconstraints_la_LIBADD = -lcassowary


# The horrid ugly hack that seems to work
# It'd be nice to be able to mention the name of 
# a library from the directory instead of this
libconstraints_la_LIBADD = $(top_builddir)/c++/*.lo @GTL_LIB@

include_HEADERS = \
	cassowary_scm.h \
	cassowary_scm.hpp \
	cl-snarf.h

guile_snarfs=cassowary_scm.x

BUILT_SOURCES=$(guile_snarfs)

# just use `make CC=g++' and the revised guile-snarf which uses ${CC} will work
# for C++ prototype extraction
%.x: %.c
	guile-snarf $(DEFS) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $< > $@

%.x: %.cc
	CC=$(CXX) \
	guile-snarf $(DEFS) $(INCLUDES) $(CPPFLAGS) $(CXXFLAGS) $< > $@

test:
	env GUILE_LOAD_PATH=.:$$GUILE_LOAD_PATH guile -s cltests.scm

