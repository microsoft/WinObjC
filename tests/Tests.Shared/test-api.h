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

#include "gtest-api.h"

#include "Logger.h"
#include <mutex>
#include <string>
#include <locale>
#include <codecvt>

#ifdef __OBJC__
#pragma push_macro("interface")
#ifndef interface
#define interface struct
#endif
#pragma push_macro("Nil")
#undef Nil
#pragma push_macro("__alignof")
#define __alignof alignof
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmicrosoft"

#include <UWP/RTHelpers.h>
#endif

#ifndef INLINE_TEST_METHOD_MARKUP
#define INLINE_TEST_METHOD_MARKUP
#endif

#include <WexTestClass.h>

#ifdef __OBJC__
#pragma pop_macro("Nil")
#pragma pop_macro("interface")
#pragma pop_macro("__alignof")
#pragma clang diagnostic pop
#endif

#include "Framework/Framework.h"

/////////////////////////////////////////////////////////
// Logging macros
/////////////////////////////////////////////////////////

#ifdef __clang__
#define _TESTAPI_FUNCTION __PRETTY_FUNCTION__
#else
#define _TESTAPI_FUNCTION __FUNCTION__
#endif

#ifdef LOG_INFO
#undef LOG_INFO
#endif
#define LOG_INFO(__format, ...) TestLog::LogComment(GTestLogPrivate::Format(__format, __VA_ARGS__).data())

#ifdef LOG_WARNING
#undef LOG_WARNING
#endif
#define LOG_WARNING(__format, ...) \
    TestLog::LogWarning(GTestLogPrivate::Format(__format, __VA_ARGS__).data(), __FILE__, _TESTAPI_FUNCTION, __LINE__)

#ifdef LOG_ERROR
#undef LOG_ERROR
#endif
#define LOG_ERROR(__format, ...) \
    TestLog::LogError(GTestLogPrivate::Format(__format, __VA_ARGS__).data(), __FILE__, _TESTAPI_FUNCTION, __LINE__)

/////////////////////////////////////////////////////////
// Assert and Verify macros override
/////////////////////////////////////////////////////////

#ifdef GTEST_SUCCESS_
#undef GTEST_SUCCESS_
#endif
#define GTEST_SUCCESS_(__message) TestLog::LogComment((__message))

#ifdef GTEST_NONFATAL_FAILURE_
#undef GTEST_NONFATAL_FAILURE_
#endif
#define GTEST_NONFATAL_FAILURE_(__message) TestLog::LogError((__message), __FILE__, _TESTAPI_FUNCTION, __LINE__)

#ifdef GTEST_FATAL_FAILURE_
#undef GTEST_FATAL_FAILURE_
#endif
#define GTEST_FATAL_FAILURE_(__message) TestLog::LogErrorAndAbort((__message), __FILE__, _TESTAPI_FUNCTION, __LINE__)

// TODO::
// todo-nithishm-04182016 - Investigate a better way to support ASSERT_*_MSG and EXPECT_*_MSG macros without re-defining them
// here. Bug 7244185 is tracking this work.

/////////////////////////////////////////////////////////
// Assert macros (terminates the test on failure)
/////////////////////////////////////////////////////////

#ifdef ASSERT_TRUE_MSG
#undef ASSERT_TRUE_MSG
#endif
#define ASSERT_TRUE_MSG(condition, format, ...)                            \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_TRUE(condition);

#ifdef ASSERT_FALSE_MSG
#undef ASSERT_FALSE_MSG
#endif
#define ASSERT_FALSE_MSG(condition, format, ...)                           \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_FALSE(condition);

#ifdef ASSERT_EQ_MSG
#undef ASSERT_EQ_MSG
#endif
#define ASSERT_EQ_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_EQ(val1, val2);

#ifdef ASSERT_NE_MSG
#undef ASSERT_NE_MSG
#endif
#define ASSERT_NE_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_NE(val1, val2);

#ifdef ASSERT_LE_MSG
#undef ASSERT_LE_MSG
#endif
#define ASSERT_LE_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_LE(val1, val2);

#ifdef ASSERT_LT_MSG
#undef ASSERT_LT_MSG
#endif
#define ASSERT_LT_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_LT(val1, val2);

