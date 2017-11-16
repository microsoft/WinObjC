/*
 * Copyright (c) 2008-2009 Apple Inc. All rights reserved.
 *
 * @APPLE_APACHE_LICENSE_HEADER_START@
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * @APPLE_APACHE_LICENSE_HEADER_END@
 */

#ifndef __DISPATCH_QUEUE__
#define __DISPATCH_QUEUE__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#include <dispatch/base.h> // for HeaderDoc
#endif

/*!
 * @header
 *
 * Dispatch is an abstract model for expressing concurrency via simple but
 * powerful API. 
 *
 * At the core, dispatch provides serial FIFO queues to which blocks may be
 * submitted. Blocks submitted to these dispatch queues are invoked on a pool
 * of threads fully managed by the system. No guarantee is made regarding
 * which thread a block will be invoked on; however, it is guaranteed that only
 * one block submitted to the FIFO dispatch queue will be invoked at a time.
 *
 * When multiple queues have blocks to be processed, the system is free to
 * allocate additional threads to invoke the blocks concurrently. When the
 * queues become empty, these threads are automatically released.
 */

/*!
 * @typedef dispatch_queue_t
 *
 * @abstract
 * Dispatch queues invoke blocks submitted to them serially in FIFO order. A
 * queue will only invoke one block at a time, but independent queues may each
 * invoke their blocks concurrently with respect to each other.
 *
 * @discussion
 * Dispatch queues are lightweight objects to which blocks may be submitted.
 * The system manages a pool of threads which process dispatch queues and
 * invoke blocks submitted to them.
 *
 * Conceptually a dispatch queue may have its own thread of execution, and
 * interaction between queues is highly asynchronous.
 *
 * Dispatch queues are reference counted via calls to dispatch_retain() and
 * dispatch_release(). Pending blocks submitted to a queue also hold a
 * reference to the queue until they have finished. Once all references to a
 * queue have been released, the queue will be deallocated by the system.
 */
DISPATCH_DECL(dispatch_queue);

/*!
 * @typedef dispatch_queue_attr_t
 *
 * @abstract
 * Attribute and policy extensions for dispatch queues.
 */
DISPATCH_DECL(dispatch_queue_attr);

/*!
 * @typedef dispatch_block_t
 *
 * @abstract
 * The prototype of blocks submitted to dispatch queues, which take no
 * arguments and have no return value.
 *
 * @discussion
 * The declaration of a block allocates storage on the stack. Therefore, this
 * is an invalid construct:
 *
 * dispatch_block_t block;
 *
 * if (x) {
 *     block = ^{ printf("true\n"); };
 * } else {
 *     block = ^{ printf("false\n"); };
 * }
 * block(); // unsafe!!!
 *
 * What is happening behind the scenes:
 *
 * if (x) {
 *     struct Block __tmp_1 = ...; // setup details
 *     block = &__tmp_1;
 * } else {
 *     struct Block __tmp_2 = ...; // setup details
 *     block = &__tmp_2;
 * }
 *
 * As the example demonstrates, the address of a stack variable is escaping the
 * scope in which it is allocated. That is a classic C bug.
 */
#ifdef __BLOCKS__
typedef void (^dispatch_block_t)(void);
#endif

__DISPATCH_BEGIN_DECLS

/*!
 * @function dispatch_async
 *
 * @abstract
 * Submits a block for asynchronous execution on a dispatch queue.
 *
 * @discussion
 * The dispatch_async() function is the fundamental mechanism for submitting
 * blocks to a dispatch queue.
 *
 * Calls to dispatch_async() always return immediately after the block has
 * been submitted, and never wait for the block to be invoked.
 *
 * The target queue determines whether the block will be invoked serially or
 * concurrently with respect to other blocks submitted to that same queue.
 * Serial queues are processed concurrently with with respect to each other.
 * 
 * @param queue
 * The target dispatch queue to which the block is submitted.
 * The system will hold a reference on the target queue until the block
 * has finished.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param block
 * The block to submit to the target dispatch queue. This function performs
 * Block_copy() and Block_release() on behalf of callers.
 * The result of passing NULL in this parameter is undefined.
 */
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_async(dispatch_queue_t queue, dispatch_block_t block);
#endif

