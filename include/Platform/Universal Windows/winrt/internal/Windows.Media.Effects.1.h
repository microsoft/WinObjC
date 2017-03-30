// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Effects.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Graphics.DirectX.Direct3D11.0.h"
#include "Windows.Media.0.h"
#include "Windows.Media.Capture.0.h"
#include "Windows.Media.Editing.0.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Media.Render.0.h"
#include "Windows.Media.Transcoding.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.UI.0.h"
#include "Windows.Graphics.DirectX.Direct3D11.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Media.MediaProperties.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Effects {

struct __declspec(uuid("8f85c271-038d-4393-8298-540110608eef")) __declspec(novtable) IAudioCaptureEffectsManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_AudioCaptureEffectsChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioCaptureEffectsManager, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AudioCaptureEffectsChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetAudioCaptureEffects(Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect> ** effects) = 0;
};

struct __declspec(uuid("34aafa51-9207-4055-be93-6e5734a86ae4")) __declspec(novtable) IAudioEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AudioEffectType(winrt::Windows::Media::Effects::AudioEffectType * value) = 0;
};

struct __declspec(uuid("e4d7f974-7d80-4f73-9089-e31c9db9c294")) __declspec(novtable) IAudioEffectDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ActivatableClassId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("8e1da646-e705-45ed-8a2b-fc4e4f405a97")) __declspec(novtable) IAudioEffectDefinitionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring activatableClassId, Windows::Media::Effects::IAudioEffectDefinition ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithProperties(hstring activatableClassId, Windows::Foundation::Collections::IPropertySet * props, Windows::Media::Effects::IAudioEffectDefinition ** value) = 0;
};

struct __declspec(uuid("66406c04-86fa-47cc-a315-f489d8c3fe10")) __declspec(novtable) IAudioEffectsManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateAudioRenderEffectsManager(hstring deviceId, winrt::Windows::Media::Render::AudioRenderCategory category, Windows::Media::Effects::IAudioRenderEffectsManager ** value) = 0;
    virtual HRESULT __stdcall abi_CreateAudioRenderEffectsManagerWithMode(hstring deviceId, winrt::Windows::Media::Render::AudioRenderCategory category, winrt::Windows::Media::AudioProcessing mode, Windows::Media::Effects::IAudioRenderEffectsManager ** value) = 0;
    virtual HRESULT __stdcall abi_CreateAudioCaptureEffectsManager(hstring deviceId, winrt::Windows::Media::Capture::MediaCategory category, Windows::Media::Effects::IAudioCaptureEffectsManager ** value) = 0;
    virtual HRESULT __stdcall abi_CreateAudioCaptureEffectsManagerWithMode(hstring deviceId, winrt::Windows::Media::Capture::MediaCategory category, winrt::Windows::Media::AudioProcessing mode, Windows::Media::Effects::IAudioCaptureEffectsManager ** value) = 0;
};

struct __declspec(uuid("4dc98966-8751-42b2-bfcb-39ca7864bd47")) __declspec(novtable) IAudioRenderEffectsManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_AudioRenderEffectsChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioRenderEffectsManager, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AudioRenderEffectsChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetAudioRenderEffects(Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect> ** effects) = 0;
};

struct __declspec(uuid("a844cd09-5ecc-44b3-bb4e-1db07287139c")) __declspec(novtable) IAudioRenderEffectsManager2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EffectsProviderThumbnail(Windows::Storage::Streams::IRandomAccessStreamWithContentType ** value) = 0;
    virtual HRESULT __stdcall get_EffectsProviderSettingsLabel(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ShowSettingsUI() = 0;
};

