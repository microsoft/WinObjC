// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.PlayTo.3.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs> : produce_base<D, Windows::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs>
{
    HRESULT __stdcall get_Time(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Time());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IMuteChangeRequestedEventArgs> : produce_base<D, Windows::Media::PlayTo::IMuteChangeRequestedEventArgs>
{
    HRESULT __stdcall get_Mute(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlayToConnection> : produce_base<D, Windows::Media::PlayTo::IPlayToConnection>
{
    HRESULT __stdcall get_State(Windows::Media::PlayTo::PlayToConnectionState * value) noexcept override
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

    HRESULT __stdcall add_StateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_Transferred(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Transferred(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Transferred(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Transferred(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Error(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionErrorEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Error(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionErrorEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Error(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Error(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs> : produce_base<D, Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs>
{
    HRESULT __stdcall get_Code(Windows::Media::PlayTo::PlayToConnectionError * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
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
struct produce<D, Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs> : produce_base<D, Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs>
{
    HRESULT __stdcall get_PreviousState(Windows::Media::PlayTo::PlayToConnectionState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviousState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentState(Windows::Media::PlayTo::PlayToConnectionState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs> : produce_base<D, Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs>
{
    HRESULT __stdcall get_PreviousSource(impl::abi_arg_out<Windows::Media::PlayTo::IPlayToSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviousSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentSource(impl::abi_arg_out<Windows::Media::PlayTo::IPlayToSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentSource());
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
struct produce<D, Windows::Media::PlayTo::IPlayToManager> : produce_base<D, Windows::Media::PlayTo::IPlayToManager>
{
    HRESULT __stdcall add_SourceRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SourceSelected(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceSelectedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceSelected(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceSelectedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceSelected(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceSelected(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultSourceSelection(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultSourceSelection(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultSourceSelection(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultSourceSelection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlayToManagerStatics> : produce_base<D, Windows::Media::PlayTo::IPlayToManagerStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::Media::PlayTo::IPlayToManager> playToManager) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *playToManager = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *playToManager = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowPlayToUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowPlayToUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlayToReceiver> : produce_base<D, Windows::Media::PlayTo::IPlayToReceiver>
{
    HRESULT __stdcall add_PlayRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PlayRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlayRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlayRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PauseRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PauseRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PauseRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PauseRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SourceChangeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::SourceChangeRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceChangeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::SourceChangeRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceChangeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceChangeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PlaybackRateChangeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PlaybackRateChangeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlaybackRateChangeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRateChangeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CurrentTimeChangeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CurrentTimeChangeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CurrentTimeChangeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentTimeChangeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MuteChangeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::MuteChangeRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MuteChangeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::MuteChangeRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MuteChangeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MuteChangeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VolumeChangeRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::VolumeChangeRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VolumeChangeRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::VolumeChangeRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VolumeChangeRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VolumeChangeRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TimeUpdateRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TimeUpdateRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TimeUpdateRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimeUpdateRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StopRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StopRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StopRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyVolumeChange(double volume, bool mute) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyVolumeChange(volume, mute);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyRateChange(double rate) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyRateChange(rate);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyLoadedMetadata() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyLoadedMetadata();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyTimeUpdate(impl::abi_arg_in<Windows::Foundation::TimeSpan> currentTime) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyTimeUpdate(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&currentTime));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyDurationChange(impl::abi_arg_in<Windows::Foundation::TimeSpan> duration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyDurationChange(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifySeeking() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifySeeking();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifySeeked() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifySeeked();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyPaused() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyPaused();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyPlaying() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyPlaying();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyEnded() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyEnded();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyError() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyError();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyStopped() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyStopped();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FriendlyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FriendlyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SupportsImage(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportsImage(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportsImage(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportsImage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SupportsAudio(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportsAudio(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportsAudio(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportsAudio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SupportsVideo(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportsVideo(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportsVideo(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportsVideo());
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall abi_StartAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().StopAsync());
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlayToSource> : produce_base<D, Windows::Media::PlayTo::IPlayToSource>
{
    HRESULT __stdcall get_Connection(impl::abi_arg_out<Windows::Media::PlayTo::IPlayToConnection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Connection());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Next(impl::abi_arg_out<Windows::Media::PlayTo::IPlayToSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Next());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Next(impl::abi_arg_in<Windows::Media::PlayTo::IPlayToSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Next(*reinterpret_cast<const Windows::Media::PlayTo::PlayToSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PlayNext() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlayNext();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlayToSourceDeferral> : produce_base<D, Windows::Media::PlayTo::IPlayToSourceDeferral>
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
struct produce<D, Windows::Media::PlayTo::IPlayToSourceRequest> : produce_base<D, Windows::Media::PlayTo::IPlayToSourceRequest>
{
    HRESULT __stdcall get_Deadline(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Deadline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DisplayErrorString(impl::abi_arg_in<hstring> errorString) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayErrorString(*reinterpret_cast<const hstring *>(&errorString));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Media::PlayTo::IPlayToSourceDeferral> deferral) noexcept override
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

    HRESULT __stdcall abi_SetSource(impl::abi_arg_in<Windows::Media::PlayTo::IPlayToSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSource(*reinterpret_cast<const Windows::Media::PlayTo::PlayToSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlayToSourceRequestedEventArgs> : produce_base<D, Windows::Media::PlayTo::IPlayToSourceRequestedEventArgs>
{
    HRESULT __stdcall get_SourceRequest(impl::abi_arg_out<Windows::Media::PlayTo::IPlayToSourceRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceRequest());
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
struct produce<D, Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs> : produce_base<D, Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs>
{
    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Icon(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamWithContentType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Icon());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportsImage(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportsImage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportsAudio(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportsAudio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportsVideo(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportsVideo());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlayToSourceWithPreferredSourceUri> : produce_base<D, Windows::Media::PlayTo::IPlayToSourceWithPreferredSourceUri>
{
    HRESULT __stdcall get_PreferredSourceUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferredSourceUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreferredSourceUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredSourceUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs> : produce_base<D, Windows::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs>
{
    HRESULT __stdcall get_Rate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::PlayTo::ISourceChangeRequestedEventArgs> : produce_base<D, Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>
{
    HRESULT __stdcall get_Stream(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamWithContentType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Stream());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Author(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Author());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Album(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Album());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Genre(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Genre());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Date(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Date());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall get_Rating(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rating());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
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
struct produce<D, Windows::Media::PlayTo::IVolumeChangeRequestedEventArgs> : produce_base<D, Windows::Media::PlayTo::IVolumeChangeRequestedEventArgs>
{
    HRESULT __stdcall get_Volume(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Volume());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::PlayTo {

template <typename D> Windows::Storage::Streams::IRandomAccessStreamWithContentType impl_ISourceChangeRequestedEventArgs<D>::Stream() const
{
    Windows::Storage::Streams::IRandomAccessStreamWithContentType value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Stream(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISourceChangeRequestedEventArgs<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Title(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISourceChangeRequestedEventArgs<D>::Author() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Author(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISourceChangeRequestedEventArgs<D>::Album() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Album(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISourceChangeRequestedEventArgs<D>::Genre() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Genre(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISourceChangeRequestedEventArgs<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Description(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_ISourceChangeRequestedEventArgs<D>::Date() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Date(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_ISourceChangeRequestedEventArgs<D>::Thumbnail() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_ISourceChangeRequestedEventArgs<D>::Rating() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Rating(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_ISourceChangeRequestedEventArgs<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(ISourceChangeRequestedEventArgs)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> double impl_IPlaybackRateChangeRequestedEventArgs<D>::Rate() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPlaybackRateChangeRequestedEventArgs)->get_Rate(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_ICurrentTimeChangeRequestedEventArgs<D>::Time() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ICurrentTimeChangeRequestedEventArgs)->get_Time(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMuteChangeRequestedEventArgs<D>::Mute() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMuteChangeRequestedEventArgs)->get_Mute(&value));
    return value;
}

template <typename D> double impl_IVolumeChangeRequestedEventArgs<D>::Volume() const
{
    double value {};
    check_hresult(WINRT_SHIM(IVolumeChangeRequestedEventArgs)->get_Volume(&value));
    return value;
}

template <typename D> event_token impl_IPlayToReceiver<D>::PlayRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->add_PlayRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToReceiver> impl_IPlayToReceiver<D>::PlayRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPlayToReceiver>(this, &ABI::Windows::Media::PlayTo::IPlayToReceiver::remove_PlayRequested, PlayRequested(handler));
}

template <typename D> void impl_IPlayToReceiver<D>::PlayRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->remove_PlayRequested(token));
}

template <typename D> event_token impl_IPlayToReceiver<D>::PauseRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->add_PauseRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToReceiver> impl_IPlayToReceiver<D>::PauseRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPlayToReceiver>(this, &ABI::Windows::Media::PlayTo::IPlayToReceiver::remove_PauseRequested, PauseRequested(handler));
}

template <typename D> void impl_IPlayToReceiver<D>::PauseRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->remove_PauseRequested(token));
}

template <typename D> event_token impl_IPlayToReceiver<D>::SourceChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::SourceChangeRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->add_SourceChangeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToReceiver> impl_IPlayToReceiver<D>::SourceChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::SourceChangeRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToReceiver>(this, &ABI::Windows::Media::PlayTo::IPlayToReceiver::remove_SourceChangeRequested, SourceChangeRequested(handler));
}

template <typename D> void impl_IPlayToReceiver<D>::SourceChangeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->remove_SourceChangeRequested(token));
}

template <typename D> event_token impl_IPlayToReceiver<D>::PlaybackRateChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->add_PlaybackRateChangeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToReceiver> impl_IPlayToReceiver<D>::PlaybackRateChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToReceiver>(this, &ABI::Windows::Media::PlayTo::IPlayToReceiver::remove_PlaybackRateChangeRequested, PlaybackRateChangeRequested(handler));
}

template <typename D> void impl_IPlayToReceiver<D>::PlaybackRateChangeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->remove_PlaybackRateChangeRequested(token));
}

template <typename D> event_token impl_IPlayToReceiver<D>::CurrentTimeChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->add_CurrentTimeChangeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToReceiver> impl_IPlayToReceiver<D>::CurrentTimeChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToReceiver>(this, &ABI::Windows::Media::PlayTo::IPlayToReceiver::remove_CurrentTimeChangeRequested, CurrentTimeChangeRequested(handler));
}

template <typename D> void impl_IPlayToReceiver<D>::CurrentTimeChangeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->remove_CurrentTimeChangeRequested(token));
}

template <typename D> event_token impl_IPlayToReceiver<D>::MuteChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::MuteChangeRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->add_MuteChangeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToReceiver> impl_IPlayToReceiver<D>::MuteChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::MuteChangeRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToReceiver>(this, &ABI::Windows::Media::PlayTo::IPlayToReceiver::remove_MuteChangeRequested, MuteChangeRequested(handler));
}

template <typename D> void impl_IPlayToReceiver<D>::MuteChangeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->remove_MuteChangeRequested(token));
}

template <typename D> event_token impl_IPlayToReceiver<D>::VolumeChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::VolumeChangeRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->add_VolumeChangeRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToReceiver> impl_IPlayToReceiver<D>::VolumeChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::VolumeChangeRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToReceiver>(this, &ABI::Windows::Media::PlayTo::IPlayToReceiver::remove_VolumeChangeRequested, VolumeChangeRequested(handler));
}

template <typename D> void impl_IPlayToReceiver<D>::VolumeChangeRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->remove_VolumeChangeRequested(token));
}

template <typename D> event_token impl_IPlayToReceiver<D>::TimeUpdateRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->add_TimeUpdateRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToReceiver> impl_IPlayToReceiver<D>::TimeUpdateRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPlayToReceiver>(this, &ABI::Windows::Media::PlayTo::IPlayToReceiver::remove_TimeUpdateRequested, TimeUpdateRequested(handler));
}

template <typename D> void impl_IPlayToReceiver<D>::TimeUpdateRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->remove_TimeUpdateRequested(token));
}

template <typename D> event_token impl_IPlayToReceiver<D>::StopRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->add_StopRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToReceiver> impl_IPlayToReceiver<D>::StopRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPlayToReceiver>(this, &ABI::Windows::Media::PlayTo::IPlayToReceiver::remove_StopRequested, StopRequested(handler));
}

template <typename D> void impl_IPlayToReceiver<D>::StopRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->remove_StopRequested(token));
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyVolumeChange(double volume, bool mute) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyVolumeChange(volume, mute));
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyRateChange(double rate) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyRateChange(rate));
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyLoadedMetadata() const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyLoadedMetadata());
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyTimeUpdate(const Windows::Foundation::TimeSpan & currentTime) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyTimeUpdate(get_abi(currentTime)));
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyDurationChange(const Windows::Foundation::TimeSpan & duration) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyDurationChange(get_abi(duration)));
}

template <typename D> void impl_IPlayToReceiver<D>::NotifySeeking() const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifySeeking());
}

template <typename D> void impl_IPlayToReceiver<D>::NotifySeeked() const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifySeeked());
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyPaused() const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyPaused());
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyPlaying() const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyPlaying());
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyEnded() const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyEnded());
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyError() const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyError());
}

template <typename D> void impl_IPlayToReceiver<D>::NotifyStopped() const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_NotifyStopped());
}

template <typename D> hstring impl_IPlayToReceiver<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPlayToReceiver)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPlayToReceiver<D>::FriendlyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->put_FriendlyName(get_abi(value)));
}

template <typename D> void impl_IPlayToReceiver<D>::SupportsImage(bool value) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->put_SupportsImage(value));
}

template <typename D> bool impl_IPlayToReceiver<D>::SupportsImage() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->get_SupportsImage(&value));
    return value;
}

template <typename D> void impl_IPlayToReceiver<D>::SupportsAudio(bool value) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->put_SupportsAudio(value));
}

template <typename D> bool impl_IPlayToReceiver<D>::SupportsAudio() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->get_SupportsAudio(&value));
    return value;
}

template <typename D> void impl_IPlayToReceiver<D>::SupportsVideo(bool value) const
{
    check_hresult(WINRT_SHIM(IPlayToReceiver)->put_SupportsVideo(value));
}

template <typename D> bool impl_IPlayToReceiver<D>::SupportsVideo() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPlayToReceiver)->get_SupportsVideo(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IPlayToReceiver<D>::Properties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IPlayToReceiver)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPlayToReceiver<D>::StartAsync() const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_StartAsync(put_abi(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPlayToReceiver<D>::StopAsync() const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IPlayToReceiver)->abi_StopAsync(put_abi(action)));
    return action;
}

template <typename D> Windows::Media::PlayTo::PlayToConnection impl_IPlayToSource<D>::Connection() const
{
    Windows::Media::PlayTo::PlayToConnection value { nullptr };
    check_hresult(WINRT_SHIM(IPlayToSource)->get_Connection(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::PlayTo::PlayToSource impl_IPlayToSource<D>::Next() const
{
    Windows::Media::PlayTo::PlayToSource value { nullptr };
    check_hresult(WINRT_SHIM(IPlayToSource)->get_Next(put_abi(value)));
    return value;
}

template <typename D> void impl_IPlayToSource<D>::Next(const Windows::Media::PlayTo::PlayToSource & value) const
{
    check_hresult(WINRT_SHIM(IPlayToSource)->put_Next(get_abi(value)));
}

template <typename D> void impl_IPlayToSource<D>::PlayNext() const
{
    check_hresult(WINRT_SHIM(IPlayToSource)->abi_PlayNext());
}

template <typename D> Windows::Foundation::Uri impl_IPlayToSourceWithPreferredSourceUri<D>::PreferredSourceUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IPlayToSourceWithPreferredSourceUri)->get_PreferredSourceUri(put_abi(value)));
    return value;
}

template <typename D> void impl_IPlayToSourceWithPreferredSourceUri<D>::PreferredSourceUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IPlayToSourceWithPreferredSourceUri)->put_PreferredSourceUri(get_abi(value)));
}

