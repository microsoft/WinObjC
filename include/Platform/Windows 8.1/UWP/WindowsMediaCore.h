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

// WindowsMediaCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMCAudioStreamDescriptor, WMCVideoStreamDescriptor, WMCMediaStreamSource, WMCMediaStreamSourceClosedEventArgs,
    WMCMediaStreamSourceStartingEventArgs, WMCMediaStreamSourceSampleRequestedEventArgs,
    WMCMediaStreamSourceSwitchStreamsRequestedEventArgs, WMCMediaStreamSamplePropertySet, WMCMediaStreamSample,
    WMCMediaStreamSampleProtectionProperties, WMCMediaStreamSourceClosedRequest, WMCMediaStreamSourceStartingRequestDeferral,
    WMCMediaStreamSourceStartingRequest, WMCMediaStreamSourceSampleRequestDeferral, WMCMediaStreamSourceSampleRequest,
    WMCMediaStreamSourceSwitchStreamsRequestDeferral, WMCMediaStreamSourceSwitchStreamsRequest;
@protocol WMCIMediaStreamDescriptor
, WMCIAudioStreamDescriptor, WMCIAudioStreamDescriptorFactory, WMCIVideoStreamDescriptor, WMCIVideoStreamDescriptorFactory, WMCIMediaSource,
    WMCIMediaStreamSource, WMCIMediaStreamSourceFactory, WMCIMediaStreamSample, WMCIMediaStreamSampleStatics,
    WMCIMediaStreamSampleProtectionProperties, WMCIMediaStreamSourceClosedRequest, WMCIMediaStreamSourceClosedEventArgs,
    WMCIMediaStreamSourceStartingRequestDeferral, WMCIMediaStreamSourceStartingRequest, WMCIMediaStreamSourceStartingEventArgs,
    WMCIMediaStreamSourceSampleRequestDeferral, WMCIMediaStreamSourceSampleRequest, WMCIMediaStreamSourceSampleRequestedEventArgs,
    WMCIMediaStreamSourceSwitchStreamsRequestDeferral, WMCIMediaStreamSourceSwitchStreamsRequest,
    WMCIMediaStreamSourceSwitchStreamsRequestedEventArgs;

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

#include "WindowsMediaProtection.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsStorageFileProperties.h"

// Windows.Media.Core.IMediaStreamDescriptor
#ifndef __WMCIMediaStreamDescriptor_DEFINED__
#define __WMCIMediaStreamDescriptor_DEFINED__

@protocol WMCIMediaStreamDescriptor
@property (readonly) BOOL isSelected;
@property (copy) NSString* language;
@property (copy) NSString* name;
@end

#endif // __WMCIMediaStreamDescriptor_DEFINED__

// Windows.Media.Core.IMediaSource
#ifndef __WMCIMediaSource_DEFINED__
#define __WMCIMediaSource_DEFINED__

@protocol WMCIMediaSource
@end

#endif // __WMCIMediaSource_DEFINED__

// Windows.Media.Core.AudioStreamDescriptor
#ifndef __WMCAudioStreamDescriptor_DEFINED__
#define __WMCAudioStreamDescriptor_DEFINED__

WINRT_EXPORT
@interface WMCAudioStreamDescriptor : RTObject <WMCIMediaStreamDescriptor>
+ (WMCAudioStreamDescriptor*)create:(WMMAudioEncodingProperties*)encodingProperties ACTIVATOR;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
@property (copy) NSString* name;
@property (copy) NSString* language;
@property (readonly) BOOL isSelected;
@end

#endif // __WMCAudioStreamDescriptor_DEFINED__

// Windows.Media.Core.VideoStreamDescriptor
#ifndef __WMCVideoStreamDescriptor_DEFINED__
#define __WMCVideoStreamDescriptor_DEFINED__

WINRT_EXPORT
@interface WMCVideoStreamDescriptor : RTObject <WMCIMediaStreamDescriptor>
+ (WMCVideoStreamDescriptor*)create:(WMMVideoEncodingProperties*)encodingProperties ACTIVATOR;
@property (readonly) WMMVideoEncodingProperties* encodingProperties;
@property (copy) NSString* name;
@property (copy) NSString* language;
@property (readonly) BOOL isSelected;
@end

#endif // __WMCVideoStreamDescriptor_DEFINED__

