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

// WindowsDevicesGpioProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESGPIOPROVIDEREXPORT
#define OBJCUWPWINDOWSDEVICESGPIOPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesGpioProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDGPGpioPinProviderValueChangedEventArgs;
@protocol WDGPIGpioPinProviderValueChangedEventArgsFactory, WDGPIGpioPinProviderValueChangedEventArgs, WDGPIGpioPinProvider, WDGPIGpioControllerProvider, WDGPIGpioProvider;

// Windows.Devices.Gpio.Provider.ProviderGpioSharingMode
enum _WDGPProviderGpioSharingMode {
    WDGPProviderGpioSharingModeExclusive = 0,
    WDGPProviderGpioSharingModeSharedReadOnly = 1,
};
typedef unsigned WDGPProviderGpioSharingMode;

// Windows.Devices.Gpio.Provider.ProviderGpioPinDriveMode
enum _WDGPProviderGpioPinDriveMode {
    WDGPProviderGpioPinDriveModeInput = 0,
    WDGPProviderGpioPinDriveModeOutput = 1,
    WDGPProviderGpioPinDriveModeInputPullUp = 2,
    WDGPProviderGpioPinDriveModeInputPullDown = 3,
    WDGPProviderGpioPinDriveModeOutputOpenDrain = 4,
    WDGPProviderGpioPinDriveModeOutputOpenDrainPullUp = 5,
    WDGPProviderGpioPinDriveModeOutputOpenSource = 6,
    WDGPProviderGpioPinDriveModeOutputOpenSourcePullDown = 7,
};
typedef unsigned WDGPProviderGpioPinDriveMode;

// Windows.Devices.Gpio.Provider.ProviderGpioPinValue
enum _WDGPProviderGpioPinValue {
    WDGPProviderGpioPinValueLow = 0,
    WDGPProviderGpioPinValueHigh = 1,
};
typedef unsigned WDGPProviderGpioPinValue;

// Windows.Devices.Gpio.Provider.ProviderGpioPinEdge
enum _WDGPProviderGpioPinEdge {
    WDGPProviderGpioPinEdgeFallingEdge = 0,
    WDGPProviderGpioPinEdgeRisingEdge = 1,
};
typedef unsigned WDGPProviderGpioPinEdge;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Gpio.Provider.IGpioPinProvider
#ifndef __WDGPIGpioPinProvider_DEFINED__
#define __WDGPIGpioPinProvider_DEFINED__

@protocol WDGPIGpioPinProvider
@property (retain) WFTimeSpan* debounceTimeout;
@property (readonly) int pinNumber;
@property (readonly) WDGPProviderGpioSharingMode sharingMode;
- (EventRegistrationToken)addValueChangedEvent:(void(^)(RTObject<WDGPIGpioPinProvider>*, WDGPGpioPinProviderValueChangedEventArgs*))del;
- (void)removeValueChangedEvent:(EventRegistrationToken)tok;
- (BOOL)isDriveModeSupported:(WDGPProviderGpioPinDriveMode)driveMode;
- (WDGPProviderGpioPinDriveMode)getDriveMode;
- (void)setDriveMode:(WDGPProviderGpioPinDriveMode)value;
- (void)write:(WDGPProviderGpioPinValue)value;
- (WDGPProviderGpioPinValue)read;
@end

OBJCUWPWINDOWSDEVICESGPIOPROVIDEREXPORT
@interface WDGPIGpioPinProvider : RTObject <WDGPIGpioPinProvider>
@end

#endif // __WDGPIGpioPinProvider_DEFINED__

// Windows.Devices.Gpio.Provider.IGpioControllerProvider
#ifndef __WDGPIGpioControllerProvider_DEFINED__
#define __WDGPIGpioControllerProvider_DEFINED__

@protocol WDGPIGpioControllerProvider
@property (readonly) int pinCount;
- (RTObject<WDGPIGpioPinProvider>*)openPinProvider:(int)pin sharingMode:(WDGPProviderGpioSharingMode)sharingMode;
@end

OBJCUWPWINDOWSDEVICESGPIOPROVIDEREXPORT
@interface WDGPIGpioControllerProvider : RTObject <WDGPIGpioControllerProvider>
@end

#endif // __WDGPIGpioControllerProvider_DEFINED__

// Windows.Devices.Gpio.Provider.IGpioProvider
#ifndef __WDGPIGpioProvider_DEFINED__
#define __WDGPIGpioProvider_DEFINED__

@protocol WDGPIGpioProvider
- (NSArray* /* RTObject<WDGPIGpioControllerProvider>* */)getControllers;
@end

OBJCUWPWINDOWSDEVICESGPIOPROVIDEREXPORT
@interface WDGPIGpioProvider : RTObject <WDGPIGpioProvider>
@end

#endif // __WDGPIGpioProvider_DEFINED__

// Windows.Devices.Gpio.Provider.GpioPinProviderValueChangedEventArgs
#ifndef __WDGPGpioPinProviderValueChangedEventArgs_DEFINED__
#define __WDGPGpioPinProviderValueChangedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESGPIOPROVIDEREXPORT
@interface WDGPGpioPinProviderValueChangedEventArgs : RTObject
+ (WDGPGpioPinProviderValueChangedEventArgs*)make:(WDGPProviderGpioPinEdge)edge ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGPProviderGpioPinEdge edge;
@end

#endif // __WDGPGpioPinProviderValueChangedEventArgs_DEFINED__

