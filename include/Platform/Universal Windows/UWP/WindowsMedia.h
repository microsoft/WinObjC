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

// WindowsMedia.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMMediaProcessingTriggerDetails, WMVideoFrame, WMAudioBuffer, WMAudioFrame, WMMediaMarkerTypes,
    WMSystemMediaTransportControlsTimelineProperties, WMMusicDisplayProperties, WMVideoDisplayProperties, WMImageDisplayProperties,
    WMSystemMediaTransportControlsDisplayUpdater, WMSystemMediaTransportControlsButtonPressedEventArgs,
    WMSystemMediaTransportControlsPropertyChangedEventArgs, WMPlaybackPositionChangeRequestedEventArgs,
    WMPlaybackRateChangeRequestedEventArgs, WMShuffleEnabledChangeRequestedEventArgs, WMAutoRepeatModeChangeRequestedEventArgs,
    WMSystemMediaTransportControls, WMMediaExtensionManager, WMVideoEffects;
@protocol WMIMediaProcessingTriggerDetails
, WMIVideoFrameFactory, WMIAudioFrameFactory, WMIMediaFrame, WMIVideoFrame, WMIAudioFrame, WMIAudioBuffer, WMIMediaMarker, WMIMediaMarkers,
    WMIMediaMarkerTypesStatics, WMISystemMediaTransportControlsTimelineProperties, WMIMusicDisplayProperties, WMIMusicDisplayProperties2,
    WMIVideoDisplayProperties, WMIVideoDisplayProperties2, WMIImageDisplayProperties, WMISystemMediaTransportControlsDisplayUpdater,
    WMISystemMediaTransportControlsButtonPressedEventArgs, WMISystemMediaTransportControlsPropertyChangedEventArgs,
    WMIPlaybackPositionChangeRequestedEventArgs, WMIPlaybackRateChangeRequestedEventArgs, WMIShuffleEnabledChangeRequestedEventArgs,
    WMIAutoRepeatModeChangeRequestedEventArgs, WMISystemMediaTransportControls, WMISystemMediaTransportControls2,
    WMISystemMediaTransportControlsStatics, WMIMediaExtension, WMIMediaExtensionManager, WMIVideoEffectsStatics;

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

// Windows.Media.AudioProcessing
enum _WMAudioProcessing {
    WMAudioProcessingDefault = 0,
    WMAudioProcessingRaw = 1,
};
typedef unsigned WMAudioProcessing;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsDirectXDirect3D11.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.IMediaFrame
#ifndef __WMIMediaFrame_DEFINED__
#define __WMIMediaFrame_DEFINED__

@protocol WMIMediaFrame <WFIClosable>
@property (copy) id duration;
@property (readonly) RTObject<WFCIPropertySet>* extendedProperties;
@property BOOL isDiscontinuous;
@property (readonly) BOOL isReadOnly;
@property (copy) id relativeTime;
@property (copy) id systemRelativeTime;
@property (readonly) NSString* type;
- (void)close;
@end

#endif // __WMIMediaFrame_DEFINED__

// Windows.Media.IMediaMarker
#ifndef __WMIMediaMarker_DEFINED__
#define __WMIMediaMarker_DEFINED__

@protocol WMIMediaMarker
@property (readonly) NSString* mediaMarkerType;
@property (readonly) NSString* text;
@property (readonly) WFTimeSpan* time;
@end

#endif // __WMIMediaMarker_DEFINED__

// Windows.Media.IMediaMarkers
#ifndef __WMIMediaMarkers_DEFINED__
#define __WMIMediaMarkers_DEFINED__

@protocol WMIMediaMarkers
@property (readonly) NSArray* markers;
@end

#endif // __WMIMediaMarkers_DEFINED__

// Windows.Media.IMediaExtension
#ifndef __WMIMediaExtension_DEFINED__
#define __WMIMediaExtension_DEFINED__

@protocol WMIMediaExtension
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMIMediaExtension_DEFINED__

// Windows.Media.MediaProcessingTriggerDetails
#ifndef __WMMediaProcessingTriggerDetails_DEFINED__
#define __WMMediaProcessingTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WMMediaProcessingTriggerDetails : RTObject
@property (readonly) WFCValueSet* arguments;
@end

#endif // __WMMediaProcessingTriggerDetails_DEFINED__

// Windows.Media.VideoFrame
#ifndef __WMVideoFrame_DEFINED__
#define __WMVideoFrame_DEFINED__

