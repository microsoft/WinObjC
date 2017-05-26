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

// WindowsPhoneNotificationManagement.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.Notification.Management.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneNotificationManagement.h"
#include "WindowsPhoneNotificationManagement_priv.h"

@implementation WPNMIAccessoryNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

@end

@implementation WPNMTextResponse

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::ITextResponse> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ITextResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)content {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ITextResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WPNMAppNotificationInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IAppNotificationInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAppNotificationInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAppNotificationInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WPNMEmailAccountInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IEmailAccountInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailAccountInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isNotificationEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailAccountInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsNotificationEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WPNMEmailFolderInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IEmailFolderInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailFolderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isNotificationEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailFolderInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsNotificationEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WPNMBinaryId

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IBinaryId> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint8_t)id {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IBinaryId>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IBinaryId>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WPNMAlarmNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IAlarmNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)alarmId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAlarmNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlarmId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAlarmNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAlarmNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WPNMReminderState)reminderState {
    ABI::Windows::Phone::Notification::Management::ReminderState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAlarmNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReminderState(&unmarshalledReturn));
    return (WPNMReminderState)unmarshalledReturn;
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

- (NSString*)instanceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAlarmNotificationTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WPNMEmailReadNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IEmailReadNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)accountName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailReadNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)parentFolderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailReadNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentFolderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMBinaryId*)messageEntryId {
    ComPtr<ABI::Windows::Phone::Notification::Management::IBinaryId> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailReadNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageEntryId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPNMBinaryId>(unmarshalledReturn.Get());
}

- (BOOL)isRead {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailReadNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRead(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

@end

@implementation WPNMEmailNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)accountName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)parentFolderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentFolderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)senderName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SenderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)senderAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SenderAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAEEmailMessage*)emailMessage {
    ComPtr<ABI::Windows::ApplicationModel::Email::IEmailMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmailMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAEEmailMessage>(unmarshalledReturn.Get());
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

- (WPNMBinaryId*)messageEntryId {
    ComPtr<ABI::Windows::Phone::Notification::Management::IBinaryId> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IEmailNotificationTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageEntryId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPNMBinaryId>(unmarshalledReturn.Get());
}

@end

@implementation WPNMPhoneLineDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)lineId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)lineNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)defaultOutgoingLine {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultOutgoingLine(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)voicemailCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_VoicemailCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WPNMPhoneLineRegistrationState)registrationState {
    ABI::Windows::Phone::Notification::Management::PhoneLineRegistrationState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_RegistrationState(&unmarshalledReturn));
    return (WPNMPhoneLineRegistrationState)unmarshalledReturn;
}

- (unsigned int)missedCallCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MissedCallCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WPNMPhoneCallDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)phoneLine {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneLine(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned int)callId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WPNMPhoneCallTransport)callTransport {
    ABI::Windows::Phone::Notification::Management::PhoneCallTransport unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallTransport(&unmarshalledReturn));
    return (WPNMPhoneCallTransport)unmarshalledReturn;
}

- (WPNMPhoneMediaType)callMediaType {
    ABI::Windows::Phone::Notification::Management::PhoneMediaType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallMediaType(&unmarshalledReturn));
    return (WPNMPhoneMediaType)unmarshalledReturn;
}

- (WPNMPhoneCallDirection)callDirection {
    ABI::Windows::Phone::Notification::Management::PhoneCallDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallDirection(&unmarshalledReturn));
    return (WPNMPhoneCallDirection)unmarshalledReturn;
}

- (WPNMPhoneCallState)state {
    ABI::Windows::Phone::Notification::Management::PhoneCallState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WPNMPhoneCallState)unmarshalledReturn;
}

- (unsigned int)conferenceCallId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConferenceCallId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)startTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)endTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)phoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)contactName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WPNMTextResponse* */)presetTextResponses {
    ComPtr<IVectorView<ABI::Windows::Phone::Notification::Management::TextResponse*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PresetTextResponses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WPNMTextResponse_create(unmarshalledReturn.Get());
}

@end

