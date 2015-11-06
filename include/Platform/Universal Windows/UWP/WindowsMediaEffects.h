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
@class WMEVideoCompositorDefinition, WMECompositeVideoFrameContext, WMEAudioEffect, WMEAudioRenderEffectsManager,
    WMEAudioCaptureEffectsManager, WMEAudioEffectsManager, WMEVideoEffectDefinition, WMEAudioEffectDefinition, WMEProcessVideoFrameContext,
    WMEProcessAudioFrameContext, WMEVideoTransformEffectDefinition;
@protocol WMEIVideoCompositorDefinition
, WMEIVideoCompositorDefinitionFactory, WMEICompositeVideoFrameContext, WMEIAudioEffect, WMEIAudioEffectsManagerStatics,
    WMEIAudioRenderEffectsManager, WMEIAudioRenderEffectsManager2, WMEIAudioCaptureEffectsManager, WMEIVideoCompositor,
    WMEIAudioEffectDefinition, WMEIVideoEffectDefinition, WMEIVideoEffectDefinitionFactory, WMEIAudioEffectDefinitionFactory,
    WMEIProcessVideoFrameContext, WMEIBasicVideoEffect, WMEIProcessAudioFrameContext, WMEIBasicAudioEffect,
    WMEIVideoTransformEffectDefinition;

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

// Windows.Media.Effects.MediaMemoryTypes
enum _WMEMediaMemoryTypes {
    WMEMediaMemoryTypesGpu = 0,
    WMEMediaMemoryTypesCpu = 1,
    WMEMediaMemoryTypesGpuAndCpu = 2,
};
typedef unsigned WMEMediaMemoryTypes;

// Windows.Media.Effects.MediaEffectClosedReason
enum _WMEMediaEffectClosedReason {
    WMEMediaEffectClosedReasonDone = 0,
    WMEMediaEffectClosedReasonUnknownError = 1,
    WMEMediaEffectClosedReasonUnsupportedEncodingFormat = 2,
    WMEMediaEffectClosedReasonEffectCurrentlyUnloaded = 3,
};
typedef unsigned WMEMediaEffectClosedReason;

#include "WindowsMediaEditing.h"
#include "WindowsMediaCapture.h"
#include "WindowsMediaTranscoding.h"
#include "WindowsStorageStreams.h"
#include "WindowsMediaRender.h"
#include "WindowsFoundationCollections.h"
#include "WindowsGraphicsDirectXDirect3D11.h"
#include "WindowsMedia.h"
#include "WindowsFoundation.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsUI.h"

#import <Foundation/Foundation.h>

// Windows.Media.Effects.IVideoCompositorDefinition
#ifndef __WMEIVideoCompositorDefinition_DEFINED__
#define __WMEIVideoCompositorDefinition_DEFINED__

@protocol WMEIVideoCompositorDefinition
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMEIVideoCompositorDefinition_DEFINED__

// Windows.Media.IMediaExtension
#ifndef __WMIMediaExtension_DEFINED__
#define __WMIMediaExtension_DEFINED__

@protocol WMIMediaExtension
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMIMediaExtension_DEFINED__

// Windows.Media.Effects.IVideoCompositor
#ifndef __WMEIVideoCompositor_DEFINED__
#define __WMEIVideoCompositor_DEFINED__

@protocol WMEIVideoCompositor <WMIMediaExtension>
@property (readonly) BOOL timeIndependent;
- (void)setEncodingProperties:(WMMVideoEncodingProperties*)backgroundProperties device:(RTObject<WGDDIDirect3DDevice>*)device;
- (void)compositeFrame:(WMECompositeVideoFrameContext*)context;
- (void)close:(WMEMediaEffectClosedReason)reason;
- (void)discardQueuedFrames;
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMEIVideoCompositor_DEFINED__

// Windows.Media.Effects.IAudioEffectDefinition
#ifndef __WMEIAudioEffectDefinition_DEFINED__
#define __WMEIAudioEffectDefinition_DEFINED__

@protocol WMEIAudioEffectDefinition
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMEIAudioEffectDefinition_DEFINED__

// Windows.Media.Effects.IVideoEffectDefinition
#ifndef __WMEIVideoEffectDefinition_DEFINED__
#define __WMEIVideoEffectDefinition_DEFINED__

@protocol WMEIVideoEffectDefinition
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMEIVideoEffectDefinition_DEFINED__

// Windows.Media.Effects.IBasicVideoEffect
#ifndef __WMEIBasicVideoEffect_DEFINED__
#define __WMEIBasicVideoEffect_DEFINED__

@protocol WMEIBasicVideoEffect <WMIMediaExtension>
@property (readonly) BOOL isReadOnly;
@property (readonly) NSArray* supportedEncodingProperties;
@property (readonly) WMEMediaMemoryTypes supportedMemoryTypes;
@property (readonly) BOOL timeIndependent;
- (void)setEncodingProperties:(WMMVideoEncodingProperties*)encodingProperties device:(RTObject<WGDDIDirect3DDevice>*)device;
- (void)processFrame:(WMEProcessVideoFrameContext*)context;
- (void)close:(WMEMediaEffectClosedReason)reason;
- (void)discardQueuedFrames;
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMEIBasicVideoEffect_DEFINED__

// Windows.Media.Effects.IBasicAudioEffect
#ifndef __WMEIBasicAudioEffect_DEFINED__
#define __WMEIBasicAudioEffect_DEFINED__

@protocol WMEIBasicAudioEffect <WMIMediaExtension>
@property (readonly) NSArray* supportedEncodingProperties;
@property (readonly) BOOL useInputFrameForOutput;
- (void)setEncodingProperties:(WMMAudioEncodingProperties*)encodingProperties;
- (void)processFrame:(WMEProcessAudioFrameContext*)context;
- (void)close:(WMEMediaEffectClosedReason)reason;
- (void)discardQueuedFrames;
- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration;
@end

