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

enum {
    k3DMixerParam_Azimuth = 0,
    k3DMixerParam_Elevation = 1,
    k3DMixerParam_Distance = 2,
    k3DMixerParam_Gain = 3,
    k3DMixerParam_PlaybackRate = 4,
    k3DMixerParam_Enable = 5,
    k3DMixerParam_MinGain = 6,
    k3DMixerParam_MaxGain = 7,
    k3DMixerParam_ReverbBlend = 8,
    k3DMixerParam_GlobalReverbGain = 9,
    k3DMixerParam_OcclusionAttenuation = 10,
    k3DMixerParam_ObstructionAttenuation = 11
};

enum {
    kMultiChannelMixerParam_Volume = 0,
    kMultiChannelMixerParam_Enable = 1,
    kMultiChannelMixerParam_Pan = 2,
    kMultiChannelMixerParam_PreAveragePower = 1000,
    kMultiChannelMixerParam_PrePeakHoldLevel = 2000,
    kMultiChannelMixerParam_PostAveragePower = 3000,
    kMultiChannelMixerParam_PostPeakHoldLevel = 4000
};

enum { kBandpassParam_CenterFrequency = 0, kBandpassParam_Bandwidth = 1 };
enum { kHipassParam_CutoffFrequency = 0, kHipassParam_Resonance = 1 };
enum { kLowPassParam_CutoffFrequency = 0, kLowPassParam_Resonance = 1 };
enum { kHighShelfParam_CutOffFrequency = 0, kHighShelfParam_Gain = 1 };
enum { kAULowShelfParam_CutoffFrequency = 0, kAULowShelfParam_Gain = 1 };
enum { kParametricEQParam_CenterFreq = 0, kParametricEQParam_Q = 1, kParametricEQParam_Gain = 2 };

enum {
    kAUNBandEQParam_BypassBand = 1000,
    kAUNBandEQParam_FilterType = 2000,
    kAUNBandEQParam_Frequency = 3000,
    kAUNBandEQParam_Gain = 4000,
    kAUNBandEQParam_Bandwidth = 5000
};

enum {
    kAUNBandEQFilterType_Parametric = 0,
    kAUNBandEQFilterType_2ndOrderButterworthLowPass = 1,
    kAUNBandEQFilterType_2ndOrderButterworthHighPass = 2,
    kAUNBandEQFilterType_ResonantLowPass = 3,
    kAUNBandEQFilterType_ResonantHighPass = 4,
    kAUNBandEQFilterType_BandPass = 5,
    kAUNBandEQFilterType_BandStop = 6,
    kAUNBandEQFilterType_LowShelf = 7,
    kAUNBandEQFilterType_HighShelf = 8,
    kAUNBandEQFilterType_ResonantLowShelf = 9,
    kAUNBandEQFilterType_ResonantHighShelf = 10,
    kNumAUNBandEQFilterTypes = 11
};

enum {
    kDynamicsProcessorParam_Threshold = 0,
    kDynamicsProcessorParam_HeadRoom = 1,
    kDynamicsProcessorParam_ExpansionRatio = 2,
    kDynamicsProcessorParam_ExpansionThreshold = 3,
    kDynamicsProcessorParam_AttackTime = 4,
    kDynamicsProcessorParam_ReleaseTime = 5,
    kDynamicsProcessorParam_MasterGain = 6,
    kDynamicsProcessorParam_CompressionAmount = 1000,
    kDynamicsProcessorParam_InputAmplitude = 2000,
    kDynamicsProcessorParam_OutputAmplitude = 3000
};

enum { kLimiterParam_AttackTime = 0, kLimiterParam_DecayTime = 1, kLimiterParam_PreGain = 2 };

enum {
    kReverb2Param_DryWetMix = 0,
    kReverb2Param_Gain = 1,
    kReverb2Param_MinDelayTime = 2,
    kReverb2Param_MaxDelayTime = 3,
    kReverb2Param_DecayTimeAt0Hz = 4,
    kReverb2Param_DecayTimeAtNyquist = 5,
    kReverb2Param_RandomizeReflections = 6,
};

enum { kReverbParam_FilterFrequency = 14, kReverbParam_FilterBandwidth = 15, kReverbParam_FilterGain = 16 };

enum { kVarispeedParam_PlaybackRate = 0, kVarispeedParam_PlaybackCents = 1 };

enum {
    kAUGroupParameterID_Volume = 7, // value 0 < 128,
    kAUGroupParameterID_Sustain = 64, // value 0-63 (off ), 64-127 (on ),
    kAUGroupParameterID_AllNotesOff = 123, // value ignored,
    kAUGroupParameterID_ModWheel = 1, // value 0 < 128,
    kAUGroupParameterID_PitchBend = 0xE0, // value -8192 - 8191,
    kAUGroupParameterID_AllSoundOff = 120, // value ignored,
    kAUGroupParameterID_ResetAllControllers = 121, // value ignored,
    kAUGroupParameterID_Pan = 10, // value 0 < 128,
    kAUGroupParameterID_Foot = 4, // value 0 < 128,
    kAUGroupParameterID_ChannelPressure = 0xD0, // value 0 < 128,
    kAUGroupParameterID_KeyPressure = 0xA0, // values 0 < 128,
    kAUGroupParameterID_Expression = 11, // value 0 < 128,
    kAUGroupParameterID_DataEntry = 6, // value 0 < 128,
    kAUGroupParameterID_Volume_LSB = kAUGroupParameterID_Volume + 32, // value 0 < 128,
    kAUGroupParameterID_ModWheel_LSB = kAUGroupParameterID_ModWheel + 32, // value 0 < 128,
    kAUGroupParameterID_Pan_LSB = kAUGroupParameterID_Pan + 32, // value 0 < 128,
    kAUGroupParameterID_Foot_LSB = kAUGroupParameterID_Foot + 32, // value 0 < 128,
    kAUGroupParameterID_Expression_LSB = kAUGroupParameterID_Expression + 32, // value 0 < 128,
    kAUGroupParameterID_DataEntry_LSB = kAUGroupParameterID_DataEntry + 32, // value 0 < 128,
    kAUGroupParameterID_KeyPressure_FirstKey = 256, // value 0 < 128,
    kAUGroupParameterID_KeyPressure_LastKey = 383 // value 0 < 128
};

enum {
    kTimePitchParam_Rate = 0,
    kTimePitchParam_Pitch = 1,
    kTimePitchParam_EffectBlend = 2 // only for the AUPitch unit
};

enum { kHALOutputParam_Volume = 14 };