/*!
 * @function dispatch_async_f
 *
 * @abstract
 * Submits a function for asynchronous execution on a dispatch queue.
 *
 * @discussion
 * See dispatch_async() for details.
 * 
 * @param queue
 * The target dispatch queue to which the function is submitted.
 * The system will hold a reference on the target queue until the function
 * has returned.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param context
 * The application-defined context parameter to pass to the function.
 *
 * @param work
 * The application-defined function to invoke on the target queue. The first
 * parameter passed to this function is the context provided to
 * dispatch_async_f().
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NONNULL3 DISPATCH_NOTHROW
void
dispatch_async_f(dispatch_queue_t queue,
	void *context,
	dispatch_function_t work);

/*!
 * @function dispatch_barrier_async
 *
 * @abstract
 * Submits a barrier block for asynchronous execution on a dispatch queue.
 *
 * @discussion
 * Submits a block to a dispatch queue like dispatch_async(), but marks that
 * block as a barrier (relevant only on DISPATCH_QUEUE_CONCURRENT queues).
 *
 * See dispatch_async() for details.
 *
 * @param queue
 * The target dispatch queue to which the block is submitted.
 * The system will hold a reference on the target queue until the block
 * has finished.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param block
 * The block to submit to the target dispatch queue. This function performs
 * Block_copy() and Block_release() on behalf of callers.
 * The result of passing NULL in this parameter is undefined.
 */

#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_barrier_async(dispatch_queue_t queue, dispatch_block_t block);
#endif

/*!
 * @function dispatch_barrier_async_f
 *
 * @abstract
 * Submits a barrier function for asynchronous execution on a dispatch queue.
 *
 * @discussion
 * Submits a function to a dispatch queue like dispatch_async_f(), but marks
 * that function as a barrier (relevant only on DISPATCH_QUEUE_CONCURRENT
 * queues).
 *
 * See dispatch_async_f() for details.
 *
 * @param queue
 * The target dispatch queue to which the function is submitted.
 * The system will hold a reference on the target queue until the function
 * has returned.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param context
 * The application-defined context parameter to pass to the function.
 *
 * @param work
 * The application-defined function to invoke on the target queue. The first
 * parameter passed to this function is the context provided to
 * dispatch_barrier_async_f().
 * The result of passing NULL in this parameter is undefined.
 */

__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NONNULL3 DISPATCH_NOTHROW
void
dispatch_barrier_async_f(dispatch_queue_t queue,
	void *_Nullable context,
	dispatch_function_t work);

/*!
 * @function dispatch_barrier_sync_f
 *
 * @abstract
 * Submits a barrier function for synchronous execution on a dispatch queue.
 *
 * @discussion
 * Submits a function to a dispatch queue like dispatch_sync_f(), but marks that
 * fuction as a barrier (relevant only on DISPATCH_QUEUE_CONCURRENT queues).
 *
 * See dispatch_sync_f() for details.
 *
 * @param queue
 * The target dispatch queue to which the function is submitted.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param context
 * The application-defined context parameter to pass to the function.
 *
 * @param work
 * The application-defined function to invoke on the target queue. The first
 * parameter passed to this function is the context provided to
 * dispatch_barrier_sync_f().
 * The result of passing NULL in this parameter is undefined.
 */

__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NONNULL3 DISPATCH_NOTHROW
void
dispatch_barrier_sync_f(dispatch_queue_t queue,
	void *_Nullable context,
	dispatch_function_t work);

