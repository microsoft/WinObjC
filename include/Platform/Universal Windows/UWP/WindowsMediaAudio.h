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

// WindowsMediaAudio.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIAAUDIOEXPORT
#define OBJCUWPWINDOWSMEDIAAUDIOEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaAudio.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMAAudioGraph, WMACreateAudioGraphResult, WMAAudioGraphSettings, WMAAudioDeviceInputNode, WMACreateAudioDeviceInputNodeResult, WMAAudioDeviceOutputNode, WMACreateAudioDeviceOutputNodeResult, WMAAudioFileInputNode, WMACreateAudioFileInputNodeResult, WMAAudioFileOutputNode, WMACreateAudioFileOutputNodeResult, WMAAudioGraphUnrecoverableErrorOccurredEventArgs, WMAAudioGraphBatchUpdater, WMAAudioFrameInputNode, WMAAudioFrameOutputNode, WMAAudioSubmixNode, WMAAudioNodeEmitter, WMAAudioNodeListener, WMAAudioGraphConnection, WMAAudioFrameCompletedEventArgs, WMAFrameInputNodeQuantumStartedEventArgs, WMAEqualizerBand, WMAEqualizerEffectDefinition, WMAReverbEffectDefinition, WMAEchoEffectDefinition, WMALimiterEffectDefinition, WMAAudioNodeEmitterConeProperties, WMAAudioNodeEmitterShape, WMAAudioNodeEmitterNaturalDecayModelProperties, WMAAudioNodeEmitterDecayModel;
@protocol WMAICreateAudioGraphResult, WMAIAudioGraphSettingsFactory, WMAIAudioGraphSettings, WMAIAudioGraphStatics, WMAICreateAudioDeviceInputNodeResult, WMAICreateAudioDeviceOutputNodeResult, WMAICreateAudioFileInputNodeResult, WMAICreateAudioFileOutputNodeResult, WMAIAudioGraphUnrecoverableErrorOccurredEventArgs, WMAIAudioGraph, WMAIAudioGraph2, WMAIAudioNode, WMAIAudioNodeWithListener, WMAIAudioInputNode, WMAIAudioInputNode2, WMAIAudioFrameInputNode, WMAIAudioFileInputNode, WMAIAudioDeviceInputNode, WMAIAudioDeviceOutputNode, WMAIAudioFrameOutputNode, WMAIAudioFileOutputNode, WMAIAudioFrameCompletedEventArgs, WMAIFrameInputNodeQuantumStartedEventArgs, WMAIAudioGraphConnection, WMAIEqualizerBand, WMAIEqualizerEffectDefinitionFactory, WMAIReverbEffectDefinitionFactory, WMAIEchoEffectDefinitionFactory, WMAILimiterEffectDefinitionFactory, WMAIAudioNodeEmitterConeProperties, WMAIAudioNodeEmitterShape, WMAIAudioNodeEmitterShapeStatics, WMAIAudioNodeEmitterNaturalDecayModelProperties, WMAIAudioNodeEmitterDecayModel, WMAIAudioNodeEmitterDecayModelStatics, WMAIAudioNodeEmitter, WMAIAudioNodeEmitter2, WMAIAudioNodeEmitterFactory, WMAIAudioNodeListener, WMAIEqualizerEffectDefinition, WMAIReverbEffectDefinition, WMAIEchoEffectDefinition, WMAILimiterEffectDefinition;

// Windows.Media.Audio.AudioGraphCreationStatus
enum _WMAAudioGraphCreationStatus {
    WMAAudioGraphCreationStatusSuccess = 0,
    WMAAudioGraphCreationStatusDeviceNotAvailable = 1,
    WMAAudioGraphCreationStatusFormatNotSupported = 2,
    WMAAudioGraphCreationStatusUnknownFailure = 3,
};
typedef unsigned WMAAudioGraphCreationStatus;

