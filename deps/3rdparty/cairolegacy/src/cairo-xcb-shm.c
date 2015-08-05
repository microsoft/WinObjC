/* Cairo - a vector graphics library with display and print output
 *
 * Copyright © 2007 Chris Wilson
 * Copyright © 2009 Intel Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it either under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * (the "LGPL") or, at your option, under the terms of the Mozilla
 * Public License Version 1.1 (the "MPL"). If you do not alter this
 * notice, a recipient may use your version of this file under either
 * the MPL or the LGPL.
 *
 * You should have received a copy of the LGPL along with this library
 * in the file COPYING-LGPL-2.1; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA
 * You should have received a copy of the MPL along with this library
 * in the file COPYING-MPL-1.1
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY
 * OF ANY KIND, either express or implied. See the LGPL or the MPL for
 * the specific language governing rights and limitations.
 *
 * The Original Code is the cairo graphics library.
 *
 * The Initial Developer of the Original Code is Red Hat, Inc.
 *
 * Contributors(s):
 *	Chris Wilson <chris@chris-wilson.co.uk>
 */

#include "cairoint.h"

#include "cairo-xcb-private.h"

#include <xcb/shm.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

/* a simple buddy allocator for memory pools
 * XXX fragmentation? use Doug Lea's malloc?
 */

typedef struct _cairo_xcb_shm_mem_block cairo_xcb_shm_mem_block_t;

struct _cairo_xcb_shm_mem_block {
    unsigned int bits;
    cairo_list_t link;
};

struct _cairo_xcb_shm_mem_pool {
    int shmid;
    uint32_t shmseg;

    char *base;
    unsigned int nBlocks;
    cairo_xcb_shm_mem_block_t *blocks;
    cairo_list_t free[32];
    unsigned char *map;

    unsigned int min_bits;     /* Minimum block size is 1 << min_bits */
    unsigned int num_sizes;

    size_t free_bytes;
    size_t max_bytes;
    unsigned int max_free_bits;

    cairo_list_t link;
};

#define BITTEST(p, n)  ((p)->map[(n) >> 3] &   (128 >> ((n) & 7)))
#define BITSET(p, n)   ((p)->map[(n) >> 3] |=  (128 >> ((n) & 7)))
#define BITCLEAR(p, n) ((p)->map[(n) >> 3] &= ~(128 >> ((n) & 7)))

static void
clear_bits (cairo_xcb_shm_mem_pool_t *pi, size_t first, size_t last)
{
    size_t i, n = last;
    size_t first_full = (first + 7) & ~7;
    size_t past_full = last & ~7;
    size_t bytes;

    if (n > first_full)
	n = first_full;
    for (i = first; i < n; i++)
	  BITCLEAR (pi, i);

    if (past_full > first_full) {
	bytes = past_full - first_full;
	bytes = bytes >> 3;
	memset (pi->map + (first_full >> 3), 0, bytes);
    }

    if (past_full < n)
	past_full = n;
    for (i = past_full; i < last; i++)
	BITCLEAR (pi, i);
}

static void
free_bits (cairo_xcb_shm_mem_pool_t *pi,
	   size_t start,
	   unsigned int bits,
	   cairo_bool_t clear)
{
    cairo_xcb_shm_mem_block_t *block;

    if (clear)
	clear_bits (pi, start, start + (1 << bits));

    block = pi->blocks + start;
    block->bits = bits;

    cairo_list_add (&block->link, &pi->free[bits]);

    pi->free_bytes += 1 << (bits + pi->min_bits);
    if (bits > pi->max_free_bits)
	pi->max_free_bits = bits;
}

