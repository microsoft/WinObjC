/*
 * Copyright (c) 2008-2009 Apple Inc. All rights reserved.
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

#ifndef __DISPATCH_ONCE__
#define __DISPATCH_ONCE__

#ifndef __DISPATCH_INDIRECT__
#error "Please #include <dispatch/dispatch.h> instead of this file directly."
#include <dispatch/base.h> // for HeaderDoc
#endif

__DISPATCH_BEGIN_DECLS

/*!
 * @typedef dispatch_once_t
 *
 * @abstract
 * A predicate for use with dispatch_once(). It must be initialized to zero.
 * Note: static and global variables default to zero.
 */
typedef intptr_t dispatch_once_t;

/*!
 * @function dispatch_once
 *
 * @abstract
 * Execute a block once and only once.
 *
 * @param predicate
 * A pointer to a dispatch_once_t that is used to test whether the block has
 * completed or not.
 *
 * @param block
 * The block to execute once.
 *
 * @discussion
 * Always call dispatch_once() before using or testing any variables that are
 * initialized by the block.
 */
#ifdef __BLOCKS__
__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL_ALL DISPATCH_NOTHROW
void
dispatch_once(dispatch_once_t *predicate, dispatch_block_t block);
#ifdef __GNUC__
#define dispatch_once(x, ...) do { if (__builtin_expect(*(x), ~0l) != ~0l) dispatch_once((x), (__VA_ARGS__)); } while (0)
#endif
#endif

__OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_4_0)
DISPATCH_EXPORT DISPATCH_NONNULL1 DISPATCH_NONNULL3 DISPATCH_NOTHROW
void
dispatch_once_f(dispatch_once_t *predicate, void *context, void (*function)(void *));
#ifdef __GNUC__
#define dispatch_once_f(x, y, z) do { if (__builtin_expect(*(x), ~0l) != ~0l) dispatch_once_f((x), (y), (z)); } while (0)
#endif

__DISPATCH_END_DECLS

#endif
