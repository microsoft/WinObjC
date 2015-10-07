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

#ifndef _AVCAPTUREDEVICE_H_
#define _AVCAPTUREDEVICE_H_

#import <Foundation/Foundation.h>

typedef enum : NSInteger {
    AVCaptureTorchModeOff    = 0,
    AVCaptureTorchModeOn     = 1,
    AVCaptureTorchModeAuto   = 2
} AVCaptureTorchMode;

typedef enum : NSInteger {
    AVCaptureFocusModeLocked                = 0,
    AVCaptureFocusModeAutoFocus             = 1,
    AVCaptureFocusModeContinuousAutoFocus   = 2,
} AVCaptureFocusMode;

typedef enum : NSInteger {
    AVCaptureDevicePositionUnspecified = 0,
    AVCaptureDevicePositionBack  = 1,
    AVCaptureDevicePositionFront = 2
} AVCaptureDevicePosition;

@class NSArray;
@class NSError;

@interface AVCaptureDevice : NSObject

@property(nonatomic) AVCaptureFocusMode focusMode;
@property(nonatomic) AVCaptureTorchMode torchMode;
@property(nonatomic, readonly) BOOL hasTorch;
@property(nonatomic, readonly) AVCaptureDevicePosition position;

+ (AVCaptureDevice *)defaultDeviceWithMediaType:(NSString *)mediaType;
+ (NSArray *)devicesWithMediaType:(NSString *)mediaType;

- (BOOL)lockForConfiguration:(NSError **)outError;
- (void)unlockForConfiguration;
- (BOOL)isFocusModeSupported:(AVCaptureFocusMode)focusMode;

@end

#endif /* _AVCAPTUREDEVICE_H_ */