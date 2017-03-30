// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Playback.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Media.0.h"
#include "Windows.Media.Casting.0.h"
#include "Windows.Media.Core.0.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Media.Protection.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.UI.Composition.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Media.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Playback {

struct __declspec(uuid("856ddbc1-55f7-471f-a0f2-68ac4c904592")) __declspec(novtable) IBackgroundMediaPlayerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Current(Windows::Media::Playback::IMediaPlayer ** player) = 0;
    virtual HRESULT __stdcall add_MessageReceivedFromBackground(Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MessageReceivedFromBackground(event_token token) = 0;
    virtual HRESULT __stdcall add_MessageReceivedFromForeground(Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MessageReceivedFromForeground(event_token token) = 0;
    virtual HRESULT __stdcall abi_SendMessageToBackground(Windows::Foundation::Collections::IPropertySet * value) = 0;
    virtual HRESULT __stdcall abi_SendMessageToForeground(Windows::Foundation::Collections::IPropertySet * value) = 0;
    virtual HRESULT __stdcall abi_IsMediaPlaying(bool * isMediaPlaying) = 0;
    virtual HRESULT __stdcall abi_Shutdown() = 0;
};

struct __declspec(uuid("1743a892-5c43-4a15-967a-572d2d0f26c6")) __declspec(novtable) ICurrentMediaPlaybackItemChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NewItem(Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
    virtual HRESULT __stdcall get_OldItem(Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
};

struct __declspec(uuid("714be270-0def-4ebc-a489-6b34930e1558")) __declspec(novtable) IMediaBreak : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PlaybackList(Windows::Media::Playback::IMediaPlaybackList ** value) = 0;
    virtual HRESULT __stdcall get_PresentationPosition(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall get_InsertionMethod(winrt::Windows::Media::Playback::MediaBreakInsertionMethod * value) = 0;
    virtual HRESULT __stdcall get_CustomProperties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
    virtual HRESULT __stdcall get_CanStart(bool * value) = 0;
    virtual HRESULT __stdcall put_CanStart(bool value) = 0;
};

struct __declspec(uuid("32b93276-1c5d-4fee-8732-236dc3a88580")) __declspec(novtable) IMediaBreakEndedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MediaBreak(Windows::Media::Playback::IMediaBreak ** value) = 0;
};

struct __declspec(uuid("4516e002-18e0-4079-8b5f-d33495c15d2e")) __declspec(novtable) IMediaBreakFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod, Windows::Media::Playback::IMediaBreak ** result) = 0;
    virtual HRESULT __stdcall abi_CreateWithPresentationPosition(winrt::Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod, Windows::Foundation::TimeSpan presentationPosition, Windows::Media::Playback::IMediaBreak ** result) = 0;
};

struct __declspec(uuid("a854ddb1-feb4-4d9b-9d97-0fdbe58e5e39")) __declspec(novtable) IMediaBreakManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_BreaksSeekedOver(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSeekedOverEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BreaksSeekedOver(event_token token) = 0;
    virtual HRESULT __stdcall add_BreakStarted(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakStartedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BreakStarted(event_token token) = 0;
    virtual HRESULT __stdcall add_BreakEnded(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakEndedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BreakEnded(event_token token) = 0;
    virtual HRESULT __stdcall add_BreakSkipped(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSkippedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BreakSkipped(event_token token) = 0;
    virtual HRESULT __stdcall get_CurrentBreak(Windows::Media::Playback::IMediaBreak ** value) = 0;
    virtual HRESULT __stdcall get_PlaybackSession(Windows::Media::Playback::IMediaPlaybackSession ** value) = 0;
    virtual HRESULT __stdcall abi_PlayBreak(Windows::Media::Playback::IMediaBreak * value) = 0;
    virtual HRESULT __stdcall abi_SkipCurrentBreak() = 0;
};

struct __declspec(uuid("a19a5813-98b6-41d8-83da-f971d22b7bba")) __declspec(novtable) IMediaBreakSchedule : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ScheduleChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakSchedule, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ScheduleChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_InsertMidrollBreak(Windows::Media::Playback::IMediaBreak * mediaBreak) = 0;
    virtual HRESULT __stdcall abi_RemoveMidrollBreak(Windows::Media::Playback::IMediaBreak * mediaBreak) = 0;
    virtual HRESULT __stdcall get_MidrollBreaks(Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak> ** value) = 0;
    virtual HRESULT __stdcall put_PrerollBreak(Windows::Media::Playback::IMediaBreak * value) = 0;
    virtual HRESULT __stdcall get_PrerollBreak(Windows::Media::Playback::IMediaBreak ** value) = 0;
    virtual HRESULT __stdcall put_PostrollBreak(Windows::Media::Playback::IMediaBreak * value) = 0;
    virtual HRESULT __stdcall get_PostrollBreak(Windows::Media::Playback::IMediaBreak ** value) = 0;
    virtual HRESULT __stdcall get_PlaybackItem(Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
};

struct __declspec(uuid("e5aa6746-0606-4492-b9d3-c3c8fde0a4ea")) __declspec(novtable) IMediaBreakSeekedOverEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SeekedOverBreaks(Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak> ** value) = 0;
    virtual HRESULT __stdcall get_OldPosition(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_NewPosition(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("6ee94c05-2f54-4a3e-a3ab-24c3b270b4a3")) __declspec(novtable) IMediaBreakSkippedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MediaBreak(Windows::Media::Playback::IMediaBreak ** value) = 0;
};

struct __declspec(uuid("a87efe71-dfd4-454a-956e-0a4a648395f8")) __declspec(novtable) IMediaBreakStartedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MediaBreak(Windows::Media::Playback::IMediaBreak ** value) = 0;
};

struct __declspec(uuid("5c1d0ba7-3856-48b9-8dc6-244bf107bf8c")) __declspec(novtable) IMediaEnginePlaybackSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentItem(Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
    virtual HRESULT __stdcall abi_SetPlaybackSource(Windows::Media::Playback::IMediaPlaybackSource * source) = 0;
};

struct __declspec(uuid("1e3c1b48-7097-4384-a217-c1291dfa8c16")) __declspec(novtable) IMediaItemDisplayProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::Media::MediaPlaybackType * value) = 0;
    virtual HRESULT __stdcall put_Type(winrt::Windows::Media::MediaPlaybackType value) = 0;
    virtual HRESULT __stdcall get_MusicProperties(Windows::Media::IMusicDisplayProperties ** value) = 0;
    virtual HRESULT __stdcall get_VideoProperties(Windows::Media::IVideoDisplayProperties ** value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall abi_ClearAll() = 0;
};

struct __declspec(uuid("5acee5a6-5cb6-4a5a-8521-cc86b1c1ed37")) __declspec(novtable) IMediaPlaybackCommandManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_MediaPlayer(Windows::Media::Playback::IMediaPlayer ** value) = 0;
    virtual HRESULT __stdcall get_PlayBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall get_PauseBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall get_NextBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall get_PreviousBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall get_FastForwardBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall get_RewindBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall get_ShuffleBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall get_AutoRepeatModeBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall get_PositionBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall get_RateBehavior(Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior ** value) = 0;
    virtual HRESULT __stdcall add_PlayReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PlayReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_PauseReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PauseReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_NextReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NextReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_PreviousReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PreviousReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_FastForwardReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FastForwardReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_RewindReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RewindReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_ShuffleReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ShuffleReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_AutoRepeatModeReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AutoRepeatModeReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_PositionReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PositionReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_RateReceived(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RateReceived(event_token token) = 0;
};

struct __declspec(uuid("3d6f4f23-5230-4411-a0e9-bad94c2a045c")) __declspec(novtable) IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_AutoRepeatMode(winrt::Windows::Media::MediaPlaybackAutoRepeatMode * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("786c1e78-ce78-4a10-afd6-843fcbb90c2e")) __declspec(novtable) IMediaPlaybackCommandManagerCommandBehavior : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CommandManager(Windows::Media::Playback::IMediaPlaybackCommandManager ** value) = 0;
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall get_EnablingRule(winrt::Windows::Media::Playback::MediaCommandEnablingRule * value) = 0;
    virtual HRESULT __stdcall put_EnablingRule(winrt::Windows::Media::Playback::MediaCommandEnablingRule value) = 0;
    virtual HRESULT __stdcall add_IsEnabledChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_IsEnabledChanged(event_token token) = 0;
};

