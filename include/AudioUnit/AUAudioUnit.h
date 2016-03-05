//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#import <AudioUnit/AudioUnitExport.h>
#import <Foundation/NSObject.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <AudioUnit/AudioUnitComponent.h>
#import <AudioUnit/AudioUnitTypes.h>
#import <AudioUnit/AUParameterNode.h>
#import <AudioUnit/AudioComponent.h>

@class NSError;
@class NSString;
@class AUAudioUnitBusArray;
@class AUParameterTree;
@class NSArray;
@class NSDictionary;
@class AUAudioUnitPreset;
@class AVAudioFormat;
@class AUAudioUnitBus;

typedef enum : NSUInteger {
    AUHostTransportStateChanged = 1,
    AUHostTransportStateMoving = 2,
    AUHostTransportStateRecording = 4,
    AUHostTransportStateCycling = 8
} AUHostTransportStateFlags;

typedef enum : AUEventSampleTime { AUEventSampleTimeImmediate = (AUEventSampleTime)0xffffffff00000000LL };
typedef enum : NSInteger { AUAudioUnitBusTypeInput = 1, AUAudioUnitBusTypeOutput = 2 } AUAudioUnitBusType;

typedef AUAudioUnitStatus (^AURenderPullInputBlock)(AudioUnitRenderActionFlags* actionFlags,
                                                    const AudioTimeStamp* timestamp,
                                                    AUAudioFrameCount frameCount,
                                                    NSInteger inputBusNumber,
                                                    AudioBufferList* inputData);

typedef AUAudioUnitStatus (^AURenderBlock)(AudioUnitRenderActionFlags* actionFlags,
                                           const AudioTimeStamp* timestamp,
                                           AUAudioFrameCount frameCount,
                                           NSInteger outputBusNumber,
                                           AudioBufferList* outputData,
                                           AURenderPullInputBlock __nullable pullInputBlock);

typedef void (^AURenderObserver)(AudioUnitRenderActionFlags actionFlags,
                                 const AudioTimeStamp* timestamp,
                                 AUAudioFrameCount frameCount,
                                 NSInteger outputBusNumber);

typedef void (^AUScheduleParameterBlock)(AUEventSampleTime eventSampleTime,
                                         AUAudioFrameCount rampDurationSampleFrames,
                                         AUParameterAddress parameterAddress,
                                         AUValue value);

typedef void (^AUScheduleMIDIEventBlock)(AUEventSampleTime eventSampleTime, uint8_t cable, NSInteger length, const uint8_t* midiBytes);

typedef BOOL (^AUHostMusicalContextBlock)(double* __nullable currentTempo,
                                          double* __nullable timeSignatureNumerator,
                                          NSInteger* __nullable timeSignatureDenominator,
                                          double* __nullable currentBeatPosition,
                                          NSInteger* __nullable sampleOffsetToNextBeat,
                                          double* __nullable currentMeasureDownbeatPosition);

typedef BOOL (^AUHostTransportStateBlock)(AUHostTransportStateFlags* __nullable transportStateFlags,
                                          double* __nullable currentSamplePosition,
                                          double* __nullable cycleStartBeatPosition,
                                          double* __nullable cycleEndBeatPosition);

typedef void (^AUInputHandler)(AudioUnitRenderActionFlags* actionFlags,
                               const AudioTimeStamp* timestamp,
                               AUAudioFrameCount frameCount,
                               NSInteger inputBusNumber);

typedef AUAudioUnitStatus (^AUInternalRenderBlock)(AudioUnitRenderActionFlags* actionFlags,
                                                   const AudioTimeStamp* timestamp,
                                                   AUAudioFrameCount frameCount,
                                                   NSInteger outputBusNumber,
                                                   AudioBufferList* outputData,
                                                   const AURenderEvent* realtimeEventListHead,
                                                   AURenderPullInputBlock pullInputBlock);

AUDIOUNIT_EXPORT_CLASS
@interface AUAudioUnit : NSObject
- (instancetype)initWithComponentDescription:(AudioComponentDescription)componentDescription
                                       error:(NSError* _Nullable*)outError STUB_METHOD;
- (instancetype)initWithComponentDescription:(AudioComponentDescription)componentDescription
                                     options:(AudioComponentInstantiationOptions)options
                                       error:(NSError* _Nullable*)outError STUB_METHOD;
