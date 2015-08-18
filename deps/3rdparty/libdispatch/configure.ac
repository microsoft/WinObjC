#
# When this file changes, rerun autogen.sh.
#

AC_PREREQ(2.59)
AC_INIT([libdispatch], [1.0], [libdispatch@macosforge.org], [libdispatch])
AC_REVISION([$$])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADER([config/config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_USE_SYSTEM_EXTENSIONS
AM_MAINTAINER_MODE

#
# On Mac OS X, some required header files come from other source packages;
# allow specifying where those are.
#
AC_ARG_WITH([apple-libc-source],
  [AS_HELP_STRING([--with-apple-libc-source],
    [Specify path to Apple Libc source])],
  [apple_libc_source_path=${withval}/pthreads
    APPLE_LIBC_SOURCE_PATH=-I$apple_libc_source_path
    CPPFLAGS="$CPPFLAGS -I$apple_libc_source_path"],
  [APPLE_LIBC_SOURCE_PATH=]
)
AC_SUBST([APPLE_LIBC_SOURCE_PATH])

AC_ARG_WITH([apple-xnu-source],
  [AS_HELP_STRING([--with-apple-xnu-source],
    [Specify path to Apple XNU source])],
  [apple_xnu_source_path=${withval}/libkern
    APPLE_XNU_SOURCE_PATH=-I$apple_xnu_source_path
    CPPFLAGS="$CPPFLAGS -I$apple_xnu_source_path"],
  [APPLE_XNU_SOURCE_PATH=]
)
AC_SUBST([APPLE_XNU_SOURCE_PATH])

AC_CACHE_CHECK([for System.framework/PrivateHeaders], dispatch_cv_system_privateheaders,
  [AS_IF([test -d /System/Library/Frameworks/System.framework/PrivateHeaders],
    [dispatch_cv_system_privateheaders=yes], [dispatch_cv_system_privateheaders=no])]
)
AS_IF([test "x$dispatch_cv_system_privateheaders" != "xno"],
  [CPPFLAGS="$CPPFLAGS -I/System/Library/Frameworks/System.framework/PrivateHeaders"]
)

#
# Try to build the legacy API only if specifically requested.
#
AC_ARG_ENABLE([legacy-api],
  [AS_HELP_STRING([--enable-legacy-api], [Enable legacy (deprecated) API.])]
)

AS_IF([test "x$enable_legacy_api" != "xyes"],
  [use_legacy_api=false
    AC_DEFINE(DISPATCH_NO_LEGACY, 1,[Define to compile out legacy API])],
  [use_legacy_api=true]
)
AM_CONDITIONAL(USE_LEGACY_API, $use_legacy_api)

#
# On Mac OS X Snow Leopard, libpispatch_init is automatically invoked during
# libsyscall process setup.  On other systems, it is tagged as a library
# constructor to be run by automatically by the runtime linker.
#
AC_ARG_ENABLE([libdispatch-init-constructor],
  [AS_HELP_STRING([--disable-libdispatch-init-constructor],
    [Disable libdispatch_init as a constructor])]
)

AS_IF([test "x$enable_libdispatch_init_constructor" != "xno"],
  [AC_DEFINE(USE_LIBDISPATCH_INIT_CONSTRUCTOR, 1,
    [Define to tag libdispatch_init as a constructor])]
)

#
# Whether or not to include/reference a crashreporter symbol.
#
AC_ARG_ENABLE([apple-crashreporter-info],
  [AS_HELP_STRING([--enable-apple-crashreporter-info],
    [Use Mac OS X crashreporter info])]
)

AS_IF([test "x$enable_apple_crashreporter_info" = "xyes"],
  [AC_DEFINE(USE_APPLE_CRASHREPORTER_INFO, 1,
    [Define to use Mac OS X crashreporter info])]
)

#
# libdispatch has micro-optimized and deeply personal knowledge of Mac OS
# implementation details.  Only enable this if explicitly requested, as it
# will lead to data corruption if applied on systems violating its
# expectations.
#
AC_ARG_ENABLE([apple-tsd-optimizations],
  [AS_HELP_STRING([--enable-apple-tsd-optimizations],
    [Use non-portable pthread TSD optimizations for Mac OS X.])]
)

AS_IF([test "x$enable_apple_tsd_optimizations" = "xyes"],
  [AC_DEFINE(USE_APPLE_TSD_OPTIMIZATIONS, 1,
    [Define to use non-portable pthread TSD optimizations for Mac OS X)])]
)

AC_ARG_ENABLE([apple-semaphore-optimizations],
  [AS_HELP_STRING([--enable-apple-semaphore-optimizations],
    [Use non-portable semaphore optimizations for Mac OS X.])]
)

AS_IF([test "x$enable_apple_semaphore_optimizations" = "xyes"],
  [AC_DEFINE(USE_APPLE_SEMAPHORE_OPTIMIZATIONS, 1,
    [Define to use non-portablesemaphore optimizations for Mac OS X])]
)

AC_USE_SYSTEM_EXTENSIONS
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PATH_PROGS(MIG, mig)

AC_PATH_PROG(LEAKS, leaks)
AS_IF([test "x$LEAKS" != "x"],
  [AC_DEFINE(HAVE_LEAKS, 1, [Define if Apple leaks program is present])]
)

AM_INIT_AUTOMAKE([foreign])

DISPATCH_C_ATOMIC_BUILTINS

case $dispatch_cv_atomic in
  yes) ;;
  -march*) MARCH_FLAGS="$dispatch_cv_atomic"
         AC_SUBST([MARCH_FLAGS]) ;;
  *) AC_MSG_ERROR([No gcc builtin atomic operations available]) ;;
