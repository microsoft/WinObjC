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
#import <CoreMedia/CMSync.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreMedia/CMTime.h>

@class NSError;
@class AVAudioMix;
@class AVVideoComposition;
@protocol AVVideoCompositing;
@class AVPlayerItemErrorLog;
@class NSString;
@class NSURL;
@class AVAsset;
@class NSArray;
@class NSDate;
@class AVPlayerItemAccessLog;
@class AVMediaSelectionOption;
@class AVMediaSelectionGroup;
@class AVPlayerItemOutput;

typedef NS_ENUM(NSInteger, AVPlayerItemStatus) {
    AVPlayerItemStatusUnknown,
    AVPlayerItemStatusReadyToPlay,
    AVPlayerItemStatusFailed
};

AVFOUNDATION_EXPORT NSString* const AVPlayerItemFailedToPlayToEndTimeErrorKey;

AVFOUNDATION_EXPORT NSString* const AVPlayerItemDidPlayToEndTimeNotification;
AVFOUNDATION_EXPORT NSString* const AVPlayerItemFailedToPlayToEndTimeNotification;
AVFOUNDATION_EXPORT NSString* const AVPlayerItemTimeJumpedNotification;
AVFOUNDATION_EXPORT NSString* const AVPlayerItemPlaybackStalledNotification;
AVFOUNDATION_EXPORT NSString* const AVPlayerItemNewAccessLogEntryNotification;
AVFOUNDATION_EXPORT NSString* const AVPlayerItemNewErrorLogEntryNotification;

AVFOUNDATION_EXPORT_CLASS
@interface AVPlayerItem : NSObject <NSCopying>
- (instancetype)initWithURL:(NSURL*)URL STUB_METHOD;
+ (AVPlayerItem*)playerItemWithURL:(NSURL*)URL STUB_METHOD;
- (instancetype)initWithAsset:(AVAsset*)asset STUB_METHOD;
+ (AVPlayerItem*)playerItemWithAsset:(AVAsset*)asset STUB_METHOD;
- (instancetype)initWithAsset:(AVAsset*)asset automaticallyLoadedAssetKeys:(NSArray*)automaticallyLoadedAssetKeys STUB_METHOD;
+ (AVPlayerItem*)playerItemWithAsset:(AVAsset*)asset automaticallyLoadedAssetKeys:(NSArray*)automaticallyLoadedAssetKeys STUB_METHOD;
@property (readonly, nonatomic) AVAsset* asset STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* tracks STUB_PROPERTY;
@property (readonly, nonatomic) AVPlayerItemStatus status STUB_PROPERTY;
@property (readonly, nonatomic) CMTime duration STUB_PROPERTY;
@property (readonly, nonatomic) CMTimebaseRef timebase STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* loadedTimeRanges STUB_PROPERTY;
@property (readonly, nonatomic) CGSize presentationSize STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* timedMetadata STUB_PROPERTY;
@property (readonly, nonatomic) NSError* error STUB_PROPERTY;
- (void)stepByCount:(NSInteger)stepCount STUB_METHOD;
@property (readonly, nonatomic) NSArray* seekableTimeRanges STUB_PROPERTY;
- (BOOL)seekToDate:(NSDate*)date STUB_METHOD;
- (void)seekToTime:(CMTime)time STUB_METHOD;
- (void)seekToTime:(CMTime)time completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (BOOL)seekToDate:(NSDate*)date completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (void)seekToTime:(CMTime)time toleranceBefore:(CMTime)toleranceBefore toleranceAfter:(CMTime)toleranceAfter STUB_METHOD;
- (void)seekToTime:(CMTime)time
   toleranceBefore:(CMTime)toleranceBefore
    toleranceAfter:(CMTime)toleranceAfter
 completionHandler:(void (^)(BOOL))completionHandler STUB_METHOD;
- (void)cancelPendingSeeks STUB_METHOD;
@property (readonly, getter=isPlaybackLikelyToKeepUp, nonatomic) BOOL playbackLikelyToKeepUp STUB_PROPERTY;
@property (readonly, getter=isPlaybackBufferEmpty, nonatomic) BOOL playbackBufferEmpty STUB_PROPERTY;
@property (readonly, getter=isPlaybackBufferFull, nonatomic) BOOL playbackBufferFull STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canPlayReverse STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canPlayFastForward STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canPlayFastReverse STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canPlaySlowForward STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canPlaySlowReverse STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canStepBackward STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canStepForward STUB_PROPERTY;
- (CMTime)currentTime STUB_METHOD;
- (NSDate*)currentDate STUB_METHOD;
@property (nonatomic) CMTime forwardPlaybackEndTime STUB_PROPERTY;
@property (nonatomic) CMTime reversePlaybackEndTime STUB_PROPERTY;
@property (copy, nonatomic) AVAudioMix* audioMix STUB_PROPERTY;
@property (copy, nonatomic) AVVideoComposition* videoComposition STUB_PROPERTY;
@property (nonatomic) BOOL seekingWaitsForVideoCompositionRendering STUB_PROPERTY;
@property (copy, nonatomic) NSString* audioTimePitchAlgorithm STUB_PROPERTY;
@property (readonly, nonatomic) id<AVVideoCompositing> customVideoCompositor STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* automaticallyLoadedAssetKeys STUB_PROPERTY;
@property (nonatomic) double preferredPeakBitRate STUB_PROPERTY;
- (AVPlayerItemAccessLog*)accessLog STUB_METHOD;
- (AVPlayerItemErrorLog*)errorLog STUB_METHOD;
- (void)selectMediaOption:(AVMediaSelectionOption*)mediaSelectionOption
    inMediaSelectionGroup:(AVMediaSelectionGroup*)mediaSelectionGroup STUB_METHOD;
- (AVMediaSelectionOption*)selectedMediaOptionInMediaSelectionGroup:(AVMediaSelectionGroup*)mediaSelectionGroup STUB_METHOD;
- (void)selectMediaOptionAutomaticallyInMediaSelectionGroup:(AVMediaSelectionGroup*)mediaSelectionGroup STUB_METHOD;
@property (copy, nonatomic) NSArray* textStyleRules STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* outputs STUB_PROPERTY;
- (void)addOutput:(AVPlayerItemOutput*)output STUB_METHOD;
- (void)removeOutput:(AVPlayerItemOutput*)output STUB_METHOD;
@end
