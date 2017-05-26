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

// WindowsApplicationModelAppointments.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Appointments.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelAppointments.h"
#include "WindowsApplicationModelAppointments_priv.h"

@implementation WAAIAppointmentParticipant

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)address {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->put_Address(nsStrToHstr(value).Get()));
}

@end

@implementation WAAAppointment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Appointments.Appointment").Get(), &out));
    return [_createRtProxy<WAAAppointment>(out.Get()) retain];
}

- (WFDateTime*)startTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setStartTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(*[value internalStruct]));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(*[value internalStruct]));
}

- (NSString*)location {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLocation:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Location(nsStrToHstr(value).Get()));
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubject:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subject(nsStrToHstr(value).Get()));
}

- (NSString*)details {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Details(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDetails:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Details(nsStrToHstr(value).Get()));
}

- (id /* WFTimeSpan* */)reminder {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reminder(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setReminder:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Reminder(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (WAAAppointmentOrganizer*)organizer {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Organizer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointmentOrganizer>(unmarshalledReturn.Get());
}

- (void)setOrganizer:(WAAAppointmentOrganizer*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Organizer(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(value).Get()));
}

- (NSMutableArray* /* WAAAppointmentInvitee* */)invitees {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Invitees(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAAAppointmentInvitee_create(unmarshalledReturn.Get());
}

- (WAAAppointmentRecurrence*)recurrence {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Recurrence(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointmentRecurrence>(unmarshalledReturn.Get());
}

- (void)setRecurrence:(WAAAppointmentRecurrence*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Recurrence(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(value).Get()));
}

- (WAAAppointmentBusyStatus)busyStatus {
    ABI::Windows::ApplicationModel::Appointments::AppointmentBusyStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_BusyStatus(&unmarshalledReturn));
    return (WAAAppointmentBusyStatus)unmarshalledReturn;
}

- (void)setBusyStatus:(WAAAppointmentBusyStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_BusyStatus((ABI::Windows::ApplicationModel::Appointments::AppointmentBusyStatus)value));
}

- (BOOL)allDay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllDay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllDay:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllDay((boolean)value));
}

- (WAAAppointmentSensitivity)sensitivity {
    ABI::Windows::ApplicationModel::Appointments::AppointmentSensitivity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Sensitivity(&unmarshalledReturn));
    return (WAAAppointmentSensitivity)unmarshalledReturn;
}

- (void)setSensitivity:(WAAAppointmentSensitivity)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Sensitivity((ABI::Windows::ApplicationModel::Appointments::AppointmentSensitivity)value));
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)localId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)calendarId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CalendarId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)roamingId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoamingId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRoamingId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoamingId(nsStrToHstr(value).Get()));
}

- (id /* WFDateTime* */)originalStartTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalStartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (BOOL)isResponseRequested {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsResponseRequested(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsResponseRequested:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsResponseRequested((boolean)value));
}

- (BOOL)allowNewTimeProposal {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowNewTimeProposal(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowNewTimeProposal:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowNewTimeProposal((boolean)value));
}

- (NSString*)onlineMeetingLink {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OnlineMeetingLink(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setOnlineMeetingLink:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_OnlineMeetingLink(nsStrToHstr(value).Get()));
}

- (id /* WFDateTime* */)replyTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReplyTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setReplyTime:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReplyTime(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WAAAppointmentParticipantResponse)userResponse {
    ABI::Windows::ApplicationModel::Appointments::AppointmentParticipantResponse unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserResponse(&unmarshalledReturn));
    return (WAAAppointmentParticipantResponse)unmarshalledReturn;
}

- (void)setUserResponse:(WAAAppointmentParticipantResponse)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_UserResponse((ABI::Windows::ApplicationModel::Appointments::AppointmentParticipantResponse)value));
}

