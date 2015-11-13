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

// WindowsGraphicsDisplay.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGDDisplayInformation, WGDDisplayProperties;
@protocol WGDIDisplayInformationStatics
, WGDIDisplayInformation, WGDIDisplayPropertiesStatics;

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
    WGDResolutionScaleScale140Percent = 140,
    WGDResolutionScaleScale150Percent = 150,
    WGDResolutionScaleScale160Percent = 160,
    WGDResolutionScaleScale180Percent = 180,
    WGDResolutionScaleScale225Percent = 225,
};
typedef unsigned WGDResolutionScale;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
// Windows.Graphics.Display.DisplayPropertiesEventHandler
#ifndef __WGDDisplayPropertiesEventHandler__DEFINED
#define __WGDDisplayPropertiesEventHandler__DEFINED
typedef void (^WGDDisplayPropertiesEventHandler)(RTObject* sender);
#endif // __WGDDisplayPropertiesEventHandler__DEFINED

// Windows.Graphics.Display.DisplayPropertiesEventHandler
#ifndef __WGDDisplayPropertiesEventHandler__DEFINED
#define __WGDDisplayPropertiesEventHandler__DEFINED
typedef void (^WGDDisplayPropertiesEventHandler)(RTObject* sender);
#endif // __WGDDisplayPropertiesEventHandler__DEFINED

// Windows.Graphics.Display.DisplayInformation
#ifndef __WGDDisplayInformation_DEFINED__
#define __WGDDisplayInformation_DEFINED__

WINRT_EXPORT
@interface WGDDisplayInformation : RTObject
+ (WGDDisplayInformation*)getForCurrentView;
@property (readonly) WGDDisplayOrientations currentOrientation;
@property (readonly) float logicalDpi;
@property (readonly) WGDDisplayOrientations nativeOrientation;
@property (readonly) float rawDpiX;
@property (readonly) float rawDpiY;
@property (readonly) WGDResolutionScale resolutionScale;
@property (readonly) BOOL stereoEnabled;
+ (WGDDisplayOrientations)autoRotationPreferences;
+ (void)setAutoRotationPreferences:(WGDDisplayOrientations)value;
- (EventRegistrationToken)addColorProfileChangedEvent:(void (^)(WGDDisplayInformation*, RTObject*))del;
- (void)removeColorProfileChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDpiChangedEvent:(void (^)(WGDDisplayInformation*, RTObject*))del;
- (void)removeDpiChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOrientationChangedEvent:(void (^)(WGDDisplayInformation*, RTObject*))del;
- (void)removeOrientationChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStereoEnabledChangedEvent:(void (^)(WGDDisplayInformation*, RTObject*))del;
- (void)removeStereoEnabledChangedEvent:(EventRegistrationToken)tok;
+ (EventRegistrationToken)addDisplayContentsInvalidatedEvent:(void (^)(WGDDisplayInformation*, RTObject*))del;
+ (void)removeDisplayContentsInvalidatedEvent:(EventRegistrationToken)tok;
- (void)getColorProfileAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGDDisplayInformation_DEFINED__

// Windows.Graphics.Display.DisplayProperties
#ifndef __WGDDisplayProperties_DEFINED__
#define __WGDDisplayProperties_DEFINED__

WINRT_EXPORT
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
