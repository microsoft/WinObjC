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

#include <stdlib.h>
#include <math.h>

#include "AL/al.h"
#include "AL/alc.h"
#include "alMain.h"
#include "alAuxEffectSlot.h"
#include "alThunk.h"
#include "alError.h"
#include "alSource.h"


static ALenum ResizeEffectSlotArray(ALCcontext *Context, ALsizei count);
static ALvoid RemoveEffectSlotArray(ALCcontext *Context, ALeffectslot *val);


AL_API ALvoid AL_APIENTRY alGenAuxiliaryEffectSlots(ALsizei n, ALuint *effectslots)
{
    ALCcontext *Context;
    ALCdevice *Device;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if(n < 0 || IsBadWritePtr((void*)effectslots, n * sizeof(ALuint)))
        alSetError(Context, AL_INVALID_VALUE);
    else
    {
        ALenum err;
        ALsizei i;

        err = ResizeEffectSlotArray(Context, n);
        if(err != AL_NO_ERROR)
        {
            alSetError(Context, err);
            n = 0;
        }

        for(i = 0;i < n;i++)
        {
            ALeffectslot *slot = calloc(1, sizeof(ALeffectslot));
            if(!slot || InitEffectSlot(slot) != AL_NO_ERROR)
            {
                free(slot);
                // We must have run out or memory
                alSetError(Context, AL_OUT_OF_MEMORY);
                alDeleteAuxiliaryEffectSlots(i, effectslots);
                break;
            }

            LockContext(Context);
            err = ResizeEffectSlotArray(Context, 1);
            if(err == AL_NO_ERROR)
                Context->ActiveEffectSlots[Context->ActiveEffectSlotCount++] = slot;
            UnlockContext(Context);
            if(err == AL_NO_ERROR)
                err = NewThunkEntry(&slot->effectslot);
            if(err == AL_NO_ERROR)
                err = InsertUIntMapEntry(&Context->EffectSlotMap, slot->effectslot, slot);
            if(err != AL_NO_ERROR)
            {
                RemoveEffectSlotArray(Context, slot);
                FreeThunkEntry(slot->effectslot);
                ALeffectState_Destroy(slot->EffectState);
                free(slot);

                alSetError(Context, err);
                alDeleteAuxiliaryEffectSlots(i, effectslots);
                break;
            }

            effectslots[i] = slot->effectslot;
        }
    }

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alDeleteAuxiliaryEffectSlots(ALsizei n, const ALuint *effectslots)
{
    ALCcontext *Context;
    ALeffectslot *EffectSlot;
    ALsizei i;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0)
        alSetError(Context, AL_INVALID_VALUE);
    else
    {
        // Check that all effectslots are valid
        for(i = 0;i < n;i++)
        {
            if((EffectSlot=LookupEffectSlot(Context, effectslots[i])) == NULL)
            {
                alSetError(Context, AL_INVALID_NAME);
                n = 0;
                break;
            }
            else if(EffectSlot->ref != 0)
            {
                alSetError(Context, AL_INVALID_OPERATION);
                n = 0;
                break;
            }
        }

        // All effectslots are valid
        for(i = 0;i < n;i++)
        {
            // Recheck that the effectslot is valid, because there could be duplicated names
            if((EffectSlot=RemoveEffectSlot(Context, effectslots[i])) == NULL)
                continue;
            FreeThunkEntry(EffectSlot->effectslot);

            RemoveEffectSlotArray(Context, EffectSlot);
            ALeffectState_Destroy(EffectSlot->EffectState);

            memset(EffectSlot, 0, sizeof(ALeffectslot));
            free(EffectSlot);
        }
    }

    ALCcontext_DecRef(Context);
}

AL_API ALboolean AL_APIENTRY alIsAuxiliaryEffectSlot(ALuint effectslot)
{
    ALCcontext *Context;
    ALboolean  result;

    Context = GetContextRef();
    if(!Context) return AL_FALSE;

    result = (LookupEffectSlot(Context, effectslot) ? AL_TRUE : AL_FALSE);

    ALCcontext_DecRef(Context);

    return result;
}