#endif // __WMEIBasicAudioEffect_DEFINED__

// Windows.Media.Effects.VideoCompositorDefinition
#ifndef __WMEVideoCompositorDefinition_DEFINED__
#define __WMEVideoCompositorDefinition_DEFINED__

WINRT_EXPORT
@interface WMEVideoCompositorDefinition : RTObject <WMEIVideoCompositorDefinition>
+ (WMEVideoCompositorDefinition*)create:(NSString*)activatableClassId ACTIVATOR;
+ (WMEVideoCompositorDefinition*)createWithProperties:(NSString*)activatableClassId props:(RTObject<WFCIPropertySet>*)props ACTIVATOR;
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMEVideoCompositorDefinition_DEFINED__

// Windows.Media.Effects.CompositeVideoFrameContext
#ifndef __WMECompositeVideoFrameContext_DEFINED__
#define __WMECompositeVideoFrameContext_DEFINED__

WINRT_EXPORT
@interface WMECompositeVideoFrameContext : RTObject
@property (readonly) WMVideoFrame* backgroundFrame;
@property (readonly) WMVideoFrame* outputFrame;
@property (readonly) NSArray* surfacesToOverlay;
- (WMEMediaOverlay*)getOverlayForSurface:(RTObject<WGDDIDirect3DSurface>*)surfaceToOverlay;
@end

#endif // __WMECompositeVideoFrameContext_DEFINED__

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
@property (readonly) NSString* effectsProviderSettingsLabel;
@property (readonly) RTObject<WSSIRandomAccessStreamWithContentType>* effectsProviderThumbnail;
- (EventRegistrationToken)addAudioRenderEffectsChangedEvent:(void (^)(WMEAudioRenderEffectsManager*, RTObject*))del;
- (void)removeAudioRenderEffectsChangedEvent:(EventRegistrationToken)tok;
- (NSArray*)getAudioRenderEffects;
- (void)showSettingsUI;
@end

#endif // __WMEAudioRenderEffectsManager_DEFINED__

// Windows.Media.Effects.AudioCaptureEffectsManager
#ifndef __WMEAudioCaptureEffectsManager_DEFINED__
#define __WMEAudioCaptureEffectsManager_DEFINED__

WINRT_EXPORT
@interface WMEAudioCaptureEffectsManager : RTObject
- (EventRegistrationToken)addAudioCaptureEffectsChangedEvent:(void (^)(WMEAudioCaptureEffectsManager*, RTObject*))del;
- (void)removeAudioCaptureEffectsChangedEvent:(EventRegistrationToken)tok;
- (NSArray*)getAudioCaptureEffects;
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

// Windows.Media.Effects.VideoEffectDefinition
#ifndef __WMEVideoEffectDefinition_DEFINED__
#define __WMEVideoEffectDefinition_DEFINED__

WINRT_EXPORT
@interface WMEVideoEffectDefinition : RTObject <WMEIVideoEffectDefinition>
+ (WMEVideoEffectDefinition*)create:(NSString*)activatableClassId ACTIVATOR;
+ (WMEVideoEffectDefinition*)createWithProperties:(NSString*)activatableClassId props:(RTObject<WFCIPropertySet>*)props ACTIVATOR;
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMEVideoEffectDefinition_DEFINED__

// Windows.Media.Effects.AudioEffectDefinition
#ifndef __WMEAudioEffectDefinition_DEFINED__
#define __WMEAudioEffectDefinition_DEFINED__

WINRT_EXPORT
@interface WMEAudioEffectDefinition : RTObject <WMEIAudioEffectDefinition>
+ (WMEAudioEffectDefinition*)create:(NSString*)activatableClassId ACTIVATOR;
+ (WMEAudioEffectDefinition*)createWithProperties:(NSString*)activatableClassId props:(RTObject<WFCIPropertySet>*)props ACTIVATOR;
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMEAudioEffectDefinition_DEFINED__

// Windows.Media.Effects.ProcessVideoFrameContext
#ifndef __WMEProcessVideoFrameContext_DEFINED__
#define __WMEProcessVideoFrameContext_DEFINED__

WINRT_EXPORT
@interface WMEProcessVideoFrameContext : RTObject
@property (readonly) WMVideoFrame* inputFrame;
@property (readonly) WMVideoFrame* outputFrame;
@end

#endif // __WMEProcessVideoFrameContext_DEFINED__

// Windows.Media.Effects.ProcessAudioFrameContext
#ifndef __WMEProcessAudioFrameContext_DEFINED__
#define __WMEProcessAudioFrameContext_DEFINED__

WINRT_EXPORT
@interface WMEProcessAudioFrameContext : RTObject
@property (readonly) WMAudioFrame* inputFrame;
@property (readonly) WMAudioFrame* outputFrame;
@end

#endif // __WMEProcessAudioFrameContext_DEFINED__

// Windows.Media.Effects.VideoTransformEffectDefinition
#ifndef __WMEVideoTransformEffectDefinition_DEFINED__
#define __WMEVideoTransformEffectDefinition_DEFINED__

WINRT_EXPORT
@interface WMEVideoTransformEffectDefinition : RTObject <WMEIVideoEffectDefinition>
+ (instancetype)create ACTIVATOR;
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@property WMMMediaRotation rotation;
@property WMTMediaVideoProcessingAlgorithm processingAlgorithm;
@property (copy) WUColor* paddingColor;
@property (copy) WFSize* outputSize;
@property WMMMediaMirroringOptions mirror;
@property (copy) WFRect* cropRectangle;
@end

#endif // __WMEVideoTransformEffectDefinition_DEFINED__
