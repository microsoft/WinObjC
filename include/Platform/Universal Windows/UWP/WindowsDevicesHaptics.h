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

// WindowsDevicesHaptics.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESHAPTICSEXPORT
#define OBJCUWPWINDOWSDEVICESHAPTICSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesHaptics.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDHSimpleHapticsControllerFeedback, WDHSimpleHapticsController, WDHKnownSimpleHapticsControllerWaveforms, WDHVibrationDevice;
@protocol WDHIKnownSimpleHapticsControllerWaveformsStatics, WDHISimpleHapticsControllerFeedback, WDHISimpleHapticsController, WDHIVibrationDeviceStatics, WDHIVibrationDevice;

// Windows.Devices.Haptics.VibrationAccessStatus
enum _WDHVibrationAccessStatus {
    WDHVibrationAccessStatusAllowed = 0,
    WDHVibrationAccessStatusDeniedByUser = 1,
    WDHVibrationAccessStatusDeniedBySystem = 2,
    WDHVibrationAccessStatusDeniedByEnergySaver = 3,
};
typedef unsigned WDHVibrationAccessStatus;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Haptics.SimpleHapticsControllerFeedback
#ifndef __WDHSimpleHapticsControllerFeedback_DEFINED__
#define __WDHSimpleHapticsControllerFeedback_DEFINED__

OBJCUWPWINDOWSDEVICESHAPTICSEXPORT
@interface WDHSimpleHapticsControllerFeedback : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* duration;
@property (readonly) unsigned short waveform;
@end

#endif // __WDHSimpleHapticsControllerFeedback_DEFINED__

// Windows.Devices.Haptics.SimpleHapticsController
#ifndef __WDHSimpleHapticsController_DEFINED__
#define __WDHSimpleHapticsController_DEFINED__

OBJCUWPWINDOWSDEVICESHAPTICSEXPORT
@interface WDHSimpleHapticsController : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
@property (readonly) BOOL isIntensitySupported;
@property (readonly) BOOL isPlayCountSupported;
@property (readonly) BOOL isPlayDurationSupported;
@property (readonly) BOOL isReplayPauseIntervalSupported;
@property (readonly) NSArray* /* WDHSimpleHapticsControllerFeedback* */ supportedFeedback;
- (void)stopFeedback;
- (void)sendHapticFeedback:(WDHSimpleHapticsControllerFeedback*)feedback;
- (void)sendHapticFeedbackWithIntensity:(WDHSimpleHapticsControllerFeedback*)feedback intensity:(double)intensity;
- (void)sendHapticFeedbackForDuration:(WDHSimpleHapticsControllerFeedback*)feedback intensity:(double)intensity playDuration:(WFTimeSpan*)playDuration;
- (void)sendHapticFeedbackForPlayCount:(WDHSimpleHapticsControllerFeedback*)feedback intensity:(double)intensity playCount:(int)playCount replayPauseInterval:(WFTimeSpan*)replayPauseInterval;
@end

#endif // __WDHSimpleHapticsController_DEFINED__

// Windows.Devices.Haptics.KnownSimpleHapticsControllerWaveforms
#ifndef __WDHKnownSimpleHapticsControllerWaveforms_DEFINED__
#define __WDHKnownSimpleHapticsControllerWaveforms_DEFINED__

OBJCUWPWINDOWSDEVICESHAPTICSEXPORT
@interface WDHKnownSimpleHapticsControllerWaveforms : RTObject
+ (unsigned short)buzzContinuous;
+ (unsigned short)click;
+ (unsigned short)press;
+ (unsigned short)Release;
+ (unsigned short)rumbleContinuous;
@end

#endif // __WDHKnownSimpleHapticsControllerWaveforms_DEFINED__

// Windows.Devices.Haptics.VibrationDevice
#ifndef __WDHVibrationDevice_DEFINED__
#define __WDHVibrationDevice_DEFINED__

OBJCUWPWINDOWSDEVICESHAPTICSEXPORT
@interface WDHVibrationDevice : RTObject
+ (void)requestAccessAsyncWithSuccess:(void (^)(WDHVibrationAccessStatus))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDHVibrationDevice*))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDHVibrationDevice*))success failure:(void (^)(NSError*))failure;
+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WDHVibrationDevice* */))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
@property (readonly) WDHSimpleHapticsController* simpleHapticsController;
@end

#endif // __WDHVibrationDevice_DEFINED__

