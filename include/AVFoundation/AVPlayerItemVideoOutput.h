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

#pragma once

#import <AVFoundation/AVFoundationExport.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVPlayerItemOutput.h>
#import <CoreMedia/CMTime.h>
#import <CoreVideo/CVPixelBuffer.h>

@class NSDictionary;
@protocol AVPlayerItemOutputPullDelegate;

AVFOUNDATION_EXPORT_CLASS
@interface AVPlayerItemVideoOutput : AVPlayerItemOutput
- (instancetype)initWithPixelBufferAttributes:(NSDictionary*)pixelBufferAttributes STUB_METHOD;
@property (readonly, assign, nonatomic) id<AVPlayerItemOutputPullDelegate> delegate STUB_PROPERTY;
@property (readonly, nonatomic) dispatch_queue_t delegateQueue STUB_PROPERTY;
- (void)setDelegate:(id<AVPlayerItemOutputPullDelegate>)delegate queue:(dispatch_queue_t)delegateQueue STUB_METHOD;
- (void)requestNotificationOfMediaDataChangeWithAdvanceInterval:(NSTimeInterval)interval STUB_METHOD;
- (BOOL)hasNewPixelBufferForItemTime:(CMTime)itemTime STUB_METHOD;
- (CVPixelBufferRef)copyPixelBufferForItemTime:(CMTime)itemTime itemTimeForDisplay:(CMTime*)outItemTimeForDisplay STUB_METHOD;
@end
