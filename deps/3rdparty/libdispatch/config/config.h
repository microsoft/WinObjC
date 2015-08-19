/* config/config.h.  Generated from config.h.in by configure.  */
/* config/config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to compile out legacy API */
/* #undef DISPATCH_NO_LEGACY */

/* Define to 1 if you have the declaration of `CLOCK_MONOTONIC', and to 0 if
   you don't. */
#define HAVE_DECL_CLOCK_MONOTONIC 0

/* Define to 1 if you have the declaration of `CLOCK_REALTIME', and to 0 if
   you don't. */
#define HAVE_DECL_CLOCK_REALTIME 0

/* Define to 1 if you have the declaration of `CLOCK_UPTIME', and to 0 if you
   don't. */
#define HAVE_DECL_CLOCK_UPTIME 0

/* Define to 1 if you have the declaration of `EVFILT_LIO', and to 0 if you
   don't. */
#define HAVE_DECL_EVFILT_LIO 0

/* Define to 1 if you have the declaration of `EVFILT_SESSION', and to 0 if
   you don't. */
#define HAVE_DECL_EVFILT_SESSION 1

/* Define to 1 if you have the declaration of `FD_COPY', and to 0 if you
   don't. */
#define HAVE_DECL_FD_COPY 1

/* Define to 1 if you have the declaration of `NOTE_NONE', and to 0 if you
   don't. */
#define HAVE_DECL_NOTE_NONE 1

/* Define to 1 if you have the declaration of `NOTE_REAP', and to 0 if you
   don't. */
#define HAVE_DECL_NOTE_REAP 1

/* Define to 1 if you have the declaration of `NOTE_REVOKE', and to 0 if you
   don't. */
#define HAVE_DECL_NOTE_REVOKE 1

/* Define to 1 if you have the declaration of `NOTE_SIGNAL', and to 0 if you
   don't. */
#define HAVE_DECL_NOTE_SIGNAL 1

/* Define to 1 if you have the declaration of `POSIX_SPAWN_START_SUSPENDED',
   and to 0 if you don't. */
#define HAVE_DECL_POSIX_SPAWN_START_SUSPENDED 1

/* Define to 1 if you have the declaration of `SIGEMT', and to 0 if you don't.
   */
#define HAVE_DECL_SIGEMT 1

/* Define to 1 if you have the declaration of `VQ_UPDATE', and to 0 if you
   don't. */
#define HAVE_DECL_VQ_UPDATE 1

/* Define to 1 if you have the declaration of `VQ_VERYLOWDISK', and to 0 if
   you don't. */
#define HAVE_DECL_VQ_VERYLOWDISK 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `getprogname' function. */
#define HAVE_GETPROGNAME 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define if Apple leaks program is present */
#define HAVE_LEAKS 0

/* Define to 1 if you have the <libkern/OSAtomic.h> header file. */
#define HAVE_LIBKERN_OSATOMIC_H 1

/* Define to 1 if you have the <libkern/OSCrossEndian.h> header file. */
#define HAVE_LIBKERN_OSCROSSENDIAN_H 1

/* Define if mach is present */
#define HAVE_MACH 0

/* Define to 1 if you have the `mach_absolute_time' function. */
#define HAVE_MACH_ABSOLUTE_TIME 1

/* Define to 1 if you have the `malloc_create_zone' function. */
#define HAVE_MALLOC_CREATE_ZONE 1

/* Define to 1 if you have the <malloc/malloc.h> header file. */
#define HAVE_MALLOC_MALLOC_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define if __builtin_trap marked noreturn */
#define HAVE_NORETURN_BUILTIN_TRAP 1

/* Define if __private_extern__ present */
#define HAVE_PRIVATE_EXTERN 1

/* Define to 1 if you have the `program_invocation_short_name' function. */
/* #undef HAVE_PROGRAM_INVOCATION_SHORT_NAME */

/* Define to 1 if you have the `pthread_key_init_np' function. */
#define HAVE_PTHREAD_KEY_INIT_NP 1

/* Define to 1 if you have the <pthread_machdep.h> header file. */
#define HAVE_PTHREAD_MACHDEP_H 1

/* Define to 1 if you have the `pthread_main_np' function. */
#define HAVE_PTHREAD_MAIN_NP 1

/* Define to 1 if you have the <pthread_np.h> header file. */
/* #undef HAVE_PTHREAD_NP_H */

/* Define if pthread work queues are present */
#define HAVE_PTHREAD_WORKQUEUES 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `sysconf' function. */
#define HAVE_SYSCONF 1

/* Define to 1 if you have the <sys/cdefs.h> header file. */
#define HAVE_SYS_CDEFS_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/sysctl.h> header file. */
#define HAVE_SYS_SYSCTL_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <TargetConditionals.h> header file. */
#define HAVE_TARGETCONDITIONALS_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "libdispatch"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "libdispatch@macosforge.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "libdispatch"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "libdispatch 1.0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "libdispatch"

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.0"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to use Mac OS X crashreporter info */
#define USE_APPLE_CRASHREPORTER_INFO 1

/* Define to use non-portablesemaphore optimizations for Mac OS X */
#define USE_APPLE_SEMAPHORE_OPTIMIZATIONS 1

/* Define to use non-portable pthread TSD optimizations for Mac OS X) */
#define USE_APPLE_TSD_OPTIMIZATIONS 1

/* Define to tag libdispatch_init as a constructor */
/* #undef USE_LIBDISPATCH_INIT_CONSTRUCTOR */

/* Define to use Mach semaphores */
#define USE_MACH_SEM 1

/* Define to use POSIX semaphores */
/* #undef USE_POSIX_SEM */

/* Version number of package */
#define VERSION "1.0"

/* Define to 1 if on AIX 3.
   System headers sometimes define this.
   We just want to avoid a redefinition error message.  */
#ifndef _ALL_SOURCE
/* # undef _ALL_SOURCE */
#endif

/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* Enable extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif

/* Define to a replacement for __private_extern */
/* #undef __private_extern__ */
