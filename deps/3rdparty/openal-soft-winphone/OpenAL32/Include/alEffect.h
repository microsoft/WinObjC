#ifndef _AL_EFFECT_H_
#define _AL_EFFECT_H_

#include "AL/al.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    EAXREVERB = 0,
    REVERB,
    ECHO,
    MODULATOR,
    DEDICATED,

    MAX_EFFECTS
};
extern ALboolean DisabledEffects[MAX_EFFECTS];

extern ALfloat ReverbBoost;
extern ALboolean EmulateEAXReverb;

typedef struct ALeffect
{
    // Effect type (AL_EFFECT_NULL, ...)
    ALenum type;

    struct {
        // Shared Reverb Properties
        ALfloat Density;
        ALfloat Diffusion;
        ALfloat Gain;
        ALfloat GainHF;
        ALfloat DecayTime;
        ALfloat DecayHFRatio;
        ALfloat ReflectionsGain;
        ALfloat ReflectionsDelay;
        ALfloat LateReverbGain;
        ALfloat LateReverbDelay;
        ALfloat AirAbsorptionGainHF;
        ALfloat RoomRolloffFactor;
        ALboolean DecayHFLimit;

        // Additional EAX Reverb Properties
        ALfloat GainLF;
        ALfloat DecayLFRatio;
        ALfloat ReflectionsPan[3];
        ALfloat LateReverbPan[3];
        ALfloat EchoTime;
        ALfloat EchoDepth;
        ALfloat ModulationTime;
        ALfloat ModulationDepth;
        ALfloat HFReference;
        ALfloat LFReference;
    } Reverb;

    struct {
        ALfloat Delay;
        ALfloat LRDelay;

        ALfloat Damping;
        ALfloat Feedback;

        ALfloat Spread;
    } Echo;

    struct {
        ALfloat Frequency;
        ALfloat HighPassCutoff;
        ALint Waveform;
    } Modulator;

    struct {
        ALfloat Gain;
    } Dedicated;

    void (*SetParami)(struct ALeffect *effect, ALCcontext *context, ALenum param, ALint val);
    void (*SetParamiv)(struct ALeffect *effect, ALCcontext *context, ALenum param, const ALint *vals);
    void (*SetParamf)(struct ALeffect *effect, ALCcontext *context, ALenum param, ALfloat val);
    void (*SetParamfv)(struct ALeffect *effect, ALCcontext *context, ALenum param, const ALfloat *vals);

    void (*GetParami)(struct ALeffect *effect, ALCcontext *context, ALenum param, ALint *val);
    void (*GetParamiv)(struct ALeffect *effect, ALCcontext *context, ALenum param, ALint *vals);
    void (*GetParamf)(struct ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *val);
    void (*GetParamfv)(struct ALeffect *effect, ALCcontext *context, ALenum param, ALfloat *vals);

    // Index to itself
    ALuint effect;
} ALeffect;

#define ALeffect_SetParami(x, c, p, v)  ((x)->SetParami((x),(c),(p),(v)))
#define ALeffect_SetParamiv(x, c, p, v) ((x)->SetParamiv((x),(c),(p),(v)))
#define ALeffect_SetParamf(x, c, p, v)  ((x)->SetParamf((x),(c),(p),(v)))
#define ALeffect_SetParamfv(x, c, p, v) ((x)->SetParamfv((x),(c),(p),(v)))

#define ALeffect_GetParami(x, c, p, v)  ((x)->GetParami((x),(c),(p),(v)))
#define ALeffect_GetParamiv(x, c, p, v) ((x)->GetParamiv((x),(c),(p),(v)))
#define ALeffect_GetParamf(x, c, p, v)  ((x)->GetParamf((x),(c),(p),(v)))
#define ALeffect_GetParamfv(x, c, p, v) ((x)->GetParamfv((x),(c),(p),(v)))

static __inline ALboolean IsReverbEffect(ALenum type)
{ return type == AL_EFFECT_REVERB || type == AL_EFFECT_EAXREVERB; }

ALenum InitEffect(ALeffect *effect);
ALvoid ReleaseALEffects(ALCdevice *device);

ALvoid GetReverbEffect(const char *name, ALeffect *effect);

#ifdef __cplusplus
}
#endif

#endif
