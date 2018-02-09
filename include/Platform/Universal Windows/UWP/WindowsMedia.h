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

// WindowsMedia.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIAEXPORT
#define OBJCUWPWINDOWSMEDIAEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMedia.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMMediaProcessingTriggerDetails, WMVideoFrame, WMAudioBuffer, WMAudioFrame, WMMediaMarkerTypes, WMSystemMediaTransportControlsTimelineProperties, WMMusicDisplayProperties, WMVideoDisplayProperties, WMImageDisplayProperties, WMSystemMediaTransportControlsDisplayUpdater, WMSystemMediaTransportControlsButtonPressedEventArgs, WMSystemMediaTransportControlsPropertyChangedEventArgs, WMPlaybackPositionChangeRequestedEventArgs, WMPlaybackRateChangeRequestedEventArgs, WMShuffleEnabledChangeRequestedEventArgs, WMAutoRepeatModeChangeRequestedEventArgs, WMSystemMediaTransportControls, WMMediaTimelineController, WMMediaTimelineControllerFailedEventArgs, WMMediaExtensionManager, WMVideoEffects, WMMediaControl;
@class WMMediaTimeRange;
@protocol WMIMediaProcessingTriggerDetails, WMIMediaFrame, WMIVideoFrame, WMIVideoFrameFactory, WMIAudioFrame, WMIAudioFrameFactory, WMIAudioBuffer, WMIMediaMarker, WMIMediaMarkers, WMIMediaMarkerTypesStatics, WMISystemMediaTransportControlsTimelineProperties, WMIMusicDisplayProperties, WMIMusicDisplayProperties2, WMIMusicDisplayProperties3, WMIVideoDisplayProperties, WMIVideoDisplayProperties2, WMIImageDisplayProperties, WMISystemMediaTransportControlsDisplayUpdater, WMISystemMediaTransportControlsButtonPressedEventArgs, WMISystemMediaTransportControlsPropertyChangedEventArgs, WMIPlaybackPositionChangeRequestedEventArgs, WMIPlaybackRateChangeRequestedEventArgs, WMIShuffleEnabledChangeRequestedEventArgs, WMIAutoRepeatModeChangeRequestedEventArgs, WMISystemMediaTransportControls, WMISystemMediaTransportControls2, WMISystemMediaTransportControlsStatics, WMIMediaTimelineController, WMIMediaTimelineController2, WMIMediaTimelineControllerFailedEventArgs, WMIMediaExtension, WMIMediaExtensionManager, WMIMediaExtensionManager2, WMIVideoEffectsStatics, WMIMediaControl;

// Windows.Media.AudioBufferAccessMode
enum _WMAudioBufferAccessMode {
    WMAudioBufferAccessModeRead = 0,
    WMAudioBufferAccessModeReadWrite = 1,
    WMAudioBufferAccessModeWrite = 2,
};
typedef unsigned WMAudioBufferAccessMode;

// Windows.Media.SoundLevel
enum _WMSoundLevel {
    WMSoundLevelMuted = 0,
    WMSoundLevelLow = 1,
    WMSoundLevelFull = 2,
};
typedef unsigned WMSoundLevel;

// Windows.Media.MediaPlaybackType
enum _WMMediaPlaybackType {
    WMMediaPlaybackTypeUnknown = 0,
    WMMediaPlaybackTypeMusic = 1,
    WMMediaPlaybackTypeVideo = 2,
    WMMediaPlaybackTypeImage = 3,
};
typedef unsigned WMMediaPlaybackType;

// Windows.Media.MediaPlaybackAutoRepeatMode
enum _WMMediaPlaybackAutoRepeatMode {
    WMMediaPlaybackAutoRepeatModeNone = 0,
    WMMediaPlaybackAutoRepeatModeTrack = 1,
    WMMediaPlaybackAutoRepeatModeList = 2,
};
typedef unsigned WMMediaPlaybackAutoRepeatMode;

