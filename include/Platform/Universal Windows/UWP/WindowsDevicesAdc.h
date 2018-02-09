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

// WindowsDevicesAdc.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESADCEXPORT
#define OBJCUWPWINDOWSDEVICESADCEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesAdc.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDAAdcChannel, WDAAdcController;
@protocol WDAIAdcController, WDAIAdcControllerStatics, WDAIAdcControllerStatics2, WDAIAdcChannel;

// Windows.Devices.Adc.AdcChannelMode
enum _WDAAdcChannelMode {
    WDAAdcChannelModeSingleEnded = 0,
    WDAAdcChannelModeDifferential = 1,
};
typedef unsigned WDAAdcChannelMode;

#include "WindowsFoundation.h"
#include "WindowsDevicesAdcProvider.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSDEVICESADCEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Adc.AdcChannel
#ifndef __WDAAdcChannel_DEFINED__
#define __WDAAdcChannel_DEFINED__

OBJCUWPWINDOWSDEVICESADCEXPORT
@interface WDAAdcChannel : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDAAdcController* controller;
- (int)readValue;
- (double)readRatio;
- (void)close;
@end

#endif // __WDAAdcChannel_DEFINED__

// Windows.Devices.Adc.AdcController
#ifndef __WDAAdcController_DEFINED__
#define __WDAAdcController_DEFINED__

OBJCUWPWINDOWSDEVICESADCEXPORT
@interface WDAAdcController : RTObject
+ (void)getControllersAsync:(RTObject<WDAPIAdcProvider>*)provider success:(void (^)(NSArray* /* WDAAdcController* */))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDAAdcController*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDAAdcChannelMode channelMode;
@property (readonly) int channelCount;
@property (readonly) int maxValue;
@property (readonly) int minValue;
@property (readonly) int resolutionInBits;
- (BOOL)isChannelModeSupported:(WDAAdcChannelMode)channelMode;
- (WDAAdcChannel*)openChannel:(int)channelNumber;
@end

#endif // __WDAAdcController_DEFINED__

