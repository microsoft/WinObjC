#ifndef _AL_ERROR_H_
#define _AL_ERROR_H_

#include "AL/al.h"
#include "AL/alc.h"

#ifdef __cplusplus
extern "C" {
#endif

extern ALboolean TrapALError;

ALvoid alSetError(ALCcontext *Context, ALenum errorCode);

#ifdef __cplusplus
}
#endif

#endif
