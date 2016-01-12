//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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
#include "windows.h"
#include <string.h>
#include <Foundation/NSProcessInfo.h>

TEST(Foundation, NSProcessInfoGetProperties) {
    // get the process name/id/processor count from windows side
    wchar_t moduleFullPath[_MAX_PATH];
    NSString* processName;
    uint32_t length = ::GetModuleFileNameW(NULL, moduleFullPath, _MAX_PATH);
    ASSERT_TRUE(length > 0 && length < _MAX_PATH);

    wchar_t moduleName[_MAX_FNAME];
    ASSERT_TRUE(::_wsplitpath_s(moduleFullPath, NULL, 0, NULL, 0, moduleName, std::extent<decltype(moduleName)>::value, NULL, 0) == 0);
    processName = [[NSString alloc] initWithCharacters:(const unichar*)moduleName length:wcsnlen_s(moduleName, _MAX_FNAME)];

    int processIdentifier = static_cast<int>(GetCurrentProcessId());
    SYSTEM_INFO systemInfo;
    GetNativeSystemInfo(&systemInfo);
    DWORD processorCount = systemInfo.dwNumberOfProcessors;

    // get the same info from NSProcessInfo side and make sure they are the same
    NSProcessInfo* processInfo = [NSProcessInfo processInfo];

    ASSERT_OBJCEQ_MSG(processName, processInfo.processName, "Process name should be equal");
    ASSERT_TRUE_MSG(processIdentifier == processInfo.processIdentifier, "Process identifier should be equal");
    ASSERT_TRUE_MSG(processorCount == processInfo.processorCount, "Process name should be equal");

    LOG_INFO(@"processName=%@, processor count=%d, process identifier=%d systemUpTime=%dseconds",
             processInfo.processName,
             processInfo.processorCount,
             processInfo.processIdentifier,
             processInfo.systemUptime);

    [processName release];
}