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

#ifdef __OBJC__
#include <objc/runtime.h>
#include <Foundation/Foundation.h>
#endif

// Unit tests will include only GTest header.
// Functional tests will unclude GTest and a functional test api header that diverts some of the logging macros to use Microsoft TAEF APIs.
#include "gtest-api.h"
#if defined FUNCTIONAL_TEST_FRAMEWORK
#include "functionaltest-api.h"
#endif

#include <vector>

// Test helper macros that selectively disable tests.

// Normal Test. tack on DISABLED_ to the test name so that gtest sees it as disabled and doesn't run it.
#define DISABLED_TEST(category, testName) TEST(category, DISABLED_##testName)

// Fixture Test. Fixture tests use a specific named test class (the category) to invoke common cleanup and setup code.
// This macro tacks on DISABLED_ to the test name so that gtest sees it as disabled and doesn't run it. Does not affect
// other tests in the fixture.
#define DISABLED_TEST_F(category, testName) TEST_F(category, DISABLED_##testName)

// Parameterized Test. Parameterized tests or data driven tests involve defining a test template (using TEST_P)
// and then instantiating specific instances (with varying data) using the INSTANTIATE_TEST_CASE_P macro.
// gtest allows a set of instantiations to be disabled by tacking on DISABLED_ to the instantiation name (each case has an auto generated
// test name)
// This macro handles this by separating out the disabled and normal test cases into two instantiations
#define DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues) \
    INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values);                             \
    INSTANTIATE_TEST_CASE_P(DISABLED_##instantiationName, testClass, disabledValues)

// WINOBJC_DISABLE_TESTS is define in the unit test projects only for the ARM platform.
// These macros make it easy to selectively disable a test in that scenario. This is useful since
// ARM may pose certain platform specific problems that need to get addressed out of band (in the compiler for instance)
// so certain tests need to be disabled temporarily but not forgotten about.
#ifdef WINOBJC_DISABLE_TESTS

#define ARM_DISABLED_TEST(category, testName) DISABLED_TEST(category, testName)
#define ARM_DISABLED_TEST_F(category, testName) DISABLED_TEST_F(category, testName)
#define ARM_DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues) \
    DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues)

#else

// Normal Test.
#define ARM_DISABLED_TEST(category, testName) TEST(category, testName)

// Normal Fixture Test.
#define ARM_DISABLED_TEST_F(category, testName) TEST_F(category, testName)

// Parameterized Test. To handle making it easy to disable specific test cases above, this variaton combines the
// normal and disabled values back into one list and runs them all under a single instantiation.
#define ARM_DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues)                  \
    INSTANTIATE_TEST_CASE_P(instantiationName,                                                                      \
                            testClass,                                                                              \
                            []() {                                                                                  \
                                ::testing::internal::ParamGenerator<testClass::ParamType> values1 = values;         \
                                ::testing::internal::ParamGenerator<testClass::ParamType> values2 = disabledValues; \
                                std::vector<testClass::ParamType> combined;                                         \
                                for (const auto& item : values1) {                                                  \
                                    combined.push_back(item);                                                       \
                                }                                                                                   \
                                                                                                                    \
                                for (const auto& item : values2) {                                                  \
                                    combined.push_back(item);                                                       \
                                }                                                                                   \
                                                                                                                    \
                                return ::testing::ValuesIn(combined);                                               \
                                                                                                                    \
                            }())
#endif

// Macros to disable tests only for the OSX platform
#if TARGET_OS_MAC

#define OSX_DISABLED_TEST(category, testName) DISABLED_TEST(category, testName)
#define OSX_DISABLED_TEST_F(category, testName) DISABLED_TEST_F(category, testName)
#define OSX_DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues) \
    DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues)

#else

#define OSX_DISABLED_TEST(category, testName) TEST(category, testName)
#define OSX_DISABLED_TEST_F(category, testName) TEST_F(category, testName)
#define OSX_DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues)                  \
    INSTANTIATE_TEST_CASE_P(instantiationName,                                                                      \
                            testClass,                                                                              \
                            []() {                                                                                  \
                                ::testing::internal::ParamGenerator<testClass::ParamType> values1 = values;         \
                                ::testing::internal::ParamGenerator<testClass::ParamType> values2 = disabledValues; \
                                std::vector<testClass::ParamType> combined;                                         \
                                for (const auto& item : values1) {                                                  \
                                    combined.push_back(item);                                                       \
                                }                                                                                   \
                                                                                                                    \
                                for (const auto& item : values2) {                                                  \
                                    combined.push_back(item);                                                       \
                                }                                                                                   \
                                                                                                                    \
                                return ::testing::ValuesIn(combined);                                               \
                                                                                                                    \
                            }())
#endif

// Macros to disable tests only for the WIN32 platform. This is for ensuring our tests match the reference platform's behavior
// even if our tests do not. Another use case is validating tests and assumptions before our own implementation.
#if TARGET_OS_WIN32

#define WIN32_DISABLED_TEST(category, testName) DISABLED_TEST(category, testName)
#define WIN32_DISABLED_TEST_F(category, testName) DISABLED_TEST_F(category, testName)
#define WIN32_DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues) \
    DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues)

#else

#define WIN32_DISABLED_TEST(category, testName) TEST(category, testName)
#define WIN32_DISABLED_TEST_F(category, testName) TEST_F(category, testName)
#define WIN32_DISABLED_INSTANTIATE_TEST_CASE_P(instantiationName, testClass, values, disabledValues)                \
    INSTANTIATE_TEST_CASE_P(instantiationName,                                                                      \
                            testClass,                                                                              \
                            []() {                                                                                  \
                                ::testing::internal::ParamGenerator<testClass::ParamType> values1 = values;         \
                                ::testing::internal::ParamGenerator<testClass::ParamType> values2 = disabledValues; \
                                std::vector<testClass::ParamType> combined;                                         \
                                for (const auto& item : values1) {                                                  \
                                    combined.push_back(item);                                                       \
                                }                                                                                   \
                                                                                                                    \
                                for (const auto& item : values2) {                                                  \
                                    combined.push_back(item);                                                       \
                                }                                                                                   \
                                                                                                                    \
                                return ::testing::ValuesIn(combined);                                               \
                                                                                                                    \
                            }())
#endif

// OSX defines for compatibility
#ifndef boolean
#define boolean Boolean
#endif