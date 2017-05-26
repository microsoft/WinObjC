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

// WindowsMediaCasting_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIPopups_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
ComPtr<ABI::Windows::Media::Casting::ICastingDeviceStatics> WMCICastingDeviceStatics_inst();

id RTProxiedNSMutableArray_WMCCastingSource_create(IInspectable* val);

@class RTProxiedNSMutableArray_WMCCastingSource;

#ifndef __ITypedEventHandler_Windows_Media_Casting_CastingConnection_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Casting_CastingConnection_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Casting_CastingConnection_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Casting::CastingConnection*, IInspectable*>> {
    void (^_delegate)(WMCCastingConnection*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Casting_CastingConnection_System_Object(void (^del)(WMCCastingConnection*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Casting_CastingConnection_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Casting::ICastingConnection* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCCastingConnection>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Casting_CastingConnection_Windows_Media_Casting_CastingConnectionErrorOccurredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Casting_CastingConnection_Windows_Media_Casting_CastingConnectionErrorOccurredEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Casting_CastingConnection_Windows_Media_Casting_CastingConnectionErrorOccurredEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Casting::CastingConnection*,
                                                       ABI::Windows::Media::Casting::CastingConnectionErrorOccurredEventArgs*>> {
    void (^_delegate)(WMCCastingConnection*, WMCCastingConnectionErrorOccurredEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Casting_CastingConnection_Windows_Media_Casting_CastingConnectionErrorOccurredEventArgs(
        void (^del)(WMCCastingConnection*, WMCCastingConnectionErrorOccurredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Casting_CastingConnection_Windows_Media_Casting_CastingConnectionErrorOccurredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Casting::ICastingConnection* arg0,
                                             ABI::Windows::Media::Casting::ICastingConnectionErrorOccurredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCCastingConnection>(arg0), _createRtProxy<WMCCastingConnectionErrorOccurredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Casting::CastingDevicePicker*, IInspectable*>> {
    void (^_delegate)(WMCCastingDevicePicker*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_System_Object(void (^del)(WMCCastingDevicePicker*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Casting::ICastingDevicePicker* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCCastingDevicePicker>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_Windows_Media_Casting_CastingDeviceSelectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_Windows_Media_Casting_CastingDeviceSelectedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_Windows_Media_Casting_CastingDeviceSelectedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Casting::CastingDevicePicker*,
                                                                       ABI::Windows::Media::Casting::CastingDeviceSelectedEventArgs*>> {
    void (^_delegate)(WMCCastingDevicePicker*, WMCCastingDeviceSelectedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_Windows_Media_Casting_CastingDeviceSelectedEventArgs(
        void (^del)(WMCCastingDevicePicker*, WMCCastingDeviceSelectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Casting_CastingDevicePicker_Windows_Media_Casting_CastingDeviceSelectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Casting::ICastingDevicePicker* arg0,
                                             ABI::Windows::Media::Casting::ICastingDeviceSelectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCCastingDevicePicker>(arg0), _createRtProxy<WMCCastingDeviceSelectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