WINRT_EXPORT
@interface WMVideoFrame : RTObject <WMIMediaFrame, WFIClosable>
+ (WMVideoFrame*)create:(WGIBitmapPixelFormat)format width:(int)width height:(int)height ACTIVATOR;
+ (WMVideoFrame*)createWithAlpha:(WGIBitmapPixelFormat)format width:(int)width height:(int)height alpha:(WGIBitmapAlphaMode)alpha ACTIVATOR;
@property (copy) id systemRelativeTime;
@property (copy) id relativeTime;
@property BOOL isDiscontinuous;
@property (copy) id duration;
@property (readonly) RTObject<WFCIPropertySet>* extendedProperties;
@property (readonly) BOOL isReadOnly;
@property (readonly) NSString* type;
@property (readonly) RTObject<WGDDIDirect3DSurface>* direct3DSurface;
@property (readonly) WGISoftwareBitmap* softwareBitmap;
- (RTObject<WFIAsyncAction>*)copyToAsync:(WMVideoFrame*)frame;
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

#endif // __WFIMemoryBuffer_DEFINED__

// Windows.Media.AudioBuffer
#ifndef __WMAudioBuffer_DEFINED__
#define __WMAudioBuffer_DEFINED__

WINRT_EXPORT
@interface WMAudioBuffer : RTObject <WFIMemoryBuffer, WFIClosable>
@property unsigned int length;
@property (readonly) unsigned int capacity;
- (RTObject<WFIMemoryBufferReference>*)createReference;
- (void)close;
@end

#endif // __WMAudioBuffer_DEFINED__

// Windows.Media.AudioFrame
#ifndef __WMAudioFrame_DEFINED__
#define __WMAudioFrame_DEFINED__

WINRT_EXPORT
@interface WMAudioFrame : RTObject <WMIMediaFrame, WFIClosable>
+ (WMAudioFrame*)create:(unsigned int)capacity ACTIVATOR;
@property (copy) id systemRelativeTime;
@property (copy) id relativeTime;
@property BOOL isDiscontinuous;
@property (copy) id duration;
@property (readonly) RTObject<WFCIPropertySet>* extendedProperties;
@property (readonly) BOOL isReadOnly;
@property (readonly) NSString* type;
- (WMAudioBuffer*)lockBuffer:(WMAudioBufferAccessMode)mode;
- (void)close;
@end

#endif // __WMAudioFrame_DEFINED__

// Windows.Media.MediaMarkerTypes
#ifndef __WMMediaMarkerTypes_DEFINED__
#define __WMMediaMarkerTypes_DEFINED__

WINRT_EXPORT
@interface WMMediaMarkerTypes : RTObject
+ (NSString*)bookmark;
@end

#endif // __WMMediaMarkerTypes_DEFINED__

// Windows.Media.SystemMediaTransportControlsTimelineProperties
#ifndef __WMSystemMediaTransportControlsTimelineProperties_DEFINED__
#define __WMSystemMediaTransportControlsTimelineProperties_DEFINED__

WINRT_EXPORT
@interface WMSystemMediaTransportControlsTimelineProperties : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFTimeSpan* startTime;
@property (copy) WFTimeSpan* position;
@property (copy) WFTimeSpan* minSeekTime;
@property (copy) WFTimeSpan* maxSeekTime;
@property (copy) WFTimeSpan* endTime;
@end

#endif // __WMSystemMediaTransportControlsTimelineProperties_DEFINED__

// Windows.Media.MusicDisplayProperties
#ifndef __WMMusicDisplayProperties_DEFINED__
#define __WMMusicDisplayProperties_DEFINED__

WINRT_EXPORT
@interface WMMusicDisplayProperties : RTObject
@property (copy) NSString* title;
@property (copy) NSString* artist;
@property (copy) NSString* albumArtist;
@property unsigned int trackNumber;
@property (copy) NSString* albumTitle;
@property (readonly) NSMutableArray* genres;
@end

#endif // __WMMusicDisplayProperties_DEFINED__

// Windows.Media.VideoDisplayProperties
#ifndef __WMVideoDisplayProperties_DEFINED__
#define __WMVideoDisplayProperties_DEFINED__

WINRT_EXPORT
@interface WMVideoDisplayProperties : RTObject
@property (copy) NSString* title;
@property (copy) NSString* subtitle;
@property (readonly) NSMutableArray* genres;
@end

