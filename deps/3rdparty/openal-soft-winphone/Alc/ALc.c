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

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <signal.h>

#include "alMain.h"
#include "alSource.h"
#include "AL/al.h"
#include "AL/alc.h"
#include "alThunk.h"
#include "alSource.h"
#include "alBuffer.h"
#include "alAuxEffectSlot.h"
#include "alError.h"
#include "bs2b.h"
#include "alu.h"


#define EmptyFuncs { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }
static struct BackendInfo BackendList[] = {
#ifdef HAVE_PULSEAUDIO
    { "pulse", alc_pulse_init, alc_pulse_deinit, alc_pulse_probe, EmptyFuncs },
#endif
#ifdef HAVE_ALSA
    { "alsa", alc_alsa_init, alc_alsa_deinit, alc_alsa_probe, EmptyFuncs },
#endif
#ifdef HAVE_COREAUDIO
    { "core", alc_ca_init, alc_ca_deinit, alc_ca_probe, EmptyFuncs },
#endif
#ifdef HAVE_OSS
    { "oss", alc_oss_init, alc_oss_deinit, alc_oss_probe, EmptyFuncs },
#endif
#ifdef HAVE_SOLARIS
    { "solaris", alc_solaris_init, alc_solaris_deinit, alc_solaris_probe, EmptyFuncs },
#endif
#ifdef HAVE_SNDIO
    { "sndio", alc_sndio_init, alc_sndio_deinit, alc_sndio_probe, EmptyFuncs },
#endif
#if defined HAVE_XAUDIO2
	{ "xaudio2", alc_xaudio2_init, alc_xaudio2_deinit, alc_xaudio2_probe, EmptyFuncs },
#endif
#ifdef HAVE_WASAPIDEVAPI
	{ "wasapidevapi", alcWASAPIDevApiInit, alcWASAPIDevApiDeinit, alcWASAPIDevApiProbe, EmptyFuncs },
#endif
#ifdef HAVE_MMDEVAPI
    { "mmdevapi", alcMMDevApiInit, alcMMDevApiDeinit, alcMMDevApiProbe, EmptyFuncs },
#endif
#ifdef HAVE_DSOUND
    { "dsound", alcDSoundInit, alcDSoundDeinit, alcDSoundProbe, EmptyFuncs },
#endif
#ifdef HAVE_WINMM
    { "winmm", alcWinMMInit, alcWinMMDeinit, alcWinMMProbe, EmptyFuncs },
#endif
#ifdef HAVE_PORTAUDIO
    { "port", alc_pa_init, alc_pa_deinit, alc_pa_probe, EmptyFuncs },
#endif
#ifdef HAVE_OPENSL
    { "opensl", alc_opensl_init, alc_opensl_deinit, alc_opensl_probe, EmptyFuncs },
#endif
#ifdef HAVE_ANDROID
    { "android", alc_android_init, alc_android_deinit, alc_android_probe, EmptyFuncs },
#endif

    { "null", alc_null_init, alc_null_deinit, alc_null_probe, EmptyFuncs },
#ifdef HAVE_WAVE
    { "wave", alc_wave_init, alc_wave_deinit, alc_wave_probe, EmptyFuncs },
#endif

    { NULL, NULL, NULL, NULL, EmptyFuncs }
};
static struct BackendInfo BackendLoopback = {
    "loopback", alc_loopback_init, alc_loopback_deinit, alc_loopback_probe, EmptyFuncs
};
#undef EmptyFuncs

static struct BackendInfo PlaybackBackend;
static struct BackendInfo CaptureBackend;

///////////////////////////////////////////////////////
// STRING and EXTENSIONS

typedef struct ALCfunction {
    const ALCchar *funcName;
    ALCvoid *address;
} ALCfunction;

typedef struct ALCenums {
    const ALCchar *enumName;
    ALCenum value;
} ALCenums;


static const ALCfunction alcFunctions[] = {
    { "alcCreateContext",           (ALCvoid *) alcCreateContext         },
    { "alcMakeContextCurrent",      (ALCvoid *) alcMakeContextCurrent    },
    { "alcProcessContext",          (ALCvoid *) alcProcessContext        },
    { "alcSuspendContext",          (ALCvoid *) alcSuspendContext        },
    { "alcDestroyContext",          (ALCvoid *) alcDestroyContext        },
    { "alcGetCurrentContext",       (ALCvoid *) alcGetCurrentContext     },
    { "alcGetContextsDevice",       (ALCvoid *) alcGetContextsDevice     },
#ifndef __ALC_OPEN_DEVICE_ASYNC_ONLY__
    { "alcOpenDevice",              (ALCvoid *) alcOpenDevice            },
#else
    { "alcOpenDevice",              NULL                                 },
#endif
    { "alcOpenDeviceAsync",         (ALCvoid *) alcOpenDeviceAsync       },
    { "alcCloseDevice",             (ALCvoid *) alcCloseDevice           },
    { "alcGetError",                (ALCvoid *) alcGetError              },
    { "alcIsExtensionPresent",      (ALCvoid *) alcIsExtensionPresent    },
    { "alcGetProcAddress",          (ALCvoid *) alcGetProcAddress        },
    { "alcGetEnumValue",            (ALCvoid *) alcGetEnumValue          },
    { "alcGetString",               (ALCvoid *) alcGetString             },
    { "alcGetIntegerv",             (ALCvoid *) alcGetIntegerv           },
    { "alcCaptureOpenDevice",       (ALCvoid *) alcCaptureOpenDevice     },
    { "alcCaptureCloseDevice",      (ALCvoid *) alcCaptureCloseDevice    },
    { "alcCaptureStart",            (ALCvoid *) alcCaptureStart          },
    { "alcCaptureStop",             (ALCvoid *) alcCaptureStop           },
    { "alcCaptureSamples",          (ALCvoid *) alcCaptureSamples        },

    { "alcSetThreadContext",        (ALCvoid *) alcSetThreadContext      },
    { "alcGetThreadContext",        (ALCvoid *) alcGetThreadContext      },

    { "alcLoopbackOpenDeviceSOFT",  (ALCvoid *) alcLoopbackOpenDeviceSOFT},
    { "alcIsRenderFormatSupportedSOFT",(ALCvoid *) alcIsRenderFormatSupportedSOFT},
    { "alcRenderSamplesSOFT",       (ALCvoid *) alcRenderSamplesSOFT         },

    { "alEnable",                   (ALCvoid *) alEnable                 },
    { "alDisable",                  (ALCvoid *) alDisable                },
    { "alIsEnabled",                (ALCvoid *) alIsEnabled              },
    { "alGetString",                (ALCvoid *) alGetString              },
    { "alGetBooleanv",              (ALCvoid *) alGetBooleanv            },
    { "alGetIntegerv",              (ALCvoid *) alGetIntegerv            },
    { "alGetFloatv",                (ALCvoid *) alGetFloatv              },
    { "alGetDoublev",               (ALCvoid *) alGetDoublev             },
    { "alGetBoolean",               (ALCvoid *) alGetBoolean             },
    { "alGetInteger",               (ALCvoid *) alGetInteger             },
    { "alGetFloat",                 (ALCvoid *) alGetFloat               },
    { "alGetDouble",                (ALCvoid *) alGetDouble              },
    { "alGetError",                 (ALCvoid *) alGetError               },
    { "alIsExtensionPresent",       (ALCvoid *) alIsExtensionPresent     },
    { "alGetProcAddress",           (ALCvoid *) alGetProcAddress         },
    { "alGetEnumValue",             (ALCvoid *) alGetEnumValue           },
    { "alListenerf",                (ALCvoid *) alListenerf              },
    { "alListener3f",               (ALCvoid *) alListener3f             },
    { "alListenerfv",               (ALCvoid *) alListenerfv             },
    { "alListeneri",                (ALCvoid *) alListeneri              },
    { "alListener3i",               (ALCvoid *) alListener3i             },
    { "alListeneriv",               (ALCvoid *) alListeneriv             },
    { "alGetListenerf",             (ALCvoid *) alGetListenerf           },
    { "alGetListener3f",            (ALCvoid *) alGetListener3f          },
    { "alGetListenerfv",            (ALCvoid *) alGetListenerfv          },
    { "alGetListeneri",             (ALCvoid *) alGetListeneri           },
    { "alGetListener3i",            (ALCvoid *) alGetListener3i          },
    { "alGetListeneriv",            (ALCvoid *) alGetListeneriv          },
    { "alGenSources",               (ALCvoid *) alGenSources             },
    { "alDeleteSources",            (ALCvoid *) alDeleteSources          },
    { "alIsSource",                 (ALCvoid *) alIsSource               },
    { "alSourcef",                  (ALCvoid *) alSourcef                },
    { "alSource3f",                 (ALCvoid *) alSource3f               },
    { "alSourcefv",                 (ALCvoid *) alSourcefv               },
    { "alSourcei",                  (ALCvoid *) alSourcei                },
    { "alSource3i",                 (ALCvoid *) alSource3i               },
    { "alSourceiv",                 (ALCvoid *) alSourceiv               },
    { "alGetSourcef",               (ALCvoid *) alGetSourcef             },
    { "alGetSource3f",              (ALCvoid *) alGetSource3f            },
    { "alGetSourcefv",              (ALCvoid *) alGetSourcefv            },
    { "alGetSourcei",               (ALCvoid *) alGetSourcei             },
    { "alGetSource3i",              (ALCvoid *) alGetSource3i            },
    { "alGetSourceiv",              (ALCvoid *) alGetSourceiv            },
    { "alSourcePlayv",              (ALCvoid *) alSourcePlayv            },
    { "alSourceStopv",              (ALCvoid *) alSourceStopv            },
    { "alSourceRewindv",            (ALCvoid *) alSourceRewindv          },
    { "alSourcePausev",             (ALCvoid *) alSourcePausev           },
    { "alSourcePlay",               (ALCvoid *) alSourcePlay             },
    { "alSourceStop",               (ALCvoid *) alSourceStop             },
    { "alSourceRewind",             (ALCvoid *) alSourceRewind           },
    { "alSourcePause",              (ALCvoid *) alSourcePause            },
    { "alSourceQueueBuffers",       (ALCvoid *) alSourceQueueBuffers     },
    { "alSourceUnqueueBuffers",     (ALCvoid *) alSourceUnqueueBuffers   },
    { "alGenBuffers",               (ALCvoid *) alGenBuffers             },
    { "alDeleteBuffers",            (ALCvoid *) alDeleteBuffers          },
    { "alIsBuffer",                 (ALCvoid *) alIsBuffer               },
    { "alBufferData",               (ALCvoid *) alBufferData             },
    { "alBufferDataStatic",         (ALCvoid *) alBufferDataStatic       },
    { "alBufferf",                  (ALCvoid *) alBufferf                },
    { "alBuffer3f",                 (ALCvoid *) alBuffer3f               },
    { "alBufferfv",                 (ALCvoid *) alBufferfv               },
    { "alBufferi",                  (ALCvoid *) alBufferi                },
    { "alBuffer3i",                 (ALCvoid *) alBuffer3i               },
    { "alBufferiv",                 (ALCvoid *) alBufferiv               },
    { "alGetBufferf",               (ALCvoid *) alGetBufferf             },
    { "alGetBuffer3f",              (ALCvoid *) alGetBuffer3f            },
    { "alGetBufferfv",              (ALCvoid *) alGetBufferfv            },
    { "alGetBufferi",               (ALCvoid *) alGetBufferi             },
    { "alGetBuffer3i",              (ALCvoid *) alGetBuffer3i            },
    { "alGetBufferiv",              (ALCvoid *) alGetBufferiv            },
    { "alDopplerFactor",            (ALCvoid *) alDopplerFactor          },
    { "alDopplerVelocity",          (ALCvoid *) alDopplerVelocity        },
    { "alSpeedOfSound",             (ALCvoid *) alSpeedOfSound           },
    { "alDistanceModel",            (ALCvoid *) alDistanceModel          },

    { "alGenFilters",               (ALCvoid *) alGenFilters             },
    { "alDeleteFilters",            (ALCvoid *) alDeleteFilters          },
    { "alIsFilter",                 (ALCvoid *) alIsFilter               },
    { "alFilteri",                  (ALCvoid *) alFilteri                },
    { "alFilteriv",                 (ALCvoid *) alFilteriv               },
    { "alFilterf",                  (ALCvoid *) alFilterf                },
    { "alFilterfv",                 (ALCvoid *) alFilterfv               },
    { "alGetFilteri",               (ALCvoid *) alGetFilteri             },
    { "alGetFilteriv",              (ALCvoid *) alGetFilteriv            },
    { "alGetFilterf",               (ALCvoid *) alGetFilterf             },
    { "alGetFilterfv",              (ALCvoid *) alGetFilterfv            },
    { "alGenEffects",               (ALCvoid *) alGenEffects             },
    { "alDeleteEffects",            (ALCvoid *) alDeleteEffects          },
    { "alIsEffect",                 (ALCvoid *) alIsEffect               },
    { "alEffecti",                  (ALCvoid *) alEffecti                },
    { "alEffectiv",                 (ALCvoid *) alEffectiv               },
    { "alEffectf",                  (ALCvoid *) alEffectf                },
    { "alEffectfv",                 (ALCvoid *) alEffectfv               },
    { "alGetEffecti",               (ALCvoid *) alGetEffecti             },
    { "alGetEffectiv",              (ALCvoid *) alGetEffectiv            },
    { "alGetEffectf",               (ALCvoid *) alGetEffectf             },
    { "alGetEffectfv",              (ALCvoid *) alGetEffectfv            },
    { "alGenAuxiliaryEffectSlots",  (ALCvoid *) alGenAuxiliaryEffectSlots},
    { "alDeleteAuxiliaryEffectSlots",(ALCvoid *) alDeleteAuxiliaryEffectSlots},
    { "alIsAuxiliaryEffectSlot",    (ALCvoid *) alIsAuxiliaryEffectSlot  },
    { "alAuxiliaryEffectSloti",     (ALCvoid *) alAuxiliaryEffectSloti   },
    { "alAuxiliaryEffectSlotiv",    (ALCvoid *) alAuxiliaryEffectSlotiv  },
    { "alAuxiliaryEffectSlotf",     (ALCvoid *) alAuxiliaryEffectSlotf   },
    { "alAuxiliaryEffectSlotfv",    (ALCvoid *) alAuxiliaryEffectSlotfv  },
    { "alGetAuxiliaryEffectSloti",  (ALCvoid *) alGetAuxiliaryEffectSloti},
    { "alGetAuxiliaryEffectSlotiv", (ALCvoid *) alGetAuxiliaryEffectSlotiv},
    { "alGetAuxiliaryEffectSlotf",  (ALCvoid *) alGetAuxiliaryEffectSlotf},
    { "alGetAuxiliaryEffectSlotfv", (ALCvoid *) alGetAuxiliaryEffectSlotfv},

    { "alBufferSubDataSOFT",        (ALCvoid *) alBufferSubDataSOFT      },

    { "alBufferSamplesSOFT",        (ALCvoid *) alBufferSamplesSOFT      },
    { "alBufferSubSamplesSOFT",     (ALCvoid *) alBufferSubSamplesSOFT   },
    { "alGetBufferSamplesSOFT",     (ALCvoid *) alGetBufferSamplesSOFT   },
    { "alIsBufferFormatSupportedSOFT",(ALCvoid *) alIsBufferFormatSupportedSOFT},

    { "alDeferUpdatesSOFT",         (ALCvoid *) alDeferUpdatesSOFT       },
    { "alProcessUpdatesSOFT",       (ALCvoid *) alProcessUpdatesSOFT     },

    { NULL,                         (ALCvoid *) NULL                     }
};

