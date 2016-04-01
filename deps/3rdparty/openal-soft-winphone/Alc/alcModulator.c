/**
 * OpenAL cross platform audio library
 * Copyright (C) 2009 by Chris Robinson.
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

#include "alMain.h"
#include "alFilter.h"
#include "alAuxEffectSlot.h"
#include "alError.h"
#include "alu.h"


typedef struct ALmodulatorState {
    // Must be first in all effects!
    ALeffectState state;

    enum {
        SINUSOID,
        SAWTOOTH,
        SQUARE
    } Waveform;

    ALuint index;
    ALuint step;

    ALfloat Gain[MAXCHANNELS];

    FILTER iirFilter;
    ALfloat history[1];
} ALmodulatorState;

#define WAVEFORM_FRACBITS  16
#define WAVEFORM_FRACONE   (1<<WAVEFORM_FRACBITS)
#define WAVEFORM_FRACMASK  (WAVEFORM_FRACONE-1)

static __inline ALfloat Sin(ALuint index)
{
    return aluSin(index * (F_PI*2.0f / WAVEFORM_FRACONE));
}

static __inline ALfloat Saw(ALuint index)
{
    return index*(2.0f/WAVEFORM_FRACONE) - 1.0f;
}

static __inline ALfloat Square(ALuint index)
{
    return ((index>>(WAVEFORM_FRACBITS-1))&1)*2.0f - 1.0f;
}


static __inline ALfloat hpFilter1P(FILTER *iir, ALuint offset, ALfloat input)
{
    ALfloat *history = &iir->history[offset];
    ALfloat a = iir->coeff;
    ALfloat output = input;

    output = output + (history[0]-output)*a;
    history[0] = output;

    return input - output;
}


#define DECL_TEMPLATE(func)                                                   \
static void Process##func(ALmodulatorState *state, ALuint SamplesToDo,        \
  const ALfloat *SamplesIn, ALfloat (*SamplesOut)[MAXCHANNELS])               \
{                                                                             \
    const ALuint step = state->step;                                          \
    ALuint index = state->index;                                              \
    ALfloat samp;                                                             \
    ALuint i, k;                                                              \
                                                                              \
    for(i = 0;i < SamplesToDo;i++)                                            \
    {                                                                         \
        samp = SamplesIn[i];                                                  \
                                                                              \
        index += step;                                                        \
        index &= WAVEFORM_FRACMASK;                                           \
        samp *= func(index);                                                  \
                                                                              \
        samp = hpFilter1P(&state->iirFilter, 0, samp);                        \
                                                                              \
        for(k = 0;k < MAXCHANNELS;k++)                                        \
            SamplesOut[i][k] += state->Gain[k] * samp;                        \
    }                                                                         \
    state->index = index;                                                     \
}

DECL_TEMPLATE(Sin)
DECL_TEMPLATE(Saw)
DECL_TEMPLATE(Square)

#undef DECL_TEMPLATE


static ALvoid ModulatorDestroy(ALeffectState *effect)
{
    ALmodulatorState *state = (ALmodulatorState*)effect;
    free(state);
}

static ALboolean ModulatorDeviceUpdate(ALeffectState *effect, ALCdevice *Device)
{
    return AL_TRUE;
    (void)effect;
    (void)Device;
}

static ALvoid ModulatorUpdate(ALeffectState *effect, ALCcontext *Context, const ALeffectslot *Slot)
{
    ALmodulatorState *state = (ALmodulatorState*)effect;
    ALCdevice *Device = Context->Device;
    ALfloat gain, cw, a = 0.0f;
    ALuint index;

    if(Slot->effect.Modulator.Waveform == AL_RING_MODULATOR_SINUSOID)
        state->Waveform = SINUSOID;
    else if(Slot->effect.Modulator.Waveform == AL_RING_MODULATOR_SAWTOOTH)
        state->Waveform = SAWTOOTH;
    else if(Slot->effect.Modulator.Waveform == AL_RING_MODULATOR_SQUARE)
        state->Waveform = SQUARE;

    state->step = fastf2u(Slot->effect.Modulator.Frequency*WAVEFORM_FRACONE /
                          Device->Frequency);
    if(state->step == 0) state->step = 1;

    cw = aluCos(F_PI*2.0f * Slot->effect.Modulator.HighPassCutoff /
                            Device->Frequency);
    a = (2.0f-cw) - aluSqrt(aluPow(2.0f-cw, 2.0f) - 1.0f);
    state->iirFilter.coeff = a;

    gain = aluSqrt(1.0f/Device->NumChan);
    gain *= Slot->Gain;
    for(index = 0;index < MAXCHANNELS;index++)
        state->Gain[index] = 0.0f;
    for(index = 0;index < Device->NumChan;index++)
    {
        enum Channel chan = Device->Speaker2Chan[index];
        state->Gain[chan] = gain;
    }
}

static ALvoid ModulatorProcess(ALeffectState *effect, ALuint SamplesToDo, const ALfloat *SamplesIn, ALfloat (*SamplesOut)[MAXCHANNELS])
{
    ALmodulatorState *state = (ALmodulatorState*)effect;

    switch(state->Waveform)
    {
        case SINUSOID:
            ProcessSin(state, SamplesToDo, SamplesIn, SamplesOut);
            break;

        case SAWTOOTH:
            ProcessSaw(state, SamplesToDo, SamplesIn, SamplesOut);
            break;

        case SQUARE:
            ProcessSquare(state, SamplesToDo, SamplesIn, SamplesOut);
            break;
    }
}

ALeffectState *ModulatorCreate(void)
{
    ALmodulatorState *state;

    state = malloc(sizeof(*state));
    if(!state)
        return NULL;

    state->state.Destroy = ModulatorDestroy;
    state->state.DeviceUpdate = ModulatorDeviceUpdate;
    state->state.Update = ModulatorUpdate;
    state->state.Process = ModulatorProcess;

    state->index = 0;
    state->step = 1;

    state->iirFilter.coeff = 0.0f;
    state->iirFilter.history[0] = 0.0f;

    return &state->state;
}
