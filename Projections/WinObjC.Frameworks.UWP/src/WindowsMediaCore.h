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

// WindowsMediaCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
#define OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaCaptureDevicesCorePlaybackProtection.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMCAudioStreamDescriptor, WMCVideoStreamDescriptor, WMCMediaStreamSource, WMCMediaStreamSourceClosedEventArgs,
    WMCMediaStreamSourceStartingEventArgs, WMCMediaStreamSourceSampleRequestedEventArgs,
    WMCMediaStreamSourceSwitchStreamsRequestedEventArgs, WMCMediaStreamSourceSampleRenderedEventArgs, WMCMediaStreamSamplePropertySet,
    WMCMediaStreamSample, WMCMediaStreamSampleProtectionProperties, WMCMediaStreamSourceClosedRequest,
    WMCMediaStreamSourceStartingRequestDeferral, WMCMediaStreamSourceStartingRequest, WMCMediaStreamSourceSampleRequestDeferral,
    WMCMediaStreamSourceSampleRequest, WMCMediaStreamSourceSwitchStreamsRequestDeferral, WMCMediaStreamSourceSwitchStreamsRequest,
    WMCMseStreamSource, WMCMseSourceBufferList, WMCMseSourceBuffer, WMCHighDynamicRangeControl, WMCSceneAnalysisEffect,
    WMCSceneAnalyzedEventArgs, WMCHighDynamicRangeOutput, WMCSceneAnalysisEffectFrame, WMCSceneAnalysisEffectDefinition,
    WMCFaceDetectionEffectFrame, WMCFaceDetectedEventArgs, WMCFaceDetectionEffect, WMCFaceDetectionEffectDefinition,
    WMCVideoStabilizationEffectEnabledChangedEventArgs, WMCVideoStabilizationEffect, WMCVideoStabilizationEffectDefinition,
    WMCMediaSourceError, WMCMediaSource, WMCMediaBinder, WMCMediaBindingEventArgs, WMCMediaSourceOpenOperationCompletedEventArgs,
    WMCTimedTextSource, WMCTimedMetadataTrack, WMCMediaSourceStateChangedEventArgs, WMCTimedTextRegion, WMCTimedTextStyle, WMCTimedTextLine,
    WMCTimedTextSubformat, WMCTimedMetadataTrackError, WMCMediaCueEventArgs, WMCTimedMetadataTrackFailedEventArgs,
    WMCTimedTextSourceResolveResultEventArgs, WMCVideoTrack, WMCVideoTrackOpenFailedEventArgs, WMCVideoTrackSupportInfo, WMCAudioTrack,
    WMCAudioTrackOpenFailedEventArgs, WMCAudioTrackSupportInfo, WMCTimedTextCue, WMCDataCue;
@class WMCMseTimeRange, WMCTimedTextPadding, WMCTimedTextSize, WMCTimedTextDouble, WMCTimedTextPoint;
@protocol WMCIMediaSource
, WMCIMediaStreamDescriptor, WMCIAudioStreamDescriptor, WMCIAudioStreamDescriptor2, WMCIAudioStreamDescriptorFactory,
    WMCIVideoStreamDescriptor, WMCIVideoStreamDescriptorFactory, WMCIMediaStreamSource, WMCIMediaStreamSource2,
    WMCIMediaStreamSourceFactory, WMCIMediaStreamSample, WMCIMediaStreamSampleStatics, WMCIMediaStreamSampleProtectionProperties,
    WMCIMediaStreamSourceClosedRequest, WMCIMediaStreamSourceClosedEventArgs, WMCIMediaStreamSourceStartingRequestDeferral,
    WMCIMediaStreamSourceStartingRequest, WMCIMediaStreamSourceStartingEventArgs, WMCIMediaStreamSourceSampleRequestDeferral,
    WMCIMediaStreamSourceSampleRequest, WMCIMediaStreamSourceSampleRequestedEventArgs, WMCIMediaStreamSourceSwitchStreamsRequestDeferral,
    WMCIMediaStreamSourceSwitchStreamsRequest, WMCIMediaStreamSourceSwitchStreamsRequestedEventArgs,
    WMCIMediaStreamSourceSampleRenderedEventArgs, WMCIMseStreamSourceStatics, WMCIMseStreamSource, WMCIMseSourceBuffer,
    WMCIMseSourceBufferList, WMCIHighDynamicRangeControl, WMCISceneAnalysisEffect, WMCIHighDynamicRangeOutput, WMCISceneAnalysisEffectFrame,
    WMCISceneAnalyzedEventArgs, WMCIFaceDetectionEffectFrame, WMCIFaceDetectedEventArgs, WMCIFaceDetectionEffect,
    WMCIFaceDetectionEffectDefinition, WMCIVideoStabilizationEffectEnabledChangedEventArgs, WMCIVideoStabilizationEffect,
    WMCIMediaSourceError, WMCIMediaSourceOpenOperationCompletedEventArgs, WMCIMediaSourceStateChangedEventArgs, WMCIMediaSourceStatics,
    WMCIMediaSourceStatics2, WMCIMediaBinder, WMCIMediaBindingEventArgs, WMCIMediaSource2, WMCIMediaSource3, WMCIMediaCue, WMCITimedTextCue,
    WMCITimedTextRegion, WMCITimedTextStyle, WMCITimedTextSubformat, WMCITimedTextLine, WMCISingleSelectMediaTrackList, WMCIMediaTrack,
    WMCITimedMetadataTrackError, WMCIMediaCueEventArgs, WMCITimedMetadataTrackFailedEventArgs, WMCIDataCue, WMCITimedMetadataTrackFactory,
    WMCITimedMetadataTrack, WMCITimedTextSourceResolveResultEventArgs, WMCITimedTextSource, WMCITimedTextSourceStatics,
    WMCIVideoTrackSupportInfo, WMCIAudioTrackSupportInfo, WMCIVideoTrackOpenFailedEventArgs, WMCIAudioTrackOpenFailedEventArgs,
    WMCIVideoTrack, WMCIAudioTrack, WMCITimedMetadataTrack2;

// Windows.Media.Core.MediaStreamSourceClosedReason
enum _WMCMediaStreamSourceClosedReason {
    WMCMediaStreamSourceClosedReasonDone = 0,
    WMCMediaStreamSourceClosedReasonUnknownError = 1,
    WMCMediaStreamSourceClosedReasonAppReportedError = 2,
    WMCMediaStreamSourceClosedReasonUnsupportedProtectionSystem = 3,
    WMCMediaStreamSourceClosedReasonProtectionSystemFailure = 4,
    WMCMediaStreamSourceClosedReasonUnsupportedEncodingFormat = 5,
    WMCMediaStreamSourceClosedReasonMissingSampleRequestedEventHandler = 6,
};
typedef unsigned WMCMediaStreamSourceClosedReason;

