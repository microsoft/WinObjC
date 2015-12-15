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

#include "Starboard.h"
#include <math.h>
#include <windows.h>
#include <string>

#include "Foundation/NSString.h"
#include "Foundation/NSProcessInfo.h"

static id _processInfo;

static IWLazyClassLookup _LazyUIDevice("UIDevice");

static inline OSVERSIONINFO winOsVersion() {
    OSVERSIONINFO result = { sizeof(OSVERSIONINFO), 0, 0, 0, 0, { '\0' } };

    MEMORY_BASIC_INFORMATION mbi = { 0 };
    if (VirtualQuery(VirtualQuery, &mbi, sizeof(mbi)) == 0)
        return result;

    HMODULE kernelModule = reinterpret_cast<HMODULE>(mbi.AllocationBase);
    if (!kernelModule)
        return result;

    typedef HMODULE(WINAPI * GetModuleHandleFunction)(LPCTSTR);
    GetModuleHandleFunction pGetModuleHandle = reinterpret_cast<GetModuleHandleFunction>(GetProcAddress(kernelModule, "GetModuleHandleW"));
    if (!pGetModuleHandle)
        return result;

    HMODULE ntdll = pGetModuleHandle(TEXT("ntdll.dll"));
    if (!ntdll)
        return result;

    // NTSTATUS is not defined on WinRT
    typedef LONG /* NTSTATUS */ (NTAPI * RtlGetVersionFunction)(LPOSVERSIONINFO);
    RtlGetVersionFunction pRtlGetVersion = reinterpret_cast<RtlGetVersionFunction>(GetProcAddress(ntdll, "RtlGetVersion"));
    if (!pRtlGetVersion)
        return result;

    // GetVersionEx() has been deprecated in Windows 8.1 and will return
    // only Windows 8 from that version on, so use the kernel API function.
    pRtlGetVersion(&result); // always returns STATUS_SUCCESS
    return result;
}

@implementation NSProcessInfo

/**
 @Status Interoperable
*/
+ (NSProcessInfo*)processInfo {
    return _processInfo;
}

+ (void)initialize {
    _processInfo = [self new];
}

- (instancetype)init {
    // set up environment, currently only HOME and TMPDIR
    _environment = [NSMutableDictionary new];
    [_environment setObject:[[NSBundle mainBundle] bundlePath] forKey:@"HOME"];
    [_environment setObject:@"/tmp" forKey:@"TMPDIR"];

    // get process id
    _processIdentifier = static_cast<int>(GetCurrentProcessId());

    // get process name
    [self _initProcessName];

    // get processor count
    SYSTEM_INFO systemInfo;
    GetNativeSystemInfo(&systemInfo);
    _processorCount = systemInfo.dwNumberOfProcessors;

    return self;
}

// get the process name
- (void)_initProcessName {
    try {
        std::wstring moduleFullPath(_MAX_PATH, L'\0');

        do {
            size_t length = ::GetModuleFileNameW(nullptr, &moduleFullPath[0], moduleFullPath.length());
            if (length == 0) {
                FAIL_FAST_LAST_ERROR();
            } else if (length == moduleFullPath.length()) {
                // buffer is too small, double the size
                assert(::GetLastError() == ERROR_INSUFFICIENT_BUFFER);
                moduleFullPath.resize(length * 2, L'\0');
            } else {
                // succeess, and resize to fit the actual needed
                moduleFullPath.resize(length);
                break;
            }
        } while (true);

        // now get the module name, which should not contain extension
        size_t dot = moduleFullPath.find_last_of(L'.');
        size_t slash = moduleFullPath.find_last_of(L'\\');
        FAIL_FAST_HR_IF(E_UNEXPECTED, dot == 0 || slash > dot);

        _processName = [[NSString alloc] initWithBytes:(const void*)&moduleFullPath[slash + 1]
                                                length:(dot - slash - 1) * sizeof(wchar_t)
                                              encoding:NSUnicodeStringEncoding];
    } CATCH_THROW_NSEXCEPTION();
}

/**
 @Status Caveat
 @Notes return processorCount instead given GetActiveProcessorCount isn't available on UWP

*/
- (NSUInteger)activeProcessorCount {
    // TODO: call GetActiveProcessorCount or similar API when it is available
    return _processorCount;
}

/**
 @Status Interoperable
*/
- (NSString*)globallyUniqueString {
    CFUUIDRef uuid = CFUUIDCreate(nullptr);
    NSString* ret = (NSString*)CFUUIDCreateString(nullptr, uuid);

    CFRelease(uuid);

    return [ret autorelease];
}

/**
 @Status Interoperable
 @Notes Returns Windows version
*/
- (NSOperatingSystemVersion)operatingSystemVersion {
    const OSVERSIONINFO info = winOsVersion();
    return (NSOperatingSystemVersion){ info.dwMajorVersion, info.dwMinorVersion, info.dwBuildNumber };
}

/**
 @Status Interoperable
 @Notes Compares against Windows version
*/
- (BOOL)isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion)version {
    const NSOperatingSystemVersion systemVersion = [self operatingSystemVersion];
    if (systemVersion.majorVersion == version.majorVersion) {
        if (systemVersion.minorVersion == version.minorVersion) {
            return systemVersion.patchVersion >= version.patchVersion;
        }
        return systemVersion.minorVersion >= version.minorVersion;
    }
    return systemVersion.majorVersion >= version.majorVersion;
}

/**
 @Status Caveat
 @Notes only support windows 10
*/
- (NSString*)operatingSystemVersionString {
    return @"Windows 10.0";
}

/**
 @Status Interoperable
*/
- (double)systemUptime {
    // NOTE: despite the name, GetTickCount64 really return number of milliseconds
    // and systemUptime need to return number of seconds.
    return ::GetTickCount64() / 1000.0;
}

/**
 @Status Interoperable
 @Notes only support WindowsNT
*/
- (NSUInteger)operatingSystem {
    return NSWindowsNTOperatingSystem;
}

/**
 @Status Interoperable
 @Notes support WindowsNT
*/
- (NSString*)operatingSystemName {
    return @"NSWindowsNTOperatingSystem";
}

/**
 @Status Stub
*/
- (id<NSObject>)beginActivityWithOptions:(NSActivityOptions)options reason:(NSString*)reason {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
- (void)endActivity:(id)activity {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)performActivityWithOptions:(NSActivityOptions)options reason:(NSString*)reason usingBlock:(void (^)(void))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)performExpiringActivityWithReason:(NSString*)reason usingBlock:(void (^)(BOOL expired))block {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (uint64_t)physicalMemory {
    return [_LazyUIDevice _deviceTotalMemory];
}

- (void)dealloc {
    [_processName release];
    [_environment release];

    [super dealloc];
}

@end
