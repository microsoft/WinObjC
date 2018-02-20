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

// WindowsMediaPlayback.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
#define OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaCaptureDevicesCoreMediaPropertiesDevicesCorePlaybackProtection.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMPPlaybackMediaMarker, WMPPlaybackMediaMarkerSequence, WMPMediaPlayerFailedEventArgs, WMPMediaPlayerRateChangedEventArgs, WMPPlaybackMediaMarkerReachedEventArgs, WMPMediaPlayerDataReceivedEventArgs, WMPMediaPlayer, WMPMediaBreakManager, WMPMediaPlaybackCommandManager, WMPMediaPlaybackSession, WMPMediaPlayerSurface, WMPMediaPlaybackSphericalVideoProjection, WMPMediaPlaybackSessionBufferingStartedEventArgs, WMPMediaBreakSeekedOverEventArgs, WMPMediaBreakStartedEventArgs, WMPMediaBreakEndedEventArgs, WMPMediaBreakSkippedEventArgs, WMPBackgroundMediaPlayer, WMPMediaPlaybackCommandManagerPlayReceivedEventArgs, WMPMediaPlaybackCommandManagerPauseReceivedEventArgs, WMPMediaPlaybackCommandManagerNextReceivedEventArgs, WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs, WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs, WMPMediaPlaybackCommandManagerRewindReceivedEventArgs, WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs, WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs, WMPMediaPlaybackCommandManagerPositionReceivedEventArgs, WMPMediaPlaybackCommandManagerRateReceivedEventArgs, WMPMediaPlaybackCommandManagerCommandBehavior, WMPMediaPlaybackItem, WMPMediaPlaybackAudioTrackList, WMPMediaPlaybackVideoTrackList, WMPMediaPlaybackTimedMetadataTrackList, WMPMediaBreakSchedule, WMPMediaItemDisplayProperties, WMPMediaBreak, WMPMediaPlaybackList, WMPMediaPlaybackItemError, WMPMediaPlaybackItemFailedEventArgs, WMPCurrentMediaPlaybackItemChangedEventArgs, WMPMediaPlaybackItemOpenedEventArgs, WMPTimedMetadataPresentationModeChangedEventArgs;
@protocol WMPIPlaybackMediaMarker, WMPIPlaybackMediaMarkerFactory, WMPIPlaybackMediaMarkerSequence, WMPIMediaPlayerFailedEventArgs, WMPIMediaPlayerRateChangedEventArgs, WMPIPlaybackMediaMarkerReachedEventArgs, WMPIMediaPlayerDataReceivedEventArgs, WMPIMediaPlayer, WMPIMediaPlayer2, WMPIMediaPlayer3, WMPIMediaPlayer4, WMPIMediaPlayer5, WMPIMediaPlayer6, WMPIMediaPlaybackSession, WMPIMediaPlaybackSphericalVideoProjection, WMPIMediaPlaybackSession2, WMPIMediaPlaybackSessionBufferingStartedEventArgs, WMPIMediaPlayerSource, WMPIMediaPlayerSource2, WMPIMediaPlayerEffects, WMPIMediaPlayerEffects2, WMPIMediaBreakStartedEventArgs, WMPIMediaBreakEndedEventArgs, WMPIMediaBreakSkippedEventArgs, WMPIMediaBreakSeekedOverEventArgs, WMPIMediaBreakManager, WMPIMediaPlayerSurface, WMPIBackgroundMediaPlayerStatics, WMPIMediaPlaybackCommandManagerPlayReceivedEventArgs, WMPIMediaPlaybackCommandManagerPauseReceivedEventArgs, WMPIMediaPlaybackCommandManagerNextReceivedEventArgs, WMPIMediaPlaybackCommandManagerPreviousReceivedEventArgs, WMPIMediaPlaybackCommandManagerFastForwardReceivedEventArgs, WMPIMediaPlaybackCommandManagerRewindReceivedEventArgs, WMPIMediaPlaybackCommandManagerShuffleReceivedEventArgs, WMPIMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs, WMPIMediaPlaybackCommandManagerPositionReceivedEventArgs, WMPIMediaPlaybackCommandManagerRateReceivedEventArgs, WMPIMediaPlaybackCommandManagerCommandBehavior, WMPIMediaPlaybackCommandManager, WMPIMediaPlaybackSource, WMPIMediaPlaybackItemFactory, WMPIMediaPlaybackItemFactory2, WMPIMediaPlaybackItemStatics, WMPIMediaPlaybackItem, WMPIMediaItemDisplayProperties, WMPIMediaPlaybackItem2, WMPIMediaPlaybackItem3, WMPIMediaBreakFactory, WMPIMediaBreak, WMPIMediaBreakSchedule, WMPIMediaPlaybackItemError, WMPIMediaEnginePlaybackSource, WMPIMediaPlaybackItemOpenedEventArgs, WMPIMediaPlaybackItemFailedEventArgs, WMPICurrentMediaPlaybackItemChangedEventArgs, WMPICurrentMediaPlaybackItemChangedEventArgs2, WMPIMediaPlaybackList, WMPIMediaPlaybackList2, WMPIMediaPlaybackList3, WMPIMediaPlaybackTimedMetadataTrackList, WMPITimedMetadataPresentationModeChangedEventArgs;

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

