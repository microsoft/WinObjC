/**
 * Reverb for the OpenAL cross platform audio library
 * Copyright (C) 2008-2009 by Christopher Fitzgerald.
 * This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the
 *  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 *  Boston, MA  02111-1307, USA.
 * Or go to http://www.gnu.org/copyleft/lgpl.html
 */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "AL/al.h"
#include "AL/alc.h"
#include "alMain.h"
#include "alAuxEffectSlot.h"
#include "alEffect.h"
#include "alError.h"
#include "alu.h"

typedef struct DelayLine
{
    // The delay lines use sample lengths that are powers of 2 to allow the
    // use of bit-masking instead of a modulus for wrapping.
    ALuint   Mask;
    ALfloat *Line;
} DelayLine;

typedef struct ALverbState {
    // Must be first in all effects!
    ALeffectState state;

    // All delay lines are allocated as a single buffer to reduce memory
    // fragmentation and management code.
    ALfloat  *SampleBuffer;
    ALuint    TotalSamples;

    // Master effect low-pass filter (2 chained 1-pole filters).
    FILTER    LpFilter;
    ALfloat   LpHistory[2];

    struct {
        // Modulator delay line.
        DelayLine Delay;

        // The vibrato time is tracked with an index over a modulus-wrapped
        // range (in samples).
        ALuint    Index;
        ALuint    Range;

        // The depth of frequency change (also in samples) and its filter.
        ALfloat   Depth;
        ALfloat   Coeff;
        ALfloat   Filter;
    } Mod;

    // Initial effect delay.
    DelayLine Delay;
    // The tap points for the initial delay.  First tap goes to early
    // reflections, the last to late reverb.
    ALuint    DelayTap[2];

    struct {
        // Output gain for early reflections.
        ALfloat   Gain;

        // Early reflections are done with 4 delay lines.
        ALfloat   Coeff[4];
        DelayLine Delay[4];
        ALuint    Offset[4];

        // The gain for each output channel based on 3D panning (only for the
        // EAX path).
        ALfloat   PanGain[MAXCHANNELS];
    } Early;

    // Decorrelator delay line.
    DelayLine Decorrelator;
    // There are actually 4 decorrelator taps, but the first occurs at the
    // initial sample.
    ALuint    DecoTap[3];

    struct {
        // Output gain for late reverb.
        ALfloat   Gain;

        // Attenuation to compensate for the modal density and decay rate of
        // the late lines.
        ALfloat   DensityGain;

        // The feed-back and feed-forward all-pass coefficient.
        ALfloat   ApFeedCoeff;

        // Mixing matrix coefficient.
        ALfloat   MixCoeff;

        // Late reverb has 4 parallel all-pass filters.
        ALfloat   ApCoeff[4];
        DelayLine ApDelay[4];
        ALuint    ApOffset[4];

        // In addition to 4 cyclical delay lines.
        ALfloat   Coeff[4];
        DelayLine Delay[4];
        ALuint    Offset[4];

        // The cyclical delay lines are 1-pole low-pass filtered.
        ALfloat   LpCoeff[4];
        ALfloat   LpSample[4];

        // The gain for each output channel based on 3D panning (only for the
        // EAX path).
        ALfloat   PanGain[MAXCHANNELS];
    } Late;

    struct {
        // Attenuation to compensate for the modal density and decay rate of
        // the echo line.
        ALfloat   DensityGain;

        // Echo delay and all-pass lines.
        DelayLine Delay;
        DelayLine ApDelay;

        ALfloat   Coeff;
        ALfloat   ApFeedCoeff;
        ALfloat   ApCoeff;

        ALuint    Offset;
        ALuint    ApOffset;

        // The echo line is 1-pole low-pass filtered.
        ALfloat   LpCoeff;
        ALfloat   LpSample;

        // Echo mixing coefficients.
        ALfloat   MixCoeff[2];
    } Echo;

    // The current read offset for all delay lines.
    ALuint Offset;

    // The gain for each output channel (non-EAX path only; aliased from
    // Late.PanGain)
    ALfloat *Gain;
} ALverbState;

/* This is a user config option for modifying the overall output of the reverb
 * effect.
 */
ALfloat ReverbBoost = 1.0f;

/* Specifies whether to use a standard reverb effect in place of EAX reverb */
ALboolean EmulateEAXReverb = AL_FALSE;

/* This coefficient is used to define the maximum frequency range controlled
 * by the modulation depth.  The current value of 0.1 will allow it to swing
 * from 0.9x to 1.1x.  This value must be below 1.  At 1 it will cause the
 * sampler to stall on the downswing, and above 1 it will cause it to sample
 * backwards.
 */
static const ALfloat MODULATION_DEPTH_COEFF = 0.1f;

/* A filter is used to avoid the terrible distortion caused by changing
 * modulation time and/or depth.  To be consistent across different sample
 * rates, the coefficient must be raised to a constant divided by the sample
 * rate:  coeff^(constant / rate).
 */
static const ALfloat MODULATION_FILTER_COEFF = 0.048f;
static const ALfloat MODULATION_FILTER_CONST = 100000.0f;

// When diffusion is above 0, an all-pass filter is used to take the edge off
// the echo effect.  It uses the following line length (in seconds).
static const ALfloat ECHO_ALLPASS_LENGTH = 0.0133f;

// Input into the late reverb is decorrelated between four channels.  Their
// timings are dependent on a fraction and multiplier.  See the
// UpdateDecorrelator() routine for the calculations involved.
static const ALfloat DECO_FRACTION = 0.15f;
static const ALfloat DECO_MULTIPLIER = 2.0f;

// All delay line lengths are specified in seconds.

// The lengths of the early delay lines.
static const ALfloat EARLY_LINE_LENGTH[4] =
{
    0.0015f, 0.0045f, 0.0135f, 0.0405f
};

// The lengths of the late all-pass delay lines.
static const ALfloat ALLPASS_LINE_LENGTH[4] =
{
    0.0151f, 0.0167f, 0.0183f, 0.0200f,
};

// The lengths of the late cyclical delay lines.
static const ALfloat LATE_LINE_LENGTH[4] =
{
    0.0211f, 0.0311f, 0.0461f, 0.0680f
};

// The late cyclical delay lines have a variable length dependent on the
// effect's density parameter (inverted for some reason) and this multiplier.
static const ALfloat LATE_LINE_MULTIPLIER = 4.0f;


// Basic delay line input/output routines.
static __inline ALfloat DelayLineOut(DelayLine *Delay, ALuint offset)
{
    return Delay->Line[offset&Delay->Mask];
}

