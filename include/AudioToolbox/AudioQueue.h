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

#import <AudioToolbox/AudioToolboxExport.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <AudioToolbox/AudioConverter.h>
#import <CoreFoundation/CFRunLoop.h>
#import <CoreFoundation/CFString.h>

enum {
    kAudioQueueParam_Volume = 1,
    kAudioQueueParam_PlayRate = 2,
    kAudioQueueParam_Pitch = 3,
    kAudioQueueParam_VolumeRampTime = 4,
    kAudioQueueParam_Pan = 13
};

enum { kAudioQueueProperty_HardwareCodecPolicy = 'aqcp' };

enum {
    kAudioQueueHardwareCodecPolicy_Default = 0,
    kAudioQueueHardwareCodecPolicy_UseSoftwareOnly = 1,
    kAudioQueueHardwareCodecPolicy_UseHardwareOnly = 2,
    kAudioQueueHardwareCodecPolicy_PreferSoftware = 3,
    kAudioQueueHardwareCodecPolicy_PreferHardware = 4
};

enum {
    kAudioQueueErr_InvalidBuffer = -66687,
    kAudioQueueErr_BufferEmpty = -66686,
    kAudioQueueErr_DisposalPending = -66685,
    kAudioQueueErr_InvalidProperty = -66684,
    kAudioQueueErr_InvalidPropertySize = -66683,
    kAudioQueueErr_InvalidParameter = -66682,
    kAudioQueueErr_CannotStart = -66681,
    kAudioQueueErr_InvalidDevice = -66680,
    kAudioQueueErr_BufferInQueue = -66679,
    kAudioQueueErr_InvalidRunState = -66678,
    kAudioQueueErr_InvalidQueueType = -66677,
    kAudioQueueErr_Permissions = -66676,
    kAudioQueueErr_InvalidPropertyValue = -66675,
    kAudioQueueErr_PrimeTimedOut = -66674,
    kAudioQueueErr_CodecNotFound = -66673,
    kAudioQueueErr_InvalidCodecAccess = -66672,
    kAudioQueueErr_QueueInvalidated = -66671,
    kAudioQueueErr_RecordUnderrun = -66668,
    kAudioQueueErr_EnqueueDuringReset = -66632,
    kAudioQueueErr_InvalidOfflineMode = -66626,
};

typedef UInt32 AudioQueueParameterID;
typedef Float32 AudioQueueParameterValue;

struct AudioQueueParameterEvent {
    AudioQueueParameterID mID;
    AudioQueueParameterValue mValue;
};

typedef struct AudioQueueBuffer {
    const UInt32 mAudioDataBytesCapacity;
    void* const mAudioData;
    UInt32 mAudioDataByteSize;
    void* mUserData;
    const UInt32 mPacketDescriptionCapacity;
    AudioStreamPacketDescription* const mPacketDescriptions;
    UInt32 mPacketDescriptionCount;
} AudioQueueBuffer;

typedef AudioQueueBuffer* AudioQueueBufferRef;
typedef struct OpaqueAudioQueue* AudioQueueRef;
typedef struct OpaqueAudioQueueTimeline* AudioQueueTimelineRef;
typedef UInt32 AudioQueuePropertyID;
typedef void (*AudioQueueInputCallback)(void* inUserData,
                                        AudioQueueRef inAQ,
                                        AudioQueueBufferRef inBuffer,
                                        const AudioTimeStamp* inStartTime,
                                        UInt32 inNumberPacketDescriptions,
                                        const AudioStreamPacketDescription* inPacketDescs);
typedef void (*AudioQueueOutputCallback)(void* inUserData, AudioQueueRef inAQ, AudioQueueBufferRef inBuffer);
typedef void (*AudioQueuePropertyListenerProc)(void* inUserData, AudioQueueRef inAQ, AudioQueuePropertyID inID);
typedef struct AudioQueueLevelMeterState {
    Float32 mAveragePower;
    Float32 mPeakPower;
} AudioQueueLevelMeterState;

typedef struct AudioQueueParameterEvent AudioQueueParameterEvent;
enum {
    kAudioQueueProperty_IsRunning = 'aqrn',
    kAudioQueueDeviceProperty_SampleRate = 'aqsr',
    kAudioQueueDeviceProperty_NumberChannels = 'aqdc',
    kAudioQueueProperty_CurrentDevice = 'aqcd',
    kAudioQueueProperty_MagicCookie = 'aqmc',
    kAudioQueueProperty_MaximumOutputPacketSize = 'xops',
    kAudioQueueProperty_StreamDescription = 'aqft',
    kAudioQueueProperty_ChannelLayout = 'aqcl',
    kAudioQueueProperty_EnableLevelMetering = 'aqme',
    kAudioQueueProperty_CurrentLevelMeter = 'aqmv',
    kAudioQueueProperty_CurrentLevelMeterDB = 'aqmd',
    kAudioQueueProperty_DecodeBufferSizeFrames = 'dcbf',
    kAudioQueueProperty_ConverterError = 'qcve'
};

