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

// WindowsDevicesI2cProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESI2CPROVIDEREXPORT
#define OBJCUWPWINDOWSDEVICESI2CPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesI2cProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDIPProviderI2cConnectionSettings;
@class WDIPProviderI2cTransferResult;
@protocol WDIPIProviderI2cConnectionSettings, WDIPII2cControllerProvider, WDIPII2cProvider, WDIPII2cDeviceProvider;

// Windows.Devices.I2c.Provider.ProviderI2cBusSpeed
enum _WDIPProviderI2cBusSpeed {
    WDIPProviderI2cBusSpeedStandardMode = 0,
    WDIPProviderI2cBusSpeedFastMode = 1,
};
typedef unsigned WDIPProviderI2cBusSpeed;

// Windows.Devices.I2c.Provider.ProviderI2cTransferStatus
enum _WDIPProviderI2cTransferStatus {
    WDIPProviderI2cTransferStatusFullTransfer = 0,
    WDIPProviderI2cTransferStatusPartialTransfer = 1,
    WDIPProviderI2cTransferStatusSlaveAddressNotAcknowledged = 2,
};
typedef unsigned WDIPProviderI2cTransferStatus;

// Windows.Devices.I2c.Provider.ProviderI2cSharingMode
enum _WDIPProviderI2cSharingMode {
    WDIPProviderI2cSharingModeExclusive = 0,
    WDIPProviderI2cSharingModeShared = 1,
};
typedef unsigned WDIPProviderI2cSharingMode;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Devices.I2c.Provider.ProviderI2cTransferResult
OBJCUWPWINDOWSDEVICESI2CPROVIDEREXPORT
@interface WDIPProviderI2cTransferResult : NSObject
+ (instancetype)new;
@property WDIPProviderI2cTransferStatus status;
@property unsigned int bytesTransferred;
@end

// Windows.Devices.I2c.Provider.II2cControllerProvider
#ifndef __WDIPII2cControllerProvider_DEFINED__
#define __WDIPII2cControllerProvider_DEFINED__

@protocol WDIPII2cControllerProvider
- (RTObject<WDIPII2cDeviceProvider>*)getDeviceProvider:(WDIPProviderI2cConnectionSettings*)settings;
@end

OBJCUWPWINDOWSDEVICESI2CPROVIDEREXPORT
@interface WDIPII2cControllerProvider : RTObject <WDIPII2cControllerProvider>
@end

#endif // __WDIPII2cControllerProvider_DEFINED__

// Windows.Devices.I2c.Provider.II2cProvider
#ifndef __WDIPII2cProvider_DEFINED__
#define __WDIPII2cProvider_DEFINED__

@protocol WDIPII2cProvider
- (void)getControllersAsyncWithSuccess:(void (^)(NSArray* /* RTObject<WDIPII2cControllerProvider>* */))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSDEVICESI2CPROVIDEREXPORT
@interface WDIPII2cProvider : RTObject <WDIPII2cProvider>
@end

#endif // __WDIPII2cProvider_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSDEVICESI2CPROVIDEREXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.I2c.Provider.II2cDeviceProvider
#ifndef __WDIPII2cDeviceProvider_DEFINED__
#define __WDIPII2cDeviceProvider_DEFINED__

@protocol WDIPII2cDeviceProvider <WFIClosable>
@property (readonly) NSString * deviceId;
- (void)write:(NSArray* /* uint8_t */)buffer;
- (WDIPProviderI2cTransferResult*)writePartial:(NSArray* /* uint8_t */)buffer;
- (void)read:(NSArray* /* uint8_t */*)buffer;
- (WDIPProviderI2cTransferResult*)readPartial:(NSArray* /* uint8_t */*)buffer;
- (void)writeRead:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer;
- (WDIPProviderI2cTransferResult*)writeReadPartial:(NSArray* /* uint8_t */)writeBuffer readBuffer:(NSArray* /* uint8_t */*)readBuffer;
- (void)close;
@end

OBJCUWPWINDOWSDEVICESI2CPROVIDEREXPORT
@interface WDIPII2cDeviceProvider : RTObject <WDIPII2cDeviceProvider>
@end

#endif // __WDIPII2cDeviceProvider_DEFINED__

// Windows.Devices.I2c.Provider.ProviderI2cConnectionSettings
#ifndef __WDIPProviderI2cConnectionSettings_DEFINED__
#define __WDIPProviderI2cConnectionSettings_DEFINED__

OBJCUWPWINDOWSDEVICESI2CPROVIDEREXPORT
@interface WDIPProviderI2cConnectionSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int slaveAddress;
@property WDIPProviderI2cSharingMode sharingMode;
@property WDIPProviderI2cBusSpeed busSpeed;
@end

#endif // __WDIPProviderI2cConnectionSettings_DEFINED__