static const ALCenums enumeration[] = {
    // Types
    { "ALC_INVALID",                          ALC_INVALID                         },
    { "ALC_FALSE",                            ALC_FALSE                           },
    { "ALC_TRUE",                             ALC_TRUE                            },

    // ALC Properties
    { "ALC_MAJOR_VERSION",                    ALC_MAJOR_VERSION                   },
    { "ALC_MINOR_VERSION",                    ALC_MINOR_VERSION                   },
    { "ALC_ATTRIBUTES_SIZE",                  ALC_ATTRIBUTES_SIZE                 },
    { "ALC_ALL_ATTRIBUTES",                   ALC_ALL_ATTRIBUTES                  },
    { "ALC_DEFAULT_DEVICE_SPECIFIER",         ALC_DEFAULT_DEVICE_SPECIFIER        },
    { "ALC_DEVICE_SPECIFIER",                 ALC_DEVICE_SPECIFIER                },
    { "ALC_ALL_DEVICES_SPECIFIER",            ALC_ALL_DEVICES_SPECIFIER           },
    { "ALC_DEFAULT_ALL_DEVICES_SPECIFIER",    ALC_DEFAULT_ALL_DEVICES_SPECIFIER   },
    { "ALC_EXTENSIONS",                       ALC_EXTENSIONS                      },
    { "ALC_FREQUENCY",                        ALC_FREQUENCY                       },
    { "ALC_REFRESH",                          ALC_REFRESH                         },
    { "ALC_SYNC",                             ALC_SYNC                            },
    { "ALC_MONO_SOURCES",                     ALC_MONO_SOURCES                    },
    { "ALC_STEREO_SOURCES",                   ALC_STEREO_SOURCES                  },
    { "ALC_CAPTURE_DEVICE_SPECIFIER",         ALC_CAPTURE_DEVICE_SPECIFIER        },
    { "ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER", ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER},
    { "ALC_CAPTURE_SAMPLES",                  ALC_CAPTURE_SAMPLES                 },
    { "ALC_CONNECTED",                        ALC_CONNECTED                       },

    // EFX Properties
    { "ALC_EFX_MAJOR_VERSION",                ALC_EFX_MAJOR_VERSION               },
    { "ALC_EFX_MINOR_VERSION",                ALC_EFX_MINOR_VERSION               },
    { "ALC_MAX_AUXILIARY_SENDS",              ALC_MAX_AUXILIARY_SENDS             },

    // Loopback device Properties
    { "ALC_FORMAT_CHANNELS_SOFT",             ALC_FORMAT_CHANNELS_SOFT            },
    { "ALC_FORMAT_TYPE_SOFT",                 ALC_FORMAT_TYPE_SOFT                },

    // Buffer Channel Configurations
    { "ALC_MONO_SOFT",                        ALC_MONO_SOFT                       },
    { "ALC_STEREO_SOFT",                      ALC_STEREO_SOFT                     },
    { "ALC_QUAD_SOFT",                        ALC_QUAD_SOFT                       },
    { "ALC_5POINT1_SOFT",                     ALC_5POINT1_SOFT                    },
    { "ALC_6POINT1_SOFT",                     ALC_6POINT1_SOFT                    },
    { "ALC_7POINT1_SOFT",                     ALC_7POINT1_SOFT                    },

    // Buffer Sample Types
    { "ALC_BYTE_SOFT",                        ALC_BYTE_SOFT                       },
    { "ALC_UNSIGNED_BYTE_SOFT",               ALC_UNSIGNED_BYTE_SOFT              },
    { "ALC_SHORT_SOFT",                       ALC_SHORT_SOFT                      },
    { "ALC_UNSIGNED_SHORT_SOFT",              ALC_UNSIGNED_SHORT_SOFT             },
    { "ALC_INT_SOFT",                         ALC_INT_SOFT                        },
    { "ALC_UNSIGNED_INT_SOFT",                ALC_UNSIGNED_INT_SOFT               },
    { "ALC_FLOAT_SOFT",                       ALC_FLOAT_SOFT                      },

    // ALC Error Message
    { "ALC_NO_ERROR",                         ALC_NO_ERROR                        },
    { "ALC_INVALID_DEVICE",                   ALC_INVALID_DEVICE                  },
    { "ALC_INVALID_CONTEXT",                  ALC_INVALID_CONTEXT                 },
    { "ALC_INVALID_ENUM",                     ALC_INVALID_ENUM                    },
    { "ALC_INVALID_VALUE",                    ALC_INVALID_VALUE                   },
    { "ALC_OUT_OF_MEMORY",                    ALC_OUT_OF_MEMORY                   },

    { NULL,                                   (ALCenum)0 }
};
// Error strings
static const ALCchar alcNoError[] = "No Error";
static const ALCchar alcErrInvalidDevice[] = "Invalid Device";
static const ALCchar alcErrInvalidContext[] = "Invalid Context";
static const ALCchar alcErrInvalidEnum[] = "Invalid Enum";
static const ALCchar alcErrInvalidValue[] = "Invalid Value";
static const ALCchar alcErrOutOfMemory[] = "Out of Memory";

/* Device lists. Sizes only include the first ending null character, not the
 * second */
static ALCchar *alcDeviceList;
static size_t alcDeviceListSize;
static ALCchar *alcAllDeviceList;
static size_t alcAllDeviceListSize;
static ALCchar *alcCaptureDeviceList;
static size_t alcCaptureDeviceListSize;
/* Default is always the first in the list */
static ALCchar *alcDefaultDeviceSpecifier;
static ALCchar *alcDefaultAllDeviceSpecifier;
static ALCchar *alcCaptureDefaultDeviceSpecifier;


static const ALCchar alcNoDeviceExtList[] =
    "ALC_ENUMERATE_ALL_EXT ALC_ENUMERATION_EXT ALC_EXT_CAPTURE "
    "ALC_EXT_thread_local_context ALC_SOFTX_loopback_device";
static const ALCchar alcExtensionList[] =
    "ALC_ENUMERATE_ALL_EXT ALC_ENUMERATION_EXT ALC_EXT_CAPTURE "
    "ALC_EXT_DEDICATED ALC_EXT_disconnect ALC_EXT_EFX "
    "ALC_EXT_thread_local_context ALC_SOFTX_loopback_device";
static const ALCint alcMajorVersion = 1;
static const ALCint alcMinorVersion = 1;

static const ALCint alcEFXMajorVersion = 1;
static const ALCint alcEFXMinorVersion = 0;

///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// Global Variables

static CRITICAL_SECTION ListLock;

/* Device List */
static ALCdevice *volatile DeviceList = NULL;

// Thread-local current context
static pthread_key_t LocalContext;
// Process-wide current context
static ALCcontext *GlobalContext;

/* Device Error */
static volatile ALCenum g_eLastNullDeviceError = ALC_NO_ERROR;

// Default context extensions
static const ALchar alExtList[] =
    "AL_EXT_ALAW AL_EXT_DOUBLE AL_EXT_EXPONENT_DISTANCE AL_EXT_FLOAT32 "
    "AL_EXT_IMA4 AL_EXT_LINEAR_DISTANCE AL_EXT_MCFORMATS AL_EXT_MULAW "
    "AL_EXT_MULAW_MCFORMATS AL_EXT_OFFSET AL_EXT_source_distance_model "
    "AL_LOKI_quadriphonic AL_SOFT_buffer_samples AL_SOFT_buffer_sub_data "
    "AL_SOFTX_deferred_updates AL_SOFT_loop_points "
    "AL_SOFTX_non_virtual_channels";

// Mixing Priority Level
ALint RTPrioLevel;

// Output Log File
FILE *LogFile;

// Output Log Level
#ifdef _DEBUG
enum LogLevel LogLevel = LogWarning;
#else
enum LogLevel LogLevel = LogError;
#endif

/* Flag to trap ALC device errors */
static ALCboolean TrapALCError = ALC_FALSE;

/* One-time configuration init control */
static pthread_once_t alc_config_once = PTHREAD_ONCE_INIT;

/* Forced effect that applies to sources that don't have an effect on send 0 */
static ALeffect ForcedEffect;

///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// ALC Related helper functions
static void ReleaseALC(void);
static void ReleaseThreadCtx(void *ptr);

static void alc_initconfig(void);
#define DO_INITCONFIG() pthread_once(&alc_config_once, alc_initconfig)

#if defined(_WIN32)
static void alc_init(void);
static void alc_deinit(void);
static void alc_deinit_safe(void);

UIntMap TlsDestructor;