// Windows.Media.MediaPlaybackStatus
enum _WMMediaPlaybackStatus {
    WMMediaPlaybackStatusClosed = 0,
    WMMediaPlaybackStatusChanging = 1,
    WMMediaPlaybackStatusStopped = 2,
    WMMediaPlaybackStatusPlaying = 3,
    WMMediaPlaybackStatusPaused = 4,
};
typedef unsigned WMMediaPlaybackStatus;

// Windows.Media.SystemMediaTransportControlsButton
enum _WMSystemMediaTransportControlsButton {
    WMSystemMediaTransportControlsButtonPlay = 0,
    WMSystemMediaTransportControlsButtonPause = 1,
    WMSystemMediaTransportControlsButtonStop = 2,
    WMSystemMediaTransportControlsButtonRecord = 3,
    WMSystemMediaTransportControlsButtonFastForward = 4,
    WMSystemMediaTransportControlsButtonRewind = 5,
    WMSystemMediaTransportControlsButtonNext = 6,
    WMSystemMediaTransportControlsButtonPrevious = 7,
    WMSystemMediaTransportControlsButtonChannelUp = 8,
    WMSystemMediaTransportControlsButtonChannelDown = 9,
};
typedef unsigned WMSystemMediaTransportControlsButton;

// Windows.Media.SystemMediaTransportControlsProperty
enum _WMSystemMediaTransportControlsProperty {
    WMSystemMediaTransportControlsPropertySoundLevel = 0,
};
typedef unsigned WMSystemMediaTransportControlsProperty;

// Windows.Media.MediaTimelineControllerState
enum _WMMediaTimelineControllerState {
    WMMediaTimelineControllerStatePaused = 0,
    WMMediaTimelineControllerStateRunning = 1,
    WMMediaTimelineControllerStateStalled = 2,
    WMMediaTimelineControllerStateError = 3,
};
typedef unsigned WMMediaTimelineControllerState;

// Windows.Media.AudioProcessing
enum _WMAudioProcessing {
    WMAudioProcessingDefault = 0,
    WMAudioProcessingRaw = 1,
};
typedef unsigned WMAudioProcessing;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsStorage.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsGraphicsDirectXDirect3D11.h"
#include "WindowsApplicationModelAppService.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Media.MediaTimeRange
OBJCUWPWINDOWSMEDIAEXPORT
@interface WMMediaTimeRange : NSObject
+ (instancetype)new;
@property (retain) WFTimeSpan* start;
@property (retain) WFTimeSpan* end;
@end

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSMEDIAEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.IMediaFrame
#ifndef __WMIMediaFrame_DEFINED__
#define __WMIMediaFrame_DEFINED__

@protocol WMIMediaFrame <WFIClosable>
@property (retain) id /* WFTimeSpan* */ duration;
@property (readonly) RTObject<WFCIPropertySet>* extendedProperties;
@property BOOL isDiscontinuous;
@property (readonly) BOOL isReadOnly;
@property (retain) id /* WFTimeSpan* */ relativeTime;
@property (retain) id /* WFTimeSpan* */ systemRelativeTime;
@property (readonly) NSString * type;
- (void)close;
@end

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMIMediaFrame : RTObject <WMIMediaFrame>
@end

#endif // __WMIMediaFrame_DEFINED__

// Windows.Media.IMediaMarker
#ifndef __WMIMediaMarker_DEFINED__
#define __WMIMediaMarker_DEFINED__

@protocol WMIMediaMarker
@property (readonly) NSString * mediaMarkerType;
@property (readonly) NSString * text;
@property (readonly) WFTimeSpan* time;
@end

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMIMediaMarker : RTObject <WMIMediaMarker>
@end

#endif // __WMIMediaMarker_DEFINED__

// Windows.Media.IMediaMarkers
#ifndef __WMIMediaMarkers_DEFINED__
#define __WMIMediaMarkers_DEFINED__

@protocol WMIMediaMarkers
@property (readonly) NSArray* /* RTObject<WMIMediaMarker>* */ markers;
@end

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMIMediaMarkers : RTObject <WMIMediaMarkers>
@end