// Windows.Media.Playback.MediaPlaybackState
enum _WMPMediaPlaybackState {
    WMPMediaPlaybackStateNone = 0,
    WMPMediaPlaybackStateOpening = 1,
    WMPMediaPlaybackStateBuffering = 2,
    WMPMediaPlaybackStatePlaying = 3,
    WMPMediaPlaybackStatePaused = 4,
};
typedef unsigned WMPMediaPlaybackState;

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

// Windows.Media.Playback.StereoscopicVideoRenderMode
enum _WMPStereoscopicVideoRenderMode {
    WMPStereoscopicVideoRenderModeMono = 0,
    WMPStereoscopicVideoRenderModeStereo = 1,
};
typedef unsigned WMPStereoscopicVideoRenderMode;

// Windows.Media.Playback.SphericalVideoProjectionMode
enum _WMPSphericalVideoProjectionMode {
    WMPSphericalVideoProjectionModeSpherical = 0,
    WMPSphericalVideoProjectionModeFlat = 1,
};
typedef unsigned WMPSphericalVideoProjectionMode;

// Windows.Media.Playback.MediaCommandEnablingRule
enum _WMPMediaCommandEnablingRule {
    WMPMediaCommandEnablingRuleAuto = 0,
    WMPMediaCommandEnablingRuleAlways = 1,
    WMPMediaCommandEnablingRuleNever = 2,
};
typedef unsigned WMPMediaCommandEnablingRule;

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

// Windows.Media.Playback.MediaBreakInsertionMethod
enum _WMPMediaBreakInsertionMethod {
    WMPMediaBreakInsertionMethodInterrupt = 0,
    WMPMediaBreakInsertionMethodReplace = 1,
};
typedef unsigned WMPMediaBreakInsertionMethod;

// Windows.Media.Playback.MediaPlaybackItemChangedReason
enum _WMPMediaPlaybackItemChangedReason {
    WMPMediaPlaybackItemChangedReasonInitialItem = 0,
    WMPMediaPlaybackItemChangedReasonEndOfStream = 1,
    WMPMediaPlaybackItemChangedReasonError = 2,
    WMPMediaPlaybackItemChangedReasonAppRequested = 3,
};
typedef unsigned WMPMediaPlaybackItemChangedReason;

// Windows.Media.Playback.AutoLoadedDisplayPropertyKind
enum _WMPAutoLoadedDisplayPropertyKind {
    WMPAutoLoadedDisplayPropertyKindNone = 0,
    WMPAutoLoadedDisplayPropertyKindMusicOrVideo = 1,
    WMPAutoLoadedDisplayPropertyKindMusic = 2,
    WMPAutoLoadedDisplayPropertyKindVideo = 3,
};
typedef unsigned WMPAutoLoadedDisplayPropertyKind;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsMedia.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsMediaCasting.h"
#include "WindowsGraphicsDirectXDirect3D11.h"
#include "WindowsUIComposition.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsMediaProtection.h"
#include "WindowsStorage.h"
#include "WindowsStorageStreams.h"
#include "WindowsMediaCore.h"

#import <Foundation/Foundation.h>

// Windows.Media.Playback.IMediaPlaybackSource
#ifndef __WMPIMediaPlaybackSource_DEFINED__
#define __WMPIMediaPlaybackSource_DEFINED__

@protocol WMPIMediaPlaybackSource
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPIMediaPlaybackSource : RTObject <WMPIMediaPlaybackSource>
@end

#endif // __WMPIMediaPlaybackSource_DEFINED__

// Windows.Media.Playback.IMediaEnginePlaybackSource
#ifndef __WMPIMediaEnginePlaybackSource_DEFINED__
#define __WMPIMediaEnginePlaybackSource_DEFINED__

@protocol WMPIMediaEnginePlaybackSource
@property (readonly) WMPMediaPlaybackItem* currentItem;
- (void)setPlaybackSource:(RTObject<WMPIMediaPlaybackSource>*)source;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPIMediaEnginePlaybackSource : RTObject <WMPIMediaEnginePlaybackSource>
@end

#endif // __WMPIMediaEnginePlaybackSource_DEFINED__