#if !defined AL_LIBTYPE_STATIC
BOOL APIENTRY DllMain(HANDLE hModule,DWORD ul_reason_for_call,LPVOID lpReserved)
{
    ALsizei i;
    (void)hModule;

    // Perform actions based on the reason for calling.
    switch(ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            InitUIntMap(&TlsDestructor, ~0);
            alc_init();
            break;

        case DLL_THREAD_DETACH:
            LockUIntMapRead(&TlsDestructor);
            for(i = 0;i < TlsDestructor.size;i++)
            {
                void *ptr = pthread_getspecific(TlsDestructor.array[i].key);
                void (*callback)(void*) = (void(*)(void*))TlsDestructor.array[i].value;
                if(ptr && callback)
                    callback(ptr);
            }
            UnlockUIntMapRead(&TlsDestructor);
            break;

        case DLL_PROCESS_DETACH:
            if(!lpReserved)
                alc_deinit();
            else
                alc_deinit_safe();
            ResetUIntMap(&TlsDestructor);
            break;
    }
    return TRUE;
}
#elif defined(_MSC_VER)
#pragma section(".CRT$XCU",read)
static void alc_constructor(void);
static void alc_destructor(void);
__declspec(allocate(".CRT$XCU")) void (__cdecl* alc_constructor_)(void) = alc_constructor;

static void alc_constructor(void)
{
    atexit(alc_destructor);
    alc_init();
}

static void alc_destructor(void)
{
    alc_deinit();
}
#elif defined(HAVE_GCC_DESTRUCTOR)
static void alc_init(void) __attribute__((constructor));
static void alc_deinit(void) __attribute__((destructor));
#else
#error "No static initialization available on this platform!"
#endif
#elif defined(HAVE_GCC_DESTRUCTOR)
static void alc_init(void) __attribute__((constructor));
static void alc_deinit(void) __attribute__((destructor));
#else
#error "No global initialization available on this platform!"
#endif

static void alc_init(void)
{
    const char *str;

    LogFile = stderr;

    str = getenv("__ALSOFT_HALF_ANGLE_CONES");
    if(str && (strcasecmp(str, "true") == 0 || strtol(str, NULL, 0) == 1))
        ConeScale = 1.0f;

    str = getenv("__ALSOFT_REVERSE_Z");
    if(str && (strcasecmp(str, "true") == 0 || strtol(str, NULL, 0) == 1))
        ZScale = -1.0f;

    str = getenv("__ALSOFT_TRAP_ERROR");
    if(str && (strcasecmp(str, "true") == 0 || strtol(str, NULL, 0) == 1))
    {
        TrapALError  = AL_TRUE;
        TrapALCError = AL_TRUE;
    }
    else
    {
        str = getenv("__ALSOFT_TRAP_AL_ERROR");
        if(str && (strcasecmp(str, "true") == 0 || strtol(str, NULL, 0) == 1))
            TrapALError = AL_TRUE;

        str = getenv("__ALSOFT_TRAP_ALC_ERROR");
        if(str && (strcasecmp(str, "true") == 0 || strtol(str, NULL, 0) == 1))
            TrapALCError = ALC_TRUE;
    }

    pthread_key_create(&LocalContext, ReleaseThreadCtx);
    InitializeCriticalSection(&ListLock);
    ThunkInit();
}

static void alc_deinit_safe(void)
{
    ReleaseALC();

    FreeHrtf();
    FreeALConfig();

    ThunkExit();
    DeleteCriticalSection(&ListLock);
    pthread_key_delete(LocalContext);

    if(LogFile != stderr)
        fclose(LogFile);
    LogFile = NULL;
}

static void alc_deinit(void)
{
    int i;

    ReleaseALC();

    memset(&PlaybackBackend, 0, sizeof(PlaybackBackend));
    memset(&CaptureBackend, 0, sizeof(CaptureBackend));

    for(i = 0;BackendList[i].Deinit;i++)
        BackendList[i].Deinit();
    BackendLoopback.Deinit();

    alc_deinit_safe();
}

static void alc_initconfig(void)
{
    const char *devs, *str;
    float valf;
    int i, n;

    str = getenv("ALSOFT_LOGLEVEL");
    if(str)
    {
        long lvl = strtol(str, NULL, 0);
        if(lvl >= NoLog && lvl <= LogRef)
            LogLevel = lvl;
    }

    str = getenv("ALSOFT_LOGFILE");
    if(str && str[0])
    {
        FILE *logfile = fopen(str, "wat");
        if(logfile) LogFile = logfile;
        else ERR("Failed to open log file '%s'\n", str);
    }

    ReadALConfig();

    InitHrtf();

#ifdef _WIN32
    RTPrioLevel = 1;
#else
    RTPrioLevel = 0;
#endif
    ConfigValueInt(NULL, "rt-prio", &RTPrioLevel);

    if(ConfigValueStr(NULL, "resampler", &str))
    {
        if(strcasecmp(str, "point") == 0 || strcasecmp(str, "none") == 0)
            DefaultResampler = POINT_RESAMPLER;
        else if(strcasecmp(str, "linear") == 0)
            DefaultResampler = LINEAR_RESAMPLER;
        else if(strcasecmp(str, "cubic") == 0)
            DefaultResampler = CUBIC_RESAMPLER;
        else
        {
            char *end;

            n = strtol(str, &end, 0);
            if(*end == '\0' && n < RESAMPLER_MAX && n > RESAMPLER_MIN)
                DefaultResampler = n;
            else
                WARN("Invalid resampler: %s\n", str);
        }
    }

    if(!TrapALCError)
        TrapALCError = GetConfigValueBool(NULL, "trap-alc-error", ALC_FALSE);

    if(!TrapALError)
        TrapALError = GetConfigValueBool(NULL, "trap-al-error", AL_FALSE);

    if(ConfigValueFloat("reverb", "boost", &valf))
        ReverbBoost *= aluPow(10.0f, valf / 20.0f);

    EmulateEAXReverb = GetConfigValueBool("reverb", "emulate-eax", AL_FALSE);

    if(ConfigValueStr(NULL, "drivers", &devs))
    {
        int n;
        size_t len;
        const char *next = devs;
        int endlist, delitem;

        i = 0;
        do {
            devs = next;
            next = strchr(devs, ',');

            delitem = (devs[0] == '-');
            if(devs[0] == '-') devs++;

            if(!devs[0] || devs[0] == ',')
            {
                endlist = 0;
                continue;
            }
            endlist = 1;

            len = (next ? ((size_t)(next-devs)) : strlen(devs));
            for(n = i;BackendList[n].Init;n++)
            {
                if(len == strlen(BackendList[n].name) &&
                   strncmp(BackendList[n].name, devs, len) == 0)
                {
                    if(delitem)
                    {
                        do {
                            BackendList[n] = BackendList[n+1];
                            ++n;
                        } while(BackendList[n].Init);
                    }
                    else
                    {
                        struct BackendInfo Bkp = BackendList[n];
                        while(n > i)
                        {
                            BackendList[n] = BackendList[n-1];
                            --n;
                        }
                        BackendList[n] = Bkp;

                        i++;
                    }
                    break;
                }
            }
        } while(next++);

        if(endlist)
        {
            BackendList[i].name = NULL;
            BackendList[i].Init = NULL;
            BackendList[i].Deinit = NULL;
            BackendList[i].Probe = NULL;
        }
    }

    for(i = 0;BackendList[i].Init && (!PlaybackBackend.name || !CaptureBackend.name);i++)
    {
        if(!BackendList[i].Init(&BackendList[i].Funcs))
        {
            WARN("Failed to initialize backend \"%s\"\n", BackendList[i].name);
            continue;
        }

        TRACE("Initialized backend \"%s\"\n", BackendList[i].name);
        if(BackendList[i].Funcs.OpenPlayback && !PlaybackBackend.name)
        {
            PlaybackBackend = BackendList[i];
            TRACE("Added \"%s\" for playback\n", PlaybackBackend.name);
        }
        if(BackendList[i].Funcs.OpenCapture && !CaptureBackend.name)
        {
            CaptureBackend = BackendList[i];
            TRACE("Added \"%s\" for capture\n", CaptureBackend.name);
        }
    }
    BackendLoopback.Init(&BackendLoopback.Funcs);

    if(ConfigValueStr(NULL, "excludefx", &str))
    {
        size_t len;
        const char *next = str;

        do {
            str = next;
            next = strchr(str, ',');

            if(!str[0] || next == str)
                continue;

            len = (next ? ((size_t)(next-str)) : strlen(str));
            for(n = 0;EffectList[n].name;n++)
            {
                if(len == strlen(EffectList[n].name) &&
                   strncmp(EffectList[n].name, str, len) == 0)
                    DisabledEffects[EffectList[n].type] = AL_TRUE;
            }
        } while(next++);
    }

    InitEffect(&ForcedEffect);
    str = getenv("__ALSOFT_DEFAULT_REVERB");
    if(str && str[0])
        GetReverbEffect(str, &ForcedEffect);
    else if(ConfigValueStr(NULL, "default-reverb", &str))
        GetReverbEffect(str, &ForcedEffect);
}


static void LockLists(void)
{
    EnterCriticalSection(&ListLock);
}

static void UnlockLists(void)
{
    LeaveCriticalSection(&ListLock);
}


static void ProbeList(ALCchar **list, size_t *listsize, enum DevProbe type)
{
    DO_INITCONFIG();

    LockLists();
    free(*list);
    *list = NULL;
    *listsize = 0;

    if(type == CAPTURE_DEVICE_PROBE)
        CaptureBackend.Probe(type);
    else
        PlaybackBackend.Probe(type);
    UnlockLists();
}

static void ProbeDeviceList(void)
{ ProbeList(&alcDeviceList, &alcDeviceListSize, DEVICE_PROBE); }
static void ProbeAllDeviceList(void)
{ ProbeList(&alcAllDeviceList, &alcAllDeviceListSize, ALL_DEVICE_PROBE); }
static void ProbeCaptureDeviceList(void)
{ ProbeList(&alcCaptureDeviceList, &alcCaptureDeviceListSize, CAPTURE_DEVICE_PROBE); }


static void AppendList(const ALCchar *name, ALCchar **List, size_t *ListSize)
{
    size_t len = strlen(name);
    void *temp;

    if(len == 0)
        return;

    temp = realloc(*List, (*ListSize) + len + 2);
    if(!temp)
    {
        ERR("Realloc failed to add %s!\n", name);
        return;
    }
    *List = temp;

    memcpy((*List)+(*ListSize), name, len+1);
    *ListSize += len+1;
    (*List)[*ListSize] = 0;
}

