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

// WindowsMedia_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsGraphicsImaging_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsDirectXDirect3D11_priv.h"
static ComPtr<ABI::Windows::Media::IVideoFrameFactory> WMIVideoFrameFactory_inst();
static ComPtr<ABI::Windows::Media::IAudioFrameFactory> WMIAudioFrameFactory_inst();
ComPtr<ABI::Windows::Media::IMediaMarkerTypesStatics> WMIMediaMarkerTypesStatics_inst();
ComPtr<ABI::Windows::Media::ISystemMediaTransportControlsStatics> WMISystemMediaTransportControlsStatics_inst();
ComPtr<ABI::Windows::Media::IVideoEffectsStatics> WMIVideoEffectsStatics_inst();
ComPtr<ABI::Windows::Media::IMediaControl> WMIMediaControl_inst();

id RTProxiedNSArray_RTObject_WMIMediaMarker_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);

@class Nullable_WFTimeSpan, RTProxiedNSArray_RTObject_WMIMediaMarker, RTProxiedNSMutableArray_NSString;

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

#ifndef __ITypedEventHandler_Windows_Media_MediaTimelineController_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_MediaTimelineController_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_MediaTimelineController_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::MediaTimelineController*, IInspectable*>> {
    void (^_delegate)(WMMediaTimelineController*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_MediaTimelineController_System_Object(void (^del)(WMMediaTimelineController*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_MediaTimelineController_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::IMediaTimelineController* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMMediaTimelineController>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_AutoRepeatModeChangeRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_AutoRepeatModeChangeRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_AutoRepeatModeChangeRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::SystemMediaTransportControls*,
                                                                       ABI::Windows::Media::AutoRepeatModeChangeRequestedEventArgs*>> {
    void (^_delegate)(WMSystemMediaTransportControls*, WMAutoRepeatModeChangeRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_AutoRepeatModeChangeRequestedEventArgs(
        void (^del)(WMSystemMediaTransportControls*, WMAutoRepeatModeChangeRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_AutoRepeatModeChangeRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::ISystemMediaTransportControls* arg0,
                                             ABI::Windows::Media::IAutoRepeatModeChangeRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSystemMediaTransportControls>(arg0), _createRtProxy<WMAutoRepeatModeChangeRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackPositionChangeRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackPositionChangeRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackPositionChangeRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::SystemMediaTransportControls*,
                                                                       ABI::Windows::Media::PlaybackPositionChangeRequestedEventArgs*>> {
    void (^_delegate)(WMSystemMediaTransportControls*, WMPlaybackPositionChangeRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackPositionChangeRequestedEventArgs(
        void (^del)(WMSystemMediaTransportControls*, WMPlaybackPositionChangeRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackPositionChangeRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::ISystemMediaTransportControls* arg0,
                                             ABI::Windows::Media::IPlaybackPositionChangeRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSystemMediaTransportControls>(arg0),
                      _createRtProxy<WMPlaybackPositionChangeRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackRateChangeRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackRateChangeRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackRateChangeRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::SystemMediaTransportControls*,
                                                                       ABI::Windows::Media::PlaybackRateChangeRequestedEventArgs*>> {
    void (^_delegate)(WMSystemMediaTransportControls*, WMPlaybackRateChangeRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackRateChangeRequestedEventArgs(
        void (^del)(WMSystemMediaTransportControls*, WMPlaybackRateChangeRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackRateChangeRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::ISystemMediaTransportControls* arg0,
                                             ABI::Windows::Media::IPlaybackRateChangeRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSystemMediaTransportControls>(arg0), _createRtProxy<WMPlaybackRateChangeRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_ShuffleEnabledChangeRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_ShuffleEnabledChangeRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_ShuffleEnabledChangeRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::SystemMediaTransportControls*,
                                                                       ABI::Windows::Media::ShuffleEnabledChangeRequestedEventArgs*>> {
    void (^_delegate)(WMSystemMediaTransportControls*, WMShuffleEnabledChangeRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_ShuffleEnabledChangeRequestedEventArgs(
        void (^del)(WMSystemMediaTransportControls*, WMShuffleEnabledChangeRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_ShuffleEnabledChangeRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::ISystemMediaTransportControls* arg0,
                                             ABI::Windows::Media::IShuffleEnabledChangeRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSystemMediaTransportControls>(arg0), _createRtProxy<WMShuffleEnabledChangeRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsButtonPressedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsButtonPressedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsButtonPressedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::SystemMediaTransportControls*,
                                                       ABI::Windows::Media::SystemMediaTransportControlsButtonPressedEventArgs*>> {
    void (^_delegate)(WMSystemMediaTransportControls*, WMSystemMediaTransportControlsButtonPressedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsButtonPressedEventArgs(
        void (^del)(WMSystemMediaTransportControls*, WMSystemMediaTransportControlsButtonPressedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsButtonPressedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::ISystemMediaTransportControls* arg0,
                                             ABI::Windows::Media::ISystemMediaTransportControlsButtonPressedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSystemMediaTransportControls>(arg0),
                      _createRtProxy<WMSystemMediaTransportControlsButtonPressedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsPropertyChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsPropertyChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsPropertyChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::SystemMediaTransportControls*,
                                                       ABI::Windows::Media::SystemMediaTransportControlsPropertyChangedEventArgs*>> {
    void (^_delegate)(WMSystemMediaTransportControls*, WMSystemMediaTransportControlsPropertyChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsPropertyChangedEventArgs(
        void (^del)(WMSystemMediaTransportControls*, WMSystemMediaTransportControlsPropertyChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsPropertyChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::ISystemMediaTransportControls* arg0,
                                             ABI::Windows::Media::ISystemMediaTransportControlsPropertyChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSystemMediaTransportControls>(arg0),
                      _createRtProxy<WMSystemMediaTransportControlsPropertyChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
