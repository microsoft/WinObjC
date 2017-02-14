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

BENCHMARK(NSOperationQueue, CreateAndAutorelease, 10) {
    @autoreleasepool {
        for (size_t i = 0; i < 1000; ++i) {
            NSOperationQueue* queue = [[NSOperationQueue new] autorelease];
        }
    }
}
class AddOperation : public ::benchmark::BenchmarkCaseBase {
    StrongId<NSOperationQueue> m_queue;

public:
    void PreRun() {
        @autoreleasepool {
            m_queue = [[NSOperationQueue new] autorelease];
        }
    }

    inline void Run() {
        for (size_t i = 0; i < 1000; ++i) {
            [m_queue addOperation:[NSOperation new]];
        }
    }

    void PostRun() {
        for (NSOperation* op in [m_queue operations]) {
            [op release];
        }
    }

    size_t GetRunCount() const {
        return 10;
    }
};

BENCHMARK_F(NSOperationQueue, AddOperation)

class AddOperations : public ::benchmark::BenchmarkCaseBase {
    StrongId<NSMutableArray<NSOperation*>> m_array;
    StrongId<NSOperationQueue> m_queue;
    BOOL m_waitUntilFinished;

public:
    AddOperations(BOOL wait) : m_waitUntilFinished(wait) {
    }

    void PreRun() {
        @autoreleasepool {
            m_array = [[[NSMutableArray<NSOperation*> alloc] initWithCapacity:1000] autorelease];
            m_queue = [[NSOperationQueue new] autorelease];

            for (size_t i = 0; i < 1000; ++i) {
                [m_array addObject:[[NSOperation new] autorelease]];
            }
        }
    }

    inline void Run() {
        [m_queue addOperations:m_array waitUntilFinished:m_waitUntilFinished];
    }

    size_t GetRunCount() const {
        return 10;
    }
};

static constexpr BOOL c_yesNo[] = { YES, NO };
BENCHMARK_REGISTER_CASE_P(NSOperationQueue, AddOperations, ::testing::ValuesIn(c_yesNo), BOOL);