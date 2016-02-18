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
#import <AVFoundation/AVVideoComposition.h>
#import <CoreMedia/CMTime.h>

@class AVAsset;
@class NSArray;
@class AVVideoCompositionCoreAnimationTool;

AVFOUNDATION_EXPORT_CLASS
@interface AVMutableVideoComposition : AVVideoComposition <NSCopying, NSMutableCopying>
+ (AVMutableVideoComposition*)videoComposition STUB_METHOD;
+ (AVMutableVideoComposition*)videoCompositionWithPropertiesOfAsset:(AVAsset*)asset STUB_METHOD;
@property (nonatomic) CMTime frameDuration STUB_PROPERTY;
@property (nonatomic) CGSize renderSize STUB_PROPERTY;
@property (nonatomic) float renderScale STUB_PROPERTY;
@property (copy, nonatomic) NSArray* instructions STUB_PROPERTY;
@property (retain, nonatomic) AVVideoCompositionCoreAnimationTool* animationTool STUB_PROPERTY;
@property (retain, nonatomic) Class customVideoCompositorClass STUB_PROPERTY;
@end
