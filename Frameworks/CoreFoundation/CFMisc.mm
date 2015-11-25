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

#include <Starboard.h>

#include <COMIncludes.h>
#include <Windows.Foundation.h>
#include <Windows.Security.Cryptography.h>
#include <wrl\wrappers\corewrappers.h>
#include <COMIncludes_End.h>

#import <CoreFoundation/CoreFoundation.h>

#include <unistd.h>
#include <mach/mach_time.h>

#include <algorithm>

using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

extern "C" void* _OBJC_CLASS_CFConstantString = NULL;
static ABI::Windows::Security::Cryptography::ICryptographicBufferStatics* bufferStatics = nullptr;

COREFOUNDATION_EXPORT extern "C" uint32_t arc4random() {
    if (bufferStatics == nullptr) {
        if (!SUCCEEDED(
                GetActivationFactory(HStringReference(L"Windows.Security.Cryptography.CryptographicBuffer").Get(), &bufferStatics))) {
            EbrDebugLog("Unable to get CryptographicBuffer interface!\n");
        }
    }

    UINT32 randResult = 0;
    if (!SUCCEEDED(bufferStatics->GenerateRandomNumber(&randResult))) {
        EbrDebugLog("Unable to get random number!\n");
    }
    return randResult;
}

COREFOUNDATION_EXPORT extern "C" int usleep(useconds_t secs) {
    Sleep(secs * 1000);
    return 0;
}

COREFOUNDATION_EXPORT extern "C" unsigned int sleep(useconds_t secs) {
    Sleep(secs * 1000);
    return 0;
}

COREFOUNDATION_EXPORT extern "C" int sysctlbyname(const char* name, void* out, size_t* outSize, const void*, size_t) {
    if (strcmp(name, "hw.machine") == 0) {
        const int required = 8;
        size_t receivedOutSize = 0;
        if (outSize) {
            receivedOutSize = *outSize;
            // If there's no buffer, we have to return the nr. of bytes required for
            // this response.
            *outSize = !out ? required : std::min(*outSize, (size_t)required);
        } else {
            return -1;
        }

        if (out) {
            size_t sizeToCopy = (*outSize == 0) ? (*outSize) : (*outSize - 1);
            strncpy_s((char*)out, receivedOutSize, "winobjc", sizeToCopy); // outsize is <= required here
        }
        return *outSize < required ? ENOMEM : 0;
    }
    return -1;
}

/**
 @Status Stub
 @Notes Returns the CFString "Desc"
*/
CFStringRef CFCopyDescription(CFTypeRef ref) {
    UNIMPLEMENTED();
    return (CFStringRef) @"Desc";
}

static int64_t _mach_get_timebase() {
    LARGE_INTEGER performanceFrequency;
    FAIL_FAST_IF(0 == QueryPerformanceFrequency(&performanceFrequency));
    return performanceFrequency.QuadPart;
}

static int64_t _mach_frequency = _mach_get_timebase();

COREFOUNDATION_EXPORT uint64_t mach_absolute_time() {
    LARGE_INTEGER current;
    FAIL_FAST_IF(0 == QueryPerformanceCounter(&current));

    return static_cast<uint64_t>(current.QuadPart);
}

COREFOUNDATION_EXPORT kern_return_t mach_timebase_info(mach_timebase_info_t tinfo) {
    //  mach_absolute_time uses QueryPerformanceCounter which returns
    //  the absolute number of cycles since boot in microseconds.
    //
    // Return a timebase representing the conversion between QPC counts and nanoseconds:
    // 1,000,000,000 nanoseconds per every n counts.
    *tinfo = {1000000000, _mach_frequency};

    return 0;
}
