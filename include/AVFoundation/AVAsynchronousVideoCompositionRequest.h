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
#import <CoreVideo/CVPixelBuffer.h>
#import <CoreMedia/CMTypes.h>
#import <CoreMedia/CMTime.h>

@class NSError;
@class AVVideoCompositionRenderContext;
@class NSArray;
@protocol AVVideoCompositionInstruction;

AVFOUNDATION_EXPORT_CLASS
@interface AVAsynchronousVideoCompositionRequest : NSObject <NSCopying>
- (CVPixelBufferRef)sourceFrameByTrackID:(CMPersistentTrackID)trackID STUB_METHOD;
- (void)finishCancelledRequest STUB_METHOD;
- (void)finishWithComposedVideoFrame:(CVPixelBufferRef)composedVideoFrame STUB_METHOD;
- (void)finishWithError:(NSError*)error STUB_METHOD;
@property (readonly, nonatomic) CMTime compositionTime STUB_PROPERTY;
@property (readonly, nonatomic) AVVideoCompositionRenderContext* renderContext STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* sourceTrackIDs STUB_PROPERTY;
@property (readonly, nonatomic) id<AVVideoCompositionInstruction> videoCompositionInstruction STUB_PROPERTY;
@end