#endif // __WMVideoDisplayProperties_DEFINED__

// Windows.Media.ImageDisplayProperties
#ifndef __WMImageDisplayProperties_DEFINED__
#define __WMImageDisplayProperties_DEFINED__

WINRT_EXPORT
@interface WMImageDisplayProperties : RTObject
@property (copy) NSString* title;
@property (copy) NSString* subtitle;
@end

#endif // __WMImageDisplayProperties_DEFINED__

// Windows.Media.SystemMediaTransportControlsDisplayUpdater
#ifndef __WMSystemMediaTransportControlsDisplayUpdater_DEFINED__
#define __WMSystemMediaTransportControlsDisplayUpdater_DEFINED__

WINRT_EXPORT
@interface WMSystemMediaTransportControlsDisplayUpdater : RTObject
@property WMMediaPlaybackType type;
@property (copy) WSSRandomAccessStreamReference* thumbnail;
@property (copy) NSString* appMediaId;
@property (readonly) WMImageDisplayProperties* imageProperties;
@property (readonly) WMMusicDisplayProperties* musicProperties;
@property (readonly) WMVideoDisplayProperties* videoProperties;
- (void)copyFromFileAsync:(WMMediaPlaybackType)type
                   source:(WSStorageFile*)source
                  success:(void (^)(BOOL))success
                  failure:(void (^)(NSError*))failure;
- (void)clearAll;
- (void)update;
@end

#endif // __WMSystemMediaTransportControlsDisplayUpdater_DEFINED__

// Windows.Media.SystemMediaTransportControlsButtonPressedEventArgs
#ifndef __WMSystemMediaTransportControlsButtonPressedEventArgs_DEFINED__
#define __WMSystemMediaTransportControlsButtonPressedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSystemMediaTransportControlsButtonPressedEventArgs : RTObject
@property (readonly) WMSystemMediaTransportControlsButton button;
@end

#endif // __WMSystemMediaTransportControlsButtonPressedEventArgs_DEFINED__

// Windows.Media.SystemMediaTransportControlsPropertyChangedEventArgs
#ifndef __WMSystemMediaTransportControlsPropertyChangedEventArgs_DEFINED__
#define __WMSystemMediaTransportControlsPropertyChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSystemMediaTransportControlsPropertyChangedEventArgs : RTObject
@property (readonly) WMSystemMediaTransportControlsProperty property ;
@end

#endif // __WMSystemMediaTransportControlsPropertyChangedEventArgs_DEFINED__

// Windows.Media.PlaybackPositionChangeRequestedEventArgs
#ifndef __WMPlaybackPositionChangeRequestedEventArgs_DEFINED__
#define __WMPlaybackPositionChangeRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPlaybackPositionChangeRequestedEventArgs : RTObject
@property (readonly) WFTimeSpan* requestedPlaybackPosition;
@end

#endif // __WMPlaybackPositionChangeRequestedEventArgs_DEFINED__

// Windows.Media.PlaybackRateChangeRequestedEventArgs
#ifndef __WMPlaybackRateChangeRequestedEventArgs_DEFINED__
#define __WMPlaybackRateChangeRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMPlaybackRateChangeRequestedEventArgs : RTObject
@property (readonly) double requestedPlaybackRate;
@end

#endif // __WMPlaybackRateChangeRequestedEventArgs_DEFINED__

// Windows.Media.ShuffleEnabledChangeRequestedEventArgs
#ifndef __WMShuffleEnabledChangeRequestedEventArgs_DEFINED__
#define __WMShuffleEnabledChangeRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMShuffleEnabledChangeRequestedEventArgs : RTObject
@property (readonly) BOOL requestedShuffleEnabled;
@end

#endif // __WMShuffleEnabledChangeRequestedEventArgs_DEFINED__

// Windows.Media.AutoRepeatModeChangeRequestedEventArgs
#ifndef __WMAutoRepeatModeChangeRequestedEventArgs_DEFINED__
#define __WMAutoRepeatModeChangeRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMAutoRepeatModeChangeRequestedEventArgs : RTObject
@property (readonly) WMMediaPlaybackAutoRepeatMode requestedAutoRepeatMode;
@end

#endif // __WMAutoRepeatModeChangeRequestedEventArgs_DEFINED__

// Windows.Media.SystemMediaTransportControls
#ifndef __WMSystemMediaTransportControls_DEFINED__
#define __WMSystemMediaTransportControls_DEFINED__