#define DECL_APPEND_LIST_FUNC(type)                                          \
void Append##type##List(const ALCchar *name)                                 \
{ AppendList(name, &alc##type##List, &alc##type##ListSize); }

DECL_APPEND_LIST_FUNC(Device)
DECL_APPEND_LIST_FUNC(AllDevice)
DECL_APPEND_LIST_FUNC(CaptureDevice)

#undef DECL_APPEND_LIST_FUNC


/* Sets the default channel order used by most non-WaveFormatEx-based APIs */
void SetDefaultChannelOrder(ALCdevice *device)
{
    switch(device->FmtChans)
    {
    case DevFmtX51: device->DevChannels[0] = FRONT_LEFT;
                    device->DevChannels[1] = FRONT_RIGHT;
                    device->DevChannels[2] = BACK_LEFT;
                    device->DevChannels[3] = BACK_RIGHT;
                    device->DevChannels[4] = FRONT_CENTER;
                    device->DevChannels[5] = LFE;
                    return;

    case DevFmtX71: device->DevChannels[0] = FRONT_LEFT;
                    device->DevChannels[1] = FRONT_RIGHT;
                    device->DevChannels[2] = BACK_LEFT;
                    device->DevChannels[3] = BACK_RIGHT;
                    device->DevChannels[4] = FRONT_CENTER;
                    device->DevChannels[5] = LFE;
                    device->DevChannels[6] = SIDE_LEFT;
                    device->DevChannels[7] = SIDE_RIGHT;
                    return;

    /* Same as WFX order */
    case DevFmtMono:
    case DevFmtStereo:
    case DevFmtQuad:
    case DevFmtX51Side:
    case DevFmtX61:
        break;
    }
    SetDefaultWFXChannelOrder(device);
}
/* Sets the default order used by WaveFormatEx */
void SetDefaultWFXChannelOrder(ALCdevice *device)
{
    switch(device->FmtChans)
    {
    case DevFmtMono: device->DevChannels[0] = FRONT_CENTER; break;

    case DevFmtStereo: device->DevChannels[0] = FRONT_LEFT;
                       device->DevChannels[1] = FRONT_RIGHT; break;

    case DevFmtQuad: device->DevChannels[0] = FRONT_LEFT;
                     device->DevChannels[1] = FRONT_RIGHT;
                     device->DevChannels[2] = BACK_LEFT;
                     device->DevChannels[3] = BACK_RIGHT; break;

    case DevFmtX51: device->DevChannels[0] = FRONT_LEFT;
                    device->DevChannels[1] = FRONT_RIGHT;
                    device->DevChannels[2] = FRONT_CENTER;
                    device->DevChannels[3] = LFE;
                    device->DevChannels[4] = BACK_LEFT;
                    device->DevChannels[5] = BACK_RIGHT; break;

    case DevFmtX51Side: device->DevChannels[0] = FRONT_LEFT;
                        device->DevChannels[1] = FRONT_RIGHT;
                        device->DevChannels[2] = FRONT_CENTER;
                        device->DevChannels[3] = LFE;
                        device->DevChannels[4] = SIDE_LEFT;
                        device->DevChannels[5] = SIDE_RIGHT; break;

    case DevFmtX61: device->DevChannels[0] = FRONT_LEFT;
                    device->DevChannels[1] = FRONT_RIGHT;
                    device->DevChannels[2] = FRONT_CENTER;
                    device->DevChannels[3] = LFE;
                    device->DevChannels[4] = BACK_CENTER;
                    device->DevChannels[5] = SIDE_LEFT;
                    device->DevChannels[6] = SIDE_RIGHT; break;

    case DevFmtX71: device->DevChannels[0] = FRONT_LEFT;
                    device->DevChannels[1] = FRONT_RIGHT;
                    device->DevChannels[2] = FRONT_CENTER;
                    device->DevChannels[3] = LFE;
                    device->DevChannels[4] = BACK_LEFT;
                    device->DevChannels[5] = BACK_RIGHT;
                    device->DevChannels[6] = SIDE_LEFT;
                    device->DevChannels[7] = SIDE_RIGHT; break;
    }
}


const ALCchar *DevFmtTypeString(enum DevFmtType type)
{
    switch(type)
    {
    case DevFmtByte: return "Signed Byte";
    case DevFmtUByte: return "Unsigned Byte";
    case DevFmtShort: return "Signed Short";
    case DevFmtUShort: return "Unsigned Short";
    case DevFmtFloat: return "Float";
    }
    return "(unknown type)";
}
const ALCchar *DevFmtChannelsString(enum DevFmtChannels chans)
{
    switch(chans)
    {
    case DevFmtMono: return "Mono";
    case DevFmtStereo: return "Stereo";
    case DevFmtQuad: return "Quadraphonic";
    case DevFmtX51: return "5.1 Surround";
    case DevFmtX51Side: return "5.1 Side";
    case DevFmtX61: return "6.1 Surround";
    case DevFmtX71: return "7.1 Surround";
    }
    return "(unknown channels)";
}

ALuint BytesFromDevFmt(enum DevFmtType type)
{
    switch(type)
    {
    case DevFmtByte: return sizeof(ALbyte);
    case DevFmtUByte: return sizeof(ALubyte);
    case DevFmtShort: return sizeof(ALshort);
    case DevFmtUShort: return sizeof(ALushort);
    case DevFmtFloat: return sizeof(ALfloat);
    }
    return 0;
}
ALuint ChannelsFromDevFmt(enum DevFmtChannels chans)
{
    switch(chans)
    {
    case DevFmtMono: return 1;
    case DevFmtStereo: return 2;
    case DevFmtQuad: return 4;
    case DevFmtX51: return 6;
    case DevFmtX51Side: return 6;
    case DevFmtX61: return 7;
    case DevFmtX71: return 8;
    }
    return 0;
}
static ALboolean DecomposeDevFormat(ALenum format, enum DevFmtChannels *chans,
                                    enum DevFmtType *type)
{
    static const struct {
        ALenum format;
        enum DevFmtChannels channels;
        enum DevFmtType type;
    } list[] = {
        { AL_FORMAT_MONO8,        DevFmtMono, DevFmtUByte },
        { AL_FORMAT_MONO16,       DevFmtMono, DevFmtShort },
        { AL_FORMAT_MONO_FLOAT32, DevFmtMono, DevFmtFloat },

        { AL_FORMAT_STEREO8,        DevFmtStereo, DevFmtUByte },
        { AL_FORMAT_STEREO16,       DevFmtStereo, DevFmtShort },
        { AL_FORMAT_STEREO_FLOAT32, DevFmtStereo, DevFmtFloat },

        { AL_FORMAT_QUAD8,  DevFmtQuad, DevFmtUByte },
        { AL_FORMAT_QUAD16, DevFmtQuad, DevFmtShort },
        { AL_FORMAT_QUAD32, DevFmtQuad, DevFmtFloat },

        { AL_FORMAT_51CHN8,  DevFmtX51, DevFmtUByte },
        { AL_FORMAT_51CHN16, DevFmtX51, DevFmtShort },
        { AL_FORMAT_51CHN32, DevFmtX51, DevFmtFloat },

        { AL_FORMAT_61CHN8,  DevFmtX61, DevFmtUByte },
        { AL_FORMAT_61CHN16, DevFmtX61, DevFmtShort },
        { AL_FORMAT_61CHN32, DevFmtX61, DevFmtFloat },

        { AL_FORMAT_71CHN8,  DevFmtX71, DevFmtUByte },
        { AL_FORMAT_71CHN16, DevFmtX71, DevFmtShort },
        { AL_FORMAT_71CHN32, DevFmtX71, DevFmtFloat },
    };
    ALuint i;

    for(i = 0;i < sizeof(list)/sizeof(list[0]);i++)
    {
        if(list[i].format == format)
        {
            *chans = list[i].channels;
            *type  = list[i].type;
            return AL_TRUE;
        }
    }

    return AL_FALSE;
}

static ALCboolean IsValidALCType(ALCenum type)
{
    switch(type)
    {
        case ALC_BYTE_SOFT:
        case ALC_UNSIGNED_BYTE_SOFT:
        case ALC_SHORT_SOFT:
        case ALC_UNSIGNED_SHORT_SOFT:
        case ALC_INT_SOFT:
        case ALC_UNSIGNED_INT_SOFT:
        case ALC_FLOAT_SOFT:
            return ALC_TRUE;
    }
    return ALC_FALSE;
}

static ALCboolean IsValidALCChannels(ALCenum channels)
{
    switch(channels)
    {
        case ALC_MONO_SOFT:
        case ALC_STEREO_SOFT:
        case ALC_QUAD_SOFT:
        case ALC_5POINT1_SOFT:
        case ALC_6POINT1_SOFT:
        case ALC_7POINT1_SOFT:
            return ALC_TRUE;
    }
    return ALC_FALSE;
}


/* alcSetError
 *
 * Stores the latest ALC Error
 */
void alcSetError(ALCdevice *device, ALCenum errorCode)
{
    if(TrapALCError)
    {
#if defined _WIN32 && !defined _WIN_RT
        /* DebugBreak() will cause an exception if there is no debugger */
        if(IsDebuggerPresent())
            DebugBreak();
#elif defined(SIGTRAP)
        raise(SIGTRAP);
#endif
    }

    if(device)
        device->LastError = errorCode;
    else
        g_eLastNullDeviceError = errorCode;
}


/* UpdateDeviceParams
 *
 * Updates device parameters according to the attribute list (caller is
 * responsible for holding the list lock).
 */
static ALCenum UpdateDeviceParams(ALCdevice *device, const ALCint *attrList)
{
    ALCcontext *context;
    enum DevFmtChannels oldChans;
    enum DevFmtType oldType;
    ALCuint oldFreq;
    int oldMode;
    ALuint i;

    if(device->IsLoopbackDevice && !(attrList && attrList[0]))
    {
        WARN("Missing attributes for loopback device\n");
        return ALC_INVALID_VALUE;
    }

    // Check for attributes
    if(attrList && attrList[0])
    {
        enum {
            GotFreq  = 1<<0,
            GotChans = 1<<1,
            GotType  = 1<<2,
            GotAll   = GotFreq|GotChans|GotType
        };
        ALCuint freq, numMono, numStereo, numSends;
        enum DevFmtChannels schans;
        enum DevFmtType stype;
        ALCuint attrIdx = 0;
        ALCint gotFmt = 0;

        // If a context is already running on the device, stop playback so the
        // device attributes can be updated
        if((device->Flags&DEVICE_RUNNING))
            ALCdevice_StopPlayback(device);
        device->Flags &= ~DEVICE_RUNNING;

        freq = device->Frequency;
        schans = device->FmtChans;
        stype = device->FmtType;
        numMono = device->NumMonoSources;
        numStereo = device->NumStereoSources;
        numSends = device->NumAuxSends;

        while(attrList[attrIdx])
        {
            if(attrList[attrIdx] == ALC_FORMAT_CHANNELS_SOFT &&
               device->IsLoopbackDevice)
            {
                ALCint val = attrList[attrIdx + 1];
                if(!IsValidALCChannels(val) || !ChannelsFromDevFmt(val))
                    return ALC_INVALID_VALUE;
                schans = val;
                gotFmt |= GotChans;
            }

            if(attrList[attrIdx] == ALC_FORMAT_TYPE_SOFT &&
               device->IsLoopbackDevice)
            {
                ALCint val = attrList[attrIdx + 1];
                if(!IsValidALCType(val) || !BytesFromDevFmt(val))
                    return ALC_INVALID_VALUE;
                stype = val;
                gotFmt |= GotType;
            }

            if(attrList[attrIdx] == ALC_FREQUENCY)
            {
                if(device->IsLoopbackDevice)
                {
                    freq = attrList[attrIdx + 1];
                    if(freq < 8000)
                        return ALC_INVALID_VALUE;
                    gotFmt |= GotFreq;
                }
                else
                {
                    freq = attrList[attrIdx + 1];
                    device->Flags |= DEVICE_FREQUENCY_REQUEST;
                }
            }

            if(attrList[attrIdx] == ALC_STEREO_SOURCES)
            {
                numStereo = attrList[attrIdx + 1];
                if(numStereo > device->MaxNoOfSources)
                    numStereo = device->MaxNoOfSources;

                numMono = device->MaxNoOfSources - numStereo;
            }

            if(attrList[attrIdx] == ALC_MAX_AUXILIARY_SENDS)
                numSends = attrList[attrIdx + 1];

            attrIdx += 2;
        }

        if(device->IsLoopbackDevice)
        {
            if(gotFmt != GotAll)
            {
                WARN("Missing format for loopback device\n");
                return ALC_INVALID_VALUE;
            }
        }
        else
        {
            ConfigValueUInt(NULL, "frequency", &freq);
            freq = maxu(freq, 8000);
        }
        ConfigValueUInt(NULL, "sends", &numSends);
        numSends = minu(MAX_SENDS, numSends);

        device->UpdateSize = (ALuint64)device->UpdateSize * freq /
                             device->Frequency;

        device->Frequency = freq;
        device->FmtChans = schans;
        device->FmtType = stype;
        device->NumMonoSources = numMono;
        device->NumStereoSources = numStereo;
        device->NumAuxSends = numSends;
    }

    if((device->Flags&DEVICE_RUNNING))
        return ALC_NO_ERROR;

    LockDevice(device);

    oldFreq  = device->Frequency;
    oldChans = device->FmtChans;
    oldType  = device->FmtType;

    TRACE("Format pre-setup: %s%s, %s, %uhz%s, %u update size x%d\n",
          DevFmtChannelsString(device->FmtChans),
          (device->Flags&DEVICE_CHANNELS_REQUEST)?" (requested)":"",
          DevFmtTypeString(device->FmtType), device->Frequency,
          (device->Flags&DEVICE_FREQUENCY_REQUEST)?" (requested)":"",
          device->UpdateSize, device->NumUpdates);
    if(ALCdevice_ResetPlayback(device) == ALC_FALSE)
    {
        UnlockDevice(device);
        return ALC_INVALID_DEVICE;
    }
    device->Flags |= DEVICE_RUNNING;

    if(device->FmtChans != oldChans)
    {
        if((device->Flags&DEVICE_CHANNELS_REQUEST))
            ERR("Failed to set %s, got %s instead\n",
                DevFmtChannelsString(oldChans),
                DevFmtChannelsString(device->FmtChans));
        device->Flags &= ~DEVICE_CHANNELS_REQUEST;
    }
    if(device->Frequency != oldFreq)
    {
        if((device->Flags&DEVICE_FREQUENCY_REQUEST))
            ERR("Failed to set %uhz, got %uhz instead\n",
                oldFreq, device->Frequency);
        device->Flags &= ~DEVICE_FREQUENCY_REQUEST;
    }

    TRACE("Format post-setup: %s, %s, %uhz, %u update size x%d\n",
          DevFmtChannelsString(device->FmtChans),
          DevFmtTypeString(device->FmtType), device->Frequency,
          device->UpdateSize, device->NumUpdates);

    aluInitPanning(device);

    for(i = 0;i < MAXCHANNELS;i++)
    {
        device->ClickRemoval[i] = 0.0f;
        device->PendingClicks[i] = 0.0f;
    }

    device->Hrtf = NULL;
    if(!device->IsLoopbackDevice && GetConfigValueBool(NULL, "hrtf", AL_FALSE))
        device->Hrtf = GetHrtf(device);
    TRACE("HRTF %s\n", device->Hrtf?"enabled":"disabled");

    if(!device->Hrtf && device->Bs2bLevel > 0 && device->Bs2bLevel <= 6)
    {
        if(!device->Bs2b)
        {
            device->Bs2b = calloc(1, sizeof(*device->Bs2b));
            bs2b_clear(device->Bs2b);
        }
        bs2b_set_srate(device->Bs2b, device->Frequency);
        bs2b_set_level(device->Bs2b, device->Bs2bLevel);
        TRACE("BS2B level %d\n", device->Bs2bLevel);
    }
    else
    {
        free(device->Bs2b);
        device->Bs2b = NULL;
        TRACE("BS2B disabled\n");
    }

    device->Flags &= ~DEVICE_DUPLICATE_STEREO;
    switch(device->FmtChans)
    {
        case DevFmtMono:
        case DevFmtStereo:
            break;
        case DevFmtQuad:
        case DevFmtX51:
        case DevFmtX51Side:
        case DevFmtX61:
        case DevFmtX71:
            if(GetConfigValueBool(NULL, "stereodup", AL_TRUE))
                device->Flags |= DEVICE_DUPLICATE_STEREO;
            break;
    }
    TRACE("Stereo duplication %s\n", (device->Flags&DEVICE_DUPLICATE_STEREO)?"enabled":"disabled");

    oldMode = SetMixerFPUMode();
    context = device->ContextList;
    while(context)
    {
        ALsizei pos;

        context->UpdateSources = AL_FALSE;
        LockUIntMapRead(&context->EffectSlotMap);
        for(pos = 0;pos < context->EffectSlotMap.size;pos++)
        {
            ALeffectslot *slot = context->EffectSlotMap.array[pos].value;

            if(ALeffectState_DeviceUpdate(slot->EffectState, device) == AL_FALSE)
            {
                UnlockUIntMapRead(&context->EffectSlotMap);
                RestoreFPUMode(oldMode);
                UnlockDevice(device);
                ALCdevice_StopPlayback(device);
                device->Flags &= ~DEVICE_RUNNING;
                return ALC_INVALID_DEVICE;
            }
            slot->NeedsUpdate = AL_FALSE;
            ALeffectState_Update(slot->EffectState, context, slot);
        }
        UnlockUIntMapRead(&context->EffectSlotMap);

        LockUIntMapRead(&context->SourceMap);
        for(pos = 0;pos < context->SourceMap.size;pos++)
        {
            ALsource *source = context->SourceMap.array[pos].value;
            ALuint s = device->NumAuxSends;
            while(s < MAX_SENDS)
            {
                if(source->Send[s].Slot)
                    DecrementRef(&source->Send[s].Slot->ref);
                source->Send[s].Slot = NULL;
                source->Send[s].WetGain = 1.0f;
                source->Send[s].WetGainHF = 1.0f;
                s++;
            }
            source->NeedsUpdate = AL_FALSE;
            ALsource_Update(source, context);
        }
        UnlockUIntMapRead(&context->SourceMap);

        context = context->next;
    }
    RestoreFPUMode(oldMode);
    UnlockDevice(device);

    return ALC_NO_ERROR;
}

/* FreeDevice
 *
 * Frees the device structure, and destroys any objects the app failed to
 * delete. Called once there's no more references on the device.
 */
static ALCvoid FreeDevice(ALCdevice *device)
{
    TRACE("%p\n", device);

    if(device->DefaultSlot)
    {
        ALeffectState_Destroy(device->DefaultSlot->EffectState);
        device->DefaultSlot->EffectState = NULL;
    }

    if(device->BufferMap.size > 0)
    {
        WARN("(%p) Deleting %d Buffer(s)\n", device, device->BufferMap.size);
        ReleaseALBuffers(device);
    }
    ResetUIntMap(&device->BufferMap);

    if(device->EffectMap.size > 0)
    {
        WARN("(%p) Deleting %d Effect(s)\n", device, device->EffectMap.size);
        ReleaseALEffects(device);
    }
    ResetUIntMap(&device->EffectMap);

    if(device->FilterMap.size > 0)
    {
        WARN("(%p) Deleting %d Filter(s)\n", device, device->FilterMap.size);
        ReleaseALFilters(device);
    }
    ResetUIntMap(&device->FilterMap);

    free(device->Bs2b);
    device->Bs2b = NULL;

    free(device->szDeviceName);
    device->szDeviceName = NULL;

    DeleteCriticalSection(&device->Mutex);

    free(device);
}


void ALCdevice_IncRef(ALCdevice *device)
{
    RefCount ref;
    ref = IncrementRef(&device->ref);
    TRACEREF("%p increasing refcount to %u\n", device, ref);
}

void ALCdevice_DecRef(ALCdevice *device)
{
    RefCount ref;
    ref = DecrementRef(&device->ref);
    TRACEREF("%p decreasing refcount to %u\n", device, ref);
    if(ref == 0) FreeDevice(device);
}

/* VerifyDevice
 *
 * Checks if the device handle is valid, and increments its ref count if so.
 */
static ALCdevice *VerifyDevice(ALCdevice *device)
{
    ALCdevice *tmpDevice;

    if(!device)
        return NULL;

    LockLists();
    tmpDevice = DeviceList;
    while(tmpDevice && tmpDevice != device)
        tmpDevice = tmpDevice->next;

    if(tmpDevice)
        ALCdevice_IncRef(tmpDevice);
    UnlockLists();
    return tmpDevice;
}


/* InitContext
 *
 * Initializes context variables
 */
static ALvoid InitContext(ALCcontext *pContext)
{
    ALint i, j;

    //Initialise listener
    pContext->Listener.Gain = 1.0f;
    pContext->Listener.MetersPerUnit = 1.0f;
    pContext->Listener.Position[0] = 0.0f;
    pContext->Listener.Position[1] = 0.0f;
    pContext->Listener.Position[2] = 0.0f;
    pContext->Listener.Velocity[0] = 0.0f;
    pContext->Listener.Velocity[1] = 0.0f;
    pContext->Listener.Velocity[2] = 0.0f;
    pContext->Listener.Forward[0] = 0.0f;
    pContext->Listener.Forward[1] = 0.0f;
    pContext->Listener.Forward[2] = -1.0f;
    pContext->Listener.Up[0] = 0.0f;
    pContext->Listener.Up[1] = 1.0f;
    pContext->Listener.Up[2] = 0.0f;
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 4;j++)
            pContext->Listener.Matrix[i][j] = ((i==j) ? 1.0f : 0.0f);
    }

    //Validate pContext
    pContext->LastError = AL_NO_ERROR;
    pContext->UpdateSources = AL_FALSE;
    pContext->ActiveSourceCount = 0;
    InitUIntMap(&pContext->SourceMap, pContext->Device->MaxNoOfSources);
    InitUIntMap(&pContext->EffectSlotMap, pContext->Device->AuxiliaryEffectSlotMax);

    //Set globals
    pContext->DistanceModel = AL_INVERSE_DISTANCE_CLAMPED;
    pContext->SourceDistanceModel = AL_FALSE;
    pContext->DopplerFactor = 1.0f;
    pContext->DopplerVelocity = 1.0f;
    pContext->flSpeedOfSound = SPEEDOFSOUNDMETRESPERSEC;
    pContext->DeferUpdates = AL_FALSE;

    pContext->ExtensionList = alExtList;
}


