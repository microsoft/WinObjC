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
#import <AVFoundation/AVAsynchronousKeyValueLoading.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>
#import <AVFoundation/AVComposition.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTypes.h>
#import <CoreMedia/CMTimeRange.h>

@class AVAsset;
@class NSError;
@class NSArray;
@class AVMutableCompositionTrack;
@class NSString;
@class AVCompositionTrack;
@class AVAssetTrack;

AVFOUNDATION_EXPORT_CLASS
@interface AVMutableComposition : AVComposition <AVAsynchronousKeyValueLoading, NSCopying, NSMutableCopying>
- (void)insertEmptyTimeRange:(CMTimeRange)timeRange STUB_METHOD;
- (BOOL)insertTimeRange:(CMTimeRange)timeRange
                ofAsset:(AVAsset*)asset
                 atTime:(CMTime)startTime
                  error:(NSError* _Nullable*)outError STUB_METHOD;
- (void)removeTimeRange:(CMTimeRange)timeRange STUB_METHOD;
- (void)scaleTimeRange:(CMTimeRange)timeRange toDuration:(CMTime)duration STUB_METHOD;
+ (instancetype)composition STUB_METHOD;
@property (readonly, nonatomic) NSArray* tracks STUB_PROPERTY;
- (AVMutableCompositionTrack*)addMutableTrackWithMediaType:(NSString*)mediaType
                                          preferredTrackID:(CMPersistentTrackID)preferredTrackID STUB_METHOD;
- (void)removeTrack:(AVCompositionTrack*)track STUB_METHOD;
- (AVMutableCompositionTrack*)mutableTrackCompatibleWithTrack:(AVAssetTrack*)track STUB_METHOD;
@property (nonatomic) CGSize naturalSize STUB_PROPERTY;
@end