// Windows.Media.Audio.QuantumSizeSelectionMode
enum _WMAQuantumSizeSelectionMode {
    WMAQuantumSizeSelectionModeSystemDefault = 0,
    WMAQuantumSizeSelectionModeLowestLatency = 1,
    WMAQuantumSizeSelectionModeClosestToDesired = 2,
};
typedef unsigned WMAQuantumSizeSelectionMode;

// Windows.Media.Audio.AudioDeviceNodeCreationStatus
enum _WMAAudioDeviceNodeCreationStatus {
    WMAAudioDeviceNodeCreationStatusSuccess = 0,
    WMAAudioDeviceNodeCreationStatusDeviceNotAvailable = 1,
    WMAAudioDeviceNodeCreationStatusFormatNotSupported = 2,
    WMAAudioDeviceNodeCreationStatusUnknownFailure = 3,
    WMAAudioDeviceNodeCreationStatusAccessDenied = 4,
};
typedef unsigned WMAAudioDeviceNodeCreationStatus;

// Windows.Media.Audio.AudioFileNodeCreationStatus
enum _WMAAudioFileNodeCreationStatus {
    WMAAudioFileNodeCreationStatusSuccess = 0,
    WMAAudioFileNodeCreationStatusFileNotFound = 1,
    WMAAudioFileNodeCreationStatusInvalidFileType = 2,
    WMAAudioFileNodeCreationStatusFormatNotSupported = 3,
    WMAAudioFileNodeCreationStatusUnknownFailure = 4,
};
typedef unsigned WMAAudioFileNodeCreationStatus;

// Windows.Media.Audio.AudioGraphUnrecoverableError
enum _WMAAudioGraphUnrecoverableError {
    WMAAudioGraphUnrecoverableErrorNone = 0,
    WMAAudioGraphUnrecoverableErrorAudioDeviceLost = 1,
    WMAAudioGraphUnrecoverableErrorAudioSessionDisconnected = 2,
    WMAAudioGraphUnrecoverableErrorUnknownFailure = 3,
};
typedef unsigned WMAAudioGraphUnrecoverableError;

// Windows.Media.Audio.AudioNodeEmitterSettings
enum _WMAAudioNodeEmitterSettings {
    WMAAudioNodeEmitterSettingsNone = 0,
    WMAAudioNodeEmitterSettingsDisableDoppler = 1,
};
typedef unsigned WMAAudioNodeEmitterSettings;

// Windows.Media.Audio.AudioNodeEmitterShapeKind
enum _WMAAudioNodeEmitterShapeKind {
    WMAAudioNodeEmitterShapeKindOmnidirectional = 0,
    WMAAudioNodeEmitterShapeKindCone = 1,
};
typedef unsigned WMAAudioNodeEmitterShapeKind;

// Windows.Media.Audio.AudioNodeEmitterDecayKind
enum _WMAAudioNodeEmitterDecayKind {
    WMAAudioNodeEmitterDecayKindNatural = 0,
    WMAAudioNodeEmitterDecayKindCustom = 1,
};
typedef unsigned WMAAudioNodeEmitterDecayKind;

// Windows.Media.Audio.SpatialAudioModel
enum _WMASpatialAudioModel {
    WMASpatialAudioModelObjectBased = 0,
    WMASpatialAudioModelFoldDown = 1,
};
typedef unsigned WMASpatialAudioModel;

#include "WindowsMedia.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsMediaRender.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsFoundation.h"
#include "WindowsMediaEffects.h"
#include "WindowsMediaCapture.h"
#include "WindowsStorage.h"
#include "WindowsMediaTranscoding.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.Audio.IAudioNode
#ifndef __WMAIAudioNode_DEFINED__
#define __WMAIAudioNode_DEFINED__

@protocol WMAIAudioNode <WFIClosable>
@property BOOL consumeInput;
@property (readonly) NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */ effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
@property double outgoingGain;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAIAudioNode : RTObject <WMAIAudioNode>
@end