// Windows.Media.Playback.PlaybackMediaMarker
#ifndef __WMPPlaybackMediaMarker_DEFINED__
#define __WMPPlaybackMediaMarker_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPPlaybackMediaMarker : RTObject
+ (WMPPlaybackMediaMarker*)makeFromTime:(WFTimeSpan*)value ACTIVATOR;
+ (WMPPlaybackMediaMarker*)make:(WFTimeSpan*)value mediaMarketType:(NSString *)mediaMarketType text:(NSString *)text ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * mediaMarkerType;
@property (readonly) NSString * text;
@property (readonly) WFTimeSpan* time;
@end

#endif // __WMPPlaybackMediaMarker_DEFINED__

// Windows.Media.Playback.PlaybackMediaMarkerSequence
#ifndef __WMPPlaybackMediaMarkerSequence_DEFINED__
#define __WMPPlaybackMediaMarkerSequence_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPPlaybackMediaMarkerSequence : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (void)insert:(WMPPlaybackMediaMarker*)value;
- (void)clear;
@end

#endif // __WMPPlaybackMediaMarkerSequence_DEFINED__

// Windows.Media.Playback.MediaPlayerFailedEventArgs
#ifndef __WMPMediaPlayerFailedEventArgs_DEFINED__
#define __WMPMediaPlayerFailedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlayerFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaPlayerError error;
@property (readonly) NSString * errorMessage;
@property (readonly) HRESULT extendedErrorCode;
@end

#endif // __WMPMediaPlayerFailedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlayerRateChangedEventArgs
#ifndef __WMPMediaPlayerRateChangedEventArgs_DEFINED__
#define __WMPMediaPlayerRateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlayerRateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double newRate;
@end

#endif // __WMPMediaPlayerRateChangedEventArgs_DEFINED__

// Windows.Media.Playback.PlaybackMediaMarkerReachedEventArgs
#ifndef __WMPPlaybackMediaMarkerReachedEventArgs_DEFINED__
#define __WMPPlaybackMediaMarkerReachedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPPlaybackMediaMarkerReachedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPPlaybackMediaMarker* playbackMediaMarker;
@end

#endif // __WMPPlaybackMediaMarkerReachedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlayerDataReceivedEventArgs
#ifndef __WMPMediaPlayerDataReceivedEventArgs_DEFINED__
#define __WMPMediaPlayerDataReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlayerDataReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFCValueSet* data;
@end

#endif // __WMPMediaPlayerDataReceivedEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.Playback.MediaPlayer
#ifndef __WMPMediaPlayer_DEFINED__
#define __WMPMediaPlayer_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlayer : RTObject <WFIClosable>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double volume;
@property (retain) WFTimeSpan* position;
@property double playbackRate;
@property BOOL autoPlay;
@property BOOL isLoopingEnabled;
@property BOOL isMuted;
@property (readonly) BOOL canSeek;
@property (readonly) WFTimeSpan* naturalDuration;
@property (readonly) WMPPlaybackMediaMarkerSequence* playbackMediaMarkers;
@property (readonly) double bufferingProgress;
@property (readonly) BOOL canPause;
@property (readonly) BOOL isProtected;
@property (readonly) WMPMediaPlayerState currentState;
@property WMPMediaPlayerAudioDeviceType audioDeviceType;
@property WMPMediaPlayerAudioCategory audioCategory;
@property (readonly) WMSystemMediaTransportControls* systemMediaTransportControls;
@property (retain) WFTimeSpan* timelineControllerPositionOffset;
@property (retain) WMMediaTimelineController* timelineController;
@property WMPStereoscopicVideoRenderMode stereoscopicVideoRenderMode;
@property BOOL realTimePlayback;
@property (retain) WDEDeviceInformation* audioDevice;
@property double audioBalance;
@property (readonly) WMPMediaPlaybackCommandManager* commandManager;
@property (readonly) WMPMediaPlaybackSession* playbackSession;
@property (readonly) WMPMediaBreakManager* breakManager;
@property BOOL isVideoFrameServerEnabled;
@property (retain) WMPMediaProtectionManager* protectionManager;
@property (retain) RTObject<WMPIMediaPlaybackSource>* source;
- (EventRegistrationToken)addBufferingEndedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeBufferingEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBufferingStartedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeBufferingStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCurrentStateChangedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeCurrentStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaEndedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeMediaEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaFailedEvent:(void(^)(WMPMediaPlayer*, WMPMediaPlayerFailedEventArgs*))del;
- (void)removeMediaFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaOpenedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeMediaOpenedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaPlayerRateChangedEvent:(void(^)(WMPMediaPlayer*, WMPMediaPlayerRateChangedEventArgs*))del;
- (void)removeMediaPlayerRateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackMediaMarkerReachedEvent:(void(^)(WMPMediaPlayer*, WMPPlaybackMediaMarkerReachedEventArgs*))del;
- (void)removePlaybackMediaMarkerReachedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSeekCompletedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeSeekCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVolumeChangedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeVolumeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addIsMutedChangedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeIsMutedChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceChangedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeSourceChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVideoFrameAvailableEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeVideoFrameAvailableEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSubtitleFrameChangedEvent:(void(^)(WMPMediaPlayer*, RTObject*))del;
- (void)removeSubtitleFrameChangedEvent:(EventRegistrationToken)tok;
- (void)play;
- (void)pause;
- (void)setUriSource:(WFUri*)value;
- (void)setFileSource:(RTObject<WSIStorageFile>*)file;
- (void)setStreamSource:(RTObject<WSSIRandomAccessStream>*)stream;
- (void)setMediaSource:(RTObject<WMCIMediaSource>*)source;
- (void)addAudioEffect:(NSString *)activatableClassId effectOptional:(BOOL)effectOptional configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)removeAllEffects;
- (void)close;
- (void)stepForwardOneFrame;
- (void)stepBackwardOneFrame;
- (WMCCastingSource*)getAsCastingSource;
- (void)setSurfaceSize:(WFSize*)size;
- (WMPMediaPlayerSurface*)getSurface:(WUCCompositor*)compositor;
- (void)addVideoEffect:(NSString *)activatableClassId effectOptional:(BOOL)effectOptional effectConfiguration:(RTObject<WFCIPropertySet>*)effectConfiguration;
- (void)copyFrameToVideoSurface:(RTObject<WGDDIDirect3DSurface>*)destination;
- (void)copyFrameToVideoSurfaceWithTargetRectangle:(RTObject<WGDDIDirect3DSurface>*)destination targetRectangle:(WFRect*)targetRectangle;
- (void)copyFrameToStereoscopicVideoSurfaces:(RTObject<WGDDIDirect3DSurface>*)destinationLeftEye destinationRightEye:(RTObject<WGDDIDirect3DSurface>*)destinationRightEye;
- (BOOL)renderSubtitlesToSurface:(RTObject<WGDDIDirect3DSurface>*)destination;
- (BOOL)renderSubtitlesToSurfaceWithTargetRectangle:(RTObject<WGDDIDirect3DSurface>*)destination targetRectangle:(WFRect*)targetRectangle;
@end

