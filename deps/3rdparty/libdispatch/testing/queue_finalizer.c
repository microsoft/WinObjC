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

#include <dispatch/dispatch.h>

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "dispatch_test.h"

void *ctxt_magic;

static void
finalizer(void *ctxt)
{
	test_ptr("finalizer ran", ctxt, ctxt_magic);
	test_stop();
}

int
main(void) {
	test_start("Dispatch Queue Finalizer");

#ifdef __LP64__
	ctxt_magic = (void*)((uintptr_t)arc4random() << 32 | arc4random());
#else
	ctxt_magic = (void*)arc4random();
#endif

	dispatch_queue_t q = dispatch_queue_create(NULL, NULL);
	test_ptr_notnull("dispatch_queue_new", q);

	dispatch_set_context(q, ctxt_magic);

	dispatch_set_finalizer_f(q, finalizer);
	
	dispatch_release(q);

	dispatch_main();
	
	return 0;
}