template <typename D> Windows::Media::PlayTo::PlayToConnectionState impl_IPlayToConnectionStateChangedEventArgs<D>::PreviousState() const
{
    Windows::Media::PlayTo::PlayToConnectionState value {};
    check_hresult(WINRT_SHIM(IPlayToConnectionStateChangedEventArgs)->get_PreviousState(&value));
    return value;
}

template <typename D> Windows::Media::PlayTo::PlayToConnectionState impl_IPlayToConnectionStateChangedEventArgs<D>::CurrentState() const
{
    Windows::Media::PlayTo::PlayToConnectionState value {};
    check_hresult(WINRT_SHIM(IPlayToConnectionStateChangedEventArgs)->get_CurrentState(&value));
    return value;
}

template <typename D> Windows::Media::PlayTo::PlayToSource impl_IPlayToConnectionTransferredEventArgs<D>::PreviousSource() const
{
    Windows::Media::PlayTo::PlayToSource value { nullptr };
    check_hresult(WINRT_SHIM(IPlayToConnectionTransferredEventArgs)->get_PreviousSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::PlayTo::PlayToSource impl_IPlayToConnectionTransferredEventArgs<D>::CurrentSource() const
{
    Windows::Media::PlayTo::PlayToSource value { nullptr };
    check_hresult(WINRT_SHIM(IPlayToConnectionTransferredEventArgs)->get_CurrentSource(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::PlayTo::PlayToConnectionError impl_IPlayToConnectionErrorEventArgs<D>::Code() const
{
    Windows::Media::PlayTo::PlayToConnectionError value {};
    check_hresult(WINRT_SHIM(IPlayToConnectionErrorEventArgs)->get_Code(&value));
    return value;
}

template <typename D> hstring impl_IPlayToConnectionErrorEventArgs<D>::Message() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPlayToConnectionErrorEventArgs)->get_Message(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::PlayTo::PlayToConnectionState impl_IPlayToConnection<D>::State() const
{
    Windows::Media::PlayTo::PlayToConnectionState value {};
    check_hresult(WINRT_SHIM(IPlayToConnection)->get_State(&value));
    return value;
}

template <typename D> event_token impl_IPlayToConnection<D>::StateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToConnection)->add_StateChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToConnection> impl_IPlayToConnection<D>::StateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToConnection>(this, &ABI::Windows::Media::PlayTo::IPlayToConnection::remove_StateChanged, StateChanged(handler));
}

template <typename D> void impl_IPlayToConnection<D>::StateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToConnection)->remove_StateChanged(token));
}

