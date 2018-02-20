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

// WindowsMediaTranscoding.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIATRANSCODINGEXPORT
#define OBJCUWPWINDOWSMEDIATRANSCODINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaTranscoding.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMTPrepareTranscodeResult, WMTMediaTranscoder;
@protocol WMTIMediaTranscoder2, WMTIMediaTranscoder, WMTIPrepareTranscodeResult;

// Windows.Media.Transcoding.MediaVideoProcessingAlgorithm
enum _WMTMediaVideoProcessingAlgorithm {
    WMTMediaVideoProcessingAlgorithmDefault = 0,
    WMTMediaVideoProcessingAlgorithmMrfCrf444 = 1,
};
typedef unsigned WMTMediaVideoProcessingAlgorithm;

// Windows.Media.Transcoding.TranscodeFailureReason
enum _WMTTranscodeFailureReason {
    WMTTranscodeFailureReasonNone = 0,
    WMTTranscodeFailureReasonUnknown = 1,
    WMTTranscodeFailureReasonInvalidProfile = 2,
    WMTTranscodeFailureReasonCodecNotFound = 3,
};
typedef unsigned WMTTranscodeFailureReason;

#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsStorage.h"
#include "WindowsMediaCore.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Media.Transcoding.PrepareTranscodeResult
#ifndef __WMTPrepareTranscodeResult_DEFINED__
#define __WMTPrepareTranscodeResult_DEFINED__

OBJCUWPWINDOWSMEDIATRANSCODINGEXPORT
@interface WMTPrepareTranscodeResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL canTranscode;
@property (readonly) WMTTranscodeFailureReason failureReason;
// Failed to generate member TranscodeAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<Double>)
@end

#endif // __WMTPrepareTranscodeResult_DEFINED__

// Windows.Media.Transcoding.MediaTranscoder
#ifndef __WMTMediaTranscoder_DEFINED__
#define __WMTMediaTranscoder_DEFINED__

OBJCUWPWINDOWSMEDIATRANSCODINGEXPORT
@interface WMTMediaTranscoder : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* trimStopTime;
@property (retain) WFTimeSpan* trimStartTime;
@property BOOL hardwareAccelerationEnabled;
@property BOOL alwaysReencode;
@property WMTMediaVideoProcessingAlgorithm videoProcessingAlgorithm;
- (void)addAudioEffect:(NSString *)activatableClassId;
- (void)addAudioEffectWithSettings:(NSString *)activatableClassId effectRequired:(BOOL)effectRequired configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)addVideoEffect:(NSString *)activatableClassId;
- (void)addVideoEffectWithSettings:(NSString *)activatableClassId effectRequired:(BOOL)effectRequired configuration:(RTObject<WFCIPropertySet>*)configuration;
- (void)clearEffects;
- (void)prepareFileTranscodeAsync:(RTObject<WSIStorageFile>*)source destination:(RTObject<WSIStorageFile>*)destination profile:(WMMMediaEncodingProfile*)profile success:(void (^)(WMTPrepareTranscodeResult*))success failure:(void (^)(NSError*))failure;
- (void)prepareStreamTranscodeAsync:(RTObject<WSSIRandomAccessStream>*)source destination:(RTObject<WSSIRandomAccessStream>*)destination profile:(WMMMediaEncodingProfile*)profile success:(void (^)(WMTPrepareTranscodeResult*))success failure:(void (^)(NSError*))failure;
- (void)prepareMediaStreamSourceTranscodeAsync:(RTObject<WMCIMediaSource>*)source destination:(RTObject<WSSIRandomAccessStream>*)destination profile:(WMMMediaEncodingProfile*)profile success:(void (^)(WMTPrepareTranscodeResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMTMediaTranscoder_DEFINED__

