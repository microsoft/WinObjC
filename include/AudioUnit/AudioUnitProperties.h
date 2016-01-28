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
#import <AudioUnit/AudioUnitComponent.h>
#import <CoreFoundation/CFString.h>

typedef OSStatus (*HostCallback_GetBeatAndTempo)(void* inHostUserData, Float64* outCurrentBeat, Float64* outCurrentTempo);
typedef OSStatus (*HostCallback_GetMusicalTimeLocation)(void* inHostUserData,
                                                        UInt32* outDeltaSampleOffsetToNextBeat,
                                                        Float32* outTimeSig_Numerator,
                                                        UInt32* outTimeSig_Denominator,
                                                        Float64* outCurrentMeasureDownBeat);
typedef OSStatus (*HostCallback_GetTransportState)(void* inHostUserData,
                                                   Boolean* outIsPlaying,
                                                   Boolean* outTransportStateChanged,
                                                   Float64* outCurrentSampleInTimeLine,
                                                   Boolean* outIsCycling,
                                                   Float64* outCycleStartBeat,
                                                   Float64* outCycleEndBeat);
typedef struct AUChannelInfo {
    SInt16 inChannels;
    SInt16 outChannels;
} AUChannelInfo;

typedef struct AUDependentParameter {
    AudioUnitScope mScope;
    AudioUnitParameterID mParameterID;
} AUDependentParameter;

typedef struct AudioOutputUnitStartAtTimeParams {
    AudioTimeStamp mTimestamp;
    UInt32 mFlags;
} AudioOutputUnitStartAtTimeParams;

typedef struct AudioUnitConnection {
    AudioUnit sourceAudioUnit;
    UInt32 sourceOutputNumber;
    UInt32 destInputNumber;
} AudioUnitConnection;

typedef struct AudioUnitExternalBuffer {
    Byte* buffer;
    UInt32 size;
} AudioUnitExternalBuffer;

typedef struct AudioUnitFrequencyResponseBin {
    Float64 mFrequency;
    Float64 mMagnitude;
} AudioUnitFrequencyResponseBin;

typedef struct AudioUnitMeterClipping {
    Float32 peakValueSinceLastCall;
    Boolean sawInfinity;
    Boolean sawNotANumber;
} AudioUnitMeterClipping;

typedef UInt32 AudioUnitParameterUnit;

typedef struct AudioUnitParameterInfo {
    char name[52];
    CFStringRef unitName;
    UInt32 clumpID;
    CFStringRef cfNameString;
    AudioUnitParameterUnit unit;
    AudioUnitParameterValue minValue;
    AudioUnitParameterValue maxValue;
    AudioUnitParameterValue defaultValue;
    UInt32 flags;
} AudioUnitParameterInfo;

typedef struct AudioUnitParameterNameInfo {
    AudioUnitParameterID inID;
    SInt32 inDesiredLength;
    CFStringRef outName;
} AudioUnitParameterIDName;

typedef struct AudioUnitParameterStringFromValue {
    AudioUnitParameterID inParamID;
    const AudioUnitParameterValue* inValue;
    CFStringRef outString;
} AudioUnitParameterStringFromValue;

typedef struct AudioUnitParameterValueFromString {
    AudioUnitParameterID inParamID;
    CFStringRef inString;
    AudioUnitParameterValue outValue;
} AudioUnitParameterValueFromString;

typedef struct AudioUnitParameterHistoryInfo {
    Float32 updatesPerSecond;
    Float32 historyDurationInSeconds;
} AudioUnitParameterHistoryInfo;

typedef struct AUInputSamplesInOutputCallbackStruct {
    AUInputSamplesInOutputCallback inputToOutputCallback;
    void* userData;
} AUInputSamplesInOutputCallbackStruct;

typedef struct AUPreset {
    SInt32 presetNumber;
    CFStringRef presetName;
} AUPreset;

typedef struct AURenderCallbackStruct {
    AURenderCallback inputProc;
    void* inputProcRefCon;
} AURenderCallbackStruct;

