/* Cairo - a vector graphics library with display and print output
 *
 * Copyright © 2008 Chris Wilson
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
 * Authors:
 *    Chris Wilson <chris@chris-wilson.co.uk>
 */

#include "cairoint.h"

#include "cairo-xcb-private.h"

struct pattern_cache_entry {
    cairo_cache_entry_t key;
    cairo_xcb_screen_t *screen;
    cairo_pattern_union_t pattern;
    cairo_surface_t *picture;
};

void
_cairo_xcb_screen_finish (cairo_xcb_screen_t *screen)
{
    int i;

    CAIRO_MUTEX_LOCK (screen->connection->screens_mutex);
    cairo_list_del (&screen->link);
    CAIRO_MUTEX_UNLOCK (screen->connection->screens_mutex);

    while (! cairo_list_is_empty (&screen->surfaces)) {
	cairo_surface_t *surface;

	surface = &cairo_list_first_entry (&screen->surfaces,
					   cairo_xcb_surface_t,
					   link)->base;

	cairo_surface_reference (surface);
	cairo_surface_finish (surface);
	cairo_surface_destroy (surface);
    }

    for (i = 0; i < screen->solid_cache_size; i++)
	cairo_surface_destroy (screen->solid_cache[i].picture);

    for (i = 0; i < ARRAY_LENGTH (screen->stock_colors); i++)
	cairo_surface_destroy (screen->stock_colors[i]);

    _cairo_cache_fini (&screen->surface_pattern_cache);
    _cairo_cache_fini (&screen->linear_pattern_cache);
    _cairo_cache_fini (&screen->radial_pattern_cache);
    _cairo_freelist_fini (&screen->pattern_cache_entry_freelist);

    cairo_device_finish (screen->device);
    cairo_device_destroy (screen->device);

    free (screen);
}

static cairo_bool_t
_surface_pattern_cache_entry_equal (const void *A, const void *B)
{
    const struct pattern_cache_entry *a = A, *b = B;

    return a->key.hash == b->key.hash;
}

static cairo_bool_t
_linear_pattern_cache_entry_equal (const void *A, const void *B)
{
    const struct pattern_cache_entry *a = A, *b = B;

    if (a->key.hash != b->key.hash)
	return FALSE;

    return _cairo_linear_pattern_equal (&a->pattern.gradient.linear,
					&b->pattern.gradient.linear);
}

static cairo_bool_t
_radial_pattern_cache_entry_equal (const void *A, const void *B)
{
    const struct pattern_cache_entry *a = A, *b = B;

    if (a->key.hash != b->key.hash)
	return FALSE;

    return _cairo_radial_pattern_equal (&a->pattern.gradient.radial,
					&b->pattern.gradient.radial);
}

static void
_surface_cache_entry_destroy (void *closure)
{
    struct pattern_cache_entry *entry = closure;

    if (entry->picture->snapshot_of != NULL)
	_cairo_surface_detach_snapshot (entry->picture);
    cairo_surface_destroy (entry->picture);
    _cairo_freelist_free (&entry->screen->pattern_cache_entry_freelist, entry);
}

static void
_pattern_cache_entry_destroy (void *closure)
{
    struct pattern_cache_entry *entry = closure;

    _cairo_pattern_fini (&entry->pattern.base);
    cairo_surface_destroy (entry->picture);
    _cairo_freelist_free (&entry->screen->pattern_cache_entry_freelist, entry);
}

#if CAIRO_HAS_DRM_SURFACE && CAIRO_HAS_XCB_DRM_FUNCTIONS
#include "drm/cairo-drm-private.h"

#include <drm/drm.h>
#include <sys/ioctl.h>
#include <xcb/dri2.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

static int drm_magic (int fd, uint32_t *magic)
{
    drm_auth_t auth;

    if (ioctl (fd, DRM_IOCTL_GET_MAGIC, &auth))
	return -errno;

    *magic = auth.magic;
    return 0;
}