- (BOOL)hasInvitees {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasInvitees(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCanceledMeeting {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceledMeeting(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsCanceledMeeting:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsCanceledMeeting((boolean)value));
}

- (BOOL)isOrganizedByUser {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOrganizedByUser(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsOrganizedByUser:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsOrganizedByUser((boolean)value));
}

- (uint64_t)changeNumber {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)remoteChangeNumber {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment3>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteChangeNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRemoteChangeNumber:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment3>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteChangeNumber(value));
}

- (WAAAppointmentDetailsKind)detailsKind {
    ABI::Windows::ApplicationModel::Appointments::AppointmentDetailsKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment3>(self);
    THROW_NS_IF_FAILED(_comInst->get_DetailsKind(&unmarshalledReturn));
    return (WAAAppointmentDetailsKind)unmarshalledReturn;
}

- (void)setDetailsKind:(WAAAppointmentDetailsKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment3>(self);
    THROW_NS_IF_FAILED(_comInst->put_DetailsKind((ABI::Windows::ApplicationModel::Appointments::AppointmentDetailsKind)value));
}

@end

@implementation WAAAppointmentStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAppointmentStoreChangeTracker*)changeTracker {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeTracker> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeTracker(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointmentStoreChangeTracker>(unmarshalledReturn.Get());
}

- (void)createAppointmentCalendarAsync:(NSString*)name
                               success:(void (^)(WAAAppointmentCalendar*))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAppointmentCalendarAsync(nsStrToHstr(name).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointmentCalendar>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getAppointmentCalendarAsync:(NSString*)calendarId
                            success:(void (^)(WAAAppointmentCalendar*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetAppointmentCalendarAsync(nsStrToHstr(calendarId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointmentCalendar>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getAppointmentAsync:(NSString*)localId success:(void (^)(WAAAppointment*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::Appointment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetAppointmentAsync(nsStrToHstr(localId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::Appointment*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::Appointment*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointment>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getAppointmentInstanceAsync:(NSString*)localId
                  instanceStartTime:(WFDateTime*)instanceStartTime
                            success:(void (^)(WAAAppointment*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::Appointment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetAppointmentInstanceAsync(nsStrToHstr(localId).Get(), *[instanceStartTime internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::Appointment*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::Appointment*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointment>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAppointmentCalendarsAsyncWithSuccess:(void (^)(NSArray* /* WAAAppointmentCalendar* */))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindAppointmentCalendarsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointmentCalendar_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAppointmentCalendarsAsyncWithOptions:(WAAFindAppointmentCalendarsOptions)options
                                         success:(void (^)(NSArray* /* WAAAppointmentCalendar* */))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindAppointmentCalendarsAsyncWithOptions(
        (ABI::Windows::ApplicationModel::Appointments::FindAppointmentCalendarsOptions)options, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointmentCalendar_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAppointmentsAsync:(WFDateTime*)rangeStart
                  rangeLength:(WFTimeSpan*)rangeLength
                      success:(void (^)(NSArray* /* WAAAppointment* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindAppointmentsAsync(*[rangeStart internalStruct], *[rangeLength internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointment_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAppointmentsAsyncWithOptions:(WFDateTime*)rangeStart
                             rangeLength:(WFTimeSpan*)rangeLength
                                 options:(WAAFindAppointmentsOptions*)options
                                 success:(void (^)(NSArray* /* WAAAppointment* */))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindAppointmentsAsyncWithOptions(
        *[rangeStart internalStruct],
        *[rangeLength internalStruct],
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(options).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointment_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findConflictAsync:(WAAAppointment*)appointment
                  success:(void (^)(WAAAppointmentConflictResult*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentConflictResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindConflictAsync(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::AppointmentConflictResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentConflictResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentConflictResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointmentConflictResult>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findConflictAsyncWithInstanceStart:(WAAAppointment*)appointment
                         instanceStartTime:(WFDateTime*)instanceStartTime
                                   success:(void (^)(WAAAppointmentConflictResult*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentConflictResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindConflictAsyncWithInstanceStart(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[instanceStartTime internalStruct],
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::AppointmentConflictResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentConflictResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentConflictResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointmentConflictResult>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)moveAppointmentAsync:(WAAAppointment*)appointment
                              destinationCalendar:(WAAAppointmentCalendar*)destinationCalendar {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->MoveAppointmentAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(destinationCalendar).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)showAddAppointmentAsync:(WAAAppointment*)appointment
                      selection:(WFRect*)selection
                        success:(void (^)(NSString*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->ShowAddAppointmentAsync(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
                                          *[selection internalStruct],
                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showReplaceAppointmentAsync:(NSString*)localId
                        appointment:(WAAAppointment*)appointment
                          selection:(WFRect*)selection
                            success:(void (^)(NSString*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->ShowReplaceAppointmentAsync(
        nsStrToHstr(localId).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showReplaceAppointmentWithPlacementAndDateAsync:(NSString*)localId
                                            appointment:(WAAAppointment*)appointment
                                              selection:(WFRect*)selection
                                     preferredPlacement:(WUPPlacement)preferredPlacement
                                      instanceStartDate:(WFDateTime*)instanceStartDate
                                                success:(void (^)(NSString*))success
                                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->ShowReplaceAppointmentWithPlacementAndDateAsync(
        nsStrToHstr(localId).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
        *[instanceStartDate internalStruct],
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showRemoveAppointmentAsync:(NSString*)localId
                         selection:(WFRect*)selection
                           success:(void (^)(BOOL))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->ShowRemoveAppointmentAsync(nsStrToHstr(localId).Get(), *[selection internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showRemoveAppointmentWithPlacementAndDateAsync:(NSString*)localId
                                             selection:(WFRect*)selection
                                    preferredPlacement:(WUPPlacement)preferredPlacement
                                     instanceStartDate:(WFDateTime*)instanceStartDate
                                               success:(void (^)(BOOL))success
                                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->ShowRemoveAppointmentWithPlacementAndDateAsync(nsStrToHstr(localId).Get(),
                                                                                *[selection internalStruct],
                                                                                (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                                                                *[instanceStartDate internalStruct],
                                                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)showAppointmentDetailsAsync:(NSString*)localId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAppointmentDetailsAsync(nsStrToHstr(localId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)showAppointmentDetailsWithDateAsync:(NSString*)localId instanceStartDate:(WFDateTime*)instanceStartDate {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAppointmentDetailsWithDateAsync(nsStrToHstr(localId).Get(),
                                                                     *[instanceStartDate internalStruct],
                                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)showEditNewAppointmentAsync:(WAAAppointment*)appointment success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->ShowEditNewAppointmentAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findLocalIdsFromRoamingIdAsync:(NSString*)roamingId
                               success:(void (^)(NSArray* /* NSString * */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindLocalIdsFromRoamingIdAsync(nsStrToHstr(roamingId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_NSString_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addStoreChangedEvent:(void (^)(WAAAppointmentStore*, WAAAppointmentStoreChangedEventArgs*))pHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore2>(self);
    THROW_NS_IF_FAILED(_comInst->add_StoreChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentStore_Windows_ApplicationModel_Appointments_AppointmentStoreChangedEventArgs>(
            pHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoreChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StoreChanged(token));
}

- (void)createAppointmentCalendarInAccountAsync:(NSString*)name
                              userDataAccountId:(NSString*)userDataAccountId
                                        success:(void (^)(WAAAppointmentCalendar*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAppointmentCalendarInAccountAsync(nsStrToHstr(name).Get(),
                                                                         nsStrToHstr(userDataAccountId).Get(),
                                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointmentCalendar>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WAAAppointmentManagerForUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)showAddAppointmentAsync:(WAAAppointment*)appointment
                      selection:(WFRect*)selection
                        success:(void (^)(NSString*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->ShowAddAppointmentAsync(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
                                          *[selection internalStruct],
                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showAddAppointmentWithPlacementAsync:(WAAAppointment*)appointment
                                   selection:(WFRect*)selection
                          preferredPlacement:(WUPPlacement)preferredPlacement
                                     success:(void (^)(NSString*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAddAppointmentWithPlacementAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showReplaceAppointmentAsync:(NSString*)appointmentId
                        appointment:(WAAAppointment*)appointment
                          selection:(WFRect*)selection
                            success:(void (^)(NSString*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->ShowReplaceAppointmentAsync(
        nsStrToHstr(appointmentId).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showReplaceAppointmentWithPlacementAsync:(NSString*)appointmentId
                                     appointment:(WAAAppointment*)appointment
                                       selection:(WFRect*)selection
                              preferredPlacement:(WUPPlacement)preferredPlacement
                                         success:(void (^)(NSString*))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->ShowReplaceAppointmentWithPlacementAsync(
        nsStrToHstr(appointmentId).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showReplaceAppointmentWithPlacementAndDateAsync:(NSString*)appointmentId
                                            appointment:(WAAAppointment*)appointment
                                              selection:(WFRect*)selection
                                     preferredPlacement:(WUPPlacement)preferredPlacement
                                      instanceStartDate:(WFDateTime*)instanceStartDate
                                                success:(void (^)(NSString*))success
                                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->ShowReplaceAppointmentWithPlacementAndDateAsync(
        nsStrToHstr(appointmentId).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
        *[instanceStartDate internalStruct],
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showRemoveAppointmentAsync:(NSString*)appointmentId
                         selection:(WFRect*)selection
                           success:(void (^)(BOOL))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->ShowRemoveAppointmentAsync(nsStrToHstr(appointmentId).Get(), *[selection internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showRemoveAppointmentWithPlacementAsync:(NSString*)appointmentId
                                      selection:(WFRect*)selection
                             preferredPlacement:(WUPPlacement)preferredPlacement
                                        success:(void (^)(BOOL))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->ShowRemoveAppointmentWithPlacementAsync(nsStrToHstr(appointmentId).Get(),
                                                                         *[selection internalStruct],
                                                                         (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)showRemoveAppointmentWithPlacementAndDateAsync:(NSString*)appointmentId
                                             selection:(WFRect*)selection
                                    preferredPlacement:(WUPPlacement)preferredPlacement
                                     instanceStartDate:(WFDateTime*)instanceStartDate
                                               success:(void (^)(BOOL))success
                                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->ShowRemoveAppointmentWithPlacementAndDateAsync(nsStrToHstr(appointmentId).Get(),
                                                                                *[selection internalStruct],
                                                                                (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                                                                *[instanceStartDate internalStruct],
                                                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)showTimeFrameAsync:(WFDateTime*)timeToShow duration:(WFTimeSpan*)duration {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->ShowTimeFrameAsync(*[timeToShow internalStruct], *[duration internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)showAppointmentDetailsAsync:(NSString*)appointmentId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAppointmentDetailsAsync(nsStrToHstr(appointmentId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)showAppointmentDetailsWithDateAsync:(NSString*)appointmentId instanceStartDate:(WFDateTime*)instanceStartDate {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAppointmentDetailsWithDateAsync(nsStrToHstr(appointmentId).Get(),
                                                                     *[instanceStartDate internalStruct],
                                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)showEditNewAppointmentAsync:(WAAAppointment*)appointment success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->ShowEditNewAppointmentAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)requestStoreAsync:(WAAAppointmentStoreAccessType)options
                  success:(void (^)(WAAAppointmentStore*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentStore*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync((ABI::Windows::ApplicationModel::Appointments::AppointmentStoreAccessType)options,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::AppointmentStore*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentStore*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointmentStore>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppointmentOrganizer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentOrganizer").Get(),
                                              &out));
    return [_createRtProxy<WAAAppointmentOrganizer>(out.Get()) retain];
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)address {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->put_Address(nsStrToHstr(value).Get()));
}

@end

@implementation WAAAppointmentInvitee

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentInvitee").Get(),
                                              &out));
    return [_createRtProxy<WAAAppointmentInvitee>(out.Get()) retain];
}

- (WAAAppointmentParticipantRole)role {
    ABI::Windows::ApplicationModel::Appointments::AppointmentParticipantRole unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee>(self);
    THROW_NS_IF_FAILED(_comInst->get_Role(&unmarshalledReturn));
    return (WAAAppointmentParticipantRole)unmarshalledReturn;
}

- (void)setRole:(WAAAppointmentParticipantRole)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee>(self);
    THROW_NS_IF_FAILED(_comInst->put_Role((ABI::Windows::ApplicationModel::Appointments::AppointmentParticipantRole)value));
}

- (WAAAppointmentParticipantResponse)response {
    ABI::Windows::ApplicationModel::Appointments::AppointmentParticipantResponse unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee>(self);
    THROW_NS_IF_FAILED(_comInst->get_Response(&unmarshalledReturn));
    return (WAAAppointmentParticipantResponse)unmarshalledReturn;
}

- (void)setResponse:(WAAAppointmentParticipantResponse)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee>(self);
    THROW_NS_IF_FAILED(_comInst->put_Response((ABI::Windows::ApplicationModel::Appointments::AppointmentParticipantResponse)value));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)address {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentParticipant>(self);
    THROW_NS_IF_FAILED(_comInst->put_Address(nsStrToHstr(value).Get()));
}

@end

@implementation WAAAppointmentRecurrence

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentRecurrence").Get(),
                                              &out));
    return [_createRtProxy<WAAAppointmentRecurrence>(out.Get()) retain];
}

- (WAAAppointmentRecurrenceUnit)unit {
    ABI::Windows::ApplicationModel::Appointments::AppointmentRecurrenceUnit unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Unit(&unmarshalledReturn));
    return (WAAAppointmentRecurrenceUnit)unmarshalledReturn;
}

- (void)setUnit:(WAAAppointmentRecurrenceUnit)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->put_Unit((ABI::Windows::ApplicationModel::Appointments::AppointmentRecurrenceUnit)value));
}

- (id /* unsigned int */)occurrences {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Occurrences(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setOccurrences:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->put_Occurrences(BuildNullable<unsigned int>(value)));
}

- (id /* WFDateTime* */)until {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Until(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setUntil:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->put_Until(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (unsigned int)interval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Interval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->put_Interval(value));
}

- (WAAAppointmentDaysOfWeek)daysOfWeek {
    ABI::Windows::ApplicationModel::Appointments::AppointmentDaysOfWeek unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->get_DaysOfWeek(&unmarshalledReturn));
    return (WAAAppointmentDaysOfWeek)unmarshalledReturn;
}

- (void)setDaysOfWeek:(WAAAppointmentDaysOfWeek)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->put_DaysOfWeek((ABI::Windows::ApplicationModel::Appointments::AppointmentDaysOfWeek)value));
}

- (WAAAppointmentWeekOfMonth)weekOfMonth {
    ABI::Windows::ApplicationModel::Appointments::AppointmentWeekOfMonth unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->get_WeekOfMonth(&unmarshalledReturn));
    return (WAAAppointmentWeekOfMonth)unmarshalledReturn;
}

- (void)setWeekOfMonth:(WAAAppointmentWeekOfMonth)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->put_WeekOfMonth((ABI::Windows::ApplicationModel::Appointments::AppointmentWeekOfMonth)value));
}

- (unsigned int)month {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Month(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMonth:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->put_Month(value));
}

- (unsigned int)day {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Day(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDay:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence>(self);
    THROW_NS_IF_FAILED(_comInst->put_Day(value));
}

- (WAARecurrenceType)recurrenceType {
    ABI::Windows::ApplicationModel::Appointments::RecurrenceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecurrenceType(&unmarshalledReturn));
    return (WAARecurrenceType)unmarshalledReturn;
}

- (NSString*)timeZone {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeZone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTimeZone:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TimeZone(nsStrToHstr(value).Get()));
}

- (NSString*)calendarIdentifier {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentRecurrence3>(self);
    THROW_NS_IF_FAILED(_comInst->get_CalendarIdentifier(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WAAAppointmentManager

ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerStatics> WAAIAppointmentManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentManager").Get(), &inst));
    return inst;
}

+ (void)showAddAppointmentAsync:(WAAAppointment*)appointment
                      selection:(WFRect*)selection
                        success:(void (^)(NSString*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ShowAddAppointmentAsync(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
                                          *[selection internalStruct],
                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)showAddAppointmentWithPlacementAsync:(WAAAppointment*)appointment
                                   selection:(WFRect*)selection
                          preferredPlacement:(WUPPlacement)preferredPlacement
                                     success:(void (^)(NSString*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowAddAppointmentWithPlacementAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)showReplaceAppointmentAsync:(NSString*)appointmentId
                        appointment:(WAAAppointment*)appointment
                          selection:(WFRect*)selection
                            success:(void (^)(NSString*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowReplaceAppointmentAsync(
        nsStrToHstr(appointmentId).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)showReplaceAppointmentWithPlacementAsync:(NSString*)appointmentId
                                     appointment:(WAAAppointment*)appointment
                                       selection:(WFRect*)selection
                              preferredPlacement:(WUPPlacement)preferredPlacement
                                         success:(void (^)(NSString*))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowReplaceAppointmentWithPlacementAsync(
        nsStrToHstr(appointmentId).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)showReplaceAppointmentWithPlacementAndDateAsync:(NSString*)appointmentId
                                            appointment:(WAAAppointment*)appointment
                                              selection:(WFRect*)selection
                                     preferredPlacement:(WUPPlacement)preferredPlacement
                                      instanceStartDate:(WFDateTime*)instanceStartDate
                                                success:(void (^)(NSString*))success
                                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowReplaceAppointmentWithPlacementAndDateAsync(
        nsStrToHstr(appointmentId).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        *[selection internalStruct],
        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
        *[instanceStartDate internalStruct],
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)showRemoveAppointmentAsync:(NSString*)appointmentId
                         selection:(WFRect*)selection
                           success:(void (^)(BOOL))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ShowRemoveAppointmentAsync(nsStrToHstr(appointmentId).Get(), *[selection internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)showRemoveAppointmentWithPlacementAsync:(NSString*)appointmentId
                                      selection:(WFRect*)selection
                             preferredPlacement:(WUPPlacement)preferredPlacement
                                        success:(void (^)(BOOL))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowRemoveAppointmentWithPlacementAsync(nsStrToHstr(appointmentId).Get(),
                                                                         *[selection internalStruct],
                                                                         (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)showRemoveAppointmentWithPlacementAndDateAsync:(NSString*)appointmentId
                                             selection:(WFRect*)selection
                                    preferredPlacement:(WUPPlacement)preferredPlacement
                                     instanceStartDate:(WFDateTime*)instanceStartDate
                                               success:(void (^)(BOOL))success
                                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowRemoveAppointmentWithPlacementAndDateAsync(nsStrToHstr(appointmentId).Get(),
                                                                                *[selection internalStruct],
                                                                                (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                                                                *[instanceStartDate internalStruct],
                                                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (RTObject<WFIAsyncAction>*)showTimeFrameAsync:(WFDateTime*)timeToShow duration:(WFTimeSpan*)duration {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ShowTimeFrameAsync(*[timeToShow internalStruct], *[duration internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerStatics2> WAAIAppointmentManagerStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)showAppointmentDetailsAsync:(NSString*)appointmentId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->ShowAppointmentDetailsAsync(nsStrToHstr(appointmentId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)showAppointmentDetailsWithDateAsync:(NSString*)appointmentId instanceStartDate:(WFDateTime*)instanceStartDate {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->ShowAppointmentDetailsWithDateAsync(nsStrToHstr(appointmentId).Get(),
                                                                     *[instanceStartDate internalStruct],
                                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)showEditNewAppointmentAsync:(WAAAppointment*)appointment success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->ShowEditNewAppointmentAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)requestStoreAsync:(WAAAppointmentStoreAccessType)options
                  success:(void (^)(WAAAppointmentStore*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentStore*>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync((ABI::Windows::ApplicationModel::Appointments::AppointmentStoreAccessType)options,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::AppointmentStore*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::AppointmentStore*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointmentStore>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerStatics3> WAAIAppointmentManagerStatics3_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentManager").Get(), &inst));
    return inst;
}

+ (WAAAppointmentManagerForUser*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerForUser> unmarshalledReturn;
    auto _comInst = WAAIAppointmentManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointmentManagerForUser>(unmarshalledReturn.Get());
}

@end

@implementation WAAFindAppointmentsOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Appointments.FindAppointmentsOptions").Get(), &out));
    return [_createRtProxy<WAAFindAppointmentsOptions>(out.Get()) retain];
}

- (NSMutableArray* /* NSString * */)calendarIds {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_CalendarIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)fetchProperties {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FetchProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (BOOL)includeHidden {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeHidden(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIncludeHidden:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncludeHidden((boolean)value));
}

- (unsigned int)maxCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxCount:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxCount(value));
}

@end

@implementation WAAAppointmentException

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentException> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAppointment*)appointment {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentException>(self);
    THROW_NS_IF_FAILED(_comInst->get_Appointment(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointment>(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)exceptionProperties {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentException>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExceptionProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (BOOL)isDeleted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentException>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDeleted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WAAAppointmentCalendarSyncManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAppointmentCalendarSyncStatus)status {
    ABI::Windows::ApplicationModel::Appointments::AppointmentCalendarSyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WAAAppointmentCalendarSyncStatus)unmarshalledReturn;
}

- (WFDateTime*)lastSuccessfulSyncTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastSuccessfulSyncTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)lastAttemptedSyncTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastAttemptedSyncTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)syncAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->SyncAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addSyncStatusChangedEvent:(void (^)(WAAAppointmentCalendarSyncManager*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SyncStatusChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentCalendarSyncManager_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSyncStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SyncStatusChanged(token));
}

- (void)setStatus:(WAAAppointmentCalendarSyncStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Status((ABI::Windows::ApplicationModel::Appointments::AppointmentCalendarSyncStatus)value));
}

- (void)setLastSuccessfulSyncTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastSuccessfulSyncTime(*[value internalStruct]));
}

- (void)setLastAttemptedSyncTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastAttemptedSyncTime(*[value internalStruct]));
}

@end

@implementation WAAAppointmentCalendar

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUColor*)displayColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)localId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isHidden {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHidden(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WAAAppointmentCalendarOtherAppReadAccess)otherAppReadAccess {
    ABI::Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppReadAccess unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_OtherAppReadAccess(&unmarshalledReturn));
    return (WAAAppointmentCalendarOtherAppReadAccess)unmarshalledReturn;
}

- (void)setOtherAppReadAccess:(WAAAppointmentCalendarOtherAppReadAccess)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_OtherAppReadAccess((ABI::Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppReadAccess)value));
}

- (WAAAppointmentCalendarOtherAppWriteAccess)otherAppWriteAccess {
    ABI::Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppWriteAccess unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_OtherAppWriteAccess(&unmarshalledReturn));
    return (WAAAppointmentCalendarOtherAppWriteAccess)unmarshalledReturn;
}

- (void)setOtherAppWriteAccess:(WAAAppointmentCalendarOtherAppWriteAccess)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_OtherAppWriteAccess((ABI::Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppWriteAccess)value));
}

- (NSString*)sourceDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAAppointmentSummaryCardView)summaryCardView {
    ABI::Windows::ApplicationModel::Appointments::AppointmentSummaryCardView unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_SummaryCardView(&unmarshalledReturn));
    return (WAAAppointmentSummaryCardView)unmarshalledReturn;
}

- (void)setSummaryCardView:(WAAAppointmentSummaryCardView)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_SummaryCardView((ABI::Windows::ApplicationModel::Appointments::AppointmentSummaryCardView)value));
}

- (void)findAppointmentsAsync:(WFDateTime*)rangeStart
                  rangeLength:(WFTimeSpan*)rangeLength
                      success:(void (^)(NSArray* /* WAAAppointment* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->FindAppointmentsAsync(*[rangeStart internalStruct], *[rangeLength internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointment_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAppointmentsAsyncWithOptions:(WFDateTime*)rangeStart
                             rangeLength:(WFTimeSpan*)rangeLength
                                 options:(WAAFindAppointmentsOptions*)options
                                 success:(void (^)(NSArray* /* WAAAppointment* */))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->FindAppointmentsAsyncWithOptions(
        *[rangeStart internalStruct],
        *[rangeLength internalStruct],
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(options).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointment_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findExceptionsFromMasterAsync:(NSString*)masterLocalId
                              success:(void (^)(NSArray* /* WAAAppointmentException* */))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentException*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->FindExceptionsFromMasterAsync(nsStrToHstr(masterLocalId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentException*>*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentException*>*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentException*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WAAAppointmentException_create(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAllInstancesAsync:(NSString*)masterLocalId
                   rangeStart:(WFDateTime*)rangeStart
                  rangeLength:(WFTimeSpan*)rangeLength
                      success:(void (^)(NSArray* /* WAAAppointment* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->FindAllInstancesAsync(nsStrToHstr(masterLocalId).Get(),
                                                       *[rangeStart internalStruct],
                                                       *[rangeLength internalStruct],
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointment_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAllInstancesAsyncWithOptions:(NSString*)masterLocalId
                              rangeStart:(WFDateTime*)rangeStart
                             rangeLength:(WFTimeSpan*)rangeLength
                                pOptions:(WAAFindAppointmentsOptions*)pOptions
                                 success:(void (^)(NSArray* /* WAAAppointment* */))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->FindAllInstancesAsyncWithOptions(
        nsStrToHstr(masterLocalId).Get(),
        *[rangeStart internalStruct],
        *[rangeLength internalStruct],
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(pOptions).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointment_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getAppointmentAsync:(NSString*)localId success:(void (^)(WAAAppointment*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::Appointment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->GetAppointmentAsync(nsStrToHstr(localId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::Appointment*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::Appointment*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointment>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getAppointmentInstanceAsync:(NSString*)localId
                  instanceStartTime:(WFDateTime*)instanceStartTime
                            success:(void (^)(WAAAppointment*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::Appointment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetAppointmentInstanceAsync(nsStrToHstr(localId).Get(), *[instanceStartTime internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Appointments::Appointment*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Appointments::Appointment*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAAAppointment>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findUnexpandedAppointmentsAsyncWithSuccess:(void (^)(NSArray* /* WAAAppointment* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->FindUnexpandedAppointmentsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointment_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findUnexpandedAppointmentsAsyncWithOptions:(WAAFindAppointmentsOptions*)options
                                           success:(void (^)(NSArray* /* WAAAppointment* */))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->FindUnexpandedAppointmentsAsyncWithOptions(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>(options).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppointment_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)saveAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->SaveAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAppointmentAsync:(NSString*)localId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAppointmentAsync(nsStrToHstr(localId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAppointmentInstanceAsync:(NSString*)localId instanceStartTime:(WFDateTime*)instanceStartTime {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAppointmentInstanceAsync(nsStrToHstr(localId).Get(),
                                                                *[instanceStartTime internalStruct],
                                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)saveAppointmentAsync:(WAAAppointment*)pAppointment {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar>(self);
    THROW_NS_IF_FAILED(
        _comInst->SaveAppointmentAsync(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(pAppointment).Get(),
                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WAAAppointmentCalendarSyncManager*)syncManager {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SyncManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointmentCalendarSyncManager>(unmarshalledReturn.Get());
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (void)setDisplayColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayColor(*[value internalStruct]));
}

- (void)setIsHidden:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsHidden((boolean)value));
}

- (NSString*)userDataAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserDataAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)canCreateOrUpdateAppointments {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanCreateOrUpdateAppointments(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanCreateOrUpdateAppointments:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanCreateOrUpdateAppointments((boolean)value));
}

- (BOOL)canCancelMeetings {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanCancelMeetings(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanCancelMeetings:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanCancelMeetings((boolean)value));
}

- (BOOL)canForwardMeetings {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanForwardMeetings(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanForwardMeetings:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanForwardMeetings((boolean)value));
}

- (BOOL)canProposeNewTimeForMeetings {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanProposeNewTimeForMeetings(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanProposeNewTimeForMeetings:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanProposeNewTimeForMeetings((boolean)value));
}

- (BOOL)canUpdateMeetingResponses {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanUpdateMeetingResponses(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanUpdateMeetingResponses:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanUpdateMeetingResponses((boolean)value));
}

- (BOOL)canNotifyInvitees {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanNotifyInvitees(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanNotifyInvitees:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanNotifyInvitees((boolean)value));
}

- (BOOL)mustNofityInvitees {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MustNofityInvitees(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setMustNofityInvitees:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MustNofityInvitees((boolean)value));
}

- (void)tryCreateOrUpdateAppointmentAsync:(WAAAppointment*)appointment
                           notifyInvitees:(BOOL)notifyInvitees
                                  success:(void (^)(BOOL))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->TryCreateOrUpdateAppointmentAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(appointment).Get(),
        (boolean)notifyInvitees,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryCancelMeetingAsync:(WAAAppointment*)meeting
                      subject:(NSString*)subject
                      comment:(NSString*)comment
               notifyInvitees:(BOOL)notifyInvitees
                      success:(void (^)(BOOL))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryCancelMeetingAsync(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(meeting).Get(),
                                        nsStrToHstr(subject).Get(),
                                        nsStrToHstr(comment).Get(),
                                        (boolean)notifyInvitees,
                                        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryForwardMeetingAsync:(WAAAppointment*)meeting
                      invitees:(id<NSFastEnumeration> /* WAAAppointmentInvitee* */)invitees
                       subject:(NSString*)subject
                 forwardHeader:(NSString*)forwardHeader
                       comment:(NSString*)comment
                       success:(void (^)(BOOL))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->TryForwardMeetingAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(meeting).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*,
                                                              ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee*>>::type>*>(
            ConvertToIterable<
                WAAAppointmentInvitee,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*,
                                                                  ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee*>>(
                invitees)
                .Get()),
        nsStrToHstr(subject).Get(),
        nsStrToHstr(forwardHeader).Get(),
        nsStrToHstr(comment).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryProposeNewTimeForMeetingAsync:(WAAAppointment*)meeting
                            newStartTime:(WFDateTime*)newStartTime
                             newDuration:(WFTimeSpan*)newDuration
                                 subject:(NSString*)subject
                                 comment:(NSString*)comment
                                 success:(void (^)(BOOL))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(_comInst->TryProposeNewTimeForMeetingAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(meeting).Get(),
        *[newStartTime internalStruct],
        *[newDuration internalStruct],
        nsStrToHstr(subject).Get(),
        nsStrToHstr(comment).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryUpdateMeetingResponseAsync:(WAAAppointment*)meeting
                             response:(WAAAppointmentParticipantResponse)response
                              subject:(NSString*)subject
                              comment:(NSString*)comment
                           sendUpdate:(BOOL)sendUpdate
                              success:(void (^)(BOOL))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar2>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryUpdateMeetingResponseAsync(_getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointment>(meeting).Get(),
                                                (ABI::Windows::ApplicationModel::Appointments::AppointmentParticipantResponse)response,
                                                nsStrToHstr(subject).Get(),
                                                nsStrToHstr(comment).Get(),
                                                (boolean)sendUpdate,
                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)registerSyncManagerAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar3>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterSyncManagerAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppointmentStoreChange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAppointment*)appointment {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Appointment(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointment>(unmarshalledReturn.Get());
}

- (WAAAppointmentStoreChangeType)changeType {
    ABI::Windows::ApplicationModel::Appointments::AppointmentStoreChangeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeType(&unmarshalledReturn));
    return (WAAAppointmentStoreChangeType)unmarshalledReturn;
}

- (WAAAppointmentCalendar*)appointmentCalendar {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChange2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppointmentCalendar(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointmentCalendar>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppointmentStoreChangeReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WAAAppointmentStoreChange* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentStoreChange*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentStoreChange*>*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentStoreChange*>*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentStoreChange*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WAAAppointmentStoreChange_create(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)acceptChanges {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptChanges());
}

- (void)acceptChangesThrough:(WAAAppointmentStoreChange*)lastChangeToAccept {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptChangesThrough(
        _getRtInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChange>(lastChangeToAccept).Get()));
}

@end

@implementation WAAAppointmentStoreChangedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WAAAppointmentStoreChangeTracker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeTracker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAppointmentStoreChangeReader*)getChangeReader {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->GetChangeReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointmentStoreChangeReader>(unmarshalledReturn.Get());
}

- (void)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Enable());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

@end

@implementation WAAAppointmentConflictResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentConflictResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAppointmentConflictType)type {
    ABI::Windows::ApplicationModel::Appointments::AppointmentConflictType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentConflictResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WAAAppointmentConflictType)unmarshalledReturn;
}

- (WFDateTime*)date {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentConflictResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Date(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WAAAppointmentStoreChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAAppointmentStoreChangedDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointmentStoreChangedDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppointmentProperties

ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics2> WAAIAppointmentPropertiesStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentProperties").Get(), &inst));
    return inst;
}

+ (NSString*)changeNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ChangeNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)remoteChangeNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_RemoteChangeNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)detailsKind {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_DetailsKind(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics> WAAIAppointmentPropertiesStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Appointments.AppointmentProperties").Get(), &inst));
    return inst;
}

+ (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)location {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Location(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)startTime {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)duration {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)reminder {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Reminder(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)busyStatus {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BusyStatus(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sensitivity {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sensitivity(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)originalStartTime {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OriginalStartTime(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)isResponseRequested {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsResponseRequested(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)allowNewTimeProposal {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowNewTimeProposal(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)allDay {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllDay(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)details {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Details(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)onlineMeetingLink {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OnlineMeetingLink(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)replyTime {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ReplyTime(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)organizer {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Organizer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)userResponse {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UserResponse(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hasInvitees {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HasInvitees(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)isCanceledMeeting {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsCanceledMeeting(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)isOrganizedByUser {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsOrganizedByUser(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)recurrence {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Recurrence(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)uri {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Uri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)invitees {
    HSTRING unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Invitees(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSMutableArray* /* NSString * */)defaultProperties {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = WAAIAppointmentPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DefaultProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WAAAppointmentStoreNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

id RTProxiedIterableNSArray_WAAAppointmentInvitee_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*>,
                                                 RTIterableObj<ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee*,
                                                               IIterable<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*>,
                                                               WAAAppointmentInvitee,
                                                               ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAAAppointment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Appointments::IAppointment*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Appointments::Appointment*>,
                                                    WAAAppointment,
                                                    ABI::Windows::ApplicationModel::Appointments::Appointment*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAAAppointmentCalendar_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendar*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*>,
                                                    WAAAppointmentCalendar,
                                                    ABI::Windows::ApplicationModel::Appointments::AppointmentCalendar*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAAAppointmentException_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentException*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Appointments::IAppointmentException*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentException*>,
                                                    WAAAppointmentException,
                                                    ABI::Windows::ApplicationModel::Appointments::AppointmentException*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAAAppointmentStoreChange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentStoreChange*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChange*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Appointments::AppointmentStoreChange*>,
                                                    WAAAppointmentStoreChange,
                                                    ABI::Windows::ApplicationModel::Appointments::AppointmentStoreChange*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WAAAppointmentInvitee_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*>,
                               RTMutableArrayObj<ABI::Windows::ApplicationModel::Appointments::IAppointmentInvitee*,
                                                 IVector<ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*>,
                                                 WAAAppointmentInvitee,
                                                 ABI::Windows::ApplicationModel::Appointments::AppointmentInvitee*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
