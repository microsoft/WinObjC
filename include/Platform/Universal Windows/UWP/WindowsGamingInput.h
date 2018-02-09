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

// WindowsGamingInput.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGAMINGINPUTEXPORT
#define OBJCUWPWINDOWSGAMINGINPUTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGamingInput.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGIHeadset, WGIArcadeStick, WGIFlightStick, WGIGamepad, WGIRacingWheel, WGIRawGameController, WGIUINavigationController;
@class WGIArcadeStickReading, WGIFlightStickReading, WGIGamepadReading, WGIGamepadVibration, WGIRacingWheelReading, WGIUINavigationReading;
@protocol WGIIGameController, WGIIGameControllerBatteryInfo, WGIIArcadeStick, WGIIArcadeStickStatics, WGIIArcadeStickStatics2, WGIIFlightStick, WGIIFlightStickStatics, WGIIGamepad, WGIIGamepad2, WGIIGamepadStatics, WGIIGamepadStatics2, WGIIHeadset, WGIIRacingWheel, WGIIRacingWheelStatics, WGIIRacingWheelStatics2, WGIIRawGameController, WGIIRawGameController2, WGIIRawGameControllerStatics, WGIIUINavigationController, WGIIUINavigationControllerStatics, WGIIUINavigationControllerStatics2;

// Windows.Gaming.Input.ArcadeStickButtons
enum _WGIArcadeStickButtons {
    WGIArcadeStickButtonsNone = 0,
    WGIArcadeStickButtonsStickUp = 1,
    WGIArcadeStickButtonsStickDown = 2,
    WGIArcadeStickButtonsStickLeft = 4,
    WGIArcadeStickButtonsStickRight = 8,
    WGIArcadeStickButtonsAction1 = 16,
    WGIArcadeStickButtonsAction2 = 32,
    WGIArcadeStickButtonsAction3 = 64,
    WGIArcadeStickButtonsAction4 = 128,
    WGIArcadeStickButtonsAction5 = 256,
    WGIArcadeStickButtonsAction6 = 512,
    WGIArcadeStickButtonsSpecial1 = 1024,
    WGIArcadeStickButtonsSpecial2 = 2048,
};
typedef unsigned WGIArcadeStickButtons;

// Windows.Gaming.Input.FlightStickButtons
enum _WGIFlightStickButtons {
    WGIFlightStickButtonsNone = 0,
    WGIFlightStickButtonsFirePrimary = 1,
    WGIFlightStickButtonsFireSecondary = 2,
};
typedef unsigned WGIFlightStickButtons;

