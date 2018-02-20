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

// WindowsGraphicsDisplay.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGRAPHICSDISPLAYEXPORT
#define OBJCUWPWINDOWSGRAPHICSDISPLAYEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGraphicsDisplay.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGDDisplayInformation, WGDDisplayProperties, WGDBrightnessOverride;
@protocol WGDIDisplayInformationStatics, WGDIDisplayInformation, WGDIDisplayInformation2, WGDIDisplayInformation3, WGDIDisplayInformation4, WGDIDisplayPropertiesStatics, WGDIBrightnessOverrideStatics, WGDIBrightnessOverride;

// Windows.Graphics.Display.DisplayOrientations
enum _WGDDisplayOrientations {
    WGDDisplayOrientationsNone = 0,
    WGDDisplayOrientationsLandscape = 1,
    WGDDisplayOrientationsPortrait = 2,
    WGDDisplayOrientationsLandscapeFlipped = 4,
    WGDDisplayOrientationsPortraitFlipped = 8,
};
typedef unsigned WGDDisplayOrientations;

// Windows.Graphics.Display.ResolutionScale
enum _WGDResolutionScale {
    WGDResolutionScaleInvalid = 0,
    WGDResolutionScaleScale100Percent = 100,
    WGDResolutionScaleScale120Percent = 120,
    WGDResolutionScaleScale125Percent = 125,
    WGDResolutionScaleScale140Percent = 140,
    WGDResolutionScaleScale150Percent = 150,
    WGDResolutionScaleScale160Percent = 160,
    WGDResolutionScaleScale175Percent = 175,
    WGDResolutionScaleScale180Percent = 180,
    WGDResolutionScaleScale200Percent = 200,
    WGDResolutionScaleScale225Percent = 225,
    WGDResolutionScaleScale250Percent = 250,
    WGDResolutionScaleScale300Percent = 300,
    WGDResolutionScaleScale350Percent = 350,
    WGDResolutionScaleScale400Percent = 400,
    WGDResolutionScaleScale450Percent = 450,
    WGDResolutionScaleScale500Percent = 500,
};
typedef unsigned WGDResolutionScale;

// Windows.Graphics.Display.DisplayBrightnessScenario
enum _WGDDisplayBrightnessScenario {
    WGDDisplayBrightnessScenarioDefaultBrightness = 0,
    WGDDisplayBrightnessScenarioIdleBrightness = 1,
    WGDDisplayBrightnessScenarioBarcodeReadingBrightness = 2,
    WGDDisplayBrightnessScenarioFullBrightness = 3,
};
typedef unsigned WGDDisplayBrightnessScenario;

// Windows.Graphics.Display.DisplayBrightnessOverrideOptions
enum _WGDDisplayBrightnessOverrideOptions {
    WGDDisplayBrightnessOverrideOptionsNone = 0,
    WGDDisplayBrightnessOverrideOptionsUseDimmedPolicyWhenBatteryIsLow = 1,
};
typedef unsigned WGDDisplayBrightnessOverrideOptions;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
// Windows.Graphics.Display.DisplayPropertiesEventHandler
#ifndef __WGDDisplayPropertiesEventHandler__DEFINED
#define __WGDDisplayPropertiesEventHandler__DEFINED
typedef void(^WGDDisplayPropertiesEventHandler)(RTObject* sender);
#endif // __WGDDisplayPropertiesEventHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.Graphics.Display.DisplayPropertiesEventHandler
#ifndef __WGDDisplayPropertiesEventHandler__DEFINED
#define __WGDDisplayPropertiesEventHandler__DEFINED
typedef void(^WGDDisplayPropertiesEventHandler)(RTObject* sender);
#endif // __WGDDisplayPropertiesEventHandler__DEFINED

// Windows.Graphics.Display.DisplayInformation
#ifndef __WGDDisplayInformation_DEFINED__
#define __WGDDisplayInformation_DEFINED__

