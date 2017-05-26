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

// WindowsMediaEffects_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsMediaEditing_priv.h"
#include "WindowsMediaCapture_priv.h"
#include "WindowsMediaTranscoding_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsMediaRender_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsGraphicsDirectXDirect3D11_priv.h"
#include "WindowsMedia_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsUI_priv.h"
static ComPtr<ABI::Windows::Media::Effects::IVideoCompositorDefinitionFactory> WMEIVideoCompositorDefinitionFactory_inst();
ComPtr<ABI::Windows::Media::Effects::IAudioEffectsManagerStatics> WMEIAudioEffectsManagerStatics_inst();
static ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinitionFactory> WMEIVideoEffectDefinitionFactory_inst();
static ComPtr<ABI::Windows::Media::Effects::IAudioEffectDefinitionFactory> WMEIAudioEffectDefinitionFactory_inst();

id RTProxiedNSArray_RTObject_WGDDIDirect3DSurface_create(IInspectable* val);
id RTProxiedNSArray_WMEAudioEffect_create(IInspectable* val);
id RTProxiedNSArray_WMMAudioEncodingProperties_create(IInspectable* val);
id RTProxiedNSArray_WMMVideoEncodingProperties_create(IInspectable* val);

@class RTProxiedNSArray_RTObject_WGDDIDirect3DSurface, RTProxiedNSArray_WMEAudioEffect, RTProxiedNSArray_WMMAudioEncodingProperties;
@class RTProxiedNSArray_WMMVideoEncodingProperties;

#ifndef __ITypedEventHandler_Windows_Media_Effects_AudioCaptureEffectsManager_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Effects_AudioCaptureEffectsManager_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Effects_AudioCaptureEffectsManager_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Effects::AudioCaptureEffectsManager*, IInspectable*>> {
    void (^_delegate)(WMEAudioCaptureEffectsManager*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Effects_AudioCaptureEffectsManager_System_Object(void (^del)(WMEAudioCaptureEffectsManager*,
                                                                                                  RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Effects_AudioCaptureEffectsManager_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Effects::IAudioCaptureEffectsManager* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMEAudioCaptureEffectsManager>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Effects_AudioRenderEffectsManager_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Effects_AudioRenderEffectsManager_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Effects_AudioRenderEffectsManager_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Effects::AudioRenderEffectsManager*, IInspectable*>> {
    void (^_delegate)(WMEAudioRenderEffectsManager*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Effects_AudioRenderEffectsManager_System_Object(void (^del)(WMEAudioRenderEffectsManager*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Effects_AudioRenderEffectsManager_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Effects::IAudioRenderEffectsManager* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMEAudioRenderEffectsManager>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
