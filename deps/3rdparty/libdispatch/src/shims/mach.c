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

#if HAVE_MACH
void *
dispatch_mach_msg_get_context(mach_msg_header_t *msg)
{
	mach_msg_context_trailer_t *tp;
	void *context = NULL;
	
	tp = (mach_msg_context_trailer_t *)((uint8_t *)msg + round_msg(msg->msgh_size));
	if (tp->msgh_trailer_size >= (mach_msg_size_t)sizeof(mach_msg_context_trailer_t)) {
		context = (void *)(uintptr_t)tp->msgh_context;
	}
	
	return context;
}

#ifndef DISPATCH_NO_LEGACY
/*
 * Raw Mach message support
 */
boolean_t
_dispatch_machport_callback(mach_msg_header_t *msg, mach_msg_header_t *reply,
  void (*callback)(mach_msg_header_t *))
{
	mig_reply_setup(msg, reply);
	((mig_reply_error_t*)reply)->RetCode = MIG_NO_REPLY;

	callback(msg);

	return TRUE;
}

/*
 * CFMachPort compatibility
 */
boolean_t
_dispatch_CFMachPortCallBack(mach_msg_header_t *msg, mach_msg_header_t *reply,
  void (*callback)(struct __CFMachPort *, void *msg, signed long size, void *))
{
	mig_reply_setup(msg, reply);
	((mig_reply_error_t*)reply)->RetCode = MIG_NO_REPLY;
	
	callback(NULL, msg, msg->msgh_size, dispatch_mach_msg_get_context(msg));

	return TRUE;
}
#endif
#endif /* HAVE_MACH */
