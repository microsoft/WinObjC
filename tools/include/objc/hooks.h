#if defined(__clang__) && !defined(__OBJC_RUNTIME_INTERNAL__)
#pragma clang system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This file includes all of the hooks that can be used to alter the behaviour
 * of the runtime.  
 */


#ifndef OBJC_HOOK
#define OBJC_HOOK extern
#endif
struct objc_category;
/**
 * Class lookup hook.  Set this to provide a mechanism for resolving classes
 * that have not been registered with the runtime.  This can be used for lazy
 * library loading, for example.  The hook takes a class name as an argument
 * and returns the class.  A JIT compiler could use this to allow classes to be
 * compiled the first time that they are looked up.  If the class is already
 * registered with the runtime, this will not be called, so it can not be used
 * for lazy loading of categories.
 */
OBJC_HOOK Class (*_objc_lookup_class)(const char *name);
/**
 * Class load callback.  
 */
OBJC_HOOK void (*_objc_load_callback)(Class cls, struct objc_category *category);
/**
 * The hook used for fast proxy lookups.  This takes an object and a selector
 * and returns the instance that the message should be forwarded to.
 */
OBJC_HOOK id (*objc_proxy_lookup)(id receiver, SEL op);
/**
 * New runtime forwarding hook.  This might be removed in future - it's
 * actually no more expressive than the forward2 hook and forces Foundation to
 * do some stuff that the runtime is better suited to.
 */
OBJC_HOOK struct objc_slot *(*__objc_msg_forward3)(id, SEL);
/**
 * Forwarding hook.  Takes an object and a selector and returns a method that
 * handles the forwarding.
 */
OBJC_HOOK IMP (*__objc_msg_forward2)(id, SEL);
/**
 * Hook defined for handling unhandled exceptions.  If the unwind library
 * reaches the end of the stack without finding a handler then this hook is
 * called.
 */
OBJC_HOOK void (*_objc_unexpected_exception)(id exception);
/**
 * Hook defined to return the class to be used for boxing a foreign exception
 * type.  The class must implement:
 *
 * + (id)exceptionWithForeignException: (_Unwind_Exception*)ex;
 *
 * This will return an instance of the class that encapsulates the exception.
 *
 * Note: Due to limitations of the current ABI, there is no way for the handler
 * to 
 */
OBJC_HOOK Class (*_objc_class_for_boxing_foreign_exception)(int64_t exceptionClass);

/**
 * Hook called when selector type does not match the method type in the
 * receiver.  This should return the slot to use instead, although it may throw
 * an exception or perform some other action.
 */
OBJC_HOOK struct objc_slot* (*_objc_selector_type_mismatch)(Class cls,
       SEL selector, struct objc_slot *result);

/**
 * Returns the object if it is not currently in the process of being
 * deallocated.  Returns nil otherwise.  
 *
 * This hook must be set for weak references to work with automatic reference counting.
 */
OBJC_HOOK id (*_objc_weak_load)(id object);

/**
 * Type for a tracing hook.  These are registered to be called before and after
 * each message send.  The parameters are the receiver and selector for the
 * message, the method to be called, a flag indicating the direction, and the
 * return value.  The flag is 0 when the message is being sent and 1 when it
 * returns, the return value is only defined for word-sized scalar returns.
 *
 * If the hook returns (IMP)0, when invoked in the sending direction, then it
 * will not be invoked on return.  This is significantly faster.
 *
 * If the hook returns (IMP)1, when invoked in the sending direction, then it
 * will be invoked again on return.  The return value is ignored on the second
 * call.
 *
 * If it returns any other value, then the result will be called instead of the
 * correct IMP.  This allows all messages with a given selector to be
 * interposed.  
 */
typedef IMP (*objc_tracing_hook)(id, SEL, IMP, int, void*);

/**
 * Registers a tracing hook for a specified selector.  
 */
int objc_registerTracingHook(SEL, objc_tracing_hook);

/**
 * Hook called when a collection is mutated while it is being enumerated.
 */
OBJC_HOOK void(*_objc_enumeration_mutation)(id object);

#ifdef __cplusplus
}
#endif