/* FreeContext
 *
 * Cleans up the context, and destroys any remaining objects the app failed to
 * delete. Called once there's no more references on the context.
 */
static ALCvoid FreeContext(ALCcontext *context)
{
    TRACE("%p\n", context);

    if(context->SourceMap.size > 0)
    {
        ERR("(%p) Deleting %d Source(s)\n", context, context->SourceMap.size);
        ReleaseALSources(context);
    }
    ResetUIntMap(&context->SourceMap);

    if(context->EffectSlotMap.size > 0)
    {
        ERR("(%p) Deleting %d AuxiliaryEffectSlot(s)\n", context, context->EffectSlotMap.size);
        ReleaseALAuxiliaryEffectSlots(context);
    }
    ResetUIntMap(&context->EffectSlotMap);

    context->ActiveSourceCount = 0;
    free(context->ActiveSources);
    context->ActiveSources = NULL;
    context->MaxActiveSources = 0;

    context->ActiveEffectSlotCount = 0;
    free(context->ActiveEffectSlots);
    context->ActiveEffectSlots = NULL;
    context->MaxActiveEffectSlots = 0;

    ALCdevice_DecRef(context->Device);
    context->Device = NULL;

    //Invalidate context
    memset(context, 0, sizeof(ALCcontext));
    free(context);
}

/* ReleaseContext
 *
 * Removes the context reference from the given device and removes it from
 * being current on the running thread or globally.
 */
static void ReleaseContext(ALCcontext *context, ALCdevice *device)
{
    ALCcontext *volatile*tmp_ctx;

    if(pthread_getspecific(LocalContext) == context)
    {
        WARN("%p released while current on thread\n", context);
        pthread_setspecific(LocalContext, NULL);
        ALCcontext_DecRef(context);
    }

    if(CompExchangePtr((XchgPtr*)&GlobalContext, context, NULL))
        ALCcontext_DecRef(context);

    LockDevice(device);
    tmp_ctx = &device->ContextList;
    while(*tmp_ctx)
    {
        if(CompExchangePtr((XchgPtr*)tmp_ctx, context, context->next))
            break;
        tmp_ctx = &(*tmp_ctx)->next;
    }
    UnlockDevice(device);

    ALCcontext_DecRef(context);
}

void ALCcontext_IncRef(ALCcontext *context)
{
    RefCount ref;
    ref = IncrementRef(&context->ref);
    TRACEREF("%p increasing refcount to %u\n", context, ref);
}

void ALCcontext_DecRef(ALCcontext *context)
{
    RefCount ref;
    ref = DecrementRef(&context->ref);
    TRACEREF("%p decreasing refcount to %u\n", context, ref);
    if(ref == 0) FreeContext(context);
}

static void ReleaseThreadCtx(void *ptr)
{
    WARN("%p current for thread being destroyed\n", ptr);
    ALCcontext_DecRef(ptr);
}

/* VerifyContext
 *
 * Checks that the given context is valid, and increments its reference count.
 */
static ALCcontext *VerifyContext(ALCcontext *context)
{
    ALCdevice *dev;

    LockLists();
    dev = DeviceList;
    while(dev)
    {
        ALCcontext *tmp_ctx = dev->ContextList;
        while(tmp_ctx)
        {
            if(tmp_ctx == context)
            {
                ALCcontext_IncRef(tmp_ctx);
                UnlockLists();
                return tmp_ctx;
            }
            tmp_ctx = tmp_ctx->next;
        }
        dev = dev->next;
    }
    UnlockLists();

    return NULL;
}


/* GetContextRef
 *
 * Returns the currently active context, and adds a reference without locking
 * it.
 */
ALCcontext *GetContextRef(void)
{
    ALCcontext *context;

    context = pthread_getspecific(LocalContext);
    if(context)
        ALCcontext_IncRef(context);
    else
    {
        LockLists();
        context = GlobalContext;
        if(context)
            ALCcontext_IncRef(context);
        UnlockLists();
    }

    return context;
}

///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
// ALC Functions calls


