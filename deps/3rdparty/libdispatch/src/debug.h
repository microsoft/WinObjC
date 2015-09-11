#ifndef DEBUG_H_
#define DEBUG_H_

#if __GNUC__
void _dispatch_bug(size_t line, long val) __attribute__((__noinline__));
void _dispatch_abort(size_t line, long val) __attribute__((__noinline__,__noreturn__));
void _dispatch_log(const char *msg, ...) __attribute__((__noinline__,__format__(printf,1,2)));
void _dispatch_logv(const char *msg, va_list) __attribute__((__noinline__,__format__(printf,1,0)));
#else
DISPATCH_NOINLINE void _dispatch_bug(size_t line, long val);
DISPATCH_NOINLINE __declspec(noreturn) void _dispatch_abort(size_t line, long val);
DISPATCH_NOINLINE void _dispatch_log(/*_Printf_format_string_*/const char *msg, ...);
DISPATCH_NOINLINE void _dispatch_logv(/*_Printf_format_string_*/const char *msg, va_list);
#endif

#if __GNUC__

# if defined(__STDC__) && !defined(typeof)
#  define typeof __typeof__
# endif

/*
 * For reporting bugs within libdispatch when using the "_debug" version of the library.
 */
#define dispatch_assert(e)	do {	\
		if (__builtin_constant_p(e)) {	\
			char __compile_time_assert__[(bool)(e) ? 1 : -1] __attribute__((unused));	\
		} else {	\
			typeof(e) _e = fastpath(e); /* always eval 'e' */	\
			if (DISPATCH_DEBUG && !_e) {	\
				_dispatch_abort(__LINE__, (long)_e);	\
			}	\
		}	\
	} while (0)
/* A lot of API return zero upon success and not-zero on fail. Let's capture and log the non-zero value */
#define dispatch_assert_zero(e)	do {	\
		if (__builtin_constant_p(e)) {	\
			char __compile_time_assert__[(bool)(!(e)) ? 1 : -1] __attribute__((unused));	\
		} else {	\
			typeof(e) _e = slowpath(e); /* always eval 'e' */	\
			if (DISPATCH_DEBUG && _e) {	\
				_dispatch_abort(__LINE__, (long)_e);	\
			}	\
		}	\
	} while (0)

/*
 * For reporting bugs or impedance mismatches between libdispatch and external subsystems.
 * These do NOT abort(), and are always compiled into the product.
 *
 * In particular, we wrap all system-calls with assume() macros.
 */
#define dispatch_assume(e)	({	\
		typeof(e) _e = fastpath(e); /* always eval 'e' */	\
		if (!_e) {	\
			if (__builtin_constant_p(e)) {	\
				char __compile_time_assert__[(e) ? 1 : -1];	\
				(void)__compile_time_assert__;	\
			}	\
			_dispatch_bug(__LINE__, (long)_e);	\
		}	\
		_e;	\
	})
/* A lot of API return zero upon success and not-zero on fail. Let's capture and log the non-zero value */
#define dispatch_assume_zero(e)	({	\
		typeof(e) _e = slowpath(e); /* always eval 'e' */	\
		if (_e) {	\
			if (__builtin_constant_p(e)) {	\
				char __compile_time_assert__[(e) ? -1 : 1];	\
				(void)__compile_time_assert__;	\
			}	\
			_dispatch_bug(__LINE__, (long)_e);	\
		}	\
		_e;	\
	})

/*
 * For reporting bugs in clients when using the "_debug" version of the library.
 */
#define dispatch_debug_assert(e, msg, args...)	do {	\
		if (__builtin_constant_p(e)) {	\
			char __compile_time_assert__[(bool)(e) ? 1 : -1] __attribute__((unused));	\
		} else {	\
			typeof(e) _e = fastpath(e); /* always eval 'e' */	\
			if (DISPATCH_DEBUG && !_e) {	\
				_dispatch_log("%s() 0x%lx: " msg, __func__, (long)_e, ##args);	\
				abort();	\
			}	\
		}	\
	} while (0)

/* Make sure the debug statments don't get too stale */
#define _dispatch_debug(x, args...)	\
({	\
	if (DISPATCH_DEBUG) {	\
		_dispatch_log("libdispatch: %u\t%p\t" x, __LINE__,	\
		    (void *)_dispatch_thread_self(), ##args);	\
	}	\
})

#elif defined(_MSC_VER)
/*
 * For reporting bugs within libdispatch when using the "_debug" version of the library.
 */
#define dispatch_assert(e)	do {	\
		uintptr_t _e = (uintptr_t)fastpath(e); /* always eval 'e' */	\
		if (DISPATCH_DEBUG && !_e) {	\
			_dispatch_abort(__LINE__, (long)_e);	\
		}	\
	} while (0)