#endif // __WMPMediaPlayer_DEFINED__

// Windows.Media.Playback.MediaBreakManager
#ifndef __WMPMediaBreakManager_DEFINED__
#define __WMPMediaBreakManager_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaBreakManager : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaBreak* currentBreak;
@property (readonly) WMPMediaPlaybackSession* playbackSession;
- (EventRegistrationToken)addBreakEndedEvent:(void(^)(WMPMediaBreakManager*, WMPMediaBreakEndedEventArgs*))del;
- (void)removeBreakEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBreakSkippedEvent:(void(^)(WMPMediaBreakManager*, WMPMediaBreakSkippedEventArgs*))del;
- (void)removeBreakSkippedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBreakStartedEvent:(void(^)(WMPMediaBreakManager*, WMPMediaBreakStartedEventArgs*))del;
- (void)removeBreakStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBreaksSeekedOverEvent:(void(^)(WMPMediaBreakManager*, WMPMediaBreakSeekedOverEventArgs*))del;
- (void)removeBreaksSeekedOverEvent:(EventRegistrationToken)tok;
- (void)playBreak:(WMPMediaBreak*)value;
- (void)skipCurrentBreak;
@end

#endif // __WMPMediaBreakManager_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManager
#ifndef __WMPMediaPlaybackCommandManager_DEFINED__
#define __WMPMediaPlaybackCommandManager_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManager : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isEnabled;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* autoRepeatModeBehavior;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* fastForwardBehavior;
@property (readonly) WMPMediaPlayer* mediaPlayer;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* nextBehavior;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* pauseBehavior;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* playBehavior;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* positionBehavior;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* previousBehavior;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* rateBehavior;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* rewindBehavior;
@property (readonly) WMPMediaPlaybackCommandManagerCommandBehavior* shuffleBehavior;
- (EventRegistrationToken)addAutoRepeatModeReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs*))del;
- (void)removeAutoRepeatModeReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFastForwardReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs*))del;
- (void)removeFastForwardReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNextReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerNextReceivedEventArgs*))del;
- (void)removeNextReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPauseReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPauseReceivedEventArgs*))del;
- (void)removePauseReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlayReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPlayReceivedEventArgs*))del;
- (void)removePlayReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPositionReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPositionReceivedEventArgs*))del;
- (void)removePositionReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPreviousReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs*))del;
- (void)removePreviousReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRateReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerRateReceivedEventArgs*))del;
- (void)removeRateReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRewindReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerRewindReceivedEventArgs*))del;
- (void)removeRewindReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addShuffleReceivedEvent:(void(^)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs*))del;
- (void)removeShuffleReceivedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMPMediaPlaybackCommandManager_DEFINED__