/*!
 * @function dispatch_barrier_sync
 *
 * @abstract
 * Submits a barrier block for synchronous execution on a dispatch queue.
 *
 * @discussion
 * Submits a block to a dispatch queue like dispatch_sync(), but marks that
 * block as a barrier (relevant only on DISPATCH_QUEUE_CONCURRENT queues).
 *
 * See dispatch_sync() for details.
 *
 * @param queue
 * The target dispatch queue to which the block is submitted.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param block
 * The block to be invoked on the target dispatch queue.
 * The result of passing NULL in this parameter is undefined.
 */
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_barrier_sync(dispatch_queue_t queue, dispatch_block_t block);
#endif

/*!
 * @function dispatch_sync
 *
 * @abstract
 * Submits a block for synchronous execution on a dispatch queue.
 *
 * @discussion
 * Submits a block to a dispatch queue like dispatch_async(), however
 * dispatch_sync() will not return until the block has finished.
 *
 * Calls to dispatch_sync() targeting the current queue will result
 * in dead-lock. Use of dispatch_sync() is also subject to the same
 * multi-party dead-lock problems that may result from the use of a mutex.
 * Use of dispatch_async() is preferred.
 *
 * Unlike dispatch_async(), no retain is performed on the target queue. Because
 * calls to this function are synchronous, the dispatch_sync() "borrows" the
 * reference of the caller.
 *
 * As an optimization, dispatch_sync() invokes the block on the current
 * thread when possible.
 *
 * @param queue
 * The target dispatch queue to which the block is submitted.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param block
 * The block to be invoked on the target dispatch queue.
 * The result of passing NULL in this parameter is undefined.
 */
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_sync(dispatch_queue_t queue, dispatch_block_t block);
#endif

/*!
 * @function dispatch_sync_f
 *
 * @abstract
 * Submits a function for synchronous execution on a dispatch queue.
 *
 * @discussion
 * See dispatch_sync() for details.
 *
 * @param queue
 * The target dispatch queue to which the function is submitted.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param context
 * The application-defined context parameter to pass to the function.
 *
 * @param work
 * The application-defined function to invoke on the target queue. The first
 * parameter passed to this function is the context provided to
 * dispatch_sync_f().
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NONNULL3 DISPATCH_NOTHROW
void
dispatch_sync_f(dispatch_queue_t queue,
	void *context,
	dispatch_function_t work);

/*!
 * @function dispatch_apply
 *
 * @abstract
 * Submits a block to a dispatch queue for multiple invocations.
 *
 * @discussion
 * Submits a block to a dispatch queue for multiple invocations. This function
 * waits for the task block to complete before returning. If the target queue
 * is a concurrent queue returned by dispatch_get_concurrent_queue(), the block
 * may be invoked concurrently, and it must therefore be reentrant safe.
 * 
 * Each invocation of the block will be passed the current index of iteration.
 *
 * @param iterations
 * The number of iterations to perform.
 *
 * @param queue
 * The target dispatch queue to which the block is submitted.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param block
 * The block to be invoked the specified number of iterations.
 * The result of passing NULL in this parameter is undefined.
 */
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_apply(size_t iterations, dispatch_queue_t queue, void (^block)(size_t));
#endif

