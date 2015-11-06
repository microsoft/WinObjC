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

// WindowsDevicesWiFiDirect.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDWWiFiDirectDevice;
@protocol WDWIWiFiDirectDeviceStatics
, WDWIWiFiDirectDevice;

// Windows.Devices.WiFiDirect.WiFiDirectConnectionStatus
enum _WDWWiFiDirectConnectionStatus {
    WDWWiFiDirectConnectionStatusDisconnected = 0,
    WDWWiFiDirectConnectionStatusConnected = 1,
};
typedef unsigned WDWWiFiDirectConnectionStatus;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsNetworking.h"

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectDevice
#ifndef __WDWWiFiDirectDevice_DEFINED__
#define __WDWWiFiDirectDevice_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectDevice : RTObject <WFIClosable>
+ (NSString*)getDeviceSelector;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDWWiFiDirectDevice*))success failure:(void (^)(NSError*))failure;
@property (readonly) WDWWiFiDirectConnectionStatus connectionStatus;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addConnectionStatusChangedEvent:(void (^)(WDWWiFiDirectDevice*, RTObject*))del;
- (void)removeConnectionStatusChangedEvent:(EventRegistrationToken)tok;
- (id<NSFastEnumeration> /*WNEndpointPair*/)getConnectionEndpointPairs;
- (void)close;
@end

#endif // __WDWWiFiDirectDevice_DEFINED__