// Windows.Media.Playback.MediaPlaybackSession
#ifndef __WMPMediaPlaybackSession_DEFINED__
#define __WMPMediaPlaybackSession_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackSession : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMMStereoscopicVideoPackingMode stereoscopicVideoPackingMode;
@property (retain) WFTimeSpan* position;
@property (retain) WFRect* normalizedSourceRect;
@property double playbackRate;
@property (readonly) BOOL isProtected;
@property (readonly) WMPMediaPlayer* mediaPlayer;
@property (readonly) unsigned int naturalVideoHeight;
@property (readonly) WFTimeSpan* naturalDuration;
@property (readonly) double bufferingProgress;
@property (readonly) unsigned int naturalVideoWidth;
@property (readonly) BOOL canPause;
@property (readonly) WMPMediaPlaybackState playbackState;
@property (readonly) BOOL canSeek;
@property (readonly) double downloadProgress;
@property BOOL isMirroring;
@property (readonly) WMPMediaPlaybackSphericalVideoProjection* sphericalVideoProjection;
- (EventRegistrationToken)addBufferingEndedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeBufferingEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBufferingProgressChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeBufferingProgressChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBufferingStartedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeBufferingStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadProgressChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeDownloadProgressChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNaturalDurationChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeNaturalDurationChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNaturalVideoSizeChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeNaturalVideoSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackRateChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removePlaybackRateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackStateChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removePlaybackStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPositionChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removePositionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSeekCompletedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeSeekCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBufferedRangesChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeBufferedRangesChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlayedRangesChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removePlayedRangesChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSeekableRangesChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeSeekableRangesChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSupportedPlaybackRatesChangedEvent:(void(^)(WMPMediaPlaybackSession*, RTObject*))del;
- (void)removeSupportedPlaybackRatesChangedEvent:(EventRegistrationToken)tok;
- (NSArray* /* WMMediaTimeRange* */)getBufferedRanges;
- (NSArray* /* WMMediaTimeRange* */)getPlayedRanges;
- (NSArray* /* WMMediaTimeRange* */)getSeekableRanges;
- (BOOL)isSupportedPlaybackRateRange:(double)rate1 rate2:(double)rate2;
@end

#endif // __WMPMediaPlaybackSession_DEFINED__

// Windows.Media.Playback.MediaPlayerSurface
#ifndef __WMPMediaPlayerSurface_DEFINED__
#define __WMPMediaPlayerSurface_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlayerSurface : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WUCICompositionSurface>* compositionSurface;
@property (readonly) WUCCompositor* compositor;
@property (readonly) WMPMediaPlayer* mediaPlayer;
- (void)close;
@end

#endif // __WMPMediaPlayerSurface_DEFINED__

// Windows.Media.Playback.MediaPlaybackSphericalVideoProjection
#ifndef __WMPMediaPlaybackSphericalVideoProjection_DEFINED__
#define __WMPMediaPlaybackSphericalVideoProjection_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackSphericalVideoProjection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNQuaternion* viewOrientation;
@property WMPSphericalVideoProjectionMode projectionMode;
@property BOOL isEnabled;
@property double horizontalFieldOfViewInDegrees;
@property WMMSphericalVideoFrameFormat frameFormat;
@end

#endif // __WMPMediaPlaybackSphericalVideoProjection_DEFINED__

// Windows.Media.Playback.MediaPlaybackSessionBufferingStartedEventArgs
#ifndef __WMPMediaPlaybackSessionBufferingStartedEventArgs_DEFINED__
#define __WMPMediaPlaybackSessionBufferingStartedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackSessionBufferingStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isPlaybackInterruption;
@end

#endif // __WMPMediaPlaybackSessionBufferingStartedEventArgs_DEFINED__

// Windows.Media.Playback.MediaBreakSeekedOverEventArgs
#ifndef __WMPMediaBreakSeekedOverEventArgs_DEFINED__
#define __WMPMediaBreakSeekedOverEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaBreakSeekedOverEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* newPosition __attribute__ ((ns_returns_not_retained));
@property (readonly) WFTimeSpan* oldPosition;
@property (readonly) NSArray* /* WMPMediaBreak* */ seekedOverBreaks;
@end

#endif // __WMPMediaBreakSeekedOverEventArgs_DEFINED__

// Windows.Media.Playback.MediaBreakStartedEventArgs
#ifndef __WMPMediaBreakStartedEventArgs_DEFINED__
#define __WMPMediaBreakStartedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaBreakStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaBreak* mediaBreak;
@end

#endif // __WMPMediaBreakStartedEventArgs_DEFINED__

// Windows.Media.Playback.MediaBreakEndedEventArgs
#ifndef __WMPMediaBreakEndedEventArgs_DEFINED__
#define __WMPMediaBreakEndedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaBreakEndedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaBreak* mediaBreak;
@end

