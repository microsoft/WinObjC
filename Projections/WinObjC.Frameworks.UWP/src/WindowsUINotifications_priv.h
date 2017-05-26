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

// WindowsUINotifications_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSystem_priv.h"
#include "WindowsApplicationModel_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsDataXmlDom_priv.h"
#include "WindowsFoundationCollections_priv.h"
static ComPtr<ABI::Windows::UI::Notifications::ITileNotificationFactory> WUNITileNotificationFactory_inst();
static ComPtr<ABI::Windows::UI::Notifications::IScheduledTileNotificationFactory> WUNIScheduledTileNotificationFactory_inst();
static ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutNotificationFactory> WUNITileFlyoutNotificationFactory_inst();
static ComPtr<ABI::Windows::UI::Notifications::IBadgeNotificationFactory> WUNIBadgeNotificationFactory_inst();
static ComPtr<ABI::Windows::UI::Notifications::IToastNotificationFactory> WUNIToastNotificationFactory_inst();
static ComPtr<ABI::Windows::UI::Notifications::IScheduledToastNotificationFactory> WUNIScheduledToastNotificationFactory_inst();
ComPtr<ABI::Windows::UI::Notifications::IKnownAdaptiveNotificationHintsStatics> WUNIKnownAdaptiveNotificationHintsStatics_inst();
ComPtr<ABI::Windows::UI::Notifications::IKnownNotificationBindingsStatics> WUNIKnownNotificationBindingsStatics_inst();
ComPtr<ABI::Windows::UI::Notifications::IKnownAdaptiveNotificationTextStylesStatics> WUNIKnownAdaptiveNotificationTextStylesStatics_inst();
ComPtr<ABI::Windows::UI::Notifications::ITileUpdateManagerStatics2> WUNITileUpdateManagerStatics2_inst();
ComPtr<ABI::Windows::UI::Notifications::ITileUpdateManagerStatics> WUNITileUpdateManagerStatics_inst();
ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdateManagerStatics> WUNIBadgeUpdateManagerStatics_inst();
ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdateManagerStatics2> WUNIBadgeUpdateManagerStatics2_inst();
ComPtr<ABI::Windows::UI::Notifications::ITileFlyoutUpdateManagerStatics> WUNITileFlyoutUpdateManagerStatics_inst();
ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerStatics> WUNIToastNotificationManagerStatics_inst();
ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerStatics2> WUNIToastNotificationManagerStatics2_inst();
ComPtr<ABI::Windows::UI::Notifications::IToastNotificationManagerStatics4> WUNIToastNotificationManagerStatics4_inst();

id RTProxiedIterableNSArray_WFUri_create(IInspectable* val);
id RTProxiedNSArray_WUNAdaptiveNotificationText_create(IInspectable* val);
id RTProxiedNSArray_WUNScheduledTileNotification_create(IInspectable* val);
id RTProxiedNSArray_WUNScheduledToastNotification_create(IInspectable* val);
id RTProxiedNSArray_WUNToastNotification_create(IInspectable* val);
id RTProxiedNSMutableArray_WUNNotificationBinding_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class Nullable_WFDateTime, Nullable_WFTimeSpan, RTProxiedIterableNSArray_WFUri, RTProxiedNSArray_WUNAdaptiveNotificationText,
    RTProxiedNSArray_WUNScheduledTileNotification;
@class RTProxiedNSArray_WUNScheduledToastNotification, RTProxiedNSArray_WUNToastNotification,
    RTProxiedNSMutableArray_WUNNotificationBinding;
@class RTProxiedNSMutableDictionary_NSString_NSString;

#ifndef __ITypedEventHandler_Windows_UI_Notifications_ToastNotification_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Notifications_ToastNotification_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Notifications_ToastNotification_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Notifications::ToastNotification*, IInspectable*>> {
    void (^_delegate)(WUNToastNotification*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Notifications_ToastNotification_System_Object(void (^del)(WUNToastNotification*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Notifications_ToastNotification_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Notifications::IToastNotification* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUNToastNotification>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastDismissedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastDismissedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastDismissedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Notifications::ToastNotification*,
                                                                       ABI::Windows::UI::Notifications::ToastDismissedEventArgs*>> {
    void (^_delegate)(WUNToastNotification*, WUNToastDismissedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastDismissedEventArgs(
        void (^del)(WUNToastNotification*, WUNToastDismissedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastDismissedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Notifications::IToastNotification* arg0,
                                             ABI::Windows::UI::Notifications::IToastDismissedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUNToastNotification>(arg0), _createRtProxy<WUNToastDismissedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastFailedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastFailedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastFailedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Notifications::ToastNotification*,
                                                                       ABI::Windows::UI::Notifications::ToastFailedEventArgs*>> {
    void (^_delegate)(WUNToastNotification*, WUNToastFailedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastFailedEventArgs(
        void (^del)(WUNToastNotification*, WUNToastFailedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Notifications_ToastNotification_Windows_UI_Notifications_ToastFailedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Notifications::IToastNotification* arg0,
                                             ABI::Windows::UI::Notifications::IToastFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUNToastNotification>(arg0), _createRtProxy<WUNToastFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
