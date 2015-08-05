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

#ifndef CAIRO_DRM_INTEL_IOCTL_PRIVATE_H
#define CAIRO_DRM_INTEL_IOCTL_PRIVATE_H

#include "cairo-drm-intel-command-private.h"

#define I915_PARAM_IRQ_ACTIVE            1
#define I915_PARAM_ALLOW_BATCHBUFFER     2
#define I915_PARAM_LAST_DISPATCH         3
#define I915_PARAM_CHIPSET_ID            4
#define I915_PARAM_HAS_GEM               5
#define I915_PARAM_NUM_FENCES_AVAIL      6
#define I915_PARAM_HAS_OVERLAY           7
#define I915_PARAM_HAS_PAGEFLIPPING	 8
#define I915_PARAM_HAS_EXECBUF2          9

struct intel_getparam {
	int param;
	int *value;
};


/** @{
 * Intel memory domains
 *
 * Most of these just align with the various caches in
 * the system and are used to flush and invalidate as
 * objects end up cached in different domains.
 */
/** CPU cache */
#define I915_GEM_DOMAIN_CPU		0x00000001
/** Render cache, used by 2D and 3D drawing */
#define I915_GEM_DOMAIN_RENDER		0x00000002
/** Sampler cache, used by texture engine */
#define I915_GEM_DOMAIN_SAMPLER		0x00000004
/** Command queue, used to load batch buffers */
#define I915_GEM_DOMAIN_COMMAND		0x00000008
/** Instruction cache, used by shader programs */
#define I915_GEM_DOMAIN_INSTRUCTION	0x00000010
/** Vertex address cache */
#define I915_GEM_DOMAIN_VERTEX		0x00000020
/** GTT domain - aperture and scanout */
#define I915_GEM_DOMAIN_GTT		0x00000040
/** @} */

#define I915_TILING_NONE	0
#define I915_TILING_X		1
#define I915_TILING_Y		2

#define I915_BIT_6_SWIZZLE_NONE		0
#define I915_BIT_6_SWIZZLE_9		1
#define I915_BIT_6_SWIZZLE_9_10		2
#define I915_BIT_6_SWIZZLE_9_11		3
#define I915_BIT_6_SWIZZLE_9_10_11	4

#define DRM_I915_GEM_EXECBUFFER	0x14
#define DRM_I915_GEM_BUSY	0x17
#define DRM_I915_GEM_THROTTLE	0x18
#define DRM_I915_GEM_CREATE	0x1b
#define DRM_I915_GEM_PREAD	0x1c
#define DRM_I915_GEM_PWRITE	0x1d
#define DRM_I915_GEM_MMAP	0x1e
#define DRM_I915_GEM_SET_DOMAIN	0x1f
#define DRM_I915_GEM_SET_TILING	0x21
#define DRM_I915_GEM_GET_TILING	0x22
#define DRM_I915_GEM_GET_APERTURE 0x23
#define DRM_I915_GEM_MMAP_GTT	0x24

struct drm_i915_gem_create {
	/**
	 * Requested size for the object.
	 *
	 * The (page-aligned) allocated size for the object will be returned.
	 */
	uint64_t size;
	/**
	 * Returned handle for the object.
	 *
	 * Object handles are nonzero.
	 */
	uint32_t handle;
	uint32_t pad;
};

struct drm_i915_gem_pread {
	/** Handle for the object being read. */
	uint32_t handle;
	uint32_t pad;
	/** Offset into the object to read from */
	uint64_t offset;
	/** Length of data to read */
	uint64_t size;
	/**
	 * Pointer to write the data into.
	 *
	 * This is a fixed-size type for 32/64 compatibility.
	 */
	uint64_t data_ptr;
};

struct drm_i915_gem_pwrite {
	/** Handle for the object being written to. */
	uint32_t handle;
	uint32_t pad;
	/** Offset into the object to write to */
	uint64_t offset;
	/** Length of data to write */
	uint64_t size;
	/**
	 * Pointer to read the data from.
	 *
	 * This is a fixed-size type for 32/64 compatibility.
	 */
	uint64_t data_ptr;
};

struct drm_i915_gem_mmap {
	/** Handle for the object being mapped. */
	uint32_t handle;
	uint32_t pad;
	/** Offset in the object to map. */
	uint64_t offset;
	/**
	 * Length of data to map.
	 *
	 * The value will be page-aligned.
	 */
	uint64_t size;
	/**
	 * Returned pointer the data was mapped at.
	 *
	 * This is a fixed-size type for 32/64 compatibility.
	 */
	uint64_t addr_ptr;
};

struct drm_i915_gem_mmap_gtt {
	/** Handle for the object being mapped. */
	uint32_t handle;
	uint32_t pad;
	/**
	 * Fake offset to use for subsequent mmap call
	 *
	 * This is a fixed-size type for 32/64 compatibility.
	 */
	uint64_t offset;
};

