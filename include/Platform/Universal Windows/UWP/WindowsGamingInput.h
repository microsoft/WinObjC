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

// WindowsGamingInput.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGIHeadset, WGIGamepad;
@class WGIGamepadReading, WGIGamepadVibration;
@protocol WGIIGameController
, WGIIGamepad, WGIIGamepadStatics, WGIIHeadset;

// Windows.Gaming.Input.GamepadButtons
enum _WGIGamepadButtons {
    WGIGamepadButtonsNone = 0,
    WGIGamepadButtonsMenu = 1,
    WGIGamepadButtonsView = 2,
    WGIGamepadButtonsA = 4,
    WGIGamepadButtonsB = 8,
    WGIGamepadButtonsX = 16,
    WGIGamepadButtonsY = 32,
    WGIGamepadButtonsDPadUp = 64,
    WGIGamepadButtonsDPadDown = 128,
    WGIGamepadButtonsDPadLeft = 256,
    WGIGamepadButtonsDPadRight = 512,
    WGIGamepadButtonsLeftShoulder = 1024,
    WGIGamepadButtonsRightShoulder = 2048,
    WGIGamepadButtonsLeftThumbstick = 4096,
    WGIGamepadButtonsRightThumbstick = 8192,
};
typedef unsigned WGIGamepadButtons;

#include "WindowsFoundation.h"
#include "WindowsSystem.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Gaming.Input.GamepadReading
WINRT_EXPORT
@interface WGIGamepadReading : NSObject
+ (instancetype) new;
@property uint64_t timestamp;
@property WGIGamepadButtons buttons;
@property double leftTrigger;
@property double rightTrigger;
@property double leftThumbstickX;
@property double leftThumbstickY;
@property double rightThumbstickX;
@property double rightThumbstickY;
@end

// [struct] Windows.Gaming.Input.GamepadVibration
WINRT_EXPORT
@interface WGIGamepadVibration : NSObject
+ (instancetype) new;
@property double leftMotor;
@property double rightMotor;
@property double leftTrigger;
@property double rightTrigger;
@end

// Windows.Gaming.Input.IGameController
#ifndef __WGIIGameController_DEFINED__
#define __WGIIGameController_DEFINED__

@protocol WGIIGameController
@property (readonly) WGIHeadset* headset;
@property (readonly) BOOL isWireless;
@property (readonly) WSUser* user;
- (EventRegistrationToken)addHeadsetConnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserChangedEvent:(void (^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))del;
- (void)removeUserChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WGIIGameController_DEFINED__

// Windows.Gaming.Input.Headset
#ifndef __WGIHeadset_DEFINED__
#define __WGIHeadset_DEFINED__

WINRT_EXPORT
@interface WGIHeadset : RTObject
@property (readonly) NSString* captureDeviceId;
@property (readonly) NSString* renderDeviceId;
@end

#endif // __WGIHeadset_DEFINED__

// Windows.Gaming.Input.Gamepad
#ifndef __WGIGamepad_DEFINED__
#define __WGIGamepad_DEFINED__

WINRT_EXPORT
@interface WGIGamepad : RTObject <WGIIGameController>
@property (readonly) WGIHeadset* headset;
@property (readonly) BOOL isWireless;
@property (readonly) WSUser* user;
@property (copy) WGIGamepadVibration* vibration;
+ (NSArray*)gamepads;
- (EventRegistrationToken)addHeadsetConnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserChangedEvent:(void (^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))del;
- (void)removeUserChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addGamepadAddedEvent:(void (^)(RTObject*, WGIGamepad*))del;
+ (void)removeGamepadAddedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addGamepadRemovedEvent:(void (^)(RTObject*, WGIGamepad*))del;
+ (void)removeGamepadRemovedEvent:(EventRegistrationToken)tok;
- (WGIGamepadReading*)getCurrentReading;
@end

#endif // __WGIGamepad_DEFINED__
