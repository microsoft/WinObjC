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
#include <memory>

#include <CoreFoundation/CoreFoundation.h>

#include "DrawingTestConfig.h"

template <size_t N>
static int strconstprefix(const char* left, const char (&right)[N]) {
    // The null terminator would fail a prefix match; don't count it.
    return strncmp(left, right, N - 1);
}

static std::string __ModuleDirectory() {
    static std::string modulePath = GetCurrentTestDirectory();
    return modulePath;
}

static std::string __OutputDirectory() {
    std::string toReturn;
    toReturn.resize(_MAX_PATH, '\0');
    _getcwd(&toReturn[0], _MAX_PATH);
    return toReturn;
}

class CommandLineDrawingTestConfigImpl : public DrawingTestConfigImpl {
private:
    DrawingTestMode _mode;
    std::string _outputPath;
    std::string _comparisonPath;

public:
    CommandLineDrawingTestConfigImpl(int argc, char** argv)
        : _mode(DrawingTestMode::Compare), _outputPath(__OutputDirectory()), _comparisonPath(__ModuleDirectory() + "/data/reference") {
#ifdef WIN32
        static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

        WEX::Common::String outputPath;
        WEX::TestExecution::RuntimeParameters::TryGetValue(L"out", outputPath);
        if (!outputPath.IsEmpty()) {
            _outputPath = converter.to_bytes(std::wstring(outputPath));
        }

        WEX::Common::String comparisonPath;
        WEX::TestExecution::RuntimeParameters::TryGetValue(L"compare", comparisonPath);
        if (!comparisonPath.IsEmpty()) {
            _comparisonPath = converter.to_bytes(std::wstring(comparisonPath));
        }
#else
        for (int i = 1; i < argc; ++i) {
            char* arg = argv[i];
            if (!arg) {
                break;
            }

            if (strcmp(arg, "--generate") == 0) {
                _mode = DrawingTestMode::Generate;
            } else if (strconstprefix(arg, "--out=") == 0) {
                _outputPath = std::move(std::string(arg + 6));
            } else if (strconstprefix(arg, "--compare=") == 0) {
                _comparisonPath = std::move(std::string(arg + 10));
            }
        }
#endif
    }

    virtual DrawingTestMode GetMode() override {
        return _mode;
    }

    virtual std::string GetOutputPath() override {
        return _outputPath;
    }

    virtual std::string GetComparisonPath() override {
        return _comparisonPath;
    }

    virtual std::string GetResourcePath(const std::string& resource) override {
        // Using / as a path separator is valid on both Windows and OS X.
        return __ModuleDirectory() + "/data/" + resource;
    }
};

std::shared_ptr<DrawingTestConfigImpl> _configImpl;
/* static */ DrawingTestConfigImpl* DrawingTestConfig::Get() {
    return _configImpl.get();
}

#ifdef WIN32
#include <roapi.h>
#include <WexTestClass.h>
#include <wrl\client.h>
#include <wrl\wrappers\corewrappers.h>
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

    if (FAILED(Windows::Foundation::GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Storage_ApplicationData).Get(),
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
#endif

#ifdef WIN32
BEGIN_MODULE()
MODULE_PROPERTY(L"RunAs", L"UAP")
END_MODULE()

MODULE_SETUP(ModuleSetup) {
#else
int main(int argc, char** argv) {
#endif

#ifdef WIN32
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
#endif
    testing::InitGoogleTest(&argc, argv);

    _configImpl = std::move(std::make_shared<CommandLineDrawingTestConfigImpl>(argc, argv));

#ifdef WIN32
    return TRUE;
#else
    auto result = RUN_ALL_TESTS();
    return result;
#endif
}

#ifdef WIN32
MODULE_CLEANUP(ModuleCleanup) {
    RoUninitialize();
    return true;
}
#endif