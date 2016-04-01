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

#include "alMain.h"
#include "AL/alc.h"
#include "alError.h"
#include "alListener.h"
#include "alSource.h"

AL_API ALvoid AL_APIENTRY alListenerf(ALenum eParam, ALfloat flValue)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    switch(eParam)
    {
        case AL_GAIN:
            if(flValue >= 0.0f && isfinite(flValue))
            {
                Context->Listener.Gain = flValue;
                Context->UpdateSources = AL_TRUE;
            }
            else
                alSetError(Context, AL_INVALID_VALUE);
            break;

        case AL_METERS_PER_UNIT:
            if(flValue > 0.0f && isfinite(flValue))
            {
                Context->Listener.MetersPerUnit = flValue;
                Context->UpdateSources = AL_TRUE;
            }
            else
                alSetError(Context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alListener3f(ALenum eParam, ALfloat flValue1, ALfloat flValue2, ALfloat flValue3)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    switch(eParam)
    {
        case AL_POSITION:
            if(isfinite(flValue1) && isfinite(flValue2) && isfinite(flValue3))
            {
                LockContext(Context);
                Context->Listener.Position[0] = flValue1;
                Context->Listener.Position[1] = flValue2;
                Context->Listener.Position[2] = flValue3;
                Context->UpdateSources = AL_TRUE;
                UnlockContext(Context);
            }
            else
                alSetError(Context, AL_INVALID_VALUE);
            break;

        case AL_VELOCITY:
            if(isfinite(flValue1) && isfinite(flValue2) && isfinite(flValue3))
            {
                LockContext(Context);
                Context->Listener.Velocity[0] = flValue1;
                Context->Listener.Velocity[1] = flValue2;
                Context->Listener.Velocity[2] = flValue3;
                Context->UpdateSources = AL_TRUE;
                UnlockContext(Context);
            }
            else
                alSetError(Context, AL_INVALID_VALUE);
            break;

        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alListenerfv(ALenum eParam, const ALfloat *pflValues)
{
    ALCcontext *Context;

    if(pflValues)
    {
        switch(eParam)
        {
            case AL_GAIN:
            case AL_METERS_PER_UNIT:
                alListenerf(eParam, pflValues[0]);
                return;

            case AL_POSITION:
            case AL_VELOCITY:
                alListener3f(eParam, pflValues[0], pflValues[1], pflValues[2]);
                return;
        }
    }

    Context = GetContextRef();
    if(!Context) return;

    if(pflValues)
    {
        switch(eParam)
        {
            case AL_ORIENTATION:
                if(isfinite(pflValues[0]) && isfinite(pflValues[1]) &&
                   isfinite(pflValues[2]) && isfinite(pflValues[3]) &&
                   isfinite(pflValues[4]) && isfinite(pflValues[5]))
                {
                    ALfloat U[3], V[3], N[3];

                    /* AT then UP */
                    N[0] = pflValues[0];
                    N[1] = pflValues[1];
                    N[2] = pflValues[2];
                    aluNormalize(N);
                    V[0] = pflValues[3];
                    V[1] = pflValues[4];
                    V[2] = pflValues[5];
                    aluNormalize(V);
                    /* Build and normalize right-vector */
                    aluCrossproduct(N, V, U);
                    aluNormalize(U);

                    LockContext(Context);
                    Context->Listener.Forward[0] = pflValues[0];
                    Context->Listener.Forward[1] = pflValues[1];
                    Context->Listener.Forward[2] = pflValues[2];
                    Context->Listener.Up[0] = pflValues[3];
                    Context->Listener.Up[1] = pflValues[4];
                    Context->Listener.Up[2] = pflValues[5];
                    Context->Listener.Matrix[0][0] =  U[0];
                    Context->Listener.Matrix[0][1] =  V[0];
                    Context->Listener.Matrix[0][2] = -N[0];
                    Context->Listener.Matrix[0][3] =  0.0f;
                    Context->Listener.Matrix[1][0] =  U[1];
                    Context->Listener.Matrix[1][1] =  V[1];
                    Context->Listener.Matrix[1][2] = -N[1];
                    Context->Listener.Matrix[1][3] =  0.0f;
                    Context->Listener.Matrix[2][0] =  U[2];
                    Context->Listener.Matrix[2][1] =  V[2];
                    Context->Listener.Matrix[2][2] = -N[2];
                    Context->Listener.Matrix[2][3] =  0.0f;
                    Context->Listener.Matrix[3][0] =  0.0f;
                    Context->Listener.Matrix[3][1] =  0.0f;
                    Context->Listener.Matrix[3][2] =  0.0f;
                    Context->Listener.Matrix[3][3] =  1.0f;
                    Context->UpdateSources = AL_TRUE;
                    UnlockContext(Context);
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
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alListeneri(ALenum eParam, ALint lValue)
{
    ALCcontext *Context;

    (void)lValue;

    Context = GetContextRef();
    if(!Context) return;

    switch(eParam)
    {
        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);
}


AL_API void AL_APIENTRY alListener3i(ALenum eParam, ALint lValue1, ALint lValue2, ALint lValue3)
{
    ALCcontext *Context;

    switch(eParam)
    {
        case AL_POSITION:
        case AL_VELOCITY:
            alListener3f(eParam, (ALfloat)lValue1, (ALfloat)lValue2, (ALfloat)lValue3);
            return;
    }

    Context = GetContextRef();
    if(!Context) return;

    switch(eParam)
    {
        default:
            alSetError(Context, AL_INVALID_ENUM);
            break;
    }

    ALCcontext_DecRef(Context);
}


AL_API void AL_APIENTRY alListeneriv( ALenum eParam, const ALint* plValues )
{
    ALCcontext *Context;
    ALfloat flValues[6];

    if(plValues)
    {
        switch(eParam)
        {
            case AL_POSITION:
            case AL_VELOCITY:
                alListener3f(eParam, (ALfloat)plValues[0], (ALfloat)plValues[1], (ALfloat)plValues[2]);
                return;

            case AL_ORIENTATION:
                flValues[0] = (ALfloat)plValues[0];
                flValues[1] = (ALfloat)plValues[1];
                flValues[2] = (ALfloat)plValues[2];
                flValues[3] = (ALfloat)plValues[3];
                flValues[4] = (ALfloat)plValues[4];
                flValues[5] = (ALfloat)plValues[5];
                alListenerfv(eParam, flValues);
                return;
        }
    }

    Context = GetContextRef();
    if(!Context) return;

    if(plValues)
    {
        switch(eParam)
        {
            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alGetListenerf(ALenum eParam, ALfloat *pflValue)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    if(pflValue)
    {
        switch(eParam)
        {
            case AL_GAIN:
                *pflValue = Context->Listener.Gain;
                break;

            case AL_METERS_PER_UNIT:
                *pflValue = Context->Listener.MetersPerUnit;
                break;

            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alGetListener3f(ALenum eParam, ALfloat *pflValue1, ALfloat *pflValue2, ALfloat *pflValue3)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    if(pflValue1 && pflValue2 && pflValue3)
    {
        switch(eParam)
        {
            case AL_POSITION:
                LockContext(Context);
                *pflValue1 = Context->Listener.Position[0];
                *pflValue2 = Context->Listener.Position[1];
                *pflValue3 = Context->Listener.Position[2];
                UnlockContext(Context);
                break;

            case AL_VELOCITY:
                LockContext(Context);
                *pflValue1 = Context->Listener.Velocity[0];
                *pflValue2 = Context->Listener.Velocity[1];
                *pflValue3 = Context->Listener.Velocity[2];
                UnlockContext(Context);
                break;

            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alGetListenerfv(ALenum eParam, ALfloat *pflValues)
{
    ALCcontext *Context;

    switch(eParam)
    {
        case AL_GAIN:
        case AL_METERS_PER_UNIT:
            alGetListenerf(eParam, pflValues);
            return;

        case AL_POSITION:
        case AL_VELOCITY:
            alGetListener3f(eParam, pflValues+0, pflValues+1, pflValues+2);
            return;
    }

    Context = GetContextRef();
    if(!Context) return;

    if(pflValues)
    {
        switch(eParam)
        {
            case AL_ORIENTATION:
                LockContext(Context);
                // AT then UP
                pflValues[0] = Context->Listener.Forward[0];
                pflValues[1] = Context->Listener.Forward[1];
                pflValues[2] = Context->Listener.Forward[2];
                pflValues[3] = Context->Listener.Up[0];
                pflValues[4] = Context->Listener.Up[1];
                pflValues[5] = Context->Listener.Up[2];
                UnlockContext(Context);
                break;

            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}


AL_API ALvoid AL_APIENTRY alGetListeneri(ALenum eParam, ALint *plValue)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    if(plValue)
    {
        switch(eParam)
        {
            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}


AL_API void AL_APIENTRY alGetListener3i(ALenum eParam, ALint *plValue1, ALint *plValue2, ALint *plValue3)
{
    ALCcontext *Context;

    Context = GetContextRef();
    if(!Context) return;

    if(plValue1 && plValue2 && plValue3)
    {
        switch (eParam)
        {
            case AL_POSITION:
                LockContext(Context);
                *plValue1 = (ALint)Context->Listener.Position[0];
                *plValue2 = (ALint)Context->Listener.Position[1];
                *plValue3 = (ALint)Context->Listener.Position[2];
                UnlockContext(Context);
                break;

            case AL_VELOCITY:
                LockContext(Context);
                *plValue1 = (ALint)Context->Listener.Velocity[0];
                *plValue2 = (ALint)Context->Listener.Velocity[1];
                *plValue3 = (ALint)Context->Listener.Velocity[2];
                UnlockContext(Context);
                break;

            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}


AL_API void AL_APIENTRY alGetListeneriv(ALenum eParam, ALint* plValues)
{
    ALCcontext *Context;

    switch(eParam)
    {
        case AL_POSITION:
        case AL_VELOCITY:
            alGetListener3i(eParam, plValues+0, plValues+1, plValues+2);
            return;
    }

    Context = GetContextRef();
    if(!Context) return;

    if(plValues)
    {
        switch(eParam)
        {
            case AL_ORIENTATION:
                LockContext(Context);
                // AT then UP
                plValues[0] = (ALint)Context->Listener.Forward[0];
                plValues[1] = (ALint)Context->Listener.Forward[1];
                plValues[2] = (ALint)Context->Listener.Forward[2];
                plValues[3] = (ALint)Context->Listener.Up[0];
                plValues[4] = (ALint)Context->Listener.Up[1];
                plValues[5] = (ALint)Context->Listener.Up[2];
                UnlockContext(Context);
                break;

            default:
                alSetError(Context, AL_INVALID_ENUM);
                break;
        }
    }
    else
        alSetError(Context, AL_INVALID_VALUE);

    ALCcontext_DecRef(Context);
}
