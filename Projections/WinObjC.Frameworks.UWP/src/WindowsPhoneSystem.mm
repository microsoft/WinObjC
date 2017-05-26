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

// WindowsPhoneSystem.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.System.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneSystem.h"
#include "WindowsPhoneSystem_priv.h"

@implementation WPSSystemProtection

ComPtr<ABI::Windows::Phone::System::ISystemProtectionStatics> WPSISystemProtectionStatics_inst() {
    ComPtr<ABI::Windows::Phone::System::ISystemProtectionStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.System.SystemProtection").Get(), &inst));
    return inst;
}

+ (BOOL)screenLocked {
    boolean unmarshalledReturn;
    auto _comInst = WPSISystemProtectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ScreenLocked(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

ComPtr<ABI::Windows::Phone::System::ISystemProtectionUnlockStatics> WPSISystemProtectionUnlockStatics_inst() {
    ComPtr<ABI::Windows::Phone::System::ISystemProtectionUnlockStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.System.SystemProtection").Get(), &inst));
    return inst;
}

+ (void)requestScreenUnlock {
    auto _comInst = WPSISystemProtectionUnlockStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestScreenUnlock());
}

@end