#endif // __WMAIAudioNode_DEFINED__

// Windows.Media.Audio.IAudioNodeWithListener
#ifndef __WMAIAudioNodeWithListener_DEFINED__
#define __WMAIAudioNodeWithListener_DEFINED__

@protocol WMAIAudioNodeWithListener <WFIClosable, WMAIAudioNode>
@property (retain) WMAAudioNodeListener* listener;
- (void)close;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
@end

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAIAudioNodeWithListener : RTObject <WMAIAudioNodeWithListener>
@end

#endif // __WMAIAudioNodeWithListener_DEFINED__

// Windows.Media.Audio.IAudioInputNode
#ifndef __WMAIAudioInputNode_DEFINED__
#define __WMAIAudioInputNode_DEFINED__

@protocol WMAIAudioInputNode <WMAIAudioNode, WFIClosable>
@property (readonly) NSArray* /* WMAAudioGraphConnection* */ outgoingConnections;
- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain;
- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAIAudioInputNode : RTObject <WMAIAudioInputNode>
@end

#endif // __WMAIAudioInputNode_DEFINED__

// Windows.Media.Audio.IAudioInputNode2
#ifndef __WMAIAudioInputNode2_DEFINED__
#define __WMAIAudioInputNode2_DEFINED__

@protocol WMAIAudioInputNode2 <WMAIAudioNode, WFIClosable, WMAIAudioInputNode>
@property (readonly) WMAAudioNodeEmitter* emitter;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain;
- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
@end

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAIAudioInputNode2 : RTObject <WMAIAudioInputNode2>
@end

#endif // __WMAIAudioInputNode2_DEFINED__

// Windows.Media.Audio.AudioGraph
#ifndef __WMAAudioGraph_DEFINED__
#define __WMAAudioGraph_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioGraph : RTObject <WFIClosable>
+ (void)createAsync:(WMAAudioGraphSettings*)settings success:(void (^)(WMACreateAudioGraphResult*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t completedQuantumCount;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
@property (readonly) int latencyInSamples;
@property (readonly) WDEDeviceInformation* primaryRenderDevice;
@property (readonly) WMAudioProcessing renderDeviceAudioProcessing;
@property (readonly) int samplesPerQuantum;
- (EventRegistrationToken)addQuantumProcessedEvent:(void(^)(WMAAudioGraph*, RTObject*))del;
- (void)removeQuantumProcessedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQuantumStartedEvent:(void(^)(WMAAudioGraph*, RTObject*))del;
- (void)removeQuantumStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnrecoverableErrorOccurredEvent:(void(^)(WMAAudioGraph*, WMAAudioGraphUnrecoverableErrorOccurredEventArgs*))del;
- (void)removeUnrecoverableErrorOccurredEvent:(EventRegistrationToken)tok;
- (WMAAudioFrameInputNode*)createFrameInputNode;
- (WMAAudioFrameInputNode*)createFrameInputNodeWithFormat:(WMMAudioEncodingProperties*)encodingProperties;
- (void)createDeviceInputNodeAsync:(WMCMediaCategory)category success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success failure:(void (^)(NSError*))failure;
- (void)createDeviceInputNodeWithFormatAsync:(WMCMediaCategory)category encodingProperties:(WMMAudioEncodingProperties*)encodingProperties success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success failure:(void (^)(NSError*))failure;
- (void)createDeviceInputNodeWithFormatOnDeviceAsync:(WMCMediaCategory)category encodingProperties:(WMMAudioEncodingProperties*)encodingProperties device:(WDEDeviceInformation*)device success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success failure:(void (^)(NSError*))failure;
- (WMAAudioFrameOutputNode*)createFrameOutputNode;
- (WMAAudioFrameOutputNode*)createFrameOutputNodeWithFormat:(WMMAudioEncodingProperties*)encodingProperties;
- (void)createDeviceOutputNodeAsyncWithSuccess:(void (^)(WMACreateAudioDeviceOutputNodeResult*))success failure:(void (^)(NSError*))failure;
- (void)createFileInputNodeAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WMACreateAudioFileInputNodeResult*))success failure:(void (^)(NSError*))failure;
- (void)createFileOutputNodeAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WMACreateAudioFileOutputNodeResult*))success failure:(void (^)(NSError*))failure;
- (void)createFileOutputNodeWithFileProfileAsync:(RTObject<WSIStorageFile>*)file fileEncodingProfile:(WMMMediaEncodingProfile*)fileEncodingProfile success:(void (^)(WMACreateAudioFileOutputNodeResult*))success failure:(void (^)(NSError*))failure;
- (WMAAudioSubmixNode*)createSubmixNode;
- (WMAAudioSubmixNode*)createSubmixNodeWithFormat:(WMMAudioEncodingProperties*)encodingProperties;
- (void)start;
- (void)stop;
- (void)resetAllNodes;
- (void)close;
- (WMAAudioFrameInputNode*)createFrameInputNodeWithFormatAndEmitter:(WMMAudioEncodingProperties*)encodingProperties emitter:(WMAAudioNodeEmitter*)emitter;
- (void)createDeviceInputNodeWithFormatAndEmitterOnDeviceAsync:(WMCMediaCategory)category encodingProperties:(WMMAudioEncodingProperties*)encodingProperties device:(WDEDeviceInformation*)device emitter:(WMAAudioNodeEmitter*)emitter success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success failure:(void (^)(NSError*))failure;
- (void)createFileInputNodeWithEmitterAsync:(RTObject<WSIStorageFile>*)file emitter:(WMAAudioNodeEmitter*)emitter success:(void (^)(WMACreateAudioFileInputNodeResult*))success failure:(void (^)(NSError*))failure;
- (WMAAudioSubmixNode*)createSubmixNodeWithFormatAndEmitter:(WMMAudioEncodingProperties*)encodingProperties emitter:(WMAAudioNodeEmitter*)emitter;
- (WMAAudioGraphBatchUpdater*)createBatchUpdater;
@end

