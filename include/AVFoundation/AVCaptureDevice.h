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
#import <CoreGraphics/CGGeometry.h>
#import <CoreMedia/CMTime.h>

@class NSArray;
@class NSString;
@class NSError;
@class AVCaptureDeviceFormat;

typedef NSInteger AVCaptureDevicePosition;

typedef enum : NSInteger { AVCaptureFlashModeOff = 0, AVCaptureFlashModeOn = 1, AVCaptureFlashModeAuto = 2 } AVCaptureFlashMode;

typedef enum : NSInteger { AVCaptureTorchModeOff = 0, AVCaptureTorchModeOn = 1, AVCaptureTorchModeAuto = 2 } AVCaptureTorchMode;

typedef enum : NSInteger {
    AVCaptureFocusModeLocked = 0,
    AVCaptureFocusModeAutoFocus = 1,
    AVCaptureFocusModeContinuousAutoFocus = 2,
} AVCaptureFocusMode;

typedef enum : NSInteger {
    AVCaptureExposureModeLocked = 0,
    AVCaptureExposureModeAutoExpose = 1,
    AVCaptureExposureModeContinuousAutoExposure = 2,
    AVCaptureExposureModeCustom = 3,
} AVCaptureExposureMode;

typedef enum : NSInteger {
    AVCaptureWhiteBalanceModeLocked = 0,
    AVCaptureWhiteBalanceModeAutoWhiteBalance = 1,
    AVCaptureWhiteBalanceModeContinuousAutoWhiteBalance = 2,
} AVCaptureWhiteBalanceMode;

typedef struct {
    float redGain;
    float blueGain;
    float greenGain;
} AVCaptureWhiteBalanceGains;

typedef struct {
    float x;
    float y;
} AVCaptureWhiteBalanceChromaticityValues;

typedef struct {
    float temperature;
    float tint;
} AVCaptureWhiteBalanceTemperatureAndTintValues;

typedef enum : NSInteger {
    AVAuthorizationStatusNotDetermined = 0,
    AVAuthorizationStatusRestricted,
    AVAuthorizationStatusDenied,
    AVAuthorizationStatusAuthorized
} AVAuthorizationStatus;

enum { AVCaptureDevicePositionUnspecified = 0, AVCaptureDevicePositionBack = 1, AVCaptureDevicePositionFront = 2 };
typedef enum: NSInteger {
    AVCaptureAutoFocusRangeRestrictionNone = 0,
    AVCaptureAutoFocusRangeRestrictionNear = 1,
    AVCaptureAutoFocusRangeRestrictionFar = 2,
} AVCaptureAutoFocusRangeRestriction;

AVFOUNDATION_EXPORT const float AVCaptureMaxAvailableTorchLevel;
AVFOUNDATION_EXPORT const AVCaptureWhiteBalanceGains AVCaptureWhiteBalanceGainsCurrent;
AVFOUNDATION_EXPORT const float AVCaptureLensPositionCurrent;
AVFOUNDATION_EXPORT const float AVCaptureISOCurrent;
AVFOUNDATION_EXPORT const float AVCaptureExposureTargetBiasCurrent;
AVFOUNDATION_EXPORT const CMTime AVCaptureExposureDurationCurrent;

AVFOUNDATION_EXPORT NSString* const AVCaptureDeviceWasConnectedNotification;
AVFOUNDATION_EXPORT NSString* const AVCaptureDeviceWasDisconnectedNotification;
AVFOUNDATION_EXPORT NSString* const AVCaptureDeviceSubjectAreaDidChangeNotification;

