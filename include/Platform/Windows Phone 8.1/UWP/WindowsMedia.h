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
@class WMMediaControl, WMMediaMarkerTypes, WMMusicDisplayProperties, WMVideoDisplayProperties, WMImageDisplayProperties,
    WMSystemMediaTransportControlsDisplayUpdater, WMSystemMediaTransportControlsButtonPressedEventArgs,
    WMSystemMediaTransportControlsPropertyChangedEventArgs, WMSystemMediaTransportControls, WMMediaExtensionManager, WMVideoEffects;
@protocol WMIMediaControl
, WMIMediaMarker, WMIMediaMarkers, WMIMediaMarkerTypesStatics, WMIMusicDisplayProperties, WMIVideoDisplayProperties,
    WMIImageDisplayProperties, WMISystemMediaTransportControlsDisplayUpdater, WMISystemMediaTransportControlsButtonPressedEventArgs,
    WMISystemMediaTransportControlsPropertyChangedEventArgs, WMISystemMediaTransportControls, WMISystemMediaTransportControlsStatics,
    WMIMediaExtension, WMIMediaExtensionManager, WMIVideoEffectsStatics;

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

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

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
@property (readonly) id<NSFastEnumeration> /*WMIMediaMarker*/ markers;
@end

#endif // __WMIMediaMarkers_DEFINED__

// Windows.Media.IMediaExtension
#ifndef __WMIMediaExtension_DEFINED__
#define __WMIMediaExtension_DEFINED__

@protocol WMIMediaExtension
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMIMediaExtension_DEFINED__

// Windows.Media.MediaControl
#ifndef __WMMediaControl_DEFINED__
#define __WMMediaControl_DEFINED__

WINRT_EXPORT
@interface WMMediaControl : RTObject
+ (NSString*)trackName;
+ (void)setTrackName:(NSString*)value;
+ (BOOL)isPlaying;
+ (void)setIsPlaying:(BOOL)value;
+ (NSString*)artistName;
+ (void)setArtistName:(NSString*)value;
+ (WFUri*)albumArt;
+ (void)setAlbumArt:(WFUri*)value;
+ (WMSoundLevel)soundLevel;
+ (EventRegistrationToken)addChannelDownPressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeChannelDownPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addChannelUpPressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeChannelUpPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addFastForwardPressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeFastForwardPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addNextTrackPressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeNextTrackPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addPausePressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removePausePressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addPlayPauseTogglePressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removePlayPauseTogglePressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addPlayPressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removePlayPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addPreviousTrackPressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removePreviousTrackPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRecordPressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeRecordPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRewindPressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeRewindPressedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addSoundLevelChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeSoundLevelChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addStopPressedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeStopPressedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMMediaControl_DEFINED__

// Windows.Media.MediaMarkerTypes
#ifndef __WMMediaMarkerTypes_DEFINED__
#define __WMMediaMarkerTypes_DEFINED__

WINRT_EXPORT
@interface WMMediaMarkerTypes : RTObject
+ (NSString*)bookmark;
@end

#endif // __WMMediaMarkerTypes_DEFINED__

// Windows.Media.MusicDisplayProperties
#ifndef __WMMusicDisplayProperties_DEFINED__
#define __WMMusicDisplayProperties_DEFINED__

WINRT_EXPORT
@interface WMMusicDisplayProperties : RTObject
@property (copy) NSString* title;
@property (copy) NSString* artist;
@property (copy) NSString* albumArtist;
@end

#endif // __WMMusicDisplayProperties_DEFINED__

// Windows.Media.VideoDisplayProperties
#ifndef __WMVideoDisplayProperties_DEFINED__
#define __WMVideoDisplayProperties_DEFINED__

WINRT_EXPORT
@interface WMVideoDisplayProperties : RTObject
@property (copy) NSString* title;
@property (copy) NSString* subtitle;
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

// Windows.Media.SystemMediaTransportControls
#ifndef __WMSystemMediaTransportControls_DEFINED__
#define __WMSystemMediaTransportControls_DEFINED__

WINRT_EXPORT
@interface WMSystemMediaTransportControls : RTObject
+ (WMSystemMediaTransportControls*)getForCurrentView;
@property WMMediaPlaybackStatus playbackStatus;
@property BOOL isStopEnabled;
@property BOOL isRewindEnabled;
@property BOOL isRecordEnabled;
@property BOOL isPreviousEnabled;
@property BOOL isPlayEnabled;
@property BOOL isPauseEnabled;
@property BOOL isNextEnabled;
@property BOOL isFastForwardEnabled;
@property BOOL isEnabled;
@property BOOL isChannelUpEnabled;
@property BOOL isChannelDownEnabled;
@property (readonly) WMSystemMediaTransportControlsDisplayUpdater* displayUpdater;
@property (readonly) WMSoundLevel soundLevel;
- (EventRegistrationToken)addButtonPressedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                          WMSystemMediaTransportControlsButtonPressedEventArgs*))del;
- (void)removeButtonPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPropertyChangedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                            WMSystemMediaTransportControlsPropertyChangedEventArgs*))del;
- (void)removePropertyChangedEvent:(EventRegistrationToken)tok;
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
