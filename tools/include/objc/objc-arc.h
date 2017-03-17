#if defined(__clang__) && !defined(__OBJC_RUNTIME_INTERNAL__)
#pragma clang system_header
#endif

#ifndef __OBJC_ARC_INCLUDED__
#define __OBJC_ARC_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Autoreleases the argument.  Equivalent to [obj autorelease].
 */
id objc_autorelease(id obj);
/**
 * Autoreleases a return value.  This is equivalent to [obj autorelease], but
 * may also store the object somewhere where it can be quickly removed without
 * the need for any message sending.
 */
id objc_autoreleaseReturnValue(id obj);
/**
 * Initializes object as a weak pointer and stores value in it, or nil if value
 * has already begun deallocation.
 */
id objc_initWeak(id *object, id value);
/**
 * Loads the object.  Returns nil if the object stored at this address has
 * already begun deallocation.
 */
id objc_loadWeak(id* object);
/**
 * Loads a weak value and retains it.
 */
id objc_loadWeakRetained(id* obj);
/**
 * Retains the argument.  Equivalent to [obj retain].
 */
id objc_retain(id obj);
/**
 * Retains and autoreleases an object.  Equivalent to [[obj retain] autorelease].
 */
id objc_retainAutorelease(id obj);
/**
 * Retains and releases a return value.  Equivalent to
 * objc_retain(objc_autoreleaseReturnValue(obj)).
 */
id objc_retainAutoreleaseReturnValue(id obj);
/**
 * Retains a return value that has previously been autoreleased and returned.
 * This is equivalent to objc_retainAutoreleaseReturnValue(), but may support a
 * fast path, skipping the autorelease pool entirely.
 */
id objc_retainAutoreleasedReturnValue(id obj);
/**
 * Retains a block.
 */
id objc_retainBlock(id b);
/**
 * Stores value in addr.  This first retains value, then releases the old value
 * at addr, and stores the retained value in the address.
 */
id objc_storeStrong(id *addr, id value);
/**
 * Stores obj in zeroing weak pointer addr.  If obj has begun deallocation,
 * then this stores nil.
 */
id objc_storeWeak(id *addr, id obj);
/**
 * Allocates an autorelease pool and pushes it onto the top of the autorelease
 * pool stack.  Note that the returned autorelease pool is not required to be
 * an object.
 */
void *objc_autoreleasePoolPush(void);
/**
 * Pops the specified autorelease pool from the stack, sending release messages
 * to every object that has been autreleased since the pool was created.
 */
void objc_autoreleasePoolPop(void *pool);
/**
 * Initializes dest as a weak pointer and stores the value stored in src into
 * it.  
 */
void objc_copyWeak(id *dest, id *src);
/**
 * Destroys addr as a weak pointer.
 */
void objc_destroyWeak(id* addr);
/**
 * Equivalent to objc_copyWeak(), but may also set src to nil.
 */
void objc_moveWeak(id *dest, id *src);
/**
 * Releases an object.  Equivalent to [obj release].
 */
void objc_release(id obj);
/**
 * Mark the object as about to begin deallocation.  All subsequent reads of
 * weak pointers will return 0.  This function should be called in -release,
 * before calling [self dealloc].
 *
 * Nonstandard extension.
 */
void objc_delete_weak_refs(id obj);
/**
 * Returns the total number of objects in the ARC-managed autorelease pool.
 */
unsigned long objc_arc_autorelease_count_np(void);
/**
 * Returns the total number of times that an object has been autoreleased in
 * this thread.
 */
unsigned long objc_arc_autorelease_count_for_object_np(id);

#ifdef __cplusplus
}
#endif

#endif // __OBJC_ARC_INCLUDED__

