// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.3.h"
#include "internal/Windows.Graphics.DirectX.Direct3D11.3.h"
#include "internal/Windows.Media.Editing.3.h"
#include "internal/Windows.Media.Render.3.h"
#include "internal/Windows.Media.Capture.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Media.Transcoding.3.h"
#include "internal/Windows.Media.Effects.3.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Effects::IAudioCaptureEffectsManager> : produce_base<D, Windows::Media::Effects::IAudioCaptureEffectsManager>
{
    HRESULT __stdcall add_AudioCaptureEffectsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioCaptureEffectsManager, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AudioCaptureEffectsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioCaptureEffectsManager, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AudioCaptureEffectsChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioCaptureEffectsChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAudioCaptureEffects(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect>> effects) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *effects = detach_abi(this->shim().GetAudioCaptureEffects());
            return S_OK;
        }
        catch (...)
        {
            *effects = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IAudioEffect> : produce_base<D, Windows::Media::Effects::IAudioEffect>
{
    HRESULT __stdcall get_AudioEffectType(Windows::Media::Effects::AudioEffectType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioEffectType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IAudioEffectDefinition> : produce_base<D, Windows::Media::Effects::IAudioEffectDefinition>
{
    HRESULT __stdcall get_ActivatableClassId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivatableClassId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IAudioEffectDefinitionFactory> : produce_base<D, Windows::Media::Effects::IAudioEffectDefinitionFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_out<Windows::Media::Effects::IAudioEffectDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&activatableClassId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithProperties(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> props, impl::abi_arg_out<Windows::Media::Effects::IAudioEffectDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithProperties(*reinterpret_cast<const hstring *>(&activatableClassId), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&props)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IAudioEffectsManagerStatics> : produce_base<D, Windows::Media::Effects::IAudioEffectsManagerStatics>
{
    HRESULT __stdcall abi_CreateAudioRenderEffectsManager(impl::abi_arg_in<hstring> deviceId, Windows::Media::Render::AudioRenderCategory category, impl::abi_arg_out<Windows::Media::Effects::IAudioRenderEffectsManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAudioRenderEffectsManager(*reinterpret_cast<const hstring *>(&deviceId), category));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAudioRenderEffectsManagerWithMode(impl::abi_arg_in<hstring> deviceId, Windows::Media::Render::AudioRenderCategory category, Windows::Media::AudioProcessing mode, impl::abi_arg_out<Windows::Media::Effects::IAudioRenderEffectsManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAudioRenderEffectsManager(*reinterpret_cast<const hstring *>(&deviceId), category, mode));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAudioCaptureEffectsManager(impl::abi_arg_in<hstring> deviceId, Windows::Media::Capture::MediaCategory category, impl::abi_arg_out<Windows::Media::Effects::IAudioCaptureEffectsManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAudioCaptureEffectsManager(*reinterpret_cast<const hstring *>(&deviceId), category));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAudioCaptureEffectsManagerWithMode(impl::abi_arg_in<hstring> deviceId, Windows::Media::Capture::MediaCategory category, Windows::Media::AudioProcessing mode, impl::abi_arg_out<Windows::Media::Effects::IAudioCaptureEffectsManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAudioCaptureEffectsManager(*reinterpret_cast<const hstring *>(&deviceId), category, mode));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IAudioRenderEffectsManager> : produce_base<D, Windows::Media::Effects::IAudioRenderEffectsManager>
{
    HRESULT __stdcall add_AudioRenderEffectsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioRenderEffectsManager, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AudioRenderEffectsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioRenderEffectsManager, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AudioRenderEffectsChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioRenderEffectsChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAudioRenderEffects(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect>> effects) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *effects = detach_abi(this->shim().GetAudioRenderEffects());
            return S_OK;
        }
        catch (...)
        {
            *effects = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IAudioRenderEffectsManager2> : produce_base<D, Windows::Media::Effects::IAudioRenderEffectsManager2>
{
    HRESULT __stdcall get_EffectsProviderThumbnail(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamWithContentType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EffectsProviderThumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EffectsProviderSettingsLabel(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EffectsProviderSettingsLabel());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowSettingsUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowSettingsUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IBasicAudioEffect> : produce_base<D, Windows::Media::Effects::IBasicAudioEffect>
{
    HRESULT __stdcall get_UseInputFrameForOutput(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UseInputFrameForOutput());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedEncodingProperties(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::AudioEncodingProperties>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedEncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEncodingProperties(impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEncodingProperties(*reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProcessFrame(impl::abi_arg_in<Windows::Media::Effects::IProcessAudioFrameContext> context) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessFrame(*reinterpret_cast<const Windows::Media::Effects::ProcessAudioFrameContext *>(&context));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Close(Windows::Media::Effects::MediaEffectClosedReason reason) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close(reason);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DiscardQueuedFrames() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiscardQueuedFrames();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IBasicVideoEffect> : produce_base<D, Windows::Media::Effects::IBasicVideoEffect>
{
    HRESULT __stdcall get_IsReadOnly(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsReadOnly());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedMemoryTypes(Windows::Media::Effects::MediaMemoryTypes * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedMemoryTypes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimeIndependent(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimeIndependent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedEncodingProperties(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::VideoEncodingProperties>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedEncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEncodingProperties(impl::abi_arg_in<Windows::Media::MediaProperties::IVideoEncodingProperties> encodingProperties, impl::abi_arg_in<Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> device) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEncodingProperties(*reinterpret_cast<const Windows::Media::MediaProperties::VideoEncodingProperties *>(&encodingProperties), *reinterpret_cast<const Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice *>(&device));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProcessFrame(impl::abi_arg_in<Windows::Media::Effects::IProcessVideoFrameContext> context) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessFrame(*reinterpret_cast<const Windows::Media::Effects::ProcessVideoFrameContext *>(&context));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Close(Windows::Media::Effects::MediaEffectClosedReason reason) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close(reason);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DiscardQueuedFrames() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiscardQueuedFrames();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::ICompositeVideoFrameContext> : produce_base<D, Windows::Media::Effects::ICompositeVideoFrameContext>
{
    HRESULT __stdcall get_SurfacesToOverlay(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SurfacesToOverlay());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutputFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutputFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetOverlayForSurface(impl::abi_arg_in<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> surfaceToOverlay, impl::abi_arg_out<Windows::Media::Editing::IMediaOverlay> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetOverlayForSurface(*reinterpret_cast<const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface *>(&surfaceToOverlay)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IProcessAudioFrameContext> : produce_base<D, Windows::Media::Effects::IProcessAudioFrameContext>
{
    HRESULT __stdcall get_InputFrame(impl::abi_arg_out<Windows::Media::IAudioFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutputFrame(impl::abi_arg_out<Windows::Media::IAudioFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutputFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IProcessVideoFrameContext> : produce_base<D, Windows::Media::Effects::IProcessVideoFrameContext>
{
    HRESULT __stdcall get_InputFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutputFrame(impl::abi_arg_out<Windows::Media::IVideoFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutputFrame());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::ISlowMotionEffectDefinition> : produce_base<D, Windows::Media::Effects::ISlowMotionEffectDefinition>
{
    HRESULT __stdcall get_TimeStretchRate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimeStretchRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TimeStretchRate(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimeStretchRate(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IVideoCompositor> : produce_base<D, Windows::Media::Effects::IVideoCompositor>
{
    HRESULT __stdcall get_TimeIndependent(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimeIndependent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetEncodingProperties(impl::abi_arg_in<Windows::Media::MediaProperties::IVideoEncodingProperties> backgroundProperties, impl::abi_arg_in<Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> device) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEncodingProperties(*reinterpret_cast<const Windows::Media::MediaProperties::VideoEncodingProperties *>(&backgroundProperties), *reinterpret_cast<const Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice *>(&device));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CompositeFrame(impl::abi_arg_in<Windows::Media::Effects::ICompositeVideoFrameContext> context) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompositeFrame(*reinterpret_cast<const Windows::Media::Effects::CompositeVideoFrameContext *>(&context));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Close(Windows::Media::Effects::MediaEffectClosedReason reason) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close(reason);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DiscardQueuedFrames() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiscardQueuedFrames();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IVideoCompositorDefinition> : produce_base<D, Windows::Media::Effects::IVideoCompositorDefinition>
{
    HRESULT __stdcall get_ActivatableClassId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivatableClassId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IVideoCompositorDefinitionFactory> : produce_base<D, Windows::Media::Effects::IVideoCompositorDefinitionFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_out<Windows::Media::Effects::IVideoCompositorDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&activatableClassId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithProperties(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> props, impl::abi_arg_out<Windows::Media::Effects::IVideoCompositorDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithProperties(*reinterpret_cast<const hstring *>(&activatableClassId), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&props)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IVideoEffectDefinition> : produce_base<D, Windows::Media::Effects::IVideoEffectDefinition>
{
    HRESULT __stdcall get_ActivatableClassId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivatableClassId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IVideoEffectDefinitionFactory> : produce_base<D, Windows::Media::Effects::IVideoEffectDefinitionFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_out<Windows::Media::Effects::IVideoEffectDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&activatableClassId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithProperties(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> props, impl::abi_arg_out<Windows::Media::Effects::IVideoEffectDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithProperties(*reinterpret_cast<const hstring *>(&activatableClassId), *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&props)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Effects::IVideoTransformEffectDefinition> : produce_base<D, Windows::Media::Effects::IVideoTransformEffectDefinition>
{
    HRESULT __stdcall get_PaddingColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PaddingColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PaddingColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PaddingColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutputSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutputSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutputSize(impl::abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutputSize(*reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CropRectangle(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CropRectangle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CropRectangle(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CropRectangle(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rotation(Windows::Media::MediaProperties::MediaRotation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rotation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Rotation(Windows::Media::MediaProperties::MediaRotation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rotation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mirror(Windows::Media::MediaProperties::MediaMirroringOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mirror());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mirror(Windows::Media::MediaProperties::MediaMirroringOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mirror(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProcessingAlgorithm(Windows::Media::Transcoding::MediaVideoProcessingAlgorithm value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessingAlgorithm(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProcessingAlgorithm(Windows::Media::Transcoding::MediaVideoProcessingAlgorithm * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProcessingAlgorithm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Effects {

template <typename D> hstring impl_IVideoCompositorDefinition<D>::ActivatableClassId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVideoCompositorDefinition)->get_ActivatableClassId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IVideoCompositorDefinition<D>::Properties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IVideoCompositorDefinition)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::VideoCompositorDefinition impl_IVideoCompositorDefinitionFactory<D>::Create(hstring_view activatableClassId) const
{
    Windows::Media::Effects::VideoCompositorDefinition value { nullptr };
    check_hresult(WINRT_SHIM(IVideoCompositorDefinitionFactory)->abi_Create(get_abi(activatableClassId), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::VideoCompositorDefinition impl_IVideoCompositorDefinitionFactory<D>::CreateWithProperties(hstring_view activatableClassId, const Windows::Foundation::Collections::IPropertySet & props) const
{
    Windows::Media::Effects::VideoCompositorDefinition value { nullptr };
    check_hresult(WINRT_SHIM(IVideoCompositorDefinitionFactory)->abi_CreateWithProperties(get_abi(activatableClassId), get_abi(props), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> impl_ICompositeVideoFrameContext<D>::SurfacesToOverlay() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> value;
    check_hresult(WINRT_SHIM(ICompositeVideoFrameContext)->get_SurfacesToOverlay(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_ICompositeVideoFrameContext<D>::BackgroundFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeVideoFrameContext)->get_BackgroundFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_ICompositeVideoFrameContext<D>::OutputFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeVideoFrameContext)->get_OutputFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Editing::MediaOverlay impl_ICompositeVideoFrameContext<D>::GetOverlayForSurface(const Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface & surfaceToOverlay) const
{
    Windows::Media::Editing::MediaOverlay value { nullptr };
    check_hresult(WINRT_SHIM(ICompositeVideoFrameContext)->abi_GetOverlayForSurface(get_abi(surfaceToOverlay), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::AudioEffectType impl_IAudioEffect<D>::AudioEffectType() const
{
    Windows::Media::Effects::AudioEffectType value {};
    check_hresult(WINRT_SHIM(IAudioEffect)->get_AudioEffectType(&value));
    return value;
}

template <typename D> Windows::Media::Effects::AudioRenderEffectsManager impl_IAudioEffectsManagerStatics<D>::CreateAudioRenderEffectsManager(hstring_view deviceId, Windows::Media::Render::AudioRenderCategory category) const
{
    Windows::Media::Effects::AudioRenderEffectsManager value { nullptr };
    check_hresult(WINRT_SHIM(IAudioEffectsManagerStatics)->abi_CreateAudioRenderEffectsManager(get_abi(deviceId), category, put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::AudioRenderEffectsManager impl_IAudioEffectsManagerStatics<D>::CreateAudioRenderEffectsManager(hstring_view deviceId, Windows::Media::Render::AudioRenderCategory category, Windows::Media::AudioProcessing mode) const
{
    Windows::Media::Effects::AudioRenderEffectsManager value { nullptr };
    check_hresult(WINRT_SHIM(IAudioEffectsManagerStatics)->abi_CreateAudioRenderEffectsManagerWithMode(get_abi(deviceId), category, mode, put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::AudioCaptureEffectsManager impl_IAudioEffectsManagerStatics<D>::CreateAudioCaptureEffectsManager(hstring_view deviceId, Windows::Media::Capture::MediaCategory category) const
{
    Windows::Media::Effects::AudioCaptureEffectsManager value { nullptr };
    check_hresult(WINRT_SHIM(IAudioEffectsManagerStatics)->abi_CreateAudioCaptureEffectsManager(get_abi(deviceId), category, put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::AudioCaptureEffectsManager impl_IAudioEffectsManagerStatics<D>::CreateAudioCaptureEffectsManager(hstring_view deviceId, Windows::Media::Capture::MediaCategory category, Windows::Media::AudioProcessing mode) const
{
    Windows::Media::Effects::AudioCaptureEffectsManager value { nullptr };
    check_hresult(WINRT_SHIM(IAudioEffectsManagerStatics)->abi_CreateAudioCaptureEffectsManagerWithMode(get_abi(deviceId), category, mode, put_abi(value)));
    return value;
}

template <typename D> event_token impl_IAudioRenderEffectsManager<D>::AudioRenderEffectsChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioRenderEffectsManager, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioRenderEffectsManager)->add_AudioRenderEffectsChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAudioRenderEffectsManager> impl_IAudioRenderEffectsManager<D>::AudioRenderEffectsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioRenderEffectsManager, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAudioRenderEffectsManager>(this, &ABI::Windows::Media::Effects::IAudioRenderEffectsManager::remove_AudioRenderEffectsChanged, AudioRenderEffectsChanged(handler));
}

template <typename D> void impl_IAudioRenderEffectsManager<D>::AudioRenderEffectsChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioRenderEffectsManager)->remove_AudioRenderEffectsChanged(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect> impl_IAudioRenderEffectsManager<D>::GetAudioRenderEffects() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect> effects;
    check_hresult(WINRT_SHIM(IAudioRenderEffectsManager)->abi_GetAudioRenderEffects(put_abi(effects)));
    return effects;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamWithContentType impl_IAudioRenderEffectsManager2<D>::EffectsProviderThumbnail() const
{
    Windows::Storage::Streams::IRandomAccessStreamWithContentType value;
    check_hresult(WINRT_SHIM(IAudioRenderEffectsManager2)->get_EffectsProviderThumbnail(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAudioRenderEffectsManager2<D>::EffectsProviderSettingsLabel() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAudioRenderEffectsManager2)->get_EffectsProviderSettingsLabel(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioRenderEffectsManager2<D>::ShowSettingsUI() const
{
    check_hresult(WINRT_SHIM(IAudioRenderEffectsManager2)->abi_ShowSettingsUI());
}

template <typename D> event_token impl_IAudioCaptureEffectsManager<D>::AudioCaptureEffectsChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioCaptureEffectsManager, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioCaptureEffectsManager)->add_AudioCaptureEffectsChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAudioCaptureEffectsManager> impl_IAudioCaptureEffectsManager<D>::AudioCaptureEffectsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Effects::AudioCaptureEffectsManager, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAudioCaptureEffectsManager>(this, &ABI::Windows::Media::Effects::IAudioCaptureEffectsManager::remove_AudioCaptureEffectsChanged, AudioCaptureEffectsChanged(handler));
}

template <typename D> void impl_IAudioCaptureEffectsManager<D>::AudioCaptureEffectsChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioCaptureEffectsManager)->remove_AudioCaptureEffectsChanged(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect> impl_IAudioCaptureEffectsManager<D>::GetAudioCaptureEffects() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Effects::AudioEffect> effects;
    check_hresult(WINRT_SHIM(IAudioCaptureEffectsManager)->abi_GetAudioCaptureEffects(put_abi(effects)));
    return effects;
}

template <typename D> bool impl_IVideoCompositor<D>::TimeIndependent() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVideoCompositor)->get_TimeIndependent(&value));
    return value;
}

template <typename D> void impl_IVideoCompositor<D>::SetEncodingProperties(const Windows::Media::MediaProperties::VideoEncodingProperties & backgroundProperties, const Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice & device) const
{
    check_hresult(WINRT_SHIM(IVideoCompositor)->abi_SetEncodingProperties(get_abi(backgroundProperties), get_abi(device)));
}

template <typename D> void impl_IVideoCompositor<D>::CompositeFrame(const Windows::Media::Effects::CompositeVideoFrameContext & context) const
{
    check_hresult(WINRT_SHIM(IVideoCompositor)->abi_CompositeFrame(get_abi(context)));
}

template <typename D> void impl_IVideoCompositor<D>::Close(Windows::Media::Effects::MediaEffectClosedReason reason) const
{
    check_hresult(WINRT_SHIM(IVideoCompositor)->abi_Close(reason));
}

template <typename D> void impl_IVideoCompositor<D>::DiscardQueuedFrames() const
{
    check_hresult(WINRT_SHIM(IVideoCompositor)->abi_DiscardQueuedFrames());
}

template <typename D> hstring impl_IAudioEffectDefinition<D>::ActivatableClassId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAudioEffectDefinition)->get_ActivatableClassId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IAudioEffectDefinition<D>::Properties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IAudioEffectDefinition)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVideoEffectDefinition<D>::ActivatableClassId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVideoEffectDefinition)->get_ActivatableClassId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IVideoEffectDefinition<D>::Properties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IVideoEffectDefinition)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::VideoEffectDefinition impl_IVideoEffectDefinitionFactory<D>::Create(hstring_view activatableClassId) const
{
    Windows::Media::Effects::VideoEffectDefinition value { nullptr };
    check_hresult(WINRT_SHIM(IVideoEffectDefinitionFactory)->abi_Create(get_abi(activatableClassId), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::VideoEffectDefinition impl_IVideoEffectDefinitionFactory<D>::CreateWithProperties(hstring_view activatableClassId, const Windows::Foundation::Collections::IPropertySet & props) const
{
    Windows::Media::Effects::VideoEffectDefinition value { nullptr };
    check_hresult(WINRT_SHIM(IVideoEffectDefinitionFactory)->abi_CreateWithProperties(get_abi(activatableClassId), get_abi(props), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::AudioEffectDefinition impl_IAudioEffectDefinitionFactory<D>::Create(hstring_view activatableClassId) const
{
    Windows::Media::Effects::AudioEffectDefinition value { nullptr };
    check_hresult(WINRT_SHIM(IAudioEffectDefinitionFactory)->abi_Create(get_abi(activatableClassId), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Effects::AudioEffectDefinition impl_IAudioEffectDefinitionFactory<D>::CreateWithProperties(hstring_view activatableClassId, const Windows::Foundation::Collections::IPropertySet & props) const
{
    Windows::Media::Effects::AudioEffectDefinition value { nullptr };
    check_hresult(WINRT_SHIM(IAudioEffectDefinitionFactory)->abi_CreateWithProperties(get_abi(activatableClassId), get_abi(props), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_IProcessVideoFrameContext<D>::InputFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IProcessVideoFrameContext)->get_InputFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoFrame impl_IProcessVideoFrameContext<D>::OutputFrame() const
{
    Windows::Media::VideoFrame value { nullptr };
    check_hresult(WINRT_SHIM(IProcessVideoFrameContext)->get_OutputFrame(put_abi(value)));
    return value;
}

template <typename D> bool impl_IBasicVideoEffect<D>::IsReadOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBasicVideoEffect)->get_IsReadOnly(&value));
    return value;
}

template <typename D> Windows::Media::Effects::MediaMemoryTypes impl_IBasicVideoEffect<D>::SupportedMemoryTypes() const
{
    Windows::Media::Effects::MediaMemoryTypes value {};
    check_hresult(WINRT_SHIM(IBasicVideoEffect)->get_SupportedMemoryTypes(&value));
    return value;
}

template <typename D> bool impl_IBasicVideoEffect<D>::TimeIndependent() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBasicVideoEffect)->get_TimeIndependent(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::VideoEncodingProperties> impl_IBasicVideoEffect<D>::SupportedEncodingProperties() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::VideoEncodingProperties> value;
    check_hresult(WINRT_SHIM(IBasicVideoEffect)->get_SupportedEncodingProperties(put_abi(value)));
    return value;
}

template <typename D> void impl_IBasicVideoEffect<D>::SetEncodingProperties(const Windows::Media::MediaProperties::VideoEncodingProperties & encodingProperties, const Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice & device) const
{
    check_hresult(WINRT_SHIM(IBasicVideoEffect)->abi_SetEncodingProperties(get_abi(encodingProperties), get_abi(device)));
}

template <typename D> void impl_IBasicVideoEffect<D>::ProcessFrame(const Windows::Media::Effects::ProcessVideoFrameContext & context) const
{
    check_hresult(WINRT_SHIM(IBasicVideoEffect)->abi_ProcessFrame(get_abi(context)));
}

template <typename D> void impl_IBasicVideoEffect<D>::Close(Windows::Media::Effects::MediaEffectClosedReason reason) const
{
    check_hresult(WINRT_SHIM(IBasicVideoEffect)->abi_Close(reason));
}

template <typename D> void impl_IBasicVideoEffect<D>::DiscardQueuedFrames() const
{
    check_hresult(WINRT_SHIM(IBasicVideoEffect)->abi_DiscardQueuedFrames());
}

template <typename D> Windows::Media::AudioFrame impl_IProcessAudioFrameContext<D>::InputFrame() const
{
    Windows::Media::AudioFrame value { nullptr };
    check_hresult(WINRT_SHIM(IProcessAudioFrameContext)->get_InputFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::AudioFrame impl_IProcessAudioFrameContext<D>::OutputFrame() const
{
    Windows::Media::AudioFrame value { nullptr };
    check_hresult(WINRT_SHIM(IProcessAudioFrameContext)->get_OutputFrame(put_abi(value)));
    return value;
}

template <typename D> bool impl_IBasicAudioEffect<D>::UseInputFrameForOutput() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBasicAudioEffect)->get_UseInputFrameForOutput(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::AudioEncodingProperties> impl_IBasicAudioEffect<D>::SupportedEncodingProperties() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::MediaProperties::AudioEncodingProperties> value;
    check_hresult(WINRT_SHIM(IBasicAudioEffect)->get_SupportedEncodingProperties(put_abi(value)));
    return value;
}

template <typename D> void impl_IBasicAudioEffect<D>::SetEncodingProperties(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const
{
    check_hresult(WINRT_SHIM(IBasicAudioEffect)->abi_SetEncodingProperties(get_abi(encodingProperties)));
}

template <typename D> void impl_IBasicAudioEffect<D>::ProcessFrame(const Windows::Media::Effects::ProcessAudioFrameContext & context) const
{
    check_hresult(WINRT_SHIM(IBasicAudioEffect)->abi_ProcessFrame(get_abi(context)));
}

template <typename D> void impl_IBasicAudioEffect<D>::Close(Windows::Media::Effects::MediaEffectClosedReason reason) const
{
    check_hresult(WINRT_SHIM(IBasicAudioEffect)->abi_Close(reason));
}

template <typename D> void impl_IBasicAudioEffect<D>::DiscardQueuedFrames() const
{
    check_hresult(WINRT_SHIM(IBasicAudioEffect)->abi_DiscardQueuedFrames());
}

template <typename D> Windows::UI::Color impl_IVideoTransformEffectDefinition<D>::PaddingColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->get_PaddingColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IVideoTransformEffectDefinition<D>::PaddingColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->put_PaddingColor(get_abi(value)));
}

template <typename D> Windows::Foundation::Size impl_IVideoTransformEffectDefinition<D>::OutputSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->get_OutputSize(put_abi(value)));
    return value;
}

template <typename D> void impl_IVideoTransformEffectDefinition<D>::OutputSize(const Windows::Foundation::Size & value) const
{
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->put_OutputSize(get_abi(value)));
}

template <typename D> Windows::Foundation::Rect impl_IVideoTransformEffectDefinition<D>::CropRectangle() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->get_CropRectangle(put_abi(value)));
    return value;
}

template <typename D> void impl_IVideoTransformEffectDefinition<D>::CropRectangle(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->put_CropRectangle(get_abi(value)));
}

template <typename D> Windows::Media::MediaProperties::MediaRotation impl_IVideoTransformEffectDefinition<D>::Rotation() const
{
    Windows::Media::MediaProperties::MediaRotation value {};
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->get_Rotation(&value));
    return value;
}

template <typename D> void impl_IVideoTransformEffectDefinition<D>::Rotation(Windows::Media::MediaProperties::MediaRotation value) const
{
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->put_Rotation(value));
}

template <typename D> Windows::Media::MediaProperties::MediaMirroringOptions impl_IVideoTransformEffectDefinition<D>::Mirror() const
{
    Windows::Media::MediaProperties::MediaMirroringOptions value {};
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->get_Mirror(&value));
    return value;
}

template <typename D> void impl_IVideoTransformEffectDefinition<D>::Mirror(Windows::Media::MediaProperties::MediaMirroringOptions value) const
{
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->put_Mirror(value));
}

template <typename D> void impl_IVideoTransformEffectDefinition<D>::ProcessingAlgorithm(Windows::Media::Transcoding::MediaVideoProcessingAlgorithm value) const
{
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->put_ProcessingAlgorithm(value));
}

template <typename D> Windows::Media::Transcoding::MediaVideoProcessingAlgorithm impl_IVideoTransformEffectDefinition<D>::ProcessingAlgorithm() const
{
    Windows::Media::Transcoding::MediaVideoProcessingAlgorithm value {};
    check_hresult(WINRT_SHIM(IVideoTransformEffectDefinition)->get_ProcessingAlgorithm(&value));
    return value;
}

template <typename D> double impl_ISlowMotionEffectDefinition<D>::TimeStretchRate() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISlowMotionEffectDefinition)->get_TimeStretchRate(&value));
    return value;
}

template <typename D> void impl_ISlowMotionEffectDefinition<D>::TimeStretchRate(double value) const
{
    check_hresult(WINRT_SHIM(ISlowMotionEffectDefinition)->put_TimeStretchRate(value));
}

inline AudioEffectDefinition::AudioEffectDefinition(hstring_view activatableClassId) :
    AudioEffectDefinition(get_activation_factory<AudioEffectDefinition, IAudioEffectDefinitionFactory>().Create(activatableClassId))
{}

inline AudioEffectDefinition::AudioEffectDefinition(hstring_view activatableClassId, const Windows::Foundation::Collections::IPropertySet & props) :
    AudioEffectDefinition(get_activation_factory<AudioEffectDefinition, IAudioEffectDefinitionFactory>().CreateWithProperties(activatableClassId, props))
{}

inline Windows::Media::Effects::AudioRenderEffectsManager AudioEffectsManager::CreateAudioRenderEffectsManager(hstring_view deviceId, Windows::Media::Render::AudioRenderCategory category)
{
    return get_activation_factory<AudioEffectsManager, IAudioEffectsManagerStatics>().CreateAudioRenderEffectsManager(deviceId, category);
}

inline Windows::Media::Effects::AudioRenderEffectsManager AudioEffectsManager::CreateAudioRenderEffectsManager(hstring_view deviceId, Windows::Media::Render::AudioRenderCategory category, Windows::Media::AudioProcessing mode)
{
    return get_activation_factory<AudioEffectsManager, IAudioEffectsManagerStatics>().CreateAudioRenderEffectsManager(deviceId, category, mode);
}

inline Windows::Media::Effects::AudioCaptureEffectsManager AudioEffectsManager::CreateAudioCaptureEffectsManager(hstring_view deviceId, Windows::Media::Capture::MediaCategory category)
{
    return get_activation_factory<AudioEffectsManager, IAudioEffectsManagerStatics>().CreateAudioCaptureEffectsManager(deviceId, category);
}

inline Windows::Media::Effects::AudioCaptureEffectsManager AudioEffectsManager::CreateAudioCaptureEffectsManager(hstring_view deviceId, Windows::Media::Capture::MediaCategory category, Windows::Media::AudioProcessing mode)
{
    return get_activation_factory<AudioEffectsManager, IAudioEffectsManagerStatics>().CreateAudioCaptureEffectsManager(deviceId, category, mode);
}

inline SlowMotionEffectDefinition::SlowMotionEffectDefinition() :
    SlowMotionEffectDefinition(activate_instance<SlowMotionEffectDefinition>())
{}

inline VideoCompositorDefinition::VideoCompositorDefinition(hstring_view activatableClassId) :
    VideoCompositorDefinition(get_activation_factory<VideoCompositorDefinition, IVideoCompositorDefinitionFactory>().Create(activatableClassId))
{}

inline VideoCompositorDefinition::VideoCompositorDefinition(hstring_view activatableClassId, const Windows::Foundation::Collections::IPropertySet & props) :
    VideoCompositorDefinition(get_activation_factory<VideoCompositorDefinition, IVideoCompositorDefinitionFactory>().CreateWithProperties(activatableClassId, props))
{}

inline VideoEffectDefinition::VideoEffectDefinition(hstring_view activatableClassId) :
    VideoEffectDefinition(get_activation_factory<VideoEffectDefinition, IVideoEffectDefinitionFactory>().Create(activatableClassId))
{}

inline VideoEffectDefinition::VideoEffectDefinition(hstring_view activatableClassId, const Windows::Foundation::Collections::IPropertySet & props) :
    VideoEffectDefinition(get_activation_factory<VideoEffectDefinition, IVideoEffectDefinitionFactory>().CreateWithProperties(activatableClassId, props))
{}

inline VideoTransformEffectDefinition::VideoTransformEffectDefinition() :
    VideoTransformEffectDefinition(activate_instance<VideoTransformEffectDefinition>())
{}

}

}
#pragma warning(pop)