#ifdef ASSERT_GE_MSG
#undef ASSERT_GE_MSG
#endif
#define ASSERT_GE_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_GE(val1, val2);

#ifdef ASSERT_GT_MSG
#undef ASSERT_GT_MSG
#endif
#define ASSERT_GT_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_GT(val1, val2);

#ifdef ASSERT_HRESULT_SUCCEEDED_MSG
#undef ASSERT_HRESULT_SUCCEEDED_MSG
#endif
#define ASSERT_HRESULT_SUCCEEDED_MSG(expr, format, ...)                    \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_HRESULT_SUCCEEDED(expr);

#ifdef ASSERT_HRESULT_FAILED_MSG
#undef ASSERT_HRESULT_FAILED_MSG
#endif
#define ASSERT_HRESULT_FAILED_MSG(expr, format, ...)                       \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_HRESULT_FAILED(expr);

#ifdef ASSERT_STREQ_MSG
#undef ASSERT_STREQ_MSG
#endif
#define ASSERT_STREQ_MSG(expected, actual, format, ...)                    \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_STREQ(expected, actual);

#ifdef ASSERT_STRNE_MSG
#undef ASSERT_STRNE_MSG
#endif
#define ASSERT_STRNE_MSG(expected, actual, format, ...)                    \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_STRNE(expected, actual);

#ifdef ASSERT_STRCASEEQ_MSG
#undef ASSERT_STRCASEEQ_MSG
#endif
#define ASSERT_STRCASEEQ_MSG(expected, actual, format, ...)                \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_STRCASEEQ(expected, actual);

#ifdef ASSERT_STRCASENE_MSG
#undef ASSERT_STRCASENE_MSG
#endif
#define ASSERT_STRCASENE_MSG(expected, actual, format, ...)                \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_STRCASENE(expected, actual);

#ifdef ASSERT_FLOAT_EQ_MSG
#undef ASSERT_FLOAT_EQ_MSG
#endif
#define ASSERT_FLOAT_EQ_MSG(expected, actual, format, ...)                 \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_FLOAT_EQ(expected, actual);

#ifdef ASSERT_DOUBLE_EQ_MSG
#undef ASSERT_DOUBLE_EQ_MSG
#endif
#define ASSERT_DOUBLE_EQ_MSG(expected, actual, format, ...)                \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_DOUBLE_EQ(expected, actual);

#ifdef ASSERT_NEAR_MSG
#undef ASSERT_NEAR_MSG
#endif
#define ASSERT_NEAR_MSG(val1, val2, abs_error, format, ...)                \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_NEAR(val1, val2, abs_error);

#ifdef ASSERT_THROW_MSG
#undef ASSERT_THROW_MSG
#endif
#define ASSERT_THROW_MSG(statement, expected_exception, format, ...)       \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_THROW(statement, expected_exception);

#ifdef ASSERT_NO_THROW_MSG
#undef ASSERT_NO_THROW_MSG
#endif
#define ASSERT_NO_THROW_MSG(statement, format, ...)                        \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_NO_THROW(statement);

#ifdef ASSERT_ANY_THROW_MSG
#undef ASSERT_ANY_THROW_MSG
#endif
#define ASSERT_ANY_THROW_MSG(statement, format, ...)                       \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_ANY_THROW(statement);

#ifdef ASSERT_OBJCEQ_MSG
#undef ASSERT_OBJCEQ_MSG
#endif
#define ASSERT_OBJCEQ_MSG(val1, val2, format, ...)                         \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_OBJCEQ(val1, val2);

#ifdef ASSERT_OBJCNE_MSG
#undef ASSERT_OBJCNE_MSG
#endif
#define ASSERT_OBJCNE_MSG(val1, val2, format, ...)                         \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    ASSERT_OBJCNE(val1, val2);

///////////////////////////////////////////////////////////
// Expect macros (fails, but continues the test on failure)
///////////////////////////////////////////////////////////

#ifdef EXPECT_TRUE_MSG
#undef EXPECT_TRUE_MSG
#endif
#define EXPECT_TRUE_MSG(condition, format, ...)                            \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_TRUE(condition);

