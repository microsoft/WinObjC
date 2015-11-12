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

// WindowsMediaAudio.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMAAudioGraph, WMACreateAudioGraphResult, WMAAudioGraphSettings, WMAAudioDeviceInputNode, WMACreateAudioDeviceInputNodeResult,
    WMAAudioDeviceOutputNode, WMACreateAudioDeviceOutputNodeResult, WMAAudioFileInputNode, WMACreateAudioFileInputNodeResult,
    WMAAudioFileOutputNode, WMACreateAudioFileOutputNodeResult, WMAAudioGraphUnrecoverableErrorOccurredEventArgs, WMAAudioFrameInputNode,
    WMAAudioFrameOutputNode, WMAAudioSubmixNode, WMAAudioGraphConnection, WMAAudioFrameCompletedEventArgs,
    WMAFrameInputNodeQuantumStartedEventArgs, WMAEqualizerBand, WMAEqualizerEffectDefinition, WMAReverbEffectDefinition,
    WMAEchoEffectDefinition, WMALimiterEffectDefinition;
@protocol WMAICreateAudioGraphResult
, WMAIAudioGraphSettingsFactory, WMAIAudioGraphSettings, WMAIAudioGraphStatics, WMAICreateAudioDeviceInputNodeResult,
    WMAICreateAudioDeviceOutputNodeResult, WMAICreateAudioFileInputNodeResult, WMAICreateAudioFileOutputNodeResult,
    WMAIAudioGraphUnrecoverableErrorOccurredEventArgs, WMAIAudioGraph, WMAIAudioNode, WMAIAudioInputNode, WMAIAudioFrameInputNode,
    WMAIAudioFileInputNode, WMAIAudioDeviceInputNode, WMAIAudioDeviceOutputNode, WMAIAudioFrameOutputNode, WMAIAudioFileOutputNode,
    WMAIAudioFrameCompletedEventArgs, WMAIFrameInputNodeQuantumStartedEventArgs, WMAIAudioGraphConnection, WMAIEqualizerBand,
    WMAIEqualizerEffectDefinitionFactory, WMAIReverbEffectDefinitionFactory, WMAIEchoEffectDefinitionFactory,
    WMAILimiterEffectDefinitionFactory, WMAIEqualizerEffectDefinition, WMAIReverbEffectDefinition, WMAIEchoEffectDefinition,
    WMAILimiterEffectDefinition;

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

#include "WindowsMedia.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsFoundationCollections.h"
#include "WindowsMediaRender.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsFoundation.h"
#include "WindowsMediaCapture.h"
#include "WindowsStorage.h"
#include "WindowsMediaEffects.h"
#include "WindowsMediaTranscoding.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.Audio.IAudioNode
#ifndef __WMAIAudioNode_DEFINED__
#define __WMAIAudioNode_DEFINED__

@protocol WMAIAudioNode <WFIClosable>
@property BOOL consumeInput;
@property (readonly) NSMutableArray* effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
@property double outgoingGain;
- (void)start;
- (void)stop;
- (void)reset;
- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition;
- (void)close;
@end

#endif // __WMAIAudioNode_DEFINED__

// Windows.Media.Audio.IAudioInputNode
#ifndef __WMAIAudioInputNode_DEFINED__
#define __WMAIAudioInputNode_DEFINED__

@protocol WMAIAudioInputNode <WMAIAudioNode, WFIClosable>
@property (readonly) NSArray* outgoingConnections;
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

#endif // __WMAIAudioInputNode_DEFINED__

// Windows.Media.Audio.AudioGraph
#ifndef __WMAAudioGraph_DEFINED__
#define __WMAAudioGraph_DEFINED__

WINRT_EXPORT
@interface WMAAudioGraph : RTObject <WFIClosable>
+ (void)createAsync:(WMAAudioGraphSettings*)settings
            success:(void (^)(WMACreateAudioGraphResult*))success
            failure:(void (^)(NSError*))failure;
@property (readonly) uint64_t completedQuantumCount;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
@property (readonly) int latencyInSamples;
@property (readonly) WDEDeviceInformation* primaryRenderDevice;
@property (readonly) WMAudioProcessing renderDeviceAudioProcessing;
@property (readonly) int samplesPerQuantum;
- (EventRegistrationToken)addQuantumProcessedEvent:(void (^)(WMAAudioGraph*, RTObject*))del;
- (void)removeQuantumProcessedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQuantumStartedEvent:(void (^)(WMAAudioGraph*, RTObject*))del;
- (void)removeQuantumStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnrecoverableErrorOccurredEvent:(void (^)(WMAAudioGraph*,
                                                                       WMAAudioGraphUnrecoverableErrorOccurredEventArgs*))del;