// Windows.Media.Core.MediaStreamSourceErrorStatus
enum _WMCMediaStreamSourceErrorStatus {
    WMCMediaStreamSourceErrorStatusOther = 0,
    WMCMediaStreamSourceErrorStatusOutOfMemory = 1,
    WMCMediaStreamSourceErrorStatusFailedToOpenFile = 2,
    WMCMediaStreamSourceErrorStatusFailedToConnectToServer = 3,
    WMCMediaStreamSourceErrorStatusConnectionToServerLost = 4,
    WMCMediaStreamSourceErrorStatusUnspecifiedNetworkError = 5,
    WMCMediaStreamSourceErrorStatusDecodeError = 6,
    WMCMediaStreamSourceErrorStatusUnsupportedMediaFormat = 7,
};
typedef unsigned WMCMediaStreamSourceErrorStatus;

// Windows.Media.Core.MseReadyState
enum _WMCMseReadyState {
    WMCMseReadyStateClosed = 0,
    WMCMseReadyStateOpen = 1,
    WMCMseReadyStateEnded = 2,
};
typedef unsigned WMCMseReadyState;

// Windows.Media.Core.MseEndOfStreamStatus
enum _WMCMseEndOfStreamStatus {
    WMCMseEndOfStreamStatusSuccess = 0,
    WMCMseEndOfStreamStatusNetworkError = 1,
    WMCMseEndOfStreamStatusDecodeError = 2,
    WMCMseEndOfStreamStatusUnknownError = 3,
};
typedef unsigned WMCMseEndOfStreamStatus;

// Windows.Media.Core.MseAppendMode
enum _WMCMseAppendMode {
    WMCMseAppendModeSegments = 0,
    WMCMseAppendModeSequence = 1,
};
typedef unsigned WMCMseAppendMode;

// Windows.Media.Core.FaceDetectionMode
enum _WMCFaceDetectionMode {
    WMCFaceDetectionModeHighPerformance = 0,
    WMCFaceDetectionModeBalanced = 1,
    WMCFaceDetectionModeHighQuality = 2,
};
typedef unsigned WMCFaceDetectionMode;

// Windows.Media.Core.VideoStabilizationEffectEnabledChangedReason
enum _WMCVideoStabilizationEffectEnabledChangedReason {
    WMCVideoStabilizationEffectEnabledChangedReasonProgrammatic = 0,
    WMCVideoStabilizationEffectEnabledChangedReasonPixelRateTooHigh = 1,
    WMCVideoStabilizationEffectEnabledChangedReasonRunningSlowly = 2,
};
typedef unsigned WMCVideoStabilizationEffectEnabledChangedReason;

// Windows.Media.Core.MediaTrackKind
enum _WMCMediaTrackKind {
    WMCMediaTrackKindAudio = 0,
    WMCMediaTrackKindVideo = 1,
    WMCMediaTrackKindTimedMetadata = 2,
};
typedef unsigned WMCMediaTrackKind;

// Windows.Media.Core.TimedMetadataKind
enum _WMCTimedMetadataKind {
    WMCTimedMetadataKindCaption = 0,
    WMCTimedMetadataKindChapter = 1,
    WMCTimedMetadataKindCustom = 2,
    WMCTimedMetadataKindData = 3,
    WMCTimedMetadataKindDescription = 4,
    WMCTimedMetadataKindSubtitle = 5,
};
typedef unsigned WMCTimedMetadataKind;

// Windows.Media.Core.TimedMetadataTrackErrorCode
enum _WMCTimedMetadataTrackErrorCode {
    WMCTimedMetadataTrackErrorCodeNone = 0,
    WMCTimedMetadataTrackErrorCodeDataFormatError = 1,
    WMCTimedMetadataTrackErrorCodeNetworkError = 2,
    WMCTimedMetadataTrackErrorCodeInternalError = 3,
};
typedef unsigned WMCTimedMetadataTrackErrorCode;

// Windows.Media.Core.TimedTextScrollMode
enum _WMCTimedTextScrollMode {
    WMCTimedTextScrollModePopon = 0,
    WMCTimedTextScrollModeRollup = 1,
};
typedef unsigned WMCTimedTextScrollMode;

// Windows.Media.Core.TimedTextUnit
enum _WMCTimedTextUnit {
    WMCTimedTextUnitPixels = 0,
    WMCTimedTextUnitPercentage = 1,
};
typedef unsigned WMCTimedTextUnit;

// Windows.Media.Core.TimedTextWritingMode
enum _WMCTimedTextWritingMode {
    WMCTimedTextWritingModeLeftRightTopBottom = 0,
    WMCTimedTextWritingModeRightLeftTopBottom = 1,
    WMCTimedTextWritingModeTopBottomRightLeft = 2,
    WMCTimedTextWritingModeTopBottomLeftRight = 3,
    WMCTimedTextWritingModeLeftRight = 4,
    WMCTimedTextWritingModeRightLeft = 5,
    WMCTimedTextWritingModeTopBottom = 6,
};
typedef unsigned WMCTimedTextWritingMode;

// Windows.Media.Core.TimedTextDisplayAlignment
enum _WMCTimedTextDisplayAlignment {
    WMCTimedTextDisplayAlignmentBefore = 0,
    WMCTimedTextDisplayAlignmentAfter = 1,
    WMCTimedTextDisplayAlignmentCenter = 2,
};
typedef unsigned WMCTimedTextDisplayAlignment;

// Windows.Media.Core.TimedTextLineAlignment
enum _WMCTimedTextLineAlignment {
    WMCTimedTextLineAlignmentStart = 0,
    WMCTimedTextLineAlignmentEnd = 1,
    WMCTimedTextLineAlignmentCenter = 2,
};
typedef unsigned WMCTimedTextLineAlignment;

// Windows.Media.Core.TimedTextWrapping
enum _WMCTimedTextWrapping {
    WMCTimedTextWrappingNoWrap = 0,
    WMCTimedTextWrappingWrap = 1,
};
typedef unsigned WMCTimedTextWrapping;

// Windows.Media.Core.TimedTextWeight
enum _WMCTimedTextWeight {
    WMCTimedTextWeightNormal = 400,
    WMCTimedTextWeightBold = 700,
};
typedef unsigned WMCTimedTextWeight;

// Windows.Media.Core.TimedTextFlowDirection
enum _WMCTimedTextFlowDirection {
    WMCTimedTextFlowDirectionLeftToRight = 0,
    WMCTimedTextFlowDirectionRightToLeft = 1,
};
typedef unsigned WMCTimedTextFlowDirection;

// Windows.Media.Core.MediaDecoderStatus
enum _WMCMediaDecoderStatus {
    WMCMediaDecoderStatusFullySupported = 0,
    WMCMediaDecoderStatusUnsupportedSubtype = 1,
    WMCMediaDecoderStatusUnsupportedEncoderProperties = 2,
    WMCMediaDecoderStatusDegraded = 3,
};
typedef unsigned WMCMediaDecoderStatus;

// Windows.Media.Core.AudioDecoderDegradation
enum _WMCAudioDecoderDegradation {
    WMCAudioDecoderDegradationNone = 0,
    WMCAudioDecoderDegradationDownmixTo2Channels = 1,
    WMCAudioDecoderDegradationDownmixTo6Channels = 2,
    WMCAudioDecoderDegradationDownmixTo8Channels = 3,
};
typedef unsigned WMCAudioDecoderDegradation;