// Windows.Media.Core.MediaStreamSource
#ifndef __WMCMediaStreamSource_DEFINED__
#define __WMCMediaStreamSource_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSource : RTObject <WMCIMediaSource>
+ (WMCMediaStreamSource*)createFromDescriptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor ACTIVATOR;
+ (WMCMediaStreamSource*)createFromDescriptors:(RTObject<WMCIMediaStreamDescriptor>*)descriptor
                                   descriptor2:(RTObject<WMCIMediaStreamDescriptor>*)descriptor2 ACTIVATOR;
@property (copy) RTObject<WSSIRandomAccessStreamReference>* thumbnail;
@property (copy) WMPMediaProtectionManager* mediaProtectionManager;
@property (copy) WFTimeSpan* duration;
@property BOOL canSeek;
@property (copy) WFTimeSpan* bufferTime;
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
- (void)notifyError:(WMCMediaStreamSourceErrorStatus)errorStatus;
- (void)addStreamDescriptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor;
- (void)setBufferedRange:(WFTimeSpan*)startOffset endOffset:(WFTimeSpan*)endOffset;
- (void)addProtectionKey:(RTObject<WMCIMediaStreamDescriptor>*)streamDescriptor
           keyIdentifier:(id<NSFastEnumeration> /*UInt8*/)keyIdentifier
             licenseData:(id<NSFastEnumeration> /*UInt8*/)licenseData;
@end

#endif // __WMCMediaStreamSource_DEFINED__

// Windows.Media.Core.MediaStreamSourceClosedEventArgs
#ifndef __WMCMediaStreamSourceClosedEventArgs_DEFINED__
#define __WMCMediaStreamSourceClosedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceClosedEventArgs : RTObject
@property (readonly) WMCMediaStreamSourceClosedRequest* request;
@end

#endif // __WMCMediaStreamSourceClosedEventArgs_DEFINED__

// Windows.Media.Core.MediaStreamSourceStartingEventArgs
#ifndef __WMCMediaStreamSourceStartingEventArgs_DEFINED__
#define __WMCMediaStreamSourceStartingEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceStartingEventArgs : RTObject
@property (readonly) WMCMediaStreamSourceStartingRequest* request;
@end

#endif // __WMCMediaStreamSourceStartingEventArgs_DEFINED__

// Windows.Media.Core.MediaStreamSourceSampleRequestedEventArgs
#ifndef __WMCMediaStreamSourceSampleRequestedEventArgs_DEFINED__
#define __WMCMediaStreamSourceSampleRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceSampleRequestedEventArgs : RTObject
@property (readonly) WMCMediaStreamSourceSampleRequest* request;
@end

#endif // __WMCMediaStreamSourceSampleRequestedEventArgs_DEFINED__

// Windows.Media.Core.MediaStreamSourceSwitchStreamsRequestedEventArgs
#ifndef __WMCMediaStreamSourceSwitchStreamsRequestedEventArgs_DEFINED__
#define __WMCMediaStreamSourceSwitchStreamsRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceSwitchStreamsRequestedEventArgs : RTObject
@property (readonly) WMCMediaStreamSourceSwitchStreamsRequest* request;
@end

#endif // __WMCMediaStreamSourceSwitchStreamsRequestedEventArgs_DEFINED__

// Windows.Media.Core.MediaStreamSamplePropertySet
#ifndef __WMCMediaStreamSamplePropertySet_DEFINED__
#define __WMCMediaStreamSamplePropertySet_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSamplePropertySet : RTObject
@property (readonly) unsigned size;
// Could not find base class Windows.Foundation.Collections.IMap`2<GUID,System.Object> type information
@end

#endif // __WMCMediaStreamSamplePropertySet_DEFINED__

// Windows.Media.Core.MediaStreamSample
#ifndef __WMCMediaStreamSample_DEFINED__
#define __WMCMediaStreamSample_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSample : RTObject
+ (WMCMediaStreamSample*)createFromBuffer:(RTObject<WSSIBuffer>*)buffer timestamp:(WFTimeSpan*)timestamp;
+ (void)createFromStreamAsync:(RTObject<WSSIInputStream>*)stream
                        count:(unsigned)count
                    timestamp:(WFTimeSpan*)timestamp
                      success:(void (^)(WMCMediaStreamSample*))success
                      failure:(void (^)(NSError*))failure;
@property BOOL keyFrame;
@property (copy) WFTimeSpan* duration;
@property BOOL discontinuous;
@property (copy) WFTimeSpan* decodeTimestamp;
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

