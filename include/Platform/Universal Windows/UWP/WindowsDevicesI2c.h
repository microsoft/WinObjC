//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsDevicesI2c.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESI2CEXPORT
#define OBJCUWPWINDOWSDEVICESI2CEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesI2c.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDII2cConnectionSettings, WDII2cDevice, WDII2cController;
@class WDII2cTransferResult;
@protocol WDIII2cConnectionSettingsFactory, WDIII2cConnectionSettings, WDIII2cDeviceStatics, WDIII2cController, WDIII2cControllerStatics, WDIII2cDevice;

// Windows.Devices.I2c.I2cBusSpeed
enum _WDII2cBusSpeed {
    WDII2cBusSpeedStandardMode = 0,
    WDII2cBusSpeedFastMode = 1,
};
typedef unsigned WDII2cBusSpeed;

// Windows.Devices.I2c.I2cTransferStatus
enum _WDII2cTransferStatus {
    WDII2cTransferStatusFullTransfer = 0,
    WDII2cTransferStatusPartialTransfer = 1,
    WDII2cTransferStatusSlaveAddressNotAcknowledged = 2,
    WDII2cTransferStatusClockStretchTimeout = 3,
    WDII2cTransferStatusUnknownError = 4,
};
typedef unsigned WDII2cTransferStatus;

// Windows.Devices.I2c.I2cSharingMode
enum _WDII2cSharingMode {
    WDII2cSharingModeExclusive = 0,
    WDII2cSharingModeShared = 1,
};
typedef unsigned WDII2cSharingMode;

#include "WindowsDevicesI2cProvider.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Devices.I2c.I2cTransferResult
OBJCUWPWINDOWSDEVICESI2CEXPORT
@interface WDII2cTransferResult : NSObject
+ (instancetype)new;
@property WDII2cTransferStatus status;
@property unsigned int bytesTransferred;
@end

// Windows.Devices.I2c.II2cDeviceStatics
#ifndef __WDIII2cDeviceStatics_DEFINED__
#define __WDIII2cDeviceStatics_DEFINED__

@protocol WDIII2cDeviceStatics
- (NSString *)getDeviceSelector;
- (NSString *)getDeviceSelectorFromFriendlyName:(NSString *)friendlyName;
- (void)fromIdAsync:(NSString *)deviceId settings:(WDII2cConnectionSettings*)settings success:(void (^)(WDII2cDevice*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSDEVICESI2CEXPORT
@interface WDIII2cDeviceStatics : RTObject <WDIII2cDeviceStatics>
@end

#endif // __WDIII2cDeviceStatics_DEFINED__

// Windows.Devices.I2c.I2cConnectionSettings
#ifndef __WDII2cConnectionSettings_DEFINED__
#define __WDII2cConnectionSettings_DEFINED__

OBJCUWPWINDOWSDEVICESI2CEXPORT
@interface WDII2cConnectionSettings : RTObject
+ (WDII2cConnectionSettings*)make:(int)slaveAddress ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int slaveAddress;
@property WDII2cSharingMode sharingMode;
@property WDII2cBusSpeed busSpeed;
@end

#endif // __WDII2cConnectionSettings_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSDEVICESI2CEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.I2c.I2cDevice
#ifndef __WDII2cDevice_DEFINED__
#define __WDII2cDevice_DEFINED__

OBJCUWPWINDOWSDEVICESI2CEXPORT
@interface WDII2cDevice : RTObject <WFIClosable>
+ (NSString *)getDeviceSelector;
+ (NSString *)getDeviceSelectorFromFriendlyName:(NSString *)friendlyName;
+ (void)fromIdAsync:(NSString *)deviceId settings:(WDII2cConnectionSettings*)settings success:(void (^)(WDII2cDevice*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDII2cConnectionSettings* connectionSettings;
@property (readonly) NSString * deviceId;
- (void)write:(NSArray* /* uint8_t */)buffer;
- (WDII2cTransferResult*)writePartial:(NSArray* /* uint8_t */)buffer;
- (void)read:(NSArray* /* uint8_t */*)buffer;
- (WDII2cTransferResult*)readPartial:(NSArray* /* uint8_t */*)buffer;
- (void)writeRead:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer;
- (WDII2cTransferResult*)writeReadPartial:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer;
- (void)close;
@end

#endif // __WDII2cDevice_DEFINED__

// Windows.Devices.I2c.I2cController
#ifndef __WDII2cController_DEFINED__
#define __WDII2cController_DEFINED__

OBJCUWPWINDOWSDEVICESI2CEXPORT
@interface WDII2cController : RTObject
+ (void)getControllersAsync:(RTObject<WDIPII2cProvider>*)provider success:(void (^)(NSArray* /* WDII2cController* */))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDII2cController*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WDII2cDevice*)getDevice:(WDII2cConnectionSettings*)settings;
@end

#endif // __WDII2cController_DEFINED__

