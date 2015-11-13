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

// WindowsDevicesBluetoothRfcomm.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDBRRfcommDeviceService, WDBRRfcommServiceId, WDBRRfcommServiceProvider;
@protocol WDBRIRfcommServiceIdStatics
, WDBRIRfcommServiceId, WDBRIRfcommDeviceServiceStatics, WDBRIRfcommDeviceService, WDBRIRfcommDeviceService2,
    WDBRIRfcommServiceProviderStatics, WDBRIRfcommServiceProvider;

#include "WindowsDevicesBluetooth.h"
#include "WindowsFoundation.h"
#include "WindowsNetworkingSockets.h"
#include "WindowsNetworking.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Bluetooth.Rfcomm.RfcommDeviceService
#ifndef __WDBRRfcommDeviceService_DEFINED__
#define __WDBRRfcommDeviceService_DEFINED__

WINRT_EXPORT
@interface WDBRRfcommDeviceService : RTObject <WFIClosable>
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDBRRfcommDeviceService*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector:(WDBRRfcommServiceId*)serviceId;
@property (readonly) WNHostName* connectionHostName;
@property (readonly) NSString* connectionServiceName;
@property (readonly) WNSSocketProtectionLevel maxProtectionLevel;
@property (readonly) WNSSocketProtectionLevel protectionLevel;
@property (readonly) WDBRRfcommServiceId* serviceId;
@property (readonly) WDBBluetoothDevice* device;
- (void)getSdpRawAttributesAsyncWithSuccess:(void (^)(NSDictionary*))success failure:(void (^)(NSError*))failure;
- (void)getSdpRawAttributesWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode
                                      success:(void (^)(NSDictionary*))success
                                      failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WDBRRfcommDeviceService_DEFINED__

// Windows.Devices.Bluetooth.Rfcomm.RfcommServiceId
#ifndef __WDBRRfcommServiceId_DEFINED__
#define __WDBRRfcommServiceId_DEFINED__

WINRT_EXPORT
@interface WDBRRfcommServiceId : RTObject
+ (WDBRRfcommServiceId*)fromUuid:(WFGUID*)uuid;
+ (WDBRRfcommServiceId*)fromShortId:(unsigned int)shortId;
@property (readonly) WFGUID* uuid;
+ (WDBRRfcommServiceId*)genericFileTransfer;
+ (WDBRRfcommServiceId*)obexFileTransfer;
+ (WDBRRfcommServiceId*)obexObjectPush;
+ (WDBRRfcommServiceId*)phoneBookAccessPce;
+ (WDBRRfcommServiceId*)phoneBookAccessPse;
+ (WDBRRfcommServiceId*)serialPort;
- (unsigned int)asShortId;
- (NSString*)asString;
@end

#endif // __WDBRRfcommServiceId_DEFINED__

// Windows.Devices.Bluetooth.Rfcomm.RfcommServiceProvider
#ifndef __WDBRRfcommServiceProvider_DEFINED__
#define __WDBRRfcommServiceProvider_DEFINED__

WINRT_EXPORT
@interface WDBRRfcommServiceProvider : RTObject
+ (void)createAsync:(WDBRRfcommServiceId*)serviceId
            success:(void (^)(WDBRRfcommServiceProvider*))success
            failure:(void (^)(NSError*))failure;
@property (readonly) NSMutableDictionary* sdpRawAttributes;
@property (readonly) WDBRRfcommServiceId* serviceId;
- (void)startAdvertising:(WNSStreamSocketListener*)listener;
- (void)stopAdvertising;
@end

#endif // __WDBRRfcommServiceProvider_DEFINED__
