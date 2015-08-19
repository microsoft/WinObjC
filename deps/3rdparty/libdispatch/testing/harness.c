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
#include <assert.h>
#include <spawn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <mach/clock_types.h>

#include "dispatch_test.h"

extern char **environ;

int
main(int argc, char *argv[])
{
	dispatch_source_t proc;
	dispatch_source_t sig;
	int res;
	pid_t pid;

	if (argc < 2) {
		fprintf(stderr, "usage: harness [...]\n");
		exit(1);
	}

	//
	// Start the test in a suspended state.  Will send SIGCONT once ready.
	//

	posix_spawnattr_t attr;
	res = posix_spawnattr_init(&attr);
	assert(res == 0);
	res = posix_spawnattr_setflags(&attr, POSIX_SPAWN_START_SUSPENDED);
	assert(res == 0);

	int i;
	char** newargv = calloc(argc, sizeof(void*));
	for (i = 1; i < argc; ++i) {
		newargv[i-1] = argv[i];
	}
	newargv[i-1] = NULL;

	res = posix_spawnp(&pid, newargv[0], NULL, &attr, newargv, environ);
	if (res) {
		errno = res;
		perror(newargv[0]);
		exit(EXIT_FAILURE);
	}
	//fprintf(stderr, "pid = %d\n", pid);
	assert(pid > 0);

	//
	// Monitor the test process exit status.
	//

	dispatch_queue_t main_q = dispatch_get_main_queue();

	proc = dispatch_source_create(DISPATCH_SOURCE_TYPE_PROC, pid, DISPATCH_PROC_EXIT, main_q);
	assert(proc);
	
	dispatch_source_set_event_handler(proc, ^{
		int status;
		int res2 = waitpid(pid, &status, 0);
		assert(res2 != -1);
		test_long("Process exited", WEXITSTATUS(status) | WTERMSIG(status), 0);
		exit(0);
	});
	
	dispatch_resume(proc);
	
	//
	// Forcibly stop currently running test after 30 second timeout.
	//

	uint64_t timeout = 30LL * NSEC_PER_SEC;

	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, timeout), main_q, ^{
		kill(pid, SIGKILL);
		fprintf(stderr, "Terminating unresponsive process (%0.1lfs)\n", (double)timeout/NSEC_PER_SEC);
	});

	//
	// Control-c forcibly stops currently running test.
	//

	// Ignore the default signal handler so that dispatch can handle it.
	signal(SIGINT, SIG_IGN);

	sig = dispatch_source_create(DISPATCH_SOURCE_TYPE_SIGNAL, SIGINT, 0, main_q);
	assert(sig);

	dispatch_source_set_event_handler(sig, ^{
		fprintf(stderr, "Terminating process due to signal\n");
		kill(pid, SIGKILL);
	});
	dispatch_resume(sig);

	//
	// Start the test.
	//

	kill(pid, SIGCONT);

	dispatch_main();

	return 0;
}