/*!
 * @function dispatch_apply_f
 *
 * @abstract
 * Submits a function to a dispatch queue for multiple invocations.
 *
 * @discussion
 * See dispatch_apply() for details.
 *
 * @param iterations
 * The number of iterations to perform.
 *
 * @param queue
 * The target dispatch queue to which the function is submitted.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param context
 * The application-defined context parameter to pass to the function.
 *
 * @param work
 * The application-defined function to invoke on the target queue. The first
 * parameter passed to this function is the context provided to
 * dispatch_apply_f(). The second parameter passed to this function is the
 * current index of iteration.
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL2 DISPATCH_NONNULL4 DISPATCH_NOTHROW
void
dispatch_apply_f(size_t iterations, dispatch_queue_t queue,
	void *context,
	void (*work)(void *, size_t));

/*!
 * @function dispatch_get_current_queue
 *
 * @abstract
 * Returns the queue on which the currently executing block is running.
 * 
 * @discussion
 * Returns the queue on which the currently executing block is running.
 *
 * When dispatch_get_current_queue() is called outside of the context of a
 * submitted block, it will return the default concurrent queue.
 *
 * @result
 * Returns the current queue.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_PURE DISPATCH_WARN_RESULT DISPATCH_NOTHROW
dispatch_queue_t
dispatch_get_current_queue(void);

/*!
 * @enum dispatch_queue_priority_t
 *
 * @constant DISPATCH_QUEUE_PRIORITY_HIGH
 * Items dispatched to the queue will run at high priority,
 * i.e. the queue will be scheduled for execution before
 * any default priority or low priority queue.
 *
 * @constant DISPATCH_QUEUE_PRIORITY_DEFAULT
 * Items dispatched to the queue will run at the default
 * priority, i.e. the queue will be scheduled for execution
 * after all high priority queues have been scheduled, but
 * before any low priority queues have been scheduled.
 *
 * @constant DISPATCH_QUEUE_PRIORITY_LOW
 * Items dispatched to the queue will run at low priority,
 * i.e. the queue will be scheduled for execution after all
 * default priority and high priority queues have been
 * scheduled.
 */
enum {
	DISPATCH_QUEUE_PRIORITY_HIGH = 2,
	DISPATCH_QUEUE_PRIORITY_DEFAULT = 0,
	DISPATCH_QUEUE_PRIORITY_LOW = -2,
};

static const uint32_t DISPATCH_QUEUE_PRIORITY_BACKGROUND 
    __attribute__((deprecated("DISPATCH_QUEUE_PRIORITY_BACKGROUND has a value of DISPATCH_QUEUE_PRIORITY_LOW instead of INT16_MIN on WinObjC"))) 
        = DISPATCH_QUEUE_PRIORITY_LOW;

/*!
 * @enum Quality of service classes
 *
 * @constant QOS_CLASS_USER_INTERACTIVE
 * Items dispatched to the queue will run at high priority.
 *
 * @constant QOS_CLASS_USER_INITIATED
 * Items dispatched to the queue will run at high priority.
 *
 * @constant QOS_CLASS_DEFAULT
 * Items dispatched to the queue will run at at the default
 * priority, after user-initiated and user-interactive tasks,
 * but before utility or background tasks.
 *
 * @constant QOS_CLASS_UTILITY
 * Items dispatched to the queue will run at low priority.
 */
enum {
	QOS_CLASS_USER_INTERACTIVE = DISPATCH_QUEUE_PRIORITY_HIGH,
	QOS_CLASS_USER_INITIATED = DISPATCH_QUEUE_PRIORITY_HIGH,
	QOS_CLASS_DEFAULT = DISPATCH_QUEUE_PRIORITY_DEFAULT,

	// WINOBJC: QOS_CLASS_UTILITY is identical to DISPATCH_QUEUE_PRIORITY_LOW
	QOS_CLASS_UTILITY = DISPATCH_QUEUE_PRIORITY_LOW,

	MIN_QOS_CLASS_PRIORITY = QOS_CLASS_UTILITY,
};

static const int32_t QOS_CLASS_BACKGROUND
    __attribute__((deprecated("QOS_CLASS_BACKGROUND is the same as DISPATCH_QUEUE_PRIORITY_LOW on WinObjC")))
        = DISPATCH_QUEUE_PRIORITY_LOW;
        
#define DISPATCH_QUEUE_SERIAL NULL