#endif // __WMAAudioGraph_DEFINED__

// Windows.Media.Audio.CreateAudioGraphResult
#ifndef __WMACreateAudioGraphResult_DEFINED__
#define __WMACreateAudioGraphResult_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMACreateAudioGraphResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMAAudioGraph* graph;
@property (readonly) WMAAudioGraphCreationStatus status;
@end

#endif // __WMACreateAudioGraphResult_DEFINED__

// Windows.Media.Audio.AudioGraphSettings
#ifndef __WMAAudioGraphSettings_DEFINED__
#define __WMAAudioGraphSettings_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioGraphSettings : RTObject
+ (WMAAudioGraphSettings*)make:(WMRAudioRenderCategory)audioRenderCategory ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WMAQuantumSizeSelectionMode quantumSizeSelectionMode;
@property (retain) WDEDeviceInformation* primaryRenderDevice;
@property (retain) WMMAudioEncodingProperties* encodingProperties;
@property int desiredSamplesPerQuantum;
@property WMAudioProcessing desiredRenderDeviceAudioProcessing;
@property WMRAudioRenderCategory audioRenderCategory;
@end

#endif // __WMAAudioGraphSettings_DEFINED__

// Windows.Media.Audio.AudioDeviceInputNode
#ifndef __WMAAudioDeviceInputNode_DEFINED__
#define __WMAAudioDeviceInputNode_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioDeviceInputNode : RTObject <WMAIAudioInputNode, WMAIAudioNode, WFIClosable, WMAIAudioInputNode2>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDEDeviceInformation* device;
@property (readonly) NSArray* /* WMAAudioGraphConnection* */ outgoingConnections;
@property (readonly) WMAAudioNodeEmitter* emitter;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */ effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain;
- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

#endif // __WMAAudioDeviceInputNode_DEFINED__

