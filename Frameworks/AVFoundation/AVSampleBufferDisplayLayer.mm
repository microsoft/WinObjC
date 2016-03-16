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

#import <AVFoundation/AVFoundation.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

NSString* const AVSampleBufferDisplayLayerFailedToDecodeNotificationErrorKey =
    @"AVSampleBufferDisplayLayerFailedToDecodeNotificationErrorKey";

NSString* const AVSampleBufferDisplayLayerFailedToDecodeNotification = @"AVSampleBufferDisplayLayerFailedToDecodeNotification";

@implementation AVSampleBufferDisplayLayer
/**
@Status Stub
@Notes
*/
- (void)requestMediaDataWhenReadyOnQueue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)stopRequestingMediaData {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)flush {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)flushAndRemoveImage {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)enqueueSampleBuffer:(CMSampleBufferRef)sampleBuffer {
    UNIMPLEMENTED();
}

@end