struct drm_i915_gem_set_domain {
	/** Handle for the object */
	uint32_t handle;

	/** New read domains */
	uint32_t read_domains;

	/** New write domain */
	uint32_t write_domain;
};

struct drm_i915_gem_relocation_entry {
	/**
	 * Handle of the buffer being pointed to by this relocation entry.
	 *
	 * It's appealing to make this be an index into the mm_validate_entry
	 * list to refer to the buffer, but this allows the driver to create
	 * a relocation list for state buffers and not re-write it per
	 * exec using the buffer.
	 */
	uint32_t target_handle;

	/**
	 * Value to be added to the offset of the target buffer to make up
	 * the relocation entry.
	 */
	uint32_t delta;

	/** Offset in the buffer the relocation entry will be written into */
	uint64_t offset;

	/**
	 * Offset value of the target buffer that the relocation entry was last
	 * written as.
	 *
	 * If the buffer has the same offset as last time, we can skip syncing
	 * and writing the relocation.  This value is written back out by
	 * the execbuffer ioctl when the relocation is written.
	 */
	uint64_t presumed_offset;

	/**
	 * Target memory domains read by this operation.
	 */
	uint32_t read_domains;

	/**
	 * Target memory domains written by this operation.
	 *
	 * Note that only one domain may be written by the whole
	 * execbuffer operation, so that where there are conflicts,
	 * the application will get -EINVAL back.
	 */
	uint32_t write_domain;
};

struct drm_i915_gem_exec_object {
	/**
	 * User's handle for a buffer to be bound into the GTT for this
	 * operation.
	 */
	uint32_t handle;

	/** Number of relocations to be performed on this buffer */
	uint32_t relocation_count;
	/**
	 * Pointer to array of struct drm_i915_gem_relocation_entry containing
	 * the relocations to be performed in this buffer.
	 */
	uint64_t relocs_ptr;

	/** Required alignment in graphics aperture */
	uint64_t alignment;

	/**
	 * Returned value of the updated offset of the object, for future
	 * presumed_offset writes.
	 */
	uint64_t offset;
};

struct drm_i915_gem_execbuffer {
	/**
	 * List of buffers to be validated with their relocations to be
	 * performend on them.
	 *
	 * This is a pointer to an array of struct drm_i915_gem_validate_entry.
	 *
	 * These buffers must be listed in an order such that all relocations
	 * a buffer is performing refer to buffers that have already appeared
	 * in the validate list.
	 */
	uint64_t buffers_ptr;
	uint32_t buffer_count;

	/** Offset in the batchbuffer to start execution from. */
	uint32_t batch_start_offset;
	/** Bytes used in batchbuffer from batch_start_offset */
	uint32_t batch_len;
	uint32_t DR1;
	uint32_t DR4;
	uint32_t num_cliprects;
	/** This is a struct drm_clip_rect *cliprects */
	uint64_t cliprects_ptr;
};

struct drm_i915_gem_busy {
	/** Handle of the buffer to check for busy */
	uint32_t handle;

	/** Return busy status (1 if busy, 0 if idle) */
	uint32_t busy;
};

struct drm_i915_gem_set_tiling {
	/** Handle of the buffer to have its tiling state updated */
	uint32_t handle;

	/**
	 * Tiling mode for the object (I915_TILING_NONE, I915_TILING_X,
	 * I915_TILING_Y).
	 *
	 * This value is to be set on request, and will be updated by the
	 * kernel on successful return with the actual chosen tiling layout.
	 *
	 * The tiling mode may be demoted to I915_TILING_NONE when the system
	 * has bit 6 swizzling that can't be managed correctly by GEM.
	 *
	 * Buffer contents become undefined when changing tiling_mode.
	 */
	uint32_t tiling_mode;

	/**
	 * Stride in bytes for the object when in I915_TILING_X or
	 * I915_TILING_Y.
	 */
	uint32_t stride;

	/**
	 * Returned address bit 6 swizzling required for CPU access through
	 * mmap mapping.
	 */
	uint32_t swizzle_mode;
};

struct drm_i915_gem_get_tiling {
	/** Handle of the buffer to get tiling state for. */
	uint32_t handle;

	/**
	 * Current tiling mode for the object (I915_TILING_NONE, I915_TILING_X,
	 * I915_TILING_Y).
	 */
	uint32_t tiling_mode;

	/**
	 * Returned address bit 6 swizzling required for CPU access through
	 * mmap mapping.
	 */
	uint32_t swizzle_mode;
};

struct drm_i915_gem_get_aperture {
	/** Total size of the aperture used by i915_gem_execbuffer, in bytes */
	uint64_t aper_size;

