#
#
#

lib_LTLIBRARIES=libdispatch.la
noinst_LTLIBRARIES=libshims.la

libdispatch_la_SOURCES=	\
	apply.c		\
	benchmark.c	\
	object.c	\
	once.c		\
	queue.c		\
	queue_kevent.c	\
	semaphore.c	\
	source.c	\
	source_kevent.c	\
	time.c

libshims_la_SOURCES=	\
	shims/mach.c	\
	shims/time.c	\
	shims/tsd.c

libdispatch_la_CFLAGS=-Wall
INCLUDES=-I$(top_builddir) -I$(top_srcdir) \
	@APPLE_LIBC_SOURCE_PATH@ @APPLE_XNU_SOURCE_PATH@

libdispatch_la_CFLAGS+=$(MARCH_FLAGS) $(CBLOCKS_FLAGS) $(KQUEUE_CFLAGS)

if USE_LEGACY_API
libdispatch_la_SOURCES+=	\
	legacy.c
endif

libdispatch_la_LIBADD=libshims.la $(KQUEUE_LIBS)
libdispatch_la_DEPENDENCIES=libshims.la

if USE_LIBPTHREAD_WORKQUEUE
libdispatch_la_LIBADD+=-lpthread_workqueue
endif

if USE_MIG
libdispatch_la_SOURCES+=	\
	protocolUser.c		\
	protocolServer.c
BUILT_SOURCES=			\
	protocol.h		\
	protocolUser.c		\
	protocolServer.c	\
	protocolServer.h
CLEANFILES=$BUILT_SOURCES

protocol.h protocolUser.c protocolServer.h protocolServer.c: protocol.defs
	$(MIG) -user protocolUser.c -header protocol.h \
	    -server protocolServer.c -sheader protocolServer.h protocol.defs
endif
