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

#include "os_shims.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
has_prefix(const char* str, const char* prefix) {
	return (strncmp(str, prefix, strlen(prefix)) == 0);
}

int
print_summary(FILE* f, long total, long pass, long fail) {
	fprintf(f, "Total:  %ld\n", total);
	fprintf(f, "Passed: %ld (%0.0lf%%)\n", pass, ((double)pass / (double)total) * (double)100.0);
	fprintf(f, "Failed: %ld (%0.0lf%%)\n", fail, ((double)fail / (double)total) * (double)100.0);
	fprintf(f, "\n");
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc > 1) {
		fprintf(stderr, "%s: usage: summarize\n", argv[0]);
		exit(1);
	}
	
	/*
	FILE* f = fopen(argv[1], "w");
	if (f == NULL) {
		perror(argv[1]);
		exit(1);
	}
	*/
	FILE* f = stdout;

	fprintf(f, "\n==================================================\n");
	fprintf(f, "[SUMMARY] Test Summary\n");
	fprintf(f, "==================================================\n\n");
	
	size_t len;
	char* ln;
	long total = 0;
	long pass = 0;
	long fail = 0;
	long total_total = 0;
	long total_pass = 0;
	long total_fail = 0;
	for(;;) {
		ln = fgetln(stdin, &len);
		//if (ln) fprintf(stdout, "%.*s", (int)len, ln);
		if (ln == NULL || has_prefix(ln, "[TEST]")) {
			if (total) {
				print_summary(f, total, pass, fail);
			}
			total_total += total;
			total_pass += pass;
			total_fail += fail;
			total = 0;
			pass = 0;
			fail = 0;
			if (ln) {
				fprintf(f, "%.*s", (int)len, ln);
			} else {
				fprintf(f, "[TOTAL]\n");
				print_summary(f, total_total, total_pass, total_fail);
				break;
			}
		} else if (has_prefix(ln, "[PASS]")) {
			++total;
			++pass;
		} else if (has_prefix(ln, "[FAIL]")) {
			++total;
			++fail;
		}
	}
	
	return (total_fail ? EXIT_FAILURE : EXIT_SUCCESS);
}