#endif // __WMIMediaMarkers_DEFINED__

// Windows.Media.IMediaExtension
#ifndef __WMIMediaExtension_DEFINED__
#define __WMIMediaExtension_DEFINED__

@protocol WMIMediaExtension
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMIMediaExtension : RTObject <WMIMediaExtension>
@end

#endif // __WMIMediaExtension_DEFINED__

// Windows.Media.MediaProcessingTriggerDetails
#ifndef __WMMediaProcessingTriggerDetails_DEFINED__
#define __WMMediaProcessingTriggerDetails_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMMediaProcessingTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFCValueSet* arguments;
@end

#endif // __WMMediaProcessingTriggerDetails_DEFINED__

// Windows.Media.VideoFrame
#ifndef __WMVideoFrame_DEFINED__
#define __WMVideoFrame_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMVideoFrame : RTObject <WMIMediaFrame, WFIClosable>
+ (WMVideoFrame*)make:(WGIBitmapPixelFormat)format width:(int)width height:(int)height ACTIVATOR;
+ (WMVideoFrame*)makeWithAlpha:(WGIBitmapPixelFormat)format width:(int)width height:(int)height alpha:(WGIBitmapAlphaMode)alpha ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WFTimeSpan* */ systemRelativeTime;
@property (retain) id /* WFTimeSpan* */ relativeTime;
@property BOOL isDiscontinuous;
@property (retain) id /* WFTimeSpan* */ duration;
@property (readonly) RTObject<WFCIPropertySet>* extendedProperties;
@property (readonly) BOOL isReadOnly;
@property (readonly) NSString * type;
@property (readonly) RTObject<WGDDIDirect3DSurface>* direct3DSurface;
@property (readonly) WGISoftwareBitmap* softwareBitmap;
- (RTObject<WFIAsyncAction>*)copyToAsync:(WMVideoFrame*)frame __attribute__ ((ns_returns_not_retained));
- (void)close;
@end

#endif // __WMVideoFrame_DEFINED__

// Windows.Foundation.IMemoryBuffer
#ifndef __WFIMemoryBuffer_DEFINED__
#define __WFIMemoryBuffer_DEFINED__

@protocol WFIMemoryBuffer <WFIClosable>
- (RTObject<WFIMemoryBufferReference>*)createReference;
- (void)close;
@end

OBJCUWPWINDOWSMEDIAEXPORT
@interface WFIMemoryBuffer : RTObject <WFIMemoryBuffer>
@end

#endif // __WFIMemoryBuffer_DEFINED__

// Windows.Media.AudioBuffer
#ifndef __WMAudioBuffer_DEFINED__
#define __WMAudioBuffer_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMAudioBuffer : RTObject <WFIMemoryBuffer, WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int length;
@property (readonly) unsigned int capacity;
- (RTObject<WFIMemoryBufferReference>*)createReference;
- (void)close;
@end

#endif // __WMAudioBuffer_DEFINED__

// Windows.Media.AudioFrame
#ifndef __WMAudioFrame_DEFINED__
#define __WMAudioFrame_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMAudioFrame : RTObject <WMIMediaFrame, WFIClosable>
+ (WMAudioFrame*)make:(unsigned int)capacity ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WFTimeSpan* */ systemRelativeTime;
@property (retain) id /* WFTimeSpan* */ relativeTime;
@property BOOL isDiscontinuous;
@property (retain) id /* WFTimeSpan* */ duration;
@property (readonly) RTObject<WFCIPropertySet>* extendedProperties;
@property (readonly) BOOL isReadOnly;
@property (readonly) NSString * type;
- (WMAudioBuffer*)lockBuffer:(WMAudioBufferAccessMode)mode;
- (void)close;
@end

#endif // __WMAudioFrame_DEFINED__

// Windows.Media.MediaMarkerTypes
#ifndef __WMMediaMarkerTypes_DEFINED__
#define __WMMediaMarkerTypes_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMMediaMarkerTypes : RTObject
+ (NSString *)bookmark;
@end

