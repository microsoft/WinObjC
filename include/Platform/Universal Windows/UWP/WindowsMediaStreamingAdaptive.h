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

// WindowsMediaStreamingAdaptive.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
#define OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaStreamingAdaptive.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMSAAdaptiveMediaSource, WMSAAdaptiveMediaSourceCreationResult, WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs, WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs, WMSAAdaptiveMediaSourceDownloadRequestedEventArgs, WMSAAdaptiveMediaSourceDownloadCompletedEventArgs, WMSAAdaptiveMediaSourceDownloadFailedEventArgs, WMSAAdaptiveMediaSourceAdvancedSettings, WMSAAdaptiveMediaSourceDiagnostics, WMSAAdaptiveMediaSourceCorrelatedTimes, WMSAAdaptiveMediaSourceDownloadResult, WMSAAdaptiveMediaSourceDownloadRequestedDeferral, WMSAAdaptiveMediaSourceDownloadStatistics, WMSAAdaptiveMediaSourceDiagnosticAvailableEventArgs;
@protocol WMSAIAdaptiveMediaSourceCreationResult, WMSAIAdaptiveMediaSourceCreationResult2, WMSAIAdaptiveMediaSourceStatics, WMSAIAdaptiveMediaSource, WMSAIAdaptiveMediaSource2, WMSAIAdaptiveMediaSource3, WMSAIAdaptiveMediaSourceAdvancedSettings, WMSAIAdaptiveMediaSourceCorrelatedTimes, WMSAIAdaptiveMediaSourceDownloadBitrateChangedEventArgs, WMSAIAdaptiveMediaSourceDownloadBitrateChangedEventArgs2, WMSAIAdaptiveMediaSourcePlaybackBitrateChangedEventArgs, WMSAIAdaptiveMediaSourceDownloadRequestedEventArgs, WMSAIAdaptiveMediaSourceDownloadRequestedEventArgs2, WMSAIAdaptiveMediaSourceDownloadResult, WMSAIAdaptiveMediaSourceDownloadResult2, WMSAIAdaptiveMediaSourceDownloadRequestedDeferral, WMSAIAdaptiveMediaSourceDownloadCompletedEventArgs, WMSAIAdaptiveMediaSourceDownloadStatistics, WMSAIAdaptiveMediaSourceDownloadCompletedEventArgs2, WMSAIAdaptiveMediaSourceDownloadFailedEventArgs, WMSAIAdaptiveMediaSourceDownloadFailedEventArgs2, WMSAIAdaptiveMediaSourceDiagnosticAvailableEventArgs, WMSAIAdaptiveMediaSourceDiagnosticAvailableEventArgs2, WMSAIAdaptiveMediaSourceDiagnostics;

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceCreationStatus
enum _WMSAAdaptiveMediaSourceCreationStatus {
    WMSAAdaptiveMediaSourceCreationStatusSuccess = 0,
    WMSAAdaptiveMediaSourceCreationStatusManifestDownloadFailure = 1,
    WMSAAdaptiveMediaSourceCreationStatusManifestParseFailure = 2,
    WMSAAdaptiveMediaSourceCreationStatusUnsupportedManifestContentType = 3,
    WMSAAdaptiveMediaSourceCreationStatusUnsupportedManifestVersion = 4,
    WMSAAdaptiveMediaSourceCreationStatusUnsupportedManifestProfile = 5,
    WMSAAdaptiveMediaSourceCreationStatusUnknownFailure = 6,
};
typedef unsigned WMSAAdaptiveMediaSourceCreationStatus;

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadBitrateChangedReason
enum _WMSAAdaptiveMediaSourceDownloadBitrateChangedReason {
    WMSAAdaptiveMediaSourceDownloadBitrateChangedReasonSufficientInboundBitsPerSecond = 0,
    WMSAAdaptiveMediaSourceDownloadBitrateChangedReasonInsufficientInboundBitsPerSecond = 1,
    WMSAAdaptiveMediaSourceDownloadBitrateChangedReasonLowBufferLevel = 2,
    WMSAAdaptiveMediaSourceDownloadBitrateChangedReasonPositionChanged = 3,
    WMSAAdaptiveMediaSourceDownloadBitrateChangedReasonTrackSelectionChanged = 4,
    WMSAAdaptiveMediaSourceDownloadBitrateChangedReasonDesiredBitratesChanged = 5,
    WMSAAdaptiveMediaSourceDownloadBitrateChangedReasonErrorInPreviousBitrate = 6,
};
typedef unsigned WMSAAdaptiveMediaSourceDownloadBitrateChangedReason;

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceResourceType
enum _WMSAAdaptiveMediaSourceResourceType {
    WMSAAdaptiveMediaSourceResourceTypeManifest = 0,
    WMSAAdaptiveMediaSourceResourceTypeInitializationSegment = 1,
    WMSAAdaptiveMediaSourceResourceTypeMediaSegment = 2,
    WMSAAdaptiveMediaSourceResourceTypeKey = 3,
    WMSAAdaptiveMediaSourceResourceTypeInitializationVector = 4,
};
typedef unsigned WMSAAdaptiveMediaSourceResourceType;

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDiagnosticType
enum _WMSAAdaptiveMediaSourceDiagnosticType {
    WMSAAdaptiveMediaSourceDiagnosticTypeManifestUnchangedUponReload = 0,
    WMSAAdaptiveMediaSourceDiagnosticTypeManifestMismatchUponReload = 1,
    WMSAAdaptiveMediaSourceDiagnosticTypeManifestSignaledEndOfLiveEventUponReload = 2,
    WMSAAdaptiveMediaSourceDiagnosticTypeMediaSegmentSkipped = 3,
    WMSAAdaptiveMediaSourceDiagnosticTypeResourceNotFound = 4,
    WMSAAdaptiveMediaSourceDiagnosticTypeResourceTimedOut = 5,
    WMSAAdaptiveMediaSourceDiagnosticTypeResourceParsingError = 6,
    WMSAAdaptiveMediaSourceDiagnosticTypeBitrateDisabled = 7,
    WMSAAdaptiveMediaSourceDiagnosticTypeFatalMediaSourceError = 8,
};
typedef unsigned WMSAAdaptiveMediaSourceDiagnosticType;

