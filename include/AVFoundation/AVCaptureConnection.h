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
#import <CoreMedia/CMTime.h>
#import <AVFoundation/AVFoundationTypes.h>

@class NSArray;
@class AVCaptureOutput;
@class AVCaptureInputPort;
@class AVCaptureVideoPreviewLayer;

typedef NSInteger AVVideoFieldMode;
enum {
    AVVideoFieldModeBoth = 0,
    AVVideoFieldModeTopOnly = 1,
    AVVideoFieldModeBottomOnly = 2,
    AVVideoFieldModeDeinterlace = 3,
};

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureConnection : NSObject
+ (instancetype)connectionWithInputPorts:(NSArray*)ports output:(AVCaptureOutput*)output STUB_METHOD;
- (instancetype)initWithInputPorts:(NSArray*)ports output:(AVCaptureOutput*)output STUB_METHOD;
+ (instancetype)connectionWithInputPort:(AVCaptureInputPort*)port videoPreviewLayer:(AVCaptureVideoPreviewLayer*)layer STUB_METHOD;
- (instancetype)initWithInputPort:(AVCaptureInputPort*)port videoPreviewLayer:(AVCaptureVideoPreviewLayer*)layer STUB_METHOD;
@property (getter=isEnabled, nonatomic) BOOL enabled STUB_PROPERTY;
@property (readonly, getter=isActive, nonatomic) BOOL active STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* inputPorts STUB_PROPERTY;
@property (readonly, nonatomic) AVCaptureOutput* output STUB_PROPERTY;
@property (readonly, nonatomic) AVCaptureVideoPreviewLayer* videoPreviewLayer STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* audioChannels STUB_PROPERTY;
@property (nonatomic) AVCaptureVideoOrientation videoOrientation STUB_PROPERTY;
@property (readonly, getter=isVideoOrientationSupported, nonatomic) BOOL supportsVideoOrientation STUB_PROPERTY;
@property (nonatomic) CMTime videoMinFrameDuration STUB_PROPERTY;
@property (readonly, getter=isVideoMinFrameDurationSupported, nonatomic) BOOL supportsVideoMinFrameDuration STUB_PROPERTY;
@property (nonatomic) CMTime videoMaxFrameDuration STUB_PROPERTY;
@property (readonly, getter=isVideoMaxFrameDurationSupported, nonatomic) BOOL supportsVideoMaxFrameDuration STUB_PROPERTY;
@property (nonatomic) CGFloat videoScaleAndCropFactor STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat videoMaxScaleAndCropFactor STUB_PROPERTY;
@property (nonatomic) BOOL automaticallyAdjustsVideoMirroring STUB_PROPERTY;
@property (readonly, getter=isVideoMirroringSupported, nonatomic) BOOL supportsVideoMirroring STUB_PROPERTY;
@property (getter=isVideoMirrored, nonatomic) BOOL videoMirrored STUB_PROPERTY;
@property (nonatomic) BOOL enablesVideoStabilizationWhenAvailable STUB_PROPERTY;
@property (readonly, getter=isVideoStabilizationSupported, nonatomic) BOOL supportsVideoStabilization STUB_PROPERTY;
@property (readonly, getter=isVideoStabilizationEnabled, nonatomic) BOOL videoStabilizationEnabled STUB_PROPERTY;
@end