static cairo_device_t *
_xcb_drm_device (xcb_connection_t	*xcb_connection,
		 xcb_screen_t		*xcb_screen)
{
    cairo_device_t *device = NULL;
    xcb_dri2_connect_reply_t *connect;
    drm_magic_t magic;
    int fd;

    connect = xcb_dri2_connect_reply (xcb_connection,
				      xcb_dri2_connect (xcb_connection,
							xcb_screen->root,
							0),
				      0);
    if (connect == NULL)
	return NULL;

    fd = open (xcb_dri2_connect_device_name (connect), O_RDWR);
    free (connect);

    if (fd < 0)
	return NULL;

    device = cairo_drm_device_get_for_fd (fd);
    close (fd);

    if (device != NULL) {
	xcb_dri2_authenticate_reply_t *authenticate;

	if (drm_magic (((cairo_drm_device_t *) device)->fd, &magic) < 0) {
	    cairo_device_destroy (device);
	    return NULL;
	}

	authenticate = xcb_dri2_authenticate_reply (xcb_connection,
						    xcb_dri2_authenticate (xcb_connection,
									   xcb_screen->root,
									   magic),
						    0);
	if (authenticate == NULL) {
	    cairo_device_destroy (device);
	    return NULL;
	}

	free (authenticate);
    }

    return device;
}
#else
static cairo_device_t *
_xcb_drm_device (xcb_connection_t	*xcb_connection,
		 xcb_screen_t		*xcb_screen)
{
    return NULL;
}
#endif

cairo_xcb_screen_t *
_cairo_xcb_screen_get (xcb_connection_t *xcb_connection,
		       xcb_screen_t *xcb_screen)
{
    cairo_xcb_connection_t *connection;
    cairo_xcb_screen_t *screen;
    cairo_status_t status;
    int i;

    connection = _cairo_xcb_connection_get (xcb_connection);
    if (unlikely (connection == NULL))
	return NULL;

    CAIRO_MUTEX_LOCK (connection->screens_mutex);

    cairo_list_foreach_entry (screen,
			      cairo_xcb_screen_t,
			      &connection->screens,
			      link)
    {
	if (screen->xcb_screen == xcb_screen) {
	    /* Maintain list in MRU order */
	    if (&screen->link != connection->screens.next)
		cairo_list_move (&screen->link, &connection->screens);

	    goto unlock;
	}
    }

    screen = malloc (sizeof (cairo_xcb_screen_t));
    if (unlikely (screen == NULL))
	goto unlock;

    screen->connection = connection;
    screen->xcb_screen = xcb_screen;

    _cairo_freelist_init (&screen->pattern_cache_entry_freelist,
			  sizeof (struct pattern_cache_entry));
    cairo_list_init (&screen->link);
    cairo_list_init (&screen->surfaces);

    if (connection->flags & CAIRO_XCB_HAS_DRI2)
	screen->device = _xcb_drm_device (xcb_connection, xcb_screen);
    else
	screen->device = NULL;

    screen->gc_depths = 0;
    memset (screen->gc, 0, sizeof (screen->gc));

    screen->solid_cache_size = 0;
    for (i = 0; i < ARRAY_LENGTH (screen->stock_colors); i++)
	screen->stock_colors[i] = NULL;

    status = _cairo_cache_init (&screen->surface_pattern_cache,
				_surface_pattern_cache_entry_equal,
				NULL,
				_surface_cache_entry_destroy,
				16*1024*1024);
    if (unlikely (status))
	goto error_screen;

    status = _cairo_cache_init (&screen->linear_pattern_cache,
				_linear_pattern_cache_entry_equal,
				NULL,
				_pattern_cache_entry_destroy,
				16);
    if (unlikely (status))
	goto error_surface;

    status = _cairo_cache_init (&screen->radial_pattern_cache,
				_radial_pattern_cache_entry_equal,
				NULL,
				_pattern_cache_entry_destroy,
				4);
    if (unlikely (status))
	goto error_linear;

    cairo_list_add (&screen->link, &connection->screens);

unlock:
    CAIRO_MUTEX_UNLOCK (connection->screens_mutex);

    return screen;

error_linear:
    _cairo_cache_fini (&screen->linear_pattern_cache);
error_surface:
    _cairo_cache_fini (&screen->surface_pattern_cache);
error_screen:
    CAIRO_MUTEX_UNLOCK (connection->screens_mutex);
    cairo_device_destroy (screen->device);
    free (screen);

    return NULL;
}