/* Add a chunk to the free list */
static void
free_blocks (cairo_xcb_shm_mem_pool_t *pi,
	     size_t first,
	     size_t last,
	     cairo_bool_t clear)
{
    size_t i;
    size_t bits = 0;
    size_t len = 1;

    i = first;
    while (i < last) {
        /* To avoid cost quadratic in the number of different
	 * blocks produced from this chunk of store, we have to
	 * use the size of the previous block produced from this
	 * chunk as the starting point to work out the size of the
	 * next block we can produce. If you look at the binary
	 * representation of the starting points of the blocks
	 * produced, you can see that you first of all increase the
	 * size of the blocks produced up to some maximum as the
	 * address dealt with gets offsets added on which zap out
	 * low order bits, then decrease as the low order bits of the
	 * final block produced get added in. E.g. as you go from
	 * 001 to 0111 you generate blocks
	 * of size 001 at 001 taking you to 010
	 * of size 010 at 010 taking you to 100
	 * of size 010 at 100 taking you to 110
	 * of size 001 at 110 taking you to 111
	 * So the maximum total cost of the loops below this comment
	 * is one trip from the lowest blocksize to the highest and
	 * back again.
	 */
	while (bits < pi->num_sizes - 1) {
	    size_t next_bits = bits + 1;
	    size_t next_len = len << 1;

	    if (i + next_bits > last) {
		/* off end of chunk to be freed */
	        break;
	    }

	    if (i & (next_len - 1)) /* block would not be on boundary */
	        break;

	    bits = next_bits;
	    len = next_len;
	}

	do {
	    if (i + len > last) /* off end of chunk to be freed */
	        continue;

	    if (i & (len - 1)) /* block would not be on boundary */
	        continue;

	    /* OK */
	    break;

	    bits--;
	    len >>=1;
	} while (len > 0);

	if (len == 0)
	    break;

	free_bits (pi, i, bits, clear);
	i += len;
    }
}

static cairo_status_t
_cairo_xcb_shm_mem_pool_init (cairo_xcb_shm_mem_pool_t *pi,
			      size_t bytes,
			      unsigned int min_bits,
			      unsigned int num_sizes)
{
    size_t setBits;
    int i;

    assert ((((unsigned long) pi->base) & ((1 << min_bits) - 1)) == 0);
    assert (num_sizes < ARRAY_LENGTH (pi->free));

    pi->free_bytes = 0;
    pi->max_bytes = bytes;
    pi->max_free_bits = 0;

    setBits = bytes >> min_bits;
    pi->blocks = calloc (setBits, sizeof (cairo_xcb_shm_mem_block_t));
    if (pi->blocks == NULL)
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);

    pi->nBlocks = setBits;
    pi->min_bits = min_bits;
    pi->num_sizes = num_sizes;

    for (i = 0; i < ARRAY_LENGTH (pi->free); i++)
	cairo_list_init (&pi->free[i]);

    pi->map = malloc ((setBits + 7) >> 3);
    if (pi->map == NULL) {
	free (pi->blocks);
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);
    }

    memset (pi->map, -1, (setBits + 7) >> 3);
    clear_bits (pi, 0, setBits);

    /* Now add all blocks to the free list */
    free_blocks (pi, 0, setBits, 1);

    return CAIRO_STATUS_SUCCESS;
}

static cairo_xcb_shm_mem_block_t *
get_buddy (cairo_xcb_shm_mem_pool_t *pi,
	   size_t offset,
	   unsigned int bits)
{
    cairo_xcb_shm_mem_block_t *block;

    assert (offset + (1 << bits) <= pi->nBlocks);

    if (BITTEST (pi, offset + (1 << bits) - 1))
	return NULL; /* buddy is allocated */

    block = pi->blocks + offset;
    if (block->bits != bits)
	return NULL; /* buddy is partially allocated */

    return block;
}

static void
merge_buddies (cairo_xcb_shm_mem_pool_t *pi,
	       cairo_xcb_shm_mem_block_t *block,
	       unsigned int max_bits)
{
    size_t block_offset = block_offset = block - pi->blocks;
    unsigned int bits = block->bits;

    while (bits < max_bits - 1) {
	/* while you can, merge two blocks and get a legal block size */
	size_t buddy_offset = block_offset ^ (1 << bits);

	block = get_buddy (pi, buddy_offset, bits);
	if (block == NULL)
	    break;

	cairo_list_del (&block->link);

	/* Merged block starts at buddy */
	if (buddy_offset < block_offset)
	    block_offset = buddy_offset;

	bits++;
    }

    block = pi->blocks + block_offset;
    block->bits = bits;
    cairo_list_add (&block->link, &pi->free[bits]);

    if (bits > pi->max_free_bits)
	pi->max_free_bits = bits;
}

/* attempt to merge all available buddies up to a particular size */
static unsigned int
merge_bits (cairo_xcb_shm_mem_pool_t *pi,
	    unsigned int max_bits)
{
    cairo_xcb_shm_mem_block_t *block, *buddy, *next;
    unsigned int bits;

    for (bits = 0; bits < max_bits - 1; bits++) {
	cairo_list_foreach_entry_safe (block, next,
				       cairo_xcb_shm_mem_block_t,
				       &pi->free[bits],
				       link)
	{
	    size_t buddy_offset = (block - pi->blocks) ^ (1 << bits);

	    buddy = get_buddy (pi, buddy_offset, bits);
	    if (buddy == NULL)
		continue;

	    if (buddy == next) {
		next = cairo_container_of (buddy->link.next,
					   cairo_xcb_shm_mem_block_t,
					   link);
	    }

	    cairo_list_del (&block->link);
	    merge_buddies (pi, block, max_bits);
	}
    }

    return pi->max_free_bits;
}

