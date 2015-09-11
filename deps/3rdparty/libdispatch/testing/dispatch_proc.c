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
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <spawn.h>
#include <signal.h>
#include <libkern/OSAtomic.h>

#include "dispatch_test.h"

#define PID_CNT 5

static long event_cnt;

int
main(void)
{
	dispatch_source_t proc;
	int res;
	pid_t pid;

	test_start("Dispatch Proc");
	
	// Creates a process and register multiple observers.  Send a signal,
	// exit the process, etc., and verify all observers were notified.
	
	//
	// Simple child process that sleeps 2 seconds.
	//
	
	posix_spawnattr_t attr;
	res = posix_spawnattr_init(&attr);
	assert(res == 0);
	res = posix_spawnattr_setflags(&attr, POSIX_SPAWN_START_SUSPENDED);
	assert(res == 0);

	char* args[] = {
		"/bin/sleep", "2", NULL
	};
	
	res = posix_spawnp(&pid, args[0], NULL, &attr, args, NULL);
	if (res < 0) {
		perror(args[0]);
		exit(127);
	}

	res = posix_spawnattr_destroy(&attr);
	assert(res == 0);

	dispatch_queue_t completion = dispatch_queue_create("completion", NULL);
	
	assert(pid > 0);

	//
	// Suspend the "completion" queue when each observer is created.
	// Each observer resumes the queue when the child process exits.
	// If the queue is resumed too few times (indicating that not all
	// observers received the exit event) then the test case will not exit
	// within the alloted time and result in failure.
	//
	
	int i;
	for (i = 0; i < PID_CNT; ++i) {
		dispatch_suspend(completion);
		proc = dispatch_source_create(DISPATCH_SOURCE_TYPE_PROC, pid, DISPATCH_PROC_EXIT, dispatch_get_main_queue());
		test_ptr_notnull("DISPATCH_SOURCE_TYPE_PROC", proc);

		dispatch_source_set_event_handler(proc, ^{
			long flags = dispatch_source_get_data(proc);
			test_long("DISPATCH_PROC_EXIT", flags, DISPATCH_PROC_EXIT);
			event_cnt++;
			dispatch_release(proc);
			dispatch_resume(completion);
		});

		dispatch_resume(proc);
	}


	//
	// The completion block will be pending on the completion queue until it
	// has been fully resumed, at which point the test will exit successfully.
	//

	dispatch_async(completion, ^{
		int status;
		int res2 = waitpid(pid, &status, 0);
		assert(res2 != -1);
		test_long("Sub-process exited", WEXITSTATUS(status) | WTERMSIG(status), 0);
		test_long("Event count", event_cnt, PID_CNT);
		test_stop();
	});

	kill(pid, SIGCONT);

	dispatch_main();

	return 0;
}
