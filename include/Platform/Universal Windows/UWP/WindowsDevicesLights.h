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

// WindowsDevicesLights.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDLLamp, WDLLampAvailabilityChangedEventArgs;
@protocol WDLILampStatics
, WDLILampAvailabilityChangedEventArgs, WDLILamp;

#include "WindowsFoundation.h"
#include "WindowsUI.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Lights.Lamp
#ifndef __WDLLamp_DEFINED__
#define __WDLLamp_DEFINED__

WINRT_EXPORT
@interface WDLLamp : RTObject <WFIClosable>
+ (NSString*)getDeviceSelector;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDLLamp*))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDLLamp*))success failure:(void (^)(NSError*))failure;
@property BOOL isEnabled;
@property (copy) WUColor* color;
@property float brightnessLevel;
@property (readonly) NSString* deviceId;
@property (readonly) BOOL isColorSettable;
- (EventRegistrationToken)addAvailabilityChangedEvent:(void (^)(WDLLamp*, WDLLampAvailabilityChangedEventArgs*))del;
- (void)removeAvailabilityChangedEvent:(EventRegistrationToken)tok;
- (void)close;
@end

#endif // __WDLLamp_DEFINED__

// Windows.Devices.Lights.LampAvailabilityChangedEventArgs
#ifndef __WDLLampAvailabilityChangedEventArgs_DEFINED__
#define __WDLLampAvailabilityChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDLLampAvailabilityChangedEventArgs : RTObject
@property (readonly) BOOL isAvailable;
@end

#endif // __WDLLampAvailabilityChangedEventArgs_DEFINED__