@implementation WPNMPhoneNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IPhoneNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WPNMPhoneNotificationType)phoneNotificationType {
    ABI::Windows::Phone::Notification::Management::PhoneNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneNotificationType(&unmarshalledReturn));
    return (WPNMPhoneNotificationType)unmarshalledReturn;
}

- (WPNMPhoneCallDetails*)callDetails {
    ComPtr<ABI::Windows::Phone::Notification::Management::IPhoneCallDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPNMPhoneCallDetails>(unmarshalledReturn.Get());
}

- (WFGUID*)phoneLineChangedId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IPhoneNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneLineChangedId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

@end

@implementation WPNMSpeedDialEntry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::ISpeedDialEntry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)phoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ISpeedDialEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)numberType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ISpeedDialEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)contactName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ISpeedDialEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WPNMReminderNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)reminderId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReminderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)details {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Details(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WAAAppointment*)appointment {
    ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Appointment(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppointment>(unmarshalledReturn.Get());
}

- (WPNMReminderState)reminderState {
    ABI::Windows::Phone::Notification::Management::ReminderState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReminderState(&unmarshalledReturn));
    return (WPNMReminderState)unmarshalledReturn;
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

- (NSString*)instanceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IReminderNotificationTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WPNMCalendarChangedNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::ICalendarChangedNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WPNMCalendarChangedEvent)eventType {
    ABI::Windows::Phone::Notification::Management::CalendarChangedEvent unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICalendarChangedNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_EventType(&unmarshalledReturn));
    return (WPNMCalendarChangedEvent)unmarshalledReturn;
}

- (NSString*)itemId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICalendarChangedNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

@end

@implementation WPNMToastNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IToastNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)text1 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IToastNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)text2 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IToastNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)text3 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IToastNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)text4 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IToastNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text4(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)suppressPopup {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IToastNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuppressPopup(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

- (NSString*)instanceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IToastNotificationTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WPNMCortanaTileNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)tileId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)content {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)largeContent1 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LargeContent1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)largeContent2 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LargeContent2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)emphasizedText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_EmphasizedText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)nonWrappedSmallContent1 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_NonWrappedSmallContent1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)nonWrappedSmallContent2 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_NonWrappedSmallContent2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)nonWrappedSmallContent3 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_NonWrappedSmallContent3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)nonWrappedSmallContent4 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_NonWrappedSmallContent4(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)source {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::ICortanaTileNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

@end

@implementation WPNMMediaMetadata

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IMediaMetadata> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IMediaMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)subtitle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IMediaMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)artist {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IMediaMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_Artist(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)album {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IMediaMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_Album(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)track {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IMediaMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IMediaMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WSSIRandomAccessStreamReference>*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IMediaMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

@end

@implementation WPNMMediaControlsTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IMediaControlsTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WPNMPlaybackStatus)playbackStatus {
    ABI::Windows::Phone::Notification::Management::PlaybackStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IMediaControlsTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackStatus(&unmarshalledReturn));
    return (WPNMPlaybackStatus)unmarshalledReturn;
}

- (WPNMMediaMetadata*)mediaMetadata {
    ComPtr<ABI::Windows::Phone::Notification::Management::IMediaMetadata> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IMediaControlsTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaMetadata(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPNMMediaMetadata>(unmarshalledReturn.Get());
}

- (WFDateTime*)timeCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)appDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WPNMAccessoryNotificationType)accessoryNotificationType {
    ABI::Windows::Phone::Notification::Management::AccessoryNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessoryNotificationType(&unmarshalledReturn));
    return (WPNMAccessoryNotificationType)unmarshalledReturn;
}

- (BOOL)startedProcessing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartedProcessing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setStartedProcessing:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartedProcessing((boolean)value));
}

@end

