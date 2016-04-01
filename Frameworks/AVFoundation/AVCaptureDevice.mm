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

/** @Status Stub */
const float AVCaptureMaxAvailableTorchLevel = StubConstant();
/** @Status Stub */
const AVCaptureWhiteBalanceGains AVCaptureWhiteBalanceGainsCurrent = StubConstant();
/** @Status Stub */
const float AVCaptureLensPositionCurrent = StubConstant();
/** @Status Stub */
const float AVCaptureISOCurrent = StubConstant();
/** @Status Stub */
const float AVCaptureExposureTargetBiasCurrent = StubConstant();
/** @Status Stub */
const CMTime AVCaptureExposureDurationCurrent = StubConstant();

NSString* const AVCaptureDeviceWasConnectedNotification = @"AVCaptureDeviceWasConnectedNotification";
NSString* const AVCaptureDeviceWasDisconnectedNotification = @"AVCaptureDeviceWasDisconnectedNotification";
NSString* const AVCaptureDeviceSubjectAreaDidChangeNotification = @"AVCaptureDeviceSubjectAreaDidChangeNotification";

@implementation AVCaptureDevice
/**
@Status Stub
@Notes
*/
+ (NSArray*)devices {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (AVCaptureDevice*)deviceWithUniqueID:(NSString*)deviceUniqueID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (AVCaptureDevice*)defaultDeviceWithMediaType:(NSString*)mediaType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)devicesWithMediaType:(NSString*)mediaType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (void)requestAccessForMediaType:(NSString*)mediaType completionHandler:(void (^)(BOOL))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
+ (AVAuthorizationStatus)authorizationStatusForMediaType:(NSString*)mediaType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)lockForConfiguration:(NSError**)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)unlockForConfiguration {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)isFocusModeSupported:(AVCaptureFocusMode)focusMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)isExposureModeSupported:(AVCaptureExposureMode)exposureMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)isWhiteBalanceModeSupported:(AVCaptureWhiteBalanceMode)whiteBalanceMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)rampToVideoZoomFactor:(CGFloat)factor withRate:(float)rate {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)cancelVideoZoomRamp {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)isFlashModeSupported:(AVCaptureFlashMode)flashMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)isTorchModeSupported:(AVCaptureTorchMode)torchMode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)setTorchModeOnWithLevel:(float)torchLevel error:(NSError**)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)hasMediaType:(NSString*)mediaType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)supportsAVCaptureSessionPreset:(NSString*)preset {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setFocusModeLockedWithLensPosition:(float)lensPosition completionHandler:(void (^)(CMTime))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)setExposureModeCustomWithDuration:(CMTime)duration ISO:(float)ISO completionHandler:(void (^)(CMTime))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)setExposureTargetBias:(float)bias completionHandler:(void (^)(CMTime))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (AVCaptureWhiteBalanceChromaticityValues)chromaticityValuesForDeviceWhiteBalanceGains:(AVCaptureWhiteBalanceGains)whiteBalanceGains {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVCaptureWhiteBalanceGains)deviceWhiteBalanceGainsForChromaticityValues:(AVCaptureWhiteBalanceChromaticityValues)chromaticityValues {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVCaptureWhiteBalanceGains)deviceWhiteBalanceGainsForTemperatureAndTintValues:
    (AVCaptureWhiteBalanceTemperatureAndTintValues)tempAndTintValues {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)setWhiteBalanceModeLockedWithDeviceWhiteBalanceGains:(AVCaptureWhiteBalanceGains)whiteBalanceGains
                                           completionHandler:(void (^)(CMTime))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (AVCaptureWhiteBalanceTemperatureAndTintValues)temperatureAndTintValuesForDeviceWhiteBalanceGains:
    (AVCaptureWhiteBalanceGains)whiteBalanceGains {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