- (void)removeUnrecoverableErrorOccurredEvent:(EventRegistrationToken)tok;
- (WMAAudioFrameInputNode*)createFrameInputNode;
- (WMAAudioFrameInputNode*)createFrameInputNodeWithFormat:(WMMAudioEncodingProperties*)encodingProperties;
- (void)createDeviceInputNodeAsync:(WMCMediaCategory)category
                           success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success
                           failure:(void (^)(NSError*))failure;
- (void)createDeviceInputNodeWithFormatAsync:(WMCMediaCategory)category
                          encodingProperties:(WMMAudioEncodingProperties*)encodingProperties
                                     success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success
                                     failure:(void (^)(NSError*))failure;
- (void)createDeviceInputNodeWithFormatOnDeviceAsync:(WMCMediaCategory)category
                                  encodingProperties:(WMMAudioEncodingProperties*)encodingProperties
                                              device:(WDEDeviceInformation*)device
                                             success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success
                                             failure:(void (^)(NSError*))failure;
- (WMAAudioFrameOutputNode*)createFrameOutputNode;
- (WMAAudioFrameOutputNode*)createFrameOutputNodeWithFormat:(WMMAudioEncodingProperties*)encodingProperties;
- (void)createDeviceOutputNodeAsyncWithSuccess:(void (^)(WMACreateAudioDeviceOutputNodeResult*))success failure:(void (^)(NSError*))failure;
- (void)createFileInputNodeAsync:(RTObject<WSIStorageFile>*)file
                         success:(void (^)(WMACreateAudioFileInputNodeResult*))success
                         failure:(void (^)(NSError*))failure;
- (void)createFileOutputNodeAsync:(RTObject<WSIStorageFile>*)file
                          success:(void (^)(WMACreateAudioFileOutputNodeResult*))success
                          failure:(void (^)(NSError*))failure;
- (void)createFileOutputNodeWithFileProfileAsync:(RTObject<WSIStorageFile>*)file
                             fileEncodingProfile:(WMMMediaEncodingProfile*)fileEncodingProfile
                                         success:(void (^)(WMACreateAudioFileOutputNodeResult*))success
                                         failure:(void (^)(NSError*))failure;
- (WMAAudioSubmixNode*)createSubmixNode;
- (WMAAudioSubmixNode*)createSubmixNodeWithFormat:(WMMAudioEncodingProperties*)encodingProperties;
- (void)start;
- (void)stop;
- (void)resetAllNodes;
- (void)close;
@end

#endif // __WMAAudioGraph_DEFINED__

// Windows.Media.Audio.CreateAudioGraphResult
#ifndef __WMACreateAudioGraphResult_DEFINED__
#define __WMACreateAudioGraphResult_DEFINED__

WINRT_EXPORT
@interface WMACreateAudioGraphResult : RTObject
@property (readonly) WMAAudioGraph* graph;
@property (readonly) WMAAudioGraphCreationStatus status;
@end

#endif // __WMACreateAudioGraphResult_DEFINED__

// Windows.Media.Audio.AudioGraphSettings
#ifndef __WMAAudioGraphSettings_DEFINED__
#define __WMAAudioGraphSettings_DEFINED__

WINRT_EXPORT
@interface WMAAudioGraphSettings : RTObject
+ (WMAAudioGraphSettings*)create:(WMRAudioRenderCategory)audioRenderCategory ACTIVATOR;
@property WMAQuantumSizeSelectionMode quantumSizeSelectionMode;
@property (copy) WDEDeviceInformation* primaryRenderDevice;
@property (copy) WMMAudioEncodingProperties* encodingProperties;
@property int desiredSamplesPerQuantum;
@property WMAudioProcessing desiredRenderDeviceAudioProcessing;
@property WMRAudioRenderCategory audioRenderCategory;
@end

#endif // __WMAAudioGraphSettings_DEFINED__

// Windows.Media.Audio.AudioDeviceInputNode
#ifndef __WMAAudioDeviceInputNode_DEFINED__
#define __WMAAudioDeviceInputNode_DEFINED__

WINRT_EXPORT
@interface WMAAudioDeviceInputNode : RTObject <WMAIAudioInputNode, WMAIAudioNode, WFIClosable>
@property (readonly) WDEDeviceInformation* device;
@property (readonly) NSArray* outgoingConnections;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* effectDefinitions;
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

