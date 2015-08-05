/* Cairo - a vector graphics library with display and print output
 *
 * Copyright © 2009 Chris Wilson
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
 */

#include "cairoint.h"

#include "cairo-drm-private.h"
#include "cairo-drm-radeon-private.h"
#include "cairo-drm-ioctl-private.h"

#include "cairo-error-private.h"

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <errno.h>

#define DRM_RADEON_GEM_INFO		0x1c
#define DRM_RADEON_GEM_CREATE		0x1d
#define DRM_RADEON_GEM_MMAP		0x1e
#define DRM_RADEON_GEM_PREAD		0x21
#define DRM_RADEON_GEM_PWRITE		0x22
#define DRM_RADEON_GEM_SET_DOMAIN	0x23
#define DRM_RADEON_GEM_WAIT_IDLE	0x24
#define DRM_RADEON_CS			0x26
#define DRM_RADEON_INFO			0x27

#define DRM_IOCTL_RADEON_GEM_INFO   DRM_IOWR(DRM_COMMAND_BASE + DRM_RADEON_GEM_INFO, struct drm_radeon_gem_info)
#define DRM_IOCTL_RADEON_GEM_CREATE   DRM_IOWR(DRM_COMMAND_BASE + DRM_RADEON_GEM_CREATE, struct drm_radeon_gem_create)
#define DRM_IOCTL_RADEON_GEM_WAIT_IDLE   DRM_IOW(DRM_COMMAND_BASE + DRM_RADEON_GEM_WAIT_IDLE, struct drm_radeon_gem_wait_idle)
#define DRM_IOCTL_RADEON_GEM_MMAP   DRM_IOWR(DRM_COMMAND_BASE + DRM_RADEON_GEM_MMAP, struct drm_radeon_gem_mmap)
#define DRM_IOCTL_RADEON_GEM_PREAD   DRM_IOWR(DRM_COMMAND_BASE + DRM_RADEON_GEM_PREAD, struct drm_radeon_gem_pread)
#define DRM_IOCTL_RADEON_GEM_PWRITE   DRM_IOWR(DRM_COMMAND_BASE + DRM_RADEON_GEM_PWRITE, struct drm_radeon_gem_pwrite)
#define DRM_IOCTL_RADEON_GEM_SET_DOMAIN  DRM_IOWR(DRM_COMMAND_BASE + DRM_RADEON_GEM_SET_DOMAIN, struct drm_radeon_gem_set_domain)
//#define DRM_IOCTL_RADEON_CS DRM_IOWR(DRM_COMMAND_BASE + DRM_RADEON_CS, struct drm_radeon_cs)

struct drm_radeon_gem_info {
    uint64_t	gart_size;
    uint64_t	vram_size;
    uint64_t	vram_visible;
};

#define RADEON_GEM_NO_BACKING_STORE 1

struct drm_radeon_gem_create {
    uint64_t	size;
    uint64_t	alignment;
    uint32_t	handle;
    uint32_t	initial_domain;
    uint32_t	flags;
};

struct drm_radeon_gem_mmap {
    uint32_t	handle;
    uint32_t	pad;
    uint64_t	offset;
    uint64_t	size;
    uint64_t	addr_ptr;
};

struct drm_radeon_gem_set_domain {
    uint32_t	handle;
    uint32_t	read_domains;
    uint32_t	write_domain;
};

struct drm_radeon_gem_wait_idle {
    uint32_t	handle;
    uint32_t	pad;
};

struct drm_radeon_gem_busy {
    uint32_t	handle;
    uint32_t	busy;
};

struct drm_radeon_gem_pread {
    /** Handle for the object being read. */
    uint32_t handle;
    uint32_t pad;
    /** Offset into the object to read from */
    uint64_t offset;
    /** Length of data to read */
    uint64_t size;
    /** Pointer to write the data into. */
    /* void *, but pointers are not 32/64 compatible */
    uint64_t data_ptr;
};

struct drm_radeon_gem_pwrite {
    /** Handle for the object being written to. */
    uint32_t handle;
    uint32_t pad;
    /** Offset into the object to write to */
    uint64_t offset;
    /** Length of data to write */
    uint64_t size;
    /** Pointer to read the data from. */
    /* void *, but pointers are not 32/64 compatible */
    uint64_t data_ptr;
};

#define RADEON_CHUNK_ID_RELOCS	0x01
#define RADEON_CHUNK_ID_IB	0x02

struct drm_radeon_cs_chunk {
    uint32_t		chunk_id;
    uint32_t		length_dw;
    uint64_t		chunk_data;
};