AUDIOTOOLBOX_EXPORT OSStatus AudioQueueStart(AudioQueueRef inAQ, const AudioTimeStamp* inStartTime) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueuePrime(AudioQueueRef inAQ,
                                             UInt32 inNumberOfFramesToPrepare,
                                             UInt32* outNumberOfFramesPrepared) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueFlush(AudioQueueRef inAQ) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueStop(AudioQueueRef inAQ, Boolean inImmediate) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueuePause(AudioQueueRef inAQ) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueReset(AudioQueueRef inAQ) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueNewOutput(const AudioStreamBasicDescription* inFormat,
                                                 AudioQueueOutputCallback inCallbackProc,
                                                 void* inUserData,
                                                 CFRunLoopRef inCallbackRunLoop,
                                                 CFStringRef inCallbackRunLoopMode,
                                                 UInt32 inFlags,
                                                 AudioQueueRef _Nullable* outAQ) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueNewInput(const AudioStreamBasicDescription* inFormat,
                                                AudioQueueInputCallback inCallbackProc,
                                                void* inUserData,
                                                CFRunLoopRef inCallbackRunLoop,
                                                CFStringRef inCallbackRunLoopMode,
                                                UInt32 inFlags,
                                                AudioQueueRef _Nullable* outAQ) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueDispose(AudioQueueRef inAQ, Boolean inImmediate) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueAllocateBuffer(AudioQueueRef inAQ,
                                                      UInt32 inBufferByteSize,
                                                      AudioQueueBufferRef _Nullable* outBuffer) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueAllocateBufferWithPacketDescriptions(AudioQueueRef inAQ,
                                                                            UInt32 inBufferByteSize,
                                                                            UInt32 inNumberPacketDescriptions,
                                                                            AudioQueueBufferRef _Nullable* outBuffer) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueFreeBuffer(AudioQueueRef inAQ, AudioQueueBufferRef inBuffer) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueEnqueueBuffer(AudioQueueRef inAQ,
                                                     AudioQueueBufferRef inBuffer,
                                                     UInt32 inNumPacketDescs,
                                                     const AudioStreamPacketDescription* inPacketDescs) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueEnqueueBufferWithParameters(AudioQueueRef inAQ,
                                                                   AudioQueueBufferRef inBuffer,
                                                                   UInt32 inNumPacketDescs,
                                                                   const AudioStreamPacketDescription* inPacketDescs,
                                                                   UInt32 inTrimFramesAtStart,
                                                                   UInt32 inTrimFramesAtEnd,
                                                                   UInt32 inNumParamValues,
                                                                   const AudioQueueParameterEvent* inParamValues,
                                                                   const AudioTimeStamp* inStartTime,
                                                                   AudioTimeStamp* outActualStartTime) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueGetParameter(AudioQueueRef inAQ,
                                                    AudioQueueParameterID inParamID,
                                                    AudioQueueParameterValue* outValue) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueSetParameter(AudioQueueRef inAQ,
                                                    AudioQueueParameterID inParamID,
                                                    AudioQueueParameterValue inValue) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueGetProperty(AudioQueueRef inAQ, AudioQueuePropertyID inID, void* outData, UInt32* ioDataSize)
    STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueSetProperty(AudioQueueRef inAQ, AudioQueuePropertyID inID, const void* inData, UInt32 inDataSize)
    STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueGetPropertySize(AudioQueueRef inAQ, AudioQueuePropertyID inID, UInt32* outDataSize) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueAddPropertyListener(AudioQueueRef inAQ,
                                                           AudioQueuePropertyID inID,
                                                           AudioQueuePropertyListenerProc inProc,
                                                           void* inUserData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueRemovePropertyListener(AudioQueueRef inAQ,
                                                              AudioQueuePropertyID inID,
                                                              AudioQueuePropertyListenerProc inProc,
                                                              void* inUserData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueCreateTimeline(AudioQueueRef inAQ, AudioQueueTimelineRef _Nullable* outTimeline) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueDisposeTimeline(AudioQueueRef inAQ, AudioQueueTimelineRef inTimeline) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueDeviceGetCurrentTime(AudioQueueRef inAQ, AudioTimeStamp* outTimeStamp) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueDeviceGetNearestStartTime(AudioQueueRef inAQ,
                                                                 AudioTimeStamp* ioRequestedStartTime,
                                                                 UInt32 inFlags) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueDeviceTranslateTime(AudioQueueRef inAQ,
                                                           const AudioTimeStamp* inTime,
                                                           AudioTimeStamp* outTime) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueGetCurrentTime(AudioQueueRef inAQ,
                                                      AudioQueueTimelineRef inTimeline,
                                                      AudioTimeStamp* outTimeStamp,
                                                      Boolean* outTimelineDiscontinuity) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueSetOfflineRenderFormat(AudioQueueRef inAQ,
                                                              const AudioStreamBasicDescription* inFormat,
                                                              const AudioChannelLayout* inLayout) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioQueueOfflineRender(AudioQueueRef inAQ,
                                                     const AudioTimeStamp* inTimestamp,
                                                     AudioQueueBufferRef ioBuffer,
                                                     UInt32 inNumberFrames) STUB_METHOD;