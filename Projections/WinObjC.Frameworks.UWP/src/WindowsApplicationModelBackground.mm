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

// WindowsApplicationModelBackground.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Background.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelBackground.h"
#include "WindowsApplicationModelBackground_priv.h"

@implementation WABIBackgroundTaskInstance

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)instanceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WABBackgroundTaskRegistration*)task {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Task(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABBackgroundTaskRegistration>(unmarshalledReturn.Get());
}

- (unsigned int)progress {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setProgress:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Progress(value));
}

- (RTObject*)triggerDetails {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerDetails(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addCanceledEvent:(WABBackgroundTaskCanceledEventHandler)cancelHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->add_Canceled(Make<WABBackgroundTaskCanceledEventHandler_shim>(cancelHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCanceledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Canceled(cookie));
}

- (unsigned int)suspendedCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuspendedCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WABBackgroundTaskDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABBackgroundTaskDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WABIBackgroundTaskInstance2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)getThrottleCount:(WABBackgroundTaskThrottleCounter)counter {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance2>(self);
    THROW_NS_IF_FAILED(_comInst->GetThrottleCount((ABI::Windows::ApplicationModel::Background::BackgroundTaskThrottleCounter)counter,
                                                  &unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFGUID*)instanceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WABBackgroundTaskRegistration*)task {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Task(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABBackgroundTaskRegistration>(unmarshalledReturn.Get());
}

- (unsigned int)progress {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setProgress:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Progress(value));
}

- (RTObject*)triggerDetails {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerDetails(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addCanceledEvent:(WABBackgroundTaskCanceledEventHandler)cancelHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->add_Canceled(Make<WABBackgroundTaskCanceledEventHandler_shim>(cancelHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCanceledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Canceled(cookie));
}

- (unsigned int)suspendedCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuspendedCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WABBackgroundTaskDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABBackgroundTaskDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WABIBackgroundTaskInstance4

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance4> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance4>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

- (WFGUID*)instanceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WABBackgroundTaskRegistration*)task {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Task(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABBackgroundTaskRegistration>(unmarshalledReturn.Get());
}

- (unsigned int)progress {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setProgress:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->put_Progress(value));
}

- (RTObject*)triggerDetails {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerDetails(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addCanceledEvent:(WABBackgroundTaskCanceledEventHandler)cancelHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->add_Canceled(Make<WABBackgroundTaskCanceledEventHandler_shim>(cancelHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCanceledEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Canceled(cookie));
}

- (unsigned int)suspendedCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuspendedCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WABBackgroundTaskDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABBackgroundTaskDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WABIBackgroundTask

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTask> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)run:(RTObject<WABIBackgroundTaskInstance>*)taskInstance {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTask>(self);
    THROW_NS_IF_FAILED(
        _comInst->Run(_getRtInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance>(taskInstance).Get()));
}

@end

@implementation WABIBackgroundTaskRegistration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)taskId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_TaskId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addProgressEvent:(WABBackgroundTaskProgressEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->add_Progress(Make<WABBackgroundTaskProgressEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeProgressEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Progress(cookie));
}

- (EventRegistrationToken)addCompletedEvent:(WABBackgroundTaskCompletedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(Make<WABBackgroundTaskCompletedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(cookie));
}

- (void)unregister:(BOOL)cancelTask {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->Unregister((boolean)cancelTask));
}

@end

@implementation WABIBackgroundTaskRegistration2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WABIBackgroundTrigger>*)trigger {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Trigger(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABIBackgroundTrigger>(unmarshalledReturn.Get());
}

- (WFGUID*)taskId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_TaskId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addProgressEvent:(WABBackgroundTaskProgressEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->add_Progress(Make<WABBackgroundTaskProgressEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeProgressEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Progress(cookie));
}

- (EventRegistrationToken)addCompletedEvent:(WABBackgroundTaskCompletedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(Make<WABBackgroundTaskCompletedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(cookie));
}

- (void)unregister:(BOOL)cancelTask {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->Unregister((boolean)cancelTask));
}

@end

@implementation WABIBackgroundTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WABIBackgroundCondition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundCondition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WABAlarmApplicationManager

ComPtr<ABI::Windows::ApplicationModel::Background::IAlarmApplicationManagerStatics> WABIAlarmApplicationManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IAlarmApplicationManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.AlarmApplicationManager").Get(), &inst));
    return inst;
}

+ (void)requestAccessAsyncWithSuccess:(void (^)(WABAlarmAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::AlarmAccessStatus>> unmarshalledReturn;
    auto _comInst = WABIAlarmApplicationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::AlarmAccessStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::AlarmAccessStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::AlarmAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABAlarmAccessStatus)result);
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