#endif // __WMMediaMarkerTypes_DEFINED__

// Windows.Media.SystemMediaTransportControlsTimelineProperties
#ifndef __WMSystemMediaTransportControlsTimelineProperties_DEFINED__
#define __WMSystemMediaTransportControlsTimelineProperties_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMSystemMediaTransportControlsTimelineProperties : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* startTime;
@property (retain) WFTimeSpan* position;
@property (retain) WFTimeSpan* minSeekTime;
@property (retain) WFTimeSpan* maxSeekTime;
@property (retain) WFTimeSpan* endTime;
@end

#endif // __WMSystemMediaTransportControlsTimelineProperties_DEFINED__

// Windows.Media.MusicDisplayProperties
#ifndef __WMMusicDisplayProperties_DEFINED__
#define __WMMusicDisplayProperties_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMMusicDisplayProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property (retain) NSString * artist;
@property (retain) NSString * albumArtist;
@property unsigned int trackNumber;
@property (retain) NSString * albumTitle;
@property (readonly) NSMutableArray* /* NSString * */ genres;
@property unsigned int albumTrackCount;
@end

#endif // __WMMusicDisplayProperties_DEFINED__

// Windows.Media.VideoDisplayProperties
#ifndef __WMVideoDisplayProperties_DEFINED__
#define __WMVideoDisplayProperties_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMVideoDisplayProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property (retain) NSString * subtitle;
@property (readonly) NSMutableArray* /* NSString * */ genres;
@end

#endif // __WMVideoDisplayProperties_DEFINED__

// Windows.Media.ImageDisplayProperties
#ifndef __WMImageDisplayProperties_DEFINED__
#define __WMImageDisplayProperties_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMImageDisplayProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property (retain) NSString * subtitle;
@end

#endif // __WMImageDisplayProperties_DEFINED__

// Windows.Media.SystemMediaTransportControlsDisplayUpdater
#ifndef __WMSystemMediaTransportControlsDisplayUpdater_DEFINED__
#define __WMSystemMediaTransportControlsDisplayUpdater_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMSystemMediaTransportControlsDisplayUpdater : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMMediaPlaybackType type;
@property (retain) WSSRandomAccessStreamReference* thumbnail;
@property (retain) NSString * appMediaId;
@property (readonly) WMImageDisplayProperties* imageProperties;
@property (readonly) WMMusicDisplayProperties* musicProperties;
@property (readonly) WMVideoDisplayProperties* videoProperties;
- (void)copyFromFileAsync:(WMMediaPlaybackType)type source:(WSStorageFile*)source success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)clearAll;
- (void)update;
@end

#endif // __WMSystemMediaTransportControlsDisplayUpdater_DEFINED__

// Windows.Media.SystemMediaTransportControlsButtonPressedEventArgs
#ifndef __WMSystemMediaTransportControlsButtonPressedEventArgs_DEFINED__
#define __WMSystemMediaTransportControlsButtonPressedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMSystemMediaTransportControlsButtonPressedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMSystemMediaTransportControlsButton button;
@end

#endif // __WMSystemMediaTransportControlsButtonPressedEventArgs_DEFINED__

// Windows.Media.SystemMediaTransportControlsPropertyChangedEventArgs
#ifndef __WMSystemMediaTransportControlsPropertyChangedEventArgs_DEFINED__
#define __WMSystemMediaTransportControlsPropertyChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMSystemMediaTransportControlsPropertyChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMSystemMediaTransportControlsProperty property;
@end

#endif // __WMSystemMediaTransportControlsPropertyChangedEventArgs_DEFINED__

// Windows.Media.PlaybackPositionChangeRequestedEventArgs
#ifndef __WMPlaybackPositionChangeRequestedEventArgs_DEFINED__
#define __WMPlaybackPositionChangeRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMPlaybackPositionChangeRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* requestedPlaybackPosition;
@end