static __inline ALvoid DelayLineIn(DelayLine *Delay, ALuint offset, ALfloat in)
{
    Delay->Line[offset&Delay->Mask] = in;
}

// Attenuated delay line output routine.
static __inline ALfloat AttenuatedDelayLineOut(DelayLine *Delay, ALuint offset, ALfloat coeff)
{
    return coeff * Delay->Line[offset&Delay->Mask];
}

// Basic attenuated all-pass input/output routine.
static __inline ALfloat AllpassInOut(DelayLine *Delay, ALuint outOffset, ALuint inOffset, ALfloat in, ALfloat feedCoeff, ALfloat coeff)
{
    ALfloat out, feed;

    out = DelayLineOut(Delay, outOffset);
    feed = feedCoeff * in;
    DelayLineIn(Delay, inOffset, (feedCoeff * (out - feed)) + in);

    // The time-based attenuation is only applied to the delay output to
    // keep it from affecting the feed-back path (which is already controlled
    // by the all-pass feed coefficient).
    return (coeff * out) - feed;
}

// Given an input sample, this function produces modulation for the late
// reverb.
static __inline ALfloat EAXModulation(ALverbState *State, ALfloat in)
{
    ALfloat sinus, frac;
    ALuint offset;
    ALfloat out0, out1;

    // Calculate the sinus rythm (dependent on modulation time and the
    // sampling rate).  The center of the sinus is moved to reduce the delay
    // of the effect when the time or depth are low.
    sinus = 1.0f - aluCos(F_PI*2.0f * State->Mod.Index / State->Mod.Range);

    // The depth determines the range over which to read the input samples
    // from, so it must be filtered to reduce the distortion caused by even
    // small parameter changes.
    State->Mod.Filter = lerp(State->Mod.Filter, State->Mod.Depth,
                             State->Mod.Coeff);

    // Calculate the read offset and fraction between it and the next sample.
    frac   = (1.0f + (State->Mod.Filter * sinus));
    offset = fastf2u(frac);
    frac  -= offset;

    // Get the two samples crossed by the offset, and feed the delay line
    // with the next input sample.
    out0 = DelayLineOut(&State->Mod.Delay, State->Offset - offset);
    out1 = DelayLineOut(&State->Mod.Delay, State->Offset - offset - 1);
    DelayLineIn(&State->Mod.Delay, State->Offset, in);

    // Step the modulation index forward, keeping it bound to its range.
    State->Mod.Index = (State->Mod.Index + 1) % State->Mod.Range;

    // The output is obtained by linearly interpolating the two samples that
    // were acquired above.
    return lerp(out0, out1, frac);
}

// Delay line output routine for early reflections.
static __inline ALfloat EarlyDelayLineOut(ALverbState *State, ALuint index)
{
    return AttenuatedDelayLineOut(&State->Early.Delay[index],
                                  State->Offset - State->Early.Offset[index],
                                  State->Early.Coeff[index]);
}

// Given an input sample, this function produces four-channel output for the
// early reflections.
static __inline ALvoid EarlyReflection(ALverbState *State, ALfloat in, ALfloat *out)
{
    ALfloat d[4], v, f[4];

    // Obtain the decayed results of each early delay line.
    d[0] = EarlyDelayLineOut(State, 0);
    d[1] = EarlyDelayLineOut(State, 1);
    d[2] = EarlyDelayLineOut(State, 2);
    d[3] = EarlyDelayLineOut(State, 3);

    /* The following uses a lossless scattering junction from waveguide
     * theory.  It actually amounts to a householder mixing matrix, which
     * will produce a maximally diffuse response, and means this can probably
     * be considered a simple feed-back delay network (FDN).
     *          N
     *         ---
     *         \
     * v = 2/N /   d_i
     *         ---
     *         i=1
     */
    v = (d[0] + d[1] + d[2] + d[3]) * 0.5f;
    // The junction is loaded with the input here.
    v += in;

    // Calculate the feed values for the delay lines.
    f[0] = v - d[0];
    f[1] = v - d[1];
    f[2] = v - d[2];
    f[3] = v - d[3];

    // Re-feed the delay lines.
    DelayLineIn(&State->Early.Delay[0], State->Offset, f[0]);
    DelayLineIn(&State->Early.Delay[1], State->Offset, f[1]);
    DelayLineIn(&State->Early.Delay[2], State->Offset, f[2]);
    DelayLineIn(&State->Early.Delay[3], State->Offset, f[3]);

    // Output the results of the junction for all four channels.
    out[0] = State->Early.Gain * f[0];
    out[1] = State->Early.Gain * f[1];
    out[2] = State->Early.Gain * f[2];
    out[3] = State->Early.Gain * f[3];
}

// All-pass input/output routine for late reverb.
static __inline ALfloat LateAllPassInOut(ALverbState *State, ALuint index, ALfloat in)
{
    return AllpassInOut(&State->Late.ApDelay[index],
                        State->Offset - State->Late.ApOffset[index],
                        State->Offset, in, State->Late.ApFeedCoeff,
                        State->Late.ApCoeff[index]);
}

// Delay line output routine for late reverb.
static __inline ALfloat LateDelayLineOut(ALverbState *State, ALuint index)
{
    return AttenuatedDelayLineOut(&State->Late.Delay[index],
                                  State->Offset - State->Late.Offset[index],
                                  State->Late.Coeff[index]);
}

// Low-pass filter input/output routine for late reverb.
static __inline ALfloat LateLowPassInOut(ALverbState *State, ALuint index, ALfloat in)
{
    in = lerp(in, State->Late.LpSample[index], State->Late.LpCoeff[index]);
    State->Late.LpSample[index] = in;
    return in;
}