+ (WABAlarmAccessStatus)getAccessStatus {
    ABI::Windows::ApplicationModel::Background::AlarmAccessStatus unmarshalledReturn;
    auto _comInst = WABIAlarmApplicationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetAccessStatus(&unmarshalledReturn));
    return (WABAlarmAccessStatus)unmarshalledReturn;
}

@end

@implementation WABPhoneTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IPhoneTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IPhoneTriggerFactory> WABIPhoneTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IPhoneTriggerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Background.PhoneTrigger").Get(),
                                                       &inst));
    return inst;
}

+ (WABPhoneTrigger*)make:(WACBPhoneTriggerType)type oneShot:(BOOL)oneShot {
    ComPtr<ABI::Windows::ApplicationModel::Background::IPhoneTrigger> unmarshalledReturn;
    auto _comInst = WABIPhoneTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create((ABI::Windows::ApplicationModel::Calls::Background::PhoneTriggerType)type,
                                        (boolean)oneShot,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABPhoneTrigger>(unmarshalledReturn.Get()) retain];
}

- (BOOL)oneShot {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IPhoneTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_OneShot(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WACBPhoneTriggerType)triggerType {
    ABI::Windows::ApplicationModel::Calls::Background::PhoneTriggerType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IPhoneTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerType(&unmarshalledReturn));
    return (WACBPhoneTriggerType)unmarshalledReturn;
}

@end

@implementation WABCommunicationBlockingAppSetAsActiveTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.CommunicationBlockingAppSetAsActiveTrigger").Get(), &out));
    return [_createRtProxy<WABCommunicationBlockingAppSetAsActiveTrigger>(out.Get()) retain];
}

@end

@implementation WABSmartCardTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISmartCardTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::ISmartCardTriggerFactory> WABISmartCardTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISmartCardTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.SmartCardTrigger").Get(), &inst));
    return inst;
}

+ (WABSmartCardTrigger*)make:(WDSSmartCardTriggerType)triggerType {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISmartCardTrigger> unmarshalledReturn;
    auto _comInst = WABISmartCardTriggerFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::Devices::SmartCards::SmartCardTriggerType)triggerType, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABSmartCardTrigger>(unmarshalledReturn.Get()) retain];
}

- (WDSSmartCardTriggerType)triggerType {
    ABI::Windows::Devices::SmartCards::SmartCardTriggerType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ISmartCardTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerType(&unmarshalledReturn));
    return (WDSSmartCardTriggerType)unmarshalledReturn;
}

@end

@implementation WABAppointmentStoreNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IAppointmentStoreNotificationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.AppointmentStoreNotificationTrigger").Get(), &out));
    return [_createRtProxy<WABAppointmentStoreNotificationTrigger>(out.Get()) retain];
}

@end

@implementation WABApplicationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IApplicationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.ApplicationTrigger").Get(),
                                              &out));
    return [_createRtProxy<WABApplicationTrigger>(out.Get()) retain];
}

- (void)requestAsyncWithSuccess:(void (^)(WABApplicationTriggerResult))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::ApplicationTriggerResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IApplicationTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::ApplicationTriggerResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::ApplicationTriggerResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::ApplicationTriggerResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABApplicationTriggerResult)result);
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

- (void)requestAsyncWithArguments:(WFCValueSet*)arguments
                          success:(void (^)(WABApplicationTriggerResult))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::ApplicationTriggerResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IApplicationTrigger>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestAsyncWithArguments(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(arguments).Get(),
                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::ApplicationTriggerResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::ApplicationTriggerResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::ApplicationTriggerResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABApplicationTriggerResult)result);
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

@implementation WABApplicationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IApplicationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFCValueSet*)arguments {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IApplicationTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Arguments(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

@end

@implementation WABBackgroundExecutionManager

ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundExecutionManagerStatics> WABIBackgroundExecutionManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundExecutionManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.BackgroundExecutionManager").Get(), &inst));
    return inst;
}

+ (void)requestAccessAsyncWithSuccess:(void (^)(WABBackgroundAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus>>
        unmarshalledReturn;
    auto _comInst = WABIBackgroundExecutionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABBackgroundAccessStatus)result);
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

+ (void)requestAccessForApplicationAsync:(NSString*)applicationId
                                 success:(void (^)(WABBackgroundAccessStatus))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus>>
        unmarshalledReturn;
    auto _comInst = WABIBackgroundExecutionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessForApplicationAsync(nsStrToHstr(applicationId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABBackgroundAccessStatus)result);
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

+ (void)removeAccess {
    auto _comInst = WABIBackgroundExecutionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RemoveAccess());
}

+ (void)removeAccessForApplication:(NSString*)applicationId {
    auto _comInst = WABIBackgroundExecutionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RemoveAccessForApplication(nsStrToHstr(applicationId).Get()));
}