#endif // __WMPMediaBreakEndedEventArgs_DEFINED__

// Windows.Media.Playback.MediaBreakSkippedEventArgs
#ifndef __WMPMediaBreakSkippedEventArgs_DEFINED__
#define __WMPMediaBreakSkippedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaBreakSkippedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaBreak* mediaBreak;
@end

#endif // __WMPMediaBreakSkippedEventArgs_DEFINED__

// Windows.Media.Playback.BackgroundMediaPlayer
#ifndef __WMPBackgroundMediaPlayer_DEFINED__
#define __WMPBackgroundMediaPlayer_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPBackgroundMediaPlayer : RTObject
+ (void)sendMessageToBackground:(WFCValueSet*)value;
+ (void)sendMessageToForeground:(WFCValueSet*)value;
+ (BOOL)isMediaPlaying;
+ (void)shutdown;
+ (WMPMediaPlayer*)current;
+ (EventRegistrationToken)addMessageReceivedFromBackgroundEvent:(void(^)(RTObject*, WMPMediaPlayerDataReceivedEventArgs*))del;
+ (void)removeMessageReceivedFromBackgroundEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addMessageReceivedFromForegroundEvent:(void(^)(RTObject*, WMPMediaPlayerDataReceivedEventArgs*))del;
+ (void)removeMessageReceivedFromForegroundEvent:(EventRegistrationToken)tok;
@end

#endif // __WMPBackgroundMediaPlayer_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerPlayReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerPlayReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerPlayReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerPlayReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerPlayReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerPauseReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerPauseReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerPauseReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerPauseReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerPauseReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerNextReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerNextReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerNextReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerNextReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerNextReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerPreviousReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerFastForwardReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerRewindReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerRewindReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerRewindReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerRewindReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerRewindReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerShuffleReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) BOOL isShuffleRequested;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WMMediaPlaybackAutoRepeatMode autoRepeatMode;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerPositionReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerPositionReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerPositionReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerPositionReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WFTimeSpan* position;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerPositionReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerRateReceivedEventArgs
#ifndef __WMPMediaPlaybackCommandManagerRateReceivedEventArgs_DEFINED__
#define __WMPMediaPlaybackCommandManagerRateReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerRateReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) double playbackRate;
- (WFDeferral*)getDeferral;
@end

#endif // __WMPMediaPlaybackCommandManagerRateReceivedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackCommandManagerCommandBehavior
#ifndef __WMPMediaPlaybackCommandManagerCommandBehavior_DEFINED__
#define __WMPMediaPlaybackCommandManagerCommandBehavior_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackCommandManagerCommandBehavior : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMPMediaCommandEnablingRule enablingRule;
@property (readonly) WMPMediaPlaybackCommandManager* commandManager;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addIsEnabledChangedEvent:(void(^)(WMPMediaPlaybackCommandManagerCommandBehavior*, RTObject*))del;
- (void)removeIsEnabledChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMPMediaPlaybackCommandManagerCommandBehavior_DEFINED__

// Windows.Media.Playback.MediaPlaybackItem
#ifndef __WMPMediaPlaybackItem_DEFINED__
#define __WMPMediaPlaybackItem_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackItem : RTObject <WMPIMediaPlaybackSource>
+ (WMPMediaPlaybackItem*)findFromMediaSource:(WMCMediaSource*)source;
+ (WMPMediaPlaybackItem*)make:(WMCMediaSource*)source ACTIVATOR;
+ (WMPMediaPlaybackItem*)makeWithStartTime:(WMCMediaSource*)source startTime:(WFTimeSpan*)startTime ACTIVATOR;
+ (WMPMediaPlaybackItem*)makeWithStartTimeAndDurationLimit:(WMCMediaSource*)source startTime:(WFTimeSpan*)startTime durationLimit:(WFTimeSpan*)durationLimit ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaPlaybackAudioTrackList* audioTracks;
@property (readonly) WMCMediaSource* source;
@property (readonly) WMPMediaPlaybackTimedMetadataTrackList* timedMetadataTracks;
@property (readonly) WMPMediaPlaybackVideoTrackList* videoTracks;
@property BOOL canSkip;
@property (readonly) WMPMediaBreakSchedule* breakSchedule;
@property (readonly) id /* WFTimeSpan* */ durationLimit;
@property (readonly) WFTimeSpan* startTime;
@property BOOL isDisabledInPlaybackList;
@property WMPAutoLoadedDisplayPropertyKind autoLoadedDisplayProperties;
@property (readonly) double totalDownloadProgress;
- (EventRegistrationToken)addAudioTracksChangedEvent:(void(^)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*))del;
- (void)removeAudioTracksChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTimedMetadataTracksChangedEvent:(void(^)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*))del;
- (void)removeTimedMetadataTracksChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVideoTracksChangedEvent:(void(^)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*))del;
- (void)removeVideoTracksChangedEvent:(EventRegistrationToken)tok;
- (WMPMediaItemDisplayProperties*)getDisplayProperties;
- (void)applyDisplayProperties:(WMPMediaItemDisplayProperties*)value;
@end