typedef struct HostCallbackInfo {
    void* hostUserData;
    HostCallback_GetBeatAndTempo beatAndTempoProc;
    HostCallback_GetMusicalTimeLocation musicalTimeLocationProc;
    HostCallback_GetTransportState transportStateProc;
} HostCallbackInfo;

typedef struct MixerDistanceParams {
    Float32 mReferenceDistance;
    Float32 mMaxDistance;
    Float32 mMaxAttenuation; // in decibels
} MixerDistanceParams;

#define GetAudioUnitParameterDisplayType (flags)((flags)&kAudioUnitParameterFlag_DisplayMask)
#define AudioUnitDisplayTypeIsLogarithmic (flags)(GetAudioUnitParameterDisplayType(flags) == kAudioUnitParameterFlag_DisplayLogarithmic)
#define AudioUnitDisplayTypeIsSquareRoot (flags)(GetAudioUnitParameterDisplayType(flags) == kAudioUnitParameterFlag_DisplaySquareRoot)
#define AudioUnitDisplayTypeIsSquared (flags)(GetAudioUnitParameterDisplayType(flags) == kAudioUnitParameterFlag_DisplaySquared)
#define AudioUnitDisplayTypeIsCubed (flags)(GetAudioUnitParameterDisplayType(flags) == kAudioUnitParameterFlag_DisplayCubed)
#define AudioUnitDisplayTypeIsCubeRoot (flags)(GetAudioUnitParameterDisplayType(flags) == kAudioUnitParameterFlag_DisplayCubeRoot)
#define AudioUnitDisplayTypeIsExponential (flags)(GetAudioUnitParameterDisplayType(flags) == kAudioUnitParameterFlag_DisplayExponential)
#define SetAudioUnitParameterDisplayType (flags, displayType)(((flags) & ~kAudioUnitParameterFlag_DisplayMask) | (displayType))

// TODO::
// todo-nithishm-01252016 - Revisit this when implementing this module. Documentation is missing for this.
typedef void (*ScheduledAudioFileRegionCompletionProc)();

struct ScheduledAudioFileRegion {
    AudioTimeStamp mTimeStamp;
    ScheduledAudioFileRegionCompletionProc mCompletionProc;
    void* mCompletionProcUserData;
    struct OpaqueAudioFileID* mAudioFile;
    UInt32 mLoopCount;
    SInt64 mStartFrame;
    UInt32 mFramesToPlay;
};

enum {
    kAudioUnitScope_Global = 0,
    kAudioUnitScope_Input = 1,
    kAudioUnitScope_Output = 2,
    kAudioUnitScope_Group = 3,
    kAudioUnitScope_Part = 4,
    kAudioUnitScope_Note = 5
};

enum {
    kAudioUnitProperty_ClassInfo = 0,
    kAudioUnitProperty_MakeConnection = 1,
    kAudioUnitProperty_SampleRate = 2,
    kAudioUnitProperty_ParameterList = 3,
    kAudioUnitProperty_ParameterInfo = 4,
    kAudioUnitProperty_StreamFormat = 8,
    kAudioUnitProperty_ElementCount = 11,
    kAudioUnitProperty_Latency = 12,
    kAudioUnitProperty_SupportedNumChannels = 13,
    kAudioUnitProperty_MaximumFramesPerSlice = 14,
    kAudioUnitProperty_AudioChannelLayout = 19,
    kAudioUnitProperty_TailTime = 20,
    kAudioUnitProperty_BypassEffect = 21,
    kAudioUnitProperty_LastRenderError = 22,
    kAudioUnitProperty_SetRenderCallback = 23,
    kAudioUnitProperty_FactoryPresets = 24,
    kAudioUnitProperty_RenderQuality = 26,
    kAudioUnitProperty_InPlaceProcessing = 29,
    kAudioUnitProperty_ElementName = 30,
    kAudioUnitProperty_SupportedChannelLayoutTags = 32,
    kAudioUnitProperty_PresentPreset = 36,
    kAudioUnitProperty_ShouldAllocateBuffer = 51,
    kAudioUnitProperty_ParameterHistoryInfo = 53,
    kAudioUnitProperty_CPULoad = 6,
    kAudioUnitProperty_ParameterValueStrings = 16,
    kAudioUnitProperty_ContextName = 25,
    kAudioUnitProperty_HostCallbacks = 27,
    kAudioUnitProperty_ParameterStringFromValue = 33,
    kAudioUnitProperty_ParameterIDName = 34,
    kAudioUnitProperty_ParameterClumpName = 35,
    kAudioUnitProperty_OfflineRender = 37,
    kAudioUnitProperty_ParameterValueFromString = 38,
    kAudioUnitProperty_PresentationLatency = 40,
    kAudioUnitProperty_DependentParameters = 45,
    kAudioUnitProperty_InputSamplesInOutput = 49,
    kAudioUnitProperty_ClassInfoFromDocument = 50,
    kAudioUnitProperty_FrequencyResponse = 52
};