template <typename D> event_token impl_IPlayToConnection<D>::Transferred(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToConnection)->add_Transferred(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToConnection> impl_IPlayToConnection<D>::Transferred(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToConnection>(this, &ABI::Windows::Media::PlayTo::IPlayToConnection::remove_Transferred, Transferred(handler));
}

template <typename D> void impl_IPlayToConnection<D>::Transferred(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToConnection)->remove_Transferred(token));
}

template <typename D> event_token impl_IPlayToConnection<D>::Error(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionErrorEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToConnection)->add_Error(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToConnection> impl_IPlayToConnection<D>::Error(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionErrorEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToConnection>(this, &ABI::Windows::Media::PlayTo::IPlayToConnection::remove_Error, Error(handler));
}

template <typename D> void impl_IPlayToConnection<D>::Error(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToConnection)->remove_Error(token));
}

template <typename D> hstring impl_IPlayToSourceSelectedEventArgs<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPlayToSourceSelectedEventArgs)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamWithContentType impl_IPlayToSourceSelectedEventArgs<D>::Icon() const
{
    Windows::Storage::Streams::IRandomAccessStreamWithContentType value;
    check_hresult(WINRT_SHIM(IPlayToSourceSelectedEventArgs)->get_Icon(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPlayToSourceSelectedEventArgs<D>::SupportsImage() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPlayToSourceSelectedEventArgs)->get_SupportsImage(&value));
    return value;
}

