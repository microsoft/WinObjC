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

// WindowsUINotificationsManagement_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUINotifications_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::UI::Notifications::Management::IUserNotificationListenerStatics> WUNMIUserNotificationListenerStatics_inst();

id RTProxiedNSArray_WUNUserNotification_create(IInspectable* val);

@class RTProxiedNSArray_WUNUserNotification;

#ifndef __ITypedEventHandler_Windows_UI_Notifications_Management_UserNotificationListener_Windows_UI_Notifications_UserNotificationChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Notifications_Management_UserNotificationListener_Windows_UI_Notifications_UserNotificationChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_UI_Notifications_Management_UserNotificationListener_Windows_UI_Notifications_UserNotificationChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Notifications::Management::UserNotificationListener*,
                                                       ABI::Windows::UI::Notifications::UserNotificationChangedEventArgs*>> {
    void (^_delegate)(WUNMUserNotificationListener*, WUNUserNotificationChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Notifications_Management_UserNotificationListener_Windows_UI_Notifications_UserNotificationChangedEventArgs(
        void (^del)(WUNMUserNotificationListener*, WUNUserNotificationChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Notifications_Management_UserNotificationListener_Windows_UI_Notifications_UserNotificationChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Notifications::Management::IUserNotificationListener* arg0,
                                             ABI::Windows::UI::Notifications::IUserNotificationChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUNMUserNotificationListener>(arg0), _createRtProxy<WUNUserNotificationChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
