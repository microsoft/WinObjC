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

// Ignore SCL warnings in gtest
#if defined __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif
#include "gtest/gtest.h"
#if defined __clang__
#pragma clang diagnostic pop
#endif

#ifdef __OBJC__
#include <objc/objc.h>
#include <Foundation/NSString.h>
#endif

namespace GTestLogPrivate
{

// Yes, we know we're taking a format string from the test code
// Quiets 'warning : format string is not a string literal'
#if defined __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-security"
#endif

// Returns a formatted char* held by an std::vector
template<typename ... Args>
std::vector<char> Format(const char* message, Args ... args)
{
#ifdef __OBJC__
    static NSString* (*formatImp)(id,SEL,NSString*,...) = reinterpret_cast<decltype(formatImp)>(class_getMethodImplementation(object_getClass([NSString class]), @selector(stringWithFormat:)));
    NSString *string = formatImp([NSString class], @selector(stringWithFormat:), [NSString stringWithUTF8String:message], args ...);
    std::vector<char> buffer([string length] + 1);
    memcpy(buffer.data(), [string UTF8String], buffer.size() - 1);
    return buffer;
#else
    // Calculate the size needed, add 1 for the null terminator
    size_t size = _snprintf(nullptr, 0, message, args ...) + 1;

    // Allocate a buffer and format the string
    std::vector<char> buffer(size);
    snprintf(buffer.data(), size, message, args ...);
    return buffer;
#endif
}

#if defined __clang__
#pragma clang diagnostic pop
#endif

}

#ifdef __OBJC__
namespace GTestLogPrivate
{
template<typename ... Args>
std::vector<char> Format(NSString* message, Args ... args)
{
    return Format([message UTF8String], std::forward<Args>(args)...);
}
}

namespace woc {
namespace testing {
inline ::testing::AssertionResult CompareObjectsEqual(
    const char* expectedExpression,
    const char* actualExpression,
    const id& expected,
    const id& actual) {
    if ((!expected && !actual) || (expected && actual && [expected isEqual:actual])) {
        return ::testing::AssertionSuccess();
    }

    return ::testing::internal::CmpHelperEQFailure(expectedExpression, actualExpression, expected, actual);
}

inline ::testing::AssertionResult CompareObjectsNotEqual(
    const char* expectedExpression,
    const char* actualExpression,
    const id& expected,
    const id& actual) {
    if (!(expected && actual && [expected isEqual:actual]) && (expected != actual)) {
        return ::testing::AssertionSuccess();
    }

    return ::testing::internal::CmpHelperOpFailure(expectedExpression, actualExpression, expected, actual, "!=");
}
}
}

namespace testing {
namespace internal {
inline std::ostream& operator<<(std::ostream& os, const id& object) {
    return os << (char*)([[object description] UTF8String]);
}
}
}

#define EXPECT_OBJCEQ(expected, actual) \
  EXPECT_PRED_FORMAT2(::woc::testing::CompareObjectsEqual, expected, actual)
#define EXPECT_OBJCNE(expected, actual) \
  EXPECT_PRED_FORMAT2(::woc::testing::CompareObjectsNotEqual, expected, actual)

#define ASSERT_OBJCEQ(expected, actual) \
  ASSERT_PRED_FORMAT2(::woc::testing::CompareObjectsEqual, expected, actual)
#define ASSERT_OBJCNE(expected, actual) \
  ASSERT_PRED_FORMAT2(::woc::testing::CompareObjectsNotEqual, expected, actual)
#endif

/////////////////////////////////////////////////////////
// Logging macros
/////////////////////////////////////////////////////////

// Log an informational message
// DOES NOT include file and line information in the log output
#define LOG_INFO(format, ...) \
    std::cout << testing::Message() <<  \
        "[  INFO ] " << GTestLogPrivate::Format(format, __VA_ARGS__).data() << std::endl

// Log a warning message (does not effect test outcome)
// Includes file and line information in the log output
#define LOG_WARNING(format, ...) \
    GTEST_LOG_(WARNING) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// Log an error message (does not effect test outcome)
// Includes file and line information in the log output
#define LOG_ERROR(format, ...) \
    GTEST_LOG_(ERROR) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

/////////////////////////////////////////////////////////
// Assert macros (terminates the test on failure)
/////////////////////////////////////////////////////////

// ASSERT_TRUE with formatted message string
# define ASSERT_TRUE_MSG(condition, format, ...) \
    ASSERT_TRUE(condition) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_FALSE with formatted message string
# define ASSERT_FALSE_MSG(condition, format, ...) \
    ASSERT_FALSE(condition) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_EQ with formatted message string