enum {
    kAudioOutputUnitProperty_CurrentDevice = 2000,
    kAudioOutputUnitProperty_IsRunning = 2001,
    kAudioOutputUnitProperty_ChannelMap = 2002,
    kAudioOutputUnitProperty_EnableIO = 2003,
    kAudioOutputUnitProperty_StartTime = 2004,
    kAudioOutputUnitProperty_SetInputCallback = 2005,
    kAudioOutputUnitProperty_HasIO = 2006,
    kAudioOutputUnitProperty_StartTimestampsAtZero = 2007
};

enum {
    kAUVoiceIOProperty_BypassVoiceProcessing = 2100,
    kAUVoiceIOProperty_VoiceProcessingEnableAGC = 2101,
    kAUVoiceIOProperty_MuteOutput = 2104,
};

enum {
    // For general mixers,
    kAudioUnitProperty_MeteringMode = 3007,
    // For the matrix mixer,
    kAudioUnitProperty_MatrixLevels = 3006,
    kAudioUnitProperty_MatrixDimensions = 3009,
    kAudioUnitProperty_MeterClipping = 3011
};

enum {
    kAudioUnitProperty_3DMixerDistanceParams = 3010,
    kAudioUnitProperty_3DMixerAttenuationCurve = 3013,
    kAudioUnitProperty_SpatializationAlgorithm = 3000,
    kAudioUnitProperty_DopplerShift = 3002,
    kAudioUnitProperty_3DMixerRenderingFlags = 3003,
    kAudioUnitProperty_3DMixerDistanceAtten = 3004,
    kAudioUnitProperty_ReverbPreset = 3012
};

enum {
    k3DMixerAttenuationCurve_Power = 0,
    k3DMixerAttenuationCurve_Exponential = 1,
    k3DMixerAttenuationCurve_Inverse = 2,
    k3DMixerAttenuationCurve_Linear = 3
};

enum {
    k3DMixerRenderingFlags_InterAuralDelay = (1L << 0),
    k3DMixerRenderingFlags_DopplerShift = (1L << 1),
    k3DMixerRenderingFlags_DistanceAttenuation = (1L << 2),
    k3DMixerRenderingFlags_DistanceFilter = (1L << 3),
    k3DMixerRenderingFlags_DistanceDiffusion = (1L << 4),
    k3DMixerRenderingFlags_LinearDistanceAttenuation = (1L << 5),
    k3DMixerRenderingFlags_ConstantReverbBlend = (1L << 6)
};

enum { kAudioUnitProperty_SampleRateConverterComplexity = 3014 };

enum {
    kAudioUnitSampleRateConverterComplexity_Linear = 'line',
    kAudioUnitSampleRateConverterComplexity_Normal = 'norm',
    kAudioUnitSampleRateConverterComplexity_Mastering = 'bats'
};

enum {
    kRenderQuality_Max = 0x7F,
    kRenderQuality_High = 0x60,
    kRenderQuality_Medium = 0x40,
    kRenderQuality_Low = 0x20,
    kRenderQuality_Min = 0
};

enum {
    kSpatializationAlgorithm_EqualPowerPanning = 0,
    kSpatializationAlgorithm_SphericalHead = 1,
    kSpatializationAlgorithm_HRTF = 2,
    kSpatializationAlgorithm_SoundField = 3,
    kSpatializationAlgorithm_VectorBasedPanning = 4,
    kSpatializationAlgorithm_StereoPassThrough = 5
};