AVFOUNDATION_EXPORT_CLASS
@interface AVCaptureDevice : NSObject <NSObject>
+ (NSArray*)devices STUB_METHOD;
+ (AVCaptureDevice*)deviceWithUniqueID:(NSString*)deviceUniqueID STUB_METHOD;
+ (AVCaptureDevice*)defaultDeviceWithMediaType:(NSString*)mediaType STUB_METHOD;
+ (NSArray*)devicesWithMediaType:(NSString*)mediaType STUB_METHOD;
+ (void)requestAccessForMediaType:(NSString*)mediaType completionHandler:(void (^)(BOOL))handler STUB_METHOD;
+ (AVAuthorizationStatus)authorizationStatusForMediaType:(NSString*)mediaType STUB_METHOD;
- (BOOL)lockForConfiguration:(NSError**)outError STUB_METHOD;
- (void)unlockForConfiguration STUB_METHOD;
@property (readonly, nonatomic) NSArray* formats STUB_PROPERTY;
@property (retain, nonatomic) AVCaptureDeviceFormat* activeFormat STUB_PROPERTY;
@property (nonatomic) AVCaptureFocusMode focusMode STUB_PROPERTY;
- (BOOL)isFocusModeSupported:(AVCaptureFocusMode)focusMode STUB_METHOD;
@property (nonatomic) CGPoint focusPointOfInterest STUB_PROPERTY;
@property (readonly, getter=isFocusPointOfInterestSupported, nonatomic) BOOL focusPointOfInterestSupported STUB_PROPERTY;
@property (readonly, getter=isAdjustingFocus, nonatomic) BOOL adjustingFocus STUB_PROPERTY;
@property (getter=isSmoothAutoFocusEnabled, nonatomic) BOOL smoothAutoFocusEnabled STUB_PROPERTY;
@property (readonly, getter=isSmoothAutoFocusSupported, nonatomic) BOOL smoothAutoFocusSupported STUB_PROPERTY;
@property (nonatomic) AVCaptureAutoFocusRangeRestriction autoFocusRangeRestriction STUB_PROPERTY;
@property (readonly, getter=isAutoFocusRangeRestrictionSupported, nonatomic) BOOL autoFocusRangeRestrictionSupported STUB_PROPERTY;
@property (readonly, getter=isAdjustingExposure, nonatomic) BOOL adjustingExposure STUB_PROPERTY;
@property (nonatomic) AVCaptureExposureMode exposureMode STUB_PROPERTY;
- (BOOL)isExposureModeSupported:(AVCaptureExposureMode)exposureMode STUB_METHOD;
@property (nonatomic) CGPoint exposurePointOfInterest STUB_PROPERTY;
@property (readonly, getter=isExposurePointOfInterestSupported, nonatomic) BOOL exposurePointOfInterestSupported STUB_PROPERTY;
- (BOOL)isWhiteBalanceModeSupported:(AVCaptureWhiteBalanceMode)whiteBalanceMode STUB_METHOD;
@property (nonatomic) AVCaptureWhiteBalanceMode whiteBalanceMode STUB_PROPERTY;
@property (readonly, getter=isAdjustingWhiteBalance, nonatomic) BOOL adjustingWhiteBalance STUB_PROPERTY;
@property (nonatomic) CGFloat videoZoomFactor STUB_PROPERTY;
- (void)rampToVideoZoomFactor:(CGFloat)factor withRate:(float)rate STUB_METHOD;
- (void)cancelVideoZoomRamp STUB_METHOD;
@property (readonly, getter=isRampingVideoZoom, nonatomic) BOOL rampingVideoZoom STUB_PROPERTY;
@property (readonly, nonatomic) BOOL hasFlash STUB_PROPERTY;
@property (nonatomic) AVCaptureFlashMode flashMode STUB_PROPERTY;
- (BOOL)isFlashModeSupported:(AVCaptureFlashMode)flashMode STUB_METHOD;
@property (readonly, getter=isFlashActive, nonatomic) BOOL flashActive STUB_PROPERTY;
@property (readonly, getter=isFlashAvailable, nonatomic) BOOL flashAvailable STUB_PROPERTY;
@property (readonly, nonatomic) BOOL hasTorch STUB_PROPERTY;
@property (readonly, getter=isTorchAvailable, nonatomic) BOOL torchAvailable STUB_PROPERTY;
@property (readonly, getter=isTorchActive, nonatomic) BOOL torchActive STUB_PROPERTY;
@property (readonly, nonatomic) float torchLevel STUB_PROPERTY;
- (BOOL)isTorchModeSupported:(AVCaptureTorchMode)torchMode STUB_METHOD;
@property (nonatomic) AVCaptureTorchMode torchMode STUB_PROPERTY;
- (BOOL)setTorchModeOnWithLevel:(float)torchLevel error:(NSError**)outError STUB_METHOD;
@property (readonly, getter=isLowLightBoostSupported, nonatomic) BOOL lowLightBoostSupported STUB_PROPERTY;
@property (readonly, getter=isLowLightBoostEnabled, nonatomic) BOOL lowLightBoostEnabled STUB_PROPERTY;
@property (nonatomic) BOOL automaticallyEnablesLowLightBoostWhenAvailable STUB_PROPERTY;
@property (nonatomic) CMTime activeVideoMinFrameDuration STUB_PROPERTY;
@property (nonatomic) CMTime activeVideoMaxFrameDuration STUB_PROPERTY;
@property (getter=isSubjectAreaChangeMonitoringEnabled, nonatomic) BOOL subjectAreaChangeMonitoringEnabled STUB_PROPERTY;
@property (readonly, getter=isConnected, nonatomic) BOOL connected STUB_PROPERTY;
@property (readonly, nonatomic) AVCaptureDevicePosition position STUB_PROPERTY;
- (BOOL)hasMediaType:(NSString*)mediaType STUB_METHOD;
@property (readonly, nonatomic) NSString* modelID STUB_PROPERTY;
@property (readonly, nonatomic) NSString* localizedName STUB_PROPERTY;
@property (readonly, nonatomic) NSString* uniqueID STUB_PROPERTY;
- (BOOL)supportsAVCaptureSessionPreset:(NSString*)preset STUB_METHOD;
@property (readonly, nonatomic) float lensAperture STUB_PROPERTY;
@property (readonly, nonatomic) float lensPosition STUB_PROPERTY;
- (void)setFocusModeLockedWithLensPosition:(float)lensPosition completionHandler:(void (^)(CMTime))handler STUB_METHOD;
@property (readonly, nonatomic) CMTime exposureDuration STUB_PROPERTY;
- (void)setExposureModeCustomWithDuration:(CMTime)duration ISO:(float)ISO completionHandler:(void (^)(CMTime))handler STUB_METHOD;
@property (readonly, nonatomic) float exposureTargetOffset STUB_PROPERTY;
@property (readonly, nonatomic) float exposureTargetBias STUB_PROPERTY;
@property (readonly, nonatomic) float maxExposureTargetBias STUB_PROPERTY;
@property (readonly, nonatomic) float minExposureTargetBias STUB_PROPERTY;
- (void)setExposureTargetBias:(float)bias completionHandler:(void (^)(CMTime))handler STUB_METHOD;
- (AVCaptureWhiteBalanceChromaticityValues)chromaticityValuesForDeviceWhiteBalanceGains:(AVCaptureWhiteBalanceGains)whiteBalanceGains
    STUB_METHOD;