+ (void)instantiateWithComponentDescription:(AudioComponentDescription)componentDescription
                                    options:(AudioComponentInstantiationOptions)options
                          completionHandler:(void (^)(AUAudioUnit*, NSError*))completionHandler STUB_METHOD;
@property (readonly, nonatomic) AudioComponentDescription componentDescription STUB_PROPERTY;
@property (readonly, nonatomic) AudioComponent component STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* componentName STUB_PROPERTY;
@property (readonly, nonatomic) uint32_t componentVersion STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* audioUnitName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* manufacturerName STUB_PROPERTY;
- (BOOL)allocateRenderResourcesAndReturnError:(NSError* _Nullable*)outError STUB_METHOD;
- (void)deallocateRenderResources STUB_METHOD;
- (void)reset STUB_METHOD;
@property (readonly, nonatomic) BOOL renderResourcesAllocated STUB_PROPERTY;
@property (readonly, nonatomic) AUAudioUnitBusArray* inputBusses STUB_PROPERTY;
@property (readonly, nonatomic) AUAudioUnitBusArray* outputBusses STUB_PROPERTY;
@property (readonly, nonatomic) AURenderBlock renderBlock STUB_PROPERTY;
@property (readonly, nonatomic) AUScheduleParameterBlock scheduleParameterBlock STUB_PROPERTY;
@property (nonatomic) AUAudioFrameCount maximumFramesToRender STUB_PROPERTY;
- (NSInteger)tokenByAddingRenderObserver:(AURenderObserver)observer STUB_METHOD;
- (void)removeRenderObserver:(NSInteger)token STUB_METHOD;
@property (readonly, nonatomic) AUParameterTree* parameterTree STUB_PROPERTY;
@property (readonly, nonatomic) BOOL allParameterValues STUB_PROPERTY;
- (NSArray*)parametersForOverviewWithCount:(NSInteger)count STUB_METHOD;
@property (readonly, getter=isMusicDeviceOrEffect, nonatomic) BOOL musicDeviceOrEffect STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger virtualMIDICableCount STUB_PROPERTY;
@property (readonly, nonatomic) AUScheduleMIDIEventBlock scheduleMIDIEventBlock STUB_PROPERTY;
@property (copy, nonatomic) NSDictionary* fullState STUB_PROPERTY;
@property (copy, nonatomic) NSDictionary* fullStateForDocument STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* factoryPresets STUB_PROPERTY;
@property (retain, nonatomic) AUAudioUnitPreset* currentPreset STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval latency STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval tailTime STUB_PROPERTY;
@property (nonatomic) NSInteger renderQuality STUB_PROPERTY;
@property (nonatomic) BOOL shouldBypassEffect STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canProcessInPlace STUB_PROPERTY;
@property (getter=isRenderingOffline, nonatomic) BOOL renderingOffline STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* channelCapabilities STUB_PROPERTY;
@property (copy, nonatomic) AUHostMusicalContextBlock musicalContextBlock STUB_PROPERTY;
@property (copy, nonatomic) AUHostTransportStateBlock transportStateBlock STUB_PROPERTY;
@property (copy, nonatomic) NSString* contextName STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canPerformInput STUB_PROPERTY;
@property (readonly, nonatomic) BOOL canPerformOutput STUB_PROPERTY;
@property (getter=isInputEnabled, nonatomic) BOOL inputEnabled STUB_PROPERTY;
@property (getter=isOutputEnabled, nonatomic) BOOL outputEnabled STUB_PROPERTY;
@property (copy, nonatomic) AUInputHandler inputHandler STUB_PROPERTY;
@property (copy, nonatomic) AURenderPullInputBlock outputProvider STUB_PROPERTY;
- (BOOL)startHardwareAndReturnError:(NSError* _Nullable*)outError STUB_METHOD;
- (void)stopHardware STUB_METHOD;
@property (readonly, nonatomic) AUInternalRenderBlock internalRenderBlock STUB_PROPERTY;
+ (void)registerSubclass:(Class)cls
  asComponentDescription:(AudioComponentDescription)componentDescription
                    name:(NSString*)name
                 version:(UInt32)version STUB_METHOD;
- (BOOL)shouldChangeToFormat:(AVAudioFormat*)format forBus:(AUAudioUnitBus*)bus STUB_METHOD;
- (void)setRenderResourcesAllocated:(BOOL)flag STUB_METHOD;
@end