struct __declspec(uuid("8c062c53-6bc0-48b8-a99a-4b41550f1359")) __declspec(novtable) IBasicAudioEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UseInputFrameForOutput(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedEncodingProperties(Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::AudioEncodingProperties> ** value) = 0;
    virtual HRESULT __stdcall abi_SetEncodingProperties(Windows::Media::MediaProperties::IAudioEncodingProperties * encodingProperties) = 0;
    virtual HRESULT __stdcall abi_ProcessFrame(Windows::Media::Effects::IProcessAudioFrameContext * context) = 0;
    virtual HRESULT __stdcall abi_Close(winrt::Windows::Media::Effects::MediaEffectClosedReason reason) = 0;
    virtual HRESULT __stdcall abi_DiscardQueuedFrames() = 0;
};

struct __declspec(uuid("8262c7ef-b360-40be-949b-2ff42ff35693")) __declspec(novtable) IBasicVideoEffect : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsReadOnly(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedMemoryTypes(winrt::Windows::Media::Effects::MediaMemoryTypes * value) = 0;
    virtual HRESULT __stdcall get_TimeIndependent(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportedEncodingProperties(Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::VideoEncodingProperties> ** value) = 0;
    virtual HRESULT __stdcall abi_SetEncodingProperties(Windows::Media::MediaProperties::IVideoEncodingProperties * encodingProperties, Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice * device) = 0;
    virtual HRESULT __stdcall abi_ProcessFrame(Windows::Media::Effects::IProcessVideoFrameContext * context) = 0;
    virtual HRESULT __stdcall abi_Close(winrt::Windows::Media::Effects::MediaEffectClosedReason reason) = 0;
    virtual HRESULT __stdcall abi_DiscardQueuedFrames() = 0;
};

struct __declspec(uuid("6c30024b-f514-4278-a5f7-b9188049d110")) __declspec(novtable) ICompositeVideoFrameContext : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SurfacesToOverlay(Windows::Foundation::Collections::IVectorView<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> ** value) = 0;
    virtual HRESULT __stdcall get_BackgroundFrame(Windows::Media::IVideoFrame ** value) = 0;
    virtual HRESULT __stdcall get_OutputFrame(Windows::Media::IVideoFrame ** value) = 0;
    virtual HRESULT __stdcall abi_GetOverlayForSurface(Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface * surfaceToOverlay, Windows::Media::Editing::IMediaOverlay ** value) = 0;
};

struct __declspec(uuid("4cd92946-1222-4a27-a586-fb3e20273255")) __declspec(novtable) IProcessAudioFrameContext : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InputFrame(Windows::Media::IAudioFrame ** value) = 0;
    virtual HRESULT __stdcall get_OutputFrame(Windows::Media::IAudioFrame ** value) = 0;
};

struct __declspec(uuid("276f0e2b-6461-401e-ba78-0fdad6114eec")) __declspec(novtable) IProcessVideoFrameContext : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InputFrame(Windows::Media::IVideoFrame ** value) = 0;
    virtual HRESULT __stdcall get_OutputFrame(Windows::Media::IVideoFrame ** value) = 0;
};

struct __declspec(uuid("35053cd0-176c-4763-82c4-1b02dbe31737")) __declspec(novtable) ISlowMotionEffectDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TimeStretchRate(double * value) = 0;
    virtual HRESULT __stdcall put_TimeStretchRate(double value) = 0;
};

struct __declspec(uuid("8510b43e-420c-420f-96c7-7c98bba1fc55")) __declspec(novtable) IVideoCompositor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TimeIndependent(bool * value) = 0;
    virtual HRESULT __stdcall abi_SetEncodingProperties(Windows::Media::MediaProperties::IVideoEncodingProperties * backgroundProperties, Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice * device) = 0;
    virtual HRESULT __stdcall abi_CompositeFrame(Windows::Media::Effects::ICompositeVideoFrameContext * context) = 0;
    virtual HRESULT __stdcall abi_Close(winrt::Windows::Media::Effects::MediaEffectClosedReason reason) = 0;
    virtual HRESULT __stdcall abi_DiscardQueuedFrames() = 0;
};

