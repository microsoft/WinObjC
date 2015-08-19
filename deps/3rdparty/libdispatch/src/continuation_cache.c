#include "internal.h"

malloc_zone_t *_dispatch_ccache_zone;

void
_dispatch_ccache_init(void *context DISPATCH_UNUSED)
{
	_dispatch_ccache_zone = malloc_create_zone(0, 0);
	dispatch_assert(_dispatch_ccache_zone);
	malloc_set_zone_name(_dispatch_ccache_zone, "DispatchContinuations");
}

dispatch_continuation_t
_dispatch_continuation_alloc_from_heap(void)
{
	static dispatch_once_t pred;
	dispatch_continuation_t dc;

	dispatch_once_f(&pred, NULL, _dispatch_ccache_init);

	while (!(dc = fastpath(malloc_zone_calloc(_dispatch_ccache_zone, 1, ROUND_UP_TO_CACHELINE_SIZE(sizeof(*dc)))))) {
		sleep(1);
	}

	return dc;
}

void
_dispatch_force_cache_cleanup(void)
{
	dispatch_continuation_t dc = _dispatch_thread_getspecific(dispatch_cache_key);
	if (dc) {
		_dispatch_thread_setspecific(dispatch_cache_key, NULL);
		_dispatch_cache_cleanup2(dc);
	}
}

DISPATCH_NOINLINE
void
_dispatch_cache_cleanup2(void *value)
{
	dispatch_continuation_t dc, next_dc = value;

	while ((dc = next_dc)) {
		next_dc = dc->do_next;
		malloc_zone_free(_dispatch_ccache_zone, dc);
	}
}