// Given four decorrelated input samples, this function produces four-channel
// output for the late reverb.
static __inline ALvoid LateReverb(ALverbState *State, ALfloat *in, ALfloat *out)
{
    ALfloat d[4], f[4];

    // Obtain the decayed results of the cyclical delay lines, and add the
    // corresponding input channels.  Then pass the results through the
    // low-pass filters.

    // This is where the feed-back cycles from line 0 to 1 to 3 to 2 and back
    // to 0.
    d[0] = LateLowPassInOut(State, 2, in[2] + LateDelayLineOut(State, 2));
    d[1] = LateLowPassInOut(State, 0, in[0] + LateDelayLineOut(State, 0));
    d[2] = LateLowPassInOut(State, 3, in[3] + LateDelayLineOut(State, 3));
    d[3] = LateLowPassInOut(State, 1, in[1] + LateDelayLineOut(State, 1));

    // To help increase diffusion, run each line through an all-pass filter.
    // When there is no diffusion, the shortest all-pass filter will feed the
    // shortest delay line.
    d[0] = LateAllPassInOut(State, 0, d[0]);
    d[1] = LateAllPassInOut(State, 1, d[1]);
    d[2] = LateAllPassInOut(State, 2, d[2]);
    d[3] = LateAllPassInOut(State, 3, d[3]);

    /* Late reverb is done with a modified feed-back delay network (FDN)
     * topology.  Four input lines are each fed through their own all-pass
     * filter and then into the mixing matrix.  The four outputs of the
     * mixing matrix are then cycled back to the inputs.  Each output feeds
     * a different input to form a circlular feed cycle.
     *
     * The mixing matrix used is a 4D skew-symmetric rotation matrix derived
     * using a single unitary rotational parameter:
     *
     *  [  d,  a,  b,  c ]          1 = a^2 + b^2 + c^2 + d^2
     *  [ -a,  d,  c, -b ]
     *  [ -b, -c,  d,  a ]
     *  [ -c,  b, -a,  d ]
     *
     * The rotation is constructed from the effect's diffusion parameter,
     * yielding:  1 = x^2 + 3 y^2; where a, b, and c are the coefficient y
     * with differing signs, and d is the coefficient x.  The matrix is thus:
     *
     *  [  x,  y, -y,  y ]          n = sqrt(matrix_order - 1)
     *  [ -y,  x,  y,  y ]          t = diffusion_parameter * atan(n)
     *  [  y, -y,  x,  y ]          x = cos(t)
     *  [ -y, -y, -y,  x ]          y = sin(t) / n
     *
     * To reduce the number of multiplies, the x coefficient is applied with
     * the cyclical delay line coefficients.  Thus only the y coefficient is
     * applied when mixing, and is modified to be:  y / x.
     */
    f[0] = d[0] + (State->Late.MixCoeff * (         d[1] + -d[2] + d[3]));
    f[1] = d[1] + (State->Late.MixCoeff * (-d[0]         +  d[2] + d[3]));
    f[2] = d[2] + (State->Late.MixCoeff * ( d[0] + -d[1]         + d[3]));
    f[3] = d[3] + (State->Late.MixCoeff * (-d[0] + -d[1] + -d[2]       ));

    // Output the results of the matrix for all four channels, attenuated by
    // the late reverb gain (which is attenuated by the 'x' mix coefficient).
    out[0] = State->Late.Gain * f[0];
    out[1] = State->Late.Gain * f[1];
    out[2] = State->Late.Gain * f[2];
    out[3] = State->Late.Gain * f[3];

    // Re-feed the cyclical delay lines.
    DelayLineIn(&State->Late.Delay[0], State->Offset, f[0]);
    DelayLineIn(&State->Late.Delay[1], State->Offset, f[1]);
    DelayLineIn(&State->Late.Delay[2], State->Offset, f[2]);
    DelayLineIn(&State->Late.Delay[3], State->Offset, f[3]);
}

// Given an input sample, this function mixes echo into the four-channel late
// reverb.
static __inline ALvoid EAXEcho(ALverbState *State, ALfloat in, ALfloat *late)
{
    ALfloat out, feed;

    // Get the latest attenuated echo sample for output.
    feed = AttenuatedDelayLineOut(&State->Echo.Delay,
                                  State->Offset - State->Echo.Offset,
                                  State->Echo.Coeff);

    // Mix the output into the late reverb channels.
    out = State->Echo.MixCoeff[0] * feed;
    late[0] = (State->Echo.MixCoeff[1] * late[0]) + out;
    late[1] = (State->Echo.MixCoeff[1] * late[1]) + out;
    late[2] = (State->Echo.MixCoeff[1] * late[2]) + out;
    late[3] = (State->Echo.MixCoeff[1] * late[3]) + out;

    // Mix the energy-attenuated input with the output and pass it through
    // the echo low-pass filter.
    feed += State->Echo.DensityGain * in;
    feed = lerp(feed, State->Echo.LpSample, State->Echo.LpCoeff);
    State->Echo.LpSample = feed;

    // Then the echo all-pass filter.
    feed = AllpassInOut(&State->Echo.ApDelay,
                        State->Offset - State->Echo.ApOffset,
                        State->Offset, feed, State->Echo.ApFeedCoeff,
                        State->Echo.ApCoeff);

    // Feed the delay with the mixed and filtered sample.
    DelayLineIn(&State->Echo.Delay, State->Offset, feed);
}

// Perform the non-EAX reverb pass on a given input sample, resulting in
// four-channel output.
static __inline ALvoid VerbPass(ALverbState *State, ALfloat in, ALfloat *early, ALfloat *late)
{
    ALfloat feed, taps[4];

    // Low-pass filter the incoming sample.
    in = lpFilter2P(&State->LpFilter, 0, in);

    // Feed the initial delay line.
    DelayLineIn(&State->Delay, State->Offset, in);

    // Calculate the early reflection from the first delay tap.
    in = DelayLineOut(&State->Delay, State->Offset - State->DelayTap[0]);
    EarlyReflection(State, in, early);

    // Feed the decorrelator from the energy-attenuated output of the second
    // delay tap.
    in = DelayLineOut(&State->Delay, State->Offset - State->DelayTap[1]);
    feed = in * State->Late.DensityGain;
    DelayLineIn(&State->Decorrelator, State->Offset, feed);

    // Calculate the late reverb from the decorrelator taps.
    taps[0] = feed;
    taps[1] = DelayLineOut(&State->Decorrelator, State->Offset - State->DecoTap[0]);
    taps[2] = DelayLineOut(&State->Decorrelator, State->Offset - State->DecoTap[1]);
    taps[3] = DelayLineOut(&State->Decorrelator, State->Offset - State->DecoTap[2]);
    LateReverb(State, taps, late);

    // Step all delays forward one sample.
    State->Offset++;
}

