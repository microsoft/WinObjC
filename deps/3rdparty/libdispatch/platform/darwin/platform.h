#ifndef PLATFORM_UNIX_PLATFORM__H
#define PLATFORM_UNIX_PLATFORM__H

#include "config/config.h"

#include <Availability.h>
#include <TargetConditionals.h>

#if HAVE_LIBKERN_OSCROSSENDIAN_H
#include <libkern/OSCrossEndian.h>
#endif
#if HAVE_LIBKERN_OSATOMIC_H
#include <libkern/OSAtomic.h>
#endif
#if HAVE_MACH
#include <mach/boolean.h>
#include <mach/clock_types.h>
#include <mach/clock.h>
#include <mach/exception.h>
#include <mach/mach.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/mach_interface.h>
#include <mach/mach_time.h>
#include <mach/mach_traps.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/host_info.h>
#include <mach/notify.h>
#endif /* HAVE_MACH */
#if HAVE_MALLOC_MALLOC_H
#include <malloc/malloc.h>
#endif
#include <sys/mount.h>
#include <sys/queue.h>
#include <sys/stat.h>
#if HAVE_SYS_SYSCTL_H
#include <sys/sysctl.h>
#endif
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>

#ifdef __BLOCKS__
#include <Block_private.h>
#include <Block.h>
#endif /* __BLOCKS__ */

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <search.h>
#if USE_POSIX_SEM
#include <semaphore.h>
#endif
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif
#include <sys/event.h>

#include <pthread.h>
#if HAVE_PTHREAD_MACHDEP_H
#include <pthread_machdep.h>
#endif
#if HAVE_PTHREAD_WORKQUEUES
#include <pthread_workqueue.h>
#endif
#if HAVE_PTHREAD_NP_H
#include <pthread_np.h>
#endif

#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
/* iPhone OS does not make any legacy definitions visible */
#ifndef DISPATCH_NO_LEGACY
#define DISPATCH_NO_LEGACY
#endif
#endif

#endif
