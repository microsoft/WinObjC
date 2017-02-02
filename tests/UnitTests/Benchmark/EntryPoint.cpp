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

#include <windows.h>
#include <TestFramework.h>
#include "BenchmarkTestPublisher.h"
#include <fstream>

#ifdef WIN32
#include <wrl\wrappers\corewrappers.h>
using namespace Microsoft::WRL::Wrappers;
#endif

using namespace benchmark;
class CSVBenchmarkTestPublisher : public BenchmarkTestPublisher {
    struct result {
        std::string testName;
        Microseconds totalRuntime;
        Microseconds meanRuntime;
        Microseconds stdDeviation;
    };
    std::string m_outPath;
    std::vector<result> m_results;

public:
    CSVBenchmarkTestPublisher(std::string&& outPath) : m_outPath(outPath) {
    }
    virtual void RegisterTestResults(const std::string& testName, const std::vector<Microseconds>& results) {
        size_t runCount = results.size();
        if (runCount > 1) {
            // Algorithm for calculating sample mean and variance with minimal rounding errors
            Microseconds netRuntime = 0.0;
            Microseconds mean = 0.0;
            Microseconds q = 0.0;
            for (size_t i = 0; i < runCount; ++i) {
                Microseconds previousMean = mean;
                netRuntime += results[i];
                mean += (results[i] - mean) / (i + 1);
                q += (results[i] - previousMean) * (results[i] - mean);
            }
            Microseconds sampleStandardDeviation = std::sqrt(q / (runCount - 1));
            m_results.emplace_back(result{ testName, netRuntime, mean, sampleStandardDeviation });
        } else {
            m_results.emplace_back(result{ testName,
                                           results[0],
                                           std::numeric_limits<Microseconds>::infinity(),
                                           std::numeric_limits<Microseconds>::infinity() });
        }
    }

    virtual void PublishTestResults() {
        std::ofstream outFile(m_outPath);
        outFile << "Test Name"
                << ","
                << "Total Runtime"
                << ","
                << "Mean Runtime"
                << ","
                << "Standard Deviation"
                << "\n";
        for (auto res : m_results) {
            outFile << res.testName << "," << res.totalRuntime << "," << res.meanRuntime << "," << res.stdDeviation << "\n";
        }

        outFile.flush();
        outFile.close();
    }
};

static std::shared_ptr<BenchmarkTestPublisher> s_publisher;
void BenchmarkTestCreator::CreatePublisher(int argc, char** argv) {
    // Currently only support CSV format
    for (int i = 1; i < argc && argv[i]; ++i) {
        char* arg = argv[i];
        if (strncmp(arg, "--out=", 6) == 0) {
            s_publisher.reset(new CSVBenchmarkTestPublisher(std::move(std::string(arg + 6))));
            return;
        }
    }

    LOG_ERROR("Unknown arguments given to Benchmark Tests");
}

std::shared_ptr<BenchmarkTestPublisher> BenchmarkTestCreator::GetPublisher() {
    return s_publisher;
}

int main(int argc, char** argv) {
#ifdef WIN32
    // Initialize the windows runtime, with uninitialized upon destructor invocation.
    RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
    if (FAILED(initialize)) {
        return -1;
    }
#endif
    BenchmarkTestCreator::CreatePublisher(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    auto result = RUN_ALL_TESTS();
    BenchmarkTestCreator::GetPublisher()->PublishTestResults();
    return result;
}