struct __declspec(uuid("30f064d9-b491-4d0a-bc21-3098bd1332e9")) __declspec(novtable) IMediaPlaybackCommandManagerFastForwardReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("e1504433-a2b0-45d4-b9de-5f42ac14a839")) __declspec(novtable) IMediaPlaybackCommandManagerNextReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("5ceccd1c-c25c-4221-b16c-c3c98ce012d6")) __declspec(novtable) IMediaPlaybackCommandManagerPauseReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("9af0004e-578b-4c56-a006-16159d888a48")) __declspec(novtable) IMediaPlaybackCommandManagerPlayReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("5591a754-d627-4bdd-a90d-86a015b24902")) __declspec(novtable) IMediaPlaybackCommandManagerPositionReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("525e3081-4632-4f76-99b1-d771623f6287")) __declspec(novtable) IMediaPlaybackCommandManagerPreviousReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("18ea3939-4a16-4169-8b05-3eb9f5ff78eb")) __declspec(novtable) IMediaPlaybackCommandManagerRateReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_PlaybackRate(double * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("9f085947-a3c0-425d-aaef-97ba7898b141")) __declspec(novtable) IMediaPlaybackCommandManagerRewindReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("50a05cef-63ee-4a96-b7b5-fee08b9ff90c")) __declspec(novtable) IMediaPlaybackCommandManagerShuffleReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_IsShuffleRequested(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("047097d2-e4af-48ab-b283-6929e674ece2")) __declspec(novtable) IMediaPlaybackItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_AudioTracksChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AudioTracksChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VideoTracksChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VideoTracksChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_TimedMetadataTracksChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TimedMetadataTracksChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Media::Core::IMediaSource2 ** value) = 0;
    virtual HRESULT __stdcall get_AudioTracks(Windows::Foundation::Collections::IVectorView<Windows::Media::Core::AudioTrack> ** value) = 0;
    virtual HRESULT __stdcall get_VideoTracks(Windows::Foundation::Collections::IVectorView<Windows::Media::Core::VideoTrack> ** value) = 0;
    virtual HRESULT __stdcall get_TimedMetadataTracks(Windows::Foundation::Collections::IVectorView<Windows::Media::Core::TimedMetadataTrack> ** value) = 0;
};

struct __declspec(uuid("d859d171-d7ef-4b81-ac1f-f40493cbb091")) __declspec(novtable) IMediaPlaybackItem2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BreakSchedule(Windows::Media::Playback::IMediaBreakSchedule ** value) = 0;
    virtual HRESULT __stdcall get_StartTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_DurationLimit(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall get_CanSkip(bool * value) = 0;
    virtual HRESULT __stdcall put_CanSkip(bool value) = 0;
    virtual HRESULT __stdcall abi_GetDisplayProperties(Windows::Media::Playback::IMediaItemDisplayProperties ** value) = 0;
    virtual HRESULT __stdcall abi_ApplyDisplayProperties(Windows::Media::Playback::IMediaItemDisplayProperties * value) = 0;
};

struct __declspec(uuid("69fbef2b-dcd6-4df9-a450-dbf4c6f1c2c2")) __declspec(novtable) IMediaPlaybackItemError : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ErrorCode(winrt::Windows::Media::Playback::MediaPlaybackItemErrorCode * value) = 0;
    virtual HRESULT __stdcall get_ExtendedError(HRESULT * value) = 0;
};

struct __declspec(uuid("7133fce1-1769-4ff9-a7c1-38d2c4d42360")) __declspec(novtable) IMediaPlaybackItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Media::Core::IMediaSource2 * source, Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
};

struct __declspec(uuid("d77cdf3a-b947-4972-b35d-adfb931a71e6")) __declspec(novtable) IMediaPlaybackItemFactory2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithStartTime(Windows::Media::Core::IMediaSource2 * source, Windows::Foundation::TimeSpan startTime, Windows::Media::Playback::IMediaPlaybackItem ** result) = 0;
    virtual HRESULT __stdcall abi_CreateWithStartTimeAndDurationLimit(Windows::Media::Core::IMediaSource2 * source, Windows::Foundation::TimeSpan startTime, Windows::Foundation::TimeSpan durationLimit, Windows::Media::Playback::IMediaPlaybackItem ** result) = 0;
};

struct __declspec(uuid("7703134a-e9a7-47c3-862c-c656d30683d4")) __declspec(novtable) IMediaPlaybackItemFailedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Item(Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
    virtual HRESULT __stdcall get_Error(Windows::Media::Playback::IMediaPlaybackItemError ** value) = 0;
};

struct __declspec(uuid("cbd9bd82-3037-4fbe-ae8f-39fc39edf4ef")) __declspec(novtable) IMediaPlaybackItemOpenedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Item(Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
};

struct __declspec(uuid("4b1be7f4-4345-403c-8a67-f5de91df4c86")) __declspec(novtable) IMediaPlaybackItemStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindFromMediaSource(Windows::Media::Core::IMediaSource2 * source, Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
};

