/**
 * OpenAL cross platform audio library
 * Copyright (C) 1999-2007 by authors.
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

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "alMain.h"
#include "AL/al.h"
#include "AL/alc.h"
#include "alSource.h"
#include "alBuffer.h"
#include "alListener.h"
#include "alAuxEffectSlot.h"
#include "alu.h"
#include "bs2b.h"


static __inline ALfloat point32(const ALfloat *vals, ALint step, ALint frac)
{ return vals[0]; (void)step; (void)frac; }
static __inline ALfloat lerp32(const ALfloat *vals, ALint step, ALint frac)
{ return lerp(vals[0], vals[step], frac * (1.0f/FRACTIONONE)); }
static __inline ALfloat cubic32(const ALfloat *vals, ALint step, ALint frac)
{ return cubic(vals[-step], vals[0], vals[step], vals[step+step],
               frac * (1.0f/FRACTIONONE)); }

#ifdef __GNUC__
#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif

#if defined(__ARM_NEON__) && defined(HAVE_ARM_NEON_H)
#include <arm_neon.h>

static __inline void ApplyCoeffs(ALuint Offset, ALfloat (*RESTRICT Values)[2],
                                 ALfloat (*RESTRICT Coeffs)[2],
                                 ALfloat left, ALfloat right)
{
    ALuint c;
    float32x4_t leftright4;
    {
        float32x2_t leftright2 = vdup_n_f32(0.0);
        leftright2 = vset_lane_f32(left, leftright2, 0);
        leftright2 = vset_lane_f32(right, leftright2, 1);
        leftright4 = vcombine_f32(leftright2, leftright2);
    }
    for(c = 0;c < HRIR_LENGTH;c += 2)
    {
        const ALuint o0 = (Offset+c)&HRIR_MASK;
        const ALuint o1 = (o0+1)&HRIR_MASK;
        float32x4_t vals = vcombine_f32(vld1_f32((float32_t*)&Values[o0][0]),
                                        vld1_f32((float32_t*)&Values[o1][0]));
        float32x4_t coefs = vld1q_f32((float32_t*)&Coeffs[c][0]);

        vals = vmlaq_f32(vals, coefs, leftright4);

        vst1_f32((float32_t*)&Values[o0][0], vget_low_f32(vals));
        vst1_f32((float32_t*)&Values[o1][0], vget_high_f32(vals));
    }
}

#else

static __inline void ApplyCoeffs(ALuint Offset, ALfloat (*RESTRICT Values)[2],
                                 ALfloat (*RESTRICT Coeffs)[2],
                                 ALfloat left, ALfloat right)
{
    ALuint c;
    for(c = 0;c < HRIR_LENGTH;c++)
    {
        const ALuint off = (Offset+c)&HRIR_MASK;
        Values[off][0] += Coeffs[c][0] * left;
        Values[off][1] += Coeffs[c][1] * right;
    }
}

#endif

#define DECL_TEMPLATE(T, sampler)                                             \
static void Mix_Hrtf_##T##_##sampler(ALsource *Source, ALCdevice *Device,     \
  const ALvoid *srcdata, ALuint *DataPosInt, ALuint *DataPosFrac,             \
  ALuint OutPos, ALuint SamplesToDo, ALuint BufferSize)                       \
{                                                                             \
    const ALuint NumChannels = Source->NumChannels;                           \
    const T *RESTRICT data = srcdata;                                         \
    const ALint *RESTRICT DelayStep = Source->Params.HrtfDelayStep;           \
    ALfloat (*RESTRICT DryBuffer)[MAXCHANNELS];                               \
    ALfloat *RESTRICT ClickRemoval, *RESTRICT PendingClicks;                  \
    ALfloat (*RESTRICT CoeffStep)[2] = Source->Params.HrtfCoeffStep;          \
    ALuint pos, frac;                                                         \
    FILTER *DryFilter;                                                        \
    ALuint BufferIdx;                                                         \
    ALuint increment;                                                         \
    ALuint i, out, c;                                                         \
    ALfloat value;                                                            \
                                                                              \
    increment = Source->Params.Step;                                          \
                                                                              \
    DryBuffer = Device->DryBuffer;                                            \
    ClickRemoval = Device->ClickRemoval;                                      \
    PendingClicks = Device->PendingClicks;                                    \
    DryFilter = &Source->Params.iirFilter;                                    \
                                                                              \
    pos = 0;                                                                  \
    frac = *DataPosFrac;                                                      \
                                                                              \
    for(i = 0;i < NumChannels;i++)                                            \
    {                                                                         \
        ALfloat (*RESTRICT TargetCoeffs)[2] = Source->Params.HrtfCoeffs[i];   \
        ALuint *RESTRICT TargetDelay = Source->Params.HrtfDelay[i];           \
        ALfloat *RESTRICT History = Source->HrtfHistory[i];                   \
        ALfloat (*RESTRICT Values)[2] = Source->HrtfValues[i];                \
        ALint Counter = maxu(Source->HrtfCounter, OutPos) - OutPos;           \
        ALuint Offset = Source->HrtfOffset + OutPos;                          \
        ALfloat Coeffs[HRIR_LENGTH][2];                                       \
        ALuint Delay[2];                                                      \
        ALfloat left, right;                                                  \
                                                                              \
        pos = 0;                                                              \
        frac = *DataPosFrac;                                                  \
                                                                              \
        for(c = 0;c < HRIR_LENGTH;c++)                                        \
        {                                                                     \
            Coeffs[c][0] = TargetCoeffs[c][0] - (CoeffStep[c][0]*Counter);    \
            Coeffs[c][1] = TargetCoeffs[c][1] - (CoeffStep[c][1]*Counter);    \
        }                                                                     \
                                                                              \
        Delay[0] = TargetDelay[0] - (DelayStep[0]*Counter) + 32768;           \
        Delay[1] = TargetDelay[1] - (DelayStep[1]*Counter) + 32768;           \
                                                                              \
        if(LIKELY(OutPos == 0))                                               \
        {                                                                     \
            value = sampler(data + pos*NumChannels + i, NumChannels, frac);   \
            value = lpFilter2PC(DryFilter, i, value);                         \
                                                                              \
            History[Offset&SRC_HISTORY_MASK] = value;                         \
            left = History[(Offset-(Delay[0]>>16))&SRC_HISTORY_MASK];         \
            right = History[(Offset-(Delay[1]>>16))&SRC_HISTORY_MASK];        \
                                                                              \
            ClickRemoval[FRONT_LEFT]  -= Values[(Offset+1)&HRIR_MASK][0] +    \
                                         Coeffs[0][0] * left;                 \
            ClickRemoval[FRONT_RIGHT] -= Values[(Offset+1)&HRIR_MASK][1] +    \
                                         Coeffs[0][1] * right;                \
        }                                                                     \
        for(BufferIdx = 0;BufferIdx < BufferSize && Counter > 0;BufferIdx++)  \
        {                                                                     \
            value = sampler(data + pos*NumChannels + i, NumChannels, frac);   \
            value = lpFilter2P(DryFilter, i, value);                          \
                                                                              \
            History[Offset&SRC_HISTORY_MASK] = value;                         \
            left = History[(Offset-(Delay[0]>>16))&SRC_HISTORY_MASK];         \
            right = History[(Offset-(Delay[1]>>16))&SRC_HISTORY_MASK];        \
                                                                              \
            Delay[0] += DelayStep[0];                                         \
            Delay[1] += DelayStep[1];                                         \
                                                                              \
            Values[Offset&HRIR_MASK][0] = 0.0f;                               \
            Values[Offset&HRIR_MASK][1] = 0.0f;                               \
            Offset++;                                                         \
                                                                              \
            for(c = 0;c < HRIR_LENGTH;c++)                                    \
            {                                                                 \
                const ALuint off = (Offset+c)&HRIR_MASK;                      \
                Values[off][0] += Coeffs[c][0] * left;                        \
                Values[off][1] += Coeffs[c][1] * right;                       \
                Coeffs[c][0] += CoeffStep[c][0];                              \
                Coeffs[c][1] += CoeffStep[c][1];                              \
            }                                                                 \
                                                                              \
            DryBuffer[OutPos][FRONT_LEFT]  += Values[Offset&HRIR_MASK][0];    \
            DryBuffer[OutPos][FRONT_RIGHT] += Values[Offset&HRIR_MASK][1];    \
                                                                              \
            frac += increment;                                                \
            pos  += frac>>FRACTIONBITS;                                       \
            frac &= FRACTIONMASK;                                             \
            OutPos++;                                                         \
            Counter--;                                                        \
        }                                                                     \
                                                                              \
        Delay[0] >>= 16;                                                      \
        Delay[1] >>= 16;                                                      \
        for(;BufferIdx < BufferSize;BufferIdx++)                              \
        {                                                                     \
            value = sampler(data + pos*NumChannels + i, NumChannels, frac);   \
            value = lpFilter2P(DryFilter, i, value);                          \
                                                                              \
            History[Offset&SRC_HISTORY_MASK] = value;                         \
            left = History[(Offset-Delay[0])&SRC_HISTORY_MASK];               \
            right = History[(Offset-Delay[1])&SRC_HISTORY_MASK];              \
                                                                              \
            Values[Offset&HRIR_MASK][0] = 0.0f;                               \
            Values[Offset&HRIR_MASK][1] = 0.0f;                               \
            Offset++;                                                         \
                                                                              \
            ApplyCoeffs(Offset, Values, Coeffs, left, right);                 \
            DryBuffer[OutPos][FRONT_LEFT]  += Values[Offset&HRIR_MASK][0];    \
            DryBuffer[OutPos][FRONT_RIGHT] += Values[Offset&HRIR_MASK][1];    \
                                                                              \
            frac += increment;                                                \
            pos  += frac>>FRACTIONBITS;                                       \
            frac &= FRACTIONMASK;                                             \
            OutPos++;                                                         \
        }                                                                     \
        if(LIKELY(OutPos == SamplesToDo))                                     \
        {                                                                     \
            value = sampler(data + pos*NumChannels + i, NumChannels, frac);   \
            value = lpFilter2PC(DryFilter, i, value);                         \
                                                                              \
            History[Offset&SRC_HISTORY_MASK] = value;                         \
            left = History[(Offset-Delay[0])&SRC_HISTORY_MASK];               \
            right = History[(Offset-Delay[1])&SRC_HISTORY_MASK];              \
                                                                              \
            PendingClicks[FRONT_LEFT]  += Values[(Offset+1)&HRIR_MASK][0] +   \
                                          Coeffs[0][0] * left;                \
            PendingClicks[FRONT_RIGHT] += Values[(Offset+1)&HRIR_MASK][1] +   \
                                          Coeffs[0][1] * right;               \
        }                                                                     \
        OutPos -= BufferSize;                                                 \
    }                                                                         \
                                                                              \
    for(out = 0;out < Device->NumAuxSends;out++)                              \
    {                                                                         \
        ALeffectslot *Slot = Source->Params.Send[out].Slot;                   \
        ALfloat  WetSend;                                                     \
        ALfloat *RESTRICT WetBuffer;                                          \
        ALfloat *RESTRICT WetClickRemoval;                                    \
        ALfloat *RESTRICT WetPendingClicks;                                   \
        FILTER  *WetFilter;                                                   \
                                                                              \
        if(Slot == NULL)                                                      \
            continue;                                                         \
                                                                              \
        WetBuffer = Slot->WetBuffer;                                          \
        WetClickRemoval = Slot->ClickRemoval;                                 \
        WetPendingClicks = Slot->PendingClicks;                               \
        WetFilter = &Source->Params.Send[out].iirFilter;                      \
        WetSend = Source->Params.Send[out].WetGain;                           \
                                                                              \
        for(i = 0;i < NumChannels;i++)                                        \
        {                                                                     \
            pos = 0;                                                          \
            frac = *DataPosFrac;                                              \
                                                                              \
            if(LIKELY(OutPos == 0))                                           \
            {                                                                 \
                value = sampler(data + pos*NumChannels + i, NumChannels,frac);\
                value = lpFilter1PC(WetFilter, i, value);                     \
                                                                              \
                WetClickRemoval[0] -= value * WetSend;                        \
            }                                                                 \
            for(BufferIdx = 0;BufferIdx < BufferSize;BufferIdx++)             \
            {                                                                 \
                value = sampler(data + pos*NumChannels + i, NumChannels,frac);\
                value = lpFilter1P(WetFilter, i, value);                      \
                                                                              \
                WetBuffer[OutPos] += value * WetSend;                         \
                                                                              \
                frac += increment;                                            \
                pos  += frac>>FRACTIONBITS;                                   \
                frac &= FRACTIONMASK;                                         \
                OutPos++;                                                     \
            }                                                                 \
            if(LIKELY(OutPos == SamplesToDo))                                 \
            {                                                                 \
                value = sampler(data + pos*NumChannels + i, NumChannels,frac);\
                value = lpFilter1PC(WetFilter, i, value);                     \
                                                                              \
                WetPendingClicks[0] += value * WetSend;                       \
            }                                                                 \
            OutPos -= BufferSize;                                             \
        }                                                                     \
    }                                                                         \
    *DataPosInt += pos;                                                       \
    *DataPosFrac = frac;                                                      \
}

DECL_TEMPLATE(ALfloat, point32)
DECL_TEMPLATE(ALfloat, lerp32)
DECL_TEMPLATE(ALfloat, cubic32)

#undef DECL_TEMPLATE


#define DECL_TEMPLATE(T, sampler)                                             \
static void Mix_##T##_##sampler(ALsource *Source, ALCdevice *Device,          \
  const ALvoid *srcdata, ALuint *DataPosInt, ALuint *DataPosFrac,             \
  ALuint OutPos, ALuint SamplesToDo, ALuint BufferSize)                       \
{                                                                             \
    const ALuint NumChannels = Source->NumChannels;                           \
    const T *RESTRICT data = srcdata;                                         \
    ALfloat (*RESTRICT DryBuffer)[MAXCHANNELS];                               \
    ALfloat *RESTRICT ClickRemoval, *RESTRICT PendingClicks;                  \
    ALfloat DrySend[MAXCHANNELS];                                             \
    FILTER *DryFilter;                                                        \
    ALuint pos, frac;                                                         \
    ALuint BufferIdx;                                                         \
    ALuint increment;                                                         \
    ALuint i, out, c;                                                         \
    ALfloat value;                                                            \
                                                                              \
    increment = Source->Params.Step;                                          \
                                                                              \
    DryBuffer = Device->DryBuffer;                                            \
    ClickRemoval = Device->ClickRemoval;                                      \
    PendingClicks = Device->PendingClicks;                                    \
    DryFilter = &Source->Params.iirFilter;                                    \
                                                                              \
    pos = 0;                                                                  \
    frac = *DataPosFrac;                                                      \
                                                                              \
    for(i = 0;i < NumChannels;i++)                                            \
    {                                                                         \
        for(c = 0;c < MAXCHANNELS;c++)                                        \
            DrySend[c] = Source->Params.DryGains[i][c];                       \
                                                                              \
        pos = 0;                                                              \
        frac = *DataPosFrac;                                                  \
                                                                              \
        if(OutPos == 0)                                                       \
        {                                                                     \
            value = sampler(data + pos*NumChannels + i, NumChannels, frac);   \
                                                                              \
            value = lpFilter2PC(DryFilter, i, value);                         \
            for(c = 0;c < MAXCHANNELS;c++)                                    \
                ClickRemoval[c] -= value*DrySend[c];                          \
        }                                                                     \
        for(BufferIdx = 0;BufferIdx < BufferSize;BufferIdx++)                 \
        {                                                                     \
            value = sampler(data + pos*NumChannels + i, NumChannels, frac);   \
                                                                              \
            value = lpFilter2P(DryFilter, i, value);                          \
            for(c = 0;c < MAXCHANNELS;c++)                                    \
                DryBuffer[OutPos][c] += value*DrySend[c];                     \
                                                                              \
            frac += increment;                                                \
            pos  += frac>>FRACTIONBITS;                                       \
            frac &= FRACTIONMASK;                                             \
            OutPos++;                                                         \
        }                                                                     \
        if(OutPos == SamplesToDo)                                             \
        {                                                                     \
            value = sampler(data + pos*NumChannels + i, NumChannels, frac);   \
                                                                              \
            value = lpFilter2PC(DryFilter, i, value);                         \
            for(c = 0;c < MAXCHANNELS;c++)                                    \
                PendingClicks[c] += value*DrySend[c];                         \
        }                                                                     \
        OutPos -= BufferSize;                                                 \
    }                                                                         \
                                                                              \
    for(out = 0;out < Device->NumAuxSends;out++)                              \
    {                                                                         \
        ALeffectslot *Slot = Source->Params.Send[out].Slot;                   \
        ALfloat  WetSend;                                                     \
        ALfloat *WetBuffer;                                                   \
        ALfloat *WetClickRemoval;                                             \
        ALfloat *WetPendingClicks;                                            \
        FILTER  *WetFilter;                                                   \
                                                                              \
        if(Slot == NULL)                                                      \
            continue;                                                         \
                                                                              \
        WetBuffer = Slot->WetBuffer;                                          \
        WetClickRemoval = Slot->ClickRemoval;                                 \
        WetPendingClicks = Slot->PendingClicks;                               \
        WetFilter = &Source->Params.Send[out].iirFilter;                      \
        WetSend = Source->Params.Send[out].WetGain;                           \
                                                                              \
        for(i = 0;i < NumChannels;i++)                                        \
        {                                                                     \
            pos = 0;                                                          \
            frac = *DataPosFrac;                                              \
                                                                              \
            if(OutPos == 0)                                                   \
            {                                                                 \
                value = sampler(data + pos*NumChannels + i, NumChannels,frac);\
                                                                              \
                value = lpFilter1PC(WetFilter, i, value);                     \
                WetClickRemoval[0] -= value * WetSend;                        \
            }                                                                 \
            for(BufferIdx = 0;BufferIdx < BufferSize;BufferIdx++)             \
            {                                                                 \
                value = sampler(data + pos*NumChannels + i, NumChannels,frac);\
                                                                              \
                value = lpFilter1P(WetFilter, i, value);                      \
                WetBuffer[OutPos] += value * WetSend;                         \
                                                                              \
                frac += increment;                                            \
                pos  += frac>>FRACTIONBITS;                                   \
                frac &= FRACTIONMASK;                                         \
                OutPos++;                                                     \
            }                                                                 \
            if(OutPos == SamplesToDo)                                         \
            {                                                                 \
                value = sampler(data + pos*NumChannels + i, NumChannels,frac);\
                                                                              \
                value = lpFilter1PC(WetFilter, i, value);                     \
                WetPendingClicks[0] += value * WetSend;                       \
            }                                                                 \
            OutPos -= BufferSize;                                             \
        }                                                                     \
    }                                                                         \
    *DataPosInt += pos;                                                       \
    *DataPosFrac = frac;                                                      \
}

DECL_TEMPLATE(ALfloat, point32)
DECL_TEMPLATE(ALfloat, lerp32)
DECL_TEMPLATE(ALfloat, cubic32)

#undef DECL_TEMPLATE


MixerFunc SelectMixer(enum Resampler Resampler)
{
    switch(Resampler)
    {
        case POINT_RESAMPLER:
            return Mix_ALfloat_point32;
        case LINEAR_RESAMPLER:
            return Mix_ALfloat_lerp32;
        case CUBIC_RESAMPLER:
            return Mix_ALfloat_cubic32;
        case RESAMPLER_MIN:
        case RESAMPLER_MAX:
            break;
    }
    return NULL;
}

MixerFunc SelectHrtfMixer(enum Resampler Resampler)
{
    switch(Resampler)
    {
        case POINT_RESAMPLER:
            return Mix_Hrtf_ALfloat_point32;
        case LINEAR_RESAMPLER:
            return Mix_Hrtf_ALfloat_lerp32;
        case CUBIC_RESAMPLER:
            return Mix_Hrtf_ALfloat_cubic32;
        case RESAMPLER_MIN:
        case RESAMPLER_MAX:
            break;
    }
    return NULL;
}


static __inline ALfloat Sample_ALbyte(ALbyte val)
{ return val * (1.0f/127.0f); }

static __inline ALfloat Sample_ALshort(ALshort val)
{ return val * (1.0f/32767.0f); }

static __inline ALfloat Sample_ALfloat(ALfloat val)
{ return val; }

#define DECL_TEMPLATE(T)                                                      \
static void Load_##T(ALfloat *dst, const T *src, ALuint samples)              \
{                                                                             \
    ALuint i;                                                                 \
    for(i = 0;i < samples;i++)                                                \
        dst[i] = Sample_##T(src[i]);                                          \
}

DECL_TEMPLATE(ALbyte)
DECL_TEMPLATE(ALshort)
DECL_TEMPLATE(ALfloat)

#undef DECL_TEMPLATE

static void LoadStack(ALfloat *dst, const ALvoid *src, enum FmtType srctype, ALuint samples)
{
    switch(srctype)
    {
        case FmtByte:
            Load_ALbyte(dst, src, samples);
            break;
        case FmtShort:
            Load_ALshort(dst, src, samples);
            break;
        case FmtFloat:
            Load_ALfloat(dst, src, samples);
            break;
    }
}

static void SilenceStack(ALfloat *dst, ALuint samples)
{
    ALuint i;
    for(i = 0;i < samples;i++)
        dst[i] = 0.0f;
}


ALvoid MixSource(ALsource *Source, ALCdevice *Device, ALuint SamplesToDo)
{
    ALbufferlistitem *BufferListItem;
    ALuint DataPosInt, DataPosFrac;
    ALuint BuffersPlayed;
    ALboolean Looping;
    ALuint increment;
    enum Resampler Resampler;
    ALenum State;
    ALuint OutPos;
    ALuint NumChannels;
    ALuint FrameSize;
    ALint64 DataSize64;
    ALuint i;

    /* Get source info */
    State         = Source->state;
    BuffersPlayed = Source->BuffersPlayed;
    DataPosInt    = Source->position;
    DataPosFrac   = Source->position_fraction;
    Looping       = Source->bLooping;
    increment     = Source->Params.Step;
    Resampler     = Source->Resampler;
    NumChannels   = Source->NumChannels;
    FrameSize     = NumChannels * Source->SampleSize;

    /* Get current buffer queue item */
    BufferListItem = Source->queue;
    for(i = 0;i < BuffersPlayed;i++)
        BufferListItem = BufferListItem->next;

    OutPos = 0;
    do {
        const ALuint BufferPrePadding = ResamplerPrePadding[Resampler];
        const ALuint BufferPadding = ResamplerPadding[Resampler];
        ALfloat StackData[STACK_DATA_SIZE/sizeof(ALfloat)];
        ALfloat *SrcData = StackData;
        ALuint SrcDataSize = 0;
        ALuint BufferSize;

        /* Figure out how many buffer bytes will be needed */
        DataSize64  = SamplesToDo-OutPos+1;
        DataSize64 *= increment;
        DataSize64 += DataPosFrac+FRACTIONMASK;
        DataSize64 >>= FRACTIONBITS;
        DataSize64 += BufferPadding+BufferPrePadding;
        DataSize64 *= NumChannels;

        BufferSize  = (ALuint)mini64(DataSize64, STACK_DATA_SIZE/sizeof(ALfloat));
        BufferSize /= NumChannels;

        if(Source->lSourceType == AL_STATIC)
        {
            const ALbuffer *ALBuffer = Source->queue->buffer;
            const ALubyte *Data = ALBuffer->data;
            ALuint DataSize;
            ALuint pos;

            /* If current pos is beyond the loop range, do not loop */
            if(Looping == AL_FALSE || DataPosInt >= (ALuint)ALBuffer->LoopEnd)
            {
                Looping = AL_FALSE;

                if(DataPosInt >= BufferPrePadding)
                    pos = DataPosInt - BufferPrePadding;
                else
                {
                    DataSize = BufferPrePadding - DataPosInt;
                    DataSize = minu(BufferSize, DataSize);

                    SilenceStack(&SrcData[SrcDataSize*NumChannels],
                                 DataSize*NumChannels);
                    SrcDataSize += DataSize;
                    BufferSize -= DataSize;

                    pos = 0;
                }

                /* Copy what's left to play in the source buffer, and clear the
                 * rest of the temp buffer */
                DataSize = ALBuffer->SampleLen - pos;
                DataSize = minu(BufferSize, DataSize);

                LoadStack(&SrcData[SrcDataSize*NumChannels], &Data[pos*FrameSize],
                          ALBuffer->FmtType, DataSize*NumChannels);
                SrcDataSize += DataSize;
                BufferSize -= DataSize;

                SilenceStack(&SrcData[SrcDataSize*NumChannels],
                             BufferSize*NumChannels);
                SrcDataSize += BufferSize;
                BufferSize -= BufferSize;
            }
            else
            {
                ALuint LoopStart = ALBuffer->LoopStart;
                ALuint LoopEnd   = ALBuffer->LoopEnd;

                if(DataPosInt >= LoopStart)
                {
                    pos = DataPosInt-LoopStart;
                    while(pos < BufferPrePadding)
                        pos += LoopEnd-LoopStart;
                    pos -= BufferPrePadding;
                    pos += LoopStart;
                }
                else if(DataPosInt >= BufferPrePadding)
                    pos = DataPosInt - BufferPrePadding;
                else
                {
                    DataSize = BufferPrePadding - DataPosInt;
                    DataSize = minu(BufferSize, DataSize);

                    SilenceStack(&SrcData[SrcDataSize*NumChannels], DataSize*NumChannels);
                    SrcDataSize += DataSize;
                    BufferSize -= DataSize;

                    pos = 0;
                }

                /* Copy what's left of this loop iteration, then copy repeats
                 * of the loop section */
                DataSize = LoopEnd - pos;
                DataSize = minu(BufferSize, DataSize);

                LoadStack(&SrcData[SrcDataSize*NumChannels], &Data[pos*FrameSize],
                          ALBuffer->FmtType, DataSize*NumChannels);
                SrcDataSize += DataSize;
                BufferSize -= DataSize;

                DataSize = LoopEnd-LoopStart;
                while(BufferSize > 0)
                {
                    DataSize = minu(BufferSize, DataSize);

                    LoadStack(&SrcData[SrcDataSize*NumChannels], &Data[LoopStart*FrameSize],
                              ALBuffer->FmtType, DataSize*NumChannels);
                    SrcDataSize += DataSize;
                    BufferSize -= DataSize;
                }
            }
        }
        else
        {
            /* Crawl the buffer queue to fill in the temp buffer */
            ALbufferlistitem *tmpiter = BufferListItem;
            ALuint pos;

            if(DataPosInt >= BufferPrePadding)
                pos = DataPosInt - BufferPrePadding;
            else
            {
                pos = BufferPrePadding - DataPosInt;
                while(pos > 0)
                {
                    if(!tmpiter->prev && !Looping)
                    {
                        ALuint DataSize = minu(BufferSize, pos);

                        SilenceStack(&SrcData[SrcDataSize*NumChannels], DataSize*NumChannels);
                        SrcDataSize += DataSize;
                        BufferSize -= DataSize;

                        pos = 0;
                        break;
                    }

                    if(tmpiter->prev)
                        tmpiter = tmpiter->prev;
                    else
                    {
                        while(tmpiter->next)
                            tmpiter = tmpiter->next;
                    }

                    if(tmpiter->buffer)
                    {
                        if((ALuint)tmpiter->buffer->SampleLen > pos)
                        {
                            pos = tmpiter->buffer->SampleLen - pos;
                            break;
                        }
                        pos -= tmpiter->buffer->SampleLen;
                    }
                }
            }

            while(tmpiter && BufferSize > 0)
            {
                const ALbuffer *ALBuffer;
                if((ALBuffer=tmpiter->buffer) != NULL)
                {
                    const ALubyte *Data = ALBuffer->data;
                    ALuint DataSize = ALBuffer->SampleLen;

                    /* Skip the data already played */
                    if(DataSize <= pos)
                        pos -= DataSize;
                    else
                    {
                        Data += pos*FrameSize;
                        DataSize -= pos;
                        pos -= pos;

                        DataSize = minu(BufferSize, DataSize);
                        LoadStack(&SrcData[SrcDataSize*NumChannels], Data,
                                  ALBuffer->FmtType, DataSize*NumChannels);
                        SrcDataSize += DataSize;
                        BufferSize -= DataSize;
                    }
                }
                tmpiter = tmpiter->next;
                if(!tmpiter && Looping)
                    tmpiter = Source->queue;
                else if(!tmpiter)
                {
                    SilenceStack(&SrcData[SrcDataSize*NumChannels], BufferSize*NumChannels);
                    SrcDataSize += BufferSize;
                    BufferSize -= BufferSize;
                }
            }
        }

        /* Figure out how many samples we can mix. */
        DataSize64  = SrcDataSize;
        DataSize64 -= BufferPadding+BufferPrePadding;
        DataSize64 <<= FRACTIONBITS;
        DataSize64 -= increment;
        DataSize64 -= DataPosFrac;

        BufferSize = (ALuint)((DataSize64+(increment-1)) / increment);
        BufferSize = minu(BufferSize, (SamplesToDo-OutPos));

        SrcData += BufferPrePadding*NumChannels;
        Source->Params.DoMix(Source, Device, SrcData, &DataPosInt, &DataPosFrac,
                             OutPos, SamplesToDo, BufferSize);
        OutPos += BufferSize;

        /* Handle looping sources */
        while(1)
        {
            const ALbuffer *ALBuffer;
            ALuint DataSize = 0;
            ALuint LoopStart = 0;
            ALuint LoopEnd = 0;

            if((ALBuffer=BufferListItem->buffer) != NULL)
            {
                DataSize = ALBuffer->SampleLen;
                LoopStart = ALBuffer->LoopStart;
                LoopEnd = ALBuffer->LoopEnd;
                if(LoopEnd > DataPosInt)
                    break;
            }

            if(Looping && Source->lSourceType == AL_STATIC)
            {
                DataPosInt = ((DataPosInt-LoopStart)%(LoopEnd-LoopStart)) + LoopStart;
                break;
            }

            if(DataSize > DataPosInt)
                break;

            if(BufferListItem->next)
            {
                BufferListItem = BufferListItem->next;
                BuffersPlayed++;
            }
            else if(Looping)
            {
                BufferListItem = Source->queue;
                BuffersPlayed = 0;
            }
            else
            {
                State = AL_STOPPED;
                BufferListItem = Source->queue;
                BuffersPlayed = Source->BuffersInQueue;
                DataPosInt = 0;
                DataPosFrac = 0;
                break;
            }

            DataPosInt -= DataSize;
        }
    } while(State == AL_PLAYING && OutPos < SamplesToDo);

    /* Update source info */
    Source->state             = State;
    Source->BuffersPlayed     = BuffersPlayed;
    Source->position          = DataPosInt;
    Source->position_fraction = DataPosFrac;
    Source->HrtfOffset       += OutPos;
    if(State == AL_PLAYING)
    {
        Source->HrtfCounter = maxu(Source->HrtfCounter, OutPos) - OutPos;
        Source->HrtfMoving  = AL_TRUE;
    }
    else
    {
        Source->HrtfCounter = 0;
        Source->HrtfMoving  = AL_FALSE;
    }
}
