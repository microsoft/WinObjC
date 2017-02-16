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

// WindowsDevicesPwm.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_PWM_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_PWM_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_Pwm.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDPPwmPin, WDPPwmController;
@protocol WDPIPwmController, WDPIPwmControllerStatics, WDPIPwmControllerStatics2, WDPIPwmPin;

// Windows.Devices.Pwm.PwmPulsePolarity
enum _WDPPwmPulsePolarity {
    WDPPwmPulsePolarityActiveHigh = 0,
    WDPPwmPulsePolarityActiveLow = 1,
};
typedef unsigned WDPPwmPulsePolarity;

#include "WindowsDevicesPwmProvider.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWP_WINDOWS_DEVICES_PWM_EXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Pwm.PwmPin
#ifndef __WDPPwmPin_DEFINED__
#define __WDPPwmPin_DEFINED__

OBJCUWP_WINDOWS_DEVICES_PWM_EXPORT
@interface WDPPwmPin : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDPPwmPulsePolarity polarity;
@property (readonly) WDPPwmController* controller;
@property (readonly) BOOL isStarted;
- (double)getActiveDutyCyclePercentage;
- (void)setActiveDutyCyclePercentage:(double)dutyCyclePercentage;
- (void)start;
- (void)stop;
- (void)close;
@end

#endif // __WDPPwmPin_DEFINED__

// Windows.Devices.Pwm.PwmController
#ifndef __WDPPwmController_DEFINED__
#define __WDPPwmController_DEFINED__

OBJCUWP_WINDOWS_DEVICES_PWM_EXPORT
@interface WDPPwmController : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPPwmController*))success failure:(void (^)(NSError*))failure;
+ (void)getControllersAsync:(RTObject<WDPPIPwmProvider>*)provider success:(void (^)(NSArray* /* WDPPwmController* */))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double actualFrequency;
@property (readonly) double maxFrequency;
@property (readonly) double minFrequency;
@property (readonly) int pinCount;
- (double)setDesiredFrequency:(double)desiredFrequency;
- (WDPPwmPin*)openPin:(int)pinNumber;
@end

#endif // __WDPPwmController_DEFINED__