struct __declspec(uuid("7946b8d0-2010-4ae3-9ab2-2cef42edd4d2")) __declspec(novtable) IVideoCompositorDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ActivatableClassId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("4366fd10-68b8-4d52-89b6-02a968cca899")) __declspec(novtable) IVideoCompositorDefinitionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring activatableClassId, Windows::Media::Effects::IVideoCompositorDefinition ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithProperties(hstring activatableClassId, Windows::Foundation::Collections::IPropertySet * props, Windows::Media::Effects::IVideoCompositorDefinition ** value) = 0;
};

struct __declspec(uuid("39f38cf0-8d0f-4f3e-84fc-2d46a5297943")) __declspec(novtable) IVideoEffectDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ActivatableClassId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("81439b4e-6e33-428f-9d21-b5aafef7617c")) __declspec(novtable) IVideoEffectDefinitionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring activatableClassId, Windows::Media::Effects::IVideoEffectDefinition ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithProperties(hstring activatableClassId, Windows::Foundation::Collections::IPropertySet * props, Windows::Media::Effects::IVideoEffectDefinition ** value) = 0;
};

struct __declspec(uuid("9664bb6a-1ea6-4aa6-8074-abe8851ecae2")) __declspec(novtable) IVideoTransformEffectDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PaddingColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_PaddingColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall get_OutputSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall put_OutputSize(Windows::Foundation::Size value) = 0;
    virtual HRESULT __stdcall get_CropRectangle(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_CropRectangle(Windows::Foundation::Rect value) = 0;
    virtual HRESULT __stdcall get_Rotation(winrt::Windows::Media::MediaProperties::MediaRotation * value) = 0;
    virtual HRESULT __stdcall put_Rotation(winrt::Windows::Media::MediaProperties::MediaRotation value) = 0;
    virtual HRESULT __stdcall get_Mirror(winrt::Windows::Media::MediaProperties::MediaMirroringOptions * value) = 0;
    virtual HRESULT __stdcall put_Mirror(winrt::Windows::Media::MediaProperties::MediaMirroringOptions value) = 0;
    virtual HRESULT __stdcall put_ProcessingAlgorithm(winrt::Windows::Media::Transcoding::MediaVideoProcessingAlgorithm value) = 0;
    virtual HRESULT __stdcall get_ProcessingAlgorithm(winrt::Windows::Media::Transcoding::MediaVideoProcessingAlgorithm * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Effects::AudioCaptureEffectsManager> { using default_interface = Windows::Media::Effects::IAudioCaptureEffectsManager; };
template <> struct traits<Windows::Media::Effects::AudioEffect> { using default_interface = Windows::Media::Effects::IAudioEffect; };
template <> struct traits<Windows::Media::Effects::AudioEffectDefinition> { using default_interface = Windows::Media::Effects::IAudioEffectDefinition; };
template <> struct traits<Windows::Media::Effects::AudioRenderEffectsManager> { using default_interface = Windows::Media::Effects::IAudioRenderEffectsManager; };
template <> struct traits<Windows::Media::Effects::CompositeVideoFrameContext> { using default_interface = Windows::Media::Effects::ICompositeVideoFrameContext; };
template <> struct traits<Windows::Media::Effects::ProcessAudioFrameContext> { using default_interface = Windows::Media::Effects::IProcessAudioFrameContext; };
template <> struct traits<Windows::Media::Effects::ProcessVideoFrameContext> { using default_interface = Windows::Media::Effects::IProcessVideoFrameContext; };
template <> struct traits<Windows::Media::Effects::SlowMotionEffectDefinition> { using default_interface = Windows::Media::Effects::ISlowMotionEffectDefinition; };
template <> struct traits<Windows::Media::Effects::VideoCompositorDefinition> { using default_interface = Windows::Media::Effects::IVideoCompositorDefinition; };
template <> struct traits<Windows::Media::Effects::VideoEffectDefinition> { using default_interface = Windows::Media::Effects::IVideoEffectDefinition; };
template <> struct traits<Windows::Media::Effects::VideoTransformEffectDefinition> { using default_interface = Windows::Media::Effects::IVideoEffectDefinition; };

}

namespace Windows::Media::Effects {

template <typename D>
struct WINRT_EBO impl_IAudioCaptureEffectsManager
{
    event_token AudioCaptureEffectsChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioCaptureEffectsManager, Windows::Foundation::IInspectable> & handler) const;
    using AudioCaptureEffectsChanged_revoker = event_revoker<IAudioCaptureEffectsManager>;
    AudioCaptureEffectsChanged_revoker AudioCaptureEffectsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioCaptureEffectsManager, Windows::Foundation::IInspectable> & handler) const;
    void AudioCaptureEffectsChanged(event_token token) const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect> GetAudioCaptureEffects() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioEffect
{
    Windows::Media::Effects::AudioEffectType AudioEffectType() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioEffectDefinition
{
    hstring ActivatableClassId() const;
    Windows::Foundation::Collections::IPropertySet Properties() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioEffectDefinitionFactory
{
    Windows::Media::Effects::AudioEffectDefinition Create(hstring_view activatableClassId) const;
    Windows::Media::Effects::AudioEffectDefinition CreateWithProperties(hstring_view activatableClassId, const Windows::Foundation::Collections::IPropertySet & props) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioEffectsManagerStatics
{
    Windows::Media::Effects::AudioRenderEffectsManager CreateAudioRenderEffectsManager(hstring_view deviceId, Windows::Media::Render::AudioRenderCategory category) const;
    Windows::Media::Effects::AudioRenderEffectsManager CreateAudioRenderEffectsManager(hstring_view deviceId, Windows::Media::Render::AudioRenderCategory category, Windows::Media::AudioProcessing mode) const;
    Windows::Media::Effects::AudioCaptureEffectsManager CreateAudioCaptureEffectsManager(hstring_view deviceId, Windows::Media::Capture::MediaCategory category) const;
    Windows::Media::Effects::AudioCaptureEffectsManager CreateAudioCaptureEffectsManager(hstring_view deviceId, Windows::Media::Capture::MediaCategory category, Windows::Media::AudioProcessing mode) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioRenderEffectsManager
{
    event_token AudioRenderEffectsChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioRenderEffectsManager, Windows::Foundation::IInspectable> & handler) const;
    using AudioRenderEffectsChanged_revoker = event_revoker<IAudioRenderEffectsManager>;
    AudioRenderEffectsChanged_revoker AudioRenderEffectsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioRenderEffectsManager, Windows::Foundation::IInspectable> & handler) const;
    void AudioRenderEffectsChanged(event_token token) const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect> GetAudioRenderEffects() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioRenderEffectsManager2
{
    [[deprecated("Not supported starting in windows 10")]] Windows::Storage::Streams::IRandomAccessStreamWithContentType EffectsProviderThumbnail() const;
    [[deprecated("Not supported starting in windows 10")]] hstring EffectsProviderSettingsLabel() const;
    [[deprecated("Not supported starting in windows 10")]] void ShowSettingsUI() const;
};

template <typename D>
struct WINRT_EBO impl_IBasicAudioEffect
{
    bool UseInputFrameForOutput() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::AudioEncodingProperties> SupportedEncodingProperties() const;
    void SetEncodingProperties(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const;
    void ProcessFrame(const Windows::Media::Effects::ProcessAudioFrameContext & context) const;
    void Close(Windows::Media::Effects::MediaEffectClosedReason reason) const;
    void DiscardQueuedFrames() const;
};

template <typename D>
struct WINRT_EBO impl_IBasicVideoEffect
{
    bool IsReadOnly() const;
    Windows::Media::Effects::MediaMemoryTypes SupportedMemoryTypes() const;
    bool TimeIndependent() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::VideoEncodingProperties> SupportedEncodingProperties() const;
    void SetEncodingProperties(const Windows::Media::MediaProperties::VideoEncodingProperties & encodingProperties, const Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice & device) const;
    void ProcessFrame(const Windows::Media::Effects::ProcessVideoFrameContext & context) const;
    void Close(Windows::Media::Effects::MediaEffectClosedReason reason) const;
    void DiscardQueuedFrames() const;
};

template <typename D>
struct WINRT_EBO impl_ICompositeVideoFrameContext
{
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> SurfacesToOverlay() const;
    Windows::Media::VideoFrame BackgroundFrame() const;
    Windows::Media::VideoFrame OutputFrame() const;
    Windows::Media::Editing::MediaOverlay GetOverlayForSurface(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surfaceToOverlay) const;
};

template <typename D>
struct WINRT_EBO impl_IProcessAudioFrameContext
{
    Windows::Media::AudioFrame InputFrame() const;
    Windows::Media::AudioFrame OutputFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IProcessVideoFrameContext
{
    Windows::Media::VideoFrame InputFrame() const;
    Windows::Media::VideoFrame OutputFrame() const;
};

template <typename D>
struct WINRT_EBO impl_ISlowMotionEffectDefinition
{
    double TimeStretchRate() const;
    void TimeStretchRate(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IVideoCompositor
{
    bool TimeIndependent() const;
    void SetEncodingProperties(const Windows::Media::MediaProperties::VideoEncodingProperties & backgroundProperties, const Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice & device) const;
    void CompositeFrame(const Windows::Media::Effects::CompositeVideoFrameContext & context) const;
    void Close(Windows::Media::Effects::MediaEffectClosedReason reason) const;
    void DiscardQueuedFrames() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoCompositorDefinition
{
    hstring ActivatableClassId() const;
    Windows::Foundation::Collections::IPropertySet Properties() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoCompositorDefinitionFactory
{
    Windows::Media::Effects::VideoCompositorDefinition Create(hstring_view activatableClassId) const;
    Windows::Media::Effects::VideoCompositorDefinition CreateWithProperties(hstring_view activatableClassId, const Windows::Foundation::Collections::IPropertySet & props) const;
};

template <typename D>
struct WINRT_EBO impl_IVideoEffectDefinition
{
    hstring ActivatableClassId() const;
    Windows::Foundation::Collections::IPropertySet Properties() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoEffectDefinitionFactory
{
    Windows::Media::Effects::VideoEffectDefinition Create(hstring_view activatableClassId) const;
    Windows::Media::Effects::VideoEffectDefinition CreateWithProperties(hstring_view activatableClassId, const Windows::Foundation::Collections::IPropertySet & props) const;
};

template <typename D>
struct WINRT_EBO impl_IVideoTransformEffectDefinition
{
    Windows::UI::Color PaddingColor() const;
    void PaddingColor(const Windows::UI::Color & value) const;
    Windows::Foundation::Size OutputSize() const;
    void OutputSize(const Windows::Foundation::Size & value) const;
    Windows::Foundation::Rect CropRectangle() const;
    void CropRectangle(const Windows::Foundation::Rect & value) const;
    Windows::Media::MediaProperties::MediaRotation Rotation() const;
    void Rotation(Windows::Media::MediaProperties::MediaRotation value) const;
    Windows::Media::MediaProperties::MediaMirroringOptions Mirror() const;
    void Mirror(Windows::Media::MediaProperties::MediaMirroringOptions value) const;
    void ProcessingAlgorithm(Windows::Media::Transcoding::MediaVideoProcessingAlgorithm value) const;
    Windows::Media::Transcoding::MediaVideoProcessingAlgorithm ProcessingAlgorithm() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Effects::IAudioCaptureEffectsManager>
{
    using abi = ABI::Windows::Media::Effects::IAudioCaptureEffectsManager;
    template <typename D> using consume = Windows::Media::Effects::impl_IAudioCaptureEffectsManager<D>;
};

template <> struct traits<Windows::Media::Effects::IAudioEffect>
{
    using abi = ABI::Windows::Media::Effects::IAudioEffect;
    template <typename D> using consume = Windows::Media::Effects::impl_IAudioEffect<D>;
};

template <> struct traits<Windows::Media::Effects::IAudioEffectDefinition>
{
    using abi = ABI::Windows::Media::Effects::IAudioEffectDefinition;
    template <typename D> using consume = Windows::Media::Effects::impl_IAudioEffectDefinition<D>;
};

template <> struct traits<Windows::Media::Effects::IAudioEffectDefinitionFactory>
{
    using abi = ABI::Windows::Media::Effects::IAudioEffectDefinitionFactory;
    template <typename D> using consume = Windows::Media::Effects::impl_IAudioEffectDefinitionFactory<D>;
};

template <> struct traits<Windows::Media::Effects::IAudioEffectsManagerStatics>
{
    using abi = ABI::Windows::Media::Effects::IAudioEffectsManagerStatics;
    template <typename D> using consume = Windows::Media::Effects::impl_IAudioEffectsManagerStatics<D>;
};

template <> struct traits<Windows::Media::Effects::IAudioRenderEffectsManager>
{
    using abi = ABI::Windows::Media::Effects::IAudioRenderEffectsManager;
    template <typename D> using consume = Windows::Media::Effects::impl_IAudioRenderEffectsManager<D>;
};

template <> struct traits<Windows::Media::Effects::IAudioRenderEffectsManager2>
{
    using abi = ABI::Windows::Media::Effects::IAudioRenderEffectsManager2;
    template <typename D> using consume = Windows::Media::Effects::impl_IAudioRenderEffectsManager2<D>;
};

template <> struct traits<Windows::Media::Effects::IBasicAudioEffect>
{
    using abi = ABI::Windows::Media::Effects::IBasicAudioEffect;
    template <typename D> using consume = Windows::Media::Effects::impl_IBasicAudioEffect<D>;
};

template <> struct traits<Windows::Media::Effects::IBasicVideoEffect>
{
    using abi = ABI::Windows::Media::Effects::IBasicVideoEffect;
    template <typename D> using consume = Windows::Media::Effects::impl_IBasicVideoEffect<D>;
};

template <> struct traits<Windows::Media::Effects::ICompositeVideoFrameContext>
{
    using abi = ABI::Windows::Media::Effects::ICompositeVideoFrameContext;
    template <typename D> using consume = Windows::Media::Effects::impl_ICompositeVideoFrameContext<D>;
};

template <> struct traits<Windows::Media::Effects::IProcessAudioFrameContext>
{
    using abi = ABI::Windows::Media::Effects::IProcessAudioFrameContext;
    template <typename D> using consume = Windows::Media::Effects::impl_IProcessAudioFrameContext<D>;
};

template <> struct traits<Windows::Media::Effects::IProcessVideoFrameContext>
{
    using abi = ABI::Windows::Media::Effects::IProcessVideoFrameContext;
    template <typename D> using consume = Windows::Media::Effects::impl_IProcessVideoFrameContext<D>;
};

template <> struct traits<Windows::Media::Effects::ISlowMotionEffectDefinition>
{
    using abi = ABI::Windows::Media::Effects::ISlowMotionEffectDefinition;
    template <typename D> using consume = Windows::Media::Effects::impl_ISlowMotionEffectDefinition<D>;
};

template <> struct traits<Windows::Media::Effects::IVideoCompositor>
{
    using abi = ABI::Windows::Media::Effects::IVideoCompositor;
    template <typename D> using consume = Windows::Media::Effects::impl_IVideoCompositor<D>;
};

template <> struct traits<Windows::Media::Effects::IVideoCompositorDefinition>
{
    using abi = ABI::Windows::Media::Effects::IVideoCompositorDefinition;
    template <typename D> using consume = Windows::Media::Effects::impl_IVideoCompositorDefinition<D>;
};

template <> struct traits<Windows::Media::Effects::IVideoCompositorDefinitionFactory>
{
    using abi = ABI::Windows::Media::Effects::IVideoCompositorDefinitionFactory;
    template <typename D> using consume = Windows::Media::Effects::impl_IVideoCompositorDefinitionFactory<D>;
};

template <> struct traits<Windows::Media::Effects::IVideoEffectDefinition>
{
    using abi = ABI::Windows::Media::Effects::IVideoEffectDefinition;
    template <typename D> using consume = Windows::Media::Effects::impl_IVideoEffectDefinition<D>;
};

template <> struct traits<Windows::Media::Effects::IVideoEffectDefinitionFactory>
{
    using abi = ABI::Windows::Media::Effects::IVideoEffectDefinitionFactory;
    template <typename D> using consume = Windows::Media::Effects::impl_IVideoEffectDefinitionFactory<D>;
};

template <> struct traits<Windows::Media::Effects::IVideoTransformEffectDefinition>
{
    using abi = ABI::Windows::Media::Effects::IVideoTransformEffectDefinition;
    template <typename D> using consume = Windows::Media::Effects::impl_IVideoTransformEffectDefinition<D>;
};

template <> struct traits<Windows::Media::Effects::AudioCaptureEffectsManager>
{
    using abi = ABI::Windows::Media::Effects::AudioCaptureEffectsManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.AudioCaptureEffectsManager"; }
};

template <> struct traits<Windows::Media::Effects::AudioEffect>
{
    using abi = ABI::Windows::Media::Effects::AudioEffect;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.AudioEffect"; }
};

template <> struct traits<Windows::Media::Effects::AudioEffectDefinition>
{
    using abi = ABI::Windows::Media::Effects::AudioEffectDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.AudioEffectDefinition"; }
};

template <> struct traits<Windows::Media::Effects::AudioEffectsManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.AudioEffectsManager"; }
};

template <> struct traits<Windows::Media::Effects::AudioRenderEffectsManager>
{
    using abi = ABI::Windows::Media::Effects::AudioRenderEffectsManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.AudioRenderEffectsManager"; }
};

template <> struct traits<Windows::Media::Effects::CompositeVideoFrameContext>
{
    using abi = ABI::Windows::Media::Effects::CompositeVideoFrameContext;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.CompositeVideoFrameContext"; }
};

template <> struct traits<Windows::Media::Effects::ProcessAudioFrameContext>
{
    using abi = ABI::Windows::Media::Effects::ProcessAudioFrameContext;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.ProcessAudioFrameContext"; }
};

template <> struct traits<Windows::Media::Effects::ProcessVideoFrameContext>
{
    using abi = ABI::Windows::Media::Effects::ProcessVideoFrameContext;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.ProcessVideoFrameContext"; }
};

template <> struct traits<Windows::Media::Effects::SlowMotionEffectDefinition>
{
    using abi = ABI::Windows::Media::Effects::SlowMotionEffectDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.SlowMotionEffectDefinition"; }
};

template <> struct traits<Windows::Media::Effects::VideoCompositorDefinition>
{
    using abi = ABI::Windows::Media::Effects::VideoCompositorDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.VideoCompositorDefinition"; }
};

template <> struct traits<Windows::Media::Effects::VideoEffectDefinition>
{
    using abi = ABI::Windows::Media::Effects::VideoEffectDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.VideoEffectDefinition"; }
};

template <> struct traits<Windows::Media::Effects::VideoTransformEffectDefinition>
{
    using abi = ABI::Windows::Media::Effects::VideoTransformEffectDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Effects.VideoTransformEffectDefinition"; }
};

}

}
