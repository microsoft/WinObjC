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
#include <string.h>
#include <ctype.h>

#include "alError.h"
#include "alMain.h"
#include "alFilter.h"
#include "alEffect.h"
#include "alAuxEffectSlot.h"
#include "alSource.h"
#include "alBuffer.h"
#include "AL/al.h"
#include "AL/alc.h"

typedef struct ALenums {
    const ALchar *enumName;
    ALenum value;
} ALenums;


static const ALenums enumeration[] = {
    // Types
    { "AL_INVALID",                           AL_INVALID                          },
    { "AL_NONE",                              AL_NONE                             },
    { "AL_FALSE",                             AL_FALSE                            },
    { "AL_TRUE",                              AL_TRUE                             },

    // Source and Listener Properties
    { "AL_SOURCE_RELATIVE",                   AL_SOURCE_RELATIVE                  },
    { "AL_CONE_INNER_ANGLE",                  AL_CONE_INNER_ANGLE                 },
    { "AL_CONE_OUTER_ANGLE",                  AL_CONE_OUTER_ANGLE                 },
    { "AL_PITCH",                             AL_PITCH                            },
    { "AL_POSITION",                          AL_POSITION                         },
    { "AL_DIRECTION",                         AL_DIRECTION                        },
    { "AL_VELOCITY",                          AL_VELOCITY                         },
    { "AL_LOOPING",                           AL_LOOPING                          },
    { "AL_BUFFER",                            AL_BUFFER                           },
    { "AL_GAIN",                              AL_GAIN                             },
    { "AL_MIN_GAIN",                          AL_MIN_GAIN                         },
    { "AL_MAX_GAIN",                          AL_MAX_GAIN                         },
    { "AL_ORIENTATION",                       AL_ORIENTATION                      },
    { "AL_REFERENCE_DISTANCE",                AL_REFERENCE_DISTANCE               },
    { "AL_ROLLOFF_FACTOR",                    AL_ROLLOFF_FACTOR                   },
    { "AL_CONE_OUTER_GAIN",                   AL_CONE_OUTER_GAIN                  },
    { "AL_MAX_DISTANCE",                      AL_MAX_DISTANCE                     },
    { "AL_SEC_OFFSET",                        AL_SEC_OFFSET                       },
    { "AL_SAMPLE_OFFSET",                     AL_SAMPLE_OFFSET                    },
    { "AL_SAMPLE_RW_OFFSETS_SOFT",            AL_SAMPLE_RW_OFFSETS_SOFT           },
    { "AL_BYTE_OFFSET",                       AL_BYTE_OFFSET                      },
    { "AL_BYTE_RW_OFFSETS_SOFT",              AL_BYTE_RW_OFFSETS_SOFT             },
    { "AL_SOURCE_TYPE",                       AL_SOURCE_TYPE                      },
    { "AL_STATIC",                            AL_STATIC                           },
    { "AL_STREAMING",                         AL_STREAMING                        },
    { "AL_UNDETERMINED",                      AL_UNDETERMINED                     },
    { "AL_METERS_PER_UNIT",                   AL_METERS_PER_UNIT                  },
    { "AL_VIRTUAL_CHANNELS_SOFT",             AL_VIRTUAL_CHANNELS_SOFT            },

    // Source EFX Properties
    { "AL_DIRECT_FILTER",                     AL_DIRECT_FILTER                    },
    { "AL_AUXILIARY_SEND_FILTER",             AL_AUXILIARY_SEND_FILTER            },
    { "AL_AIR_ABSORPTION_FACTOR",             AL_AIR_ABSORPTION_FACTOR            },
    { "AL_ROOM_ROLLOFF_FACTOR",               AL_ROOM_ROLLOFF_FACTOR              },
    { "AL_CONE_OUTER_GAINHF",                 AL_CONE_OUTER_GAINHF                },
    { "AL_DIRECT_FILTER_GAINHF_AUTO",         AL_DIRECT_FILTER_GAINHF_AUTO        },
    { "AL_AUXILIARY_SEND_FILTER_GAIN_AUTO",   AL_AUXILIARY_SEND_FILTER_GAIN_AUTO  },
    { "AL_AUXILIARY_SEND_FILTER_GAINHF_AUTO", AL_AUXILIARY_SEND_FILTER_GAINHF_AUTO},

    // Source State information
    { "AL_SOURCE_STATE",                      AL_SOURCE_STATE                     },
    { "AL_INITIAL",                           AL_INITIAL                          },
    { "AL_PLAYING",                           AL_PLAYING                          },
    { "AL_PAUSED",                            AL_PAUSED                           },
    { "AL_STOPPED",                           AL_STOPPED                          },

    // Queue information
    { "AL_BUFFERS_QUEUED",                    AL_BUFFERS_QUEUED                   },
    { "AL_BUFFERS_PROCESSED",                 AL_BUFFERS_PROCESSED                },

    // Buffer Formats
    { "AL_FORMAT_MONO8",                      AL_FORMAT_MONO8                     },
    { "AL_FORMAT_MONO16",                     AL_FORMAT_MONO16                    },
    { "AL_FORMAT_MONO_FLOAT32",               AL_FORMAT_MONO_FLOAT32              },
    { "AL_FORMAT_MONO_DOUBLE_EXT",            AL_FORMAT_MONO_DOUBLE_EXT           },
    { "AL_FORMAT_STEREO8",                    AL_FORMAT_STEREO8                   },
    { "AL_FORMAT_STEREO16",                   AL_FORMAT_STEREO16                  },
    { "AL_FORMAT_STEREO_FLOAT32",             AL_FORMAT_STEREO_FLOAT32            },
    { "AL_FORMAT_STEREO_DOUBLE_EXT",          AL_FORMAT_STEREO_DOUBLE_EXT         },
    { "AL_FORMAT_MONO_IMA4",                  AL_FORMAT_MONO_IMA4                 },
    { "AL_FORMAT_STEREO_IMA4",                AL_FORMAT_STEREO_IMA4               },
    { "AL_FORMAT_QUAD8_LOKI",                 AL_FORMAT_QUAD8_LOKI                },
    { "AL_FORMAT_QUAD16_LOKI",                AL_FORMAT_QUAD16_LOKI               },
    { "AL_FORMAT_QUAD8",                      AL_FORMAT_QUAD8                     },
    { "AL_FORMAT_QUAD16",                     AL_FORMAT_QUAD16                    },
    { "AL_FORMAT_QUAD32",                     AL_FORMAT_QUAD32                    },
    { "AL_FORMAT_51CHN8",                     AL_FORMAT_51CHN8                    },
    { "AL_FORMAT_51CHN16",                    AL_FORMAT_51CHN16                   },
    { "AL_FORMAT_51CHN32",                    AL_FORMAT_51CHN32                   },
    { "AL_FORMAT_61CHN8",                     AL_FORMAT_61CHN8                    },
    { "AL_FORMAT_61CHN16",                    AL_FORMAT_61CHN16                   },
    { "AL_FORMAT_61CHN32",                    AL_FORMAT_61CHN32                   },
    { "AL_FORMAT_71CHN8",                     AL_FORMAT_71CHN8                    },
    { "AL_FORMAT_71CHN16",                    AL_FORMAT_71CHN16                   },
    { "AL_FORMAT_71CHN32",                    AL_FORMAT_71CHN32                   },
    { "AL_FORMAT_REAR8",                      AL_FORMAT_REAR8                     },
    { "AL_FORMAT_REAR16",                     AL_FORMAT_REAR16                    },
    { "AL_FORMAT_REAR32",                     AL_FORMAT_REAR32                    },
    { "AL_FORMAT_MONO_MULAW",                 AL_FORMAT_MONO_MULAW                },
    { "AL_FORMAT_MONO_MULAW_EXT",             AL_FORMAT_MONO_MULAW_EXT            },
    { "AL_FORMAT_STEREO_MULAW",               AL_FORMAT_STEREO_MULAW              },
    { "AL_FORMAT_STEREO_MULAW_EXT",           AL_FORMAT_STEREO_MULAW_EXT          },
    { "AL_FORMAT_QUAD_MULAW",                 AL_FORMAT_QUAD_MULAW                },
    { "AL_FORMAT_51CHN_MULAW",                AL_FORMAT_51CHN_MULAW               },
    { "AL_FORMAT_61CHN_MULAW",                AL_FORMAT_61CHN_MULAW               },
    { "AL_FORMAT_71CHN_MULAW",                AL_FORMAT_71CHN_MULAW               },
    { "AL_FORMAT_REAR_MULAW",                 AL_FORMAT_REAR_MULAW                },
    { "AL_FORMAT_MONO_ALAW_EXT",              AL_FORMAT_MONO_ALAW_EXT             },
    { "AL_FORMAT_STEREO_ALAW_EXT",            AL_FORMAT_STEREO_ALAW_EXT           },

    // Internal Buffer Formats
    { "AL_MONO8_SOFT",                        AL_MONO8_SOFT                       },
    { "AL_MONO16_SOFT",                       AL_MONO16_SOFT                      },
    { "AL_MONO32F_SOFT",                      AL_MONO32F_SOFT                     },
    { "AL_STEREO8_SOFT",                      AL_STEREO8_SOFT                     },
    { "AL_STEREO16_SOFT",                     AL_STEREO16_SOFT                    },
    { "AL_STEREO32F_SOFT",                    AL_STEREO32F_SOFT                   },
    { "AL_QUAD8_SOFT",                        AL_QUAD8_SOFT                       },
    { "AL_QUAD16_SOFT",                       AL_QUAD16_SOFT                      },
    { "AL_QUAD32F_SOFT",                      AL_QUAD32F_SOFT                     },
    { "AL_REAR8_SOFT",                        AL_REAR8_SOFT                       },
    { "AL_REAR16_SOFT",                       AL_REAR16_SOFT                      },
    { "AL_REAR32F_SOFT",                      AL_REAR32F_SOFT                     },
    { "AL_5POINT1_8_SOFT",                    AL_5POINT1_8_SOFT                   },
    { "AL_5POINT1_16_SOFT",                   AL_5POINT1_16_SOFT                  },
    { "AL_5POINT1_32F_SOFT",                  AL_5POINT1_32F_SOFT                 },
    { "AL_6POINT1_8_SOFT",                    AL_6POINT1_8_SOFT                   },
    { "AL_6POINT1_16_SOFT",                   AL_6POINT1_16_SOFT                  },
    { "AL_6POINT1_32F_SOFT",                  AL_6POINT1_32F_SOFT                 },
    { "AL_7POINT1_8_SOFT",                    AL_7POINT1_8_SOFT                   },
    { "AL_7POINT1_16_SOFT",                   AL_7POINT1_16_SOFT                  },
    { "AL_7POINT1_32F_SOFT",                  AL_7POINT1_32F_SOFT                 },

    // Buffer Channel Configurations
    { "AL_MONO_SOFT",                         AL_MONO_SOFT                        },
    { "AL_STEREO_SOFT",                       AL_STEREO_SOFT                      },
    { "AL_QUAD_SOFT",                         AL_QUAD_SOFT                        },
    { "AL_REAR_SOFT",                         AL_REAR_SOFT                        },
    { "AL_5POINT1_SOFT",                      AL_5POINT1_SOFT                     },
    { "AL_6POINT1_SOFT",                      AL_6POINT1_SOFT                     },
    { "AL_7POINT1_SOFT",                      AL_7POINT1_SOFT                     },

    // Buffer Sample Types
    { "AL_BYTE_SOFT",                         AL_BYTE_SOFT                        },
    { "AL_UNSIGNED_BYTE_SOFT",                AL_UNSIGNED_BYTE_SOFT               },
    { "AL_SHORT_SOFT",                        AL_SHORT_SOFT                       },
    { "AL_UNSIGNED_SHORT_SOFT",               AL_UNSIGNED_SHORT_SOFT              },
    { "AL_INT_SOFT",                          AL_INT_SOFT                         },
    { "AL_UNSIGNED_INT_SOFT",                 AL_UNSIGNED_INT_SOFT                },
    { "AL_FLOAT_SOFT",                        AL_FLOAT_SOFT                       },
    { "AL_DOUBLE_SOFT",                       AL_DOUBLE_SOFT                      },
    { "AL_BYTE3_SOFT",                        AL_BYTE3_SOFT                       },
    { "AL_UNSIGNED_BYTE3_SOFT",               AL_UNSIGNED_BYTE3_SOFT              },

    // Buffer attributes
    { "AL_FREQUENCY",                         AL_FREQUENCY                        },
    { "AL_BITS",                              AL_BITS                             },
    { "AL_CHANNELS",                          AL_CHANNELS                         },
    { "AL_SIZE",                              AL_SIZE                             },
    { "AL_INTERNAL_FORMAT_SOFT",              AL_INTERNAL_FORMAT_SOFT             },
    { "AL_BYTE_LENGTH_SOFT",                  AL_BYTE_LENGTH_SOFT                 },
    { "AL_SAMPLE_LENGTH_SOFT",                AL_SAMPLE_LENGTH_SOFT               },
    { "AL_SEC_LENGTH_SOFT",                   AL_SEC_LENGTH_SOFT                  },

    // Buffer States (not supported yet)
    { "AL_UNUSED",                            AL_UNUSED                           },
    { "AL_PENDING",                           AL_PENDING                          },
    { "AL_PROCESSED",                         AL_PROCESSED                        },

    // AL Error Messages
    { "AL_NO_ERROR",                          AL_NO_ERROR                         },
    { "AL_INVALID_NAME",                      AL_INVALID_NAME                     },
    { "AL_INVALID_ENUM",                      AL_INVALID_ENUM                     },
    { "AL_INVALID_VALUE",                     AL_INVALID_VALUE                    },
    { "AL_INVALID_OPERATION",                 AL_INVALID_OPERATION                },
    { "AL_OUT_OF_MEMORY",                     AL_OUT_OF_MEMORY                    },

    // Context strings
    { "AL_VENDOR",                            AL_VENDOR                           },
    { "AL_VERSION",                           AL_VERSION                          },
    { "AL_RENDERER",                          AL_RENDERER                         },
    { "AL_EXTENSIONS",                        AL_EXTENSIONS                       },

    // Global states
    { "AL_DOPPLER_FACTOR",                    AL_DOPPLER_FACTOR                   },
    { "AL_DOPPLER_VELOCITY",                  AL_DOPPLER_VELOCITY                 },
    { "AL_DISTANCE_MODEL",                    AL_DISTANCE_MODEL                   },
    { "AL_SPEED_OF_SOUND",                    AL_SPEED_OF_SOUND                   },
    { "AL_SOURCE_DISTANCE_MODEL",             AL_SOURCE_DISTANCE_MODEL            },
    { "AL_DEFERRED_UPDATES_SOFT",             AL_DEFERRED_UPDATES_SOFT            },

    // Distance Models
    { "AL_INVERSE_DISTANCE",                  AL_INVERSE_DISTANCE                 },
    { "AL_INVERSE_DISTANCE_CLAMPED",          AL_INVERSE_DISTANCE_CLAMPED         },
    { "AL_LINEAR_DISTANCE",                   AL_LINEAR_DISTANCE                  },
    { "AL_LINEAR_DISTANCE_CLAMPED",           AL_LINEAR_DISTANCE_CLAMPED          },
    { "AL_EXPONENT_DISTANCE",                 AL_EXPONENT_DISTANCE                },
    { "AL_EXPONENT_DISTANCE_CLAMPED",         AL_EXPONENT_DISTANCE_CLAMPED        },

    // Filter types
    { "AL_FILTER_TYPE",                       AL_FILTER_TYPE                      },
    { "AL_FILTER_NULL",                       AL_FILTER_NULL                      },
    { "AL_FILTER_LOWPASS",                    AL_FILTER_LOWPASS                   },
#if 0
    { "AL_FILTER_HIGHPASS",                   AL_FILTER_HIGHPASS                  },
    { "AL_FILTER_BANDPASS",                   AL_FILTER_BANDPASS                  },
#endif

    // Filter params
    { "AL_LOWPASS_GAIN",                      AL_LOWPASS_GAIN                     },
    { "AL_LOWPASS_GAINHF",                    AL_LOWPASS_GAINHF                   },

    // Effect types
    { "AL_EFFECT_TYPE",                       AL_EFFECT_TYPE                      },
    { "AL_EFFECT_NULL",                       AL_EFFECT_NULL                      },
    { "AL_EFFECT_REVERB",                     AL_EFFECT_REVERB                    },
    { "AL_EFFECT_EAXREVERB",                  AL_EFFECT_EAXREVERB                 },
#if 0
    { "AL_EFFECT_CHORUS",                     AL_EFFECT_CHORUS                    },
    { "AL_EFFECT_DISTORTION",                 AL_EFFECT_DISTORTION                },
#endif
    { "AL_EFFECT_ECHO",                       AL_EFFECT_ECHO                      },
#if 0
    { "AL_EFFECT_FLANGER",                    AL_EFFECT_FLANGER                   },
    { "AL_EFFECT_FREQUENCY_SHIFTER",          AL_EFFECT_FREQUENCY_SHIFTER         },
    { "AL_EFFECT_VOCAL_MORPHER",              AL_EFFECT_VOCAL_MORPHER             },
    { "AL_EFFECT_PITCH_SHIFTER",              AL_EFFECT_PITCH_SHIFTER             },
#endif
    { "AL_EFFECT_RING_MODULATOR",             AL_EFFECT_RING_MODULATOR            },
#if 0
    { "AL_EFFECT_AUTOWAH",                    AL_EFFECT_AUTOWAH                   },
    { "AL_EFFECT_COMPRESSOR",                 AL_EFFECT_COMPRESSOR                },
    { "AL_EFFECT_EQUALIZER",                  AL_EFFECT_EQUALIZER                 },
#endif
    { "AL_EFFECT_DEDICATED_LOW_FREQUENCY_EFFECT",AL_EFFECT_DEDICATED_LOW_FREQUENCY_EFFECT},
    { "AL_EFFECT_DEDICATED_DIALOGUE",         AL_EFFECT_DEDICATED_DIALOGUE        },

    // Reverb params
    { "AL_REVERB_DENSITY",                    AL_REVERB_DENSITY                   },
    { "AL_REVERB_DIFFUSION",                  AL_REVERB_DIFFUSION                 },
    { "AL_REVERB_GAIN",                       AL_REVERB_GAIN                      },
    { "AL_REVERB_GAINHF",                     AL_REVERB_GAINHF                    },
    { "AL_REVERB_DECAY_TIME",                 AL_REVERB_DECAY_TIME                },
    { "AL_REVERB_DECAY_HFRATIO",              AL_REVERB_DECAY_HFRATIO             },
    { "AL_REVERB_REFLECTIONS_GAIN",           AL_REVERB_REFLECTIONS_GAIN          },
    { "AL_REVERB_REFLECTIONS_DELAY",          AL_REVERB_REFLECTIONS_DELAY         },
    { "AL_REVERB_LATE_REVERB_GAIN",           AL_REVERB_LATE_REVERB_GAIN          },
    { "AL_REVERB_LATE_REVERB_DELAY",          AL_REVERB_LATE_REVERB_DELAY         },
    { "AL_REVERB_AIR_ABSORPTION_GAINHF",      AL_REVERB_AIR_ABSORPTION_GAINHF     },
    { "AL_REVERB_ROOM_ROLLOFF_FACTOR",        AL_REVERB_ROOM_ROLLOFF_FACTOR       },
    { "AL_REVERB_DECAY_HFLIMIT",              AL_REVERB_DECAY_HFLIMIT             },

    // EAX Reverb params
    { "AL_EAXREVERB_DENSITY",                 AL_EAXREVERB_DENSITY                },
    { "AL_EAXREVERB_DIFFUSION",               AL_EAXREVERB_DIFFUSION              },
    { "AL_EAXREVERB_GAIN",                    AL_EAXREVERB_GAIN                   },
    { "AL_EAXREVERB_GAINHF",                  AL_EAXREVERB_GAINHF                 },
    { "AL_EAXREVERB_GAINLF",                  AL_EAXREVERB_GAINLF                 },
    { "AL_EAXREVERB_DECAY_TIME",              AL_EAXREVERB_DECAY_TIME             },
    { "AL_EAXREVERB_DECAY_HFRATIO",           AL_EAXREVERB_DECAY_HFRATIO          },
    { "AL_EAXREVERB_DECAY_LFRATIO",           AL_EAXREVERB_DECAY_LFRATIO          },
    { "AL_EAXREVERB_REFLECTIONS_GAIN",        AL_EAXREVERB_REFLECTIONS_GAIN       },
    { "AL_EAXREVERB_REFLECTIONS_DELAY",       AL_EAXREVERB_REFLECTIONS_DELAY      },
    { "AL_EAXREVERB_REFLECTIONS_PAN",         AL_EAXREVERB_REFLECTIONS_PAN        },
    { "AL_EAXREVERB_LATE_REVERB_GAIN",        AL_EAXREVERB_LATE_REVERB_GAIN       },
    { "AL_EAXREVERB_LATE_REVERB_DELAY",       AL_EAXREVERB_LATE_REVERB_DELAY      },
    { "AL_EAXREVERB_LATE_REVERB_PAN",         AL_EAXREVERB_LATE_REVERB_PAN        },
    { "AL_EAXREVERB_ECHO_TIME",               AL_EAXREVERB_ECHO_TIME              },
    { "AL_EAXREVERB_ECHO_DEPTH",              AL_EAXREVERB_ECHO_DEPTH             },
    { "AL_EAXREVERB_MODULATION_TIME",         AL_EAXREVERB_MODULATION_TIME        },
    { "AL_EAXREVERB_MODULATION_DEPTH",        AL_EAXREVERB_MODULATION_DEPTH       },
    { "AL_EAXREVERB_AIR_ABSORPTION_GAINHF",   AL_EAXREVERB_AIR_ABSORPTION_GAINHF  },
    { "AL_EAXREVERB_HFREFERENCE",             AL_EAXREVERB_HFREFERENCE            },
    { "AL_EAXREVERB_LFREFERENCE",             AL_EAXREVERB_LFREFERENCE            },
    { "AL_EAXREVERB_ROOM_ROLLOFF_FACTOR",     AL_EAXREVERB_ROOM_ROLLOFF_FACTOR    },
    { "AL_EAXREVERB_DECAY_HFLIMIT",           AL_EAXREVERB_DECAY_HFLIMIT          },

    // Echo params
    { "AL_ECHO_DELAY",                        AL_ECHO_DELAY                       },
    { "AL_ECHO_LRDELAY",                      AL_ECHO_LRDELAY                     },
    { "AL_ECHO_DAMPING",                      AL_ECHO_DAMPING                     },
    { "AL_ECHO_FEEDBACK",                     AL_ECHO_FEEDBACK                    },
    { "AL_ECHO_SPREAD",                       AL_ECHO_SPREAD                      },

    // Ring Modulator params
    { "AL_RING_MODULATOR_FREQUENCY",          AL_RING_MODULATOR_FREQUENCY         },
    { "AL_RING_MODULATOR_HIGHPASS_CUTOFF",    AL_RING_MODULATOR_HIGHPASS_CUTOFF   },
    { "AL_RING_MODULATOR_WAVEFORM",           AL_RING_MODULATOR_WAVEFORM          },

    // Dedicated Dialogue/LFE params
    { "AL_DEDICATED_GAIN",                    AL_DEDICATED_GAIN                   },


    // Default
    { NULL,                                   (ALenum)0                           }
};


