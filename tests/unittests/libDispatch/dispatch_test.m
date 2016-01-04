//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// Copyright (c) 2008-2009 Apple Inc. All rights reserved.
//
// @APPLE_APACHE_LICENSE_HEADER_START@
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// @APPLE_APACHE_LICENSE_HEADER_END@
//
//******************************************************************************

#include <TestFramework.h>
#include "dispatch_test.h"

#include <sys/types.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

#include <string.h>
#include <windows.h>
#import <UIKit/UIKit.h>

UIKIT_EXPORT void UIShutdown();

static int _exitcode = 0;

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4127) // conditional expression is constant
#pragma warning(disable : 4130) // '==' : logical operation on address of string constant
#endif

#define _test_print(_file, _line, _desc, _expr, _fmt1, _val1, _fmt2, _val2)   \
    do {                                                                      \
        const char* _exprstr = _expr ? "PASS" : "FAIL";                       \
        char _linestr[BUFSIZ];                                                \
        if (!_expr) {                                                         \
            _exitcode = 1;                                                    \
            _snprintf(_linestr, sizeof(_linestr), " (%s:%ld)", _file, _line); \
        } else {                                                              \
            _linestr[0] = 0;                                                  \
        }                                                                     \
        if (_fmt2 == 0) {                                                     \
            LOG_INFO("\tValue: " _fmt1                                        \
                     "\n"                                                     \
                     "[%s] %s%s\n",                                           \
                     _val1,                                                   \
                     _exprstr,                                                \
                     _desc,                                                   \
                     _linestr);                                               \
        } else {                                                              \
            LOG_INFO("\tActual: " _fmt1                                       \
                     "\n"                                                     \
                     "\tExpected: " _fmt2                                     \
                     "\n"                                                     \
                     "[%s] %s%s\n",                                           \
                     _val1,                                                   \
                     _val2,                                                   \
                     _exprstr,                                                \
                     _desc,                                                   \
                     _linestr);                                               \
        }                                                                     \
        if (!_expr) {                                                         \
            LOG_INFO("\t%s:%ld", _file, _line);                               \
        }                                                                     \
        fflush(stdout);                                                       \
    } while (0)

void test_start(const char* desc) {
    LOG_INFO("\n==================================================");
    LOG_INFO("[TEST] %s", desc);
    LOG_INFO("[PID] %d", GetCurrentProcessId());
    LOG_INFO("==================================================\n");
}

#define test_ptr_null(a, b) _test_ptr_null(__FILE__, __LINE__, a, b)
void _test_ptr_null(const char* file, long line, const char* desc, const void* ptr) {
    _test_print(file, line, desc, (ptr == NULL), "%p", ptr, "%p", (void*)0);
}

#define test_ptr_notnull(a, b) _test_ptr_notnull(__FILE__, __LINE__, a, b)
void _test_ptr_notnull(const char* file, long line, const char* desc, const void* ptr) {
    _test_print(file, line, desc, (ptr != NULL), "%p", ptr, "%p", ptr ? ptr : (void*)~(size_t)0);
}

#define test_ptr(a, b, c) _test_ptr(__FILE__, __LINE__, a, b, c)
void _test_ptr(const char* file, long line, const char* desc, const void* actual, const void* expected) {
    _test_print(file, line, desc, (actual == expected), "%p", actual, "%p", expected);
}

#define test_long(a, b, c) _test_long(__FILE__, __LINE__, a, b, c)
void _test_long(const char* file, long line, const char* desc, long actual, long expected) {
    _test_print(file, line, desc, (actual == expected), "%ld", actual, "%ld", expected);
}

#define test_long_less_than(a, b, c) _test_long_less_than(__FILE__, __LINE__, a, b, c)
void _test_long_less_than(const char* file, long line, const char* desc, long actual, long expected_max) {
    _test_print(file, line, desc, (actual < expected_max), "%ld", actual, "<%ld", expected_max);
}

#define test_time_less_than(a, b, c) _test_time_less_than(__FILE__, __LINE__, a, b, c)
void _test_time_less_than(const char* file, long line, const char* desc, dispatch_time_t actual, dispatch_time_t expected_max) {
    _test_print(file, line, desc, (actual < expected_max), "%I64u", actual, "<%I64u", expected_max);
}

#define test_double_less_than(d, v, m) _test_double_less_than(__FILE__, __LINE__, d, v, m)
void _test_double_less_than(const char* file, long line, const char* desc, double val, double max_expected) {
    _test_print(file, line, desc, (val < max_expected), "%f", val, "<%f", max_expected);
}

#define test_double_less_than_or_equal(d, v, m) _test_double_less_than(__FILE__, __LINE__, d, v, m)
void _test_double_less_than_or_equal(const char* file, long line, const char* desc, double val, double max_expected) {
    _test_print(file, line, desc, (val <= max_expected), "%f", val, "<%f", max_expected);
}

#define test_errno(a, b, c) _test_errno(__FILE__, __LINE__, a, b, c)
void _test_errno(const char* file, long line, const char* desc, long actual, long expected) {
    char* actual_str = (char*)malloc(256);
    char* expected_str = (char*)malloc(256);
    _snprintf(actual_str, 256, "%ld\t%s", actual, actual ? strerror(actual) : "");
    _snprintf(expected_str, 256, "%ld\t%s", expected, expected ? strerror(expected) : "");
    _test_print(file, line, desc, (actual == expected), "%s", actual_str, "%s", expected_str);
    free(actual_str);
    free(expected_str);
}

void test_stop(void) {
    test_stop_after_delay((void*)(intptr_t)0);
}

void test_stop_after_delay(void* delay) {
#if HAVE_LEAKS
    int res;
    pid_t pid;
    char pidstr[10];
#endif

    if (delay != NULL) {
        Sleep((DWORD)(SIZE_T)delay * 1000);
    }

#if HAVE_LEAKS
    if (getenv("NOLEAKS"))
        _exit(EXIT_SUCCESS);

    /* leaks doesn't work against debug variant malloc */
    if (getenv("DYLD_IMAGE_SUFFIX"))
        _exit(EXIT_SUCCESS);

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
    UIShutdown();
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif
