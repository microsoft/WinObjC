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

// WindowsDevicesGpio.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESGPIOEXPORT
#define OBJCUWPWINDOWSDEVICESGPIOEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesGpio.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDGGpioPinValueChangedEventArgs, WDGGpioPin, WDGGpioController, WDGGpioChangeReader, WDGGpioChangeCounter;
@class WDGGpioChangeRecord, WDGGpioChangeCount;
@protocol WDGIGpioPinValueChangedEventArgs, WDGIGpioController, WDGIGpioControllerStatics, WDGIGpioControllerStatics2, WDGIGpioChangeReaderFactory, WDGIGpioChangeCounterFactory, WDGIGpioPin, WDGIGpioChangeReader, WDGIGpioChangeCounter;

// Windows.Devices.Gpio.GpioSharingMode
enum _WDGGpioSharingMode {
    WDGGpioSharingModeExclusive = 0,
    WDGGpioSharingModeSharedReadOnly = 1,
};
typedef unsigned WDGGpioSharingMode;

// Windows.Devices.Gpio.GpioOpenStatus
enum _WDGGpioOpenStatus {
    WDGGpioOpenStatusPinOpened = 0,
    WDGGpioOpenStatusPinUnavailable = 1,
    WDGGpioOpenStatusSharingViolation = 2,
    WDGGpioOpenStatusMuxingConflict = 3,
    WDGGpioOpenStatusUnknownError = 4,
};
typedef unsigned WDGGpioOpenStatus;

// Windows.Devices.Gpio.GpioPinDriveMode
enum _WDGGpioPinDriveMode {
    WDGGpioPinDriveModeInput = 0,
    WDGGpioPinDriveModeOutput = 1,
    WDGGpioPinDriveModeInputPullUp = 2,
    WDGGpioPinDriveModeInputPullDown = 3,
    WDGGpioPinDriveModeOutputOpenDrain = 4,
    WDGGpioPinDriveModeOutputOpenDrainPullUp = 5,
    WDGGpioPinDriveModeOutputOpenSource = 6,
    WDGGpioPinDriveModeOutputOpenSourcePullDown = 7,
};
typedef unsigned WDGGpioPinDriveMode;

// Windows.Devices.Gpio.GpioPinValue
enum _WDGGpioPinValue {
    WDGGpioPinValueLow = 0,
    WDGGpioPinValueHigh = 1,
};
typedef unsigned WDGGpioPinValue;

// Windows.Devices.Gpio.GpioPinEdge
enum _WDGGpioPinEdge {
    WDGGpioPinEdgeFallingEdge = 0,
    WDGGpioPinEdgeRisingEdge = 1,
};
typedef unsigned WDGGpioPinEdge;

// Windows.Devices.Gpio.GpioChangePolarity
enum _WDGGpioChangePolarity {
    WDGGpioChangePolarityFalling = 0,
    WDGGpioChangePolarityRising = 1,
    WDGGpioChangePolarityBoth = 2,
};
typedef unsigned WDGGpioChangePolarity;

#include "WindowsFoundation.h"
#include "WindowsDevicesGpioProvider.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Devices.Gpio.GpioChangeRecord
OBJCUWPWINDOWSDEVICESGPIOEXPORT
@interface WDGGpioChangeRecord : NSObject
+ (instancetype)new;
@property (retain) WFTimeSpan* relativeTime;
@property WDGGpioPinEdge edge;
@end

// [struct] Windows.Devices.Gpio.GpioChangeCount
OBJCUWPWINDOWSDEVICESGPIOEXPORT
@interface WDGGpioChangeCount : NSObject
+ (instancetype)new;
@property uint64_t count;
@property (retain) WFTimeSpan* relativeTime;
@end

// Windows.Devices.Gpio.GpioPinValueChangedEventArgs
#ifndef __WDGGpioPinValueChangedEventArgs_DEFINED__
#define __WDGGpioPinValueChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESGPIOEXPORT
@interface WDGGpioPinValueChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGpioPinEdge edge;
@end

#endif // __WDGGpioPinValueChangedEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSDEVICESGPIOEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Gpio.GpioPin
#ifndef __WDGGpioPin_DEFINED__
#define __WDGGpioPin_DEFINED__

OBJCUWPWINDOWSDEVICESGPIOEXPORT
@interface WDGGpioPin : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* debounceTimeout;
@property (readonly) int pinNumber;
@property (readonly) WDGGpioSharingMode sharingMode;
- (EventRegistrationToken)addValueChangedEvent:(void(^)(WDGGpioPin*, WDGGpioPinValueChangedEventArgs*))del;
- (void)removeValueChangedEvent:(EventRegistrationToken)tok;
- (BOOL)isDriveModeSupported:(WDGGpioPinDriveMode)driveMode;
- (WDGGpioPinDriveMode)getDriveMode;
- (void)setDriveMode:(WDGGpioPinDriveMode)value;
- (void)write:(WDGGpioPinValue)value;
- (WDGGpioPinValue)read;
- (void)close;
@end

#endif // __WDGGpioPin_DEFINED__

// Windows.Devices.Gpio.GpioController
#ifndef __WDGGpioController_DEFINED__
#define __WDGGpioController_DEFINED__

OBJCUWPWINDOWSDEVICESGPIOEXPORT
@interface WDGGpioController : RTObject
+ (void)getControllersAsync:(RTObject<WDGPIGpioProvider>*)provider success:(void (^)(NSArray* /* WDGGpioController* */))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDGGpioController*))success failure:(void (^)(NSError*))failure;
+ (WDGGpioController*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int pinCount;
- (WDGGpioPin*)openPin:(int)pinNumber;
- (WDGGpioPin*)openPinWithSharingMode:(int)pinNumber sharingMode:(WDGGpioSharingMode)sharingMode;
- (BOOL)tryOpenPin:(int)pinNumber sharingMode:(WDGGpioSharingMode)sharingMode pin:(WDGGpioPin**)pin openStatus:(WDGGpioOpenStatus*)openStatus;
@end

#endif // __WDGGpioController_DEFINED__

// Windows.Devices.Gpio.GpioChangeReader
#ifndef __WDGGpioChangeReader_DEFINED__
#define __WDGGpioChangeReader_DEFINED__

OBJCUWPWINDOWSDEVICESGPIOEXPORT
@interface WDGGpioChangeReader : RTObject <WFIClosable>
+ (WDGGpioChangeReader*)make:(WDGGpioPin*)pin ACTIVATOR;
+ (WDGGpioChangeReader*)makeWithCapacity:(WDGGpioPin*)pin minCapacity:(int)minCapacity ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDGGpioChangePolarity polarity;
@property (readonly) int capacity;
@property (readonly) BOOL isEmpty;
@property (readonly) BOOL isOverflowed;
@property (readonly) BOOL isStarted;
@property (readonly) int length;
- (void)start;
- (void)stop;
- (void)clear;
- (WDGGpioChangeRecord*)getNextItem;
- (WDGGpioChangeRecord*)peekNextItem;
- (NSMutableArray* /* WDGGpioChangeRecord* */)getAllItems;
- (RTObject<WFIAsyncAction>*)waitForItemsAsync:(int)count;
- (void)close;
@end

#endif // __WDGGpioChangeReader_DEFINED__

// Windows.Devices.Gpio.GpioChangeCounter
#ifndef __WDGGpioChangeCounter_DEFINED__
#define __WDGGpioChangeCounter_DEFINED__

OBJCUWPWINDOWSDEVICESGPIOEXPORT
@interface WDGGpioChangeCounter : RTObject <WFIClosable>
+ (WDGGpioChangeCounter*)make:(WDGGpioPin*)pin ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDGGpioChangePolarity polarity;
@property (readonly) BOOL isStarted;
- (void)start;
- (void)stop;
- (WDGGpioChangeCount*)read;
- (WDGGpioChangeCount*)reset;
- (void)close;
@end

#endif // __WDGGpioChangeCounter_DEFINED__

