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
#import <CoreMedia/CMFormatDescription.h>
#import <CoreMedia/CMTime.h>

@class NSString;
@class NSArray;

typedef NSInteger AVCaptureVideoStabilizationMode;
typedef NSInteger AVCaptureAutoFocusSystem;
enum {
    AVCaptureVideoStabilizationModeOff = 0,
    AVCaptureVideoStabilizationModeStandard = 1,
    AVCaptureVideoStabilizationModeCinematic = 2,
    AVCaptureVideoStabilizationModeAuto = -1,
};
enum {
    AVCaptureAutoFocusSystemNone = 0,
    AVCaptureAutoFocusSystemContrastDetection = 1,
    AVCaptureAutoFocusSystemPhaseDetection = 2,
};

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureDeviceFormat : NSObject
@property (readonly, nonatomic) NSString* mediaType STUB_PROPERTY;
@property (readonly, nonatomic) CMFormatDescriptionRef formatDescription STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* videoSupportedFrameRateRanges STUB_PROPERTY;
@property (readonly, getter=isVideoBinned, nonatomic) BOOL videoBinned STUB_PROPERTY;
@property (readonly, nonatomic) float videoFieldOfView STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat videoMaxZoomFactor STUB_PROPERTY;
@property (readonly, getter=isVideoStabilizationSupported, nonatomic) BOOL videoStabilizationSupported STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat videoZoomFactorUpscaleThreshold STUB_PROPERTY;
@property (readonly, getter=isVideoHDRSupported, nonatomic) BOOL videoHDRSupported STUB_PROPERTY;
@property (readonly, nonatomic) CMVideoDimensions highResolutionStillImageDimensions STUB_PROPERTY;
@property (readonly, nonatomic) CMTime maxExposureDuration STUB_PROPERTY;
@property (readonly, nonatomic) float maxISO STUB_PROPERTY;
@property (readonly, nonatomic) CMTime minExposureDuration STUB_PROPERTY;
@property (readonly, nonatomic) float minISO STUB_PROPERTY;
@property (readonly, nonatomic) AVCaptureAutoFocusSystem autoFocusSystem STUB_PROPERTY;
- (BOOL)isVideoStabilizationModeSupported:(AVCaptureVideoStabilizationMode)videoStabilizationMode STUB_METHOD;
@end
