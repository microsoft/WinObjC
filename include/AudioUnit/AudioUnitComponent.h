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
#import <CoreAudio/CoreAudioTypes.h>
#import <AudioUnit/AudioComponent.h>

typedef Float32 AudioUnitParameterValue;
typedef UInt32 AUParameterEventType;
typedef AudioComponentInstance AudioUnit;
typedef UInt32 AudioUnitElement;
typedef UInt32 AudioUnitParameterID;
typedef UInt32 AudioUnitPropertyID;
typedef UInt32 AudioUnitScope;

struct AudioUnitParameter {
    AudioUnit mAudioUnit;
    AudioUnitParameterID mParameterID;
    AudioUnitScope mScope;
    AudioUnitElement mElement;
};

struct AudioUnitParameterEvent {
    AudioUnitScope scope;
    AudioUnitElement element;
    AudioUnitParameterID parameter;
    AUParameterEventType eventType;
    union {
        struct {
            SInt32 startBufferOffset;
            UInt32 durationInFrames;
            AudioUnitParameterValue startValue;
            AudioUnitParameterValue endValue;
        } ramp;
        struct {
            UInt32 bufferOffset;
            AudioUnitParameterValue value;
        } immediate;
    } eventValues;
};

struct AudioUnitProperty {
    AudioUnit mAudioUnit;
    AudioUnitPropertyID mPropertyID;
    AudioUnitScope mScope;
    AudioUnitElement mElement;
};

typedef UInt32 AudioUnitRenderActionFlags;
typedef void (*AUInputSamplesInOutputCallback)(void* inRefCon,
                                               const AudioTimeStamp* inOutputTimeStamp,
                                               Float64 inInputSample,
                                               Float64 inNumberInputSamples);
typedef OSStatus (*AURenderCallback)(void* inRefCon,
                                     AudioUnitRenderActionFlags* ioActionFlags,
                                     const AudioTimeStamp* inTimeStamp,
                                     UInt32 inBusNumber,
                                     UInt32 inNumberFrames,
                                     AudioBufferList* ioData);
typedef void (*AudioUnitPropertyListenerProc)(
    void* inRefCon, AudioUnit inUnit, AudioUnitPropertyID inID, AudioUnitScope inScope, AudioUnitElement inElement);
typedef struct AudioUnitParameter AudioUnitParameter;
typedef struct AudioUnitParameterEvent AudioUnitParameterEvent;
typedef struct AudioUnitProperty AudioUnitProperty;

enum {
    kAudioUnitRenderAction_PreRender = (1 << 2),
    kAudioUnitRenderAction_PostRender = (1 << 3),
    kAudioUnitRenderAction_OutputIsSilence = (1 << 4),
    kAudioOfflineUnitRenderAction_Preflight = (1 << 5),
    kAudioOfflineUnitRenderAction_Render = (1 << 6),
    kAudioOfflineUnitRenderAction_Complete = (1 << 7),
    kAudioUnitRenderAction_PostRenderError = (1 << 8),
    kAudioUnitRenderAction_DoNotCheckRenderArgs = (1 << 9)
};

AUDIOUNIT_EXPORT OSStatus AudioUnitInitialize(AudioUnit inUnit) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitUninitialize(AudioUnit inUnit) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitAddRenderNotify(AudioUnit inUnit, AURenderCallback inProc, void* inProcUserData) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitRemoveRenderNotify(AudioUnit inUnit, AURenderCallback inProc, void* inProcUserData) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitRender(AudioUnit inUnit,
                                          AudioUnitRenderActionFlags* ioActionFlags,
                                          const AudioTimeStamp* inTimeStamp,
                                          UInt32 inOutputBusNumber,
                                          UInt32 inNumberFrames,
                                          AudioBufferList* ioData) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitReset(AudioUnit inUnit, AudioUnitScope inScope, AudioUnitElement inElement) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitAddPropertyListener(AudioUnit inUnit,
                                                       AudioUnitPropertyID inID,
                                                       AudioUnitPropertyListenerProc inProc,
                                                       void* inProcUserData) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitRemovePropertyListenerWithUserData(AudioUnit inUnit,
                                                                      AudioUnitPropertyID inID,
                                                                      AudioUnitPropertyListenerProc inProc,
                                                                      void* inProcUserData) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitGetProperty(AudioUnit inUnit,
                                               AudioUnitPropertyID inID,
                                               AudioUnitScope inScope,
                                               AudioUnitElement inElement,
                                               void* outData,
                                               UInt32* ioDataSize) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitGetPropertyInfo(AudioUnit inUnit,
                                                   AudioUnitPropertyID inID,
                                                   AudioUnitScope inScope,
                                                   AudioUnitElement inElement,
                                                   UInt32* outDataSize,
                                                   Boolean* outWritable) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitSetProperty(AudioUnit inUnit,
                                               AudioUnitPropertyID inID,
                                               AudioUnitScope inScope,
                                               AudioUnitElement inElement,
                                               const void* inData,
                                               UInt32 inDataSize) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitGetParameter(AudioUnit inUnit,
                                                AudioUnitParameterID inID,
                                                AudioUnitScope inScope,
                                                AudioUnitElement inElement,
                                                AudioUnitParameterValue* outValue) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitSetParameter(AudioUnit inUnit,
                                                AudioUnitParameterID inID,
                                                AudioUnitScope inScope,
                                                AudioUnitElement inElement,
                                                AudioUnitParameterValue inValue,
                                                UInt32 inBufferOffsetInFrames) STUB_METHOD;