// This should probably move to another c file but for now ...
ALC_API ALCdevice* ALC_APIENTRY alcCaptureOpenDevice(const ALCchar *deviceName, ALCuint frequency, ALCenum format, ALCsizei SampleSize)
{
    ALCdevice *device = NULL;
    ALCenum err;

    DO_INITCONFIG();

    if(!CaptureBackend.name)
    {
        alcSetError(NULL, ALC_INVALID_VALUE);
        return NULL;
    }

    if(SampleSize <= 0)
    {
        alcSetError(NULL, ALC_INVALID_VALUE);
        return NULL;
    }

    if(deviceName && (!deviceName[0] || strcasecmp(deviceName, "openal soft") == 0 || strcasecmp(deviceName, "openal-soft") == 0))
        deviceName = NULL;

    device = calloc(1, sizeof(ALCdevice));
    if(!device)
    {
        alcSetError(NULL, ALC_OUT_OF_MEMORY);
        return NULL;
    }

    //Validate device
    device->Funcs = &CaptureBackend.Funcs;
    device->ref = 1;
    device->Connected = ALC_TRUE;
    device->IsCaptureDevice = AL_TRUE;
    device->IsLoopbackDevice = AL_FALSE;
    InitializeCriticalSection(&device->Mutex);

    InitUIntMap(&device->BufferMap, ~0);
    InitUIntMap(&device->EffectMap, ~0);
    InitUIntMap(&device->FilterMap, ~0);

    device->szDeviceName = NULL;

    device->Flags |= DEVICE_FREQUENCY_REQUEST;
    device->Frequency = frequency;

    device->Flags |= DEVICE_CHANNELS_REQUEST;
    if(DecomposeDevFormat(format, &device->FmtChans, &device->FmtType) == AL_FALSE)
    {
        DeleteCriticalSection(&device->Mutex);
        free(device);
        alcSetError(NULL, ALC_INVALID_ENUM);
        return NULL;
    }

    device->UpdateSize = SampleSize;
    device->NumUpdates = 1;

    LockLists();
    if((err=ALCdevice_OpenCapture(device, deviceName)) != ALC_NO_ERROR)
    {
        UnlockLists();
        DeleteCriticalSection(&device->Mutex);
        free(device);
        alcSetError(NULL, err);
        return NULL;
    }
    UnlockLists();

    do {
        device->next = DeviceList;
    } while(!CompExchangePtr((XchgPtr*)&DeviceList, device->next, device));

    TRACE("Created device %p\n", device);
    return device;
}

ALC_API ALCboolean ALC_APIENTRY alcCaptureCloseDevice(ALCdevice *pDevice)
{
    ALCdevice *volatile*list;

    LockLists();
    list = &DeviceList;
    while(*list && *list != pDevice)
        list = &(*list)->next;

    if(!*list || !(*list)->IsCaptureDevice)
    {
        alcSetError(*list, ALC_INVALID_DEVICE);
        UnlockLists();
        return ALC_FALSE;
    }

    *list = (*list)->next;
    UnlockLists();

    LockDevice(pDevice);
    ALCdevice_CloseCapture(pDevice);
    UnlockDevice(pDevice);

    ALCdevice_DecRef(pDevice);

    return ALC_TRUE;
}

ALC_API void ALC_APIENTRY alcCaptureStart(ALCdevice *device)
{
    if(!(device=VerifyDevice(device)) || !device->IsCaptureDevice)
    {
        alcSetError(device, ALC_INVALID_DEVICE);
        if(device) ALCdevice_DecRef(device);
        return;
    }
    LockDevice(device);
    if(device->Connected)
        ALCdevice_StartCapture(device);
    UnlockDevice(device);

    ALCdevice_DecRef(device);
}

ALC_API void ALC_APIENTRY alcCaptureStop(ALCdevice *device)
{
    if(!(device=VerifyDevice(device)) || !device->IsCaptureDevice)
    {
        alcSetError(device, ALC_INVALID_DEVICE);
        if(device) ALCdevice_DecRef(device);
        return;
    }
    LockDevice(device);
    if(device->Connected)
        ALCdevice_StopCapture(device);
    UnlockDevice(device);

    ALCdevice_DecRef(device);
}

ALC_API void ALC_APIENTRY alcCaptureSamples(ALCdevice *device, ALCvoid *buffer, ALCsizei samples)
{
    ALCenum err = ALC_INVALID_DEVICE;
    if((device=VerifyDevice(device)) != NULL && device->IsCaptureDevice)
    {
        err = ALC_INVALID_VALUE;
        LockDevice(device);
        if(samples >= 0 && ALCdevice_AvailableSamples(device) >= (ALCuint)samples)
            err = ALCdevice_CaptureSamples(device, buffer, samples);
        UnlockDevice(device);
    }
    if(err != ALC_NO_ERROR)
        alcSetError(device, err);
    if(device) ALCdevice_DecRef(device);
}

/*
    alcGetError

    Return last ALC generated error code
*/
ALC_API ALCenum ALC_APIENTRY alcGetError(ALCdevice *device)
{
    ALCenum errorCode;

    if(VerifyDevice(device))
    {
        errorCode = ExchangeInt(&device->LastError, ALC_NO_ERROR);
        ALCdevice_DecRef(device);
    }
    else
        errorCode = ExchangeInt(&g_eLastNullDeviceError, ALC_NO_ERROR);

    return errorCode;
}


/* alcSuspendContext
 *
 * Not functional
 */
ALC_API ALCvoid ALC_APIENTRY alcSuspendContext(ALCcontext *Context)
{
    (void)Context;
}

/* alcProcessContext
 *
 * Not functional
 */
ALC_API ALCvoid ALC_APIENTRY alcProcessContext(ALCcontext *Context)
{
    (void)Context;
}


/* alcGetString
 *
 * Returns information about the Device, and error strings
 */
ALC_API const ALCchar* ALC_APIENTRY alcGetString(ALCdevice *pDevice,ALCenum param)
{
    const ALCchar *value = NULL;

    switch(param)
    {
    case ALC_NO_ERROR:
        value = alcNoError;
        break;

    case ALC_INVALID_ENUM:
        value = alcErrInvalidEnum;
        break;

    case ALC_INVALID_VALUE:
        value = alcErrInvalidValue;
        break;

    case ALC_INVALID_DEVICE:
        value = alcErrInvalidDevice;
        break;

    case ALC_INVALID_CONTEXT:
        value = alcErrInvalidContext;
        break;

    case ALC_OUT_OF_MEMORY:
        value = alcErrOutOfMemory;
        break;

    case ALC_DEVICE_SPECIFIER:
        if(VerifyDevice(pDevice))
        {
            value = pDevice->szDeviceName;
            ALCdevice_DecRef(pDevice);
        }
        else
        {
            ProbeDeviceList();
            value = alcDeviceList;
        }
        break;

    case ALC_ALL_DEVICES_SPECIFIER:
        ProbeAllDeviceList();
        value = alcAllDeviceList;
        break;

    case ALC_CAPTURE_DEVICE_SPECIFIER:
        if(VerifyDevice(pDevice))
        {
            value = pDevice->szDeviceName;
            ALCdevice_DecRef(pDevice);
        }
        else
        {
            ProbeCaptureDeviceList();
            value = alcCaptureDeviceList;
        }
        break;

    /* Default devices are always first in the list */
    case ALC_DEFAULT_DEVICE_SPECIFIER:
        if(!alcDeviceList)
            ProbeDeviceList();

        pDevice = VerifyDevice(pDevice);

        free(alcDefaultDeviceSpecifier);
        alcDefaultDeviceSpecifier = alc_strdup(alcDeviceList ? alcDeviceList : "");
        if(!alcDefaultDeviceSpecifier)
            alcSetError(pDevice, ALC_OUT_OF_MEMORY);

        value = alcDefaultDeviceSpecifier;
        if(pDevice) ALCdevice_DecRef(pDevice);
        break;

    case ALC_DEFAULT_ALL_DEVICES_SPECIFIER:
        if(!alcAllDeviceList)
            ProbeAllDeviceList();

        pDevice = VerifyDevice(pDevice);

        free(alcDefaultAllDeviceSpecifier);
        alcDefaultAllDeviceSpecifier = alc_strdup(alcAllDeviceList ?
                                              alcAllDeviceList : "");
        if(!alcDefaultAllDeviceSpecifier)
            alcSetError(pDevice, ALC_OUT_OF_MEMORY);

        value = alcDefaultAllDeviceSpecifier;
        if(pDevice) ALCdevice_DecRef(pDevice);
        break;

    case ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER:
        if(!alcCaptureDeviceList)
            ProbeCaptureDeviceList();

        pDevice = VerifyDevice(pDevice);

        free(alcCaptureDefaultDeviceSpecifier);
        alcCaptureDefaultDeviceSpecifier = alc_strdup(alcCaptureDeviceList ?
                                                  alcCaptureDeviceList : "");
        if(!alcCaptureDefaultDeviceSpecifier)
            alcSetError(pDevice, ALC_OUT_OF_MEMORY);

        value = alcCaptureDefaultDeviceSpecifier;
        if(pDevice) ALCdevice_DecRef(pDevice);
        break;

    case ALC_EXTENSIONS:
        if(!VerifyDevice(pDevice))
            value = alcNoDeviceExtList;
        else
        {
            value = alcExtensionList;
            ALCdevice_DecRef(pDevice);
        }
        break;

    default:
        pDevice = VerifyDevice(pDevice);
        alcSetError(pDevice, ALC_INVALID_ENUM);
        if(pDevice) ALCdevice_DecRef(pDevice);
        break;
    }

    return value;
}


/* alcGetIntegerv
 *
 * Returns information about the Device and the version of Open AL
 */
ALC_API ALCvoid ALC_APIENTRY alcGetIntegerv(ALCdevice *device,ALCenum param,ALsizei size,ALCint *data)
{
    device = VerifyDevice(device);

    if(size == 0 || data == NULL)
    {
        alcSetError(device, ALC_INVALID_VALUE);
        if(device) ALCdevice_DecRef(device);
        return;
    }

    if(!device)
    {
        switch(param)
        {
            case ALC_MAJOR_VERSION:
                *data = alcMajorVersion;
                break;
            case ALC_MINOR_VERSION:
                *data = alcMinorVersion;
                break;

            case ALC_ATTRIBUTES_SIZE:
            case ALC_ALL_ATTRIBUTES:
            case ALC_FREQUENCY:
            case ALC_REFRESH:
            case ALC_SYNC:
            case ALC_MONO_SOURCES:
            case ALC_STEREO_SOURCES:
            case ALC_CAPTURE_SAMPLES:
            case ALC_FORMAT_CHANNELS_SOFT:
            case ALC_FORMAT_TYPE_SOFT:
                alcSetError(NULL, ALC_INVALID_DEVICE);
                break;

            default:
                alcSetError(NULL, ALC_INVALID_ENUM);
                break;
        }
    }
    else if(device->IsCaptureDevice)
    {
        switch(param)
        {
            case ALC_CAPTURE_SAMPLES:
                LockDevice(device);
                *data = ALCdevice_AvailableSamples(device);
                UnlockDevice(device);
                break;

            case ALC_CONNECTED:
                *data = device->Connected;
                break;

            default:
                alcSetError(device, ALC_INVALID_ENUM);
                break;
        }
    }
    else /* render device */
    {
        switch(param)
        {
            case ALC_MAJOR_VERSION:
                *data = alcMajorVersion;
                break;

            case ALC_MINOR_VERSION:
                *data = alcMinorVersion;
                break;

            case ALC_EFX_MAJOR_VERSION:
                *data = alcEFXMajorVersion;
                break;

            case ALC_EFX_MINOR_VERSION:
                *data = alcEFXMinorVersion;
                break;

            case ALC_ATTRIBUTES_SIZE:
                *data = 13;
                break;

            case ALC_ALL_ATTRIBUTES:
                if(size < 13)
                    alcSetError(device, ALC_INVALID_VALUE);
                else
                {
                    int i = 0;

                    data[i++] = ALC_FREQUENCY;
                    data[i++] = device->Frequency;

                    if(!device->IsLoopbackDevice)
                    {
                        data[i++] = ALC_REFRESH;
                        data[i++] = device->Frequency / device->UpdateSize;

                        data[i++] = ALC_SYNC;
                        data[i++] = ALC_FALSE;
                    }
                    else
                    {
                        data[i++] = ALC_FORMAT_CHANNELS_SOFT;
                        data[i++] = device->FmtChans;

                        data[i++] = ALC_FORMAT_TYPE_SOFT;
                        data[i++] = device->FmtType;
                    }

                    data[i++] = ALC_MONO_SOURCES;
                    data[i++] = device->NumMonoSources;

                    data[i++] = ALC_STEREO_SOURCES;
                    data[i++] = device->NumStereoSources;

                    data[i++] = ALC_MAX_AUXILIARY_SENDS;
                    data[i++] = device->NumAuxSends;

                    data[i++] = 0;
                }
                break;

            case ALC_FREQUENCY:
                *data = device->Frequency;
                break;

            case ALC_REFRESH:
                if(device->IsLoopbackDevice)
                    alcSetError(device, ALC_INVALID_DEVICE);
                else
                    *data = device->Frequency / device->UpdateSize;
                break;

            case ALC_SYNC:
                if(device->IsLoopbackDevice)
                    alcSetError(device, ALC_INVALID_DEVICE);
                else
                    *data = ALC_FALSE;
                break;

            case ALC_FORMAT_CHANNELS_SOFT:
                if(!device->IsLoopbackDevice)
                    alcSetError(device, ALC_INVALID_DEVICE);
                else
                    *data = device->FmtChans;
                break;

            case ALC_FORMAT_TYPE_SOFT:
                if(!device->IsLoopbackDevice)
                    alcSetError(device, ALC_INVALID_DEVICE);
                else
                    *data = device->FmtType;
                break;

            case ALC_MONO_SOURCES:
                *data = device->NumMonoSources;
                break;

            case ALC_STEREO_SOURCES:
                *data = device->NumStereoSources;
                break;

            case ALC_MAX_AUXILIARY_SENDS:
                *data = device->NumAuxSends;
                break;

            case ALC_CONNECTED:
                *data = device->Connected;
                break;

            default:
                alcSetError(device, ALC_INVALID_ENUM);
                break;
        }
    }
    if(device)
        ALCdevice_DecRef(device);
}