/* find store for 1 << bits blocks */
static void *
buddy_malloc (cairo_xcb_shm_mem_pool_t *pi,
	      unsigned int bits)
{
    unsigned int b;
    size_t offset;
    size_t past;
    cairo_xcb_shm_mem_block_t *block;

    if (bits > pi->max_free_bits && bits > merge_bits (pi, bits))
	return NULL;

    /* Find a list with blocks big enough on it */
    block = NULL;
    for (b = bits; b <= pi->max_free_bits; b++) {
	if (! cairo_list_is_empty (&pi->free[b])) {
	    block = cairo_list_first_entry (&pi->free[b],
					    cairo_xcb_shm_mem_block_t,
					    link);
	    break;
	}
    }
    assert (block != NULL);

    cairo_list_del (&block->link);

    while (cairo_list_is_empty (&pi->free[pi->max_free_bits])) {
	if (--pi->max_free_bits == 0)
	    break;
    }

    /* Mark end of allocated area */
    offset = block - pi->blocks;
    past = offset + (1 << bits);
    BITSET (pi, past - 1);
    block->bits = bits;

    /* If we used a larger free block than we needed, free the rest */
    pi->free_bytes -= 1 << (b + pi->min_bits);
    free_blocks (pi, past, offset + (1 << b), 0);

    return pi->base + ((block - pi->blocks) << pi->min_bits);
}

static void *
_cairo_xcb_shm_mem_pool_malloc (cairo_xcb_shm_mem_pool_t *pi,
				size_t bytes)
{
    unsigned int bits;
    size_t size;

    size = 1 << pi->min_bits;
    for (bits = 0; size < bytes; bits++)
	size <<= 1;
    if (bits >= pi->num_sizes)
	return NULL;

    return buddy_malloc (pi, bits);
}

static void
_cairo_xcb_shm_mem_pool_free (cairo_xcb_shm_mem_pool_t *pi,
			      char *storage)
{
    size_t block_offset;
    cairo_xcb_shm_mem_block_t *block;

    block_offset = (storage - pi->base) >> pi->min_bits;
    block = pi->blocks + block_offset;

    BITCLEAR (pi, block_offset + ((1 << block->bits) - 1));
    pi->free_bytes += 1 << (block->bits + pi->min_bits);

    merge_buddies (pi, block, pi->num_sizes);
}

static void
_cairo_xcb_shm_mem_pool_destroy (cairo_xcb_shm_mem_pool_t *pool)
{
    shmdt (pool->base);
    cairo_list_del (&pool->link);

    free (pool->map);
    free (pool->blocks);
    free (pool);
}