WINRT_EXPORT
@interface WMCMediaStreamSampleProtectionProperties : RTObject
- (void)setKeyIdentifier:(id<NSFastEnumeration> /*UInt8*/)value;
- (void)getKeyIdentifier:(id<NSFastEnumeration> /*UInt8*/*)value;
- (void)setInitializationVector:(id<NSFastEnumeration> /*UInt8*/)value;
- (void)getInitializationVector:(id<NSFastEnumeration> /*UInt8*/*)value;
- (void)setSubSampleMapping:(id<NSFastEnumeration> /*UInt8*/)value;
- (void)getSubSampleMapping:(id<NSFastEnumeration> /*UInt8*/*)value;
@end

#endif // __WMCMediaStreamSampleProtectionProperties_DEFINED__

// Windows.Media.Core.MediaStreamSourceClosedRequest
#ifndef __WMCMediaStreamSourceClosedRequest_DEFINED__
#define __WMCMediaStreamSourceClosedRequest_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceClosedRequest : RTObject
@property (readonly) WMCMediaStreamSourceClosedReason reason;
@end

#endif // __WMCMediaStreamSourceClosedRequest_DEFINED__

// Windows.Media.Core.MediaStreamSourceStartingRequestDeferral
#ifndef __WMCMediaStreamSourceStartingRequestDeferral_DEFINED__
#define __WMCMediaStreamSourceStartingRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceStartingRequestDeferral : RTObject
- (void)complete;
@end

#endif // __WMCMediaStreamSourceStartingRequestDeferral_DEFINED__

// Windows.Media.Core.MediaStreamSourceStartingRequest
#ifndef __WMCMediaStreamSourceStartingRequest_DEFINED__
#define __WMCMediaStreamSourceStartingRequest_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceStartingRequest : RTObject
@property (readonly) WFTimeSpan* startPosition;
- (WMCMediaStreamSourceStartingRequestDeferral*)getDeferral;
- (void)setActualStartPosition:(WFTimeSpan*)position;
@end

#endif // __WMCMediaStreamSourceStartingRequest_DEFINED__

// Windows.Media.Core.MediaStreamSourceSampleRequestDeferral
#ifndef __WMCMediaStreamSourceSampleRequestDeferral_DEFINED__
#define __WMCMediaStreamSourceSampleRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceSampleRequestDeferral : RTObject
- (void)complete;
@end

#endif // __WMCMediaStreamSourceSampleRequestDeferral_DEFINED__

// Windows.Media.Core.MediaStreamSourceSampleRequest
#ifndef __WMCMediaStreamSourceSampleRequest_DEFINED__
#define __WMCMediaStreamSourceSampleRequest_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceSampleRequest : RTObject
@property (copy) WMCMediaStreamSample* sample;
@property (readonly) RTObject<WMCIMediaStreamDescriptor>* streamDescriptor;
- (WMCMediaStreamSourceSampleRequestDeferral*)getDeferral;
- (void)reportSampleProgress:(unsigned)progress;
@end

#endif // __WMCMediaStreamSourceSampleRequest_DEFINED__

// Windows.Media.Core.MediaStreamSourceSwitchStreamsRequestDeferral
#ifndef __WMCMediaStreamSourceSwitchStreamsRequestDeferral_DEFINED__
#define __WMCMediaStreamSourceSwitchStreamsRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceSwitchStreamsRequestDeferral : RTObject
- (void)complete;
@end

#endif // __WMCMediaStreamSourceSwitchStreamsRequestDeferral_DEFINED__

// Windows.Media.Core.MediaStreamSourceSwitchStreamsRequest
#ifndef __WMCMediaStreamSourceSwitchStreamsRequest_DEFINED__
#define __WMCMediaStreamSourceSwitchStreamsRequest_DEFINED__

WINRT_EXPORT
@interface WMCMediaStreamSourceSwitchStreamsRequest : RTObject
@property (readonly) RTObject<WMCIMediaStreamDescriptor>* newStreamDescriptor;
@property (readonly) RTObject<WMCIMediaStreamDescriptor>* oldStreamDescriptor;
- (WMCMediaStreamSourceSwitchStreamsRequestDeferral*)getDeferral;
@end

#endif // __WMCMediaStreamSourceSwitchStreamsRequest_DEFINED__
