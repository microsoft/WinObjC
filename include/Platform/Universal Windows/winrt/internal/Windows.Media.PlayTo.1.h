// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.PlayTo.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::PlayTo {

struct __declspec(uuid("99711324-edc7-4bf5-91f6-3c8627db59e5")) __declspec(novtable) ICurrentTimeChangeRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Time(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("e4b4f5f6-af1f-4f1e-b437-7da32400e1d4")) __declspec(novtable) IMuteChangeRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mute(bool * value) = 0;
};

struct __declspec(uuid("112fbfc8-f235-4fde-8d41-9bf27c9e9a40")) __declspec(novtable) IPlayToConnection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_State(winrt::Windows::Media::PlayTo::PlayToConnectionState * value) = 0;
    virtual HRESULT __stdcall add_StateChanged(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_Transferred(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Transferred(event_token token) = 0;
    virtual HRESULT __stdcall add_Error(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionErrorEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Error(event_token token) = 0;
};

struct __declspec(uuid("bf5eada6-88e6-445f-9d40-d9b9f8939896")) __declspec(novtable) IPlayToConnectionErrorEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Code(winrt::Windows::Media::PlayTo::PlayToConnectionError * value) = 0;
    virtual HRESULT __stdcall get_Message(hstring * value) = 0;
};

struct __declspec(uuid("68c4b50f-0c20-4980-8602-58c62238d423")) __declspec(novtable) IPlayToConnectionStateChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PreviousState(winrt::Windows::Media::PlayTo::PlayToConnectionState * value) = 0;
    virtual HRESULT __stdcall get_CurrentState(winrt::Windows::Media::PlayTo::PlayToConnectionState * value) = 0;
};

struct __declspec(uuid("fae3193a-0683-47d9-8df0-18cbb48984d8")) __declspec(novtable) IPlayToConnectionTransferredEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PreviousSource(Windows::Media::PlayTo::IPlayToSource ** value) = 0;
    virtual HRESULT __stdcall get_CurrentSource(Windows::Media::PlayTo::IPlayToSource ** value) = 0;
};

struct __declspec(uuid("f56a206e-1b77-42ef-8f0d-b949f8d9b260")) __declspec(novtable) IPlayToManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_SourceRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_SourceSelected(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceSelectedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceSelected(event_token token) = 0;
    virtual HRESULT __stdcall put_DefaultSourceSelection(bool value) = 0;
    virtual HRESULT __stdcall get_DefaultSourceSelection(bool * value) = 0;
};

struct __declspec(uuid("64e6a887-3982-4f3b-ba20-6155e435325b")) __declspec(novtable) IPlayToManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::Media::PlayTo::IPlayToManager ** playToManager) = 0;
    virtual HRESULT __stdcall abi_ShowPlayToUI() = 0;
};

struct __declspec(uuid("ac15cf47-a162-4aa6-af1b-3aa35f3b9069")) __declspec(novtable) IPlayToReceiver : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_PlayRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PlayRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_PauseRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PauseRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_SourceChangeRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::SourceChangeRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceChangeRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_PlaybackRateChangeRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PlaybackRateChangeRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_CurrentTimeChangeRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CurrentTimeChangeRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_MuteChangeRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::MuteChangeRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MuteChangeRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_VolumeChangeRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::VolumeChangeRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VolumeChangeRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_TimeUpdateRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TimeUpdateRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_StopRequested(Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StopRequested(event_token token) = 0;
    virtual HRESULT __stdcall abi_NotifyVolumeChange(double volume, bool mute) = 0;
    virtual HRESULT __stdcall abi_NotifyRateChange(double rate) = 0;
    virtual HRESULT __stdcall abi_NotifyLoadedMetadata() = 0;
    virtual HRESULT __stdcall abi_NotifyTimeUpdate(Windows::Foundation::TimeSpan currentTime) = 0;
    virtual HRESULT __stdcall abi_NotifyDurationChange(Windows::Foundation::TimeSpan duration) = 0;
    virtual HRESULT __stdcall abi_NotifySeeking() = 0;
    virtual HRESULT __stdcall abi_NotifySeeked() = 0;
    virtual HRESULT __stdcall abi_NotifyPaused() = 0;
    virtual HRESULT __stdcall abi_NotifyPlaying() = 0;
    virtual HRESULT __stdcall abi_NotifyEnded() = 0;
    virtual HRESULT __stdcall abi_NotifyError() = 0;
    virtual HRESULT __stdcall abi_NotifyStopped() = 0;
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_FriendlyName(hstring value) = 0;
    virtual HRESULT __stdcall put_SupportsImage(bool value) = 0;
    virtual HRESULT __stdcall get_SupportsImage(bool * value) = 0;
    virtual HRESULT __stdcall put_SupportsAudio(bool value) = 0;
    virtual HRESULT __stdcall get_SupportsAudio(bool * value) = 0;
    virtual HRESULT __stdcall put_SupportsVideo(bool value) = 0;
    virtual HRESULT __stdcall get_SupportsVideo(bool * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
    virtual HRESULT __stdcall abi_StartAsync(Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall abi_StopAsync(Windows::Foundation::IAsyncAction ** action) = 0;
};

struct __declspec(uuid("7f138a08-fbb7-4b09-8356-aa5f4e335c31")) __declspec(novtable) IPlayToSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Connection(Windows::Media::PlayTo::IPlayToConnection ** value) = 0;
    virtual HRESULT __stdcall get_Next(Windows::Media::PlayTo::IPlayToSource ** value) = 0;
    virtual HRESULT __stdcall put_Next(Windows::Media::PlayTo::IPlayToSource * value) = 0;
    virtual HRESULT __stdcall abi_PlayNext() = 0;
};

struct __declspec(uuid("4100891d-278e-4f29-859b-a9e501053e7d")) __declspec(novtable) IPlayToSourceDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("f8584665-64f4-44a0-ac0d-468d2b8fda83")) __declspec(novtable) IPlayToSourceRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_DisplayErrorString(hstring errorString) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Media::PlayTo::IPlayToSourceDeferral ** deferral) = 0;
    virtual HRESULT __stdcall abi_SetSource(Windows::Media::PlayTo::IPlayToSource * value) = 0;
};

