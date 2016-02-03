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
#import <CoreGraphics/CGAffineTransform.h>
#import <AVFoundation/AVVideoCompositionLayerInstruction.h>
#import <CoreMedia/CMTypes.h>
#import <CoreMedia/CMTime.h>

@class AVAssetTrack;

AVFOUNDATION_EXPORT_CLASS
@interface AVMutableVideoCompositionLayerInstruction
    : AVVideoCompositionLayerInstruction <NSCopying, NSMutableCopying, NSObject, NSSecureCoding>
+ (instancetype)videoCompositionLayerInstruction STUB_METHOD;
+ (instancetype)videoCompositionLayerInstructionWithAssetTrack:(AVAssetTrack*)track STUB_METHOD;
@property (assign, nonatomic) CMPersistentTrackID trackID STUB_PROPERTY;
- (void)setOpacity:(float)opacity atTime:(CMTime)time STUB_METHOD;
- (void)setOpacityRampFromStartOpacity:(float)startOpacity toEndOpacity:(float)endOpacity timeRange:(CMTimeRange)timeRange STUB_METHOD;
- (void)setTransform:(CGAffineTransform)transform atTime:(CMTime)time STUB_METHOD;
- (void)setTransformRampFromStartTransform:(CGAffineTransform)startTransform
                            toEndTransform:(CGAffineTransform)endTransform
                                 timeRange:(CMTimeRange)timeRange STUB_METHOD;
- (void)setCropRectangle:(CGRect)cropRectangle atTime:(CMTime)time STUB_METHOD;
- (void)setCropRectangleRampFromStartCropRectangle:(CGRect)startCropRectangle
                                toEndCropRectangle:(CGRect)endCropRectangle
                                         timeRange:(CMTimeRange)timeRange STUB_METHOD;
@end