@property (readonly, nonatomic) AVCaptureWhiteBalanceGains deviceWhiteBalanceGains STUB_PROPERTY;
@property (readonly, nonatomic) float maxWhiteBalanceGain STUB_PROPERTY;
- (AVCaptureWhiteBalanceGains)deviceWhiteBalanceGainsForChromaticityValues:(AVCaptureWhiteBalanceChromaticityValues)chromaticityValues
    STUB_METHOD;
- (AVCaptureWhiteBalanceGains)deviceWhiteBalanceGainsForTemperatureAndTintValues:
    (AVCaptureWhiteBalanceTemperatureAndTintValues)tempAndTintValues STUB_METHOD;
@property (readonly, nonatomic) AVCaptureWhiteBalanceGains grayWorldDeviceWhiteBalanceGains STUB_PROPERTY;
- (void)setWhiteBalanceModeLockedWithDeviceWhiteBalanceGains:(AVCaptureWhiteBalanceGains)whiteBalanceGains
                                           completionHandler:(void (^)(CMTime))handler STUB_METHOD;
- (AVCaptureWhiteBalanceTemperatureAndTintValues)temperatureAndTintValuesForDeviceWhiteBalanceGains:
    (AVCaptureWhiteBalanceGains)whiteBalanceGains STUB_METHOD;
@property (readonly, nonatomic) float ISO STUB_PROPERTY;
@property (nonatomic) BOOL automaticallyAdjustsVideoHDREnabled STUB_PROPERTY;
@property (getter=isVideoHDREnabled, nonatomic) BOOL videoHDREnabled STUB_PROPERTY;
@end