template <typename D> bool impl_IPlayToSourceSelectedEventArgs<D>::SupportsAudio() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPlayToSourceSelectedEventArgs)->get_SupportsAudio(&value));
    return value;
}

template <typename D> bool impl_IPlayToSourceSelectedEventArgs<D>::SupportsVideo() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPlayToSourceSelectedEventArgs)->get_SupportsVideo(&value));
    return value;
}

template <typename D> void impl_IPlayToSourceDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IPlayToSourceDeferral)->abi_Complete());
}

template <typename D> Windows::Foundation::DateTime impl_IPlayToSourceRequest<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IPlayToSourceRequest)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> void impl_IPlayToSourceRequest<D>::DisplayErrorString(hstring_view errorString) const
{
    check_hresult(WINRT_SHIM(IPlayToSourceRequest)->abi_DisplayErrorString(get_abi(errorString)));
}

template <typename D> Windows::Media::PlayTo::PlayToSourceDeferral impl_IPlayToSourceRequest<D>::GetDeferral() const
{
    Windows::Media::PlayTo::PlayToSourceDeferral deferral { nullptr };
    check_hresult(WINRT_SHIM(IPlayToSourceRequest)->abi_GetDeferral(put_abi(deferral)));
    return deferral;
}

template <typename D> void impl_IPlayToSourceRequest<D>::SetSource(const Windows::Media::PlayTo::PlayToSource & value) const
{
    check_hresult(WINRT_SHIM(IPlayToSourceRequest)->abi_SetSource(get_abi(value)));
}