WINRT_EXPORT
@interface WMSystemMediaTransportControls : RTObject
+ (WMSystemMediaTransportControls*)getForCurrentView;
@property BOOL isRewindEnabled;
@property BOOL isNextEnabled;
@property BOOL isEnabled;
@property BOOL isChannelUpEnabled;
@property BOOL isChannelDownEnabled;
@property BOOL isPlayEnabled;
@property BOOL isFastForwardEnabled;
@property BOOL isPreviousEnabled;
@property WMMediaPlaybackStatus playbackStatus;
@property BOOL isStopEnabled;
@property BOOL isPauseEnabled;
@property BOOL isRecordEnabled;
@property (readonly) WMSystemMediaTransportControlsDisplayUpdater* displayUpdater;
@property (readonly) WMSoundLevel soundLevel;
@property BOOL shuffleEnabled;
@property double playbackRate;
@property WMMediaPlaybackAutoRepeatMode autoRepeatMode;
- (EventRegistrationToken)addButtonPressedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                          WMSystemMediaTransportControlsButtonPressedEventArgs*))del;
- (void)removeButtonPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPropertyChangedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                            WMSystemMediaTransportControlsPropertyChangedEventArgs*))del;
- (void)removePropertyChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAutoRepeatModeChangeRequestedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                                          WMAutoRepeatModeChangeRequestedEventArgs*))del;
- (void)removeAutoRepeatModeChangeRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackPositionChangeRequestedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                                            WMPlaybackPositionChangeRequestedEventArgs*))del;
- (void)removePlaybackPositionChangeRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackRateChangeRequestedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                                        WMPlaybackRateChangeRequestedEventArgs*))del;
- (void)removePlaybackRateChangeRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addShuffleEnabledChangeRequestedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                                          WMShuffleEnabledChangeRequestedEventArgs*))del;
- (void)removeShuffleEnabledChangeRequestedEvent:(EventRegistrationToken)tok;
- (void)updateTimelineProperties:(WMSystemMediaTransportControlsTimelineProperties*)timelineProperties;
@end

#endif // __WMSystemMediaTransportControls_DEFINED__

// Windows.Media.MediaExtensionManager
#ifndef __WMMediaExtensionManager_DEFINED__
#define __WMMediaExtensionManager_DEFINED__

WINRT_EXPORT
@interface WMMediaExtensionManager : RTObject
+ (instancetype)create ACTIVATOR;
- (void)registerSchemeHandler:(NSString*)activatableClassId scheme:(NSString*)scheme;
- (void)registerSchemeHandlerWithSettings:(NSString*)activatableClassId
                                   scheme:(NSString*)scheme
                            configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerByteStreamHandler:(NSString*)activatableClassId fileExtension:(NSString*)fileExtension mimeType:(NSString*)mimeType;
- (void)registerByteStreamHandlerWithSettings:(NSString*)activatableClassId
                                fileExtension:(NSString*)fileExtension
                                     mimeType:(NSString*)mimeType
                                configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerAudioDecoder:(NSString*)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype;
- (void)registerAudioDecoderWithSettings:(NSString*)activatableClassId
                            inputSubtype:(WFGUID*)inputSubtype
                           outputSubtype:(WFGUID*)outputSubtype
                           configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerAudioEncoder:(NSString*)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype;
- (void)registerAudioEncoderWithSettings:(NSString*)activatableClassId
                            inputSubtype:(WFGUID*)inputSubtype
                           outputSubtype:(WFGUID*)outputSubtype
                           configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerVideoDecoder:(NSString*)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype;
- (void)registerVideoDecoderWithSettings:(NSString*)activatableClassId
                            inputSubtype:(WFGUID*)inputSubtype
                           outputSubtype:(WFGUID*)outputSubtype
                           configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)registerVideoEncoder:(NSString*)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype;
- (void)registerVideoEncoderWithSettings:(NSString*)activatableClassId
                            inputSubtype:(WFGUID*)inputSubtype
                           outputSubtype:(WFGUID*)outputSubtype
                           configuration:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMMediaExtensionManager_DEFINED__

// Windows.Media.VideoEffects
#ifndef __WMVideoEffects_DEFINED__
#define __WMVideoEffects_DEFINED__

WINRT_EXPORT
@interface WMVideoEffects : RTObject
+ (NSString*)videoStabilization;
@end

#endif // __WMVideoEffects_DEFINED__
