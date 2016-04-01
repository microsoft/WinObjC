#ifndef _AL_LISTENER_H_
#define _AL_LISTENER_H_

#include "AL/al.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ALlistener_struct
{
    volatile ALfloat Position[3];
    volatile ALfloat Velocity[3];
    volatile ALfloat Forward[3];
    volatile ALfloat Up[3];
    volatile ALfloat Matrix[4][4];
    volatile ALfloat Gain;
    volatile ALfloat MetersPerUnit;
} ALlistener;

#ifdef __cplusplus
}
#endif

#endif