const struct EffectList EffectList[] = {
    { "eaxreverb", EAXREVERB, "AL_EFFECT_EAXREVERB",      AL_EFFECT_EAXREVERB },
    { "reverb",    REVERB,    "AL_EFFECT_REVERB",         AL_EFFECT_REVERB },
    { "echo",      ECHO,      "AL_EFFECT_ECHO",           AL_EFFECT_ECHO },
    { "modulator", MODULATOR, "AL_EFFECT_RING_MODULATOR", AL_EFFECT_RING_MODULATOR },
    { "dedicated", DEDICATED, "AL_EFFECT_DEDICATED_LOW_FREQUENCY_EFFECT", AL_EFFECT_DEDICATED_LOW_FREQUENCY_EFFECT },
    { "dedicated", DEDICATED, "AL_EFFECT_DEDICATED_DIALOGUE", AL_EFFECT_DEDICATED_DIALOGUE },
    { NULL, 0, NULL, (ALenum)0 }
};


AL_API ALboolean AL_APIENTRY alIsExtensionPresent(const ALchar *extName)
{
    ALboolean bIsSupported = AL_FALSE;
    ALCcontext *Context;
    const char *ptr;
    size_t len;

    Context = GetContextRef();
    if(!Context) return AL_FALSE;

    if(!extName)
        alSetError(Context, AL_INVALID_VALUE);
    else
    {
        len = strlen(extName);
        ptr = Context->ExtensionList;
        while(ptr && *ptr)
        {
            if(strncasecmp(ptr, extName, len) == 0 &&
               (ptr[len] == '\0' || isspace(ptr[len])))
            {
                bIsSupported = AL_TRUE;
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

    ALCcontext_DecRef(Context);
    return bIsSupported;
}


AL_API ALvoid* AL_APIENTRY alGetProcAddress(const ALchar *funcName)
{
    if(!funcName)
        return NULL;
    return alcGetProcAddress(NULL, funcName);
}

AL_API ALenum AL_APIENTRY alGetEnumValue(const ALchar *enumName)
{
    ALsizei i;

    for(i = 0;EffectList[i].ename;i++)
    {
        if(DisabledEffects[EffectList[i].type] &&
           strcmp(EffectList[i].ename, enumName) == 0)
            return (ALenum)0;
    }

    i = 0;
    while(enumeration[i].enumName &&
          strcmp(enumeration[i].enumName, enumName) != 0)
        i++;

    return enumeration[i].value;
}