// Windows.Gaming.Input.GameControllerButtonLabel
enum _WGIGameControllerButtonLabel {
    WGIGameControllerButtonLabelNone = 0,
    WGIGameControllerButtonLabelXboxBack = 1,
    WGIGameControllerButtonLabelXboxStart = 2,
    WGIGameControllerButtonLabelXboxMenu = 3,
    WGIGameControllerButtonLabelXboxView = 4,
    WGIGameControllerButtonLabelXboxUp = 5,
    WGIGameControllerButtonLabelXboxDown = 6,
    WGIGameControllerButtonLabelXboxLeft = 7,
    WGIGameControllerButtonLabelXboxRight = 8,
    WGIGameControllerButtonLabelXboxA = 9,
    WGIGameControllerButtonLabelXboxB = 10,
    WGIGameControllerButtonLabelXboxX = 11,
    WGIGameControllerButtonLabelXboxY = 12,
    WGIGameControllerButtonLabelXboxLeftBumper = 13,
    WGIGameControllerButtonLabelXboxLeftTrigger = 14,
    WGIGameControllerButtonLabelXboxLeftStickButton = 15,
    WGIGameControllerButtonLabelXboxRightBumper = 16,
    WGIGameControllerButtonLabelXboxRightTrigger = 17,
    WGIGameControllerButtonLabelXboxRightStickButton = 18,
    WGIGameControllerButtonLabelXboxPaddle1 = 19,
    WGIGameControllerButtonLabelXboxPaddle2 = 20,
    WGIGameControllerButtonLabelXboxPaddle3 = 21,
    WGIGameControllerButtonLabelXboxPaddle4 = 22,
    WGIGameControllerButtonLabelMode = 23,
    WGIGameControllerButtonLabelSelect = 24,
    WGIGameControllerButtonLabelMenu = 25,
    WGIGameControllerButtonLabelView = 26,
    WGIGameControllerButtonLabelBack = 27,
    WGIGameControllerButtonLabelStart = 28,
    WGIGameControllerButtonLabelOptions = 29,
    WGIGameControllerButtonLabelShare = 30,
    WGIGameControllerButtonLabelUp = 31,
    WGIGameControllerButtonLabelDown = 32,
    WGIGameControllerButtonLabelLeft = 33,
    WGIGameControllerButtonLabelRight = 34,
    WGIGameControllerButtonLabelLetterA = 35,
    WGIGameControllerButtonLabelLetterB = 36,
    WGIGameControllerButtonLabelLetterC = 37,
    WGIGameControllerButtonLabelLetterL = 38,
    WGIGameControllerButtonLabelLetterR = 39,
    WGIGameControllerButtonLabelLetterX = 40,
    WGIGameControllerButtonLabelLetterY = 41,
    WGIGameControllerButtonLabelLetterZ = 42,
    WGIGameControllerButtonLabelCross = 43,
    WGIGameControllerButtonLabelCircle = 44,
    WGIGameControllerButtonLabelSquare = 45,
    WGIGameControllerButtonLabelTriangle = 46,
    WGIGameControllerButtonLabelLeftBumper = 47,
    WGIGameControllerButtonLabelLeftTrigger = 48,
    WGIGameControllerButtonLabelLeftStickButton = 49,
    WGIGameControllerButtonLabelLeft1 = 50,
    WGIGameControllerButtonLabelLeft2 = 51,
    WGIGameControllerButtonLabelLeft3 = 52,
    WGIGameControllerButtonLabelRightBumper = 53,
    WGIGameControllerButtonLabelRightTrigger = 54,
    WGIGameControllerButtonLabelRightStickButton = 55,
    WGIGameControllerButtonLabelRight1 = 56,
    WGIGameControllerButtonLabelRight2 = 57,
    WGIGameControllerButtonLabelRight3 = 58,
    WGIGameControllerButtonLabelPaddle1 = 59,
    WGIGameControllerButtonLabelPaddle2 = 60,
    WGIGameControllerButtonLabelPaddle3 = 61,
    WGIGameControllerButtonLabelPaddle4 = 62,
    WGIGameControllerButtonLabelPlus = 63,
    WGIGameControllerButtonLabelMinus = 64,
    WGIGameControllerButtonLabelDownLeftArrow = 65,
    WGIGameControllerButtonLabelDialLeft = 66,
    WGIGameControllerButtonLabelDialRight = 67,
    WGIGameControllerButtonLabelSuspension = 68,
};
typedef unsigned WGIGameControllerButtonLabel;

// Windows.Gaming.Input.GameControllerSwitchKind
enum _WGIGameControllerSwitchKind {
    WGIGameControllerSwitchKindTwoWay = 0,
    WGIGameControllerSwitchKindFourWay = 1,
    WGIGameControllerSwitchKindEightWay = 2,
};
typedef unsigned WGIGameControllerSwitchKind;

// Windows.Gaming.Input.GameControllerSwitchPosition
enum _WGIGameControllerSwitchPosition {
    WGIGameControllerSwitchPositionCenter = 0,
    WGIGameControllerSwitchPositionUp = 1,
    WGIGameControllerSwitchPositionUpRight = 2,
    WGIGameControllerSwitchPositionRight = 3,
    WGIGameControllerSwitchPositionDownRight = 4,
    WGIGameControllerSwitchPositionDown = 5,
    WGIGameControllerSwitchPositionDownLeft = 6,
    WGIGameControllerSwitchPositionLeft = 7,
    WGIGameControllerSwitchPositionUpLeft = 8,
};
typedef unsigned WGIGameControllerSwitchPosition;

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
    WGIGamepadButtonsPaddle1 = 16384,
    WGIGamepadButtonsPaddle2 = 32768,
    WGIGamepadButtonsPaddle3 = 65536,
    WGIGamepadButtonsPaddle4 = 131072,
};
typedef unsigned WGIGamepadButtons;