#include "WindowsWebHttp.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsMediaCore.h"

#import <Foundation/Foundation.h>

// Windows.Media.Core.IMediaSource
#ifndef __WMCIMediaSource_DEFINED__
#define __WMCIMediaSource_DEFINED__

@protocol WMCIMediaSource
@end

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMCIMediaSource : RTObject <WMCIMediaSource>
@end

#endif // __WMCIMediaSource_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSource
#ifndef __WMSAAdaptiveMediaSource_DEFINED__
#define __WMSAAdaptiveMediaSource_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSource : RTObject <WMCIMediaSource, WFIClosable>
+ (BOOL)isContentTypeSupported:(NSString *)contentType;
+ (void)createFromUriAsync:(WFUri*)uri success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success failure:(void (^)(NSError*))failure;
+ (void)createFromUriWithDownloaderAsync:(WFUri*)uri httpClient:(WWHHttpClient*)httpClient success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success failure:(void (^)(NSError*))failure;
+ (void)createFromStreamAsync:(RTObject<WSSIInputStream>*)stream uri:(WFUri*)uri contentType:(NSString *)contentType success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success failure:(void (^)(NSError*))failure;
+ (void)createFromStreamWithDownloaderAsync:(RTObject<WSSIInputStream>*)stream uri:(WFUri*)uri contentType:(NSString *)contentType httpClient:(WWHHttpClient*)httpClient success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int initialBitrate;
@property (retain) WFTimeSpan* inboundBitsPerSecondWindow;
@property (retain) id /* unsigned int */ desiredMaxBitrate;
@property (retain) WFTimeSpan* desiredLiveOffset;
@property (retain) id /* unsigned int */ desiredMinBitrate;
@property (readonly) unsigned int currentPlaybackBitrate;
@property (readonly) BOOL audioOnlyPlayback;
@property (readonly) uint64_t inboundBitsPerSecond;
@property (readonly) NSArray* /* unsigned int */ availableBitrates;
@property (readonly) unsigned int currentDownloadBitrate;
@property (readonly) BOOL isLive;
@property (readonly) WMSAAdaptiveMediaSourceAdvancedSettings* advancedSettings;
@property (retain) id /* WFTimeSpan* */ desiredSeekableWindowSize;
@property (readonly) WMSAAdaptiveMediaSourceDiagnostics* diagnostics;
@property (readonly) id /* WFTimeSpan* */ maxSeekableWindowSize;
@property (readonly) id /* WFTimeSpan* */ minLiveOffset;
- (EventRegistrationToken)addDownloadBitrateChangedEvent:(void(^)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs*))del;
- (void)removeDownloadBitrateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadCompletedEvent:(void(^)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadCompletedEventArgs*))del;
- (void)removeDownloadCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadFailedEvent:(void(^)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadFailedEventArgs*))del;
- (void)removeDownloadFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadRequestedEvent:(void(^)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadRequestedEventArgs*))del;
- (void)removeDownloadRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackBitrateChangedEvent:(void(^)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs*))del;
- (void)removePlaybackBitrateChangedEvent:(EventRegistrationToken)tok;
- (WMSAAdaptiveMediaSourceCorrelatedTimes*)getCorrelatedTimes;
- (void)close;
@end

