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

@implementation AVCaptureStillImageOutput
/**
@Status Stub
@Notes
*/
- (void)captureStillImageAsynchronouslyFromConnection:(AVCaptureConnection*)connection
                                    completionHandler:(void (^)(CMSampleBufferRef, NSError*))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
+ (NSData*)jpegStillImageNSDataRepresentation:(CMSampleBufferRef)jpegSampleBuffer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)captureStillImageBracketAsynchronouslyFromConnection:(AVCaptureConnection*)connection
                                           withSettingsArray:(NSArray*)settings
                                           completionHandler:
                                               (void (^)(CMSampleBufferRef, AVCaptureBracketedStillImageSettings*, NSError*))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)prepareToCaptureStillImageBracketFromConnection:(AVCaptureConnection*)connection
                                      withSettingsArray:(NSArray*)settings
                                      completionHandler:(void (^)(BOOL, NSError*))handler {
    UNIMPLEMENTED();
}

@end
