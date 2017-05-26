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

// WindowsMediaDevices_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsMediaCapture_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsMediaDevicesCore_priv.h"
ComPtr<ABI::Windows::Media::Devices::IMediaDeviceStatics> WMDIMediaDeviceStatics_inst();
ComPtr<ABI::Windows::Media::Devices::ICallControlStatics> WMDICallControlStatics_inst();

id RTProxiedIterableNSArray_WMDRegionOfInterest_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WMMIMediaEncodingProperties_create(IInspectable* val);
id RTProxiedNSArray_WMDAdvancedPhotoMode_create(IInspectable* val);
id RTProxiedNSArray_WMDAutoFocusRange_create(IInspectable* val);
id RTProxiedNSArray_WMDCaptureSceneMode_create(IInspectable* val);
id RTProxiedNSArray_WMDFocusMode_create(IInspectable* val);
id RTProxiedNSArray_WMDFocusPreset_create(IInspectable* val);
id RTProxiedNSArray_WMDHdrVideoMode_create(IInspectable* val);
id RTProxiedNSArray_WMDIsoSpeedPreset_create(IInspectable* val);
id RTProxiedNSArray_WMDManualFocusDistance_create(IInspectable* val);
id RTProxiedNSArray_WMDOpticalImageStabilizationMode_create(IInspectable* val);
id RTProxiedNSArray_WMDZoomTransitionMode_create(IInspectable* val);

@class Nullable_UInt32, Nullable_WMDManualFocusDistance, RTProxiedIterableNSArray_WMDRegionOfInterest,
    RTProxiedNSArray_RTObject_WMMIMediaEncodingProperties;
@class RTProxiedNSArray_WMDAdvancedPhotoMode, RTProxiedNSArray_WMDAutoFocusRange, RTProxiedNSArray_WMDCaptureSceneMode,
    RTProxiedNSArray_WMDFocusMode;
@class RTProxiedNSArray_WMDFocusPreset, RTProxiedNSArray_WMDHdrVideoMode, RTProxiedNSArray_WMDIsoSpeedPreset,
    RTProxiedNSArray_WMDManualFocusDistance;
@class RTProxiedNSArray_WMDOpticalImageStabilizationMode, RTProxiedNSArray_WMDZoomTransitionMode;

#ifndef __ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioCaptureDeviceChangedEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioCaptureDeviceChangedEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioCaptureDeviceChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::
                              ITypedEventHandler<IInspectable*, ABI::Windows::Media::Devices::DefaultAudioCaptureDeviceChangedEventArgs*>> {
    void (^_delegate)(RTObject*, WMDDefaultAudioCaptureDeviceChangedEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioCaptureDeviceChangedEventArgs(
        void (^del)(RTObject*, WMDDefaultAudioCaptureDeviceChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioCaptureDeviceChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WMDDefaultAudioCaptureDeviceChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioRenderDeviceChangedEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioRenderDeviceChangedEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioRenderDeviceChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::
                              ITypedEventHandler<IInspectable*, ABI::Windows::Media::Devices::DefaultAudioRenderDeviceChangedEventArgs*>> {
    void (^_delegate)(RTObject*, WMDDefaultAudioRenderDeviceChangedEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioRenderDeviceChangedEventArgs(
        void (^del)(RTObject*, WMDDefaultAudioRenderDeviceChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioRenderDeviceChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WMDDefaultAudioRenderDeviceChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WMDCallControlEventHandler_shim__DEFINED
#define __WMDCallControlEventHandler_shim__DEFINED
class WMDCallControlEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Media::Devices::ICallControlEventHandler> {
    void (^_delegate)(WMDCallControl*);

public:
    WMDCallControlEventHandler_shim(void (^del)(WMDCallControl*)) : _delegate([del copy]) {
    }
    ~WMDCallControlEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Devices::ICallControl* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMDCallControl>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WMDDialRequestedEventHandler_shim__DEFINED
#define __WMDDialRequestedEventHandler_shim__DEFINED
class WMDDialRequestedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Media::Devices::IDialRequestedEventHandler> {
    void (^_delegate)(WMDCallControl*, WMDDialRequestedEventArgs*);

public:
    WMDDialRequestedEventHandler_shim(void (^del)(WMDCallControl*, WMDDialRequestedEventArgs*)) : _delegate([del copy]) {
    }
    ~WMDDialRequestedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Devices::ICallControl* arg0,
                                             ABI::Windows::Media::Devices::IDialRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMDCallControl>(arg0), _createRtProxy<WMDDialRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WMDKeypadPressedEventHandler_shim__DEFINED
#define __WMDKeypadPressedEventHandler_shim__DEFINED
class WMDKeypadPressedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Media::Devices::IKeypadPressedEventHandler> {
    void (^_delegate)(WMDCallControl*, WMDKeypadPressedEventArgs*);

public:
    WMDKeypadPressedEventHandler_shim(void (^del)(WMDCallControl*, WMDKeypadPressedEventArgs*)) : _delegate([del copy]) {
    }
    ~WMDKeypadPressedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Devices::ICallControl* arg0,
                                             ABI::Windows::Media::Devices::IKeypadPressedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMDCallControl>(arg0), _createRtProxy<WMDKeypadPressedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WMDRedialRequestedEventHandler_shim__DEFINED
#define __WMDRedialRequestedEventHandler_shim__DEFINED
class WMDRedialRequestedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Media::Devices::IRedialRequestedEventHandler> {
    void (^_delegate)(WMDCallControl*, WMDRedialRequestedEventArgs*);

public:
    WMDRedialRequestedEventHandler_shim(void (^del)(WMDCallControl*, WMDRedialRequestedEventArgs*)) : _delegate([del copy]) {
    }
    ~WMDRedialRequestedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Devices::ICallControl* arg0,
                                             ABI::Windows::Media::Devices::IRedialRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMDCallControl>(arg0), _createRtProxy<WMDRedialRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