cairo_int_status_t
_cairo_xcb_connection_allocate_shm_info (cairo_xcb_connection_t *connection,
					 size_t size,
					 cairo_xcb_shm_info_t **shm_info_out)
{
    cairo_xcb_shm_info_t *shm_info;
    cairo_xcb_shm_mem_pool_t *pool, *next;
    size_t bytes, maxbits = 16, minbits = 8;
    void *mem = NULL;
    cairo_status_t status;

    assert (connection->flags & CAIRO_XCB_HAS_SHM);

    CAIRO_MUTEX_LOCK (connection->shm_mutex);
    cairo_list_foreach_entry_safe (pool, next, cairo_xcb_shm_mem_pool_t,
				   &connection->shm_pools, link)
    {
	if (pool->free_bytes > size) {
	    mem = _cairo_xcb_shm_mem_pool_malloc (pool, size);
	    if (mem != NULL) {
		/* keep the active pools towards the front */
		cairo_list_move (&pool->link, &connection->shm_pools);
		goto allocate_shm_info;
	    }
	}
	/* scan for old, unused pools */
	if (pool->free_bytes == pool->max_bytes) {
	    _cairo_xcb_connection_shm_detach (connection,
					      pool->shmseg);
	    _cairo_xcb_shm_mem_pool_destroy (pool);
	}
    }

    pool = malloc (sizeof (cairo_xcb_shm_mem_pool_t));
    if (unlikely (pool == NULL)) {
	CAIRO_MUTEX_UNLOCK (connection->shm_mutex);
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);
    }

    bytes = 1 << maxbits;
    while (bytes <= size)
	bytes <<= 1, maxbits++;
    bytes <<= 3;

    do {
	pool->shmid = shmget (IPC_PRIVATE, bytes, IPC_CREAT | 0600);
	if (pool->shmid != -1)
	    break;

	if (errno == EINVAL && bytes > size) {
	    bytes >>= 1;
	    continue;
	}
    } while (FALSE);
    if (pool->shmid == -1) {
	int err = errno;
	if (! (err == EINVAL || err == ENOMEM))
	    connection->flags &= ~CAIRO_XCB_HAS_SHM;
	free (pool);
	CAIRO_MUTEX_UNLOCK (connection->shm_mutex);
	return CAIRO_INT_STATUS_UNSUPPORTED;
    }

    pool->base = shmat (pool->shmid, NULL, 0);
    if (unlikely (pool->base == (char *) -1)) {
	shmctl (pool->shmid, IPC_RMID, NULL);
	free (pool);
	CAIRO_MUTEX_UNLOCK (connection->shm_mutex);
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);
    }

    status = _cairo_xcb_shm_mem_pool_init (pool,
					   bytes,
					   minbits,
					   maxbits - minbits + 1);
    if (unlikely (status)) {
	shmdt (pool->base);
	free (pool);
	CAIRO_MUTEX_UNLOCK (connection->shm_mutex);
	return status;
    }

    pool->shmseg = _cairo_xcb_connection_shm_attach (connection, pool->shmid, FALSE);
    shmctl (pool->shmid, IPC_RMID, NULL);

    cairo_list_add (&pool->link, &connection->shm_pools);
    mem = _cairo_xcb_shm_mem_pool_malloc (pool, size);

  allocate_shm_info:
    shm_info = _cairo_freepool_alloc (&connection->shm_info_freelist);
    if (unlikely (shm_info == NULL)) {
	_cairo_xcb_shm_mem_pool_free (pool, mem);
	CAIRO_MUTEX_UNLOCK (connection->shm_mutex);
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);
    }

    shm_info->connection = connection;
    shm_info->pool = pool;
    shm_info->shm = pool->shmseg;
    shm_info->offset = (char *) mem - (char *) pool->base;
    shm_info->mem = mem;

    /* scan for old, unused pools */
    cairo_list_foreach_entry_safe (pool, next, cairo_xcb_shm_mem_pool_t,
				   &connection->shm_pools, link)
    {
	if (pool->free_bytes == pool->max_bytes) {
	    _cairo_xcb_connection_shm_detach (connection,
					      pool->shmseg);
	    _cairo_xcb_shm_mem_pool_destroy (pool);
	}
    }
    CAIRO_MUTEX_UNLOCK (connection->shm_mutex);

    *shm_info_out = shm_info;
    return CAIRO_STATUS_SUCCESS;
}

void
_cairo_xcb_shm_info_destroy (cairo_xcb_shm_info_t *shm_info)
{
    cairo_xcb_connection_t *connection = shm_info->connection;

    CAIRO_MUTEX_LOCK (connection->shm_mutex);

    _cairo_xcb_shm_mem_pool_free (shm_info->pool, shm_info->mem);
    _cairo_freepool_free (&connection->shm_info_freelist, shm_info);

    /* scan for old, unused pools - hold at least one in reserve */
    if (! cairo_list_is_singular (&connection->shm_pools) &&
	_cairo_xcb_connection_take_socket (connection) == CAIRO_STATUS_SUCCESS)
    {
	cairo_xcb_shm_mem_pool_t *pool, *next;
	cairo_list_t head;

	cairo_list_init (&head);
	cairo_list_move (connection->shm_pools.next, &head);

	cairo_list_foreach_entry_safe (pool, next, cairo_xcb_shm_mem_pool_t,
				       &connection->shm_pools, link)
	{
	    if (pool->free_bytes == pool->max_bytes) {
		_cairo_xcb_connection_shm_detach (connection, pool->shmseg);
		_cairo_xcb_shm_mem_pool_destroy (pool);
	    }
	}

	cairo_list_move (head.next, &connection->shm_pools);
    }

    CAIRO_MUTEX_UNLOCK (connection->shm_mutex);
}

void
_cairo_xcb_connection_shm_mem_pools_fini (cairo_xcb_connection_t *connection)
{
    while (! cairo_list_is_empty (&connection->shm_pools)) {
	_cairo_xcb_shm_mem_pool_destroy (cairo_list_first_entry (&connection->shm_pools,
								 cairo_xcb_shm_mem_pool_t,
								 link));
    }
}
