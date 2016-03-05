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
#include <float.h>
#include "alMain.h"
#include "AL/al.h"
#include "AL/alc.h"
#include "alError.h"
#include "alSource.h"
#include "alBuffer.h"
#include "alThunk.h"
#include "alAuxEffectSlot.h"


enum Resampler DefaultResampler = RESAMPLER_DEFAULT;
const ALsizei ResamplerPadding[RESAMPLER_MAX] = {
    0, /* Point */
    1, /* Linear */
    2, /* Cubic */
};
const ALsizei ResamplerPrePadding[RESAMPLER_MAX] = {
    0, /* Point */
    0, /* Linear */
    1, /* Cubic */
};


static ALvoid InitSourceParams(ALsource *Source);
static ALvoid GetSourceOffset(ALsource *Source, ALenum eName, ALdouble *Offsets, ALdouble updateLen);
static ALint GetSampleOffset(ALsource *Source);


AL_API ALvoid AL_APIENTRY alGenSources(ALsizei n,ALuint *sources)
{
    ALCcontext *Context;
    ALCdevice *Device;

    Context = GetContextRef();
    if(!Context) return;

    Device = Context->Device;
    if(n < 0 || IsBadWritePtr((void*)sources, n * sizeof(ALuint)))
        alSetError(Context, AL_INVALID_VALUE);
    else
    {
        ALenum err;
        ALsizei i;

        // Add additional sources to the list
        i = 0;
        while(i < n)
        {
            ALsource *source = calloc(1, sizeof(ALsource));
            if(!source)
            {
                alSetError(Context, AL_OUT_OF_MEMORY);
                alDeleteSources(i, sources);
                break;
            }
            InitSourceParams(source);

            err = NewThunkEntry(&source->source);
            if(err == AL_NO_ERROR)
                err = InsertUIntMapEntry(&Context->SourceMap, source->source, source);
            if(err != AL_NO_ERROR)
            {
                FreeThunkEntry(source->source);
                memset(source, 0, sizeof(ALsource));
                free(source);

                alSetError(Context, err);
                alDeleteSources(i, sources);
                break;
            }

            sources[i++] = source->source;
        }
    }

    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alDeleteSources(ALsizei n, const ALuint *sources)
{
    ALCcontext *Context;
    ALsource *Source;
    ALsizei i, j;
    ALbufferlistitem *BufferList;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0)
        alSetError(Context, AL_INVALID_VALUE);
    else
    {
        // Check that all Sources are valid (and can therefore be deleted)
        for(i = 0;i < n;i++)
        {
            if(LookupSource(Context, sources[i]) == NULL)
            {
                alSetError(Context, AL_INVALID_NAME);
                n = 0;
                break;
            }
        }

        // All Sources are valid, and can be deleted
        for(i = 0;i < n;i++)
        {
            ALsource **srclist, **srclistend;

            // Remove Source from list of Sources
            if((Source=RemoveSource(Context, sources[i])) == NULL)
                continue;

            FreeThunkEntry(Source->source);

            LockContext(Context);
            srclist = Context->ActiveSources;
            srclistend = srclist + Context->ActiveSourceCount;
            while(srclist != srclistend)
            {
                if(*srclist == Source)
                {
                    Context->ActiveSourceCount--;
                    *srclist = *(--srclistend);
                    break;
                }
                srclist++;
            }
            UnlockContext(Context);

            // For each buffer in the source's queue...
            while(Source->queue != NULL)
            {
                BufferList = Source->queue;
                Source->queue = BufferList->next;

                if(BufferList->buffer != NULL)
                    DecrementRef(&BufferList->buffer->ref);
                free(BufferList);
            }

            for(j = 0;j < MAX_SENDS;++j)
            {
                if(Source->Send[j].Slot)
                    DecrementRef(&Source->Send[j].Slot->ref);
                Source->Send[j].Slot = NULL;
            }

            memset(Source,0,sizeof(ALsource));
            free(Source);
        }
    }

    ALCcontext_DecRef(Context);
}


AL_API ALboolean AL_APIENTRY alIsSource(ALuint source)
{
    ALCcontext *Context;
    ALboolean  result;

    Context = GetContextRef();
    if(!Context) return AL_FALSE;

    result = (LookupSource(Context, source) ? AL_TRUE : AL_FALSE);

    ALCcontext_DecRef(Context);

    return result;
}


