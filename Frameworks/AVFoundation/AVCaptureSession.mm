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

NSString* const AVCaptureSessionErrorKey = @"AVCaptureSessionErrorKey";
NSString* const AVCaptureSessionPresetPhoto = @"AVCaptureSessionPresetPhoto";
NSString* const AVCaptureSessionPresetHigh = @"AVCaptureSessionPresetHigh";
NSString* const AVCaptureSessionPresetMedium = @"AVCaptureSessionPresetMedium";
NSString* const AVCaptureSessionPresetLow = @"AVCaptureSessionPresetLow";
NSString* const AVCaptureSessionPreset352x288 = @"AVCaptureSessionPreset352x288";
NSString* const AVCaptureSessionPreset640x480 = @"AVCaptureSessionPreset640x480";
NSString* const AVCaptureSessionPreset1280x720 = @"AVCaptureSessionPreset1280x720";
NSString* const AVCaptureSessionPreset1920x1080 = @"AVCaptureSessionPreset1920x1080";
NSString* const AVCaptureSessionPresetiFrame960x540 = @"AVCaptureSessionPresetiFrame960x540";
NSString* const AVCaptureSessionPresetiFrame1280x720 = @"AVCaptureSessionPresetiFrame1280x720";
NSString* const AVCaptureSessionPresetInputPriority = @"AVCaptureSessionPresetInputPriority";

NSString* const AVCaptureSessionRuntimeErrorNotification = @"AVCaptureSessionRuntimeErrorNotification";
NSString* const AVCaptureSessionDidStartRunningNotification = @"AVCaptureSessionDidStartRunningNotification";
NSString* const AVCaptureSessionDidStopRunningNotification = @"AVCaptureSessionDidStopRunningNotification";
NSString* const AVCaptureSessionWasInterruptedNotification = @"AVCaptureSessionWasInterruptedNotification";
NSString* const AVCaptureSessionInterruptionEndedNotification = @"AVCaptureSessionInterruptionEndedNotification";

@implementation AVCaptureSession
/**
@Status Stub
@Notes
*/
- (BOOL)canAddInput:(AVCaptureInput*)input {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)addInput:(AVCaptureInput*)input {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)removeInput:(AVCaptureInput*)input {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)canAddOutput:(AVCaptureOutput*)output {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)addOutput:(AVCaptureOutput*)output {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)removeOutput:(AVCaptureOutput*)output {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)startRunning {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)stopRunning {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)beginConfiguration {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)commitConfiguration {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)canSetSessionPreset:(NSString*)preset {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)addConnection:(AVCaptureConnection*)connection {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)canAddConnection:(AVCaptureConnection*)connection {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)addInputWithNoConnections:(AVCaptureInput*)input {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)addOutputWithNoConnections:(AVCaptureOutput*)output {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)removeConnection:(AVCaptureConnection*)connection {
    UNIMPLEMENTED();
}

@end