// Perform the EAX reverb pass on a given input sample, resulting in four-
// channel output.
static __inline ALvoid EAXVerbPass(ALverbState *State, ALfloat in, ALfloat *early, ALfloat *late)
{
    ALfloat feed, taps[4];

    // Low-pass filter the incoming sample.
    in = lpFilter2P(&State->LpFilter, 0, in);

    // Perform any modulation on the input.
    in = EAXModulation(State, in);

    // Feed the initial delay line.
    DelayLineIn(&State->Delay, State->Offset, in);

    // Calculate the early reflection from the first delay tap.
    in = DelayLineOut(&State->Delay, State->Offset - State->DelayTap[0]);
    EarlyReflection(State, in, early);

    // Feed the decorrelator from the energy-attenuated output of the second
    // delay tap.
    in = DelayLineOut(&State->Delay, State->Offset - State->DelayTap[1]);
    feed = in * State->Late.DensityGain;
    DelayLineIn(&State->Decorrelator, State->Offset, feed);

    // Calculate the late reverb from the decorrelator taps.
    taps[0] = feed;
    taps[1] = DelayLineOut(&State->Decorrelator, State->Offset - State->DecoTap[0]);
    taps[2] = DelayLineOut(&State->Decorrelator, State->Offset - State->DecoTap[1]);
    taps[3] = DelayLineOut(&State->Decorrelator, State->Offset - State->DecoTap[2]);
    LateReverb(State, taps, late);

    // Calculate and mix in any echo.
    EAXEcho(State, in, late);

    // Step all delays forward one sample.
    State->Offset++;
}

// This processes the reverb state, given the input samples and an output
// buffer.
static ALvoid VerbProcess(ALeffectState *effect, ALuint SamplesToDo, const ALfloat *SamplesIn, ALfloat (*SamplesOut)[MAXCHANNELS])
{
    ALverbState *State = (ALverbState*)effect;
    ALuint index, c;
    ALfloat early[4], late[4], out[4];
    const ALfloat *panGain = State->Gain;

    for(index = 0;index < SamplesToDo;index++)
    {
        // Process reverb for this sample.
        VerbPass(State, SamplesIn[index], early, late);

        // Mix early reflections and late reverb.
        out[0] = (early[0] + late[0]);
        out[1] = (early[1] + late[1]);
        out[2] = (early[2] + late[2]);
        out[3] = (early[3] + late[3]);

        // Output the results.
        for(c = 0;c < MAXCHANNELS;c++)
            SamplesOut[index][c] += panGain[c] * out[c&3];
    }
}

// This processes the EAX reverb state, given the input samples and an output
// buffer.
static ALvoid EAXVerbProcess(ALeffectState *effect, ALuint SamplesToDo, const ALfloat *SamplesIn, ALfloat (*SamplesOut)[MAXCHANNELS])
{
    ALverbState *State = (ALverbState*)effect;
    ALuint index, c;
    ALfloat early[4], late[4];

    for(index = 0;index < SamplesToDo;index++)
    {
        // Process reverb for this sample.
        EAXVerbPass(State, SamplesIn[index], early, late);

        for(c = 0;c < MAXCHANNELS;c++)
            SamplesOut[index][c] += State->Early.PanGain[c]*early[c&3] +
                                    State->Late.PanGain[c]*late[c&3];
    }
}


// Given the allocated sample buffer, this function updates each delay line
// offset.
static __inline ALvoid RealizeLineOffset(ALfloat * sampleBuffer, DelayLine *Delay)
{
    Delay->Line = &sampleBuffer[(ALintptrEXT)Delay->Line];
}

// Calculate the length of a delay line and store its mask and offset.
static ALuint CalcLineLength(ALfloat length, ALintptrEXT offset, ALuint frequency, DelayLine *Delay)
{
    ALuint samples;

    // All line lengths are powers of 2, calculated from their lengths, with
    // an additional sample in case of rounding errors.
    samples = NextPowerOf2(fastf2u(length * frequency) + 1);
    // All lines share a single sample buffer.
    Delay->Mask = samples - 1;
    Delay->Line = (ALfloat*)offset;
    // Return the sample count for accumulation.
    return samples;
}

/* Calculates the delay line metrics and allocates the shared sample buffer
 * for all lines given the sample rate (frequency).  If an allocation failure
 * occurs, it returns AL_FALSE.
 */
static ALboolean AllocLines(ALuint frequency, ALverbState *State)
{
    ALuint totalSamples, index;
    ALfloat length;
    ALfloat *newBuffer = NULL;

    // All delay line lengths are calculated to accomodate the full range of
    // lengths given their respective paramters.
    totalSamples = 0;

    /* The modulator's line length is calculated from the maximum modulation
     * time and depth coefficient, and halfed for the low-to-high frequency
     * swing.  An additional sample is added to keep it stable when there is no
     * modulation.
     */
    length = (AL_EAXREVERB_MAX_MODULATION_TIME*MODULATION_DEPTH_COEFF/2.0f) +
             (1.0f / frequency);
    totalSamples += CalcLineLength(length, totalSamples, frequency,
                                   &State->Mod.Delay);

    // The initial delay is the sum of the reflections and late reverb
    // delays.
    length = AL_EAXREVERB_MAX_REFLECTIONS_DELAY +
             AL_EAXREVERB_MAX_LATE_REVERB_DELAY;
    totalSamples += CalcLineLength(length, totalSamples, frequency,
                                   &State->Delay);

    // The early reflection lines.
    for(index = 0;index < 4;index++)
        totalSamples += CalcLineLength(EARLY_LINE_LENGTH[index], totalSamples,
                                       frequency, &State->Early.Delay[index]);

    // The decorrelator line is calculated from the lowest reverb density (a
    // parameter value of 1).
    length = (DECO_FRACTION * DECO_MULTIPLIER * DECO_MULTIPLIER) *
             LATE_LINE_LENGTH[0] * (1.0f + LATE_LINE_MULTIPLIER);
    totalSamples += CalcLineLength(length, totalSamples, frequency,
                                   &State->Decorrelator);

    // The late all-pass lines.
    for(index = 0;index < 4;index++)
        totalSamples += CalcLineLength(ALLPASS_LINE_LENGTH[index], totalSamples,
                                       frequency, &State->Late.ApDelay[index]);

    // The late delay lines are calculated from the lowest reverb density.
    for(index = 0;index < 4;index++)
    {
        length = LATE_LINE_LENGTH[index] * (1.0f + LATE_LINE_MULTIPLIER);
        totalSamples += CalcLineLength(length, totalSamples, frequency,
                                       &State->Late.Delay[index]);
    }

    // The echo all-pass and delay lines.
    totalSamples += CalcLineLength(ECHO_ALLPASS_LENGTH, totalSamples,
                                   frequency, &State->Echo.ApDelay);
    totalSamples += CalcLineLength(AL_EAXREVERB_MAX_ECHO_TIME, totalSamples,
                                   frequency, &State->Echo.Delay);

    if(totalSamples != State->TotalSamples)
    {
        TRACE("New reverb buffer length: %u samples (%f sec)\n", totalSamples, totalSamples/(float)frequency);
        newBuffer = realloc(State->SampleBuffer, sizeof(ALfloat) * totalSamples);
        if(newBuffer == NULL)
            return AL_FALSE;
        State->SampleBuffer = newBuffer;
        State->TotalSamples = totalSamples;
    }

    // Update all delays to reflect the new sample buffer.
    RealizeLineOffset(State->SampleBuffer, &State->Delay);
    RealizeLineOffset(State->SampleBuffer, &State->Decorrelator);
    for(index = 0;index < 4;index++)
    {
        RealizeLineOffset(State->SampleBuffer, &State->Early.Delay[index]);
        RealizeLineOffset(State->SampleBuffer, &State->Late.ApDelay[index]);
        RealizeLineOffset(State->SampleBuffer, &State->Late.Delay[index]);
    }
    RealizeLineOffset(State->SampleBuffer, &State->Mod.Delay);
    RealizeLineOffset(State->SampleBuffer, &State->Echo.ApDelay);
    RealizeLineOffset(State->SampleBuffer, &State->Echo.Delay);

    // Clear the sample buffer.
    for(index = 0;index < State->TotalSamples;index++)
        State->SampleBuffer[index] = 0.0f;

    return AL_TRUE;
}