// Windows.Media.Audio.CreateAudioDeviceInputNodeResult
#ifndef __WMACreateAudioDeviceInputNodeResult_DEFINED__
#define __WMACreateAudioDeviceInputNodeResult_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMACreateAudioDeviceInputNodeResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMAAudioDeviceInputNode* deviceInputNode;
@property (readonly) WMAAudioDeviceNodeCreationStatus status;
@end

#endif // __WMACreateAudioDeviceInputNodeResult_DEFINED__

// Windows.Media.Audio.AudioDeviceOutputNode
#ifndef __WMAAudioDeviceOutputNode_DEFINED__
#define __WMAAudioDeviceOutputNode_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioDeviceOutputNode : RTObject <WMAIAudioNode, WFIClosable, WMAIAudioNodeWithListener>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDEDeviceInformation* device;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */ effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
@property (retain) WMAAudioNodeListener* listener;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

#endif // __WMAAudioDeviceOutputNode_DEFINED__

// Windows.Media.Audio.CreateAudioDeviceOutputNodeResult
#ifndef __WMACreateAudioDeviceOutputNodeResult_DEFINED__
#define __WMACreateAudioDeviceOutputNodeResult_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMACreateAudioDeviceOutputNodeResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMAAudioDeviceOutputNode* deviceOutputNode;
@property (readonly) WMAAudioDeviceNodeCreationStatus status;
@end

#endif // __WMACreateAudioDeviceOutputNodeResult_DEFINED__

// Windows.Media.Audio.AudioFileInputNode
#ifndef __WMAAudioFileInputNode_DEFINED__
#define __WMAAudioFileInputNode_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioFileInputNode : RTObject <WMAIAudioInputNode, WMAIAudioNode, WFIClosable, WMAIAudioInputNode2>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double playbackSpeedFactor;
@property (retain) id /* int */ loopCount;
@property (retain) id /* WFTimeSpan* */ endTime;
@property (retain) id /* WFTimeSpan* */ startTime;
@property (readonly) WFTimeSpan* position;
@property (readonly) WSStorageFile* sourceFile;
@property (readonly) WFTimeSpan* duration;
@property (readonly) NSArray* /* WMAAudioGraphConnection* */ outgoingConnections;
@property (readonly) WMAAudioNodeEmitter* emitter;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */ effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
- (EventRegistrationToken)addFileCompletedEvent:(void(^)(WMAAudioFileInputNode*, RTObject*))del;
- (void)removeFileCompletedEvent:(EventRegistrationToken)tok;
- (void)seek:(WFTimeSpan*)position;
- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain;
- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

#endif // __WMAAudioFileInputNode_DEFINED__

// Windows.Media.Audio.CreateAudioFileInputNodeResult
#ifndef __WMACreateAudioFileInputNodeResult_DEFINED__
#define __WMACreateAudioFileInputNodeResult_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMACreateAudioFileInputNodeResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMAAudioFileInputNode* fileInputNode;
@property (readonly) WMAAudioFileNodeCreationStatus status;
@end

#endif // __WMACreateAudioFileInputNodeResult_DEFINED__

// Windows.Media.Audio.AudioFileOutputNode
#ifndef __WMAAudioFileOutputNode_DEFINED__
#define __WMAAudioFileOutputNode_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioFileOutputNode : RTObject <WMAIAudioNode, WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSIStorageFile>* file;
@property (readonly) WMMMediaEncodingProfile* fileEncodingProfile;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */ effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
- (void)finalizeAsyncWithSuccess:(void (^)(WMTTranscodeFailureReason))success failure:(void (^)(NSError*))failure;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

#endif // __WMAAudioFileOutputNode_DEFINED__

// Windows.Media.Audio.CreateAudioFileOutputNodeResult
#ifndef __WMACreateAudioFileOutputNodeResult_DEFINED__
#define __WMACreateAudioFileOutputNodeResult_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMACreateAudioFileOutputNodeResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMAAudioFileOutputNode* fileOutputNode;
@property (readonly) WMAAudioFileNodeCreationStatus status;
@end

