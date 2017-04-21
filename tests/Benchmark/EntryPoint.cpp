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

#include <TestFramework.h>
#include "BenchmarkPublisher.h"
#include <fstream>
#include <algorithm>

#include <roapi.h>
#include <wrl/client.h>
#include <wrl/wrappers/corewrappers.h>
#include <windows.storage.h>

using namespace ABI::Windows::Storage;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;

Wrappers::HString GetAppDataPath() {
    Wrappers::HString toReturn;
    ComPtr<IStorageFolder> folder;
    ComPtr<IApplicationDataStatics> applicationDataStatics;
    ComPtr<IApplicationData> applicationData;
    ComPtr<IStorageItem> storageItem;

    if (FAILED(GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Storage_ApplicationData).Get(),
                                    &applicationDataStatics))) {
        return toReturn;
    }

    if (FAILED(applicationDataStatics->get_Current(&applicationData))) {
        return toReturn;
    }

    if (FAILED(applicationData->get_LocalFolder(&folder))) {
        return toReturn;
    }

    if (FAILED(folder.As<IStorageItem>(&storageItem))) {
        return toReturn;
    }

    if (FAILED(storageItem->get_Path(toReturn.GetAddressOf()))) {
        return toReturn;
    }

    return toReturn;
}

using namespace benchmark;
struct __Result {
    std::string testName;
    Microseconds totalRuntime;
    Microseconds minRuntime;
    Microseconds meanRuntime;
    Microseconds medianRuntime;
    Microseconds stdDeviation;
    size_t runCount;
};

class PublisherBase : public BenchmarkPublisher {
public:
    // Expect results.size() > 1
    virtual void RegisterCaseResults(const std::string& caseName, std::vector<Microseconds>& results) {
        // Algorithm for calculating sample mean and variance with minimal rounding errors
        Microseconds netRuntime = 0.0;
        Microseconds minRuntime = FLT_MAX;
        Microseconds mean = 0.0;
        Microseconds q = 0.0;
        size_t runCount = results.size();
        for (size_t i = 0; i < runCount; ++i) {
            Microseconds previousMean = mean;
            minRuntime = min(minRuntime, results[i]);
            netRuntime += results[i];
            mean += (results[i] - mean) / (i + 1);
            q += (results[i] - previousMean) * (results[i] - mean);
        }

        Microseconds sampleStandardDeviation = std::sqrt(q / (runCount - 1));
        std::nth_element(results.begin(), results.begin() + runCount / 2, results.end());
        Microseconds median = results[runCount / 2];

        if ((runCount & 1) == 0) {
            // Median is the mean of the two central elements
            std::nth_element(results.begin(), results.begin() + (runCount / 2) - 1, results.end());
            median = (median + results[(runCount / 2) - 1]) / 2.0;
        }

        m_results.emplace_back(__Result{ caseName, netRuntime, minRuntime, mean, median, sampleStandardDeviation, runCount });
    }

protected:
    std::vector<__Result> m_results;
};

class CSVBenchmarkPublisher : public PublisherBase {
    std::wstring m_outPath;

public:
    CSVBenchmarkPublisher(std::wstring&& outPath) : m_outPath(outPath) {
    }

    virtual void PublishResults() {
        std::ofstream outFile(m_outPath);
        outFile << "Case Name"
                << ","
                << "Total Runtime"
                << ","
                << "Min Runtime"
                << ","
                << "Mean Runtime"
                << ","
                << "Median Runtime"
                << ","
                << "Standard Deviation"
                << ","
                << "Run Count" << std::endl;
        for (auto res : m_results) {
            outFile << res.testName << "," << res.totalRuntime << "," << res.minRuntime << "," << res.meanRuntime << ","
                    << res.medianRuntime << "," << res.stdDeviation << "," << res.runCount << std::endl;
        }

        outFile.flush();
        outFile.close();

        // Actually saves the file since this is running as TAEF
        WEX::Logging::Log::File(m_outPath.c_str());
        m_results.clear();
    }
};

static std::shared_ptr<BenchmarkPublisher> s_publisher;
void BenchmarkPublisherFactory::CreatePublisher(int argc, char** argv) {
    // Currently only support CSV format
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    WEX::Common::String outputPath;
    WEX::TestExecution::RuntimeParameters::TryGetValue(L"output", outputPath);
    if (!outputPath.IsEmpty()) {
        s_publisher.reset(new CSVBenchmarkPublisher(std::wstring(outputPath)));
    }

    if (!s_publisher) {
        WEX::Logging::Log::Comment(L"Using default output filename");
        s_publisher.reset(new CSVBenchmarkPublisher(std::wstring(L"benchmark_results.csv")));
    }
}

std::shared_ptr<BenchmarkPublisher> BenchmarkPublisherFactory::GetPublisher() {
    return s_publisher;
}

BEGIN_MODULE()
MODULE_PROPERTY(L"RunAs", L"UAP")
MODULE_PROPERTY(L"UAP:AppXManifest", L"Default.AppxManifest.xml")
END_MODULE()

MODULE_SETUP(ModuleSetup) {
    if (FAILED(RoInitialize(RO_INIT_MULTITHREADED))) {
        return FALSE;
    }

    Wrappers::HString path = GetAppDataPath();
    if (path.IsValid()) {
        unsigned int rawLength;
        _wchdir(WindowsGetStringRawBuffer(path.Get(), &rawLength));
    }

    int argc = 1;
    char* argv[] = { "UnitTests" };

    BenchmarkPublisherFactory::CreatePublisher(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return TRUE;
}

MODULE_CLEANUP(ModuleCleanup) {
    BenchmarkPublisherFactory::GetPublisher()->PublishResults();
    RoUninitialize();
    return true;
}