#endif // __WMPMediaPlaybackItem_DEFINED__

// Windows.Media.Core.ISingleSelectMediaTrackList
#ifndef __WMCISingleSelectMediaTrackList_DEFINED__
#define __WMCISingleSelectMediaTrackList_DEFINED__

@protocol WMCISingleSelectMediaTrackList
@property int selectedIndex;
- (EventRegistrationToken)addSelectedIndexChangedEvent:(void(^)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*))del;
- (void)removeSelectedIndexChangedEvent:(EventRegistrationToken)tok;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCISingleSelectMediaTrackList : RTObject <WMCISingleSelectMediaTrackList>
@end

#endif // __WMCISingleSelectMediaTrackList_DEFINED__

// Windows.Media.Playback.MediaPlaybackAudioTrackList
#ifndef __WMPMediaPlaybackAudioTrackList_DEFINED__
#define __WMPMediaPlaybackAudioTrackList_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackAudioTrackList : RTObject <WMCISingleSelectMediaTrackList>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
@property int selectedIndex;
- (EventRegistrationToken)addSelectedIndexChangedEvent:(void(^)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*))del;
- (void)removeSelectedIndexChangedEvent:(EventRegistrationToken)tok;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

@end

#endif // __WMPMediaPlaybackAudioTrackList_DEFINED__

// Windows.Media.Playback.MediaPlaybackVideoTrackList
#ifndef __WMPMediaPlaybackVideoTrackList_DEFINED__
#define __WMPMediaPlaybackVideoTrackList_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackVideoTrackList : RTObject <WMCISingleSelectMediaTrackList>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
@property int selectedIndex;
- (EventRegistrationToken)addSelectedIndexChangedEvent:(void(^)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*))del;
- (void)removeSelectedIndexChangedEvent:(EventRegistrationToken)tok;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

@end

#endif // __WMPMediaPlaybackVideoTrackList_DEFINED__

// Windows.Media.Playback.MediaPlaybackTimedMetadataTrackList
#ifndef __WMPMediaPlaybackTimedMetadataTrackList_DEFINED__
#define __WMPMediaPlaybackTimedMetadataTrackList_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackTimedMetadataTrackList : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (EventRegistrationToken)addPresentationModeChangedEvent:(void(^)(WMPMediaPlaybackTimedMetadataTrackList*, WMPTimedMetadataPresentationModeChangedEventArgs*))del;
- (void)removePresentationModeChangedEvent:(EventRegistrationToken)tok;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (WMPTimedMetadataTrackPresentationMode)getPresentationMode:(unsigned int)index;
- (void)setPresentationMode:(unsigned int)index value:(WMPTimedMetadataTrackPresentationMode)value;
@end

#endif // __WMPMediaPlaybackTimedMetadataTrackList_DEFINED__

// Windows.Media.Playback.MediaBreakSchedule
#ifndef __WMPMediaBreakSchedule_DEFINED__
#define __WMPMediaBreakSchedule_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaBreakSchedule : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WMPMediaBreak* prerollBreak;
@property (retain) WMPMediaBreak* postrollBreak;
@property (readonly) NSArray* /* WMPMediaBreak* */ midrollBreaks;
@property (readonly) WMPMediaPlaybackItem* playbackItem;
- (EventRegistrationToken)addScheduleChangedEvent:(void(^)(WMPMediaBreakSchedule*, RTObject*))del;
- (void)removeScheduleChangedEvent:(EventRegistrationToken)tok;
- (void)insertMidrollBreak:(WMPMediaBreak*)mediaBreak;
- (void)removeMidrollBreak:(WMPMediaBreak*)mediaBreak;
@end

#endif // __WMPMediaBreakSchedule_DEFINED__

// Windows.Media.Playback.MediaItemDisplayProperties
#ifndef __WMPMediaItemDisplayProperties_DEFINED__
#define __WMPMediaItemDisplayProperties_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaItemDisplayProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMMediaPlaybackType type;
@property (retain) WSSRandomAccessStreamReference* thumbnail;
@property (readonly) WMMusicDisplayProperties* musicProperties;
@property (readonly) WMVideoDisplayProperties* videoProperties;
- (void)clearAll;
@end

#endif // __WMPMediaItemDisplayProperties_DEFINED__

