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
#include "BenchmarkPublisher.h"

namespace benchmark {
class BenchmarkCaseBase {
public:
    inline void Run();

    // Number of times to run each test, default to 2
    size_t GetRunCount() const {
        return 2;
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

// Helper method shared between BenchmarkCaseRunner classes
// This is called to actually run and benchmark the tests
// Can't be shared internally because parameterized tests need a different inheritance than non
template <typename T>
static void __RunCase(T& test, const char* caseName) {
    using Microseconds = double;
    size_t runCount = test.GetRunCount();
    ASSERT_LT(1, runCount);
    std::vector<Microseconds> results(runCount);
    @autoreleasepool {
        for (size_t i = 0; i < runCount; ++i) {
            test.PreRun();
            auto start = std::chrono::high_resolution_clock::now();
            test.Run();
            auto end = std::chrono::high_resolution_clock::now();
            test.PostRun();
            std::chrono::duration<Microseconds, std::micro> duration = end - start;
            results[i] = duration.count();
        }
    }

    std::shared_ptr<::benchmark::BenchmarkPublisher> publisher = ::benchmark::BenchmarkPublisherFactory::GetPublisher();
    auto testName = std::string(caseName);
    publisher->RegisterCaseResults(testName, results);
}

template <typename CaseClass>
class BenchmarkCaseRunner : public ::testing::Test {
    static_assert(std::is_base_of<BenchmarkCaseBase, CaseClass>::value, "Benchmark Case should derive from ::benchmark::BenchmarkCaseBase");
    static_assert(std::is_default_constructible<CaseClass>::value, "Benchmark Case Class MUST be default constructible");

public:
    BenchmarkCaseRunner() : m_test() {
    }

protected:
    CaseClass m_test;
};

template <typename CaseClass, typename Arg>
class BenchmarkCaseRunnerP : public ::testing::TestWithParam<Arg> {
    static_assert(std::is_base_of<BenchmarkCaseBase, CaseClass>::value, "Benchmark Case should derive from ::benchmark::BenchmarkCaseBase");
    static_assert(std::is_constructible<CaseClass, Arg>::value,
                  "Benchmark Case Class MUST be constructible from template arguments, if any");

public:
    BenchmarkCaseRunnerP() {
        // Note: This will break when multiple args have the same type
        m_test.reset(new CaseClass(::testing::WithParamInterface<Arg>::GetParam()));
    }

protected:
    std::unique_ptr<CaseClass> m_test;
};
}
}

// clang-format off
#define _BENCHMARK_CLASSNAME(test_name, test_case_name) test_name##__##test_case_name
#define _STRINGIFY_INTERNAL(var) #var
#define _STRINGIFY(var) _STRINGIFY_INTERNAL(var)

#define BENCHMARK(test_name, test_case_name, run_count)                                            \
class _BENCHMARK_CLASSNAME(test_name, test_case_name) : public ::benchmark::BenchmarkCaseBase   {       \
public:                                                                                                 \
        size_t GetRunCount() const {                                                                    \
            return run_count;                                                                           \
        }                                                                                               \
        inline void Run();                                                                              \
};                                                                                                      \
GTEST_TEST_(test_name,                                                                                  \
            test_case_name,                                                                             \
            ::benchmark::internal::BenchmarkCaseRunner<_BENCHMARK_CLASSNAME(test_name, test_case_name)>,\
            ::testing::internal::GetTestTypeId()) {                                                             \
        ::benchmark::internal::__RunCase(m_test, _STRINGIFY(_BENCHMARK_CLASSNAME(test_name, test_case_name)));  \
}                                                                                                               \
inline void _BENCHMARK_CLASSNAME(test_name, test_case_name)::Run()

#define BENCHMARK_F(test_name, test_class_name)                                                                                                 \
GTEST_TEST_(test_name, test_class_name, ::benchmark::internal::BenchmarkCaseRunner<test_class_name>, ::testing::internal::GetTestTypeId()) {    \
        ::benchmark::internal::__RunCase(m_test, _STRINGIFY(_BENCHMARK_CLASSNAME(test_name, test_class_name)));                                 \
}

#define BENCHMARK_REGISTER_CASE_P(test_name, test_class, generator, ...)                                                \
class _Benchmark_##test_class : public ::benchmark::internal::BenchmarkCaseRunnerP<test_class, __VA_ARGS__> {};         \
TEST_P(_Benchmark_##test_class, test_name) {                                                                            \
    const char* testName = _STRINGIFY(__##test_class);                                                                  \
    ::benchmark::internal::__RunCase(*m_test, GetTestFullName().c_str());                                               \
}                                                                                                                       \
INSTANTIATE_TEST_CASE_P(test_name, _Benchmark_##test_class, generator);

// clang-format on