template <typename D> Windows::Media::PlayTo::PlayToSourceRequest impl_IPlayToSourceRequestedEventArgs<D>::SourceRequest() const
{
    Windows::Media::PlayTo::PlayToSourceRequest value { nullptr };
    check_hresult(WINRT_SHIM(IPlayToSourceRequestedEventArgs)->get_SourceRequest(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IPlayToManager<D>::SourceRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToManager)->add_SourceRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToManager> impl_IPlayToManager<D>::SourceRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToManager>(this, &ABI::Windows::Media::PlayTo::IPlayToManager::remove_SourceRequested, SourceRequested(handler));
}

template <typename D> void impl_IPlayToManager<D>::SourceRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToManager)->remove_SourceRequested(token));
}

template <typename D> event_token impl_IPlayToManager<D>::SourceSelected(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceSelectedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPlayToManager)->add_SourceSelected(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPlayToManager> impl_IPlayToManager<D>::SourceSelected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceSelectedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPlayToManager>(this, &ABI::Windows::Media::PlayTo::IPlayToManager::remove_SourceSelected, SourceSelected(handler));
}

template <typename D> void impl_IPlayToManager<D>::SourceSelected(event_token token) const
{
    check_hresult(WINRT_SHIM(IPlayToManager)->remove_SourceSelected(token));
}