// Windows.Media.Core.AudioDecoderDegradationReason
enum _WMCAudioDecoderDegradationReason {
    WMCAudioDecoderDegradationReasonNone = 0,
    WMCAudioDecoderDegradationReasonLicensingRequirement = 1,
};
typedef unsigned WMCAudioDecoderDegradationReason;

// Windows.Media.Core.MediaSourceStatus
enum _WMCMediaSourceStatus {
    WMCMediaSourceStatusFullySupported = 0,
    WMCMediaSourceStatusUnknown = 1,
};
typedef unsigned WMCMediaSourceStatus;

// Windows.Media.Core.MediaSourceState
enum _WMCMediaSourceState {
    WMCMediaSourceStateInitial = 0,
    WMCMediaSourceStateOpening = 1,
    WMCMediaSourceStateOpened = 2,
    WMCMediaSourceStateFailed = 3,
    WMCMediaSourceStateClosed = 4,
};
typedef unsigned WMCMediaSourceState;

#include "WindowsMediaFaceAnalysis.h"
#include "WindowsMediaProtection.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsStorageFileProperties.h"
#include "WindowsMediaDevicesCore.h"
#include "WindowsMedia.h"
#include "WindowsMediaCapture.h"
#include "WindowsMediaEffects.h"
#include "WindowsMediaDevices.h"
#include "WindowsMediaStreamingAdaptive.h"
#include "WindowsStorage.h"
#include "WindowsMediaPlayback.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUI.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Media.Core.MseTimeRange
OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMseTimeRange : NSObject
+ (instancetype) new;
@property (retain) WFTimeSpan* start;
@property (retain) WFTimeSpan* end;
@end

// [struct] Windows.Media.Core.TimedTextPadding
OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextPadding : NSObject
+ (instancetype) new;
@property double before;
@property double after;
@property double start;
@property double end;
@property WMCTimedTextUnit unit;
@end

// [struct] Windows.Media.Core.TimedTextSize
OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextSize : NSObject
+ (instancetype) new;
@property double height;
@property double width;
@property WMCTimedTextUnit unit;
@end

// [struct] Windows.Media.Core.TimedTextDouble
OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextDouble : NSObject
+ (instancetype) new;
@property double value;
@property WMCTimedTextUnit unit;
@end

// [struct] Windows.Media.Core.TimedTextPoint
OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextPoint : NSObject
+ (instancetype) new;
@property double x;
@property double y;
@property WMCTimedTextUnit unit;
@end

// Windows.Media.Core.IMediaSource
#ifndef __WMCIMediaSource_DEFINED__
#define __WMCIMediaSource_DEFINED__

@protocol WMCIMediaSource
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCIMediaSource : RTObject <WMCIMediaSource>
@end

#endif // __WMCIMediaSource_DEFINED__

// Windows.Media.Core.IMediaStreamDescriptor
#ifndef __WMCIMediaStreamDescriptor_DEFINED__
#define __WMCIMediaStreamDescriptor_DEFINED__

@protocol WMCIMediaStreamDescriptor
@property (readonly) BOOL isSelected;
@property (retain) NSString* language;
@property (retain) NSString* name;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCIMediaStreamDescriptor : RTObject <WMCIMediaStreamDescriptor>
@end

#endif // __WMCIMediaStreamDescriptor_DEFINED__

// Windows.Media.Core.IMediaCue
#ifndef __WMCIMediaCue_DEFINED__
#define __WMCIMediaCue_DEFINED__

@protocol WMCIMediaCue
@property (retain) WFTimeSpan* duration;
@property (retain) NSString* id;
@property (retain) WFTimeSpan* startTime;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCIMediaCue : RTObject <WMCIMediaCue>
@end

#endif // __WMCIMediaCue_DEFINED__

// Windows.Media.Core.ISingleSelectMediaTrackList
#ifndef __WMCISingleSelectMediaTrackList_DEFINED__
#define __WMCISingleSelectMediaTrackList_DEFINED__

@protocol WMCISingleSelectMediaTrackList
@property int selectedIndex;
- (EventRegistrationToken)addSelectedIndexChangedEvent:(void (^)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*))del;
- (void)removeSelectedIndexChangedEvent:(EventRegistrationToken)tok;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCISingleSelectMediaTrackList : RTObject <WMCISingleSelectMediaTrackList>
@end

#endif // __WMCISingleSelectMediaTrackList_DEFINED__

// Windows.Media.Core.IMediaTrack
#ifndef __WMCIMediaTrack_DEFINED__
#define __WMCIMediaTrack_DEFINED__

@protocol WMCIMediaTrack
@property (readonly) NSString* id;
@property (retain) NSString* label;
@property (readonly) NSString* language;
@property (readonly) WMCMediaTrackKind trackKind;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCIMediaTrack : RTObject <WMCIMediaTrack>
@end

#endif // __WMCIMediaTrack_DEFINED__

// Windows.Media.Core.AudioStreamDescriptor
#ifndef __WMCAudioStreamDescriptor_DEFINED__
#define __WMCAudioStreamDescriptor_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAudioStreamDescriptor : RTObject <WMCIMediaStreamDescriptor>
+ (WMCAudioStreamDescriptor*)make:(WMMAudioEncodingProperties*)encodingProperties ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
@property (retain) id /* unsigned int */ trailingEncoderPadding;
@property (retain) id /* unsigned int */ leadingEncoderPadding;
@property (retain) NSString* name;
@property (retain) NSString* language;
@property (readonly) BOOL isSelected;
@end

#endif // __WMCAudioStreamDescriptor_DEFINED__

// Windows.Media.Core.VideoStreamDescriptor
#ifndef __WMCVideoStreamDescriptor_DEFINED__
#define __WMCVideoStreamDescriptor_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCVideoStreamDescriptor : RTObject <WMCIMediaStreamDescriptor>
+ (WMCVideoStreamDescriptor*)make:(WMMVideoEncodingProperties*)encodingProperties ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) NSString* name;
@property (retain) NSString* language;
@property (readonly) BOOL isSelected;
@property (readonly) WMMVideoEncodingProperties* encodingProperties;
@end

#endif // __WMCVideoStreamDescriptor_DEFINED__

// Windows.Media.Core.MediaStreamSource
#ifndef __WMCMediaStreamSource_DEFINED__
#define __WMCMediaStreamSource_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSource : RTObject <WMCIMediaSource>
+ (WMCMediaStreamSource*)makeFromDescriptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor ACTIVATOR;
+ (WMCMediaStreamSource*)makeFromDescriptors:(RTObject<WMCIMediaStreamDescriptor>*)descriptor
                                 descriptor2:(RTObject<WMCIMediaStreamDescriptor>*)descriptor2 ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) RTObject<WSSIRandomAccessStreamReference>* thumbnail;