/* alcIsExtensionPresent
 *
 * Determines if there is support for a particular extension
 */
ALC_API ALCboolean ALC_APIENTRY alcIsExtensionPresent(ALCdevice *device, const ALCchar *extName)
{
    ALCboolean bResult = ALC_FALSE;

    device = VerifyDevice(device);

    if(!extName)
        alcSetError(device, ALC_INVALID_VALUE);
    else
    {
        size_t len = strlen(extName);
        const char *ptr = (device ? alcExtensionList : alcNoDeviceExtList);
        while(ptr && *ptr)
        {
            if(strncasecmp(ptr, extName, len) == 0 &&
               (ptr[len] == '\0' || isspace(ptr[len])))
            {
                bResult = ALC_TRUE;
                break;
            }
            if((ptr=strchr(ptr, ' ')) != NULL)
            {
                do {
                    ++ptr;
                } while(isspace(*ptr));
            }
        }
    }
    if(device)
        ALCdevice_DecRef(device);
    return bResult;
}


/* alcGetProcAddress
 *
 * Retrieves the function address for a particular extension function
 */
ALC_API ALCvoid* ALC_APIENTRY alcGetProcAddress(ALCdevice *device, const ALCchar *funcName)
{
    ALCvoid *ptr = NULL;

    device = VerifyDevice(device);

    if(!funcName)
        alcSetError(device, ALC_INVALID_VALUE);
    else
    {
        ALsizei i = 0;
        while(alcFunctions[i].funcName && strcmp(alcFunctions[i].funcName,funcName) != 0)
            i++;
        ptr = alcFunctions[i].address;
    }
    if(device)
        ALCdevice_DecRef(device);
    return ptr;
}


/* alcGetEnumValue
 *
 * Get the value for a particular ALC Enumerated Value
 */
ALC_API ALCenum ALC_APIENTRY alcGetEnumValue(ALCdevice *device, const ALCchar *enumName)
{
    ALCenum val = 0;

    device = VerifyDevice(device);

    if(!enumName)
        alcSetError(device, ALC_INVALID_VALUE);
    else
    {
        ALsizei i = 0;
        while(enumeration[i].enumName && strcmp(enumeration[i].enumName,enumName) != 0)
            i++;
        val = enumeration[i].value;
    }
    if(device)
        ALCdevice_DecRef(device);
    return val;
}


/* alcCreateContext
 *
 * Create and attach a Context to a particular Device.
 */
ALC_API ALCcontext* ALC_APIENTRY alcCreateContext(ALCdevice *device, const ALCint *attrList)
{
    ALCcontext *ALContext;
    ALCenum err;

    LockLists();
    if(!(device=VerifyDevice(device)) || device->IsCaptureDevice || !device->Connected)
    {
        UnlockLists();
        alcSetError(device, ALC_INVALID_DEVICE);
        if(device) ALCdevice_DecRef(device);
        return NULL;
    }

    /* Reset Context Last Error code */
    device->LastError = ALC_NO_ERROR;

    if((err=UpdateDeviceParams(device, attrList)) != ALC_NO_ERROR)
    {
        UnlockLists();
        alcSetError(device, err);
        if(err == ALC_INVALID_DEVICE)
            aluHandleDisconnect(device);
        ALCdevice_DecRef(device);
        return NULL;
    }

    ALContext = calloc(1, sizeof(ALCcontext));
    if(ALContext)
    {
        ALContext->ref = 1;

        ALContext->MaxActiveSources = 256;
        ALContext->ActiveSources = malloc(sizeof(ALContext->ActiveSources[0]) *
                                          ALContext->MaxActiveSources);
    }
    if(!ALContext || !ALContext->ActiveSources)
    {
        if(!device->ContextList)
        {
            ALCdevice_StopPlayback(device);
            device->Flags &= ~DEVICE_RUNNING;
        }
        UnlockLists();

        free(ALContext);
        ALContext = NULL;

        alcSetError(device, ALC_OUT_OF_MEMORY);
        ALCdevice_DecRef(device);
        return NULL;
    }

    ALContext->Device = device;
    ALCdevice_IncRef(device);
    InitContext(ALContext);

    do {
        ALContext->next = device->ContextList;
    } while(!CompExchangePtr((XchgPtr*)&device->ContextList, ALContext->next, ALContext));
    UnlockLists();

    if(device->DefaultSlot)
        InitializeEffect(ALContext, device->DefaultSlot, &ForcedEffect);
    ALContext->LastError = AL_NO_ERROR;

    ALCdevice_DecRef(device);

    TRACE("Created context %p\n", ALContext);
    return ALContext;
}

/* alcDestroyContext
 *
 * Remove a Context
 */
ALC_API ALCvoid ALC_APIENTRY alcDestroyContext(ALCcontext *context)
{
    ALCdevice *Device;

    LockLists();
    /* alcGetContextsDevice sets an error for invalid contexts */
    Device = alcGetContextsDevice(context);
    if(Device)
    {
        ReleaseContext(context, Device);
        if(!Device->ContextList)
        {
            ALCdevice_StopPlayback(Device);
            Device->Flags &= ~DEVICE_RUNNING;
        }
    }
    UnlockLists();
}


/* alcGetCurrentContext
 *
 * Returns the currently active Context
 */
ALC_API ALCcontext* ALC_APIENTRY alcGetCurrentContext(ALCvoid)
{
    ALCcontext *Context;

    Context = pthread_getspecific(LocalContext);
    if(!Context) Context = GlobalContext;

    return Context;
}

/* alcGetThreadContext
 *
 * Returns the currently active thread-local Context
 */
ALC_API ALCcontext* ALC_APIENTRY alcGetThreadContext(void)
{
    ALCcontext *Context;
    Context = pthread_getspecific(LocalContext);
    return Context;
}


/* alcMakeContextCurrent
 *
 * Makes the given Context the active Context
 */
ALC_API ALCboolean ALC_APIENTRY alcMakeContextCurrent(ALCcontext *context)
{
    /* context must be a valid Context or NULL */
    if(context && !(context=VerifyContext(context)))
    {
        alcSetError(NULL, ALC_INVALID_CONTEXT);
        return ALC_FALSE;
    }
    /* context's reference count is already incremented */
    context = ExchangePtr((XchgPtr*)&GlobalContext, context);
    if(context) ALCcontext_DecRef(context);

    if((context=pthread_getspecific(LocalContext)) != NULL)
    {
        pthread_setspecific(LocalContext, NULL);
        ALCcontext_DecRef(context);
    }

    return ALC_TRUE;
}

/* alcSetThreadContext
 *
 * Makes the given Context the active Context for the current thread
 */
ALC_API ALCboolean ALC_APIENTRY alcSetThreadContext(ALCcontext *context)
{
    ALCcontext *old;

    /* context must be a valid Context or NULL */
    if(context && !(context=VerifyContext(context)))
    {
        alcSetError(NULL, ALC_INVALID_CONTEXT);
        return ALC_FALSE;
    }
    /* context's reference count is already incremented */
    old = pthread_getspecific(LocalContext);
    pthread_setspecific(LocalContext, context);
    if(old) ALCcontext_DecRef(old);

    return ALC_TRUE;
}


/* alcGetContextsDevice
 *
 * Returns the Device that a particular Context is attached to
 */
ALC_API ALCdevice* ALC_APIENTRY alcGetContextsDevice(ALCcontext *Context)
{
    ALCdevice *Device;

    if(!(Context=VerifyContext(Context)))
    {
        alcSetError(NULL, ALC_INVALID_CONTEXT);
        return NULL;
    }
    Device = Context->Device;
    ALCcontext_DecRef(Context);

    return Device;
}


static void GetFormatFromString(const char *str, enum DevFmtChannels *chans, enum DevFmtType *type)
{
    static const struct {
        const char name[32];
        enum DevFmtChannels channels;
        enum DevFmtType type;
    } formats[] = {
        { "AL_FORMAT_MONO32",   DevFmtMono,   DevFmtFloat },
        { "AL_FORMAT_STEREO32", DevFmtStereo, DevFmtFloat },
        { "AL_FORMAT_QUAD32",   DevFmtQuad,   DevFmtFloat },
        { "AL_FORMAT_51CHN32",  DevFmtX51,    DevFmtFloat },
        { "AL_FORMAT_61CHN32",  DevFmtX61,    DevFmtFloat },
        { "AL_FORMAT_71CHN32",  DevFmtX71,    DevFmtFloat },

        { "AL_FORMAT_MONO16",   DevFmtMono,   DevFmtShort },
        { "AL_FORMAT_STEREO16", DevFmtStereo, DevFmtShort },
        { "AL_FORMAT_QUAD16",   DevFmtQuad,   DevFmtShort },
        { "AL_FORMAT_51CHN16",  DevFmtX51,    DevFmtShort },
        { "AL_FORMAT_61CHN16",  DevFmtX61,    DevFmtShort },
        { "AL_FORMAT_71CHN16",  DevFmtX71,    DevFmtShort },

        { "AL_FORMAT_MONO8",   DevFmtMono,   DevFmtByte },
        { "AL_FORMAT_STEREO8", DevFmtStereo, DevFmtByte },
        { "AL_FORMAT_QUAD8",   DevFmtQuad,   DevFmtByte },
        { "AL_FORMAT_51CHN8",  DevFmtX51,    DevFmtByte },
        { "AL_FORMAT_61CHN8",  DevFmtX61,    DevFmtByte },
        { "AL_FORMAT_71CHN8",  DevFmtX71,    DevFmtByte }
    };
    size_t i;

    for(i = 0;i < sizeof(formats)/sizeof(formats[0]);i++)
    {
        if(strcasecmp(str, formats[i].name) == 0)
        {
            *chans = formats[i].channels;
            *type = formats[i].type;
            return;
        }
    }

    ERR("Unknown format: \"%s\"\n", str);
    *chans = DevFmtStereo;
    *type = DevFmtShort;
}

/* alcOpenDevice
 *
 * Open the Device specified.
 */
