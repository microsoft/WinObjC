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

#include "DrawingTestConfig.h"

class CommandLineDrawingTestConfigImpl : public DrawingTestConfigImpl {
private:
    DrawingTestMode _mode;
    std::string _outputPath;
    std::string _comparisonPath;

public:
    CommandLineDrawingTestConfigImpl(int argc, char** argv)
        : _mode(DrawingTestMode::Compare), _outputPath("."), _comparisonPath("./data/reference") {
        for (int i = 1; i < argc; ++i) {
            char* arg = argv[i];
            if (!arg) {
                break;
            }

            if (strcmp(arg, "--generate") == 0) {
                _mode = DrawingTestMode::Generate;
            } else if (strncmp(arg, "--out=", 6) == 0) {
                _outputPath = std::move(std::string(arg + 6));
            } else if (strncmp(arg, "--compare=", 10) == 0) {
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
#include <wrl\wrappers\corewrappers.h>
using namespace Microsoft::WRL::Wrappers;
#endif

int main(int argc, char** argv) {
    // TODO GH#1124 When we have a bitmap context, enable all these tests.
    exit(0);

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