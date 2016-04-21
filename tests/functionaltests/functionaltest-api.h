//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#define LOG_INFO(__format, ...) FunctionalTestLog::LogComment(GTestLogPrivate::Format(__format, __VA_ARGS__).data())

#ifdef LOG_WARNING
#undef LOG_WARNING
#endif
#define LOG_WARNING(__format, ...) \
    FunctionalTestLog::LogWarning(GTestLogPrivate::Format(__format, __VA_ARGS__).data(), __FILE__, __PRETTY_FUNCTION__, __LINE__)

#ifdef LOG_ERROR
#undef LOG_ERROR
#endif
#define LOG_ERROR(__format, ...) \
    FunctionalTestLog::LogError(GTestLogPrivate::Format(__format, __VA_ARGS__).data(), __FILE__, __PRETTY_FUNCTION__, __LINE__)

/////////////////////////////////////////////////////////
// Assert and Verify macros override
/////////////////////////////////////////////////////////

#ifdef GTEST_SUCCESS_
#undef GTEST_SUCCESS_
#endif
#define GTEST_SUCCESS_(__message) FunctionalTestLog::LogComment((__message))

#ifdef GTEST_NONFATAL_FAILURE_
#undef GTEST_NONFATAL_FAILURE_
#endif
#define GTEST_NONFATAL_FAILURE_(__message) FunctionalTestLog::LogError((__message), __FILE__, __PRETTY_FUNCTION__, __LINE__)

#ifdef GTEST_FATAL_FAILURE_
#undef GTEST_FATAL_FAILURE_
#endif
#define GTEST_FATAL_FAILURE_(__message) FunctionalTestLog::LogErrorAndAbort((__message), __FILE__, __PRETTY_FUNCTION__, __LINE__)

// TODO::
// todo-nithishm-04182016 - Investigate a better way to support ASSERT_*_MSG and EXPECT_*_MSG macros without re-defining them
// here. Bug 7244185 is tracking this work.

/////////////////////////////////////////////////////////
// Assert macros (terminates the test on failure)
/////////////////////////////////////////////////////////

#ifdef ASSERT_TRUE_MSG
#undef ASSERT_TRUE_MSG
#endif
#define ASSERT_TRUE_MSG(condition, format, ...)                                      \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_TRUE(condition);

#ifdef ASSERT_FALSE_MSG
#undef ASSERT_FALSE_MSG
#endif
#define ASSERT_FALSE_MSG(condition, format, ...)                                     \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_FALSE(condition);

#ifdef ASSERT_EQ_MSG
#undef ASSERT_EQ_MSG
#endif
#define ASSERT_EQ_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_EQ(val1, val2);

#ifdef ASSERT_NE_MSG
#undef ASSERT_NE_MSG
#endif
#define ASSERT_NE_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_NE(val1, val2);

#ifdef ASSERT_LE_MSG
#undef ASSERT_LE_MSG
#endif
#define ASSERT_LE_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_LE(val1, val2);

#ifdef ASSERT_LT_MSG
#undef ASSERT_LT_MSG
#endif
#define ASSERT_LT_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_LT(val1, val2);

#ifdef ASSERT_GE_MSG
#undef ASSERT_GE_MSG
#endif
#define ASSERT_GE_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_GE(val1, val2);

#ifdef ASSERT_GT_MSG
#undef ASSERT_GT_MSG
#endif
#define ASSERT_GT_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_GT(val1, val2);

#ifdef ASSERT_HRESULT_SUCCEEDED_MSG
#undef ASSERT_HRESULT_SUCCEEDED_MSG
#endif
#define ASSERT_HRESULT_SUCCEEDED_MSG(expr, format, ...)                              \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_HRESULT_SUCCEEDED(expr);

#ifdef ASSERT_HRESULT_FAILED_MSG
#undef ASSERT_HRESULT_FAILED_MSG
#endif
#define ASSERT_HRESULT_FAILED_MSG(expr, format, ...)                                 \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_HRESULT_FAILED(expr);

