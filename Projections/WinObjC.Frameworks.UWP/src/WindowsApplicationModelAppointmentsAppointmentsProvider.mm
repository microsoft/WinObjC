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

// WindowsApplicationModelAppointmentsAppointmentsProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Appointments.AppointmentsProvider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider_priv.h"

@implementation WAAAAppointmentsProviderLaunchActionVerbs

ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2>
WAAAIAppointmentsProviderLaunchActionVerbsStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentsProvider.AppointmentsProviderLaunchActionVerbs").Get(),
        &inst));
    return inst;
}

+ (NSString*)showAppointmentDetails {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAAIAppointmentsProviderLaunchActionVerbsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ShowAppointmentDetails(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics>
WAAAIAppointmentsProviderLaunchActionVerbsStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentsProvider.AppointmentsProviderLaunchActionVerbs").Get(),
        &inst));
    return inst;
}

+ (NSString*)addAppointment {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAAIAppointmentsProviderLaunchActionVerbsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AddAppointment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)replaceAppointment {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAAIAppointmentsProviderLaunchActionVerbsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ReplaceAppointment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)removeAppointment {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAAIAppointmentsProviderLaunchActionVerbsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RemoveAppointment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)showTimeFrame {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAAIAppointmentsProviderLaunchActionVerbsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ShowTimeFrame(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WAAAAddAppointmentOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAppointment*)appointmentInformation {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointment>(unmarshalledReturn.Get());
}

- (NSString*)sourcePackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourcePackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)reportCompleted:(NSString*)itemId {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted(nsStrToHstr(itemId).Get()));
}

- (void)reportCanceled {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCanceled());
}

- (void)reportError:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportError(nsStrToHstr(value).Get()));
}

- (void)dismissUI {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->DismissUI());
}

@end

@implementation WAAAReplaceAppointmentOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appointmentId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAAppointment*)appointmentInformation {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointment>(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)instanceStartDate {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceStartDate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (NSString*)sourcePackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourcePackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)reportCompleted:(NSString*)itemId {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted(nsStrToHstr(itemId).Get()));
}

- (void)reportCanceled {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCanceled());
}

- (void)reportError:(NSString*)value {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportError(nsStrToHstr(value).Get()));
}

- (void)dismissUI {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->DismissUI());
}

@end

@implementation WAAARemoveAppointmentOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appointmentId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* WFDateTime* */)instanceStartDate {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceStartDate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (NSString*)sourcePackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourcePackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)reportCompleted {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportCanceled {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCanceled());
}

- (void)reportError:(NSString*)value {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportError(nsStrToHstr(value).Get()));
}

- (void)dismissUI {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>(self);
    THROW_NS_IF_FAILED(_comInst->DismissUI());
}

@end