esac

#
# Find libraries we will need
#
AC_SEARCH_LIBS(clock_gettime, rt)
AC_SEARCH_LIBS(pthread_create, pthread)

#
# Prefer native kqueue(2); otherwise use libkqueue if present.
#
AC_CHECK_HEADER(sys/event.h, [],
  [PKG_CHECK_MODULES(KQUEUE, libkqueue)]
)

#
# Checks for header files.
#
AC_HEADER_STDC
AC_CHECK_HEADERS([TargetConditionals.h pthread_machdep.h pthread_np.h malloc/malloc.h libkern/OSCrossEndian.h libkern/OSAtomic.h sys/sysctl.h])

#
# Core Services is tested in one of the GCD regression tests, so test for its
# presence using its header file.
#
AC_CHECK_HEADER([CoreServices/CoreServices.h],
  [have_coreservices=true],
  [have_coreservices=false]
)
AM_CONDITIONAL(HAVE_CORESERVICES, $have_coreservices)

#
# We use the availability of mach.h to decide whether to compile in all sorts
# of Machisms, including using Mach ports as event sources, etc.
#
AC_CHECK_HEADER([mach/mach.h],
  [AC_DEFINE(HAVE_MACH, 1,Define if mach is present)
    have_mach=true],
  [have_mach=false]
)
AM_CONDITIONAL(USE_MIG, $have_mach)

#
# We use the availability of pthread_workqueue.h to decide whether to compile
# in support for pthread work queues.
#
AC_CHECK_HEADER([pthread_workqueue.h],
  [AC_DEFINE(HAVE_PTHREAD_WORKQUEUES, 1,Define if pthread work queues are present)]
)

#
# Check if libpthread_workqueue.so exists
#
AC_CHECK_LIB(pthread_workqueue, pthread_workqueue_init_np,
        have_lpwq=true, have_lpwq=false)
AM_CONDITIONAL(USE_LIBPTHREAD_WORKQUEUE, $have_lpwq)

#
# Find functions and declarations we care about.
#
AC_CHECK_DECLS([CLOCK_UPTIME, CLOCK_MONOTONIC, CLOCK_REALTIME], [], [],
  [[#include <time.h>]])
AC_CHECK_DECLS([EVFILT_LIO, EVFILT_SESSION, NOTE_NONE, NOTE_REAP, NOTE_REVOKE, NOTE_SIGNAL], [], [],
  [[#include <sys/types.h>
#include <sys/event.h>]])
AC_CHECK_DECLS([FD_COPY], [], [], [[#include <sys/select.h>]])
AC_CHECK_DECLS([SIGEMT], [], [], [[#include <signal.h>]])
AC_CHECK_DECLS([VQ_UPDATE, VQ_VERYLOWDISK], [], [], [[#include <sys/mount.h>]])
AC_CHECK_DECLS([program_invocation_short_name], [], [], [[#include <errno.h>]])
AC_CHECK_FUNCS([pthread_key_init_np pthread_main_np mach_absolute_time malloc_create_zone sysconf getprogname getexecname vasprintf asprintf arc4random fgetln])

AC_CHECK_DECLS([POSIX_SPAWN_START_SUSPENDED],
  [have_posix_spawn_start_suspended=true],
  [have_posix_spawn_start_suspended=false],
  [[#include <sys/spawn.h>]]
)
AM_CONDITIONAL(HAVE_POSIX_SPAWN_START_SUSPENDED, $have_posix_spawn_start_suspended)

AC_CHECK_FUNC([sem_init],
  [have_sem_init=true],
  [have_sem_init=false]
)

#
# We support both Mach semaphores and POSIX semaphores; if the former are
# available, prefer them.
#
AC_MSG_CHECKING([what semaphore type to use]);
AS_IF([test "x$have_mach" = "xtrue"],
  [AC_DEFINE(USE_MACH_SEM, 1,[Define to use Mach semaphores])
    AC_MSG_RESULT([Mach semaphores])],
  [test "x$have_sem_init" = "xtrue"],
  [AC_DEFINE(USE_POSIX_SEM, 1,[Define to use POSIX semaphores])
    AC_MSG_RESULT([POSIX semaphores])],
  [AC_MSG_ERROR([no supported semaphore type])]
)

AC_CHECK_HEADERS([sys/cdefs.h], [], [],
  [#ifdef HAVE_SYS_CDEFS_H
   #include <sys/cdefs.h>
   #endif])

DISPATCH_C_PRIVATE_EXTERN
DISPATCH_C_BLOCKS

#
# Temporary: some versions of clang do not mark __builtin_trap() as
# __attribute__((__noreturn__)).  Detect and add if required.
#
AC_COMPILE_IFELSE([
  AC_LANG_PROGRAM([void __attribute__((__noreturn__)) temp(void) { __builtin_trap(); }], [])], [
    AC_DEFINE(HAVE_NORETURN_BUILTIN_TRAP, 1,[Define if __builtin_trap marked noreturn])
  ], [])

#
# Generate Makefiles.
#
AC_CONFIG_FILES([Makefile dispatch/Makefile man/Makefile src/Makefile testing/Makefile])
AC_OUTPUT
