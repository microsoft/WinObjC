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

#include "AL/al.h"
#include "AL/alc.h"
#include "alMain.h"
#include "alFilter.h"
#include "alThunk.h"
#include "alError.h"


static void InitFilterParams(ALfilter *filter, ALenum type);


AL_API ALvoid AL_APIENTRY alGenFilters(ALsizei n, ALuint *filters)
{
    ALCcontext *Context;
    ALsizei i;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0 || IsBadWritePtr((void*)filters, n * sizeof(ALuint)))
        alSetError(Context, AL_INVALID_VALUE);
    else
    {
        ALCdevice *device = Context->Device;
        ALenum err;

        for(i = 0;i < n;i++)
        {
            ALfilter *filter = calloc(1, sizeof(ALfilter));
            if(!filter)
            {
                alSetError(Context, AL_OUT_OF_MEMORY);
                alDeleteFilters(i, filters);
                break;
            }
            InitFilterParams(filter, AL_FILTER_NULL);

            err = NewThunkEntry(&filter->filter);
            if(err == AL_NO_ERROR)
                err = InsertUIntMapEntry(&device->FilterMap, filter->filter, filter);
            if(err != AL_NO_ERROR)
            {
                FreeThunkEntry(filter->filter);
                memset(filter, 0, sizeof(ALfilter));
                free(filter);

                alSetError(Context, err);
                alDeleteFilters(i, filters);
                break;
            }

            filters[i] = filter->filter;
        }
    }

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alDeleteFilters(ALsizei n, const ALuint *filters)
{
    ALCcontext *Context;
    ALCdevice *device;
    ALfilter *ALFilter;
    ALsizei i;

    Context = GetContextRef();
    if(!Context) return;

    device = Context->Device;
    if(n < 0)
        alSetError(Context, AL_INVALID_VALUE);
    else
    {
        // Check that all filters are valid
        for(i = 0;i < n;i++)
        {
            if(!filters[i])
                continue;

            if(LookupFilter(device, filters[i]) == NULL)
            {
                alSetError(Context, AL_INVALID_NAME);
                n = 0;
                break;
            }
        }

        for(i = 0;i < n;i++)
        {
            // Recheck that the filter is valid, because there could be duplicated names
            if((ALFilter=RemoveFilter(device, filters[i])) == NULL)
                continue;
            FreeThunkEntry(ALFilter->filter);

            memset(ALFilter, 0, sizeof(ALfilter));
            free(ALFilter);
        }
    }

    ALCcontext_DecRef(Context);
}

AL_API ALboolean AL_APIENTRY alIsFilter(ALuint filter)
{
    ALCcontext *Context;
    ALboolean  result;

    Context = GetContextRef();
    if(!Context) return AL_FALSE;

    result = ((!filter || LookupFilter(Context->Device, filter)) ?
              AL_TRUE : AL_FALSE);

    ALCcontext_DecRef(Context);

    return result;
}