#endif // __WMSAAdaptiveMediaSource_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceCreationResult
#ifndef __WMSAAdaptiveMediaSourceCreationResult_DEFINED__
#define __WMSAAdaptiveMediaSourceCreationResult_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceCreationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WWHHttpResponseMessage* httpResponseMessage;
@property (readonly) WMSAAdaptiveMediaSource* mediaSource;
@property (readonly) WMSAAdaptiveMediaSourceCreationStatus status;
@property (readonly) HRESULT extendedError;
@end

#endif // __WMSAAdaptiveMediaSourceCreationResult_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadBitrateChangedEventArgs
#ifndef __WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int newValue;
@property (readonly) unsigned int oldValue;
@property (readonly) WMSAAdaptiveMediaSourceDownloadBitrateChangedReason reason;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourcePlaybackBitrateChangedEventArgs
#ifndef __WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL audioOnly;
@property (readonly) unsigned int newValue;
@property (readonly) unsigned int oldValue;
@end

#endif // __WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadRequestedEventArgs
#ifndef __WMSAAdaptiveMediaSourceDownloadRequestedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceDownloadRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* uint64_t */ resourceByteRangeLength;
@property (readonly) id /* uint64_t */ resourceByteRangeOffset;
@property (readonly) WMSAAdaptiveMediaSourceResourceType resourceType;
@property (readonly) WFUri* resourceUri;
@property (readonly) WMSAAdaptiveMediaSourceDownloadResult* result;
@property (readonly) id /* WFTimeSpan* */ position;
@property (readonly) int requestId;
- (WMSAAdaptiveMediaSourceDownloadRequestedDeferral*)getDeferral;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadRequestedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadCompletedEventArgs
#ifndef __WMSAAdaptiveMediaSourceDownloadCompletedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceDownloadCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WWHHttpResponseMessage* httpResponseMessage;
@property (readonly) id /* uint64_t */ resourceByteRangeLength;
@property (readonly) id /* uint64_t */ resourceByteRangeOffset;
@property (readonly) WMSAAdaptiveMediaSourceResourceType resourceType;
@property (readonly) WFUri* resourceUri;
@property (readonly) id /* WFTimeSpan* */ position;
@property (readonly) int requestId;
@property (readonly) WMSAAdaptiveMediaSourceDownloadStatistics* statistics;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadCompletedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadFailedEventArgs
#ifndef __WMSAAdaptiveMediaSourceDownloadFailedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadFailedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceDownloadFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WWHHttpResponseMessage* httpResponseMessage;
@property (readonly) id /* uint64_t */ resourceByteRangeLength;
@property (readonly) id /* uint64_t */ resourceByteRangeOffset;
@property (readonly) WMSAAdaptiveMediaSourceResourceType resourceType;
@property (readonly) WFUri* resourceUri;
@property (readonly) HRESULT extendedError;
@property (readonly) id /* WFTimeSpan* */ position;
@property (readonly) int requestId;
@property (readonly) WMSAAdaptiveMediaSourceDownloadStatistics* statistics;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadFailedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceAdvancedSettings
#ifndef __WMSAAdaptiveMediaSourceAdvancedSettings_DEFINED__
#define __WMSAAdaptiveMediaSourceAdvancedSettings_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceAdvancedSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* double */ desiredBitrateHeadroomRatio;
@property (retain) id /* double */ bitrateDowngradeTriggerRatio;
@property BOOL allSegmentsIndependent;
@end

