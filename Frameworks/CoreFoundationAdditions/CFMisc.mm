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
#include <CoreFoundation/CFBase.h>
#include "CFInternal.h"

#include <COMIncludes.h>
#include <wrl\client.h>
#include <Windows.Foundation.h>
#include <Windows.Security.Cryptography.h>
#include <wrl\wrappers\corewrappers.h>
#include <COMIncludes_End.h>

#import <CoreFoundation/CoreFoundation.h>

#include <mach/mach_time.h>

#include <algorithm>
#include "LoggingNative.h"

static const wchar_t* TAG = L"CFMisc";

using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

ComPtr<ABI::Windows::Security::Cryptography::ICryptographicBufferStatics> GetBufferStatics() {
    ComPtr<ABI::Windows::Security::Cryptography::ICryptographicBufferStatics> bufferStatics;
    if (FAILED(GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_CryptographicBuffer).Get(),
                                    &bufferStatics))) {
        return nullptr;
    }

    return bufferStatics;
}

extern "C" uint32_t arc4random() {
    static ComPtr<ABI::Windows::Security::Cryptography::ICryptographicBufferStatics> bufferStatics(GetBufferStatics());

    UINT32 randResult = 0;
    if (FAILED(bufferStatics->GenerateRandomNumber(&randResult))) {
        TraceVerbose(TAG, L"Unable to get random number!");
    }
    return randResult;
}

extern "C" int sysctlbyname(const char* name, void* out, size_t* outSize, const void*, size_t) {
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

static int64_t _mach_get_timebase() {
    LARGE_INTEGER performanceFrequency;
    CFAssert(0 == QueryPerformanceFrequency(&performanceFrequency), __kCFLogAssertion, "QueryPerformanceFrequency failed");
    return performanceFrequency.QuadPart;
}

static int64_t _mach_frequency = _mach_get_timebase();

extern "C" kern_return_t mach_timebase_info(mach_timebase_info_t tinfo) {
    //  mach_absolute_time uses QueryPerformanceCounter which returns
    //  the absolute number of cycles since boot in microseconds.
    //
    // Return a timebase representing the conversion between QPC counts and nanoseconds:
    // 1,000,000,000 nanoseconds per every n counts.
    *tinfo = { 1000000000, _mach_frequency };

    return 0;
}
