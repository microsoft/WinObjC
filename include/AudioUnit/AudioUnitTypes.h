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

#import <AudioUnit/AudioComponent.h>
#import <CoreFoundation/CFBase.h>

typedef Float32 AudioUnitParameterValue;
typedef UInt32 AUParameterEventType;
typedef AudioComponentInstance AudioUnit;
typedef UInt32 AudioUnitElement;
typedef UInt32 AudioUnitParameterID;
typedef UInt32 AudioUnitPropertyID;
typedef UInt32 AudioUnitScope;

typedef struct {
    AudioUnit mAudioUnit;
    AudioUnitParameterID mParameterID;
    AudioUnitScope mScope;
    AudioUnitElement mElement;
} AudioUnitParameter;

typedef struct {
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
} AudioUnitParameterEvent;

typedef struct {
    AudioUnit mAudioUnit;
    AudioUnitPropertyID mPropertyID;
    AudioUnitScope mScope;
    AudioUnitElement mElement;
} AudioUnitProperty;

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
    kAudioUnitSubType_PeakLimiter          = 'lmtr',
    kAudioUnitSubType_DynamicsProcessor    = 'dcmp',
    kAudioUnitSubType_Reverb2              = 'rvb2',
    kAudioUnitSubType_LowPassFilter        = 'lpas',
    kAudioUnitSubType_HighPassFilter       = 'hpas',
    kAudioUnitSubType_BandPassFilter       = 'bpas',
    kAudioUnitSubType_HighShelfFilter      = 'hshf',
    kAudioUnitSubType_LowShelfFilter       = 'lshf',
    kAudioUnitSubType_ParametricEQ         = 'pmeq',
    kAudioUnitSubType_Delay                = 'dely',
    kAudioUnitSubType_SampleDelay          = 'sdly',
    kAudioUnitSubType_Distortion           = 'dist',
    kAudioUnitSubType_AUiPodEQ             = 'ipeq',
    kAudioUnitSubType_NBandEQ              = 'nbeq'
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