AL_API ALvoid AL_APIENTRY alSourcef(ALuint source, ALenum eParam, ALfloat flValue)
{
    ALCcontext *pContext;
    ALsource   *Source;

    pContext = GetContextRef();
    if(!pContext) return;

    if((Source=LookupSource(pContext, source)) != NULL)
    {
        switch(eParam)
        {
            case AL_PITCH:
                if(flValue >= 0.0f)
                {
                    Source->flPitch = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_CONE_INNER_ANGLE:
                if(flValue >= 0.0f && flValue <= 360.0f)
                {
                    Source->flInnerAngle = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_CONE_OUTER_ANGLE:
                if(flValue >= 0.0f && flValue <= 360.0f)
                {
                    Source->flOuterAngle = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_GAIN:
                if(flValue >= 0.0f)
                {
                    Source->flGain = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_MAX_DISTANCE:
                if(flValue >= 0.0f)
                {
                    Source->flMaxDistance = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_ROLLOFF_FACTOR:
                if(flValue >= 0.0f)
                {
                    Source->flRollOffFactor = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_REFERENCE_DISTANCE:
                if(flValue >= 0.0f)
                {
                    Source->flRefDistance = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_MIN_GAIN:
                if(flValue >= 0.0f && flValue <= 1.0f)
                {
                    Source->flMinGain = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_MAX_GAIN:
                if(flValue >= 0.0f && flValue <= 1.0f)
                {
                    Source->flMaxGain = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_CONE_OUTER_GAIN:
                if(flValue >= 0.0f && flValue <= 1.0f)
                {
                    Source->flOuterGain = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_CONE_OUTER_GAINHF:
                if(flValue >= 0.0f && flValue <= 1.0f)
                {
                    Source->OuterGainHF = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_AIR_ABSORPTION_FACTOR:
                if(flValue >= 0.0f && flValue <= 10.0f)
                {
                    Source->AirAbsorptionFactor = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_ROOM_ROLLOFF_FACTOR:
                if(flValue >= 0.0f && flValue <= 10.0f)
                {
                    Source->RoomRolloffFactor = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_DOPPLER_FACTOR:
                if(flValue >= 0.0f && flValue <= 1.0f)
                {
                    Source->DopplerFactor = flValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_SEC_OFFSET:
            case AL_SAMPLE_OFFSET:
            case AL_BYTE_OFFSET:
                if(flValue >= 0.0f)
                {
                    LockContext(pContext);
                    Source->lOffsetType = eParam;

                    // Store Offset (convert Seconds into Milliseconds)
                    if(eParam == AL_SEC_OFFSET)
                        Source->lOffset = (ALint)(flValue * 1000.0f);
                    else
                        Source->lOffset = (ALint)flValue;

                    if((Source->state == AL_PLAYING || Source->state == AL_PAUSED) &&
                       !pContext->DeferUpdates)
                    {
                        if(ApplyOffset(Source) == AL_FALSE)
                            alSetError(pContext, AL_INVALID_VALUE);
                    }
                    UnlockContext(pContext);
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            default:
                alSetError(pContext, AL_INVALID_ENUM);
                break;
        }
    }
    else
    {
        // Invalid Source Name
        alSetError(pContext, AL_INVALID_NAME);
    }

    ALCcontext_DecRef(pContext);
}


AL_API ALvoid AL_APIENTRY alSource3f(ALuint source, ALenum eParam, ALfloat flValue1,ALfloat flValue2,ALfloat flValue3)
{
    ALCcontext *pContext;
    ALsource   *Source;

    pContext = GetContextRef();
    if(!pContext) return;

    if((Source=LookupSource(pContext, source)) != NULL)
    {
        switch(eParam)
        {
            case AL_POSITION:
                if(isfinite(flValue1) && isfinite(flValue2) && isfinite(flValue3))
                {
                    LockContext(pContext);
                    Source->vPosition[0] = flValue1;
                    Source->vPosition[1] = flValue2;
                    Source->vPosition[2] = flValue3;
                    UnlockContext(pContext);
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_VELOCITY:
                if(isfinite(flValue1) && isfinite(flValue2) && isfinite(flValue3))
                {
                    LockContext(pContext);
                    Source->vVelocity[0] = flValue1;
                    Source->vVelocity[1] = flValue2;
                    Source->vVelocity[2] = flValue3;
                    UnlockContext(pContext);
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_DIRECTION:
                if(isfinite(flValue1) && isfinite(flValue2) && isfinite(flValue3))
                {
                    LockContext(pContext);
                    Source->vOrientation[0] = flValue1;
                    Source->vOrientation[1] = flValue2;
                    Source->vOrientation[2] = flValue3;
                    UnlockContext(pContext);
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            default:
                alSetError(pContext, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(pContext, AL_INVALID_NAME);

    ALCcontext_DecRef(pContext);
}


AL_API ALvoid AL_APIENTRY alSourcefv(ALuint source, ALenum eParam, const ALfloat *pflValues)
{
    ALCcontext *pContext;

    if(pflValues)
    {
        switch(eParam)
        {
            case AL_PITCH:
            case AL_CONE_INNER_ANGLE:
            case AL_CONE_OUTER_ANGLE:
            case AL_GAIN:
            case AL_MAX_DISTANCE:
            case AL_ROLLOFF_FACTOR:
            case AL_REFERENCE_DISTANCE:
            case AL_MIN_GAIN:
            case AL_MAX_GAIN:
            case AL_CONE_OUTER_GAIN:
            case AL_CONE_OUTER_GAINHF:
            case AL_SEC_OFFSET:
            case AL_SAMPLE_OFFSET:
            case AL_BYTE_OFFSET:
            case AL_AIR_ABSORPTION_FACTOR:
            case AL_ROOM_ROLLOFF_FACTOR:
                alSourcef(source, eParam, pflValues[0]);
                return;

            case AL_POSITION:
            case AL_VELOCITY:
            case AL_DIRECTION:
                alSource3f(source, eParam, pflValues[0], pflValues[1], pflValues[2]);
                return;
        }
    }

    pContext = GetContextRef();
    if(!pContext) return;

    if(pflValues)
    {
        if(LookupSource(pContext, source) != NULL)
        {
            switch(eParam)
            {
                default:
                    alSetError(pContext, AL_INVALID_ENUM);
                    break;
            }
        }
        else
            alSetError(pContext, AL_INVALID_NAME);
    }
    else
        alSetError(pContext, AL_INVALID_VALUE);

    ALCcontext_DecRef(pContext);
}


AL_API ALvoid AL_APIENTRY alSourcei(ALuint source,ALenum eParam,ALint lValue)
{
    ALCcontext       *pContext;
    ALsource         *Source;
    ALbufferlistitem *BufferListItem;

    switch(eParam)
    {
        case AL_MAX_DISTANCE:
        case AL_ROLLOFF_FACTOR:
        case AL_CONE_INNER_ANGLE:
        case AL_CONE_OUTER_ANGLE:
        case AL_REFERENCE_DISTANCE:
            alSourcef(source, eParam, (ALfloat)lValue);
            return;
    }

    pContext = GetContextRef();
    if(!pContext) return;

    if((Source=LookupSource(pContext, source)) != NULL)
    {
        ALCdevice *device = pContext->Device;

        switch(eParam)
        {
            case AL_SOURCE_RELATIVE:
                if(lValue == AL_FALSE || lValue == AL_TRUE)
                {
                    Source->bHeadRelative = (ALboolean)lValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_LOOPING:
                if(lValue == AL_FALSE || lValue == AL_TRUE)
                    Source->bLooping = (ALboolean)lValue;
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_BUFFER:
                LockContext(pContext);
                if(Source->state == AL_STOPPED || Source->state == AL_INITIAL)
                {
                    ALbufferlistitem *oldlist;
                    ALbuffer *buffer = NULL;

                    if(lValue == 0 || (buffer=LookupBuffer(device, lValue)) != NULL)
                    {
                        Source->BuffersInQueue = 0;
                        Source->BuffersPlayed = 0;

                        // Add the buffer to the queue (as long as it is NOT the NULL buffer)
                        if(buffer != NULL)
                        {
                            // Source is now in STATIC mode
                            Source->lSourceType = AL_STATIC;

                            // Add the selected buffer to the queue
                            BufferListItem = malloc(sizeof(ALbufferlistitem));
                            BufferListItem->buffer = buffer;
                            BufferListItem->next = NULL;
                            BufferListItem->prev = NULL;
                            // Increment reference counter for buffer
                            IncrementRef(&buffer->ref);

                            oldlist = ExchangePtr((XchgPtr*)&Source->queue, BufferListItem);
                            Source->BuffersInQueue = 1;

                            ReadLock(&buffer->lock);
                            Source->NumChannels = ChannelsFromFmt(buffer->FmtChannels);
                            Source->SampleSize  = BytesFromFmt(buffer->FmtType);
                            ReadUnlock(&buffer->lock);
                            if(buffer->FmtChannels == FmtMono)
                                Source->Update = CalcSourceParams;
                            else
                                Source->Update = CalcNonAttnSourceParams;
                            Source->NeedsUpdate = AL_TRUE;
                        }
                        else
                        {
                            // Source is now in UNDETERMINED mode
                            Source->lSourceType = AL_UNDETERMINED;
                            oldlist = ExchangePtr((XchgPtr*)&Source->queue, NULL);
                        }

                        // Delete all previous elements in the queue
                        while(oldlist != NULL)
                        {
                            BufferListItem = oldlist;
                            oldlist = BufferListItem->next;

                            if(BufferListItem->buffer)
                                DecrementRef(&BufferListItem->buffer->ref);
                            free(BufferListItem);
                        }
                    }
                    else
                        alSetError(pContext, AL_INVALID_VALUE);
                }
                else
                    alSetError(pContext, AL_INVALID_OPERATION);
                UnlockContext(pContext);
                break;

            case AL_SOURCE_STATE:
                // Query only
                alSetError(pContext, AL_INVALID_OPERATION);
                break;

            case AL_SEC_OFFSET:
            case AL_SAMPLE_OFFSET:
            case AL_BYTE_OFFSET:
                if(lValue >= 0)
                {
                    LockContext(pContext);
                    Source->lOffsetType = eParam;

                    // Store Offset (convert Seconds into Milliseconds)
                    if(eParam == AL_SEC_OFFSET)
                        Source->lOffset = lValue * 1000;
                    else
                        Source->lOffset = lValue;

                    if((Source->state == AL_PLAYING || Source->state == AL_PAUSED) &&
                       !pContext->DeferUpdates)
                    {
                        if(ApplyOffset(Source) == AL_FALSE)
                            alSetError(pContext, AL_INVALID_VALUE);
                    }
                    UnlockContext(pContext);
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_DIRECT_FILTER: {
                ALfilter *filter = NULL;

                if(lValue == 0 || (filter=LookupFilter(pContext->Device, lValue)) != NULL)
                {
                    LockContext(pContext);
                    if(!filter)
                    {
                        Source->DirectGain = 1.0f;
                        Source->DirectGainHF = 1.0f;
                    }
                    else
                    {
                        Source->DirectGain = filter->Gain;
                        Source->DirectGainHF = filter->GainHF;
                    }
                    UnlockContext(pContext);
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
            }   break;

            case AL_DIRECT_FILTER_GAINHF_AUTO:
                if(lValue == AL_TRUE || lValue == AL_FALSE)
                {
                    Source->DryGainHFAuto = lValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_AUXILIARY_SEND_FILTER_GAIN_AUTO:
                if(lValue == AL_TRUE || lValue == AL_FALSE)
                {
                    Source->WetGainAuto = lValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_AUXILIARY_SEND_FILTER_GAINHF_AUTO:
                if(lValue == AL_TRUE || lValue == AL_FALSE)
                {
                    Source->WetGainHFAuto = lValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_VIRTUAL_CHANNELS_SOFT:
                if(lValue == AL_TRUE || lValue == AL_FALSE)
                {
                    Source->VirtualChannels = lValue;
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            case AL_DISTANCE_MODEL:
                if(lValue == AL_NONE ||
                   lValue == AL_INVERSE_DISTANCE ||
                   lValue == AL_INVERSE_DISTANCE_CLAMPED ||
                   lValue == AL_LINEAR_DISTANCE ||
                   lValue == AL_LINEAR_DISTANCE_CLAMPED ||
                   lValue == AL_EXPONENT_DISTANCE ||
                   lValue == AL_EXPONENT_DISTANCE_CLAMPED)
                {
                    Source->DistanceModel = lValue;
                    if(pContext->SourceDistanceModel)
                        Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                break;

            default:
                alSetError(pContext, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(pContext, AL_INVALID_NAME);

    ALCcontext_DecRef(pContext);
}


AL_API void AL_APIENTRY alSource3i(ALuint source, ALenum eParam, ALint lValue1, ALint lValue2, ALint lValue3)
{
    ALCcontext *pContext;
    ALsource   *Source;

    switch(eParam)
    {
        case AL_POSITION:
        case AL_VELOCITY:
        case AL_DIRECTION:
            alSource3f(source, eParam, (ALfloat)lValue1, (ALfloat)lValue2, (ALfloat)lValue3);
            return;
    }

    pContext = GetContextRef();
    if(!pContext) return;

    if((Source=LookupSource(pContext, source)) != NULL)
    {
        ALCdevice *device = pContext->Device;

        switch(eParam)
        {
            case AL_AUXILIARY_SEND_FILTER: {
                ALeffectslot *ALEffectSlot = NULL;
                ALfilter     *ALFilter = NULL;

                LockContext(pContext);
                if((ALuint)lValue2 < device->NumAuxSends &&
                   (lValue1 == 0 || (ALEffectSlot=LookupEffectSlot(pContext, lValue1)) != NULL) &&
                   (lValue3 == 0 || (ALFilter=LookupFilter(device, lValue3)) != NULL))
                {
                    /* Release refcount on the previous slot, and add one for
                     * the new slot */
                    if(ALEffectSlot) IncrementRef(&ALEffectSlot->ref);
                    ALEffectSlot = ExchangePtr((XchgPtr*)&Source->Send[lValue2].Slot, ALEffectSlot);
                    if(ALEffectSlot) DecrementRef(&ALEffectSlot->ref);

                    if(!ALFilter)
                    {
                        /* Disable filter */
                        Source->Send[lValue2].WetGain = 1.0f;
                        Source->Send[lValue2].WetGainHF = 1.0f;
                    }
                    else
                    {
                        Source->Send[lValue2].WetGain = ALFilter->Gain;
                        Source->Send[lValue2].WetGainHF = ALFilter->GainHF;
                    }
                    Source->NeedsUpdate = AL_TRUE;
                }
                else
                    alSetError(pContext, AL_INVALID_VALUE);
                UnlockContext(pContext);
            }   break;

            default:
                alSetError(pContext, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(pContext, AL_INVALID_NAME);

    ALCcontext_DecRef(pContext);
}


AL_API void AL_APIENTRY alSourceiv(ALuint source, ALenum eParam, const ALint* plValues)
{
    ALCcontext *pContext;

    if(plValues)
    {
        switch(eParam)
        {
            case AL_SOURCE_RELATIVE:
            case AL_CONE_INNER_ANGLE:
            case AL_CONE_OUTER_ANGLE:
            case AL_LOOPING:
            case AL_BUFFER:
            case AL_SOURCE_STATE:
            case AL_SEC_OFFSET:
            case AL_SAMPLE_OFFSET:
            case AL_BYTE_OFFSET:
            case AL_MAX_DISTANCE:
            case AL_ROLLOFF_FACTOR:
            case AL_REFERENCE_DISTANCE:
            case AL_DIRECT_FILTER:
            case AL_DIRECT_FILTER_GAINHF_AUTO:
            case AL_AUXILIARY_SEND_FILTER_GAIN_AUTO:
            case AL_AUXILIARY_SEND_FILTER_GAINHF_AUTO:
            case AL_DISTANCE_MODEL:
            case AL_VIRTUAL_CHANNELS_SOFT:
                alSourcei(source, eParam, plValues[0]);
                return;

            case AL_POSITION:
            case AL_VELOCITY:
            case AL_DIRECTION:
            case AL_AUXILIARY_SEND_FILTER:
                alSource3i(source, eParam, plValues[0], plValues[1], plValues[2]);
                return;
        }
    }

    pContext = GetContextRef();
    if(!pContext) return;

    if(plValues)
    {
        if(LookupSource(pContext, source) != NULL)
        {
            switch(eParam)
            {
                default:
                    alSetError(pContext, AL_INVALID_ENUM);
                    break;
            }
        }
        else
            alSetError(pContext, AL_INVALID_NAME);
    }
    else
        alSetError(pContext, AL_INVALID_VALUE);

    ALCcontext_DecRef(pContext);
}


AL_API ALvoid AL_APIENTRY alGetSourcef(ALuint source, ALenum eParam, ALfloat *pflValue)
{
    ALCcontext  *pContext;
    ALsource    *Source;
    ALdouble    Offsets[2];
    ALdouble    updateLen;

    pContext = GetContextRef();
    if(!pContext) return;

    if(pflValue)
    {
        if((Source=LookupSource(pContext, source)) != NULL)
        {
            switch(eParam)
            {
                case AL_PITCH:
                    *pflValue = Source->flPitch;
                    break;

                case AL_GAIN:
                    *pflValue = Source->flGain;
                    break;

                case AL_MIN_GAIN:
                    *pflValue = Source->flMinGain;
                    break;

                case AL_MAX_GAIN:
                    *pflValue = Source->flMaxGain;
                    break;

                case AL_MAX_DISTANCE:
                    *pflValue = Source->flMaxDistance;
                    break;

                case AL_ROLLOFF_FACTOR:
                    *pflValue = Source->flRollOffFactor;
                    break;

                case AL_CONE_OUTER_GAIN:
                    *pflValue = Source->flOuterGain;
                    break;

                case AL_CONE_OUTER_GAINHF:
                    *pflValue = Source->OuterGainHF;
                    break;

                case AL_SEC_OFFSET:
                case AL_SAMPLE_OFFSET:
                case AL_BYTE_OFFSET:
                    LockContext(pContext);
                    updateLen = (ALdouble)pContext->Device->UpdateSize /
                                pContext->Device->Frequency;
                    GetSourceOffset(Source, eParam, Offsets, updateLen);
                    UnlockContext(pContext);
                    *pflValue = (ALfloat)Offsets[0];
                    break;

                case AL_CONE_INNER_ANGLE:
                    *pflValue = Source->flInnerAngle;
                    break;

                case AL_CONE_OUTER_ANGLE:
                    *pflValue = Source->flOuterAngle;
                    break;

                case AL_REFERENCE_DISTANCE:
                    *pflValue = Source->flRefDistance;
                    break;

                case AL_AIR_ABSORPTION_FACTOR:
                    *pflValue = Source->AirAbsorptionFactor;
                    break;

                case AL_ROOM_ROLLOFF_FACTOR:
                    *pflValue = Source->RoomRolloffFactor;
                    break;

                case AL_DOPPLER_FACTOR:
                    *pflValue = Source->DopplerFactor;
                    break;

                default:
                    alSetError(pContext, AL_INVALID_ENUM);
                    break;
            }
        }
        else
            alSetError(pContext, AL_INVALID_NAME);
    }
    else
        alSetError(pContext, AL_INVALID_VALUE);

    ALCcontext_DecRef(pContext);
}


AL_API ALvoid AL_APIENTRY alGetSource3f(ALuint source, ALenum eParam, ALfloat* pflValue1, ALfloat* pflValue2, ALfloat* pflValue3)
{
    ALCcontext *pContext;
    ALsource   *Source;

    pContext = GetContextRef();
    if(!pContext) return;

    if(pflValue1 && pflValue2 && pflValue3)
    {
        if((Source=LookupSource(pContext, source)) != NULL)
        {
            switch(eParam)
            {
                case AL_POSITION:
                    LockContext(pContext);
                    *pflValue1 = Source->vPosition[0];
                    *pflValue2 = Source->vPosition[1];
                    *pflValue3 = Source->vPosition[2];
                    UnlockContext(pContext);
                    break;

                case AL_VELOCITY:
                    LockContext(pContext);
                    *pflValue1 = Source->vVelocity[0];
                    *pflValue2 = Source->vVelocity[1];
                    *pflValue3 = Source->vVelocity[2];
                    UnlockContext(pContext);
                    break;

                case AL_DIRECTION:
                    LockContext(pContext);
                    *pflValue1 = Source->vOrientation[0];
                    *pflValue2 = Source->vOrientation[1];
                    *pflValue3 = Source->vOrientation[2];
                    UnlockContext(pContext);
                    break;

                default:
                    alSetError(pContext, AL_INVALID_ENUM);
                    break;
            }
        }
        else
            alSetError(pContext, AL_INVALID_NAME);
    }
    else
        alSetError(pContext, AL_INVALID_VALUE);

    ALCcontext_DecRef(pContext);
}


AL_API ALvoid AL_APIENTRY alGetSourcefv(ALuint source, ALenum eParam, ALfloat *pflValues)
{
    ALCcontext  *pContext;
    ALsource    *Source;
    ALdouble    Offsets[2];
    ALdouble    updateLen;

    switch(eParam)
    {
        case AL_PITCH:
        case AL_GAIN:
        case AL_MIN_GAIN:
        case AL_MAX_GAIN:
        case AL_MAX_DISTANCE:
        case AL_ROLLOFF_FACTOR:
        case AL_DOPPLER_FACTOR:
        case AL_CONE_OUTER_GAIN:
        case AL_SEC_OFFSET:
        case AL_SAMPLE_OFFSET:
        case AL_BYTE_OFFSET:
        case AL_CONE_INNER_ANGLE:
        case AL_CONE_OUTER_ANGLE:
        case AL_REFERENCE_DISTANCE:
        case AL_CONE_OUTER_GAINHF:
        case AL_AIR_ABSORPTION_FACTOR:
        case AL_ROOM_ROLLOFF_FACTOR:
            alGetSourcef(source, eParam, pflValues);
            return;

        case AL_POSITION:
        case AL_VELOCITY:
        case AL_DIRECTION:
            alGetSource3f(source, eParam, pflValues+0, pflValues+1, pflValues+2);
            return;
    }

    pContext = GetContextRef();
    if(!pContext) return;

    if(pflValues)
    {
        if((Source=LookupSource(pContext, source)) != NULL)
        {
            switch(eParam)
            {
                case AL_SAMPLE_RW_OFFSETS_SOFT:
                case AL_BYTE_RW_OFFSETS_SOFT:
                    LockContext(pContext);
                    updateLen = (ALdouble)pContext->Device->UpdateSize /
                                pContext->Device->Frequency;
                    GetSourceOffset(Source, eParam, Offsets, updateLen);
                    UnlockContext(pContext);
                    pflValues[0] = (ALfloat)Offsets[0];
                    pflValues[1] = (ALfloat)Offsets[1];
                    break;

                default:
                    alSetError(pContext, AL_INVALID_ENUM);
                    break;
            }
        }
        else
            alSetError(pContext, AL_INVALID_NAME);
    }
    else
        alSetError(pContext, AL_INVALID_VALUE);

    ALCcontext_DecRef(pContext);
}


AL_API ALvoid AL_APIENTRY alGetSourcei(ALuint source, ALenum eParam, ALint *plValue)
{
    ALbufferlistitem *BufferList;
    ALCcontext *pContext;
    ALsource   *Source;
    ALdouble   Offsets[2];
    ALdouble   updateLen;

    pContext = GetContextRef();
    if(!pContext) return;

    if(plValue)
    {
        if((Source=LookupSource(pContext, source)) != NULL)
        {
            switch(eParam)
            {
                case AL_MAX_DISTANCE:
                    *plValue = (ALint)Source->flMaxDistance;
                    break;

                case AL_ROLLOFF_FACTOR:
                    *plValue = (ALint)Source->flRollOffFactor;
                    break;

                case AL_REFERENCE_DISTANCE:
                    *plValue = (ALint)Source->flRefDistance;
                    break;

                case AL_SOURCE_RELATIVE:
                    *plValue = Source->bHeadRelative;
                    break;

                case AL_CONE_INNER_ANGLE:
                    *plValue = (ALint)Source->flInnerAngle;
                    break;

                case AL_CONE_OUTER_ANGLE:
                    *plValue = (ALint)Source->flOuterAngle;
                    break;

                case AL_LOOPING:
                    *plValue = Source->bLooping;
                    break;

                case AL_BUFFER:
                    LockContext(pContext);
                    BufferList = Source->queue;
                    if(Source->lSourceType != AL_STATIC)
                    {
                        ALuint i = Source->BuffersPlayed;
                        while(i > 0)
                        {
                            BufferList = BufferList->next;
                            i--;
                        }
                    }
                    *plValue = ((BufferList && BufferList->buffer) ?
                                BufferList->buffer->buffer : 0);
                    UnlockContext(pContext);
                    break;

                case AL_SOURCE_STATE:
                    *plValue = Source->state;
                    break;

                case AL_BUFFERS_QUEUED:
                    *plValue = Source->BuffersInQueue;
                    break;

                case AL_BUFFERS_PROCESSED:
                    LockContext(pContext);
                    if(Source->bLooping || Source->lSourceType != AL_STREAMING)
                    {
                        /* Buffers on a looping source are in a perpetual state
                         * of PENDING, so don't report any as PROCESSED */
                        *plValue = 0;
                    }
                    else
                        *plValue = Source->BuffersPlayed;
                    UnlockContext(pContext);
                    break;

                case AL_SOURCE_TYPE:
                    *plValue = Source->lSourceType;
                    break;

                case AL_SEC_OFFSET:
                case AL_SAMPLE_OFFSET:
                case AL_BYTE_OFFSET:
                    LockContext(pContext);
                    updateLen = (ALdouble)pContext->Device->UpdateSize /
                                pContext->Device->Frequency;
                    GetSourceOffset(Source, eParam, Offsets, updateLen);
                    UnlockContext(pContext);
                    *plValue = (ALint)Offsets[0];
                    break;

                case AL_DIRECT_FILTER_GAINHF_AUTO:
                    *plValue = Source->DryGainHFAuto;
                    break;

                case AL_AUXILIARY_SEND_FILTER_GAIN_AUTO:
                    *plValue = Source->WetGainAuto;
                    break;

                case AL_AUXILIARY_SEND_FILTER_GAINHF_AUTO:
                    *plValue = Source->WetGainHFAuto;
                    break;

                case AL_DOPPLER_FACTOR:
                    *plValue = (ALint)Source->DopplerFactor;
                    break;

                case AL_VIRTUAL_CHANNELS_SOFT:
                    *plValue = Source->VirtualChannels;
                    break;

                case AL_DISTANCE_MODEL:
                    *plValue = Source->DistanceModel;
                    break;

                default:
                    alSetError(pContext, AL_INVALID_ENUM);
                    break;
            }
        }
        else
            alSetError(pContext, AL_INVALID_NAME);
    }
    else
        alSetError(pContext, AL_INVALID_VALUE);

    ALCcontext_DecRef(pContext);
}


AL_API void AL_APIENTRY alGetSource3i(ALuint source, ALenum eParam, ALint* plValue1, ALint* plValue2, ALint* plValue3)
{
    ALCcontext  *pContext;
    ALsource    *Source;

    pContext = GetContextRef();
    if(!pContext) return;

    if(plValue1 && plValue2 && plValue3)
    {
        if((Source=LookupSource(pContext, source)) != NULL)
        {
            switch(eParam)
            {
                case AL_POSITION:
                    LockContext(pContext);
                    *plValue1 = (ALint)Source->vPosition[0];
                    *plValue2 = (ALint)Source->vPosition[1];
                    *plValue3 = (ALint)Source->vPosition[2];
                    UnlockContext(pContext);
                    break;

                case AL_VELOCITY:
                    LockContext(pContext);
                    *plValue1 = (ALint)Source->vVelocity[0];
                    *plValue2 = (ALint)Source->vVelocity[1];
                    *plValue3 = (ALint)Source->vVelocity[2];
                    UnlockContext(pContext);
                    break;

                case AL_DIRECTION:
                    LockContext(pContext);
                    *plValue1 = (ALint)Source->vOrientation[0];
                    *plValue2 = (ALint)Source->vOrientation[1];
                    *plValue3 = (ALint)Source->vOrientation[2];
                    UnlockContext(pContext);
                    break;

                default:
                    alSetError(pContext, AL_INVALID_ENUM);
                    break;
            }
        }
        else
            alSetError(pContext, AL_INVALID_NAME);
    }
    else
        alSetError(pContext, AL_INVALID_VALUE);

    ALCcontext_DecRef(pContext);
}


AL_API void AL_APIENTRY alGetSourceiv(ALuint source, ALenum eParam, ALint* plValues)
{
    ALCcontext  *pContext;
    ALsource    *Source;
    ALdouble    Offsets[2];
    ALdouble    updateLen;

    switch(eParam)
    {
        case AL_SOURCE_RELATIVE:
        case AL_CONE_INNER_ANGLE:
        case AL_CONE_OUTER_ANGLE:
        case AL_LOOPING:
        case AL_BUFFER:
        case AL_SOURCE_STATE:
        case AL_BUFFERS_QUEUED:
        case AL_BUFFERS_PROCESSED:
        case AL_SEC_OFFSET:
        case AL_SAMPLE_OFFSET:
        case AL_BYTE_OFFSET:
        case AL_MAX_DISTANCE:
        case AL_ROLLOFF_FACTOR:
        case AL_DOPPLER_FACTOR:
        case AL_REFERENCE_DISTANCE:
        case AL_SOURCE_TYPE:
        case AL_DIRECT_FILTER:
        case AL_DIRECT_FILTER_GAINHF_AUTO:
        case AL_AUXILIARY_SEND_FILTER_GAIN_AUTO:
        case AL_AUXILIARY_SEND_FILTER_GAINHF_AUTO:
        case AL_DISTANCE_MODEL:
        case AL_VIRTUAL_CHANNELS_SOFT:
            alGetSourcei(source, eParam, plValues);
            return;

        case AL_POSITION:
        case AL_VELOCITY:
        case AL_DIRECTION:
            alGetSource3i(source, eParam, plValues+0, plValues+1, plValues+2);
            return;
    }

    pContext = GetContextRef();
    if(!pContext) return;

    if(plValues)
    {
        if((Source=LookupSource(pContext, source)) != NULL)
        {
            switch(eParam)
            {
                case AL_SAMPLE_RW_OFFSETS_SOFT:
                case AL_BYTE_RW_OFFSETS_SOFT:
                    LockContext(pContext);
                    updateLen = (ALdouble)pContext->Device->UpdateSize /
                                pContext->Device->Frequency;
                    GetSourceOffset(Source, eParam, Offsets, updateLen);
                    UnlockContext(pContext);
                    plValues[0] = (ALint)Offsets[0];
                    plValues[1] = (ALint)Offsets[1];
                    break;

                default:
                    alSetError(pContext, AL_INVALID_ENUM);
                    break;
            }
        }
        else
            alSetError(pContext, AL_INVALID_NAME);
    }
    else
        alSetError(pContext, AL_INVALID_VALUE);

    ALCcontext_DecRef(pContext);
}


AL_API ALvoid AL_APIENTRY alSourcePlay(ALuint source)
{
    alSourcePlayv(1, &source);
}

AL_API ALvoid AL_APIENTRY alSourcePlayv(ALsizei n, const ALuint *sources)
{
    ALCcontext       *Context;
    ALsource         *Source;
    ALsizei          i;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }
    if(n > 0 && !sources)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }

    // Check that all the Sources are valid
    for(i = 0;i < n;i++)
    {
        if(!LookupSource(Context, sources[i]))
        {
            alSetError(Context, AL_INVALID_NAME);
            goto done;
        }
    }

    LockContext(Context);
    while(Context->MaxActiveSources-Context->ActiveSourceCount < n)
    {
        void *temp = NULL;
        ALsizei newcount;

        newcount = Context->MaxActiveSources << 1;
        if(newcount > 0)
            temp = realloc(Context->ActiveSources,
                           sizeof(*Context->ActiveSources) * newcount);
        if(!temp)
        {
            UnlockContext(Context);
            alSetError(Context, AL_OUT_OF_MEMORY);
            goto done;
        }

        Context->ActiveSources = temp;
        Context->MaxActiveSources = newcount;
    }

    for(i = 0;i < n;i++)
    {
        Source = LookupSource(Context, sources[i]);
        if(Context->DeferUpdates) Source->new_state = AL_PLAYING;
        else SetSourceState(Source, Context, AL_PLAYING);
    }
    UnlockContext(Context);

done:
    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alSourcePause(ALuint source)
{
    alSourcePausev(1, &source);
}

AL_API ALvoid AL_APIENTRY alSourcePausev(ALsizei n, const ALuint *sources)
{
    ALCcontext *Context;
    ALsource *Source;
    ALsizei i;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }
    if(n > 0 && !sources)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }

    // Check all the Sources are valid
    for(i = 0;i < n;i++)
    {
        if(!LookupSource(Context, sources[i]))
        {
            alSetError(Context, AL_INVALID_NAME);
            goto done;
        }
    }

    LockContext(Context);
    for(i = 0;i < n;i++)
    {
        Source = LookupSource(Context, sources[i]);
        if(Context->DeferUpdates) Source->new_state = AL_PAUSED;
        else SetSourceState(Source, Context, AL_PAUSED);
    }
    UnlockContext(Context);

done:
    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alSourceStop(ALuint source)
{
    alSourceStopv(1, &source);
}

AL_API ALvoid AL_APIENTRY alSourceStopv(ALsizei n, const ALuint *sources)
{
    ALCcontext *Context;
    ALsource *Source;
    ALsizei i;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }
    if(n > 0 && !sources)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }

    // Check all the Sources are valid
    for(i = 0;i < n;i++)
    {
        if(!LookupSource(Context, sources[i]))
        {
            alSetError(Context, AL_INVALID_NAME);
            goto done;
        }
    }

    LockContext(Context);
    for(i = 0;i < n;i++)
    {
        Source = LookupSource(Context, sources[i]);
        Source->new_state = AL_NONE;
        SetSourceState(Source, Context, AL_STOPPED);
    }
    UnlockContext(Context);

done:
    ALCcontext_DecRef(Context);
}

AL_API ALvoid AL_APIENTRY alSourceRewind(ALuint source)
{
    alSourceRewindv(1, &source);
}

AL_API ALvoid AL_APIENTRY alSourceRewindv(ALsizei n, const ALuint *sources)
{
    ALCcontext *Context;
    ALsource *Source;
    ALsizei i;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }
    if(n > 0 && !sources)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }

    // Check all the Sources are valid
    for(i = 0;i < n;i++)
    {
        if(!LookupSource(Context, sources[i]))
        {
            alSetError(Context, AL_INVALID_NAME);
            goto done;
        }
    }

    LockContext(Context);
    for(i = 0;i < n;i++)
    {
        Source = LookupSource(Context, sources[i]);
        Source->new_state = AL_NONE;
        SetSourceState(Source, Context, AL_INITIAL);
    }
    UnlockContext(Context);

done:
    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alSourceQueueBuffers(ALuint source, ALsizei n, const ALuint *buffers)
{
    ALCcontext *Context;
    ALCdevice *device;
    ALsource *Source;
    ALsizei i;
    ALbufferlistitem *BufferListStart = NULL;
    ALbufferlistitem *BufferList;
    ALbuffer *BufferFmt;

    if(n == 0)
        return;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto error;
    }

    // Check that all buffers are valid or zero and that the source is valid

    // Check that this is a valid source
    if((Source=LookupSource(Context, source)) == NULL)
    {
        alSetError(Context, AL_INVALID_NAME);
        goto error;
    }

    LockContext(Context);
    // Check that this is not a STATIC Source
    if(Source->lSourceType == AL_STATIC)
    {
        UnlockContext(Context);
        // Invalid Source Type (can't queue on a Static Source)
        alSetError(Context, AL_INVALID_OPERATION);
        goto error;
    }

    device = Context->Device;

    BufferFmt = NULL;

    // Check existing Queue (if any) for a valid Buffers and get its frequency and format
    BufferList = Source->queue;
    while(BufferList)
    {
        if(BufferList->buffer)
        {
            BufferFmt = BufferList->buffer;
            break;
        }
        BufferList = BufferList->next;
    }

    for(i = 0;i < n;i++)
    {
        ALbuffer *buffer = NULL;
        if(buffers[i] && (buffer=LookupBuffer(device, buffers[i])) == NULL)
        {
            UnlockContext(Context);
            alSetError(Context, AL_INVALID_NAME);
            goto error;
        }

        if(!BufferListStart)
        {
            BufferListStart = malloc(sizeof(ALbufferlistitem));
            BufferListStart->buffer = buffer;
            BufferListStart->next = NULL;
            BufferListStart->prev = NULL;
            BufferList = BufferListStart;
        }
        else
        {
            BufferList->next = malloc(sizeof(ALbufferlistitem));
            BufferList->next->buffer = buffer;
            BufferList->next->next = NULL;
            BufferList->next->prev = BufferList;
            BufferList = BufferList->next;
        }
        if(!buffer) continue;

        // Increment reference counter for buffer
        IncrementRef(&buffer->ref);
        ReadLock(&buffer->lock);
        if(BufferFmt == NULL)
        {
            BufferFmt = buffer;

            Source->NumChannels = ChannelsFromFmt(buffer->FmtChannels);
            Source->SampleSize  = BytesFromFmt(buffer->FmtType);
            if(buffer->FmtChannels == FmtMono)
                Source->Update = CalcSourceParams;
            else
                Source->Update = CalcNonAttnSourceParams;

            Source->NeedsUpdate = AL_TRUE;
        }
        else if(BufferFmt->Frequency != buffer->Frequency ||
                BufferFmt->OriginalChannels != buffer->OriginalChannels ||
                BufferFmt->OriginalType != buffer->OriginalType)
        {
            ReadUnlock(&buffer->lock);
            UnlockContext(Context);
            alSetError(Context, AL_INVALID_OPERATION);
            goto error;
        }
        ReadUnlock(&buffer->lock);
    }

    // Change Source Type
    Source->lSourceType = AL_STREAMING;

    if(Source->queue == NULL)
        Source->queue = BufferListStart;
    else
    {
        // Find end of queue
        BufferList = Source->queue;
        while(BufferList->next != NULL)
            BufferList = BufferList->next;

        BufferListStart->prev = BufferList;
        BufferList->next = BufferListStart;
    }

    // Update number of buffers in queue
    Source->BuffersInQueue += n;

    UnlockContext(Context);
    ALCcontext_DecRef(Context);
    return;

error:
    while(BufferListStart)
    {
        BufferList = BufferListStart;
        BufferListStart = BufferList->next;

        if(BufferList->buffer)
            DecrementRef(&BufferList->buffer->ref);
        free(BufferList);
    }
    ALCcontext_DecRef(Context);
}


// Implementation assumes that n is the number of buffers to be removed from the queue and buffers is
// an array of buffer IDs that are to be filled with the names of the buffers removed
AL_API ALvoid AL_APIENTRY alSourceUnqueueBuffers( ALuint source, ALsizei n, ALuint* buffers )
{
    ALCcontext *Context;
    ALsource *Source;
    ALsizei i;
    ALbufferlistitem *BufferList;

    if(n == 0)
        return;

    Context = GetContextRef();
    if(!Context) return;

    if(n < 0)
    {
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }

    if((Source=LookupSource(Context, source)) == NULL)
    {
        alSetError(Context, AL_INVALID_NAME);
        goto done;
    }

    LockContext(Context);
    if(Source->bLooping || Source->lSourceType != AL_STREAMING ||
       (ALuint)n > Source->BuffersPlayed)
    {
        UnlockContext(Context);
        // Some buffers can't be unqueue because they have not been processed
        alSetError(Context, AL_INVALID_VALUE);
        goto done;
    }

    for(i = 0;i < n;i++)
    {
        BufferList = Source->queue;
        Source->queue = BufferList->next;
        Source->BuffersInQueue--;
        Source->BuffersPlayed--;

        if(BufferList->buffer)
        {
            // Record name of buffer
            buffers[i] = BufferList->buffer->buffer;
            // Decrement buffer reference counter
            DecrementRef(&BufferList->buffer->ref);
        }
        else
            buffers[i] = 0;

        // Release memory for buffer list item
        free(BufferList);
    }
    if(Source->queue)
        Source->queue->prev = NULL;
    UnlockContext(Context);

done:
    ALCcontext_DecRef(Context);
}


static ALvoid InitSourceParams(ALsource *Source)
{
    ALuint i;

    Source->flInnerAngle = 360.0f;
    Source->flOuterAngle = 360.0f;
    Source->flPitch = 1.0f;
    Source->vPosition[0] = 0.0f;
    Source->vPosition[1] = 0.0f;
    Source->vPosition[2] = 0.0f;
    Source->vOrientation[0] = 0.0f;
    Source->vOrientation[1] = 0.0f;
    Source->vOrientation[2] = 0.0f;
    Source->vVelocity[0] = 0.0f;
    Source->vVelocity[1] = 0.0f;
    Source->vVelocity[2] = 0.0f;
    Source->flRefDistance = 1.0f;
    Source->flMaxDistance = FLT_MAX;
    Source->flRollOffFactor = 1.0f;
    Source->bLooping = AL_FALSE;
    Source->flGain = 1.0f;
    Source->flMinGain = 0.0f;
    Source->flMaxGain = 1.0f;
    Source->flOuterGain = 0.0f;
    Source->OuterGainHF = 1.0f;

    Source->DryGainHFAuto = AL_TRUE;
    Source->WetGainAuto = AL_TRUE;
    Source->WetGainHFAuto = AL_TRUE;
    Source->AirAbsorptionFactor = 0.0f;
    Source->RoomRolloffFactor = 0.0f;
    Source->DopplerFactor = 1.0f;
    Source->VirtualChannels = AL_TRUE;

    Source->DistanceModel = AL_INVERSE_DISTANCE_CLAMPED;

    Source->Resampler = DefaultResampler;

    Source->state = AL_INITIAL;
    Source->new_state = AL_NONE;
    Source->lSourceType = AL_UNDETERMINED;
    Source->lOffset = -1;

    Source->DirectGain = 1.0f;
    Source->DirectGainHF = 1.0f;
    for(i = 0;i < MAX_SENDS;i++)
    {
        Source->Send[i].WetGain = 1.0f;
        Source->Send[i].WetGainHF = 1.0f;
    }

    Source->NeedsUpdate = AL_TRUE;

    Source->HrtfMoving = AL_FALSE;
    Source->HrtfCounter = 0;
}


/*
 * SetSourceState
 *
 * Sets the source's new play state given its current state
 */
ALvoid SetSourceState(ALsource *Source, ALCcontext *Context, ALenum state)
{
    if(state == AL_PLAYING)
    {
        ALbufferlistitem *BufferList;
        ALsizei j, k;

        /* Check that there is a queue containing at least one non-null, non zero length AL Buffer */
        BufferList = Source->queue;
        while(BufferList)
        {
            if(BufferList->buffer != NULL && BufferList->buffer->SampleLen)
                break;
            BufferList = BufferList->next;
        }

        if(Source->state != AL_PLAYING)
        {
            for(j = 0;j < MAXCHANNELS;j++)
            {
                for(k = 0;k < SRC_HISTORY_LENGTH;k++)
                    Source->HrtfHistory[j][k] = 0.0f;
                for(k = 0;k < HRIR_LENGTH;k++)
                {
                    Source->HrtfValues[j][k][0] = 0.0f;
                    Source->HrtfValues[j][k][1] = 0.0f;
                }
            }
        }

        if(Source->state != AL_PAUSED)
        {
            Source->state = AL_PLAYING;
            Source->position = 0;
            Source->position_fraction = 0;
            Source->BuffersPlayed = 0;
        }
        else
            Source->state = AL_PLAYING;

        // Check if an Offset has been set
        if(Source->lOffset != -1)
            ApplyOffset(Source);

        /* If there's nothing to play, or device is disconnected, go right to
         * stopped */
        if(!BufferList || !Context->Device->Connected)
        {
            SetSourceState(Source, Context, AL_STOPPED);
            return;
        }

        for(j = 0;j < Context->ActiveSourceCount;j++)
        {
            if(Context->ActiveSources[j] == Source)
                break;
        }
        if(j == Context->ActiveSourceCount)
            Context->ActiveSources[Context->ActiveSourceCount++] = Source;
    }
    else if(state == AL_PAUSED)
    {
        if(Source->state == AL_PLAYING)
        {
            Source->state = AL_PAUSED;
            Source->HrtfMoving = AL_FALSE;
            Source->HrtfCounter = 0;
        }
    }
    else if(state == AL_STOPPED)
    {
        if(Source->state != AL_INITIAL)
        {
            Source->state = AL_STOPPED;
            Source->BuffersPlayed = Source->BuffersInQueue;
            Source->HrtfMoving = AL_FALSE;
            Source->HrtfCounter = 0;
        }
        Source->lOffset = -1;
    }
    else if(state == AL_INITIAL)
    {
        if(Source->state != AL_INITIAL)
        {
            Source->state = AL_INITIAL;
            Source->position = 0;
            Source->position_fraction = 0;
            Source->BuffersPlayed = 0;
            Source->HrtfMoving = AL_FALSE;
            Source->HrtfCounter = 0;
        }
        Source->lOffset = -1;
    }
}

/*
    GetSourceOffset

    Gets the current playback position in the given Source, in the appropriate format (Bytes, Samples or MilliSeconds)
    The offset is relative to the start of the queue (not the start of the current buffer)
*/
static ALvoid GetSourceOffset(ALsource *Source, ALenum name, ALdouble *offset, ALdouble updateLen)
{
    const ALbufferlistitem *BufferList;
    const ALbuffer         *Buffer = NULL;
    ALuint  BufferFreq = 0;
    ALuint  readPos, writePos;
    ALuint  totalBufferLen;
    ALuint  i;

    // Find the first non-NULL Buffer in the Queue
    BufferList = Source->queue;
    while(BufferList)
    {
        if(BufferList->buffer)
        {
            Buffer = BufferList->buffer;
            BufferFreq = Buffer->Frequency;
            break;
        }
        BufferList = BufferList->next;
    }

    if((Source->state != AL_PLAYING && Source->state != AL_PAUSED) || !Buffer)
    {
        offset[0] = 0.0;
        offset[1] = 0.0;
        return;
    }

    // Get Current SamplesPlayed (NOTE : This is the offset into the *current* buffer)
    readPos = Source->position;
    // Add length of any processed buffers in the queue
    totalBufferLen = 0;
    BufferList = Source->queue;
    for(i = 0;BufferList;i++)
    {
        if(BufferList->buffer)
        {
            if(i < Source->BuffersPlayed)
                readPos += BufferList->buffer->SampleLen;
            totalBufferLen += BufferList->buffer->SampleLen;
        }
        BufferList = BufferList->next;
    }
    if(Source->state == AL_PLAYING)
        writePos = readPos + (ALuint)(updateLen*BufferFreq);
    else
        writePos = readPos;

    if(Source->bLooping)
    {
        readPos %= totalBufferLen;
        writePos %= totalBufferLen;
    }
    else
    {
        // Wrap positions back to 0
        if(readPos >= totalBufferLen)
            readPos = 0;
        if(writePos >= totalBufferLen)
            writePos = 0;
    }

    switch(name)
    {
        case AL_SEC_OFFSET:
            offset[0] = (ALdouble)readPos / Buffer->Frequency;
            offset[1] = (ALdouble)writePos / Buffer->Frequency;
            break;
        case AL_SAMPLE_OFFSET:
        case AL_SAMPLE_RW_OFFSETS_SOFT:
            offset[0] = (ALdouble)readPos;
            offset[1] = (ALdouble)writePos;
            break;
        case AL_BYTE_OFFSET:
        case AL_BYTE_RW_OFFSETS_SOFT:
            // Take into account the original format of the Buffer
            if(Buffer->OriginalType == UserFmtIMA4)
            {
                ALuint BlockSize = 36 * ChannelsFromFmt(Buffer->FmtChannels);
                ALuint FrameBlockSize = 65;

                // Round down to nearest ADPCM block
                offset[0] = (ALdouble)(readPos / FrameBlockSize * BlockSize);
                if(Source->state != AL_PLAYING)
                    offset[1] = offset[0];
                else
                {
                    // Round up to nearest ADPCM block
                    offset[1] = (ALdouble)((writePos+FrameBlockSize-1) /
                                           FrameBlockSize * BlockSize);
                }
            }
            else
            {
                ALuint FrameSize = FrameSizeFromUserFmt(Buffer->OriginalChannels, Buffer->OriginalType);
                offset[0] = (ALdouble)(readPos * FrameSize);
                offset[1] = (ALdouble)(writePos * FrameSize);
            }
            break;
    }
}


/*
    ApplyOffset

    Apply a playback offset to the Source.  This function will update the queue (to correctly
    mark buffers as 'pending' or 'processed' depending upon the new offset.
*/
ALboolean ApplyOffset(ALsource *Source)
{
    const ALbufferlistitem *BufferList;
    const ALbuffer         *Buffer;
    ALint bufferLen, totalBufferLen;
    ALint buffersPlayed;
    ALint offset;

    // Get true byte offset
    offset = GetSampleOffset(Source);

    // If the offset is invalid, don't apply it
    if(offset == -1)
        return AL_FALSE;

    // Sort out the queue (pending and processed states)
    BufferList = Source->queue;
    totalBufferLen = 0;
    buffersPlayed = 0;

    while(BufferList)
    {
        Buffer = BufferList->buffer;
        bufferLen = Buffer ? Buffer->SampleLen : 0;

        if(bufferLen <= offset-totalBufferLen)
        {
            // Offset is past this buffer so increment BuffersPlayed
            buffersPlayed++;
        }
        else if(totalBufferLen <= offset)
        {
            // Offset is within this buffer
            Source->BuffersPlayed = buffersPlayed;

            // SW Mixer Positions are in Samples
            Source->position = offset - totalBufferLen;
            return AL_TRUE;
        }

        // Increment the TotalBufferSize
        totalBufferLen += bufferLen;

        // Move on to next buffer in the Queue
        BufferList = BufferList->next;
    }
    // Offset is out of range of the buffer queue
    return AL_FALSE;
}


/*
    GetSampleOffset

    Returns the sample offset into the Source's queue (from the Sample, Byte or Millisecond offset
    supplied by the application). This takes into account the fact that the buffer format may have
    been modifed by AL
*/
static ALint GetSampleOffset(ALsource *Source)
{
    const ALbuffer *Buffer = NULL;
    const ALbufferlistitem *BufferList;
    ALint Offset = -1;

    // Find the first non-NULL Buffer in the Queue
    BufferList = Source->queue;
    while(BufferList)
    {
        if(BufferList->buffer)
        {
            Buffer = BufferList->buffer;
            break;
        }
        BufferList = BufferList->next;
    }

    if(!Buffer)
    {
        Source->lOffset = -1;
        return -1;
    }

    // Determine the ByteOffset (and ensure it is block aligned)
    switch(Source->lOffsetType)
    {
    case AL_BYTE_OFFSET:
        // Take into consideration the original format
        Offset = Source->lOffset;
        if(Buffer->OriginalType == UserFmtIMA4)
        {
            // Round down to nearest ADPCM block
            Offset /= 36 * ChannelsFromUserFmt(Buffer->OriginalChannels);
            // Multiply by compression rate (65 sample frames per block)
            Offset *= 65;
        }
        else
            Offset /= FrameSizeFromUserFmt(Buffer->OriginalChannels, Buffer->OriginalType);
        break;

    case AL_SAMPLE_OFFSET:
        Offset = Source->lOffset;
        break;

    case AL_SEC_OFFSET:
        // Note - lOffset is internally stored as Milliseconds
        Offset = (ALint)(Source->lOffset / 1000.0 * Buffer->Frequency);
        break;
    }
    // Clear Offset
    Source->lOffset = -1;

    return Offset;
}


ALvoid ReleaseALSources(ALCcontext *Context)
{
    ALsizei pos;
    ALuint j;
    for(pos = 0;pos < Context->SourceMap.size;pos++)
    {
        ALsource *temp = Context->SourceMap.array[pos].value;
        Context->SourceMap.array[pos].value = NULL;

        // For each buffer in the source's queue, decrement its reference counter and remove it
        while(temp->queue != NULL)
        {
            ALbufferlistitem *BufferList = temp->queue;
            temp->queue = BufferList->next;

            if(BufferList->buffer != NULL)
                DecrementRef(&BufferList->buffer->ref);
            free(BufferList);
        }

        for(j = 0;j < MAX_SENDS;++j)
        {
            if(temp->Send[j].Slot)
                DecrementRef(&temp->Send[j].Slot->ref);
            temp->Send[j].Slot = NULL;
        }

        // Release source structure
        FreeThunkEntry(temp->source);
        memset(temp, 0, sizeof(ALsource));
        free(temp);
    }
}
