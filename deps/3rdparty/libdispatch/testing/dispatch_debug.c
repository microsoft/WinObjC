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

#include "config/config.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <dispatch/dispatch.h>

#include "dispatch_test.h"

int
main(void)
{
	test_start("Dispatch Debug");

	dispatch_queue_t main_q = dispatch_get_main_queue();
	dispatch_debug(main_q, "dispatch_queue_t");
	
	dispatch_queue_t default_q = dispatch_get_global_queue(0, 0);
	dispatch_debug(default_q, "dispatch_queue_t");
	
	dispatch_source_t s = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, main_q);
	dispatch_debug(s, "dispatch_source_t");

	dispatch_group_t g = dispatch_group_create();
	dispatch_debug(g, "dispatch_group_t");

	return 0;
}
