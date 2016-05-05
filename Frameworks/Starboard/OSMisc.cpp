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
#include <wrl\client.h>
#include <Windows.Foundation.h>
#include <Windows.Security.Cryptography.h>
#include <wrl\wrappers\corewrappers.h>
#include <COMIncludes_End.h>

#include <algorithm>
#include <mach/mach_defs.h>
#include "LoggingNative.h"

static const wchar_t* TAG = L"OSMisc";

using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

ComPtr<ABI::Windows::Security::Cryptography::ICryptographicBufferStatics> GetBufferStatics() {
    ComPtr<ABI::Windows::Security::Cryptography::ICryptographicBufferStatics> bufferStatics;
    RETURN_NULL_IF_FAILED(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Security_Cryptography_CryptographicBuffer).Get(),
                             &bufferStatics));
    return bufferStatics;
}

extern "C" uint32_t arc4random() {
    static ComPtr<ABI::Windows::Security::Cryptography::ICryptographicBufferStatics> bufferStatics(GetBufferStatics());

    UINT32 randResult = 0;
    FAIL_FAST_IF(!SUCCEEDED(bufferStatics->GenerateRandomNumber(&randResult)));
    return randResult;
}

extern "C" uint32_t arc4random_uniform(uint32_t upperbound) {
    if (upperbound == 0) {
        TraceError(TAG, L"arc4random_uniform: Invalid upper bound");
        FAIL_FAST();
    }

    static ComPtr<ABI::Windows::Security::Cryptography::ICryptographicBufferStatics> bufferStatics(GetBufferStatics());

    UINT32 randResult = 0;
    UINT32 highestMultipleOfUpperBound = ULONG_MAX - (ULONG_MAX % upperbound);

    // Constrict the result so it is < upperbound. In order to get a uniform result distribution, we generate a new random number
    // when the result of GenerateRandomNumber falls within the range [highestMultipleOfUpperBound, ULONG_MAX]
    do {
        FAIL_FAST_IF(!SUCCEEDED(bufferStatics->GenerateRandomNumber(&randResult)));
    } while (randResult >= highestMultipleOfUpperBound);

    return randResult % upperbound;
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

