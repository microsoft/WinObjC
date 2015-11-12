//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsMediaPlayback.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMPPlaybackMediaMarker, WMPPlaybackMediaMarkerSequence, WMPMediaPlayerFailedEventArgs, WMPMediaPlayerRateChangedEventArgs,
    WMPPlaybackMediaMarkerReachedEventArgs, WMPMediaPlayerDataReceivedEventArgs, WMPMediaPlayer, WMPBackgroundMediaPlayer,
    WMPMediaPlaybackItem, WMPMediaPlaybackAudioTrackList, WMPMediaPlaybackVideoTrackList, WMPMediaPlaybackTimedMetadataTrackList,
    WMPMediaPlaybackItemError, WMPMediaPlaybackList, WMPMediaPlaybackItemFailedEventArgs, WMPCurrentMediaPlaybackItemChangedEventArgs,
    WMPMediaPlaybackItemOpenedEventArgs, WMPTimedMetadataPresentationModeChangedEventArgs;
@protocol WMPIPlaybackMediaMarker
, WMPIPlaybackMediaMarkerFactory, WMPIPlaybackMediaMarkerSequence, WMPIMediaPlayerFailedEventArgs, WMPIMediaPlayerRateChangedEventArgs,
    WMPIPlaybackMediaMarkerReachedEventArgs, WMPIMediaPlayerDataReceivedEventArgs, WMPIMediaPlayer, WMPIMediaPlayer2, WMPIMediaPlayerSource,
    WMPIMediaPlayerSource2, WMPIBackgroundMediaPlayerStatics, WMPIMediaPlaybackSource, WMPIMediaPlaybackItemFactory, WMPIMediaPlaybackItem,
    WMPIMediaPlaybackItemError, WMPIMediaEnginePlaybackSource, WMPIMediaPlaybackItemOpenedEventArgs, WMPIMediaPlaybackItemFailedEventArgs,
    WMPICurrentMediaPlaybackItemChangedEventArgs, WMPIMediaPlaybackList, WMPIMediaPlaybackTimedMetadataTrackList,
    WMPITimedMetadataPresentationModeChangedEventArgs;

// Windows.Media.Playback.MediaPlayerState
enum _WMPMediaPlayerState {
    WMPMediaPlayerStateClosed = 0,
    WMPMediaPlayerStateOpening = 1,
    WMPMediaPlayerStateBuffering = 2,
    WMPMediaPlayerStatePlaying = 3,
    WMPMediaPlayerStatePaused = 4,
    WMPMediaPlayerStateStopped = 5,
};
typedef unsigned WMPMediaPlayerState;

// Windows.Media.Playback.MediaPlayerError
enum _WMPMediaPlayerError {
    WMPMediaPlayerErrorUnknown = 0,
    WMPMediaPlayerErrorAborted = 1,
    WMPMediaPlayerErrorNetworkError = 2,
    WMPMediaPlayerErrorDecodingError = 3,
    WMPMediaPlayerErrorSourceNotSupported = 4,
};
typedef unsigned WMPMediaPlayerError;

// Windows.Media.Playback.MediaPlayerAudioCategory
enum _WMPMediaPlayerAudioCategory {
    WMPMediaPlayerAudioCategoryOther = 0,
    WMPMediaPlayerAudioCategoryCommunications = 3,
    WMPMediaPlayerAudioCategoryAlerts = 4,
    WMPMediaPlayerAudioCategorySoundEffects = 5,
    WMPMediaPlayerAudioCategoryGameEffects = 6,
    WMPMediaPlayerAudioCategoryGameMedia = 7,
    WMPMediaPlayerAudioCategoryGameChat = 8,
    WMPMediaPlayerAudioCategorySpeech = 9,
    WMPMediaPlayerAudioCategoryMovie = 10,
    WMPMediaPlayerAudioCategoryMedia = 11,
};
typedef unsigned WMPMediaPlayerAudioCategory;

// Windows.Media.Playback.MediaPlayerAudioDeviceType
enum _WMPMediaPlayerAudioDeviceType {
    WMPMediaPlayerAudioDeviceTypeConsole = 0,
    WMPMediaPlayerAudioDeviceTypeMultimedia = 1,
    WMPMediaPlayerAudioDeviceTypeCommunications = 2,
};
typedef unsigned WMPMediaPlayerAudioDeviceType;