+ (WABBackgroundAccessStatus)getAccessStatus {
    ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus unmarshalledReturn;
    auto _comInst = WABIBackgroundExecutionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetAccessStatus(&unmarshalledReturn));
    return (WABBackgroundAccessStatus)unmarshalledReturn;
}

+ (WABBackgroundAccessStatus)getAccessStatusForApplication:(NSString*)applicationId {
    ABI::Windows::ApplicationModel::Background::BackgroundAccessStatus unmarshalledReturn;
    auto _comInst = WABIBackgroundExecutionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetAccessStatusForApplication(nsStrToHstr(applicationId).Get(), &unmarshalledReturn));
    return (WABBackgroundAccessStatus)unmarshalledReturn;
}

@end

@implementation WABMediaProcessingTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IMediaProcessingTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.MediaProcessingTrigger").Get(),
                                              &out));
    return [_createRtProxy<WABMediaProcessingTrigger>(out.Get()) retain];
}

- (void)requestAsyncWithSuccess:(void (^)(WABMediaProcessingTriggerResult))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::MediaProcessingTriggerResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IMediaProcessingTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::MediaProcessingTriggerResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::MediaProcessingTriggerResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::MediaProcessingTriggerResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABMediaProcessingTriggerResult)result);
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

- (void)requestAsyncWithArguments:(WFCValueSet*)arguments
                          success:(void (^)(WABMediaProcessingTriggerResult))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::MediaProcessingTriggerResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IMediaProcessingTrigger>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestAsyncWithArguments(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(arguments).Get(),
                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::MediaProcessingTriggerResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::MediaProcessingTriggerResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::MediaProcessingTriggerResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABMediaProcessingTriggerResult)result);
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

@implementation WABBackgroundTaskRegistration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistrationStatics> WABIBackgroundTaskRegistrationStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistrationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.BackgroundTaskRegistration").Get(), &inst));
    return inst;
}

+ (NSDictionary* /* WFGUID*, RTObject<WABIBackgroundTaskRegistration>* */)allTasks {
    ComPtr<IMapView<GUID, ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration*>> unmarshalledReturn;
    auto _comInst = WABIBackgroundTaskRegistrationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllTasks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_WFGUID_RTObject_WABIBackgroundTaskRegistration_create(unmarshalledReturn.Get());
}

- (WFGUID*)taskId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_TaskId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addProgressEvent:(WABBackgroundTaskProgressEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->add_Progress(Make<WABBackgroundTaskProgressEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeProgressEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Progress(cookie));
}

- (EventRegistrationToken)addCompletedEvent:(WABBackgroundTaskCompletedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(Make<WABBackgroundTaskCompletedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(cookie));
}

- (void)unregister:(BOOL)cancelTask {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->Unregister((boolean)cancelTask));
}

- (RTObject<WABIBackgroundTrigger>*)trigger {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Trigger(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABIBackgroundTrigger>(unmarshalledReturn.Get());
}

@end

@implementation WABBackgroundTaskDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WABBackgroundTaskProgressEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)instanceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned int)progress {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WABBackgroundTaskCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)instanceId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstanceId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)checkResult {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->CheckResult());
}

@end

@implementation WABBackgroundTaskBuilder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.BackgroundTaskBuilder").Get(),
                                              &out));
    return [_createRtProxy<WABBackgroundTaskBuilder>(out.Get()) retain];
}

- (void)setTaskEntryPoint:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->put_TaskEntryPoint(nsStrToHstr(value).Get()));
}

- (NSString*)taskEntryPoint {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->get_TaskEntryPoint(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTrigger:(RTObject<WABIBackgroundTrigger>*)trigger {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetTrigger(_getRtInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger>(trigger).Get()));
}

- (void)addCondition:(RTObject<WABIBackgroundCondition>*)condition {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddCondition(_getRtInterface<ABI::Windows::ApplicationModel::Background::IBackgroundCondition>(condition).Get()));
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WABBackgroundTaskRegistration*)Register {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder>(self);
    THROW_NS_IF_FAILED(_comInst->Register(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABBackgroundTaskRegistration>(unmarshalledReturn.Get());
}

- (void)setCancelOnConditionLoss:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CancelOnConditionLoss((boolean)value));
}

- (BOOL)cancelOnConditionLoss {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CancelOnConditionLoss(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsNetworkRequested:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder3>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsNetworkRequested((boolean)value));
}

- (BOOL)isNetworkRequested {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsNetworkRequested(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WABBackgroundWorkCost

ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundWorkCostStatics> WABIBackgroundWorkCostStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundWorkCostStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.BackgroundWorkCost").Get(), &inst));
    return inst;
}

+ (WABBackgroundWorkCostValue)currentBackgroundWorkCost {
    ABI::Windows::ApplicationModel::Background::BackgroundWorkCostValue unmarshalledReturn;
    auto _comInst = WABIBackgroundWorkCostStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CurrentBackgroundWorkCost(&unmarshalledReturn));
    return (WABBackgroundWorkCostValue)unmarshalledReturn;
}

