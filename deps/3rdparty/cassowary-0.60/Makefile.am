## $Id: Makefile.am,v 1.12 2000/03/12 21:39:33 gjb Exp $
## Process this file with automake to create Makefile.in

SUBDIRS = \
 c++ \
 guile \
 docs \
 java \
 smalltalk

bin_SCRIPTS = cassowary-config

EXTRA_DIST = ANNOUNCE AUTHORS IMPORTANT INSTALL LICENSE COPYING.LGPL NEWS README THANKS \
		cassowary.spec cassowary-nofd.spec2 scripts/recreate-symlinks \
		GTL.h.patch \
		c++/config.h.in c++/stamp-h.in

distdir_nofd = cassowary-nofd-@VERSION@

distdir-nofd:	distdir
	mv cassowary-@VERSION@ $(distdir_nofd)
	mv $(distdir_nofd)/cassowary-nofd.spec2 $(distdir_nofd)/cassowary-nofd.spec
	rm -f $(distdir_nofd)/cassowary.spec

dist-nofd:	distdir-nofd
	-chmod -R a+r $(distdir_nofd)
	GZIP=$(GZIP_ENV) $(TAR) chozf $(distdir_nofd).tar.gz $(distdir_nofd)
	-rm -rf $(distdir_nofd)
