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
#import <CoreMedia/CMTypes.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>

AVFOUNDATION_EXPORT_CLASS
@interface AVVideoCompositionLayerInstruction : NSObject <NSCopying, NSMutableCopying, NSObject, NSSecureCoding>
@property (readonly, assign, nonatomic) CMPersistentTrackID trackID STUB_PROPERTY;
- (BOOL)getOpacityRampForTime:(CMTime)time
                 startOpacity:(float*)startOpacity
                   endOpacity:(float*)endOpacity
                    timeRange:(CMTimeRange*)timeRange STUB_METHOD;
- (BOOL)getTransformRampForTime:(CMTime)time
                 startTransform:(CGAffineTransform*)startTransform
                   endTransform:(CGAffineTransform*)endTransform
                      timeRange:(CMTimeRange*)timeRange STUB_METHOD;
- (BOOL)getCropRectangleRampForTime:(CMTime)time
                 startCropRectangle:(CGRect*)startCropRectangle
                   endCropRectangle:(CGRect*)endCropRectangle
                          timeRange:(CMTimeRange*)timeRange STUB_METHOD;
@end