@end

@implementation WABChatMessageNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IChatMessageNotificationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.ChatMessageNotificationTrigger").Get(), &out));
    return [_createRtProxy<WABChatMessageNotificationTrigger>(out.Get()) retain];
}

@end

@implementation WABChatMessageReceivedNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.ChatMessageReceivedNotificationTrigger").Get(), &out));
    return [_createRtProxy<WABChatMessageReceivedNotificationTrigger>(out.Get()) retain];
}

@end

@implementation WABRcsEndUserMessageAvailableTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.RcsEndUserMessageAvailableTrigger").Get(), &out));
    return [_createRtProxy<WABRcsEndUserMessageAvailableTrigger>(out.Get()) retain];
}

@end

@implementation WABContactStoreNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IContactStoreNotificationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.ContactStoreNotificationTrigger").Get(), &out));
    return [_createRtProxy<WABContactStoreNotificationTrigger>(out.Get()) retain];
}

@end

@implementation WABContentPrefetchTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IContentPrefetchTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IContentPrefetchTriggerFactory> WABIContentPrefetchTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IContentPrefetchTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.ContentPrefetchTrigger").Get(), &inst));
    return inst;
}

+ (WABContentPrefetchTrigger*)make:(WFTimeSpan*)waitInterval {
    ComPtr<ABI::Windows::ApplicationModel::Background::IContentPrefetchTrigger> unmarshalledReturn;
    auto _comInst = WABIContentPrefetchTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(*[waitInterval internalStruct], unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABContentPrefetchTrigger>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.ContentPrefetchTrigger").Get(),
                                              &out));
    return [_createRtProxy<WABContentPrefetchTrigger>(out.Get()) retain];
}

- (WFTimeSpan*)waitInterval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IContentPrefetchTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_WaitInterval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WABEmailStoreNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IEmailStoreNotificationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.EmailStoreNotificationTrigger").Get(), &out));
    return [_createRtProxy<WABEmailStoreNotificationTrigger>(out.Get()) retain];
}

@end

@implementation WABMobileBroadbandRegistrationStateChangeTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.MobileBroadbandRegistrationStateChangeTrigger").Get(), &out));
    return [_createRtProxy<WABMobileBroadbandRegistrationStateChangeTrigger>(out.Get()) retain];
}

@end

@implementation WABMobileBroadbandRadioStateChangeTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.MobileBroadbandRadioStateChangeTrigger").Get(), &out));
    return [_createRtProxy<WABMobileBroadbandRadioStateChangeTrigger>(out.Get()) retain];
}

@end

@implementation WABMobileBroadbandPinLockStateChangeTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.MobileBroadbandPinLockStateChangeTrigger").Get(), &out));
    return [_createRtProxy<WABMobileBroadbandPinLockStateChangeTrigger>(out.Get()) retain];
}

@end

@implementation WABMobileBroadbandDeviceServiceNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.MobileBroadbandDeviceServiceNotificationTrigger").Get(), &out));
    return [_createRtProxy<WABMobileBroadbandDeviceServiceNotificationTrigger>(out.Get()) retain];
}

@end

@implementation WABSecondaryAuthenticationFactorAuthenticationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.SecondaryAuthenticationFactorAuthenticationTrigger").Get(), &out));
    return [_createRtProxy<WABSecondaryAuthenticationFactorAuthenticationTrigger>(out.Get()) retain];
}

@end

@implementation WABSmsMessageReceivedTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory> WABISmsMessageReceivedTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.SmsMessageReceivedTrigger").Get(), &inst));
    return inst;
}

+ (WABSmsMessageReceivedTrigger*)make:(WDSSmsFilterRules*)filterRules {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = WABISmsMessageReceivedTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::Devices::Sms::ISmsFilterRules>(filterRules).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABSmsMessageReceivedTrigger>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WABStorageLibraryContentChangedTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics>
WABIStorageLibraryContentChangedTriggerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.StorageLibraryContentChangedTrigger").Get(), &inst));
    return inst;
}

+ (WABStorageLibraryContentChangedTrigger*)create:(WSStorageLibrary*)storageLibrary {
    ComPtr<ABI::Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger> unmarshalledReturn;
    auto _comInst = WABIStorageLibraryContentChangedTriggerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Storage::IStorageLibrary>(storageLibrary).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABStorageLibraryContentChangedTrigger>(unmarshalledReturn.Get());
}