@property (retain) WMPMediaProtectionManager* mediaProtectionManager;
@property (retain) WFTimeSpan* duration;
@property BOOL canSeek;
@property (retain) WFTimeSpan* bufferTime;
@property (readonly) WSFMusicProperties* musicProperties;
@property (readonly) WSFVideoProperties* videoProperties;
- (EventRegistrationToken)addClosedEvent:(void (^)(WMCMediaStreamSource*, WMCMediaStreamSourceClosedEventArgs*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPausedEvent:(void (^)(WMCMediaStreamSource*, RTObject*))del;
- (void)removePausedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSampleRequestedEvent:(void (^)(WMCMediaStreamSource*, WMCMediaStreamSourceSampleRequestedEventArgs*))del;
- (void)removeSampleRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStartingEvent:(void (^)(WMCMediaStreamSource*, WMCMediaStreamSourceStartingEventArgs*))del;
- (void)removeStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSwitchStreamsRequestedEvent:(void (^)(WMCMediaStreamSource*,
                                                                   WMCMediaStreamSourceSwitchStreamsRequestedEventArgs*))del;
- (void)removeSwitchStreamsRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSampleRenderedEvent:(void (^)(WMCMediaStreamSource*, WMCMediaStreamSourceSampleRenderedEventArgs*))del;
- (void)removeSampleRenderedEvent:(EventRegistrationToken)tok;
- (void)notifyError:(WMCMediaStreamSourceErrorStatus)errorStatus;
- (void)addStreamDescriptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor;
- (void)setBufferedRange:(WFTimeSpan*)startOffset endOffset:(WFTimeSpan*)endOffset;
- (void)addProtectionKey:(RTObject<WMCIMediaStreamDescriptor>*)streamDescriptor
           keyIdentifier:(NSArray* /* uint8_t */)keyIdentifier
             licenseData:(NSArray* /* uint8_t */)licenseData;
@end

#endif // __WMCMediaStreamSource_DEFINED__

// Windows.Media.Core.MediaStreamSourceClosedEventArgs
#ifndef __WMCMediaStreamSourceClosedEventArgs_DEFINED__
#define __WMCMediaStreamSourceClosedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceClosedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaStreamSourceClosedRequest* request;
@end

#endif // __WMCMediaStreamSourceClosedEventArgs_DEFINED__

// Windows.Media.Core.MediaStreamSourceStartingEventArgs
#ifndef __WMCMediaStreamSourceStartingEventArgs_DEFINED__
#define __WMCMediaStreamSourceStartingEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceStartingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaStreamSourceStartingRequest* request;
@end

#endif // __WMCMediaStreamSourceStartingEventArgs_DEFINED__

// Windows.Media.Core.MediaStreamSourceSampleRequestedEventArgs
#ifndef __WMCMediaStreamSourceSampleRequestedEventArgs_DEFINED__
#define __WMCMediaStreamSourceSampleRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceSampleRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaStreamSourceSampleRequest* request;
@end

#endif // __WMCMediaStreamSourceSampleRequestedEventArgs_DEFINED__

// Windows.Media.Core.MediaStreamSourceSwitchStreamsRequestedEventArgs
#ifndef __WMCMediaStreamSourceSwitchStreamsRequestedEventArgs_DEFINED__
#define __WMCMediaStreamSourceSwitchStreamsRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceSwitchStreamsRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaStreamSourceSwitchStreamsRequest* request;
@end

#endif // __WMCMediaStreamSourceSwitchStreamsRequestedEventArgs_DEFINED__

// Windows.Media.Core.MediaStreamSourceSampleRenderedEventArgs
#ifndef __WMCMediaStreamSourceSampleRenderedEventArgs_DEFINED__
#define __WMCMediaStreamSourceSampleRenderedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceSampleRenderedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* sampleLag;
@end

#endif // __WMCMediaStreamSourceSampleRenderedEventArgs_DEFINED__

// Windows.Media.Core.MediaStreamSamplePropertySet
#ifndef __WMCMediaStreamSamplePropertySet_DEFINED__
#define __WMCMediaStreamSamplePropertySet_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSamplePropertySet : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (id)objectForKey:(id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

- (void)setObject:(id)obj forKey:(id)key;
- (void)setObject:(id)object forKeyedSubscript:(id)key;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keys;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDict;
- (void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
- (void)setDictionary:(NSDictionary*)dict;
@end

#endif // __WMCMediaStreamSamplePropertySet_DEFINED__

// Windows.Media.Core.MediaStreamSample
#ifndef __WMCMediaStreamSample_DEFINED__
#define __WMCMediaStreamSample_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSample : RTObject
+ (WMCMediaStreamSample*)createFromBuffer:(RTObject<WSSIBuffer>*)buffer timestamp:(WFTimeSpan*)timestamp;
+ (void)createFromStreamAsync:(RTObject<WSSIInputStream>*)stream
                        count:(unsigned int)count
                    timestamp:(WFTimeSpan*)timestamp
                      success:(void (^)(WMCMediaStreamSample*))success
                      failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property BOOL keyFrame;
@property (retain) WFTimeSpan* duration;
@property BOOL discontinuous;
@property (retain) WFTimeSpan* decodeTimestamp;
@property (readonly) WSSBuffer* buffer;
@property (readonly) WMCMediaStreamSamplePropertySet* extendedProperties;
@property (readonly) WMCMediaStreamSampleProtectionProperties* protection;
@property (readonly) WFTimeSpan* timestamp;
- (EventRegistrationToken)addProcessedEvent:(void (^)(WMCMediaStreamSample*, RTObject*))del;
- (void)removeProcessedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMCMediaStreamSample_DEFINED__

// Windows.Media.Core.MediaStreamSampleProtectionProperties
#ifndef __WMCMediaStreamSampleProtectionProperties_DEFINED__
#define __WMCMediaStreamSampleProtectionProperties_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSampleProtectionProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (void)setKeyIdentifier:(NSArray* /* uint8_t */)value;
- (void)getKeyIdentifier:(NSArray* /* uint8_t */*)value;
- (void)setInitializationVector:(NSArray* /* uint8_t */)value;
- (void)getInitializationVector:(NSArray* /* uint8_t */*)value;
- (void)setSubSampleMapping:(NSArray* /* uint8_t */)value;
- (void)getSubSampleMapping:(NSArray* /* uint8_t */*)value;
@end

#endif // __WMCMediaStreamSampleProtectionProperties_DEFINED__

// Windows.Media.Core.MediaStreamSourceClosedRequest
#ifndef __WMCMediaStreamSourceClosedRequest_DEFINED__
#define __WMCMediaStreamSourceClosedRequest_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceClosedRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaStreamSourceClosedReason reason;
@end

#endif // __WMCMediaStreamSourceClosedRequest_DEFINED__

// Windows.Media.Core.MediaStreamSourceStartingRequestDeferral
#ifndef __WMCMediaStreamSourceStartingRequestDeferral_DEFINED__
#define __WMCMediaStreamSourceStartingRequestDeferral_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceStartingRequestDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WMCMediaStreamSourceStartingRequestDeferral_DEFINED__

// Windows.Media.Core.MediaStreamSourceStartingRequest
#ifndef __WMCMediaStreamSourceStartingRequest_DEFINED__
#define __WMCMediaStreamSourceStartingRequest_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceStartingRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) id /* WFTimeSpan* */ startPosition;
- (WMCMediaStreamSourceStartingRequestDeferral*)getDeferral;
- (void)setActualStartPosition:(WFTimeSpan*)position;
@end

#endif // __WMCMediaStreamSourceStartingRequest_DEFINED__

// Windows.Media.Core.MediaStreamSourceSampleRequestDeferral
#ifndef __WMCMediaStreamSourceSampleRequestDeferral_DEFINED__
#define __WMCMediaStreamSourceSampleRequestDeferral_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceSampleRequestDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WMCMediaStreamSourceSampleRequestDeferral_DEFINED__

// Windows.Media.Core.MediaStreamSourceSampleRequest
#ifndef __WMCMediaStreamSourceSampleRequest_DEFINED__
#define __WMCMediaStreamSourceSampleRequest_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceSampleRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) WMCMediaStreamSample* sample;
@property (readonly) RTObject<WMCIMediaStreamDescriptor>* streamDescriptor;
- (WMCMediaStreamSourceSampleRequestDeferral*)getDeferral;
- (void)reportSampleProgress:(unsigned int)progress;
@end

#endif // __WMCMediaStreamSourceSampleRequest_DEFINED__

// Windows.Media.Core.MediaStreamSourceSwitchStreamsRequestDeferral
#ifndef __WMCMediaStreamSourceSwitchStreamsRequestDeferral_DEFINED__
#define __WMCMediaStreamSourceSwitchStreamsRequestDeferral_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceSwitchStreamsRequestDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WMCMediaStreamSourceSwitchStreamsRequestDeferral_DEFINED__

// Windows.Media.Core.MediaStreamSourceSwitchStreamsRequest
#ifndef __WMCMediaStreamSourceSwitchStreamsRequest_DEFINED__
#define __WMCMediaStreamSourceSwitchStreamsRequest_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaStreamSourceSwitchStreamsRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WMCIMediaStreamDescriptor>* newStreamDescriptor __attribute__((ns_returns_not_retained));
@property (readonly) RTObject<WMCIMediaStreamDescriptor>* oldStreamDescriptor;
- (WMCMediaStreamSourceSwitchStreamsRequestDeferral*)getDeferral;
@end

#endif // __WMCMediaStreamSourceSwitchStreamsRequest_DEFINED__

// Windows.Media.Core.MseStreamSource
#ifndef __WMCMseStreamSource_DEFINED__
#define __WMCMseStreamSource_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMseStreamSource : RTObject <WMCIMediaSource>
+ (BOOL)isContentTypeSupported:(NSString*)contentType;
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) id /* WFTimeSpan* */ duration;
@property (readonly) WMCMseSourceBufferList* activeSourceBuffers;
@property (readonly) WMCMseReadyState readyState;
@property (readonly) WMCMseSourceBufferList* sourceBuffers;
- (EventRegistrationToken)addClosedEvent:(void (^)(WMCMseStreamSource*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEndedEvent:(void (^)(WMCMseStreamSource*, RTObject*))del;
- (void)removeEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(void (^)(WMCMseStreamSource*, RTObject*))del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
- (WMCMseSourceBuffer*)addSourceBuffer:(NSString*)mimeType;
- (void)removeSourceBuffer:(WMCMseSourceBuffer*)buffer;
- (void)endOfStream:(WMCMseEndOfStreamStatus)status;
@end

#endif // __WMCMseStreamSource_DEFINED__

// Windows.Media.Core.MseSourceBufferList
#ifndef __WMCMseSourceBufferList_DEFINED__
#define __WMCMseSourceBufferList_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMseSourceBufferList : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WMCMseSourceBuffer* */ buffers;
- (EventRegistrationToken)addSourceBufferAddedEvent:(void (^)(WMCMseSourceBufferList*, RTObject*))del;
- (void)removeSourceBufferAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceBufferRemovedEvent:(void (^)(WMCMseSourceBufferList*, RTObject*))del;
- (void)removeSourceBufferRemovedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMCMseSourceBufferList_DEFINED__

// Windows.Media.Core.MseSourceBuffer
#ifndef __WMCMseSourceBuffer_DEFINED__
#define __WMCMseSourceBuffer_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMseSourceBuffer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* timestampOffset;
@property WMCMseAppendMode mode;
@property (retain) WFTimeSpan* appendWindowStart;
@property (retain) id /* WFTimeSpan* */ appendWindowEnd;
@property (readonly) NSArray* /* WMCMseTimeRange* */ buffered;
@property (readonly) BOOL isUpdating;
- (EventRegistrationToken)addAbortedEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))del;
- (void)removeAbortedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdateEndedEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))del;
- (void)removeUpdateEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdateStartingEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))del;
- (void)removeUpdateStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdatedEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))del;
- (void)removeUpdatedEvent:(EventRegistrationToken)tok;
- (void)appendBuffer:(RTObject<WSSIBuffer>*)buffer;
- (void)appendStream:(RTObject<WSSIInputStream>*)stream;
- (void)appendStreamMaxSize:(RTObject<WSSIInputStream>*)stream maxSize:(uint64_t)maxSize;
- (void)abort;
- (void)remove:(WFTimeSpan*)start end:(id /* WFTimeSpan* */)end;
@end