#endif // __WMPlaybackPositionChangeRequestedEventArgs_DEFINED__

// Windows.Media.PlaybackRateChangeRequestedEventArgs
#ifndef __WMPlaybackRateChangeRequestedEventArgs_DEFINED__
#define __WMPlaybackRateChangeRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMPlaybackRateChangeRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double requestedPlaybackRate;
@end

#endif // __WMPlaybackRateChangeRequestedEventArgs_DEFINED__

// Windows.Media.ShuffleEnabledChangeRequestedEventArgs
#ifndef __WMShuffleEnabledChangeRequestedEventArgs_DEFINED__
#define __WMShuffleEnabledChangeRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMShuffleEnabledChangeRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL requestedShuffleEnabled;
@end

#endif // __WMShuffleEnabledChangeRequestedEventArgs_DEFINED__

// Windows.Media.AutoRepeatModeChangeRequestedEventArgs
#ifndef __WMAutoRepeatModeChangeRequestedEventArgs_DEFINED__
#define __WMAutoRepeatModeChangeRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMAutoRepeatModeChangeRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMMediaPlaybackAutoRepeatMode requestedAutoRepeatMode;
@end

#endif // __WMAutoRepeatModeChangeRequestedEventArgs_DEFINED__

// Windows.Media.SystemMediaTransportControls
#ifndef __WMSystemMediaTransportControls_DEFINED__
#define __WMSystemMediaTransportControls_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMSystemMediaTransportControls : RTObject
+ (WMSystemMediaTransportControls*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isPlayEnabled;
@property BOOL isPauseEnabled;
@property BOOL isNextEnabled;
@property BOOL isPreviousEnabled;
@property BOOL isEnabled;
@property BOOL isChannelDownEnabled;
@property BOOL isFastForwardEnabled;
@property BOOL isChannelUpEnabled;
@property WMMediaPlaybackStatus playbackStatus;
@property BOOL isStopEnabled;
@property BOOL isRewindEnabled;
@property BOOL isRecordEnabled;
@property (readonly) WMSystemMediaTransportControlsDisplayUpdater* displayUpdater;
@property (readonly) WMSoundLevel soundLevel;
@property BOOL shuffleEnabled;
@property double playbackRate;
@property WMMediaPlaybackAutoRepeatMode autoRepeatMode;
- (EventRegistrationToken)addButtonPressedEvent:(void(^)(WMSystemMediaTransportControls*, WMSystemMediaTransportControlsButtonPressedEventArgs*))del;
- (void)removeButtonPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPropertyChangedEvent:(void(^)(WMSystemMediaTransportControls*, WMSystemMediaTransportControlsPropertyChangedEventArgs*))del;
- (void)removePropertyChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAutoRepeatModeChangeRequestedEvent:(void(^)(WMSystemMediaTransportControls*, WMAutoRepeatModeChangeRequestedEventArgs*))del;
- (void)removeAutoRepeatModeChangeRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackPositionChangeRequestedEvent:(void(^)(WMSystemMediaTransportControls*, WMPlaybackPositionChangeRequestedEventArgs*))del;
- (void)removePlaybackPositionChangeRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackRateChangeRequestedEvent:(void(^)(WMSystemMediaTransportControls*, WMPlaybackRateChangeRequestedEventArgs*))del;
- (void)removePlaybackRateChangeRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addShuffleEnabledChangeRequestedEvent:(void(^)(WMSystemMediaTransportControls*, WMShuffleEnabledChangeRequestedEventArgs*))del;
- (void)removeShuffleEnabledChangeRequestedEvent:(EventRegistrationToken)tok;
- (void)updateTimelineProperties:(WMSystemMediaTransportControlsTimelineProperties*)timelineProperties;
@end

#endif // __WMSystemMediaTransportControls_DEFINED__

// Windows.Media.MediaTimelineController
#ifndef __WMMediaTimelineController_DEFINED__
#define __WMMediaTimelineController_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMMediaTimelineController : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* position;
@property double clockRate;
@property (readonly) WMMediaTimelineControllerState state;
@property BOOL isLoopingEnabled;
@property (retain) id /* WFTimeSpan* */ duration;
- (EventRegistrationToken)addPositionChangedEvent:(void(^)(WMMediaTimelineController*, RTObject*))del;
- (void)removePositionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStateChangedEvent:(void(^)(WMMediaTimelineController*, RTObject*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEndedEvent:(void(^)(WMMediaTimelineController*, RTObject*))del;
- (void)removeEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFailedEvent:(void(^)(WMMediaTimelineController*, WMMediaTimelineControllerFailedEventArgs*))del;
- (void)removeFailedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)resume;
- (void)pause;
@end

#endif // __WMMediaTimelineController_DEFINED__

// Windows.Media.MediaTimelineControllerFailedEventArgs
#ifndef __WMMediaTimelineControllerFailedEventArgs_DEFINED__
#define __WMMediaTimelineControllerFailedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMMediaTimelineControllerFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@end

#endif // __WMMediaTimelineControllerFailedEventArgs_DEFINED__

// Windows.Media.MediaExtensionManager
#ifndef __WMMediaExtensionManager_DEFINED__
#define __WMMediaExtensionManager_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMMediaExtensionManager : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)registerSchemeHandler:(NSString *)activatableClassId scheme:(NSString *)scheme;
- (void)registerSchemeHandlerWithSettings:(NSString *)activatableClassId scheme:(NSString *)scheme configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerByteStreamHandler:(NSString *)activatableClassId fileExtension:(NSString *)fileExtension mimeType:(NSString *)mimeType;
- (void)registerByteStreamHandlerWithSettings:(NSString *)activatableClassId fileExtension:(NSString *)fileExtension mimeType:(NSString *)mimeType configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerAudioDecoder:(NSString *)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype;
- (void)registerAudioDecoderWithSettings:(NSString *)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerAudioEncoder:(NSString *)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype;
- (void)registerAudioEncoderWithSettings:(NSString *)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerVideoDecoder:(NSString *)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype;
- (void)registerVideoDecoderWithSettings:(NSString *)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerVideoEncoder:(NSString *)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype;
- (void)registerVideoEncoderWithSettings:(NSString *)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerMediaExtensionForAppService:(RTObject<WMIMediaExtension>*)extension connection:(WAAAppServiceConnection*)connection;
@end

#endif // __WMMediaExtensionManager_DEFINED__

// Windows.Media.VideoEffects
#ifndef __WMVideoEffects_DEFINED__
#define __WMVideoEffects_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMVideoEffects : RTObject
+ (NSString *)videoStabilization;
@end

#endif // __WMVideoEffects_DEFINED__

// Windows.Media.MediaControl
#ifndef __WMMediaControl_DEFINED__
#define __WMMediaControl_DEFINED__

OBJCUWPWINDOWSMEDIAEXPORT
@interface WMMediaControl : RTObject
+ (NSString *)trackName;
+ (void)setTrackName:(NSString *)value;
+ (BOOL)isPlaying;
+ (void)setIsPlaying:(BOOL)value;
+ (NSString *)artistName;
+ (void)setArtistName:(NSString *)value;
+ (WFUri*)albumArt;
+ (void)setAlbumArt:(WFUri*)value;
+ (WMSoundLevel)soundLevel;
+ (EventRegistrationToken)addChannelDownPressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeChannelDownPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addChannelUpPressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeChannelUpPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addFastForwardPressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeFastForwardPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addNextTrackPressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeNextTrackPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addPausePressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removePausePressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addPlayPauseTogglePressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removePlayPauseTogglePressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addPlayPressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removePlayPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addPreviousTrackPressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removePreviousTrackPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRecordPressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeRecordPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRewindPressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeRewindPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addSoundLevelChangedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeSoundLevelChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addStopPressedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeStopPressedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMMediaControl_DEFINED__