+ (WABStorageLibraryContentChangedTrigger*)createFromLibraries:(id<NSFastEnumeration> /* WSStorageLibrary* */)storageLibraries {
    ComPtr<ABI::Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger> unmarshalledReturn;
    auto _comInst = WABIStorageLibraryContentChangedTriggerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromLibraries(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::StorageLibrary*,
                                                              ABI::Windows::Storage::IStorageLibrary*>>::type>*>(
            ConvertToIterable<WSStorageLibrary,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::StorageLibrary*,
                                                                                ABI::Windows::Storage::IStorageLibrary*>>(storageLibraries)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABStorageLibraryContentChangedTrigger>(unmarshalledReturn.Get());
}

@end

@implementation WABSystemTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISystemTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::ISystemTriggerFactory> WABISystemTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISystemTriggerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Background.SystemTrigger").Get(),
                                                       &inst));
    return inst;
}

+ (WABSystemTrigger*)make:(WABSystemTriggerType)triggerType oneShot:(BOOL)oneShot {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISystemTrigger> unmarshalledReturn;
    auto _comInst = WABISystemTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create((ABI::Windows::ApplicationModel::Background::SystemTriggerType)triggerType,
                                        (boolean)oneShot,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABSystemTrigger>(unmarshalledReturn.Get()) retain];
}

- (BOOL)oneShot {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ISystemTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_OneShot(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WABSystemTriggerType)triggerType {
    ABI::Windows::ApplicationModel::Background::SystemTriggerType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ISystemTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerType(&unmarshalledReturn));
    return (WABSystemTriggerType)unmarshalledReturn;
}

@end

@implementation WABSystemCondition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISystemCondition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::ISystemConditionFactory> WABISystemConditionFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISystemConditionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Background.SystemCondition").Get(),
                                                       &inst));
    return inst;
}

+ (WABSystemCondition*)make:(WABSystemConditionType)conditionType {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISystemCondition> unmarshalledReturn;
    auto _comInst = WABISystemConditionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create((ABI::Windows::ApplicationModel::Background::SystemConditionType)conditionType,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABSystemCondition>(unmarshalledReturn.Get()) retain];
}

- (WABSystemConditionType)conditionType {
    ABI::Windows::ApplicationModel::Background::SystemConditionType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ISystemCondition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConditionType(&unmarshalledReturn));
    return (WABSystemConditionType)unmarshalledReturn;
}

@end

@implementation WABNetworkOperatorNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory>
WABINetworkOperatorNotificationTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.NetworkOperatorNotificationTrigger").Get(), &inst));
    return inst;
}

+ (WABNetworkOperatorNotificationTrigger*)make:(NSString*)networkAccountId {
    ComPtr<ABI::Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger> unmarshalledReturn;
    auto _comInst = WABINetworkOperatorNotificationTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(networkAccountId).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABNetworkOperatorNotificationTrigger>(unmarshalledReturn.Get()) retain];
}

- (NSString*)networkAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_NetworkAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WABDeviceManufacturerNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory>
WABIDeviceManufacturerNotificationTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.DeviceManufacturerNotificationTrigger").Get(), &inst));
    return inst;
}

+ (WABDeviceManufacturerNotificationTrigger*)make:(NSString*)triggerQualifier oneShot:(BOOL)oneShot {
    ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger> unmarshalledReturn;
    auto _comInst = WABIDeviceManufacturerNotificationTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(triggerQualifier).Get(), (boolean)oneShot, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABDeviceManufacturerNotificationTrigger>(unmarshalledReturn.Get()) retain];
}

- (NSString*)triggerQualifier {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerQualifier(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)oneShot {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_OneShot(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WABCachedFileUpdaterTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSPCachedFileTarget)updateTarget {
    ABI::Windows::Storage::Provider::CachedFileTarget unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_UpdateTarget(&unmarshalledReturn));
    return (WSPCachedFileTarget)unmarshalledReturn;
}

- (WSPFileUpdateRequest*)updateRequest {
    ComPtr<ABI::Windows::Storage::Provider::IFileUpdateRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_UpdateRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPFileUpdateRequest>(unmarshalledReturn.Get());
}

- (BOOL)canRequestUserInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanRequestUserInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WABCachedFileUpdaterTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ICachedFileUpdaterTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.CachedFileUpdaterTrigger").Get(),
                                              &out));
    return [_createRtProxy<WABCachedFileUpdaterTrigger>(out.Get()) retain];
}

@end

@implementation WABTimeTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ITimeTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::ITimeTriggerFactory> WABITimeTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::ITimeTriggerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Background.TimeTrigger").Get(),
                                                       &inst));
    return inst;
}