// Windows.Gaming.Input.RacingWheelButtons
enum _WGIRacingWheelButtons {
    WGIRacingWheelButtonsNone = 0,
    WGIRacingWheelButtonsPreviousGear = 1,
    WGIRacingWheelButtonsNextGear = 2,
    WGIRacingWheelButtonsDPadUp = 4,
    WGIRacingWheelButtonsDPadDown = 8,
    WGIRacingWheelButtonsDPadLeft = 16,
    WGIRacingWheelButtonsDPadRight = 32,
    WGIRacingWheelButtonsButton1 = 64,
    WGIRacingWheelButtonsButton2 = 128,
    WGIRacingWheelButtonsButton3 = 256,
    WGIRacingWheelButtonsButton4 = 512,
    WGIRacingWheelButtonsButton5 = 1024,
    WGIRacingWheelButtonsButton6 = 2048,
    WGIRacingWheelButtonsButton7 = 4096,
    WGIRacingWheelButtonsButton8 = 8192,
    WGIRacingWheelButtonsButton9 = 16384,
    WGIRacingWheelButtonsButton10 = 32768,
    WGIRacingWheelButtonsButton11 = 65536,
    WGIRacingWheelButtonsButton12 = 131072,
    WGIRacingWheelButtonsButton13 = 262144,
    WGIRacingWheelButtonsButton14 = 524288,
    WGIRacingWheelButtonsButton15 = 1048576,
    WGIRacingWheelButtonsButton16 = 2097152,
};
typedef unsigned WGIRacingWheelButtons;

// Windows.Gaming.Input.RequiredUINavigationButtons
enum _WGIRequiredUINavigationButtons {
    WGIRequiredUINavigationButtonsNone = 0,
    WGIRequiredUINavigationButtonsMenu = 1,
    WGIRequiredUINavigationButtonsView = 2,
    WGIRequiredUINavigationButtonsAccept = 4,
    WGIRequiredUINavigationButtonsCancel = 8,
    WGIRequiredUINavigationButtonsUp = 16,
    WGIRequiredUINavigationButtonsDown = 32,
    WGIRequiredUINavigationButtonsLeft = 64,
    WGIRequiredUINavigationButtonsRight = 128,
};
typedef unsigned WGIRequiredUINavigationButtons;

// Windows.Gaming.Input.OptionalUINavigationButtons
enum _WGIOptionalUINavigationButtons {
    WGIOptionalUINavigationButtonsNone = 0,
    WGIOptionalUINavigationButtonsContext1 = 1,
    WGIOptionalUINavigationButtonsContext2 = 2,
    WGIOptionalUINavigationButtonsContext3 = 4,
    WGIOptionalUINavigationButtonsContext4 = 8,
    WGIOptionalUINavigationButtonsPageUp = 16,
    WGIOptionalUINavigationButtonsPageDown = 32,
    WGIOptionalUINavigationButtonsPageLeft = 64,
    WGIOptionalUINavigationButtonsPageRight = 128,
    WGIOptionalUINavigationButtonsScrollUp = 256,
    WGIOptionalUINavigationButtonsScrollDown = 512,
    WGIOptionalUINavigationButtonsScrollLeft = 1024,
    WGIOptionalUINavigationButtonsScrollRight = 2048,
};
typedef unsigned WGIOptionalUINavigationButtons;

#include "WindowsFoundation.h"
#include "WindowsSystem.h"
#include "WindowsDevicesPower.h"
#include "WindowsDevicesHaptics.h"
#include "WindowsGamingInputForceFeedback.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Gaming.Input.ArcadeStickReading
OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIArcadeStickReading : NSObject
+ (instancetype)new;
@property uint64_t timestamp;
@property WGIArcadeStickButtons buttons;
@end

