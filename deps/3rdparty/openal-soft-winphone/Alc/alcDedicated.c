/**
 * OpenAL cross platform audio library
 * Copyright (C) 2011 by Chris Robinson.
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

#include <stdlib.h>

#include "alMain.h"
#include "alFilter.h"
#include "alAuxEffectSlot.h"
#include "alError.h"
#include "alu.h"


typedef struct ALdedicatedState {
    // Must be first in all effects!
    ALeffectState state;

    ALfloat gains[MAXCHANNELS];
} ALdedicatedState;


static ALvoid DedicatedDestroy(ALeffectState *effect)
{
    ALdedicatedState *state = (ALdedicatedState*)effect;
    free(state);
}

static ALboolean DedicatedDeviceUpdate(ALeffectState *effect, ALCdevice *Device)
{
    (void)effect;
    (void)Device;
    return AL_TRUE;
}

static ALvoid DedicatedUpdate(ALeffectState *effect, ALCcontext *Context, const ALeffectslot *Slot)
{
    ALdedicatedState *state = (ALdedicatedState*)effect;
    ALCdevice *device = Context->Device;
    const ALfloat *SpeakerGain;
    ALfloat Gain;
    ALint pos;
    ALsizei s;

    Gain = Slot->Gain * Slot->effect.Dedicated.Gain;
    for(s = 0;s < MAXCHANNELS;s++)
        state->gains[s] = 0.0f;

    if(Slot->effect.type == AL_EFFECT_DEDICATED_DIALOGUE)
    {
        pos = aluCart2LUTpos(1.0f, 0.0f);
        SpeakerGain = device->PanningLUT[pos];

        for(s = 0;s < MAXCHANNELS;s++)
            state->gains[s] = SpeakerGain[s] * Gain;
    }
    else if(Slot->effect.type == AL_EFFECT_DEDICATED_LOW_FREQUENCY_EFFECT)
        state->gains[LFE] = Gain;
}

static ALvoid DedicatedProcess(ALeffectState *effect, ALuint SamplesToDo, const ALfloat *SamplesIn, ALfloat (*SamplesOut)[MAXCHANNELS])
{
    ALdedicatedState *state = (ALdedicatedState*)effect;
    const ALfloat *gains = state->gains;
    ALuint i, s;

    for(i = 0;i < SamplesToDo;i++)
    {
        ALfloat sample;

        sample = SamplesIn[i];
        for(s = 0;s < MAXCHANNELS;s++)
            SamplesOut[i][s] = sample * gains[s];
    }
}

ALeffectState *DedicatedCreate(void)
{
    ALdedicatedState *state;
    ALsizei s;

    state = malloc(sizeof(*state));
    if(!state)
        return NULL;

    state->state.Destroy = DedicatedDestroy;
    state->state.DeviceUpdate = DedicatedDeviceUpdate;
    state->state.Update = DedicatedUpdate;
    state->state.Process = DedicatedProcess;

    for(s = 0;s < MAXCHANNELS;s++)
        state->gains[s] = 0.0f;

    return &state->state;
}