WINRT_EXPORT
@interface WMACreateAudioDeviceInputNodeResult : RTObject
@property (readonly) WMAAudioDeviceInputNode* deviceInputNode;
@property (readonly) WMAAudioDeviceNodeCreationStatus status;
@end

#endif // __WMACreateAudioDeviceInputNodeResult_DEFINED__

// Windows.Media.Audio.AudioDeviceOutputNode
#ifndef __WMAAudioDeviceOutputNode_DEFINED__
#define __WMAAudioDeviceOutputNode_DEFINED__

WINRT_EXPORT
@interface WMAAudioDeviceOutputNode : RTObject <WMAIAudioNode, WFIClosable>
@property (readonly) WDEDeviceInformation* device;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
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

WINRT_EXPORT
@interface WMACreateAudioDeviceOutputNodeResult : RTObject
@property (readonly) WMAAudioDeviceOutputNode* deviceOutputNode;
@property (readonly) WMAAudioDeviceNodeCreationStatus status;
@end

#endif // __WMACreateAudioDeviceOutputNodeResult_DEFINED__

// Windows.Media.Audio.AudioFileInputNode
#ifndef __WMAAudioFileInputNode_DEFINED__
#define __WMAAudioFileInputNode_DEFINED__

WINRT_EXPORT
@interface WMAAudioFileInputNode : RTObject <WMAIAudioInputNode, WMAIAudioNode, WFIClosable>
@property double playbackSpeedFactor;
@property (copy) id loopCount;
@property (copy) id endTime;
@property (copy) id startTime;
@property (readonly) WFTimeSpan* position;
@property (readonly) WSStorageFile* sourceFile;
@property (readonly) WFTimeSpan* duration;
@property (readonly) NSArray* outgoingConnections;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
- (EventRegistrationToken)addFileCompletedEvent:(void (^)(WMAAudioFileInputNode*, RTObject*))del;
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

WINRT_EXPORT
@interface WMACreateAudioFileInputNodeResult : RTObject
@property (readonly) WMAAudioFileInputNode* fileInputNode;
@property (readonly) WMAAudioFileNodeCreationStatus status;
@end

#endif // __WMACreateAudioFileInputNodeResult_DEFINED__

// Windows.Media.Audio.AudioFileOutputNode
#ifndef __WMAAudioFileOutputNode_DEFINED__
#define __WMAAudioFileOutputNode_DEFINED__

WINRT_EXPORT
@interface WMAAudioFileOutputNode : RTObject <WMAIAudioNode, WFIClosable>
@property (readonly) RTObject<WSIStorageFile>* file;
@property (readonly) WMMMediaEncodingProfile* fileEncodingProfile;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* effectDefinitions;
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

WINRT_EXPORT
@interface WMACreateAudioFileOutputNodeResult : RTObject
@property (readonly) WMAAudioFileOutputNode* fileOutputNode;
@property (readonly) WMAAudioFileNodeCreationStatus status;
@end

#endif // __WMACreateAudioFileOutputNodeResult_DEFINED__

// Windows.Media.Audio.AudioGraphUnrecoverableErrorOccurredEventArgs
#ifndef __WMAAudioGraphUnrecoverableErrorOccurredEventArgs_DEFINED__
#define __WMAAudioGraphUnrecoverableErrorOccurredEventArgs_DEFINED__

WINRT_EXPORT
@interface WMAAudioGraphUnrecoverableErrorOccurredEventArgs : RTObject
@property (readonly) WMAAudioGraphUnrecoverableError error;
@end

#endif // __WMAAudioGraphUnrecoverableErrorOccurredEventArgs_DEFINED__

// Windows.Media.Audio.AudioFrameInputNode
#ifndef __WMAAudioFrameInputNode_DEFINED__
#define __WMAAudioFrameInputNode_DEFINED__

WINRT_EXPORT
@interface WMAAudioFrameInputNode : RTObject <WMAIAudioInputNode, WMAIAudioNode, WFIClosable>
@property double playbackSpeedFactor;
@property (readonly) uint64_t queuedSampleCount;
@property (readonly) NSArray* outgoingConnections;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* effectDefinitions;
@property (readonly) WMMAudioEncodingProperties* encodingProperties;
- (EventRegistrationToken)addAudioFrameCompletedEvent:(void (^)(WMAAudioFrameInputNode*, WMAAudioFrameCompletedEventArgs*))del;
- (void)removeAudioFrameCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQuantumStartedEvent:(void (^)(WMAAudioFrameInputNode*, WMAFrameInputNodeQuantumStartedEventArgs*))del;
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

WINRT_EXPORT
@interface WMAAudioFrameOutputNode : RTObject <WMAIAudioNode, WFIClosable>
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* effectDefinitions;
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

