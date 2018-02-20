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

// WindowsUIInputPreviewInjection.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
#define OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIInputPreviewInjection.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUIPIInjectedInputGamepadInfo, WUIPIInjectedInputKeyboardInfo, WUIPIInjectedInputMouseInfo, WUIPIInjectedInputTouchInfo, WUIPIInjectedInputPenInfo, WUIPIInputInjector;
@class WUIPIInjectedInputRectangle, WUIPIInjectedInputPoint, WUIPIInjectedInputPointerInfo;
@protocol WUIPIIInjectedInputTouchInfo, WUIPIIInjectedInputPenInfo, WUIPIIInjectedInputMouseInfo, WUIPIIInjectedInputKeyboardInfo, WUIPIIInjectedInputGamepadInfo, WUIPIIInjectedInputGamepadInfoFactory, WUIPIIInputInjector, WUIPIIInputInjector2, WUIPIIInputInjectorStatics, WUIPIIInputInjectorStatics2;

// Windows.UI.Input.Preview.Injection.InjectedInputTouchParameters
enum _WUIPIInjectedInputTouchParameters {
    WUIPIInjectedInputTouchParametersNone = 0,
    WUIPIInjectedInputTouchParametersContact = 1,
    WUIPIInjectedInputTouchParametersOrientation = 2,
    WUIPIInjectedInputTouchParametersPressure = 4,
};
typedef unsigned WUIPIInjectedInputTouchParameters;

// Windows.UI.Input.Preview.Injection.InjectedInputPointerOptions
enum _WUIPIInjectedInputPointerOptions {
    WUIPIInjectedInputPointerOptionsNone = 0,
    WUIPIInjectedInputPointerOptionsNew = 1,
    WUIPIInjectedInputPointerOptionsInRange = 2,
    WUIPIInjectedInputPointerOptionsInContact = 4,
    WUIPIInjectedInputPointerOptionsFirstButton = 16,
    WUIPIInjectedInputPointerOptionsSecondButton = 32,
    WUIPIInjectedInputPointerOptionsPrimary = 8192,
    WUIPIInjectedInputPointerOptionsConfidence = 16384,
    WUIPIInjectedInputPointerOptionsCanceled = 32768,
    WUIPIInjectedInputPointerOptionsPointerDown = 65536,
    WUIPIInjectedInputPointerOptionsUpdate = 131072,
    WUIPIInjectedInputPointerOptionsPointerUp = 262144,
    WUIPIInjectedInputPointerOptionsCaptureChanged = 2097152,
};
typedef unsigned WUIPIInjectedInputPointerOptions;

// Windows.UI.Input.Preview.Injection.InjectedInputButtonChangeKind
enum _WUIPIInjectedInputButtonChangeKind {
    WUIPIInjectedInputButtonChangeKindNone = 0,
    WUIPIInjectedInputButtonChangeKindFirstButtonDown = 1,
    WUIPIInjectedInputButtonChangeKindFirstButtonUp = 2,
    WUIPIInjectedInputButtonChangeKindSecondButtonDown = 3,
    WUIPIInjectedInputButtonChangeKindSecondButtonUp = 4,
    WUIPIInjectedInputButtonChangeKindThirdButtonDown = 5,
    WUIPIInjectedInputButtonChangeKindThirdButtonUp = 6,
    WUIPIInjectedInputButtonChangeKindFourthButtonDown = 7,
    WUIPIInjectedInputButtonChangeKindFourthButtonUp = 8,
    WUIPIInjectedInputButtonChangeKindFifthButtonDown = 9,
    WUIPIInjectedInputButtonChangeKindFifthButtonUp = 10,
};
typedef unsigned WUIPIInjectedInputButtonChangeKind;

// Windows.UI.Input.Preview.Injection.InjectedInputPenButtons
enum _WUIPIInjectedInputPenButtons {
    WUIPIInjectedInputPenButtonsNone = 0,
    WUIPIInjectedInputPenButtonsBarrel = 1,
    WUIPIInjectedInputPenButtonsInverted = 2,
    WUIPIInjectedInputPenButtonsEraser = 4,
};
typedef unsigned WUIPIInjectedInputPenButtons;

