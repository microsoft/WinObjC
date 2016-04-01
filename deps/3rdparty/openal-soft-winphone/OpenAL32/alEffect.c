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
#include "alEffect.h"
#include "alThunk.h"
#include "alError.h"


ALboolean DisabledEffects[MAX_EFFECTS];


static void InitEffectParams(ALeffect *effect, ALenum type);


AL_API ALvoid AL_APIENTRY alGenEffects(ALsizei n, ALuint *effects)
{
    ALCcontext *Context;
    ALsizei i;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0 || IsBadWritePtr((void*)effects, n * sizeof(ALuint)))
        alSetError(Context, AL_INVALID_VALUE);
    else
    {
        ALCdevice *device = Context->Device;
        ALenum err;

        for(i = 0;i < n;i++)
        {
            ALeffect *effect = calloc(1, sizeof(ALeffect));
            if(!effect || InitEffect(effect) != AL_NO_ERROR)
            {
                free(effect);
                alSetError(Context, AL_OUT_OF_MEMORY);
                alDeleteEffects(i, effects);
                break;
            }

            err = NewThunkEntry(&effect->effect);
            if(err == AL_NO_ERROR)
                err = InsertUIntMapEntry(&device->EffectMap, effect->effect, effect);
            if(err != AL_NO_ERROR)
            {
                FreeThunkEntry(effect->effect);
                memset(effect, 0, sizeof(ALeffect));
                free(effect);

                alSetError(Context, err);
                alDeleteEffects(i, effects);
                break;
            }

            effects[i] = effect->effect;
        }
    }

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alDeleteEffects(ALsizei n, const ALuint *effects)
{
    ALCcontext *Context;
    ALCdevice *device;
    ALeffect *ALEffect;
    ALsizei i;

    Context = GetContextRef();
    if(!Context) return;

    device = Context->Device;
    if(n < 0)
        alSetError(Context, AL_INVALID_VALUE);
    else
    {
        // Check that all effects are valid
        for(i = 0;i < n;i++)
        {
            if(!effects[i])
                continue;

            if(LookupEffect(device, effects[i]) == NULL)
            {
                alSetError(Context, AL_INVALID_NAME);
                n = 0;
                break;
            }
        }

        for(i = 0;i < n;i++)
        {
            // Recheck that the effect is valid, because there could be duplicated names
            if((ALEffect=RemoveEffect(device, effects[i])) == NULL)
                continue;
            FreeThunkEntry(ALEffect->effect);

            memset(ALEffect, 0, sizeof(ALeffect));
            free(ALEffect);
        }
    }

    ALCcontext_DecRef(Context);
}

AL_API ALboolean AL_APIENTRY alIsEffect(ALuint effect)
{
    ALCcontext *Context;
    ALboolean  result;

    Context = GetContextRef();
    if(!Context) return AL_FALSE;

    result = ((!effect || LookupEffect(Context->Device, effect)) ?
              AL_TRUE : AL_FALSE);

    ALCcontext_DecRef(Context);

    return result;
}

AL_API ALvoid AL_APIENTRY alEffecti(ALuint effect, ALenum param, ALint iValue)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALeffect   *ALEffect;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALEffect=LookupEffect(Device, effect)) != NULL)
    {
        if(param == AL_EFFECT_TYPE)
        {
            ALboolean isOk = (iValue == AL_EFFECT_NULL);
            ALint i;
            for(i = 0;!isOk && EffectList[i].val;i++)
            {
                if(iValue == EffectList[i].val &&
                   !DisabledEffects[EffectList[i].type])
                    isOk = AL_TRUE;
            }

            if(isOk)
                InitEffectParams(ALEffect, iValue);
            else
                alSetError(Context, AL_INVALID_VALUE);
        }
        else
        {
            /* Call the appropriate handler */
            ALeffect_SetParami(ALEffect, Context, param, iValue);
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alEffectiv(ALuint effect, ALenum param, const ALint *piValues)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALeffect   *ALEffect;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALEffect=LookupEffect(Device, effect)) != NULL)
    {
        /* Call the appropriate handler */
        ALeffect_SetParamiv(ALEffect, Context, param, piValues);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alEffectf(ALuint effect, ALenum param, ALfloat flValue)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALeffect   *ALEffect;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALEffect=LookupEffect(Device, effect)) != NULL)
    {
        /* Call the appropriate handler */
        ALeffect_SetParamf(ALEffect, Context, param, flValue);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alEffectfv(ALuint effect, ALenum param, const ALfloat *pflValues)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALeffect   *ALEffect;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALEffect=LookupEffect(Device, effect)) != NULL)
    {
        /* Call the appropriate handler */
        ALeffect_SetParamfv(ALEffect, Context, param, pflValues);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetEffecti(ALuint effect, ALenum param, ALint *piValue)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALeffect   *ALEffect;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALEffect=LookupEffect(Device, effect)) != NULL)
    {
        if(param == AL_EFFECT_TYPE)
        {
            *piValue = ALEffect->type;
        }
        else
        {
            /* Call the appropriate handler */
            ALeffect_GetParamiv(ALEffect, Context, param, piValue);
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetEffectiv(ALuint effect, ALenum param, ALint *piValues)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALeffect   *ALEffect;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALEffect=LookupEffect(Device, effect)) != NULL)
    {
        /* Call the appropriate handler */
        ALeffect_GetParamiv(ALEffect, Context, param, piValues);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetEffectf(ALuint effect, ALenum param, ALfloat *pflValue)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALeffect   *ALEffect;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALEffect=LookupEffect(Device, effect)) != NULL)
    {
        /* Call the appropriate handler */
        ALeffect_GetParamf(ALEffect, Context, param, pflValue);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetEffectfv(ALuint effect, ALenum param, ALfloat *pflValues)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALeffect   *ALEffect;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALEffect=LookupEffect(Device, effect)) != NULL)
    {
        /* Call the appropriate handler */
        ALeffect_GetParamfv(ALEffect, Context, param, pflValues);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}


