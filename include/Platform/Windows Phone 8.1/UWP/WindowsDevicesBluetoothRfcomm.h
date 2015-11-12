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
@class WDBRRfcommServiceId, WDBRRfcommDeviceService, WDBRRfcommServiceProvider;
@protocol WDBRIRfcommServiceIdStatics
, WDBRIRfcommServiceId, WDBRIRfcommDeviceServiceStatics, WDBRIRfcommDeviceService, WDBRIRfcommServiceProviderStatics,
    WDBRIRfcommServiceProvider;

#include "WindowsDevicesBluetooth.h"
#include "WindowsFoundation.h"
#include "WindowsNetworkingSockets.h"
#include "WindowsNetworking.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"

// Windows.Devices.Bluetooth.Rfcomm.RfcommServiceId
#ifndef __WDBRRfcommServiceId_DEFINED__
#define __WDBRRfcommServiceId_DEFINED__

WINRT_EXPORT
@interface WDBRRfcommServiceId : RTObject
+ (WDBRRfcommServiceId*)fromUuid:(WFGUID*)uuid;
+ (WDBRRfcommServiceId*)fromShortId:(unsigned)shortId;
@property (readonly) WFGUID* uuid;
+ (WDBRRfcommServiceId*)genericFileTransfer;
+ (WDBRRfcommServiceId*)obexFileTransfer;
+ (WDBRRfcommServiceId*)obexObjectPush;
+ (WDBRRfcommServiceId*)phoneBookAccessPce;
+ (WDBRRfcommServiceId*)phoneBookAccessPse;
+ (WDBRRfcommServiceId*)serialPort;
- (unsigned)asShortId;
- (NSString*)asString;
@end

#endif // __WDBRRfcommServiceId_DEFINED__

// Windows.Devices.Bluetooth.Rfcomm.RfcommDeviceService
#ifndef __WDBRRfcommDeviceService_DEFINED__
#define __WDBRRfcommDeviceService_DEFINED__

WINRT_EXPORT
@interface WDBRRfcommDeviceService : RTObject
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDBRRfcommDeviceService*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector:(WDBRRfcommServiceId*)serviceId;
@property (readonly) WNHostName* connectionHostName;
@property (readonly) NSString* connectionServiceName;
@property (readonly) WNSSocketProtectionLevel maxProtectionLevel;
@property (readonly) WNSSocketProtectionLevel protectionLevel;
@property (readonly) WDBRRfcommServiceId* serviceId;
- (void)getSdpRawAttributesAsyncWithSuccess:(void (^)(NSDictionary* /*UInt32, WSSIBuffer*/))success failure:(void (^)(NSError*))failure;
- (void)getSdpRawAttributesWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode
                                      success:(void (^)(NSDictionary* /*UInt32, WSSIBuffer*/))success
                                      failure:(void (^)(NSError*))failure;
@end

#endif // __WDBRRfcommDeviceService_DEFINED__

// Windows.Devices.Bluetooth.Rfcomm.RfcommServiceProvider
#ifndef __WDBRRfcommServiceProvider_DEFINED__
#define __WDBRRfcommServiceProvider_DEFINED__

WINRT_EXPORT
@interface WDBRRfcommServiceProvider : RTObject
+ (void)createAsync:(WDBRRfcommServiceId*)serviceId
            success:(void (^)(WDBRRfcommServiceProvider*))success
            failure:(void (^)(NSError*))failure;
// Failed to generate property SdpRawAttributes (Can't marshal
// Windows.Foundation.Collections.IMap`2<UInt32,Windows.Storage.Streams.IBuffer>)
@property (readonly) WDBRRfcommServiceId* serviceId;
// Failed to generate member get_SdpRawAttributes (Can't marshal
// Windows.Foundation.Collections.IMap`2<UInt32,Windows.Storage.Streams.IBuffer>)
- (void)startAdvertising:(WNSStreamSocketListener*)listener;
- (void)stopAdvertising;
@end

#endif // __WDBRRfcommServiceProvider_DEFINED__