WINRT_EXPORT
@interface WMAAudioSubmixNode : RTObject <WMAIAudioInputNode, WMAIAudioNode, WFIClosable>
@property (readonly) NSArray* outgoingConnections;
@property double outgoingGain;
@property BOOL consumeInput;
@property (readonly) NSMutableArray* effectDefinitions;
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

// Windows.Media.Audio.AudioGraphConnection
#ifndef __WMAAudioGraphConnection_DEFINED__
#define __WMAAudioGraphConnection_DEFINED__

WINRT_EXPORT
@interface WMAAudioGraphConnection : RTObject
@property double gain;
@property (readonly) RTObject<WMAIAudioNode>* destination;
@end

#endif // __WMAAudioGraphConnection_DEFINED__

// Windows.Media.Audio.AudioFrameCompletedEventArgs
#ifndef __WMAAudioFrameCompletedEventArgs_DEFINED__
#define __WMAAudioFrameCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMAAudioFrameCompletedEventArgs : RTObject
@property (readonly) WMAudioFrame* frame;
@end

#endif // __WMAAudioFrameCompletedEventArgs_DEFINED__

// Windows.Media.Audio.FrameInputNodeQuantumStartedEventArgs
#ifndef __WMAFrameInputNodeQuantumStartedEventArgs_DEFINED__
#define __WMAFrameInputNodeQuantumStartedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMAFrameInputNodeQuantumStartedEventArgs : RTObject
@property (readonly) int requiredSamples;
@end

#endif // __WMAFrameInputNodeQuantumStartedEventArgs_DEFINED__

// Windows.Media.Audio.EqualizerBand
#ifndef __WMAEqualizerBand_DEFINED__
#define __WMAEqualizerBand_DEFINED__

WINRT_EXPORT
@interface WMAEqualizerBand : RTObject
@property double gain;
@property double frequencyCenter;
@property double bandwidth;
@end

#endif // __WMAEqualizerBand_DEFINED__

// Windows.Media.Effects.IAudioEffectDefinition
#ifndef __WMEIAudioEffectDefinition_DEFINED__
#define __WMEIAudioEffectDefinition_DEFINED__

@protocol WMEIAudioEffectDefinition
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMEIAudioEffectDefinition_DEFINED__

// Windows.Media.Audio.EqualizerEffectDefinition
#ifndef __WMAEqualizerEffectDefinition_DEFINED__
#define __WMAEqualizerEffectDefinition_DEFINED__

WINRT_EXPORT
@interface WMAEqualizerEffectDefinition : RTObject <WMEIAudioEffectDefinition>
+ (WMAEqualizerEffectDefinition*)create:(WMAAudioGraph*)audioGraph ACTIVATOR;
@property (readonly) NSArray* bands;
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMAEqualizerEffectDefinition_DEFINED__

// Windows.Media.Audio.ReverbEffectDefinition
#ifndef __WMAReverbEffectDefinition_DEFINED__
#define __WMAReverbEffectDefinition_DEFINED__

WINRT_EXPORT
@interface WMAReverbEffectDefinition : RTObject <WMEIAudioEffectDefinition>
+ (WMAReverbEffectDefinition*)create:(WMAAudioGraph*)audioGraph ACTIVATOR;
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
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMAReverbEffectDefinition_DEFINED__

// Windows.Media.Audio.EchoEffectDefinition
#ifndef __WMAEchoEffectDefinition_DEFINED__
#define __WMAEchoEffectDefinition_DEFINED__

WINRT_EXPORT
@interface WMAEchoEffectDefinition : RTObject <WMEIAudioEffectDefinition>
+ (WMAEchoEffectDefinition*)create:(WMAAudioGraph*)audioGraph ACTIVATOR;
@property double wetDryMix;
@property double feedback;
@property double delay;
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMAEchoEffectDefinition_DEFINED__

// Windows.Media.Audio.LimiterEffectDefinition
#ifndef __WMALimiterEffectDefinition_DEFINED__
#define __WMALimiterEffectDefinition_DEFINED__

WINRT_EXPORT
@interface WMALimiterEffectDefinition : RTObject <WMEIAudioEffectDefinition>
+ (WMALimiterEffectDefinition*)create:(WMAAudioGraph*)audioGraph ACTIVATOR;
@property unsigned int release;
@property unsigned int loudness;
@property (readonly) NSString* activatableClassId;
@property (readonly) RTObject<WFCIPropertySet>* properties;
@end

#endif // __WMALimiterEffectDefinition_DEFINED__