#endif // __WMSAAdaptiveMediaSourceAdvancedSettings_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDiagnostics
#ifndef __WMSAAdaptiveMediaSourceDiagnostics_DEFINED__
#define __WMSAAdaptiveMediaSourceDiagnostics_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceDiagnostics : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addDiagnosticAvailableEvent:(void(^)(WMSAAdaptiveMediaSourceDiagnostics*, WMSAAdaptiveMediaSourceDiagnosticAvailableEventArgs*))del;
- (void)removeDiagnosticAvailableEvent:(EventRegistrationToken)tok;
@end

#endif // __WMSAAdaptiveMediaSourceDiagnostics_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceCorrelatedTimes
#ifndef __WMSAAdaptiveMediaSourceCorrelatedTimes_DEFINED__
#define __WMSAAdaptiveMediaSourceCorrelatedTimes_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceCorrelatedTimes : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* WFTimeSpan* */ position;
@property (readonly) id /* WFTimeSpan* */ presentationTimeStamp;
@property (readonly) id /* WFDateTime* */ programDateTime;
@end

#endif // __WMSAAdaptiveMediaSourceCorrelatedTimes_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadResult
#ifndef __WMSAAdaptiveMediaSourceDownloadResult_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadResult_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceDownloadResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* resourceUri;
@property (retain) RTObject<WSSIInputStream>* inputStream;
@property unsigned int extendedStatus;
@property (retain) NSString * contentType;
@property (retain) RTObject<WSSIBuffer>* buffer;
@property (retain) id /* uint64_t */ resourceByteRangeOffset;
@property (retain) id /* uint64_t */ resourceByteRangeLength;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadResult_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadRequestedDeferral
#ifndef __WMSAAdaptiveMediaSourceDownloadRequestedDeferral_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadRequestedDeferral_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceDownloadRequestedDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadRequestedDeferral_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadStatistics
#ifndef __WMSAAdaptiveMediaSourceDownloadStatistics_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadStatistics_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceDownloadStatistics : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t contentBytesReceivedCount;
@property (readonly) id /* WFTimeSpan* */ timeToFirstByteReceived;
@property (readonly) id /* WFTimeSpan* */ timeToHeadersReceived;
@property (readonly) id /* WFTimeSpan* */ timeToLastByteReceived;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadStatistics_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDiagnosticAvailableEventArgs
#ifndef __WMSAAdaptiveMediaSourceDiagnosticAvailableEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourceDiagnosticAvailableEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIASTREAMINGADAPTIVEEXPORT
@interface WMSAAdaptiveMediaSourceDiagnosticAvailableEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* unsigned int */ bitrate;
@property (readonly) WMSAAdaptiveMediaSourceDiagnosticType diagnosticType;
@property (readonly) id /* WFTimeSpan* */ position;
@property (readonly) id /* int */ requestId;
@property (readonly) id /* uint64_t */ resourceByteRangeLength;
@property (readonly) id /* uint64_t */ resourceByteRangeOffset;
@property (readonly) id /* WMSAAdaptiveMediaSourceResourceType */ resourceType;
@property (readonly) WFUri* resourceUri;
@property (readonly) id /* uint64_t */ segmentId;
@property (readonly) HRESULT extendedError;
@end

#endif // __WMSAAdaptiveMediaSourceDiagnosticAvailableEventArgs_DEFINED__