#endif // __WMCMseSourceBuffer_DEFINED__

// Windows.Media.Core.HighDynamicRangeControl
#ifndef __WMCHighDynamicRangeControl_DEFINED__
#define __WMCHighDynamicRangeControl_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCHighDynamicRangeControl : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property BOOL enabled;
@end

#endif // __WMCHighDynamicRangeControl_DEFINED__

// Windows.Media.IMediaExtension
#ifndef __WMIMediaExtension_DEFINED__
#define __WMIMediaExtension_DEFINED__

@protocol WMIMediaExtension
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMIMediaExtension : RTObject <WMIMediaExtension>
@end

#endif // __WMIMediaExtension_DEFINED__

// Windows.Media.Core.SceneAnalysisEffect
#ifndef __WMCSceneAnalysisEffect_DEFINED__
#define __WMCSceneAnalysisEffect_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCSceneAnalysisEffect : RTObject <WMIMediaExtension>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* desiredAnalysisInterval;
@property (readonly) WMCHighDynamicRangeControl* highDynamicRangeAnalyzer;
- (EventRegistrationToken)addSceneAnalyzedEvent:(void (^)(WMCSceneAnalysisEffect*, WMCSceneAnalyzedEventArgs*))del;
- (void)removeSceneAnalyzedEvent:(EventRegistrationToken)tok;
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMCSceneAnalysisEffect_DEFINED__

// Windows.Media.Core.SceneAnalyzedEventArgs
#ifndef __WMCSceneAnalyzedEventArgs_DEFINED__
#define __WMCSceneAnalyzedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCSceneAnalyzedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCSceneAnalysisEffectFrame* resultFrame;
@end

#endif // __WMCSceneAnalyzedEventArgs_DEFINED__

// Windows.Media.Core.HighDynamicRangeOutput
#ifndef __WMCHighDynamicRangeOutput_DEFINED__
#define __WMCHighDynamicRangeOutput_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCHighDynamicRangeOutput : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) double certainty;
@property (readonly) NSArray* /* WMDCFrameController* */ frameControllers;
@end

#endif // __WMCHighDynamicRangeOutput_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
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
@property (readonly) NSString* type;
- (void)close;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMIMediaFrame : RTObject <WMIMediaFrame>
@end

