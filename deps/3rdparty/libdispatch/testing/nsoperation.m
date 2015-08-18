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

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <Foundation/Foundation.h>
#include <dispatch/dispatch.h>

#include "dispatch_test.h"

@interface MYOperation : NSOperation
{
}
@end

@implementation MYOperation

- (id) init
{
	self = [super init];
	return self;
}

- (void)main
{
	test_stop();
}

@end

int
main(void)
{
	test_start("NSOperation");

	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	NSOperationQueue *queue = [[[NSOperationQueue alloc] init] autorelease];
	test_ptr_notnull("NSOperationQueue", queue);
	
	MYOperation *operation = [[MYOperation alloc] init];
	test_ptr_notnull("NSOperation", operation);
	
	[queue addOperation:operation];
	[operation release];
	
	[[NSRunLoop mainRunLoop] run];
	
	[pool release];
	
	return 0;
}
