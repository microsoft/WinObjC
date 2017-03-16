#ifndef __DISPATCH_ATOMIC__
#define __DISPATCH_ATOMIC__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#endif

#ifdef _MSC_VER
#include <intrin.h>
#endif

__DISPATCH_BEGIN_DECLS

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)
// GCC generates suboptimal register pressure
// LLVM does better, but doesn't support tail calls
// 6248590 __sync_*() intrinsics force a gratuitous "lea" instruction, with resulting register pressure
#if 0 && defined(__i386__) || defined(__x86_64__)
#define dispatch_atomic_xchg(p, n)	({ typeof(*(p)) _r; asm("xchg %0, %1" : "=r" (_r) : "m" (*(p)), "0" (n)); _r; })
#else
#define dispatch_atomic_xchg(p, n)	((typeof(*(p)))__sync_lock_test_and_set((p), (n)))
#endif
#define dispatch_atomic_xchg_pointer	dispatch_atomic_xchg
#define dispatch_atomic_cmpxchg(p, o, n)	__sync_bool_compare_and_swap((p), (o), (n))
#define dispatch_atomic_cmpxchg_pointer	dispatch_atomic_cmpxchg
#define dispatch_atomic_inc(p)	__sync_add_and_fetch((p), 1)
#define dispatch_atomic_dec(p)	__sync_sub_and_fetch((p), 1)
#define dispatch_atomic_add(p, v)	__sync_add_and_fetch((p), (v))
#define dispatch_atomic_sub(p, v)	__sync_sub_and_fetch((p), (v))
#define dispatch_atomic_or(p, v)	__sync_fetch_and_or((p), (v))
#define dispatch_atomic_and(p, v)	__sync_fetch_and_and((p), (v))
#if defined(__i386__) || defined(__x86_64__)
/* GCC emits nothing for __sync_synchronize() on i386/x86_64. */
#define dispatch_atomic_barrier()	__asm__ __volatile__("mfence")
#else
#define dispatch_atomic_barrier()	__sync_synchronize()
#endif
#elif _MSC_VER
#if defined(_M_IX86) || (defined(WINOBJC) && defined(_M_ARM))
#pragma intrinsic(_InterlockedExchange)
#define dispatch_atomic_xchg(p, n)         (intptr_t)_InterlockedExchange       ((volatile long*)(p), (long )(n))
#define dispatch_atomic_xchg_pointer(p, n) (void*   ) InterlockedExchangePointer((volatile void*)(p), (void*)(n))
#pragma intrinsic(_InterlockedCompareExchange)
#define _dispatch_atomic_cmpxchg(p, o, n)         (intptr_t)_InterlockedCompareExchange((volatile long*)(p), (long)(n), (long)(o))
#define _dispatch_atomic_cmpxchg_pointer(p, o, n) (void*   )_InterlockedCompareExchange((volatile long*)(p), (long)(n), (long)(o))
#pragma intrinsic(_InterlockedIncrement)
#define dispatch_atomic_inc(p)	_InterlockedIncrement((volatile long*)(p))
#pragma intrinsic(_InterlockedDecrement)
#define dispatch_atomic_dec(p)	_InterlockedDecrement((volatile long*)(p))
#pragma intrinsic(_InterlockedExchangeAdd)
#define dispatch_atomic_add(p, v)	(_InterlockedExchangeAdd((volatile long*)(p), +(signed long)(v)), *(p))
#define dispatch_atomic_sub(p, v)	(_InterlockedExchangeAdd((volatile long*)(p), -(signed long)(v)), *(p))
#pragma intrinsic(_InterlockedOr)
#define dispatch_atomic_or(p, v)	_InterlockedOr((volatile long*)(p), (long)(v))
#pragma intrinsic(_InterlockedAnd)
#define dispatch_atomic_and(p, v)	_InterlockedAnd((volatile long*)(p), (long)(v))
#elif defined(_M_X64)
#pragma intrinsic(_InterlockedExchange64)
#define dispatch_atomic_xchg(p, n)	_InterlockedExchange64((p), (n))
#pragma intrinsic(_InterlockedExchangePointer)
#define dispatch_atomic_xchg_pointer(p, n)	_InterlockedExchangePointer((p), (n))
#pragma intrinsic(_InterlockedCompareExchange64)
#define _dispatch_atomic_cmpxchg(p, o, n)	_InterlockedCompareExchange64((p), (n), (o))
#pragma intrinsic(_InterlockedCompareExchangePointer)
#define _dispatch_atomic_cmpxchg_pointer(p, o, n)	_InterlockedCompareExchangePointer((p), (n), (o))
#pragma intrinsic(_InterlockedIncrement64)
#define dispatch_atomic_inc(p)	_InterlockedIncrement64((p))
#pragma intrinsic(_InterlockedDecrement64)
#define dispatch_atomic_dec(p)	_InterlockedDecrement64((p))
#pragma intrinsic(_InterlockedExchangeAdd64)
#define dispatch_atomic_add(p, v)	(_InterlockedExchangeAdd64((p), +(signed __int64)(v)), *(p))
#define dispatch_atomic_sub(p, v)	(_InterlockedExchangeAdd64((p), -(signed __int64)(v)), *(p)	)
#pragma intrinsic(_InterlockedOr)
#define dispatch_atomic_or(p, v)	_InterlockedOr64((p), (v))
#pragma intrinsic(_InterlockedAnd)
#define dispatch_atomic_and(p, v)	_InterlockedAnd64((p), (v))
#else
#error Unsupported architecture
#endif

DISPATCH_INLINE bool dispatch_atomic_cmpxchg(intptr_t* p, intptr_t o, intptr_t n)
{
	return o == _dispatch_atomic_cmpxchg(p, o, n);
}

DISPATCH_INLINE bool dispatch_atomic_cmpxchg_pointer(void* volatile* p, void* o, void* n)
{
	return o == _dispatch_atomic_cmpxchg_pointer(p, o, n);
}

#ifdef WINOBJC
#define dispatch_atomic_barrier()	__sync_synchronize()
#else
#pragma intrinsic(_mm_mfence)
#define dispatch_atomic_barrier()	_mm_mfence()
#endif
#else
#error "Please upgrade to GCC 4.2 or newer."
#endif

__DISPATCH_END_DECLS

#endif