template <typename D> void impl_IPlayToManager<D>::DefaultSourceSelection(bool value) const
{
    check_hresult(WINRT_SHIM(IPlayToManager)->put_DefaultSourceSelection(value));
}

template <typename D> bool impl_IPlayToManager<D>::DefaultSourceSelection() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPlayToManager)->get_DefaultSourceSelection(&value));
    return value;
}

template <typename D> Windows::Media::PlayTo::PlayToManager impl_IPlayToManagerStatics<D>::GetForCurrentView() const
{
    Windows::Media::PlayTo::PlayToManager playToManager { nullptr };
    check_hresult(WINRT_SHIM(IPlayToManagerStatics)->abi_GetForCurrentView(put_abi(playToManager)));
    return playToManager;
}

template <typename D> void impl_IPlayToManagerStatics<D>::ShowPlayToUI() const
{
    check_hresult(WINRT_SHIM(IPlayToManagerStatics)->abi_ShowPlayToUI());
}

inline Windows::Media::PlayTo::PlayToManager PlayToManager::GetForCurrentView()
{
    return get_activation_factory<PlayToManager, IPlayToManagerStatics>().GetForCurrentView();
}

inline void PlayToManager::ShowPlayToUI()
{
    get_activation_factory<PlayToManager, IPlayToManagerStatics>().ShowPlayToUI();
}

inline PlayToReceiver::PlayToReceiver() :
    PlayToReceiver(activate_instance<PlayToReceiver>())
{}

}

}
#pragma warning(pop)
