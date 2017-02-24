// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Media.Render.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Media.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Media.Capture.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.Effects.3.h"
#include "internal/Windows.Media.Audio.3.h"
#include "Windows.Media.h"
#include "Windows.Foundation.h"
#include "Windows.Media.Effects.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioDeviceInputNode> : produce_base<D, Windows::Media::Audio::IAudioDeviceInputNode>
{
    HRESULT __stdcall get_Device(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Device());
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
struct produce<D, Windows::Media::Audio::IAudioDeviceOutputNode> : produce_base<D, Windows::Media::Audio::IAudioDeviceOutputNode>
{
    HRESULT __stdcall get_Device(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Device());
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
struct produce<D, Windows::Media::Audio::IAudioFileInputNode> : produce_base<D, Windows::Media::Audio::IAudioFileInputNode>
{
    HRESULT __stdcall put_PlaybackSpeedFactor(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackSpeedFactor(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackSpeedFactor(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackSpeedFactor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
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

    HRESULT __stdcall abi_Seek(impl::abi_arg_in<Windows::Foundation::TimeSpan> position) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Seek(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&position));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EndTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LoopCount(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LoopCount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LoopCount(impl::abi_arg_in<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoopCount(*reinterpret_cast<const Windows::Foundation::IReference<int32_t> *>(&value));
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

    HRESULT __stdcall get_SourceFile(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceFile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FileCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFileInputNode, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FileCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFileInputNode, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FileCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FileCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioFileOutputNode> : produce_base<D, Windows::Media::Audio::IAudioFileOutputNode>
{
    HRESULT __stdcall get_File(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().File());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileEncodingProfile(impl::abi_arg_out<Windows::Media::MediaProperties::IMediaEncodingProfile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileEncodingProfile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FinalizeAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Transcoding::TranscodeFailureReason>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FinalizeAsync());
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
struct produce<D, Windows::Media::Audio::IAudioFrameCompletedEventArgs> : produce_base<D, Windows::Media::Audio::IAudioFrameCompletedEventArgs>
{
    HRESULT __stdcall get_Frame(impl::abi_arg_out<Windows::Media::IAudioFrame> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Frame());
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
struct produce<D, Windows::Media::Audio::IAudioFrameInputNode> : produce_base<D, Windows::Media::Audio::IAudioFrameInputNode>
{
    HRESULT __stdcall put_PlaybackSpeedFactor(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackSpeedFactor(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackSpeedFactor(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackSpeedFactor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddFrame(impl::abi_arg_in<Windows::Media::IAudioFrame> frame) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddFrame(*reinterpret_cast<const Windows::Media::AudioFrame *>(&frame));
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

    HRESULT __stdcall get_QueuedSampleCount(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueuedSampleCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AudioFrameCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::AudioFrameCompletedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AudioFrameCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::AudioFrameCompletedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AudioFrameCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioFrameCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_QuantumStarted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().QuantumStarted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_QuantumStarted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QuantumStarted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioFrameOutputNode> : produce_base<D, Windows::Media::Audio::IAudioFrameOutputNode>
{
    HRESULT __stdcall abi_GetFrame(impl::abi_arg_out<Windows::Media::IAudioFrame> audioFrame) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *audioFrame = detach_abi(this->shim().GetFrame());
            return S_OK;
        }
        catch (...)
        {
            *audioFrame = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioGraph> : produce_base<D, Windows::Media::Audio::IAudioGraph>
{
    HRESULT __stdcall abi_CreateFrameInputNode(impl::abi_arg_out<Windows::Media::Audio::IAudioFrameInputNode> frameInputNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *frameInputNode = detach_abi(this->shim().CreateFrameInputNode());
            return S_OK;
        }
        catch (...)
        {
            *frameInputNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFrameInputNodeWithFormat(impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties, impl::abi_arg_out<Windows::Media::Audio::IAudioFrameInputNode> frameInputNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *frameInputNode = detach_abi(this->shim().CreateFrameInputNode(*reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties)));
            return S_OK;
        }
        catch (...)
        {
            *frameInputNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDeviceInputNodeAsync(Windows::Media::Capture::MediaCategory category, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDeviceInputNodeAsync(category));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDeviceInputNodeWithFormatAsync(Windows::Media::Capture::MediaCategory category, impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDeviceInputNodeAsync(category, *reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDeviceInputNodeWithFormatOnDeviceAsync(Windows::Media::Capture::MediaCategory category, impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties, impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> device, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDeviceInputNodeAsync(category, *reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties), *reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&device)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFrameOutputNode(impl::abi_arg_out<Windows::Media::Audio::IAudioFrameOutputNode> frameOutputNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *frameOutputNode = detach_abi(this->shim().CreateFrameOutputNode());
            return S_OK;
        }
        catch (...)
        {
            *frameOutputNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFrameOutputNodeWithFormat(impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties, impl::abi_arg_out<Windows::Media::Audio::IAudioFrameOutputNode> frameOutputNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *frameOutputNode = detach_abi(this->shim().CreateFrameOutputNode(*reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties)));
            return S_OK;
        }
        catch (...)
        {
            *frameOutputNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDeviceOutputNodeAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDeviceOutputNodeAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileInputNodeAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFileInputNodeAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileOutputNodeAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFileOutputNodeAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileOutputNodeWithFileProfileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Media::MediaProperties::IMediaEncodingProfile> fileEncodingProfile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFileOutputNodeAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Media::MediaProperties::MediaEncodingProfile *>(&fileEncodingProfile)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSubmixNode(impl::abi_arg_out<Windows::Media::Audio::IAudioInputNode> submixNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *submixNode = detach_abi(this->shim().CreateSubmixNode());
            return S_OK;
        }
        catch (...)
        {
            *submixNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSubmixNodeWithFormat(impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties, impl::abi_arg_out<Windows::Media::Audio::IAudioInputNode> submixNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *submixNode = detach_abi(this->shim().CreateSubmixNode(*reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties)));
            return S_OK;
        }
        catch (...)
        {
            *submixNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResetAllNodes() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResetAllNodes();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_QuantumStarted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().QuantumStarted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_QuantumStarted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QuantumStarted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_QuantumProcessed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().QuantumProcessed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_QuantumProcessed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QuantumProcessed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UnrecoverableErrorOccurred(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UnrecoverableErrorOccurred(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UnrecoverableErrorOccurred(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnrecoverableErrorOccurred(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompletedQuantumCount(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompletedQuantumCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IAudioEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LatencyInSamples(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LatencyInSamples());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrimaryRenderDevice(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrimaryRenderDevice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RenderDeviceAudioProcessing(Windows::Media::AudioProcessing * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenderDeviceAudioProcessing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SamplesPerQuantum(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SamplesPerQuantum());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioGraph2> : produce_base<D, Windows::Media::Audio::IAudioGraph2>
{
    HRESULT __stdcall abi_CreateFrameInputNodeWithFormatAndEmitter(impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties, impl::abi_arg_in<Windows::Media::Audio::IAudioNodeEmitter> emitter, impl::abi_arg_out<Windows::Media::Audio::IAudioFrameInputNode> frameInputNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *frameInputNode = detach_abi(this->shim().CreateFrameInputNode(*reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties), *reinterpret_cast<const Windows::Media::Audio::AudioNodeEmitter *>(&emitter)));
            return S_OK;
        }
        catch (...)
        {
            *frameInputNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDeviceInputNodeWithFormatAndEmitterOnDeviceAsync(Windows::Media::Capture::MediaCategory category, impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties, impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> device, impl::abi_arg_in<Windows::Media::Audio::IAudioNodeEmitter> emitter, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDeviceInputNodeAsync(category, *reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties), *reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&device), *reinterpret_cast<const Windows::Media::Audio::AudioNodeEmitter *>(&emitter)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFileInputNodeWithEmitterAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Media::Audio::IAudioNodeEmitter> emitter, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateFileInputNodeAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Media::Audio::AudioNodeEmitter *>(&emitter)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSubmixNodeWithFormatAndEmitter(impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> encodingProperties, impl::abi_arg_in<Windows::Media::Audio::IAudioNodeEmitter> emitter, impl::abi_arg_out<Windows::Media::Audio::IAudioInputNode> submixNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *submixNode = detach_abi(this->shim().CreateSubmixNode(*reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&encodingProperties), *reinterpret_cast<const Windows::Media::Audio::AudioNodeEmitter *>(&emitter)));
            return S_OK;
        }
        catch (...)
        {
            *submixNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateBatchUpdater(impl::abi_arg_out<Windows::Foundation::IClosable> updater) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updater = detach_abi(this->shim().CreateBatchUpdater());
            return S_OK;
        }
        catch (...)
        {
            *updater = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioGraphConnection> : produce_base<D, Windows::Media::Audio::IAudioGraphConnection>
{
    HRESULT __stdcall get_Destination(impl::abi_arg_out<Windows::Media::Audio::IAudioNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Destination());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Gain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Gain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioGraphSettings> : produce_base<D, Windows::Media::Audio::IAudioGraphSettings>
{
    HRESULT __stdcall get_EncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IAudioEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EncodingProperties(impl::abi_arg_in<Windows::Media::MediaProperties::IAudioEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EncodingProperties(*reinterpret_cast<const Windows::Media::MediaProperties::AudioEncodingProperties *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrimaryRenderDevice(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrimaryRenderDevice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PrimaryRenderDevice(impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrimaryRenderDevice(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QuantumSizeSelectionMode(Windows::Media::Audio::QuantumSizeSelectionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QuantumSizeSelectionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_QuantumSizeSelectionMode(Windows::Media::Audio::QuantumSizeSelectionMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QuantumSizeSelectionMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredSamplesPerQuantum(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredSamplesPerQuantum());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredSamplesPerQuantum(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredSamplesPerQuantum(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioRenderCategory(Windows::Media::Render::AudioRenderCategory * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioRenderCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioRenderCategory(Windows::Media::Render::AudioRenderCategory value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioRenderCategory(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredRenderDeviceAudioProcessing(Windows::Media::AudioProcessing * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredRenderDeviceAudioProcessing());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredRenderDeviceAudioProcessing(Windows::Media::AudioProcessing value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredRenderDeviceAudioProcessing(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioGraphSettingsFactory> : produce_base<D, Windows::Media::Audio::IAudioGraphSettingsFactory>
{
    HRESULT __stdcall abi_Create(Windows::Media::Render::AudioRenderCategory audioRenderCategory, impl::abi_arg_out<Windows::Media::Audio::IAudioGraphSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(audioRenderCategory));
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
struct produce<D, Windows::Media::Audio::IAudioGraphStatics> : produce_base<D, Windows::Media::Audio::IAudioGraphStatics>
{
    HRESULT __stdcall abi_CreateAsync(impl::abi_arg_in<Windows::Media::Audio::IAudioGraphSettings> settings, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioGraphResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateAsync(*reinterpret_cast<const Windows::Media::Audio::AudioGraphSettings *>(&settings)));
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
struct produce<D, Windows::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs> : produce_base<D, Windows::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs>
{
    HRESULT __stdcall get_Error(Windows::Media::Audio::AudioGraphUnrecoverableError * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Error());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioInputNode> : produce_base<D, Windows::Media::Audio::IAudioInputNode>
{
    HRESULT __stdcall get_OutgoingConnections(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::AudioGraphConnection>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutgoingConnections());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddOutgoingConnection(impl::abi_arg_in<Windows::Media::Audio::IAudioNode> destination) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOutgoingConnection(*reinterpret_cast<const Windows::Media::Audio::IAudioNode *>(&destination));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddOutgoingConnectionWithGain(impl::abi_arg_in<Windows::Media::Audio::IAudioNode> destination, double gain) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddOutgoingConnection(*reinterpret_cast<const Windows::Media::Audio::IAudioNode *>(&destination), gain);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveOutgoingConnection(impl::abi_arg_in<Windows::Media::Audio::IAudioNode> destination) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveOutgoingConnection(*reinterpret_cast<const Windows::Media::Audio::IAudioNode *>(&destination));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioInputNode2> : produce_base<D, Windows::Media::Audio::IAudioInputNode2>
{
    HRESULT __stdcall get_Emitter(impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Emitter());
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
struct produce<D, Windows::Media::Audio::IAudioNode> : produce_base<D, Windows::Media::Audio::IAudioNode>
{
    HRESULT __stdcall get_EffectDefinitions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EffectDefinitions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutgoingGain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutgoingGain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutgoingGain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutgoingGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EncodingProperties(impl::abi_arg_out<Windows::Media::MediaProperties::IAudioEncodingProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncodingProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConsumeInput(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConsumeInput());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ConsumeInput(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConsumeInput(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
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

    HRESULT __stdcall abi_DisableEffectsByDefinition(impl::abi_arg_in<Windows::Media::Effects::IAudioEffectDefinition> definition) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisableEffectsByDefinition(*reinterpret_cast<const Windows::Media::Effects::IAudioEffectDefinition *>(&definition));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnableEffectsByDefinition(impl::abi_arg_in<Windows::Media::Effects::IAudioEffectDefinition> definition) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableEffectsByDefinition(*reinterpret_cast<const Windows::Media::Effects::IAudioEffectDefinition *>(&definition));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioNodeEmitter> : produce_base<D, Windows::Media::Audio::IAudioNodeEmitter>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
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

    HRESULT __stdcall put_Position(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Direction(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Direction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Direction(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Direction(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Shape(impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitterShape> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Shape());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DecayModel(impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitterDecayModel> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecayModel());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Gain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Gain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DistanceScale(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DistanceScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DistanceScale(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DistanceScale(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DopplerScale(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DopplerScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DopplerScale(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DopplerScale(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DopplerVelocity(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DopplerVelocity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DopplerVelocity(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DopplerVelocity(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDopplerDisabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDopplerDisabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioNodeEmitter2> : produce_base<D, Windows::Media::Audio::IAudioNodeEmitter2>
{
    HRESULT __stdcall get_SpatialAudioModel(Windows::Media::Audio::SpatialAudioModel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpatialAudioModel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpatialAudioModel(Windows::Media::Audio::SpatialAudioModel value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpatialAudioModel(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioNodeEmitterConeProperties> : produce_base<D, Windows::Media::Audio::IAudioNodeEmitterConeProperties>
{
    HRESULT __stdcall get_InnerAngle(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InnerAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OuterAngle(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OuterAngle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OuterAngleGain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OuterAngleGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioNodeEmitterDecayModel> : produce_base<D, Windows::Media::Audio::IAudioNodeEmitterDecayModel>
{
    HRESULT __stdcall get_Kind(Windows::Media::Audio::AudioNodeEmitterDecayKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinGain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxGain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NaturalProperties(impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NaturalProperties());
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
struct produce<D, Windows::Media::Audio::IAudioNodeEmitterDecayModelStatics> : produce_base<D, Windows::Media::Audio::IAudioNodeEmitterDecayModelStatics>
{
    HRESULT __stdcall abi_CreateNatural(double minGain, double maxGain, double unityGainDistance, double cutoffDistance, impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitterDecayModel> decayModel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *decayModel = detach_abi(this->shim().CreateNatural(minGain, maxGain, unityGainDistance, cutoffDistance));
            return S_OK;
        }
        catch (...)
        {
            *decayModel = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCustom(double minGain, double maxGain, impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitterDecayModel> decayModel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *decayModel = detach_abi(this->shim().CreateCustom(minGain, maxGain));
            return S_OK;
        }
        catch (...)
        {
            *decayModel = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioNodeEmitterFactory> : produce_base<D, Windows::Media::Audio::IAudioNodeEmitterFactory>
{
    HRESULT __stdcall abi_CreateAudioNodeEmitter(impl::abi_arg_in<Windows::Media::Audio::IAudioNodeEmitterShape> shape, impl::abi_arg_in<Windows::Media::Audio::IAudioNodeEmitterDecayModel> decayModel, Windows::Media::Audio::AudioNodeEmitterSettings settings, impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitter> emitter) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *emitter = detach_abi(this->shim().CreateAudioNodeEmitter(*reinterpret_cast<const Windows::Media::Audio::AudioNodeEmitterShape *>(&shape), *reinterpret_cast<const Windows::Media::Audio::AudioNodeEmitterDecayModel *>(&decayModel), settings));
            return S_OK;
        }
        catch (...)
        {
            *emitter = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties> : produce_base<D, Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties>
{
    HRESULT __stdcall get_UnityGainDistance(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnityGainDistance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CutoffDistance(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CutoffDistance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioNodeEmitterShape> : produce_base<D, Windows::Media::Audio::IAudioNodeEmitterShape>
{
    HRESULT __stdcall get_Kind(Windows::Media::Audio::AudioNodeEmitterShapeKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConeProperties(impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitterConeProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConeProperties());
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
struct produce<D, Windows::Media::Audio::IAudioNodeEmitterShapeStatics> : produce_base<D, Windows::Media::Audio::IAudioNodeEmitterShapeStatics>
{
    HRESULT __stdcall abi_CreateCone(double innerAngle, double outerAngle, double outerAngleGain, impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitterShape> shape) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *shape = detach_abi(this->shim().CreateCone(innerAngle, outerAngle, outerAngleGain));
            return S_OK;
        }
        catch (...)
        {
            *shape = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateOmnidirectional(impl::abi_arg_out<Windows::Media::Audio::IAudioNodeEmitterShape> shape) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *shape = detach_abi(this->shim().CreateOmnidirectional());
            return S_OK;
        }
        catch (...)
        {
            *shape = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioNodeListener> : produce_base<D, Windows::Media::Audio::IAudioNodeListener>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
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

    HRESULT __stdcall put_Position(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Orientation(impl::abi_arg_out<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Orientation(impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Orientation(*reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpeedOfSound(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpeedOfSound());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpeedOfSound(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpeedOfSound(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DopplerVelocity(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DopplerVelocity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DopplerVelocity(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DopplerVelocity(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IAudioNodeWithListener> : produce_base<D, Windows::Media::Audio::IAudioNodeWithListener>
{
    HRESULT __stdcall put_Listener(impl::abi_arg_in<Windows::Media::Audio::IAudioNodeListener> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Listener(*reinterpret_cast<const Windows::Media::Audio::AudioNodeListener *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Listener(impl::abi_arg_out<Windows::Media::Audio::IAudioNodeListener> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Listener());
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
struct produce<D, Windows::Media::Audio::ICreateAudioDeviceInputNodeResult> : produce_base<D, Windows::Media::Audio::ICreateAudioDeviceInputNodeResult>
{
    HRESULT __stdcall get_Status(Windows::Media::Audio::AudioDeviceNodeCreationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceInputNode(impl::abi_arg_out<Windows::Media::Audio::IAudioDeviceInputNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceInputNode());
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
struct produce<D, Windows::Media::Audio::ICreateAudioDeviceOutputNodeResult> : produce_base<D, Windows::Media::Audio::ICreateAudioDeviceOutputNodeResult>
{
    HRESULT __stdcall get_Status(Windows::Media::Audio::AudioDeviceNodeCreationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceOutputNode(impl::abi_arg_out<Windows::Media::Audio::IAudioDeviceOutputNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceOutputNode());
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
struct produce<D, Windows::Media::Audio::ICreateAudioFileInputNodeResult> : produce_base<D, Windows::Media::Audio::ICreateAudioFileInputNodeResult>
{
    HRESULT __stdcall get_Status(Windows::Media::Audio::AudioFileNodeCreationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileInputNode(impl::abi_arg_out<Windows::Media::Audio::IAudioFileInputNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileInputNode());
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
struct produce<D, Windows::Media::Audio::ICreateAudioFileOutputNodeResult> : produce_base<D, Windows::Media::Audio::ICreateAudioFileOutputNodeResult>
{
    HRESULT __stdcall get_Status(Windows::Media::Audio::AudioFileNodeCreationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileOutputNode(impl::abi_arg_out<Windows::Media::Audio::IAudioFileOutputNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileOutputNode());
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
struct produce<D, Windows::Media::Audio::ICreateAudioGraphResult> : produce_base<D, Windows::Media::Audio::ICreateAudioGraphResult>
{
    HRESULT __stdcall get_Status(Windows::Media::Audio::AudioGraphCreationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Graph(impl::abi_arg_out<Windows::Media::Audio::IAudioGraph> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Graph());
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
struct produce<D, Windows::Media::Audio::IEchoEffectDefinition> : produce_base<D, Windows::Media::Audio::IEchoEffectDefinition>
{
    HRESULT __stdcall put_WetDryMix(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetDryMix(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WetDryMix(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WetDryMix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Feedback(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Feedback(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Feedback(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Feedback());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Delay(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Delay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Delay(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Delay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IEchoEffectDefinitionFactory> : produce_base<D, Windows::Media::Audio::IEchoEffectDefinitionFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Media::Audio::IAudioGraph> audioGraph, impl::abi_arg_out<Windows::Media::Audio::IEchoEffectDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Media::Audio::AudioGraph *>(&audioGraph)));
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
struct produce<D, Windows::Media::Audio::IEqualizerBand> : produce_base<D, Windows::Media::Audio::IEqualizerBand>
{
    HRESULT __stdcall get_Bandwidth(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bandwidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Bandwidth(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Bandwidth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FrequencyCenter(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FrequencyCenter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FrequencyCenter(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FrequencyCenter(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Gain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Gain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IEqualizerEffectDefinition> : produce_base<D, Windows::Media::Audio::IEqualizerEffectDefinition>
{
    HRESULT __stdcall get_Bands(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::EqualizerBand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bands());
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
struct produce<D, Windows::Media::Audio::IEqualizerEffectDefinitionFactory> : produce_base<D, Windows::Media::Audio::IEqualizerEffectDefinitionFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Media::Audio::IAudioGraph> audioGraph, impl::abi_arg_out<Windows::Media::Audio::IEqualizerEffectDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Media::Audio::AudioGraph *>(&audioGraph)));
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
struct produce<D, Windows::Media::Audio::IFrameInputNodeQuantumStartedEventArgs> : produce_base<D, Windows::Media::Audio::IFrameInputNodeQuantumStartedEventArgs>
{
    HRESULT __stdcall get_RequiredSamples(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequiredSamples());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::ILimiterEffectDefinition> : produce_base<D, Windows::Media::Audio::ILimiterEffectDefinition>
{
    HRESULT __stdcall put_Release(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Release(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Release(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Release());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Loudness(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Loudness(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Loudness(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Loudness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::ILimiterEffectDefinitionFactory> : produce_base<D, Windows::Media::Audio::ILimiterEffectDefinitionFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Media::Audio::IAudioGraph> audioGraph, impl::abi_arg_out<Windows::Media::Audio::ILimiterEffectDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Media::Audio::AudioGraph *>(&audioGraph)));
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
struct produce<D, Windows::Media::Audio::IReverbEffectDefinition> : produce_base<D, Windows::Media::Audio::IReverbEffectDefinition>
{
    HRESULT __stdcall put_WetDryMix(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetDryMix(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WetDryMix(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WetDryMix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReflectionsDelay(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReflectionsDelay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReflectionsDelay(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReflectionsDelay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReverbDelay(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReverbDelay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReverbDelay(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReverbDelay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RearDelay(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RearDelay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RearDelay(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RearDelay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PositionLeft(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionLeft(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionLeft(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionLeft());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PositionRight(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionRight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionRight(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionRight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PositionMatrixLeft(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionMatrixLeft(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionMatrixLeft(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionMatrixLeft());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PositionMatrixRight(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionMatrixRight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionMatrixRight(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionMatrixRight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EarlyDiffusion(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EarlyDiffusion(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EarlyDiffusion(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EarlyDiffusion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LateDiffusion(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LateDiffusion(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LateDiffusion(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LateDiffusion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LowEQGain(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LowEQGain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LowEQGain(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LowEQGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LowEQCutoff(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LowEQCutoff(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LowEQCutoff(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LowEQCutoff());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HighEQGain(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HighEQGain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HighEQGain(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HighEQGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HighEQCutoff(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HighEQCutoff(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HighEQCutoff(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HighEQCutoff());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoomFilterFreq(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoomFilterFreq(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoomFilterFreq(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoomFilterFreq());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoomFilterMain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoomFilterMain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoomFilterMain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoomFilterMain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoomFilterHF(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoomFilterHF(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoomFilterHF(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoomFilterHF());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReflectionsGain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReflectionsGain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReflectionsGain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReflectionsGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReverbGain(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReverbGain(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReverbGain(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReverbGain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DecayTime(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DecayTime(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DecayTime(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecayTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Density(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Density(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Density(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Density());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoomSize(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoomSize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoomSize(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoomSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisableLateField(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisableLateField(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisableLateField(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisableLateField());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Audio::IReverbEffectDefinitionFactory> : produce_base<D, Windows::Media::Audio::IReverbEffectDefinitionFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Media::Audio::IAudioGraph> audioGraph, impl::abi_arg_out<Windows::Media::Audio::IReverbEffectDefinition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Media::Audio::AudioGraph *>(&audioGraph)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Audio {

template <typename D> Windows::Media::Audio::AudioGraphCreationStatus impl_ICreateAudioGraphResult<D>::Status() const
{
    Windows::Media::Audio::AudioGraphCreationStatus value {};
    check_hresult(WINRT_SHIM(ICreateAudioGraphResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioGraph impl_ICreateAudioGraphResult<D>::Graph() const
{
    Windows::Media::Audio::AudioGraph value { nullptr };
    check_hresult(WINRT_SHIM(ICreateAudioGraphResult)->get_Graph(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::AudioGraphSettings impl_IAudioGraphSettingsFactory<D>::Create(Windows::Media::Render::AudioRenderCategory audioRenderCategory) const
{
    Windows::Media::Audio::AudioGraphSettings value { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraphSettingsFactory)->abi_Create(audioRenderCategory, put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::AudioEncodingProperties impl_IAudioGraphSettings<D>::EncodingProperties() const
{
    Windows::Media::MediaProperties::AudioEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->get_EncodingProperties(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioGraphSettings<D>::EncodingProperties(const Windows::Media::MediaProperties::AudioEncodingProperties & value) const
{
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->put_EncodingProperties(get_abi(value)));
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IAudioGraphSettings<D>::PrimaryRenderDevice() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->get_PrimaryRenderDevice(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioGraphSettings<D>::PrimaryRenderDevice(const Windows::Devices::Enumeration::DeviceInformation & value) const
{
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->put_PrimaryRenderDevice(get_abi(value)));
}

template <typename D> Windows::Media::Audio::QuantumSizeSelectionMode impl_IAudioGraphSettings<D>::QuantumSizeSelectionMode() const
{
    Windows::Media::Audio::QuantumSizeSelectionMode value {};
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->get_QuantumSizeSelectionMode(&value));
    return value;
}

template <typename D> void impl_IAudioGraphSettings<D>::QuantumSizeSelectionMode(Windows::Media::Audio::QuantumSizeSelectionMode value) const
{
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->put_QuantumSizeSelectionMode(value));
}

template <typename D> int32_t impl_IAudioGraphSettings<D>::DesiredSamplesPerQuantum() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->get_DesiredSamplesPerQuantum(&value));
    return value;
}

template <typename D> void impl_IAudioGraphSettings<D>::DesiredSamplesPerQuantum(int32_t value) const
{
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->put_DesiredSamplesPerQuantum(value));
}

template <typename D> Windows::Media::Render::AudioRenderCategory impl_IAudioGraphSettings<D>::AudioRenderCategory() const
{
    Windows::Media::Render::AudioRenderCategory value {};
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->get_AudioRenderCategory(&value));
    return value;
}

template <typename D> void impl_IAudioGraphSettings<D>::AudioRenderCategory(Windows::Media::Render::AudioRenderCategory value) const
{
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->put_AudioRenderCategory(value));
}

template <typename D> Windows::Media::AudioProcessing impl_IAudioGraphSettings<D>::DesiredRenderDeviceAudioProcessing() const
{
    Windows::Media::AudioProcessing value {};
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->get_DesiredRenderDeviceAudioProcessing(&value));
    return value;
}

template <typename D> void impl_IAudioGraphSettings<D>::DesiredRenderDeviceAudioProcessing(Windows::Media::AudioProcessing value) const
{
    check_hresult(WINRT_SHIM(IAudioGraphSettings)->put_DesiredRenderDeviceAudioProcessing(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioGraphResult> impl_IAudioGraphStatics<D>::CreateAsync(const Windows::Media::Audio::AudioGraphSettings & settings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioGraphResult> result;
    check_hresult(WINRT_SHIM(IAudioGraphStatics)->abi_CreateAsync(get_abi(settings), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Audio::AudioDeviceNodeCreationStatus impl_ICreateAudioDeviceInputNodeResult<D>::Status() const
{
    Windows::Media::Audio::AudioDeviceNodeCreationStatus value {};
    check_hresult(WINRT_SHIM(ICreateAudioDeviceInputNodeResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioDeviceInputNode impl_ICreateAudioDeviceInputNodeResult<D>::DeviceInputNode() const
{
    Windows::Media::Audio::AudioDeviceInputNode value { nullptr };
    check_hresult(WINRT_SHIM(ICreateAudioDeviceInputNodeResult)->get_DeviceInputNode(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::AudioDeviceNodeCreationStatus impl_ICreateAudioDeviceOutputNodeResult<D>::Status() const
{
    Windows::Media::Audio::AudioDeviceNodeCreationStatus value {};
    check_hresult(WINRT_SHIM(ICreateAudioDeviceOutputNodeResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioDeviceOutputNode impl_ICreateAudioDeviceOutputNodeResult<D>::DeviceOutputNode() const
{
    Windows::Media::Audio::AudioDeviceOutputNode value { nullptr };
    check_hresult(WINRT_SHIM(ICreateAudioDeviceOutputNodeResult)->get_DeviceOutputNode(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::AudioFileNodeCreationStatus impl_ICreateAudioFileInputNodeResult<D>::Status() const
{
    Windows::Media::Audio::AudioFileNodeCreationStatus value {};
    check_hresult(WINRT_SHIM(ICreateAudioFileInputNodeResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioFileInputNode impl_ICreateAudioFileInputNodeResult<D>::FileInputNode() const
{
    Windows::Media::Audio::AudioFileInputNode value { nullptr };
    check_hresult(WINRT_SHIM(ICreateAudioFileInputNodeResult)->get_FileInputNode(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::AudioFileNodeCreationStatus impl_ICreateAudioFileOutputNodeResult<D>::Status() const
{
    Windows::Media::Audio::AudioFileNodeCreationStatus value {};
    check_hresult(WINRT_SHIM(ICreateAudioFileOutputNodeResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioFileOutputNode impl_ICreateAudioFileOutputNodeResult<D>::FileOutputNode() const
{
    Windows::Media::Audio::AudioFileOutputNode value { nullptr };
    check_hresult(WINRT_SHIM(ICreateAudioFileOutputNodeResult)->get_FileOutputNode(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::AudioGraphUnrecoverableError impl_IAudioGraphUnrecoverableErrorOccurredEventArgs<D>::Error() const
{
    Windows::Media::Audio::AudioGraphUnrecoverableError value {};
    check_hresult(WINRT_SHIM(IAudioGraphUnrecoverableErrorOccurredEventArgs)->get_Error(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioFrameInputNode impl_IAudioGraph<D>::CreateFrameInputNode() const
{
    Windows::Media::Audio::AudioFrameInputNode frameInputNode { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateFrameInputNode(put_abi(frameInputNode)));
    return frameInputNode;
}

template <typename D> Windows::Media::Audio::AudioFrameInputNode impl_IAudioGraph<D>::CreateFrameInputNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const
{
    Windows::Media::Audio::AudioFrameInputNode frameInputNode { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateFrameInputNodeWithFormat(get_abi(encodingProperties), put_abi(frameInputNode)));
    return frameInputNode;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> impl_IAudioGraph<D>::CreateDeviceInputNodeAsync(Windows::Media::Capture::MediaCategory category) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> result;
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateDeviceInputNodeAsync(category, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> impl_IAudioGraph<D>::CreateDeviceInputNodeAsync(Windows::Media::Capture::MediaCategory category, const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> result;
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateDeviceInputNodeWithFormatAsync(category, get_abi(encodingProperties), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> impl_IAudioGraph<D>::CreateDeviceInputNodeAsync(Windows::Media::Capture::MediaCategory category, const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties, const Windows::Devices::Enumeration::DeviceInformation & device) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> result;
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateDeviceInputNodeWithFormatOnDeviceAsync(category, get_abi(encodingProperties), get_abi(device), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Audio::AudioFrameOutputNode impl_IAudioGraph<D>::CreateFrameOutputNode() const
{
    Windows::Media::Audio::AudioFrameOutputNode frameOutputNode { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateFrameOutputNode(put_abi(frameOutputNode)));
    return frameOutputNode;
}

template <typename D> Windows::Media::Audio::AudioFrameOutputNode impl_IAudioGraph<D>::CreateFrameOutputNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const
{
    Windows::Media::Audio::AudioFrameOutputNode frameOutputNode { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateFrameOutputNodeWithFormat(get_abi(encodingProperties), put_abi(frameOutputNode)));
    return frameOutputNode;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult> impl_IAudioGraph<D>::CreateDeviceOutputNodeAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult> result;
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateDeviceOutputNodeAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> impl_IAudioGraph<D>::CreateFileInputNodeAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> result;
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateFileInputNodeAsync(get_abi(file), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> impl_IAudioGraph<D>::CreateFileOutputNodeAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> result;
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateFileOutputNodeAsync(get_abi(file), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> impl_IAudioGraph<D>::CreateFileOutputNodeAsync(const Windows::Storage::IStorageFile & file, const Windows::Media::MediaProperties::MediaEncodingProfile & fileEncodingProfile) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> result;
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateFileOutputNodeWithFileProfileAsync(get_abi(file), get_abi(fileEncodingProfile), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Audio::AudioSubmixNode impl_IAudioGraph<D>::CreateSubmixNode() const
{
    Windows::Media::Audio::AudioSubmixNode submixNode { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateSubmixNode(put_abi(submixNode)));
    return submixNode;
}

template <typename D> Windows::Media::Audio::AudioSubmixNode impl_IAudioGraph<D>::CreateSubmixNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const
{
    Windows::Media::Audio::AudioSubmixNode submixNode { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_CreateSubmixNodeWithFormat(get_abi(encodingProperties), put_abi(submixNode)));
    return submixNode;
}

template <typename D> void impl_IAudioGraph<D>::Start() const
{
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_Start());
}

template <typename D> void impl_IAudioGraph<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_Stop());
}

template <typename D> void impl_IAudioGraph<D>::ResetAllNodes() const
{
    check_hresult(WINRT_SHIM(IAudioGraph)->abi_ResetAllNodes());
}

template <typename D> event_token impl_IAudioGraph<D>::QuantumStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioGraph)->add_QuantumStarted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAudioGraph> impl_IAudioGraph<D>::QuantumStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAudioGraph>(this, &ABI::Windows::Media::Audio::IAudioGraph::remove_QuantumStarted, QuantumStarted(handler));
}

template <typename D> void impl_IAudioGraph<D>::QuantumStarted(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioGraph)->remove_QuantumStarted(token));
}

template <typename D> event_token impl_IAudioGraph<D>::QuantumProcessed(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioGraph)->add_QuantumProcessed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAudioGraph> impl_IAudioGraph<D>::QuantumProcessed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAudioGraph>(this, &ABI::Windows::Media::Audio::IAudioGraph::remove_QuantumProcessed, QuantumProcessed(handler));
}

template <typename D> void impl_IAudioGraph<D>::QuantumProcessed(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioGraph)->remove_QuantumProcessed(token));
}

template <typename D> event_token impl_IAudioGraph<D>::UnrecoverableErrorOccurred(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioGraph)->add_UnrecoverableErrorOccurred(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAudioGraph> impl_IAudioGraph<D>::UnrecoverableErrorOccurred(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAudioGraph>(this, &ABI::Windows::Media::Audio::IAudioGraph::remove_UnrecoverableErrorOccurred, UnrecoverableErrorOccurred(handler));
}

template <typename D> void impl_IAudioGraph<D>::UnrecoverableErrorOccurred(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioGraph)->remove_UnrecoverableErrorOccurred(token));
}

template <typename D> uint64_t impl_IAudioGraph<D>::CompletedQuantumCount() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAudioGraph)->get_CompletedQuantumCount(&value));
    return value;
}

template <typename D> Windows::Media::MediaProperties::AudioEncodingProperties impl_IAudioGraph<D>::EncodingProperties() const
{
    Windows::Media::MediaProperties::AudioEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph)->get_EncodingProperties(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IAudioGraph<D>::LatencyInSamples() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IAudioGraph)->get_LatencyInSamples(&value));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IAudioGraph<D>::PrimaryRenderDevice() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph)->get_PrimaryRenderDevice(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::AudioProcessing impl_IAudioGraph<D>::RenderDeviceAudioProcessing() const
{
    Windows::Media::AudioProcessing value {};
    check_hresult(WINRT_SHIM(IAudioGraph)->get_RenderDeviceAudioProcessing(&value));
    return value;
}

template <typename D> int32_t impl_IAudioGraph<D>::SamplesPerQuantum() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IAudioGraph)->get_SamplesPerQuantum(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioFrameInputNode impl_IAudioGraph2<D>::CreateFrameInputNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties, const Windows::Media::Audio::AudioNodeEmitter & emitter) const
{
    Windows::Media::Audio::AudioFrameInputNode frameInputNode { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph2)->abi_CreateFrameInputNodeWithFormatAndEmitter(get_abi(encodingProperties), get_abi(emitter), put_abi(frameInputNode)));
    return frameInputNode;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> impl_IAudioGraph2<D>::CreateDeviceInputNodeAsync(Windows::Media::Capture::MediaCategory category, const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties, const Windows::Devices::Enumeration::DeviceInformation & device, const Windows::Media::Audio::AudioNodeEmitter & emitter) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> result;
    check_hresult(WINRT_SHIM(IAudioGraph2)->abi_CreateDeviceInputNodeWithFormatAndEmitterOnDeviceAsync(category, get_abi(encodingProperties), get_abi(device), get_abi(emitter), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> impl_IAudioGraph2<D>::CreateFileInputNodeAsync(const Windows::Storage::IStorageFile & file, const Windows::Media::Audio::AudioNodeEmitter & emitter) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> result;
    check_hresult(WINRT_SHIM(IAudioGraph2)->abi_CreateFileInputNodeWithEmitterAsync(get_abi(file), get_abi(emitter), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Audio::AudioSubmixNode impl_IAudioGraph2<D>::CreateSubmixNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties, const Windows::Media::Audio::AudioNodeEmitter & emitter) const
{
    Windows::Media::Audio::AudioSubmixNode submixNode { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph2)->abi_CreateSubmixNodeWithFormatAndEmitter(get_abi(encodingProperties), get_abi(emitter), put_abi(submixNode)));
    return submixNode;
}

template <typename D> Windows::Media::Audio::AudioGraphBatchUpdater impl_IAudioGraph2<D>::CreateBatchUpdater() const
{
    Windows::Media::Audio::AudioGraphBatchUpdater updater { nullptr };
    check_hresult(WINRT_SHIM(IAudioGraph2)->abi_CreateBatchUpdater(put_abi(updater)));
    return updater;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> impl_IAudioNode<D>::EffectDefinitions() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> value;
    check_hresult(WINRT_SHIM(IAudioNode)->get_EffectDefinitions(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioNode<D>::OutgoingGain(double value) const
{
    check_hresult(WINRT_SHIM(IAudioNode)->put_OutgoingGain(value));
}

template <typename D> double impl_IAudioNode<D>::OutgoingGain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNode)->get_OutgoingGain(&value));
    return value;
}

template <typename D> Windows::Media::MediaProperties::AudioEncodingProperties impl_IAudioNode<D>::EncodingProperties() const
{
    Windows::Media::MediaProperties::AudioEncodingProperties value { nullptr };
    check_hresult(WINRT_SHIM(IAudioNode)->get_EncodingProperties(put_abi(value)));
    return value;
}

template <typename D> bool impl_IAudioNode<D>::ConsumeInput() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAudioNode)->get_ConsumeInput(&value));
    return value;
}

template <typename D> void impl_IAudioNode<D>::ConsumeInput(bool value) const
{
    check_hresult(WINRT_SHIM(IAudioNode)->put_ConsumeInput(value));
}

template <typename D> void impl_IAudioNode<D>::Start() const
{
    check_hresult(WINRT_SHIM(IAudioNode)->abi_Start());
}

template <typename D> void impl_IAudioNode<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IAudioNode)->abi_Stop());
}

template <typename D> void impl_IAudioNode<D>::Reset() const
{
    check_hresult(WINRT_SHIM(IAudioNode)->abi_Reset());
}

template <typename D> void impl_IAudioNode<D>::DisableEffectsByDefinition(const Windows::Media::Effects::IAudioEffectDefinition & definition) const
{
    check_hresult(WINRT_SHIM(IAudioNode)->abi_DisableEffectsByDefinition(get_abi(definition)));
}

template <typename D> void impl_IAudioNode<D>::EnableEffectsByDefinition(const Windows::Media::Effects::IAudioEffectDefinition & definition) const
{
    check_hresult(WINRT_SHIM(IAudioNode)->abi_EnableEffectsByDefinition(get_abi(definition)));
}

template <typename D> void impl_IAudioNodeWithListener<D>::Listener(const Windows::Media::Audio::AudioNodeListener & value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeWithListener)->put_Listener(get_abi(value)));
}

template <typename D> Windows::Media::Audio::AudioNodeListener impl_IAudioNodeWithListener<D>::Listener() const
{
    Windows::Media::Audio::AudioNodeListener value { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeWithListener)->get_Listener(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::AudioGraphConnection> impl_IAudioInputNode<D>::OutgoingConnections() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::AudioGraphConnection> value;
    check_hresult(WINRT_SHIM(IAudioInputNode)->get_OutgoingConnections(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioInputNode<D>::AddOutgoingConnection(const Windows::Media::Audio::IAudioNode & destination) const
{
    check_hresult(WINRT_SHIM(IAudioInputNode)->abi_AddOutgoingConnection(get_abi(destination)));
}

template <typename D> void impl_IAudioInputNode<D>::AddOutgoingConnection(const Windows::Media::Audio::IAudioNode & destination, double gain) const
{
    check_hresult(WINRT_SHIM(IAudioInputNode)->abi_AddOutgoingConnectionWithGain(get_abi(destination), gain));
}

template <typename D> void impl_IAudioInputNode<D>::RemoveOutgoingConnection(const Windows::Media::Audio::IAudioNode & destination) const
{
    check_hresult(WINRT_SHIM(IAudioInputNode)->abi_RemoveOutgoingConnection(get_abi(destination)));
}

template <typename D> Windows::Media::Audio::AudioNodeEmitter impl_IAudioInputNode2<D>::Emitter() const
{
    Windows::Media::Audio::AudioNodeEmitter value { nullptr };
    check_hresult(WINRT_SHIM(IAudioInputNode2)->get_Emitter(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioFrameInputNode<D>::PlaybackSpeedFactor(double value) const
{
    check_hresult(WINRT_SHIM(IAudioFrameInputNode)->put_PlaybackSpeedFactor(value));
}

template <typename D> double impl_IAudioFrameInputNode<D>::PlaybackSpeedFactor() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioFrameInputNode)->get_PlaybackSpeedFactor(&value));
    return value;
}

template <typename D> void impl_IAudioFrameInputNode<D>::AddFrame(const Windows::Media::AudioFrame & frame) const
{
    check_hresult(WINRT_SHIM(IAudioFrameInputNode)->abi_AddFrame(get_abi(frame)));
}

template <typename D> void impl_IAudioFrameInputNode<D>::DiscardQueuedFrames() const
{
    check_hresult(WINRT_SHIM(IAudioFrameInputNode)->abi_DiscardQueuedFrames());
}

template <typename D> uint64_t impl_IAudioFrameInputNode<D>::QueuedSampleCount() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAudioFrameInputNode)->get_QueuedSampleCount(&value));
    return value;
}

template <typename D> event_token impl_IAudioFrameInputNode<D>::AudioFrameCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::AudioFrameCompletedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioFrameInputNode)->add_AudioFrameCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAudioFrameInputNode> impl_IAudioFrameInputNode<D>::AudioFrameCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::AudioFrameCompletedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAudioFrameInputNode>(this, &ABI::Windows::Media::Audio::IAudioFrameInputNode::remove_AudioFrameCompleted, AudioFrameCompleted(handler));
}

template <typename D> void impl_IAudioFrameInputNode<D>::AudioFrameCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioFrameInputNode)->remove_AudioFrameCompleted(token));
}

template <typename D> event_token impl_IAudioFrameInputNode<D>::QuantumStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioFrameInputNode)->add_QuantumStarted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAudioFrameInputNode> impl_IAudioFrameInputNode<D>::QuantumStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAudioFrameInputNode>(this, &ABI::Windows::Media::Audio::IAudioFrameInputNode::remove_QuantumStarted, QuantumStarted(handler));
}

template <typename D> void impl_IAudioFrameInputNode<D>::QuantumStarted(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioFrameInputNode)->remove_QuantumStarted(token));
}

template <typename D> void impl_IAudioFileInputNode<D>::PlaybackSpeedFactor(double value) const
{
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->put_PlaybackSpeedFactor(value));
}

template <typename D> double impl_IAudioFileInputNode<D>::PlaybackSpeedFactor() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->get_PlaybackSpeedFactor(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IAudioFileInputNode<D>::Position() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioFileInputNode<D>::Seek(const Windows::Foundation::TimeSpan & position) const
{
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->abi_Seek(get_abi(position)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IAudioFileInputNode<D>::StartTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioFileInputNode<D>::StartTime(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->put_StartTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IAudioFileInputNode<D>::EndTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->get_EndTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioFileInputNode<D>::EndTime(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->put_EndTime(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_IAudioFileInputNode<D>::LoopCount() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->get_LoopCount(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioFileInputNode<D>::LoopCount(const optional<int32_t> & value) const
{
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->put_LoopCount(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IAudioFileInputNode<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFile impl_IAudioFileInputNode<D>::SourceFile() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->get_SourceFile(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IAudioFileInputNode<D>::FileCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFileInputNode, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->add_FileCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAudioFileInputNode> impl_IAudioFileInputNode<D>::FileCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFileInputNode, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAudioFileInputNode>(this, &ABI::Windows::Media::Audio::IAudioFileInputNode::remove_FileCompleted, FileCompleted(handler));
}

template <typename D> void impl_IAudioFileInputNode<D>::FileCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IAudioFileInputNode)->remove_FileCompleted(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IAudioDeviceInputNode<D>::Device() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IAudioDeviceInputNode)->get_Device(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IAudioDeviceOutputNode<D>::Device() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IAudioDeviceOutputNode)->get_Device(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::AudioFrame impl_IAudioFrameOutputNode<D>::GetFrame() const
{
    Windows::Media::AudioFrame audioFrame { nullptr };
    check_hresult(WINRT_SHIM(IAudioFrameOutputNode)->abi_GetFrame(put_abi(audioFrame)));
    return audioFrame;
}

template <typename D> Windows::Storage::IStorageFile impl_IAudioFileOutputNode<D>::File() const
{
    Windows::Storage::IStorageFile value;
    check_hresult(WINRT_SHIM(IAudioFileOutputNode)->get_File(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaProperties::MediaEncodingProfile impl_IAudioFileOutputNode<D>::FileEncodingProfile() const
{
    Windows::Media::MediaProperties::MediaEncodingProfile value { nullptr };
    check_hresult(WINRT_SHIM(IAudioFileOutputNode)->get_FileEncodingProfile(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Transcoding::TranscodeFailureReason> impl_IAudioFileOutputNode<D>::FinalizeAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Transcoding::TranscodeFailureReason> result;
    check_hresult(WINRT_SHIM(IAudioFileOutputNode)->abi_FinalizeAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Media::AudioFrame impl_IAudioFrameCompletedEventArgs<D>::Frame() const
{
    Windows::Media::AudioFrame value { nullptr };
    check_hresult(WINRT_SHIM(IAudioFrameCompletedEventArgs)->get_Frame(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IFrameInputNodeQuantumStartedEventArgs<D>::RequiredSamples() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IFrameInputNodeQuantumStartedEventArgs)->get_RequiredSamples(&value));
    return value;
}

template <typename D> Windows::Media::Audio::IAudioNode impl_IAudioGraphConnection<D>::Destination() const
{
    Windows::Media::Audio::IAudioNode value;
    check_hresult(WINRT_SHIM(IAudioGraphConnection)->get_Destination(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioGraphConnection<D>::Gain(double value) const
{
    check_hresult(WINRT_SHIM(IAudioGraphConnection)->put_Gain(value));
}

template <typename D> double impl_IAudioGraphConnection<D>::Gain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioGraphConnection)->get_Gain(&value));
    return value;
}

template <typename D> double impl_IEqualizerBand<D>::Bandwidth() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEqualizerBand)->get_Bandwidth(&value));
    return value;
}

template <typename D> void impl_IEqualizerBand<D>::Bandwidth(double value) const
{
    check_hresult(WINRT_SHIM(IEqualizerBand)->put_Bandwidth(value));
}

template <typename D> double impl_IEqualizerBand<D>::FrequencyCenter() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEqualizerBand)->get_FrequencyCenter(&value));
    return value;
}

template <typename D> void impl_IEqualizerBand<D>::FrequencyCenter(double value) const
{
    check_hresult(WINRT_SHIM(IEqualizerBand)->put_FrequencyCenter(value));
}

template <typename D> double impl_IEqualizerBand<D>::Gain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEqualizerBand)->get_Gain(&value));
    return value;
}

template <typename D> void impl_IEqualizerBand<D>::Gain(double value) const
{
    check_hresult(WINRT_SHIM(IEqualizerBand)->put_Gain(value));
}

template <typename D> Windows::Media::Audio::EqualizerEffectDefinition impl_IEqualizerEffectDefinitionFactory<D>::Create(const Windows::Media::Audio::AudioGraph & audioGraph) const
{
    Windows::Media::Audio::EqualizerEffectDefinition value { nullptr };
    check_hresult(WINRT_SHIM(IEqualizerEffectDefinitionFactory)->abi_Create(get_abi(audioGraph), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::ReverbEffectDefinition impl_IReverbEffectDefinitionFactory<D>::Create(const Windows::Media::Audio::AudioGraph & audioGraph) const
{
    Windows::Media::Audio::ReverbEffectDefinition value { nullptr };
    check_hresult(WINRT_SHIM(IReverbEffectDefinitionFactory)->abi_Create(get_abi(audioGraph), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::EchoEffectDefinition impl_IEchoEffectDefinitionFactory<D>::Create(const Windows::Media::Audio::AudioGraph & audioGraph) const
{
    Windows::Media::Audio::EchoEffectDefinition value { nullptr };
    check_hresult(WINRT_SHIM(IEchoEffectDefinitionFactory)->abi_Create(get_abi(audioGraph), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::LimiterEffectDefinition impl_ILimiterEffectDefinitionFactory<D>::Create(const Windows::Media::Audio::AudioGraph & audioGraph) const
{
    Windows::Media::Audio::LimiterEffectDefinition value { nullptr };
    check_hresult(WINRT_SHIM(ILimiterEffectDefinitionFactory)->abi_Create(get_abi(audioGraph), put_abi(value)));
    return value;
}

template <typename D> double impl_IAudioNodeEmitterConeProperties<D>::InnerAngle() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitterConeProperties)->get_InnerAngle(&value));
    return value;
}

template <typename D> double impl_IAudioNodeEmitterConeProperties<D>::OuterAngle() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitterConeProperties)->get_OuterAngle(&value));
    return value;
}

template <typename D> double impl_IAudioNodeEmitterConeProperties<D>::OuterAngleGain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitterConeProperties)->get_OuterAngleGain(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterShapeKind impl_IAudioNodeEmitterShape<D>::Kind() const
{
    Windows::Media::Audio::AudioNodeEmitterShapeKind value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitterShape)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterConeProperties impl_IAudioNodeEmitterShape<D>::ConeProperties() const
{
    Windows::Media::Audio::AudioNodeEmitterConeProperties value { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeEmitterShape)->get_ConeProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterShape impl_IAudioNodeEmitterShapeStatics<D>::CreateCone(double innerAngle, double outerAngle, double outerAngleGain) const
{
    Windows::Media::Audio::AudioNodeEmitterShape shape { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeEmitterShapeStatics)->abi_CreateCone(innerAngle, outerAngle, outerAngleGain, put_abi(shape)));
    return shape;
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterShape impl_IAudioNodeEmitterShapeStatics<D>::CreateOmnidirectional() const
{
    Windows::Media::Audio::AudioNodeEmitterShape shape { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeEmitterShapeStatics)->abi_CreateOmnidirectional(put_abi(shape)));
    return shape;
}

template <typename D> double impl_IAudioNodeEmitterNaturalDecayModelProperties<D>::UnityGainDistance() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitterNaturalDecayModelProperties)->get_UnityGainDistance(&value));
    return value;
}

template <typename D> double impl_IAudioNodeEmitterNaturalDecayModelProperties<D>::CutoffDistance() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitterNaturalDecayModelProperties)->get_CutoffDistance(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterDecayKind impl_IAudioNodeEmitterDecayModel<D>::Kind() const
{
    Windows::Media::Audio::AudioNodeEmitterDecayKind value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitterDecayModel)->get_Kind(&value));
    return value;
}

template <typename D> double impl_IAudioNodeEmitterDecayModel<D>::MinGain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitterDecayModel)->get_MinGain(&value));
    return value;
}

template <typename D> double impl_IAudioNodeEmitterDecayModel<D>::MaxGain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitterDecayModel)->get_MaxGain(&value));
    return value;
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterNaturalDecayModelProperties impl_IAudioNodeEmitterDecayModel<D>::NaturalProperties() const
{
    Windows::Media::Audio::AudioNodeEmitterNaturalDecayModelProperties value { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeEmitterDecayModel)->get_NaturalProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterDecayModel impl_IAudioNodeEmitterDecayModelStatics<D>::CreateNatural(double minGain, double maxGain, double unityGainDistance, double cutoffDistance) const
{
    Windows::Media::Audio::AudioNodeEmitterDecayModel decayModel { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeEmitterDecayModelStatics)->abi_CreateNatural(minGain, maxGain, unityGainDistance, cutoffDistance, put_abi(decayModel)));
    return decayModel;
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterDecayModel impl_IAudioNodeEmitterDecayModelStatics<D>::CreateCustom(double minGain, double maxGain) const
{
    Windows::Media::Audio::AudioNodeEmitterDecayModel decayModel { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeEmitterDecayModelStatics)->abi_CreateCustom(minGain, maxGain, put_abi(decayModel)));
    return decayModel;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IAudioNodeEmitter<D>::Position() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioNodeEmitter<D>::Position(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->put_Position(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IAudioNodeEmitter<D>::Direction() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->get_Direction(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioNodeEmitter<D>::Direction(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->put_Direction(get_abi(value)));
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterShape impl_IAudioNodeEmitter<D>::Shape() const
{
    Windows::Media::Audio::AudioNodeEmitterShape value { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->get_Shape(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Audio::AudioNodeEmitterDecayModel impl_IAudioNodeEmitter<D>::DecayModel() const
{
    Windows::Media::Audio::AudioNodeEmitterDecayModel value { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->get_DecayModel(put_abi(value)));
    return value;
}

template <typename D> double impl_IAudioNodeEmitter<D>::Gain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->get_Gain(&value));
    return value;
}

template <typename D> void impl_IAudioNodeEmitter<D>::Gain(double value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->put_Gain(value));
}

template <typename D> double impl_IAudioNodeEmitter<D>::DistanceScale() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->get_DistanceScale(&value));
    return value;
}

template <typename D> void impl_IAudioNodeEmitter<D>::DistanceScale(double value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->put_DistanceScale(value));
}

template <typename D> double impl_IAudioNodeEmitter<D>::DopplerScale() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->get_DopplerScale(&value));
    return value;
}

template <typename D> void impl_IAudioNodeEmitter<D>::DopplerScale(double value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->put_DopplerScale(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IAudioNodeEmitter<D>::DopplerVelocity() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->get_DopplerVelocity(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioNodeEmitter<D>::DopplerVelocity(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->put_DopplerVelocity(get_abi(value)));
}

template <typename D> bool impl_IAudioNodeEmitter<D>::IsDopplerDisabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitter)->get_IsDopplerDisabled(&value));
    return value;
}

template <typename D> Windows::Media::Audio::SpatialAudioModel impl_IAudioNodeEmitter2<D>::SpatialAudioModel() const
{
    Windows::Media::Audio::SpatialAudioModel value {};
    check_hresult(WINRT_SHIM(IAudioNodeEmitter2)->get_SpatialAudioModel(&value));
    return value;
}

template <typename D> void impl_IAudioNodeEmitter2<D>::SpatialAudioModel(Windows::Media::Audio::SpatialAudioModel value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeEmitter2)->put_SpatialAudioModel(value));
}

template <typename D> Windows::Media::Audio::AudioNodeEmitter impl_IAudioNodeEmitterFactory<D>::CreateAudioNodeEmitter(const Windows::Media::Audio::AudioNodeEmitterShape & shape, const Windows::Media::Audio::AudioNodeEmitterDecayModel & decayModel, Windows::Media::Audio::AudioNodeEmitterSettings settings) const
{
    Windows::Media::Audio::AudioNodeEmitter emitter { nullptr };
    check_hresult(WINRT_SHIM(IAudioNodeEmitterFactory)->abi_CreateAudioNodeEmitter(get_abi(shape), get_abi(decayModel), settings, put_abi(emitter)));
    return emitter;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IAudioNodeListener<D>::Position() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IAudioNodeListener)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioNodeListener<D>::Position(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeListener)->put_Position(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::quaternion impl_IAudioNodeListener<D>::Orientation() const
{
    Windows::Foundation::Numerics::quaternion value {};
    check_hresult(WINRT_SHIM(IAudioNodeListener)->get_Orientation(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioNodeListener<D>::Orientation(const Windows::Foundation::Numerics::quaternion & value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeListener)->put_Orientation(get_abi(value)));
}

template <typename D> double impl_IAudioNodeListener<D>::SpeedOfSound() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAudioNodeListener)->get_SpeedOfSound(&value));
    return value;
}

template <typename D> void impl_IAudioNodeListener<D>::SpeedOfSound(double value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeListener)->put_SpeedOfSound(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_IAudioNodeListener<D>::DopplerVelocity() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(IAudioNodeListener)->get_DopplerVelocity(put_abi(value)));
    return value;
}

template <typename D> void impl_IAudioNodeListener<D>::DopplerVelocity(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(IAudioNodeListener)->put_DopplerVelocity(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::EqualizerBand> impl_IEqualizerEffectDefinition<D>::Bands() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::EqualizerBand> value;
    check_hresult(WINRT_SHIM(IEqualizerEffectDefinition)->get_Bands(put_abi(value)));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::WetDryMix(double value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_WetDryMix(value));
}

template <typename D> double impl_IReverbEffectDefinition<D>::WetDryMix() const
{
    double value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_WetDryMix(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::ReflectionsDelay(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_ReflectionsDelay(value));
}

template <typename D> uint32_t impl_IReverbEffectDefinition<D>::ReflectionsDelay() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_ReflectionsDelay(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::ReverbDelay(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_ReverbDelay(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::ReverbDelay() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_ReverbDelay(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::RearDelay(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_RearDelay(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::RearDelay() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_RearDelay(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::PositionLeft(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_PositionLeft(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::PositionLeft() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_PositionLeft(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::PositionRight(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_PositionRight(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::PositionRight() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_PositionRight(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::PositionMatrixLeft(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_PositionMatrixLeft(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::PositionMatrixLeft() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_PositionMatrixLeft(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::PositionMatrixRight(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_PositionMatrixRight(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::PositionMatrixRight() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_PositionMatrixRight(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::EarlyDiffusion(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_EarlyDiffusion(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::EarlyDiffusion() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_EarlyDiffusion(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::LateDiffusion(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_LateDiffusion(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::LateDiffusion() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_LateDiffusion(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::LowEQGain(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_LowEQGain(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::LowEQGain() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_LowEQGain(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::LowEQCutoff(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_LowEQCutoff(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::LowEQCutoff() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_LowEQCutoff(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::HighEQGain(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_HighEQGain(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::HighEQGain() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_HighEQGain(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::HighEQCutoff(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_HighEQCutoff(value));
}

template <typename D> uint8_t impl_IReverbEffectDefinition<D>::HighEQCutoff() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_HighEQCutoff(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::RoomFilterFreq(double value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_RoomFilterFreq(value));
}

template <typename D> double impl_IReverbEffectDefinition<D>::RoomFilterFreq() const
{
    double value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_RoomFilterFreq(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::RoomFilterMain(double value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_RoomFilterMain(value));
}

template <typename D> double impl_IReverbEffectDefinition<D>::RoomFilterMain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_RoomFilterMain(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::RoomFilterHF(double value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_RoomFilterHF(value));
}

template <typename D> double impl_IReverbEffectDefinition<D>::RoomFilterHF() const
{
    double value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_RoomFilterHF(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::ReflectionsGain(double value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_ReflectionsGain(value));
}

template <typename D> double impl_IReverbEffectDefinition<D>::ReflectionsGain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_ReflectionsGain(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::ReverbGain(double value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_ReverbGain(value));
}

template <typename D> double impl_IReverbEffectDefinition<D>::ReverbGain() const
{
    double value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_ReverbGain(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::DecayTime(double value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_DecayTime(value));
}

template <typename D> double impl_IReverbEffectDefinition<D>::DecayTime() const
{
    double value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_DecayTime(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::Density(double value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_Density(value));
}

template <typename D> double impl_IReverbEffectDefinition<D>::Density() const
{
    double value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_Density(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::RoomSize(double value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_RoomSize(value));
}

template <typename D> double impl_IReverbEffectDefinition<D>::RoomSize() const
{
    double value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_RoomSize(&value));
    return value;
}

template <typename D> void impl_IReverbEffectDefinition<D>::DisableLateField(bool value) const
{
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->put_DisableLateField(value));
}

template <typename D> bool impl_IReverbEffectDefinition<D>::DisableLateField() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IReverbEffectDefinition)->get_DisableLateField(&value));
    return value;
}

template <typename D> void impl_IEchoEffectDefinition<D>::WetDryMix(double value) const
{
    check_hresult(WINRT_SHIM(IEchoEffectDefinition)->put_WetDryMix(value));
}

template <typename D> double impl_IEchoEffectDefinition<D>::WetDryMix() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEchoEffectDefinition)->get_WetDryMix(&value));
    return value;
}

template <typename D> void impl_IEchoEffectDefinition<D>::Feedback(double value) const
{
    check_hresult(WINRT_SHIM(IEchoEffectDefinition)->put_Feedback(value));
}

template <typename D> double impl_IEchoEffectDefinition<D>::Feedback() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEchoEffectDefinition)->get_Feedback(&value));
    return value;
}

template <typename D> void impl_IEchoEffectDefinition<D>::Delay(double value) const
{
    check_hresult(WINRT_SHIM(IEchoEffectDefinition)->put_Delay(value));
}

template <typename D> double impl_IEchoEffectDefinition<D>::Delay() const
{
    double value {};
    check_hresult(WINRT_SHIM(IEchoEffectDefinition)->get_Delay(&value));
    return value;
}

template <typename D> void impl_ILimiterEffectDefinition<D>::Release(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ILimiterEffectDefinition)->put_Release(value));
}

template <typename D> uint32_t impl_ILimiterEffectDefinition<D>::Release() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ILimiterEffectDefinition)->get_Release(&value));
    return value;
}

template <typename D> void impl_ILimiterEffectDefinition<D>::Loudness(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ILimiterEffectDefinition)->put_Loudness(value));
}

template <typename D> uint32_t impl_ILimiterEffectDefinition<D>::Loudness() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ILimiterEffectDefinition)->get_Loudness(&value));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioGraphResult> AudioGraph::CreateAsync(const Windows::Media::Audio::AudioGraphSettings & settings)
{
    return get_activation_factory<AudioGraph, IAudioGraphStatics>().CreateAsync(settings);
}

inline AudioGraphSettings::AudioGraphSettings(Windows::Media::Render::AudioRenderCategory audioRenderCategory) :
    AudioGraphSettings(get_activation_factory<AudioGraphSettings, IAudioGraphSettingsFactory>().Create(audioRenderCategory))
{}

inline AudioNodeEmitter::AudioNodeEmitter() :
    AudioNodeEmitter(activate_instance<AudioNodeEmitter>())
{}

inline AudioNodeEmitter::AudioNodeEmitter(const Windows::Media::Audio::AudioNodeEmitterShape & shape, const Windows::Media::Audio::AudioNodeEmitterDecayModel & decayModel, Windows::Media::Audio::AudioNodeEmitterSettings settings) :
    AudioNodeEmitter(get_activation_factory<AudioNodeEmitter, IAudioNodeEmitterFactory>().CreateAudioNodeEmitter(shape, decayModel, settings))
{}

inline Windows::Media::Audio::AudioNodeEmitterDecayModel AudioNodeEmitterDecayModel::CreateNatural(double minGain, double maxGain, double unityGainDistance, double cutoffDistance)
{
    return get_activation_factory<AudioNodeEmitterDecayModel, IAudioNodeEmitterDecayModelStatics>().CreateNatural(minGain, maxGain, unityGainDistance, cutoffDistance);
}

inline Windows::Media::Audio::AudioNodeEmitterDecayModel AudioNodeEmitterDecayModel::CreateCustom(double minGain, double maxGain)
{
    return get_activation_factory<AudioNodeEmitterDecayModel, IAudioNodeEmitterDecayModelStatics>().CreateCustom(minGain, maxGain);
}

inline Windows::Media::Audio::AudioNodeEmitterShape AudioNodeEmitterShape::CreateCone(double innerAngle, double outerAngle, double outerAngleGain)
{
    return get_activation_factory<AudioNodeEmitterShape, IAudioNodeEmitterShapeStatics>().CreateCone(innerAngle, outerAngle, outerAngleGain);
}

inline Windows::Media::Audio::AudioNodeEmitterShape AudioNodeEmitterShape::CreateOmnidirectional()
{
    return get_activation_factory<AudioNodeEmitterShape, IAudioNodeEmitterShapeStatics>().CreateOmnidirectional();
}

inline AudioNodeListener::AudioNodeListener() :
    AudioNodeListener(activate_instance<AudioNodeListener>())
{}

inline EchoEffectDefinition::EchoEffectDefinition(const Windows::Media::Audio::AudioGraph & audioGraph) :
    EchoEffectDefinition(get_activation_factory<EchoEffectDefinition, IEchoEffectDefinitionFactory>().Create(audioGraph))
{}

inline EqualizerEffectDefinition::EqualizerEffectDefinition(const Windows::Media::Audio::AudioGraph & audioGraph) :
    EqualizerEffectDefinition(get_activation_factory<EqualizerEffectDefinition, IEqualizerEffectDefinitionFactory>().Create(audioGraph))
{}

inline LimiterEffectDefinition::LimiterEffectDefinition(const Windows::Media::Audio::AudioGraph & audioGraph) :
    LimiterEffectDefinition(get_activation_factory<LimiterEffectDefinition, ILimiterEffectDefinitionFactory>().Create(audioGraph))
{}

inline ReverbEffectDefinition::ReverbEffectDefinition(const Windows::Media::Audio::AudioGraph & audioGraph) :
    ReverbEffectDefinition(get_activation_factory<ReverbEffectDefinition, IReverbEffectDefinitionFactory>().Create(audioGraph))
{}

}

}
#pragma warning(pop)
