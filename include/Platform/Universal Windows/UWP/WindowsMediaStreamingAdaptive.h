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

// WindowsMediaStreamingAdaptive.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMSAAdaptiveMediaSource, WMSAAdaptiveMediaSourceCreationResult, WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs,
    WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs, WMSAAdaptiveMediaSourceDownloadRequestedEventArgs,
    WMSAAdaptiveMediaSourceDownloadCompletedEventArgs, WMSAAdaptiveMediaSourceDownloadFailedEventArgs,
    WMSAAdaptiveMediaSourceDownloadResult, WMSAAdaptiveMediaSourceDownloadRequestedDeferral;
@protocol WMSAIAdaptiveMediaSourceCreationResult
, WMSAIAdaptiveMediaSourceStatics, WMSAIAdaptiveMediaSource, WMSAIAdaptiveMediaSourceDownloadBitrateChangedEventArgs,
    WMSAIAdaptiveMediaSourcePlaybackBitrateChangedEventArgs, WMSAIAdaptiveMediaSourceDownloadRequestedEventArgs,
    WMSAIAdaptiveMediaSourceDownloadResult, WMSAIAdaptiveMediaSourceDownloadRequestedDeferral,
    WMSAIAdaptiveMediaSourceDownloadCompletedEventArgs, WMSAIAdaptiveMediaSourceDownloadFailedEventArgs;

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

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceResourceType
enum _WMSAAdaptiveMediaSourceResourceType {
    WMSAAdaptiveMediaSourceResourceTypeManifest = 0,
    WMSAAdaptiveMediaSourceResourceTypeInitializationSegment = 1,
    WMSAAdaptiveMediaSourceResourceTypeMediaSegment = 2,
    WMSAAdaptiveMediaSourceResourceTypeKey = 3,
    WMSAAdaptiveMediaSourceResourceTypeInitializationVector = 4,
};
typedef unsigned WMSAAdaptiveMediaSourceResourceType;

#include "WindowsWebHttp.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsMediaCore.h"

#import <Foundation/Foundation.h>

// Windows.Media.Core.IMediaSource
#ifndef __WMCIMediaSource_DEFINED__
#define __WMCIMediaSource_DEFINED__

@protocol WMCIMediaSource
@end

#endif // __WMCIMediaSource_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSource
#ifndef __WMSAAdaptiveMediaSource_DEFINED__
#define __WMSAAdaptiveMediaSource_DEFINED__

WINRT_EXPORT
@interface WMSAAdaptiveMediaSource : RTObject <WMCIMediaSource>
+ (BOOL)isContentTypeSupported:(NSString*)contentType;
+ (void)createFromUriAsync:(WFUri*)uri
                   success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success
                   failure:(void (^)(NSError*))failure;
+ (void)createFromUriWithDownloaderAsync:(WFUri*)uri
                              httpClient:(WWHHttpClient*)httpClient
                                 success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success
                                 failure:(void (^)(NSError*))failure;
+ (void)createFromStreamAsync:(RTObject<WSSIInputStream>*)stream
                          uri:(WFUri*)uri
                  contentType:(NSString*)contentType
                      success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success
                      failure:(void (^)(NSError*))failure;
+ (void)createFromStreamWithDownloaderAsync:(RTObject<WSSIInputStream>*)stream
                                        uri:(WFUri*)uri
                                contentType:(NSString*)contentType
                                 httpClient:(WWHHttpClient*)httpClient
                                    success:(void (^)(WMSAAdaptiveMediaSourceCreationResult*))success
                                    failure:(void (^)(NSError*))failure;
@property unsigned int initialBitrate;
@property (copy) WFTimeSpan* inboundBitsPerSecondWindow;
@property (copy) id desiredMinBitrate;
@property (copy) WFTimeSpan* desiredLiveOffset;
@property (copy) id desiredMaxBitrate;
@property (readonly) BOOL audioOnlyPlayback;
@property (readonly) NSArray* availableBitrates;
@property (readonly) uint64_t inboundBitsPerSecond;
@property (readonly) unsigned int currentDownloadBitrate;
@property (readonly) unsigned int currentPlaybackBitrate;
@property (readonly) BOOL isLive;
- (EventRegistrationToken)addDownloadBitrateChangedEvent:(void (^)(WMSAAdaptiveMediaSource*,
                                                                   WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs*))del;