	/**
	 * Available space in the aperture used by i915_gem_execbuffer, in
	 * bytes
	 */
	uint64_t aper_available_size;
};

#define DRM_I915_GETPARAM	0x06

#define DRM_IOCTL_I915_GETPARAM         DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GETPARAM, struct intel_getparam)
#define DRM_IOCTL_I915_GEM_EXECBUFFER	DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_EXECBUFFER, struct drm_i915_gem_execbuffer)
#define DRM_IOCTL_I915_GEM_BUSY		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_BUSY, struct drm_i915_gem_busy)
#define DRM_IOCTL_I915_GEM_THROTTLE	DRM_IO ( DRM_COMMAND_BASE + DRM_I915_GEM_THROTTLE)
#define DRM_IOCTL_I915_GEM_CREATE	DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_CREATE, struct drm_i915_gem_create)
#define DRM_IOCTL_I915_GEM_PREAD	DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_PREAD, struct drm_i915_gem_pread)
#define DRM_IOCTL_I915_GEM_PWRITE	DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_PWRITE, struct drm_i915_gem_pwrite)
#define DRM_IOCTL_I915_GEM_MMAP		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_MMAP, struct drm_i915_gem_mmap)
#define DRM_IOCTL_I915_GEM_MMAP_GTT	DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_MMAP_GTT, struct drm_i915_gem_mmap_gtt)
#define DRM_IOCTL_I915_GEM_SET_DOMAIN	DRM_IOW (DRM_COMMAND_BASE + DRM_I915_GEM_SET_DOMAIN, struct drm_i915_gem_set_domain)
#define DRM_IOCTL_I915_GEM_SET_TILING	DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_SET_TILING, struct drm_i915_gem_set_tiling)
#define DRM_IOCTL_I915_GEM_GET_TILING	DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_GET_TILING, struct drm_i915_gem_get_tiling)
#define DRM_IOCTL_I915_GEM_GET_APERTURE	DRM_IOR  (DRM_COMMAND_BASE + DRM_I915_GEM_GET_APERTURE, struct drm_i915_gem_get_aperture)

#define I915_MADV_WILLNEED	0
#define I915_MADV_DONTNEED	1

struct drm_i915_gem_madvise {
	uint32_t handle;
	uint32_t madv;
	uint32_t retained;
};
#define DRM_I915_GEM_MADVISE	0x26
#define DRM_IOCTL_I915_GEM_MADVISE	DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_MADVISE, struct drm_i915_gem_madvise)


/* XXX execbuffer2 */
struct drm_i915_gem_exec_object2 {
	/**
	 * User's handle for a buffer to be bound into the GTT for this
	 * operation.
	 */
	uint32_t handle;

	/** Number of relocations to be performed on this buffer */
	uint32_t relocation_count;
	/**
	 * Pointer to array of struct drm_i915_gem_relocation_entry containing
	 * the relocations to be performed in this buffer.
	 */
	uint64_t relocs_ptr;

	/** Required alignment in graphics aperture */
	uint64_t alignment;

	/**
	 * Returned value of the updated offset of the object, for future
	 * presumed_offset writes.
	 */
	uint64_t offset;

#define EXEC_OBJECT_NEEDS_FENCE (1<<0)
	uint64_t flags;
	uint64_t rsvd1;
	uint64_t rsvd2;
};

struct drm_i915_gem_execbuffer2 {
	/**
	 * List of gem_exec_object2 structs
	 */
	uint64_t buffers_ptr;
	uint32_t buffer_count;

	/** Offset in the batchbuffer to start execution from. */
	uint32_t batch_start_offset;
	/** Bytes used in batchbuffer from batch_start_offset */
	uint32_t batch_len;
	uint32_t DR1;
	uint32_t DR4;
	uint32_t num_cliprects;
	/** This is a struct drm_clip_rect *cliprects */
	uint64_t cliprects_ptr;
	uint64_t flags;
	uint64_t rsvd1;
	uint64_t rsvd2;
};

#define I915_GEM_3D_PIPELINE 0x1
#define I915_GEM_MEDIA_PIPELINE 0x2
#define DRM_I915_GEM_EXECBUFFER2	0x29
#define DRM_IOCTL_I915_GEM_EXECBUFFER2	DRM_IOW(DRM_COMMAND_BASE + DRM_I915_GEM_EXECBUFFER2, struct drm_i915_gem_execbuffer2)

struct drm_i915_gem_real_size {
	uint32_t handle;
	uint64_t size;
};
#define DRM_I915_GEM_REAL_SIZE	0x2a
#define DRM_IOCTL_I915_GEM_REAL_SIZE	DRM_IOWR (DRM_COMMAND_BASE + DRM_I915_GEM_REAL_SIZE, struct drm_i915_gem_real_size)

#endif /* CAIRO_DRM_INTEL_IOCTL_PRIVATE_H */
