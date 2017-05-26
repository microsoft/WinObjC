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

// WindowsNetworkingPushNotifications_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSystem_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUINotifications_priv.h"
ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics2>
WNPIPushNotificationChannelManagerStatics2_inst();
ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics>
WNPIPushNotificationChannelManagerStatics_inst();

#ifndef __ITypedEventHandler_Windows_Networking_PushNotifications_PushNotificationChannel_Windows_Networking_PushNotifications_PushNotificationReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_PushNotifications_PushNotificationChannel_Windows_Networking_PushNotifications_PushNotificationReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Networking_PushNotifications_PushNotificationChannel_Windows_Networking_PushNotifications_PushNotificationReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*,
                                                       ABI::Windows::Networking::PushNotifications::PushNotificationReceivedEventArgs*>> {
    void (^_delegate)(WNPPushNotificationChannel*, WNPPushNotificationReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_PushNotifications_PushNotificationChannel_Windows_Networking_PushNotifications_PushNotificationReceivedEventArgs(
        void (^del)(WNPPushNotificationChannel*, WNPPushNotificationReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_PushNotifications_PushNotificationChannel_Windows_Networking_PushNotifications_PushNotificationReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Networking::PushNotifications::IPushNotificationChannel* arg0,
           ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNPPushNotificationChannel>(arg0), _createRtProxy<WNPPushNotificationReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
