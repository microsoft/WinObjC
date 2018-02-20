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

// WindowsGamingInputForceFeedback.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGAMINGINPUTFORCEFEEDBACKEXPORT
#define OBJCUWPWINDOWSGAMINGINPUTFORCEFEEDBACKEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGamingInputForceFeedback.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGIFConditionForceEffect, WGIFPeriodicForceEffect, WGIFConstantForceEffect, WGIFRampForceEffect, WGIFForceFeedbackMotor;
@protocol WGIFIForceFeedbackEffect, WGIFIConditionForceEffect, WGIFIConditionForceEffectFactory, WGIFIConstantForceEffect, WGIFIPeriodicForceEffect, WGIFIPeriodicForceEffectFactory, WGIFIRampForceEffect, WGIFIForceFeedbackMotor;

// Windows.Gaming.Input.ForceFeedback.ConditionForceEffectKind
enum _WGIFConditionForceEffectKind {
    WGIFConditionForceEffectKindSpring = 0,
    WGIFConditionForceEffectKindDamper = 1,
    WGIFConditionForceEffectKindInertia = 2,
    WGIFConditionForceEffectKindFriction = 3,
};
typedef unsigned WGIFConditionForceEffectKind;

// Windows.Gaming.Input.ForceFeedback.ForceFeedbackEffectAxes
enum _WGIFForceFeedbackEffectAxes {
    WGIFForceFeedbackEffectAxesNone = 0,
    WGIFForceFeedbackEffectAxesX = 1,
    WGIFForceFeedbackEffectAxesY = 2,
    WGIFForceFeedbackEffectAxesZ = 4,
};
typedef unsigned WGIFForceFeedbackEffectAxes;

// Windows.Gaming.Input.ForceFeedback.ForceFeedbackEffectState
enum _WGIFForceFeedbackEffectState {
    WGIFForceFeedbackEffectStateStopped = 0,
    WGIFForceFeedbackEffectStateRunning = 1,
    WGIFForceFeedbackEffectStatePaused = 2,
    WGIFForceFeedbackEffectStateFaulted = 3,
};
typedef unsigned WGIFForceFeedbackEffectState;

// Windows.Gaming.Input.ForceFeedback.ForceFeedbackLoadEffectResult
enum _WGIFForceFeedbackLoadEffectResult {
    WGIFForceFeedbackLoadEffectResultSucceeded = 0,
    WGIFForceFeedbackLoadEffectResultEffectStorageFull = 1,
    WGIFForceFeedbackLoadEffectResultEffectNotSupported = 2,
};
typedef unsigned WGIFForceFeedbackLoadEffectResult;

// Windows.Gaming.Input.ForceFeedback.PeriodicForceEffectKind
enum _WGIFPeriodicForceEffectKind {
    WGIFPeriodicForceEffectKindSquareWave = 0,
    WGIFPeriodicForceEffectKindSineWave = 1,
    WGIFPeriodicForceEffectKindTriangleWave = 2,
    WGIFPeriodicForceEffectKindSawtoothWaveUp = 3,
    WGIFPeriodicForceEffectKindSawtoothWaveDown = 4,
};
typedef unsigned WGIFPeriodicForceEffectKind;

#include "WindowsFoundationNumerics.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Gaming.Input.ForceFeedback.IForceFeedbackEffect
#ifndef __WGIFIForceFeedbackEffect_DEFINED__
#define __WGIFIForceFeedbackEffect_DEFINED__

@protocol WGIFIForceFeedbackEffect
@property double gain;
@property (readonly) WGIFForceFeedbackEffectState state;
- (void)start;
- (void)stop;
@end

OBJCUWPWINDOWSGAMINGINPUTFORCEFEEDBACKEXPORT
@interface WGIFIForceFeedbackEffect : RTObject <WGIFIForceFeedbackEffect>
@end

#endif // __WGIFIForceFeedbackEffect_DEFINED__

// Windows.Gaming.Input.ForceFeedback.ConditionForceEffect
#ifndef __WGIFConditionForceEffect_DEFINED__
#define __WGIFConditionForceEffect_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTFORCEFEEDBACKEXPORT
@interface WGIFConditionForceEffect : RTObject <WGIFIForceFeedbackEffect>
+ (WGIFConditionForceEffect*)makeInstance:(WGIFConditionForceEffectKind)effectKind ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGIFConditionForceEffectKind kind;
@property double gain;
@property (readonly) WGIFForceFeedbackEffectState state;
- (void)start;
- (void)stop;
- (void)setParameters:(WFNVector3*)direction positiveCoefficient:(float)positiveCoefficient negativeCoefficient:(float)negativeCoefficient maxPositiveMagnitude:(float)maxPositiveMagnitude maxNegativeMagnitude:(float)maxNegativeMagnitude deadZone:(float)deadZone bias:(float)bias;
@end