+ (WABTimeTrigger*)make:(unsigned int)freshnessTime oneShot:(BOOL)oneShot {
    ComPtr<ABI::Windows::ApplicationModel::Background::ITimeTrigger> unmarshalledReturn;
    auto _comInst = WABITimeTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(freshnessTime, (boolean)oneShot, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABTimeTrigger>(unmarshalledReturn.Get()) retain];
}

- (unsigned int)freshnessTime {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ITimeTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_FreshnessTime(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)oneShot {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ITimeTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_OneShot(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WABMaintenanceTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IMaintenanceTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IMaintenanceTriggerFactory> WABIMaintenanceTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IMaintenanceTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.MaintenanceTrigger").Get(), &inst));
    return inst;
}

+ (WABMaintenanceTrigger*)make:(unsigned int)freshnessTime oneShot:(BOOL)oneShot {
    ComPtr<ABI::Windows::ApplicationModel::Background::IMaintenanceTrigger> unmarshalledReturn;
    auto _comInst = WABIMaintenanceTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(freshnessTime, (boolean)oneShot, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABMaintenanceTrigger>(unmarshalledReturn.Get()) retain];
}

- (unsigned int)freshnessTime {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IMaintenanceTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_FreshnessTime(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)oneShot {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IMaintenanceTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_OneShot(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WABDeviceUseTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceUseTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.DeviceUseTrigger").Get(), &out));
    return [_createRtProxy<WABDeviceUseTrigger>(out.Get()) retain];
}

- (void)requestAsyncSimple:(NSString*)deviceId success:(void (^)(WABDeviceTriggerResult))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceUseTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAsyncSimple(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::DeviceTriggerResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABDeviceTriggerResult)result);
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

- (void)requestAsyncWithArguments:(NSString*)deviceId
                        arguments:(NSString*)arguments
                          success:(void (^)(WABDeviceTriggerResult))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceUseTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAsyncWithArguments(nsStrToHstr(deviceId).Get(), nsStrToHstr(arguments).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::DeviceTriggerResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABDeviceTriggerResult)result);
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

@implementation WABDeviceServicingTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceServicingTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.DeviceServicingTrigger").Get(),
                                              &out));
    return [_createRtProxy<WABDeviceServicingTrigger>(out.Get()) retain];
}

- (void)requestAsyncSimple:(NSString*)deviceId
          expectedDuration:(WFTimeSpan*)expectedDuration
                   success:(void (^)(WABDeviceTriggerResult))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceServicingTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAsyncSimple(nsStrToHstr(deviceId).Get(), *[expectedDuration internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::DeviceTriggerResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABDeviceTriggerResult)result);
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

- (void)requestAsyncWithArguments:(NSString*)deviceId
                 expectedDuration:(WFTimeSpan*)expectedDuration
                        arguments:(NSString*)arguments
                          success:(void (^)(WABDeviceTriggerResult))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceServicingTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAsyncWithArguments(nsStrToHstr(deviceId).Get(),
                                                           *[expectedDuration internalStruct],
                                                           nsStrToHstr(arguments).Get(),
                                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceTriggerResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::Background::DeviceTriggerResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WABDeviceTriggerResult)result);
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

@implementation WABRfcommConnectionTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.RfcommConnectionTrigger").Get(),
                                              &out));
    return [_createRtProxy<WABRfcommConnectionTrigger>(out.Get()) retain];
}

- (WDBBRfcommInboundConnectionInformation*)inboundConnection {
    ComPtr<ABI::Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_InboundConnection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBRfcommInboundConnectionInformation>(unmarshalledReturn.Get());
}

- (WDBBRfcommOutboundConnectionInformation*)outboundConnection {
    ComPtr<ABI::Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutboundConnection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBRfcommOutboundConnectionInformation>(unmarshalledReturn.Get());
}

- (BOOL)allowMultipleConnections {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowMultipleConnections(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowMultipleConnections:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowMultipleConnections((boolean)value));
}

- (WNSSocketProtectionLevel)protectionLevel {
    ABI::Windows::Networking::Sockets::SocketProtectionLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionLevel(&unmarshalledReturn));
    return (WNSSocketProtectionLevel)unmarshalledReturn;
}

- (void)setProtectionLevel:(WNSSocketProtectionLevel)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProtectionLevel((ABI::Windows::Networking::Sockets::SocketProtectionLevel)value));
}

- (WNHostName*)remoteHostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteHostName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (void)setRemoteHostName:(WNHostName*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteHostName(_getRtInterface<ABI::Windows::Networking::IHostName>(value).Get()));
}

@end

@implementation WABDeviceConnectionChangeTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics> WABIDeviceConnectionChangeTriggerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.DeviceConnectionChangeTrigger").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WABDeviceConnectionChangeTrigger*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger*>>
        unmarshalledReturn;
    auto _comInst = WABIDeviceConnectionChangeTriggerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WABDeviceConnectionChangeTrigger>(result.Get()));
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

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)canMaintainConnection {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanMaintainConnection(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)maintainConnection {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaintainConnection(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setMaintainConnection:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaintainConnection((boolean)value));
}

@end

@implementation WABGattCharacteristicNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory>
WABIGattCharacteristicNotificationTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.GattCharacteristicNotificationTrigger").Get(), &inst));
    return inst;
}

+ (WABGattCharacteristicNotificationTrigger*)make:(WDBGGattCharacteristic*)characteristic {
    ComPtr<ABI::Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger> unmarshalledReturn;
    auto _comInst = WABIGattCharacteristicNotificationTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>(characteristic).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABGattCharacteristicNotificationTrigger>(unmarshalledReturn.Get()) retain];
}

- (WDBGGattCharacteristic*)characteristic {
    ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_Characteristic(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBGGattCharacteristic>(unmarshalledReturn.Get());
}

@end

@implementation WABBluetoothLEAdvertisementWatcherTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.BluetoothLEAdvertisementWatcherTrigger").Get(), &out));
    return [_createRtProxy<WABBluetoothLEAdvertisementWatcherTrigger>(out.Get()) retain];
}

- (WFTimeSpan*)minSamplingInterval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinSamplingInterval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)maxSamplingInterval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxSamplingInterval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)minOutOfRangeTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinOutOfRangeTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)maxOutOfRangeTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxOutOfRangeTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WDBBluetoothSignalStrengthFilter*)signalStrengthFilter {
    ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignalStrengthFilter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBBluetoothSignalStrengthFilter>(unmarshalledReturn.Get());
}

- (void)setSignalStrengthFilter:(WDBBluetoothSignalStrengthFilter*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SignalStrengthFilter(_getRtInterface<ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>(value).Get()));
}

- (WDBABluetoothLEAdvertisementFilter*)advertisementFilter {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdvertisementFilter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBABluetoothLEAdvertisementFilter>(unmarshalledReturn.Get());
}

- (void)setAdvertisementFilter:(WDBABluetoothLEAdvertisementFilter*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->put_AdvertisementFilter(
        _getRtInterface<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter>(value).Get()));
}

@end

@implementation WABBluetoothLEAdvertisementPublisherTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.BluetoothLEAdvertisementPublisherTrigger").Get(), &out));
    return [_createRtProxy<WABBluetoothLEAdvertisementPublisherTrigger>(out.Get()) retain];
}

- (WDBABluetoothLEAdvertisement*)advertisement {
    ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_Advertisement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDBABluetoothLEAdvertisement>(unmarshalledReturn.Get());
}

@end

@implementation WABDeviceWatcherTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceWatcherTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WABLocationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ILocationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::ILocationTriggerFactory> WABILocationTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::ILocationTriggerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Background.LocationTrigger").Get(),
                                                       &inst));
    return inst;
}

+ (WABLocationTrigger*)make:(WABLocationTriggerType)triggerType {
    ComPtr<ABI::Windows::ApplicationModel::Background::ILocationTrigger> unmarshalledReturn;
    auto _comInst = WABILocationTriggerFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::ApplicationModel::Background::LocationTriggerType)triggerType, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABLocationTrigger>(unmarshalledReturn.Get()) retain];
}

- (WABLocationTriggerType)triggerType {
    ABI::Windows::ApplicationModel::Background::LocationTriggerType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ILocationTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerType(&unmarshalledReturn));
    return (WABLocationTriggerType)unmarshalledReturn;
}

@end

@implementation WABActivitySensorTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IActivitySensorTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IActivitySensorTriggerFactory> WABIActivitySensorTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IActivitySensorTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.ActivitySensorTrigger").Get(), &inst));
    return inst;
}

+ (WABActivitySensorTrigger*)make:(unsigned int)reportIntervalInMilliseconds {
    ComPtr<ABI::Windows::ApplicationModel::Background::IActivitySensorTrigger> unmarshalledReturn;
    auto _comInst = WABIActivitySensorTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(reportIntervalInMilliseconds, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABActivitySensorTrigger>(unmarshalledReturn.Get()) retain];
}

