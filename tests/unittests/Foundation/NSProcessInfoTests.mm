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

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import <string.h>
#import <windows.h>

// Accessors for process info differ between platforms
#if !TARGET_OS_WIN32
#import <libproc.h>
#endif

int processIdentifier = static_cast<int>(GetCurrentProcessId());

TEST(NSProcessInfo, NSProcessInfoGetProperties) {
    // Accessors for process name differ between platforms
    NSString* processName;
#if TARGET_OS_WIN32
    // get the process name/id/processor count from windows side
    wchar_t moduleFullPath[_MAX_PATH];
    uint32_t length = ::GetModuleFileNameW(NULL, moduleFullPath, _MAX_PATH);
    ASSERT_TRUE(length > 0 && length < _MAX_PATH);

    wchar_t moduleName[_MAX_FNAME];
    ASSERT_TRUE(::_wsplitpath_s(moduleFullPath, NULL, 0, NULL, 0, moduleName, std::extent<decltype(moduleName)>::value, NULL, 0) == 0);
    processName = [NSString stringWithCharacters:(const unichar*)moduleName length:wcsnlen_s(moduleName, _MAX_FNAME)];
#else
    char moduleFullPath[_MAX_PATH];
    proc_name(processIdentifier, moduleFullPath, _MAX_PATH);
    processName = [NSString stringWithUTF8String:moduleFullPath];
#endif

    // Accessors for processor count differ between platforms
    DWORD processorCount;
#if TARGET_OS_WIN32
    SYSTEM_INFO systemInfo;
    GetNativeSystemInfo(&systemInfo);
    processorCount = systemInfo.dwNumberOfProcessors;
#else
    processorCount = sysconf(_SC_NPROCESSORS_ONLN);
#endif

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
}