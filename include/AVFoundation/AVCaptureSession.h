//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _AVCAPTURESESSION_H_
#define _AVCAPTURESESSION_H_

#import <StarboardExport.h>
#import <Foundation/Foundation.h>

SB_EXPORT NSString *const AVCaptureSessionPresetPhoto;
SB_EXPORT NSString *const AVCaptureSessionPresetHigh;
SB_EXPORT NSString *const AVCaptureSessionPresetMedium;
SB_EXPORT NSString *const AVCaptureSessionPresetLow;
SB_EXPORT NSString *const AVCaptureSessionPreset352x288;
SB_EXPORT NSString *const AVCaptureSessionPreset640x480;
SB_EXPORT NSString *const AVCaptureSessionPreset1280x720;
SB_EXPORT NSString *const AVCaptureSessionPreset1920x1080;
SB_EXPORT NSString *const AVCaptureSessionPresetiFrame960x540;
SB_EXPORT NSString *const AVCaptureSessionPresetiFrame1280x720;
SB_EXPORT NSString *const AVCaptureSessionPresetInputPriority;

SB_EXPORT NSString *const AVCaptureSessionRuntimeErrorNotification;
SB_EXPORT NSString *const AVCaptureSessionDidStartRunningNotification;
SB_EXPORT NSString *const AVCaptureSessionDidStopRunningNotification;
SB_EXPORT NSString *const AVCaptureSessionWasInterruptedNotification;
SB_EXPORT NSString *const AVCaptureSessionInterruptionEndedNotification;

SB_EXPORT NSString *const AVCaptureSessionErrorKey;

@class AVCaptureInput;
@class AVCaptureOutput;

@interface AVCaptureSession : NSObject

@property(nonatomic, copy) NSString *sessionPreset;
@property(nonatomic, readonly) NSArray *inputs;
@property(nonatomic, readonly) NSArray *outputs;
@property(nonatomic, readonly, getter=isRunning) BOOL running;

- (void)addInput:(AVCaptureInput *)input;
- (void)addOutput:(AVCaptureOutput *)output;
- (void)startRunning;
- (void)stopRunning;
- (void)beginConfiguration;
- (void)commitConfiguration;
- (void)removeInput:(AVCaptureInput *)input;

@end

@interface AVCaptureConnection : NSObject
@end

#endif /* _AVCAPTURESESSION_H_ */