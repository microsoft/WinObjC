#if defined(__clang__) && !defined(__OBJC_RUNTIME_INTERNAL__)
#pragma clang system_header
#endif

#ifndef __OBJC_SLOT_H_INCLUDED__
#define __OBJC_SLOT_H_INCLUDED__
/**
 * The objc_slot structure is used to permit safe IMP caching.  It is returned
 * by the new lookup APIs.  When you cache an IMP, you should store a copy of
 * the version field and a pointer to the slot. 
 *
 * The slot version is guaranteed never to be 0.  When updating a cache, you
 * should use code of the following form:
 *
 * 1) version = 0;
 * 2) slot->cachedFor = receiver->isa;
 * 3) slot_cache = slot;
 * 4) version = slot->version;
 *
 * The runtime guarantees that the version in any cachable slot will never be
 * 0.  This should ensure that, if the version and cache pointer mismatch, the
 * next access will cause a cache miss.  
 *
 * When using a cached slot, you should compare the owner pointer to the isa
 * pointer of the receiver and the message and the version of the slot to your
 * cached version.
 */
struct objc_slot
{
	/** The class to which this slot is attached (used internally).  */
	Class owner;
	/** The class for which this slot was cached.  Note that this can be
	 * modified by different cache owners, in different threads.  Doing so may
	 * cause some cache misses, but if different methods are sending messages
	 * to the same object and sharing a cached slot then it may also improve
	 * cache hits.  Profiling is probably required here. */
	Class cachedFor;
	/** The (typed) selector for the method identified by this slot. */
	const char *types;
	/** The current version.  This changes if the method changes or if a
	 * subclass overrides this method, potentially invalidating this cache. */
	int version;
	/** The method pointer for this method. */
	IMP method;
	/** Selector for this method. */
	SEL selector;
} OBJC_NONPORTABLE;
#endif // __OBJC_SLOT_H_INCLUDED__
