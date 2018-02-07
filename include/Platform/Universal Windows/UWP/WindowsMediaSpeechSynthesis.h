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

// WindowsMediaSpeechSynthesis.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
#define OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaSpeechSynthesis.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMSVoiceInformation, WMSSpeechSynthesisStream, WMSSpeechSynthesizerOptions, WMSSpeechSynthesizer;
@protocol WMSIVoiceInformation, WMSIInstalledVoicesStatic, WMSIInstalledVoicesStatic2, WMSISpeechSynthesisStream, WMSISpeechSynthesizer, WMSISpeechSynthesizer2, WMSISpeechSynthesizerOptions, WMSISpeechSynthesizerOptions2;

// Windows.Media.SpeechSynthesis.VoiceGender
enum _WMSVoiceGender {
    WMSVoiceGenderMale = 0,
    WMSVoiceGenderFemale = 1,
};
typedef unsigned WMSVoiceGender;

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"
#include "WindowsMedia.h"
#include "WindowsMediaCore.h"

#import <Foundation/Foundation.h>

// Windows.Media.SpeechSynthesis.VoiceInformation
#ifndef __WMSVoiceInformation_DEFINED__
#define __WMSVoiceInformation_DEFINED__

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WMSVoiceInformation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * Description;
@property (readonly) NSString * displayName;
@property (readonly) WMSVoiceGender gender;
@property (readonly) NSString * id;
@property (readonly) NSString * language;
@end

#endif // __WMSVoiceInformation_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Storage.Streams.IInputStream
#ifndef __WSSIInputStream_DEFINED__
#define __WSSIInputStream_DEFINED__

@protocol WSSIInputStream <WFIClosable>
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer count:(unsigned int)count options:(WSSInputStreamOptions)options success:(void (^)(RTObject<WSSIBuffer>*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)close;
@end

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WSSIInputStream : RTObject <WSSIInputStream>
@end

#endif // __WSSIInputStream_DEFINED__

// Windows.Storage.Streams.IOutputStream
#ifndef __WSSIOutputStream_DEFINED__
#define __WSSIOutputStream_DEFINED__

@protocol WSSIOutputStream <WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WSSIOutputStream : RTObject <WSSIOutputStream>
@end

#endif // __WSSIOutputStream_DEFINED__

// Windows.Storage.Streams.IRandomAccessStream
#ifndef __WSSIRandomAccessStream_DEFINED__
#define __WSSIRandomAccessStream_DEFINED__

@protocol WSSIRandomAccessStream <WFIClosable, WSSIInputStream, WSSIOutputStream>
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
@property uint64_t size;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer count:(unsigned int)count options:(WSSInputStreamOptions)options success:(void (^)(RTObject<WSSIBuffer>*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WSSIRandomAccessStream : RTObject <WSSIRandomAccessStream>
@end

#endif // __WSSIRandomAccessStream_DEFINED__

// Windows.Storage.Streams.IContentTypeProvider
#ifndef __WSSIContentTypeProvider_DEFINED__
#define __WSSIContentTypeProvider_DEFINED__

@protocol WSSIContentTypeProvider
@property (readonly) NSString * contentType;
@end

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WSSIContentTypeProvider : RTObject <WSSIContentTypeProvider>
@end

#endif // __WSSIContentTypeProvider_DEFINED__

// Windows.Storage.Streams.IRandomAccessStreamWithContentType
#ifndef __WSSIRandomAccessStreamWithContentType_DEFINED__
#define __WSSIRandomAccessStreamWithContentType_DEFINED__

@protocol WSSIRandomAccessStreamWithContentType <WSSIRandomAccessStream, WFIClosable, WSSIInputStream, WSSIOutputStream, WSSIContentTypeProvider>
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer count:(unsigned int)count options:(WSSInputStreamOptions)options success:(void (^)(RTObject<WSSIBuffer>*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WSSIRandomAccessStreamWithContentType : RTObject <WSSIRandomAccessStreamWithContentType>
@end

#endif // __WSSIRandomAccessStreamWithContentType_DEFINED__

// Windows.Media.Core.ITimedMetadataTrackProvider
#ifndef __WMCITimedMetadataTrackProvider_DEFINED__
#define __WMCITimedMetadataTrackProvider_DEFINED__

@protocol WMCITimedMetadataTrackProvider
@property (readonly) NSArray* /* WMCTimedMetadataTrack* */ timedMetadataTracks;
@end

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WMCITimedMetadataTrackProvider : RTObject <WMCITimedMetadataTrackProvider>
@end

#endif // __WMCITimedMetadataTrackProvider_DEFINED__

// Windows.Media.SpeechSynthesis.SpeechSynthesisStream
#ifndef __WMSSpeechSynthesisStream_DEFINED__
#define __WMSSpeechSynthesisStream_DEFINED__

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WMSSpeechSynthesisStream : RTObject <WSSIRandomAccessStreamWithContentType, WSSIContentTypeProvider, WSSIRandomAccessStream, WSSIOutputStream, WFIClosable, WSSIInputStream, WMCITimedMetadataTrackProvider>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WMCTimedMetadataTrack* */ timedMetadataTracks;
@property (readonly) NSArray* /* RTObject<WMIMediaMarker>* */ markers;
@property (readonly) NSString * contentType;
@property uint64_t size;
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer count:(unsigned int)count options:(WSSInputStreamOptions)options success:(void (^)(RTObject<WSSIBuffer>*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMSSpeechSynthesisStream_DEFINED__

// Windows.Media.SpeechSynthesis.SpeechSynthesizerOptions
#ifndef __WMSSpeechSynthesizerOptions_DEFINED__
#define __WMSSpeechSynthesizerOptions_DEFINED__

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WMSSpeechSynthesizerOptions : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL includeWordBoundaryMetadata;
@property BOOL includeSentenceBoundaryMetadata;
@property double speakingRate;
@property double audioVolume;
@property double audioPitch;
@end

#endif // __WMSSpeechSynthesizerOptions_DEFINED__

// Windows.Media.SpeechSynthesis.SpeechSynthesizer
#ifndef __WMSSpeechSynthesizer_DEFINED__
#define __WMSSpeechSynthesizer_DEFINED__

OBJCUWPWINDOWSMEDIASPEECHSYNTHESISEXPORT
@interface WMSSpeechSynthesizer : RTObject <WFIClosable>
+ (void)trySetDefaultVoiceAsync:(WMSVoiceInformation*)voice success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WMSVoiceInformation* voice;
@property (readonly) WMSSpeechSynthesizerOptions* options;
+ (NSArray* /* WMSVoiceInformation* */)allVoices;
+ (WMSVoiceInformation*)defaultVoice;
- (void)synthesizeTextToStreamAsync:(NSString *)text success:(void (^)(WMSSpeechSynthesisStream*))success failure:(void (^)(NSError*))failure;
- (void)synthesizeSsmlToStreamAsync:(NSString *)Ssml success:(void (^)(WMSSpeechSynthesisStream*))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WMSSpeechSynthesizer_DEFINED__

