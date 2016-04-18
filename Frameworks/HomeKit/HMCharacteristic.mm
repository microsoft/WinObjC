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

#import <StubReturn.h>

#import <HomeKit/HMCharacteristic.h>
#import "AssertARCEnabled.h"

NSString* const HMCharacteristicPropertySupportsEventNotification = @"HMCharacteristicPropertySupportsEventNotification";
NSString* const HMCharacteristicPropertyReadable = @"HMCharacteristicPropertyReadable";
NSString* const HMCharacteristicPropertyWritable = @"HMCharacteristicPropertyWritable";
NSString* const HMCharacteristicTypePowerState = @"HMCharacteristicTypePowerState";
NSString* const HMCharacteristicTypeHue = @"HMCharacteristicTypeHue";
NSString* const HMCharacteristicTypeSaturation = @"HMCharacteristicTypeSaturation";
NSString* const HMCharacteristicTypeBrightness = @"HMCharacteristicTypeBrightness";
NSString* const HMCharacteristicTypeTemperatureUnits = @"HMCharacteristicTypeTemperatureUnits";
NSString* const HMCharacteristicTypeCurrentTemperature = @"HMCharacteristicTypeCurrentTemperature";
NSString* const HMCharacteristicTypeTargetTemperature = @"HMCharacteristicTypeTargetTemperature";
NSString* const HMCharacteristicTypeCurrentHeatingCooling = @"HMCharacteristicTypeCurrentHeatingCooling";
NSString* const HMCharacteristicTypeTargetHeatingCooling = @"HMCharacteristicTypeTargetHeatingCooling";
NSString* const HMCharacteristicTypeCoolingThreshold = @"HMCharacteristicTypeCoolingThreshold";
NSString* const HMCharacteristicTypeHeatingThreshold = @"HMCharacteristicTypeHeatingThreshold";
NSString* const HMCharacteristicTypeCurrentRelativeHumidity = @"HMCharacteristicTypeCurrentRelativeHumidity";
NSString* const HMCharacteristicTypeTargetRelativeHumidity = @"HMCharacteristicTypeTargetRelativeHumidity";
NSString* const HMCharacteristicTypeCurrentDoorState = @"HMCharacteristicTypeCurrentDoorState";
NSString* const HMCharacteristicTypeTargetDoorState = @"HMCharacteristicTypeTargetDoorState";
NSString* const HMCharacteristicTypeObstructionDetected = @"HMCharacteristicTypeObstructionDetected";
NSString* const HMCharacteristicTypeName = @"HMCharacteristicTypeName";
NSString* const HMCharacteristicTypeManufacturer = @"HMCharacteristicTypeManufacturer";
NSString* const HMCharacteristicTypeModel = @"HMCharacteristicTypeModel";
NSString* const HMCharacteristicTypeSerialNumber = @"HMCharacteristicTypeSerialNumber";
NSString* const HMCharacteristicTypeIdentify = @"HMCharacteristicTypeIdentify";
NSString* const HMCharacteristicTypeRotationDirection = @"HMCharacteristicTypeRotationDirection";
NSString* const HMCharacteristicTypeRotationSpeed = @"HMCharacteristicTypeRotationSpeed";
NSString* const HMCharacteristicTypeOutletInUse = @"HMCharacteristicTypeOutletInUse";
NSString* const HMCharacteristicTypeVersion = @"HMCharacteristicTypeVersion";
NSString* const HMCharacteristicTypeLogs = @"HMCharacteristicTypeLogs";
NSString* const HMCharacteristicTypeAudioFeedback = @"HMCharacteristicTypeAudioFeedback";
NSString* const HMCharacteristicTypeAdminOnlyAccess = @"HMCharacteristicTypeAdminOnlyAccess";
NSString* const HMCharacteristicTypeMotionDetected = @"HMCharacteristicTypeMotionDetected";
NSString* const HMCharacteristicTypeCurrentLockMechanismState = @"HMCharacteristicTypeCurrentLockMechanismState";
NSString* const HMCharacteristicTypeTargetLockMechanismState = @"HMCharacteristicTypeTargetLockMechanismState";
NSString* const HMCharacteristicTypeLockMechanismLastKnownAction = @"HMCharacteristicTypeLockMechanismLastKnownAction";
NSString* const HMCharacteristicTypeLockManagementControlPoint = @"HMCharacteristicTypeLockManagementControlPoint";
NSString* const HMCharacteristicTypeLockManagementAutoSecureTimeout = @"HMCharacteristicTypeLockManagementAutoSecureTimeout";

@implementation HMCharacteristic

/**
 @Status Stub
 @Notes
*/
- (void)enableNotification:(BOOL)enable completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)readValueWithCompletionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeValue:(id)value completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateAuthorizationData:(NSData*)data completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

@end