struct __declspec(uuid("7f77ee9c-dc42-4e26-a98d-7850df8ec925")) __declspec(novtable) IMediaPlaybackList : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ItemFailed(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemFailedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ItemFailed(event_token token) = 0;
    virtual HRESULT __stdcall add_CurrentItemChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CurrentItemChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ItemOpened(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ItemOpened(event_token token) = 0;
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IObservableVector<Windows::Media::Playback::MediaPlaybackItem> ** value) = 0;
    virtual HRESULT __stdcall get_AutoRepeatEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoRepeatEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ShuffleEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_ShuffleEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_CurrentItem(Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
    virtual HRESULT __stdcall get_CurrentItemIndex(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_MoveNext(Windows::Media::Playback::IMediaPlaybackItem ** item) = 0;
    virtual HRESULT __stdcall abi_MovePrevious(Windows::Media::Playback::IMediaPlaybackItem ** item) = 0;
    virtual HRESULT __stdcall abi_MoveTo(uint32_t itemIndex, Windows::Media::Playback::IMediaPlaybackItem ** item) = 0;
};

struct __declspec(uuid("0e09b478-600a-4274-a14b-0b6723d0f48b")) __declspec(novtable) IMediaPlaybackList2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxPrefetchTime(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_MaxPrefetchTime(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_StartingItem(Windows::Media::Playback::IMediaPlaybackItem ** value) = 0;
    virtual HRESULT __stdcall put_StartingItem(Windows::Media::Playback::IMediaPlaybackItem * value) = 0;
    virtual HRESULT __stdcall get_ShuffledItems(Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaPlaybackItem> ** value) = 0;
    virtual HRESULT __stdcall abi_SetShuffledItems(Windows::Foundation::Collections::IIterable<Windows::Media::Playback::MediaPlaybackItem> * value) = 0;
};

struct __declspec(uuid("c32b683d-0407-41ba-8946-8b345a5a5435")) __declspec(novtable) IMediaPlaybackSession : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_PlaybackStateChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PlaybackStateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PlaybackRateChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PlaybackRateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_SeekCompleted(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SeekCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_BufferingStarted(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BufferingStarted(event_token token) = 0;
    virtual HRESULT __stdcall add_BufferingEnded(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BufferingEnded(event_token token) = 0;
    virtual HRESULT __stdcall add_BufferingProgressChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BufferingProgressChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_DownloadProgressChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DownloadProgressChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_NaturalDurationChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NaturalDurationChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PositionChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PositionChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_NaturalVideoSizeChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NaturalVideoSizeChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_MediaPlayer(Windows::Media::Playback::IMediaPlayer ** value) = 0;
    virtual HRESULT __stdcall get_NaturalDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Position(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_PlaybackState(winrt::Windows::Media::Playback::MediaPlaybackState * value) = 0;
    virtual HRESULT __stdcall get_CanSeek(bool * value) = 0;
    virtual HRESULT __stdcall get_CanPause(bool * value) = 0;
    virtual HRESULT __stdcall get_IsProtected(bool * value) = 0;
    virtual HRESULT __stdcall get_PlaybackRate(double * value) = 0;
    virtual HRESULT __stdcall put_PlaybackRate(double value) = 0;
    virtual HRESULT __stdcall get_BufferingProgress(double * value) = 0;
    virtual HRESULT __stdcall get_DownloadProgress(double * value) = 0;
    virtual HRESULT __stdcall get_NaturalVideoHeight(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_NaturalVideoWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_NormalizedSourceRect(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_NormalizedSourceRect(Windows::Foundation::Rect value) = 0;
    virtual HRESULT __stdcall get_StereoscopicVideoPackingMode(winrt::Windows::Media::MediaProperties::StereoscopicVideoPackingMode * value) = 0;
    virtual HRESULT __stdcall put_StereoscopicVideoPackingMode(winrt::Windows::Media::MediaProperties::StereoscopicVideoPackingMode value) = 0;
};

struct __declspec(uuid("ef9dc2bc-9317-4696-b051-2bad643177b5")) __declspec(novtable) IMediaPlaybackSource : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("72b41319-bbfb-46a3-9372-9c9c744b9438")) __declspec(novtable) IMediaPlaybackTimedMetadataTrackList : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_PresentationModeChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PresentationModeChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetPresentationMode(uint32_t index, winrt::Windows::Media::Playback::TimedMetadataTrackPresentationMode * value) = 0;
    virtual HRESULT __stdcall abi_SetPresentationMode(uint32_t index, winrt::Windows::Media::Playback::TimedMetadataTrackPresentationMode value) = 0;
};

struct __declspec(uuid("381a83cb-6fff-499b-8d64-2885dfc1249e")) __declspec(novtable) IMediaPlayer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AutoPlay(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoPlay(bool value) = 0;
    virtual HRESULT __stdcall get_NaturalDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Position(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_BufferingProgress(double * value) = 0;
    virtual HRESULT __stdcall get_CurrentState(winrt::Windows::Media::Playback::MediaPlayerState * value) = 0;
    virtual HRESULT __stdcall get_CanSeek(bool * value) = 0;
    virtual HRESULT __stdcall get_CanPause(bool * value) = 0;
    virtual HRESULT __stdcall get_IsLoopingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsLoopingEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsProtected(bool * value) = 0;
    virtual HRESULT __stdcall get_IsMuted(bool * value) = 0;
    virtual HRESULT __stdcall put_IsMuted(bool value) = 0;
    virtual HRESULT __stdcall get_PlaybackRate(double * value) = 0;
    virtual HRESULT __stdcall put_PlaybackRate(double value) = 0;
    virtual HRESULT __stdcall get_Volume(double * value) = 0;
    virtual HRESULT __stdcall put_Volume(double value) = 0;
    virtual HRESULT __stdcall get_PlaybackMediaMarkers(Windows::Media::Playback::IPlaybackMediaMarkerSequence ** value) = 0;
    virtual HRESULT __stdcall add_MediaOpened(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MediaOpened(event_token token) = 0;
    virtual HRESULT __stdcall add_MediaEnded(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MediaEnded(event_token token) = 0;
    virtual HRESULT __stdcall add_MediaFailed(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerFailedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MediaFailed(event_token token) = 0;
    virtual HRESULT __stdcall add_CurrentStateChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CurrentStateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PlaybackMediaMarkerReached(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PlaybackMediaMarkerReached(event_token token) = 0;
    virtual HRESULT __stdcall add_MediaPlayerRateChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerRateChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MediaPlayerRateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VolumeChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VolumeChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_SeekCompleted(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SeekCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_BufferingStarted(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BufferingStarted(event_token token) = 0;
    virtual HRESULT __stdcall add_BufferingEnded(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BufferingEnded(event_token token) = 0;
    virtual HRESULT __stdcall abi_Play() = 0;
    virtual HRESULT __stdcall abi_Pause() = 0;
    virtual HRESULT __stdcall abi_SetUriSource(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("3c841218-2123-4fc5-9082-2f883f77bdf5")) __declspec(novtable) IMediaPlayer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SystemMediaTransportControls(Windows::Media::ISystemMediaTransportControls ** value) = 0;
    virtual HRESULT __stdcall get_AudioCategory(winrt::Windows::Media::Playback::MediaPlayerAudioCategory * value) = 0;
    virtual HRESULT __stdcall put_AudioCategory(winrt::Windows::Media::Playback::MediaPlayerAudioCategory value) = 0;
    virtual HRESULT __stdcall get_AudioDeviceType(winrt::Windows::Media::Playback::MediaPlayerAudioDeviceType * value) = 0;
    virtual HRESULT __stdcall put_AudioDeviceType(winrt::Windows::Media::Playback::MediaPlayerAudioDeviceType value) = 0;
};

struct __declspec(uuid("ee0660da-031b-4feb-bd9b-92e0a0a8d299")) __declspec(novtable) IMediaPlayer3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_IsMutedChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_IsMutedChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_SourceChanged(Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SourceChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_AudioBalance(double * value) = 0;
    virtual HRESULT __stdcall put_AudioBalance(double value) = 0;
    virtual HRESULT __stdcall get_RealTimePlayback(bool * value) = 0;
    virtual HRESULT __stdcall put_RealTimePlayback(bool value) = 0;
    virtual HRESULT __stdcall get_StereoscopicVideoRenderMode(winrt::Windows::Media::Playback::StereoscopicVideoRenderMode * value) = 0;
    virtual HRESULT __stdcall put_StereoscopicVideoRenderMode(winrt::Windows::Media::Playback::StereoscopicVideoRenderMode value) = 0;
    virtual HRESULT __stdcall get_BreakManager(Windows::Media::Playback::IMediaBreakManager ** value) = 0;
    virtual HRESULT __stdcall get_CommandManager(Windows::Media::Playback::IMediaPlaybackCommandManager ** value) = 0;
    virtual HRESULT __stdcall get_AudioDevice(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
    virtual HRESULT __stdcall put_AudioDevice(Windows::Devices::Enumeration::IDeviceInformation * value) = 0;
    virtual HRESULT __stdcall get_TimelineController(Windows::Media::IMediaTimelineController ** value) = 0;
    virtual HRESULT __stdcall put_TimelineController(Windows::Media::IMediaTimelineController * value) = 0;
    virtual HRESULT __stdcall get_TimelineControllerPositionOffset(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_TimelineControllerPositionOffset(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_PlaybackSession(Windows::Media::Playback::IMediaPlaybackSession ** value) = 0;
    virtual HRESULT __stdcall abi_StepForwardOneFrame() = 0;
    virtual HRESULT __stdcall abi_StepBackwardOneFrame() = 0;
    virtual HRESULT __stdcall abi_GetAsCastingSource(Windows::Media::Casting::ICastingSource ** returnValue) = 0;
};

struct __declspec(uuid("80035db0-7448-4770-afcf-2a57450914c5")) __declspec(novtable) IMediaPlayer4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetSurfaceSize(Windows::Foundation::Size size) = 0;
    virtual HRESULT __stdcall abi_GetSurface(Windows::UI::Composition::ICompositor * compositor, Windows::Media::Playback::IMediaPlayerSurface ** result) = 0;
};

struct __declspec(uuid("c75a9405-c801-412a-835b-83fc0e622a8e")) __declspec(novtable) IMediaPlayerDataReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Data(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("85a1deda-cab6-4cc0-8be3-6035f4de2591")) __declspec(novtable) IMediaPlayerEffects : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddAudioEffect(hstring activatableClassId, bool effectOptional, Windows::Foundation::Collections::IPropertySet * configuration) = 0;
    virtual HRESULT __stdcall abi_RemoveAllEffects() = 0;
};

struct __declspec(uuid("fa419a79-1bbe-46c5-ae1f-8ee69fb3c2c7")) __declspec(novtable) IMediaPlayerEffects2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddVideoEffect(hstring activatableClassId, bool effectOptional, Windows::Foundation::Collections::IPropertySet * effectConfiguration) = 0;
};

struct __declspec(uuid("2744e9b9-a7e3-4f16-bac4-7914ebc08301")) __declspec(novtable) IMediaPlayerFailedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Error(winrt::Windows::Media::Playback::MediaPlayerError * value) = 0;
    virtual HRESULT __stdcall get_ExtendedErrorCode(HRESULT * value) = 0;
    virtual HRESULT __stdcall get_ErrorMessage(hstring * value) = 0;
};

struct __declspec(uuid("40600d58-3b61-4bb2-989f-fc65608b6cab")) __declspec(novtable) IMediaPlayerRateChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NewRate(double * value) = 0;
};

struct __declspec(uuid("bd4f8897-1423-4c3e-82c5-0fb1af94f715")) __declspec(novtable) IMediaPlayerSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProtectionManager(Windows::Media::Protection::IMediaProtectionManager ** value) = 0;
    virtual HRESULT __stdcall put_ProtectionManager(Windows::Media::Protection::IMediaProtectionManager * value) = 0;
    virtual HRESULT __stdcall abi_SetFileSource(Windows::Storage::IStorageFile * file) = 0;
    virtual HRESULT __stdcall abi_SetStreamSource(Windows::Storage::Streams::IRandomAccessStream * stream) = 0;
    virtual HRESULT __stdcall abi_SetMediaSource(Windows::Media::Core::IMediaSource * source) = 0;
};

struct __declspec(uuid("82449b9f-7322-4c0b-b03b-3e69a48260c5")) __declspec(novtable) IMediaPlayerSource2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Source(Windows::Media::Playback::IMediaPlaybackSource ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::Media::Playback::IMediaPlaybackSource * value) = 0;
};

struct __declspec(uuid("0ed653bc-b736-49c3-830b-764a3845313a")) __declspec(novtable) IMediaPlayerSurface : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CompositionSurface(Windows::UI::Composition::ICompositionSurface ** value) = 0;
    virtual HRESULT __stdcall get_Compositor(Windows::UI::Composition::ICompositor ** value) = 0;
    virtual HRESULT __stdcall get_MediaPlayer(Windows::Media::Playback::IMediaPlayer ** value) = 0;
};

struct __declspec(uuid("c4d22f5c-3c1c-4444-b6b9-778b0422d41a")) __declspec(novtable) IPlaybackMediaMarker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Time(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_MediaMarkerType(hstring * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("8c530a78-e0ae-4e1a-a8c8-e23f982a937b")) __declspec(novtable) IPlaybackMediaMarkerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromTime(Windows::Foundation::TimeSpan value, Windows::Media::Playback::IPlaybackMediaMarker ** marker) = 0;
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::TimeSpan value, hstring mediaMarketType, hstring text, Windows::Media::Playback::IPlaybackMediaMarker ** marker) = 0;
};

struct __declspec(uuid("578cd1b9-90e2-4e60-abc4-8740b01f6196")) __declspec(novtable) IPlaybackMediaMarkerReachedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PlaybackMediaMarker(Windows::Media::Playback::IPlaybackMediaMarker ** value) = 0;
};

struct __declspec(uuid("f2810cee-638b-46cf-8817-1d111fe9d8c4")) __declspec(novtable) IPlaybackMediaMarkerSequence : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Size(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_Insert(Windows::Media::Playback::IPlaybackMediaMarker * value) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
};

struct __declspec(uuid("d1636099-65df-45ae-8cef-dc0b53fdc2bb")) __declspec(novtable) ITimedMetadataPresentationModeChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Track(Windows::Media::Core::ITimedMetadataTrack ** value) = 0;
    virtual HRESULT __stdcall get_OldPresentationMode(winrt::Windows::Media::Playback::TimedMetadataTrackPresentationMode * value) = 0;
    virtual HRESULT __stdcall get_NewPresentationMode(winrt::Windows::Media::Playback::TimedMetadataTrackPresentationMode * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> { using default_interface = Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaBreak> { using default_interface = Windows::Media::Playback::IMediaBreak; };
template <> struct traits<Windows::Media::Playback::MediaBreakEndedEventArgs> { using default_interface = Windows::Media::Playback::IMediaBreakEndedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaBreakManager> { using default_interface = Windows::Media::Playback::IMediaBreakManager; };
template <> struct traits<Windows::Media::Playback::MediaBreakSchedule> { using default_interface = Windows::Media::Playback::IMediaBreakSchedule; };
template <> struct traits<Windows::Media::Playback::MediaBreakSeekedOverEventArgs> { using default_interface = Windows::Media::Playback::IMediaBreakSeekedOverEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaBreakSkippedEventArgs> { using default_interface = Windows::Media::Playback::IMediaBreakSkippedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaBreakStartedEventArgs> { using default_interface = Windows::Media::Playback::IMediaBreakStartedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaItemDisplayProperties> { using default_interface = Windows::Media::Playback::IMediaItemDisplayProperties; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackAudioTrackList> { using default_interface = Windows::Foundation::Collections::IVectorView<Windows::Media::Core::AudioTrack>; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManager> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManager; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackItem> { using default_interface = Windows::Media::Playback::IMediaPlaybackItem; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackItemError> { using default_interface = Windows::Media::Playback::IMediaPlaybackItemError; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackItemFailedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlaybackItemOpenedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackList> { using default_interface = Windows::Media::Playback::IMediaPlaybackList; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackSession> { using default_interface = Windows::Media::Playback::IMediaPlaybackSession; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList> { using default_interface = Windows::Foundation::Collections::IVectorView<Windows::Media::Core::TimedMetadataTrack>; };
template <> struct traits<Windows::Media::Playback::MediaPlaybackVideoTrackList> { using default_interface = Windows::Foundation::Collections::IVectorView<Windows::Media::Core::VideoTrack>; };
template <> struct traits<Windows::Media::Playback::MediaPlayer> { using default_interface = Windows::Media::Playback::IMediaPlayer; };
template <> struct traits<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlayerDataReceivedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlayerFailedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlayerFailedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlayerRateChangedEventArgs> { using default_interface = Windows::Media::Playback::IMediaPlayerRateChangedEventArgs; };
template <> struct traits<Windows::Media::Playback::MediaPlayerSurface> { using default_interface = Windows::Media::Playback::IMediaPlayerSurface; };
template <> struct traits<Windows::Media::Playback::PlaybackMediaMarker> { using default_interface = Windows::Media::Playback::IPlaybackMediaMarker; };
template <> struct traits<Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs> { using default_interface = Windows::Media::Playback::IPlaybackMediaMarkerReachedEventArgs; };
template <> struct traits<Windows::Media::Playback::PlaybackMediaMarkerSequence> { using default_interface = Windows::Media::Playback::IPlaybackMediaMarkerSequence; };
template <> struct traits<Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> { using default_interface = Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs; };

}

namespace Windows::Media::Playback {

template <typename D>
struct WINRT_EBO impl_IBackgroundMediaPlayerStatics
{
    Windows::Media::Playback::MediaPlayer Current() const;
    event_token MessageReceivedFromBackground(const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value) const;
    using MessageReceivedFromBackground_revoker = event_revoker<IBackgroundMediaPlayerStatics>;
    MessageReceivedFromBackground_revoker MessageReceivedFromBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value) const;
    void MessageReceivedFromBackground(event_token token) const;
    event_token MessageReceivedFromForeground(const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value) const;
    using MessageReceivedFromForeground_revoker = event_revoker<IBackgroundMediaPlayerStatics>;
    MessageReceivedFromForeground_revoker MessageReceivedFromForeground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs> & value) const;
    void MessageReceivedFromForeground(event_token token) const;
    void SendMessageToBackground(const Windows::Foundation::Collections::ValueSet & value) const;
    void SendMessageToForeground(const Windows::Foundation::Collections::ValueSet & value) const;
    bool IsMediaPlaying() const;
    void Shutdown() const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentMediaPlaybackItemChangedEventArgs
{
    Windows::Media::Playback::MediaPlaybackItem NewItem() const;
    Windows::Media::Playback::MediaPlaybackItem OldItem() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaBreak
{
    Windows::Media::Playback::MediaPlaybackList PlaybackList() const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> PresentationPosition() const;
    Windows::Media::Playback::MediaBreakInsertionMethod InsertionMethod() const;
    Windows::Foundation::Collections::ValueSet CustomProperties() const;
    bool CanStart() const;
    void CanStart(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaBreakEndedEventArgs
{
    Windows::Media::Playback::MediaBreak MediaBreak() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaBreakFactory
{
    Windows::Media::Playback::MediaBreak Create(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod) const;
    Windows::Media::Playback::MediaBreak CreateWithPresentationPosition(Windows::Media::Playback::MediaBreakInsertionMethod insertionMethod, const Windows::Foundation::TimeSpan & presentationPosition) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaBreakManager
{
    event_token BreaksSeekedOver(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSeekedOverEventArgs> & handler) const;
    using BreaksSeekedOver_revoker = event_revoker<IMediaBreakManager>;
    BreaksSeekedOver_revoker BreaksSeekedOver(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSeekedOverEventArgs> & handler) const;
    void BreaksSeekedOver(event_token token) const;
    event_token BreakStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakStartedEventArgs> & handler) const;
    using BreakStarted_revoker = event_revoker<IMediaBreakManager>;
    BreakStarted_revoker BreakStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakStartedEventArgs> & handler) const;
    void BreakStarted(event_token token) const;
    event_token BreakEnded(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakEndedEventArgs> & handler) const;
    using BreakEnded_revoker = event_revoker<IMediaBreakManager>;
    BreakEnded_revoker BreakEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakEndedEventArgs> & handler) const;
    void BreakEnded(event_token token) const;
    event_token BreakSkipped(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSkippedEventArgs> & handler) const;
    using BreakSkipped_revoker = event_revoker<IMediaBreakManager>;
    BreakSkipped_revoker BreakSkipped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakManager, Windows::Media::Playback::MediaBreakSkippedEventArgs> & handler) const;
    void BreakSkipped(event_token token) const;
    Windows::Media::Playback::MediaBreak CurrentBreak() const;
    Windows::Media::Playback::MediaPlaybackSession PlaybackSession() const;
    void PlayBreak(const Windows::Media::Playback::MediaBreak & value) const;
    void SkipCurrentBreak() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaBreakSchedule
{
    event_token ScheduleChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakSchedule, Windows::Foundation::IInspectable> & handler) const;
    using ScheduleChanged_revoker = event_revoker<IMediaBreakSchedule>;
    ScheduleChanged_revoker ScheduleChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaBreakSchedule, Windows::Foundation::IInspectable> & handler) const;
    void ScheduleChanged(event_token token) const;
    void InsertMidrollBreak(const Windows::Media::Playback::MediaBreak & mediaBreak) const;
    void RemoveMidrollBreak(const Windows::Media::Playback::MediaBreak & mediaBreak) const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak> MidrollBreaks() const;
    void PrerollBreak(const Windows::Media::Playback::MediaBreak & value) const;
    Windows::Media::Playback::MediaBreak PrerollBreak() const;
    void PostrollBreak(const Windows::Media::Playback::MediaBreak & value) const;
    Windows::Media::Playback::MediaBreak PostrollBreak() const;
    Windows::Media::Playback::MediaPlaybackItem PlaybackItem() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaBreakSeekedOverEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaBreak> SeekedOverBreaks() const;
    Windows::Foundation::TimeSpan OldPosition() const;
    Windows::Foundation::TimeSpan NewPosition() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaBreakSkippedEventArgs
{
    Windows::Media::Playback::MediaBreak MediaBreak() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaBreakStartedEventArgs
{
    Windows::Media::Playback::MediaBreak MediaBreak() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaEnginePlaybackSource
{
    [[deprecated("Use MediaPlayer instead of MediaEngine. For more info, see MSDN.")]] Windows::Media::Playback::MediaPlaybackItem CurrentItem() const;
    [[deprecated("Use MediaPlayer instead of MediaEngine. For more info, see MSDN.")]] void SetPlaybackSource(const Windows::Media::Playback::IMediaPlaybackSource & source) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaItemDisplayProperties
{
    Windows::Media::MediaPlaybackType Type() const;
    void Type(Windows::Media::MediaPlaybackType value) const;
    Windows::Media::MusicDisplayProperties MusicProperties() const;
    Windows::Media::VideoDisplayProperties VideoProperties() const;
    Windows::Storage::Streams::RandomAccessStreamReference Thumbnail() const;
    void Thumbnail(const Windows::Storage::Streams::RandomAccessStreamReference & value) const;
    void ClearAll() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManager
{
    bool IsEnabled() const;
    void IsEnabled(bool value) const;
    Windows::Media::Playback::MediaPlayer MediaPlayer() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior PlayBehavior() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior PauseBehavior() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior NextBehavior() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior PreviousBehavior() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior FastForwardBehavior() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior RewindBehavior() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior ShuffleBehavior() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior AutoRepeatModeBehavior() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior PositionBehavior() const;
    Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior RateBehavior() const;
    event_token PlayReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> & handler) const;
    using PlayReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    PlayReceived_revoker PlayReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs> & handler) const;
    void PlayReceived(event_token token) const;
    event_token PauseReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> & handler) const;
    using PauseReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    PauseReceived_revoker PauseReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs> & handler) const;
    void PauseReceived(event_token token) const;
    event_token NextReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> & handler) const;
    using NextReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    NextReceived_revoker NextReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs> & handler) const;
    void NextReceived(event_token token) const;
    event_token PreviousReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> & handler) const;
    using PreviousReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    PreviousReceived_revoker PreviousReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs> & handler) const;
    void PreviousReceived(event_token token) const;
    event_token FastForwardReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> & handler) const;
    using FastForwardReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    FastForwardReceived_revoker FastForwardReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs> & handler) const;
    void FastForwardReceived(event_token token) const;
    event_token RewindReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> & handler) const;
    using RewindReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    RewindReceived_revoker RewindReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs> & handler) const;
    void RewindReceived(event_token token) const;
    event_token ShuffleReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> & handler) const;
    using ShuffleReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    ShuffleReceived_revoker ShuffleReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs> & handler) const;
    void ShuffleReceived(event_token token) const;
    event_token AutoRepeatModeReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> & handler) const;
    using AutoRepeatModeReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    AutoRepeatModeReceived_revoker AutoRepeatModeReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> & handler) const;
    void AutoRepeatModeReceived(event_token token) const;
    event_token PositionReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> & handler) const;
    using PositionReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    PositionReceived_revoker PositionReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs> & handler) const;
    void PositionReceived(event_token token) const;
    event_token RateReceived(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> & handler) const;
    using RateReceived_revoker = event_revoker<IMediaPlaybackCommandManager>;
    RateReceived_revoker RateReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManager, Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs> & handler) const;
    void RateReceived(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Media::MediaPlaybackAutoRepeatMode AutoRepeatMode() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerCommandBehavior
{
    Windows::Media::Playback::MediaPlaybackCommandManager CommandManager() const;
    bool IsEnabled() const;
    Windows::Media::Playback::MediaCommandEnablingRule EnablingRule() const;
    void EnablingRule(Windows::Media::Playback::MediaCommandEnablingRule value) const;
    event_token IsEnabledChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, Windows::Foundation::IInspectable> & handler) const;
    using IsEnabledChanged_revoker = event_revoker<IMediaPlaybackCommandManagerCommandBehavior>;
    IsEnabledChanged_revoker IsEnabledChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior, Windows::Foundation::IInspectable> & handler) const;
    void IsEnabledChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerFastForwardReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerNextReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerPauseReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerPlayReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerPositionReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::TimeSpan Position() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerPreviousReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerRateReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    double PlaybackRate() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerRewindReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackCommandManagerShuffleReceivedEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    bool IsShuffleRequested() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackItem
{
    event_token AudioTracksChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const;
    using AudioTracksChanged_revoker = event_revoker<IMediaPlaybackItem>;
    AudioTracksChanged_revoker AudioTracksChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const;
    void AudioTracksChanged(event_token token) const;
    event_token VideoTracksChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const;
    using VideoTracksChanged_revoker = event_revoker<IMediaPlaybackItem>;
    VideoTracksChanged_revoker VideoTracksChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const;
    void VideoTracksChanged(event_token token) const;
    event_token TimedMetadataTracksChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const;
    using TimedMetadataTracksChanged_revoker = event_revoker<IMediaPlaybackItem>;
    TimedMetadataTracksChanged_revoker TimedMetadataTracksChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackItem, Windows::Foundation::Collections::IVectorChangedEventArgs> & handler) const;
    void TimedMetadataTracksChanged(event_token token) const;
    Windows::Media::Core::MediaSource Source() const;
    Windows::Media::Playback::MediaPlaybackAudioTrackList AudioTracks() const;
    Windows::Media::Playback::MediaPlaybackVideoTrackList VideoTracks() const;
    Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList TimedMetadataTracks() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackItem2
{
    Windows::Media::Playback::MediaBreakSchedule BreakSchedule() const;
    Windows::Foundation::TimeSpan StartTime() const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> DurationLimit() const;
    bool CanSkip() const;
    void CanSkip(bool value) const;
    Windows::Media::Playback::MediaItemDisplayProperties GetDisplayProperties() const;
    void ApplyDisplayProperties(const Windows::Media::Playback::MediaItemDisplayProperties & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackItemError
{
    Windows::Media::Playback::MediaPlaybackItemErrorCode ErrorCode() const;
    HRESULT ExtendedError() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackItemFactory
{
    Windows::Media::Playback::MediaPlaybackItem Create(const Windows::Media::Core::MediaSource & source) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackItemFactory2
{
    Windows::Media::Playback::MediaPlaybackItem CreateWithStartTime(const Windows::Media::Core::MediaSource & source, const Windows::Foundation::TimeSpan & startTime) const;
    Windows::Media::Playback::MediaPlaybackItem CreateWithStartTimeAndDurationLimit(const Windows::Media::Core::MediaSource & source, const Windows::Foundation::TimeSpan & startTime, const Windows::Foundation::TimeSpan & durationLimit) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackItemFailedEventArgs
{
    Windows::Media::Playback::MediaPlaybackItem Item() const;
    Windows::Media::Playback::MediaPlaybackItemError Error() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackItemOpenedEventArgs
{
    Windows::Media::Playback::MediaPlaybackItem Item() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackItemStatics
{
    Windows::Media::Playback::MediaPlaybackItem FindFromMediaSource(const Windows::Media::Core::MediaSource & source) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackList
{
    event_token ItemFailed(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemFailedEventArgs> & handler) const;
    using ItemFailed_revoker = event_revoker<IMediaPlaybackList>;
    ItemFailed_revoker ItemFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemFailedEventArgs> & handler) const;
    void ItemFailed(event_token token) const;
    event_token CurrentItemChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> & handler) const;
    using CurrentItemChanged_revoker = event_revoker<IMediaPlaybackList>;
    CurrentItemChanged_revoker CurrentItemChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs> & handler) const;
    void CurrentItemChanged(event_token token) const;
    event_token ItemOpened(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs> & handler) const;
    using ItemOpened_revoker = event_revoker<IMediaPlaybackList>;
    ItemOpened_revoker ItemOpened(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackList, Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs> & handler) const;
    void ItemOpened(event_token token) const;
    Windows::Foundation::Collections::IObservableVector<Windows::Media::Playback::MediaPlaybackItem> Items() const;
    bool AutoRepeatEnabled() const;
    void AutoRepeatEnabled(bool value) const;
    bool ShuffleEnabled() const;
    void ShuffleEnabled(bool value) const;
    Windows::Media::Playback::MediaPlaybackItem CurrentItem() const;
    uint32_t CurrentItemIndex() const;
    Windows::Media::Playback::MediaPlaybackItem MoveNext() const;
    Windows::Media::Playback::MediaPlaybackItem MovePrevious() const;
    Windows::Media::Playback::MediaPlaybackItem MoveTo(uint32_t itemIndex) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackList2
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> MaxPrefetchTime() const;
    void MaxPrefetchTime(const optional<Windows::Foundation::TimeSpan> & value) const;
    Windows::Media::Playback::MediaPlaybackItem StartingItem() const;
    void StartingItem(const Windows::Media::Playback::MediaPlaybackItem & value) const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::Playback::MediaPlaybackItem> ShuffledItems() const;
    void SetShuffledItems(iterable<Windows::Media::Playback::MediaPlaybackItem> value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackSession
{
    event_token PlaybackStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using PlaybackStateChanged_revoker = event_revoker<IMediaPlaybackSession>;
    PlaybackStateChanged_revoker PlaybackStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void PlaybackStateChanged(event_token token) const;
    event_token PlaybackRateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using PlaybackRateChanged_revoker = event_revoker<IMediaPlaybackSession>;
    PlaybackRateChanged_revoker PlaybackRateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void PlaybackRateChanged(event_token token) const;
    event_token SeekCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using SeekCompleted_revoker = event_revoker<IMediaPlaybackSession>;
    SeekCompleted_revoker SeekCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void SeekCompleted(event_token token) const;
    event_token BufferingStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using BufferingStarted_revoker = event_revoker<IMediaPlaybackSession>;
    BufferingStarted_revoker BufferingStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void BufferingStarted(event_token token) const;
    event_token BufferingEnded(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using BufferingEnded_revoker = event_revoker<IMediaPlaybackSession>;
    BufferingEnded_revoker BufferingEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void BufferingEnded(event_token token) const;
    event_token BufferingProgressChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using BufferingProgressChanged_revoker = event_revoker<IMediaPlaybackSession>;
    BufferingProgressChanged_revoker BufferingProgressChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void BufferingProgressChanged(event_token token) const;
    event_token DownloadProgressChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using DownloadProgressChanged_revoker = event_revoker<IMediaPlaybackSession>;
    DownloadProgressChanged_revoker DownloadProgressChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void DownloadProgressChanged(event_token token) const;
    event_token NaturalDurationChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using NaturalDurationChanged_revoker = event_revoker<IMediaPlaybackSession>;
    NaturalDurationChanged_revoker NaturalDurationChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void NaturalDurationChanged(event_token token) const;
    event_token PositionChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using PositionChanged_revoker = event_revoker<IMediaPlaybackSession>;
    PositionChanged_revoker PositionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void PositionChanged(event_token token) const;
    event_token NaturalVideoSizeChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    using NaturalVideoSizeChanged_revoker = event_revoker<IMediaPlaybackSession>;
    NaturalVideoSizeChanged_revoker NaturalVideoSizeChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackSession, Windows::Foundation::IInspectable> & value) const;
    void NaturalVideoSizeChanged(event_token token) const;
    Windows::Media::Playback::MediaPlayer MediaPlayer() const;
    Windows::Foundation::TimeSpan NaturalDuration() const;
    Windows::Foundation::TimeSpan Position() const;
    void Position(const Windows::Foundation::TimeSpan & value) const;
    Windows::Media::Playback::MediaPlaybackState PlaybackState() const;
    bool CanSeek() const;
    bool CanPause() const;
    bool IsProtected() const;
    double PlaybackRate() const;
    void PlaybackRate(double value) const;
    double BufferingProgress() const;
    double DownloadProgress() const;
    uint32_t NaturalVideoHeight() const;
    uint32_t NaturalVideoWidth() const;
    Windows::Foundation::Rect NormalizedSourceRect() const;
    void NormalizedSourceRect(const Windows::Foundation::Rect & value) const;
    Windows::Media::MediaProperties::StereoscopicVideoPackingMode StereoscopicVideoPackingMode() const;
    void StereoscopicVideoPackingMode(Windows::Media::MediaProperties::StereoscopicVideoPackingMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackSource
{
};

template <typename D>
struct WINRT_EBO impl_IMediaPlaybackTimedMetadataTrackList
{
    event_token PresentationModeChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> & handler) const;
    using PresentationModeChanged_revoker = event_revoker<IMediaPlaybackTimedMetadataTrackList>;
    PresentationModeChanged_revoker PresentationModeChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList, Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs> & handler) const;
    void PresentationModeChanged(event_token token) const;
    Windows::Media::Playback::TimedMetadataTrackPresentationMode GetPresentationMode(uint32_t index) const;
    void SetPresentationMode(uint32_t index, Windows::Media::Playback::TimedMetadataTrackPresentationMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayer
{
    bool AutoPlay() const;
    void AutoPlay(bool value) const;
    [[deprecated("Use PlaybackSession.NaturalDuration instead of NaturalDuration.  For more info, see MSDN.")]] Windows::Foundation::TimeSpan NaturalDuration() const;
    [[deprecated("Use PlaybackSession.Position instead of Position.  For more info, see MSDN.")]] Windows::Foundation::TimeSpan Position() const;
    [[deprecated("Use PlaybackSession.Position instead of Position.  For more info, see MSDN.")]] void Position(const Windows::Foundation::TimeSpan & value) const;
    [[deprecated("Use PlaybackSession.BufferingProgress instead of BufferingProgress.  For more info, see MSDN.")]] double BufferingProgress() const;
    [[deprecated("Use PlaybackSession.State instead of CurrentState.  For more info, see MSDN.")]] Windows::Media::Playback::MediaPlayerState CurrentState() const;
    [[deprecated("Use PlaybackSession.CanSeek instead of CanSeek.  For more info, see MSDN.")]] bool CanSeek() const;
    [[deprecated("Use PlaybackSession.CanPause instead of CanPause.  For more info, see MSDN.")]] bool CanPause() const;
    bool IsLoopingEnabled() const;
    void IsLoopingEnabled(bool value) const;
    [[deprecated("Use PlaybackSession.IsProtected instead of IsProtected.  For more info, see MSDN.")]] bool IsProtected() const;
    bool IsMuted() const;
    void IsMuted(bool value) const;
    [[deprecated("Use PlaybackSession.PlaybackRate instead of PlaybackRate.  For more info, see MSDN.")]] double PlaybackRate() const;
    [[deprecated("Use PlaybackSession.PlaybackRate instead of PlaybackRate.  For more info, see MSDN.")]] void PlaybackRate(double value) const;
    double Volume() const;
    void Volume(double value) const;
    [[deprecated("Use media tracks on MediaPlaybackItem instead of PlaybackMediaMarkers.  For more info, see MSDN.")]] Windows::Media::Playback::PlaybackMediaMarkerSequence PlaybackMediaMarkers() const;
    event_token MediaOpened(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    using MediaOpened_revoker = event_revoker<IMediaPlayer>;
    MediaOpened_revoker MediaOpened(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    void MediaOpened(event_token token) const;
    event_token MediaEnded(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    using MediaEnded_revoker = event_revoker<IMediaPlayer>;
    MediaEnded_revoker MediaEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    void MediaEnded(event_token token) const;
    event_token MediaFailed(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerFailedEventArgs> & value) const;
    using MediaFailed_revoker = event_revoker<IMediaPlayer>;
    MediaFailed_revoker MediaFailed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerFailedEventArgs> & value) const;
    void MediaFailed(event_token token) const;
    [[deprecated("Use PlaybackSession.PlaybackStateChanged instead of CurrentStateChanged.  For more info, see MSDN.")]] event_token CurrentStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    using CurrentStateChanged_revoker = event_revoker<IMediaPlayer>;
    [[deprecated("Use PlaybackSession.PlaybackStateChanged instead of CurrentStateChanged.  For more info, see MSDN.")]] CurrentStateChanged_revoker CurrentStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    [[deprecated("Use PlaybackSession.PlaybackStateChanged instead of CurrentStateChanged.  For more info, see MSDN.")]] void CurrentStateChanged(event_token token) const;
    [[deprecated("Use media tracks on MediaPlaybackItem instead of PlaybackMediaMarkers.  For more info, see MSDN.")]] event_token PlaybackMediaMarkerReached(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs> & value) const;
    using PlaybackMediaMarkerReached_revoker = event_revoker<IMediaPlayer>;
    [[deprecated("Use media tracks on MediaPlaybackItem instead of PlaybackMediaMarkers.  For more info, see MSDN.")]] PlaybackMediaMarkerReached_revoker PlaybackMediaMarkerReached(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs> & value) const;
    [[deprecated("Use media tracks on MediaPlaybackItem instead of PlaybackMediaMarkers.  For more info, see MSDN.")]] void PlaybackMediaMarkerReached(event_token token) const;
    [[deprecated("Use PlaybackSession.PlaybackRateChanged instead of MediaPlayerRateChanged.  For more info, see MSDN.")]] event_token MediaPlayerRateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerRateChangedEventArgs> & value) const;
    using MediaPlayerRateChanged_revoker = event_revoker<IMediaPlayer>;
    [[deprecated("Use PlaybackSession.PlaybackRateChanged instead of MediaPlayerRateChanged.  For more info, see MSDN.")]] MediaPlayerRateChanged_revoker MediaPlayerRateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Media::Playback::MediaPlayerRateChangedEventArgs> & value) const;
    [[deprecated("Use PlaybackSession.PlaybackRateChanged instead of MediaPlayerRateChanged.  For more info, see MSDN.")]] void MediaPlayerRateChanged(event_token token) const;
    event_token VolumeChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    using VolumeChanged_revoker = event_revoker<IMediaPlayer>;
    VolumeChanged_revoker VolumeChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    void VolumeChanged(event_token token) const;
    [[deprecated("Use PlaybackSession.SeekCompleted instead of SeekCompleted.  For more info, see MSDN.")]] event_token SeekCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    using SeekCompleted_revoker = event_revoker<IMediaPlayer>;
    [[deprecated("Use PlaybackSession.SeekCompleted instead of SeekCompleted.  For more info, see MSDN.")]] SeekCompleted_revoker SeekCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    [[deprecated("Use PlaybackSession.SeekCompleted instead of SeekCompleted.  For more info, see MSDN.")]] void SeekCompleted(event_token token) const;
    [[deprecated("Use PlaybackSession.BufferingStarted instead of BufferingStarted.  For more info, see MSDN.")]] event_token BufferingStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    using BufferingStarted_revoker = event_revoker<IMediaPlayer>;
    [[deprecated("Use PlaybackSession.BufferingStarted instead of BufferingStarted.  For more info, see MSDN.")]] BufferingStarted_revoker BufferingStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    [[deprecated("Use PlaybackSession.BufferingStarted instead of BufferingStarted.  For more info, see MSDN.")]] void BufferingStarted(event_token token) const;
    [[deprecated("Use PlaybackSession.BufferingEnded instead of BufferingEnded.  For more info, see MSDN.")]] event_token BufferingEnded(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    using BufferingEnded_revoker = event_revoker<IMediaPlayer>;
    [[deprecated("Use PlaybackSession.BufferingEnded instead of BufferingEnded.  For more info, see MSDN.")]] BufferingEnded_revoker BufferingEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    [[deprecated("Use PlaybackSession.BufferingEnded instead of BufferingEnded.  For more info, see MSDN.")]] void BufferingEnded(event_token token) const;
    void Play() const;
    void Pause() const;
    [[deprecated("Use Source instead of SetUriSource.  For more info, see MSDN.")]] void SetUriSource(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayer2
{
    Windows::Media::SystemMediaTransportControls SystemMediaTransportControls() const;
    Windows::Media::Playback::MediaPlayerAudioCategory AudioCategory() const;
    void AudioCategory(Windows::Media::Playback::MediaPlayerAudioCategory value) const;
    Windows::Media::Playback::MediaPlayerAudioDeviceType AudioDeviceType() const;
    void AudioDeviceType(Windows::Media::Playback::MediaPlayerAudioDeviceType value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayer3
{
    event_token IsMutedChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    using IsMutedChanged_revoker = event_revoker<IMediaPlayer3>;
    IsMutedChanged_revoker IsMutedChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    void IsMutedChanged(event_token token) const;
    event_token SourceChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    using SourceChanged_revoker = event_revoker<IMediaPlayer3>;
    SourceChanged_revoker SourceChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Playback::MediaPlayer, Windows::Foundation::IInspectable> & value) const;
    void SourceChanged(event_token token) const;
    double AudioBalance() const;
    void AudioBalance(double value) const;
    bool RealTimePlayback() const;
    void RealTimePlayback(bool value) const;
    Windows::Media::Playback::StereoscopicVideoRenderMode StereoscopicVideoRenderMode() const;
    void StereoscopicVideoRenderMode(Windows::Media::Playback::StereoscopicVideoRenderMode value) const;
    Windows::Media::Playback::MediaBreakManager BreakManager() const;
    Windows::Media::Playback::MediaPlaybackCommandManager CommandManager() const;
    Windows::Devices::Enumeration::DeviceInformation AudioDevice() const;
    void AudioDevice(const Windows::Devices::Enumeration::DeviceInformation & value) const;
    Windows::Media::MediaTimelineController TimelineController() const;
    void TimelineController(const Windows::Media::MediaTimelineController & value) const;
    Windows::Foundation::TimeSpan TimelineControllerPositionOffset() const;
    void TimelineControllerPositionOffset(const Windows::Foundation::TimeSpan & value) const;
    Windows::Media::Playback::MediaPlaybackSession PlaybackSession() const;
    void StepForwardOneFrame() const;
    void StepBackwardOneFrame() const;
    Windows::Media::Casting::CastingSource GetAsCastingSource() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayer4
{
    void SetSurfaceSize(const Windows::Foundation::Size & size) const;
    Windows::Media::Playback::MediaPlayerSurface GetSurface(const Windows::UI::Composition::Compositor & compositor) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerDataReceivedEventArgs
{
    Windows::Foundation::Collections::ValueSet Data() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerEffects
{
    void AddAudioEffect(hstring_view activatableClassId, bool effectOptional, const Windows::Foundation::Collections::IPropertySet & configuration) const;
    void RemoveAllEffects() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerEffects2
{
    void AddVideoEffect(hstring_view activatableClassId, bool effectOptional, const Windows::Foundation::Collections::IPropertySet & effectConfiguration) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerFailedEventArgs
{
    Windows::Media::Playback::MediaPlayerError Error() const;
    HRESULT ExtendedErrorCode() const;
    hstring ErrorMessage() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerRateChangedEventArgs
{
    double NewRate() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerSource
{
    Windows::Media::Protection::MediaProtectionManager ProtectionManager() const;
    void ProtectionManager(const Windows::Media::Protection::MediaProtectionManager & value) const;
    [[deprecated("Use Source instead of SetFileSource.  For more info, see MSDN.")]] void SetFileSource(const Windows::Storage::IStorageFile & file) const;
    [[deprecated("Use Source instead of SetStreamSource.  For more info, see MSDN.")]] void SetStreamSource(const Windows::Storage::Streams::IRandomAccessStream & stream) const;
    [[deprecated("Use Source instead of SetMediaSource.  For more info, see MSDN.")]] void SetMediaSource(const Windows::Media::Core::IMediaSource & source) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerSource2
{
    Windows::Media::Playback::IMediaPlaybackSource Source() const;
    void Source(const Windows::Media::Playback::IMediaPlaybackSource & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerSurface
{
    Windows::UI::Composition::ICompositionSurface CompositionSurface() const;
    Windows::UI::Composition::Compositor Compositor() const;
    Windows::Media::Playback::MediaPlayer MediaPlayer() const;
};

template <typename D>
struct WINRT_EBO impl_IPlaybackMediaMarker
{
    Windows::Foundation::TimeSpan Time() const;
    hstring MediaMarkerType() const;
    hstring Text() const;
};

template <typename D>
struct WINRT_EBO impl_IPlaybackMediaMarkerFactory
{
    Windows::Media::Playback::PlaybackMediaMarker CreateFromTime(const Windows::Foundation::TimeSpan & value) const;
    Windows::Media::Playback::PlaybackMediaMarker Create(const Windows::Foundation::TimeSpan & value, hstring_view mediaMarketType, hstring_view text) const;
};

template <typename D>
struct WINRT_EBO impl_IPlaybackMediaMarkerReachedEventArgs
{
    Windows::Media::Playback::PlaybackMediaMarker PlaybackMediaMarker() const;
};

template <typename D>
struct WINRT_EBO impl_IPlaybackMediaMarkerSequence
{
    uint32_t Size() const;
    void Insert(const Windows::Media::Playback::PlaybackMediaMarker & value) const;
    void Clear() const;
};

template <typename D>
struct WINRT_EBO impl_ITimedMetadataPresentationModeChangedEventArgs
{
    Windows::Media::Core::TimedMetadataTrack Track() const;
    Windows::Media::Playback::TimedMetadataTrackPresentationMode OldPresentationMode() const;
    Windows::Media::Playback::TimedMetadataTrackPresentationMode NewPresentationMode() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Playback::IBackgroundMediaPlayerStatics>
{
    using abi = ABI::Windows::Media::Playback::IBackgroundMediaPlayerStatics;
    template <typename D> using consume = Windows::Media::Playback::impl_IBackgroundMediaPlayerStatics<D>;
};

template <> struct traits<Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_ICurrentMediaPlaybackItemChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaBreak>
{
    using abi = ABI::Windows::Media::Playback::IMediaBreak;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaBreak<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaBreakEndedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaBreakEndedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaBreakEndedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaBreakFactory>
{
    using abi = ABI::Windows::Media::Playback::IMediaBreakFactory;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaBreakFactory<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaBreakManager>
{
    using abi = ABI::Windows::Media::Playback::IMediaBreakManager;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaBreakManager<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaBreakSchedule>
{
    using abi = ABI::Windows::Media::Playback::IMediaBreakSchedule;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaBreakSchedule<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaBreakSeekedOverEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaBreakSeekedOverEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaBreakSeekedOverEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaBreakSkippedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaBreakSkippedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaBreakSkippedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaBreakStartedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaBreakStartedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaBreakStartedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaEnginePlaybackSource>
{
    using abi = ABI::Windows::Media::Playback::IMediaEnginePlaybackSource;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaEnginePlaybackSource<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaItemDisplayProperties>
{
    using abi = ABI::Windows::Media::Playback::IMediaItemDisplayProperties;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaItemDisplayProperties<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManager>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManager;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManager<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerCommandBehavior<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerFastForwardReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerNextReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerPauseReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerPlayReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerPositionReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerPreviousReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerRateReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerRewindReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackCommandManagerShuffleReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackItem>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackItem;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackItem<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackItem2>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackItem2;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackItem2<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackItemError>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackItemError;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackItemError<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackItemFactory>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackItemFactory;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackItemFactory<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackItemFactory2>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackItemFactory2;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackItemFactory2<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackItemFailedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackItemOpenedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackItemOpenedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackItemOpenedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackItemStatics>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackItemStatics;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackItemStatics<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackList>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackList;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackList<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackList2>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackList2;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackList2<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackSession>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackSession;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackSession<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackSource>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackSource;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackSource<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlaybackTimedMetadataTrackList<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayer>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayer;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayer<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayer2>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayer2;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayer2<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayer3>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayer3;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayer3<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayer4>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayer4;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayer4<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayerDataReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayerDataReceivedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayerDataReceivedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayerEffects>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayerEffects;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayerEffects<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayerEffects2>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayerEffects2;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayerEffects2<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayerFailedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayerFailedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayerFailedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayerRateChangedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayerRateChangedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayerRateChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayerSource>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayerSource;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayerSource<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayerSource2>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayerSource2;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayerSource2<D>;
};

template <> struct traits<Windows::Media::Playback::IMediaPlayerSurface>
{
    using abi = ABI::Windows::Media::Playback::IMediaPlayerSurface;
    template <typename D> using consume = Windows::Media::Playback::impl_IMediaPlayerSurface<D>;
};

template <> struct traits<Windows::Media::Playback::IPlaybackMediaMarker>
{
    using abi = ABI::Windows::Media::Playback::IPlaybackMediaMarker;
    template <typename D> using consume = Windows::Media::Playback::impl_IPlaybackMediaMarker<D>;
};

template <> struct traits<Windows::Media::Playback::IPlaybackMediaMarkerFactory>
{
    using abi = ABI::Windows::Media::Playback::IPlaybackMediaMarkerFactory;
    template <typename D> using consume = Windows::Media::Playback::impl_IPlaybackMediaMarkerFactory<D>;
};

template <> struct traits<Windows::Media::Playback::IPlaybackMediaMarkerReachedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::IPlaybackMediaMarkerReachedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_IPlaybackMediaMarkerReachedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::IPlaybackMediaMarkerSequence>
{
    using abi = ABI::Windows::Media::Playback::IPlaybackMediaMarkerSequence;
    template <typename D> using consume = Windows::Media::Playback::impl_IPlaybackMediaMarkerSequence<D>;
};

template <> struct traits<Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs;
    template <typename D> using consume = Windows::Media::Playback::impl_ITimedMetadataPresentationModeChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::Playback::BackgroundMediaPlayer>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.BackgroundMediaPlayer"; }
};

template <> struct traits<Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.CurrentMediaPlaybackItemChangedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaBreak>
{
    using abi = ABI::Windows::Media::Playback::MediaBreak;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaBreak"; }
};

template <> struct traits<Windows::Media::Playback::MediaBreakEndedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaBreakEndedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaBreakEndedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaBreakManager>
{
    using abi = ABI::Windows::Media::Playback::MediaBreakManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaBreakManager"; }
};

template <> struct traits<Windows::Media::Playback::MediaBreakSchedule>
{
    using abi = ABI::Windows::Media::Playback::MediaBreakSchedule;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaBreakSchedule"; }
};

template <> struct traits<Windows::Media::Playback::MediaBreakSeekedOverEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaBreakSeekedOverEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaBreakSeekedOverEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaBreakSkippedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaBreakSkippedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaBreakSkippedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaBreakStartedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaBreakStartedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaBreakStartedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaItemDisplayProperties>
{
    using abi = ABI::Windows::Media::Playback::MediaItemDisplayProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaItemDisplayProperties"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackAudioTrackList>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackAudioTrackList;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackAudioTrackList"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManager>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManager"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerCommandBehavior"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerFastForwardReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerNextReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerPauseReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerPlayReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerPositionReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerPreviousReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerRateReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerRewindReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackCommandManagerShuffleReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackItem>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackItem"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackItemError>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackItemError;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackItemError"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackItemFailedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackItemFailedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackItemFailedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackItemOpenedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackList>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackList;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackList"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackSession>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackSession"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackTimedMetadataTrackList"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlaybackVideoTrackList>
{
    using abi = ABI::Windows::Media::Playback::MediaPlaybackVideoTrackList;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlaybackVideoTrackList"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlayer>
{
    using abi = ABI::Windows::Media::Playback::MediaPlayer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlayer"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlayerDataReceivedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlayerDataReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlayerDataReceivedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlayerFailedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlayerFailedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlayerFailedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlayerRateChangedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::MediaPlayerRateChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlayerRateChangedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::MediaPlayerSurface>
{
    using abi = ABI::Windows::Media::Playback::MediaPlayerSurface;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.MediaPlayerSurface"; }
};

template <> struct traits<Windows::Media::Playback::PlaybackMediaMarker>
{
    using abi = ABI::Windows::Media::Playback::PlaybackMediaMarker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.PlaybackMediaMarker"; }
};

template <> struct traits<Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.PlaybackMediaMarkerReachedEventArgs"; }
};

template <> struct traits<Windows::Media::Playback::PlaybackMediaMarkerSequence>
{
    using abi = ABI::Windows::Media::Playback::PlaybackMediaMarkerSequence;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.PlaybackMediaMarkerSequence"; }
};

template <> struct traits<Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs>
{
    using abi = ABI::Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Playback.TimedMetadataPresentationModeChangedEventArgs"; }
};

}

}
