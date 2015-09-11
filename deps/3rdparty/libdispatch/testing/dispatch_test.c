#include "config/config.h"

#include <sys/types.h>
#include <sys/wait.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/errno.h>
#include <string.h>

#include "dispatch_test.h"

#define _test_print(_file, _line, _desc, \
	_expr, _fmt1, _val1, _fmt2, _val2) do { \
	const char* _exprstr = _expr ? "PASS" : "FAIL"; \
	char _linestr[BUFSIZ]; \
	if (!_expr) { \
		snprintf(_linestr, sizeof(_linestr), \
			" (%s:%ld)", _file, _line); \
	} else { \
		_linestr[0] = 0; \
	} \
	if (_fmt2 == 0) { \
		printf("\tValue: " _fmt1 "\n"		\
			"[%s] %s%s\n",			\
			_val1,				\
			_exprstr,			\
			_desc,				\
			_linestr); 			\
	} else { \
		printf("\tActual: " _fmt1 "\n"	   \
			"\tExpected: " _fmt2 "\n"  \
			"[%s] %s%s\n",		   \
			_val1,			   \
			_val2,			   \
			_exprstr,		   \
			_desc,			   \
			_linestr);		   \
	} \
	if (!_expr) { \
		printf("\t%s:%ld\n", _file, _line); \
	} \
	fflush(stdout); \
} while (0);

void
test_start(const char* desc) {
	printf("\n==================================================\n");
	printf("[TEST] %s\n", desc);
	printf("[PID] %d\n", getpid());
	printf("==================================================\n\n");
	usleep(100000);	// give 'gdb --waitfor=' a chance to find this proc
}

#define test_ptr_null(a,b) _test_ptr_null(__FILE__, __LINE__, a, b)
void
_test_ptr_null(const char* file, long line, const char* desc, const void* ptr) {
	_test_print(file, line, desc,
		(ptr == NULL), "%p", ptr, "%p", (void*)0);
}

#define test_ptr_notnull(a,b) _test_ptr_notnull(__FILE__, __LINE__, a, b)
void
_test_ptr_notnull(const char* file, long line, const char* desc, const void* ptr) {
	_test_print(file, line, desc,
		(ptr != NULL), "%p", ptr, "%p", ptr ?: (void*)~0);
}

#define test_ptr(a,b,c) _test_ptr(__FILE__, __LINE__, a, b, c)
void
_test_ptr(const char* file, long line, const char* desc, const void* actual, const void* expected) {
	_test_print(file, line, desc,
		(actual == expected), "%p", actual, "%p", expected);
}

#define test_long(a,b,c) _test_long(__FILE__, __LINE__, a, b, c)
void
_test_long(const char* file, long line, const char* desc, long actual, long expected) {
	_test_print(file, line, desc,
		(actual == expected), "%ld", actual, "%ld", expected);
}

#define test_long_less_than(a, b, c) _test_long_less_than(__FILE__, __LINE__, a, b, c)
void
_test_long_less_than(const char* file, long line, const char* desc, long actual, long expected_max) {
	_test_print(file, line, desc, (actual < expected_max), "%ld", actual, "<%ld", expected_max);
}

#define test_double_less_than(d, v, m) _test_double_less_than(__FILE__, __LINE__, d, v, m)
void
_test_double_less_than(const char* file, long line, const char* desc, double val, double max_expected) {
	_test_print(file, line, desc, (val < max_expected), "%f", val, "<%f", max_expected);
}

#define test_double_less_than_or_equal(d, v, m) _test_double_less_than(__FILE__, __LINE__, d, v, m)
void
_test_double_less_than_or_equal(const char* file, long line, const char* desc, double val, double max_expected) {
	_test_print(file, line, desc, (val <= max_expected), "%f", val, "<%f", max_expected);
}

#define test_errno(a,b,c) _test_errno(__FILE__, __LINE__, a, b, c)
void
_test_errno(const char* file, long line, const char* desc, long actual, long expected) {
	char* actual_str;
	char* expected_str;
	asprintf(&actual_str, "%ld\t%s", actual, actual ? strerror(actual) : "");
	asprintf(&expected_str, "%ld\t%s", expected, expected ? strerror(expected) : "");
	_test_print(file, line, desc,
		(actual == expected), "%s", actual_str, "%s", expected_str);
	free(actual_str);
	free(expected_str);
}

#include <spawn.h>

extern char **environ;

void
test_stop(void) {
	test_stop_after_delay((void *)(intptr_t)0);
}

void
test_stop_after_delay(void *delay) {
#if HAVE_LEAKS
	int res;
	pid_t pid;
	char pidstr[10];
#endif

	if (delay != NULL) {
		sleep((int)(intptr_t)delay);
	}

#if HAVE_LEAKS
	if (getenv("NOLEAKS")) _exit(EXIT_SUCCESS);

	/* leaks doesn't work against debug variant malloc */
	if (getenv("DYLD_IMAGE_SUFFIX")) _exit(EXIT_SUCCESS);
	
	snprintf(pidstr, sizeof(pidstr), "%d", getpid());
	char* args[] = { "./leaks-wrapper", pidstr, NULL };
	res = posix_spawnp(&pid, args[0], NULL, NULL, args, environ);
	if (res == 0 && pid > 0) {
		int status;
		waitpid(pid, &status, 0);
		test_long("Leaks", status, 0);
	} else {
		perror(args[0]);
	}
#endif
	_exit(EXIT_SUCCESS);
}
