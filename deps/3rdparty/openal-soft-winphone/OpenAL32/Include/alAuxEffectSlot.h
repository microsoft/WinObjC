#ifndef _AL_AUXEFFECTSLOT_H_
#define _AL_AUXEFFECTSLOT_H_

#include "AL/al.h"
#include "alEffect.h"
#include "alFilter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ALeffectState ALeffectState;

typedef struct ALeffectslot
{
    ALeffect effect;

    volatile ALfloat   Gain;
    volatile ALboolean AuxSendAuto;

    volatile ALenum NeedsUpdate;
    ALeffectState *EffectState;

    ALfloat WetBuffer[BUFFERSIZE];

    ALfloat ClickRemoval[1];
    ALfloat PendingClicks[1];

    RefCount ref;

    // Index to itself
    ALuint effectslot;

    struct ALeffectslot *next;
} ALeffectslot;


ALenum InitEffectSlot(ALeffectslot *slot);
ALvoid ReleaseALAuxiliaryEffectSlots(ALCcontext *Context);

struct ALeffectState {
    ALvoid (*Destroy)(ALeffectState *State);
    ALboolean (*DeviceUpdate)(ALeffectState *State, ALCdevice *Device);
    ALvoid (*Update)(ALeffectState *State, ALCcontext *Context, const ALeffectslot *Slot);
    ALvoid (*Process)(ALeffectState *State, ALuint SamplesToDo, const ALfloat *SamplesIn, ALfloat (*SamplesOut)[MAXCHANNELS]);
};

ALeffectState *NoneCreate(void);
ALeffectState *ReverbCreate(void);
ALeffectState *EchoCreate(void);
ALeffectState *ModulatorCreate(void);
ALeffectState *DedicatedCreate(void);

#define ALeffectState_Destroy(a)        ((a)->Destroy((a)))
#define ALeffectState_DeviceUpdate(a,b) ((a)->DeviceUpdate((a),(b)))
#define ALeffectState_Update(a,b,c)     ((a)->Update((a),(b),(c)))
#define ALeffectState_Process(a,b,c,d)  ((a)->Process((a),(b),(c),(d)))

ALvoid InitializeEffect(ALCcontext *Context, ALeffectslot *EffectSlot, ALeffect *effect);

#ifdef __cplusplus
}
#endif

#endif