#endif // __WMACreateAudioFileOutputNodeResult_DEFINED__

// Windows.Media.Audio.AudioGraphUnrecoverableErrorOccurredEventArgs
#ifndef __WMAAudioGraphUnrecoverableErrorOccurredEventArgs_DEFINED__
#define __WMAAudioGraphUnrecoverableErrorOccurredEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioGraphUnrecoverableErrorOccurredEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMAAudioGraphUnrecoverableError error;
@end

#endif // __WMAAudioGraphUnrecoverableErrorOccurredEventArgs_DEFINED__

// Windows.Media.Audio.AudioGraphBatchUpdater
#ifndef __WMAAudioGraphBatchUpdater_DEFINED__
#define __WMAAudioGraphBatchUpdater_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioGraphBatchUpdater : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)close;
@end

#endif // __WMAAudioGraphBatchUpdater_DEFINED__

// Windows.Media.Audio.AudioFrameInputNode
#ifndef __WMAAudioFrameInputNode_DEFINED__
#define __WMAAudioFrameInputNode_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioFrameInputNode : RTObject <WMAIAudioInputNode, WMAIAudioNode, WFIClosable, WMAIAudioInputNode2>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double playbackSpeedFactor;
@property (readonly) uint64_t queuedSampleCount;
@property (readonly) NSArray* /* WMAAudioGraphConnection* */ outgoingConnections;
@property (readonly) WMAAudioNodeEmitter* emitter;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */ effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
- (EventRegistrationToken)addAudioFrameCompletedEvent:(void(^)(WMAAudioFrameInputNode*, WMAAudioFrameCompletedEventArgs*))del;
- (void)removeAudioFrameCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQuantumStartedEvent:(void(^)(WMAAudioFrameInputNode*, WMAFrameInputNodeQuantumStartedEventArgs*))del;
- (void)removeQuantumStartedEvent:(EventRegistrationToken)tok;
- (void)addFrame:(WMAudioFrame*)frame;
- (void)discardQueuedFrames;
- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain;
- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

#endif // __WMAAudioFrameInputNode_DEFINED__

// Windows.Media.Audio.AudioFrameOutputNode
#ifndef __WMAAudioFrameOutputNode_DEFINED__
#define __WMAAudioFrameOutputNode_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioFrameOutputNode : RTObject <WMAIAudioNode, WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */ effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
- (WMAudioFrame*)getFrame;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

#endif // __WMAAudioFrameOutputNode_DEFINED__

// Windows.Media.Audio.AudioSubmixNode
#ifndef __WMAAudioSubmixNode_DEFINED__
#define __WMAAudioSubmixNode_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioSubmixNode : RTObject <WMAIAudioInputNode, WMAIAudioNode, WFIClosable, WMAIAudioInputNode2>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WMAAudioGraphConnection* */ outgoingConnections;
@property (readonly) WMAAudioNodeEmitter* emitter;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */ effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain;
- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

#endif // __WMAAudioSubmixNode_DEFINED__

// Windows.Media.Audio.AudioNodeEmitter
#ifndef __WMAAudioNodeEmitter_DEFINED__
#define __WMAAudioNodeEmitter_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioNodeEmitter : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WMAAudioNodeEmitter*)makeAudioNodeEmitter:(WMAAudioNodeEmitterShape*)shape decayModel:(WMAAudioNodeEmitterDecayModel*)decayModel settings:(WMAAudioNodeEmitterSettings)settings ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNVector3* position;
@property double gain;
@property (retain) WFNVector3* dopplerVelocity;
@property double dopplerScale;
@property double distanceScale;
@property (retain) WFNVector3* direction;
@property (readonly) WMAAudioNodeEmitterDecayModel* decayModel;
@property (readonly) BOOL isDopplerDisabled;
@property (readonly) WMAAudioNodeEmitterShape* shape;
@property WMASpatialAudioModel spatialAudioModel;
@end

