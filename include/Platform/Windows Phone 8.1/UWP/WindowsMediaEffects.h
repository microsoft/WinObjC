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

// WindowsMediaEffects.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMEAudioEffect, WMEAudioRenderEffectsManager, WMEAudioCaptureEffectsManager, WMEAudioEffectsManager;
@protocol WMEIAudioEffect
, WMEIAudioEffectsManagerStatics, WMEIAudioRenderEffectsManager, WMEIAudioCaptureEffectsManager;

// Windows.Media.Effects.AudioEffectType
enum _WMEAudioEffectType {
    WMEAudioEffectTypeOther = 0,
    WMEAudioEffectTypeAcousticEchoCancellation = 1,
    WMEAudioEffectTypeNoiseSuppression = 2,
    WMEAudioEffectTypeAutomaticGainControl = 3,
    WMEAudioEffectTypeBeamForming = 4,
    WMEAudioEffectTypeConstantToneRemoval = 5,
    WMEAudioEffectTypeEqualizer = 6,
    WMEAudioEffectTypeLoudnessEqualizer = 7,
    WMEAudioEffectTypeBassBoost = 8,
    WMEAudioEffectTypeVirtualSurround = 9,
    WMEAudioEffectTypeVirtualHeadphones = 10,
    WMEAudioEffectTypeSpeakerFill = 11,
    WMEAudioEffectTypeRoomCorrection = 12,
    WMEAudioEffectTypeBassManagement = 13,
    WMEAudioEffectTypeEnvironmentalEffects = 14,
    WMEAudioEffectTypeSpeakerProtection = 15,
    WMEAudioEffectTypeSpeakerCompensation = 16,
    WMEAudioEffectTypeDynamicRangeCompression = 17,
};
typedef unsigned WMEAudioEffectType;

#include "WindowsMediaCapture.h"
#include "WindowsFoundationCollections.h"
#include "WindowsMediaRender.h"
#include "WindowsMedia.h"
#include "WindowsFoundation.h"

// Windows.Media.Effects.AudioEffect
#ifndef __WMEAudioEffect_DEFINED__
#define __WMEAudioEffect_DEFINED__

WINRT_EXPORT
@interface WMEAudioEffect : RTObject
@property (readonly) WMEAudioEffectType audioEffectType;
@end

#endif // __WMEAudioEffect_DEFINED__

// Windows.Media.Effects.AudioRenderEffectsManager
#ifndef __WMEAudioRenderEffectsManager_DEFINED__
#define __WMEAudioRenderEffectsManager_DEFINED__

WINRT_EXPORT
@interface WMEAudioRenderEffectsManager : RTObject
- (EventRegistrationToken)addAudioRenderEffectsChangedEvent:(void (^)(WMEAudioRenderEffectsManager*, RTObject*))del;
- (void)removeAudioRenderEffectsChangedEvent:(EventRegistrationToken)tok;
- (id<NSFastEnumeration> /*WMEAudioEffect*/)getAudioRenderEffects;
@end

#endif // __WMEAudioRenderEffectsManager_DEFINED__

// Windows.Media.Effects.AudioCaptureEffectsManager
#ifndef __WMEAudioCaptureEffectsManager_DEFINED__
#define __WMEAudioCaptureEffectsManager_DEFINED__

WINRT_EXPORT
@interface WMEAudioCaptureEffectsManager : RTObject
- (EventRegistrationToken)addAudioCaptureEffectsChangedEvent:(void (^)(WMEAudioCaptureEffectsManager*, RTObject*))del;
- (void)removeAudioCaptureEffectsChangedEvent:(EventRegistrationToken)tok;
- (id<NSFastEnumeration> /*WMEAudioEffect*/)getAudioCaptureEffects;
@end

#endif // __WMEAudioCaptureEffectsManager_DEFINED__

// Windows.Media.Effects.AudioEffectsManager
#ifndef __WMEAudioEffectsManager_DEFINED__
#define __WMEAudioEffectsManager_DEFINED__

WINRT_EXPORT
@interface WMEAudioEffectsManager : RTObject
+ (WMEAudioRenderEffectsManager*)createAudioRenderEffectsManager:(NSString*)deviceId category:(WMRAudioRenderCategory)category;
+ (WMEAudioRenderEffectsManager*)createAudioRenderEffectsManagerWithMode:(NSString*)deviceId
                                                                category:(WMRAudioRenderCategory)category
                                                                    mode:(WMAudioProcessing)mode;
+ (WMEAudioCaptureEffectsManager*)createAudioCaptureEffectsManager:(NSString*)deviceId category:(WMCMediaCategory)category;
+ (WMEAudioCaptureEffectsManager*)createAudioCaptureEffectsManagerWithMode:(NSString*)deviceId
                                                                  category:(WMCMediaCategory)category
                                                                      mode:(WMAudioProcessing)mode;
@end

#endif // __WMEAudioEffectsManager_DEFINED__