// [struct] Windows.Gaming.Input.FlightStickReading
OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIFlightStickReading : NSObject
+ (instancetype)new;
@property uint64_t timestamp;
@property WGIFlightStickButtons buttons;
@property WGIGameControllerSwitchPosition hatSwitch;
@property double roll;
@property double pitch;
@property double yaw;
@property double throttle;
@end

// [struct] Windows.Gaming.Input.GamepadReading
OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIGamepadReading : NSObject
+ (instancetype)new;
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
OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIGamepadVibration : NSObject
+ (instancetype)new;
@property double leftMotor;
@property double rightMotor;
@property double leftTrigger;
@property double rightTrigger;
@end

// [struct] Windows.Gaming.Input.RacingWheelReading
OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIRacingWheelReading : NSObject
+ (instancetype)new;
@property uint64_t timestamp;
@property WGIRacingWheelButtons buttons;
@property int patternShifterGear;
@property double wheel;
@property double throttle;
@property double brake;
@property double clutch;
@property double handbrake;
@end

// [struct] Windows.Gaming.Input.UINavigationReading
OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIUINavigationReading : NSObject
+ (instancetype)new;
@property uint64_t timestamp;
@property WGIRequiredUINavigationButtons requiredButtons;
@property WGIOptionalUINavigationButtons optionalButtons;
@end

// Windows.Gaming.Input.IGameController
#ifndef __WGIIGameController_DEFINED__
#define __WGIIGameController_DEFINED__

@protocol WGIIGameController
@property (readonly) WGIHeadset* headset;
@property (readonly) BOOL isWireless;
@property (readonly) WSUser* user;
- (EventRegistrationToken)addHeadsetConnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserChangedEvent:(void(^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))del;
- (void)removeUserChangedEvent:(EventRegistrationToken)tok;
@end

OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIIGameController : RTObject <WGIIGameController>
@end

#endif // __WGIIGameController_DEFINED__

// Windows.Gaming.Input.IGameControllerBatteryInfo
#ifndef __WGIIGameControllerBatteryInfo_DEFINED__
#define __WGIIGameControllerBatteryInfo_DEFINED__

@protocol WGIIGameControllerBatteryInfo
- (WDPBatteryReport*)tryGetBatteryReport;
@end

OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIIGameControllerBatteryInfo : RTObject <WGIIGameControllerBatteryInfo>
@end

#endif // __WGIIGameControllerBatteryInfo_DEFINED__

// Windows.Gaming.Input.Headset
#ifndef __WGIHeadset_DEFINED__
#define __WGIHeadset_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIHeadset : RTObject <WGIIGameControllerBatteryInfo>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * captureDeviceId;
@property (readonly) NSString * renderDeviceId;
- (WDPBatteryReport*)tryGetBatteryReport;
@end

#endif // __WGIHeadset_DEFINED__

// Windows.Gaming.Input.ArcadeStick
#ifndef __WGIArcadeStick_DEFINED__
#define __WGIArcadeStick_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIArcadeStick : RTObject <WGIIGameController, WGIIGameControllerBatteryInfo>
+ (WGIArcadeStick*)fromGameController:(RTObject<WGIIGameController>*)gameController;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGIHeadset* headset;
@property (readonly) BOOL isWireless;
@property (readonly) WSUser* user;
+ (NSArray* /* WGIArcadeStick* */)arcadeSticks;
- (EventRegistrationToken)addHeadsetConnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserChangedEvent:(void(^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))del;
- (void)removeUserChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addArcadeStickAddedEvent:(void(^)(RTObject*, WGIArcadeStick*))del;
+ (void)removeArcadeStickAddedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addArcadeStickRemovedEvent:(void(^)(RTObject*, WGIArcadeStick*))del;
+ (void)removeArcadeStickRemovedEvent:(EventRegistrationToken)tok;
- (WGIGameControllerButtonLabel)getButtonLabel:(WGIArcadeStickButtons)button;
- (WGIArcadeStickReading*)getCurrentReading;
- (WDPBatteryReport*)tryGetBatteryReport;
@end

#endif // __WGIArcadeStick_DEFINED__

// Windows.Gaming.Input.FlightStick
#ifndef __WGIFlightStick_DEFINED__
#define __WGIFlightStick_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIFlightStick : RTObject <WGIIGameController, WGIIGameControllerBatteryInfo>
+ (WGIFlightStick*)fromGameController:(RTObject<WGIIGameController>*)gameController;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGIGameControllerSwitchKind hatSwitchKind;
@property (readonly) WGIHeadset* headset;
@property (readonly) BOOL isWireless;
@property (readonly) WSUser* user;
+ (NSArray* /* WGIFlightStick* */)flightSticks;
- (EventRegistrationToken)addHeadsetConnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserChangedEvent:(void(^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))del;
- (void)removeUserChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addFlightStickAddedEvent:(void(^)(RTObject*, WGIFlightStick*))del;
+ (void)removeFlightStickAddedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addFlightStickRemovedEvent:(void(^)(RTObject*, WGIFlightStick*))del;
+ (void)removeFlightStickRemovedEvent:(EventRegistrationToken)tok;
- (WGIGameControllerButtonLabel)getButtonLabel:(WGIFlightStickButtons)button;
- (WGIFlightStickReading*)getCurrentReading;
- (WDPBatteryReport*)tryGetBatteryReport;
@end

#endif // __WGIFlightStick_DEFINED__

// Windows.Gaming.Input.Gamepad
#ifndef __WGIGamepad_DEFINED__
#define __WGIGamepad_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIGamepad : RTObject <WGIIGameController, WGIIGameControllerBatteryInfo>
+ (WGIGamepad*)fromGameController:(RTObject<WGIIGameController>*)gameController;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGIHeadset* headset;
@property (readonly) BOOL isWireless;
@property (readonly) WSUser* user;
@property (retain) WGIGamepadVibration* vibration;
+ (NSArray* /* WGIGamepad* */)gamepads;
- (EventRegistrationToken)addHeadsetConnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserChangedEvent:(void(^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))del;
- (void)removeUserChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addGamepadAddedEvent:(void(^)(RTObject*, WGIGamepad*))del;
+ (void)removeGamepadAddedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addGamepadRemovedEvent:(void(^)(RTObject*, WGIGamepad*))del;
+ (void)removeGamepadRemovedEvent:(EventRegistrationToken)tok;
- (WGIGamepadReading*)getCurrentReading;
- (WGIGameControllerButtonLabel)getButtonLabel:(WGIGamepadButtons)button;
- (WDPBatteryReport*)tryGetBatteryReport;
@end

#endif // __WGIGamepad_DEFINED__

// Windows.Gaming.Input.RacingWheel
#ifndef __WGIRacingWheel_DEFINED__
#define __WGIRacingWheel_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIRacingWheel : RTObject <WGIIGameController, WGIIGameControllerBatteryInfo>
+ (WGIRacingWheel*)fromGameController:(RTObject<WGIIGameController>*)gameController;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGIHeadset* headset;
@property (readonly) BOOL isWireless;
@property (readonly) WSUser* user;
@property (readonly) BOOL hasClutch;
@property (readonly) BOOL hasHandbrake;
@property (readonly) BOOL hasPatternShifter;
@property (readonly) int maxPatternShifterGear;
@property (readonly) double maxWheelAngle;
@property (readonly) WGIFForceFeedbackMotor* wheelMotor;
+ (NSArray* /* WGIRacingWheel* */)racingWheels;
- (EventRegistrationToken)addHeadsetConnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserChangedEvent:(void(^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))del;
- (void)removeUserChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRacingWheelAddedEvent:(void(^)(RTObject*, WGIRacingWheel*))del;
+ (void)removeRacingWheelAddedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRacingWheelRemovedEvent:(void(^)(RTObject*, WGIRacingWheel*))del;
+ (void)removeRacingWheelRemovedEvent:(EventRegistrationToken)tok;
- (WGIGameControllerButtonLabel)getButtonLabel:(WGIRacingWheelButtons)button;
- (WGIRacingWheelReading*)getCurrentReading;
- (WDPBatteryReport*)tryGetBatteryReport;
@end

