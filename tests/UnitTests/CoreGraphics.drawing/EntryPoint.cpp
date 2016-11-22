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
    return strncmp(left, right, N-1);
}

static std::string __ModuleDirectory() {
    static std::string modulePath = []() {
        std::string modulePath(MAX_PATH, '\0');
        GetModuleFileNameA(nullptr, &modulePath[0], modulePath.capacity());
        auto pos = modulePath.rfind('\\');
        if (pos == std::string::npos) {
            pos = modulePath.rfind('/');
        }

        if (pos != std::string::npos) {
            modulePath.erase(pos);
        }

        return modulePath;
    }();
    return modulePath;
}

class CommandLineDrawingTestConfigImpl : public DrawingTestConfigImpl {
private:
    DrawingTestMode _mode;
    std::string _outputPath;
    std::string _comparisonPath;

public:
    CommandLineDrawingTestConfigImpl(int argc, char** argv)
        : _mode(DrawingTestMode::Compare), _outputPath(__ModuleDirectory()), _comparisonPath(__ModuleDirectory() + "/data/reference") {
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
};

std::shared_ptr<DrawingTestConfigImpl> _configImpl;
/* static */ DrawingTestConfigImpl* DrawingTestConfig::Get() {
    return _configImpl.get();
}

#ifdef WIN32
#include <COMIncludes.h>
#include <wrl\wrappers\corewrappers.h>
#include <COMIncludes_end.h>
using namespace Microsoft::WRL::Wrappers;
#endif

int main(int argc, char** argv) {
#ifdef WIN32
    // Initialize the windows runtime, with uninitialized upon destructor invocation.
    RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
    if (FAILED(initialize)) {
        return -1;
    }
#endif
    testing::InitGoogleTest(&argc, argv);

    _configImpl = std::move(std::make_shared<CommandLineDrawingTestConfigImpl>(argc, argv));

    auto result = RUN_ALL_TESTS();
    return result;
}