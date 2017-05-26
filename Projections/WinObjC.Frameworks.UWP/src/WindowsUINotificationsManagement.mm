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

// WindowsUINotificationsManagement.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Notifications.Management.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUINotificationsManagement.h"
#include "WindowsUINotificationsManagement_priv.h"

@implementation WUNMUserNotificationListener

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Notifications::Management::IUserNotificationListener> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Notifications::Management::IUserNotificationListenerStatics> WUNMIUserNotificationListenerStatics_inst() {
    ComPtr<ABI::Windows::UI::Notifications::Management::IUserNotificationListenerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Notifications.Management.UserNotificationListener").Get(), &inst));
    return inst;
}

+ (WUNMUserNotificationListener*)current {
    ComPtr<ABI::Windows::UI::Notifications::Management::IUserNotificationListener> unmarshalledReturn;
    auto _comInst = WUNMIUserNotificationListenerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNMUserNotificationListener>(unmarshalledReturn.Get());
}

- (void)requestAccessAsyncWithSuccess:(void (^)(WUNMUserNotificationListenerAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::Management::IUserNotificationListener>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WUNMUserNotificationListenerAccessStatus)result);
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

- (WUNMUserNotificationListenerAccessStatus)getAccessStatus {
    ABI::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::Management::IUserNotificationListener>(self);
    THROW_NS_IF_FAILED(_comInst->GetAccessStatus(&unmarshalledReturn));
    return (WUNMUserNotificationListenerAccessStatus)unmarshalledReturn;
}

- (EventRegistrationToken)addNotificationChangedEvent:(void (^)(WUNMUserNotificationListener*,
                                                                WUNUserNotificationChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::Management::IUserNotificationListener>(self);
    THROW_NS_IF_FAILED(_comInst->add_NotificationChanged(
        Make<
            ITypedEventHandler_Windows_UI_Notifications_Management_UserNotificationListener_Windows_UI_Notifications_UserNotificationChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNotificationChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::Management::IUserNotificationListener>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NotificationChanged(token));
}

- (void)getNotificationsAsync:(WUNNotificationKinds)kinds
                      success:(void (^)(NSArray* /* WUNUserNotification* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Notifications::UserNotification*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::Management::IUserNotificationListener>(self);
    THROW_NS_IF_FAILED(_comInst->GetNotificationsAsync((ABI::Windows::UI::Notifications::NotificationKinds)kinds, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::UI::Notifications::UserNotification*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::UI::Notifications::UserNotification*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::UI::Notifications::UserNotification*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WUNUserNotification_create(result.Get()));
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

- (WUNUserNotification*)getNotification:(unsigned int)notificationId {
    ComPtr<ABI::Windows::UI::Notifications::IUserNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::Management::IUserNotificationListener>(self);
    THROW_NS_IF_FAILED(_comInst->GetNotification(notificationId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNUserNotification>(unmarshalledReturn.Get());
}

- (void)clearNotifications {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::Management::IUserNotificationListener>(self);
    THROW_NS_IF_FAILED(_comInst->ClearNotifications());
}

- (void)removeNotification:(unsigned int)notificationId {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Notifications::Management::IUserNotificationListener>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveNotification(notificationId));
}

@end

id RTProxiedNSArray_WUNUserNotification_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Notifications::UserNotification*>,
                                         RTArrayObj<ABI::Windows::UI::Notifications::IUserNotification*,
                                                    IVectorView<ABI::Windows::UI::Notifications::UserNotification*>,
                                                    WUNUserNotification,
                                                    ABI::Windows::UI::Notifications::UserNotification*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