struct drm_radeon_cs_reloc {
    uint32_t		handle;
    uint32_t		read_domains;
    uint32_t		write_domain;
    uint32_t		flags;
};

struct drm_radeon_cs {
    uint32_t		num_chunks;
    uint32_t		cs_id;
    /* this points to uint64_t * which point to cs chunks */
    uint64_t		chunks;
    /* updates to the limits after this CS ioctl */
    uint64_t		gart_limit;
    uint64_t		vram_limit;
};

#define RADEON_INFO_DEVICE_ID		0x00
#define RADEON_INFO_NUM_GB_PIPES	0x01

struct drm_radeon_info {
    uint32_t		request;
    uint32_t		pad;
    uint64_t		value;
};


cairo_bool_t
radeon_info (int fd,
             uint64_t *gart_size,
	     uint64_t *vram_size)
{
    struct drm_radeon_gem_info info;
    int ret;

    ret = ioctl (fd, DRM_IOCTL_RADEON_GEM_INFO, &info);
    if (ret == -1)
	return FALSE;

    if (gart_size != NULL)
	*gart_size = info.gart_size;

    if (vram_size != NULL)
	*vram_size = info.vram_size;

    return TRUE;
}

void
radeon_bo_write (const radeon_device_t *device,
	         radeon_bo_t *bo,
		 unsigned long offset,
		 unsigned long size,
		 const void *data)
{
    struct drm_radeon_gem_pwrite pwrite;
    int ret;

    memset (&pwrite, 0, sizeof (pwrite));
    pwrite.handle = bo->base.handle;
    pwrite.offset = offset;
    pwrite.size = size;
    pwrite.data_ptr = (uint64_t) (uintptr_t) data;
    do {
	ret = ioctl (device->base.fd, DRM_IOCTL_RADEON_GEM_PWRITE, &pwrite);
    } while (ret == -1 && errno == EINTR);

    /* XXX temporary workaround */
    if (ret == -1 && errno == ENOSYS) {
	uint8_t *ptr;

	ptr = radeon_bo_map (device, bo);
	if (ptr != NULL) {
	    memcpy (ptr + offset, data, size);
	    radeon_bo_unmap (bo);
	}
    }
}

void
radeon_bo_read (const radeon_device_t *device,
	        radeon_bo_t *bo,
	        unsigned long offset,
		unsigned long size,
		void *data)
{
    struct drm_radeon_gem_pread pread;
    int ret;

    memset (&pread, 0, sizeof (pread));
    pread.handle = bo->base.handle;
    pread.offset = offset;
    pread.size = size;
    pread.data_ptr = (uint64_t) (uintptr_t) data;
    do {
	ret = ioctl (device->base.fd, DRM_IOCTL_RADEON_GEM_PREAD, &pread);
    } while (ret == -1 && errno == EINTR);

    /* XXX temporary workaround */
    if (ret == -1 && errno == ENOSYS) {
	uint8_t *ptr;

	ptr = radeon_bo_map (device, bo);
	if (ptr != NULL) {
	    memcpy (data, ptr + offset, size);
	    radeon_bo_unmap (bo);
	}
    }

    VG (VALGRIND_MAKE_MEM_DEFINED (data, size));
}

void
radeon_bo_wait (const radeon_device_t *device, radeon_bo_t *bo)
{
    struct drm_radeon_gem_wait_idle wait;
    int ret;

    wait.handle = bo->base.handle;
    do {
	ret = ioctl (device->base.fd, DRM_IOCTL_RADEON_GEM_WAIT_IDLE, &wait);
    } while (ret == -1 && (errno == EINTR || errno == EBUSY));
}

void *
radeon_bo_map (const radeon_device_t *device, radeon_bo_t *bo)
{
    struct drm_radeon_gem_mmap mmap_arg;
    void *ptr;
    int ret;

    assert (bo->virtual == NULL);

    memset (&mmap_arg, 0, sizeof (mmap_arg));
    mmap_arg.handle = bo->base.handle;
    mmap_arg.offset = 0;
    mmap_arg.size = bo->base.size;

    do {
	ret = ioctl (device->base.fd, DRM_IOCTL_RADEON_GEM_MMAP, &mmap_arg);
    } while (ret == -1 && errno == EINTR);
    if (unlikely (ret != 0)) {
	_cairo_error_throw (CAIRO_STATUS_NO_MEMORY);
	return NULL;
    }

    VG (VALGRIND_MAKE_MEM_DEFINED (&mmap_arg, sizeof (mmap_arg)));

    /* and mmap it */
    ptr = mmap (0, bo->base.size, PROT_READ | PROT_WRITE,
		MAP_SHARED, device->base.fd,
		mmap_arg.addr_ptr);
    if (unlikely (ptr == MAP_FAILED)) {
	_cairo_error_throw (CAIRO_STATUS_NO_MEMORY);
	return NULL;
    }

    bo->virtual = ptr;

    /* XXX set_domain? */
    return bo->virtual;
}

