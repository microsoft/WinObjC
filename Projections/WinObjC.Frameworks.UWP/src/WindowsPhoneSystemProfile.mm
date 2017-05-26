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

// WindowsPhoneSystemProfile.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.System.Profile.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneSystemProfile.h"
#include "WindowsPhoneSystemProfile_priv.h"

@implementation WPSPRetailMode

ComPtr<ABI::Windows::Phone::System::Profile::IRetailModeStatics> WPSPIRetailModeStatics_inst() {
    ComPtr<ABI::Windows::Phone::System::Profile::IRetailModeStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.System.Profile.RetailMode").Get(), &inst));
    return inst;
}

+ (BOOL)retailModeEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WPSPIRetailModeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RetailModeEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end