/*!
 * @function dispatch_get_global_queue
 *
 * @abstract
 * Returns a well-known global concurrent queue of a given priority level.
 *
 * @discussion
 * The well-known global concurrent queues may not be modified. Calls to
 * dispatch_suspend(), dispatch_resume(), dispatch_set_context(), etc., will
 * have no effect when used with queues returned by this function.
 *
 * @param priority
 * A priority defined in dispatch_queue_priority_t
 *
 * @param flags
 * Reserved for future use. Passing any value other than zero may result in
 * a NULL return value.
 *
 * @result
 * Returns the requested global queue.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_PURE DISPATCH_WARN_RESULT DISPATCH_NOTHROW
dispatch_queue_t
dispatch_get_global_queue(long priority, unsigned long flags);

/*!
 * @function dispatch_queue_create
 *
 * @abstract
 * Creates a new dispatch queue to which blocks may be submitted.
 *
 * @discussion
 * Dispatch queues invoke blocks serially in FIFO order.
 *
 * When the dispatch queue is no longer needed, it should be released
 * with dispatch_release(). Note that any pending blocks submitted
 * to a queue will hold a reference to that queue. Therefore a queue
 * will not be deallocated until all pending blocks have finished.
 *
 * @param label
 * A string label to attach to the queue.
 * This parameter is optional and may be NULL.
 *
 * @param attr
 * Unused. Pass NULL for now.
 *
 * @result
 * The newly created dispatch queue.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_MALLOC DISPATCH_WARN_RESULT DISPATCH_NOTHROW
dispatch_queue_t
dispatch_queue_create(const char *label, dispatch_queue_attr_t attr);

/*!
 * @function dispatch_queue_get_label
 *
 * @abstract
 * Returns the label of the queue that was specified when the
 * queue was created.
 *
 * @param queue
 * The result of passing NULL in this parameter is undefined.
 *
 * @result
 * The label of the queue. The result may be NULL.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_PURE DISPATCH_WARN_RESULT DISPATCH_NOTHROW
const char *
dispatch_queue_get_label(dispatch_queue_t queue);

/*!
 * @function dispatch_set_target_queue
 *
 * @abstract
 * Sets the target queue for the given object.
 *
 * @discussion
 * An object's target queue is responsible for processing the object.
 *
 * A dispatch queue's priority is inherited by its target queue. Use the
 * dispatch_get_global_queue() function to obtain suitable target queue
 * of the desired priority.
 *
 * A dispatch source's target queue specifies where its event handler and
 * cancellation handler blocks will be submitted.
 *
 * The result of calling dispatch_set_target_queue() on any other type of
 * dispatch object is undefined.
 *
 * @param       object
 * The object to modify.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param       queue
 * The new target queue for the object. The queue is retained, and the
 * previous one, if any, is released.
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_set_target_queue(dispatch_object_t object, dispatch_queue_t queue);

/*!
 * @function dispatch_main
 *
 * @abstract
 * Execute blocks submitted to the main queue.
 *
 * @discussion
 * This function "parks" the main thread and waits for blocks to be submitted
 * to the main queue. This function never returns.
 *
 * Applications that call NSApplicationMain() or CFRunLoopRun() on the
 * main thread do not need to call dispatch_main().
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NOTHROW DISPATCH_NORETURN
void
dispatch_main(void);

/*!
 * @function dispatch_after
 *
 * @abstract
 * Schedule a block for execution on a given queue at a specified time.
 *
 * @discussion
 * Passing DISPATCH_TIME_NOW as the "when" parameter is supported, but not as
 * optimal as calling dispatch_async() instead. Passing DISPATCH_TIME_FOREVER
 * is undefined.
 *
 * @param when
 * A temporal milestone returned by dispatch_time() or dispatch_walltime().
 *
 * @param queue
 * A queue to which the given block will be submitted at the specified time.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param block
 * The block of code to execute.
 * The result of passing NULL in this parameter is undefined.
 */
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL2 DISPATCH_NONNULL3 DISPATCH_NOTHROW
void
dispatch_after(dispatch_time_t when,
	dispatch_queue_t queue,
	dispatch_block_t block);
#endif

