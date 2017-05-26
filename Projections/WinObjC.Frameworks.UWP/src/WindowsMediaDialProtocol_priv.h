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

// WindowsMediaDialProtocol_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsUIPopups_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Media::DialProtocol::IDialDeviceStatics> WMDIDialDeviceStatics_inst();

id RTProxiedNSMutableArray_NSString_create(IInspectable* val);

@class RTProxiedNSMutableArray_NSString;

#ifndef __ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::DialProtocol::DialDevicePicker*, IInspectable*>> {
    void (^_delegate)(WMDDialDevicePicker*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_System_Object(void (^del)(WMDDialDevicePicker*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::DialProtocol::IDialDevicePicker* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMDDialDevicePicker>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDeviceSelectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDeviceSelectedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDeviceSelectedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::DialProtocol::DialDevicePicker*,
                                                                       ABI::Windows::Media::DialProtocol::DialDeviceSelectedEventArgs*>> {
    void (^_delegate)(WMDDialDevicePicker*, WMDDialDeviceSelectedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDeviceSelectedEventArgs(
        void (^del)(WMDDialDevicePicker*, WMDDialDeviceSelectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDeviceSelectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::DialProtocol::IDialDevicePicker* arg0,
                                             ABI::Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMDDialDevicePicker>(arg0), _createRtProxy<WMDDialDeviceSelectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDisconnectButtonClickedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDisconnectButtonClickedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDisconnectButtonClickedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::DialProtocol::DialDevicePicker*,
                                                       ABI::Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs*>> {
    void (^_delegate)(WMDDialDevicePicker*, WMDDialDisconnectButtonClickedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDisconnectButtonClickedEventArgs(
        void (^del)(WMDDialDevicePicker*, WMDDialDisconnectButtonClickedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_DialProtocol_DialDevicePicker_Windows_Media_DialProtocol_DialDisconnectButtonClickedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::DialProtocol::IDialDevicePicker* arg0,
                                             ABI::Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMDDialDevicePicker>(arg0), _createRtProxy<WMDDialDisconnectButtonClickedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