// Windows.Media.Playback.MediaBreak
#ifndef __WMPMediaBreak_DEFINED__
#define __WMPMediaBreak_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaBreak : RTObject
+ (WMPMediaBreak*)make:(WMPMediaBreakInsertionMethod)insertionMethod ACTIVATOR;
+ (WMPMediaBreak*)makeWithPresentationPosition:(WMPMediaBreakInsertionMethod)insertionMethod presentationPosition:(WFTimeSpan*)presentationPosition ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL canStart;
@property (readonly) WFCValueSet* customProperties;
@property (readonly) WMPMediaBreakInsertionMethod insertionMethod;
@property (readonly) WMPMediaPlaybackList* playbackList;
@property (readonly) id /* WFTimeSpan* */ presentationPosition;
@end

#endif // __WMPMediaBreak_DEFINED__

// Windows.Media.Playback.MediaPlaybackList
#ifndef __WMPMediaPlaybackList_DEFINED__
#define __WMPMediaPlaybackList_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackList : RTObject <WMPIMediaPlaybackSource>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL shuffleEnabled;
@property BOOL autoRepeatEnabled;
@property (readonly) WMPMediaPlaybackItem* currentItem;
@property (readonly) unsigned int currentItemIndex;
@property (readonly) NSMutableArray<RTObservableCollection>* /* WMPMediaPlaybackItem* */ items;
@property (retain) WMPMediaPlaybackItem* startingItem;
@property (retain) id /* WFTimeSpan* */ maxPrefetchTime;
@property (readonly) NSArray* /* WMPMediaPlaybackItem* */ shuffledItems;
@property (retain) id /* unsigned int */ maxPlayedItemsToKeepOpen;
- (EventRegistrationToken)addCurrentItemChangedEvent:(void(^)(WMPMediaPlaybackList*, WMPCurrentMediaPlaybackItemChangedEventArgs*))del;
- (void)removeCurrentItemChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addItemFailedEvent:(void(^)(WMPMediaPlaybackList*, WMPMediaPlaybackItemFailedEventArgs*))del;
- (void)removeItemFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addItemOpenedEvent:(void(^)(WMPMediaPlaybackList*, WMPMediaPlaybackItemOpenedEventArgs*))del;
- (void)removeItemOpenedEvent:(EventRegistrationToken)tok;
- (WMPMediaPlaybackItem*)moveNext;
- (WMPMediaPlaybackItem*)movePrevious;
- (WMPMediaPlaybackItem*)moveTo:(unsigned int)itemIndex;
- (void)setShuffledItems:(id<NSFastEnumeration> /* WMPMediaPlaybackItem* */)value;
@end

#endif // __WMPMediaPlaybackList_DEFINED__

// Windows.Media.Playback.MediaPlaybackItemError
#ifndef __WMPMediaPlaybackItemError_DEFINED__
#define __WMPMediaPlaybackItemError_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackItemError : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaPlaybackItemErrorCode errorCode;
@property (readonly) HRESULT extendedError;
@end

#endif // __WMPMediaPlaybackItemError_DEFINED__

// Windows.Media.Playback.MediaPlaybackItemFailedEventArgs
#ifndef __WMPMediaPlaybackItemFailedEventArgs_DEFINED__
#define __WMPMediaPlaybackItemFailedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackItemFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaPlaybackItemError* error;
@property (readonly) WMPMediaPlaybackItem* item;
@end

#endif // __WMPMediaPlaybackItemFailedEventArgs_DEFINED__

// Windows.Media.Playback.CurrentMediaPlaybackItemChangedEventArgs
#ifndef __WMPCurrentMediaPlaybackItemChangedEventArgs_DEFINED__
#define __WMPCurrentMediaPlaybackItemChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPCurrentMediaPlaybackItemChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaPlaybackItem* newItem __attribute__ ((ns_returns_not_retained));
@property (readonly) WMPMediaPlaybackItem* oldItem;
@property (readonly) WMPMediaPlaybackItemChangedReason reason;
@end

#endif // __WMPCurrentMediaPlaybackItemChangedEventArgs_DEFINED__

// Windows.Media.Playback.MediaPlaybackItemOpenedEventArgs
#ifndef __WMPMediaPlaybackItemOpenedEventArgs_DEFINED__
#define __WMPMediaPlaybackItemOpenedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPMediaPlaybackItemOpenedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPMediaPlaybackItem* item;
@end

#endif // __WMPMediaPlaybackItemOpenedEventArgs_DEFINED__

// Windows.Media.Playback.TimedMetadataPresentationModeChangedEventArgs
#ifndef __WMPTimedMetadataPresentationModeChangedEventArgs_DEFINED__
#define __WMPTimedMetadataPresentationModeChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREMEDIAPROPERTIESDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPTimedMetadataPresentationModeChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMPTimedMetadataTrackPresentationMode newPresentationMode;
@property (readonly) WMPTimedMetadataTrackPresentationMode oldPresentationMode;
@property (readonly) WMCTimedMetadataTrack* track;
@end

#endif // __WMPTimedMetadataPresentationModeChangedEventArgs_DEFINED__