#endif // __WMAAudioNodeEmitter_DEFINED__

// Windows.Media.Audio.AudioNodeListener
#ifndef __WMAAudioNodeListener_DEFINED__
#define __WMAAudioNodeListener_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioNodeListener : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double speedOfSound;
@property (retain) WFNVector3* position;
@property (retain) WFNQuaternion* orientation;
@property (retain) WFNVector3* dopplerVelocity;
@end

#endif // __WMAAudioNodeListener_DEFINED__

// Windows.Media.Audio.AudioGraphConnection
#ifndef __WMAAudioGraphConnection_DEFINED__
#define __WMAAudioGraphConnection_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioGraphConnection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double gain;
@property (readonly) RTObject<WMAIAudioNode>* destination;
@end

#endif // __WMAAudioGraphConnection_DEFINED__

// Windows.Media.Audio.AudioFrameCompletedEventArgs
#ifndef __WMAAudioFrameCompletedEventArgs_DEFINED__
#define __WMAAudioFrameCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioFrameCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMAudioFrame* frame;
@end

#endif // __WMAAudioFrameCompletedEventArgs_DEFINED__

// Windows.Media.Audio.FrameInputNodeQuantumStartedEventArgs
#ifndef __WMAFrameInputNodeQuantumStartedEventArgs_DEFINED__
#define __WMAFrameInputNodeQuantumStartedEventArgs_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAFrameInputNodeQuantumStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int requiredSamples;
@end

#endif // __WMAFrameInputNodeQuantumStartedEventArgs_DEFINED__

// Windows.Media.Audio.EqualizerBand
#ifndef __WMAEqualizerBand_DEFINED__
#define __WMAEqualizerBand_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAEqualizerBand : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double gain;
@property double frequencyCenter;
@property double bandwidth;
@end

#endif // __WMAEqualizerBand_DEFINED__

// Windows.Media.Effects.IAudioEffectDefinition
#ifndef __WMEIAudioEffectDefinition_DEFINED__
#define __WMEIAudioEffectDefinition_DEFINED__

@protocol WMEIAudioEffectDefinition
@property (readonly) NSString * activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMEIAudioEffectDefinition : RTObject <WMEIAudioEffectDefinition>
@end

#endif // __WMEIAudioEffectDefinition_DEFINED__

// Windows.Media.Audio.EqualizerEffectDefinition
#ifndef __WMAEqualizerEffectDefinition_DEFINED__
#define __WMAEqualizerEffectDefinition_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAEqualizerEffectDefinition : RTObject <WMEIAudioEffectDefinition>
+ (WMAEqualizerEffectDefinition*)make:(WMAAudioGraph*)audioGraph ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WMAEqualizerBand* */ bands;
@property (readonly) NSString * activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMAEqualizerEffectDefinition_DEFINED__

// Windows.Media.Audio.ReverbEffectDefinition
#ifndef __WMAReverbEffectDefinition_DEFINED__
#define __WMAReverbEffectDefinition_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAReverbEffectDefinition : RTObject <WMEIAudioEffectDefinition>
+ (WMAReverbEffectDefinition*)make:(WMAAudioGraph*)audioGraph ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property uint8_t highEQGain;
@property uint8_t highEQCutoff;
@property BOOL disableLateField;
@property double density;
@property uint8_t positionRight;
@property double decayTime;
@property uint8_t lateDiffusion;
@property uint8_t positionMatrixRight;
@property uint8_t positionMatrixLeft;
@property uint8_t positionLeft;
@property uint8_t lowEQGain;
@property uint8_t lowEQCutoff;
@property double roomFilterFreq;
@property double reverbGain;
@property uint8_t reverbDelay;
@property double reflectionsGain;
@property unsigned int reflectionsDelay;
@property uint8_t rearDelay;
@property double wetDryMix;
@property uint8_t earlyDiffusion;
@property double roomSize;
@property double roomFilterMain;
@property double roomFilterHF;
@property (readonly) NSString * activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMAReverbEffectDefinition_DEFINED__

