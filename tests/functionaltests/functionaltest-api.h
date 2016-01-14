//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************
#pragma once

#include "Logger.h"

/////////////////////////////////////////////////////////
// TEST macro override
/////////////////////////////////////////////////////////

// 'TEST(SampleTest, Sanity)' becomes 'void SampleTestSanity()'
#ifdef TEST
#undef TEST
#endif
#define TEST(__Name1, __Name2) void __Name1##__Name2()

/////////////////////////////////////////////////////////
// Logging macros
/////////////////////////////////////////////////////////

#ifdef LOG_INFO
#undef LOG_INFO
#endif
#define LOG_INFO(__format, ...) FunctionalTestLog::LogComment(FunctionalTestLogPrivate::Format(__format, __VA_ARGS__))

#ifdef LOG_WARNING
#undef LOG_WARNING
#endif
#define LOG_WARNING(__format, ...) \
    FunctionalTestLog::LogWarning(FunctionalTestLogPrivate::Format(__format, __VA_ARGS__), __FILE__, __PRETTY_FUNCTION__, __LINE__)

#ifdef LOG_ERROR
#undef LOG_ERROR
#endif
#define LOG_ERROR(__format, ...) \
    FunctionalTestLog::LogError(FunctionalTestLogPrivate::Format(__format, __VA_ARGS__), __FILE__, __PRETTY_FUNCTION__, __LINE__)

/////////////////////////////////////////////////////////
// Assert and Verify macros override
/////////////////////////////////////////////////////////

#ifdef GTEST_SUCCESS_
#undef GTEST_SUCCESS_
#endif
#define GTEST_SUCCESS_(__message) FunctionalTestLog::LogComment((__message));

#ifdef GTEST_NONFATAL_FAILURE_
#undef GTEST_NONFATAL_FAILURE_
#endif
#define GTEST_NONFATAL_FAILURE_(__message) FunctionalTestLog::LogError((__message), __FILE__, __PRETTY_FUNCTION__, __LINE__)

#ifdef GTEST_FATAL_FAILURE_
#undef GTEST_FATAL_FAILURE_
#endif
#define GTEST_FATAL_FAILURE_(__message) FunctionalTestLog::LogErrorAndAbort((__message), __FILE__, __PRETTY_FUNCTION__, __LINE__)