// This updates the device-dependant EAX reverb state.  This is called on
// initialization and any time the device parameters (eg. playback frequency,
// format) have been changed.
static ALboolean ReverbDeviceUpdate(ALeffectState *effect, ALCdevice *Device)
{
    ALverbState *State = (ALverbState*)effect;
    ALuint frequency = Device->Frequency, index;

    // Allocate the delay lines.
    if(!AllocLines(frequency, State))
        return AL_FALSE;

    // Calculate the modulation filter coefficient.  Notice that the exponent
    // is calculated given the current sample rate.  This ensures that the
    // resulting filter response over time is consistent across all sample
    // rates.
    State->Mod.Coeff = aluPow(MODULATION_FILTER_COEFF,
                              MODULATION_FILTER_CONST / frequency);

    // The early reflection and late all-pass filter line lengths are static,
    // so their offsets only need to be calculated once.
    for(index = 0;index < 4;index++)
    {
        State->Early.Offset[index] = fastf2u(EARLY_LINE_LENGTH[index] *
                                             frequency);
        State->Late.ApOffset[index] = fastf2u(ALLPASS_LINE_LENGTH[index] *
                                              frequency);
    }

    // The echo all-pass filter line length is static, so its offset only
    // needs to be calculated once.
    State->Echo.ApOffset = fastf2u(ECHO_ALLPASS_LENGTH * frequency);

    return AL_TRUE;
}

// Calculate a decay coefficient given the length of each cycle and the time
// until the decay reaches -60 dB.
static __inline ALfloat CalcDecayCoeff(ALfloat length, ALfloat decayTime)
{
    return aluPow(0.001f/*-60 dB*/, length/decayTime);
}

// Calculate a decay length from a coefficient and the time until the decay
// reaches -60 dB.
static __inline ALfloat CalcDecayLength(ALfloat coeff, ALfloat decayTime)
{
    return aluLog10(coeff) * decayTime / aluLog10(0.001f)/*-60 dB*/;
}

// Calculate the high frequency parameter for the I3DL2 coefficient
// calculation.
static __inline ALfloat CalcI3DL2HFreq(ALfloat hfRef, ALuint frequency)
{
    return aluCos(F_PI*2.0f * hfRef / frequency);
}

// Calculate an attenuation to be applied to the input of any echo models to
// compensate for modal density and decay time.
static __inline ALfloat CalcDensityGain(ALfloat a)
{
    /* The energy of a signal can be obtained by finding the area under the
     * squared signal.  This takes the form of Sum(x_n^2), where x is the
     * amplitude for the sample n.
     *
     * Decaying feedback matches exponential decay of the form Sum(a^n),
     * where a is the attenuation coefficient, and n is the sample.  The area
     * under this decay curve can be calculated as:  1 / (1 - a).
     *
     * Modifying the above equation to find the squared area under the curve
     * (for energy) yields:  1 / (1 - a^2).  Input attenuation can then be
     * calculated by inverting the square root of this approximation,
     * yielding:  1 / sqrt(1 / (1 - a^2)), simplified to: sqrt(1 - a^2).
     */
    return aluSqrt(1.0f - (a * a));
}

// Calculate the mixing matrix coefficients given a diffusion factor.
static __inline ALvoid CalcMatrixCoeffs(ALfloat diffusion, ALfloat *x, ALfloat *y)
{
    ALfloat n, t;

    // The matrix is of order 4, so n is sqrt (4 - 1).
    n = aluSqrt(3.0f);
    t = diffusion * aluAtan(n);

    // Calculate the first mixing matrix coefficient.
    *x = aluCos(t);
    // Calculate the second mixing matrix coefficient.
    *y = aluSin(t) / n;
}

// Calculate the limited HF ratio for use with the late reverb low-pass
// filters.
static ALfloat CalcLimitedHfRatio(ALfloat hfRatio, ALfloat airAbsorptionGainHF, ALfloat decayTime)
{
    ALfloat limitRatio;

    /* Find the attenuation due to air absorption in dB (converting delay
     * time to meters using the speed of sound).  Then reversing the decay
     * equation, solve for HF ratio.  The delay length is cancelled out of
     * the equation, so it can be calculated once for all lines.
     */
    limitRatio = 1.0f / (CalcDecayLength(airAbsorptionGainHF, decayTime) *
                         SPEEDOFSOUNDMETRESPERSEC);
    /* Using the limit calculated above, apply the upper bound to the HF
     * ratio. Also need to limit the result to a minimum of 0.1, just like the
     * HF ratio parameter. */
    return clampf(limitRatio, 0.1f, hfRatio);
}

