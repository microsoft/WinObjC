/**
 * OpenAL cross platform audio library
 * Copyright (C) 1999-2000 by authors.
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
#include "AL/alc.h"
#include "AL/alext.h"
#include "alError.h"
#include "alSource.h"
#include "alAuxEffectSlot.h"
#include "alState.h"

static const ALchar alVendor[] = "OpenAL Community";
static const ALchar alVersion[] = "1.1 ALSOFT "ALSOFT_VERSION;
static const ALchar alRenderer[] = "OpenAL Soft";

// Error Messages
static const ALchar alNoError[] = "No Error";
static const ALchar alErrInvalidName[] = "Invalid Name";
static const ALchar alErrInvalidEnum[] = "Invalid Enum";
static const ALchar alErrInvalidValue[] = "Invalid Value";
static const ALchar alErrInvalidOp[] = "Invalid Operation";
static const ALchar alErrOutOfMemory[] = "Out of Memory";

AL_API ALvoid AL_APIENTRY alEnable(ALenum capability)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    switch(capability)
    {
        case AL_SOURCE_DISTANCE_MODEL:
            Context->SourceDistanceModel = AL_TRUE;
            Context->UpdateSources = AL_TRUE;
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alDisable(ALenum capability)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    switch(capability)
    {
        case AL_SOURCE_DISTANCE_MODEL:
            Context->SourceDistanceModel = AL_FALSE;
            Context->UpdateSources = AL_TRUE;
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);
}

AL_API ALboolean AL_APIENTRY alIsEnabled(ALenum capability)
{
    ALCcontext *Context;
    ALboolean value=AL_FALSE;

    Context = GetContextRef();
    if(!Context) return AL_FALSE;

    switch(capability)
    {
        case AL_SOURCE_DISTANCE_MODEL:
            value = Context->SourceDistanceModel;
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);

    return value;
}

AL_API ALboolean AL_APIENTRY alGetBoolean(ALenum pname)
{
    ALCcontext *Context;
    ALboolean value=AL_FALSE;

    Context = GetContextRef();
    if(!Context) return AL_FALSE;

    switch(pname)
    {
        case AL_DOPPLER_FACTOR:
            if(Context->DopplerFactor != 0.0f)
                value = AL_TRUE;
            break;

        case AL_DOPPLER_VELOCITY:
            if(Context->DopplerVelocity != 0.0f)
                value = AL_TRUE;
            break;

        case AL_DISTANCE_MODEL:
            if(Context->DistanceModel == AL_INVERSE_DISTANCE_CLAMPED)
                value = AL_TRUE;
            break;

        case AL_SPEED_OF_SOUND:
            if(Context->flSpeedOfSound != 0.0f)
                value = AL_TRUE;
            break;

        case AL_DEFERRED_UPDATES_SOFT:
            value = Context->DeferUpdates;
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);

    return value;
}

AL_API ALdouble AL_APIENTRY alGetDouble(ALenum pname)
{
    ALCcontext *Context;
    ALdouble value = 0.0;

    Context = GetContextRef();
    if(!Context) return 0.0;

    switch(pname)
    {
        case AL_DOPPLER_FACTOR:
            value = (double)Context->DopplerFactor;
            break;

        case AL_DOPPLER_VELOCITY:
            value = (double)Context->DopplerVelocity;
            break;

        case AL_DISTANCE_MODEL:
            value = (double)Context->DistanceModel;
            break;

        case AL_SPEED_OF_SOUND:
            value = (double)Context->flSpeedOfSound;
            break;

        case AL_DEFERRED_UPDATES_SOFT:
            value = (ALdouble)Context->DeferUpdates;
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);

    return value;
}

AL_API ALfloat AL_APIENTRY alGetFloat(ALenum pname)
{
    ALCcontext *Context;
    ALfloat value = 0.0f;

    Context = GetContextRef();
    if(!Context) return 0.0f;

    switch(pname)
    {
        case AL_DOPPLER_FACTOR:
            value = Context->DopplerFactor;
            break;

        case AL_DOPPLER_VELOCITY:
            value = Context->DopplerVelocity;
            break;

        case AL_DISTANCE_MODEL:
            value = (float)Context->DistanceModel;
            break;

        case AL_SPEED_OF_SOUND:
            value = Context->flSpeedOfSound;
            break;

        case AL_DEFERRED_UPDATES_SOFT:
            value = (ALfloat)Context->DeferUpdates;
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);

    return value;
}

AL_API ALint AL_APIENTRY alGetInteger(ALenum pname)
{
    ALCcontext *Context;
    ALint value = 0;

    Context = GetContextRef();
    if(!Context) return 0;

    switch(pname)
    {
        case AL_DOPPLER_FACTOR:
            value = (ALint)Context->DopplerFactor;
            break;

        case AL_DOPPLER_VELOCITY:
            value = (ALint)Context->DopplerVelocity;
            break;

        case AL_DISTANCE_MODEL:
            value = (ALint)Context->DistanceModel;
            break;

        case AL_SPEED_OF_SOUND:
            value = (ALint)Context->flSpeedOfSound;
            break;

        case AL_DEFERRED_UPDATES_SOFT:
            value = (ALint)Context->DeferUpdates;
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);

    return value;
}

AL_API ALvoid AL_APIENTRY alGetBooleanv(ALenum pname,ALboolean *data)
{
    ALCcontext *Context;

    if(data)
    {
        switch(pname)
        {
            case AL_DOPPLER_FACTOR:
            case AL_DOPPLER_VELOCITY:
            case AL_DISTANCE_MODEL:
            case AL_SPEED_OF_SOUND:
            case AL_DEFERRED_UPDATES_SOFT:
                *data = alGetBoolean(pname);
                return;
        }
    }

    Context = GetContextRef();
    if(!Context) return;

    if(data)
    {
        switch(pname)
        {
            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
    {
        // data is a NULL pointer
        alSetError(Context, AL_INVALID_VALUE);
    }

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetDoublev(ALenum pname,ALdouble *data)
{
    ALCcontext *Context;

    if(data)
    {
        switch(pname)
        {
            case AL_DOPPLER_FACTOR:
            case AL_DOPPLER_VELOCITY:
            case AL_DISTANCE_MODEL:
            case AL_SPEED_OF_SOUND:
            case AL_DEFERRED_UPDATES_SOFT:
                *data = alGetDouble(pname);
                return;
        }
    }

    Context = GetContextRef();
    if(!Context) return;

    if(data)
    {
        switch(pname)
        {
            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
    {
        // data is a NULL pointer
        alSetError(Context, AL_INVALID_VALUE);
    }

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetFloatv(ALenum pname,ALfloat *data)
{
    ALCcontext *Context;

    if(data)
    {
        switch(pname)
        {
            case AL_DOPPLER_FACTOR:
            case AL_DOPPLER_VELOCITY:
            case AL_DISTANCE_MODEL:
            case AL_SPEED_OF_SOUND:
            case AL_DEFERRED_UPDATES_SOFT:
                *data = alGetFloat(pname);
                return;
        }
    }

    Context = GetContextRef();
    if(!Context) return;

    if(data)
    {
        switch(pname)
        {
            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
    {
        // data is a NULL pointer
        alSetError(Context, AL_INVALID_VALUE);
    }

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetIntegerv(ALenum pname,ALint *data)
{
    ALCcontext *Context;

    if(data)
    {
        switch(pname)
        {
            case AL_DOPPLER_FACTOR:
            case AL_DOPPLER_VELOCITY:
            case AL_DISTANCE_MODEL:
            case AL_SPEED_OF_SOUND:
            case AL_DEFERRED_UPDATES_SOFT:
                *data = alGetInteger(pname);
                return;
        }
    }

    Context = GetContextRef();
    if(!Context) return;

    if(data)
    {
        switch(pname)
        {
            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
    {
        // data is a NULL pointer
        alSetError(Context, AL_INVALID_VALUE);
    }

    ALCcontext_DecRef(Context);
}

AL_API const ALchar* AL_APIENTRY alGetString(ALenum pname)
{
    const ALchar *value;
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return NULL;

    switch(pname)
    {
        case AL_VENDOR:
            value=alVendor;
            break;

        case AL_VERSION:
            value=alVersion;
            break;

        case AL_RENDERER:
            value=alRenderer;
            break;

        case AL_EXTENSIONS:
            value=Context->ExtensionList;
            break;

        case AL_NO_ERROR:
            value=alNoError;
            break;

        case AL_INVALID_NAME:
            value=alErrInvalidName;
            break;

        case AL_INVALID_ENUM:
            value=alErrInvalidEnum;
            break;

        case AL_INVALID_VALUE:
            value=alErrInvalidValue;
            break;

        case AL_INVALID_OPERATION:
            value=alErrInvalidOp;
            break;

        case AL_OUT_OF_MEMORY:
            value=alErrOutOfMemory;
            break;

        default:
            value=NULL;
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);

    return value;
}

AL_API ALvoid AL_APIENTRY alDopplerFactor(ALfloat value)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    if(value >= 0.0f && isfinite(value))
    {
        Context->DopplerFactor = value;
        Context->UpdateSources = AL_TRUE;
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alDopplerVelocity(ALfloat value)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    if(value > 0.0f && isfinite(value))
    {
        Context->DopplerVelocity=value;
        Context->UpdateSources = AL_TRUE;
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alSpeedOfSound(ALfloat flSpeedOfSound)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    if(flSpeedOfSound > 0.0f && isfinite(flSpeedOfSound))
    {
        Context->flSpeedOfSound = flSpeedOfSound;
        Context->UpdateSources = AL_TRUE;
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alDistanceModel(ALenum value)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    switch(value)
    {
        case AL_NONE:
        case AL_INVERSE_DISTANCE:
        case AL_INVERSE_DISTANCE_CLAMPED:
        case AL_LINEAR_DISTANCE:
        case AL_LINEAR_DISTANCE_CLAMPED:
        case AL_EXPONENT_DISTANCE:
        case AL_EXPONENT_DISTANCE_CLAMPED:
            Context->DistanceModel = value;
            Context->UpdateSources = AL_TRUE;
            break;

        default:
            alSetError(Context, AL_INVALID_VALUE);
            break;
    }

    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alDeferUpdatesSOFT(void)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    if(!Context->DeferUpdates)
    {
        ALboolean UpdateSources;
        ALsource **src, **src_end;
        ALeffectslot **slot, **slot_end;
        int fpuState;

        fpuState = SetMixerFPUMode();

        LockContext(Context);
        Context->DeferUpdates = AL_TRUE;

        /* Make sure all pending updates are performed */
        UpdateSources = ExchangeInt(&Context->UpdateSources, AL_FALSE);

        src = Context->ActiveSources;
        src_end = src + Context->ActiveSourceCount;
        while(src != src_end)
        {
            if((*src)->state != AL_PLAYING)
            {
                Context->ActiveSourceCount--;
                *src = *(--src_end);
                continue;
            }

            if(ExchangeInt(&(*src)->NeedsUpdate, AL_FALSE) || UpdateSources)
                ALsource_Update(*src, Context);

            src++;
        }

        slot = Context->ActiveEffectSlots;
        slot_end = slot + Context->ActiveEffectSlotCount;
        while(slot != slot_end)
        {
            if(ExchangeInt(&(*slot)->NeedsUpdate, AL_FALSE))
                ALeffectState_Update((*slot)->EffectState, Context, *slot);
            slot++;
        }

        UnlockContext(Context);
        RestoreFPUMode(fpuState);
    }

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alProcessUpdatesSOFT(void)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    if(ExchangeInt(&Context->DeferUpdates, AL_FALSE))
    {
        ALsizei pos;

        LockContext(Context);
        LockUIntMapRead(&Context->SourceMap);
        for(pos = 0;pos < Context->SourceMap.size;pos++)
        {
            ALsource *Source = Context->SourceMap.array[pos].value;
            ALenum new_state;

            if((Source->state == AL_PLAYING || Source->state == AL_PAUSED) &&
               Source->lOffset != -1)
                ApplyOffset(Source);

            new_state = ExchangeInt(&Source->new_state, AL_NONE);
            if(new_state)
                SetSourceState(Source, Context, new_state);
        }
        UnlockUIntMapRead(&Context->SourceMap);
        UnlockContext(Context);
    }

    ALCcontext_DecRef(Context);
}