enum {
    kAudioUnitParameterUnit_Generic = 0,
    kAudioUnitParameterUnit_Indexed = 1,
    kAudioUnitParameterUnit_Boolean = 2,
    kAudioUnitParameterUnit_Percent = 3,
    kAudioUnitParameterUnit_Seconds = 4,
    kAudioUnitParameterUnit_SampleFrames = 5,
    kAudioUnitParameterUnit_Phase = 6,
    kAudioUnitParameterUnit_Rate = 7,
    kAudioUnitParameterUnit_Hertz = 8,
    kAudioUnitParameterUnit_Cents = 9,
    kAudioUnitParameterUnit_RelativeSemiTones = 10,
    kAudioUnitParameterUnit_MIDINoteNumber = 11,
    kAudioUnitParameterUnit_MIDIController = 12,
    kAudioUnitParameterUnit_Decibels = 13,
    kAudioUnitParameterUnit_LinearGain = 14,
    kAudioUnitParameterUnit_Degrees = 15,
    kAudioUnitParameterUnit_EqualPowerCrossfade = 16,
    kAudioUnitParameterUnit_MixerFaderCurve1 = 17,
    kAudioUnitParameterUnit_Pan = 18,
    kAudioUnitParameterUnit_Meters = 19,
    kAudioUnitParameterUnit_AbsoluteCents = 20,
    kAudioUnitParameterUnit_Octaves = 21,
    kAudioUnitParameterUnit_BPM = 22,
    kAudioUnitParameterUnit_Beats = 23,
    kAudioUnitParameterUnit_Milliseconds = 24,
    kAudioUnitParameterUnit_Ratio = 25,
    kAudioUnitParameterUnit_CustomUnit = 26
};

enum {
    kAudioUnitParameterFlag_CFNameRelease = (1L << 4),
    kAudioUnitParameterFlag_PlotHistory = (1L << 14),
    kAudioUnitParameterFlag_MeterReadOnly = (1L << 15),
    kAudioUnitParameterFlag_DisplayMask = (7L << 16) | (1L << 22),
    kAudioUnitParameterFlag_DisplaySquareRoot = (1L << 16),
    kAudioUnitParameterFlag_DisplaySquared = (2L << 16),
    kAudioUnitParameterFlag_DisplayCubed = (3L << 16),
    kAudioUnitParameterFlag_DisplayCubeRoot = (4L << 16),
    kAudioUnitParameterFlag_DisplayExponential = (5L << 16),
    kAudioUnitParameterFlag_HasClump = (1L << 20),
    kAudioUnitParameterFlag_ValuesHaveStrings = (1L << 21),
    kAudioUnitParameterFlag_DisplayLogarithmic = (1L << 22),
    kAudioUnitParameterFlag_IsHighResolution = (1L << 23),
    kAudioUnitParameterFlag_NonRealTime = (1L << 24),
    kAudioUnitParameterFlag_CanRamp = (1L << 25),
    kAudioUnitParameterFlag_ExpertMode = (1L << 26),
    kAudioUnitParameterFlag_HasCFNameString = (1L << 27),
    kAudioUnitParameterFlag_IsGlobalMeta = (1L << 28),
    kAudioUnitParameterFlag_IsElementMeta = (1L << 29),
    kAudioUnitParameterFlag_IsReadable = (1L << 30),
    kAudioUnitParameterFlag_IsWritable = (1L << 31)
};

enum { kNumberOfResponseFrequencies = 1024 };

#define kAUPresetVersionKey "version"
#define kAUPresetTypeKey "type"
#define kAUPresetSubtypeKey "subtype"
#define kAUPresetManufacturerKey "manufacturer"
#define kAUPresetDataKey "data"
#define kAUPresetNameKey "name"
#define kAUPresetRenderQualityKey "render-quality"
#define kAUPresetCPULoadKey "cpu-load"
#define kAUPresetElementNameKey "element-name"
#define kAUPresetExternalFileRefs "file-references"
#define kAUPresetPartKey "part"

enum { kAudioUnitClumpID_System = 0 };