#endif // __WGIFConditionForceEffect_DEFINED__

// Windows.Gaming.Input.ForceFeedback.PeriodicForceEffect
#ifndef __WGIFPeriodicForceEffect_DEFINED__
#define __WGIFPeriodicForceEffect_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTFORCEFEEDBACKEXPORT
@interface WGIFPeriodicForceEffect : RTObject <WGIFIForceFeedbackEffect>
+ (WGIFPeriodicForceEffect*)makeInstance:(WGIFPeriodicForceEffectKind)effectKind ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double gain;
@property (readonly) WGIFForceFeedbackEffectState state;
@property (readonly) WGIFPeriodicForceEffectKind kind;
- (void)start;
- (void)stop;
- (void)setParameters:(WFNVector3*)vector frequency:(float)frequency phase:(float)phase bias:(float)bias duration:(WFTimeSpan*)duration;
- (void)setParametersWithEnvelope:(WFNVector3*)vector frequency:(float)frequency phase:(float)phase bias:(float)bias attackGain:(float)attackGain sustainGain:(float)sustainGain releaseGain:(float)releaseGain startDelay:(WFTimeSpan*)startDelay attackDuration:(WFTimeSpan*)attackDuration sustainDuration:(WFTimeSpan*)sustainDuration releaseDuration:(WFTimeSpan*)releaseDuration repeatCount:(unsigned int)repeatCount;
@end

#endif // __WGIFPeriodicForceEffect_DEFINED__

// Windows.Gaming.Input.ForceFeedback.ConstantForceEffect
#ifndef __WGIFConstantForceEffect_DEFINED__
#define __WGIFConstantForceEffect_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTFORCEFEEDBACKEXPORT
@interface WGIFConstantForceEffect : RTObject <WGIFIForceFeedbackEffect>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double gain;
@property (readonly) WGIFForceFeedbackEffectState state;
- (void)start;
- (void)stop;
- (void)setParameters:(WFNVector3*)vector duration:(WFTimeSpan*)duration;
- (void)setParametersWithEnvelope:(WFNVector3*)vector attackGain:(float)attackGain sustainGain:(float)sustainGain releaseGain:(float)releaseGain startDelay:(WFTimeSpan*)startDelay attackDuration:(WFTimeSpan*)attackDuration sustainDuration:(WFTimeSpan*)sustainDuration releaseDuration:(WFTimeSpan*)releaseDuration repeatCount:(unsigned int)repeatCount;
@end

#endif // __WGIFConstantForceEffect_DEFINED__

// Windows.Gaming.Input.ForceFeedback.RampForceEffect
#ifndef __WGIFRampForceEffect_DEFINED__
#define __WGIFRampForceEffect_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTFORCEFEEDBACKEXPORT
@interface WGIFRampForceEffect : RTObject <WGIFIForceFeedbackEffect>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double gain;
@property (readonly) WGIFForceFeedbackEffectState state;
- (void)start;
- (void)stop;
- (void)setParameters:(WFNVector3*)startVector endVector:(WFNVector3*)endVector duration:(WFTimeSpan*)duration;
- (void)setParametersWithEnvelope:(WFNVector3*)startVector endVector:(WFNVector3*)endVector attackGain:(float)attackGain sustainGain:(float)sustainGain releaseGain:(float)releaseGain startDelay:(WFTimeSpan*)startDelay attackDuration:(WFTimeSpan*)attackDuration sustainDuration:(WFTimeSpan*)sustainDuration releaseDuration:(WFTimeSpan*)releaseDuration repeatCount:(unsigned int)repeatCount;
@end

#endif // __WGIFRampForceEffect_DEFINED__

// Windows.Gaming.Input.ForceFeedback.ForceFeedbackMotor
#ifndef __WGIFForceFeedbackMotor_DEFINED__
#define __WGIFForceFeedbackMotor_DEFINED__

OBJCUWPWINDOWSGAMINGINPUTFORCEFEEDBACKEXPORT
@interface WGIFForceFeedbackMotor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double masterGain;
@property (readonly) BOOL areEffectsPaused;
@property (readonly) BOOL isEnabled;
@property (readonly) WGIFForceFeedbackEffectAxes supportedAxes;
- (void)loadEffectAsync:(RTObject<WGIFIForceFeedbackEffect>*)effect success:(void (^)(WGIFForceFeedbackLoadEffectResult))success failure:(void (^)(NSError*))failure;
- (void)pauseAllEffects;
- (void)resumeAllEffects;
- (void)stopAllEffects;
- (void)tryDisableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryEnableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryResetAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryUnloadEffectAsync:(RTObject<WGIFIForceFeedbackEffect>*)effect success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGIFForceFeedbackMotor_DEFINED__

