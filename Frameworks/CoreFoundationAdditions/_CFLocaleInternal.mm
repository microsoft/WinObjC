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

// As a part of bridging, any calls must use core foundation calls instead
// of any foundation objects. This workaround here allows us to use the
// APIs in starboard.h
#pragma push_macro("__OBJC__")
#undef __OBJC__

#include "Starboard.h"

#pragma pop_macro("__OBJC__")

#include <CoreFoundation/CoreFoundation.h>
#include "_CFLocaleInternal.h"

#include <COMIncludes.h>
#include <wrl/client.h>
#include <wrl/wrappers/corewrappers.h>
#include <windows.system.userprofile.h>
#include <windows.globalization.h>
#include <COMIncludes_End.h>

using namespace Microsoft::WRL;
using namespace ABI::Windows::System::UserProfile;
using namespace ABI::Windows::Foundation::Collections;
using namespace Windows::Foundation;

#define RETURN_NULL_IF_FAILED(hr) \
    if (FAILED(hr)) {             \
        return nullptr;           \
    }

CFMutableArrayRef EnumerateUserPreferredLanguages() {
    ComPtr<IGlobalizationPreferencesStatics> globalizationPreferences;
    RETURN_NULL_IF_FAILED(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_System_UserProfile_GlobalizationPreferences).Get(),
                             &globalizationPreferences));

    ComPtr<IVectorView<HSTRING>> languages;
    RETURN_NULL_IF_FAILED(globalizationPreferences->get_Languages(languages.GetAddressOf()));

    unsigned int size = 0;
    RETURN_NULL_IF_FAILED(languages->get_Size(&size));

    CFMutableArrayRef languageArray = CFArrayCreateMutable(NULL, size, &kCFTypeArrayCallBacks);
    unsigned int rawLength;

    for (unsigned int i = 0; i < size; ++i) {
        Wrappers::HString wrlString;
        RETURN_NULL_IF_FAILED(languages->GetAt(i, wrlString.GetAddressOf()));

        const wchar_t* rawString = WindowsGetStringRawBuffer(wrlString.Get(), &rawLength);

        // wchar_t to CFStringRef
        CFStringEncoding encoding =
            (CFByteOrderLittleEndian == CFByteOrderGetCurrent()) ? kCFStringEncodingUTF16LE : kCFStringEncodingUTF16BE;
        int stringLength = WindowsGetStringLen(wrlString.Get());

        CFStringRef string = CFStringCreateWithBytes(NULL, (const UInt8*)rawString, (stringLength * sizeof(wchar_t)), encoding, false);

        // Append value to mutable array
        CFArrayAppendValue(languageArray, string);
    }

    return languageArray;
}