#ifdef EXPECT_FALSE_MSG
#undef EXPECT_FALSE_MSG
#endif
#define EXPECT_FALSE_MSG(condition, format, ...)                           \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_FALSE(condition);

#ifdef EXPECT_EQ_MSG
#undef EXPECT_EQ_MSG
#endif
#define EXPECT_EQ_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_EQ(val1, val2);

#ifdef EXPECT_NE_MSG
#undef EXPECT_NE_MSG
#endif
#define EXPECT_NE_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_NE(val1, val2);

#ifdef EXPECT_LE_MSG
#undef EXPECT_LE_MSG
#endif
#define EXPECT_LE_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_LE(val1, val2);

#ifdef EXPECT_LT_MSG
#undef EXPECT_LT_MSG
#endif
#define EXPECT_LT_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_LT(val1, val2);

#ifdef EXPECT_GE_MSG
#undef EXPECT_GE_MSG
#endif
#define EXPECT_GE_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_GE(val1, val2);

#ifdef EXPECT_GT_MSG
#undef EXPECT_GT_MSG
#endif
#define EXPECT_GT_MSG(val1, val2, format, ...)                             \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_GT(val1, val2);

#ifdef EXPECT_HRESULT_SUCCEEDED_MSG
#undef EXPECT_HRESULT_SUCCEEDED_MSG
#endif
#define EXPECT_HRESULT_SUCCEEDED_MSG(expr, format, ...)                    \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_HRESULT_SUCCEEDED(expr);

#ifdef EXPECT_HRESULT_FAILED_MSG
#undef EXPECT_HRESULT_FAILED_MSG
#endif
#define EXPECT_HRESULT_FAILED_MSG(expr, format, ...)                       \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_HRESULT_FAILED(expr);

#ifdef EXPECT_STREQ_MSG
#undef EXPECT_STREQ_MSG
#endif
#define EXPECT_STREQ_MSG(expected, actual, format, ...)                    \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_STREQ(expected, actual);

#ifdef EXPECT_STRNE_MSG
#undef EXPECT_STRNE_MSG
#endif
#define EXPECT_STRNE_MSG(expected, actual, format, ...)                    \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_STRNE(expected, actual);

#ifdef EXPECT_STRCASEEQ_MSG
#undef EXPECT_STRCASEEQ_MSG
#endif
#define EXPECT_STRCASEEQ_MSG(expected, actual, format, ...)                \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_STRCASEEQ(expected, actual);

#ifdef EXPECT_STRCASENE_MSG
#undef EXPECT_STRCASENE_MSG
#endif
#define EXPECT_STRCASENE_MSG(expected, actual, format, ...)                \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_STRCASENE(expected, actual);

#ifdef EXPECT_FLOAT_EQ_MSG
#undef EXPECT_FLOAT_EQ_MSG
#endif
#define EXPECT_FLOAT_EQ_MSG(expected, actual, format, ...)                 \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_FLOAT_EQ(expected, actual);

#ifdef EXPECT_DOUBLE_EQ_MSG
#undef EXPECT_DOUBLE_EQ_MSG
#endif
#define EXPECT_DOUBLE_EQ_MSG(expected, actual, format, ...)                \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_DOUBLE_EQ(expected, actual);

#ifdef EXPECT_NEAR_MSG
#undef EXPECT_NEAR_MSG
#endif
#define EXPECT_NEAR_MSG(val1, val2, abs_error, format, ...)                \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_NEAR(val1, val2, abs_error);

#ifdef EXPECT_THROW_MSG
#undef EXPECT_THROW_MSG
#endif
#define EXPECT_THROW_MSG(statement, expected_exception, format, ...)       \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_EXPECT_THROW(statement, expected_exception);

#ifdef EXPECT_NO_THROW_MSG
#undef EXPECT_NO_THROW_MSG
#endif
#define EXPECT_NO_THROW_MSG(statement, format, ...)                        \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_NO_THROW(statement);

#ifdef EXPECT_ANY_THROW_MSG
#undef EXPECT_ANY_THROW_MSG
#endif
#define EXPECT_ANY_THROW_MSG(statement, format, ...)                       \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_ANY_THROW(statement);