@implementation WPNMVolumeInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Notification::Management::IVolumeInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)systemVolume {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IVolumeInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemVolume(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)callVolume {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IVolumeInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallVolume(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)mediaVolume {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IVolumeInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaVolume(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isMuted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IVolumeInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMuted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WPNMVibrateState)isVibrateEnabled {
    ABI::Windows::Phone::Notification::Management::VibrateState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Notification::Management::IVolumeInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVibrateEnabled(&unmarshalledReturn));
    return (WPNMVibrateState)unmarshalledReturn;
}

@end

@implementation WPNMAccessoryManager

ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryManager2> WPNMIAccessoryManager2_inst() {
    ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryManager2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.Notification.Management.AccessoryManager").Get(), &inst));
    return inst;
}

+ (void)ringDevice {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->RingDevice());
}

+ (NSArray* /* WPNMSpeedDialEntry* */)speedDialList {
    ComPtr<IVectorView<ABI::Windows::Phone::Notification::Management::SpeedDialEntry*>> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->get_SpeedDialList(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WPNMSpeedDialEntry_create(unmarshalledReturn.Get());
}

+ (void)clearToast:(NSString*)instanceId {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->ClearToast(nsStrToHstr(instanceId).Get()));
}

+ (BOOL)isPhonePinLocked {
    boolean unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsPhonePinLocked(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)increaseVolume:(int)step {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->IncreaseVolume(step));
}

+ (void)decreaseVolume:(int)step {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->DecreaseVolume(step));
}

+ (void)setMute:(BOOL)mute {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->SetMute((boolean)mute));
}

+ (void)setRingerVibrate:(BOOL)ringer vibrate:(BOOL)vibrate {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->SetRingerVibrate((boolean)ringer, (boolean)vibrate));
}

+ (WPNMVolumeInfo*)volumeInfo {
    ComPtr<ABI::Windows::Phone::Notification::Management::IVolumeInfo> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->get_VolumeInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPNMVolumeInfo>(unmarshalledReturn.Get());
}

+ (NSArray* /* WPNMEmailAccountInfo* */)getAllEmailAccounts {
    ComPtr<IVectorView<ABI::Windows::Phone::Notification::Management::EmailAccountInfo*>> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->GetAllEmailAccounts(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WPNMEmailAccountInfo_create(unmarshalledReturn.Get());
}

+ (NSArray* /* WPNMEmailFolderInfo* */)getFolders:(NSString*)emailAccount {
    ComPtr<IVectorView<ABI::Windows::Phone::Notification::Management::EmailFolderInfo*>> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->GetFolders(nsStrToHstr(emailAccount).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WPNMEmailFolderInfo_create(unmarshalledReturn.Get());
}

+ (void)enableEmailNotificationEmailAccount:(NSString*)emailAccount {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->EnableEmailNotificationEmailAccount(nsStrToHstr(emailAccount).Get()));
}

+ (void)disableEmailNotificationEmailAccount:(NSString*)emailAccount {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->DisableEmailNotificationEmailAccount(nsStrToHstr(emailAccount).Get()));
}

+ (void)enableEmailNotificationFolderFilter:(NSString*)emailAccount folders:(NSArray* /* NSString * */)folders {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(_comInst->EnableEmailNotificationFolderFilter(
        nsStrToHstr(emailAccount).Get(),
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToVectorView<NSString, HSTRING>(folders).Get())));
}

+ (void)updateEmailReadStatus:(WPNMBinaryId*)messageEntryId isRead:(BOOL)isRead {
    auto _comInst = WPNMIAccessoryManager2_inst();
    THROW_NS_IF_FAILED(
        _comInst->UpdateEmailReadStatus(_getRtInterface<ABI::Windows::Phone::Notification::Management::IBinaryId>(messageEntryId).Get(),
                                        (boolean)isRead));
}

ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryManager3> WPNMIAccessoryManager3_inst() {
    ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryManager3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.Notification.Management.AccessoryManager").Get(), &inst));
    return inst;
}

+ (void)snoozeAlarmByInstanceId:(NSString*)instanceId {
    auto _comInst = WPNMIAccessoryManager3_inst();
    THROW_NS_IF_FAILED(_comInst->SnoozeAlarmByInstanceId(nsStrToHstr(instanceId).Get()));
}

+ (void)dismissAlarmByInstanceId:(NSString*)instanceId {
    auto _comInst = WPNMIAccessoryManager3_inst();
    THROW_NS_IF_FAILED(_comInst->DismissAlarmByInstanceId(nsStrToHstr(instanceId).Get()));
}

