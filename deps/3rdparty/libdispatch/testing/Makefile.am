#
#
#

noinst_LTLIBRARIES=libtest.la

libtest_la_SOURCES=			\
	dispatch_test.c			\
	shims/asprintf.c		\
	shims/arc4random.c		\
	shims/fgetln.c

TESTS=					\
	dispatch_api			\
	dispatch_c99			\
	dispatch_cascade		\
	dispatch_debug			\
	dispatch_priority		\
	dispatch_priority2		\
	dispatch_starfish		\
	queue_finalizer

dispatch_c99_CFLAGS=-std=c99
dispatch_priority2_SOURCES=dispatch_priority.c
dispatch_priority2_CFLAGS=-DUSE_SET_TARGET_QUEUE=1

if HAVE_CBLOCKS
CBLOCKS_TESTS=				\
	dispatch_after			\
	dispatch_apply			\
	dispatch_drift			\
	dispatch_group			\
	dispatch_pingpong		\
	dispatch_read			\
	dispatch_readsync		\
	dispatch_sema			\
	dispatch_timer_bit31		\
	dispatch_timer_bit63
endif
TESTS+=$(CBLOCKS_TESTS)

if HAVE_CXXBLOCKS
CXXBLOCKS_TESTS=			\
	dispatch_plusplus
dispatch_plusplus_SOURCES=dispatch_plusplus.cpp
endif
TESTS+=$(CXXBLOCKS_TESTS)

if HAVE_CORESERVICES
CORESERVICES_TESTS=			\
	dispatch_cffd
dispatch_cffd_LDFLAGS=-framework CoreFoundation
endif
TESTS+=$(CORESERVICES_TESTS)

if HAVE_POSIX_SPAWN_START_SUSPENDED
POSIX_SPAWN_START_SUSPENDED_TESTS=	\
	dispatch_proc
endif
TESTS+=$(POSIX_SPAWN_START_SUSPENDED_TESTS)

if USE_LEGACY_API
LEGACY_TESTS=				\
	dispatch_timer_set_time
endif
TESTS+=$(LEGACY_TESTS)

#
# XXX: By broken, we mean non-portable.  We should instead test for the OS
# features they depend on, or port them as required.
#
BROKEN_TOOLS=				\
	harness				\
	nsoperation

noinst_PROGRAMS=$(TESTS)

TOOLS=					\
	summarize

noinst_PROGRAMS+=$(TOOLS)

INCLUDES=-I$(top_builddir) -I$(top_srcdir)
LDADD=libtest.la ../src/libdispatch.la
CFLAGS=-Wall $(MARCH_FLAGS) $(CBLOCKS_FLAGS)
CXXFLAGS=-Wall $(MARCH_FLAGS) $(CXXBLOCKS_FLAGS)