#endif // __WMIMediaFrame_DEFINED__

// Windows.Media.Core.SceneAnalysisEffectFrame
#ifndef __WMCSceneAnalysisEffectFrame_DEFINED__
#define __WMCSceneAnalysisEffectFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCSceneAnalysisEffectFrame : RTObject <WMIMediaFrame, WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCCapturedFrameControlValues* frameControlValues;
@property (readonly) WMCHighDynamicRangeOutput* highDynamicRange;
@property (retain) id /* WFTimeSpan* */ systemRelativeTime;
@property (retain) id /* WFTimeSpan* */ relativeTime;
@property BOOL isDiscontinuous;
@property (retain) id /* WFTimeSpan* */ duration;
@property (readonly) RTObject<WFCIPropertySet>* extendedProperties;
@property (readonly) BOOL isReadOnly;
@property (readonly) NSString* type;
- (void)close;
@end

#endif // __WMCSceneAnalysisEffectFrame_DEFINED__

// Windows.Media.Effects.IVideoEffectDefinition
#ifndef __WMEIVideoEffectDefinition_DEFINED__
#define __WMEIVideoEffectDefinition_DEFINED__

@protocol WMEIVideoEffectDefinition
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMEIVideoEffectDefinition : RTObject <WMEIVideoEffectDefinition>
@end

#endif // __WMEIVideoEffectDefinition_DEFINED__

// Windows.Media.Core.SceneAnalysisEffectDefinition
#ifndef __WMCSceneAnalysisEffectDefinition_DEFINED__
#define __WMCSceneAnalysisEffectDefinition_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCSceneAnalysisEffectDefinition : RTObject <WMEIVideoEffectDefinition>
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMCSceneAnalysisEffectDefinition_DEFINED__

// Windows.Media.Core.FaceDetectionEffectFrame
#ifndef __WMCFaceDetectionEffectFrame_DEFINED__
#define __WMCFaceDetectionEffectFrame_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFaceDetectionEffectFrame : RTObject <WMIMediaFrame, WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WMFDetectedFace* */ detectedFaces;
@property (retain) id /* WFTimeSpan* */ systemRelativeTime;
@property (retain) id /* WFTimeSpan* */ relativeTime;
@property BOOL isDiscontinuous;
@property (retain) id /* WFTimeSpan* */ duration;
@property (readonly) RTObject<WFCIPropertySet>* extendedProperties;
@property (readonly) BOOL isReadOnly;
@property (readonly) NSString* type;
- (void)close;
@end

#endif // __WMCFaceDetectionEffectFrame_DEFINED__

// Windows.Media.Core.FaceDetectedEventArgs
#ifndef __WMCFaceDetectedEventArgs_DEFINED__
#define __WMCFaceDetectedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFaceDetectedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCFaceDetectionEffectFrame* resultFrame;
@end

#endif // __WMCFaceDetectedEventArgs_DEFINED__

// Windows.Media.Core.FaceDetectionEffect
#ifndef __WMCFaceDetectionEffect_DEFINED__
#define __WMCFaceDetectionEffect_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFaceDetectionEffect : RTObject <WMIMediaExtension>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property BOOL enabled;
@property (retain) WFTimeSpan* desiredDetectionInterval;
- (EventRegistrationToken)addFaceDetectedEvent:(void (^)(WMCFaceDetectionEffect*, WMCFaceDetectedEventArgs*))del;
- (void)removeFaceDetectedEvent:(EventRegistrationToken)tok;
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMCFaceDetectionEffect_DEFINED__

// Windows.Media.Core.FaceDetectionEffectDefinition
#ifndef __WMCFaceDetectionEffectDefinition_DEFINED__
#define __WMCFaceDetectionEffectDefinition_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCFaceDetectionEffectDefinition : RTObject <WMEIVideoEffectDefinition>
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property BOOL synchronousDetectionEnabled;
@property WMCFaceDetectionMode detectionMode;
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMCFaceDetectionEffectDefinition_DEFINED__

// Windows.Media.Core.VideoStabilizationEffectEnabledChangedEventArgs
#ifndef __WMCVideoStabilizationEffectEnabledChangedEventArgs_DEFINED__
#define __WMCVideoStabilizationEffectEnabledChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCVideoStabilizationEffectEnabledChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCVideoStabilizationEffectEnabledChangedReason reason;
@end

#endif // __WMCVideoStabilizationEffectEnabledChangedEventArgs_DEFINED__

// Windows.Media.Core.VideoStabilizationEffect
#ifndef __WMCVideoStabilizationEffect_DEFINED__
#define __WMCVideoStabilizationEffect_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCVideoStabilizationEffect : RTObject <WMIMediaExtension>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property BOOL enabled;
- (EventRegistrationToken)addEnabledChangedEvent:(void (^)(WMCVideoStabilizationEffect*,
                                                           WMCVideoStabilizationEffectEnabledChangedEventArgs*))del;
- (void)removeEnabledChangedEvent:(EventRegistrationToken)tok;
- (WMCVideoStreamConfiguration*)getRecommendedStreamConfiguration:(WMDVideoDeviceController*)controller
                                                desiredProperties:(WMMVideoEncodingProperties*)desiredProperties;
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMCVideoStabilizationEffect_DEFINED__

// Windows.Media.Core.VideoStabilizationEffectDefinition
#ifndef __WMCVideoStabilizationEffectDefinition_DEFINED__
#define __WMCVideoStabilizationEffectDefinition_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCVideoStabilizationEffectDefinition : RTObject <WMEIVideoEffectDefinition>
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMCVideoStabilizationEffectDefinition_DEFINED__

// Windows.Media.Core.MediaSourceError
#ifndef __WMCMediaSourceError_DEFINED__
#define __WMCMediaSourceError_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaSourceError : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@end

#endif // __WMCMediaSourceError_DEFINED__

// Windows.Media.Playback.IMediaPlaybackSource
#ifndef __WMPIMediaPlaybackSource_DEFINED__
#define __WMPIMediaPlaybackSource_DEFINED__

@protocol WMPIMediaPlaybackSource
@end

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMPIMediaPlaybackSource : RTObject <WMPIMediaPlaybackSource>
@end

#endif // __WMPIMediaPlaybackSource_DEFINED__