- (NSMutableArray* /* WDSActivityType */)subscribedActivities {
    ComPtr<IVector<ABI::Windows::Devices::Sensors::ActivityType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IActivitySensorTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubscribedActivities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDSActivityType_create(unmarshalledReturn.Get());
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IActivitySensorTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* WDSActivityType */)supportedActivities {
    ComPtr<IVectorView<ABI::Windows::Devices::Sensors::ActivityType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IActivitySensorTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedActivities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSActivityType_create(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::IActivitySensorTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WABSensorDataThresholdTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISensorDataThresholdTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::ISensorDataThresholdTriggerFactory> WABISensorDataThresholdTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISensorDataThresholdTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.SensorDataThresholdTrigger").Get(), &inst));
    return inst;
}

+ (WABSensorDataThresholdTrigger*)make:(RTObject<WDSISensorDataThreshold>*)threshold {
    ComPtr<ABI::Windows::ApplicationModel::Background::ISensorDataThresholdTrigger> unmarshalledReturn;
    auto _comInst = WABISensorDataThresholdTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::Devices::Sensors::ISensorDataThreshold>(threshold).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABSensorDataThresholdTrigger>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WABNetworkOperatorHotspotAuthenticationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.NetworkOperatorHotspotAuthenticationTrigger").Get(), &out));
    return [_createRtProxy<WABNetworkOperatorHotspotAuthenticationTrigger>(out.Get()) retain];
}

@end

@implementation WABSocketActivityTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.SocketActivityTrigger").Get(),
                                              &out));
    return [_createRtProxy<WABSocketActivityTrigger>(out.Get()) retain];
}

- (BOOL)isWakeFromLowPowerSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Background::ISocketActivityTrigger>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWakeFromLowPowerSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WABPushNotificationTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IPushNotificationTriggerFactory> WABIPushNotificationTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IPushNotificationTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.PushNotificationTrigger").Get(), &inst));
    return inst;
}

+ (WABPushNotificationTrigger*)make:(NSString*)applicationId {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = WABIPushNotificationTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABPushNotificationTrigger>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Background.PushNotificationTrigger").Get(),
                                              &out));
    return [_createRtProxy<WABPushNotificationTrigger>(out.Get()) retain];
}

@end

@implementation WABToastNotificationHistoryChangedTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.ToastNotificationHistoryChangedTrigger").Get(), &out));
    return [_createRtProxy<WABToastNotificationHistoryChangedTrigger>(out.Get()) retain];
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory>
WABIToastNotificationHistoryChangedTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.ToastNotificationHistoryChangedTrigger").Get(), &inst));
    return inst;
}

+ (WABToastNotificationHistoryChangedTrigger*)make:(NSString*)applicationId {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = WABIToastNotificationHistoryChangedTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABToastNotificationHistoryChangedTrigger>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WABToastNotificationActionTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IToastNotificationActionTriggerFactory>
WABIToastNotificationActionTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IToastNotificationActionTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.ToastNotificationActionTrigger").Get(), &inst));
    return inst;
}

+ (WABToastNotificationActionTrigger*)make:(NSString*)applicationId {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = WABIToastNotificationActionTriggerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(applicationId).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABToastNotificationActionTrigger>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Background.ToastNotificationActionTrigger").Get(), &out));
    return [_createRtProxy<WABToastNotificationActionTrigger>(out.Get()) retain];
}

@end

@implementation WABUserNotificationChangedTrigger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Background::IUserNotificationChangedTriggerFactory>
WABIUserNotificationChangedTriggerFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Background::IUserNotificationChangedTriggerFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Background.UserNotificationChangedTrigger").Get(), &inst));
    return inst;
}

+ (WABUserNotificationChangedTrigger*)make:(WUNNotificationKinds)notificationKinds {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = WABIUserNotificationChangedTriggerFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::UI::Notifications::NotificationKinds)notificationKinds, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WABUserNotificationChangedTrigger>(unmarshalledReturn.Get()) retain];
}

@end

id RTProxiedIterableNSArray_WSStorageLibrary_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Storage::StorageLibrary*>,
                                                 RTIterableObj<ABI::Windows::Storage::IStorageLibrary*,
                                                               IIterable<ABI::Windows::Storage::StorageLibrary*>,
                                                               WSStorageLibrary,
                                                               ABI::Windows::Storage::StorageLibrary*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSActivityType_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Sensors::ActivityType>,
                                         RTArrayObj<ABI::Windows::Devices::Sensors::ActivityType,
                                                    IVectorView<ABI::Windows::Devices::Sensors::ActivityType>,
                                                    WDSActivityType,
                                                    ABI::Windows::Devices::Sensors::ActivityType,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_WFGUID_RTObject_WABIBackgroundTaskRegistration_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<GUID, ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<GUID, GUID, WFGUID, ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration*>>,
        RTMapViewObj<GUID,
                     GUID,
                     ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration*,
                     ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration*,
                     WFGUID,
                     RTObject<WABIBackgroundTaskRegistration>,
                     IMapView<GUID, ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDSActivityType_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::Sensors::ActivityType>,
                                                RTMutableArrayObj<ABI::Windows::Devices::Sensors::ActivityType,
                                                                  IVector<ABI::Windows::Devices::Sensors::ActivityType>,
                                                                  WDSActivityType,
                                                                  ABI::Windows::Devices::Sensors::ActivityType,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