# define ASSERT_EQ_MSG(val1, val2, format, ...) \
    ASSERT_EQ(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_NE with formatted message string
# define ASSERT_NE_MSG(val1, val2, format, ...) \
    ASSERT_NE(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_LE with formatted message string
# define ASSERT_LE_MSG(val1, val2, format, ...) \
    ASSERT_LE(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_LT with formatted message string
# define ASSERT_LT_MSG(val1, val2, format, ...) \
    ASSERT_LT(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_GE with formatted message string
# define ASSERT_GE_MSG(val1, val2, format, ...) \
    ASSERT_GE(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_GT with formatted message string
# define ASSERT_GT_MSG(val1, val2, format, ...) \
    ASSERT_GT(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_HRESULT_SUCCEEDED with formatted message string
# define ASSERT_HRESULT_SUCCEEDED_MSG(expr, format, ...) \
    ASSERT_HRESULT_SUCCEEDED(expr) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_HRESULT_FAILED with formatted message string
# define ASSERT_HRESULT_FAILED_MSG(expr, format, ...) \
    ASSERT_HRESULT_FAILED(expr) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_STREQ with formatted message string
#define ASSERT_STREQ_MSG(expected, actual, format, ...) \
    ASSERT_STREQ(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_STRNE with formatted message string
#define ASSERT_STRNE_MSG(expected, actual, format, ...) \
    ASSERT_STRNE(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_STRCASEEQ with formatted message string
#define ASSERT_STRCASEEQ_MSG(expected, actual, format, ...) \
    ASSERT_STRCASEEQ(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_STRCASENE with formatted message string
#define ASSERT_STRCASENE_MSG(expected, actual, format, ...) \
    ASSERT_STRCASENE(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_FLOAT_EQ with formatted message string
#define ASSERT_FLOAT_EQ_MSG(expected, actual, format, ...)\
    ASSERT_FLOAT_EQ(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_DOUBLE_EQ with formatted message string
#define ASSERT_DOUBLE_EQ_MSG(expected, actual, format, ...)\
    ASSERT_DOUBLE_EQ(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_NEAR with formatted message string
#define ASSERT_NEAR_MSG(val1, val2, abs_error, format, ...)\
    ASSERT_NEAR(val1, val2, abs_error) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_THROW with formatted message string
#define ASSERT_THROW_MSG(statement, expected_exception, format, ...) \
    ASSERT_THROW(statement, expected_exception) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_NO_THROW with formatted message string
#define ASSERT_NO_THROW_MSG(statement, format, ...) \
    ASSERT_NO_THROW(statement) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_ANY_THROW with formatted message string
#define ASSERT_ANY_THROW_MSG(statement, format, ...) \
    ASSERT_ANY_THROW(statement) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_OBJCEQ with formatted message string
# define ASSERT_OBJCEQ_MSG(val1, val2, format, ...) \
    ASSERT_OBJCEQ(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// ASSERT_OBJCNE with formatted message string
# define ASSERT_OBJCNE_MSG(val1, val2, format, ...) \
    ASSERT_OBJCNE(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

///////////////////////////////////////////////////////////
// Expect macros (fails, but continues the test on failure)
///////////////////////////////////////////////////////////

// EXPECT_TRUE with formatted message string
# define EXPECT_TRUE_MSG(condition, format, ...) \
    EXPECT_TRUE(condition) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_FALSE with formatted message string
# define EXPECT_FALSE_MSG(condition, format, ...) \
    EXPECT_FALSE(condition) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_EQ with formatted message string
# define EXPECT_EQ_MSG(val1, val2, format, ...) \
    EXPECT_EQ(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_NE with formatted message string
# define EXPECT_NE_MSG(val1, val2, format, ...) \
    EXPECT_NE(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_LE with formatted message string
# define EXPECT_LE_MSG(val1, val2, format, ...) \
    EXPECT_LE(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_LT with formatted message string
# define EXPECT_LT_MSG(val1, val2, format, ...) \
    EXPECT_LT(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_GE with formatted message string
# define EXPECT_GE_MSG(val1, val2, format, ...) \
    EXPECT_GE(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_GT with formatted message string
# define EXPECT_GT_MSG(val1, val2, format, ...) \
    EXPECT_GT(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_HRESULT_SUCCEEDED with formatted message string
# define EXPECT_HRESULT_SUCCEEDED_MSG(expr, format, ...) \
    EXPECT_HRESULT_SUCCEEDED(expr) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_HRESULT_FAILED with formatted message string
# define EXPECT_HRESULT_FAILED_MSG(expr, format, ...) \
    EXPECT_HRESULT_FAILED(expr) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_STREQ with formatted message string
#define EXPECT_STREQ_MSG(expected, actual, format, ...) \
    EXPECT_STREQ(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_STRNE with formatted message string
#define EXPECT_STRNE_MSG(expected, actual, format, ...) \
    EXPECT_STRNE(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_STRCASEEQ with formatted message string
#define EXPECT_STRCASEEQ_MSG(expected, actual, format, ...) \
    EXPECT_STRCASEEQ(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_STRCASENE with formatted message string
#define EXPECT_STRCASENE_MSG(expected, actual, format, ...) \
    EXPECT_STRCASENE(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_FLOAT_EQ with formatted message string
#define EXPECT_FLOAT_EQ_MSG(expected, actual, format, ...)\
    EXPECT_FLOAT_EQ(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_DOUBLE_EQ with formatted message string
#define EXPECT_DOUBLE_EQ_MSG(expected, actual, format, ...)\
    EXPECT_DOUBLE_EQ(expected, actual) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_NEAR with formatted message string
#define EXPECT_NEAR_MSG(val1, val2, abs_error, format, ...)\
    EXPECT_NEAR(val1, val2, abs_error) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_THROW with formatted message string
#define EXPECT_THROW_MSG(statement, expected_exception, format, ...) \
    EXPECT_THROW(statement, expected_exception) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_NO_THROW with formatted message string
#define EXPECT_NO_THROW_MSG(statement, format, ...) \
    EXPECT_NO_THROW(statement) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_ANY_THROW with formatted message string
#define EXPECT_ANY_THROW_MSG(statement, format, ...) \
    EXPECT_ANY_THROW(statement) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_OBJCEQ with formatted message string
# define EXPECT_OBJCEQ_MSG(val1, val2, format, ...) \
    EXPECT_OBJCEQ(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()

// EXPECT_OBJCNE with formatted message string
# define EXPECT_OBJCNE_MSG(val1, val2, format, ...) \
    EXPECT_OBJCNE(val1, val2) << GTestLogPrivate::Format(format, __VA_ARGS__).data()