AUDIOUNIT_EXPORT OSStatus AudioUnitScheduleParameters(AudioUnit inUnit,
                                                      const AudioUnitParameterEvent* inParameterEvent,
                                                      UInt32 inNumParamEvents) STUB_METHOD;
enum {
    kAudioUnitType_Output = 'auou',
    kAudioUnitType_MusicDevice = 'aumu',
    kAudioUnitType_MusicEffect = 'aumf',
    kAudioUnitType_FormatConverter = 'aufc',
    kAudioUnitType_Effect = 'aufx',
    kAudioUnitType_Mixer = 'aumx',
    kAudioUnitType_Panner = 'aupn',
    kAudioUnitType_OfflineEffect = 'auol',
    kAudioUnitType_Generator = 'augn',
};
enum { kAudioUnitManufacturer_Apple = 'appl' };
enum {
    kAudioUnitSubType_AUConverter = 'conv',
    kAudioUnitSubType_NewTimePitch = 'nutp',
    kAudioUnitSubType_TimePitch = 'tmpt',
    kAudioUnitSubType_DeferredRenderer = 'defr',
    kAudioUnitSubType_Splitter = 'splt',
    kAudioUnitSubType_Merger = 'merg',
    kAudioUnitSubType_Varispeed = 'vari',
    kAudioUnitSubType_AUiPodTime = 'iptm',
    kAudioUnitSubType_AUiPodTimeOther = 'ipto'
};
enum {
    kAudioUnitSubType_PeakLimiter = 'lmtr',
    kAudioUnitSubType_DynamicsProcessor = 'dcmp',
    kAudioUnitSubType_Reverb2 = 'rvb2',
    kAudioUnitSubType_LowPassFilter = 'lpas',
    kAudioUnitSubType_HighPassFilter = 'hpas',
    kAudioUnitSubType_BandPassFilter = 'bpas',
    kAudioUnitSubType_HighShelfFilter = 'hshf',
    kAudioUnitSubType_LowShelfFilter = 'lshf',
    kAudioUnitSubType_ParametricEQ = 'pmeq',
    kAudioUnitSubType_Delay = 'dely',
    kAudioUnitSubType_SampleDelay = 'sdly',
    kAudioUnitSubType_Distortion = 'dist',
    kAudioUnitSubType_AUiPodEQ = 'ipeq',
    kAudioUnitSubType_NBandEQ = 'nbeq'
};
enum {
    kAudioUnitSubType_MultiChannelMixer = 'mcmx',
    kAudioUnitSubType_MatrixMixer = 'mxmx',
    kAudioUnitSubType_AU3DMixerEmbedded = '3dem',
};
enum {
    kAudioUnitSubType_ScheduledSoundPlayer = 'sspl',
    kAudioUnitSubType_AudioFilePlayer = 'afpl',
};
enum { kAudioUnitSubType_Sampler = 'samp' };
enum { kAudioUnitSubType_GenericOutput = 'genr', kAudioUnitSubType_RemoteIO = 'rioc', kAudioUnitSubType_VoiceProcessingIO = 'vpio' };
enum { kParameterEvent_Immediate = 1, kParameterEvent_Ramped = 2 };
enum {
    kAudioUnitRange = 0x0000,
    kAudioUnitInitializeSelect = 0x0001,
    kAudioUnitUninitializeSelect = 0x0002,
    kAudioUnitGetPropertyInfoSelect = 0x0003,
    kAudioUnitGetPropertySelect = 0x0004,
    kAudioUnitSetPropertySelect = 0x0005,
    kAudioUnitAddPropertyListenerSelect = 0x000A,
    kAudioUnitRemovePropertyListenerSelect = 0x000B,
    kAudioUnitRemovePropertyListenerWithUserDataSelect = 0x0012,
    kAudioUnitAddRenderNotifySelect = 0x000F,
    kAudioUnitRemoveRenderNotifySelect = 0x0010,
    kAudioUnitGetParameterSelect = 0x0006,
    kAudioUnitSetParameterSelect = 0x0007,
    kAudioUnitScheduleParametersSelect = 0x0011,
    kAudioUnitRenderSelect = 0x000E,
    kAudioUnitResetSelect = 0x0009,
    kAudioUnitComplexRenderSelect = 0x0013,
    kAudioUnitProcessSelect = 0x0014,
    kAudioUnitProcessMultipleSelect = 0x0015
};

enum {
    kAudioUnitErr_InvalidProperty = -10879,
    kAudioUnitErr_InvalidParameter = -10878,
    kAudioUnitErr_InvalidElement = -10877,
    kAudioUnitErr_NoConnection = -10876,
    kAudioUnitErr_FailedInitialization = -10875,
    kAudioUnitErr_TooManyFramesToProcess = -10874,
    kAudioUnitErr_IllegalInstrument = -10873,
    kAudioUnitErr_InstrumentTypeNotFound = -10872,
    kAudioUnitErr_InvalidFile = -10871,
    kAudioUnitErr_UnknownFileType = -10870,
    kAudioUnitErr_FileNotSpecified = -10869,
    kAudioUnitErr_FormatNotSupported = -10868,
    kAudioUnitErr_Uninitialized = -10867,
    kAudioUnitErr_InvalidScope = -10866,
    kAudioUnitErr_PropertyNotWritable = -10865,
    kAudioUnitErr_CannotDoInCurrentContext = -10863,
    kAudioUnitErr_InvalidPropertyValue = -10851,
    kAudioUnitErr_PropertyNotInUse = -10850,
    kAudioUnitErr_Initialized = -10849,
    kAudioUnitErr_InvalidOfflineRender = -10848,
    kAudioUnitErr_Unauthorized = -10847
};