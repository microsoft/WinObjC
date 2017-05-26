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

// WindowsMediaAudio_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsMedia_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsMediaRender_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsMediaEffects_priv.h"
#include "WindowsMediaCapture_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsMediaTranscoding_priv.h"
#include "WindowsFoundationNumerics_priv.h"
#include "WindowsFoundationCollections_priv.h"
ComPtr<ABI::Windows::Media::Audio::IAudioGraphStatics> WMAIAudioGraphStatics_inst();
static ComPtr<ABI::Windows::Media::Audio::IAudioGraphSettingsFactory> WMAIAudioGraphSettingsFactory_inst();
static ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterFactory> WMAIAudioNodeEmitterFactory_inst();
static ComPtr<ABI::Windows::Media::Audio::IEqualizerEffectDefinitionFactory> WMAIEqualizerEffectDefinitionFactory_inst();
static ComPtr<ABI::Windows::Media::Audio::IReverbEffectDefinitionFactory> WMAIReverbEffectDefinitionFactory_inst();
static ComPtr<ABI::Windows::Media::Audio::IEchoEffectDefinitionFactory> WMAIEchoEffectDefinitionFactory_inst();
static ComPtr<ABI::Windows::Media::Audio::ILimiterEffectDefinitionFactory> WMAILimiterEffectDefinitionFactory_inst();
ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterShapeStatics> WMAIAudioNodeEmitterShapeStatics_inst();
ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModelStatics> WMAIAudioNodeEmitterDecayModelStatics_inst();

id RTProxiedNSArray_WMAAudioGraphConnection_create(IInspectable* val);
id RTProxiedNSArray_WMAEqualizerBand_create(IInspectable* val);
id RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(IInspectable* val);

@class Nullable_Int32, Nullable_WFTimeSpan, RTProxiedNSArray_WMAAudioGraphConnection, RTProxiedNSArray_WMAEqualizerBand,
    RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition;

#ifndef __ITypedEventHandler_Windows_Media_Audio_AudioFileInputNode_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Audio_AudioFileInputNode_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Audio_AudioFileInputNode_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Audio::AudioFileInputNode*, IInspectable*>> {
    void (^_delegate)(WMAAudioFileInputNode*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Audio_AudioFileInputNode_System_Object(void (^del)(WMAAudioFileInputNode*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Audio_AudioFileInputNode_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Audio::IAudioFileInputNode* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMAAudioFileInputNode>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_AudioFrameCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_AudioFrameCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_AudioFrameCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Audio::AudioFrameInputNode*,
                                                                       ABI::Windows::Media::Audio::AudioFrameCompletedEventArgs*>> {
    void (^_delegate)(WMAAudioFrameInputNode*, WMAAudioFrameCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_AudioFrameCompletedEventArgs(
        void (^del)(WMAAudioFrameInputNode*, WMAAudioFrameCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_AudioFrameCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Audio::IAudioFrameInputNode* arg0,
                                             ABI::Windows::Media::Audio::IAudioFrameCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMAAudioFrameInputNode>(arg0), _createRtProxy<WMAAudioFrameCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_FrameInputNodeQuantumStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_FrameInputNodeQuantumStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_FrameInputNodeQuantumStartedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Audio::AudioFrameInputNode*,
                                                       ABI::Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs*>> {
    void (^_delegate)(WMAAudioFrameInputNode*, WMAFrameInputNodeQuantumStartedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_FrameInputNodeQuantumStartedEventArgs(
        void (^del)(WMAAudioFrameInputNode*, WMAFrameInputNodeQuantumStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_FrameInputNodeQuantumStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Audio::IAudioFrameInputNode* arg0,
                                             ABI::Windows::Media::Audio::IFrameInputNodeQuantumStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMAAudioFrameInputNode>(arg0), _createRtProxy<WMAFrameInputNodeQuantumStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Audio_AudioGraph_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Audio_AudioGraph_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Audio_AudioGraph_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Audio::AudioGraph*, IInspectable*>> {
    void (^_delegate)(WMAAudioGraph*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Audio_AudioGraph_System_Object(void (^del)(WMAAudioGraph*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Audio_AudioGraph_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Audio::IAudioGraph* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMAAudioGraph>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Audio_AudioGraph_Windows_Media_Audio_AudioGraphUnrecoverableErrorOccurredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Audio_AudioGraph_Windows_Media_Audio_AudioGraphUnrecoverableErrorOccurredEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Audio_AudioGraph_Windows_Media_Audio_AudioGraphUnrecoverableErrorOccurredEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Audio::AudioGraph*,
                                                       ABI::Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs*>> {
    void (^_delegate)(WMAAudioGraph*, WMAAudioGraphUnrecoverableErrorOccurredEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Audio_AudioGraph_Windows_Media_Audio_AudioGraphUnrecoverableErrorOccurredEventArgs(
        void (^del)(WMAAudioGraph*, WMAAudioGraphUnrecoverableErrorOccurredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Audio_AudioGraph_Windows_Media_Audio_AudioGraphUnrecoverableErrorOccurredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Audio::IAudioGraph* arg0,
                                             ABI::Windows::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMAAudioGraph>(arg0), _createRtProxy<WMAAudioGraphUnrecoverableErrorOccurredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