- (void)removeDownloadBitrateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadCompletedEvent:(void (^)(WMSAAdaptiveMediaSource*,
                                                              WMSAAdaptiveMediaSourceDownloadCompletedEventArgs*))del;
- (void)removeDownloadCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadFailedEvent:(void (^)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadFailedEventArgs*))del;
- (void)removeDownloadFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadRequestedEvent:(void (^)(WMSAAdaptiveMediaSource*,
                                                              WMSAAdaptiveMediaSourceDownloadRequestedEventArgs*))del;
- (void)removeDownloadRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPlaybackBitrateChangedEvent:(void (^)(WMSAAdaptiveMediaSource*,
                                                                   WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs*))del;
- (void)removePlaybackBitrateChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMSAAdaptiveMediaSource_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceCreationResult
#ifndef __WMSAAdaptiveMediaSourceCreationResult_DEFINED__
#define __WMSAAdaptiveMediaSourceCreationResult_DEFINED__

WINRT_EXPORT
@interface WMSAAdaptiveMediaSourceCreationResult : RTObject
@property (readonly) WWHHttpResponseMessage* httpResponseMessage;
@property (readonly) WMSAAdaptiveMediaSource* mediaSource;
@property (readonly) WMSAAdaptiveMediaSourceCreationStatus status;
@end

#endif // __WMSAAdaptiveMediaSourceCreationResult_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadBitrateChangedEventArgs
#ifndef __WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs : RTObject
@property (readonly) unsigned int newValue;
@property (readonly) unsigned int oldValue;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourcePlaybackBitrateChangedEventArgs
#ifndef __WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs : RTObject
@property (readonly) BOOL audioOnly;
@property (readonly) unsigned int newValue;
@property (readonly) unsigned int oldValue;
@end

#endif // __WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadRequestedEventArgs
#ifndef __WMSAAdaptiveMediaSourceDownloadRequestedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSAAdaptiveMediaSourceDownloadRequestedEventArgs : RTObject
@property (readonly) id resourceByteRangeLength;
@property (readonly) id resourceByteRangeOffset;
@property (readonly) WMSAAdaptiveMediaSourceResourceType resourceType;
@property (readonly) WFUri* resourceUri;
@property (readonly) WMSAAdaptiveMediaSourceDownloadResult* result;
- (WMSAAdaptiveMediaSourceDownloadRequestedDeferral*)getDeferral;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadRequestedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadCompletedEventArgs
#ifndef __WMSAAdaptiveMediaSourceDownloadCompletedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSAAdaptiveMediaSourceDownloadCompletedEventArgs : RTObject
@property (readonly) WWHHttpResponseMessage* httpResponseMessage;
@property (readonly) id resourceByteRangeLength;
@property (readonly) id resourceByteRangeOffset;
@property (readonly) WMSAAdaptiveMediaSourceResourceType resourceType;
@property (readonly) WFUri* resourceUri;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadCompletedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadFailedEventArgs
#ifndef __WMSAAdaptiveMediaSourceDownloadFailedEventArgs_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadFailedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSAAdaptiveMediaSourceDownloadFailedEventArgs : RTObject
@property (readonly) WWHHttpResponseMessage* httpResponseMessage;
@property (readonly) id resourceByteRangeLength;
@property (readonly) id resourceByteRangeOffset;
@property (readonly) WMSAAdaptiveMediaSourceResourceType resourceType;
@property (readonly) WFUri* resourceUri;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadFailedEventArgs_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadResult
#ifndef __WMSAAdaptiveMediaSourceDownloadResult_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadResult_DEFINED__

WINRT_EXPORT
@interface WMSAAdaptiveMediaSourceDownloadResult : RTObject
@property (copy) WFUri* resourceUri;
@property (copy) RTObject<WSSIInputStream>* inputStream;
@property unsigned int extendedStatus;
@property (copy) NSString* contentType;
@property (copy) RTObject<WSSIBuffer>* buffer;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadResult_DEFINED__

// Windows.Media.Streaming.Adaptive.AdaptiveMediaSourceDownloadRequestedDeferral
#ifndef __WMSAAdaptiveMediaSourceDownloadRequestedDeferral_DEFINED__
#define __WMSAAdaptiveMediaSourceDownloadRequestedDeferral_DEFINED__

WINRT_EXPORT
@interface WMSAAdaptiveMediaSourceDownloadRequestedDeferral : RTObject
- (void)complete;
@end

#endif // __WMSAAdaptiveMediaSourceDownloadRequestedDeferral_DEFINED__
