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
#include <sys/time.h>

#include <dispatch/dispatch.h>

#include "dispatch_test.h"

//
// There were several bugs related to sign extension / integer overflow that
// were encountered during development. Create a timer whose interval has the
// 31st bit of the word set to verify that it behaves correctly.
//
// 2 s < 0x80000000ull ns < 4 s
//

int
main(void)
{
	test_start("Dispatch Source Timer, bit 31");

	dispatch_queue_t main_q = dispatch_get_main_queue();
	test_ptr("dispatch_get_main_queue", main_q, dispatch_get_current_queue());

	dispatch_source_t timer;
	struct timeval start_time;
	
	gettimeofday(&start_time, NULL);

	timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, main_q);
	test_ptr_notnull("DISPATCH_SOURCE_TYPE_TIMER", timer);

	dispatch_source_set_timer(timer, dispatch_time(DISPATCH_TIME_NOW, 0x80000000ull), 0, 0);

	dispatch_source_set_event_handler(timer, ^{
		dispatch_source_cancel(timer);
	});

	dispatch_source_set_cancel_handler(timer, ^{
		struct timeval end_time;
		gettimeofday(&end_time, NULL);

		test_long_less_than("elapsed time < 4s", end_time.tv_sec - start_time.tv_sec, 4);
		test_long_less_than("elapsed time > 2s", 1, end_time.tv_sec - start_time.tv_sec);
		test_stop();
	});
	
	dispatch_resume(timer);
	
	dispatch_main();

	return 0;
}