AL_API ALvoid AL_APIENTRY alAuxiliaryEffectSloti(ALuint effectslot, ALenum param, ALint iValue)
{
    ALCdevice *Device;
    ALCcontext *Context;
    ALeffectslot *EffectSlot;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((EffectSlot=LookupEffectSlot(Context, effectslot)) != NULL)
    {
        switch(param)
        {
        case AL_EFFECTSLOT_EFFECT: {
            ALeffect *effect = NULL;

            if(iValue == 0 ||
               (effect=LookupEffect(Device, iValue)) != NULL)
            {
                InitializeEffect(Context, EffectSlot, effect);
                Context->UpdateSources = AL_TRUE;
            }
            else
                alSetError(Context, AL_INVALID_VALUE);
        }   break;

        case AL_EFFECTSLOT_AUXILIARY_SEND_AUTO:
            if(iValue == AL_TRUE || iValue == AL_FALSE)
            {
                EffectSlot->AuxSendAuto = iValue;
                Context->UpdateSources = AL_TRUE;
            }
            else
                alSetError(Context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alAuxiliaryEffectSlotiv(ALuint effectslot, ALenum param, const ALint *piValues)
{
    ALCcontext *Context;

    switch(param)
    {
        case AL_EFFECTSLOT_EFFECT:
        case AL_EFFECTSLOT_AUXILIARY_SEND_AUTO:
            alAuxiliaryEffectSloti(effectslot, param, piValues[0]);
            return;
    }

    Context = GetContextRef();
    if(!Context) return;

    if(LookupEffectSlot(Context, effectslot) != NULL)
    {
        switch(param)
        {
        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alAuxiliaryEffectSlotf(ALuint effectslot, ALenum param, ALfloat flValue)
{
    ALCcontext *Context;
    ALeffectslot *EffectSlot;

    Context = GetContextRef();
    if(!Context) return;

    if((EffectSlot=LookupEffectSlot(Context, effectslot)) != NULL)
    {
        switch(param)
        {
        case AL_EFFECTSLOT_GAIN:
            if(flValue >= 0.0f && flValue <= 1.0f)
            {
                EffectSlot->Gain = flValue;
                EffectSlot->NeedsUpdate = AL_TRUE;
            }
            else
                alSetError(Context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alAuxiliaryEffectSlotfv(ALuint effectslot, ALenum param, const ALfloat *pflValues)
{
    ALCcontext *Context;

    switch(param)
    {
        case AL_EFFECTSLOT_GAIN:
            alAuxiliaryEffectSlotf(effectslot, param, pflValues[0]);
            return;
    }

    Context = GetContextRef();
    if(!Context) return;

    if(LookupEffectSlot(Context, effectslot) != NULL)
    {
        switch(param)
        {
        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetAuxiliaryEffectSloti(ALuint effectslot, ALenum param, ALint *piValue)
{
    ALCcontext *Context;
    ALeffectslot *EffectSlot;

    Context = GetContextRef();
    if(!Context) return;

    if((EffectSlot=LookupEffectSlot(Context, effectslot)) != NULL)
    {
        switch(param)
        {
        case AL_EFFECTSLOT_EFFECT:
            *piValue = EffectSlot->effect.effect;
            break;

        case AL_EFFECTSLOT_AUXILIARY_SEND_AUTO:
            *piValue = EffectSlot->AuxSendAuto;
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetAuxiliaryEffectSlotiv(ALuint effectslot, ALenum param, ALint *piValues)
{
    ALCcontext *Context;

    switch(param)
    {
        case AL_EFFECTSLOT_EFFECT:
        case AL_EFFECTSLOT_AUXILIARY_SEND_AUTO:
            alGetAuxiliaryEffectSloti(effectslot, param, piValues);
            return;
    }

    Context = GetContextRef();
    if(!Context) return;

    if(LookupEffectSlot(Context, effectslot) != NULL)
    {
        switch(param)
        {
        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetAuxiliaryEffectSlotf(ALuint effectslot, ALenum param, ALfloat *pflValue)
{
    ALCcontext *Context;
    ALeffectslot *EffectSlot;

    Context = GetContextRef();
    if(!Context) return;

    if((EffectSlot=LookupEffectSlot(Context, effectslot)) != NULL)
    {
        switch(param)
        {
        case AL_EFFECTSLOT_GAIN:
            *pflValue = EffectSlot->Gain;
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetAuxiliaryEffectSlotfv(ALuint effectslot, ALenum param, ALfloat *pflValues)
{
    ALCcontext *Context;

    switch(param)
    {
        case AL_EFFECTSLOT_GAIN:
            alGetAuxiliaryEffectSlotf(effectslot, param, pflValues);
            return;
    }

    Context = GetContextRef();
    if(!Context) return;

    if(LookupEffectSlot(Context, effectslot) != NULL)
    {
        switch(param)
        {
        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}


static ALvoid NoneDestroy(ALeffectState *State)
{ free(State); }
static ALboolean NoneDeviceUpdate(ALeffectState *State, ALCdevice *Device)
{
    return AL_TRUE;
    (void)State;
    (void)Device;
}
static ALvoid NoneUpdate(ALeffectState *State, ALCcontext *Context, const ALeffectslot *Slot)
{
    (void)State;
    (void)Context;
    (void)Slot;
}
static ALvoid NoneProcess(ALeffectState *State, ALuint SamplesToDo, const ALfloat *SamplesIn, ALfloat (*SamplesOut)[MAXCHANNELS])
{
    (void)State;
    (void)SamplesToDo;
    (void)SamplesIn;
    (void)SamplesOut;
}
ALeffectState *NoneCreate(void)
{
    ALeffectState *state;

    state = calloc(1, sizeof(*state));
    if(!state)
        return NULL;

    state->Destroy = NoneDestroy;
    state->DeviceUpdate = NoneDeviceUpdate;
    state->Update = NoneUpdate;
    state->Process = NoneProcess;

    return state;
}


static ALvoid RemoveEffectSlotArray(ALCcontext *Context, ALeffectslot *slot)
{
    ALeffectslot **slotlist, **slotlistend;

    LockContext(Context);
    slotlist = Context->ActiveEffectSlots;
    slotlistend = slotlist + Context->ActiveEffectSlotCount;
    while(slotlist != slotlistend)
    {
        if(*slotlist == slot)
        {
            *slotlist = *(--slotlistend);
            Context->ActiveEffectSlotCount--;
            break;
        }
        slotlist++;
    }
    UnlockContext(Context);
}

static ALenum ResizeEffectSlotArray(ALCcontext *Context, ALsizei count)
{
    ALsizei newcount;
    void *temp;

    if(count <= Context->MaxActiveEffectSlots-Context->ActiveEffectSlotCount)
        return AL_NO_ERROR;

    newcount = Context->MaxActiveEffectSlots ?
               (Context->MaxActiveEffectSlots<<1) : 1;
    if(newcount <= Context->MaxActiveEffectSlots ||
       !(temp=realloc(Context->ActiveEffectSlots, newcount *
                                                  sizeof(*Context->ActiveEffectSlots))))
        return AL_OUT_OF_MEMORY;

    Context->ActiveEffectSlots = temp;
    Context->MaxActiveEffectSlots = newcount;
    return AL_NO_ERROR;
}

ALvoid InitializeEffect(ALCcontext *Context, ALeffectslot *EffectSlot, ALeffect *effect)
{
    ALenum newtype = (effect ? effect->type : AL_EFFECT_NULL);
    ALeffectState *State = NULL;
    ALenum err = AL_NO_ERROR;

    LockContext(Context);
    if(newtype == AL_EFFECT_NULL && EffectSlot->effect.type != AL_EFFECT_NULL)
    {
        State = NoneCreate();
        if(!State) err = AL_OUT_OF_MEMORY;
    }
    else if(newtype == AL_EFFECT_EAXREVERB || newtype == AL_EFFECT_REVERB)
    {
        if(EffectSlot->effect.type != AL_EFFECT_EAXREVERB && EffectSlot->effect.type != AL_EFFECT_REVERB)
        {
            State = ReverbCreate();
            if(!State) err = AL_OUT_OF_MEMORY;
        }
    }
    else if(newtype == AL_EFFECT_ECHO && EffectSlot->effect.type != AL_EFFECT_ECHO)
    {
        State = EchoCreate();
        if(!State) err = AL_OUT_OF_MEMORY;
    }
    else if(newtype == AL_EFFECT_RING_MODULATOR && EffectSlot->effect.type != AL_EFFECT_RING_MODULATOR)
    {
        State = ModulatorCreate();
        if(!State) err = AL_OUT_OF_MEMORY;
    }
    else if(newtype == AL_EFFECT_DEDICATED_DIALOGUE || newtype == AL_EFFECT_DEDICATED_LOW_FREQUENCY_EFFECT)
    {
        if(EffectSlot->effect.type != AL_EFFECT_DEDICATED_DIALOGUE && EffectSlot->effect.type != AL_EFFECT_DEDICATED_LOW_FREQUENCY_EFFECT)
        {
            State = DedicatedCreate();
            if(!State) err = AL_OUT_OF_MEMORY;
        }
    }

    if(err != AL_NO_ERROR)
    {
        UnlockContext(Context);
        alSetError(Context, err);
        return;
    }

    if(State)
    {
        int oldMode;
        oldMode = SetMixerFPUMode();

        if(ALeffectState_DeviceUpdate(State, Context->Device) == AL_FALSE)
        {
            UnlockContext(Context);
            ALeffectState_Destroy(State);
            alSetError(Context, AL_OUT_OF_MEMORY);
            return;
        }
        State = ExchangePtr((XchgPtr*)&EffectSlot->EffectState, State);

        if(!effect)
            memset(&EffectSlot->effect, 0, sizeof(EffectSlot->effect));
        else
            memcpy(&EffectSlot->effect, effect, sizeof(*effect));
        /* FIXME: This should be done asynchronously, but since the EffectState
         * object was changed, it needs an update before its Process method can
         * be called. */
        EffectSlot->NeedsUpdate = AL_FALSE;
        ALeffectState_Update(EffectSlot->EffectState, Context, EffectSlot);
        UnlockContext(Context);

        RestoreFPUMode(oldMode);

        ALeffectState_Destroy(State);
        State = NULL;
    }
    else
    {
        if(!effect)
            memset(&EffectSlot->effect, 0, sizeof(EffectSlot->effect));
        else
            memcpy(&EffectSlot->effect, effect, sizeof(*effect));
        UnlockContext(Context);
        EffectSlot->NeedsUpdate = AL_TRUE;
    }
}


ALenum InitEffectSlot(ALeffectslot *slot)
{
    ALint i;

    if(!(slot->EffectState=NoneCreate()))
        return AL_OUT_OF_MEMORY;

    slot->Gain = 1.0;
    slot->AuxSendAuto = AL_TRUE;
    slot->NeedsUpdate = AL_FALSE;
    for(i = 0;i < BUFFERSIZE;i++)
        slot->WetBuffer[i] = 0.0f;
    for(i = 0;i < 1;i++)
    {
        slot->ClickRemoval[i] = 0.0f;
        slot->PendingClicks[i] = 0.0f;
    }
    slot->ref = 0;

    return AL_NO_ERROR;
}

ALvoid ReleaseALAuxiliaryEffectSlots(ALCcontext *Context)
{
    ALsizei pos;
    for(pos = 0;pos < Context->EffectSlotMap.size;pos++)
    {
        ALeffectslot *temp = Context->EffectSlotMap.array[pos].value;
        Context->EffectSlotMap.array[pos].value = NULL;

        // Release effectslot structure
        ALeffectState_Destroy(temp->EffectState);

        FreeThunkEntry(temp->effectslot);
        memset(temp, 0, sizeof(ALeffectslot));
        free(temp);
    }
}