// Calculate the coefficient for a HF (and eventually LF) decay damping
// filter.
static __inline ALfloat CalcDampingCoeff(ALfloat hfRatio, ALfloat length, ALfloat decayTime, ALfloat decayCoeff, ALfloat cw)
{
    ALfloat coeff, g;

    // Eventually this should boost the high frequencies when the ratio
    // exceeds 1.
    coeff = 0.0f;
    if (hfRatio < 1.0f)
    {
        // Calculate the low-pass coefficient by dividing the HF decay
        // coefficient by the full decay coefficient.
        g = CalcDecayCoeff(length, decayTime * hfRatio) / decayCoeff;

        // Damping is done with a 1-pole filter, so g needs to be squared.
        g *= g;
        coeff = lpCoeffCalc(g, cw);

        // Very low decay times will produce minimal output, so apply an
        // upper bound to the coefficient.
        coeff = minf(coeff, 0.98f);
    }
    return coeff;
}

// Update the EAX modulation index, range, and depth.  Keep in mind that this
// kind of vibrato is additive and not multiplicative as one may expect.  The
// downswing will sound stronger than the upswing.
static ALvoid UpdateModulator(ALfloat modTime, ALfloat modDepth, ALuint frequency, ALverbState *State)
{
    ALuint range;

    /* Modulation is calculated in two parts.
     *
     * The modulation time effects the sinus applied to the change in
     * frequency.  An index out of the current time range (both in samples)
     * is incremented each sample.  The range is bound to a reasonable
     * minimum (1 sample) and when the timing changes, the index is rescaled
     * to the new range (to keep the sinus consistent).
     */
    range = maxu(fastf2u(modTime*frequency), 1);
    State->Mod.Index = (ALuint)(State->Mod.Index * (ALuint64)range /
                                State->Mod.Range);
    State->Mod.Range = range;

    /* The modulation depth effects the amount of frequency change over the
     * range of the sinus.  It needs to be scaled by the modulation time so
     * that a given depth produces a consistent change in frequency over all
     * ranges of time.  Since the depth is applied to a sinus value, it needs
     * to be halfed once for the sinus range and again for the sinus swing
     * in time (half of it is spent decreasing the frequency, half is spent
     * increasing it).
     */
    State->Mod.Depth = modDepth * MODULATION_DEPTH_COEFF * modTime / 2.0f /
                       2.0f * frequency;
}

// Update the offsets for the initial effect delay line.
static ALvoid UpdateDelayLine(ALfloat earlyDelay, ALfloat lateDelay, ALuint frequency, ALverbState *State)
{
    // Calculate the initial delay taps.
    State->DelayTap[0] = fastf2u(earlyDelay * frequency);
    State->DelayTap[1] = fastf2u((earlyDelay + lateDelay) * frequency);
}

// Update the early reflections gain and line coefficients.
static ALvoid UpdateEarlyLines(ALfloat reverbGain, ALfloat earlyGain, ALfloat lateDelay, ALverbState *State)
{
    ALuint index;

    // Calculate the early reflections gain (from the master effect gain, and
    // reflections gain parameters) with a constant attenuation of 0.5.
    State->Early.Gain = 0.5f * reverbGain * earlyGain;

    // Calculate the gain (coefficient) for each early delay line using the
    // late delay time.  This expands the early reflections to the start of
    // the late reverb.
    for(index = 0;index < 4;index++)
        State->Early.Coeff[index] = CalcDecayCoeff(EARLY_LINE_LENGTH[index],
                                                   lateDelay);
}

// Update the offsets for the decorrelator line.
static ALvoid UpdateDecorrelator(ALfloat density, ALuint frequency, ALverbState *State)
{
    ALuint index;
    ALfloat length;

    /* The late reverb inputs are decorrelated to smooth the reverb tail and
     * reduce harsh echos.  The first tap occurs immediately, while the
     * remaining taps are delayed by multiples of a fraction of the smallest
     * cyclical delay time.
     *
     * offset[index] = (FRACTION (MULTIPLIER^index)) smallest_delay
     */
    for(index = 0;index < 3;index++)
    {
        length = (DECO_FRACTION * aluPow(DECO_MULTIPLIER, (ALfloat)index)) *
                 LATE_LINE_LENGTH[0] * (1.0f + (density * LATE_LINE_MULTIPLIER));
        State->DecoTap[index] = fastf2u(length * frequency);
    }
}

// Update the late reverb gains, line lengths, and line coefficients.
static ALvoid UpdateLateLines(ALfloat reverbGain, ALfloat lateGain, ALfloat xMix, ALfloat density, ALfloat decayTime, ALfloat diffusion, ALfloat hfRatio, ALfloat cw, ALuint frequency, ALverbState *State)
{
    ALfloat length;
    ALuint index;

    /* Calculate the late reverb gain (from the master effect gain, and late
     * reverb gain parameters).  Since the output is tapped prior to the
     * application of the next delay line coefficients, this gain needs to be
     * attenuated by the 'x' mixing matrix coefficient as well.
     */
    State->Late.Gain = reverbGain * lateGain * xMix;

    /* To compensate for changes in modal density and decay time of the late
     * reverb signal, the input is attenuated based on the maximal energy of
     * the outgoing signal.  This approximation is used to keep the apparent
     * energy of the signal equal for all ranges of density and decay time.
     *
     * The average length of the cyclcical delay lines is used to calculate
     * the attenuation coefficient.
     */
    length = (LATE_LINE_LENGTH[0] + LATE_LINE_LENGTH[1] +
              LATE_LINE_LENGTH[2] + LATE_LINE_LENGTH[3]) / 4.0f;
    length *= 1.0f + (density * LATE_LINE_MULTIPLIER);
    State->Late.DensityGain = CalcDensityGain(CalcDecayCoeff(length,
                                                             decayTime));

    // Calculate the all-pass feed-back and feed-forward coefficient.
    State->Late.ApFeedCoeff = 0.5f * aluPow(diffusion, 2.0f);

    for(index = 0;index < 4;index++)
    {
        // Calculate the gain (coefficient) for each all-pass line.
        State->Late.ApCoeff[index] = CalcDecayCoeff(ALLPASS_LINE_LENGTH[index],
                                                    decayTime);

        // Calculate the length (in seconds) of each cyclical delay line.
        length = LATE_LINE_LENGTH[index] * (1.0f + (density *
                                                    LATE_LINE_MULTIPLIER));

        // Calculate the delay offset for each cyclical delay line.
        State->Late.Offset[index] = fastf2u(length * frequency);

        // Calculate the gain (coefficient) for each cyclical line.
        State->Late.Coeff[index] = CalcDecayCoeff(length, decayTime);

        // Calculate the damping coefficient for each low-pass filter.
        State->Late.LpCoeff[index] =
            CalcDampingCoeff(hfRatio, length, decayTime,
                             State->Late.Coeff[index], cw);

        // Attenuate the cyclical line coefficients by the mixing coefficient
        // (x).
        State->Late.Coeff[index] *= xMix;
    }
}

