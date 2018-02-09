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

// WindowsDevicesCustom.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESCUSTOMEXPORT
#define OBJCUWPWINDOWSDEVICESCUSTOMEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesCustom.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDCKnownDeviceTypes, WDCIOControlCode, WDCCustomDevice;
@protocol WDCIKnownDeviceTypesStatics, WDCIIOControlCode, WDCIIOControlCodeFactory, WDCICustomDeviceStatics, WDCICustomDevice;

// Windows.Devices.Custom.IOControlAccessMode
enum _WDCIOControlAccessMode {
    WDCIOControlAccessModeAny = 0,
    WDCIOControlAccessModeRead = 1,
    WDCIOControlAccessModeWrite = 2,
    WDCIOControlAccessModeReadWrite = 3,
};
typedef unsigned WDCIOControlAccessMode;

// Windows.Devices.Custom.IOControlBufferingMethod
enum _WDCIOControlBufferingMethod {
    WDCIOControlBufferingMethodBuffered = 0,
    WDCIOControlBufferingMethodDirectInput = 1,
    WDCIOControlBufferingMethodDirectOutput = 2,
    WDCIOControlBufferingMethodNeither = 3,
};
typedef unsigned WDCIOControlBufferingMethod;

// Windows.Devices.Custom.DeviceAccessMode
enum _WDCDeviceAccessMode {
    WDCDeviceAccessModeRead = 0,
    WDCDeviceAccessModeWrite = 1,
    WDCDeviceAccessModeReadWrite = 2,
};
typedef unsigned WDCDeviceAccessMode;

// Windows.Devices.Custom.DeviceSharingMode
enum _WDCDeviceSharingMode {
    WDCDeviceSharingModeShared = 0,
    WDCDeviceSharingModeExclusive = 1,
};
typedef unsigned WDCDeviceSharingMode;

#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Custom.IIOControlCode
#ifndef __WDCIIOControlCode_DEFINED__
#define __WDCIIOControlCode_DEFINED__

@protocol WDCIIOControlCode
@property (readonly) WDCIOControlAccessMode accessMode;
@property (readonly) WDCIOControlBufferingMethod bufferingMethod;
@property (readonly) unsigned int controlCode;
@property (readonly) unsigned short deviceType;
@property (readonly) unsigned short function;
@end

OBJCUWPWINDOWSDEVICESCUSTOMEXPORT
@interface WDCIIOControlCode : RTObject <WDCIIOControlCode>
@end

#endif // __WDCIIOControlCode_DEFINED__

// Windows.Devices.Custom.KnownDeviceTypes
#ifndef __WDCKnownDeviceTypes_DEFINED__
#define __WDCKnownDeviceTypes_DEFINED__

OBJCUWPWINDOWSDEVICESCUSTOMEXPORT
@interface WDCKnownDeviceTypes : RTObject
+ (unsigned short)unknown;
@end

#endif // __WDCKnownDeviceTypes_DEFINED__

// Windows.Devices.Custom.IOControlCode
#ifndef __WDCIOControlCode_DEFINED__
#define __WDCIOControlCode_DEFINED__

OBJCUWPWINDOWSDEVICESCUSTOMEXPORT
@interface WDCIOControlCode : RTObject <WDCIIOControlCode>
+ (WDCIOControlCode*)makeIOControlCode:(unsigned short)deviceType function:(unsigned short)function accessMode:(WDCIOControlAccessMode)accessMode bufferingMethod:(WDCIOControlBufferingMethod)bufferingMethod ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDCIOControlAccessMode accessMode;
@property (readonly) WDCIOControlBufferingMethod bufferingMethod;
@property (readonly) unsigned int controlCode;
@property (readonly) unsigned short deviceType;
@property (readonly) unsigned short function;
@end

#endif // __WDCIOControlCode_DEFINED__

// Windows.Devices.Custom.CustomDevice
#ifndef __WDCCustomDevice_DEFINED__
#define __WDCCustomDevice_DEFINED__

OBJCUWPWINDOWSDEVICESCUSTOMEXPORT
@interface WDCCustomDevice : RTObject
+ (NSString *)getDeviceSelector:(WFGUID*)classGuid;
+ (void)fromIdAsync:(NSString *)deviceId desiredAccess:(WDCDeviceAccessMode)desiredAccess sharingMode:(WDCDeviceSharingMode)sharingMode success:(void (^)(WDCCustomDevice*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIInputStream>* inputStream;
@property (readonly) RTObject<WSSIOutputStream>* outputStream;
- (void)sendIOControlAsync:(RTObject<WDCIIOControlCode>*)ioControlCode inputBuffer:(RTObject<WSSIBuffer>*)inputBuffer outputBuffer:(RTObject<WSSIBuffer>*)outputBuffer success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)trySendIOControlAsync:(RTObject<WDCIIOControlCode>*)ioControlCode inputBuffer:(RTObject<WSSIBuffer>*)inputBuffer outputBuffer:(RTObject<WSSIBuffer>*)outputBuffer success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDCCustomDevice_DEFINED__

