#ifndef __CONTINUATION_CACHE_H_
#define __CONTINUATION_CACHE_H_

// If dc_vtable is less than 127, then the object is a continuation.
// Otherwise, the object has a private layout and memory management rules. The
// first two words must align with normal objects.
#define DISPATCH_CONTINUATION_HEADER(x)	\
	const void *				do_vtable;	\
	struct x *volatile	do_next;	\
	dispatch_function_t	dc_func;	\
	void *						dc_ctxt

struct dispatch_continuation_s {
	DISPATCH_CONTINUATION_HEADER(dispatch_continuation_s);
	dispatch_group_t	dc_group;
	void *				dc_data[3];
};

typedef struct dispatch_continuation_s *dispatch_continuation_t;

__private_extern__ malloc_zone_t *_dispatch_ccache_zone;
dispatch_continuation_t _dispatch_continuation_alloc_from_heap(void);

static DISPATCH_INLINE dispatch_continuation_t
_dispatch_continuation_alloc_cacheonly(void)
{
	dispatch_continuation_t dc = fastpath(_dispatch_thread_getspecific(dispatch_cache_key));
	if (dc) {
		_dispatch_thread_setspecific(dispatch_cache_key, dc->do_next);
	}
	return dc;
}

void
_dispatch_ccache_init(void *context DISPATCH_UNUSED);

dispatch_continuation_t
_dispatch_continuation_alloc_from_heap(void);

void
_dispatch_force_cache_cleanup(void);

DISPATCH_NOINLINE
void
_dispatch_cache_cleanup2(void *value);

#endif /* __CONTINUATION_CACHE_H_ */
