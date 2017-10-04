#ifndef __DISPATCH_INTEROP__
#define __DISPATCH_INTEROP__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#include <dispatch/base.h> // for HeaderDoc
#endif

__DISPATCH_BEGIN_DECLS

/*!
 * @function dispatch_get_main_queue
 *
 * @abstract
 * Returns the default queue that is bound to the main thread.
 *
 * @discussion
 * In order to invoke blocks submitted to the main queue, the application must
 * call dispatch_main(), NSApplicationMain(), or use a CFRunLoop on the main
 * thread.
 *
 * @result
 * Returns the main queue. This queue is created automatically on behalf of
 * the main thread before main() is called.
 */
 __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_NA)
DISPATCH_EXPORT DISPATCH_PURE DISPATCH_WARN_RESULT DISPATCH_NOTHROW
dispatch_queue_t dispatch_get_main_queue(void);

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT struct dispatch_queue_s _dispatch_main_q;

#if !defined(_MSC_VER) // for reasons I don't understand, exporting this object doesn't work as well as it should.
#define dispatch_get_main_queue() (&_dispatch_main_q)
#endif

/*!
 * @function dispatch_thread_queue_callback
 * 
 * @abstract
 * External code calls dispatch_thread_queue_callback() to drain blocks queued to per-thread queues.
 *
 */
DISPATCH_EXPORT DISPATCH_NOTHROW
void
dispatch_thread_queue_callback(void);

/*!
 * @function dispatch_main_queue_callback
 * 
 * @abstract
 * External code calls dispatch_main_queue_callback() to drain blocks queued to the main queue.
 *
 */
DISPATCH_EXPORT DISPATCH_NOTHROW
void
dispatch_main_queue_callback(void);

#if defined( WINOBJC )
DISPATCH_EXPORT DISPATCH_NOTHROW
struct timespec *dispatch_get_next_timer_fire(struct timespec *howsoon);

typedef void (*dispatch_wake_main_thread_callback)(void *userptr);
    
DISPATCH_EXPORT DISPATCH_NOTHROW
void dispatch_set_wakeup_callback(dispatch_wake_main_thread_callback callback, void *userptr);
#endif

#if defined( WIN32 ) || defined( WINOBJC )

typedef unsigned int UINT;

DISPATCH_EXPORT DISPATCH_NOTHROW
UINT dispatch_get_thread_window_message(void);

DISPATCH_EXPORT DISPATCH_NOTHROW
UINT dispatch_get_main_window_message(void);

DISPATCH_EXPORT
void *(*_dispatch_begin_NSAutoReleasePool)(void);

DISPATCH_EXPORT
void(*_dispatch_end_NSAutoReleasePool)(void *);

#else
#if HAVE_MACH
#define DISPATCH_COCOA_COMPAT 1
#if DISPATCH_COCOA_COMPAT

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NOTHROW
mach_port_t
_dispatch_get_main_queue_port_4CF(void);

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NOTHROW
void
_dispatch_main_queue_callback_4CF(mach_msg_header_t *msg);

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
void (*dispatch_begin_thread_4GC)(void);

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
void (*dispatch_end_thread_4GC)(void);

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
void *(*_dispatch_begin_NSAutoReleasePool)(void);

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT
void (*_dispatch_end_NSAutoReleasePool)(void *);

#endif
#endif /* HAVE_MACH */
#endif /* WIN32 */

__DISPATCH_END_DECLS

#endif
