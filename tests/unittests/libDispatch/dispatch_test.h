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
#pragma once

#include <TestFramework.h>
#include <windows.h>
#include <errno.h>
//#include "os_shims.h"
#include <dispatch/dispatch.h>

__DISPATCH_BEGIN_DECLS
// The dispatch test cases are open source code, and there is no as_do definition for _CPlusPlus Macro.
#define as_do(para) para

void test_start(const char* desc);
void test_stop(void);
void test_stop_after_delay(void* delay);
void test_block_until_stopped(void);
void test_unblock(void);

#define test_ptr_null(desc, val) ASSERT_TRUE_MSG((val == NULL), desc)

#define test_ptr_notnull(desc, val) ASSERT_TRUE_MSG((val != NULL), desc)

#define test_ptr(desc, actual, expected) ASSERT_EQ_MSG(actual, expected, desc)

void _test_long(const char* file, long line, const char* desc, long actual, long expected);
#define test_long(a, b, c) _test_long(__FILE__, __LINE__, a, b, c)

void _test_long_less_than(const char* file, long line, const char* desc, long actual, long max_expected);
#define test_long_less_than(a, b, c) _test_long_less_than(__FILE__, __LINE__, a, b, c)

void _test_double_less_than_or_equal(const char* file, long line, const char* desc, double val, double max_expected);
#define test_double_less_than_or_equal(d, v, m) _test_double_less_than(__FILE__, __LINE__, d, v, m)

void _test_double_less_than(const char* file, long line, const char* desc, double val, double max_expected);
#define test_double_less_than(d, v, m) _test_double_less_than(__FILE__, __LINE__, d, v, m)

__DISPATCH_END_DECLS