// Update the echo gain, line offset, line coefficients, and mixing
// coefficients.
static ALvoid UpdateEchoLine(ALfloat reverbGain, ALfloat lateGain, ALfloat echoTime, ALfloat decayTime, ALfloat diffusion, ALfloat echoDepth, ALfloat hfRatio, ALfloat cw, ALuint frequency, ALverbState *State)
{
    // Update the offset and coefficient for the echo delay line.
    State->Echo.Offset = fastf2u(echoTime * frequency);

    // Calculate the decay coefficient for the echo line.
    State->Echo.Coeff = CalcDecayCoeff(echoTime, decayTime);

    // Calculate the energy-based attenuation coefficient for the echo delay
    // line.
    State->Echo.DensityGain = CalcDensityGain(State->Echo.Coeff);

    // Calculate the echo all-pass feed coefficient.
    State->Echo.ApFeedCoeff = 0.5f * aluPow(diffusion, 2.0f);

    // Calculate the echo all-pass attenuation coefficient.
    State->Echo.ApCoeff = CalcDecayCoeff(ECHO_ALLPASS_LENGTH, decayTime);

    // Calculate the damping coefficient for each low-pass filter.
    State->Echo.LpCoeff = CalcDampingCoeff(hfRatio, echoTime, decayTime,
                                           State->Echo.Coeff, cw);

    /* Calculate the echo mixing coefficients.  The first is applied to the
     * echo itself.  The second is used to attenuate the late reverb when
     * echo depth is high and diffusion is low, so the echo is slightly
     * stronger than the decorrelated echos in the reverb tail.
     */
    State->Echo.MixCoeff[0] = reverbGain * lateGain * echoDepth;
    State->Echo.MixCoeff[1] = 1.0f - (echoDepth * 0.5f * (1.0f - diffusion));
}

// Update the early and late 3D panning gains.
static ALvoid Update3DPanning(const ALCdevice *Device, const ALfloat *ReflectionsPan, const ALfloat *LateReverbPan, ALfloat Gain, ALverbState *State)
{
    ALfloat earlyPan[3] = { ReflectionsPan[0], ReflectionsPan[1],
                            ReflectionsPan[2] };
    ALfloat latePan[3] = { LateReverbPan[0], LateReverbPan[1],
                           LateReverbPan[2] };
    const ALfloat *speakerGain;
    ALfloat ambientGain;
    ALfloat dirGain;
    ALfloat length;
    ALuint index;
    ALint pos;

    Gain *= ReverbBoost;

    // Attenuate non-directional reverb according to the number of channels
    ambientGain = aluSqrt(2.0f/Device->NumChan);

    // Calculate the 3D-panning gains for the early reflections and late
    // reverb.
    length = earlyPan[0]*earlyPan[0] + earlyPan[1]*earlyPan[1] + earlyPan[2]*earlyPan[2];
    if(length > 1.0f)
    {
        length = 1.0f / aluSqrt(length);
        earlyPan[0] *= length;
        earlyPan[1] *= length;
        earlyPan[2] *= length;
    }
    length = latePan[0]*latePan[0] + latePan[1]*latePan[1] + latePan[2]*latePan[2];
    if(length > 1.0f)
    {
        length = 1.0f / aluSqrt(length);
        latePan[0] *= length;
        latePan[1] *= length;
        latePan[2] *= length;
    }

    /* This code applies directional reverb just like the mixer applies
     * directional sources.  It diffuses the sound toward all speakers as the
     * magnitude of the panning vector drops, which is only a rough
     * approximation of the expansion of sound across the speakers from the
     * panning direction.
     */
    pos = aluCart2LUTpos(earlyPan[2], earlyPan[0]);
    speakerGain = Device->PanningLUT[pos];
    dirGain = aluSqrt((earlyPan[0] * earlyPan[0]) + (earlyPan[2] * earlyPan[2]));

    for(index = 0;index < MAXCHANNELS;index++)
        State->Early.PanGain[index] = 0.0f;
    for(index = 0;index < Device->NumChan;index++)
    {
        enum Channel chan = Device->Speaker2Chan[index];
        State->Early.PanGain[chan] = lerp(ambientGain, speakerGain[chan], dirGain) * Gain;
    }


    pos = aluCart2LUTpos(latePan[2], latePan[0]);
    speakerGain = Device->PanningLUT[pos];
    dirGain = aluSqrt((latePan[0] * latePan[0]) + (latePan[2] * latePan[2]));

    for(index = 0;index < MAXCHANNELS;index++)
         State->Late.PanGain[index] = 0.0f;
    for(index = 0;index < Device->NumChan;index++)
    {
        enum Channel chan = Device->Speaker2Chan[index];
        State->Late.PanGain[chan] = lerp(ambientGain, speakerGain[chan], dirGain) * Gain;
    }
}

