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

// WindowsDevicesPrinters.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_PRINTERS_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_PRINTERS_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_Printers.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDPPrint3DDevice, WDPPrintSchema;
@protocol WDPIPrint3DDeviceStatics, WDPIPrint3DDevice, WDPIPrintSchema;

#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Printers.Print3DDevice
#ifndef __WDPPrint3DDevice_DEFINED__
#define __WDPPrint3DDevice_DEFINED__

OBJCUWP_WINDOWS_DEVICES_PRINTERS_EXPORT
@interface WDPPrint3DDevice : RTObject
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPPrint3DDevice*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPPrintSchema* printSchema;
@end

#endif // __WDPPrint3DDevice_DEFINED__

// Windows.Devices.Printers.PrintSchema
#ifndef __WDPPrintSchema_DEFINED__
#define __WDPPrintSchema_DEFINED__

OBJCUWP_WINDOWS_DEVICES_PRINTERS_EXPORT
@interface WDPPrintSchema : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)getDefaultPrintTicketAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
- (void)getCapabilitiesAsync:(RTObject<WSSIRandomAccessStreamWithContentType>*)constrainTicket success:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
- (void)mergeAndValidateWithDefaultPrintTicketAsync:(RTObject<WSSIRandomAccessStreamWithContentType>*)deltaTicket success:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPPrintSchema_DEFINED__