#ifdef EXPECT_OBJCEQ_MSG
#undef EXPECT_OBJCEQ_MSG
#endif
#define EXPECT_OBJCEQ_MSG(val1, val2, format, ...)                         \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_OBJCEQ(val1, val2);

#ifdef EXPECT_OBJCNE_MSG
#undef EXPECT_OBJCNE_MSG
#endif
#define EXPECT_OBJCNE_MSG(val1, val2, format, ...)                         \
    TestLog::SetUserComment(GTestLogPrivate::Format(format, __VA_ARGS__)); \
    EXPECT_OBJCNE(val1, val2);

#ifdef FRIEND_TEST
#undef FRIEND_TEST
#endif
#define FRIEND_TEST(test_case_name, test_name) friend class test_case_name##_##test_name

// clang-format off

// GTEST uses a name prefix of DISABLED to determine if a test is to be run or not.
// TAEF on the other hand uses metadata stamped into a specific section of the binary
// which means we need a compile time way to determine if a test needs that metadata.
template <unsigned NumChar>
constexpr const wchar_t* const _IsDisabledTest(char const (&str1)[NumChar]) {
    return ((NumChar > 8)  &&
            str1[0] == 'D' &&
            str1[1] == 'I' &&
            str1[2] == 'S' &&
            str1[3] == 'A' &&
            str1[4] == 'B' &&
            str1[5] == 'L' &&
            str1[6] == 'E' &&
            str1[7] == 'D') ? L"TRUE" : L"FALSE";
}

// Helper function to allow parameterized tests to change the name of 
// "current" running test. This is __declspec(noinline) inline so that
// a single version of the function is used across the module. This is 
// a technique for modifying global state in a header only fashion.
__declspec(noinline) inline std::string _ExchangeAlternateTestName(
    const std::string& alternateName, bool exchange) {

    static std::string s_alternateTestName;
    static std::mutex s_alternateTestNameLock;
    std::lock_guard<std::mutex> lock(s_alternateTestNameLock);
    std::string toReturn = s_alternateTestName;
    if (exchange) {
        s_alternateTestName = alternateName;
    }
    
    return toReturn;
}