#ifdef ASSERT_STREQ_MSG
#undef ASSERT_STREQ_MSG
#endif
#define ASSERT_STREQ_MSG(expected, actual, format, ...)                              \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_STREQ(expected, actual);

#ifdef ASSERT_STRNE_MSG
#undef ASSERT_STRNE_MSG
#endif
#define ASSERT_STRNE_MSG(expected, actual, format, ...)                              \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_STRNE(expected, actual);

#ifdef ASSERT_STRCASEEQ_MSG
#undef ASSERT_STRCASEEQ_MSG
#endif
#define ASSERT_STRCASEEQ_MSG(expected, actual, format, ...)                          \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_STRCASEEQ(expected, actual);

#ifdef ASSERT_STRCASENE_MSG
#undef ASSERT_STRCASENE_MSG
#endif
#define ASSERT_STRCASENE_MSG(expected, actual, format, ...)                          \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_STRCASENE(expected, actual);

#ifdef ASSERT_FLOAT_EQ_MSG
#undef ASSERT_FLOAT_EQ_MSG
#endif
#define ASSERT_FLOAT_EQ_MSG(expected, actual, format, ...)                           \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_FLOAT_EQ(expected, actual);

#ifdef ASSERT_DOUBLE_EQ_MSG
#undef ASSERT_DOUBLE_EQ_MSG
#endif
#define ASSERT_DOUBLE_EQ_MSG(expected, actual, format, ...)                          \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_DOUBLE_EQ(expected, actual);

#ifdef ASSERT_NEAR_MSG
#undef ASSERT_NEAR_MSG
#endif
#define ASSERT_NEAR_MSG(val1, val2, abs_error, format, ...)                          \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_NEAR(expected, actual);

#ifdef ASSERT_THROW_MSG
#undef ASSERT_THROW_MSG
#endif
#define ASSERT_THROW_MSG(statement, expected_exception, format, ...)                 \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERASSERT_THROW(statement, expected_exception);

#ifdef ASSERT_NO_THROW_MSG
#undef ASSERT_NO_THROW_MSG
#endif
#define ASSERT_NO_THROW_MSG(statement, format, ...)                                  \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_NO_THROW(statement);

#ifdef ASSERT_ANY_THROW_MSG
#undef ASSERT_ANY_THROW_MSG
#endif
#define ASSERT_ANY_THROW_MSG(statement, format, ...)                                 \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_ANY_THROW(statement);

#ifdef ASSERT_OBJCEQ_MSG
#undef ASSERT_OBJCEQ_MSG
#endif
#define ASSERT_OBJCEQ_MSG(val1, val2, format, ...)                                   \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_OBJCEQ(val1, val2);

#ifdef ASSERT_OBJCNE_MSG
#undef ASSERT_OBJCNE_MSG
#endif
#define ASSERT_OBJCNE_MSG(val1, val2, format, ...)                                   \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_OBJCNE(val1, val2);

///////////////////////////////////////////////////////////
// Expect macros (fails, but continues the test on failure)
///////////////////////////////////////////////////////////

#ifdef EXPECT_TRUE_MSG
#undef EXPECT_TRUE_MSG
#endif
#define EXPECT_TRUE_MSG(condition, format, ...)                                      \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_TRUE(condition);

#ifdef EXPECT_FALSE_MSG
#undef EXPECT_FALSE_MSG
#endif
#define EXPECT_FALSE_MSG(condition, format, ...)                                     \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_FALSE(condition);

#ifdef EXPECT_EQ_MSG
#undef EXPECT_EQ_MSG
#endif
#define EXPECT_EQ_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_EQ(val1, val2);

#ifdef EXPECT_NE_MSG
#undef EXPECT_NE_MSG
#endif
#define EXPECT_NE_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_NE(val1, val2);

#ifdef EXPECT_LE_MSG
#undef EXPECT_LE_MSG
#endif
#define EXPECT_LE_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_LE(val1, val2);