+ (void)snoozeReminderByInstanceId:(NSString*)instanceId {
    auto _comInst = WPNMIAccessoryManager3_inst();
    THROW_NS_IF_FAILED(_comInst->SnoozeReminderByInstanceId(nsStrToHstr(instanceId).Get()));
}

+ (void)dismissReminderByInstanceId:(NSString*)instanceId {
    auto _comInst = WPNMIAccessoryManager3_inst();
    THROW_NS_IF_FAILED(_comInst->DismissReminderByInstanceId(nsStrToHstr(instanceId).Get()));
}

ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryManager> WPNMIAccessoryManager_inst() {
    ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryManager> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.Notification.Management.AccessoryManager").Get(), &inst));
    return inst;
}

+ (NSString*)registerAccessoryApp {
    HSTRING unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterAccessoryApp(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (RTObject<WPNMIAccessoryNotificationTriggerDetails>*)getNextTriggerDetails {
    ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->GetNextTriggerDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPNMIAccessoryNotificationTriggerDetails>(unmarshalledReturn.Get());
}

+ (void)processTriggerDetails:(RTObject<WPNMIAccessoryNotificationTriggerDetails>*)pDetails {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->ProcessTriggerDetails(
        _getRtInterface<ABI::Windows::Phone::Notification::Management::IAccessoryNotificationTriggerDetails>(pDetails).Get()));
}

+ (NSArray* /* WPNMPhoneLineDetails* */)phoneLineDetails {
    ComPtr<IVectorView<ABI::Windows::Phone::Notification::Management::PhoneLineDetails*>> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_PhoneLineDetails(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WPNMPhoneLineDetails_create(unmarshalledReturn.Get());
}

+ (WPNMPhoneLineDetails*)getPhoneLineDetails:(WFGUID*)phoneLine {
    ComPtr<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->GetPhoneLineDetails(phoneLine.guidValue, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPNMPhoneLineDetails>(unmarshalledReturn.Get());
}

+ (void)acceptPhoneCall:(unsigned int)phoneCallId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->AcceptPhoneCall(phoneCallId));
}

+ (void)acceptPhoneCallOnEndpoint:(unsigned int)phoneCallId endPoint:(WPNMPhoneCallAudioEndpoint)endPoint {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(
        _comInst->AcceptPhoneCallOnEndpoint(phoneCallId, (ABI::Windows::Phone::Notification::Management::PhoneCallAudioEndpoint)endPoint));
}

+ (void)acceptPhoneCallWithVideo:(unsigned int)phoneCallId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->AcceptPhoneCallWithVideo(phoneCallId));
}

+ (void)acceptPhoneCallWithVideoOnAudioEndpoint:(unsigned int)phoneCallId endPoint:(WPNMPhoneCallAudioEndpoint)endPoint {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(
        _comInst->AcceptPhoneCallWithVideoOnAudioEndpoint(phoneCallId,
                                                          (ABI::Windows::Phone::Notification::Management::PhoneCallAudioEndpoint)endPoint));
}

+ (void)rejectPhoneCall:(unsigned int)phoneCallId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->RejectPhoneCall(phoneCallId));
}

+ (void)rejectPhoneCallWithText:(unsigned int)phoneCallId textResponseID:(unsigned int)textResponseID {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->RejectPhoneCallWithText(phoneCallId, textResponseID));
}

+ (void)makePhoneCall:(WFGUID*)phoneLine phoneNumber:(NSString*)phoneNumber {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->MakePhoneCall(phoneLine.guidValue, nsStrToHstr(phoneNumber).Get()));
}

+ (void)makePhoneCallOnAudioEndpoint:(WFGUID*)phoneLine phoneNumber:(NSString*)phoneNumber endPoint:(WPNMPhoneCallAudioEndpoint)endPoint {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(
        _comInst->MakePhoneCallOnAudioEndpoint(phoneLine.guidValue,
                                               nsStrToHstr(phoneNumber).Get(),
                                               (ABI::Windows::Phone::Notification::Management::PhoneCallAudioEndpoint)endPoint));
}

+ (void)makePhoneCallWithVideo:(WFGUID*)phoneLine phoneNumber:(NSString*)phoneNumber {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->MakePhoneCallWithVideo(phoneLine.guidValue, nsStrToHstr(phoneNumber).Get()));
}

