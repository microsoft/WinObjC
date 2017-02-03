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
#include "BenchmarkPublisher.h"
#include <fstream>
#include <algorithm>

#ifdef WIN32
#include <wrl/wrappers/corewrappers.h>
using namespace Microsoft::WRL::Wrappers;
#endif

using namespace benchmark;
struct __Result {
    std::string testName;
    Microseconds totalRuntime;
    Microseconds meanRuntime;
    Microseconds stdDeviation;
    size_t runCount;
};

class PublisherBase : public BenchmarkPublisher {
public:
    // Expect results.size() > 1
    virtual void RegisterCaseResults(const std::string& caseName, const std::vector<Microseconds>& results) {
        // Algorithm for calculating sample mean and variance with minimal rounding errors
        Microseconds netRuntime = 0.0;
        Microseconds mean = 0.0;
        Microseconds q = 0.0;
        size_t runCount = results.size();
        for (size_t i = 0; i < runCount; ++i) {
            Microseconds previousMean = mean;
            netRuntime += results[i];
            mean += (results[i] - mean) / (i + 1);
            q += (results[i] - previousMean) * (results[i] - mean);
        }
        Microseconds sampleStandardDeviation = std::sqrt(q / (runCount - 1));
        m_results.emplace_back(__Result{ caseName, netRuntime, mean, sampleStandardDeviation, runCount });
    }

protected:
    std::vector<__Result> m_results;
};

class CSVBenchmarkPublisher : public PublisherBase {
    std::string m_outPath;

public:
    CSVBenchmarkPublisher(std::string&& outPath) : m_outPath(outPath) {
    }

    virtual void PublishResults() {
        std::ofstream outFile(m_outPath);
        outFile << "Case Name"
                << ","
                << "Total Runtime"
                << ","
                << "Mean Runtime"
                << ","
                << "Standard Deviation"
                << ","
                << "Run Count"
                << "\n";
        for (auto res : m_results) {
            outFile << res.testName << "," << res.totalRuntime << "," << res.meanRuntime << "," << res.stdDeviation << "," << res.runCount
                    << "\n";
        }

        outFile.flush();
        outFile.close();
        m_results.clear();
    }
};

class LogBenchmarkPublisher : public PublisherBase {
    size_t m_maxNameWidth = 0;

public:
    virtual void RegisterCaseResults(const std::string& testName, const std::vector<Microseconds>& results) {
        m_maxNameWidth = max(m_maxNameWidth, testName.size());
        PublisherBase::RegisterCaseResults(testName, results);
    }

    virtual void PublishResults() {
        // Align output horizontally
        std::string spaces(m_maxNameWidth - 5, ' ');
        std::cout << "Case Name" << spaces << "|"
                  << "Total Runtime"
                  << "\t\t|"
                  << "Mean Runtime"
                  << "\t\t|"
                  << "Standard Deviation"
                  << "\t|"
                  << "Run Count"
                  << "\n";
        for (auto res : m_results) {
            std::string spaces(m_maxNameWidth - res.testName.size() + 4, ' ');
            std::cout << std::fixed << res.testName << spaces << "|" << res.totalRuntime << "\t\t|" << res.meanRuntime << "\t\t|"
                      << res.stdDeviation << "\t\t|" << res.runCount << "\n";
        }

        std::cout << std::endl;
        m_results.clear();
    }
};

static std::shared_ptr<BenchmarkPublisher> s_publisher;
void BenchmarkPublisherFactory::CreatePublisher(int argc, char** argv) {
    // Currently only support CSV format
    bool created = false;
    for (int i = 1; i < argc && argv[i]; ++i) {
        char* arg = argv[i];
        if (strncmp(arg, "--out=", 6) == 0) {
            s_publisher.reset(new CSVBenchmarkPublisher(std::move(std::string(arg + 6))));
            created = true;
        }
    }

    if (!created) {
        LOG_INFO("No arguments given to benchmark. Defaulting to logging results");
        s_publisher.reset(new LogBenchmarkPublisher());
    }
}

std::shared_ptr<BenchmarkPublisher> BenchmarkPublisherFactory::GetPublisher() {
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
    BenchmarkPublisherFactory::CreatePublisher(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    auto result = RUN_ALL_TESTS();
    BenchmarkPublisherFactory::GetPublisher()->PublishResults();
    return result;
}