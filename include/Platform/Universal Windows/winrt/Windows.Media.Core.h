// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Media.Protection.3.h"
#include "internal/Windows.Storage.FileProperties.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.Capture.3.h"
#include "internal/Windows.Media.Devices.3.h"
#include "internal/Windows.Media.Streaming.Adaptive.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Media.Playback.3.h"
#include "internal/Windows.Media.Core.3.h"
#include "Windows.Media.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"
#include "Windows.Media.Effects.h"
#include "Windows.Media.Playback.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Core::IAudioStreamDescriptor> : produce_base<D, Windows::Media::Core::IAudioStreamDescriptor>
{
    HRESULT __stdcall get_EncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *encodingProperties = detach_abi(this->shim().EncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *encodingProperties = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IAudioStreamDescriptor2> : produce_base<D, Windows::Media::Core::IAudioStreamDescriptor2>
{
    HRESULT __stdcall put_LeadingEncoderPadding(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeadingEncoderPadding(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LeadingEncoderPadding(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LeadingEncoderPadding());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrailingEncoderPadding(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrailingEncoderPadding(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrailingEncoderPadding(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrailingEncoderPadding());
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
struct produce<D, Windows::Media::Core::IAudioStreamDescriptorFactory> : produce_base<D, Windows::Media::Core::IAudioStreamDescriptorFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties, impl::abi_arg_out<Windows::Media::Core::IAudioStreamDescriptor> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IAudioTrack> : produce_base<D, Windows::Media::Core::IAudioTrack>
{
    HRESULT __stdcall add_OpenFailed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::AudioTrack, Windows::Media::Core::AudioTrackOpenFailedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().OpenFailed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::AudioTrack, Windows::Media::Core::AudioTrackOpenFailedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OpenFailed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenFailed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IAudioEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetEncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackItem(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportInfo(impl::abi_arg_out<Windows::Media::Core::IAudioTrackSupportInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportInfo());
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
struct produce<D, Windows::Media::Core::IAudioTrackOpenFailedEventArgs> : produce_base<D, Windows::Media::Core::IAudioTrackOpenFailedEventArgs>
{
    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IAudioTrackSupportInfo> : produce_base<D, Windows::Media::Core::IAudioTrackSupportInfo>
{
    HRESULT __stdcall get_DecoderStatus(Windows::Media::Core::MediaDecoderStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecoderStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Degradation(Windows::Media::Core::AudioDecoderDegradation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Degradation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DegradationReason(Windows::Media::Core::AudioDecoderDegradationReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DegradationReason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaSourceStatus(Windows::Media::Core::MediaSourceStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaSourceStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IDataCue> : produce_base<D, Windows::Media::Core::IDataCue>
{
    HRESULT __stdcall put_Data(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Data(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
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
struct produce<D, Windows::Media::Core::IFaceDetectedEventArgs> : produce_base<D, Windows::Media::Core::IFaceDetectedEventArgs>
{
    HRESULT __stdcall get_ResultFrame(impl::abi_arg_out<Windows::Media::Core::IFaceDetectionEffectFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResultFrame());
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
struct produce<D, Windows::Media::Core::IFaceDetectionEffect> : produce_base<D, Windows::Media::Core::IFaceDetectionEffect>
{
    HRESULT __stdcall put_Enabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Enabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredDetectionInterval(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredDetectionInterval(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredDetectionInterval(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredDetectionInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FaceDetected(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::FaceDetectionEffect, Windows::Media::Core::FaceDetectedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().FaceDetected(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::FaceDetectionEffect, Windows::Media::Core::FaceDetectedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FaceDetected(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FaceDetected(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IFaceDetectionEffectDefinition> : produce_base<D, Windows::Media::Core::IFaceDetectionEffectDefinition>
{
    HRESULT __stdcall put_DetectionMode(Windows::Media::Core::FaceDetectionMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DetectionMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DetectionMode(Windows::Media::Core::FaceDetectionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DetectionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SynchronousDetectionEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SynchronousDetectionEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SynchronousDetectionEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SynchronousDetectionEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IFaceDetectionEffectFrame> : produce_base<D, Windows::Media::Core::IFaceDetectionEffectFrame>
{
    HRESULT __stdcall get_DetectedFaces(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::FaceAnalysis::DetectedFace>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DetectedFaces());
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
struct produce<D, Windows::Media::Core::IHighDynamicRangeControl> : produce_base<D, Windows::Media::Core::IHighDynamicRangeControl>
{
    HRESULT __stdcall put_Enabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Enabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IHighDynamicRangeOutput> : produce_base<D, Windows::Media::Core::IHighDynamicRangeOutput>
{
    HRESULT __stdcall get_Certainty(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Certainty());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrameControllers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Devices::Core::FrameController>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameControllers());
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
struct produce<D, Windows::Media::Core::IMediaBinder> : produce_base<D, Windows::Media::Core::IMediaBinder>
{
    HRESULT __stdcall add_Binding(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaBinder, Windows::Media::Core::MediaBindingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Binding(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaBinder, Windows::Media::Core::MediaBindingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Binding(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Binding(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Token(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Token());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Token(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Token(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Media::Core::IMediaSource2> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
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
struct produce<D, Windows::Media::Core::IMediaBindingEventArgs> : produce_base<D, Windows::Media::Core::IMediaBindingEventArgs>
{
    HRESULT __stdcall add_Canceled(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaBindingEventArgs, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Canceled(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaBindingEventArgs, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Canceled(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Canceled(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaBinder(impl::abi_arg_out<Windows::Media::Core::IMediaBinder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaBinder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStream(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_in<hstring> contentType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStream(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream), *reinterpret_cast<const hstring *>(&contentType));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStreamReference(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> stream, impl::abi_arg_in<hstring> contentType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStreamReference(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&stream), *reinterpret_cast<const hstring *>(&contentType));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaCue> : produce_base<D, Windows::Media::Core::IMediaCue>
{
    HRESULT __stdcall put_StartTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
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
struct produce<D, Windows::Media::Core::IMediaCueEventArgs> : produce_base<D, Windows::Media::Core::IMediaCueEventArgs>
{
    HRESULT __stdcall get_Cue(impl::abi_arg_out<Windows::Media::Core::IMediaCue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cue());
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
struct produce<D, Windows::Media::Core::IMediaSource> : produce_base<D, Windows::Media::Core::IMediaSource>
{};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaSource2> : produce_base<D, Windows::Media::Core::IMediaSource2>
{
    HRESULT __stdcall add_OpenOperationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaSource, Windows::Media::Core::MediaSourceOpenOperationCompletedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().OpenOperationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaSource, Windows::Media::Core::MediaSourceOpenOperationCompletedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OpenOperationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenOperationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomProperties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOpen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOpen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExternalTimedTextSources(impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::Media::Core::TimedTextSource>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExternalTimedTextSources());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExternalTimedMetadataTracks(impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::Media::Core::TimedMetadataTrack>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExternalTimedMetadataTracks());
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
struct produce<D, Windows::Media::Core::IMediaSource3> : produce_base<D, Windows::Media::Core::IMediaSource3>
{
    HRESULT __stdcall add_StateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaSource, Windows::Media::Core::MediaSourceStateChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaSource, Windows::Media::Core::MediaSourceStateChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(Windows::Media::Core::MediaSourceState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Reset() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reset();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaSourceError> : produce_base<D, Windows::Media::Core::IMediaSourceError>
{
    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaSourceOpenOperationCompletedEventArgs> : produce_base<D, Windows::Media::Core::IMediaSourceOpenOperationCompletedEventArgs>
{
    HRESULT __stdcall get_Error(impl::abi_arg_out<Windows::Media::Core::IMediaSourceError> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Error());
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
struct produce<D, Windows::Media::Core::IMediaSourceStateChangedEventArgs> : produce_base<D, Windows::Media::Core::IMediaSourceStateChangedEventArgs>
{
    HRESULT __stdcall get_OldState(Windows::Media::Core::MediaSourceState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewState(Windows::Media::Core::MediaSourceState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaSourceStatics> : produce_base<D, Windows::Media::Core::IMediaSourceStatics>
{
    HRESULT __stdcall abi_CreateFromAdaptiveMediaSource(impl::abi_arg_in<Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource> mediaSource, impl::abi_arg_out<Windows::Media::Core::IMediaSource2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromAdaptiveMediaSource(*reinterpret_cast<const Windows::Media::Streaming::Adaptive::AdaptiveMediaSource *>(&mediaSource)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromMediaStreamSource(impl::abi_arg_in<Windows::Media::Core::IMediaStreamSource> mediaSource, impl::abi_arg_out<Windows::Media::Core::IMediaSource2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromMediaStreamSource(*reinterpret_cast<const Windows::Media::Core::MediaStreamSource *>(&mediaSource)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromMseStreamSource(impl::abi_arg_in<Windows::Media::Core::IMseStreamSource> mediaSource, impl::abi_arg_out<Windows::Media::Core::IMediaSource2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromMseStreamSource(*reinterpret_cast<const Windows::Media::Core::MseStreamSource *>(&mediaSource)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromIMediaSource(impl::abi_arg_in<Windows::Media::Core::IMediaSource> mediaSource, impl::abi_arg_out<Windows::Media::Core::IMediaSource2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromIMediaSource(*reinterpret_cast<const Windows::Media::Core::IMediaSource *>(&mediaSource)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromStorageFile(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Media::Core::IMediaSource2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromStorageFile(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromStream(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_in<hstring> contentType, impl::abi_arg_out<Windows::Media::Core::IMediaSource2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromStream(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream), *reinterpret_cast<const hstring *>(&contentType)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromStreamReference(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> stream, impl::abi_arg_in<hstring> contentType, impl::abi_arg_out<Windows::Media::Core::IMediaSource2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromStreamReference(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&stream), *reinterpret_cast<const hstring *>(&contentType)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Media::Core::IMediaSource2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaSourceStatics2> : produce_base<D, Windows::Media::Core::IMediaSourceStatics2>
{
    HRESULT __stdcall abi_CreateFromMediaBinder(impl::abi_arg_in<Windows::Media::Core::IMediaBinder> binder, impl::abi_arg_out<Windows::Media::Core::IMediaSource2> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromMediaBinder(*reinterpret_cast<const Windows::Media::Core::MediaBinder *>(&binder)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamDescriptor> : produce_base<D, Windows::Media::Core::IMediaStreamDescriptor>
{
    HRESULT __stdcall get_IsSelected(bool * selected) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selected = detach_abi(this->shim().IsSelected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Language(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
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
struct produce<D, Windows::Media::Core::IMediaStreamSample> : produce_base<D, Windows::Media::Core::IMediaStreamSample>
{
    HRESULT __stdcall add_Processed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSample, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Processed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSample, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Processed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Processed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Buffer(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Buffer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedProperties(impl::abi_arg_out<Windows::Foundation::Collections::IMap<GUID, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Protection(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSampleProtectionProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Protection());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DecodeTimestamp(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DecodeTimestamp(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DecodeTimestamp(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecodeTimestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyFrame(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyFrame(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyFrame(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyFrame());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Discontinuous(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Discontinuous(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Discontinuous(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Discontinuous());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSampleProtectionProperties> : produce_base<D, Windows::Media::Core::IMediaStreamSampleProtectionProperties>
{
    HRESULT __stdcall abi_SetKeyIdentifier(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetKeyIdentifier(array_view<const uint8_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetKeyIdentifier(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetKeyIdentifier(detach_abi<uint8_t>(__valueSize, value));
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetInitializationVector(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInitializationVector(array_view<const uint8_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetInitializationVector(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetInitializationVector(detach_abi<uint8_t>(__valueSize, value));
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSubSampleMapping(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSubSampleMapping(array_view<const uint8_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSubSampleMapping(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetSubSampleMapping(detach_abi<uint8_t>(__valueSize, value));
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSampleStatics> : produce_base<D, Windows::Media::Core::IMediaStreamSampleStatics>
{
    HRESULT __stdcall abi_CreateFromBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_in<Windows::Foundation::TimeSpan> timestamp, impl::abi_arg_out<Windows::Media::Core::IMediaStreamSample> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timestamp)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromStreamAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> stream, uint32_t count, impl::abi_arg_in<Windows::Foundation::TimeSpan> timestamp, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Core::MediaStreamSample>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&stream), count, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timestamp)));
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
struct produce<D, Windows::Media::Core::IMediaStreamSource> : produce_base<D, Windows::Media::Core::IMediaStreamSource>
{
    HRESULT __stdcall add_Closed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceClosedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Closed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceClosedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Closed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Starting(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceStartingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Starting(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceStartingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Starting(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Starting(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Paused(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Paused(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Paused(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Paused(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SampleRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSampleRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SampleRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSampleRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SampleRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SampleRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SwitchStreamsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSwitchStreamsRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SwitchStreamsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSwitchStreamsRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SwitchStreamsRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SwitchStreamsRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyError(Windows::Media::Core::MediaStreamSourceErrorStatus errorStatus) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyError(errorStatus);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddStreamDescriptor(impl::abi_arg_in<Windows::Media::Core::IMediaStreamDescriptor> descriptor) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddStreamDescriptor(*reinterpret_cast<const Windows::Media::Core::IMediaStreamDescriptor *>(&descriptor));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MediaProtectionManager(impl::abi_arg_in<Windows::Media::Protection::IMediaProtectionManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaProtectionManager(*reinterpret_cast<const Windows::Media::Protection::MediaProtectionManager *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaProtectionManager(impl::abi_arg_out<Windows::Media::Protection::IMediaProtectionManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaProtectionManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanSeek(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanSeek(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanSeek(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanSeek());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BufferTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BufferTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BufferTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetBufferedRange(impl::abi_arg_in<Windows::Foundation::TimeSpan> startOffset, impl::abi_arg_in<Windows::Foundation::TimeSpan> endOffset) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBufferedRange(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&startOffset), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&endOffset));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MusicProperties(impl::abi_arg_out<Windows::Storage::FileProperties::IMusicProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MusicProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoProperties(impl::abi_arg_out<Windows::Storage::FileProperties::IVideoProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Thumbnail(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddProtectionKey(impl::abi_arg_in<Windows::Media::Core::IMediaStreamDescriptor> streamDescriptor, uint32_t __keyIdentifierSize, impl::abi_arg_in<uint8_t> * keyIdentifier, uint32_t __licenseDataSize, impl::abi_arg_in<uint8_t> * licenseData) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddProtectionKey(*reinterpret_cast<const Windows::Media::Core::IMediaStreamDescriptor *>(&streamDescriptor), array_view<const uint8_t>(keyIdentifier, keyIdentifier + __keyIdentifierSize), array_view<const uint8_t>(licenseData, licenseData + __licenseDataSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSource2> : produce_base<D, Windows::Media::Core::IMediaStreamSource2>
{
    HRESULT __stdcall add_SampleRendered(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSampleRenderedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SampleRendered(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSampleRenderedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SampleRendered(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SampleRendered(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceClosedEventArgs> : produce_base<D, Windows::Media::Core::IMediaStreamSourceClosedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSourceClosedRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
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
struct produce<D, Windows::Media::Core::IMediaStreamSourceClosedRequest> : produce_base<D, Windows::Media::Core::IMediaStreamSourceClosedRequest>
{
    HRESULT __stdcall get_Reason(Windows::Media::Core::MediaStreamSourceClosedReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceFactory> : produce_base<D, Windows::Media::Core::IMediaStreamSourceFactory>
{
    HRESULT __stdcall abi_CreateFromDescriptor(impl::abi_arg_in<Windows::Media::Core::IMediaStreamDescriptor> descriptor, impl::abi_arg_out<Windows::Media::Core::IMediaStreamSource> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromDescriptor(*reinterpret_cast<const Windows::Media::Core::IMediaStreamDescriptor *>(&descriptor)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromDescriptors(impl::abi_arg_in<Windows::Media::Core::IMediaStreamDescriptor> descriptor, impl::abi_arg_in<Windows::Media::Core::IMediaStreamDescriptor> descriptor2, impl::abi_arg_out<Windows::Media::Core::IMediaStreamSource> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFromDescriptors(*reinterpret_cast<const Windows::Media::Core::IMediaStreamDescriptor *>(&descriptor), *reinterpret_cast<const Windows::Media::Core::IMediaStreamDescriptor *>(&descriptor2)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceSampleRenderedEventArgs> : produce_base<D, Windows::Media::Core::IMediaStreamSourceSampleRenderedEventArgs>
{
    HRESULT __stdcall get_SampleLag(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SampleLag());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceSampleRequest> : produce_base<D, Windows::Media::Core::IMediaStreamSourceSampleRequest>
{
    HRESULT __stdcall get_StreamDescriptor(impl::abi_arg_out<Windows::Media::Core::IMediaStreamDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StreamDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSourceSampleRequestDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Sample(impl::abi_arg_in<Windows::Media::Core::IMediaStreamSample> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Sample(*reinterpret_cast<const Windows::Media::Core::MediaStreamSample *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Sample(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSample> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Sample());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportSampleProgress(uint32_t progress) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportSampleProgress(progress);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceSampleRequestDeferral> : produce_base<D, Windows::Media::Core::IMediaStreamSourceSampleRequestDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceSampleRequestedEventArgs> : produce_base<D, Windows::Media::Core::IMediaStreamSourceSampleRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSourceSampleRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
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
struct produce<D, Windows::Media::Core::IMediaStreamSourceStartingEventArgs> : produce_base<D, Windows::Media::Core::IMediaStreamSourceStartingEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSourceStartingRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
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
struct produce<D, Windows::Media::Core::IMediaStreamSourceStartingRequest> : produce_base<D, Windows::Media::Core::IMediaStreamSourceStartingRequest>
{
    HRESULT __stdcall get_StartPosition(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartPosition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSourceStartingRequestDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetActualStartPosition(impl::abi_arg_in<Windows::Foundation::TimeSpan> position) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetActualStartPosition(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&position));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceStartingRequestDeferral> : produce_base<D, Windows::Media::Core::IMediaStreamSourceStartingRequestDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequest> : produce_base<D, Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequest>
{
    HRESULT __stdcall get_OldStreamDescriptor(impl::abi_arg_out<Windows::Media::Core::IMediaStreamDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldStreamDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewStreamDescriptor(impl::abi_arg_out<Windows::Media::Core::IMediaStreamDescriptor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewStreamDescriptor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestDeferral> deferral) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deferral = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestDeferral> : produce_base<D, Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestedEventArgs> : produce_base<D, Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
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
struct produce<D, Windows::Media::Core::IMediaTrack> : produce_base<D, Windows::Media::Core::IMediaTrack>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrackKind(Windows::Media::Core::MediaTrackKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrackKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Label(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Label(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Label(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Label());
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
struct produce<D, Windows::Media::Core::IMseSourceBuffer> : produce_base<D, Windows::Media::Core::IMseSourceBuffer>
{
    HRESULT __stdcall add_UpdateStarting(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UpdateStarting(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UpdateStarting(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateStarting(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Updated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Updated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Updated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UpdateEnded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UpdateEnded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UpdateEnded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateEnded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ErrorOccurred(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ErrorOccurred(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ErrorOccurred(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorOccurred(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Aborted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Aborted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Aborted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Aborted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mode(Windows::Media::Core::MseAppendMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mode(Windows::Media::Core::MseAppendMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsUpdating(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsUpdating());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Buffered(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Core::MseTimeRange>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Buffered());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimestampOffset(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimestampOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TimestampOffset(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimestampOffset(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppendWindowStart(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppendWindowStart());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppendWindowStart(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendWindowStart(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppendWindowEnd(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppendWindowEnd());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppendWindowEnd(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendWindowEnd(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendStream(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> stream) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendStream(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&stream));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendStreamMaxSize(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> stream, uint64_t maxSize) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendStream(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&stream), maxSize);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Abort() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Abort();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(impl::abi_arg_in<Windows::Foundation::TimeSpan> start, impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> end) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&start), *reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&end));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMseSourceBufferList> : produce_base<D, Windows::Media::Core::IMseSourceBufferList>
{
    HRESULT __stdcall add_SourceBufferAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBufferList, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceBufferAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBufferList, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceBufferAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceBufferAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SourceBufferRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBufferList, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceBufferRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBufferList, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceBufferRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceBufferRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Buffers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Core::MseSourceBuffer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Buffers());
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
struct produce<D, Windows::Media::Core::IMseStreamSource> : produce_base<D, Windows::Media::Core::IMseStreamSource>
{
    HRESULT __stdcall add_Opened(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Opened(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Opened(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opened(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Ended(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Ended(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Ended(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ended(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Closed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Closed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Closed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceBuffers(impl::abi_arg_out<Windows::Media::Core::IMseSourceBufferList> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceBuffers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActiveSourceBuffers(impl::abi_arg_out<Windows::Media::Core::IMseSourceBufferList> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActiveSourceBuffers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadyState(Windows::Media::Core::MseReadyState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadyState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSourceBuffer(impl::abi_arg_in<hstring> mimeType, impl::abi_arg_out<Windows::Media::Core::IMseSourceBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().AddSourceBuffer(*reinterpret_cast<const hstring *>(&mimeType)));
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveSourceBuffer(impl::abi_arg_in<Windows::Media::Core::IMseSourceBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveSourceBuffer(*reinterpret_cast<const Windows::Media::Core::MseSourceBuffer *>(&buffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EndOfStream(Windows::Media::Core::MseEndOfStreamStatus status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndOfStream(status);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IMseStreamSourceStatics> : produce_base<D, Windows::Media::Core::IMseStreamSourceStatics>
{
    HRESULT __stdcall abi_IsContentTypeSupported(impl::abi_arg_in<hstring> contentType, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsContentTypeSupported(*reinterpret_cast<const hstring *>(&contentType)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::ISceneAnalysisEffect> : produce_base<D, Windows::Media::Core::ISceneAnalysisEffect>
{
    HRESULT __stdcall get_HighDynamicRangeAnalyzer(impl::abi_arg_out<Windows::Media::Core::IHighDynamicRangeControl> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HighDynamicRangeAnalyzer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredAnalysisInterval(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredAnalysisInterval(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredAnalysisInterval(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredAnalysisInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SceneAnalyzed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::SceneAnalysisEffect, Windows::Media::Core::SceneAnalyzedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().SceneAnalyzed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::SceneAnalysisEffect, Windows::Media::Core::SceneAnalyzedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SceneAnalyzed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SceneAnalyzed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::ISceneAnalysisEffectFrame> : produce_base<D, Windows::Media::Core::ISceneAnalysisEffectFrame>
{
    HRESULT __stdcall get_FrameControlValues(impl::abi_arg_out<Windows::Media::Capture::ICapturedFrameControlValues> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrameControlValues());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HighDynamicRange(impl::abi_arg_out<Windows::Media::Core::IHighDynamicRangeOutput> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HighDynamicRange());
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
struct produce<D, Windows::Media::Core::ISceneAnalyzedEventArgs> : produce_base<D, Windows::Media::Core::ISceneAnalyzedEventArgs>
{
    HRESULT __stdcall get_ResultFrame(impl::abi_arg_out<Windows::Media::Core::ISceneAnalysisEffectFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResultFrame());
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
struct produce<D, Windows::Media::Core::ISingleSelectMediaTrackList> : produce_base<D, Windows::Media::Core::ISingleSelectMediaTrackList>
{
    HRESULT __stdcall add_SelectedIndexChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::ISingleSelectMediaTrackList, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SelectedIndexChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::ISingleSelectMediaTrackList, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SelectedIndexChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedIndexChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SelectedIndex(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::ITimedMetadataTrack> : produce_base<D, Windows::Media::Core::ITimedMetadataTrack>
{
    HRESULT __stdcall add_CueEntered(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::MediaCueEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CueEntered(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::MediaCueEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CueEntered(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CueEntered(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CueExited(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::MediaCueEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CueExited(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::MediaCueEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CueExited(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CueExited(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TrackFailed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::TimedMetadataTrackFailedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TrackFailed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::TimedMetadataTrackFailedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TrackFailed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrackFailed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cues(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Core::IMediaCue>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cues());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActiveCues(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Core::IMediaCue>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActiveCues());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimedMetadataKind(Windows::Media::Core::TimedMetadataKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimedMetadataKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DispatchType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DispatchType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddCue(impl::abi_arg_in<Windows::Media::Core::IMediaCue> cue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddCue(*reinterpret_cast<const Windows::Media::Core::IMediaCue *>(&cue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveCue(impl::abi_arg_in<Windows::Media::Core::IMediaCue> cue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveCue(*reinterpret_cast<const Windows::Media::Core::IMediaCue *>(&cue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::ITimedMetadataTrack2> : produce_base<D, Windows::Media::Core::ITimedMetadataTrack2>
{
    HRESULT __stdcall get_PlaybackItem(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
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
struct produce<D, Windows::Media::Core::ITimedMetadataTrackError> : produce_base<D, Windows::Media::Core::ITimedMetadataTrackError>
{
    HRESULT __stdcall get_ErrorCode(Windows::Media::Core::TimedMetadataTrackErrorCode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::ITimedMetadataTrackFactory> : produce_base<D, Windows::Media::Core::ITimedMetadataTrackFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> id, impl::abi_arg_in<hstring> language, Windows::Media::Core::TimedMetadataKind kind, impl::abi_arg_out<Windows::Media::Core::ITimedMetadataTrack> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const hstring *>(&language), kind));
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
struct produce<D, Windows::Media::Core::ITimedMetadataTrackFailedEventArgs> : produce_base<D, Windows::Media::Core::ITimedMetadataTrackFailedEventArgs>
{
    HRESULT __stdcall get_Error(impl::abi_arg_out<Windows::Media::Core::ITimedMetadataTrackError> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Error());
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
struct produce<D, Windows::Media::Core::ITimedTextCue> : produce_base<D, Windows::Media::Core::ITimedTextCue>
{
    HRESULT __stdcall get_CueRegion(impl::abi_arg_out<Windows::Media::Core::ITimedTextRegion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CueRegion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CueRegion(impl::abi_arg_in<Windows::Media::Core::ITimedTextRegion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CueRegion(*reinterpret_cast<const Windows::Media::Core::TimedTextRegion *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CueStyle(impl::abi_arg_out<Windows::Media::Core::ITimedTextStyle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CueStyle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CueStyle(impl::abi_arg_in<Windows::Media::Core::ITimedTextStyle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CueStyle(*reinterpret_cast<const Windows::Media::Core::TimedTextStyle *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Lines(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Core::TimedTextLine>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Lines());
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
struct produce<D, Windows::Media::Core::ITimedTextLine> : produce_base<D, Windows::Media::Core::ITimedTextLine>
{
    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subformats(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Core::TimedTextSubformat>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subformats());
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
struct produce<D, Windows::Media::Core::ITimedTextRegion> : produce_base<D, Windows::Media::Core::ITimedTextRegion>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Media::Core::TimedTextPoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Position(impl::abi_arg_in<Windows::Media::Core::TimedTextPoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<const Windows::Media::Core::TimedTextPoint *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Extent(impl::abi_arg_out<Windows::Media::Core::TimedTextSize> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Extent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Extent(impl::abi_arg_in<Windows::Media::Core::TimedTextSize> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Extent(*reinterpret_cast<const Windows::Media::Core::TimedTextSize *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Background(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Background());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Background(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Background(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WritingMode(Windows::Media::Core::TimedTextWritingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WritingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WritingMode(Windows::Media::Core::TimedTextWritingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WritingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayAlignment(Windows::Media::Core::TimedTextDisplayAlignment * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayAlignment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayAlignment(Windows::Media::Core::TimedTextDisplayAlignment value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayAlignment(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineHeight(impl::abi_arg_out<Windows::Media::Core::TimedTextDouble> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LineHeight(impl::abi_arg_in<Windows::Media::Core::TimedTextDouble> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineHeight(*reinterpret_cast<const Windows::Media::Core::TimedTextDouble *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOverflowClipped(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOverflowClipped());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsOverflowClipped(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsOverflowClipped(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Padding(impl::abi_arg_out<Windows::Media::Core::TimedTextPadding> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Padding());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Padding(impl::abi_arg_in<Windows::Media::Core::TimedTextPadding> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Padding(*reinterpret_cast<const Windows::Media::Core::TimedTextPadding *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextWrapping(Windows::Media::Core::TimedTextWrapping * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextWrapping());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextWrapping(Windows::Media::Core::TimedTextWrapping value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextWrapping(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ZIndex(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ZIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScrollMode(Windows::Media::Core::TimedTextScrollMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScrollMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ScrollMode(Windows::Media::Core::TimedTextScrollMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScrollMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::ITimedTextSource> : produce_base<D, Windows::Media::Core::ITimedTextSource>
{
    HRESULT __stdcall add_Resolved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedTextSource, Windows::Media::Core::TimedTextSourceResolveResultEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Resolved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedTextSource, Windows::Media::Core::TimedTextSourceResolveResultEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Resolved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resolved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::ITimedTextSourceResolveResultEventArgs> : produce_base<D, Windows::Media::Core::ITimedTextSourceResolveResultEventArgs>
{
    HRESULT __stdcall get_Error(impl::abi_arg_out<Windows::Media::Core::ITimedMetadataTrackError> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Error());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tracks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Core::TimedMetadataTrack>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tracks());
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
struct produce<D, Windows::Media::Core::ITimedTextSourceStatics> : produce_base<D, Windows::Media::Core::ITimedTextSourceStatics>
{
    HRESULT __stdcall abi_CreateFromStream(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_out<Windows::Media::Core::ITimedTextSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromStream(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Media::Core::ITimedTextSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromStreamWithLanguage(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_in<hstring> defaultLanguage, impl::abi_arg_out<Windows::Media::Core::ITimedTextSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromStream(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream), *reinterpret_cast<const hstring *>(&defaultLanguage)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromUriWithLanguage(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<hstring> defaultLanguage, impl::abi_arg_out<Windows::Media::Core::ITimedTextSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const hstring *>(&defaultLanguage)));
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
struct produce<D, Windows::Media::Core::ITimedTextStyle> : produce_base<D, Windows::Media::Core::ITimedTextStyle>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontFamily(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontFamily());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontFamily(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontFamily(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontSize(impl::abi_arg_out<Windows::Media::Core::TimedTextDouble> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontSize(impl::abi_arg_in<Windows::Media::Core::TimedTextDouble> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontSize(*reinterpret_cast<const Windows::Media::Core::TimedTextDouble *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FontWeight(Windows::Media::Core::TimedTextWeight * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FontWeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FontWeight(Windows::Media::Core::TimedTextWeight value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FontWeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Foreground(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Foreground());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Foreground(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Foreground(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Background(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Background());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Background(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Background(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsBackgroundAlwaysShown(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsBackgroundAlwaysShown());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsBackgroundAlwaysShown(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsBackgroundAlwaysShown(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlowDirection(Windows::Media::Core::TimedTextFlowDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlowDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FlowDirection(Windows::Media::Core::TimedTextFlowDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FlowDirection(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineAlignment(Windows::Media::Core::TimedTextLineAlignment * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineAlignment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LineAlignment(Windows::Media::Core::TimedTextLineAlignment value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LineAlignment(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutlineColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutlineColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutlineColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutlineColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutlineThickness(impl::abi_arg_out<Windows::Media::Core::TimedTextDouble> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutlineThickness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutlineThickness(impl::abi_arg_in<Windows::Media::Core::TimedTextDouble> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutlineThickness(*reinterpret_cast<const Windows::Media::Core::TimedTextDouble *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutlineRadius(impl::abi_arg_out<Windows::Media::Core::TimedTextDouble> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutlineRadius());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutlineRadius(impl::abi_arg_in<Windows::Media::Core::TimedTextDouble> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutlineRadius(*reinterpret_cast<const Windows::Media::Core::TimedTextDouble *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::ITimedTextSubformat> : produce_base<D, Windows::Media::Core::ITimedTextSubformat>
{
    HRESULT __stdcall get_StartIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartIndex(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Length(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Length(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Length(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubformatStyle(impl::abi_arg_out<Windows::Media::Core::ITimedTextStyle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubformatStyle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SubformatStyle(impl::abi_arg_in<Windows::Media::Core::ITimedTextStyle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SubformatStyle(*reinterpret_cast<const Windows::Media::Core::TimedTextStyle *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IVideoStabilizationEffect> : produce_base<D, Windows::Media::Core::IVideoStabilizationEffect>
{
    HRESULT __stdcall put_Enabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Enabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnabledChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::VideoStabilizationEffect, Windows::Media::Core::VideoStabilizationEffectEnabledChangedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().EnabledChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::VideoStabilizationEffect, Windows::Media::Core::VideoStabilizationEffectEnabledChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnabledChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnabledChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRecommendedStreamConfiguration(impl::abi_arg_in<Windows::Media::Devices::IVideoDeviceController> controller, impl::abi_arg_in<Windows::Media::MediaProperties::IVideoEncodingProperties> desiredProperties, impl::abi_arg_out<Windows::Media::Capture::IVideoStreamConfiguration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetRecommendedStreamConfiguration(*reinterpret_cast<const Windows::Media::Devices::VideoDeviceController *>(&controller), *reinterpret_cast<const Windows::Media::MediaProperties::VideoEncodingProperties *>(&desiredProperties)));
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
struct produce<D, Windows::Media::Core::IVideoStabilizationEffectEnabledChangedEventArgs> : produce_base<D, Windows::Media::Core::IVideoStabilizationEffectEnabledChangedEventArgs>
{
    HRESULT __stdcall get_Reason(Windows::Media::Core::VideoStabilizationEffectEnabledChangedReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IVideoStreamDescriptor> : produce_base<D, Windows::Media::Core::IVideoStreamDescriptor>
{
    HRESULT __stdcall get_EncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IVideoEncodingProperties> encodingProperties) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *encodingProperties = detach_abi(this->shim().EncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *encodingProperties = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IVideoStreamDescriptorFactory> : produce_base<D, Windows::Media::Core::IVideoStreamDescriptorFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Media::MediaProperties::IVideoEncodingProperties> encodingProperties, impl::abi_arg_out<Windows::Media::Core::IVideoStreamDescriptor> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Media::MediaProperties::VideoEncodingProperties *>(&encodingProperties)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IVideoTrack> : produce_base<D, Windows::Media::Core::IVideoTrack>
{
    HRESULT __stdcall add_OpenFailed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Core::VideoTrack, Windows::Media::Core::VideoTrackOpenFailedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().OpenFailed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Core::VideoTrack, Windows::Media::Core::VideoTrackOpenFailedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OpenFailed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OpenFailed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IVideoEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetEncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackItem(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportInfo(impl::abi_arg_out<Windows::Media::Core::IVideoTrackSupportInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportInfo());
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
struct produce<D, Windows::Media::Core::IVideoTrackOpenFailedEventArgs> : produce_base<D, Windows::Media::Core::IVideoTrackOpenFailedEventArgs>
{
    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Core::IVideoTrackSupportInfo> : produce_base<D, Windows::Media::Core::IVideoTrackSupportInfo>
{
    HRESULT __stdcall get_DecoderStatus(Windows::Media::Core::MediaDecoderStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecoderStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaSourceStatus(Windows::Media::Core::MediaSourceStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaSourceStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Core {

template <typename D> bool impl_IMediaStreamDescriptor<D>::IsSelected() const
{
    bool selected {};
    check_hresult(WINRT_SHIM(IMediaStreamDescriptor)->get_IsSelected(&selected));
    return selected;
}

template <typename D> void impl_IMediaStreamDescriptor<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamDescriptor)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_IMediaStreamDescriptor<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaStreamDescriptor)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamDescriptor<D>::Language(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamDescriptor)->put_Language(get_abi(value)));
}

template <typename D> hstring impl_IMediaStreamDescriptor<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaStreamDescriptor)->get_Language(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::AudioEncodingProperties impl_IAudioStreamDescriptor<D>::EncodingProperties() const
{
    Windows::Media::MediaProperties::AudioEncodingProperties encodingProperties { nullptr };
    check_hresult(WINRT_SHIM(IAudioStreamDescriptor)->get_EncodingProperties(put_abi(encodingProperties)));
    return encodingProperties;
}

template <typename D> void impl_IAudioStreamDescriptor2<D>::LeadingEncoderPadding(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IAudioStreamDescriptor2)->put_LeadingEncoderPadding(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IAudioStreamDescriptor2<D>::LeadingEncoderPadding() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IAudioStreamDescriptor2)->get_LeadingEncoderPadding(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioStreamDescriptor2<D>::TrailingEncoderPadding(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IAudioStreamDescriptor2)->put_TrailingEncoderPadding(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IAudioStreamDescriptor2<D>::TrailingEncoderPadding() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IAudioStreamDescriptor2)->get_TrailingEncoderPadding(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::AudioStreamDescriptor impl_IAudioStreamDescriptorFactory<D>::Create(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const
{
    Windows::Media::Core::AudioStreamDescriptor result { nullptr };
    check_hresult(WINRT_SHIM(IAudioStreamDescriptorFactory)->abi_Create(get_abi(encodingProperties), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::MediaProperties::VideoEncodingProperties impl_IVideoStreamDescriptor<D>::EncodingProperties() const
{
    Windows::Media::MediaProperties::VideoEncodingProperties encodingProperties { nullptr };
    check_hresult(WINRT_SHIM(IVideoStreamDescriptor)->get_EncodingProperties(put_abi(encodingProperties)));
    return encodingProperties;
}

template <typename D> Windows::Media::Core::VideoStreamDescriptor impl_IVideoStreamDescriptorFactory<D>::Create(const Windows::Media::MediaProperties::VideoEncodingProperties & encodingProperties) const
{
    Windows::Media::Core::VideoStreamDescriptor result { nullptr };
    check_hresult(WINRT_SHIM(IVideoStreamDescriptorFactory)->abi_Create(get_abi(encodingProperties), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IMediaStreamSource<D>::Closed(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceClosedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaStreamSource)->add_Closed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaStreamSource> impl_IMediaStreamSource<D>::Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceClosedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaStreamSource>(this, &ABI::Windows::Media::Core::IMediaStreamSource::remove_Closed, Closed(handler));
}

template <typename D> void impl_IMediaStreamSource<D>::Closed(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->remove_Closed(token));
}

template <typename D> event_token impl_IMediaStreamSource<D>::Starting(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceStartingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaStreamSource)->add_Starting(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaStreamSource> impl_IMediaStreamSource<D>::Starting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceStartingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaStreamSource>(this, &ABI::Windows::Media::Core::IMediaStreamSource::remove_Starting, Starting(handler));
}

template <typename D> void impl_IMediaStreamSource<D>::Starting(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->remove_Starting(token));
}

template <typename D> event_token impl_IMediaStreamSource<D>::Paused(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaStreamSource)->add_Paused(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaStreamSource> impl_IMediaStreamSource<D>::Paused(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaStreamSource>(this, &ABI::Windows::Media::Core::IMediaStreamSource::remove_Paused, Paused(handler));
}

template <typename D> void impl_IMediaStreamSource<D>::Paused(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->remove_Paused(token));
}

template <typename D> event_token impl_IMediaStreamSource<D>::SampleRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSampleRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaStreamSource)->add_SampleRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaStreamSource> impl_IMediaStreamSource<D>::SampleRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSampleRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaStreamSource>(this, &ABI::Windows::Media::Core::IMediaStreamSource::remove_SampleRequested, SampleRequested(handler));
}

template <typename D> void impl_IMediaStreamSource<D>::SampleRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->remove_SampleRequested(token));
}

template <typename D> event_token impl_IMediaStreamSource<D>::SwitchStreamsRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSwitchStreamsRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaStreamSource)->add_SwitchStreamsRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaStreamSource> impl_IMediaStreamSource<D>::SwitchStreamsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSwitchStreamsRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaStreamSource>(this, &ABI::Windows::Media::Core::IMediaStreamSource::remove_SwitchStreamsRequested, SwitchStreamsRequested(handler));
}

template <typename D> void impl_IMediaStreamSource<D>::SwitchStreamsRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->remove_SwitchStreamsRequested(token));
}

template <typename D> void impl_IMediaStreamSource<D>::NotifyError(Windows::Media::Core::MediaStreamSourceErrorStatus errorStatus) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->abi_NotifyError(errorStatus));
}

template <typename D> void impl_IMediaStreamSource<D>::AddStreamDescriptor(const Windows::Media::Core::IMediaStreamDescriptor & descriptor) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->abi_AddStreamDescriptor(get_abi(descriptor)));
}

template <typename D> void impl_IMediaStreamSource<D>::MediaProtectionManager(const Windows::Media::Protection::MediaProtectionManager & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->put_MediaProtectionManager(get_abi(value)));
}

template <typename D> Windows::Media::Protection::MediaProtectionManager impl_IMediaStreamSource<D>::MediaProtectionManager() const
{
    Windows::Media::Protection::MediaProtectionManager value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSource)->get_MediaProtectionManager(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSource<D>::Duration(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->put_Duration(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaStreamSource<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaStreamSource)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSource<D>::CanSeek(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->put_CanSeek(value));
}

template <typename D> bool impl_IMediaStreamSource<D>::CanSeek() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaStreamSource)->get_CanSeek(&value));
    return value;
}

template <typename D> void impl_IMediaStreamSource<D>::BufferTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->put_BufferTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaStreamSource<D>::BufferTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaStreamSource)->get_BufferTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSource<D>::SetBufferedRange(const Windows::Foundation::TimeSpan & startOffset, const Windows::Foundation::TimeSpan & endOffset) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->abi_SetBufferedRange(get_abi(startOffset), get_abi(endOffset)));
}

template <typename D> Windows::Storage::FileProperties::MusicProperties impl_IMediaStreamSource<D>::MusicProperties() const
{
    Windows::Storage::FileProperties::MusicProperties value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSource)->get_MusicProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::FileProperties::VideoProperties impl_IMediaStreamSource<D>::VideoProperties() const
{
    Windows::Storage::FileProperties::VideoProperties value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSource)->get_VideoProperties(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSource<D>::Thumbnail(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->put_Thumbnail(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IMediaStreamSource<D>::Thumbnail() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IMediaStreamSource)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSource<D>::AddProtectionKey(const Windows::Media::Core::IMediaStreamDescriptor & streamDescriptor, array_view<const uint8_t> keyIdentifier, array_view<const uint8_t> licenseData) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource)->abi_AddProtectionKey(get_abi(streamDescriptor), keyIdentifier.size(), get_abi(keyIdentifier), licenseData.size(), get_abi(licenseData)));
}

template <typename D> event_token impl_IMediaStreamSource2<D>::SampleRendered(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSampleRenderedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaStreamSource2)->add_SampleRendered(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaStreamSource2> impl_IMediaStreamSource2<D>::SampleRendered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSource, Windows::Media::Core::MediaStreamSourceSampleRenderedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaStreamSource2>(this, &ABI::Windows::Media::Core::IMediaStreamSource2::remove_SampleRendered, SampleRendered(handler));
}

template <typename D> void impl_IMediaStreamSource2<D>::SampleRendered(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSource2)->remove_SampleRendered(token));
}

template <typename D> Windows::Media::Core::MediaStreamSource impl_IMediaStreamSourceFactory<D>::CreateFromDescriptor(const Windows::Media::Core::IMediaStreamDescriptor & descriptor) const
{
    Windows::Media::Core::MediaStreamSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceFactory)->abi_CreateFromDescriptor(get_abi(descriptor), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Core::MediaStreamSource impl_IMediaStreamSourceFactory<D>::CreateFromDescriptors(const Windows::Media::Core::IMediaStreamDescriptor & descriptor, const Windows::Media::Core::IMediaStreamDescriptor & descriptor2) const
{
    Windows::Media::Core::MediaStreamSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceFactory)->abi_CreateFromDescriptors(get_abi(descriptor), get_abi(descriptor2), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IMediaStreamSample<D>::Processed(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSample, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaStreamSample)->add_Processed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaStreamSample> impl_IMediaStreamSample<D>::Processed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaStreamSample, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaStreamSample>(this, &ABI::Windows::Media::Core::IMediaStreamSample::remove_Processed, Processed(handler));
}

template <typename D> void impl_IMediaStreamSample<D>::Processed(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSample)->remove_Processed(token));
}

template <typename D> Windows::Storage::Streams::Buffer impl_IMediaStreamSample<D>::Buffer() const
{
    Windows::Storage::Streams::Buffer value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSample)->get_Buffer(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaStreamSample<D>::Timestamp() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaStreamSample)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSamplePropertySet impl_IMediaStreamSample<D>::ExtendedProperties() const
{
    Windows::Media::Core::MediaStreamSamplePropertySet value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSample)->get_ExtendedProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSampleProtectionProperties impl_IMediaStreamSample<D>::Protection() const
{
    Windows::Media::Core::MediaStreamSampleProtectionProperties value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSample)->get_Protection(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSample<D>::DecodeTimestamp(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSample)->put_DecodeTimestamp(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaStreamSample<D>::DecodeTimestamp() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaStreamSample)->get_DecodeTimestamp(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSample<D>::Duration(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSample)->put_Duration(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaStreamSample<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaStreamSample)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSample<D>::KeyFrame(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSample)->put_KeyFrame(value));
}

template <typename D> bool impl_IMediaStreamSample<D>::KeyFrame() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaStreamSample)->get_KeyFrame(&value));
    return value;
}

template <typename D> void impl_IMediaStreamSample<D>::Discontinuous(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSample)->put_Discontinuous(value));
}

template <typename D> bool impl_IMediaStreamSample<D>::Discontinuous() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaStreamSample)->get_Discontinuous(&value));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSample impl_IMediaStreamSampleStatics<D>::CreateFromBuffer(const Windows::Storage::Streams::IBuffer & buffer, const Windows::Foundation::TimeSpan & timestamp) const
{
    Windows::Media::Core::MediaStreamSample value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSampleStatics)->abi_CreateFromBuffer(get_abi(buffer), get_abi(timestamp), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Core::MediaStreamSample> impl_IMediaStreamSampleStatics<D>::CreateFromStreamAsync(const Windows::Storage::Streams::IInputStream & stream, uint32_t count, const Windows::Foundation::TimeSpan & timestamp) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Core::MediaStreamSample> value;
    check_hresult(WINRT_SHIM(IMediaStreamSampleStatics)->abi_CreateFromStreamAsync(get_abi(stream), count, get_abi(timestamp), put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSampleProtectionProperties<D>::SetKeyIdentifier(array_view<const uint8_t> value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSampleProtectionProperties)->abi_SetKeyIdentifier(value.size(), get_abi(value)));
}

template <typename D> void impl_IMediaStreamSampleProtectionProperties<D>::GetKeyIdentifier(com_array<uint8_t> & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSampleProtectionProperties)->abi_GetKeyIdentifier(impl::put_size_abi(value), put_abi(value)));
}

template <typename D> void impl_IMediaStreamSampleProtectionProperties<D>::SetInitializationVector(array_view<const uint8_t> value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSampleProtectionProperties)->abi_SetInitializationVector(value.size(), get_abi(value)));
}

template <typename D> void impl_IMediaStreamSampleProtectionProperties<D>::GetInitializationVector(com_array<uint8_t> & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSampleProtectionProperties)->abi_GetInitializationVector(impl::put_size_abi(value), put_abi(value)));
}

template <typename D> void impl_IMediaStreamSampleProtectionProperties<D>::SetSubSampleMapping(array_view<const uint8_t> value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSampleProtectionProperties)->abi_SetSubSampleMapping(value.size(), get_abi(value)));
}

template <typename D> void impl_IMediaStreamSampleProtectionProperties<D>::GetSubSampleMapping(com_array<uint8_t> & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSampleProtectionProperties)->abi_GetSubSampleMapping(impl::put_size_abi(value), put_abi(value)));
}

template <typename D> Windows::Media::Core::MediaStreamSourceClosedReason impl_IMediaStreamSourceClosedRequest<D>::Reason() const
{
    Windows::Media::Core::MediaStreamSourceClosedReason value {};
    check_hresult(WINRT_SHIM(IMediaStreamSourceClosedRequest)->get_Reason(&value));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSourceClosedRequest impl_IMediaStreamSourceClosedEventArgs<D>::Request() const
{
    Windows::Media::Core::MediaStreamSourceClosedRequest value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceClosedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSourceStartingRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IMediaStreamSourceStartingRequestDeferral)->abi_Complete());
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMediaStreamSourceStartingRequest<D>::StartPosition() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMediaStreamSourceStartingRequest)->get_StartPosition(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSourceStartingRequestDeferral impl_IMediaStreamSourceStartingRequest<D>::GetDeferral() const
{
    Windows::Media::Core::MediaStreamSourceStartingRequestDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceStartingRequest)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> void impl_IMediaStreamSourceStartingRequest<D>::SetActualStartPosition(const Windows::Foundation::TimeSpan & position) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSourceStartingRequest)->abi_SetActualStartPosition(get_abi(position)));
}

template <typename D> Windows::Media::Core::MediaStreamSourceStartingRequest impl_IMediaStreamSourceStartingEventArgs<D>::Request() const
{
    Windows::Media::Core::MediaStreamSourceStartingRequest value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceStartingEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSourceSampleRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IMediaStreamSourceSampleRequestDeferral)->abi_Complete());
}

template <typename D> Windows::Media::Core::IMediaStreamDescriptor impl_IMediaStreamSourceSampleRequest<D>::StreamDescriptor() const
{
    Windows::Media::Core::IMediaStreamDescriptor value;
    check_hresult(WINRT_SHIM(IMediaStreamSourceSampleRequest)->get_StreamDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSourceSampleRequestDeferral impl_IMediaStreamSourceSampleRequest<D>::GetDeferral() const
{
    Windows::Media::Core::MediaStreamSourceSampleRequestDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceSampleRequest)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> void impl_IMediaStreamSourceSampleRequest<D>::Sample(const Windows::Media::Core::MediaStreamSample & value) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSourceSampleRequest)->put_Sample(get_abi(value)));
}

template <typename D> Windows::Media::Core::MediaStreamSample impl_IMediaStreamSourceSampleRequest<D>::Sample() const
{
    Windows::Media::Core::MediaStreamSample value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceSampleRequest)->get_Sample(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSourceSampleRequest<D>::ReportSampleProgress(uint32_t progress) const
{
    check_hresult(WINRT_SHIM(IMediaStreamSourceSampleRequest)->abi_ReportSampleProgress(progress));
}

template <typename D> Windows::Media::Core::MediaStreamSourceSampleRequest impl_IMediaStreamSourceSampleRequestedEventArgs<D>::Request() const
{
    Windows::Media::Core::MediaStreamSourceSampleRequest value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceSampleRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaStreamSourceSwitchStreamsRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IMediaStreamSourceSwitchStreamsRequestDeferral)->abi_Complete());
}

template <typename D> Windows::Media::Core::IMediaStreamDescriptor impl_IMediaStreamSourceSwitchStreamsRequest<D>::OldStreamDescriptor() const
{
    Windows::Media::Core::IMediaStreamDescriptor value;
    check_hresult(WINRT_SHIM(IMediaStreamSourceSwitchStreamsRequest)->get_OldStreamDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::IMediaStreamDescriptor impl_IMediaStreamSourceSwitchStreamsRequest<D>::NewStreamDescriptor() const
{
    Windows::Media::Core::IMediaStreamDescriptor value;
    check_hresult(WINRT_SHIM(IMediaStreamSourceSwitchStreamsRequest)->get_NewStreamDescriptor(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaStreamSourceSwitchStreamsRequestDeferral impl_IMediaStreamSourceSwitchStreamsRequest<D>::GetDeferral() const
{
    Windows::Media::Core::MediaStreamSourceSwitchStreamsRequestDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceSwitchStreamsRequest)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> Windows::Media::Core::MediaStreamSourceSwitchStreamsRequest impl_IMediaStreamSourceSwitchStreamsRequestedEventArgs<D>::Request() const
{
    Windows::Media::Core::MediaStreamSourceSwitchStreamsRequest value { nullptr };
    check_hresult(WINRT_SHIM(IMediaStreamSourceSwitchStreamsRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaStreamSourceSampleRenderedEventArgs<D>::SampleLag() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaStreamSourceSampleRenderedEventArgs)->get_SampleLag(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMseStreamSourceStatics<D>::IsContentTypeSupported(hstring_view contentType) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMseStreamSourceStatics)->abi_IsContentTypeSupported(get_abi(contentType), &value));
    return value;
}

template <typename D> event_token impl_IMseStreamSource<D>::Opened(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseStreamSource)->add_Opened(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseStreamSource> impl_IMseStreamSource<D>::Opened(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseStreamSource>(this, &ABI::Windows::Media::Core::IMseStreamSource::remove_Opened, Opened(handler));
}

template <typename D> void impl_IMseStreamSource<D>::Opened(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseStreamSource)->remove_Opened(token));
}

template <typename D> event_token impl_IMseStreamSource<D>::Ended(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseStreamSource)->add_Ended(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseStreamSource> impl_IMseStreamSource<D>::Ended(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseStreamSource>(this, &ABI::Windows::Media::Core::IMseStreamSource::remove_Ended, Ended(handler));
}

template <typename D> void impl_IMseStreamSource<D>::Ended(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseStreamSource)->remove_Ended(token));
}

template <typename D> event_token impl_IMseStreamSource<D>::Closed(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseStreamSource)->add_Closed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseStreamSource> impl_IMseStreamSource<D>::Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseStreamSource, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseStreamSource>(this, &ABI::Windows::Media::Core::IMseStreamSource::remove_Closed, Closed(handler));
}

template <typename D> void impl_IMseStreamSource<D>::Closed(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseStreamSource)->remove_Closed(token));
}

template <typename D> Windows::Media::Core::MseSourceBufferList impl_IMseStreamSource<D>::SourceBuffers() const
{
    Windows::Media::Core::MseSourceBufferList value { nullptr };
    check_hresult(WINRT_SHIM(IMseStreamSource)->get_SourceBuffers(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MseSourceBufferList impl_IMseStreamSource<D>::ActiveSourceBuffers() const
{
    Windows::Media::Core::MseSourceBufferList value { nullptr };
    check_hresult(WINRT_SHIM(IMseStreamSource)->get_ActiveSourceBuffers(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MseReadyState impl_IMseStreamSource<D>::ReadyState() const
{
    Windows::Media::Core::MseReadyState value {};
    check_hresult(WINRT_SHIM(IMseStreamSource)->get_ReadyState(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMseStreamSource<D>::Duration() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMseStreamSource)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IMseStreamSource<D>::Duration(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IMseStreamSource)->put_Duration(get_abi(value)));
}

template <typename D> Windows::Media::Core::MseSourceBuffer impl_IMseStreamSource<D>::AddSourceBuffer(hstring_view mimeType) const
{
    Windows::Media::Core::MseSourceBuffer buffer { nullptr };
    check_hresult(WINRT_SHIM(IMseStreamSource)->abi_AddSourceBuffer(get_abi(mimeType), put_abi(buffer)));
    return buffer;
}

template <typename D> void impl_IMseStreamSource<D>::RemoveSourceBuffer(const Windows::Media::Core::MseSourceBuffer & buffer) const
{
    check_hresult(WINRT_SHIM(IMseStreamSource)->abi_RemoveSourceBuffer(get_abi(buffer)));
}

template <typename D> void impl_IMseStreamSource<D>::EndOfStream(Windows::Media::Core::MseEndOfStreamStatus status) const
{
    check_hresult(WINRT_SHIM(IMseStreamSource)->abi_EndOfStream(status));
}

template <typename D> event_token impl_IMseSourceBuffer<D>::UpdateStarting(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->add_UpdateStarting(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseSourceBuffer> impl_IMseSourceBuffer<D>::UpdateStarting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseSourceBuffer>(this, &ABI::Windows::Media::Core::IMseSourceBuffer::remove_UpdateStarting, UpdateStarting(handler));
}

template <typename D> void impl_IMseSourceBuffer<D>::UpdateStarting(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->remove_UpdateStarting(token));
}

template <typename D> event_token impl_IMseSourceBuffer<D>::Updated(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->add_Updated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseSourceBuffer> impl_IMseSourceBuffer<D>::Updated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseSourceBuffer>(this, &ABI::Windows::Media::Core::IMseSourceBuffer::remove_Updated, Updated(handler));
}

template <typename D> void impl_IMseSourceBuffer<D>::Updated(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->remove_Updated(token));
}

template <typename D> event_token impl_IMseSourceBuffer<D>::UpdateEnded(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->add_UpdateEnded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseSourceBuffer> impl_IMseSourceBuffer<D>::UpdateEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseSourceBuffer>(this, &ABI::Windows::Media::Core::IMseSourceBuffer::remove_UpdateEnded, UpdateEnded(handler));
}

template <typename D> void impl_IMseSourceBuffer<D>::UpdateEnded(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->remove_UpdateEnded(token));
}

template <typename D> event_token impl_IMseSourceBuffer<D>::ErrorOccurred(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->add_ErrorOccurred(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseSourceBuffer> impl_IMseSourceBuffer<D>::ErrorOccurred(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseSourceBuffer>(this, &ABI::Windows::Media::Core::IMseSourceBuffer::remove_ErrorOccurred, ErrorOccurred(handler));
}

template <typename D> void impl_IMseSourceBuffer<D>::ErrorOccurred(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->remove_ErrorOccurred(token));
}

template <typename D> event_token impl_IMseSourceBuffer<D>::Aborted(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->add_Aborted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseSourceBuffer> impl_IMseSourceBuffer<D>::Aborted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBuffer, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseSourceBuffer>(this, &ABI::Windows::Media::Core::IMseSourceBuffer::remove_Aborted, Aborted(handler));
}

template <typename D> void impl_IMseSourceBuffer<D>::Aborted(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->remove_Aborted(token));
}

template <typename D> Windows::Media::Core::MseAppendMode impl_IMseSourceBuffer<D>::Mode() const
{
    Windows::Media::Core::MseAppendMode value {};
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->get_Mode(&value));
    return value;
}

template <typename D> void impl_IMseSourceBuffer<D>::Mode(Windows::Media::Core::MseAppendMode value) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->put_Mode(value));
}

template <typename D> bool impl_IMseSourceBuffer<D>::IsUpdating() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->get_IsUpdating(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Core::MseTimeRange> impl_IMseSourceBuffer<D>::Buffered() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Core::MseTimeRange> value;
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->get_Buffered(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMseSourceBuffer<D>::TimestampOffset() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->get_TimestampOffset(put_abi(value)));
    return value;
}

template <typename D> void impl_IMseSourceBuffer<D>::TimestampOffset(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->put_TimestampOffset(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMseSourceBuffer<D>::AppendWindowStart() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->get_AppendWindowStart(put_abi(value)));
    return value;
}

template <typename D> void impl_IMseSourceBuffer<D>::AppendWindowStart(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->put_AppendWindowStart(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMseSourceBuffer<D>::AppendWindowEnd() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->get_AppendWindowEnd(put_abi(value)));
    return value;
}

template <typename D> void impl_IMseSourceBuffer<D>::AppendWindowEnd(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->put_AppendWindowEnd(get_abi(value)));
}

template <typename D> void impl_IMseSourceBuffer<D>::AppendBuffer(const Windows::Storage::Streams::IBuffer & buffer) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->abi_AppendBuffer(get_abi(buffer)));
}

template <typename D> void impl_IMseSourceBuffer<D>::AppendStream(const Windows::Storage::Streams::IInputStream & stream) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->abi_AppendStream(get_abi(stream)));
}

template <typename D> void impl_IMseSourceBuffer<D>::AppendStream(const Windows::Storage::Streams::IInputStream & stream, uint64_t maxSize) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->abi_AppendStreamMaxSize(get_abi(stream), maxSize));
}

template <typename D> void impl_IMseSourceBuffer<D>::Abort() const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->abi_Abort());
}

template <typename D> void impl_IMseSourceBuffer<D>::Remove(const Windows::Foundation::TimeSpan & start, const optional<Windows::Foundation::TimeSpan> & end) const
{
    check_hresult(WINRT_SHIM(IMseSourceBuffer)->abi_Remove(get_abi(start), get_abi(end)));
}

template <typename D> event_token impl_IMseSourceBufferList<D>::SourceBufferAdded(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBufferList, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseSourceBufferList)->add_SourceBufferAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseSourceBufferList> impl_IMseSourceBufferList<D>::SourceBufferAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBufferList, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseSourceBufferList>(this, &ABI::Windows::Media::Core::IMseSourceBufferList::remove_SourceBufferAdded, SourceBufferAdded(handler));
}

template <typename D> void impl_IMseSourceBufferList<D>::SourceBufferAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseSourceBufferList)->remove_SourceBufferAdded(token));
}

template <typename D> event_token impl_IMseSourceBufferList<D>::SourceBufferRemoved(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBufferList, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMseSourceBufferList)->add_SourceBufferRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMseSourceBufferList> impl_IMseSourceBufferList<D>::SourceBufferRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MseSourceBufferList, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMseSourceBufferList>(this, &ABI::Windows::Media::Core::IMseSourceBufferList::remove_SourceBufferRemoved, SourceBufferRemoved(handler));
}

template <typename D> void impl_IMseSourceBufferList<D>::SourceBufferRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IMseSourceBufferList)->remove_SourceBufferRemoved(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Core::MseSourceBuffer> impl_IMseSourceBufferList<D>::Buffers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Core::MseSourceBuffer> value;
    check_hresult(WINRT_SHIM(IMseSourceBufferList)->get_Buffers(put_abi(value)));
    return value;
}

template <typename D> void impl_IHighDynamicRangeControl<D>::Enabled(bool value) const
{
    check_hresult(WINRT_SHIM(IHighDynamicRangeControl)->put_Enabled(value));
}

template <typename D> bool impl_IHighDynamicRangeControl<D>::Enabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHighDynamicRangeControl)->get_Enabled(&value));
    return value;
}

template <typename D> Windows::Media::Core::HighDynamicRangeControl impl_ISceneAnalysisEffect<D>::HighDynamicRangeAnalyzer() const
{
    Windows::Media::Core::HighDynamicRangeControl value { nullptr };
    check_hresult(WINRT_SHIM(ISceneAnalysisEffect)->get_HighDynamicRangeAnalyzer(put_abi(value)));
    return value;
}

template <typename D> void impl_ISceneAnalysisEffect<D>::DesiredAnalysisInterval(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISceneAnalysisEffect)->put_DesiredAnalysisInterval(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ISceneAnalysisEffect<D>::DesiredAnalysisInterval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISceneAnalysisEffect)->get_DesiredAnalysisInterval(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ISceneAnalysisEffect<D>::SceneAnalyzed(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::SceneAnalysisEffect, Windows::Media::Core::SceneAnalyzedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ISceneAnalysisEffect)->add_SceneAnalyzed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ISceneAnalysisEffect> impl_ISceneAnalysisEffect<D>::SceneAnalyzed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::SceneAnalysisEffect, Windows::Media::Core::SceneAnalyzedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISceneAnalysisEffect>(this, &ABI::Windows::Media::Core::ISceneAnalysisEffect::remove_SceneAnalyzed, SceneAnalyzed(handler));
}

template <typename D> void impl_ISceneAnalysisEffect<D>::SceneAnalyzed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ISceneAnalysisEffect)->remove_SceneAnalyzed(cookie));
}

template <typename D> double impl_IHighDynamicRangeOutput<D>::Certainty() const
{
    double value {};
    check_hresult(WINRT_SHIM(IHighDynamicRangeOutput)->get_Certainty(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Devices::Core::FrameController> impl_IHighDynamicRangeOutput<D>::FrameControllers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Devices::Core::FrameController> value;
    check_hresult(WINRT_SHIM(IHighDynamicRangeOutput)->get_FrameControllers(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Capture::CapturedFrameControlValues impl_ISceneAnalysisEffectFrame<D>::FrameControlValues() const
{
    Windows::Media::Capture::CapturedFrameControlValues value { nullptr };
    check_hresult(WINRT_SHIM(ISceneAnalysisEffectFrame)->get_FrameControlValues(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::HighDynamicRangeOutput impl_ISceneAnalysisEffectFrame<D>::HighDynamicRange() const
{
    Windows::Media::Core::HighDynamicRangeOutput value { nullptr };
    check_hresult(WINRT_SHIM(ISceneAnalysisEffectFrame)->get_HighDynamicRange(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::SceneAnalysisEffectFrame impl_ISceneAnalyzedEventArgs<D>::ResultFrame() const
{
    Windows::Media::Core::SceneAnalysisEffectFrame value { nullptr };
    check_hresult(WINRT_SHIM(ISceneAnalyzedEventArgs)->get_ResultFrame(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::FaceAnalysis::DetectedFace> impl_IFaceDetectionEffectFrame<D>::DetectedFaces() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::FaceAnalysis::DetectedFace> value;
    check_hresult(WINRT_SHIM(IFaceDetectionEffectFrame)->get_DetectedFaces(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::FaceDetectionEffectFrame impl_IFaceDetectedEventArgs<D>::ResultFrame() const
{
    Windows::Media::Core::FaceDetectionEffectFrame value { nullptr };
    check_hresult(WINRT_SHIM(IFaceDetectedEventArgs)->get_ResultFrame(put_abi(value)));
    return value;
}

template <typename D> void impl_IFaceDetectionEffect<D>::Enabled(bool value) const
{
    check_hresult(WINRT_SHIM(IFaceDetectionEffect)->put_Enabled(value));
}

template <typename D> bool impl_IFaceDetectionEffect<D>::Enabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFaceDetectionEffect)->get_Enabled(&value));
    return value;
}

template <typename D> void impl_IFaceDetectionEffect<D>::DesiredDetectionInterval(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IFaceDetectionEffect)->put_DesiredDetectionInterval(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IFaceDetectionEffect<D>::DesiredDetectionInterval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IFaceDetectionEffect)->get_DesiredDetectionInterval(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IFaceDetectionEffect<D>::FaceDetected(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::FaceDetectionEffect, Windows::Media::Core::FaceDetectedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IFaceDetectionEffect)->add_FaceDetected(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IFaceDetectionEffect> impl_IFaceDetectionEffect<D>::FaceDetected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::FaceDetectionEffect, Windows::Media::Core::FaceDetectedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IFaceDetectionEffect>(this, &ABI::Windows::Media::Core::IFaceDetectionEffect::remove_FaceDetected, FaceDetected(handler));
}

template <typename D> void impl_IFaceDetectionEffect<D>::FaceDetected(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IFaceDetectionEffect)->remove_FaceDetected(cookie));
}

template <typename D> void impl_IFaceDetectionEffectDefinition<D>::DetectionMode(Windows::Media::Core::FaceDetectionMode value) const
{
    check_hresult(WINRT_SHIM(IFaceDetectionEffectDefinition)->put_DetectionMode(value));
}

template <typename D> Windows::Media::Core::FaceDetectionMode impl_IFaceDetectionEffectDefinition<D>::DetectionMode() const
{
    Windows::Media::Core::FaceDetectionMode value {};
    check_hresult(WINRT_SHIM(IFaceDetectionEffectDefinition)->get_DetectionMode(&value));
    return value;
}

template <typename D> void impl_IFaceDetectionEffectDefinition<D>::SynchronousDetectionEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IFaceDetectionEffectDefinition)->put_SynchronousDetectionEnabled(value));
}

template <typename D> bool impl_IFaceDetectionEffectDefinition<D>::SynchronousDetectionEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFaceDetectionEffectDefinition)->get_SynchronousDetectionEnabled(&value));
    return value;
}

template <typename D> Windows::Media::Core::VideoStabilizationEffectEnabledChangedReason impl_IVideoStabilizationEffectEnabledChangedEventArgs<D>::Reason() const
{
    Windows::Media::Core::VideoStabilizationEffectEnabledChangedReason value {};
    check_hresult(WINRT_SHIM(IVideoStabilizationEffectEnabledChangedEventArgs)->get_Reason(&value));
    return value;
}

template <typename D> void impl_IVideoStabilizationEffect<D>::Enabled(bool value) const
{
    check_hresult(WINRT_SHIM(IVideoStabilizationEffect)->put_Enabled(value));
}

template <typename D> bool impl_IVideoStabilizationEffect<D>::Enabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVideoStabilizationEffect)->get_Enabled(&value));
    return value;
}

template <typename D> event_token impl_IVideoStabilizationEffect<D>::EnabledChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::VideoStabilizationEffect, Windows::Media::Core::VideoStabilizationEffectEnabledChangedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IVideoStabilizationEffect)->add_EnabledChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IVideoStabilizationEffect> impl_IVideoStabilizationEffect<D>::EnabledChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::VideoStabilizationEffect, Windows::Media::Core::VideoStabilizationEffectEnabledChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVideoStabilizationEffect>(this, &ABI::Windows::Media::Core::IVideoStabilizationEffect::remove_EnabledChanged, EnabledChanged(handler));
}

template <typename D> void impl_IVideoStabilizationEffect<D>::EnabledChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IVideoStabilizationEffect)->remove_EnabledChanged(cookie));
}

template <typename D> Windows::Media::Capture::VideoStreamConfiguration impl_IVideoStabilizationEffect<D>::GetRecommendedStreamConfiguration(const Windows::Media::Devices::VideoDeviceController & controller, const Windows::Media::MediaProperties::VideoEncodingProperties & desiredProperties) const
{
    Windows::Media::Capture::VideoStreamConfiguration value { nullptr };
    check_hresult(WINRT_SHIM(IVideoStabilizationEffect)->abi_GetRecommendedStreamConfiguration(get_abi(controller), get_abi(desiredProperties), put_abi(value)));
    return value;
}

template <typename D> HRESULT impl_IMediaSourceError<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IMediaSourceError)->get_ExtendedError(&value));
    return value;
}

template <typename D> Windows::Media::Core::MediaSourceError impl_IMediaSourceOpenOperationCompletedEventArgs<D>::Error() const
{
    Windows::Media::Core::MediaSourceError value { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceOpenOperationCompletedEventArgs)->get_Error(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaSourceState impl_IMediaSourceStateChangedEventArgs<D>::OldState() const
{
    Windows::Media::Core::MediaSourceState value {};
    check_hresult(WINRT_SHIM(IMediaSourceStateChangedEventArgs)->get_OldState(&value));
    return value;
}

template <typename D> Windows::Media::Core::MediaSourceState impl_IMediaSourceStateChangedEventArgs<D>::NewState() const
{
    Windows::Media::Core::MediaSourceState value {};
    check_hresult(WINRT_SHIM(IMediaSourceStateChangedEventArgs)->get_NewState(&value));
    return value;
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaSourceStatics<D>::CreateFromAdaptiveMediaSource(const Windows::Media::Streaming::Adaptive::AdaptiveMediaSource & mediaSource) const
{
    Windows::Media::Core::MediaSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceStatics)->abi_CreateFromAdaptiveMediaSource(get_abi(mediaSource), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaSourceStatics<D>::CreateFromMediaStreamSource(const Windows::Media::Core::MediaStreamSource & mediaSource) const
{
    Windows::Media::Core::MediaSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceStatics)->abi_CreateFromMediaStreamSource(get_abi(mediaSource), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaSourceStatics<D>::CreateFromMseStreamSource(const Windows::Media::Core::MseStreamSource & mediaSource) const
{
    Windows::Media::Core::MediaSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceStatics)->abi_CreateFromMseStreamSource(get_abi(mediaSource), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaSourceStatics<D>::CreateFromIMediaSource(const Windows::Media::Core::IMediaSource & mediaSource) const
{
    Windows::Media::Core::MediaSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceStatics)->abi_CreateFromIMediaSource(get_abi(mediaSource), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaSourceStatics<D>::CreateFromStorageFile(const Windows::Storage::IStorageFile & file) const
{
    Windows::Media::Core::MediaSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceStatics)->abi_CreateFromStorageFile(get_abi(file), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaSourceStatics<D>::CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream, hstring_view contentType) const
{
    Windows::Media::Core::MediaSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceStatics)->abi_CreateFromStream(get_abi(stream), get_abi(contentType), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaSourceStatics<D>::CreateFromStreamReference(const Windows::Storage::Streams::IRandomAccessStreamReference & stream, hstring_view contentType) const
{
    Windows::Media::Core::MediaSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceStatics)->abi_CreateFromStreamReference(get_abi(stream), get_abi(contentType), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaSourceStatics<D>::CreateFromUri(const Windows::Foundation::Uri & uri) const
{
    Windows::Media::Core::MediaSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceStatics)->abi_CreateFromUri(get_abi(uri), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaSourceStatics2<D>::CreateFromMediaBinder(const Windows::Media::Core::MediaBinder & binder) const
{
    Windows::Media::Core::MediaSource result { nullptr };
    check_hresult(WINRT_SHIM(IMediaSourceStatics2)->abi_CreateFromMediaBinder(get_abi(binder), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IMediaBinder<D>::Binding(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaBinder, Windows::Media::Core::MediaBindingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaBinder)->add_Binding(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaBinder> impl_IMediaBinder<D>::Binding(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaBinder, Windows::Media::Core::MediaBindingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaBinder>(this, &ABI::Windows::Media::Core::IMediaBinder::remove_Binding, Binding(handler));
}

template <typename D> void impl_IMediaBinder<D>::Binding(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaBinder)->remove_Binding(token));
}

template <typename D> hstring impl_IMediaBinder<D>::Token() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaBinder)->get_Token(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaBinder<D>::Token(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMediaBinder)->put_Token(get_abi(value)));
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaBinder<D>::Source() const
{
    Windows::Media::Core::MediaSource value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBinder)->get_Source(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMediaBindingEventArgs<D>::Canceled(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaBindingEventArgs, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaBindingEventArgs)->add_Canceled(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaBindingEventArgs> impl_IMediaBindingEventArgs<D>::Canceled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaBindingEventArgs, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaBindingEventArgs>(this, &ABI::Windows::Media::Core::IMediaBindingEventArgs::remove_Canceled, Canceled(handler));
}

template <typename D> void impl_IMediaBindingEventArgs<D>::Canceled(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaBindingEventArgs)->remove_Canceled(token));
}

template <typename D> Windows::Media::Core::MediaBinder impl_IMediaBindingEventArgs<D>::MediaBinder() const
{
    Windows::Media::Core::MediaBinder value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBindingEventArgs)->get_MediaBinder(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IMediaBindingEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IMediaBindingEventArgs)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> void impl_IMediaBindingEventArgs<D>::SetUri(const Windows::Foundation::Uri & uri) const
{
    check_hresult(WINRT_SHIM(IMediaBindingEventArgs)->abi_SetUri(get_abi(uri)));
}

template <typename D> void impl_IMediaBindingEventArgs<D>::SetStream(const Windows::Storage::Streams::IRandomAccessStream & stream, hstring_view contentType) const
{
    check_hresult(WINRT_SHIM(IMediaBindingEventArgs)->abi_SetStream(get_abi(stream), get_abi(contentType)));
}

template <typename D> void impl_IMediaBindingEventArgs<D>::SetStreamReference(const Windows::Storage::Streams::IRandomAccessStreamReference & stream, hstring_view contentType) const
{
    check_hresult(WINRT_SHIM(IMediaBindingEventArgs)->abi_SetStreamReference(get_abi(stream), get_abi(contentType)));
}

template <typename D> event_token impl_IMediaSource2<D>::OpenOperationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaSource, Windows::Media::Core::MediaSourceOpenOperationCompletedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaSource2)->add_OpenOperationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaSource2> impl_IMediaSource2<D>::OpenOperationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaSource, Windows::Media::Core::MediaSourceOpenOperationCompletedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaSource2>(this, &ABI::Windows::Media::Core::IMediaSource2::remove_OpenOperationCompleted, OpenOperationCompleted(handler));
}

template <typename D> void impl_IMediaSource2<D>::OpenOperationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaSource2)->remove_OpenOperationCompleted(token));
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IMediaSource2<D>::CustomProperties() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IMediaSource2)->get_CustomProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMediaSource2<D>::Duration() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMediaSource2)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaSource2<D>::IsOpen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaSource2)->get_IsOpen(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IObservableVector<Windows::Media::Core::TimedTextSource> impl_IMediaSource2<D>::ExternalTimedTextSources() const
{
    Windows::Foundation::Collections::IObservableVector<Windows::Media::Core::TimedTextSource> value;
    check_hresult(WINRT_SHIM(IMediaSource2)->get_ExternalTimedTextSources(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IObservableVector<Windows::Media::Core::TimedMetadataTrack> impl_IMediaSource2<D>::ExternalTimedMetadataTracks() const
{
    Windows::Foundation::Collections::IObservableVector<Windows::Media::Core::TimedMetadataTrack> value;
    check_hresult(WINRT_SHIM(IMediaSource2)->get_ExternalTimedMetadataTracks(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMediaSource3<D>::StateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaSource, Windows::Media::Core::MediaSourceStateChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaSource3)->add_StateChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaSource3> impl_IMediaSource3<D>::StateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::MediaSource, Windows::Media::Core::MediaSourceStateChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaSource3>(this, &ABI::Windows::Media::Core::IMediaSource3::remove_StateChanged, StateChanged(handler));
}

template <typename D> void impl_IMediaSource3<D>::StateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaSource3)->remove_StateChanged(token));
}

template <typename D> Windows::Media::Core::MediaSourceState impl_IMediaSource3<D>::State() const
{
    Windows::Media::Core::MediaSourceState value {};
    check_hresult(WINRT_SHIM(IMediaSource3)->get_State(&value));
    return value;
}

template <typename D> void impl_IMediaSource3<D>::Reset() const
{
    check_hresult(WINRT_SHIM(IMediaSource3)->abi_Reset());
}

template <typename D> void impl_IMediaCue<D>::StartTime(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaCue)->put_StartTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaCue<D>::StartTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaCue)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCue<D>::Duration(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaCue)->put_Duration(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaCue<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaCue)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaCue<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMediaCue)->put_Id(get_abi(value)));
}

template <typename D> hstring impl_IMediaCue<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaCue)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::TimedTextRegion impl_ITimedTextCue<D>::CueRegion() const
{
    Windows::Media::Core::TimedTextRegion value { nullptr };
    check_hresult(WINRT_SHIM(ITimedTextCue)->get_CueRegion(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextCue<D>::CueRegion(const Windows::Media::Core::TimedTextRegion & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextCue)->put_CueRegion(get_abi(value)));
}

template <typename D> Windows::Media::Core::TimedTextStyle impl_ITimedTextCue<D>::CueStyle() const
{
    Windows::Media::Core::TimedTextStyle value { nullptr };
    check_hresult(WINRT_SHIM(ITimedTextCue)->get_CueStyle(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextCue<D>::CueStyle(const Windows::Media::Core::TimedTextStyle & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextCue)->put_CueStyle(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Core::TimedTextLine> impl_ITimedTextCue<D>::Lines() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Core::TimedTextLine> value;
    check_hresult(WINRT_SHIM(ITimedTextCue)->get_Lines(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ITimedTextRegion<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_Name(get_abi(value)));
}

template <typename D> Windows::Media::Core::TimedTextPoint impl_ITimedTextRegion<D>::Position() const
{
    Windows::Media::Core::TimedTextPoint value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::Position(const Windows::Media::Core::TimedTextPoint & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_Position(get_abi(value)));
}

template <typename D> Windows::Media::Core::TimedTextSize impl_ITimedTextRegion<D>::Extent() const
{
    Windows::Media::Core::TimedTextSize value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_Extent(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::Extent(const Windows::Media::Core::TimedTextSize & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_Extent(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_ITimedTextRegion<D>::Background() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_Background(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::Background(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_Background(get_abi(value)));
}

template <typename D> Windows::Media::Core::TimedTextWritingMode impl_ITimedTextRegion<D>::WritingMode() const
{
    Windows::Media::Core::TimedTextWritingMode value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_WritingMode(&value));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::WritingMode(Windows::Media::Core::TimedTextWritingMode value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_WritingMode(value));
}

template <typename D> Windows::Media::Core::TimedTextDisplayAlignment impl_ITimedTextRegion<D>::DisplayAlignment() const
{
    Windows::Media::Core::TimedTextDisplayAlignment value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_DisplayAlignment(&value));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::DisplayAlignment(Windows::Media::Core::TimedTextDisplayAlignment value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_DisplayAlignment(value));
}

template <typename D> Windows::Media::Core::TimedTextDouble impl_ITimedTextRegion<D>::LineHeight() const
{
    Windows::Media::Core::TimedTextDouble value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_LineHeight(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::LineHeight(const Windows::Media::Core::TimedTextDouble & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_LineHeight(get_abi(value)));
}

template <typename D> bool impl_ITimedTextRegion<D>::IsOverflowClipped() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_IsOverflowClipped(&value));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::IsOverflowClipped(bool value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_IsOverflowClipped(value));
}

template <typename D> Windows::Media::Core::TimedTextPadding impl_ITimedTextRegion<D>::Padding() const
{
    Windows::Media::Core::TimedTextPadding value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_Padding(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::Padding(const Windows::Media::Core::TimedTextPadding & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_Padding(get_abi(value)));
}

template <typename D> Windows::Media::Core::TimedTextWrapping impl_ITimedTextRegion<D>::TextWrapping() const
{
    Windows::Media::Core::TimedTextWrapping value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_TextWrapping(&value));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::TextWrapping(Windows::Media::Core::TimedTextWrapping value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_TextWrapping(value));
}

template <typename D> int32_t impl_ITimedTextRegion<D>::ZIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_ZIndex(&value));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::ZIndex(int32_t value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_ZIndex(value));
}

template <typename D> Windows::Media::Core::TimedTextScrollMode impl_ITimedTextRegion<D>::ScrollMode() const
{
    Windows::Media::Core::TimedTextScrollMode value {};
    check_hresult(WINRT_SHIM(ITimedTextRegion)->get_ScrollMode(&value));
    return value;
}

template <typename D> void impl_ITimedTextRegion<D>::ScrollMode(Windows::Media::Core::TimedTextScrollMode value) const
{
    check_hresult(WINRT_SHIM(ITimedTextRegion)->put_ScrollMode(value));
}

template <typename D> hstring impl_ITimedTextStyle<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_ITimedTextStyle<D>::FontFamily() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_FontFamily(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::FontFamily(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_FontFamily(get_abi(value)));
}

template <typename D> Windows::Media::Core::TimedTextDouble impl_ITimedTextStyle<D>::FontSize() const
{
    Windows::Media::Core::TimedTextDouble value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_FontSize(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::FontSize(const Windows::Media::Core::TimedTextDouble & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_FontSize(get_abi(value)));
}

template <typename D> Windows::Media::Core::TimedTextWeight impl_ITimedTextStyle<D>::FontWeight() const
{
    Windows::Media::Core::TimedTextWeight value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_FontWeight(&value));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::FontWeight(Windows::Media::Core::TimedTextWeight value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_FontWeight(value));
}

template <typename D> Windows::UI::Color impl_ITimedTextStyle<D>::Foreground() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_Foreground(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::Foreground(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_Foreground(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_ITimedTextStyle<D>::Background() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_Background(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::Background(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_Background(get_abi(value)));
}

template <typename D> bool impl_ITimedTextStyle<D>::IsBackgroundAlwaysShown() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_IsBackgroundAlwaysShown(&value));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::IsBackgroundAlwaysShown(bool value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_IsBackgroundAlwaysShown(value));
}

template <typename D> Windows::Media::Core::TimedTextFlowDirection impl_ITimedTextStyle<D>::FlowDirection() const
{
    Windows::Media::Core::TimedTextFlowDirection value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_FlowDirection(&value));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::FlowDirection(Windows::Media::Core::TimedTextFlowDirection value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_FlowDirection(value));
}

template <typename D> Windows::Media::Core::TimedTextLineAlignment impl_ITimedTextStyle<D>::LineAlignment() const
{
    Windows::Media::Core::TimedTextLineAlignment value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_LineAlignment(&value));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::LineAlignment(Windows::Media::Core::TimedTextLineAlignment value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_LineAlignment(value));
}

template <typename D> Windows::UI::Color impl_ITimedTextStyle<D>::OutlineColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_OutlineColor(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::OutlineColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_OutlineColor(get_abi(value)));
}

template <typename D> Windows::Media::Core::TimedTextDouble impl_ITimedTextStyle<D>::OutlineThickness() const
{
    Windows::Media::Core::TimedTextDouble value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_OutlineThickness(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::OutlineThickness(const Windows::Media::Core::TimedTextDouble & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_OutlineThickness(get_abi(value)));
}

template <typename D> Windows::Media::Core::TimedTextDouble impl_ITimedTextStyle<D>::OutlineRadius() const
{
    Windows::Media::Core::TimedTextDouble value {};
    check_hresult(WINRT_SHIM(ITimedTextStyle)->get_OutlineRadius(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextStyle<D>::OutlineRadius(const Windows::Media::Core::TimedTextDouble & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextStyle)->put_OutlineRadius(get_abi(value)));
}

template <typename D> int32_t impl_ITimedTextSubformat<D>::StartIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITimedTextSubformat)->get_StartIndex(&value));
    return value;
}

template <typename D> void impl_ITimedTextSubformat<D>::StartIndex(int32_t value) const
{
    check_hresult(WINRT_SHIM(ITimedTextSubformat)->put_StartIndex(value));
}

template <typename D> int32_t impl_ITimedTextSubformat<D>::Length() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITimedTextSubformat)->get_Length(&value));
    return value;
}

template <typename D> void impl_ITimedTextSubformat<D>::Length(int32_t value) const
{
    check_hresult(WINRT_SHIM(ITimedTextSubformat)->put_Length(value));
}

template <typename D> Windows::Media::Core::TimedTextStyle impl_ITimedTextSubformat<D>::SubformatStyle() const
{
    Windows::Media::Core::TimedTextStyle value { nullptr };
    check_hresult(WINRT_SHIM(ITimedTextSubformat)->get_SubformatStyle(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextSubformat<D>::SubformatStyle(const Windows::Media::Core::TimedTextStyle & value) const
{
    check_hresult(WINRT_SHIM(ITimedTextSubformat)->put_SubformatStyle(get_abi(value)));
}

template <typename D> hstring impl_ITimedTextLine<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimedTextLine)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedTextLine<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ITimedTextLine)->put_Text(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Core::TimedTextSubformat> impl_ITimedTextLine<D>::Subformats() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Core::TimedTextSubformat> value;
    check_hresult(WINRT_SHIM(ITimedTextLine)->get_Subformats(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ISingleSelectMediaTrackList<D>::SelectedIndexChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::ISingleSelectMediaTrackList, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISingleSelectMediaTrackList)->add_SelectedIndexChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISingleSelectMediaTrackList> impl_ISingleSelectMediaTrackList<D>::SelectedIndexChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::ISingleSelectMediaTrackList, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ISingleSelectMediaTrackList>(this, &ABI::Windows::Media::Core::ISingleSelectMediaTrackList::remove_SelectedIndexChanged, SelectedIndexChanged(handler));
}

template <typename D> void impl_ISingleSelectMediaTrackList<D>::SelectedIndexChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ISingleSelectMediaTrackList)->remove_SelectedIndexChanged(token));
}

template <typename D> void impl_ISingleSelectMediaTrackList<D>::SelectedIndex(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISingleSelectMediaTrackList)->put_SelectedIndex(value));
}

template <typename D> int32_t impl_ISingleSelectMediaTrackList<D>::SelectedIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISingleSelectMediaTrackList)->get_SelectedIndex(&value));
    return value;
}

template <typename D> hstring impl_IMediaTrack<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaTrack)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaTrack<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaTrack)->get_Language(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaTrackKind impl_IMediaTrack<D>::TrackKind() const
{
    Windows::Media::Core::MediaTrackKind value {};
    check_hresult(WINRT_SHIM(IMediaTrack)->get_TrackKind(&value));
    return value;
}

template <typename D> void impl_IMediaTrack<D>::Label(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMediaTrack)->put_Label(get_abi(value)));
}

template <typename D> hstring impl_IMediaTrack<D>::Label() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaTrack)->get_Label(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::TimedMetadataTrackErrorCode impl_ITimedMetadataTrackError<D>::ErrorCode() const
{
    Windows::Media::Core::TimedMetadataTrackErrorCode value {};
    check_hresult(WINRT_SHIM(ITimedMetadataTrackError)->get_ErrorCode(&value));
    return value;
}

template <typename D> HRESULT impl_ITimedMetadataTrackError<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(ITimedMetadataTrackError)->get_ExtendedError(&value));
    return value;
}

template <typename D> Windows::Media::Core::IMediaCue impl_IMediaCueEventArgs<D>::Cue() const
{
    Windows::Media::Core::IMediaCue value;
    check_hresult(WINRT_SHIM(IMediaCueEventArgs)->get_Cue(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::TimedMetadataTrackError impl_ITimedMetadataTrackFailedEventArgs<D>::Error() const
{
    Windows::Media::Core::TimedMetadataTrackError value { nullptr };
    check_hresult(WINRT_SHIM(ITimedMetadataTrackFailedEventArgs)->get_Error(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataCue<D>::Data(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(IDataCue)->put_Data(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IDataCue<D>::Data() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IDataCue)->get_Data(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::TimedMetadataTrack impl_ITimedMetadataTrackFactory<D>::Create(hstring_view id, hstring_view language, Windows::Media::Core::TimedMetadataKind kind) const
{
    Windows::Media::Core::TimedMetadataTrack value { nullptr };
    check_hresult(WINRT_SHIM(ITimedMetadataTrackFactory)->abi_Create(get_abi(id), get_abi(language), kind, put_abi(value)));
    return value;
}

template <typename D> event_token impl_ITimedMetadataTrack<D>::CueEntered(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::MediaCueEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->add_CueEntered(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ITimedMetadataTrack> impl_ITimedMetadataTrack<D>::CueEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::MediaCueEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ITimedMetadataTrack>(this, &ABI::Windows::Media::Core::ITimedMetadataTrack::remove_CueEntered, CueEntered(handler));
}

template <typename D> void impl_ITimedMetadataTrack<D>::CueEntered(event_token token) const
{
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->remove_CueEntered(token));
}

template <typename D> event_token impl_ITimedMetadataTrack<D>::CueExited(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::MediaCueEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->add_CueExited(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ITimedMetadataTrack> impl_ITimedMetadataTrack<D>::CueExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::MediaCueEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ITimedMetadataTrack>(this, &ABI::Windows::Media::Core::ITimedMetadataTrack::remove_CueExited, CueExited(handler));
}

template <typename D> void impl_ITimedMetadataTrack<D>::CueExited(event_token token) const
{
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->remove_CueExited(token));
}

template <typename D> event_token impl_ITimedMetadataTrack<D>::TrackFailed(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::TimedMetadataTrackFailedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->add_TrackFailed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ITimedMetadataTrack> impl_ITimedMetadataTrack<D>::TrackFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedMetadataTrack, Windows::Media::Core::TimedMetadataTrackFailedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ITimedMetadataTrack>(this, &ABI::Windows::Media::Core::ITimedMetadataTrack::remove_TrackFailed, TrackFailed(handler));
}

template <typename D> void impl_ITimedMetadataTrack<D>::TrackFailed(event_token token) const
{
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->remove_TrackFailed(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Core::IMediaCue> impl_ITimedMetadataTrack<D>::Cues() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Core::IMediaCue> value;
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->get_Cues(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Core::IMediaCue> impl_ITimedMetadataTrack<D>::ActiveCues() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Core::IMediaCue> value;
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->get_ActiveCues(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::TimedMetadataKind impl_ITimedMetadataTrack<D>::TimedMetadataKind() const
{
    Windows::Media::Core::TimedMetadataKind value {};
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->get_TimedMetadataKind(&value));
    return value;
}

template <typename D> hstring impl_ITimedMetadataTrack<D>::DispatchType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->get_DispatchType(put_abi(value)));
    return value;
}

template <typename D> void impl_ITimedMetadataTrack<D>::AddCue(const Windows::Media::Core::IMediaCue & cue) const
{
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->abi_AddCue(get_abi(cue)));
}

template <typename D> void impl_ITimedMetadataTrack<D>::RemoveCue(const Windows::Media::Core::IMediaCue & cue) const
{
    check_hresult(WINRT_SHIM(ITimedMetadataTrack)->abi_RemoveCue(get_abi(cue)));
}

template <typename D> Windows::Media::Core::TimedMetadataTrackError impl_ITimedTextSourceResolveResultEventArgs<D>::Error() const
{
    Windows::Media::Core::TimedMetadataTrackError value { nullptr };
    check_hresult(WINRT_SHIM(ITimedTextSourceResolveResultEventArgs)->get_Error(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Core::TimedMetadataTrack> impl_ITimedTextSourceResolveResultEventArgs<D>::Tracks() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Core::TimedMetadataTrack> value;
    check_hresult(WINRT_SHIM(ITimedTextSourceResolveResultEventArgs)->get_Tracks(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ITimedTextSource<D>::Resolved(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedTextSource, Windows::Media::Core::TimedTextSourceResolveResultEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ITimedTextSource)->add_Resolved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ITimedTextSource> impl_ITimedTextSource<D>::Resolved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::TimedTextSource, Windows::Media::Core::TimedTextSourceResolveResultEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ITimedTextSource>(this, &ABI::Windows::Media::Core::ITimedTextSource::remove_Resolved, Resolved(handler));
}

template <typename D> void impl_ITimedTextSource<D>::Resolved(event_token token) const
{
    check_hresult(WINRT_SHIM(ITimedTextSource)->remove_Resolved(token));
}

template <typename D> Windows::Media::Core::TimedTextSource impl_ITimedTextSourceStatics<D>::CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Media::Core::TimedTextSource value { nullptr };
    check_hresult(WINRT_SHIM(ITimedTextSourceStatics)->abi_CreateFromStream(get_abi(stream), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::TimedTextSource impl_ITimedTextSourceStatics<D>::CreateFromUri(const Windows::Foundation::Uri & uri) const
{
    Windows::Media::Core::TimedTextSource value { nullptr };
    check_hresult(WINRT_SHIM(ITimedTextSourceStatics)->abi_CreateFromUri(get_abi(uri), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::TimedTextSource impl_ITimedTextSourceStatics<D>::CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream, hstring_view defaultLanguage) const
{
    Windows::Media::Core::TimedTextSource value { nullptr };
    check_hresult(WINRT_SHIM(ITimedTextSourceStatics)->abi_CreateFromStreamWithLanguage(get_abi(stream), get_abi(defaultLanguage), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::TimedTextSource impl_ITimedTextSourceStatics<D>::CreateFromUri(const Windows::Foundation::Uri & uri, hstring_view defaultLanguage) const
{
    Windows::Media::Core::TimedTextSource value { nullptr };
    check_hresult(WINRT_SHIM(ITimedTextSourceStatics)->abi_CreateFromUriWithLanguage(get_abi(uri), get_abi(defaultLanguage), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::MediaDecoderStatus impl_IVideoTrackSupportInfo<D>::DecoderStatus() const
{
    Windows::Media::Core::MediaDecoderStatus value {};
    check_hresult(WINRT_SHIM(IVideoTrackSupportInfo)->get_DecoderStatus(&value));
    return value;
}

template <typename D> Windows::Media::Core::MediaSourceStatus impl_IVideoTrackSupportInfo<D>::MediaSourceStatus() const
{
    Windows::Media::Core::MediaSourceStatus value {};
    check_hresult(WINRT_SHIM(IVideoTrackSupportInfo)->get_MediaSourceStatus(&value));
    return value;
}

template <typename D> Windows::Media::Core::MediaDecoderStatus impl_IAudioTrackSupportInfo<D>::DecoderStatus() const
{
    Windows::Media::Core::MediaDecoderStatus value {};
    check_hresult(WINRT_SHIM(IAudioTrackSupportInfo)->get_DecoderStatus(&value));
    return value;
}

template <typename D> Windows::Media::Core::AudioDecoderDegradation impl_IAudioTrackSupportInfo<D>::Degradation() const
{
    Windows::Media::Core::AudioDecoderDegradation value {};
    check_hresult(WINRT_SHIM(IAudioTrackSupportInfo)->get_Degradation(&value));
    return value;
}

template <typename D> Windows::Media::Core::AudioDecoderDegradationReason impl_IAudioTrackSupportInfo<D>::DegradationReason() const
{
    Windows::Media::Core::AudioDecoderDegradationReason value {};
    check_hresult(WINRT_SHIM(IAudioTrackSupportInfo)->get_DegradationReason(&value));
    return value;
}

template <typename D> Windows::Media::Core::MediaSourceStatus impl_IAudioTrackSupportInfo<D>::MediaSourceStatus() const
{
    Windows::Media::Core::MediaSourceStatus value {};
    check_hresult(WINRT_SHIM(IAudioTrackSupportInfo)->get_MediaSourceStatus(&value));
    return value;
}

template <typename D> HRESULT impl_IVideoTrackOpenFailedEventArgs<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IVideoTrackOpenFailedEventArgs)->get_ExtendedError(&value));
    return value;
}

template <typename D> HRESULT impl_IAudioTrackOpenFailedEventArgs<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IAudioTrackOpenFailedEventArgs)->get_ExtendedError(&value));
    return value;
}

template <typename D> event_token impl_IVideoTrack<D>::OpenFailed(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::VideoTrack, Windows::Media::Core::VideoTrackOpenFailedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVideoTrack)->add_OpenFailed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVideoTrack> impl_IVideoTrack<D>::OpenFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::VideoTrack, Windows::Media::Core::VideoTrackOpenFailedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVideoTrack>(this, &ABI::Windows::Media::Core::IVideoTrack::remove_OpenFailed, OpenFailed(handler));
}

template <typename D> void impl_IVideoTrack<D>::OpenFailed(event_token token) const
{
    check_hresult(WINRT_SHIM(IVideoTrack)->remove_OpenFailed(token));
}

template <typename D> Windows::Media::MediaProperties::VideoEncodingProperties impl_IVideoTrack<D>::GetEncodingProperties() const
{
    Windows::Media::MediaProperties::VideoEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IVideoTrack)->abi_GetEncodingProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IVideoTrack<D>::PlaybackItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IVideoTrack)->get_PlaybackItem(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVideoTrack<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVideoTrack)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::VideoTrackSupportInfo impl_IVideoTrack<D>::SupportInfo() const
{
    Windows::Media::Core::VideoTrackSupportInfo value { nullptr };
    check_hresult(WINRT_SHIM(IVideoTrack)->get_SupportInfo(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IAudioTrack<D>::OpenFailed(const Windows::Foundation::TypedEventHandler<Windows::Media::Core::AudioTrack, Windows::Media::Core::AudioTrackOpenFailedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioTrack)->add_OpenFailed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAudioTrack> impl_IAudioTrack<D>::OpenFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Core::AudioTrack, Windows::Media::Core::AudioTrackOpenFailedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAudioTrack>(this, &ABI::Windows::Media::Core::IAudioTrack::remove_OpenFailed, OpenFailed(handler));
}

template <typename D> void impl_IAudioTrack<D>::OpenFailed(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioTrack)->remove_OpenFailed(token));
}

template <typename D> Windows::Media::MediaProperties::AudioEncodingProperties impl_IAudioTrack<D>::GetEncodingProperties() const
{
    Windows::Media::MediaProperties::AudioEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IAudioTrack)->abi_GetEncodingProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IAudioTrack<D>::PlaybackItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IAudioTrack)->get_PlaybackItem(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAudioTrack<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAudioTrack)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Core::AudioTrackSupportInfo impl_IAudioTrack<D>::SupportInfo() const
{
    Windows::Media::Core::AudioTrackSupportInfo value { nullptr };
    check_hresult(WINRT_SHIM(IAudioTrack)->get_SupportInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_ITimedMetadataTrack2<D>::PlaybackItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(ITimedMetadataTrack2)->get_PlaybackItem(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ITimedMetadataTrack2<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ITimedMetadataTrack2)->get_Name(put_abi(value)));
    return value;
}

inline AudioStreamDescriptor::AudioStreamDescriptor(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) :
    AudioStreamDescriptor(get_activation_factory<AudioStreamDescriptor, IAudioStreamDescriptorFactory>().Create(encodingProperties))
{}

inline DataCue::DataCue() :
    DataCue(activate_instance<DataCue>())
{}

inline FaceDetectionEffectDefinition::FaceDetectionEffectDefinition() :
    FaceDetectionEffectDefinition(activate_instance<FaceDetectionEffectDefinition>())
{}

inline MediaBinder::MediaBinder() :
    MediaBinder(activate_instance<MediaBinder>())
{}

inline Windows::Media::Core::MediaSource MediaSource::CreateFromAdaptiveMediaSource(const Windows::Media::Streaming::Adaptive::AdaptiveMediaSource & mediaSource)
{
    return get_activation_factory<MediaSource, IMediaSourceStatics>().CreateFromAdaptiveMediaSource(mediaSource);
}

inline Windows::Media::Core::MediaSource MediaSource::CreateFromMediaStreamSource(const Windows::Media::Core::MediaStreamSource & mediaSource)
{
    return get_activation_factory<MediaSource, IMediaSourceStatics>().CreateFromMediaStreamSource(mediaSource);
}

inline Windows::Media::Core::MediaSource MediaSource::CreateFromMseStreamSource(const Windows::Media::Core::MseStreamSource & mediaSource)
{
    return get_activation_factory<MediaSource, IMediaSourceStatics>().CreateFromMseStreamSource(mediaSource);
}

inline Windows::Media::Core::MediaSource MediaSource::CreateFromIMediaSource(const Windows::Media::Core::IMediaSource & mediaSource)
{
    return get_activation_factory<MediaSource, IMediaSourceStatics>().CreateFromIMediaSource(mediaSource);
}

inline Windows::Media::Core::MediaSource MediaSource::CreateFromStorageFile(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<MediaSource, IMediaSourceStatics>().CreateFromStorageFile(file);
}

inline Windows::Media::Core::MediaSource MediaSource::CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream, hstring_view contentType)
{
    return get_activation_factory<MediaSource, IMediaSourceStatics>().CreateFromStream(stream, contentType);
}

inline Windows::Media::Core::MediaSource MediaSource::CreateFromStreamReference(const Windows::Storage::Streams::IRandomAccessStreamReference & stream, hstring_view contentType)
{
    return get_activation_factory<MediaSource, IMediaSourceStatics>().CreateFromStreamReference(stream, contentType);
}

inline Windows::Media::Core::MediaSource MediaSource::CreateFromUri(const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<MediaSource, IMediaSourceStatics>().CreateFromUri(uri);
}

inline Windows::Media::Core::MediaSource MediaSource::CreateFromMediaBinder(const Windows::Media::Core::MediaBinder & binder)
{
    return get_activation_factory<MediaSource, IMediaSourceStatics2>().CreateFromMediaBinder(binder);
}

inline Windows::Media::Core::MediaStreamSample MediaStreamSample::CreateFromBuffer(const Windows::Storage::Streams::IBuffer & buffer, const Windows::Foundation::TimeSpan & timestamp)
{
    return get_activation_factory<MediaStreamSample, IMediaStreamSampleStatics>().CreateFromBuffer(buffer, timestamp);
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::Core::MediaStreamSample> MediaStreamSample::CreateFromStreamAsync(const Windows::Storage::Streams::IInputStream & stream, uint32_t count, const Windows::Foundation::TimeSpan & timestamp)
{
    return get_activation_factory<MediaStreamSample, IMediaStreamSampleStatics>().CreateFromStreamAsync(stream, count, timestamp);
}

inline MediaStreamSource::MediaStreamSource(const Windows::Media::Core::IMediaStreamDescriptor & descriptor) :
    MediaStreamSource(get_activation_factory<MediaStreamSource, IMediaStreamSourceFactory>().CreateFromDescriptor(descriptor))
{}

inline MediaStreamSource::MediaStreamSource(const Windows::Media::Core::IMediaStreamDescriptor & descriptor, const Windows::Media::Core::IMediaStreamDescriptor & descriptor2) :
    MediaStreamSource(get_activation_factory<MediaStreamSource, IMediaStreamSourceFactory>().CreateFromDescriptors(descriptor, descriptor2))
{}

inline MseStreamSource::MseStreamSource() :
    MseStreamSource(activate_instance<MseStreamSource>())
{}

inline bool MseStreamSource::IsContentTypeSupported(hstring_view contentType)
{
    return get_activation_factory<MseStreamSource, IMseStreamSourceStatics>().IsContentTypeSupported(contentType);
}

inline SceneAnalysisEffectDefinition::SceneAnalysisEffectDefinition() :
    SceneAnalysisEffectDefinition(activate_instance<SceneAnalysisEffectDefinition>())
{}

inline TimedMetadataTrack::TimedMetadataTrack(hstring_view id, hstring_view language, Windows::Media::Core::TimedMetadataKind kind) :
    TimedMetadataTrack(get_activation_factory<TimedMetadataTrack, ITimedMetadataTrackFactory>().Create(id, language, kind))
{}

inline TimedTextCue::TimedTextCue() :
    TimedTextCue(activate_instance<TimedTextCue>())
{}

inline TimedTextLine::TimedTextLine() :
    TimedTextLine(activate_instance<TimedTextLine>())
{}

inline TimedTextRegion::TimedTextRegion() :
    TimedTextRegion(activate_instance<TimedTextRegion>())
{}

inline Windows::Media::Core::TimedTextSource TimedTextSource::CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream)
{
    return get_activation_factory<TimedTextSource, ITimedTextSourceStatics>().CreateFromStream(stream);
}

inline Windows::Media::Core::TimedTextSource TimedTextSource::CreateFromUri(const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<TimedTextSource, ITimedTextSourceStatics>().CreateFromUri(uri);
}

inline Windows::Media::Core::TimedTextSource TimedTextSource::CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream, hstring_view defaultLanguage)
{
    return get_activation_factory<TimedTextSource, ITimedTextSourceStatics>().CreateFromStream(stream, defaultLanguage);
}

inline Windows::Media::Core::TimedTextSource TimedTextSource::CreateFromUri(const Windows::Foundation::Uri & uri, hstring_view defaultLanguage)
{
    return get_activation_factory<TimedTextSource, ITimedTextSourceStatics>().CreateFromUri(uri, defaultLanguage);
}

inline TimedTextStyle::TimedTextStyle() :
    TimedTextStyle(activate_instance<TimedTextStyle>())
{}

inline TimedTextSubformat::TimedTextSubformat() :
    TimedTextSubformat(activate_instance<TimedTextSubformat>())
{}

inline VideoStabilizationEffectDefinition::VideoStabilizationEffectDefinition() :
    VideoStabilizationEffectDefinition(activate_instance<VideoStabilizationEffectDefinition>())
{}

inline VideoStreamDescriptor::VideoStreamDescriptor(const Windows::Media::MediaProperties::VideoEncodingProperties & encodingProperties) :
    VideoStreamDescriptor(get_activation_factory<VideoStreamDescriptor, IVideoStreamDescriptorFactory>().Create(encodingProperties))
{}

}

}
#pragma warning(pop)