static xcb_gcontext_t
_create_gc (cairo_xcb_screen_t *screen,
	    xcb_drawable_t drawable)
{
    uint32_t values[] = { 0 };

    return _cairo_xcb_connection_create_gc (screen->connection, drawable,
					    XCB_GC_GRAPHICS_EXPOSURES,
					    values);
}

xcb_gcontext_t
_cairo_xcb_screen_get_gc (cairo_xcb_screen_t *screen,
			  xcb_drawable_t drawable,
			  int depth)
{
    int i;

    assert (CAIRO_MUTEX_IS_LOCKED (screen->connection->device.mutex));

    for (i = 0; i < ARRAY_LENGTH (screen->gc); i++) {
	if (((screen->gc_depths >> (8*i)) & 0xff) == depth) {
	    screen->gc_depths &= ~(0xff << (8*i));
	    return screen->gc[i];
	}
    }

    return _create_gc (screen, drawable);
}

void
_cairo_xcb_screen_put_gc (cairo_xcb_screen_t *screen, int depth, xcb_gcontext_t gc)
{
    int i;

    assert (CAIRO_MUTEX_IS_LOCKED (screen->connection->device.mutex));

    for (i = 0; i < ARRAY_LENGTH (screen->gc); i++) {
	if (((screen->gc_depths >> (8*i)) & 0xff) == 0)
	    break;
    }

    if (i == ARRAY_LENGTH (screen->gc)) {
	/* perform random substitution to ensure fair caching over depths */
	i = rand () % ARRAY_LENGTH (screen->gc);
	_cairo_xcb_connection_free_gc (screen->connection, screen->gc[i]);
    }

    screen->gc[i] = gc;
    screen->gc_depths &= ~(0xff << (8*i));
    screen->gc_depths |= depth << (8*i);
}

cairo_status_t
_cairo_xcb_screen_store_surface_picture (cairo_xcb_screen_t *screen,
					 cairo_surface_t *picture,
					 unsigned int size)
{
    struct pattern_cache_entry *entry;
    cairo_status_t status;

    assert (CAIRO_MUTEX_IS_LOCKED (screen->connection->device.mutex));

    entry = _cairo_freelist_alloc (&screen->pattern_cache_entry_freelist);
    if (unlikely (entry == NULL))
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);

    entry->key.hash = picture->unique_id;
    entry->key.size = size;

    entry->picture = cairo_surface_reference (picture);
    entry->screen = screen;

    status = _cairo_cache_insert (&screen->surface_pattern_cache,
				  &entry->key);
    if (unlikely (status)) {
	cairo_surface_destroy (picture);
	_cairo_freelist_free (&screen->pattern_cache_entry_freelist, entry);
	return status;
    }

    return CAIRO_STATUS_SUCCESS;
}

void
_cairo_xcb_screen_remove_surface_picture (cairo_xcb_screen_t *screen,
					  cairo_surface_t *picture)
{
    struct pattern_cache_entry tmpl;
    struct pattern_cache_entry *entry;

    assert (CAIRO_MUTEX_IS_LOCKED (screen->connection->device.mutex));

    tmpl.key.hash = picture->unique_id;

    entry = _cairo_cache_lookup (&screen->surface_pattern_cache, &tmpl.key);
    if (entry != NULL)
	_cairo_cache_remove (&screen->surface_pattern_cache, &entry->key);
}

