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

// WindowsPhoneSystemPower.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONESYSTEMPOWEREXPORT
#define OBJCUWPWINDOWSPHONESYSTEMPOWEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhoneSystemPower.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPSPPowerManager;
@protocol WPSPIPowerManagerStatics, WPSPIPowerManagerStatics2;

// Windows.Phone.System.Power.PowerSavingMode
enum _WPSPPowerSavingMode {
    WPSPPowerSavingModeOff = 0,
    WPSPPowerSavingModeOn = 1,
};
typedef unsigned WPSPPowerSavingMode;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Phone.System.Power.PowerManager
#ifndef __WPSPPowerManager_DEFINED__
#define __WPSPPowerManager_DEFINED__

OBJCUWPWINDOWSPHONESYSTEMPOWEREXPORT
@interface WPSPPowerManager : RTObject
+ (WPSPPowerSavingMode)powerSavingMode;
+ (BOOL)powerSavingModeEnabled;
+ (EventRegistrationToken)addPowerSavingModeChangedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removePowerSavingModeChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WPSPPowerManager_DEFINED__