#endif // __WGIRacingWheel_DEFINED__

// Windows.Gaming.Input.RawGameController
#ifndef __WGIRawGameController_DEFINED__
#define __WGIRawGameController_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIRawGameController : RTObject <WGIIGameController, WGIIGameControllerBatteryInfo>
+ (WGIRawGameController*)fromGameController:(RTObject<WGIIGameController>*)gameController;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGIHeadset* headset;
@property (readonly) BOOL isWireless;
@property (readonly) WSUser* user;
@property (readonly) int axisCount;
@property (readonly) int buttonCount;
@property (readonly) NSArray* /* WGIFForceFeedbackMotor* */ forceFeedbackMotors;
@property (readonly) unsigned short hardwareProductId;
@property (readonly) unsigned short hardwareVendorId;
@property (readonly) int switchCount;
@property (readonly) NSString * displayName;
@property (readonly) NSString * nonRoamableId;
@property (readonly) NSArray* /* WDHSimpleHapticsController* */ simpleHapticsControllers;
+ (NSArray* /* WGIRawGameController* */)rawGameControllers;
- (EventRegistrationToken)addHeadsetConnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserChangedEvent:(void(^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))del;
- (void)removeUserChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRawGameControllerAddedEvent:(void(^)(RTObject*, WGIRawGameController*))del;
+ (void)removeRawGameControllerAddedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addRawGameControllerRemovedEvent:(void(^)(RTObject*, WGIRawGameController*))del;
+ (void)removeRawGameControllerRemovedEvent:(EventRegistrationToken)tok;
- (WGIGameControllerButtonLabel)getButtonLabel:(int)buttonIndex;
- (uint64_t)getCurrentReading:(NSArray* /* BOOL */*)buttonArray switchArray:(NSArray* /* WGIGameControllerSwitchPosition */*)switchArray axisArray:(NSArray* /* double */*)axisArray;
- (WGIGameControllerSwitchKind)getSwitchKind:(int)switchIndex;
- (WDPBatteryReport*)tryGetBatteryReport;
@end

#endif // __WGIRawGameController_DEFINED__

// Windows.Gaming.Input.UINavigationController
#ifndef __WGIUINavigationController_DEFINED__
#define __WGIUINavigationController_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTEXPORT
@interface WGIUINavigationController : RTObject <WGIIGameController, WGIIGameControllerBatteryInfo>
+ (WGIUINavigationController*)fromGameController:(RTObject<WGIIGameController>*)gameController;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGIHeadset* headset;
@property (readonly) BOOL isWireless;
@property (readonly) WSUser* user;
+ (NSArray* /* WGIUINavigationController* */)uINavigationControllers;
- (EventRegistrationToken)addHeadsetConnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void(^)(RTObject<WGIIGameController>*, WGIHeadset*))del;
- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserChangedEvent:(void(^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))del;
- (void)removeUserChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addUINavigationControllerAddedEvent:(void(^)(RTObject*, WGIUINavigationController*))del;
+ (void)removeUINavigationControllerAddedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addUINavigationControllerRemovedEvent:(void(^)(RTObject*, WGIUINavigationController*))del;
+ (void)removeUINavigationControllerRemovedEvent:(EventRegistrationToken)tok;
- (WGIUINavigationReading*)getCurrentReading;
- (WGIGameControllerButtonLabel)getOptionalButtonLabel:(WGIOptionalUINavigationButtons)button;
- (WGIGameControllerButtonLabel)getRequiredButtonLabel:(WGIRequiredUINavigationButtons)button;
- (WDPBatteryReport*)tryGetBatteryReport;
@end

#endif // __WGIUINavigationController_DEFINED__