+ (void)makePhoneCallWithVideoOnAudioEndpoint:(WFGUID*)phoneLine
                                  phoneNumber:(NSString*)phoneNumber
                                     endPoint:(WPNMPhoneCallAudioEndpoint)endPoint {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(
        _comInst->MakePhoneCallWithVideoOnAudioEndpoint(phoneLine.guidValue,
                                                        nsStrToHstr(phoneNumber).Get(),
                                                        (ABI::Windows::Phone::Notification::Management::PhoneCallAudioEndpoint)endPoint));
}

+ (void)swapPhoneCalls:(unsigned int)phoneCallIdToHold phoneCallIdOnHold:(unsigned int)phoneCallIdOnHold {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->SwapPhoneCalls(phoneCallIdToHold, phoneCallIdOnHold));
}

+ (void)holdPhoneCall:(unsigned int)phoneCallId holdCall:(BOOL)holdCall {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->HoldPhoneCall(phoneCallId, (boolean)holdCall));
}

+ (void)endPhoneCall:(unsigned int)phoneCallId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->EndPhoneCall(phoneCallId));
}

+ (void)setPhoneMute:(BOOL)value {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->put_PhoneMute((boolean)value));
}

+ (BOOL)phoneMute {
    boolean unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_PhoneMute(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setPhoneCallAudioEndpoint:(WPNMPhoneCallAudioEndpoint)value {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->put_PhoneCallAudioEndpoint((ABI::Windows::Phone::Notification::Management::PhoneCallAudioEndpoint)value));
}

+ (WPNMPhoneCallAudioEndpoint)phoneCallAudioEndpoint {
    ABI::Windows::Phone::Notification::Management::PhoneCallAudioEndpoint unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_PhoneCallAudioEndpoint(&unmarshalledReturn));
    return (WPNMPhoneCallAudioEndpoint)unmarshalledReturn;
}

+ (void)snoozeAlarm:(WFGUID*)alarmId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->SnoozeAlarm(alarmId.guidValue));
}

+ (void)snoozeAlarmForSpecifiedTime:(WFGUID*)alarmId timeSpan:(WFTimeSpan*)timeSpan {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->SnoozeAlarmForSpecifiedTime(alarmId.guidValue, *[timeSpan internalStruct]));
}

+ (void)dismissAlarm:(WFGUID*)alarmId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->DismissAlarm(alarmId.guidValue));
}

+ (void)snoozeReminder:(WFGUID*)reminderId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->SnoozeReminder(reminderId.guidValue));
}

+ (void)snoozeReminderForSpecifiedTime:(WFGUID*)reminderId timeSpan:(WFTimeSpan*)timeSpan {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->SnoozeReminderForSpecifiedTime(reminderId.guidValue, *[timeSpan internalStruct]));
}

+ (void)dismissReminder:(WFGUID*)reminderId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->DismissReminder(reminderId.guidValue));
}

+ (WPNMMediaMetadata*)getMediaMetadata {
    ComPtr<ABI::Windows::Phone::Notification::Management::IMediaMetadata> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->GetMediaMetadata(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPNMMediaMetadata>(unmarshalledReturn.Get());
}

+ (WPNMPlaybackCapability)mediaPlaybackCapabilities {
    ABI::Windows::Phone::Notification::Management::PlaybackCapability unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediaPlaybackCapabilities(&unmarshalledReturn));
    return (WPNMPlaybackCapability)unmarshalledReturn;
}

+ (WPNMPlaybackStatus)mediaPlaybackStatus {
    ABI::Windows::Phone::Notification::Management::PlaybackStatus unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediaPlaybackStatus(&unmarshalledReturn));
    return (WPNMPlaybackStatus)unmarshalledReturn;
}

+ (void)performMediaPlaybackCommand:(WPNMPlaybackCommand)command {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->PerformMediaPlaybackCommand((ABI::Windows::Phone::Notification::Management::PlaybackCommand)command));
}

