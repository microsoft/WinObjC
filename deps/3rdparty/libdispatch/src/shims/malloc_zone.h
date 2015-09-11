/*
 * Copyright (c) 2009 Apple Inc. All rights reserved.
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

#ifndef __DISPATCH_SHIMS_MALLOC_ZONE__
#define __DISPATCH_SHIMS_MALLOC_ZONE__

#include <sys/types.h>

#include <stdlib.h>

/*
 * Implement malloc zones as a simple wrapper around malloc(3) on systems
 * that don't support them.
 */
#if !HAVE_MALLOC_CREATE_ZONE
typedef void * malloc_zone_t;

static DISPATCH_INLINE malloc_zone_t *
malloc_create_zone(size_t start_size, unsigned flags)
{
	return ((malloc_zone_t *)((intptr_t)-1));
}

static DISPATCH_INLINE void
malloc_destroy_zone(malloc_zone_t *zone)
{
	/* No-op. */
}

static DISPATCH_INLINE malloc_zone_t *
malloc_default_zone(void)
{
	return ((malloc_zone_t *)((intptr_t)-1));
}

static DISPATCH_INLINE malloc_zone_t *
malloc_zone_from_ptr(const void *ptr)
{
	return ((malloc_zone_t *)((intptr_t)-1));
}

static DISPATCH_INLINE void *
malloc_zone_malloc(malloc_zone_t *zone, size_t size)
{
	return (malloc(size));
}

static DISPATCH_INLINE void *
malloc_zone_calloc(malloc_zone_t *zone, size_t num_items, size_t size)
{
	return (calloc(num_items, size));
}

#if !TARGET_OS_WIN32
static DISPATCH_INLINE void *
malloc_zone_realloc(malloc_zone_t *zone, void *ptr, size_t size)
{
	return (realloc(ptr, size));
}
#endif

static DISPATCH_INLINE void
malloc_zone_free(malloc_zone_t *zone, void *ptr)
{
	free(ptr);
}

static DISPATCH_INLINE void
malloc_set_zone_name(malloc_zone_t *zone, const char *name)
{
	/* No-op. */
}
#endif /* !HAVE_MALLOC_CREATE_ZONE */

#endif /* __DISPATCH_SHIMS_MALLOC_ZONE__ */
