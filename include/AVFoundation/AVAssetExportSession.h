//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#pragma once

#import <AVFoundation/AVFoundationExport.h>
#import <Foundation/NSObject.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>

@class NSString;
@class AVAsset;
@class NSURL;
@class NSArray;
@class AVMetadataItemFilter;
@class AVAudioMix;
@class AVVideoComposition;
@protocol AVVideoCompositing;
@class NSError;

typedef NSInteger AVAssetExportSessionStatus;
enum {
    AVAssetExportSessionStatusUnknown,
    AVAssetExportSessionStatusWaiting,
    AVAssetExportSessionStatusExporting,
    AVAssetExportSessionStatusCompleted,
    AVAssetExportSessionStatusFailed,
    AVAssetExportSessionStatusCancelled
};
AVFOUNDATION_EXPORT NSString* const AVAssetExportPresetLowQuality;
AVFOUNDATION_EXPORT NSString* const AVAssetExportPresetMediumQuality;
AVFOUNDATION_EXPORT NSString* const AVAssetExportPresetHighestQuality;
AVFOUNDATION_EXPORT NSString* const AVAssetExportPreset640x480;
AVFOUNDATION_EXPORT NSString* const AVAssetExportPreset960x540;
AVFOUNDATION_EXPORT NSString* const AVAssetExportPreset1280x720;
AVFOUNDATION_EXPORT NSString* const AVAssetExportPreset1920x1080;
AVFOUNDATION_EXPORT NSString* const AVAssetExportPreset3840x2160;
AVFOUNDATION_EXPORT NSString* const AVAssetExportPresetAppleM4A;
AVFOUNDATION_EXPORT NSString* const AVAssetExportPresetPassthrough;

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetExportSession : NSObject
- (instancetype)initWithAsset:(AVAsset*)asset presetName:(NSString*)presetName STUB_METHOD;
+ (instancetype)exportSessionWithAsset:(AVAsset*)asset presetName:(NSString*)presetName STUB_METHOD;
@property (copy, nonatomic) NSURL* outputURL STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* supportedFileTypes STUB_PROPERTY;
@property (copy, nonatomic) NSString* outputFileType STUB_PROPERTY;
@property (nonatomic) long long fileLengthLimit STUB_PROPERTY;
@property (nonatomic) CMTimeRange timeRange STUB_PROPERTY;
@property (copy, nonatomic) NSArray* metadata STUB_PROPERTY;
@property (retain, nonatomic) AVMetadataItemFilter* metadataItemFilter STUB_PROPERTY;
@property (copy, nonatomic) AVAudioMix* audioMix STUB_PROPERTY;
@property (copy, nonatomic) NSString* audioTimePitchAlgorithm STUB_PROPERTY;
@property (nonatomic) BOOL shouldOptimizeForNetworkUse STUB_PROPERTY;
@property (copy, nonatomic) AVVideoComposition* videoComposition STUB_PROPERTY;
@property (readonly, nonatomic) id<AVVideoCompositing> customVideoCompositor STUB_PROPERTY;
@property (nonatomic) BOOL canPerformMultiplePassesOverSourceMediaData STUB_PROPERTY;
@property (copy, nonatomic) NSURL* directoryForTemporaryFiles STUB_PROPERTY;
@property (readonly, nonatomic) NSString* presetName STUB_PROPERTY;
+ (NSArray*)allExportPresets STUB_METHOD;
+ (NSArray*)exportPresetsCompatibleWithAsset:(AVAsset*)asset STUB_METHOD;
+ (void)determineCompatibilityOfExportPreset:(NSString*)presetName
                                   withAsset:(AVAsset*)asset
                              outputFileType:(NSString*)outputFileType
                           completionHandler:(void (^)(BOOL))handler STUB_METHOD;
- (void)determineCompatibleFileTypesWithCompletionHandler:(void (^)(NSArray*))handler STUB_METHOD;
- (void)exportAsynchronouslyWithCompletionHandler:(void (^)(void))handler STUB_METHOD;
- (void)cancelExport STUB_METHOD;
@property (readonly, nonatomic) NSError* error STUB_PROPERTY;
@property (readonly, nonatomic) long long estimatedOutputFileLength STUB_PROPERTY;
@property (readonly, nonatomic) CMTime maxDuration STUB_PROPERTY;
@property (readonly, nonatomic) float progress STUB_PROPERTY;
@property (readonly, nonatomic) AVAssetExportSessionStatus status STUB_PROPERTY;
@property (readonly, retain, nonatomic) AVAsset* asset STUB_PROPERTY;
@end
