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
#import <CoreGraphics/CGGeometry.h>
#import <CoreVideo/CVPixelBuffer.h>

@class AVVideoComposition;

typedef struct {
    NSInteger horizontalSpacing;
    NSInteger verticalSpacing;
} AVPixelAspectRatio;
typedef struct {
    CGFloat left;
    CGFloat top;
    CGFloat right;
    CGFloat bottom;
} AVEdgeWidths;

AVFOUNDATION_EXPORT_CLASS
@interface AVVideoCompositionRenderContext : NSObject
- (CVPixelBufferRef)newPixelBuffer STUB_METHOD;
@property (readonly, nonatomic) AVVideoComposition* videoComposition STUB_PROPERTY;
@property (readonly, nonatomic) BOOL highQualityRendering STUB_PROPERTY;
@property (readonly, nonatomic) AVEdgeWidths edgeWidths STUB_PROPERTY;
@property (readonly, nonatomic) AVPixelAspectRatio pixelAspectRatio STUB_PROPERTY;
@property (readonly, nonatomic) float renderScale STUB_PROPERTY;
@property (readonly, nonatomic) CGAffineTransform renderTransform STUB_PROPERTY;
@property (readonly, nonatomic) CGSize size STUB_PROPERTY;
@end
