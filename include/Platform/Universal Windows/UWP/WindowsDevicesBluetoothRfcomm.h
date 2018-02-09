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

// WindowsDevicesBluetoothRfcomm.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDBRRfcommDeviceService, WDBRRfcommDeviceServicesResult, WDBRRfcommServiceId, WDBRRfcommServiceProvider;
@protocol WDBRIRfcommServiceIdStatics, WDBRIRfcommServiceId, WDBRIRfcommDeviceServicesResult, WDBRIRfcommDeviceServiceStatics, WDBRIRfcommDeviceServiceStatics2, WDBRIRfcommDeviceService, WDBRIRfcommDeviceService2, WDBRIRfcommDeviceService3, WDBRIRfcommServiceProviderStatics, WDBRIRfcommServiceProvider, WDBRIRfcommServiceProvider2;

#include "WindowsFoundation.h"
#include "WindowsDevicesBluetooth.h"
#include "WindowsNetworkingSockets.h"
#include "WindowsNetworking.h"
#include "WindowsStorageStreams.h"
#include "WindowsDevicesEnumeration.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Bluetooth.Rfcomm.RfcommDeviceService
#ifndef __WDBRRfcommDeviceService_DEFINED__
#define __WDBRRfcommDeviceService_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBRRfcommDeviceService : RTObject <WFIClosable>
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDBRRfcommDeviceService*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector:(WDBRRfcommServiceId*)serviceId;
+ (NSString *)getDeviceSelectorForBluetoothDevice:(WDBBluetoothDevice*)bluetoothDevice;
+ (NSString *)getDeviceSelectorForBluetoothDeviceWithCacheMode:(WDBBluetoothDevice*)bluetoothDevice cacheMode:(WDBBluetoothCacheMode)cacheMode;
+ (NSString *)getDeviceSelectorForBluetoothDeviceAndServiceId:(WDBBluetoothDevice*)bluetoothDevice serviceId:(WDBRRfcommServiceId*)serviceId;
+ (NSString *)getDeviceSelectorForBluetoothDeviceAndServiceIdWithCacheMode:(WDBBluetoothDevice*)bluetoothDevice serviceId:(WDBRRfcommServiceId*)serviceId cacheMode:(WDBBluetoothCacheMode)cacheMode;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDBRRfcommDeviceService*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector:(WDBRRfcommServiceId*)serviceId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WNHostName* connectionHostName;
@property (readonly) NSString * connectionServiceName;
@property (readonly) WNSSocketProtectionLevel maxProtectionLevel;
@property (readonly) WNSSocketProtectionLevel protectionLevel;
@property (readonly) WDBRRfcommServiceId* serviceId;
@property (readonly) WDBBluetoothDevice* device;
@property (readonly) WDEDeviceAccessInformation* deviceAccessInformation;
- (void)getSdpRawAttributesAsyncWithSuccess:(void (^)(NSDictionary* /* unsigned int, RTObject<WSSIBuffer>* */))success failure:(void (^)(NSError*))failure;
- (void)getSdpRawAttributesWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode success:(void (^)(NSDictionary* /* unsigned int, RTObject<WSSIBuffer>* */))success failure:(void (^)(NSError*))failure;
- (void)close;
- (void)requestAccessAsyncWithSuccess:(void (^)(WDEDeviceAccessStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBRRfcommDeviceService_DEFINED__

// Windows.Devices.Bluetooth.Rfcomm.RfcommDeviceServicesResult
#ifndef __WDBRRfcommDeviceServicesResult_DEFINED__
#define __WDBRRfcommDeviceServicesResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBRRfcommDeviceServicesResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBBluetoothError error;
@property (readonly) NSArray* /* WDBRRfcommDeviceService* */ services;
@end

#endif // __WDBRRfcommDeviceServicesResult_DEFINED__

// Windows.Devices.Bluetooth.Rfcomm.RfcommServiceId
#ifndef __WDBRRfcommServiceId_DEFINED__
#define __WDBRRfcommServiceId_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBRRfcommServiceId : RTObject
+ (WDBRRfcommServiceId*)fromUuid:(WFGUID*)uuid;
+ (WDBRRfcommServiceId*)fromShortId:(unsigned int)shortId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* uuid;
+ (WDBRRfcommServiceId*)genericFileTransfer;
+ (WDBRRfcommServiceId*)obexFileTransfer;
+ (WDBRRfcommServiceId*)obexObjectPush;
+ (WDBRRfcommServiceId*)phoneBookAccessPce;
+ (WDBRRfcommServiceId*)phoneBookAccessPse;
+ (WDBRRfcommServiceId*)serialPort;
- (unsigned int)asShortId;
- (NSString *)asString;
@end

#endif // __WDBRRfcommServiceId_DEFINED__

// Windows.Devices.Bluetooth.Rfcomm.RfcommServiceProvider
#ifndef __WDBRRfcommServiceProvider_DEFINED__
#define __WDBRRfcommServiceProvider_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBRRfcommServiceProvider : RTObject
+ (void)createAsync:(WDBRRfcommServiceId*)serviceId success:(void (^)(WDBRRfcommServiceProvider*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableDictionary* /* unsigned int, RTObject<WSSIBuffer>* */ sdpRawAttributes;
@property (readonly) WDBRRfcommServiceId* serviceId;
- (void)startAdvertising:(WNSStreamSocketListener*)listener;
- (void)stopAdvertising;
- (void)startAdvertisingWithRadioDiscoverability:(WNSStreamSocketListener*)listener radioDiscoverable:(BOOL)radioDiscoverable;
@end

#endif // __WDBRRfcommServiceProvider_DEFINED__