// Windows.UI.Input.Preview.Injection.InjectedInputPenParameters
enum _WUIPIInjectedInputPenParameters {
    WUIPIInjectedInputPenParametersNone = 0,
    WUIPIInjectedInputPenParametersPressure = 1,
    WUIPIInjectedInputPenParametersRotation = 2,
    WUIPIInjectedInputPenParametersTiltX = 4,
    WUIPIInjectedInputPenParametersTiltY = 8,
};
typedef unsigned WUIPIInjectedInputPenParameters;

// Windows.UI.Input.Preview.Injection.InjectedInputMouseOptions
enum _WUIPIInjectedInputMouseOptions {
    WUIPIInjectedInputMouseOptionsNone = 0,
    WUIPIInjectedInputMouseOptionsMove = 1,
    WUIPIInjectedInputMouseOptionsLeftDown = 2,
    WUIPIInjectedInputMouseOptionsLeftUp = 4,
    WUIPIInjectedInputMouseOptionsRightDown = 8,
    WUIPIInjectedInputMouseOptionsRightUp = 16,
    WUIPIInjectedInputMouseOptionsMiddleDown = 32,
    WUIPIInjectedInputMouseOptionsMiddleUp = 64,
    WUIPIInjectedInputMouseOptionsXDown = 128,
    WUIPIInjectedInputMouseOptionsXUp = 256,
    WUIPIInjectedInputMouseOptionsWheel = 2048,
    WUIPIInjectedInputMouseOptionsHWheel = 4096,
    WUIPIInjectedInputMouseOptionsMoveNoCoalesce = 8192,
    WUIPIInjectedInputMouseOptionsVirtualDesk = 16384,
    WUIPIInjectedInputMouseOptionsAbsolute = 32768,
};
typedef unsigned WUIPIInjectedInputMouseOptions;

// Windows.UI.Input.Preview.Injection.InjectedInputKeyOptions
enum _WUIPIInjectedInputKeyOptions {
    WUIPIInjectedInputKeyOptionsNone = 0,
    WUIPIInjectedInputKeyOptionsExtendedKey = 1,
    WUIPIInjectedInputKeyOptionsKeyUp = 2,
    WUIPIInjectedInputKeyOptionsScanCode = 8,
    WUIPIInjectedInputKeyOptionsUnicode = 4,
};
typedef unsigned WUIPIInjectedInputKeyOptions;

// Windows.UI.Input.Preview.Injection.InjectedInputShortcut
enum _WUIPIInjectedInputShortcut {
    WUIPIInjectedInputShortcutBack = 0,
    WUIPIInjectedInputShortcutStart = 1,
    WUIPIInjectedInputShortcutSearch = 2,
};
typedef unsigned WUIPIInjectedInputShortcut;

// Windows.UI.Input.Preview.Injection.InjectedInputVisualizationMode
enum _WUIPIInjectedInputVisualizationMode {
    WUIPIInjectedInputVisualizationModeNone = 0,
    WUIPIInjectedInputVisualizationModeDefault = 1,
    WUIPIInjectedInputVisualizationModeIndirect = 2,
};
typedef unsigned WUIPIInjectedInputVisualizationMode;

#include "WindowsGamingInput.h"

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Input.Preview.Injection.InjectedInputRectangle
OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
@interface WUIPIInjectedInputRectangle : NSObject
+ (instancetype)new;
@property int left;
@property int top;
@property int bottom;
@property int right;
@end

// [struct] Windows.UI.Input.Preview.Injection.InjectedInputPoint
OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
@interface WUIPIInjectedInputPoint : NSObject
+ (instancetype)new;
@property int positionX;
@property int positionY;
@end

// [struct] Windows.UI.Input.Preview.Injection.InjectedInputPointerInfo
OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
@interface WUIPIInjectedInputPointerInfo : NSObject
+ (instancetype)new;
@property unsigned int pointerId;
@property WUIPIInjectedInputPointerOptions pointerOptions;
@property (retain) WUIPIInjectedInputPoint* pixelLocation;
@property unsigned int timeOffsetInMilliseconds;
@property uint64_t performanceCount;
@end

// Windows.UI.Input.Preview.Injection.InjectedInputGamepadInfo
#ifndef __WUIPIInjectedInputGamepadInfo_DEFINED__
#define __WUIPIInjectedInputGamepadInfo_DEFINED__

OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
@interface WUIPIInjectedInputGamepadInfo : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WUIPIInjectedInputGamepadInfo*)makeInstanceFromGamepadReading:(WGIGamepadReading*)reading ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double rightTrigger;
@property double rightThumbstickY;
@property double rightThumbstickX;
@property double leftTrigger;
@property double leftThumbstickY;
@property double leftThumbstickX;
@property WGIGamepadButtons buttons;
@end

#endif // __WUIPIInjectedInputGamepadInfo_DEFINED__

// Windows.UI.Input.Preview.Injection.InjectedInputKeyboardInfo
#ifndef __WUIPIInjectedInputKeyboardInfo_DEFINED__
#define __WUIPIInjectedInputKeyboardInfo_DEFINED__

OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
@interface WUIPIInjectedInputKeyboardInfo : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned short virtualKey;
@property unsigned short scanCode;
@property WUIPIInjectedInputKeyOptions keyOptions;
@end

#endif // __WUIPIInjectedInputKeyboardInfo_DEFINED__

// Windows.UI.Input.Preview.Injection.InjectedInputMouseInfo
#ifndef __WUIPIInjectedInputMouseInfo_DEFINED__
#define __WUIPIInjectedInputMouseInfo_DEFINED__

OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
@interface WUIPIInjectedInputMouseInfo : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int timeOffsetInMilliseconds;
@property WUIPIInjectedInputMouseOptions mouseOptions;
@property unsigned int mouseData;
@property int deltaY;
@property int deltaX;
@end

#endif // __WUIPIInjectedInputMouseInfo_DEFINED__

// Windows.UI.Input.Preview.Injection.InjectedInputTouchInfo
#ifndef __WUIPIInjectedInputTouchInfo_DEFINED__
#define __WUIPIInjectedInputTouchInfo_DEFINED__

OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
@interface WUIPIInjectedInputTouchInfo : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUIPIInjectedInputTouchParameters touchParameters;
@property double pressure;
@property (retain) WUIPIInjectedInputPointerInfo* pointerInfo;
@property int orientation;
@property (retain) WUIPIInjectedInputRectangle* contact;
@end

#endif // __WUIPIInjectedInputTouchInfo_DEFINED__

// Windows.UI.Input.Preview.Injection.InjectedInputPenInfo
#ifndef __WUIPIInjectedInputPenInfo_DEFINED__
#define __WUIPIInjectedInputPenInfo_DEFINED__

OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
@interface WUIPIInjectedInputPenInfo : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int tiltY;
@property int tiltX;
@property double rotation;
@property double pressure;
@property (retain) WUIPIInjectedInputPointerInfo* pointerInfo;
@property WUIPIInjectedInputPenParameters penParameters;
@property WUIPIInjectedInputPenButtons penButtons;
@end

#endif // __WUIPIInjectedInputPenInfo_DEFINED__

// Windows.UI.Input.Preview.Injection.InputInjector
#ifndef __WUIPIInputInjector_DEFINED__
#define __WUIPIInputInjector_DEFINED__

OBJCUWPWINDOWSUIINPUTPREVIEWINJECTIONEXPORT
@interface WUIPIInputInjector : RTObject
+ (WUIPIInputInjector*)tryCreateForAppBroadcastOnly;
+ (WUIPIInputInjector*)tryCreate;
+ (WUIPIInputInjector*)tryCreate;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)injectKeyboardInput:(id<NSFastEnumeration> /* WUIPIInjectedInputKeyboardInfo* */)input;
- (void)injectMouseInput:(id<NSFastEnumeration> /* WUIPIInjectedInputMouseInfo* */)input;
- (void)initializeTouchInjection:(WUIPIInjectedInputVisualizationMode)visualMode;
- (void)injectTouchInput:(id<NSFastEnumeration> /* WUIPIInjectedInputTouchInfo* */)input;
- (void)uninitializeTouchInjection;
- (void)initializePenInjection:(WUIPIInjectedInputVisualizationMode)visualMode;
- (void)injectPenInput:(WUIPIInjectedInputPenInfo*)input;
- (void)uninitializePenInjection;
- (void)injectShortcut:(WUIPIInjectedInputShortcut)shortcut;
- (void)initializeGamepadInjection;
- (void)injectGamepadInput:(WUIPIInjectedInputGamepadInfo*)input;
- (void)uninitializeGamepadInjection;
@end

#endif // __WUIPIInputInjector_DEFINED__