/* A lot of API return zero upon success and not-zero on fail. Let's capture and log the non-zero value */
#define dispatch_assert_zero(e)	do {	\
		uintptr_t _e = (uintptr_t)slowpath(e); /* always eval 'e' */	\
		if (DISPATCH_DEBUG && _e) {	\
			_dispatch_abort(__LINE__, (long)_e);	\
		}	\
	} while (0)

/*
 * For reporting bugs or impedance mismatches between libdispatch and external subsystems.
 * These do NOT abort(), and are always compiled into the product.
 *
 * In particular, we wrap all system-calls with assume() macros.
 */
#define dispatch_assume(e)	do{	\
		uintptr_t _e = (uintptr_t)fastpath(e); /* always eval 'e' */	\
		if (!_e) {	\
			_dispatch_bug(__LINE__, (long)_e);	\
		}	\
		_e;	\
	}while(0)
/* A lot of API return zero upon success and not-zero on fail. Let's capture and log the non-zero value */
#define dispatch_assume_zero(e)	do{	\
		uintptr_t _e = (uintptr_t)slowpath(e); /* always eval 'e' */	\
		if (_e) {	\
			_dispatch_bug(__LINE__, (long)_e);	\
		}	\
		_e;	\
	}while(0)

/*
 * For reporting bugs in clients when using the "_debug" version of the library.
 */
#define dispatch_debug_assert(e, msg, ...)	do {	\
		uintptr_t _e = (uintptr_t)fastpath(e); /* always eval 'e' */	\
		if (DISPATCH_DEBUG && !_e) {	\
			_dispatch_log("%s() 0x%lx: " msg, __func__, (long)_e, __VA_ARGS__);	\
			abort();	\
		}	\
	} while (0)

/* Make sure the debug statments don't get too stale */
#define _dispatch_debug(x, ...)	\
do{	\
	if (DISPATCH_DEBUG) {	\
		_dispatch_log("libdispatch: %u\t%p\t" x, __LINE__,	\
		    (void *)_dispatch_thread_self(), __VA_ARGS__);	\
	}	\
}while(0)

#endif

#if USE_APPLE_CRASHREPORTER_INFO

#if HAVE_MACH
// MIG_REPLY_MISMATCH means either:
// 1) A signal handler is NOT using async-safe API. See the sigaction(2) man page for more info.
// 2) A hand crafted call to mach_msg*() screwed up. Use MIG.
#define DISPATCH_VERIFY_MIG(x) do {	\
		if ((x) == MIG_REPLY_MISMATCH) {	\
			__crashreporter_info__ = "MIG_REPLY_MISMATCH";	\
			_dispatch_hardware_crash();	\
		}	\
	} while (0)
#endif

#if defined(__x86_64__) || defined(__i386__)
// total hack to ensure that return register of a function is not trashed
#define DISPATCH_CRASH(x)	do {	\
		asm("mov	%1, %0" : "=m" (__crashreporter_info__) : "c" ("BUG IN LIBDISPATCH: " x));	\
		_dispatch_hardware_crash();	\
	} while (0)

#define DISPATCH_CLIENT_CRASH(x)	do {	\
		asm("mov	%1, %0" : "=m" (__crashreporter_info__) : "c" ("BUG IN CLIENT OF LIBDISPATCH: " x));	\
		_dispatch_hardware_crash();	\
	} while (0)

#else /* !(defined(__x86_64__) || defined(__i386__)) */

#define DISPATCH_CRASH(x)	do {	\
		__crashreporter_info__ = "BUG IN LIBDISPATCH: " x;	\
		_dispatch_hardware_crash();	\
	} while (0)

#define DISPATCH_CLIENT_CRASH(x)	do {	\
		__crashreporter_info__ = "BUG IN CLIENT OF LIBDISPATCH: " x;	\
		_dispatch_hardware_crash();	\
	} while (0)
#endif /* defined(__x86_64__) || defined(__i386__) */

#else /* !USE_APPLE_CRASHREPORTER_INFO */

#if HAVE_MACH
#define DISPATCH_VERIFY_MIG(x) do {	\
		if ((x) == MIG_REPLY_MISMATCH) {	\
			_dispatch_hardware_crash();	\
		}	\
	} while (0)
#endif

#define	DISPATCH_CRASH(x)		_dispatch_hardware_crash()
#define	DISPATCH_CLIENT_CRASH(x)	_dispatch_hardware_crash()

#endif /* USE_APPLE_CRASHREPORTER_INFO */

#endif /* DEBUG_H_ */
