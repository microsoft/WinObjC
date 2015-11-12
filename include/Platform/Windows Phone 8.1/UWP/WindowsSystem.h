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

// WindowsSystem.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSLauncherUIOptions, WSLauncherOptions, WSLauncher;
@protocol WSILauncherUIOptions
, WSILauncherOptions, WSILauncherViewOptions, WSILauncherStatics;

// Windows.System.ProcessorArchitecture
enum _WSProcessorArchitecture {
    WSProcessorArchitectureX86 = 0,
    WSProcessorArchitectureArm = 5,
    WSProcessorArchitectureX64 = 9,
    WSProcessorArchitectureNeutral = 11,
    WSProcessorArchitectureUnknown = 65535,
};
typedef unsigned WSProcessorArchitecture;

// Windows.System.VirtualKeyModifiers
enum _WSVirtualKeyModifiers {
    WSVirtualKeyModifiersNone = 0,
    WSVirtualKeyModifiersControl = 1,
    WSVirtualKeyModifiersMenu = 2,
    WSVirtualKeyModifiersShift = 4,
    WSVirtualKeyModifiersWindows = 8,
};
typedef unsigned WSVirtualKeyModifiers;

// Windows.System.VirtualKey
enum _WSVirtualKey {
    WSVirtualKeyNone = 0,
    WSVirtualKeyLeftButton = 1,
    WSVirtualKeyRightButton = 2,
    WSVirtualKeyCancel = 3,
    WSVirtualKeyMiddleButton = 4,
    WSVirtualKeyXButton1 = 5,
    WSVirtualKeyXButton2 = 6,
    WSVirtualKeyBack = 8,
    WSVirtualKeyTab = 9,
    WSVirtualKeyClear = 12,
    WSVirtualKeyEnter = 13,
    WSVirtualKeyShift = 16,
    WSVirtualKeyControl = 17,
    WSVirtualKeyMenu = 18,
    WSVirtualKeyPause = 19,
    WSVirtualKeyCapitalLock = 20,
    WSVirtualKeyKana = 21,
    WSVirtualKeyHangul = 21,
    WSVirtualKeyJunja = 23,
    WSVirtualKeyFinal = 24,
    WSVirtualKeyHanja = 25,
    WSVirtualKeyKanji = 25,
    WSVirtualKeyEscape = 27,
    WSVirtualKeyConvert = 28,
    WSVirtualKeyNonConvert = 29,
    WSVirtualKeyAccept = 30,
    WSVirtualKeyModeChange = 31,
    WSVirtualKeySpace = 32,
    WSVirtualKeyPageUp = 33,
    WSVirtualKeyPageDown = 34,
    WSVirtualKeyEnd = 35,
    WSVirtualKeyHome = 36,
    WSVirtualKeyLeft = 37,
    WSVirtualKeyUp = 38,
    WSVirtualKeyRight = 39,
    WSVirtualKeyDown = 40,
    WSVirtualKeySelect = 41,
    WSVirtualKeyPrint = 42,
    WSVirtualKeyExecute = 43,
    WSVirtualKeySnapshot = 44,
    WSVirtualKeyInsert = 45,
    WSVirtualKeyDelete = 46,
    WSVirtualKeyHelp = 47,
    WSVirtualKeyNumber0 = 48,
    WSVirtualKeyNumber1 = 49,
    WSVirtualKeyNumber2 = 50,
    WSVirtualKeyNumber3 = 51,
    WSVirtualKeyNumber4 = 52,
    WSVirtualKeyNumber5 = 53,
    WSVirtualKeyNumber6 = 54,
    WSVirtualKeyNumber7 = 55,
    WSVirtualKeyNumber8 = 56,
    WSVirtualKeyNumber9 = 57,
    WSVirtualKeyA = 65,
    WSVirtualKeyB = 66,
    WSVirtualKeyC = 67,
    WSVirtualKeyD = 68,
    WSVirtualKeyE = 69,
    WSVirtualKeyF = 70,
    WSVirtualKeyG = 71,
    WSVirtualKeyH = 72,
    WSVirtualKeyI = 73,
    WSVirtualKeyJ = 74,
    WSVirtualKeyK = 75,
    WSVirtualKeyL = 76,
    WSVirtualKeyM = 77,
    WSVirtualKeyN = 78,
    WSVirtualKeyO = 79,
    WSVirtualKeyP = 80,
    WSVirtualKeyQ = 81,
    WSVirtualKeyR = 82,
    WSVirtualKeyS = 83,
    WSVirtualKeyT = 84,
    WSVirtualKeyU = 85,
    WSVirtualKeyV = 86,
    WSVirtualKeyW = 87,
    WSVirtualKeyX = 88,
    WSVirtualKeyY = 89,
    WSVirtualKeyZ = 90,
    WSVirtualKeyLeftWindows = 91,
    WSVirtualKeyRightWindows = 92,
    WSVirtualKeyApplication = 93,
    WSVirtualKeySleep = 95,
    WSVirtualKeyNumberPad0 = 96,
    WSVirtualKeyNumberPad1 = 97,
    WSVirtualKeyNumberPad2 = 98,
    WSVirtualKeyNumberPad3 = 99,
    WSVirtualKeyNumberPad4 = 100,
    WSVirtualKeyNumberPad5 = 101,
    WSVirtualKeyNumberPad6 = 102,
    WSVirtualKeyNumberPad7 = 103,
    WSVirtualKeyNumberPad8 = 104,
    WSVirtualKeyNumberPad9 = 105,
    WSVirtualKeyMultiply = 106,
    WSVirtualKeyAdd = 107,
    WSVirtualKeySeparator = 108,
    WSVirtualKeySubtract = 109,
    WSVirtualKeyDecimal = 110,
    WSVirtualKeyDivide = 111,
    WSVirtualKeyF1 = 112,
    WSVirtualKeyF2 = 113,
    WSVirtualKeyF3 = 114,
    WSVirtualKeyF4 = 115,
    WSVirtualKeyF5 = 116,
    WSVirtualKeyF6 = 117,
    WSVirtualKeyF7 = 118,
    WSVirtualKeyF8 = 119,
    WSVirtualKeyF9 = 120,
    WSVirtualKeyF10 = 121,
    WSVirtualKeyF11 = 122,
    WSVirtualKeyF12 = 123,
    WSVirtualKeyF13 = 124,
    WSVirtualKeyF14 = 125,
    WSVirtualKeyF15 = 126,
    WSVirtualKeyF16 = 127,
    WSVirtualKeyF17 = 128,
    WSVirtualKeyF18 = 129,
    WSVirtualKeyF19 = 130,
    WSVirtualKeyF20 = 131,
    WSVirtualKeyF21 = 132,
    WSVirtualKeyF22 = 133,
    WSVirtualKeyF23 = 134,
    WSVirtualKeyF24 = 135,
    WSVirtualKeyNumberKeyLock = 144,
    WSVirtualKeyScroll = 145,
    WSVirtualKeyLeftShift = 160,
    WSVirtualKeyRightShift = 161,
    WSVirtualKeyLeftControl = 162,
    WSVirtualKeyRightControl = 163,
    WSVirtualKeyLeftMenu = 164,
    WSVirtualKeyRightMenu = 165,
    WSVirtualKeyGoBack = 166,
    WSVirtualKeyGoForward = 167,
    WSVirtualKeyRefresh = 168,
    WSVirtualKeyStop = 169,
    WSVirtualKeySearch = 170,
    WSVirtualKeyFavorites = 171,
    WSVirtualKeyGoHome = 172,
};
typedef unsigned WSVirtualKey;

