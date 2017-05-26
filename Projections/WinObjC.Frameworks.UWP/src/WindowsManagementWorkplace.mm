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

// WindowsManagementWorkplace.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Management.Workplace.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsManagementWorkplace.h"
#include "WindowsManagementWorkplace_priv.h"

@implementation WMWMdmPolicy

ComPtr<ABI::Windows::Management::Workplace::IMdmPolicyStatics2> WMWIMdmPolicyStatics2_inst() {
    ComPtr<ABI::Windows::Management::Workplace::IMdmPolicyStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Management.Workplace.MdmPolicy").Get(), &inst));
    return inst;
}

+ (WMWMessagingSyncPolicy)getMessagingSyncPolicy {
    ABI::Windows::Management::Workplace::MessagingSyncPolicy unmarshalledReturn;
    auto _comInst = WMWIMdmPolicyStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetMessagingSyncPolicy(&unmarshalledReturn));
    return (WMWMessagingSyncPolicy)unmarshalledReturn;
}

ComPtr<ABI::Windows::Management::Workplace::IMdmAllowPolicyStatics> WMWIMdmAllowPolicyStatics_inst() {
    ComPtr<ABI::Windows::Management::Workplace::IMdmAllowPolicyStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Management.Workplace.MdmPolicy").Get(), &inst));
    return inst;
}

+ (BOOL)isBrowserAllowed {
    boolean unmarshalledReturn;
    auto _comInst = WMWIMdmAllowPolicyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsBrowserAllowed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isCameraAllowed {
    boolean unmarshalledReturn;
    auto _comInst = WMWIMdmAllowPolicyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsCameraAllowed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isMicrosoftAccountAllowed {
    boolean unmarshalledReturn;
    auto _comInst = WMWIMdmAllowPolicyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsMicrosoftAccountAllowed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isStoreAllowed {
    boolean unmarshalledReturn;
    auto _comInst = WMWIMdmAllowPolicyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsStoreAllowed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMWWorkplaceSettings

ComPtr<ABI::Windows::Management::Workplace::IWorkplaceSettingsStatics> WMWIWorkplaceSettingsStatics_inst() {
    ComPtr<ABI::Windows::Management::Workplace::IWorkplaceSettingsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Management.Workplace.WorkplaceSettings").Get(),
                                                       &inst));
    return inst;
}

+ (BOOL)isMicrosoftAccountOptional {
    boolean unmarshalledReturn;
    auto _comInst = WMWIWorkplaceSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsMicrosoftAccountOptional(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end