// Windows.Media.Playback.MediaPlaybackItemErrorCode
enum _WMPMediaPlaybackItemErrorCode {
    WMPMediaPlaybackItemErrorCodeNone = 0,
    WMPMediaPlaybackItemErrorCodeAborted = 1,
    WMPMediaPlaybackItemErrorCodeNetworkError = 2,
    WMPMediaPlaybackItemErrorCodeDecodeError = 3,
    WMPMediaPlaybackItemErrorCodeSourceNotSupportedError = 4,
    WMPMediaPlaybackItemErrorCodeEncryptionError = 5,
};
typedef unsigned WMPMediaPlaybackItemErrorCode;

// Windows.Media.Playback.FailedMediaStreamKind
enum _WMPFailedMediaStreamKind {
    WMPFailedMediaStreamKindUnknown = 0,
    WMPFailedMediaStreamKindAudio = 1,
    WMPFailedMediaStreamKindVideo = 2,
};
typedef unsigned WMPFailedMediaStreamKind;

// Windows.Media.Playback.TimedMetadataTrackPresentationMode
enum _WMPTimedMetadataTrackPresentationMode {
    WMPTimedMetadataTrackPresentationModeDisabled = 0,
    WMPTimedMetadataTrackPresentationModeHidden = 1,
    WMPTimedMetadataTrackPresentationModeApplicationPresented = 2,
    WMPTimedMetadataTrackPresentationModePlatformPresented = 3,
};
typedef unsigned WMPTimedMetadataTrackPresentationMode;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsMedia.h"
#include "WindowsMediaCore.h"
#include "WindowsStorage.h"
#include "WindowsMediaProtection.h"

#import <Foundation/Foundation.h>

// Windows.Media.Playback.IMediaPlaybackSource
#ifndef __WMPIMediaPlaybackSource_DEFINED__
#define __WMPIMediaPlaybackSource_DEFINED__

@protocol WMPIMediaPlaybackSource
@end

#endif // __WMPIMediaPlaybackSource_DEFINED__

// Windows.Media.Playback.IMediaEnginePlaybackSource
#ifndef __WMPIMediaEnginePlaybackSource_DEFINED__
#define __WMPIMediaEnginePlaybackSource_DEFINED__

@protocol WMPIMediaEnginePlaybackSource
@property (readonly) WMPMediaPlaybackItem* currentItem;
- (void)setPlaybackSource:(RTObject<WMPIMediaPlaybackSource>*)source;
@end

#endif // __WMPIMediaEnginePlaybackSource_DEFINED__

// Windows.Media.Playback.PlaybackMediaMarker
#ifndef __WMPPlaybackMediaMarker_DEFINED__
#define __WMPPlaybackMediaMarker_DEFINED__

WINRT_EXPORT
@interface WMPPlaybackMediaMarker : RTObject
+ (WMPPlaybackMediaMarker*)createFromTime:(WFTimeSpan*)value ACTIVATOR;
+ (WMPPlaybackMediaMarker*)create:(WFTimeSpan*)value mediaMarketType:(NSString*)mediaMarketType text:(NSString*)text ACTIVATOR;
@property (readonly) NSString* mediaMarkerType;
@property (readonly) NSString* text;
@property (readonly) WFTimeSpan* time;
@end

#endif // __WMPPlaybackMediaMarker_DEFINED__

// Windows.Media.Playback.PlaybackMediaMarkerSequence
#ifndef __WMPPlaybackMediaMarkerSequence_DEFINED__
#define __WMPPlaybackMediaMarkerSequence_DEFINED__

WINRT_EXPORT
@interface WMPPlaybackMediaMarkerSequence : RTObject
@property (readonly) unsigned int size;
- (void)insert:(WMPPlaybackMediaMarker*)value;
- (void)clear;
@end

#endif // __WMPPlaybackMediaMarkerSequence_DEFINED__

// Windows.Media.Playback.MediaPlayerFailedEventArgs
#ifndef __WMPMediaPlayerFailedEventArgs_DEFINED__
#define __WMPMediaPlayerFailedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlayerFailedEventArgs : RTObject
@property (readonly) WMPMediaPlayerError error;
@property (readonly) NSString* errorMessage;
@property (readonly) HRESULT extendedErrorCode;
@end

#endif // __WMPMediaPlayerFailedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlayerRateChangedEventArgs
#ifndef __WMPMediaPlayerRateChangedEventArgs_DEFINED__
#define __WMPMediaPlayerRateChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlayerRateChangedEventArgs : RTObject
@property (readonly) double newRate;
@end

#endif // __WMPMediaPlayerRateChangedEventArgs_DEFINED__

// Windows.Media.Playback.PlaybackMediaMarkerReachedEventArgs
#ifndef __WMPPlaybackMediaMarkerReachedEventArgs_DEFINED__
#define __WMPPlaybackMediaMarkerReachedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPPlaybackMediaMarkerReachedEventArgs : RTObject
@property (readonly) WMPPlaybackMediaMarker* playbackMediaMarker;
@end

#endif // __WMPPlaybackMediaMarkerReachedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlayerDataReceivedEventArgs
#ifndef __WMPMediaPlayerDataReceivedEventArgs_DEFINED__
#define __WMPMediaPlayerDataReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlayerDataReceivedEventArgs : RTObject
@property (readonly) WFCValueSet* data;
@end

#endif // __WMPMediaPlayerDataReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlayer
#ifndef __WMPMediaPlayer_DEFINED__
#define __WMPMediaPlayer_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlayer : RTObject
@property double volume;
@property (copy) WFTimeSpan* position;
@property double playbackRate;
@property BOOL isLoopingEnabled;
@property BOOL isMuted;
@property BOOL autoPlay;
@property (readonly) WMPMediaPlayerState currentState;
@property (readonly) BOOL isProtected;
@property (readonly) WFTimeSpan* naturalDuration;
@property (readonly) BOOL canPause;
@property (readonly) WMPPlaybackMediaMarkerSequence* playbackMediaMarkers;
@property (readonly) double bufferingProgress;
@property (readonly) BOOL canSeek;
@property WMPMediaPlayerAudioDeviceType audioDeviceType;
@property WMPMediaPlayerAudioCategory audioCategory;
@property (readonly) WMSystemMediaTransportControls* systemMediaTransportControls;
@property (copy) WMPMediaProtectionManager* protectionManager;
@property (copy) RTObject<WMPIMediaPlaybackSource>* source;
- (EventRegistrationToken)addBufferingEndedEvent:(void (^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeBufferingEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBufferingStartedEvent:(void (^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeBufferingStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCurrentStateChangedEvent:(void (^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeCurrentStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaEndedEvent:(void (^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeMediaEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaFailedEvent:(void (^)(WMPMediaPlayer*, WMPMediaPlayerFailedEventArgs*))del;
- (void)removeMediaFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaOpenedEvent:(void (^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeMediaOpenedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaPlayerRateChangedEvent:(void (^)(WMPMediaPlayer*, WMPMediaPlayerRateChangedEventArgs*))del;
- (void)removeMediaPlayerRateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackMediaMarkerReachedEvent:(void (^)(WMPMediaPlayer*, WMPPlaybackMediaMarkerReachedEventArgs*))del;
- (void)removePlaybackMediaMarkerReachedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSeekCompletedEvent:(void (^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeSeekCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVolumeChangedEvent:(void (^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeVolumeChangedEvent:(EventRegistrationToken)tok;
- (void)play;
- (void)pause;
- (void)setUriSource:(WFUri*)value;
- (void)setFileSource:(RTObject<WSIStorageFile>*)file;
- (void)setStreamSource:(RTObject<WSSIRandomAccessStream>*)stream;
- (void)setMediaSource:(RTObject<WMCIMediaSource>*)source;
@end

#endif // __WMPMediaPlayer_DEFINED__

// Windows.Media.Playback.BackgroundMediaPlayer
#ifndef __WMPBackgroundMediaPlayer_DEFINED__
#define __WMPBackgroundMediaPlayer_DEFINED__

WINRT_EXPORT
@interface WMPBackgroundMediaPlayer : RTObject
+ (void)sendMessageToBackground:(WFCValueSet*)value;
+ (void)sendMessageToForeground:(WFCValueSet*)value;
+ (BOOL)isMediaPlaying;
+ (void)shutdown;
+ (WMPMediaPlayer*)current;
+ (EventRegistrationToken)addMessageReceivedFromBackgroundEvent:(void (^)(RTObject*, WMPMediaPlayerDataReceivedEventArgs*))del;
+ (void)removeMessageReceivedFromBackgroundEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addMessageReceivedFromForegroundEvent:(void (^)(RTObject*, WMPMediaPlayerDataReceivedEventArgs*))del;
+ (void)removeMessageReceivedFromForegroundEvent:(EventRegistrationToken)tok;
@end

#endif // __WMPBackgroundMediaPlayer_DEFINED__

// Windows.Media.Playback.MediaPlaybackItem
#ifndef __WMPMediaPlaybackItem_DEFINED__
#define __WMPMediaPlaybackItem_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlaybackItem : RTObject <WMPIMediaPlaybackSource>
+ (WMPMediaPlaybackItem*)create:(WMCMediaSource*)source ACTIVATOR;
@property (readonly) WMPMediaPlaybackAudioTrackList* audioTracks;
@property (readonly) WMCMediaSource* source;
@property (readonly) WMPMediaPlaybackTimedMetadataTrackList* timedMetadataTracks;
@property (readonly) WMPMediaPlaybackVideoTrackList* videoTracks;
- (EventRegistrationToken)addAudioTracksChangedEvent:(void (^)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*))del;
- (void)removeAudioTracksChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTimedMetadataTracksChangedEvent:(void (^)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*))del;
- (void)removeTimedMetadataTracksChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVideoTracksChangedEvent:(void (^)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*))del;
- (void)removeVideoTracksChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMPMediaPlaybackItem_DEFINED__

// Windows.Media.Core.ISingleSelectMediaTrackList
#ifndef __WMCISingleSelectMediaTrackList_DEFINED__
#define __WMCISingleSelectMediaTrackList_DEFINED__

@protocol WMCISingleSelectMediaTrackList
@property int selectedIndex;
- (EventRegistrationToken)addSelectedIndexChangedEvent:(void (^)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*))del;
- (void)removeSelectedIndexChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMCISingleSelectMediaTrackList_DEFINED__

// Windows.Media.Playback.MediaPlaybackAudioTrackList
#ifndef __WMPMediaPlaybackAudioTrackList_DEFINED__
#define __WMPMediaPlaybackAudioTrackList_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlaybackAudioTrackList : RTObject <WMCISingleSelectMediaTrackList>
@property (readonly) unsigned int size;
@property int selectedIndex;
- (EventRegistrationToken)addSelectedIndexChangedEvent:(void (^)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*))del;
- (void)removeSelectedIndexChangedEvent:(EventRegistrationToken)tok;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

@end

#endif // __WMPMediaPlaybackAudioTrackList_DEFINED__

// Windows.Media.Playback.MediaPlaybackVideoTrackList
#ifndef __WMPMediaPlaybackVideoTrackList_DEFINED__
#define __WMPMediaPlaybackVideoTrackList_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlaybackVideoTrackList : RTObject <WMCISingleSelectMediaTrackList>
@property (readonly) unsigned int size;
@property int selectedIndex;
- (EventRegistrationToken)addSelectedIndexChangedEvent:(void (^)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*))del;
- (void)removeSelectedIndexChangedEvent:(EventRegistrationToken)tok;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

@end

#endif // __WMPMediaPlaybackVideoTrackList_DEFINED__

// Windows.Media.Playback.MediaPlaybackTimedMetadataTrackList
#ifndef __WMPMediaPlaybackTimedMetadataTrackList_DEFINED__
#define __WMPMediaPlaybackTimedMetadataTrackList_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlaybackTimedMetadataTrackList : RTObject
@property (readonly) unsigned int size;
- (EventRegistrationToken)addPresentationModeChangedEvent:(void (^)(WMPMediaPlaybackTimedMetadataTrackList*,
                                                                    WMPTimedMetadataPresentationModeChangedEventArgs*))del;
- (void)removePresentationModeChangedEvent:(EventRegistrationToken)tok;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (WMPTimedMetadataTrackPresentationMode)getPresentationMode:(unsigned int)index;
- (void)setPresentationMode:(unsigned int)index value:(WMPTimedMetadataTrackPresentationMode)value;
@end

#endif // __WMPMediaPlaybackTimedMetadataTrackList_DEFINED__

// Windows.Media.Playback.MediaPlaybackItemError
#ifndef __WMPMediaPlaybackItemError_DEFINED__
#define __WMPMediaPlaybackItemError_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlaybackItemError : RTObject
@property (readonly) WMPMediaPlaybackItemErrorCode errorCode;
@property (readonly) HRESULT extendedError;
@end

#endif // __WMPMediaPlaybackItemError_DEFINED__

// Windows.Media.Playback.MediaPlaybackList
#ifndef __WMPMediaPlaybackList_DEFINED__
#define __WMPMediaPlaybackList_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlaybackList : RTObject <WMPIMediaPlaybackSource>
+ (instancetype)create ACTIVATOR;
@property BOOL shuffleEnabled;
@property BOOL autoRepeatEnabled;
@property (readonly) WMPMediaPlaybackItem* currentItem;
@property (readonly) unsigned int currentItemIndex;
@property (readonly) NSMutableArray<RTObservableCollection>* items;
- (EventRegistrationToken)addCurrentItemChangedEvent:(void (^)(WMPMediaPlaybackList*, WMPCurrentMediaPlaybackItemChangedEventArgs*))del;
- (void)removeCurrentItemChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addItemFailedEvent:(void (^)(WMPMediaPlaybackList*, WMPMediaPlaybackItemFailedEventArgs*))del;
- (void)removeItemFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addItemOpenedEvent:(void (^)(WMPMediaPlaybackList*, WMPMediaPlaybackItemOpenedEventArgs*))del;
- (void)removeItemOpenedEvent:(EventRegistrationToken)tok;
- (WMPMediaPlaybackItem*)moveNext;
- (WMPMediaPlaybackItem*)movePrevious;
- (WMPMediaPlaybackItem*)moveTo:(unsigned int)itemIndex;
@end

#endif // __WMPMediaPlaybackList_DEFINED__

// Windows.Media.Playback.MediaPlaybackItemFailedEventArgs
#ifndef __WMPMediaPlaybackItemFailedEventArgs_DEFINED__
#define __WMPMediaPlaybackItemFailedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlaybackItemFailedEventArgs : RTObject
@property (readonly) WMPMediaPlaybackItemError* error;
@property (readonly) WMPMediaPlaybackItem* item;
@end

#endif // __WMPMediaPlaybackItemFailedEventArgs_DEFINED__

// Windows.Media.Playback.CurrentMediaPlaybackItemChangedEventArgs
#ifndef __WMPCurrentMediaPlaybackItemChangedEventArgs_DEFINED__
#define __WMPCurrentMediaPlaybackItemChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPCurrentMediaPlaybackItemChangedEventArgs : RTObject
@property (readonly) WMPMediaPlaybackItem* newItem;
@property (readonly) WMPMediaPlaybackItem* oldItem;
@end

#endif // __WMPCurrentMediaPlaybackItemChangedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackItemOpenedEventArgs
#ifndef __WMPMediaPlaybackItemOpenedEventArgs_DEFINED__
#define __WMPMediaPlaybackItemOpenedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPMediaPlaybackItemOpenedEventArgs : RTObject
@property (readonly) WMPMediaPlaybackItem* item;
@end

#endif // __WMPMediaPlaybackItemOpenedEventArgs_DEFINED__

// Windows.Media.Playback.TimedMetadataPresentationModeChangedEventArgs
#ifndef __WMPTimedMetadataPresentationModeChangedEventArgs_DEFINED__
#define __WMPTimedMetadataPresentationModeChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPTimedMetadataPresentationModeChangedEventArgs : RTObject
@property (readonly) WMPTimedMetadataTrackPresentationMode newPresentationMode;
@property (readonly) WMPTimedMetadataTrackPresentationMode oldPresentationMode;
@property (readonly) WMCTimedMetadataTrack* track;
@end

#endif // __WMPTimedMetadataPresentationModeChangedEventArgs_DEFINED__
