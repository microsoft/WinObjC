#ifndef _AL_FILTER_H_
#define _AL_FILTER_H_

#include "AL/al.h"
#include "alu.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    ALfloat coeff;
#ifndef _MSC_VER
    ALfloat history[0];
#else
    ALfloat history[1];
#endif
} FILTER;

static __inline ALfloat lpFilter2P(FILTER *iir, ALuint offset, ALfloat input)
{
    ALfloat *history = &iir->history[offset*2];
    ALfloat a = iir->coeff;
    ALfloat output = input;

    output = output + (history[0]-output)*a;
    history[0] = output;
    output = output + (history[1]-output)*a;
    history[1] = output;

    return output;
}
static __inline ALfloat lpFilter1P(FILTER *iir, ALuint offset, ALfloat input)
{
    ALfloat *history = &iir->history[offset];
    ALfloat a = iir->coeff;
    ALfloat output = input;

    output = output + (history[0]-output)*a;
    history[0] = output;

    return output;
}

static __inline ALfloat lpFilter2PC(const FILTER *iir, ALuint offset, ALfloat input)
{
    const ALfloat *history = &iir->history[offset*2];
    ALfloat a = iir->coeff;
    ALfloat output = input;

    output = output + (history[0]-output)*a;
    output = output + (history[1]-output)*a;

    return output;
}
static __inline ALfloat lpFilter1PC(FILTER *iir, ALuint offset, ALfloat input)
{
    const ALfloat *history = &iir->history[offset];
    ALfloat a = iir->coeff;
    ALfloat output = input;

    output = output + (history[0]-output)*a;

    return output;
}

/* Calculates the low-pass filter coefficient given the pre-scaled gain and
 * cos(w) value. Note that g should be pre-scaled (sqr(gain) for one-pole,
 * sqrt(gain) for four-pole, etc) */
ALfloat lpCoeffCalc(ALfloat g, ALfloat cw);


typedef struct ALfilter {
    // Filter type (AL_FILTER_NULL, ...)
    ALenum type;

    ALfloat Gain;
    ALfloat GainHF;

    void (*SetParami)(struct ALfilter *filter, ALCcontext *context, ALenum param, ALint val);
    void (*SetParamiv)(struct ALfilter *filter, ALCcontext *context, ALenum param, const ALint *vals);
    void (*SetParamf)(struct ALfilter *filter, ALCcontext *context, ALenum param, ALfloat val);
    void (*SetParamfv)(struct ALfilter *filter, ALCcontext *context, ALenum param, const ALfloat *vals);

    void (*GetParami)(struct ALfilter *filter, ALCcontext *context, ALenum param, ALint *val);
    void (*GetParamiv)(struct ALfilter *filter, ALCcontext *context, ALenum param, ALint *vals);
    void (*GetParamf)(struct ALfilter *filter, ALCcontext *context, ALenum param, ALfloat *val);
    void (*GetParamfv)(struct ALfilter *filter, ALCcontext *context, ALenum param, ALfloat *vals);

    // Index to itself
    ALuint filter;
} ALfilter;

#define ALfilter_SetParami(x, c, p, v)  ((x)->SetParami((x),(c),(p),(v)))
#define ALfilter_SetParamiv(x, c, p, v) ((x)->SetParamiv((x),(c),(p),(v)))
#define ALfilter_SetParamf(x, c, p, v)  ((x)->SetParamf((x),(c),(p),(v)))
#define ALfilter_SetParamfv(x, c, p, v) ((x)->SetParamfv((x),(c),(p),(v)))

#define ALfilter_GetParami(x, c, p, v)  ((x)->GetParami((x),(c),(p),(v)))
#define ALfilter_GetParamiv(x, c, p, v) ((x)->GetParamiv((x),(c),(p),(v)))
#define ALfilter_GetParamf(x, c, p, v)  ((x)->GetParamf((x),(c),(p),(v)))
#define ALfilter_GetParamfv(x, c, p, v) ((x)->GetParamfv((x),(c),(p),(v)))

ALvoid ReleaseALFilters(ALCdevice *device);

#ifdef __cplusplus
}
#endif

#endif
