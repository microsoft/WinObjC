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

#import <Starboard/SmartTypes.h>
#import "Benchmark.h"
#import <CppUtils.h>

BENCHMARK(BenchmarkSample, BasicAddition, 1024) {
    size_t sum = 0;
    for (size_t i = 0; i < 1000; ++i) {
        sum += i;
    }
}

class BenchmarkTestFSample : public ::benchmark::BenchmarkCaseBase {
    NSMutableArray* m_array;

public:
    BenchmarkTestFSample() : m_array([[NSMutableArray alloc] initWithCapacity:1000]) {
        for (unsigned int i = 0; i < 1000; ++i) {
            m_array[i] = [NSNumber numberWithUnsignedInt:i];
        }
    }

    ~BenchmarkTestFSample() {
        [m_array release];
    }

    inline void Run() {
        unsigned int sum = 0;
        for (NSNumber* num in m_array) {
            sum += [num unsignedIntValue];
        }
    }

    size_t GetRunCount() const {
        return 1024;
    }
};

BENCHMARK_F(BenchmarkSample, BenchmarkTestFSample)

class BenchmarkTestPreRunSample : public ::benchmark::BenchmarkCaseBase {
    NSMutableArray* m_array;

public:
    void PreRun() {
        m_array = [[NSMutableArray alloc] initWithCapacity:1000];
    }

    inline void Run() {
        [m_array release];
    }

    size_t GetRunCount() const {
        return 2048;
    }
};

BENCHMARK_F(BenchmarkSample, BenchmarkTestPreRunSample)

class BenchmarkTestPostRunSample : public ::benchmark::BenchmarkCaseBase {
    NSMutableArray* m_array;

public:
    inline void Run() {
        m_array = [[NSMutableArray alloc] initWithCapacity:1000];
    }

    void PostRun() {
        [m_array release];
    }

    size_t GetRunCount() const {
        return 12345;
    }
};

BENCHMARK_F(BenchmarkSample, BenchmarkTestPostRunSample)

BENCHMARK(BenchmarkSample, BigTest, 2) {
    NSMutableArray* arr = [[NSMutableArray alloc] initWithCapacity:100000];
    for (size_t i = 0; i < 100000; ++i) {
        arr[i] = [NSMutableArray arrayWithCapacity:10000];
    }
    [arr release];
}

class BenchmarkTestMultipleParameters : public ::benchmark::BenchmarkCaseBase {
    CGSize m_size;
    CGFloat m_mult;

public:
    BenchmarkTestMultipleParameters(const ::testing::tuple<CGSize, CGFloat>& params)
        : m_size(::testing::get<0>(params)), m_mult(::testing::get<1>(params)) {
    }

    inline void Run() {
        CGSize other = m_size;
        for (size_t i = 0; i < 1000; ++i) {
            other = other * m_mult;
        }
    }

    size_t GetRunCount() const {
        return 4545;
    }
};

static constexpr CGSize c_sizes[] = { { 0, 0 }, { 0, 512 }, { 256, 0 }, { 256, 512 } };
static constexpr CGFloat c_mults[] = { .1f, 3.25f, 99.99f, 1234.5f, .00001f };

BENCHMARK_REGISTER_CASE_P(BenchmarkSample,
                          BenchmarkTestMultipleParameters,
                          ::testing::Combine(::testing::ValuesIn(c_sizes), ::testing::ValuesIn(c_mults)),
                          ::testing::tuple<CGSize, CGFloat>);