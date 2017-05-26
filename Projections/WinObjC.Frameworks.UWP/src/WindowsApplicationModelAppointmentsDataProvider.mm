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

// WindowsApplicationModelAppointmentsDataProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Appointments.DataProvider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelAppointmentsDataProvider.h"
#include "WindowsApplicationModelAppointmentsDataProvider_priv.h"

@implementation WAADAppointmentDataProviderConnection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addSyncRequestedEvent:(void (^)(WAADAppointmentDataProviderConnection*,
                                                          WAADAppointmentCalendarSyncManagerSyncRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_SyncRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarSyncManagerSyncRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSyncRequestedEvent:(EventRegistrationToken)token {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SyncRequested(token));
}

- (EventRegistrationToken)addCreateOrUpdateAppointmentRequestedEvent:
    (void (^)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_CreateOrUpdateAppointmentRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCreateOrUpdateAppointmentRequestedEvent:(EventRegistrationToken)token {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CreateOrUpdateAppointmentRequested(token));
}

- (EventRegistrationToken)addCancelMeetingRequestedEvent:(void (^)(WAADAppointmentDataProviderConnection*,
                                                                   WAADAppointmentCalendarCancelMeetingRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_CancelMeetingRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCancelMeetingRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCancelMeetingRequestedEvent:(EventRegistrationToken)token {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CancelMeetingRequested(token));
}

- (EventRegistrationToken)addForwardMeetingRequestedEvent:(void (^)(WAADAppointmentDataProviderConnection*,
                                                                    WAADAppointmentCalendarForwardMeetingRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_ForwardMeetingRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarForwardMeetingRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeForwardMeetingRequestedEvent:(EventRegistrationToken)token {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ForwardMeetingRequested(token));
}

- (EventRegistrationToken)addProposeNewTimeForMeetingRequestedEvent:
    (void (^)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_ProposeNewTimeForMeetingRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeProposeNewTimeForMeetingRequestedEvent:(EventRegistrationToken)token {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ProposeNewTimeForMeetingRequested(token));
}

- (EventRegistrationToken)addUpdateMeetingResponseRequestedEvent:
    (void (^)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_UpdateMeetingResponseRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarUpdateMeetingResponseRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdateMeetingResponseRequestedEvent:(EventRegistrationToken)token {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UpdateMeetingResponseRequested(token));
}

- (void)start {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

@end

@implementation WAADAppointmentCalendarSyncManagerSyncRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequestEventArgs>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAADAppointmentCalendarSyncManagerSyncRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequestEventArgs>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAADAppointmentCalendarSyncManagerSyncRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequestEventArgs>(
            self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAADAppointmentCalendarCreateOrUpdateAppointmentRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAADAppointmentCalendarCreateOrUpdateAppointmentRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarCancelMeetingRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAADAppointmentCalendarCancelMeetingRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequestEventArgs>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAADAppointmentCalendarCancelMeetingRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequestEventArgs>(
            self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarForwardMeetingRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAADAppointmentCalendarForwardMeetingRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequestEventArgs>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAADAppointmentCalendarForwardMeetingRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequestEventArgs>(
            self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAADAppointmentCalendarProposeNewTimeForMeetingRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAADAppointmentCalendarProposeNewTimeForMeetingRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequestEventArgs>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAADAppointmentCalendarUpdateMeetingResponseRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAADAppointmentCalendarUpdateMeetingResponseRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentDataProviderTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAADAppointmentDataProviderConnection*)connection {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Connection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAADAppointmentDataProviderConnection>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarSyncManagerSyncRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appointmentCalendarLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentCalendarLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarCreateOrUpdateAppointmentRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appointmentCalendarLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentCalendarLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAAppointment*)appointment {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Appointment(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointment>(unmarshalledReturn.Get());
}

- (BOOL)notifyInvitees {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_NotifyInvitees(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* NSString * */)changedProperties {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangedProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(WAAAppointment*)createdOrUpdatedAppointment {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(createdOrUpdatedAppointment).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarCancelMeetingRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appointmentCalendarLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentCalendarLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appointmentLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* WFDateTime* */)appointmentOriginalStartTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentOriginalStartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)notifyInvitees {
    boolean unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_NotifyInvitees(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarForwardMeetingRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appointmentCalendarLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentCalendarLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appointmentLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* WFDateTime* */)appointmentOriginalStartTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentOriginalStartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (NSArray* /* WAAAppointmentInvitee* */)invitees {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Invitees(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WAAAppointmentInvitee_create(unmarshalledReturn.Get());
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)forwardHeader {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForwardHeader(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarProposeNewTimeForMeetingRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appointmentCalendarLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentCalendarLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appointmentLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* WFDateTime* */)appointmentOriginalStartTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentOriginalStartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (WFDateTime*)newStartTime __attribute__((ns_returns_not_retained)) {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_NewStartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)newDuration __attribute__((ns_returns_not_retained)) {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_NewDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAADAppointmentCalendarUpdateMeetingResponseRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appointmentCalendarLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentCalendarLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appointmentLocalId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentLocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* WFDateTime* */)appointmentOriginalStartTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentOriginalStartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (WAAAppointmentParticipantResponse)response {
    ABI::Windows::ApplicationModel::Appointments::AppointmentParticipantResponse unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Response(&unmarshalledReturn));
    return (WAAAppointmentParticipantResponse)unmarshalledReturn;
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)sendUpdate {
    boolean unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_SendUpdate(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequest>(
            self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAAAppointmentInvitee_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*>,
                                                    WAAAppointmentInvitee,
                                                    ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
