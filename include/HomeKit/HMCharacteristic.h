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

#import <HomeKit/HomeKitExport.h>
#import <Foundation/NSObject.h>

@class NSArray;
@class NSData;
@class NSError;
@class NSString;
@class HMCharacteristicMetadata;
@class HMService;

typedef NS_ENUM(NSInteger, HMCharacteristicValueDoorState) {
    HMCharacteristicValueDoorStateOpen = 0,
    HMCharacteristicValueDoorStateClosed,
    HMCharacteristicValueDoorStateOpening,
    HMCharacteristicValueDoorStateClosing,
    HMCharacteristicValueDoorStateStopped,
};

typedef NS_ENUM(NSInteger, HMCharacteristicValueHeatingCooling) {
    HMCharacteristicValueHeatingCoolingOff = 0,
    HMCharacteristicValueHeatingCoolingHeat,
    HMCharacteristicValueHeatingCoolingCool,
    HMCharacteristicValueHeatingCoolingAuto,
};

typedef NS_ENUM(NSInteger, HMCharacteristicValueRotationDirection) {
    HMCharacteristicValueRotationDirectionClockwise = 0,
    HMCharacteristicValueRotationDirectionCounterClockwise,
};

typedef NS_ENUM(NSInteger, HMCharacteristicValueTemperatureUnit) {
    HMCharacteristicValueTemperatureUnitCelsius = 0,
    HMCharacteristicValueTemperatureUnitFahrenheit,
};

typedef NS_ENUM(NSInteger, HMCharacteristicValueLockMechanismState) {
    HMCharacteristicValueLockMechanismStateUnsecured = 0,
    HMCharacteristicValueLockMechanismStateSecured,
    HMCharacteristicValueLockMechanismStateJammed,
    HMCharacteristicValueLockMechanismStateUnknown,
};

typedef NS_ENUM(NSInteger, HMCharacteristicValueLockMechanism) {
    HMCharacteristicValueLockMechanismLastKnownActionSecuredUsingPhysicalMovementInterior = 0,
    HMCharacteristicValueLockMechanismLastKnownActionUnsecuredUsingPhysicalMovementInterior,
    HMCharacteristicValueLockMechanismLastKnownActionSecuredUsingPhysicalMovementExterior,
    HMCharacteristicValueLockMechanismLastKnownActionUnsecuredUsingPhysicalMovementExterior,
    HMCharacteristicValueLockMechanismLastKnownActionSecuredWithKeypad,
    HMCharacteristicValueLockMechanismLastKnownActionUnsecuredWithKeypad,
    HMCharacteristicValueLockMechanismLastKnownActionSecuredRemotely,
    HMCharacteristicValueLockMechanismLastKnownActionUnsecuredRemotely,
    HMCharacteristicValueLockMechanismLastKnownActionSecuredWithAutomaticSecureTimeout,
};

HOMEKIT_EXPORT NSString* const HMCharacteristicPropertySupportsEventNotification;
HOMEKIT_EXPORT NSString* const HMCharacteristicPropertyReadable;
HOMEKIT_EXPORT NSString* const HMCharacteristicPropertyWritable;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypePowerState;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeHue;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeSaturation;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeBrightness;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeTemperatureUnits;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeCurrentTemperature;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeTargetTemperature;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeCurrentHeatingCooling;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeTargetHeatingCooling;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeCoolingThreshold;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeHeatingThreshold;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeCurrentRelativeHumidity;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeTargetRelativeHumidity;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeCurrentDoorState;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeTargetDoorState;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeObstructionDetected;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeName;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeManufacturer;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeModel;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeSerialNumber;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeIdentify;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeRotationDirection;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeRotationSpeed;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeOutletInUse;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeVersion;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeLogs;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeAudioFeedback;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeAdminOnlyAccess;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeMotionDetected;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeCurrentLockMechanismState;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeTargetLockMechanismState;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeLockMechanismLastKnownAction;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeLockManagementControlPoint;
HOMEKIT_EXPORT NSString* const HMCharacteristicTypeLockManagementAutoSecureTimeout;

HOMEKIT_EXPORT_CLASS
@interface HMCharacteristic : NSObject
@property (readonly, copy, nonatomic) NSString* characteristicType STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* properties STUB_PROPERTY;
@property (readonly, nonatomic, strong) HMCharacteristicMetadata* metadata STUB_PROPERTY;
- (void)enableNotification:(BOOL)enable completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, getter=isNotificationEnabled, nonatomic) BOOL notificationEnabled STUB_PROPERTY;
@property (readonly, copy, nonatomic) id value STUB_PROPERTY;
- (void)readValueWithCompletionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)writeValue:(id)value completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)updateAuthorizationData:(NSData*)data completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, nonatomic, weak) HMService* service STUB_PROPERTY;

@end
