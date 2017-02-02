//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include <TestFramework.h>
#include <type_traits>
#include <chrono>
#include <numeric>
#include <utility>
#include <memory>
#include "BenchmarkTestPublisher.h"

namespace testing {
class BenchmarkTestBase {
public:
    inline void Run();

    // Number of times to run each test, default to 1
    size_t GetRunCount() const {
        return 1;
    }

    // Pre-run and Post-run equivalent to SetUp and TearDown per test case
    // Setup and Tear down that is performed once per all tests should be done in the constructor/destructor
    void PreRun() {
        // Default do nothing
    }

    void PostRun() {
        // Default do nothing
    }
};

namespace internal {

// Helper method shared between BenchmarkTestRunner classes
// This is called to actually run and benchmark the tests
// Can't be shared internally because parameterized tests need a different inheritance than non
template <typename T>
static void __RunTest(T& test) {
    using Microseconds = double;
    size_t runCount = test.GetRunCount();
    ASSERT_NE(0, runCount);
    std::vector<Microseconds> results(runCount);
    for (size_t i = 0; i < runCount; ++i) {
        test.PreRun();
        auto start = std::chrono::high_resolution_clock::now();
        test.Run();
        auto end = std::chrono::high_resolution_clock::now();
        test.PostRun();
        std::chrono::duration<Microseconds, std::micro> duration = end - start;
        results[i] = duration.count();
    }

    std::shared_ptr<::benchmark::BenchmarkTestPublisher> publisher = ::benchmark::BenchmarkTestCreator::GetPublisher();
    auto testName = std::string(::testing::UnitTest::GetInstance()->current_test_info()->name());
    publisher->RegisterTestResults(testName, results);
}

template <typename TestClass>
class BenchmarkTestRunner : public ::testing::Test {
    static_assert(std::is_base_of<BenchmarkTestBase, TestClass>::value, "Benchmark Test should derive from ::testing::BenchmarkTestBase");
    static_assert(std::is_default_constructible<TestClass>::value, "Benchmark Test Class MUST be default constructible");

public:
    BenchmarkTestRunner() : m_test() {
    }

protected:
    TestClass m_test;
};

template <typename TestClass, typename Arg>
class BenchmarkTestRunnerP : public ::testing::TestWithParam<Arg> {
    static_assert(std::is_base_of<BenchmarkTestBase, TestClass>::value, "Benchmark Test should derive from ::testing::BenchmarkTestBase");
    static_assert(std::is_constructible<TestClass, Arg>::value,
                  "Benchmark Test Class MUST be constructible from template arguments, if any");

public:
    BenchmarkTestRunnerP() {
        // Note: This will break when multiple args have the same type
        m_test.reset(new TestClass(::testing::WithParamInterface<Arg>::GetParam()));
    }

protected:
    std::unique_ptr<TestClass> m_test;
};
}
}

// clang-format off
#define _BENCHMARK_CLASSNAME(test_name, test_case_name) BenchmarkInternal##test_name##test_case_name

#define TEST_BENCHMARK(test_name, test_case_name, run_count)                                            \
class _BENCHMARK_CLASSNAME(test_name, test_case_name) : public ::testing::BenchmarkTestBase   {         \
public:                                                                                                 \
        size_t GetRunCount() const {                                                                    \
            return run_count;                                                                           \
        }                                                                                               \
        inline void Run();                                                                              \
};                                                                                                      \
GTEST_TEST_(test_name,                                                                                  \
            test_case_name,                                                                             \
            ::testing::internal::BenchmarkTestRunner<_BENCHMARK_CLASSNAME(test_name, test_case_name)>,  \
            ::testing::internal::GetTestTypeId()) {                                                     \
        ::testing::internal::__RunTest(m_test);                                                         \
}                                                                                                       \
inline void _BENCHMARK_CLASSNAME(test_name, test_case_name)::Run()

#define TEST_BENCHMARK_F(test_name, test_class_name)                                                                                        \
GTEST_TEST_(test_name, test_class_name, ::testing::internal::BenchmarkTestRunner<test_class_name>, ::testing::internal::GetTestTypeId()) {  \
        ::testing::internal::__RunTest(m_test);                                                                                             \
}

#define BENCHMARK_REGISTER_TEST_P(test_name, test_class, generator, ...)                                                \
class _Benchmark_##test_class : public ::testing::internal::BenchmarkTestRunnerP<test_class, __VA_ARGS__> {};           \
TEST_P(_Benchmark_##test_class, test_name) {                                                                            \
    ::testing::internal::__RunTest(*m_test);                                                                            \
}                                                                                                                       \
INSTANTIATE_TEST_CASE_P(test_name, _Benchmark_##test_class, generator);

// clang-format on