// Windows.Media.Core.MediaSource
#ifndef __WMCMediaSource_DEFINED__
#define __WMCMediaSource_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaSource : RTObject <WFIClosable, WMPIMediaPlaybackSource>
+ (WMCMediaSource*)createFromMediaBinder:(WMCMediaBinder*)binder;
+ (WMCMediaSource*)createFromAdaptiveMediaSource:(WMSAAdaptiveMediaSource*)mediaSource;
+ (WMCMediaSource*)createFromMediaStreamSource:(WMCMediaStreamSource*)mediaSource;
+ (WMCMediaSource*)createFromMseStreamSource:(WMCMseStreamSource*)mediaSource;
+ (WMCMediaSource*)createFromIMediaSource:(RTObject<WMCIMediaSource>*)mediaSource;
+ (WMCMediaSource*)createFromStorageFile:(RTObject<WSIStorageFile>*)file;
+ (WMCMediaSource*)createFromStream:(RTObject<WSSIRandomAccessStream>*)stream contentType:(NSString*)contentType;
+ (WMCMediaSource*)createFromStreamReference:(RTObject<WSSIRandomAccessStreamReference>*)stream contentType:(NSString*)contentType;
+ (WMCMediaSource*)createFromUri:(WFUri*)uri;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WFCValueSet* customProperties;
@property (readonly) id /* WFTimeSpan* */ duration;
@property (readonly) NSMutableArray<RTObservableCollection>* /* WMCTimedMetadataTrack* */ externalTimedMetadataTracks;
@property (readonly) NSMutableArray<RTObservableCollection>* /* WMCTimedTextSource* */ externalTimedTextSources;
@property (readonly) BOOL isOpen;
@property (readonly) WMCMediaSourceState state;
- (EventRegistrationToken)addOpenOperationCompletedEvent:(void (^)(WMCMediaSource*, WMCMediaSourceOpenOperationCompletedEventArgs*))del;
- (void)removeOpenOperationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStateChangedEvent:(void (^)(WMCMediaSource*, WMCMediaSourceStateChangedEventArgs*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (void)close;
- (void)reset;
@end

#endif // __WMCMediaSource_DEFINED__

// Windows.Media.Core.MediaBinder
#ifndef __WMCMediaBinder_DEFINED__
#define __WMCMediaBinder_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaBinder : RTObject
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) NSString* token;
@property (readonly) WMCMediaSource* source;
- (EventRegistrationToken)addBindingEvent:(void (^)(WMCMediaBinder*, WMCMediaBindingEventArgs*))del;
- (void)removeBindingEvent:(EventRegistrationToken)tok;
@end

#endif // __WMCMediaBinder_DEFINED__

// Windows.Media.Core.MediaBindingEventArgs
#ifndef __WMCMediaBindingEventArgs_DEFINED__
#define __WMCMediaBindingEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaBindingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaBinder* mediaBinder;
- (EventRegistrationToken)addCanceledEvent:(void (^)(WMCMediaBindingEventArgs*, RTObject*))del;
- (void)removeCanceledEvent:(EventRegistrationToken)tok;
- (WFDeferral*)getDeferral;
- (void)setUri:(WFUri*)uri;
- (void)setStream:(RTObject<WSSIRandomAccessStream>*)stream contentType:(NSString*)contentType;
- (void)setStreamReference:(RTObject<WSSIRandomAccessStreamReference>*)stream contentType:(NSString*)contentType;
@end

#endif // __WMCMediaBindingEventArgs_DEFINED__

// Windows.Media.Core.MediaSourceOpenOperationCompletedEventArgs
#ifndef __WMCMediaSourceOpenOperationCompletedEventArgs_DEFINED__
#define __WMCMediaSourceOpenOperationCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaSourceOpenOperationCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaSourceError* error;
@end

#endif // __WMCMediaSourceOpenOperationCompletedEventArgs_DEFINED__

// Windows.Media.Core.TimedTextSource
#ifndef __WMCTimedTextSource_DEFINED__
#define __WMCTimedTextSource_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextSource : RTObject
+ (WMCTimedTextSource*)createFromStream:(RTObject<WSSIRandomAccessStream>*)stream;
+ (WMCTimedTextSource*)createFromUri:(WFUri*)uri;
+ (WMCTimedTextSource*)createFromStreamWithLanguage:(RTObject<WSSIRandomAccessStream>*)stream defaultLanguage:(NSString*)defaultLanguage;
+ (WMCTimedTextSource*)createFromUriWithLanguage:(WFUri*)uri defaultLanguage:(NSString*)defaultLanguage;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addResolvedEvent:(void (^)(WMCTimedTextSource*, WMCTimedTextSourceResolveResultEventArgs*))del;
- (void)removeResolvedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMCTimedTextSource_DEFINED__

// Windows.Media.Core.TimedMetadataTrack
#ifndef __WMCTimedMetadataTrack_DEFINED__
#define __WMCTimedMetadataTrack_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedMetadataTrack : RTObject <WMCIMediaTrack>
+ (WMCTimedMetadataTrack*)make:(NSString*)id language:(NSString*)language kind:(WMCTimedMetadataKind)kind ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) NSString* label;
@property (readonly) NSString* id;
@property (readonly) NSString* language;
@property (readonly) WMCMediaTrackKind trackKind;
@property (readonly) NSArray* /* RTObject<WMCIMediaCue>* */ activeCues;
@property (readonly) NSArray* /* RTObject<WMCIMediaCue>* */ cues;
@property (readonly) NSString* dispatchType;
@property (readonly) WMCTimedMetadataKind timedMetadataKind;
@property (readonly) NSString* name;
@property (readonly) WMPMediaPlaybackItem* playbackItem;
- (EventRegistrationToken)addCueEnteredEvent:(void (^)(WMCTimedMetadataTrack*, WMCMediaCueEventArgs*))del;
- (void)removeCueEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCueExitedEvent:(void (^)(WMCTimedMetadataTrack*, WMCMediaCueEventArgs*))del;
- (void)removeCueExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTrackFailedEvent:(void (^)(WMCTimedMetadataTrack*, WMCTimedMetadataTrackFailedEventArgs*))del;
- (void)removeTrackFailedEvent:(EventRegistrationToken)tok;
- (void)addCue:(RTObject<WMCIMediaCue>*)cue;
- (void)removeCue:(RTObject<WMCIMediaCue>*)cue;
@end

#endif // __WMCTimedMetadataTrack_DEFINED__

// Windows.Media.Core.MediaSourceStateChangedEventArgs
#ifndef __WMCMediaSourceStateChangedEventArgs_DEFINED__
#define __WMCMediaSourceStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaSourceStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaSourceState newState;
@property (readonly) WMCMediaSourceState oldState;
@end

#endif // __WMCMediaSourceStateChangedEventArgs_DEFINED__

// Windows.Media.Core.TimedTextRegion
#ifndef __WMCTimedTextRegion_DEFINED__
#define __WMCTimedTextRegion_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextRegion : RTObject
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) NSString* name;
@property (retain) WMCTimedTextDouble* lineHeight;
@property BOOL isOverflowClipped;
@property (retain) WMCTimedTextSize* extent;
@property WMCTimedTextDisplayAlignment displayAlignment;
@property (retain) WMCTimedTextPadding* padding;
@property (retain) WUColor* background;
@property int zIndex;
@property WMCTimedTextWritingMode writingMode;
@property WMCTimedTextWrapping textWrapping;
@property WMCTimedTextScrollMode scrollMode;
@property (retain) WMCTimedTextPoint* position;
@end

#endif // __WMCTimedTextRegion_DEFINED__

// Windows.Media.Core.TimedTextStyle
#ifndef __WMCTimedTextStyle_DEFINED__
#define __WMCTimedTextStyle_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextStyle : RTObject
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) WUColor* foreground;
@property WMCTimedTextWeight fontWeight;
@property (retain) WMCTimedTextDouble* fontSize;
@property (retain) NSString* fontFamily;
@property WMCTimedTextFlowDirection flowDirection;
@property BOOL isBackgroundAlwaysShown;
@property (retain) WUColor* background;
@property (retain) WMCTimedTextDouble* outlineThickness;
@property (retain) WMCTimedTextDouble* outlineRadius;
@property (retain) WUColor* outlineColor;
@property (retain) NSString* name;
@property WMCTimedTextLineAlignment lineAlignment;
@end