OBJCUWPWINDOWSGRAPHICSDISPLAYEXPORT
@interface WGDDisplayInformation : RTObject
+ (WGDDisplayInformation*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGDDisplayOrientations currentOrientation;
@property (readonly) float logicalDpi;
@property (readonly) WGDDisplayOrientations nativeOrientation;
@property (readonly) float rawDpiX;
@property (readonly) float rawDpiY;
@property (readonly) WGDResolutionScale resolutionScale;
@property (readonly) BOOL stereoEnabled;
@property (readonly) double rawPixelsPerViewPixel;
@property (readonly) id /* double */ diagonalSizeInInches;
@property (readonly) unsigned int screenHeightInRawPixels;
@property (readonly) unsigned int screenWidthInRawPixels;
+ (WGDDisplayOrientations)autoRotationPreferences;
+ (void)setAutoRotationPreferences:(WGDDisplayOrientations)value;
- (EventRegistrationToken)addColorProfileChangedEvent:(void(^)(WGDDisplayInformation*, RTObject*))del;
- (void)removeColorProfileChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDpiChangedEvent:(void(^)(WGDDisplayInformation*, RTObject*))del;
- (void)removeDpiChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOrientationChangedEvent:(void(^)(WGDDisplayInformation*, RTObject*))del;
- (void)removeOrientationChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStereoEnabledChangedEvent:(void(^)(WGDDisplayInformation*, RTObject*))del;
- (void)removeStereoEnabledChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addDisplayContentsInvalidatedEvent:(void(^)(WGDDisplayInformation*, RTObject*))del;
+ (void)removeDisplayContentsInvalidatedEvent:(EventRegistrationToken)tok;
- (void)getColorProfileAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGDDisplayInformation_DEFINED__

// Windows.Graphics.Display.DisplayProperties
#ifndef __WGDDisplayProperties_DEFINED__
#define __WGDDisplayProperties_DEFINED__

OBJCUWPWINDOWSGRAPHICSDISPLAYEXPORT
@interface WGDDisplayProperties : RTObject
+ (void)getColorProfileAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
+ (WGDDisplayOrientations)autoRotationPreferences;
+ (void)setAutoRotationPreferences:(WGDDisplayOrientations)value;
+ (WGDDisplayOrientations)currentOrientation;
+ (float)logicalDpi;
+ (WGDDisplayOrientations)nativeOrientation;
+ (WGDResolutionScale)resolutionScale;
+ (BOOL)stereoEnabled;
+ (EventRegistrationToken)addColorProfileChangedEvent:(WGDDisplayPropertiesEventHandler)del;
+ (void)removeColorProfileChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addDisplayContentsInvalidatedEvent:(WGDDisplayPropertiesEventHandler)del;
+ (void)removeDisplayContentsInvalidatedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addLogicalDpiChangedEvent:(WGDDisplayPropertiesEventHandler)del;
+ (void)removeLogicalDpiChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addOrientationChangedEvent:(WGDDisplayPropertiesEventHandler)del;
+ (void)removeOrientationChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addStereoEnabledChangedEvent:(WGDDisplayPropertiesEventHandler)del;
+ (void)removeStereoEnabledChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WGDDisplayProperties_DEFINED__

// Windows.Graphics.Display.BrightnessOverride
#ifndef __WGDBrightnessOverride_DEFINED__
#define __WGDBrightnessOverride_DEFINED__

OBJCUWPWINDOWSGRAPHICSDISPLAYEXPORT
@interface WGDBrightnessOverride : RTObject
+ (WGDBrightnessOverride*)getDefaultForSystem;
+ (WGDBrightnessOverride*)getForCurrentView;
+ (void)saveForSystemAsync:(WGDBrightnessOverride*)value success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double brightnessLevel;
@property (readonly) BOOL isOverrideActive;
@property (readonly) BOOL isSupported;
- (EventRegistrationToken)addBrightnessLevelChangedEvent:(void(^)(WGDBrightnessOverride*, RTObject*))del;
- (void)removeBrightnessLevelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addIsOverrideActiveChangedEvent:(void(^)(WGDBrightnessOverride*, RTObject*))del;
- (void)removeIsOverrideActiveChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addIsSupportedChangedEvent:(void(^)(WGDBrightnessOverride*, RTObject*))del;
- (void)removeIsSupportedChangedEvent:(EventRegistrationToken)tok;
- (void)setBrightnessLevel:(double)brightnessLevel options:(WGDDisplayBrightnessOverrideOptions)options;
- (void)setBrightnessScenario:(WGDDisplayBrightnessScenario)scenario options:(WGDDisplayBrightnessOverrideOptions)options;
- (double)getLevelForScenario:(WGDDisplayBrightnessScenario)scenario;
- (void)startOverride;
- (void)stopOverride;
@end

#endif // __WGDBrightnessOverride_DEFINED__

