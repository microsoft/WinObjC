// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Media.Casting.3.h"
#include "internal/Windows.UI.Composition.3.h"
#include "internal/Windows.Media.MediaProperties.3.h"
#include "internal/Windows.Media.Protection.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Media.Core.3.h"
#include "internal/Windows.Media.Playback.3.h"
#include "Windows.Media.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"
#include "Windows.Media.Core.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Playback::IBackgroundMediaPlayerStatics> : produce_base<D, Windows::Media::Playback::IBackgroundMediaPlayerStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::Media::Playback::IMediaPlayer> player) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *player = detach_abi(this->shim().Current());
            return S_OK;
        }
        catch (...)
        {
            *player = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MessageReceivedFromBackground(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MessageReceivedFromBackground(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MessageReceivedFromBackground(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageReceivedFromBackground(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MessageReceivedFromForeground(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MessageReceivedFromForeground(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MessageReceivedFromForeground(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageReceivedFromForeground(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendMessageToBackground(impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendMessageToBackground(*reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendMessageToForeground(impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SendMessageToForeground(*reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsMediaPlaying(bool * isMediaPlaying) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *isMediaPlaying = detach_abi(this->shim().IsMediaPlaying());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Shutdown() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Shutdown();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs> : produce_base<D, Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs>
{
    HRESULT __stdcall get_NewItem(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OldItem(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldItem());
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
struct produce<D, Windows::Media::Playback::IMediaBreak> : produce_base<D, Windows::Media::Playback::IMediaBreak>
{
    HRESULT __stdcall get_PlaybackList(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackList> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackList());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PresentationPosition(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PresentationPosition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InsertionMethod(Windows::Media::Playback::MediaBreakInsertionMethod * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InsertionMethod());
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

    HRESULT __stdcall get_CanStart(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanStart());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanStart(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanStart(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaBreakEndedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaBreakEndedEventArgs>
{
    HRESULT __stdcall get_MediaBreak(impl::abi_arg_out<Windows::Media::Playback::IMediaBreak> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaBreak());
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
struct produce<D, Windows::Media::Playback::IMediaBreakFactory> : produce_base<D, Windows::Media::Playback::IMediaBreakFactory>
{
    HRESULT __stdcall abi_Create(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod, impl::abi_arg_out<Windows::Media::Playback::IMediaBreak> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(insertionMethod));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithPresentationPosition(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod, impl::abi_arg_in<Windows::Foundation::TimeSpan> presentationPosition, impl::abi_arg_out<Windows::Media::Playback::IMediaBreak> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithPresentationPosition(insertionMethod, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&presentationPosition)));
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
struct produce<D, Windows::Media::Playback::IMediaBreakManager> : produce_base<D, Windows::Media::Playback::IMediaBreakManager>
{
    HRESULT __stdcall add_BreaksSeekedOver(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSeekedOverEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BreaksSeekedOver(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSeekedOverEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BreaksSeekedOver(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreaksSeekedOver(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BreakStarted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakStartedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BreakStarted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakStartedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BreakStarted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreakStarted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BreakEnded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakEndedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BreakEnded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakEndedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BreakEnded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreakEnded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BreakSkipped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSkippedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BreakSkipped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSkippedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BreakSkipped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BreakSkipped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentBreak(impl::abi_arg_out<Windows::Media::Playback::IMediaBreak> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentBreak());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackSession(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackSession> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackSession());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PlayBreak(impl::abi_arg_in<Windows::Media::Playback::IMediaBreak> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlayBreak(*reinterpret_cast<const Windows::Media::Playback::MediaBreak *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SkipCurrentBreak() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SkipCurrentBreak();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaBreakSchedule> : produce_base<D, Windows::Media::Playback::IMediaBreakSchedule>
{
    HRESULT __stdcall add_ScheduleChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakSchedule, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ScheduleChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakSchedule, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ScheduleChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScheduleChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertMidrollBreak(impl::abi_arg_in<Windows::Media::Playback::IMediaBreak> mediaBreak) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertMidrollBreak(*reinterpret_cast<const Windows::Media::Playback::MediaBreak *>(&mediaBreak));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveMidrollBreak(impl::abi_arg_in<Windows::Media::Playback::IMediaBreak> mediaBreak) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveMidrollBreak(*reinterpret_cast<const Windows::Media::Playback::MediaBreak *>(&mediaBreak));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MidrollBreaks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MidrollBreaks());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PrerollBreak(impl::abi_arg_in<Windows::Media::Playback::IMediaBreak> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrerollBreak(*reinterpret_cast<const Windows::Media::Playback::MediaBreak *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrerollBreak(impl::abi_arg_out<Windows::Media::Playback::IMediaBreak> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrerollBreak());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PostrollBreak(impl::abi_arg_in<Windows::Media::Playback::IMediaBreak> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PostrollBreak(*reinterpret_cast<const Windows::Media::Playback::MediaBreak *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PostrollBreak(impl::abi_arg_out<Windows::Media::Playback::IMediaBreak> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PostrollBreak());
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
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaBreakSeekedOverEventArgs> : produce_base<D, Windows::Media::Playback::IMediaBreakSeekedOverEventArgs>
{
    HRESULT __stdcall get_SeekedOverBreaks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SeekedOverBreaks());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OldPosition(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewPosition(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaBreakSkippedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaBreakSkippedEventArgs>
{
    HRESULT __stdcall get_MediaBreak(impl::abi_arg_out<Windows::Media::Playback::IMediaBreak> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaBreak());
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
struct produce<D, Windows::Media::Playback::IMediaBreakStartedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaBreakStartedEventArgs>
{
    HRESULT __stdcall get_MediaBreak(impl::abi_arg_out<Windows::Media::Playback::IMediaBreak> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaBreak());
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
struct produce<D, Windows::Media::Playback::IMediaEnginePlaybackSource> : produce_base<D, Windows::Media::Playback::IMediaEnginePlaybackSource>
{
    HRESULT __stdcall get_CurrentItem(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPlaybackSource(impl::abi_arg_in<Windows::Media::Playback::IMediaPlaybackSource> source) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPlaybackSource(*reinterpret_cast<const Windows::Media::Playback::IMediaPlaybackSource *>(&source));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaItemDisplayProperties> : produce_base<D, Windows::Media::Playback::IMediaItemDisplayProperties>
{
    HRESULT __stdcall get_Type(Windows::Media::MediaPlaybackType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Type(Windows::Media::MediaPlaybackType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MusicProperties(impl::abi_arg_out<Windows::Media::IMusicDisplayProperties> value) noexcept override
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

    HRESULT __stdcall get_VideoProperties(impl::abi_arg_out<Windows::Media::IVideoDisplayProperties> value) noexcept override
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

    HRESULT __stdcall put_Thumbnail(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<const Windows::Storage::Streams::RandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearAll() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearAll();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManager> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManager>
{
    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaPlayer(impl::abi_arg_out<Windows::Media::Playback::IMediaPlayer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaPlayer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlayBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlayBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PauseBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PauseBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NextBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NextBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreviousBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviousBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FastForwardBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FastForwardBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RewindBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RewindBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShuffleBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShuffleBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoRepeatModeBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoRepeatModeBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PositionBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RateBehavior(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RateBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PlayReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PlayReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlayReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlayReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PauseReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PauseReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PauseReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PauseReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NextReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().NextReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NextReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NextReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PreviousReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PreviousReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PreviousReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreviousReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_FastForwardReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().FastForwardReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_FastForwardReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FastForwardReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RewindReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RewindReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RewindReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RewindReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ShuffleReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ShuffleReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ShuffleReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShuffleReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AutoRepeatModeReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AutoRepeatModeReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AutoRepeatModeReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRepeatModeReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PositionReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PositionReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PositionReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RateReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RateReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RateReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RateReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoRepeatMode(Windows::Media::MediaPlaybackAutoRepeatMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoRepeatMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior>
{
    HRESULT __stdcall get_CommandManager(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommandManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnablingRule(Windows::Media::Playback::MediaCommandEnablingRule * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnablingRule());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnablingRule(Windows::Media::Playback::MediaCommandEnablingRule value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnablingRule(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_IsEnabledChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().IsEnabledChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_IsEnabledChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabledChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackRate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsShuffleRequested(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsShuffleRequested());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackItem> : produce_base<D, Windows::Media::Playback::IMediaPlaybackItem>
{
    HRESULT __stdcall add_AudioTracksChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AudioTracksChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AudioTracksChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioTracksChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VideoTracksChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VideoTracksChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VideoTracksChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VideoTracksChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TimedMetadataTracksChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TimedMetadataTracksChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TimedMetadataTracksChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimedMetadataTracksChanged(token);
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

    HRESULT __stdcall get_AudioTracks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Core::AudioTrack>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioTracks());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoTracks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Core::VideoTrack>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoTracks());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimedMetadataTracks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Core::TimedMetadataTrack>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimedMetadataTracks());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackItem2> : produce_base<D, Windows::Media::Playback::IMediaPlaybackItem2>
{
    HRESULT __stdcall get_BreakSchedule(impl::abi_arg_out<Windows::Media::Playback::IMediaBreakSchedule> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BreakSchedule());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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

    HRESULT __stdcall get_DurationLimit(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DurationLimit());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanSkip(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanSkip());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanSkip(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanSkip(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDisplayProperties(impl::abi_arg_out<Windows::Media::Playback::IMediaItemDisplayProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDisplayProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ApplyDisplayProperties(impl::abi_arg_in<Windows::Media::Playback::IMediaItemDisplayProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplyDisplayProperties(*reinterpret_cast<const Windows::Media::Playback::MediaItemDisplayProperties *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlaybackItemError> : produce_base<D, Windows::Media::Playback::IMediaPlaybackItemError>
{
    HRESULT __stdcall get_ErrorCode(Windows::Media::Playback::MediaPlaybackItemErrorCode * value) noexcept override
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackItemFactory> : produce_base<D, Windows::Media::Playback::IMediaPlaybackItemFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Media::Core::IMediaSource2> source, impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Media::Core::MediaSource *>(&source)));
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackItemFactory2> : produce_base<D, Windows::Media::Playback::IMediaPlaybackItemFactory2>
{
    HRESULT __stdcall abi_CreateWithStartTime(impl::abi_arg_in<Windows::Media::Core::IMediaSource2> source, impl::abi_arg_in<Windows::Foundation::TimeSpan> startTime, impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithStartTime(*reinterpret_cast<const Windows::Media::Core::MediaSource *>(&source), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&startTime)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithStartTimeAndDurationLimit(impl::abi_arg_in<Windows::Media::Core::IMediaSource2> source, impl::abi_arg_in<Windows::Foundation::TimeSpan> startTime, impl::abi_arg_in<Windows::Foundation::TimeSpan> durationLimit, impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWithStartTimeAndDurationLimit(*reinterpret_cast<const Windows::Media::Core::MediaSource *>(&source), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&startTime), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&durationLimit)));
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs>
{
    HRESULT __stdcall get_Item(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Item());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Error(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItemError> value) noexcept override
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackItemOpenedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlaybackItemOpenedEventArgs>
{
    HRESULT __stdcall get_Item(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Item());
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackItemStatics> : produce_base<D, Windows::Media::Playback::IMediaPlaybackItemStatics>
{
    HRESULT __stdcall abi_FindFromMediaSource(impl::abi_arg_in<Windows::Media::Core::IMediaSource2> source, impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindFromMediaSource(*reinterpret_cast<const Windows::Media::Core::MediaSource *>(&source)));
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
struct produce<D, Windows::Media::Playback::IMediaPlaybackList> : produce_base<D, Windows::Media::Playback::IMediaPlaybackList>
{
    HRESULT __stdcall add_ItemFailed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemFailedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ItemFailed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemFailedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemFailed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemFailed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CurrentItemChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CurrentItemChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CurrentItemChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentItemChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ItemOpened(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ItemOpened(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ItemOpened(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemOpened(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Items(impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::Media::Playback::MediaPlaybackItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Items());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoRepeatEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoRepeatEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoRepeatEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoRepeatEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShuffleEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShuffleEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ShuffleEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShuffleEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentItem(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentItemIndex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentItemIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveNext(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> item) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *item = detach_abi(this->shim().MoveNext());
            return S_OK;
        }
        catch (...)
        {
            *item = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MovePrevious(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> item) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *item = detach_abi(this->shim().MovePrevious());
            return S_OK;
        }
        catch (...)
        {
            *item = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveTo(uint32_t itemIndex, impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> item) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *item = detach_abi(this->shim().MoveTo(itemIndex));
            return S_OK;
        }
        catch (...)
        {
            *item = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlaybackList2> : produce_base<D, Windows::Media::Playback::IMediaPlaybackList2>
{
    HRESULT __stdcall get_MaxPrefetchTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPrefetchTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxPrefetchTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxPrefetchTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartingItem(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartingItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartingItem(impl::abi_arg_in<Windows::Media::Playback::IMediaPlaybackItem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartingItem(*reinterpret_cast<const Windows::Media::Playback::MediaPlaybackItem *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShuffledItems(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaPlaybackItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShuffledItems());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetShuffledItems(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Media::Playback::MediaPlaybackItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetShuffledItems(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Media::Playback::MediaPlaybackItem> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlaybackSession> : produce_base<D, Windows::Media::Playback::IMediaPlaybackSession>
{
    HRESULT __stdcall add_PlaybackStateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PlaybackStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlaybackStateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PlaybackRateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PlaybackRateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlaybackRateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SeekCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SeekCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SeekCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SeekCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BufferingStarted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BufferingStarted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BufferingStarted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingStarted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BufferingEnded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BufferingEnded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BufferingEnded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingEnded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BufferingProgressChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BufferingProgressChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BufferingProgressChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingProgressChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DownloadProgressChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DownloadProgressChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DownloadProgressChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadProgressChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NaturalDurationChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().NaturalDurationChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NaturalDurationChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NaturalDurationChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PositionChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PositionChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PositionChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NaturalVideoSizeChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().NaturalVideoSizeChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NaturalVideoSizeChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NaturalVideoSizeChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaPlayer(impl::abi_arg_out<Windows::Media::Playback::IMediaPlayer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaPlayer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NaturalDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NaturalDuration());
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

    HRESULT __stdcall put_Position(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackState(Windows::Media::Playback::MediaPlaybackState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackState());
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

    HRESULT __stdcall get_CanPause(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanPause());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsProtected(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsProtected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackRate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PlaybackRate(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRate(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BufferingProgress(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BufferingProgress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DownloadProgress(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DownloadProgress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NaturalVideoHeight(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NaturalVideoHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NaturalVideoWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NaturalVideoWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NormalizedSourceRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NormalizedSourceRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NormalizedSourceRect(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NormalizedSourceRect(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StereoscopicVideoPackingMode(Windows::Media::MediaProperties::StereoscopicVideoPackingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StereoscopicVideoPackingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StereoscopicVideoPackingMode(Windows::Media::MediaProperties::StereoscopicVideoPackingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StereoscopicVideoPackingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlaybackSource> : produce_base<D, Windows::Media::Playback::IMediaPlaybackSource>
{};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList> : produce_base<D, Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList>
{
    HRESULT __stdcall add_PresentationModeChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PresentationModeChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PresentationModeChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PresentationModeChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPresentationMode(uint32_t index, Windows::Media::Playback::TimedMetadataTrackPresentationMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetPresentationMode(index));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPresentationMode(uint32_t index, Windows::Media::Playback::TimedMetadataTrackPresentationMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPresentationMode(index, value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlayer> : produce_base<D, Windows::Media::Playback::IMediaPlayer>
{
    HRESULT __stdcall get_AutoPlay(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoPlay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoPlay(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoPlay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NaturalDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NaturalDuration());
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

    HRESULT __stdcall put_Position(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Position(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BufferingProgress(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BufferingProgress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentState(Windows::Media::Playback::MediaPlayerState * value) noexcept override
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

    HRESULT __stdcall get_CanPause(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanPause());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsLoopingEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsLoopingEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsLoopingEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsLoopingEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsProtected(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsProtected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMuted(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMuted());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsMuted(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMuted(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackRate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PlaybackRate(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRate(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Volume(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Volume(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackMediaMarkers(impl::abi_arg_out<Windows::Media::Playback::IPlaybackMediaMarkerSequence> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackMediaMarkers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MediaOpened(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MediaOpened(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MediaOpened(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaOpened(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MediaEnded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MediaEnded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MediaEnded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaEnded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MediaFailed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerFailedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MediaFailed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerFailedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MediaFailed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaFailed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CurrentStateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CurrentStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CurrentStateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PlaybackMediaMarkerReached(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PlaybackMediaMarkerReached(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PlaybackMediaMarkerReached(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackMediaMarkerReached(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MediaPlayerRateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerRateChangedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MediaPlayerRateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerRateChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MediaPlayerRateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaPlayerRateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VolumeChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VolumeChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VolumeChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VolumeChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SeekCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SeekCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SeekCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SeekCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BufferingStarted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BufferingStarted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BufferingStarted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingStarted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BufferingEnded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BufferingEnded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BufferingEnded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BufferingEnded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Play() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Play();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Pause() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetUriSource(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetUriSource(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlayer2> : produce_base<D, Windows::Media::Playback::IMediaPlayer2>
{
    HRESULT __stdcall get_SystemMediaTransportControls(impl::abi_arg_out<Windows::Media::ISystemMediaTransportControls> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemMediaTransportControls());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioCategory(Windows::Media::Playback::MediaPlayerAudioCategory * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioCategory(Windows::Media::Playback::MediaPlayerAudioCategory value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioCategory(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioDeviceType(Windows::Media::Playback::MediaPlayerAudioDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioDeviceType(Windows::Media::Playback::MediaPlayerAudioDeviceType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioDeviceType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlayer3> : produce_base<D, Windows::Media::Playback::IMediaPlayer3>
{
    HRESULT __stdcall add_IsMutedChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().IsMutedChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_IsMutedChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMutedChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SourceChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SourceChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioBalance(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioBalance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioBalance(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioBalance(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RealTimePlayback(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RealTimePlayback());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RealTimePlayback(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RealTimePlayback(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StereoscopicVideoRenderMode(Windows::Media::Playback::StereoscopicVideoRenderMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StereoscopicVideoRenderMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StereoscopicVideoRenderMode(Windows::Media::Playback::StereoscopicVideoRenderMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StereoscopicVideoRenderMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BreakManager(impl::abi_arg_out<Windows::Media::Playback::IMediaBreakManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BreakManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CommandManager(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackCommandManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommandManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudioDevice(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudioDevice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudioDevice(impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudioDevice(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimelineController(impl::abi_arg_out<Windows::Media::IMediaTimelineController> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimelineController());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TimelineController(impl::abi_arg_in<Windows::Media::IMediaTimelineController> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimelineController(*reinterpret_cast<const Windows::Media::MediaTimelineController *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimelineControllerPositionOffset(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimelineControllerPositionOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TimelineControllerPositionOffset(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimelineControllerPositionOffset(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaybackSession(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackSession> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackSession());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StepForwardOneFrame() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StepForwardOneFrame();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StepBackwardOneFrame() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StepBackwardOneFrame();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAsCastingSource(impl::abi_arg_out<Windows::Media::Casting::ICastingSource> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAsCastingSource());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlayer4> : produce_base<D, Windows::Media::Playback::IMediaPlayer4>
{
    HRESULT __stdcall abi_SetSurfaceSize(impl::abi_arg_in<Windows::Foundation::Size> size) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSurfaceSize(*reinterpret_cast<const Windows::Foundation::Size *>(&size));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSurface(impl::abi_arg_in<Windows::UI::Composition::ICompositor> compositor, impl::abi_arg_out<Windows::Media::Playback::IMediaPlayerSurface> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSurface(*reinterpret_cast<const Windows::UI::Composition::Compositor *>(&compositor)));
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
struct produce<D, Windows::Media::Playback::IMediaPlayerDataReceivedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlayerDataReceivedEventArgs>
{
    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
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
struct produce<D, Windows::Media::Playback::IMediaPlayerEffects> : produce_base<D, Windows::Media::Playback::IMediaPlayerEffects>
{
    HRESULT __stdcall abi_AddAudioEffect(impl::abi_arg_in<hstring> activatableClassId, bool effectOptional, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAudioEffect(*reinterpret_cast<const hstring *>(&activatableClassId), effectOptional, *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&configuration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAllEffects() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAllEffects();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlayerEffects2> : produce_base<D, Windows::Media::Playback::IMediaPlayerEffects2>
{
    HRESULT __stdcall abi_AddVideoEffect(impl::abi_arg_in<hstring> activatableClassId, bool effectOptional, impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> effectConfiguration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddVideoEffect(*reinterpret_cast<const hstring *>(&activatableClassId), effectOptional, *reinterpret_cast<const Windows::Foundation::Collections::IPropertySet *>(&effectConfiguration));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlayerFailedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlayerFailedEventArgs>
{
    HRESULT __stdcall get_Error(Windows::Media::Playback::MediaPlayerError * value) noexcept override
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

    HRESULT __stdcall get_ExtendedErrorCode(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorMessage());
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
struct produce<D, Windows::Media::Playback::IMediaPlayerRateChangedEventArgs> : produce_base<D, Windows::Media::Playback::IMediaPlayerRateChangedEventArgs>
{
    HRESULT __stdcall get_NewRate(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlayerSource> : produce_base<D, Windows::Media::Playback::IMediaPlayerSource>
{
    HRESULT __stdcall get_ProtectionManager(impl::abi_arg_out<Windows::Media::Protection::IMediaProtectionManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtectionManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProtectionManager(impl::abi_arg_in<Windows::Media::Protection::IMediaProtectionManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtectionManager(*reinterpret_cast<const Windows::Media::Protection::MediaProtectionManager *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFileSource(impl::abi_arg_in<Windows::Storage::IStorageFile> file) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFileSource(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetStreamSource(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStreamSource(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetMediaSource(impl::abi_arg_in<Windows::Media::Core::IMediaSource> source) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMediaSource(*reinterpret_cast<const Windows::Media::Core::IMediaSource *>(&source));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlayerSource2> : produce_base<D, Windows::Media::Playback::IMediaPlayerSource2>
{
    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Media::Playback::IMediaPlaybackSource> value) noexcept override
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

    HRESULT __stdcall put_Source(impl::abi_arg_in<Windows::Media::Playback::IMediaPlaybackSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<const Windows::Media::Playback::IMediaPlaybackSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IMediaPlayerSurface> : produce_base<D, Windows::Media::Playback::IMediaPlayerSurface>
{
    HRESULT __stdcall get_CompositionSurface(impl::abi_arg_out<Windows::UI::Composition::ICompositionSurface> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompositionSurface());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Compositor(impl::abi_arg_out<Windows::UI::Composition::ICompositor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Compositor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaPlayer(impl::abi_arg_out<Windows::Media::Playback::IMediaPlayer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaPlayer());
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
struct produce<D, Windows::Media::Playback::IPlaybackMediaMarker> : produce_base<D, Windows::Media::Playback::IPlaybackMediaMarker>
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

    HRESULT __stdcall get_MediaMarkerType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaMarkerType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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
};

template <typename D>
struct produce<D, Windows::Media::Playback::IPlaybackMediaMarkerFactory> : produce_base<D, Windows::Media::Playback::IPlaybackMediaMarkerFactory>
{
    HRESULT __stdcall abi_CreateFromTime(impl::abi_arg_in<Windows::Foundation::TimeSpan> value, impl::abi_arg_out<Windows::Media::Playback::IPlaybackMediaMarker> marker) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *marker = detach_abi(this->shim().CreateFromTime(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *marker = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::TimeSpan> value, impl::abi_arg_in<hstring> mediaMarketType, impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::Media::Playback::IPlaybackMediaMarker> marker) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *marker = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value), *reinterpret_cast<const hstring *>(&mediaMarketType), *reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *marker = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::IPlaybackMediaMarkerReachedEventArgs> : produce_base<D, Windows::Media::Playback::IPlaybackMediaMarkerReachedEventArgs>
{
    HRESULT __stdcall get_PlaybackMediaMarker(impl::abi_arg_out<Windows::Media::Playback::IPlaybackMediaMarker> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaybackMediaMarker());
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
struct produce<D, Windows::Media::Playback::IPlaybackMediaMarkerSequence> : produce_base<D, Windows::Media::Playback::IPlaybackMediaMarkerSequence>
{
    HRESULT __stdcall get_Size(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Insert(impl::abi_arg_in<Windows::Media::Playback::IPlaybackMediaMarker> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Insert(*reinterpret_cast<const Windows::Media::Playback::PlaybackMediaMarker *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs> : produce_base<D, Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs>
{
    HRESULT __stdcall get_Track(impl::abi_arg_out<Windows::Media::Core::ITimedMetadataTrack> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Track());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OldPresentationMode(Windows::Media::Playback::TimedMetadataTrackPresentationMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldPresentationMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewPresentationMode(Windows::Media::Playback::TimedMetadataTrackPresentationMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewPresentationMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::Playback {

template <typename D> Windows::Foundation::TimeSpan impl_IPlaybackMediaMarker<D>::Time() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPlaybackMediaMarker)->get_Time(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPlaybackMediaMarker<D>::MediaMarkerType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPlaybackMediaMarker)->get_MediaMarkerType(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPlaybackMediaMarker<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPlaybackMediaMarker)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::PlaybackMediaMarker impl_IPlaybackMediaMarkerFactory<D>::CreateFromTime(const Windows::Foundation::TimeSpan & value) const
{
    Windows::Media::Playback::PlaybackMediaMarker marker { nullptr };
    check_hresult(WINRT_SHIM(IPlaybackMediaMarkerFactory)->abi_CreateFromTime(get_abi(value), put_abi(marker)));
    return marker;
}

template <typename D> Windows::Media::Playback::PlaybackMediaMarker impl_IPlaybackMediaMarkerFactory<D>::Create(const Windows::Foundation::TimeSpan & value, hstring_view mediaMarketType, hstring_view text) const
{
    Windows::Media::Playback::PlaybackMediaMarker marker { nullptr };
    check_hresult(WINRT_SHIM(IPlaybackMediaMarkerFactory)->abi_Create(get_abi(value), get_abi(mediaMarketType), get_abi(text), put_abi(marker)));
    return marker;
}

template <typename D> uint32_t impl_IPlaybackMediaMarkerSequence<D>::Size() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPlaybackMediaMarkerSequence)->get_Size(&value));
    return value;
}

template <typename D> void impl_IPlaybackMediaMarkerSequence<D>::Insert(const Windows::Media::Playback::PlaybackMediaMarker & value) const
{
    check_hresult(WINRT_SHIM(IPlaybackMediaMarkerSequence)->abi_Insert(get_abi(value)));
}

template <typename D> void impl_IPlaybackMediaMarkerSequence<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IPlaybackMediaMarkerSequence)->abi_Clear());
}

template <typename D> Windows::Media::Playback::MediaPlayerError impl_IMediaPlayerFailedEventArgs<D>::Error() const
{
    Windows::Media::Playback::MediaPlayerError value {};
    check_hresult(WINRT_SHIM(IMediaPlayerFailedEventArgs)->get_Error(&value));
    return value;
}

template <typename D> HRESULT impl_IMediaPlayerFailedEventArgs<D>::ExtendedErrorCode() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IMediaPlayerFailedEventArgs)->get_ExtendedErrorCode(&value));
    return value;
}

template <typename D> hstring impl_IMediaPlayerFailedEventArgs<D>::ErrorMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaPlayerFailedEventArgs)->get_ErrorMessage(put_abi(value)));
    return value;
}

template <typename D> double impl_IMediaPlayerRateChangedEventArgs<D>::NewRate() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaPlayerRateChangedEventArgs)->get_NewRate(&value));
    return value;
}

template <typename D> Windows::Media::Playback::PlaybackMediaMarker impl_IPlaybackMediaMarkerReachedEventArgs<D>::PlaybackMediaMarker() const
{
    Windows::Media::Playback::PlaybackMediaMarker value { nullptr };
    check_hresult(WINRT_SHIM(IPlaybackMediaMarkerReachedEventArgs)->get_PlaybackMediaMarker(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IMediaPlayerDataReceivedEventArgs<D>::Data() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayerDataReceivedEventArgs)->get_Data(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlayer<D>::AutoPlay() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_AutoPlay(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer<D>::AutoPlay(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->put_AutoPlay(value));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaPlayer<D>::NaturalDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_NaturalDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaPlayer<D>::Position() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlayer<D>::Position(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->put_Position(get_abi(value)));
}

template <typename D> double impl_IMediaPlayer<D>::BufferingProgress() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_BufferingProgress(&value));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlayerState impl_IMediaPlayer<D>::CurrentState() const
{
    Windows::Media::Playback::MediaPlayerState value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_CurrentState(&value));
    return value;
}

template <typename D> bool impl_IMediaPlayer<D>::CanSeek() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_CanSeek(&value));
    return value;
}

template <typename D> bool impl_IMediaPlayer<D>::CanPause() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_CanPause(&value));
    return value;
}

template <typename D> bool impl_IMediaPlayer<D>::IsLoopingEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_IsLoopingEnabled(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer<D>::IsLoopingEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->put_IsLoopingEnabled(value));
}

template <typename D> bool impl_IMediaPlayer<D>::IsProtected() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_IsProtected(&value));
    return value;
}

template <typename D> bool impl_IMediaPlayer<D>::IsMuted() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_IsMuted(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer<D>::IsMuted(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->put_IsMuted(value));
}

template <typename D> double impl_IMediaPlayer<D>::PlaybackRate() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_PlaybackRate(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer<D>::PlaybackRate(double value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->put_PlaybackRate(value));
}

template <typename D> double impl_IMediaPlayer<D>::Volume() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_Volume(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer<D>::Volume(double value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->put_Volume(value));
}

template <typename D> Windows::Media::Playback::PlaybackMediaMarkerSequence impl_IMediaPlayer<D>::PlaybackMediaMarkers() const
{
    Windows::Media::Playback::PlaybackMediaMarkerSequence value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayer)->get_PlaybackMediaMarkers(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMediaPlayer<D>::MediaOpened(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_MediaOpened(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::MediaOpened(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_MediaOpened, MediaOpened(value));
}

template <typename D> void impl_IMediaPlayer<D>::MediaOpened(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_MediaOpened(token));
}

template <typename D> event_token impl_IMediaPlayer<D>::MediaEnded(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_MediaEnded(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::MediaEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_MediaEnded, MediaEnded(value));
}

template <typename D> void impl_IMediaPlayer<D>::MediaEnded(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_MediaEnded(token));
}

template <typename D> event_token impl_IMediaPlayer<D>::MediaFailed(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerFailedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_MediaFailed(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::MediaFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerFailedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_MediaFailed, MediaFailed(value));
}

template <typename D> void impl_IMediaPlayer<D>::MediaFailed(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_MediaFailed(token));
}

template <typename D> event_token impl_IMediaPlayer<D>::CurrentStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_CurrentStateChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::CurrentStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_CurrentStateChanged, CurrentStateChanged(value));
}

template <typename D> void impl_IMediaPlayer<D>::CurrentStateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_CurrentStateChanged(token));
}

template <typename D> event_token impl_IMediaPlayer<D>::PlaybackMediaMarkerReached(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_PlaybackMediaMarkerReached(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::PlaybackMediaMarkerReached(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_PlaybackMediaMarkerReached, PlaybackMediaMarkerReached(value));
}

template <typename D> void impl_IMediaPlayer<D>::PlaybackMediaMarkerReached(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_PlaybackMediaMarkerReached(token));
}

template <typename D> event_token impl_IMediaPlayer<D>::MediaPlayerRateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerRateChangedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_MediaPlayerRateChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::MediaPlayerRateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerRateChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_MediaPlayerRateChanged, MediaPlayerRateChanged(value));
}

template <typename D> void impl_IMediaPlayer<D>::MediaPlayerRateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_MediaPlayerRateChanged(token));
}

template <typename D> event_token impl_IMediaPlayer<D>::VolumeChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_VolumeChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::VolumeChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_VolumeChanged, VolumeChanged(value));
}

template <typename D> void impl_IMediaPlayer<D>::VolumeChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_VolumeChanged(token));
}

template <typename D> event_token impl_IMediaPlayer<D>::SeekCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_SeekCompleted(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::SeekCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_SeekCompleted, SeekCompleted(value));
}

template <typename D> void impl_IMediaPlayer<D>::SeekCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_SeekCompleted(token));
}

template <typename D> event_token impl_IMediaPlayer<D>::BufferingStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_BufferingStarted(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::BufferingStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_BufferingStarted, BufferingStarted(value));
}

template <typename D> void impl_IMediaPlayer<D>::BufferingStarted(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_BufferingStarted(token));
}

template <typename D> event_token impl_IMediaPlayer<D>::BufferingEnded(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer)->add_BufferingEnded(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer> impl_IMediaPlayer<D>::BufferingEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer>(this, &ABI::Windows::Media::Playback::IMediaPlayer::remove_BufferingEnded, BufferingEnded(value));
}

template <typename D> void impl_IMediaPlayer<D>::BufferingEnded(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->remove_BufferingEnded(token));
}

template <typename D> void impl_IMediaPlayer<D>::Play() const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->abi_Play());
}

template <typename D> void impl_IMediaPlayer<D>::Pause() const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->abi_Pause());
}

template <typename D> void impl_IMediaPlayer<D>::SetUriSource(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer)->abi_SetUriSource(get_abi(value)));
}

template <typename D> Windows::Media::SystemMediaTransportControls impl_IMediaPlayer2<D>::SystemMediaTransportControls() const
{
    Windows::Media::SystemMediaTransportControls value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayer2)->get_SystemMediaTransportControls(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlayerAudioCategory impl_IMediaPlayer2<D>::AudioCategory() const
{
    Windows::Media::Playback::MediaPlayerAudioCategory value {};
    check_hresult(WINRT_SHIM(IMediaPlayer2)->get_AudioCategory(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer2<D>::AudioCategory(Windows::Media::Playback::MediaPlayerAudioCategory value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer2)->put_AudioCategory(value));
}

template <typename D> Windows::Media::Playback::MediaPlayerAudioDeviceType impl_IMediaPlayer2<D>::AudioDeviceType() const
{
    Windows::Media::Playback::MediaPlayerAudioDeviceType value {};
    check_hresult(WINRT_SHIM(IMediaPlayer2)->get_AudioDeviceType(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer2<D>::AudioDeviceType(Windows::Media::Playback::MediaPlayerAudioDeviceType value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer2)->put_AudioDeviceType(value));
}

template <typename D> event_token impl_IMediaPlayer3<D>::IsMutedChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer3)->add_IsMutedChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer3> impl_IMediaPlayer3<D>::IsMutedChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer3>(this, &ABI::Windows::Media::Playback::IMediaPlayer3::remove_IsMutedChanged, IsMutedChanged(value));
}

template <typename D> void impl_IMediaPlayer3<D>::IsMutedChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->remove_IsMutedChanged(token));
}

template <typename D> event_token impl_IMediaPlayer3<D>::SourceChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlayer3)->add_SourceChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlayer3> impl_IMediaPlayer3<D>::SourceChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlayer3>(this, &ABI::Windows::Media::Playback::IMediaPlayer3::remove_SourceChanged, SourceChanged(value));
}

template <typename D> void impl_IMediaPlayer3<D>::SourceChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->remove_SourceChanged(token));
}

template <typename D> double impl_IMediaPlayer3<D>::AudioBalance() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaPlayer3)->get_AudioBalance(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer3<D>::AudioBalance(double value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->put_AudioBalance(value));
}

template <typename D> bool impl_IMediaPlayer3<D>::RealTimePlayback() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlayer3)->get_RealTimePlayback(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer3<D>::RealTimePlayback(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->put_RealTimePlayback(value));
}

template <typename D> Windows::Media::Playback::StereoscopicVideoRenderMode impl_IMediaPlayer3<D>::StereoscopicVideoRenderMode() const
{
    Windows::Media::Playback::StereoscopicVideoRenderMode value {};
    check_hresult(WINRT_SHIM(IMediaPlayer3)->get_StereoscopicVideoRenderMode(&value));
    return value;
}

template <typename D> void impl_IMediaPlayer3<D>::StereoscopicVideoRenderMode(Windows::Media::Playback::StereoscopicVideoRenderMode value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->put_StereoscopicVideoRenderMode(value));
}

template <typename D> Windows::Media::Playback::MediaBreakManager impl_IMediaPlayer3<D>::BreakManager() const
{
    Windows::Media::Playback::MediaBreakManager value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayer3)->get_BreakManager(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManager impl_IMediaPlayer3<D>::CommandManager() const
{
    Windows::Media::Playback::MediaPlaybackCommandManager value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayer3)->get_CommandManager(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IMediaPlayer3<D>::AudioDevice() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayer3)->get_AudioDevice(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlayer3<D>::AudioDevice(const Windows::Devices::Enumeration::DeviceInformation & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->put_AudioDevice(get_abi(value)));
}

template <typename D> Windows::Media::MediaTimelineController impl_IMediaPlayer3<D>::TimelineController() const
{
    Windows::Media::MediaTimelineController value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayer3)->get_TimelineController(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlayer3<D>::TimelineController(const Windows::Media::MediaTimelineController & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->put_TimelineController(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaPlayer3<D>::TimelineControllerPositionOffset() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaPlayer3)->get_TimelineControllerPositionOffset(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlayer3<D>::TimelineControllerPositionOffset(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->put_TimelineControllerPositionOffset(get_abi(value)));
}

template <typename D> Windows::Media::Playback::MediaPlaybackSession impl_IMediaPlayer3<D>::PlaybackSession() const
{
    Windows::Media::Playback::MediaPlaybackSession value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayer3)->get_PlaybackSession(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlayer3<D>::StepForwardOneFrame() const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->abi_StepForwardOneFrame());
}

template <typename D> void impl_IMediaPlayer3<D>::StepBackwardOneFrame() const
{
    check_hresult(WINRT_SHIM(IMediaPlayer3)->abi_StepBackwardOneFrame());
}

template <typename D> Windows::Media::Casting::CastingSource impl_IMediaPlayer3<D>::GetAsCastingSource() const
{
    Windows::Media::Casting::CastingSource returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayer3)->abi_GetAsCastingSource(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IMediaPlayer4<D>::SetSurfaceSize(const Windows::Foundation::Size & size) const
{
    check_hresult(WINRT_SHIM(IMediaPlayer4)->abi_SetSurfaceSize(get_abi(size)));
}

template <typename D> Windows::Media::Playback::MediaPlayerSurface impl_IMediaPlayer4<D>::GetSurface(const Windows::UI::Composition::Compositor & compositor) const
{
    Windows::Media::Playback::MediaPlayerSurface result { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayer4)->abi_GetSurface(get_abi(compositor), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::PlaybackStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_PlaybackStateChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::PlaybackStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_PlaybackStateChanged, PlaybackStateChanged(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::PlaybackStateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_PlaybackStateChanged(token));
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::PlaybackRateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_PlaybackRateChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::PlaybackRateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_PlaybackRateChanged, PlaybackRateChanged(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::PlaybackRateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_PlaybackRateChanged(token));
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::SeekCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_SeekCompleted(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::SeekCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_SeekCompleted, SeekCompleted(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::SeekCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_SeekCompleted(token));
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::BufferingStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_BufferingStarted(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::BufferingStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_BufferingStarted, BufferingStarted(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::BufferingStarted(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_BufferingStarted(token));
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::BufferingEnded(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_BufferingEnded(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::BufferingEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_BufferingEnded, BufferingEnded(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::BufferingEnded(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_BufferingEnded(token));
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::BufferingProgressChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_BufferingProgressChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::BufferingProgressChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_BufferingProgressChanged, BufferingProgressChanged(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::BufferingProgressChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_BufferingProgressChanged(token));
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::DownloadProgressChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_DownloadProgressChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::DownloadProgressChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_DownloadProgressChanged, DownloadProgressChanged(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::DownloadProgressChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_DownloadProgressChanged(token));
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::NaturalDurationChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_NaturalDurationChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::NaturalDurationChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_NaturalDurationChanged, NaturalDurationChanged(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::NaturalDurationChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_NaturalDurationChanged(token));
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::PositionChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_PositionChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::PositionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_PositionChanged, PositionChanged(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::PositionChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_PositionChanged(token));
}

template <typename D> event_token impl_IMediaPlaybackSession<D>::NaturalVideoSizeChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->add_NaturalVideoSizeChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackSession> impl_IMediaPlaybackSession<D>::NaturalVideoSizeChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMediaPlaybackSession>(this, &ABI::Windows::Media::Playback::IMediaPlaybackSession::remove_NaturalVideoSizeChanged, NaturalVideoSizeChanged(value));
}

template <typename D> void impl_IMediaPlaybackSession<D>::NaturalVideoSizeChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->remove_NaturalVideoSizeChanged(token));
}

template <typename D> Windows::Media::Playback::MediaPlayer impl_IMediaPlaybackSession<D>::MediaPlayer() const
{
    Windows::Media::Playback::MediaPlayer value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_MediaPlayer(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaPlaybackSession<D>::NaturalDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_NaturalDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaPlaybackSession<D>::Position() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_Position(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlaybackSession<D>::Position(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->put_Position(get_abi(value)));
}

template <typename D> Windows::Media::Playback::MediaPlaybackState impl_IMediaPlaybackSession<D>::PlaybackState() const
{
    Windows::Media::Playback::MediaPlaybackState value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_PlaybackState(&value));
    return value;
}

template <typename D> bool impl_IMediaPlaybackSession<D>::CanSeek() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_CanSeek(&value));
    return value;
}

template <typename D> bool impl_IMediaPlaybackSession<D>::CanPause() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_CanPause(&value));
    return value;
}

template <typename D> bool impl_IMediaPlaybackSession<D>::IsProtected() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_IsProtected(&value));
    return value;
}

template <typename D> double impl_IMediaPlaybackSession<D>::PlaybackRate() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_PlaybackRate(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackSession<D>::PlaybackRate(double value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->put_PlaybackRate(value));
}

template <typename D> double impl_IMediaPlaybackSession<D>::BufferingProgress() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_BufferingProgress(&value));
    return value;
}

template <typename D> double impl_IMediaPlaybackSession<D>::DownloadProgress() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_DownloadProgress(&value));
    return value;
}

template <typename D> uint32_t impl_IMediaPlaybackSession<D>::NaturalVideoHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_NaturalVideoHeight(&value));
    return value;
}

template <typename D> uint32_t impl_IMediaPlaybackSession<D>::NaturalVideoWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_NaturalVideoWidth(&value));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IMediaPlaybackSession<D>::NormalizedSourceRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_NormalizedSourceRect(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlaybackSession<D>::NormalizedSourceRect(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->put_NormalizedSourceRect(get_abi(value)));
}

template <typename D> Windows::Media::MediaProperties::StereoscopicVideoPackingMode impl_IMediaPlaybackSession<D>::StereoscopicVideoPackingMode() const
{
    Windows::Media::MediaProperties::StereoscopicVideoPackingMode value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->get_StereoscopicVideoPackingMode(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackSession<D>::StereoscopicVideoPackingMode(Windows::Media::MediaProperties::StereoscopicVideoPackingMode value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackSession)->put_StereoscopicVideoPackingMode(value));
}

template <typename D> Windows::Media::Protection::MediaProtectionManager impl_IMediaPlayerSource<D>::ProtectionManager() const
{
    Windows::Media::Protection::MediaProtectionManager value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayerSource)->get_ProtectionManager(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlayerSource<D>::ProtectionManager(const Windows::Media::Protection::MediaProtectionManager & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayerSource)->put_ProtectionManager(get_abi(value)));
}

template <typename D> void impl_IMediaPlayerSource<D>::SetFileSource(const Windows::Storage::IStorageFile & file) const
{
    check_hresult(WINRT_SHIM(IMediaPlayerSource)->abi_SetFileSource(get_abi(file)));
}

template <typename D> void impl_IMediaPlayerSource<D>::SetStreamSource(const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    check_hresult(WINRT_SHIM(IMediaPlayerSource)->abi_SetStreamSource(get_abi(stream)));
}

template <typename D> void impl_IMediaPlayerSource<D>::SetMediaSource(const Windows::Media::Core::IMediaSource & source) const
{
    check_hresult(WINRT_SHIM(IMediaPlayerSource)->abi_SetMediaSource(get_abi(source)));
}

template <typename D> Windows::Media::Playback::IMediaPlaybackSource impl_IMediaPlayerSource2<D>::Source() const
{
    Windows::Media::Playback::IMediaPlaybackSource value;
    check_hresult(WINRT_SHIM(IMediaPlayerSource2)->get_Source(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlayerSource2<D>::Source(const Windows::Media::Playback::IMediaPlaybackSource & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlayerSource2)->put_Source(get_abi(value)));
}

template <typename D> void impl_IMediaPlayerEffects<D>::AddAudioEffect(hstring_view activatableClassId, bool effectOptional, const Windows::Foundation::Collections::IPropertySet & configuration) const
{
    check_hresult(WINRT_SHIM(IMediaPlayerEffects)->abi_AddAudioEffect(get_abi(activatableClassId), effectOptional, get_abi(configuration)));
}

template <typename D> void impl_IMediaPlayerEffects<D>::RemoveAllEffects() const
{
    check_hresult(WINRT_SHIM(IMediaPlayerEffects)->abi_RemoveAllEffects());
}

template <typename D> void impl_IMediaPlayerEffects2<D>::AddVideoEffect(hstring_view activatableClassId, bool effectOptional, const Windows::Foundation::Collections::IPropertySet & effectConfiguration) const
{
    check_hresult(WINRT_SHIM(IMediaPlayerEffects2)->abi_AddVideoEffect(get_abi(activatableClassId), effectOptional, get_abi(effectConfiguration)));
}

template <typename D> Windows::Media::Playback::MediaBreak impl_IMediaBreakStartedEventArgs<D>::MediaBreak() const
{
    Windows::Media::Playback::MediaBreak value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakStartedEventArgs)->get_MediaBreak(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaBreak impl_IMediaBreakEndedEventArgs<D>::MediaBreak() const
{
    Windows::Media::Playback::MediaBreak value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakEndedEventArgs)->get_MediaBreak(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaBreak impl_IMediaBreakSkippedEventArgs<D>::MediaBreak() const
{
    Windows::Media::Playback::MediaBreak value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakSkippedEventArgs)->get_MediaBreak(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak> impl_IMediaBreakSeekedOverEventArgs<D>::SeekedOverBreaks() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak> value;
    check_hresult(WINRT_SHIM(IMediaBreakSeekedOverEventArgs)->get_SeekedOverBreaks(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaBreakSeekedOverEventArgs<D>::OldPosition() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaBreakSeekedOverEventArgs)->get_OldPosition(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaBreakSeekedOverEventArgs<D>::NewPosition() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaBreakSeekedOverEventArgs)->get_NewPosition(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMediaBreakManager<D>::BreaksSeekedOver(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSeekedOverEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaBreakManager)->add_BreaksSeekedOver(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaBreakManager> impl_IMediaBreakManager<D>::BreaksSeekedOver(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSeekedOverEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaBreakManager>(this, &ABI::Windows::Media::Playback::IMediaBreakManager::remove_BreaksSeekedOver, BreaksSeekedOver(handler));
}

template <typename D> void impl_IMediaBreakManager<D>::BreaksSeekedOver(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaBreakManager)->remove_BreaksSeekedOver(token));
}

template <typename D> event_token impl_IMediaBreakManager<D>::BreakStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakStartedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaBreakManager)->add_BreakStarted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaBreakManager> impl_IMediaBreakManager<D>::BreakStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakStartedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaBreakManager>(this, &ABI::Windows::Media::Playback::IMediaBreakManager::remove_BreakStarted, BreakStarted(handler));
}

template <typename D> void impl_IMediaBreakManager<D>::BreakStarted(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaBreakManager)->remove_BreakStarted(token));
}

template <typename D> event_token impl_IMediaBreakManager<D>::BreakEnded(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakEndedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaBreakManager)->add_BreakEnded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaBreakManager> impl_IMediaBreakManager<D>::BreakEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakEndedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaBreakManager>(this, &ABI::Windows::Media::Playback::IMediaBreakManager::remove_BreakEnded, BreakEnded(handler));
}

template <typename D> void impl_IMediaBreakManager<D>::BreakEnded(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaBreakManager)->remove_BreakEnded(token));
}

template <typename D> event_token impl_IMediaBreakManager<D>::BreakSkipped(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSkippedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaBreakManager)->add_BreakSkipped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaBreakManager> impl_IMediaBreakManager<D>::BreakSkipped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSkippedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaBreakManager>(this, &ABI::Windows::Media::Playback::IMediaBreakManager::remove_BreakSkipped, BreakSkipped(handler));
}

template <typename D> void impl_IMediaBreakManager<D>::BreakSkipped(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaBreakManager)->remove_BreakSkipped(token));
}

template <typename D> Windows::Media::Playback::MediaBreak impl_IMediaBreakManager<D>::CurrentBreak() const
{
    Windows::Media::Playback::MediaBreak value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakManager)->get_CurrentBreak(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackSession impl_IMediaBreakManager<D>::PlaybackSession() const
{
    Windows::Media::Playback::MediaPlaybackSession value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakManager)->get_PlaybackSession(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaBreakManager<D>::PlayBreak(const Windows::Media::Playback::MediaBreak & value) const
{
    check_hresult(WINRT_SHIM(IMediaBreakManager)->abi_PlayBreak(get_abi(value)));
}

template <typename D> void impl_IMediaBreakManager<D>::SkipCurrentBreak() const
{
    check_hresult(WINRT_SHIM(IMediaBreakManager)->abi_SkipCurrentBreak());
}

template <typename D> Windows::UI::Composition::ICompositionSurface impl_IMediaPlayerSurface<D>::CompositionSurface() const
{
    Windows::UI::Composition::ICompositionSurface value;
    check_hresult(WINRT_SHIM(IMediaPlayerSurface)->get_CompositionSurface(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Composition::Compositor impl_IMediaPlayerSurface<D>::Compositor() const
{
    Windows::UI::Composition::Compositor value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayerSurface)->get_Compositor(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlayer impl_IMediaPlayerSurface<D>::MediaPlayer() const
{
    Windows::Media::Playback::MediaPlayer value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayerSurface)->get_MediaPlayer(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlayer impl_IBackgroundMediaPlayerStatics<D>::Current() const
{
    Windows::Media::Playback::MediaPlayer player { nullptr };
    check_hresult(WINRT_SHIM(IBackgroundMediaPlayerStatics)->get_Current(put_abi(player)));
    return player;
}

template <typename D> event_token impl_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromBackground(const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBackgroundMediaPlayerStatics)->add_MessageReceivedFromBackground(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IBackgroundMediaPlayerStatics> impl_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IBackgroundMediaPlayerStatics>(this, &ABI::Windows::Media::Playback::IBackgroundMediaPlayerStatics::remove_MessageReceivedFromBackground, MessageReceivedFromBackground(value));
}

template <typename D> void impl_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromBackground(event_token token) const
{
    check_hresult(WINRT_SHIM(IBackgroundMediaPlayerStatics)->remove_MessageReceivedFromBackground(token));
}

template <typename D> event_token impl_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromForeground(const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBackgroundMediaPlayerStatics)->add_MessageReceivedFromForeground(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IBackgroundMediaPlayerStatics> impl_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromForeground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IBackgroundMediaPlayerStatics>(this, &ABI::Windows::Media::Playback::IBackgroundMediaPlayerStatics::remove_MessageReceivedFromForeground, MessageReceivedFromForeground(value));
}

template <typename D> void impl_IBackgroundMediaPlayerStatics<D>::MessageReceivedFromForeground(event_token token) const
{
    check_hresult(WINRT_SHIM(IBackgroundMediaPlayerStatics)->remove_MessageReceivedFromForeground(token));
}

template <typename D> void impl_IBackgroundMediaPlayerStatics<D>::SendMessageToBackground(const Windows::Foundation::Collections::ValueSet & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundMediaPlayerStatics)->abi_SendMessageToBackground(get_abi(value)));
}

template <typename D> void impl_IBackgroundMediaPlayerStatics<D>::SendMessageToForeground(const Windows::Foundation::Collections::ValueSet & value) const
{
    check_hresult(WINRT_SHIM(IBackgroundMediaPlayerStatics)->abi_SendMessageToForeground(get_abi(value)));
}

template <typename D> bool impl_IBackgroundMediaPlayerStatics<D>::IsMediaPlaying() const
{
    bool isMediaPlaying {};
    check_hresult(WINRT_SHIM(IBackgroundMediaPlayerStatics)->abi_IsMediaPlaying(&isMediaPlaying));
    return isMediaPlaying;
}

template <typename D> void impl_IBackgroundMediaPlayerStatics<D>::Shutdown() const
{
    check_hresult(WINRT_SHIM(IBackgroundMediaPlayerStatics)->abi_Shutdown());
}

template <typename D> bool impl_IMediaPlaybackCommandManagerPlayReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPlayReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerPlayReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPlayReceivedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerPlayReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPlayReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerPauseReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPauseReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerPauseReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPauseReceivedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerPauseReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPauseReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerNextReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerNextReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerNextReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerNextReceivedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerNextReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerNextReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerPreviousReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPreviousReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerPreviousReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPreviousReceivedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerPreviousReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPreviousReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerFastForwardReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerFastForwardReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerFastForwardReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerFastForwardReceivedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerFastForwardReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerFastForwardReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerRewindReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerRewindReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerRewindReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerRewindReceivedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerRewindReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerRewindReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerShuffleReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerShuffleReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerShuffleReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerShuffleReceivedEventArgs)->put_Handled(value));
}

template <typename D> bool impl_IMediaPlaybackCommandManagerShuffleReceivedEventArgs<D>::IsShuffleRequested() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerShuffleReceivedEventArgs)->get_IsShuffleRequested(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerShuffleReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerShuffleReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Media::MediaPlaybackAutoRepeatMode impl_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs<D>::AutoRepeatMode() const
{
    Windows::Media::MediaPlaybackAutoRepeatMode value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs)->get_AutoRepeatMode(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerPositionReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPositionReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerPositionReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPositionReceivedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaPlaybackCommandManagerPositionReceivedEventArgs<D>::Position() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPositionReceivedEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerPositionReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerPositionReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerRateReceivedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerRateReceivedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerRateReceivedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerRateReceivedEventArgs)->put_Handled(value));
}

template <typename D> double impl_IMediaPlaybackCommandManagerRateReceivedEventArgs<D>::PlaybackRate() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerRateReceivedEventArgs)->get_PlaybackRate(&value));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IMediaPlaybackCommandManagerRateReceivedEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerRateReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManager impl_IMediaPlaybackCommandManagerCommandBehavior<D>::CommandManager() const
{
    Windows::Media::Playback::MediaPlaybackCommandManager value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerCommandBehavior)->get_CommandManager(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackCommandManagerCommandBehavior<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerCommandBehavior)->get_IsEnabled(&value));
    return value;
}

template <typename D> Windows::Media::Playback::MediaCommandEnablingRule impl_IMediaPlaybackCommandManagerCommandBehavior<D>::EnablingRule() const
{
    Windows::Media::Playback::MediaCommandEnablingRule value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerCommandBehavior)->get_EnablingRule(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManagerCommandBehavior<D>::EnablingRule(Windows::Media::Playback::MediaCommandEnablingRule value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerCommandBehavior)->put_EnablingRule(value));
}

template <typename D> event_token impl_IMediaPlaybackCommandManagerCommandBehavior<D>::IsEnabledChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerCommandBehavior)->add_IsEnabledChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManagerCommandBehavior> impl_IMediaPlaybackCommandManagerCommandBehavior<D>::IsEnabledChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManagerCommandBehavior>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior::remove_IsEnabledChanged, IsEnabledChanged(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManagerCommandBehavior<D>::IsEnabledChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManagerCommandBehavior)->remove_IsEnabledChanged(token));
}

template <typename D> bool impl_IMediaPlaybackCommandManager<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::IsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->put_IsEnabled(value));
}

template <typename D> Windows::Media::Playback::MediaPlayer impl_IMediaPlaybackCommandManager<D>::MediaPlayer() const
{
    Windows::Media::Playback::MediaPlayer value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_MediaPlayer(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::PlayBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_PlayBehavior(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::PauseBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_PauseBehavior(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::NextBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_NextBehavior(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::PreviousBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_PreviousBehavior(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::FastForwardBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_FastForwardBehavior(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::RewindBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_RewindBehavior(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::ShuffleBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_ShuffleBehavior(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::AutoRepeatModeBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_AutoRepeatModeBehavior(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::PositionBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_PositionBehavior(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior impl_IMediaPlaybackCommandManager<D>::RateBehavior() const
{
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->get_RateBehavior(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::PlayReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_PlayReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::PlayReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_PlayReceived, PlayReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::PlayReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_PlayReceived(token));
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::PauseReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_PauseReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::PauseReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_PauseReceived, PauseReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::PauseReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_PauseReceived(token));
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::NextReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_NextReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::NextReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_NextReceived, NextReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::NextReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_NextReceived(token));
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::PreviousReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_PreviousReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::PreviousReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_PreviousReceived, PreviousReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::PreviousReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_PreviousReceived(token));
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::FastForwardReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_FastForwardReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::FastForwardReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_FastForwardReceived, FastForwardReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::FastForwardReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_FastForwardReceived(token));
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::RewindReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_RewindReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::RewindReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_RewindReceived, RewindReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::RewindReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_RewindReceived(token));
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::ShuffleReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_ShuffleReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::ShuffleReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_ShuffleReceived, ShuffleReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::ShuffleReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_ShuffleReceived(token));
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::AutoRepeatModeReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_AutoRepeatModeReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::AutoRepeatModeReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_AutoRepeatModeReceived, AutoRepeatModeReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::AutoRepeatModeReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_AutoRepeatModeReceived(token));
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::PositionReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_PositionReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::PositionReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_PositionReceived, PositionReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::PositionReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_PositionReceived(token));
}

template <typename D> event_token impl_IMediaPlaybackCommandManager<D>::RateReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->add_RateReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackCommandManager> impl_IMediaPlaybackCommandManager<D>::RateReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackCommandManager>(this, &ABI::Windows::Media::Playback::IMediaPlaybackCommandManager::remove_RateReceived, RateReceived(handler));
}

template <typename D> void impl_IMediaPlaybackCommandManager<D>::RateReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackCommandManager)->remove_RateReceived(token));
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackItemFactory<D>::Create(const Windows::Media::Core::MediaSource & source) const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItemFactory)->abi_Create(get_abi(source), put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackItemFactory2<D>::CreateWithStartTime(const Windows::Media::Core::MediaSource & source, const Windows::Foundation::TimeSpan & startTime) const
{
    Windows::Media::Playback::MediaPlaybackItem result { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItemFactory2)->abi_CreateWithStartTime(get_abi(source), get_abi(startTime), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackItemFactory2<D>::CreateWithStartTimeAndDurationLimit(const Windows::Media::Core::MediaSource & source, const Windows::Foundation::TimeSpan & startTime, const Windows::Foundation::TimeSpan & durationLimit) const
{
    Windows::Media::Playback::MediaPlaybackItem result { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItemFactory2)->abi_CreateWithStartTimeAndDurationLimit(get_abi(source), get_abi(startTime), get_abi(durationLimit), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackItemStatics<D>::FindFromMediaSource(const Windows::Media::Core::MediaSource & source) const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItemStatics)->abi_FindFromMediaSource(get_abi(source), put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMediaPlaybackItem<D>::AudioTracksChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->add_AudioTracksChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackItem> impl_IMediaPlaybackItem<D>::AudioTracksChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackItem>(this, &ABI::Windows::Media::Playback::IMediaPlaybackItem::remove_AudioTracksChanged, AudioTracksChanged(handler));
}

template <typename D> void impl_IMediaPlaybackItem<D>::AudioTracksChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->remove_AudioTracksChanged(token));
}

template <typename D> event_token impl_IMediaPlaybackItem<D>::VideoTracksChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->add_VideoTracksChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackItem> impl_IMediaPlaybackItem<D>::VideoTracksChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackItem>(this, &ABI::Windows::Media::Playback::IMediaPlaybackItem::remove_VideoTracksChanged, VideoTracksChanged(handler));
}

template <typename D> void impl_IMediaPlaybackItem<D>::VideoTracksChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->remove_VideoTracksChanged(token));
}

template <typename D> event_token impl_IMediaPlaybackItem<D>::TimedMetadataTracksChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->add_TimedMetadataTracksChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackItem> impl_IMediaPlaybackItem<D>::TimedMetadataTracksChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackItem>(this, &ABI::Windows::Media::Playback::IMediaPlaybackItem::remove_TimedMetadataTracksChanged, TimedMetadataTracksChanged(handler));
}

template <typename D> void impl_IMediaPlaybackItem<D>::TimedMetadataTracksChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->remove_TimedMetadataTracksChanged(token));
}

template <typename D> Windows::Media::Core::MediaSource impl_IMediaPlaybackItem<D>::Source() const
{
    Windows::Media::Core::MediaSource value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->get_Source(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackAudioTrackList impl_IMediaPlaybackItem<D>::AudioTracks() const
{
    Windows::Media::Playback::MediaPlaybackAudioTrackList value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->get_AudioTracks(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackVideoTrackList impl_IMediaPlaybackItem<D>::VideoTracks() const
{
    Windows::Media::Playback::MediaPlaybackVideoTrackList value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->get_VideoTracks(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList impl_IMediaPlaybackItem<D>::TimedMetadataTracks() const
{
    Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItem)->get_TimedMetadataTracks(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::MediaPlaybackType impl_IMediaItemDisplayProperties<D>::Type() const
{
    Windows::Media::MediaPlaybackType value {};
    check_hresult(WINRT_SHIM(IMediaItemDisplayProperties)->get_Type(&value));
    return value;
}

template <typename D> void impl_IMediaItemDisplayProperties<D>::Type(Windows::Media::MediaPlaybackType value) const
{
    check_hresult(WINRT_SHIM(IMediaItemDisplayProperties)->put_Type(value));
}

template <typename D> Windows::Media::MusicDisplayProperties impl_IMediaItemDisplayProperties<D>::MusicProperties() const
{
    Windows::Media::MusicDisplayProperties value { nullptr };
    check_hresult(WINRT_SHIM(IMediaItemDisplayProperties)->get_MusicProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::VideoDisplayProperties impl_IMediaItemDisplayProperties<D>::VideoProperties() const
{
    Windows::Media::VideoDisplayProperties value { nullptr };
    check_hresult(WINRT_SHIM(IMediaItemDisplayProperties)->get_VideoProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::RandomAccessStreamReference impl_IMediaItemDisplayProperties<D>::Thumbnail() const
{
    Windows::Storage::Streams::RandomAccessStreamReference value { nullptr };
    check_hresult(WINRT_SHIM(IMediaItemDisplayProperties)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaItemDisplayProperties<D>::Thumbnail(const Windows::Storage::Streams::RandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IMediaItemDisplayProperties)->put_Thumbnail(get_abi(value)));
}

template <typename D> void impl_IMediaItemDisplayProperties<D>::ClearAll() const
{
    check_hresult(WINRT_SHIM(IMediaItemDisplayProperties)->abi_ClearAll());
}

template <typename D> Windows::Media::Playback::MediaBreakSchedule impl_IMediaPlaybackItem2<D>::BreakSchedule() const
{
    Windows::Media::Playback::MediaBreakSchedule value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItem2)->get_BreakSchedule(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMediaPlaybackItem2<D>::StartTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackItem2)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMediaPlaybackItem2<D>::DurationLimit() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMediaPlaybackItem2)->get_DurationLimit(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackItem2<D>::CanSkip() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackItem2)->get_CanSkip(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackItem2<D>::CanSkip(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackItem2)->put_CanSkip(value));
}

template <typename D> Windows::Media::Playback::MediaItemDisplayProperties impl_IMediaPlaybackItem2<D>::GetDisplayProperties() const
{
    Windows::Media::Playback::MediaItemDisplayProperties value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItem2)->abi_GetDisplayProperties(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlaybackItem2<D>::ApplyDisplayProperties(const Windows::Media::Playback::MediaItemDisplayProperties & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackItem2)->abi_ApplyDisplayProperties(get_abi(value)));
}

template <typename D> Windows::Media::Playback::MediaBreak impl_IMediaBreakFactory<D>::Create(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod) const
{
    Windows::Media::Playback::MediaBreak result { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakFactory)->abi_Create(insertionMethod, put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Playback::MediaBreak impl_IMediaBreakFactory<D>::CreateWithPresentationPosition(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod, const Windows::Foundation::TimeSpan & presentationPosition) const
{
    Windows::Media::Playback::MediaBreak result { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakFactory)->abi_CreateWithPresentationPosition(insertionMethod, get_abi(presentationPosition), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Playback::MediaPlaybackList impl_IMediaBreak<D>::PlaybackList() const
{
    Windows::Media::Playback::MediaPlaybackList value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreak)->get_PlaybackList(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMediaBreak<D>::PresentationPosition() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMediaBreak)->get_PresentationPosition(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaBreakInsertionMethod impl_IMediaBreak<D>::InsertionMethod() const
{
    Windows::Media::Playback::MediaBreakInsertionMethod value {};
    check_hresult(WINRT_SHIM(IMediaBreak)->get_InsertionMethod(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IMediaBreak<D>::CustomProperties() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreak)->get_CustomProperties(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaBreak<D>::CanStart() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaBreak)->get_CanStart(&value));
    return value;
}

template <typename D> void impl_IMediaBreak<D>::CanStart(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaBreak)->put_CanStart(value));
}

template <typename D> event_token impl_IMediaBreakSchedule<D>::ScheduleChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakSchedule, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->add_ScheduleChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaBreakSchedule> impl_IMediaBreakSchedule<D>::ScheduleChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakSchedule, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMediaBreakSchedule>(this, &ABI::Windows::Media::Playback::IMediaBreakSchedule::remove_ScheduleChanged, ScheduleChanged(handler));
}

template <typename D> void impl_IMediaBreakSchedule<D>::ScheduleChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->remove_ScheduleChanged(token));
}

template <typename D> void impl_IMediaBreakSchedule<D>::InsertMidrollBreak(const Windows::Media::Playback::MediaBreak & mediaBreak) const
{
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->abi_InsertMidrollBreak(get_abi(mediaBreak)));
}

template <typename D> void impl_IMediaBreakSchedule<D>::RemoveMidrollBreak(const Windows::Media::Playback::MediaBreak & mediaBreak) const
{
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->abi_RemoveMidrollBreak(get_abi(mediaBreak)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak> impl_IMediaBreakSchedule<D>::MidrollBreaks() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak> value;
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->get_MidrollBreaks(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaBreakSchedule<D>::PrerollBreak(const Windows::Media::Playback::MediaBreak & value) const
{
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->put_PrerollBreak(get_abi(value)));
}

template <typename D> Windows::Media::Playback::MediaBreak impl_IMediaBreakSchedule<D>::PrerollBreak() const
{
    Windows::Media::Playback::MediaBreak value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->get_PrerollBreak(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaBreakSchedule<D>::PostrollBreak(const Windows::Media::Playback::MediaBreak & value) const
{
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->put_PostrollBreak(get_abi(value)));
}

template <typename D> Windows::Media::Playback::MediaBreak impl_IMediaBreakSchedule<D>::PostrollBreak() const
{
    Windows::Media::Playback::MediaBreak value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->get_PostrollBreak(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaBreakSchedule<D>::PlaybackItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaBreakSchedule)->get_PlaybackItem(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItemErrorCode impl_IMediaPlaybackItemError<D>::ErrorCode() const
{
    Windows::Media::Playback::MediaPlaybackItemErrorCode value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackItemError)->get_ErrorCode(&value));
    return value;
}

template <typename D> HRESULT impl_IMediaPlaybackItemError<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackItemError)->get_ExtendedError(&value));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaEnginePlaybackSource<D>::CurrentItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaEnginePlaybackSource)->get_CurrentItem(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaEnginePlaybackSource<D>::SetPlaybackSource(const Windows::Media::Playback::IMediaPlaybackSource & source) const
{
    check_hresult(WINRT_SHIM(IMediaEnginePlaybackSource)->abi_SetPlaybackSource(get_abi(source)));
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackItemOpenedEventArgs<D>::Item() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItemOpenedEventArgs)->get_Item(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackItemFailedEventArgs<D>::Item() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItemFailedEventArgs)->get_Item(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItemError impl_IMediaPlaybackItemFailedEventArgs<D>::Error() const
{
    Windows::Media::Playback::MediaPlaybackItemError value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackItemFailedEventArgs)->get_Error(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_ICurrentMediaPlaybackItemChangedEventArgs<D>::NewItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(ICurrentMediaPlaybackItemChangedEventArgs)->get_NewItem(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_ICurrentMediaPlaybackItemChangedEventArgs<D>::OldItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(ICurrentMediaPlaybackItemChangedEventArgs)->get_OldItem(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMediaPlaybackList<D>::ItemFailed(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemFailedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->add_ItemFailed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackList> impl_IMediaPlaybackList<D>::ItemFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemFailedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackList>(this, &ABI::Windows::Media::Playback::IMediaPlaybackList::remove_ItemFailed, ItemFailed(handler));
}

template <typename D> void impl_IMediaPlaybackList<D>::ItemFailed(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->remove_ItemFailed(token));
}

template <typename D> event_token impl_IMediaPlaybackList<D>::CurrentItemChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->add_CurrentItemChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackList> impl_IMediaPlaybackList<D>::CurrentItemChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackList>(this, &ABI::Windows::Media::Playback::IMediaPlaybackList::remove_CurrentItemChanged, CurrentItemChanged(handler));
}

template <typename D> void impl_IMediaPlaybackList<D>::CurrentItemChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->remove_CurrentItemChanged(token));
}

template <typename D> event_token impl_IMediaPlaybackList<D>::ItemOpened(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->add_ItemOpened(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackList> impl_IMediaPlaybackList<D>::ItemOpened(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackList>(this, &ABI::Windows::Media::Playback::IMediaPlaybackList::remove_ItemOpened, ItemOpened(handler));
}

template <typename D> void impl_IMediaPlaybackList<D>::ItemOpened(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->remove_ItemOpened(token));
}

template <typename D> Windows::Foundation::Collections::IObservableVector<Windows::Media::Playback::MediaPlaybackItem> impl_IMediaPlaybackList<D>::Items() const
{
    Windows::Foundation::Collections::IObservableVector<Windows::Media::Playback::MediaPlaybackItem> value;
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->get_Items(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMediaPlaybackList<D>::AutoRepeatEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->get_AutoRepeatEnabled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackList<D>::AutoRepeatEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->put_AutoRepeatEnabled(value));
}

template <typename D> bool impl_IMediaPlaybackList<D>::ShuffleEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->get_ShuffleEnabled(&value));
    return value;
}

template <typename D> void impl_IMediaPlaybackList<D>::ShuffleEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->put_ShuffleEnabled(value));
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackList<D>::CurrentItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->get_CurrentItem(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMediaPlaybackList<D>::CurrentItemIndex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->get_CurrentItemIndex(&value));
    return value;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackList<D>::MoveNext() const
{
    Windows::Media::Playback::MediaPlaybackItem item { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->abi_MoveNext(put_abi(item)));
    return item;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackList<D>::MovePrevious() const
{
    Windows::Media::Playback::MediaPlaybackItem item { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->abi_MovePrevious(put_abi(item)));
    return item;
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackList<D>::MoveTo(uint32_t itemIndex) const
{
    Windows::Media::Playback::MediaPlaybackItem item { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackList)->abi_MoveTo(itemIndex, put_abi(item)));
    return item;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IMediaPlaybackList2<D>::MaxPrefetchTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IMediaPlaybackList2)->get_MaxPrefetchTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlaybackList2<D>::MaxPrefetchTime(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackList2)->put_MaxPrefetchTime(get_abi(value)));
}

template <typename D> Windows::Media::Playback::MediaPlaybackItem impl_IMediaPlaybackList2<D>::StartingItem() const
{
    Windows::Media::Playback::MediaPlaybackItem value { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlaybackList2)->get_StartingItem(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlaybackList2<D>::StartingItem(const Windows::Media::Playback::MediaPlaybackItem & value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackList2)->put_StartingItem(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaPlaybackItem> impl_IMediaPlaybackList2<D>::ShuffledItems() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaPlaybackItem> value;
    check_hresult(WINRT_SHIM(IMediaPlaybackList2)->get_ShuffledItems(put_abi(value)));
    return value;
}

template <typename D> void impl_IMediaPlaybackList2<D>::SetShuffledItems(iterable<Windows::Media::Playback::MediaPlaybackItem> value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackList2)->abi_SetShuffledItems(get_abi(value)));
}

template <typename D> event_token impl_IMediaPlaybackTimedMetadataTrackList<D>::PresentationModeChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMediaPlaybackTimedMetadataTrackList)->add_PresentationModeChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IMediaPlaybackTimedMetadataTrackList> impl_IMediaPlaybackTimedMetadataTrackList<D>::PresentationModeChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMediaPlaybackTimedMetadataTrackList>(this, &ABI::Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList::remove_PresentationModeChanged, PresentationModeChanged(handler));
}

template <typename D> void impl_IMediaPlaybackTimedMetadataTrackList<D>::PresentationModeChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackTimedMetadataTrackList)->remove_PresentationModeChanged(token));
}

template <typename D> Windows::Media::Playback::TimedMetadataTrackPresentationMode impl_IMediaPlaybackTimedMetadataTrackList<D>::GetPresentationMode(uint32_t index) const
{
    Windows::Media::Playback::TimedMetadataTrackPresentationMode value {};
    check_hresult(WINRT_SHIM(IMediaPlaybackTimedMetadataTrackList)->abi_GetPresentationMode(index, &value));
    return value;
}

template <typename D> void impl_IMediaPlaybackTimedMetadataTrackList<D>::SetPresentationMode(uint32_t index, Windows::Media::Playback::TimedMetadataTrackPresentationMode value) const
{
    check_hresult(WINRT_SHIM(IMediaPlaybackTimedMetadataTrackList)->abi_SetPresentationMode(index, value));
}

template <typename D> Windows::Media::Core::TimedMetadataTrack impl_ITimedMetadataPresentationModeChangedEventArgs<D>::Track() const
{
    Windows::Media::Core::TimedMetadataTrack value { nullptr };
    check_hresult(WINRT_SHIM(ITimedMetadataPresentationModeChangedEventArgs)->get_Track(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::Playback::TimedMetadataTrackPresentationMode impl_ITimedMetadataPresentationModeChangedEventArgs<D>::OldPresentationMode() const
{
    Windows::Media::Playback::TimedMetadataTrackPresentationMode value {};
    check_hresult(WINRT_SHIM(ITimedMetadataPresentationModeChangedEventArgs)->get_OldPresentationMode(&value));
    return value;
}

template <typename D> Windows::Media::Playback::TimedMetadataTrackPresentationMode impl_ITimedMetadataPresentationModeChangedEventArgs<D>::NewPresentationMode() const
{
    Windows::Media::Playback::TimedMetadataTrackPresentationMode value {};
    check_hresult(WINRT_SHIM(ITimedMetadataPresentationModeChangedEventArgs)->get_NewPresentationMode(&value));
    return value;
}

inline Windows::Media::Playback::MediaPlayer BackgroundMediaPlayer::Current()
{
    return get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>().Current();
}

inline event_token BackgroundMediaPlayer::MessageReceivedFromBackground(const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value)
{
    return get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>().MessageReceivedFromBackground(value);
}

inline factory_event_revoker<IBackgroundMediaPlayerStatics> BackgroundMediaPlayer::MessageReceivedFromBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value)
{
    auto factory = get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>();
    return { factory, &ABI::Windows::Media::Playback::IBackgroundMediaPlayerStatics::remove_MessageReceivedFromBackground, factory.MessageReceivedFromBackground(value) };
}

inline void BackgroundMediaPlayer::MessageReceivedFromBackground(event_token token)
{
    get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>().MessageReceivedFromBackground(token);
}

inline event_token BackgroundMediaPlayer::MessageReceivedFromForeground(const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value)
{
    return get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>().MessageReceivedFromForeground(value);
}

inline factory_event_revoker<IBackgroundMediaPlayerStatics> BackgroundMediaPlayer::MessageReceivedFromForeground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value)
{
    auto factory = get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>();
    return { factory, &ABI::Windows::Media::Playback::IBackgroundMediaPlayerStatics::remove_MessageReceivedFromForeground, factory.MessageReceivedFromForeground(value) };
}

inline void BackgroundMediaPlayer::MessageReceivedFromForeground(event_token token)
{
    get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>().MessageReceivedFromForeground(token);
}

inline void BackgroundMediaPlayer::SendMessageToBackground(const Windows::Foundation::Collections::ValueSet & value)
{
    get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>().SendMessageToBackground(value);
}

inline void BackgroundMediaPlayer::SendMessageToForeground(const Windows::Foundation::Collections::ValueSet & value)
{
    get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>().SendMessageToForeground(value);
}

inline bool BackgroundMediaPlayer::IsMediaPlaying()
{
    return get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>().IsMediaPlaying();
}

inline void BackgroundMediaPlayer::Shutdown()
{
    get_activation_factory<BackgroundMediaPlayer, IBackgroundMediaPlayerStatics>().Shutdown();
}

inline MediaBreak::MediaBreak(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod) :
    MediaBreak(get_activation_factory<MediaBreak, IMediaBreakFactory>().Create(insertionMethod))
{}

inline MediaBreak::MediaBreak(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod, const Windows::Foundation::TimeSpan & presentationPosition) :
    MediaBreak(get_activation_factory<MediaBreak, IMediaBreakFactory>().CreateWithPresentationPosition(insertionMethod, presentationPosition))
{}

inline MediaPlaybackItem::MediaPlaybackItem(const Windows::Media::Core::MediaSource & source) :
    MediaPlaybackItem(get_activation_factory<MediaPlaybackItem, IMediaPlaybackItemFactory>().Create(source))
{}

inline MediaPlaybackItem::MediaPlaybackItem(const Windows::Media::Core::MediaSource & source, const Windows::Foundation::TimeSpan & startTime) :
    MediaPlaybackItem(get_activation_factory<MediaPlaybackItem, IMediaPlaybackItemFactory2>().CreateWithStartTime(source, startTime))
{}

inline MediaPlaybackItem::MediaPlaybackItem(const Windows::Media::Core::MediaSource & source, const Windows::Foundation::TimeSpan & startTime, const Windows::Foundation::TimeSpan & durationLimit) :
    MediaPlaybackItem(get_activation_factory<MediaPlaybackItem, IMediaPlaybackItemFactory2>().CreateWithStartTimeAndDurationLimit(source, startTime, durationLimit))
{}

inline Windows::Media::Playback::MediaPlaybackItem MediaPlaybackItem::FindFromMediaSource(const Windows::Media::Core::MediaSource & source)
{
    return get_activation_factory<MediaPlaybackItem, IMediaPlaybackItemStatics>().FindFromMediaSource(source);
}

inline MediaPlaybackList::MediaPlaybackList() :
    MediaPlaybackList(activate_instance<MediaPlaybackList>())
{}

inline MediaPlayer::MediaPlayer() :
    MediaPlayer(activate_instance<MediaPlayer>())
{}

inline PlaybackMediaMarker::PlaybackMediaMarker(const Windows::Foundation::TimeSpan & value) :
    PlaybackMediaMarker(get_activation_factory<PlaybackMediaMarker, IPlaybackMediaMarkerFactory>().CreateFromTime(value))
{}

inline PlaybackMediaMarker::PlaybackMediaMarker(const Windows::Foundation::TimeSpan & value, hstring_view mediaMarketType, hstring_view text) :
    PlaybackMediaMarker(get_activation_factory<PlaybackMediaMarker, IPlaybackMediaMarkerFactory>().Create(value, mediaMarketType, text))
{}

}

}
#pragma warning(pop)
