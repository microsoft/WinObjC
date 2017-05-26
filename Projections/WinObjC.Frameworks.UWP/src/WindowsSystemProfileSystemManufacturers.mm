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

// WindowsSystemProfileSystemManufacturers.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.Profile.SystemManufacturers.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemProfileSystemManufacturers.h"
#include "WindowsSystemProfileSystemManufacturers_priv.h"

@implementation WSPSSmbiosInformation

ComPtr<ABI::Windows::System::Profile::SystemManufacturers::ISmbiosInformationStatics> WSPSISmbiosInformationStatics_inst() {
    ComPtr<ABI::Windows::System::Profile::SystemManufacturers::ISmbiosInformationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.System.Profile.SystemManufacturers.SmbiosInformation").Get(), &inst));
    return inst;
}

+ (NSString*)serialNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = WSPSISmbiosInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SerialNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end
