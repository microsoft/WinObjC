#ifndef PLATFORM_WINDOWS_PLATFORM__H
#define PLATFORM_WINDOWS_PLATFORM__H

#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <SDKDDKVer.h>
#include <Windows.h>

#ifdef SLIST_ENTRY
#undef SLIST_ENTRY
#endif
#define NT_SLIST_ENTRY SINGLE_LIST_ENTRY

#if defined(_M_IX86)
#ifndef __i386__
 #define __i386__
#endif
#elif defined(_M_X64)
#define __x86_64__
#define __LLP64__
#elif defined(WINOBJC) && defined(_M_ARM)
#ifndef __arm__
 #define __arm__
#endif
#else
#error Unsupported architecture
#endif

#define DISPATCH_NO_LEGACY 1
#define DISPATCH_PERF_MON 1
#define HAVE_DECL_CLOCK_MONOTONIC 0
#define HAVE_DECL_CLOCK_REALTIME 0
#define HAVE_DECL_CLOCK_UPTIME 1
#define HAVE_DECL_EVFILT_LIO 0
#define HAVE_DECL_EVFILT_SESSION 0
#define HAVE_DECL_FD_COPY 0
#define HAVE_DECL_NOTE_NONE 0
#define HAVE_DECL_NOTE_REAP 0
#define HAVE_DECL_NOTE_REVOKE 0
#define HAVE_DECL_NOTE_SIGNAL 0
#define HAVE_DECL_POSIX_SPAWN_START_SUSPENDED 0
#define HAVE_DECL_SIGEMT 0
#define HAVE_DECL_VQ_UPDATE 0
#define HAVE_DECL_VQ_VERYLOWDISK 0
#define HAVE_DLFCN_H 0
#define HAVE_GETPROGNAME 0
#define HAVE_INTTYPES_H 1
#define HAVE_LEAKS 0
#define HAVE_LIBKERN_OSATOMIC_H 1
#define HAVE_LIBKERN_OSCROSSENDIAN_H 0
#define HAVE_MACH_ABSOLUTE_TIME 0
#define HAVE_MALLOC_CREATE_ZONE 0
#define HAVE_MALLOC_MALLOC_H 0
#define HAVE_NORETURN_BUILTIN_TRAP 0
#define HAVE_PRIVATE_EXTERN 0
#define HAVE_MEMORY_H 1
#define HAVE_PTHREAD_KEY_INIT_NP 0
#define HAVE_PTHREAD_MACHDEP_H 0
#define HAVE_PTHREAD_MAIN_NP 0
#define HAVE_PTHREAD_NP_H 0
#define HAVE_PTHREAD_WORKQUEUES 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRINGS_H 1
#define HAVE_STRING_H 1
#define HAVE_SYSCONF 0
#define HAVE_SYS_CDEFS_H 0
#define HAVE_SYS_STAT_H 0
#define HAVE_SYS_SYSCTL_H 0
#define HAVE_SYS_TYPES_H 0
#define HAVE_TARGETCONDITIONALS_H 0
#define HAVE_UNISTD_H 0
#define LT_OBJDIR ".libs/"
#define PACKAGE "libdispatch"
#define PACKAGE_BUGREPORT "libdispatch@macosforge.org"
#define PACKAGE_NAME "libdispatch"
#define PACKAGE_STRING "libdispatch 1.0"
#define PACKAGE_TARNAME "libdispatch"
#define PACKAGE_VERSION "1.0"
#define STDC_HEADERS 1
#define USE_APPLE_CRASHREPORTER_INFO 0
#define USE_APPLE_SEMAPHORE_OPTIMIZATIONS 0
#define USE_MACH_SEM 0
#define USE_POSIX_SEM 0
#define USE_WIN32_SEM 1
#define TARGET_OS_WIN32 1
#define VERSION "1.0"
#define __private_extern__

#ifdef __BLOCKS__
#include <objc/blocks_private.h>
#include <objc/blocks_runtime.h>
#endif /* __BLOCKS__ */

#ifdef _MSC_VER

#if defined DEBUG || defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_CLIENTBLOCK new(_CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#endif

#endif

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdarg.h>
#ifndef _MSC_VER
#include <stdbool.h>
#include <inttypes.h>
#elif defined( WINOBJC )
#include <stdbool.h>
#include <inttypes.h>
#else
#include "platform/windows/stdbool.h"
#include "platform/windows/inttypes.h"
#endif
#include <stdarg.h>
#include <stdint.h>

#include "semaphore.h"
#include "signal.h"
#include "unistd.h"
#include "strings.h"
#include "stdio.h"

#include "sys/mount.h"
#include "sys/queue.h"
#include "sys/time.h"
#include "sys/event.h"

#include "pthread.h"
#include "pthread_workqueue.h"

#include "libkern/OSAtomic.h"

#pragma warning(disable : 4098) // warning C4098: 'identifier': 'void' function returning a value
#pragma warning(disable : 4100) // warning C4100: 'identifier': unreferenced formal parameter
#pragma warning(disable : 4127) // warning C4127: conditional expression is constant
#pragma warning(disable : 4152) // warning C4152: nonstandard extension, function/data pointer conversion in expression
#pragma warning(disable : 4201) // warning C4201: nonstandard extension used : nameless struct/union
#pragma warning(disable : 4204) // warning C4204: nonstandard extension used : non-constant aggregate initializer
#pragma warning(disable : 4221) // warning C4221: nonstandard extension used : 'identifier': cannot be initialized using address of automatic variable 'identifier'
#pragma warning(disable : 4706) // warning C4706: assignment within conditional expression

#define __builtin_return_address(X) _ReturnAddress()

#define snprintf _snprintf

#endif
