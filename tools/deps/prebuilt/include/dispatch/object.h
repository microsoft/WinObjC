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

#ifndef __DISPATCH_OBJECT__
#define __DISPATCH_OBJECT__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#include <dispatch/base.h> // for HeaderDoc
#endif

__DISPATCH_BEGIN_DECLS

/*!
 * @function dispatch_debug
 *
 * @abstract
 * Programmatically log debug information about a dispatch object.
 *
 * @param object
 * The object to introspect.
 *
 * @param message
 * The message to log above and beyond the introspection.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL2 DISPATCH_NOTHROW DISPATCH_FORMAT(printf,2,3)
void
dispatch_debug(dispatch_object_t object, const char *message, ...);

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL2 DISPATCH_NOTHROW DISPATCH_FORMAT(printf,2,0)
void
dispatch_debugv(dispatch_object_t object, const char *message, va_list ap);

/*!
 * @function dispatch_retain
 *
 * @abstract
 * Increment the reference count of a dispatch object.
 *
 * @discussion
 * Calls to dispatch_retain() must be balanced with calls to
 * dispatch_release().
 *
 * @param object
 * The object to retain.
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_retain(dispatch_object_t object);

/*!
 * @function dispatch_release
 *
 * @abstract
 * Decrement the reference count of a dispatch object.
 *
 * @discussion
 * A dispatch object is asynchronously deallocated once all references are
 * released (i.e. the reference count becomes zero). The system does not
 * guarantee that a given client is the last or only reference to a given
 * object.
 *
 * @param object
 * The object to release.
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_release(dispatch_object_t object);

/*!
 * @function dispatch_get_context
 *
 * @abstract
 * Returns the application defined context of the object.
 *
 * @param object
 * The result of passing NULL in this parameter is undefined.
 *
 * @result
 * The context of the object; may be NULL.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_PURE DISPATCH_WARN_RESULT DISPATCH_NOTHROW
void *
dispatch_get_context(dispatch_object_t object);

/*!
 * @function dispatch_set_context
 *
 * @abstract
 * Associates an application defined context with the object.
 *
 * @param object
 * The result of passing NULL in this parameter is undefined.
 *
 * @param context
 * The new client defined context for the object. This may be NULL.
 *
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NOTHROW //DISPATCH_NONNULL1
void
dispatch_set_context(dispatch_object_t object, void *context);

/*!
 * @function dispatch_set_finalizer_f
 *
 * @abstract
 * Set the finalizer function for a dispatch object.
 *
 * @param
 * The dispatch object to modify.
 * The result of passing NULL in this parameter is undefined.
 *
 * @param
 * The finalizer function pointer.
 *
 * @discussion
 * A dispatch object's finalizer will be invoked on the object's target queue
 * after all references to the object have been released. This finalizer may be
 * used by the application to release any resources associated with the object,
 * such as freeing the object's context.
 * The context parameter passed to the finalizer function is the current
 * context of the dispatch object at the time the finalizer call is made.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NOTHROW //DISPATCH_NONNULL1
void
dispatch_set_finalizer_f(dispatch_object_t object,
	dispatch_function_t finalizer);

/*!
 * @function dispatch_suspend
 *
 * @abstract
 * Suspends the invocation of blocks on a dispatch object.
 *
 * @discussion
 * A suspended object will not invoke any blocks associated with it. The
 * suspension of an object will occur after any running block associated with
 * the object completes.
 *
 * Calls to dispatch_suspend() must be balanced with calls
 * to dispatch_resume().
 *
 * @param	object
 * The object to be suspended.
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_suspend(dispatch_object_t object);

/*!
 * @function dispatch_resume
 *
 * @abstract
 * Resumes the invocation of blocks on a dispatch object.
 *
 * @param	object
 * The object to be resumed.
 * The result of passing NULL in this parameter is undefined.
 */
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_resume(dispatch_object_t object);

__DISPATCH_END_DECLS

#endif
