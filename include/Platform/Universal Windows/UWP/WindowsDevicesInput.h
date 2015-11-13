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

// WindowsDevicesInput.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDIPointerDevice, WDIMouseDevice, WDIMouseEventArgs, WDIMouseCapabilities, WDIKeyboardCapabilities, WDITouchCapabilities;
@class WDIPointerDeviceUsage, WDIMouseDelta;
@protocol WDIIMouseCapabilities
, WDIIKeyboardCapabilities, WDIITouchCapabilities, WDIIPointerDeviceStatics, WDIIPointerDevice, WDIIPointerDevice2, WDIIMouseEventArgs,
    WDIIMouseDevice, WDIIMouseDeviceStatics;

// Windows.Devices.Input.PointerDeviceType
enum _WDIPointerDeviceType {
    WDIPointerDeviceTypeTouch = 0,
    WDIPointerDeviceTypePen = 1,
    WDIPointerDeviceTypeMouse = 2,
};
typedef unsigned WDIPointerDeviceType;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Devices.Input.PointerDeviceUsage
WINRT_EXPORT
@interface WDIPointerDeviceUsage : NSObject
+ (instancetype) new;
@property unsigned int usagePage;
@property unsigned int usage;
@property int minLogical;
@property int maxLogical;
@property int minPhysical;
@property int maxPhysical;
@property unsigned int unit;
@property float physicalMultiplier;
@end

// [struct] Windows.Devices.Input.MouseDelta
WINRT_EXPORT
@interface WDIMouseDelta : NSObject
+ (instancetype) new;
@property int x;
@property int y;
@end

// Windows.Devices.Input.PointerDevice
#ifndef __WDIPointerDevice_DEFINED__
#define __WDIPointerDevice_DEFINED__

WINRT_EXPORT
@interface WDIPointerDevice : RTObject
+ (WDIPointerDevice*)getPointerDevice:(unsigned int)pointerId;
+ (NSArray*)getPointerDevices;
@property (readonly) BOOL isIntegrated;
@property (readonly) unsigned int maxContacts;
@property (readonly) WFRect* physicalDeviceRect;
@property (readonly) WDIPointerDeviceType pointerDeviceType;
@property (readonly) WFRect* screenRect;
@property (readonly) NSArray* supportedUsages;
@property (readonly) unsigned int maxPointersWithZDistance;
@end

#endif // __WDIPointerDevice_DEFINED__

// Windows.Devices.Input.MouseDevice
#ifndef __WDIMouseDevice_DEFINED__
#define __WDIMouseDevice_DEFINED__

WINRT_EXPORT
@interface WDIMouseDevice : RTObject
+ (WDIMouseDevice*)getForCurrentView;
- (EventRegistrationToken)addMouseMovedEvent:(void (^)(WDIMouseDevice*, WDIMouseEventArgs*))del;
- (void)removeMouseMovedEvent:(EventRegistrationToken)tok;
@end

#endif // __WDIMouseDevice_DEFINED__

// Windows.Devices.Input.MouseEventArgs
#ifndef __WDIMouseEventArgs_DEFINED__
#define __WDIMouseEventArgs_DEFINED__

WINRT_EXPORT
@interface WDIMouseEventArgs : RTObject
@property (readonly) WDIMouseDelta* mouseDelta;
@end

#endif // __WDIMouseEventArgs_DEFINED__

// Windows.Devices.Input.MouseCapabilities
#ifndef __WDIMouseCapabilities_DEFINED__
#define __WDIMouseCapabilities_DEFINED__

WINRT_EXPORT
@interface WDIMouseCapabilities : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) int horizontalWheelPresent;
@property (readonly) int mousePresent;
@property (readonly) unsigned int numberOfButtons;
@property (readonly) int swapButtons;
@property (readonly) int verticalWheelPresent;
@end

#endif // __WDIMouseCapabilities_DEFINED__

// Windows.Devices.Input.KeyboardCapabilities
#ifndef __WDIKeyboardCapabilities_DEFINED__
#define __WDIKeyboardCapabilities_DEFINED__

WINRT_EXPORT
@interface WDIKeyboardCapabilities : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) int keyboardPresent;
@end

#endif // __WDIKeyboardCapabilities_DEFINED__

// Windows.Devices.Input.TouchCapabilities
#ifndef __WDITouchCapabilities_DEFINED__
#define __WDITouchCapabilities_DEFINED__

WINRT_EXPORT
@interface WDITouchCapabilities : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int contacts;
@property (readonly) int touchPresent;
@end

#endif // __WDITouchCapabilities_DEFINED__