AL_API ALvoid AL_APIENTRY alFilteri(ALuint filter, ALenum param, ALint iValue)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALfilter   *ALFilter;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALFilter=LookupFilter(Device, filter)) != NULL)
    {
        switch(param)
        {
        case AL_FILTER_TYPE:
            if(iValue == AL_FILTER_NULL || iValue == AL_FILTER_LOWPASS)
                InitFilterParams(ALFilter, iValue);
            else
                alSetError(Context, AL_INVALID_VALUE);
            break;

        default:
            /* Call the appropriate handler */
            ALfilter_SetParami(ALFilter, Context, param, iValue);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alFilteriv(ALuint filter, ALenum param, const ALint *piValues)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALfilter   *ALFilter;

    switch(param)
    {
        case AL_FILTER_TYPE:
            alFilteri(filter, param, piValues[0]);
            return;
    }

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALFilter=LookupFilter(Device, filter)) != NULL)
    {
        /* Call the appropriate handler */
        ALfilter_SetParamiv(ALFilter, Context, param, piValues);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alFilterf(ALuint filter, ALenum param, ALfloat flValue)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALfilter   *ALFilter;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALFilter=LookupFilter(Device, filter)) != NULL)
    {
        /* Call the appropriate handler */
        ALfilter_SetParamf(ALFilter, Context, param, flValue);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alFilterfv(ALuint filter, ALenum param, const ALfloat *pflValues)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALfilter   *ALFilter;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALFilter=LookupFilter(Device, filter)) != NULL)
    {
        /* Call the appropriate handler */
        ALfilter_SetParamfv(ALFilter, Context, param, pflValues);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetFilteri(ALuint filter, ALenum param, ALint *piValue)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALfilter   *ALFilter;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALFilter=LookupFilter(Device, filter)) != NULL)
    {
        switch(param)
        {
        case AL_FILTER_TYPE:
            *piValue = ALFilter->type;
            break;

        default:
            /* Call the appropriate handler */
            ALfilter_GetParami(ALFilter, Context, param, piValue);
            break;
        }
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetFilteriv(ALuint filter, ALenum param, ALint *piValues)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALfilter   *ALFilter;

    switch(param)
    {
        case AL_FILTER_TYPE:
            alGetFilteri(filter, param, piValues);
            return;
    }

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALFilter=LookupFilter(Device, filter)) != NULL)
    {
        /* Call the appropriate handler */
        ALfilter_GetParamiv(ALFilter, Context, param, piValues);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetFilterf(ALuint filter, ALenum param, ALfloat *pflValue)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALfilter   *ALFilter;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALFilter=LookupFilter(Device, filter)) != NULL)
    {
        /* Call the appropriate handler */
        ALfilter_GetParamf(ALFilter, Context, param, pflValue);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alGetFilterfv(ALuint filter, ALenum param, ALfloat *pflValues)
{
    ALCcontext *Context;
    ALCdevice  *Device;
    ALfilter   *ALFilter;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if((ALFilter=LookupFilter(Device, filter)) != NULL)
    {
        /* Call the appropriate handler */
        ALfilter_GetParamfv(ALFilter, Context, param, pflValues);
    }
    else
        alSetError(Context, AL_INVALID_NAME);

    ALCcontext_DecRef(Context);
}


ALfloat lpCoeffCalc(ALfloat g, ALfloat cw)
{
    ALfloat a = 0.0f;

    /* Be careful with gains < 0.001, as that causes the coefficient head
     * towards 1, which will flatten the signal */
    if(g < 0.9999f) /* 1-epsilon */
    {
        g = maxf(g, 0.001f);
        a = (1 - g*cw - aluSqrt(2*g*(1-cw) - g*g*(1 - cw*cw))) /
            (1 - g);
    }

    return a;
}


static void lp_SetParami(ALfilter *filter, ALCcontext *context, ALenum param, ALint val)
{ (void)filter;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void lp_SetParamiv(ALfilter *filter, ALCcontext *context, ALenum param, const ALint *vals)
{ (void)filter;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }
static void lp_SetParamf(ALfilter *filter, ALCcontext *context, ALenum param, ALfloat val)
{
    switch(param)
    {
        case AL_LOWPASS_GAIN:
            if(val >= AL_LOWPASS_MIN_GAIN && val <= AL_LOWPASS_MAX_GAIN)
                filter->Gain = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        case AL_LOWPASS_GAINHF:
            if(val >= AL_LOWPASS_MIN_GAINHF && val <= AL_LOWPASS_MAX_GAINHF)
                filter->GainHF = val;
            else
                alSetError(context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void lp_SetParamfv(ALfilter *filter, ALCcontext *context, ALenum param, const ALfloat *vals)
{
    lp_SetParamf(filter, context, param, vals[0]);
}

static void lp_GetParami(ALfilter *filter, ALCcontext *context, ALenum param, ALint *val)
{ (void)filter;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void lp_GetParamiv(ALfilter *filter, ALCcontext *context, ALenum param, ALint *vals)
{ (void)filter;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }
static void lp_GetParamf(ALfilter *filter, ALCcontext *context, ALenum param, ALfloat *val)
{
    switch(param)
    {
        case AL_LOWPASS_GAIN:
            *val = filter->Gain;
            break;

        case AL_LOWPASS_GAINHF:
            *val = filter->GainHF;
            break;

        default:
            alSetError(context, AL_INVALID_ENUM);
            break;
    }
}
static void lp_GetParamfv(ALfilter *filter, ALCcontext *context, ALenum param, ALfloat *vals)
{
    lp_GetParamf(filter, context, param, vals);
}


static void null_SetParami(ALfilter *filter, ALCcontext *context, ALenum param, ALint val)
{ (void)filter;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void null_SetParamiv(ALfilter *filter, ALCcontext *context, ALenum param, const ALint *vals)
{ (void)filter;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }
static void null_SetParamf(ALfilter *filter, ALCcontext *context, ALenum param, ALfloat val)
{ (void)filter;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void null_SetParamfv(ALfilter *filter, ALCcontext *context, ALenum param, const ALfloat *vals)
{ (void)filter;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }

static void null_GetParami(ALfilter *filter, ALCcontext *context, ALenum param, ALint *val)
{ (void)filter;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void null_GetParamiv(ALfilter *filter, ALCcontext *context, ALenum param, ALint *vals)
{ (void)filter;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }
static void null_GetParamf(ALfilter *filter, ALCcontext *context, ALenum param, ALfloat *val)
{ (void)filter;(void)param;(void)val; alSetError(context, AL_INVALID_ENUM); }
static void null_GetParamfv(ALfilter *filter, ALCcontext *context, ALenum param, ALfloat *vals)
{ (void)filter;(void)param;(void)vals; alSetError(context, AL_INVALID_ENUM); }


ALvoid ReleaseALFilters(ALCdevice *device)
{
    ALsizei i;
    for(i = 0;i < device->FilterMap.size;i++)
    {
        ALfilter *temp = device->FilterMap.array[i].value;
        device->FilterMap.array[i].value = NULL;

        // Release filter structure
        FreeThunkEntry(temp->filter);
        memset(temp, 0, sizeof(ALfilter));
        free(temp);
    }
}


static void InitFilterParams(ALfilter *filter, ALenum type)
{
    if(type == AL_FILTER_LOWPASS)
    {
        filter->Gain = AL_LOWPASS_DEFAULT_GAIN;
        filter->GainHF = AL_LOWPASS_DEFAULT_GAINHF;

        filter->SetParami  = lp_SetParami;
        filter->SetParamiv = lp_SetParamiv;
        filter->SetParamf  = lp_SetParamf;
        filter->SetParamfv = lp_SetParamfv;
        filter->GetParami  = lp_GetParami;
        filter->GetParamiv = lp_GetParamiv;
        filter->GetParamf  = lp_GetParamf;
        filter->GetParamfv = lp_GetParamfv;
    }
    else
    {
        filter->SetParami  = null_SetParami;
        filter->SetParamiv = null_SetParamiv;
        filter->SetParamf  = null_SetParamf;
        filter->SetParamfv = null_SetParamfv;
        filter->GetParami  = null_GetParami;
        filter->GetParamiv = null_GetParamiv;
        filter->GetParamf  = null_GetParamf;
        filter->GetParamfv = null_GetParamfv;
    }
    filter->type = type;
}
