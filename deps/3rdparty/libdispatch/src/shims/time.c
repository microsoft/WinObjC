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

#include "../internal.h"

#if !(defined(__i386__) || defined(__x86_64__)) || !HAVE_MACH_ABSOLUTE_TIME
_dispatch_host_time_data_s _dispatch_host_time_data;

void
_dispatch_get_host_time_init(void *context DISPATCH_UNUSED)
{
#if HAVE_MACH_ABSOLUTE_TIME
	mach_timebase_info_data_t tbi;
	(void)dispatch_assume_zero(mach_timebase_info(&tbi));
	_dispatch_host_time_data.frac = tbi.numer;
	_dispatch_host_time_data.frac /= tbi.denom;
	_dispatch_host_time_data.ratio_1_to_1 = (tbi.numer == tbi.denom);
#elif TARGET_OS_WIN32
	LARGE_INTEGER freq;
	dispatch_assume(QueryPerformanceFrequency(&freq));
	_dispatch_host_time_data.frac = (long double)NSEC_PER_SEC / (long double)freq.QuadPart;
	_dispatch_host_time_data.ratio_1_to_1 = (freq.QuadPart == NSEC_PER_SEC);
#else // TARGET_OS_WIN32 
	_dispatch_host_time_data.frac = 1.0;
	_dispatch_host_time_data.ratio_1_to_1 = 1;
#endif
}

#endif