struct __declspec(uuid("c5cdc330-29df-4ec6-9da9-9fbdfcfc1b3e")) __declspec(novtable) IPlayToSourceRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceRequest(Windows::Media::PlayTo::IPlayToSourceRequest ** value) = 0;
};

struct __declspec(uuid("0c9d8511-5202-4dcb-8c67-abda12bb3c12")) __declspec(novtable) IPlayToSourceSelectedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Icon(Windows::Storage::Streams::IRandomAccessStreamWithContentType ** value) = 0;
    virtual HRESULT __stdcall get_SupportsImage(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportsAudio(bool * value) = 0;
    virtual HRESULT __stdcall get_SupportsVideo(bool * value) = 0;
};

struct __declspec(uuid("aab253eb-3301-4dc4-afba-b2f2ed9635a0")) __declspec(novtable) IPlayToSourceWithPreferredSourceUri : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PreferredSourceUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_PreferredSourceUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("0f5661ae-2c88-4cca-8540-d586095d13a5")) __declspec(novtable) IPlaybackRateChangeRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Rate(double * value) = 0;
};

struct __declspec(uuid("fb3f3a96-7aa6-4a8b-86e7-54f6c6d34f64")) __declspec(novtable) ISourceChangeRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Stream(Windows::Storage::Streams::IRandomAccessStreamWithContentType ** value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall get_Author(hstring * value) = 0;
    virtual HRESULT __stdcall get_Album(hstring * value) = 0;
    virtual HRESULT __stdcall get_Genre(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_Date(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall get_Rating(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("6f026d5c-cf75-4c2b-913e-6d7c6c329179")) __declspec(novtable) IVolumeChangeRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Volume(double * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs> { using default_interface = Windows::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs; };
template <> struct traits<Windows::Media::PlayTo::MuteChangeRequestedEventArgs> { using default_interface = Windows::Media::PlayTo::IMuteChangeRequestedEventArgs; };
template <> struct traits<Windows::Media::PlayTo::PlayToConnection> { using default_interface = Windows::Media::PlayTo::IPlayToConnection; };
template <> struct traits<Windows::Media::PlayTo::PlayToConnectionErrorEventArgs> { using default_interface = Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs; };
template <> struct traits<Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs> { using default_interface = Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs; };
template <> struct traits<Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs> { using default_interface = Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs; };
template <> struct traits<Windows::Media::PlayTo::PlayToManager> { using default_interface = Windows::Media::PlayTo::IPlayToManager; };
template <> struct traits<Windows::Media::PlayTo::PlayToReceiver> { using default_interface = Windows::Media::PlayTo::IPlayToReceiver; };
template <> struct traits<Windows::Media::PlayTo::PlayToSource> { using default_interface = Windows::Media::PlayTo::IPlayToSource; };
template <> struct traits<Windows::Media::PlayTo::PlayToSourceDeferral> { using default_interface = Windows::Media::PlayTo::IPlayToSourceDeferral; };
template <> struct traits<Windows::Media::PlayTo::PlayToSourceRequest> { using default_interface = Windows::Media::PlayTo::IPlayToSourceRequest; };
template <> struct traits<Windows::Media::PlayTo::PlayToSourceRequestedEventArgs> { using default_interface = Windows::Media::PlayTo::IPlayToSourceRequestedEventArgs; };
template <> struct traits<Windows::Media::PlayTo::PlayToSourceSelectedEventArgs> { using default_interface = Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs; };
template <> struct traits<Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs> { using default_interface = Windows::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs; };
template <> struct traits<Windows::Media::PlayTo::SourceChangeRequestedEventArgs> { using default_interface = Windows::Media::PlayTo::ISourceChangeRequestedEventArgs; };
template <> struct traits<Windows::Media::PlayTo::VolumeChangeRequestedEventArgs> { using default_interface = Windows::Media::PlayTo::IVolumeChangeRequestedEventArgs; };

}

namespace Windows::Media::PlayTo {

template <typename D>
struct WINRT_EBO impl_ICurrentTimeChangeRequestedEventArgs
{
    Windows::Foundation::TimeSpan Time() const;
};

template <typename D>
struct WINRT_EBO impl_IMuteChangeRequestedEventArgs
{
    bool Mute() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToConnection
{
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] Windows::Media::PlayTo::PlayToConnectionState State() const;
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] event_token StateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs> & handler) const;
    using StateChanged_revoker = event_revoker<IPlayToConnection>;
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] StateChanged_revoker StateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs> & handler) const;
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] void StateChanged(event_token token) const;
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] event_token Transferred(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs> & handler) const;
    using Transferred_revoker = event_revoker<IPlayToConnection>;
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] Transferred_revoker Transferred(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs> & handler) const;
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] void Transferred(event_token token) const;
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] event_token Error(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionErrorEventArgs> & handler) const;
    using Error_revoker = event_revoker<IPlayToConnection>;
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] Error_revoker Error(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToConnection, Windows::Media::PlayTo::PlayToConnectionErrorEventArgs> & handler) const;
    [[deprecated("PlayToConnection may be altered or unavailable for releases after Windows 10. Instead, use CastingConnection.")]] void Error(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToConnectionErrorEventArgs
{
    [[deprecated("PlayToConnectionErrorEventArgs may be altered or unavailable for releases after Windows 10. Instead, use CastingConnectionErrorOccurredEventArgs.")]] Windows::Media::PlayTo::PlayToConnectionError Code() const;
    [[deprecated("PlayToConnectionErrorEventArgs may be altered or unavailable for releases after Windows 10. Instead, use CastingConnectionErrorOccurredEventArgs.")]] hstring Message() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToConnectionStateChangedEventArgs
{
    [[deprecated("PlayToConnectionStateChangedEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::Media::PlayTo::PlayToConnectionState PreviousState() const;
    [[deprecated("PlayToConnectionStateChangedEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::Media::PlayTo::PlayToConnectionState CurrentState() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToConnectionTransferredEventArgs
{
    [[deprecated("PlayToConnectionTransferredEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::Media::PlayTo::PlayToSource PreviousSource() const;
    [[deprecated("PlayToConnectionTransferredEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::Media::PlayTo::PlayToSource CurrentSource() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToManager
{
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] event_token SourceRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceRequestedEventArgs> & handler) const;
    using SourceRequested_revoker = event_revoker<IPlayToManager>;
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] SourceRequested_revoker SourceRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceRequestedEventArgs> & handler) const;
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] void SourceRequested(event_token token) const;
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] event_token SourceSelected(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceSelectedEventArgs> & handler) const;
    using SourceSelected_revoker = event_revoker<IPlayToManager>;
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] SourceSelected_revoker SourceSelected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToManager, Windows::Media::PlayTo::PlayToSourceSelectedEventArgs> & handler) const;
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] void SourceSelected(event_token token) const;
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] void DefaultSourceSelection(bool value) const;
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] bool DefaultSourceSelection() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToManagerStatics
{
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] Windows::Media::PlayTo::PlayToManager GetForCurrentView() const;
    [[deprecated("PlayToManager may be altered or unavailable for releases after Windows 10.")]] void ShowPlayToUI() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToReceiver
{
    event_token PlayRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const;
    using PlayRequested_revoker = event_revoker<IPlayToReceiver>;
    PlayRequested_revoker PlayRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const;
    void PlayRequested(event_token token) const;
    event_token PauseRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const;
    using PauseRequested_revoker = event_revoker<IPlayToReceiver>;
    PauseRequested_revoker PauseRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const;
    void PauseRequested(event_token token) const;
    event_token SourceChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::SourceChangeRequestedEventArgs> & handler) const;
    using SourceChangeRequested_revoker = event_revoker<IPlayToReceiver>;
    SourceChangeRequested_revoker SourceChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::SourceChangeRequestedEventArgs> & handler) const;
    void SourceChangeRequested(event_token token) const;
    event_token PlaybackRateChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs> & handler) const;
    using PlaybackRateChangeRequested_revoker = event_revoker<IPlayToReceiver>;
    PlaybackRateChangeRequested_revoker PlaybackRateChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs> & handler) const;
    void PlaybackRateChangeRequested(event_token token) const;
    event_token CurrentTimeChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs> & handler) const;
    using CurrentTimeChangeRequested_revoker = event_revoker<IPlayToReceiver>;
    CurrentTimeChangeRequested_revoker CurrentTimeChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs> & handler) const;
    void CurrentTimeChangeRequested(event_token token) const;
    event_token MuteChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::MuteChangeRequestedEventArgs> & handler) const;
    using MuteChangeRequested_revoker = event_revoker<IPlayToReceiver>;
    MuteChangeRequested_revoker MuteChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::MuteChangeRequestedEventArgs> & handler) const;
    void MuteChangeRequested(event_token token) const;
    event_token VolumeChangeRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::VolumeChangeRequestedEventArgs> & handler) const;
    using VolumeChangeRequested_revoker = event_revoker<IPlayToReceiver>;
    VolumeChangeRequested_revoker VolumeChangeRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Media::PlayTo::VolumeChangeRequestedEventArgs> & handler) const;
    void VolumeChangeRequested(event_token token) const;
    event_token TimeUpdateRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const;
    using TimeUpdateRequested_revoker = event_revoker<IPlayToReceiver>;
    TimeUpdateRequested_revoker TimeUpdateRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const;
    void TimeUpdateRequested(event_token token) const;
    event_token StopRequested(const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const;
    using StopRequested_revoker = event_revoker<IPlayToReceiver>;
    StopRequested_revoker StopRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::PlayTo::PlayToReceiver, Windows::Foundation::IInspectable> & handler) const;
    void StopRequested(event_token token) const;
    void NotifyVolumeChange(double volume, bool mute) const;
    void NotifyRateChange(double rate) const;
    void NotifyLoadedMetadata() const;
    void NotifyTimeUpdate(const Windows::Foundation::TimeSpan & currentTime) const;
    void NotifyDurationChange(const Windows::Foundation::TimeSpan & duration) const;
    void NotifySeeking() const;
    void NotifySeeked() const;
    void NotifyPaused() const;
    void NotifyPlaying() const;
    void NotifyEnded() const;
    void NotifyError() const;
    void NotifyStopped() const;
    hstring FriendlyName() const;
    void FriendlyName(hstring_view value) const;
    void SupportsImage(bool value) const;
    bool SupportsImage() const;
    void SupportsAudio(bool value) const;
    bool SupportsAudio() const;
    void SupportsVideo(bool value) const;
    bool SupportsVideo() const;
    Windows::Foundation::Collections::IPropertySet Properties() const;
    Windows::Foundation::IAsyncAction StartAsync() const;
    Windows::Foundation::IAsyncAction StopAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToSource
{
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10. Instead, use CastingSource.")]] Windows::Media::PlayTo::PlayToConnection Connection() const;
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10. Instead, use CastingSource.")]] Windows::Media::PlayTo::PlayToSource Next() const;
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10. Instead, use CastingSource.")]] void Next(const Windows::Media::PlayTo::PlayToSource & value) const;
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10. Instead, use CastingSource.")]] void PlayNext() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToSourceDeferral
{
    [[deprecated("PlayToSourceDeferral may be altered or unavailable for releases after Windows 10.")]] void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToSourceRequest
{
    [[deprecated("PlayToSourceRequest may be altered or unavailable for releases after Windows 10.")]] Windows::Foundation::DateTime Deadline() const;
    [[deprecated("PlayToSourceRequest may be altered or unavailable for releases after Windows 10.")]] void DisplayErrorString(hstring_view errorString) const;
    [[deprecated("PlayToSourceRequest may be altered or unavailable for releases after Windows 10.")]] Windows::Media::PlayTo::PlayToSourceDeferral GetDeferral() const;
    [[deprecated("PlayToSourceRequest may be altered or unavailable for releases after Windows 10.")]] void SetSource(const Windows::Media::PlayTo::PlayToSource & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToSourceRequestedEventArgs
{
    [[deprecated("PlayToSourceRequestedEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::Media::PlayTo::PlayToSourceRequest SourceRequest() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToSourceSelectedEventArgs
{
    [[deprecated("PlayToSourceSelectedEventArgs may be altered or unavailable for releases after Windows 10.")]] hstring FriendlyName() const;
    [[deprecated("PlayToSourceSelectedEventArgs may be altered or unavailable for releases after Windows 10.")]] Windows::Storage::Streams::IRandomAccessStreamWithContentType Icon() const;
    [[deprecated("PlayToSourceSelectedEventArgs may be altered or unavailable for releases after Windows 10.")]] bool SupportsImage() const;
    [[deprecated("PlayToSourceSelectedEventArgs may be altered or unavailable for releases after Windows 10.")]] bool SupportsAudio() const;
    [[deprecated("PlayToSourceSelectedEventArgs may be altered or unavailable for releases after Windows 10.")]] bool SupportsVideo() const;
};

template <typename D>
struct WINRT_EBO impl_IPlayToSourceWithPreferredSourceUri
{
    [[deprecated("PlayToSourceWithPreferredSourceUri may be altered or unavailable for releases after Windows 10. Instead, use CastingSource.")]] Windows::Foundation::Uri PreferredSourceUri() const;
    [[deprecated("PlayToSourceWithPreferredSourceUri may be altered or unavailable for releases after Windows 10. Instead, use CastingSource.")]] void PreferredSourceUri(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPlaybackRateChangeRequestedEventArgs
{
    double Rate() const;
};

template <typename D>
struct WINRT_EBO impl_ISourceChangeRequestedEventArgs
{
    Windows::Storage::Streams::IRandomAccessStreamWithContentType Stream() const;
    hstring Title() const;
    hstring Author() const;
    hstring Album() const;
    hstring Genre() const;
    hstring Description() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> Date() const;
    Windows::Storage::Streams::IRandomAccessStreamReference Thumbnail() const;
    Windows::Foundation::IReference<uint32_t> Rating() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> Properties() const;
};

template <typename D>
struct WINRT_EBO impl_IVolumeChangeRequestedEventArgs
{
    double Volume() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_ICurrentTimeChangeRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::IMuteChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::IMuteChangeRequestedEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IMuteChangeRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToConnection>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToConnection;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToConnection<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToConnectionErrorEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToConnectionStateChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToConnectionTransferredEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToManager>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToManager;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToManager<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToManagerStatics>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToManagerStatics;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToManagerStatics<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToReceiver>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToReceiver;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToReceiver<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToSource>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToSource;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToSource<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToSourceDeferral>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToSourceDeferral;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToSourceDeferral<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToSourceRequest>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToSourceRequest;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToSourceRequest<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToSourceRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToSourceRequestedEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToSourceRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToSourceSelectedEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlayToSourceWithPreferredSourceUri>
{
    using abi = ABI::Windows::Media::PlayTo::IPlayToSourceWithPreferredSourceUri;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlayToSourceWithPreferredSourceUri<D>;
};

template <> struct traits<Windows::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IPlaybackRateChangeRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_ISourceChangeRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::IVolumeChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::IVolumeChangeRequestedEventArgs;
    template <typename D> using consume = Windows::Media::PlayTo::impl_IVolumeChangeRequestedEventArgs<D>;
};

template <> struct traits<Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.CurrentTimeChangeRequestedEventArgs"; }
};

template <> struct traits<Windows::Media::PlayTo::MuteChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::MuteChangeRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.MuteChangeRequestedEventArgs"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToConnection>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToConnection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToConnection"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToConnectionErrorEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToConnectionErrorEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToConnectionErrorEventArgs"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToConnectionStateChangedEventArgs"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToConnectionTransferredEventArgs"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToManager>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToManager"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToReceiver>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToReceiver;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToReceiver"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToSource>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToSource"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToSourceDeferral>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToSourceDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToSourceDeferral"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToSourceRequest>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToSourceRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToSourceRequest"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToSourceRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToSourceRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToSourceRequestedEventArgs"; }
};

template <> struct traits<Windows::Media::PlayTo::PlayToSourceSelectedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::PlayToSourceSelectedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlayToSourceSelectedEventArgs"; }
};

template <> struct traits<Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.PlaybackRateChangeRequestedEventArgs"; }
};

template <> struct traits<Windows::Media::PlayTo::SourceChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::SourceChangeRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.SourceChangeRequestedEventArgs"; }
};

template <> struct traits<Windows::Media::PlayTo::VolumeChangeRequestedEventArgs>
{
    using abi = ABI::Windows::Media::PlayTo::VolumeChangeRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.PlayTo.VolumeChangeRequestedEventArgs"; }
};

}

}