#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"
#include "WindowsUIViewManagement.h"
#include "WindowsStorage.h"

// Windows.System.LauncherUIOptions
#ifndef __WSLauncherUIOptions_DEFINED__
#define __WSLauncherUIOptions_DEFINED__

WINRT_EXPORT
@interface WSLauncherUIOptions : RTObject
@property (copy) WFRect* selectionRect;
@property WUPPlacement preferredPlacement;
@property (copy) WFPoint* invocationPoint;
@end

#endif // __WSLauncherUIOptions_DEFINED__

// Windows.System.LauncherOptions
#ifndef __WSLauncherOptions_DEFINED__
#define __WSLauncherOptions_DEFINED__

WINRT_EXPORT
@interface WSLauncherOptions : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL treatAsUntrusted;
@property (copy) NSString* preferredApplicationPackageFamilyName;
@property (copy) NSString* preferredApplicationDisplayName;
@property (copy) WFUri* fallbackUri;
@property BOOL displayApplicationPicker;
@property (copy) NSString* contentType;
@property (readonly) WSLauncherUIOptions* uI;
@property WUVViewSizePreference desiredRemainingView;
@end

#endif // __WSLauncherOptions_DEFINED__

// Windows.System.Launcher
#ifndef __WSLauncher_DEFINED__
#define __WSLauncher_DEFINED__

WINRT_EXPORT
@interface WSLauncher : RTObject
+ (void)launchFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchFileWithOptionsAsync:(RTObject<WSIStorageFile>*)file
                           options:(WSLauncherOptions*)options
                           success:(void (^)(BOOL))success
                           failure:(void (^)(NSError*))failure;
+ (void)launchUriAsync:(WFUri*)uri success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)launchUriWithOptionsAsync:(WFUri*)uri
                          options:(WSLauncherOptions*)options
                          success:(void (^)(BOOL))success
                          failure:(void (^)(NSError*))failure;
@end

#endif // __WSLauncher_DEFINED__
