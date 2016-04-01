#ifndef ALHELPERS_H
#define ALHELPERS_H

#ifndef _WIN32
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#else
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Some helper functions to get the name from the channel and type enums. */
const char *ChannelsName(ALenum chans);
const char *TypeName(ALenum type);

/* Helpers to convert frame counts and byte lengths. */
ALsizei FramesToBytes(ALsizei size, ALenum channels, ALenum type);
ALsizei BytesToFrames(ALsizei size, ALenum channels, ALenum type);

/* Retrieves a compatible buffer format given the channel configuration and
 * sample type. If an alIsBufferFormatSupportedSOFT-compatible function is
 * provided, it will be called to find the closest-matching format from
 * AL_SOFT_buffer_samples. Returns AL_NONE (0) if no supported format can be
 * found. */
ALenum GetFormat(ALenum channels, ALenum type, LPALISBUFFERFORMATSUPPORTEDSOFT palIsBufferFormatSupportedSOFT);

/* Loads samples into a buffer using the standard alBufferData call, but with a
 * LPALBUFFERSAMPLESSOFT-compatible prototype. Assumes internalformat is valid
 * for alBufferData, and that channels and type match it. */
void AL_APIENTRY wrap_BufferSamples(ALuint buffer, ALuint samplerate,
                                    ALenum internalformat, ALsizei samples,
                                    ALenum channels, ALenum type,
                                    const ALvoid *data);

/* Easy device init/deinit functions. InitAL returns 0 on success. */
int InitAL(void);
void CloseAL(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ALHELPERS_H */