#ifdef EXPECT_LT_MSG
#undef EXPECT_LT_MSG
#endif
#define EXPECT_LT_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_LT(val1, val2);

#ifdef EXPECT_GE_MSG
#undef EXPECT_GE_MSG
#endif
#define EXPECT_GE_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_GE(val1, val2);

#ifdef EXPECT_GT_MSG
#undef EXPECT_GT_MSG
#endif
#define EXPECT_GT_MSG(val1, val2, format, ...)                                       \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_GT(val1, val2);

#ifdef EXPECT_HRESULT_SUCCEEDED_MSG
#undef EXPECT_HRESULT_SUCCEEDED_MSG
#endif
#define EXPECT_HRESULT_SUCCEEDED_MSG(expr, format, ...)                              \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_HRESULT_SUCCEEDED(expr);

#ifdef EXPECT_HRESULT_FAILED_MSG
#undef EXPECT_HRESULT_FAILED_MSG
#endif
#define EXPECT_HRESULT_FAILED_MSG(expr, format, ...)                                 \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_HRESULT_FAILED(expr);

#ifdef EXPECT_STREQ_MSG
#undef EXPECT_STREQ_MSG
#endif
#define EXPECT_STREQ_MSG(expected, actual, format, ...)                              \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_STREQ(expected, actual);

#ifdef EXPECT_STRNE_MSG
#undef EXPECT_STRNE_MSG
#endif
#define EXPECT_STRNE_MSG(expected, actual, format, ...)                              \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_STRNE(expected, actual);

#ifdef EXPECT_STRCASEEQ_MSG
#undef EXPECT_STRCASEEQ_MSG
#endif
#define EXPECT_STRCASEEQ_MSG(expected, actual, format, ...)                          \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_STRCASEEQ(expected, actual);

#ifdef EXPECT_STRCASENE_MSG
#undef EXPECT_STRCASENE_MSG
#endif
#define EXPECT_STRCASENE_MSG(expected, actual, format, ...)                          \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_STRCASENE(expected, actual);

#ifdef EXPECT_FLOAT_EQ_MSG
#undef EXPECT_FLOAT_EQ_MSG
#endif
#define EXPECT_FLOAT_EQ_MSG(expected, actual, format, ...)                           \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_FLOAT_EQ(expected, actual);

#ifdef EXPECT_DOUBLE_EQ_MSG
#undef EXPECT_DOUBLE_EQ_MSG
#endif
#define EXPECT_DOUBLE_EQ_MSG(expected, actual, format, ...)                          \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_DOUBLE_EQ(expected, actual);

#ifdef EXPECT_NEAR_MSG
#undef EXPECT_NEAR_MSG
#endif
#define EXPECT_NEAR_MSG(val1, val2, abs_error, format, ...)                          \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_DOUBLEXPECT_NEAR(val1, val2, abs_error);

#ifdef EXPECT_THROW_MSG
#undef EXPECT_THROW_MSG
#endif
#define EXPECT_THROW_MSG(statement, expected_exception, format, ...)                 \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_EXPECT_THROW(statement, expected_exception);

#ifdef EXPECT_NO_THROW_MSG
#undef EXPECT_NO_THROW_MSG
#endif
#define EXPECT_NO_THROW_MSG(statement, format, ...)                                  \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_NO_THROW(statement);

#ifdef EXPECT_ANY_THROW_MSG
#undef EXPECT_ANY_THROW_MSG
#endif
#define EXPECT_ANY_THROW_MSG(statement, format, ...)                                 \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_ANY_THROW(statement);

#ifdef EXPECT_OBJCEQ_MSG
#undef EXPECT_OBJCEQ_MSG
#endif
#define EXPECT_OBJCEQ_MSG(val1, val2, format, ...)                                   \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_OBJCEQ(val1, val2);

#ifdef EXPECT_OBJCNE_MSG
#undef EXPECT_OBJCNE_MSG
#endif
#define EXPECT_OBJCNE_MSG(val1, val2, format, ...)                                   \
    FunctionalTestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_OBJCNE(val1, val2);