// This updates the EAX reverb state.  This is called any time the EAX reverb
// effect is loaded into a slot.
static ALvoid ReverbUpdate(ALeffectState *effect, ALCcontext *Context, const ALeffectslot *Slot)
{
    ALverbState *State = (ALverbState*)effect;
    ALuint frequency = Context->Device->Frequency;
    ALboolean isEAX = AL_FALSE;
    ALfloat cw, x, y, hfRatio;

    if(Slot->effect.type == AL_EFFECT_EAXREVERB && !EmulateEAXReverb)
    {
        State->state.Process = EAXVerbProcess;
        isEAX = AL_TRUE;
    }
    else if(Slot->effect.type == AL_EFFECT_REVERB || EmulateEAXReverb)
    {
        State->state.Process = VerbProcess;
        isEAX = AL_FALSE;
    }

    // Calculate the master low-pass filter (from the master effect HF gain).
    if(isEAX) cw = CalcI3DL2HFreq(Slot->effect.Reverb.HFReference, frequency);
    else cw = CalcI3DL2HFreq(LOWPASSFREQREF, frequency);
    // This is done with 2 chained 1-pole filters, so no need to square g.
    State->LpFilter.coeff = lpCoeffCalc(Slot->effect.Reverb.GainHF, cw);

    if(isEAX)
    {
        // Update the modulator line.
        UpdateModulator(Slot->effect.Reverb.ModulationTime,
                        Slot->effect.Reverb.ModulationDepth,
                        frequency, State);
    }

    // Update the initial effect delay.
    UpdateDelayLine(Slot->effect.Reverb.ReflectionsDelay,
                    Slot->effect.Reverb.LateReverbDelay,
                    frequency, State);

    // Update the early lines.
    UpdateEarlyLines(Slot->effect.Reverb.Gain,
                     Slot->effect.Reverb.ReflectionsGain,
                     Slot->effect.Reverb.LateReverbDelay, State);

    // Update the decorrelator.
    UpdateDecorrelator(Slot->effect.Reverb.Density, frequency, State);

    // Get the mixing matrix coefficients (x and y).
    CalcMatrixCoeffs(Slot->effect.Reverb.Diffusion, &x, &y);
    // Then divide x into y to simplify the matrix calculation.
    State->Late.MixCoeff = y / x;

    // If the HF limit parameter is flagged, calculate an appropriate limit
    // based on the air absorption parameter.
    hfRatio = Slot->effect.Reverb.DecayHFRatio;
    if(Slot->effect.Reverb.DecayHFLimit &&
       Slot->effect.Reverb.AirAbsorptionGainHF < 1.0f)
        hfRatio = CalcLimitedHfRatio(hfRatio,
                                     Slot->effect.Reverb.AirAbsorptionGainHF,
                                     Slot->effect.Reverb.DecayTime);

    // Update the late lines.
    UpdateLateLines(Slot->effect.Reverb.Gain, Slot->effect.Reverb.LateReverbGain,
                    x, Slot->effect.Reverb.Density, Slot->effect.Reverb.DecayTime,
                    Slot->effect.Reverb.Diffusion, hfRatio, cw, frequency, State);

    if(isEAX)
    {
        // Update the echo line.
        UpdateEchoLine(Slot->effect.Reverb.Gain, Slot->effect.Reverb.LateReverbGain,
                       Slot->effect.Reverb.EchoTime, Slot->effect.Reverb.DecayTime,
                       Slot->effect.Reverb.Diffusion, Slot->effect.Reverb.EchoDepth,
                       hfRatio, cw, frequency, State);

        // Update early and late 3D panning.
        Update3DPanning(Context->Device, Slot->effect.Reverb.ReflectionsPan,
                        Slot->effect.Reverb.LateReverbPan, Slot->Gain, State);
    }
    else
    {
        ALCdevice *Device = Context->Device;
        ALfloat gain = Slot->Gain;
        ALuint index;

        /* Update channel gains */
        gain *= aluSqrt(2.0f/Device->NumChan) * ReverbBoost;
        for(index = 0;index < MAXCHANNELS;index++)
             State->Gain[index] = 0.0f;
        for(index = 0;index < Device->NumChan;index++)
        {
            enum Channel chan = Device->Speaker2Chan[index];
            State->Gain[chan] = gain;
        }
    }
}

// This destroys the reverb state.  It should be called only when the effect
// slot has a different (or no) effect loaded over the reverb effect.
static ALvoid ReverbDestroy(ALeffectState *effect)
{
    ALverbState *State = (ALverbState*)effect;
    if(State)
    {
        free(State->SampleBuffer);
        State->SampleBuffer = NULL;
        free(State);
    }
}

// This creates the reverb state.  It should be called only when the reverb
// effect is loaded into a slot that doesn't already have a reverb effect.
ALeffectState *ReverbCreate(void)
{
    ALverbState *State = NULL;
    ALuint index;

    State = malloc(sizeof(ALverbState));
    if(!State)
        return NULL;

    State->state.Destroy = ReverbDestroy;
    State->state.DeviceUpdate = ReverbDeviceUpdate;
    State->state.Update = ReverbUpdate;
    State->state.Process = VerbProcess;

    State->TotalSamples = 0;
    State->SampleBuffer = NULL;

    State->LpFilter.coeff = 0.0f;
    State->LpFilter.history[0] = 0.0f;
    State->LpFilter.history[1] = 0.0f;

    State->Mod.Delay.Mask = 0;
    State->Mod.Delay.Line = NULL;
    State->Mod.Index = 0;
    State->Mod.Range = 1;
    State->Mod.Depth = 0.0f;
    State->Mod.Coeff = 0.0f;
    State->Mod.Filter = 0.0f;

    State->Delay.Mask = 0;
    State->Delay.Line = NULL;
    State->DelayTap[0] = 0;
    State->DelayTap[1] = 0;

    State->Early.Gain = 0.0f;
    for(index = 0;index < 4;index++)
    {
        State->Early.Coeff[index] = 0.0f;
        State->Early.Delay[index].Mask = 0;
        State->Early.Delay[index].Line = NULL;
        State->Early.Offset[index] = 0;
    }

    State->Decorrelator.Mask = 0;
    State->Decorrelator.Line = NULL;
    State->DecoTap[0] = 0;
    State->DecoTap[1] = 0;
    State->DecoTap[2] = 0;

    State->Late.Gain = 0.0f;
    State->Late.DensityGain = 0.0f;
    State->Late.ApFeedCoeff = 0.0f;
    State->Late.MixCoeff = 0.0f;
    for(index = 0;index < 4;index++)
    {
        State->Late.ApCoeff[index] = 0.0f;
        State->Late.ApDelay[index].Mask = 0;
        State->Late.ApDelay[index].Line = NULL;
        State->Late.ApOffset[index] = 0;

        State->Late.Coeff[index] = 0.0f;
        State->Late.Delay[index].Mask = 0;
        State->Late.Delay[index].Line = NULL;
        State->Late.Offset[index] = 0;

        State->Late.LpCoeff[index] = 0.0f;
        State->Late.LpSample[index] = 0.0f;
    }

    for(index = 0;index < MAXCHANNELS;index++)
    {
        State->Early.PanGain[index] = 0.0f;
        State->Late.PanGain[index] = 0.0f;
    }

    State->Echo.DensityGain = 0.0f;
    State->Echo.Delay.Mask = 0;
    State->Echo.Delay.Line = NULL;
    State->Echo.ApDelay.Mask = 0;
    State->Echo.ApDelay.Line = NULL;
    State->Echo.Coeff = 0.0f;
    State->Echo.ApFeedCoeff = 0.0f;
    State->Echo.ApCoeff = 0.0f;
    State->Echo.Offset = 0;
    State->Echo.ApOffset = 0;
    State->Echo.LpCoeff = 0.0f;
    State->Echo.LpSample = 0.0f;
    State->Echo.MixCoeff[0] = 0.0f;
    State->Echo.MixCoeff[1] = 0.0f;

    State->Offset = 0;

    State->Gain = State->Late.PanGain;

    return &State->state;
}
