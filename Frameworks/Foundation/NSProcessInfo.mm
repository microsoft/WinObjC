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
    GetModuleHandleFunction pGetModuleHandle =
        reinterpret_cast<GetModuleHandleFunction>(GetProcAddress(kernelModule, "GetModuleHandleW"));
    if (!pGetModuleHandle)
        return result;

    HMODULE ntdll = pGetModuleHandle(TEXT("ntdll.dll"));
    if (!ntdll)
        return result;

    // NTSTATUS is not defined on WinRT
    typedef LONG /* NTSTATUS */ (NTAPI * RtlGetVersionFunction)(LPOSVERSIONINFO);
    RtlGetVersionFunction pRtlGetVersion =
        reinterpret_cast<RtlGetVersionFunction>(GetProcAddress(ntdll, "RtlGetVersion"));
    if (!pRtlGetVersion)
        return result;

    // GetVersionEx() has been deprecated in Windows 8.1 and will return
    // only Windows 8 from that version on, so use the kernel API function.
    pRtlGetVersion(&result); // always returns STATUS_SUCCESS
    return result;
}

@implementation NSProcessInfo : NSObject
+ (NSProcessInfo*)processInfo {
    return _processInfo;
}

+ (void)initialize {
    _processInfo = [self new];
}

- (instancetype)init {
    _environment = [NSMutableDictionary new];

    [_environment setObject:[[NSBundle mainBundle] bundlePath] forKey:@"HOME"];
    [_environment setObject:@"/tmp" forKey:@"TMPDIR"];

    return self;
}

- (NSString*)globallyUniqueString {
    CFUUIDRef uuid = CFUUIDCreate(nil);
    NSString* ret = (NSString*)CFUUIDCreateString(nil, uuid);

    CFRelease(uuid);

    return [ret autorelease];
}

- (NSOperatingSystemVersion)operatingSystemVersion {
    const OSVERSIONINFO info = winOsVersion();
    return (NSOperatingSystemVersion){ info.dwMajorVersion, info.dwMinorVersion, info.dwBuildNumber };
}

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

- (NSString*)operatingSystemVersionString {
    return @"iOS 3.2";
}

- (NSString*)processName {
    return @"MainProcess";
}

- (int)processIdentifier {
    return 12345;
}

- (double)systemUptime {
    return 60.0 * 5.0;
}

- (NSDictionary*)environment {
    return _environment;
}

- (unsigned)processorCount {
    return 2;
}

- (uint64_t)physicalMemory {
    return [_LazyUIDevice _deviceTotalMemory];
}

@end
