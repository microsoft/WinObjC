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
#import <QuartzCore/CAMediaTiming.h>
#import <Foundation/NSObject.h>
#import <QuartzCore/CALayer.h>
#import <CoreMedia/CMSync.h>
#import <CoreMedia/CMSampleBuffer.h>

@class NSString;
@class NSError;

typedef NSInteger AVQueuedSampleBufferRenderingStatus;
enum {
    AVQueuedSampleBufferRenderingStatusUnknown,
    AVQueuedSampleBufferRenderingStatusRendering,
    AVQueuedSampleBufferRenderingStatusFailed
};
AVFOUNDATION_EXPORT NSString* const AVSampleBufferDisplayLayerFailedToDecodeNotificationErrorKey;

AVFOUNDATION_EXPORT NSString* const AVSampleBufferDisplayLayerFailedToDecodeNotification;

AVFOUNDATION_EXPORT_CLASS
@interface AVSampleBufferDisplayLayer : CALayer <CAMediaTiming, NSCoding>
- (void)requestMediaDataWhenReadyOnQueue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block STUB_METHOD;
@property (readonly, getter=isReadyForMoreMediaData) BOOL readyForMoreMediaData STUB_PROPERTY;
- (void)stopRequestingMediaData STUB_METHOD;
- (void)flush STUB_METHOD;
- (void)flushAndRemoveImage STUB_METHOD;
@property CMTimebaseRef controlTimebase STUB_PROPERTY;
- (void)enqueueSampleBuffer:(CMSampleBufferRef)sampleBuffer STUB_METHOD;
@property (copy) NSString* videoGravity STUB_PROPERTY;
@property (readonly, nonatomic) NSError* error STUB_PROPERTY;
@property (readonly, nonatomic) AVQueuedSampleBufferRenderingStatus status STUB_PROPERTY;
@end