/*!
 * @function dispatch_after_f
 *
 * @abstract
 * Schedule a function for execution on a given queue at a specified time.
 *
 * @discussion
 * See dispatch_after() for details.
 *
 * @param when
 * A temporal milestone returned by dispatch_time() or dispatch_walltime().
 *
 * @param queue
 * A queue to which the given function will be submitted at the specified time.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param context
 * The application-defined context parameter to pass to the function.
 *
 * @param work
 * The application-defined function to invoke on the target queue. The first
 * parameter passed to this function is the context provided to
 * dispatch_after_f().
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL2 DISPATCH_NONNULL4 DISPATCH_NOTHROW
void
dispatch_after_f(dispatch_time_t when,
	dispatch_queue_t queue,
	void *context,
	dispatch_function_t work);

/*!
 * @function dispatch_get_thread_queue
 *
 * @abstract Get the per-thread queue belonging to the current thread.
 *
 */
DISPATCH_EXPORT DISPATCH_PURE DISPATCH_WARN_RESULT DISPATCH_NOTHROW
dispatch_queue_t
dispatch_get_current_thread_queue();

/*!
* @function dispatch_queue_set_specific
*
* @abstract
* Sets the key/value data for the specified dispatch queue.
*
* @discussion
* Use this method to associate custom context data with a dispatch queue. 
* Blocks executing on the queue can use the dispatch_get_specific function
* to retrieve this data while they are running.
*
* @param queue
* The queue on which to set the specified key/value data. This parameter must not be NULL.
*
* @param key
* The key you want to use to identify the associated context data. Keys are only compared
* as pointers and are never dereferenced. Thus, you can use a pointer to a static variable
* for a specific subsystem or any other value that allows you to identify the value uniquely.
* Specifying a pointer to a string constant is not recommended. NULL is not a valid value
* for the key and attempts to set context data with a NULL key are ignored.
*
* @param context
* The context data to associate with key. This parameter may be NULL.
*
* @param destructor
* A destructor function that you can use to release your context data. This parameter may be
* NULL. If context is NULL, your destructor function is ignored.
*/

__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NOTHROW
void dispatch_queue_set_specific(dispatch_queue_t queue, const void *key, void *context, dispatch_function_t destructor);

/*!
* @function dispatch_queue_get_specific
*
* @abstract
* Gets the value for the key associated with the specified dispatch queue.
*
* @discussion
* You can use this method to get the context data associated with a specific dispatch queue.
* Blocks executing on a queue can use the dispatch_get_specific function to retrieve the
* context associated with that specific queue instead.
*
* @param queue
* The queue containing the desired context data. This parameter must not be NULL.
*
* @param key
* The key that identifies the associated context data. Keys are only compared as
* pointers and are never dereferenced. Thus, you can use a pointer to a static variable
* for a specific subsystem or any other value that allows you to identify the value uniquely.
* Specifying a pointer to a string constant is not recommended.
*
* @result
* The context data associated with key or NULL if no context was found.
*/
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_PURE DISPATCH_WARN_RESULT
DISPATCH_NOTHROW
void * dispatch_queue_get_specific(dispatch_queue_t queue, const void *key);

/*!
* @function dispatch_get_specific
*
* @abstract
* Returns the value for the key associated with the current dispatch queue.
*
* @discussion
* This function is intended to be called from a block executing in a dispatch queue.
* You use it to obtain context data associated with the queue. Calling this method
* from code not running in a dispatch queue returns NULL because there is no queue
* to provide context.
*
* @param key
* The key associated with the dispatch queue on which the current block is executing.
* Keys are only compared as pointers and never dereferenced. Passing a string constant
* directly is not recommended.
*
* @result
* The context value for the specified key; otherwise NULL if the key was not set for
* the queue (or its target queue) or the queue is a global concurrent queue.
*/
__OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_5_0)
DISPATCH_EXPORT DISPATCH_PURE DISPATCH_WARN_RESULT DISPATCH_NOTHROW
void * dispatch_get_specific(const void *key);

__DISPATCH_END_DECLS

#endif