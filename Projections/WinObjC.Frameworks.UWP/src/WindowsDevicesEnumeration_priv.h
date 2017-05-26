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

// WindowsDevicesEnumeration_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUI_priv.h"
#include "WindowsUIPopups_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelBackground_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationStatics2> WDEIDeviceInformationStatics2_inst();
ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationStatics> WDEIDeviceInformationStatics_inst();
ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformationPairingStatics> WDEIDeviceInformationPairingStatics_inst();
ComPtr<ABI::Windows::Devices::Enumeration::IDeviceAccessInformationStatics> WDEIDeviceAccessInformationStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_WDEDeviceWatcherEventKind_create(IInspectable* val);
id RTProxiedNSArray_WDEDeviceWatcherEvent_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WDEDeviceClass_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_WDEDeviceWatcherEventKind, RTProxiedNSArray_WDEDeviceWatcherEvent;
@class RTProxiedNSDictionary_NSString_RTObject, RTProxiedNSMutableArray_NSString, RTProxiedNSMutableArray_WDEDeviceClass;

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_DeviceAccessInformation_Windows_Devices_Enumeration_DeviceAccessChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_DeviceAccessInformation_Windows_Devices_Enumeration_DeviceAccessChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_DeviceAccessInformation_Windows_Devices_Enumeration_DeviceAccessChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::DeviceAccessInformation*,
                                                                       ABI::Windows::Devices::Enumeration::DeviceAccessChangedEventArgs*>> {
    void (^_delegate)(WDEDeviceAccessInformation*, WDEDeviceAccessChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_DeviceAccessInformation_Windows_Devices_Enumeration_DeviceAccessChangedEventArgs(
        void (^del)(WDEDeviceAccessInformation*, WDEDeviceAccessChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_DeviceAccessInformation_Windows_Devices_Enumeration_DeviceAccessChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::IDeviceAccessInformation* arg0,
                                             ABI::Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEDeviceAccessInformation>(arg0), _createRtProxy<WDEDeviceAccessChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_DeviceInformationCustomPairing_Windows_Devices_Enumeration_DevicePairingRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_DeviceInformationCustomPairing_Windows_Devices_Enumeration_DevicePairingRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Enumeration_DeviceInformationCustomPairing_Windows_Devices_Enumeration_DevicePairingRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::DeviceInformationCustomPairing*,
                                                       ABI::Windows::Devices::Enumeration::DevicePairingRequestedEventArgs*>> {
    void (^_delegate)(WDEDeviceInformationCustomPairing*, WDEDevicePairingRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_DeviceInformationCustomPairing_Windows_Devices_Enumeration_DevicePairingRequestedEventArgs(
        void (^del)(WDEDeviceInformationCustomPairing*, WDEDevicePairingRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_DeviceInformationCustomPairing_Windows_Devices_Enumeration_DevicePairingRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::IDeviceInformationCustomPairing* arg0,
                                             ABI::Windows::Devices::Enumeration::IDevicePairingRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEDeviceInformationCustomPairing>(arg0), _createRtProxy<WDEDevicePairingRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::DevicePicker*, IInspectable*>> {
    void (^_delegate)(WDEDevicePicker*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_System_Object(void (^del)(WDEDevicePicker*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::IDevicePicker* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEDevicePicker>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceDisconnectButtonClickedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceDisconnectButtonClickedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceDisconnectButtonClickedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::DevicePicker*,
                                                       ABI::Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs*>> {
    void (^_delegate)(WDEDevicePicker*, WDEDeviceDisconnectButtonClickedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceDisconnectButtonClickedEventArgs(
        void (^del)(WDEDevicePicker*, WDEDeviceDisconnectButtonClickedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceDisconnectButtonClickedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::IDevicePicker* arg0,
                                             ABI::Windows::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEDevicePicker>(arg0), _createRtProxy<WDEDeviceDisconnectButtonClickedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceSelectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceSelectedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceSelectedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::DevicePicker*,
                                                                       ABI::Windows::Devices::Enumeration::DeviceSelectedEventArgs*>> {
    void (^_delegate)(WDEDevicePicker*, WDEDeviceSelectedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceSelectedEventArgs(
        void (^del)(WDEDevicePicker*, WDEDeviceSelectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_DevicePicker_Windows_Devices_Enumeration_DeviceSelectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::IDevicePicker* arg0,
                                             ABI::Windows::Devices::Enumeration::IDeviceSelectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEDevicePicker>(arg0), _createRtProxy<WDEDeviceSelectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::DeviceWatcher*, IInspectable*>> {
    void (^_delegate)(WDEDeviceWatcher*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_System_Object(void (^del)(WDEDeviceWatcher*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::IDeviceWatcher* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEDeviceWatcher>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformation__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformation__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformation
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::DeviceWatcher*,
                                                                       ABI::Windows::Devices::Enumeration::DeviceInformation*>> {
    void (^_delegate)(WDEDeviceWatcher*, WDEDeviceInformation*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformation(
        void (^del)(WDEDeviceWatcher*, WDEDeviceInformation*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformation() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::IDeviceWatcher* arg0,
                                             ABI::Windows::Devices::Enumeration::IDeviceInformation* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEDeviceWatcher>(arg0), _createRtProxy<WDEDeviceInformation>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformationUpdate__DEFINED
#define __ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformationUpdate__DEFINED
class ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformationUpdate
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Enumeration::DeviceWatcher*,
                                                                       ABI::Windows::Devices::Enumeration::DeviceInformationUpdate*>> {
    void (^_delegate)(WDEDeviceWatcher*, WDEDeviceInformationUpdate*);

public:
    ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformationUpdate(
        void (^del)(WDEDeviceWatcher*, WDEDeviceInformationUpdate*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Enumeration_DeviceWatcher_Windows_Devices_Enumeration_DeviceInformationUpdate() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Enumeration::IDeviceWatcher* arg0,
                                             ABI::Windows::Devices::Enumeration::IDeviceInformationUpdate* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDEDeviceWatcher>(arg0), _createRtProxy<WDEDeviceInformationUpdate>(arg1));
            return 0;
        };
    }
};
#endif