// Rewrite the GTEST_TEST_ macro to instead use TAEF meta data and paradigms
#pragma push_macro("GTEST_TEST_")
#define GTEST_TEST_(className, methodName, parent_class, parent_id) \
    class className##_##methodName : public parent_class { \
        BEGIN_TEST_CLASS(className##_##methodName) \
            TEST_CLASS_PROPERTY(L"Ignore", _IsDisabledTest( #methodName )) \
        END_TEST_CLASS() \
        \
        TEST_METHOD(Test); \
        \
        TEST_METHOD_SETUP(_Setup) { \
            SetUp(); \
            return true; \
        } \
        TEST_METHOD_CLEANUP(_Teardown) { \
            TearDown(); \
            return true; \
        } \
        TEST_CLASS_SETUP(_SetupClass) { \
            SetUpTestCase(); \
            return true; \
        } \
        TEST_CLASS_CLEANUP(_TeardownClass) { \
            TearDownTestCase(); \
            return true; \
        } \
        \
        virtual void TestBody() { \
            /* Unused. Strictly to conform to GTEST test abstract methods. */ \
            Test(); \
        } \
        \
    }; \
    \
    void className##_##methodName::Test()

#pragma push_macro("INSTANTIATE_TEST_CASE_P")
#define  INSTANTIATE_TEST_CASE_P(prefix, className, generator, ...)                  \
/* This assumes that there already exists a className type with SetUp and TearDown methods to call */ \
    \
    class prefix##_##className { \
        BEGIN_TEST_CLASS(prefix##_##className) \
                TEST_CLASS_PROPERTY(L"Ignore", _IsDisabledTest( #prefix )) \
        END_TEST_CLASS() \
    \
        TEST_CLASS_SETUP(_SetupClass) { \
            className::SetUpTestCase(); \
            return true; \
        } \
       TEST_CLASS_CLEANUP(_TeardownClass) { \
            className::TearDownTestCase(); \
            return true; \
        } \
        \
        TEST_METHOD(Test) { \
            WEX::Logging::Log::Comment(L"\nStarting parameterized subtests for " L#prefix L"_" L#className L":"); \
            ::testing::internal::ParamGenerator<className::ParamType> paramGenerator(generator); \
            for (const auto& metaFactory : ::testing::UnitTest::GetInstance()->parameterized_test_registry(). \
              GetTestCasePatternHolder<className>( \
                  #className, \
                  ::testing::internal::CodeLocation( \
                      __FILE__, __LINE__))->GetTestMetaFactories()) { \
                 size_t i = 0; \
                 static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter; \
                 std::wstring c_stringPrefix = L #prefix L"_" L#className L"." + converter.from_bytes(metaFactory.first.c_str()); \
                 for (typename ::testing::internal::ParamGenerator<className::ParamType>::iterator param = paramGenerator.begin(); param != paramGenerator.end(); ++param, ++i) { \
                    std::wstring currentTest = c_stringPrefix + L"/" + std::to_wstring(i); \
                    /* TODO: don't leak. Use better storage. */ \
                    auto factory = metaFactory.second->CreateTestFactory(*param); \
                    auto test = factory->CreateTest(); \
                    \
                    WEX::Logging::Log::StartGroup(currentTest.c_str()); \
                    _ExchangeAlternateTestName(converter.to_bytes(currentTest), true); \
                    /* Emulate GTEST as much as possible here. That means that SetUp and TearDown are always run. */ \
                    /* The actual TestBody is only run if Setup was successful though. NOTE: this is slighty different */ \
                    /* than normal TAEF behavior as TaerDown failure here will fail the test whereas it won't in a non parameterized test. */ \
                    try \
                    { \
                        ::testing::TestRunner::SetUp(test); \
                        ::testing::TestRunner::TestBody(test); \
                    } \
                    catch (const ::WEX::TestExecution::VerifyFailureException&) \
                    { \
                    } \
                    \
                    try \
                    { \
                        ::testing::TestRunner::TearDown(test); \
                    } \
                    catch (const ::WEX::TestExecution::VerifyFailureException&) \
                    { \
                    } \
                    _ExchangeAlternateTestName(std::string(), true); \
                    \
                    WEX::Logging::Log::EndGroup(currentTest.c_str()); \
                    \
                    delete factory; \
                    delete test; \
                } \
            } \
            WEX::Logging::Log::Comment(L"\nEnd of parameterized subtests for " L#className L"_" L#prefix L".\n"); \
        } \
    };

// clang-format on

IF_NOT_EXISTS_BEGIN(GetCurrentTestDirectory)
    static std::string GetCurrentTestDirectory() {
        WEX::Common::String testDeploymentPath;
        WEX::TestExecution::RuntimeParameters::TryGetValue(L"TestDeploymentDir", testDeploymentPath);
        std::wstring toReturn(testDeploymentPath);

        static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        return converter.to_bytes(toReturn);
    }
IF_NOT_EXISTS_END

IF_NOT_EXISTS_BEGIN(GetTestFullName)
    static std::string GetTestFullName() {
        std::string alternateTestName = _ExchangeAlternateTestName(std::string(), false);
        if (!alternateTestName.empty()) {
            return alternateTestName;
        }
        WEX::Common::String testName;
        WEX::TestExecution::RuntimeParameters::TryGetValue(L"TestName", testName);

        std::wstring wideToReturn(testName);
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::string toReturn = converter.to_bytes(wideToReturn);

        toReturn = toReturn.substr(0, toReturn.rfind("::Test"));
        toReturn.replace(toReturn.find("_"), 1, ".");
        return toReturn;
    }
IF_NOT_EXISTS_END

#ifndef LOG_TEST_PROPERTY
#define LOG_TEST_PROPERTY(key, value)                                            \
    {                                                                            \
        static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter; \
        std::wstring wideKey = converter.from_bytes(key);                        \
        std::wstring wideValue = converter.from_bytes(value);                    \
        WEX::Logging::Log::Property(wideKey.c_str(), wideValue.c_str());         \
    }
#endif