// Windows.Media.Audio.EchoEffectDefinition
#ifndef __WMAEchoEffectDefinition_DEFINED__
#define __WMAEchoEffectDefinition_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAEchoEffectDefinition : RTObject <WMEIAudioEffectDefinition>
+ (WMAEchoEffectDefinition*)make:(WMAAudioGraph*)audioGraph ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double wetDryMix;
@property double feedback;
@property double delay;
@property (readonly) NSString * activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMAEchoEffectDefinition_DEFINED__

// Windows.Media.Audio.LimiterEffectDefinition
#ifndef __WMALimiterEffectDefinition_DEFINED__
#define __WMALimiterEffectDefinition_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMALimiterEffectDefinition : RTObject <WMEIAudioEffectDefinition>
+ (WMALimiterEffectDefinition*)make:(WMAAudioGraph*)audioGraph ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int Release;
@property unsigned int loudness;
@property (readonly) NSString * activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMALimiterEffectDefinition_DEFINED__

// Windows.Media.Audio.AudioNodeEmitterConeProperties
#ifndef __WMAAudioNodeEmitterConeProperties_DEFINED__
#define __WMAAudioNodeEmitterConeProperties_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioNodeEmitterConeProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double innerAngle;
@property (readonly) double outerAngle;
@property (readonly) double outerAngleGain;
@end

#endif // __WMAAudioNodeEmitterConeProperties_DEFINED__

// Windows.Media.Audio.AudioNodeEmitterShape
#ifndef __WMAAudioNodeEmitterShape_DEFINED__
#define __WMAAudioNodeEmitterShape_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioNodeEmitterShape : RTObject
+ (WMAAudioNodeEmitterShape*)createCone:(double)innerAngle outerAngle:(double)outerAngle outerAngleGain:(double)outerAngleGain;
+ (WMAAudioNodeEmitterShape*)createOmnidirectional;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMAAudioNodeEmitterConeProperties* coneProperties;
@property (readonly) WMAAudioNodeEmitterShapeKind kind;
@end

#endif // __WMAAudioNodeEmitterShape_DEFINED__

// Windows.Media.Audio.AudioNodeEmitterNaturalDecayModelProperties
#ifndef __WMAAudioNodeEmitterNaturalDecayModelProperties_DEFINED__
#define __WMAAudioNodeEmitterNaturalDecayModelProperties_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioNodeEmitterNaturalDecayModelProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double cutoffDistance;
@property (readonly) double unityGainDistance;
@end

#endif // __WMAAudioNodeEmitterNaturalDecayModelProperties_DEFINED__

// Windows.Media.Audio.AudioNodeEmitterDecayModel
#ifndef __WMAAudioNodeEmitterDecayModel_DEFINED__
#define __WMAAudioNodeEmitterDecayModel_DEFINED__

OBJCUWPWINDOWSMEDIAAUDIOEXPORT
@interface WMAAudioNodeEmitterDecayModel : RTObject
+ (WMAAudioNodeEmitterDecayModel*)createNatural:(double)minGain maxGain:(double)maxGain unityGainDistance:(double)unityGainDistance cutoffDistance:(double)cutoffDistance;
+ (WMAAudioNodeEmitterDecayModel*)createCustom:(double)minGain maxGain:(double)maxGain;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WMAAudioNodeEmitterDecayKind kind;
@property (readonly) double maxGain;
@property (readonly) double minGain;
@property (readonly) WMAAudioNodeEmitterNaturalDecayModelProperties* naturalProperties;
@end

#endif // __WMAAudioNodeEmitterDecayModel_DEFINED__

