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

#pragma once

#ifndef __DISPATCH_PUBLIC__
#define __DISPATCH_PUBLIC__

#ifdef __APPLE__
#include <Availability.h>
#include <TargetConditionals.h>
#endif

#include <stdbool.h>
#include <stdarg.h>

#if defined(__cplusplus)
#define __DISPATCH_BEGIN_DECLS extern "C" {
#define __DISPATCH_END_DECLS }
#else
#define __DISPATCH_BEGIN_DECLS
#define __DISPATCH_END_DECLS
#endif

#ifndef __OSX_AVAILABLE_STARTING
#define __OSX_AVAILABLE_STARTING(x, y)
#endif

#define DISPATCH_API_VERSION 20090501

#ifndef __DISPATCH_BUILDING_DISPATCH__

#ifndef __DISPATCH_INDIRECT__
#define __DISPATCH_INDIRECT__
#endif

#include <dispatch/base.h>
#include <dispatch/atomic.h>
#include <dispatch/object.h>
#include <dispatch/time.h>
#include <dispatch/queue.h>
#include <dispatch/source.h>
#include <dispatch/group.h>
#include <dispatch/semaphore.h>
#include <dispatch/once.h>
#include <dispatch/interop.h>

#undef __DISPATCH_INDIRECT__

#ifndef DISPATCH_QUEUE_CONCURRENT
#define DISPATCH_QUEUE_CONCURRENT NULL
#endif

#endif /* !__DISPATCH_BUILDING_DISPATCH__ */

#endif
