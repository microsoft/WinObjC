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
#import <CoreGraphics/CGGeometry.h>
#import <CoreMedia/CMTime.h>
#import <CoreGraphics/CGImage.h>

@class NSError;
@class NSString;
@class AVAsset;
@class NSArray;
@class AVVideoComposition;
@protocol AVVideoCompositing;

typedef NSInteger AVAssetImageGeneratorResult;
typedef void (^AVAssetImageGeneratorCompletionHandler)(
    CMTime requestedTime, CGImageRef image, CMTime actualTime, AVAssetImageGeneratorResult result, NSError* error);
AVFOUNDATION_EXPORT NSString* const AVAssetImageGeneratorApertureModeCleanAperture;
AVFOUNDATION_EXPORT NSString* const AVAssetImageGeneratorApertureModeProductionAperture;
AVFOUNDATION_EXPORT NSString* const AVAssetImageGeneratorApertureModeEncodedPixels;
enum {
    AVAssetImageGeneratorSucceeded,
    AVAssetImageGeneratorFailed,
    AVAssetImageGeneratorCancelled,
};

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetImageGenerator : NSObject
- (instancetype)initWithAsset:(AVAsset*)asset STUB_METHOD;
+ (instancetype)assetImageGeneratorWithAsset:(AVAsset*)asset STUB_METHOD;
- (CGImageRef)copyCGImageAtTime:(CMTime)requestedTime actualTime:(CMTime*)actualTime error:(NSError* _Nullable*)outError STUB_METHOD;
- (void)generateCGImagesAsynchronouslyForTimes:(NSArray*)requestedTimes
                             completionHandler:(AVAssetImageGeneratorCompletionHandler)handler STUB_METHOD;
- (void)cancelAllCGImageGeneration STUB_METHOD;
@property (nonatomic) CMTime requestedTimeToleranceBefore STUB_PROPERTY;
@property (nonatomic) CMTime requestedTimeToleranceAfter STUB_PROPERTY;
@property (copy, nonatomic) NSString* apertureMode STUB_PROPERTY;
@property (nonatomic) BOOL appliesPreferredTrackTransform STUB_PROPERTY;
@property (readonly, nonatomic) AVAsset* asset STUB_PROPERTY;
@property (nonatomic) CGSize maximumSize STUB_PROPERTY;
@property (copy, nonatomic) AVVideoComposition* videoComposition STUB_PROPERTY;
@property (readonly, nonatomic) id<AVVideoCompositing> customVideoCompositor STUB_PROPERTY;
@end