cairo_status_t
_cairo_xcb_screen_store_linear_picture (cairo_xcb_screen_t *screen,
					const cairo_linear_pattern_t *linear,
					cairo_surface_t *picture)
{
    struct pattern_cache_entry *entry;
    cairo_status_t status;

    assert (CAIRO_MUTEX_IS_LOCKED (screen->connection->device.mutex));

    entry = _cairo_freelist_alloc (&screen->pattern_cache_entry_freelist);
    if (unlikely (entry == NULL))
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);

    entry->key.hash = _cairo_linear_pattern_hash (_CAIRO_HASH_INIT_VALUE, linear);
    entry->key.size = 1;

    status = _cairo_pattern_init_copy (&entry->pattern.base, &linear->base.base);
    if (unlikely (status)) {
	_cairo_freelist_free (&screen->pattern_cache_entry_freelist, entry);
	return status;
    }

    entry->picture = cairo_surface_reference (picture);
    entry->screen = screen;

    status = _cairo_cache_insert (&screen->linear_pattern_cache,
				  &entry->key);
    if (unlikely (status)) {
	cairo_surface_destroy (picture);
	_cairo_freelist_free (&screen->pattern_cache_entry_freelist, entry);
	return status;
    }

    return CAIRO_STATUS_SUCCESS;
}

cairo_surface_t *
_cairo_xcb_screen_lookup_linear_picture (cairo_xcb_screen_t *screen,
					 const cairo_linear_pattern_t *linear)
{
    cairo_surface_t *picture = NULL;
    struct pattern_cache_entry tmpl;
    struct pattern_cache_entry *entry;

    assert (CAIRO_MUTEX_IS_LOCKED (screen->connection->device.mutex));

    tmpl.key.hash = _cairo_linear_pattern_hash (_CAIRO_HASH_INIT_VALUE, linear);
    _cairo_pattern_init_static_copy (&tmpl.pattern.base, &linear->base.base);

    entry = _cairo_cache_lookup (&screen->linear_pattern_cache, &tmpl.key);
    if (entry != NULL)
	picture = cairo_surface_reference (entry->picture);

    return picture;
}

cairo_status_t
_cairo_xcb_screen_store_radial_picture (cairo_xcb_screen_t *screen,
					const cairo_radial_pattern_t *radial,
					cairo_surface_t *picture)
{
    struct pattern_cache_entry *entry;
    cairo_status_t status;

    assert (CAIRO_MUTEX_IS_LOCKED (screen->connection->device.mutex));

    entry = _cairo_freelist_alloc (&screen->pattern_cache_entry_freelist);
    if (unlikely (entry == NULL))
	return _cairo_error (CAIRO_STATUS_NO_MEMORY);

    entry->key.hash = _cairo_radial_pattern_hash (_CAIRO_HASH_INIT_VALUE, radial);
    entry->key.size = 1;

    status = _cairo_pattern_init_copy (&entry->pattern.base, &radial->base.base);
    if (unlikely (status)) {
	_cairo_freelist_free (&screen->pattern_cache_entry_freelist, entry);
	return status;
    }

    entry->picture = cairo_surface_reference (picture);
    entry->screen = screen;

    status = _cairo_cache_insert (&screen->radial_pattern_cache, &entry->key);
    if (unlikely (status)) {
	cairo_surface_destroy (picture);
	_cairo_freelist_free (&screen->pattern_cache_entry_freelist, entry);
	return status;
    }

    return CAIRO_STATUS_SUCCESS;
}

cairo_surface_t *
_cairo_xcb_screen_lookup_radial_picture (cairo_xcb_screen_t *screen,
					 const cairo_radial_pattern_t *radial)
{
    cairo_surface_t *picture = NULL;
    struct pattern_cache_entry tmpl;
    struct pattern_cache_entry *entry;

    assert (CAIRO_MUTEX_IS_LOCKED (screen->connection->device.mutex));

    tmpl.key.hash = _cairo_radial_pattern_hash (_CAIRO_HASH_INIT_VALUE, radial);
    _cairo_pattern_init_static_copy (&tmpl.pattern.base, &radial->base.base);

    entry = _cairo_cache_lookup (&screen->radial_pattern_cache, &tmpl.key);
    if (entry != NULL)
	picture = cairo_surface_reference (entry->picture);

    return picture;
}