+ (BOOL)doNotDisturbEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_DoNotDisturbEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)drivingModeEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_DrivingModeEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)batterySaverState {
    boolean unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_BatterySaverState(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (NSDictionary* /* NSString *, WPNMAppNotificationInfo* */)getApps {
    ComPtr<IMapView<HSTRING, ABI::Windows::Phone::Notification::Management::AppNotificationInfo*>> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->GetApps(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WPNMAppNotificationInfo_create(unmarshalledReturn.Get());
}

+ (void)enableNotificationsForApplication:(NSString*)appId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->EnableNotificationsForApplication(nsStrToHstr(appId).Get()));
}

+ (void)disableNotificationsForApplication:(NSString*)appId {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->DisableNotificationsForApplication(nsStrToHstr(appId).Get()));
}

+ (BOOL)isNotificationEnabledForApplication:(NSString*)appId {
    boolean unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->IsNotificationEnabledForApplication(nsStrToHstr(appId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (int)getEnabledAccessoryNotificationTypes {
    int unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->GetEnabledAccessoryNotificationTypes(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)enableAccessoryNotificationTypes:(int)accessoryNotificationTypes {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->EnableAccessoryNotificationTypes(accessoryNotificationTypes));
}

+ (void)disableAllAccessoryNotificationTypes {
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->DisableAllAccessoryNotificationTypes());
}

+ (BOOL)getUserConsent {
    boolean unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->GetUserConsent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (RTObject<WSSIRandomAccessStreamReference>*)getAppIcon:(NSString*)appId {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = WPNMIAccessoryManager_inst();
    THROW_NS_IF_FAILED(_comInst->GetAppIcon(nsStrToHstr(appId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WPNMEmailAccountInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Phone::Notification::Management::EmailAccountInfo*>,
                                         RTArrayObj<ABI::Windows::Phone::Notification::Management::IEmailAccountInfo*,
                                                    IVectorView<ABI::Windows::Phone::Notification::Management::EmailAccountInfo*>,
                                                    WPNMEmailAccountInfo,
                                                    ABI::Windows::Phone::Notification::Management::EmailAccountInfo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WPNMEmailFolderInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Phone::Notification::Management::EmailFolderInfo*>,
                                         RTArrayObj<ABI::Windows::Phone::Notification::Management::IEmailFolderInfo*,
                                                    IVectorView<ABI::Windows::Phone::Notification::Management::EmailFolderInfo*>,
                                                    WPNMEmailFolderInfo,
                                                    ABI::Windows::Phone::Notification::Management::EmailFolderInfo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WPNMPhoneLineDetails_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Phone::Notification::Management::PhoneLineDetails*>,
                                         RTArrayObj<ABI::Windows::Phone::Notification::Management::IPhoneLineDetails*,
                                                    IVectorView<ABI::Windows::Phone::Notification::Management::PhoneLineDetails*>,
                                                    WPNMPhoneLineDetails,
                                                    ABI::Windows::Phone::Notification::Management::PhoneLineDetails*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WPNMSpeedDialEntry_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Phone::Notification::Management::SpeedDialEntry*>,
                                         RTArrayObj<ABI::Windows::Phone::Notification::Management::ISpeedDialEntry*,
                                                    IVectorView<ABI::Windows::Phone::Notification::Management::SpeedDialEntry*>,
                                                    WPNMSpeedDialEntry,
                                                    ABI::Windows::Phone::Notification::Management::SpeedDialEntry*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WPNMTextResponse_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Phone::Notification::Management::TextResponse*>,
                                         RTArrayObj<ABI::Windows::Phone::Notification::Management::ITextResponse*,
                                                    IVectorView<ABI::Windows::Phone::Notification::Management::TextResponse*>,
                                                    WPNMTextResponse,
                                                    ABI::Windows::Phone::Notification::Management::TextResponse*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WPNMAppNotificationInfo_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::Phone::Notification::Management::AppNotificationInfo*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Phone::Notification::Management::AppNotificationInfo*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::Phone::Notification::Management::AppNotificationInfo*,
                     ABI::Windows::Phone::Notification::Management::IAppNotificationInfo*,
                     NSString,
                     WPNMAppNotificationInfo,
                     IMapView<HSTRING, ABI::Windows::Phone::Notification::Management::AppNotificationInfo*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
