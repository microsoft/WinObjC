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

// WindowsSystem_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsApplicationModel_priv.h"
#include "WindowsUIPopups_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsStorageSearch_priv.h"
#include "WindowsUIViewManagement_priv.h"
#include "WindowsSystemRemoteSystems_priv.h"
ComPtr<ABI::Windows::System::IMemoryManagerStatics2> WSIMemoryManagerStatics2_inst();
ComPtr<ABI::Windows::System::IMemoryManagerStatics3> WSIMemoryManagerStatics3_inst();
ComPtr<ABI::Windows::System::IMemoryManagerStatics> WSIMemoryManagerStatics_inst();
ComPtr<ABI::Windows::System::IUserStatics> WSIUserStatics_inst();
ComPtr<ABI::Windows::System::IKnownUserPropertiesStatics> WSIKnownUserPropertiesStatics_inst();
ComPtr<ABI::Windows::System::IUserPickerStatics> WSIUserPickerStatics_inst();
ComPtr<ABI::Windows::System::IUserDeviceAssociationStatics> WSIUserDeviceAssociationStatics_inst();
ComPtr<ABI::Windows::System::ILauncherStatics> WSILauncherStatics_inst();
ComPtr<ABI::Windows::System::ILauncherStatics4> WSILauncherStatics4_inst();
ComPtr<ABI::Windows::System::ILauncherStatics3> WSILauncherStatics3_inst();
ComPtr<ABI::Windows::System::ILauncherStatics2> WSILauncherStatics2_inst();
ComPtr<ABI::Windows::System::IRemoteLauncherStatics> WSIRemoteLauncherStatics_inst();
ComPtr<ABI::Windows::System::IProcessLauncherStatics> WSIProcessLauncherStatics_inst();
ComPtr<ABI::Windows::System::IShutdownManagerStatics> WSIShutdownManagerStatics_inst();
ComPtr<ABI::Windows::System::ITimeZoneSettingsStatics> WSITimeZoneSettingsStatics_inst();

id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WAAppInfo_create(IInspectable* val);
id RTProxiedNSArray_WSUser_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_RTObject_WSIStorageItem_create(IInspectable* val);

@class Nullable_WFPoint, Nullable_WFRect, RTProxiedNSArray_NSString, RTProxiedNSArray_WAAppInfo, RTProxiedNSArray_WSUser,
    RTProxiedNSMutableArray_NSString;
@class RTProxiedNSMutableArray_RTObject_WSIStorageItem;

#ifndef __EventHandler_System_Object__DEFINED
#define __EventHandler_System_Object__DEFINED
class EventHandler_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IEventHandler<IInspectable*>> {
    void (^_delegate)(RTObject*, RTObject*);

public:
    EventHandler_System_Object(void (^del)(RTObject*, RTObject*)) : _delegate([del copy]) {
    }
    ~EventHandler_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_System_AppMemoryUsageLimitChangingEventArgs__DEFINED
#define __EventHandler_Windows_System_AppMemoryUsageLimitChangingEventArgs__DEFINED
class EventHandler_Windows_System_AppMemoryUsageLimitChangingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::System::AppMemoryUsageLimitChangingEventArgs*>> {
    void (^_delegate)(RTObject*, WSAppMemoryUsageLimitChangingEventArgs*);

public:
    EventHandler_Windows_System_AppMemoryUsageLimitChangingEventArgs(void (^del)(RTObject*, WSAppMemoryUsageLimitChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_System_AppMemoryUsageLimitChangingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::System::IAppMemoryUsageLimitChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WSAppMemoryUsageLimitChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_System_UserDeviceAssociationChangedEventArgs__DEFINED
#define __EventHandler_Windows_System_UserDeviceAssociationChangedEventArgs__DEFINED
class EventHandler_Windows_System_UserDeviceAssociationChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::System::UserDeviceAssociationChangedEventArgs*>> {
    void (^_delegate)(RTObject*, WSUserDeviceAssociationChangedEventArgs*);

public:
    EventHandler_Windows_System_UserDeviceAssociationChangedEventArgs(void (^del)(RTObject*, WSUserDeviceAssociationChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_System_UserDeviceAssociationChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::System::IUserDeviceAssociationChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WSUserDeviceAssociationChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_System_UserWatcher_System_Object__DEFINED
#define __ITypedEventHandler_Windows_System_UserWatcher_System_Object__DEFINED
class ITypedEventHandler_Windows_System_UserWatcher_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::System::UserWatcher*, IInspectable*>> {
    void (^_delegate)(WSUserWatcher*, RTObject*);

public:
    ITypedEventHandler_Windows_System_UserWatcher_System_Object(void (^del)(WSUserWatcher*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_System_UserWatcher_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::System::IUserWatcher* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSUserWatcher>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserAuthenticationStatusChangingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserAuthenticationStatusChangingEventArgs__DEFINED
class ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserAuthenticationStatusChangingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::System::UserWatcher*,
                                                                       ABI::Windows::System::UserAuthenticationStatusChangingEventArgs*>> {
    void (^_delegate)(WSUserWatcher*, WSUserAuthenticationStatusChangingEventArgs*);

public:
    ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserAuthenticationStatusChangingEventArgs(
        void (^del)(WSUserWatcher*, WSUserAuthenticationStatusChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserAuthenticationStatusChangingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::System::IUserWatcher* arg0,
                                             ABI::Windows::System::IUserAuthenticationStatusChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSUserWatcher>(arg0), _createRtProxy<WSUserAuthenticationStatusChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::System::UserWatcher*, ABI::Windows::System::UserChangedEventArgs*>> {
    void (^_delegate)(WSUserWatcher*, WSUserChangedEventArgs*);

public:
    ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserChangedEventArgs(void (^del)(WSUserWatcher*, WSUserChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::System::IUserWatcher* arg0,
                                             ABI::Windows::System::IUserChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSUserWatcher>(arg0), _createRtProxy<WSUserChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