void
radeon_bo_unmap (radeon_bo_t *bo)
{
    assert (bo->virtual != NULL);

    munmap (bo->virtual, bo->base.size);
    bo->virtual = NULL;
}

cairo_drm_bo_t *
radeon_bo_create (radeon_device_t *device,
		  uint32_t size,
		  uint32_t initial_domain)
{
    struct drm_radeon_gem_create create;
    radeon_bo_t *bo;
    int ret;

    bo = _cairo_freepool_alloc (&device->bo_pool);
    if (unlikely (bo == NULL))
	return NULL;

    create.size = size;
    create.alignment = 0;
    create.initial_domain = initial_domain;
    create.flags = 0;
    create.handle = 0;

    do {
	ret = ioctl (device->base.fd, DRM_IOCTL_RADEON_GEM_CREATE, &create);
    } while (ret == -1 && errno == EINTR);
    if (ret == -1) {
	_cairo_freepool_free (&device->bo_pool, bo);
	return NULL;
    }

    bo->base.handle = create.handle;
    bo->base.size = size;

    bo->virtual = NULL;

    bo->in_batch = FALSE;
    bo->read_domains = 0;
    bo->write_domain = 0;

    CAIRO_REFERENCE_COUNT_INIT (&bo->base.ref_count, 1);
    return &bo->base;
}

cairo_drm_bo_t *
radeon_bo_create_for_name (radeon_device_t *device,
			   uint32_t name)
{
    radeon_bo_t *bo;
    cairo_status_t status;

    bo = _cairo_freepool_alloc (&device->bo_pool);
    if (unlikely (bo == NULL))
	return NULL;

    status = _cairo_drm_bo_open_for_name (&device->base, &bo->base, name);
    if (unlikely (status)) {
	_cairo_freepool_free (&device->bo_pool, bo);
	return NULL;
    }

    bo->virtual = NULL;

    bo->in_batch = FALSE;
    bo->read_domains = 0;
    bo->write_domain = 0;

    CAIRO_REFERENCE_COUNT_INIT (&bo->base.ref_count, 1);
    return &bo->base;
}

static void
radeon_bo_release (void *_dev, void *_bo)
{
    radeon_device_t *device = _dev;
    radeon_bo_t *bo = _bo;

    _cairo_drm_bo_close (&device->base, &bo->base);
    _cairo_freepool_free (&device->bo_pool, bo);
}

cairo_surface_t *
radeon_bo_get_image (const radeon_device_t *device,
	             radeon_bo_t *bo,
		     const cairo_drm_surface_t *surface)
{
    cairo_image_surface_t *image;
    uint8_t *dst;
    int size, row;

    image = (cairo_image_surface_t *)
	cairo_image_surface_create (surface->format,
				    surface->width,
				    surface->height);
    if (unlikely (image->base.status))
	return &image->base;

    if (image->stride == surface->stride) {
	size = surface->stride * surface->height;
	radeon_bo_read (device, bo, 0, size, image->data);
    } else {
	int offset;

	size = surface->width;
	if (surface->format != CAIRO_FORMAT_A8)
	    size *= 4;

	offset = 0;
	row = surface->height;
	dst = image->data;
	while (row--) {
	    radeon_bo_read (device, bo, offset, size, dst);
	    offset += surface->stride;
	    dst += image->stride;
	}
    }

    return &image->base;
}

static void
_radeon_device_init_bo_cache (radeon_device_t *device)
{
    _cairo_freepool_init (&device->bo_pool, sizeof (radeon_bo_t));
}

cairo_status_t
radeon_device_init (radeon_device_t *device, int fd)
{
    _radeon_device_init_bo_cache (device);

    device->base.bo.release = radeon_bo_release;

    return CAIRO_STATUS_SUCCESS;
}

static void
_radeon_bo_cache_fini (radeon_device_t *device)
{
    _cairo_freepool_fini (&device->bo_pool);
}

void
radeon_device_fini (radeon_device_t *device)
{
    _radeon_bo_cache_fini (device);
    _cairo_drm_device_fini (&device->base);
}