ALC_API ALCdevice* ALC_APIENTRY alcOpenDevice(const ALCchar *deviceName)
{
    const ALCchar *fmt;
    ALCdevice *device;
    ALCenum err;

    DO_INITCONFIG();

    if(!PlaybackBackend.name)
    {
        alcSetError(NULL, ALC_INVALID_VALUE);
        return NULL;
    }

    if(deviceName && (!deviceName[0] || strcasecmp(deviceName, "openal soft") == 0 || strcasecmp(deviceName, "openal-soft") == 0))
        deviceName = NULL;

    device = calloc(1, sizeof(ALCdevice)+sizeof(ALeffectslot));
    if(!device)
    {
        alcSetError(NULL, ALC_OUT_OF_MEMORY);
        return NULL;
    }

    //Validate device
    device->Funcs = &PlaybackBackend.Funcs;
    device->ref = 1;
    device->Connected = ALC_TRUE;
    device->IsCaptureDevice = AL_FALSE;
    device->IsLoopbackDevice = AL_FALSE;
    InitializeCriticalSection(&device->Mutex);
    device->LastError = ALC_NO_ERROR;

    device->Flags = 0;
    device->Bs2b = NULL;
    device->Bs2bLevel = 0;
    device->szDeviceName = NULL;

    device->ContextList = NULL;

    device->MaxNoOfSources = 256;
    device->AuxiliaryEffectSlotMax = 4;
    device->NumAuxSends = MAX_SENDS;

    InitUIntMap(&device->BufferMap, ~0);
    InitUIntMap(&device->EffectMap, ~0);
    InitUIntMap(&device->FilterMap, ~0);

    //Set output format
    device->NumUpdates = 4;
    device->UpdateSize = 1024;

    device->Frequency = DEFAULT_OUTPUT_RATE;
    if(ConfigValueUInt(NULL, "frequency", &device->Frequency))
        device->Flags |= DEVICE_FREQUENCY_REQUEST;
    device->Frequency = maxu(device->Frequency, 8000);

    fmt = "AL_FORMAT_STEREO32";
    if(ConfigValueStr(NULL, "format", &fmt))
        device->Flags |= DEVICE_CHANNELS_REQUEST;
    GetFormatFromString(fmt, &device->FmtChans, &device->FmtType);

    ConfigValueUInt(NULL, "periods", &device->NumUpdates);
    if(device->NumUpdates < 2) device->NumUpdates = 4;

    ConfigValueUInt(NULL, "period_size", &device->UpdateSize);
    if(device->UpdateSize == 0) device->UpdateSize = 1024;

    ConfigValueUInt(NULL, "sources", &device->MaxNoOfSources);
    if(device->MaxNoOfSources == 0) device->MaxNoOfSources = 256;

    ConfigValueUInt(NULL, "slots", &device->AuxiliaryEffectSlotMax);
    if(device->AuxiliaryEffectSlotMax == 0) device->AuxiliaryEffectSlotMax = 4;

    ConfigValueUInt(NULL, "sends", &device->NumAuxSends);
    if(device->NumAuxSends > MAX_SENDS) device->NumAuxSends = MAX_SENDS;

    ConfigValueInt(NULL, "cf_level", &device->Bs2bLevel);

    device->NumStereoSources = 1;
    device->NumMonoSources = device->MaxNoOfSources - device->NumStereoSources;

    device->DefaultSlot = (ALeffectslot*)(device+1);
    if(InitEffectSlot(device->DefaultSlot) != AL_NO_ERROR)
        device->DefaultSlot = NULL;

    // Find a playback device to open
    LockLists();
    if((err=ALCdevice_OpenPlayback(device, deviceName)) != ALC_NO_ERROR)
    {
        UnlockLists();
        DeleteCriticalSection(&device->Mutex);
        free(device);
        alcSetError(NULL, err);
        return NULL;
    }
    UnlockLists();

    do {
        device->next = DeviceList;
    } while(!CompExchangePtr((XchgPtr*)&DeviceList, device->next, device));

    TRACE("Created device %p\n", device);
    return device;
}

/*
* Asynchronously open device
*/
typedef void(*alc_open_device_callback_t)(ALCdevice *, ALCvoid*);

typedef struct {
	ALCchar * deviceName;
	alc_open_device_callback_t alc_open_device_callback;
	ALCvoid* user_args;
	CRITICAL_SECTION lock;
	ALCvoid* threadHandle;
} alcOpenDeviceAsyncArgs_t;

static void Cleanup_alcOpenDeviceAsyncArgs(alcOpenDeviceAsyncArgs_t * asyncArg)
{
	DeleteCriticalSection(&asyncArg->lock);
	free(asyncArg->deviceName);
	free(asyncArg);
}

/* The async function */
static ALuint  alcOpenDeviceAsyncFunc(void *arg)
{
	alcOpenDeviceAsyncArgs_t* asyncArg = (alcOpenDeviceAsyncArgs_t*)arg;
	ALCdevice* device = alcOpenDevice(asyncArg->deviceName);
	if (device != NULL)
	{
		EnterCriticalSection(&asyncArg->lock);
		device->asyncOpenThread = asyncArg->threadHandle;//store this thread's handle so that it can be deleted when closing the device
		LeaveCriticalSection(&asyncArg->lock);
	}

	//finished, now invoke callback
	asyncArg->alc_open_device_callback(device, asyncArg->user_args);

	//cleanup
	Cleanup_alcOpenDeviceAsyncArgs(asyncArg);

	return 1;
}

ALC_API ALCboolean ALC_APIENTRY alcOpenDeviceAsync(
	const ALCchar *devicename, 
	void(*_open_device_callback_)(ALCdevice *, ALCvoid* user_args), 
	ALCvoid* user_args)
{
	ALenum err = ALC_NO_ERROR;
	alcOpenDeviceAsyncArgs_t *args = calloc(1, sizeof(alcOpenDeviceAsyncArgs_t));
	if (args != NULL && devicename != NULL)
	{
		//copy device name
		args->deviceName = alc_strdup(devicename);
		if (args->deviceName == NULL)//failed
		{
			free(args);
			args = NULL;
		}
	}//if (args != NULL && devicename != NULL)

	if (args != NULL){
		InitializeCriticalSection(&args->lock);
		args->alc_open_device_callback = _open_device_callback_;
		args->user_args = user_args;
		
		//create background thread
		EnterCriticalSection(&args->lock);//lock the "args" object so that the thread only starts processing after args->threadHandle is written
		args->threadHandle = StartThread(alcOpenDeviceAsyncFunc, args);
		LeaveCriticalSection(&args->lock);

		if (args->threadHandle == NULL)
		{
			Cleanup_alcOpenDeviceAsyncArgs(args);
			err = ALC_OUT_OF_MEMORY;
		}
	}// if (args != NULL)
	else
		err = ALC_OUT_OF_MEMORY;

	if (err != ALC_NO_ERROR)
	{
		alcSetError(NULL, err);
		return ALC_FALSE;
	}

	return ALC_TRUE;
}

/* alcCloseDevice
 *
 * Close the specified Device
 */
ALC_API ALCboolean ALC_APIENTRY alcCloseDevice(ALCdevice *pDevice)
{
    ALCdevice *volatile*list;
    ALCcontext *ctx;

    LockLists();
    list = &DeviceList;
    while(*list && *list != pDevice)
        list = &(*list)->next;

    if(!*list || (*list)->IsCaptureDevice)
    {
        alcSetError(*list, ALC_INVALID_DEVICE);
        UnlockLists();
        return ALC_FALSE;
    }

    *list = (*list)->next;
    UnlockLists();

    if((ctx=pDevice->ContextList) != NULL)
    {
        do {
            WARN("Releasing context %p\n", ctx);
            ReleaseContext(ctx, pDevice);
        } while((ctx=pDevice->ContextList) != NULL);
        ALCdevice_StopPlayback(pDevice);
        pDevice->Flags &= ~DEVICE_RUNNING;
    }
    ALCdevice_ClosePlayback(pDevice);

	//close async thread handle if there is one
    if (pDevice->asyncOpenThread != NULL)
        StopThread(pDevice->asyncOpenThread);

    ALCdevice_DecRef(pDevice);

    return ALC_TRUE;
}


/* alcLoopbackOpenDeviceSOFT
 *
 * Open a loopback device, for manual rendering.
 */
ALC_API ALCdevice* ALC_APIENTRY alcLoopbackOpenDeviceSOFT(void)
{
    ALCdevice *device;

    DO_INITCONFIG();

    device = calloc(1, sizeof(ALCdevice));
    if(!device)
    {
        alcSetError(NULL, ALC_OUT_OF_MEMORY);
        return NULL;
    }

    //Validate device
    device->Funcs = &BackendLoopback.Funcs;
    device->ref = 1;
    device->Connected = ALC_TRUE;
    device->IsCaptureDevice = AL_FALSE;
    device->IsLoopbackDevice = AL_TRUE;
    InitializeCriticalSection(&device->Mutex);
    device->LastError = ALC_NO_ERROR;

    device->Flags = 0;
    device->Bs2b = NULL;
    device->Bs2bLevel = 0;
    device->szDeviceName = NULL;

    device->ContextList = NULL;

    device->MaxNoOfSources = 256;
    device->AuxiliaryEffectSlotMax = 4;
    device->NumAuxSends = MAX_SENDS;

    InitUIntMap(&device->BufferMap, ~0);
    InitUIntMap(&device->EffectMap, ~0);
    InitUIntMap(&device->FilterMap, ~0);

    //Set output format
    device->NumUpdates = 0;
    device->UpdateSize = 0;

    device->Frequency = 44100;
    device->FmtChans = DevFmtStereo;
    device->FmtType = DevFmtShort;

    ConfigValueUInt(NULL, "sources", &device->MaxNoOfSources);
    if(device->MaxNoOfSources == 0) device->MaxNoOfSources = 256;

    ConfigValueUInt(NULL, "slots", &device->AuxiliaryEffectSlotMax);
    if(device->AuxiliaryEffectSlotMax == 0) device->AuxiliaryEffectSlotMax = 4;

    ConfigValueUInt(NULL, "sends", &device->NumAuxSends);
    if(device->NumAuxSends > MAX_SENDS) device->NumAuxSends = MAX_SENDS;

    ConfigValueInt(NULL, "cf_level", &device->Bs2bLevel);

    device->NumStereoSources = 1;
    device->NumMonoSources = device->MaxNoOfSources - device->NumStereoSources;

    // Open the "backend"
    ALCdevice_OpenPlayback(device, "Loopback");
    do {
        device->next = DeviceList;
    } while(!CompExchangePtr((XchgPtr*)&DeviceList, device->next, device));

    TRACE("Created device %p\n", device);
    return device;
}

/* alcIsRenderFormatSupportedSOFT
 *
 * Determines if the loopback device supports the given format for rendering.
 */
ALC_API ALCboolean ALC_APIENTRY alcIsRenderFormatSupportedSOFT(ALCdevice *device, ALCsizei freq, ALCenum channels, ALCenum type)
{
    ALCboolean ret = ALC_FALSE;

    if(!(device=VerifyDevice(device)) || !device->IsLoopbackDevice)
        alcSetError(device, ALC_INVALID_DEVICE);
    else if(freq <= 0)
        alcSetError(device, ALC_INVALID_VALUE);
    else if(!IsValidALCType(type) || !IsValidALCChannels(channels))
        alcSetError(device, ALC_INVALID_ENUM);
    else
    {
        if(BytesFromDevFmt(type) > 0 && ChannelsFromDevFmt(channels) > 0 &&
           freq >= 8000)
            ret = ALC_TRUE;
    }
    if(device) ALCdevice_DecRef(device);

    return ret;
}

/* alcRenderSamplesSOFT
 *
 * Renders some samples into a buffer, using the format last set by the
 * attributes given to alcCreateContext.
 */
ALC_API void ALC_APIENTRY alcRenderSamplesSOFT(ALCdevice *device, ALCvoid *buffer, ALCsizei samples)
{
    if(!(device=VerifyDevice(device)) || !device->IsLoopbackDevice)
        alcSetError(device, ALC_INVALID_DEVICE);
    else if(samples < 0 || (samples > 0 && buffer == NULL))
        alcSetError(device, ALC_INVALID_VALUE);
    else
        aluMixData(device, buffer, samples);
    if(device) ALCdevice_DecRef(device);
}


static void ReleaseALC(void)
{
    ALCdevice *dev;

    free(alcDeviceList); alcDeviceList = NULL;
    alcDeviceListSize = 0;
    free(alcAllDeviceList); alcAllDeviceList = NULL;
    alcAllDeviceListSize = 0;
    free(alcCaptureDeviceList); alcCaptureDeviceList = NULL;
    alcCaptureDeviceListSize = 0;

    free(alcDefaultDeviceSpecifier);
    alcDefaultDeviceSpecifier = NULL;
    free(alcDefaultAllDeviceSpecifier);
    alcDefaultAllDeviceSpecifier = NULL;
    free(alcCaptureDefaultDeviceSpecifier);
    alcCaptureDefaultDeviceSpecifier = NULL;

    if((dev=ExchangePtr((XchgPtr*)&DeviceList, NULL)) != NULL)
    {
        ALCuint num = 0;
        do {
            num++;
        } while((dev=dev->next) != NULL);
        ERR("%u device%s not closed\n", num, (num>1)?"s":"");
    }
}

///////////////////////////////////////////////////////