#endif // __WMCTimedTextStyle_DEFINED__

// Windows.Media.Core.TimedTextLine
#ifndef __WMCTimedTextLine_DEFINED__
#define __WMCTimedTextLine_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextLine : RTObject
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) NSString* text;
@property (readonly) NSMutableArray* /* WMCTimedTextSubformat* */ subformats;
@end

#endif // __WMCTimedTextLine_DEFINED__

// Windows.Media.Core.TimedTextSubformat
#ifndef __WMCTimedTextSubformat_DEFINED__
#define __WMCTimedTextSubformat_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextSubformat : RTObject
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) WMCTimedTextStyle* subformatStyle;
@property int startIndex;
@property int length;
@end

#endif // __WMCTimedTextSubformat_DEFINED__

// Windows.Media.Core.TimedMetadataTrackError
#ifndef __WMCTimedMetadataTrackError_DEFINED__
#define __WMCTimedMetadataTrackError_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedMetadataTrackError : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCTimedMetadataTrackErrorCode errorCode;
@property (readonly) HRESULT extendedError;
@end

#endif // __WMCTimedMetadataTrackError_DEFINED__

// Windows.Media.Core.MediaCueEventArgs
#ifndef __WMCMediaCueEventArgs_DEFINED__
#define __WMCMediaCueEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCMediaCueEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WMCIMediaCue>* cue;
@end

#endif // __WMCMediaCueEventArgs_DEFINED__

// Windows.Media.Core.TimedMetadataTrackFailedEventArgs
#ifndef __WMCTimedMetadataTrackFailedEventArgs_DEFINED__
#define __WMCTimedMetadataTrackFailedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedMetadataTrackFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCTimedMetadataTrackError* error;
@end

#endif // __WMCTimedMetadataTrackFailedEventArgs_DEFINED__

// Windows.Media.Core.TimedTextSourceResolveResultEventArgs
#ifndef __WMCTimedTextSourceResolveResultEventArgs_DEFINED__
#define __WMCTimedTextSourceResolveResultEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextSourceResolveResultEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCTimedMetadataTrackError* error;
@property (readonly) NSArray* /* WMCTimedMetadataTrack* */ tracks;
@end

#endif // __WMCTimedTextSourceResolveResultEventArgs_DEFINED__

// Windows.Media.Core.VideoTrack
#ifndef __WMCVideoTrack_DEFINED__
#define __WMCVideoTrack_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCVideoTrack : RTObject <WMCIMediaTrack>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) NSString* label;
@property (readonly) NSString* id;
@property (readonly) NSString* language;
@property (readonly) WMCMediaTrackKind trackKind;
@property (readonly) NSString* name;
@property (readonly) WMPMediaPlaybackItem* playbackItem;
@property (readonly) WMCVideoTrackSupportInfo* supportInfo;
- (EventRegistrationToken)addOpenFailedEvent:(void (^)(WMCVideoTrack*, WMCVideoTrackOpenFailedEventArgs*))del;
- (void)removeOpenFailedEvent:(EventRegistrationToken)tok;
- (WMMVideoEncodingProperties*)getEncodingProperties;
@end

#endif // __WMCVideoTrack_DEFINED__

// Windows.Media.Core.VideoTrackOpenFailedEventArgs
#ifndef __WMCVideoTrackOpenFailedEventArgs_DEFINED__
#define __WMCVideoTrackOpenFailedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCVideoTrackOpenFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@end

#endif // __WMCVideoTrackOpenFailedEventArgs_DEFINED__

// Windows.Media.Core.VideoTrackSupportInfo
#ifndef __WMCVideoTrackSupportInfo_DEFINED__
#define __WMCVideoTrackSupportInfo_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCVideoTrackSupportInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaDecoderStatus decoderStatus;
@property (readonly) WMCMediaSourceStatus mediaSourceStatus;
@end

#endif // __WMCVideoTrackSupportInfo_DEFINED__

// Windows.Media.Core.AudioTrack
#ifndef __WMCAudioTrack_DEFINED__
#define __WMCAudioTrack_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAudioTrack : RTObject <WMCIMediaTrack>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSString* name;
@property (readonly) WMPMediaPlaybackItem* playbackItem;
@property (readonly) WMCAudioTrackSupportInfo* supportInfo;
@property (retain) NSString* label;
@property (readonly) NSString* id;
@property (readonly) NSString* language;
@property (readonly) WMCMediaTrackKind trackKind;
- (EventRegistrationToken)addOpenFailedEvent:(void (^)(WMCAudioTrack*, WMCAudioTrackOpenFailedEventArgs*))del;
- (void)removeOpenFailedEvent:(EventRegistrationToken)tok;
- (WMMAudioEncodingProperties*)getEncodingProperties;
@end

#endif // __WMCAudioTrack_DEFINED__

// Windows.Media.Core.AudioTrackOpenFailedEventArgs
#ifndef __WMCAudioTrackOpenFailedEventArgs_DEFINED__
#define __WMCAudioTrackOpenFailedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAudioTrackOpenFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@end

#endif // __WMCAudioTrackOpenFailedEventArgs_DEFINED__

// Windows.Media.Core.AudioTrackSupportInfo
#ifndef __WMCAudioTrackSupportInfo_DEFINED__
#define __WMCAudioTrackSupportInfo_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCAudioTrackSupportInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WMCMediaDecoderStatus decoderStatus;
@property (readonly) WMCAudioDecoderDegradation degradation;
@property (readonly) WMCAudioDecoderDegradationReason degradationReason;
@property (readonly) WMCMediaSourceStatus mediaSourceStatus;
@end

#endif // __WMCAudioTrackSupportInfo_DEFINED__

// Windows.Media.Core.TimedTextCue
#ifndef __WMCTimedTextCue_DEFINED__
#define __WMCTimedTextCue_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCTimedTextCue : RTObject <WMCIMediaCue>
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* startTime;
@property (retain) NSString* id;
@property (retain) WFTimeSpan* duration;
@property (retain) WMCTimedTextStyle* cueStyle;
@property (retain) WMCTimedTextRegion* cueRegion;
@property (readonly) NSMutableArray* /* WMCTimedTextLine* */ lines;
@end

#endif // __WMCTimedTextCue_DEFINED__

// Windows.Media.Core.DataCue
#ifndef __WMCDataCue_DEFINED__
#define __WMCDataCue_DEFINED__

OBJCUWPWINDOWSMEDIACAPTUREDEVICESCOREPLAYBACKPROTECTIONEXPORT
@interface WMCDataCue : RTObject <WMCIMediaCue>
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) RTObject<WSSIBuffer>* data;
@property (retain) WFTimeSpan* startTime;
@property (retain) NSString* id;
@property (retain) WFTimeSpan* duration;
@end

#endif // __WMCDataCue_DEFINED__