static void eaxreverb_SetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint val)
{
    switch(param)
    {
        case AL_EAXREVERB_DECAY_HFLIMIT:
            if(val >= AL_EAXREVERB_MIN_DECAY_HFLIMIT && val <= AL_EAXREVERB_MAX_DECAY_HFLIMIT)
                effect->Reverb.DecayHFLimit = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void eaxreverb_SetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, const ALint *vals)
{
    eaxreverb_SetParami(effect, context, param, vals[0]);
}
static void eaxreverb_SetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat val)
{
    switch(param)
    {
        case AL_EAXREVERB_DENSITY:
            if(val >= AL_EAXREVERB_MIN_DENSITY &&
               val <= AL_EAXREVERB_MAX_DENSITY)
                effect->Reverb.Density = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_DIFFUSION:
            if(val >= AL_EAXREVERB_MIN_DIFFUSION &&
               val <= AL_EAXREVERB_MAX_DIFFUSION)
                effect->Reverb.Diffusion = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_GAIN:
            if(val >= AL_EAXREVERB_MIN_GAIN &&
               val <= AL_EAXREVERB_MAX_GAIN)
                effect->Reverb.Gain = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_GAINHF:
            if(val >= AL_EAXREVERB_MIN_GAINHF &&
               val <= AL_EAXREVERB_MAX_GAINHF)
                effect->Reverb.GainHF = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_GAINLF:
            if(val >= AL_EAXREVERB_MIN_GAINLF &&
               val <= AL_EAXREVERB_MAX_GAINLF)
                effect->Reverb.GainLF = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_DECAY_TIME:
            if(val >= AL_EAXREVERB_MIN_DECAY_TIME &&
               val <= AL_EAXREVERB_MAX_DECAY_TIME)
                effect->Reverb.DecayTime = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_DECAY_HFRATIO:
            if(val >= AL_EAXREVERB_MIN_DECAY_HFRATIO &&
               val <= AL_EAXREVERB_MAX_DECAY_HFRATIO)
                effect->Reverb.DecayHFRatio = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_DECAY_LFRATIO:
            if(val >= AL_EAXREVERB_MIN_DECAY_LFRATIO &&
               val <= AL_EAXREVERB_MAX_DECAY_LFRATIO)
                effect->Reverb.DecayLFRatio = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_REFLECTIONS_GAIN:
            if(val >= AL_EAXREVERB_MIN_REFLECTIONS_GAIN &&
               val <= AL_EAXREVERB_MAX_REFLECTIONS_GAIN)
                effect->Reverb.ReflectionsGain = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_REFLECTIONS_DELAY:
            if(val >= AL_EAXREVERB_MIN_REFLECTIONS_DELAY &&
               val <= AL_EAXREVERB_MAX_REFLECTIONS_DELAY)
                effect->Reverb.ReflectionsDelay = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_LATE_REVERB_GAIN:
            if(val >= AL_EAXREVERB_MIN_LATE_REVERB_GAIN &&
               val <= AL_EAXREVERB_MAX_LATE_REVERB_GAIN)
                effect->Reverb.LateReverbGain = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_LATE_REVERB_DELAY:
            if(val >= AL_EAXREVERB_MIN_LATE_REVERB_DELAY &&
               val <= AL_EAXREVERB_MAX_LATE_REVERB_DELAY)
                effect->Reverb.LateReverbDelay = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_AIR_ABSORPTION_GAINHF:
            if(val >= AL_EAXREVERB_MIN_AIR_ABSORPTION_GAINHF &&
               val <= AL_EAXREVERB_MAX_AIR_ABSORPTION_GAINHF)
                effect->Reverb.AirAbsorptionGainHF = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_ECHO_TIME:
            if(val >= AL_EAXREVERB_MIN_ECHO_TIME &&
               val <= AL_EAXREVERB_MAX_ECHO_TIME)
                effect->Reverb.EchoTime = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_ECHO_DEPTH:
            if(val >= AL_EAXREVERB_MIN_ECHO_DEPTH &&
               val <= AL_EAXREVERB_MAX_ECHO_DEPTH)
                effect->Reverb.EchoDepth = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_MODULATION_TIME:
            if(val >= AL_EAXREVERB_MIN_MODULATION_TIME &&
               val <= AL_EAXREVERB_MAX_MODULATION_TIME)
                effect->Reverb.ModulationTime = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_MODULATION_DEPTH:
            if(val >= AL_EAXREVERB_MIN_MODULATION_DEPTH &&
               val <= AL_EAXREVERB_MAX_MODULATION_DEPTH)
                effect->Reverb.ModulationDepth = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_HFREFERENCE:
            if(val >= AL_EAXREVERB_MIN_HFREFERENCE &&
               val <= AL_EAXREVERB_MAX_HFREFERENCE)
                effect->Reverb.HFReference = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_LFREFERENCE:
            if(val >= AL_EAXREVERB_MIN_LFREFERENCE &&
               val <= AL_EAXREVERB_MAX_LFREFERENCE)
                effect->Reverb.LFReference = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_EAXREVERB_ROOM_ROLLOFF_FACTOR:
            if(val >= 0.0f && val <= 10.0f)
                effect->Reverb.RoomRolloffFactor = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void eaxreverb_SetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, const ALfloat *vals)
{
    switch(param)
    {
        case AL_EAXREVERB_REFLECTIONS_PAN:
            if(isfinite(vals[0]) && isfinite(vals[1]) && isfinite(vals[2]))
            {
                LockContext(context);
                effect->Reverb.ReflectionsPan[0] = vals[0];
                effect->Reverb.ReflectionsPan[1] = vals[1];
                effect->Reverb.ReflectionsPan[2] = vals[2];
                UnlockContext(context);
            }
            else
                alSetError(context, AL_INVALID_VALUE);
            break;
        case AL_EAXREVERB_LATE_REVERB_PAN:
            if(isfinite(vals[0]) && isfinite(vals[1]) && isfinite(vals[2]))
            {
                LockContext(context);
                effect->Reverb.LateReverbPan[0] = vals[0];
                effect->Reverb.LateReverbPan[1] = vals[1];
                effect->Reverb.LateReverbPan[2] = vals[2];
                UnlockContext(context);
            }
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            eaxreverb_SetParamf(effect, context, param, vals[0]);
            break;
    }
}

static void eaxreverb_GetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint *val)
{
    switch(param)
    {
        case AL_EAXREVERB_DECAY_HFLIMIT:
            *val = effect->Reverb.DecayHFLimit;
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void eaxreverb_GetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, ALint *vals)
{
    eaxreverb_GetParami(effect, context, param, vals);
}
static void eaxreverb_GetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *val)
{
    switch(param)
    {
        case AL_EAXREVERB_DENSITY:
            *val = effect->Reverb.Density;
            break;

        case AL_EAXREVERB_DIFFUSION:
            *val = effect->Reverb.Diffusion;
            break;

        case AL_EAXREVERB_GAIN:
            *val = effect->Reverb.Gain;
            break;

        case AL_EAXREVERB_GAINHF:
            *val = effect->Reverb.GainHF;
            break;

        case AL_EAXREVERB_GAINLF:
            *val = effect->Reverb.GainLF;
            break;

        case AL_EAXREVERB_DECAY_TIME:
            *val = effect->Reverb.DecayTime;
            break;

        case AL_EAXREVERB_DECAY_HFRATIO:
            *val = effect->Reverb.DecayHFRatio;
            break;

        case AL_EAXREVERB_DECAY_LFRATIO:
            *val = effect->Reverb.DecayLFRatio;
            break;

        case AL_EAXREVERB_REFLECTIONS_GAIN:
            *val = effect->Reverb.ReflectionsGain;
            break;

        case AL_EAXREVERB_REFLECTIONS_DELAY:
            *val = effect->Reverb.ReflectionsDelay;
            break;

        case AL_EAXREVERB_LATE_REVERB_GAIN:
            *val = effect->Reverb.LateReverbGain;
            break;

        case AL_EAXREVERB_LATE_REVERB_DELAY:
            *val = effect->Reverb.LateReverbDelay;
            break;

        case AL_EAXREVERB_AIR_ABSORPTION_GAINHF:
            *val = effect->Reverb.AirAbsorptionGainHF;
            break;

        case AL_EAXREVERB_ECHO_TIME:
            *val = effect->Reverb.EchoTime;
            break;

        case AL_EAXREVERB_ECHO_DEPTH:
            *val = effect->Reverb.EchoDepth;
            break;

        case AL_EAXREVERB_MODULATION_TIME:
            *val = effect->Reverb.ModulationTime;
            break;

        case AL_EAXREVERB_MODULATION_DEPTH:
            *val = effect->Reverb.ModulationDepth;
            break;

        case AL_EAXREVERB_HFREFERENCE:
            *val = effect->Reverb.HFReference;
            break;

        case AL_EAXREVERB_LFREFERENCE:
            *val = effect->Reverb.LFReference;
            break;

        case AL_EAXREVERB_ROOM_ROLLOFF_FACTOR:
            *val = effect->Reverb.RoomRolloffFactor;
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void eaxreverb_GetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *vals)
{
    switch(param)
    {
        case AL_EAXREVERB_REFLECTIONS_PAN:
            LockContext(context);
            vals[0] = effect->Reverb.ReflectionsPan[0];
            vals[1] = effect->Reverb.ReflectionsPan[1];
            vals[2] = effect->Reverb.ReflectionsPan[2];
            UnlockContext(context);
            break;
        case AL_EAXREVERB_LATE_REVERB_PAN:
            LockContext(context);
            vals[0] = effect->Reverb.LateReverbPan[0];
            vals[1] = effect->Reverb.LateReverbPan[1];
            vals[2] = effect->Reverb.LateReverbPan[2];
            UnlockContext(context);
            break;

        default:
            eaxreverb_GetParamf(effect, context, param, vals);
            break;
    }
}


static void reverb_SetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint val)
{
    switch(param)
    {
        case AL_REVERB_DECAY_HFLIMIT:
            if(val >= AL_REVERB_MIN_DECAY_HFLIMIT &&
               val <= AL_REVERB_MAX_DECAY_HFLIMIT)
                effect->Reverb.DecayHFLimit = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void reverb_SetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, const ALint *vals)
{
    reverb_SetParami(effect, context, param, vals[0]);
}
static void reverb_SetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat val)
{
    switch(param)
    {
        case AL_REVERB_DENSITY:
            if(val >= AL_REVERB_MIN_DENSITY &&
               val <= AL_REVERB_MAX_DENSITY)
                effect->Reverb.Density = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_DIFFUSION:
            if(val >= AL_REVERB_MIN_DIFFUSION &&
               val <= AL_REVERB_MAX_DIFFUSION)
                effect->Reverb.Diffusion = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_GAIN:
            if(val >= AL_REVERB_MIN_GAIN &&
               val <= AL_REVERB_MAX_GAIN)
                effect->Reverb.Gain = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_GAINHF:
            if(val >= AL_REVERB_MIN_GAINHF &&
               val <= AL_REVERB_MAX_GAINHF)
                effect->Reverb.GainHF = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_DECAY_TIME:
            if(val >= AL_REVERB_MIN_DECAY_TIME &&
               val <= AL_REVERB_MAX_DECAY_TIME)
                effect->Reverb.DecayTime = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_DECAY_HFRATIO:
            if(val >= AL_REVERB_MIN_DECAY_HFRATIO &&
               val <= AL_REVERB_MAX_DECAY_HFRATIO)
                effect->Reverb.DecayHFRatio = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_REFLECTIONS_GAIN:
            if(val >= AL_REVERB_MIN_REFLECTIONS_GAIN &&
               val <= AL_REVERB_MAX_REFLECTIONS_GAIN)
                effect->Reverb.ReflectionsGain = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_REFLECTIONS_DELAY:
            if(val >= AL_REVERB_MIN_REFLECTIONS_DELAY &&
               val <= AL_REVERB_MAX_REFLECTIONS_DELAY)
                effect->Reverb.ReflectionsDelay = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_LATE_REVERB_GAIN:
            if(val >= AL_REVERB_MIN_LATE_REVERB_GAIN &&
               val <= AL_REVERB_MAX_LATE_REVERB_GAIN)
                effect->Reverb.LateReverbGain = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_LATE_REVERB_DELAY:
            if(val >= AL_REVERB_MIN_LATE_REVERB_DELAY &&
               val <= AL_REVERB_MAX_LATE_REVERB_DELAY)
                effect->Reverb.LateReverbDelay = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_AIR_ABSORPTION_GAINHF:
            if(val >= AL_REVERB_MIN_AIR_ABSORPTION_GAINHF &&
               val <= AL_REVERB_MAX_AIR_ABSORPTION_GAINHF)
                effect->Reverb.AirAbsorptionGainHF = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_REVERB_ROOM_ROLLOFF_FACTOR:
            if(val >= AL_REVERB_MIN_ROOM_ROLLOFF_FACTOR &&
               val <= AL_REVERB_MAX_ROOM_ROLLOFF_FACTOR)
                effect->Reverb.RoomRolloffFactor = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void reverb_SetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, const ALfloat *vals)
{
    reverb_SetParamf(effect, context, param, vals[0]);
}

static void reverb_GetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint *val)
{
    switch(param)
    {
        case AL_REVERB_DECAY_HFLIMIT:
            *val = effect->Reverb.DecayHFLimit;
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void reverb_GetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, ALint *vals)
{
    reverb_GetParami(effect, context, param, vals);
}
static void reverb_GetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *val)
{
    switch(param)
    {
        case AL_REVERB_DENSITY:
            *val = effect->Reverb.Density;
            break;

        case AL_REVERB_DIFFUSION:
            *val = effect->Reverb.Diffusion;
            break;

        case AL_REVERB_GAIN:
            *val = effect->Reverb.Gain;
            break;

        case AL_REVERB_GAINHF:
            *val = effect->Reverb.GainHF;
            break;

        case AL_REVERB_DECAY_TIME:
            *val = effect->Reverb.DecayTime;
            break;

        case AL_REVERB_DECAY_HFRATIO:
            *val = effect->Reverb.DecayHFRatio;
            break;

        case AL_REVERB_REFLECTIONS_GAIN:
            *val = effect->Reverb.ReflectionsGain;
            break;

        case AL_REVERB_REFLECTIONS_DELAY:
            *val = effect->Reverb.ReflectionsDelay;
            break;

        case AL_REVERB_LATE_REVERB_GAIN:
            *val = effect->Reverb.LateReverbGain;
            break;

        case AL_REVERB_LATE_REVERB_DELAY:
            *val = effect->Reverb.LateReverbDelay;
            break;

        case AL_REVERB_AIR_ABSORPTION_GAINHF:
            *val = effect->Reverb.AirAbsorptionGainHF;
            break;

        case AL_REVERB_ROOM_ROLLOFF_FACTOR:
            *val = effect->Reverb.RoomRolloffFactor;
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void reverb_GetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *vals)
{
    reverb_GetParamf(effect, context, param, vals);
}


static void echo_SetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint val)
{ (void)effect;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void echo_SetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, const ALint *vals)
{
    echo_SetParami(effect, context, param, vals[0]);
}
static void echo_SetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat val)
{
    switch(param)
    {
        case AL_ECHO_DELAY:
            if(val >= AL_ECHO_MIN_DELAY && val <= AL_ECHO_MAX_DELAY)
                effect->Echo.Delay = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_ECHO_LRDELAY:
            if(val >= AL_ECHO_MIN_LRDELAY && val <= AL_ECHO_MAX_LRDELAY)
                effect->Echo.LRDelay = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_ECHO_DAMPING:
            if(val >= AL_ECHO_MIN_DAMPING && val <= AL_ECHO_MAX_DAMPING)
                effect->Echo.Damping = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_ECHO_FEEDBACK:
            if(val >= AL_ECHO_MIN_FEEDBACK && val <= AL_ECHO_MAX_FEEDBACK)
                effect->Echo.Feedback = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_ECHO_SPREAD:
            if(val >= AL_ECHO_MIN_SPREAD && val <= AL_ECHO_MAX_SPREAD)
                effect->Echo.Spread = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void echo_SetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, const ALfloat *vals)
{
    echo_SetParamf(effect, context, param, vals[0]);
}

static void echo_GetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint *val)
{ (void)effect;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void echo_GetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, ALint *vals)
{
    echo_GetParami(effect, context, param, vals);
}
static void echo_GetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *val)
{
    switch(param)
    {
        case AL_ECHO_DELAY:
            *val = effect->Echo.Delay;
            break;

        case AL_ECHO_LRDELAY:
            *val = effect->Echo.LRDelay;
            break;

        case AL_ECHO_DAMPING:
            *val = effect->Echo.Damping;
            break;

        case AL_ECHO_FEEDBACK:
            *val = effect->Echo.Feedback;
            break;

        case AL_ECHO_SPREAD:
            *val = effect->Echo.Spread;
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void echo_GetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *vals)
{
    echo_GetParamf(effect, context, param, vals);
}


static void mod_SetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat val)
{
    switch(param)
    {
        case AL_RING_MODULATOR_FREQUENCY:
            if(val >= AL_RING_MODULATOR_MIN_FREQUENCY &&
               val <= AL_RING_MODULATOR_MAX_FREQUENCY)
                effect->Modulator.Frequency = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_RING_MODULATOR_HIGHPASS_CUTOFF:
            if(val >= AL_RING_MODULATOR_MIN_HIGHPASS_CUTOFF &&
               val <= AL_RING_MODULATOR_MAX_HIGHPASS_CUTOFF)
                effect->Modulator.HighPassCutoff = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void mod_SetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, const ALfloat *vals)
{
    mod_SetParamf(effect, context, param, vals[0]);
}
static void mod_SetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint val)
{
    switch(param)
    {
        case AL_RING_MODULATOR_FREQUENCY:
        case AL_RING_MODULATOR_HIGHPASS_CUTOFF:
            mod_SetParamf(effect, context, param, (ALfloat)val);
            break;

        case AL_RING_MODULATOR_WAVEFORM:
            if(val >= AL_RING_MODULATOR_MIN_WAVEFORM &&
               val <= AL_RING_MODULATOR_MAX_WAVEFORM)
                effect->Modulator.Waveform = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void mod_SetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, const ALint *vals)
{
    mod_SetParami(effect, context, param, vals[0]);
}

static void mod_GetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint *val)
{
    switch(param)
    {
        case AL_RING_MODULATOR_FREQUENCY:
            *val = (ALint)effect->Modulator.Frequency;
            break;
        case AL_RING_MODULATOR_HIGHPASS_CUTOFF:
            *val = (ALint)effect->Modulator.HighPassCutoff;
            break;
        case AL_RING_MODULATOR_WAVEFORM:
            *val = effect->Modulator.Waveform;
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void mod_GetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, ALint *vals)
{
    mod_GetParami(effect, context, param, vals);
}
static void mod_GetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *val)
{
    switch(param)
    {
        case AL_RING_MODULATOR_FREQUENCY:
            *val = effect->Modulator.Frequency;
            break;
        case AL_RING_MODULATOR_HIGHPASS_CUTOFF:
            *val = effect->Modulator.HighPassCutoff;
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void mod_GetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *vals)
{
    mod_GetParamf(effect, context, param, vals);
}


static void ded_SetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint val)
{ (void)effect;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void ded_SetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, const ALint *vals)
{
    ded_SetParami(effect, context, param, vals[0]);
}
static void ded_SetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat val)
{
    switch(param)
    {
        case AL_DEDICATED_GAIN:
            if(val >= 0.0f && isfinite(val))
                effect->Dedicated.Gain = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void ded_SetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, const ALfloat *vals)
{
    ded_SetParamf(effect, context, param, vals[0]);
}

static void ded_GetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint *val)
{ (void)effect;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void ded_GetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, ALint *vals)
{
    ded_GetParami(effect, context, param, vals);
}
static void ded_GetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *val)
{
    switch(param)
    {
        case AL_DEDICATED_GAIN:
            *val = effect->Dedicated.Gain;
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void ded_GetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *vals)
{
    ded_GetParamf(effect, context, param, vals);
}


static void null_SetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint val)
{ (void)effect;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void null_SetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, const ALint *vals)
{ (void)effect;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }
static void null_SetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat val)
{ (void)effect;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void null_SetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, const ALfloat *vals)
{ (void)effect;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }

static void null_GetParami(ALeffect *effect, ALCcontext *context, ALenum param, ALint *val)
{ (void)effect;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void null_GetParamiv(ALeffect *effect, ALCcontext *context, ALenum param, ALint *vals)
{ (void)effect;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }
static void null_GetParamf(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *val)
{ (void)effect;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void null_GetParamfv(ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *vals)
{ (void)effect;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }


ALenum InitEffect(ALeffect *effect)
{
    InitEffectParams(effect, AL_EFFECT_NULL);
    return AL_NO_ERROR;
}

ALvoid ReleaseALEffects(ALCdevice *device)
{
    ALsizei i;
    for(i = 0;i < device->EffectMap.size;i++)
    {
        ALeffect *temp = device->EffectMap.array[i].value;
        device->EffectMap.array[i].value = NULL;

        // Release effect structure
        FreeThunkEntry(temp->effect);
        memset(temp, 0, sizeof(ALeffect));
        free(temp);
    }
}


static void InitEffectParams(ALeffect *effect, ALenum type)
{
    switch(type)
    {
    case AL_EFFECT_EAXREVERB:
        effect->Reverb.Density   = AL_EAXREVERB_DEFAULT_DENSITY;
        effect->Reverb.Diffusion = AL_EAXREVERB_DEFAULT_DIFFUSION;
        effect->Reverb.Gain   = AL_EAXREVERB_DEFAULT_GAIN;
        effect->Reverb.GainHF = AL_EAXREVERB_DEFAULT_GAINHF;
        effect->Reverb.GainLF = AL_EAXREVERB_DEFAULT_GAINLF;
        effect->Reverb.DecayTime    = AL_EAXREVERB_DEFAULT_DECAY_TIME;
        effect->Reverb.DecayHFRatio = AL_EAXREVERB_DEFAULT_DECAY_HFRATIO;
        effect->Reverb.DecayLFRatio = AL_EAXREVERB_DEFAULT_DECAY_LFRATIO;
        effect->Reverb.ReflectionsGain   = AL_EAXREVERB_DEFAULT_REFLECTIONS_GAIN;
        effect->Reverb.ReflectionsDelay  = AL_EAXREVERB_DEFAULT_REFLECTIONS_DELAY;
        effect->Reverb.ReflectionsPan[0] = AL_EAXREVERB_DEFAULT_REFLECTIONS_PAN_XYZ;
        effect->Reverb.ReflectionsPan[1] = AL_EAXREVERB_DEFAULT_REFLECTIONS_PAN_XYZ;
        effect->Reverb.ReflectionsPan[2] = AL_EAXREVERB_DEFAULT_REFLECTIONS_PAN_XYZ;
        effect->Reverb.LateReverbGain   = AL_EAXREVERB_DEFAULT_LATE_REVERB_GAIN;
        effect->Reverb.LateReverbDelay  = AL_EAXREVERB_DEFAULT_LATE_REVERB_DELAY;
        effect->Reverb.LateReverbPan[0] = AL_EAXREVERB_DEFAULT_LATE_REVERB_PAN_XYZ;
        effect->Reverb.LateReverbPan[1] = AL_EAXREVERB_DEFAULT_LATE_REVERB_PAN_XYZ;
        effect->Reverb.LateReverbPan[2] = AL_EAXREVERB_DEFAULT_LATE_REVERB_PAN_XYZ;
        effect->Reverb.EchoTime  = AL_EAXREVERB_DEFAULT_ECHO_TIME;
        effect->Reverb.EchoDepth = AL_EAXREVERB_DEFAULT_ECHO_DEPTH;
        effect->Reverb.ModulationTime  = AL_EAXREVERB_DEFAULT_MODULATION_TIME;
        effect->Reverb.ModulationDepth = AL_EAXREVERB_DEFAULT_MODULATION_DEPTH;
        effect->Reverb.AirAbsorptionGainHF = AL_EAXREVERB_DEFAULT_AIR_ABSORPTION_GAINHF;
        effect->Reverb.HFReference = AL_EAXREVERB_DEFAULT_HFREFERENCE;
        effect->Reverb.LFReference = AL_EAXREVERB_DEFAULT_LFREFERENCE;
        effect->Reverb.RoomRolloffFactor = AL_EAXREVERB_DEFAULT_ROOM_ROLLOFF_FACTOR;
        effect->Reverb.DecayHFLimit = AL_EAXREVERB_DEFAULT_DECAY_HFLIMIT;
        effect->SetParami  = eaxreverb_SetParami;
        effect->SetParamiv = eaxreverb_SetParamiv;
        effect->SetParamf  = eaxreverb_SetParamf;
        effect->SetParamfv = eaxreverb_SetParamfv;
        effect->GetParami  = eaxreverb_GetParami;
        effect->GetParamiv = eaxreverb_GetParamiv;
        effect->GetParamf  = eaxreverb_GetParamf;
        effect->GetParamfv = eaxreverb_GetParamfv;
        break;
    case AL_EFFECT_REVERB:
        effect->Reverb.Density   = AL_REVERB_DEFAULT_DENSITY;
        effect->Reverb.Diffusion = AL_REVERB_DEFAULT_DIFFUSION;
        effect->Reverb.Gain   = AL_REVERB_DEFAULT_GAIN;
        effect->Reverb.GainHF = AL_REVERB_DEFAULT_GAINHF;
        effect->Reverb.DecayTime    = AL_REVERB_DEFAULT_DECAY_TIME;
        effect->Reverb.DecayHFRatio = AL_REVERB_DEFAULT_DECAY_HFRATIO;
        effect->Reverb.ReflectionsGain   = AL_REVERB_DEFAULT_REFLECTIONS_GAIN;
        effect->Reverb.ReflectionsDelay  = AL_REVERB_DEFAULT_REFLECTIONS_DELAY;
        effect->Reverb.LateReverbGain   = AL_REVERB_DEFAULT_LATE_REVERB_GAIN;
        effect->Reverb.LateReverbDelay  = AL_REVERB_DEFAULT_LATE_REVERB_DELAY;
        effect->Reverb.AirAbsorptionGainHF = AL_REVERB_DEFAULT_AIR_ABSORPTION_GAINHF;
        effect->Reverb.RoomRolloffFactor = AL_REVERB_DEFAULT_ROOM_ROLLOFF_FACTOR;
        effect->Reverb.DecayHFLimit = AL_REVERB_DEFAULT_DECAY_HFLIMIT;
        effect->SetParami  = reverb_SetParami;
        effect->SetParamiv = reverb_SetParamiv;
        effect->SetParamf  = reverb_SetParamf;
        effect->SetParamfv = reverb_SetParamfv;
        effect->GetParami  = reverb_GetParami;
        effect->GetParamiv = reverb_GetParamiv;
        effect->GetParamf  = reverb_GetParamf;
        effect->GetParamfv = reverb_GetParamfv;
        break;
    case AL_EFFECT_ECHO:
        effect->Echo.Delay    = AL_ECHO_DEFAULT_DELAY;
        effect->Echo.LRDelay  = AL_ECHO_DEFAULT_LRDELAY;
        effect->Echo.Damping  = AL_ECHO_DEFAULT_DAMPING;
        effect->Echo.Feedback = AL_ECHO_DEFAULT_FEEDBACK;
        effect->Echo.Spread   = AL_ECHO_DEFAULT_SPREAD;
        effect->SetParami  = echo_SetParami;
        effect->SetParamiv = echo_SetParamiv;
        effect->SetParamf  = echo_SetParamf;
        effect->SetParamfv = echo_SetParamfv;
        effect->GetParami  = echo_GetParami;
        effect->GetParamiv = echo_GetParamiv;
        effect->GetParamf  = echo_GetParamf;
        effect->GetParamfv = echo_GetParamfv;
        break;
    case AL_EFFECT_RING_MODULATOR:
        effect->Modulator.Frequency      = AL_RING_MODULATOR_DEFAULT_FREQUENCY;
        effect->Modulator.HighPassCutoff = AL_RING_MODULATOR_DEFAULT_HIGHPASS_CUTOFF;
        effect->Modulator.Waveform       = AL_RING_MODULATOR_DEFAULT_WAVEFORM;
        effect->SetParami  = mod_SetParami;
        effect->SetParamiv = mod_SetParamiv;
        effect->SetParamf  = mod_SetParamf;
        effect->SetParamfv = mod_SetParamfv;
        effect->GetParami  = mod_GetParami;
        effect->GetParamiv = mod_GetParamiv;
        effect->GetParamf  = mod_GetParamf;
        effect->GetParamfv = mod_GetParamfv;
        break;
    case AL_EFFECT_DEDICATED_LOW_FREQUENCY_EFFECT:
    case AL_EFFECT_DEDICATED_DIALOGUE:
        effect->Dedicated.Gain = 1.0f;
        effect->SetParami  = ded_SetParami;
        effect->SetParamiv = ded_SetParamiv;
        effect->SetParamf  = ded_SetParamf;
        effect->SetParamfv = ded_SetParamfv;
        effect->GetParami  = ded_GetParami;
        effect->GetParamiv = ded_GetParamiv;
        effect->GetParamf  = ded_GetParamf;
        effect->GetParamfv = ded_GetParamfv;
        break;
    default:
        effect->SetParami  = null_SetParami;
        effect->SetParamiv = null_SetParamiv;
        effect->SetParamf  = null_SetParamf;
        effect->SetParamfv = null_SetParamfv;
        effect->GetParami  = null_GetParami;
        effect->GetParamiv = null_GetParamiv;
        effect->GetParamf  = null_GetParamf;
        effect->GetParamfv = null_GetParamfv;
        break;
    }
    effect->type = type;
}


#include "AL/efx-presets.h"

#define DECL(x) { #x, EFX_REVERB_PRESET_##x }
static const struct {
    const char name[32];
    EFXEAXREVERBPROPERTIES props;
} reverblist[] = {
    DECL(GENERIC),
    DECL(PADDEDCELL),
    DECL(ROOM),
    DECL(BATHROOM),
    DECL(LIVINGROOM),
    DECL(STONEROOM),
    DECL(AUDITORIUM),
    DECL(CONCERTHALL),
    DECL(CAVE),
    DECL(ARENA),
    DECL(HANGAR),
    DECL(CARPETTEDHALLWAY),
    DECL(HALLWAY),
    DECL(STONECORRIDOR),
    DECL(ALLEY),
    DECL(FOREST),
    DECL(CITY),
    DECL(MOUNTAINS),
    DECL(QUARRY),
    DECL(PLAIN),
    DECL(PARKINGLOT),
    DECL(SEWERPIPE),
    DECL(UNDERWATER),
    DECL(DRUGGED),
    DECL(DIZZY),
    DECL(PSYCHOTIC),

    DECL(CASTLE_SMALLROOM),
    DECL(CASTLE_SHORTPASSAGE),
    DECL(CASTLE_MEDIUMROOM),
    DECL(CASTLE_LARGEROOM),
    DECL(CASTLE_LONGPASSAGE),
    DECL(CASTLE_HALL),
    DECL(CASTLE_CUPBOARD),
    DECL(CASTLE_COURTYARD),
    DECL(CASTLE_ALCOVE),

    DECL(FACTORY_SMALLROOM),
    DECL(FACTORY_SHORTPASSAGE),
    DECL(FACTORY_MEDIUMROOM),
    DECL(FACTORY_LARGEROOM),
    DECL(FACTORY_LONGPASSAGE),
    DECL(FACTORY_HALL),
    DECL(FACTORY_CUPBOARD),
    DECL(FACTORY_COURTYARD),
    DECL(FACTORY_ALCOVE),

    DECL(ICEPALACE_SMALLROOM),
    DECL(ICEPALACE_SHORTPASSAGE),
    DECL(ICEPALACE_MEDIUMROOM),
    DECL(ICEPALACE_LARGEROOM),
    DECL(ICEPALACE_LONGPASSAGE),
    DECL(ICEPALACE_HALL),
    DECL(ICEPALACE_CUPBOARD),
    DECL(ICEPALACE_COURTYARD),
    DECL(ICEPALACE_ALCOVE),

    DECL(SPACESTATION_SMALLROOM),
    DECL(SPACESTATION_SHORTPASSAGE),
    DECL(SPACESTATION_MEDIUMROOM),
    DECL(SPACESTATION_LARGEROOM),
    DECL(SPACESTATION_LONGPASSAGE),
    DECL(SPACESTATION_HALL),
    DECL(SPACESTATION_CUPBOARD),
    DECL(SPACESTATION_ALCOVE),

    DECL(WOODEN_SMALLROOM),
    DECL(WOODEN_SHORTPASSAGE),
    DECL(WOODEN_MEDIUMROOM),
    DECL(WOODEN_LARGEROOM),
    DECL(WOODEN_LONGPASSAGE),
    DECL(WOODEN_HALL),
    DECL(WOODEN_CUPBOARD),
    DECL(WOODEN_COURTYARD),
    DECL(WOODEN_ALCOVE),

    DECL(SPORT_EMPTYSTADIUM),
    DECL(SPORT_SQUASHCOURT),
    DECL(SPORT_SMALLSWIMMINGPOOL),
    DECL(SPORT_LARGESWIMMINGPOOL),
    DECL(SPORT_GYMNASIUM),
    DECL(SPORT_FULLSTADIUM),
    DECL(SPORT_STADIUMTANNOY),

    DECL(PREFAB_WORKSHOP),
    DECL(PREFAB_SCHOOLROOM),
    DECL(PREFAB_PRACTISEROOM),
    DECL(PREFAB_OUTHOUSE),
    DECL(PREFAB_CARAVAN),

    DECL(DOME_TOMB),
    DECL(PIPE_SMALL),
    DECL(DOME_SAINTPAULS),
    DECL(PIPE_LONGTHIN),
    DECL(PIPE_LARGE),
    DECL(PIPE_RESONANT),

    DECL(OUTDOORS_BACKYARD),
    DECL(OUTDOORS_ROLLINGPLAINS),
    DECL(OUTDOORS_DEEPCANYON),
    DECL(OUTDOORS_CREEK),
    DECL(OUTDOORS_VALLEY),

    DECL(MOOD_HEAVEN),
    DECL(MOOD_HELL),
    DECL(MOOD_MEMORY),

    DECL(DRIVING_COMMENTATOR),
    DECL(DRIVING_PITGARAGE),
    DECL(DRIVING_INCAR_RACER),
    DECL(DRIVING_INCAR_SPORTS),
    DECL(DRIVING_INCAR_LUXURY),
    DECL(DRIVING_FULLGRANDSTAND),
    DECL(DRIVING_EMPTYGRANDSTAND),
    DECL(DRIVING_TUNNEL),

    DECL(CITY_STREETS),
    DECL(CITY_SUBWAY),
    DECL(CITY_MUSEUM),
    DECL(CITY_LIBRARY),
    DECL(CITY_UNDERPASS),
    DECL(CITY_ABANDONED),

    DECL(DUSTYROOM),
    DECL(CHAPEL),
    DECL(SMALLWATERROOM),
};
#undef DECL
static const ALsizei reverblistsize = sizeof(reverblist)/sizeof(reverblist[0]);

ALvoid GetReverbEffect(const char *name, ALeffect *effect)
{
    int i;

    if(!DisabledEffects[EAXREVERB])
        InitEffectParams(effect, AL_EFFECT_EAXREVERB);
    else if(!DisabledEffects[REVERB])
        InitEffectParams(effect, AL_EFFECT_REVERB);
    else
        InitEffectParams(effect, AL_EFFECT_NULL);
    for(i = 0;i < reverblistsize;i++)
    {
        const EFXEAXREVERBPROPERTIES *props;

        if(strcasecmp(name, reverblist[i].name) != 0)
            continue;

        TRACE("Loading reverb '%s'\n", reverblist[i].name);
        props = &reverblist[i].props;
        effect->Reverb.Density   = props->flDensity;
        effect->Reverb.Diffusion = props->flDiffusion;
        effect->Reverb.Gain   = props->flGain;
        effect->Reverb.GainHF = props->flGainHF;
        effect->Reverb.GainLF = props->flGainLF;
        effect->Reverb.DecayTime    = props->flDecayTime;
        effect->Reverb.DecayHFRatio = props->flDecayHFRatio;
        effect->Reverb.DecayLFRatio = props->flDecayLFRatio;
        effect->Reverb.ReflectionsGain   = props->flReflectionsGain;
        effect->Reverb.ReflectionsDelay  = props->flReflectionsDelay;
        effect->Reverb.ReflectionsPan[0] = props->flReflectionsPan[0];
        effect->Reverb.ReflectionsPan[1] = props->flReflectionsPan[1];
        effect->Reverb.ReflectionsPan[2] = props->flReflectionsPan[2];
        effect->Reverb.LateReverbGain   = props->flLateReverbGain;
        effect->Reverb.LateReverbDelay  = props->flLateReverbDelay;
        effect->Reverb.LateReverbPan[0] = props->flLateReverbPan[0];
        effect->Reverb.LateReverbPan[1] = props->flLateReverbPan[1];
        effect->Reverb.LateReverbPan[2] = props->flLateReverbPan[2];
        effect->Reverb.EchoTime  = props->flEchoTime;
        effect->Reverb.EchoDepth = props->flEchoDepth;
        effect->Reverb.ModulationTime  = props->flModulationTime;
        effect->Reverb.ModulationDepth = props->flModulationDepth;
        effect->Reverb.AirAbsorptionGainHF = props->flAirAbsorptionGainHF;
        effect->Reverb.HFReference = props->flHFReference;
        effect->Reverb.LFReference = props->flLFReference;
        effect->Reverb.RoomRolloffFactor = props->flRoomRolloffFactor;
        effect->Reverb.DecayHFLimit = props->iDecayHFLimit;
        break;
    }
    if(i == reverblistsize)
        WARN("Reverb preset '%s' not found\n", name);
}
