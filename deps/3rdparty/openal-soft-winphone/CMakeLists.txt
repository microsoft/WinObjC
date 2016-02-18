# CMake build file list for OpenAL

CMAKE_MINIMUM_REQUIRED(VERSION 2.4)

IF(COMMAND CMAKE_POLICY)
  CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND CMAKE_POLICY)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

INCLUDE(CheckFunctionExists)
INCLUDE(CheckLibraryExists)
INCLUDE(CheckSharedFunctionExists)
INCLUDE(CheckIncludeFile)
INCLUDE(CheckIncludeFiles)
INCLUDE(CheckSymbolExists)
INCLUDE(CheckCCompilerFlag)
INCLUDE(CheckCSourceCompiles)
INCLUDE(CheckTypeSize)
INCLUDE(FindPkgConfig)


PROJECT(OpenAL C)


SET(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)


OPTION(ALSA    "Check for ALSA backend"                ON)
OPTION(OSS     "Check for OSS backend"                 ON)
OPTION(SOLARIS "Check for Solaris backend"             ON)
OPTION(SNDIO   "Check for SndIO backend"               ON)
OPTION(MMDEVAPI "Check for MMDevApi"                   ON)
OPTION(DSOUND  "Check for DirectSound backend"         ON)
OPTION(WINMM   "Check for Windows Multimedia backend"  ON)
OPTION(PORTAUDIO  "Check for PortAudio backend"        ON)
OPTION(PULSEAUDIO "Check for PulseAudio backend"       ON)
OPTION(COREAUDIO  "Check for CoreAudio backend"        ON)
OPTION(OPENSL     "Check for OpenSL backend"           ON)
OPTION(WAVE    "Enable Wave Writer backend"            ON)

OPTION(REQUIRE_ALSA       "Require ALSA backend"               OFF)
OPTION(REQUIRE_OSS        "Require OSS backend"                OFF)
OPTION(REQUIRE_SOLARIS    "Require Solaris backend"            OFF)
OPTION(REQUIRE_SNDIO      "Require SndIO backend"              OFF)
OPTION(REQUIRE_MMDEVAPI   "Require MMDevApi"                   OFF)
OPTION(REQUIRE_DSOUND     "Require DirectSound backend"        OFF)
OPTION(REQUIRE_WINMM      "Require Windows Multimedia backend" OFF)
OPTION(REQUIRE_PORTAUDIO  "Require PortAudio backend"          OFF)
OPTION(REQUIRE_PULSEAUDIO "Require PulseAudio backend"         OFF)
OPTION(REQUIRE_COREAUDIO  "Require CoreAudio backend"          OFF)
OPTION(REQUIRE_OPENSL     "Require OpenSL backend"             OFF)

OPTION(DLOPEN  "Check for the dlopen API for loading optional libs"  ON)

OPTION(WERROR  "Treat compile warnings as errors"      OFF)

OPTION(UTILS  "Build and install utility programs"  ON)

OPTION(EXAMPLES  "Build and install example programs"  ON)

OPTION(ALSOFT_CONFIG "Install alsoft.conf configuration file" OFF)


IF(WIN32)
    SET(LIBNAME OpenAL32)
    ADD_DEFINITIONS("-D_WIN32 -D_WIN32_WINNT=0x0500")
ELSE()
    SET(LIBNAME openal)
ENDIF()

IF(NOT LIBTYPE)
    SET(LIBTYPE SHARED)
ENDIF()

SET(LIB_MAJOR_VERSION "1")
SET(LIB_MINOR_VERSION "13")
SET(LIB_VERSION "${LIB_MAJOR_VERSION}.${LIB_MINOR_VERSION}")

SET(EXPORT_DECL "")


CHECK_TYPE_SIZE("long" SIZEOF_LONG)
CHECK_TYPE_SIZE("long long" SIZEOF_LONG_LONG)


CHECK_C_SOURCE_COMPILES("int *restrict foo;
                         int main() {return 0;}" HAVE_RESTRICT)
CHECK_C_SOURCE_COMPILES("int *__restrict foo;
                         int main() {return 0;}" HAVE___RESTRICT)


# Add definitions, compiler switches, etc.
INCLUDE_DIRECTORIES(OpenAL32/Include include "${OpenAL_BINARY_DIR}")

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
        "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
ENDIF()
IF(NOT CMAKE_DEBUG_POSTFIX)
    SET(CMAKE_DEBUG_POSTFIX "" CACHE STRING
        "Library postfix for debug builds. Normally left blank."
        FORCE)
ENDIF()

IF(MSVC)
    # ???
    SET(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} -D_DEBUG")
    SET(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL} -DNDEBUG")
    SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DNDEBUG")
    SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
    ADD_DEFINITIONS(-D_CRT_NONSTDC_NO_DEPRECATE)

    IF(NOT DXSDK_DIR)
        STRING(REGEX REPLACE "\\\\" "/" DXSDK_DIR "$ENV{DXSDK_DIR}")
    ELSE()
        STRING(REGEX REPLACE "\\\\" "/" DXSDK_DIR "${DXSDK_DIR}")
    ENDIF()
    IF(DXSDK_DIR)
        MESSAGE(STATUS "Using DirectX SDK directory: ${DXSDK_DIR}")
        SET(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} "${DXSDK_DIR}/Include")
        INCLUDE_DIRECTORIES("${DXSDK_DIR}/Include")
        LINK_DIRECTORIES("${DXSDK_DIR}/Lib")
    ENDIF()

    OPTION(FORCE_STATIC_VCRT "Force /MT for static VC runtimes" OFF)
    IF(FORCE_STATIC_VCRT)
        FOREACH(flag_var
                CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
                CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
            IF(${flag_var} MATCHES "/MD")
                STRING(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
            ENDIF()
        ENDFOREACH(flag_var)
    ENDIF()
ELSE()
    ADD_DEFINITIONS(-Winline -Wall)
    CHECK_C_COMPILER_FLAG(-Wextra HAVE_W_EXTRA)
    IF(HAVE_W_EXTRA)
        ADD_DEFINITIONS(-Wextra)
    ENDIF()

    IF(WERROR)
        ADD_DEFINITIONS(-Werror)
    ENDIF()

    SET(CMAKE_C_FLAGS_RELWITHDEBINFO "-g -O2 -D_DEBUG" CACHE STRING
        "Flags used by the compiler during Release with Debug Info builds."
        FORCE)
    SET(CMAKE_C_FLAGS_MINSIZEREL "-Os -DNDEBUG" CACHE STRING
        "Flags used by the compiler during release minsize builds."
        FORCE)
    SET(CMAKE_C_FLAGS_RELEASE "-O2 -fomit-frame-pointer -DNDEBUG" CACHE STRING
        "Flags used by the compiler during release builds"
        FORCE)
    SET(CMAKE_C_FLAGS_DEBUG "-g3 -D_DEBUG" CACHE STRING
        "Flags used by the compiler during debug builds."
        FORCE)

    CHECK_C_SOURCE_COMPILES("int foo() __attribute__((destructor));
                             int main() {return 0;}" HAVE_GCC_DESTRUCTOR)
ENDIF()

# Set visibility/export options if available
IF(WIN32)
    SET(EXPORT_DECL "__declspec(dllexport)")

    OPTION(WINE "Enable use of Wine headers when compiling" OFF)
    IF(WINE)
        FIND_PATH(WINE_INCLUDE_DIR library.h
                  PATHS
                  /usr/include/wine
                  /usr/local/include/wine
                  CMAKE_FIND_ROOT_PATH_BOTH)
        IF(WINE_INCLUDE_DIR)
            MESSAGE(STATUS "Found Wine header files - ${WINE_INCLUDE_DIR}" )
            INCLUDE_DIRECTORIES("${WINE_INCLUDE_DIR}/windows")
            SET(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} "${WINE_INCLUDE_DIR}/windows")
        ELSE()
            MESSAGE(STATUS "Could not find Wine header files" )
        ENDIF()
    ENDIF()
ELSE()
    SET(OLD_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS}")
    # Yes GCC, really don't accept visibility modes you don't support
    SET(CMAKE_REQUIRED_FLAGS "${OLD_REQUIRED_FLAGS} -Wattributes -Werror")

    CHECK_C_SOURCE_COMPILES("int foo() __attribute__((visibility(\"protected\")));
                             int main() {return 0;}" HAVE_GCC_PROTECTED_VISIBILITY)
    IF(HAVE_GCC_PROTECTED_VISIBILITY)
        SET(EXPORT_DECL "__attribute__((visibility(\"protected\")))")
    ELSE()
        CHECK_C_SOURCE_COMPILES("int foo() __attribute__((visibility(\"default\")));
                                 int main() {return 0;}" HAVE_GCC_DEFAULT_VISIBILITY)
        IF(HAVE_GCC_DEFAULT_VISIBILITY)
            SET(EXPORT_DECL "__attribute__((visibility(\"default\")))")
        ENDIF()
    ENDIF()

    IF(HAVE_GCC_PROTECTED_VISIBILITY OR HAVE_GCC_DEFAULT_VISIBILITY)
        CHECK_C_COMPILER_FLAG(-fvisibility=internal HAVE_VISIBILITY_INTERNAL_SWITCH)
        IF(HAVE_VISIBILITY_INTERNAL_SWITCH)
            ADD_DEFINITIONS(-fvisibility=internal)
        ELSE()
            CHECK_C_COMPILER_FLAG(-fvisibility=hidden HAVE_VISIBILITY_HIDDEN_SWITCH)
            IF(HAVE_VISIBILITY_HIDDEN_SWITCH)
                ADD_DEFINITIONS(-fvisibility=hidden)
            ENDIF()
        ENDIF()
    ENDIF()

    SET(CMAKE_REQUIRED_FLAGS "${OLD_REQUIRED_FLAGS}")
ENDIF()

CHECK_C_SOURCE_COMPILES("int foo(const char *str, ...) __attribute__((format(printf, 1, 2)));
                         int main() {return 0;}" HAVE_GCC_FORMAT)

CHECK_INCLUDE_FILE(fenv.h HAVE_FENV_H)
CHECK_INCLUDE_FILE(fpu_control.h HAVE_FPU_CONTROL_H)
CHECK_INCLUDE_FILE(float.h HAVE_FLOAT_H)
CHECK_INCLUDE_FILE(ieeefp.h HAVE_IEEEFP_H)
CHECK_INCLUDE_FILE(guiddef.h HAVE_GUIDDEF_H)
IF(NOT HAVE_GUIDDEF_H)
    CHECK_INCLUDE_FILE(initguid.h HAVE_INITGUID_H)
ENDIF()
CHECK_INCLUDE_FILE(arm_neon.h HAVE_ARM_NEON_H)

# Some systems need libm for some of the following math functions to work
CHECK_LIBRARY_EXISTS(m pow "" HAVE_LIBM)
IF(HAVE_LIBM)
    SET(EXTRA_LIBS m ${EXTRA_LIBS})
    SET(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} m)
ENDIF()


CHECK_SYMBOL_EXISTS(powf   math.h HAVE_POWF)
CHECK_SYMBOL_EXISTS(sqrtf  math.h HAVE_SQRTF)
CHECK_SYMBOL_EXISTS(cosf   math.h HAVE_COSF)
CHECK_SYMBOL_EXISTS(sinf   math.h HAVE_SINF)
CHECK_SYMBOL_EXISTS(acosf  math.h HAVE_ACOSF)
CHECK_SYMBOL_EXISTS(asinf  math.h HAVE_ASINF)
CHECK_SYMBOL_EXISTS(atanf  math.h HAVE_ATANF)
CHECK_SYMBOL_EXISTS(atan2f math.h HAVE_ATAN2F)
CHECK_SYMBOL_EXISTS(fabsf  math.h HAVE_FABSF)
CHECK_SYMBOL_EXISTS(log10f math.h HAVE_LOG10F)
CHECK_SYMBOL_EXISTS(floorf math.h HAVE_FLOORF)

IF(HAVE_FENV_H)
    CHECK_SYMBOL_EXISTS(fesetround fenv.h HAVE_FESETROUND)
ENDIF()

CHECK_FUNCTION_EXISTS(strtof HAVE_STRTOF)
CHECK_FUNCTION_EXISTS(_controlfp HAVE__CONTROLFP)

CHECK_FUNCTION_EXISTS(stat HAVE_STAT)
CHECK_FUNCTION_EXISTS(strcasecmp HAVE_STRCASECMP)
IF(NOT HAVE_STRCASECMP)
    CHECK_FUNCTION_EXISTS(_stricmp HAVE__STRICMP)
    IF(NOT HAVE__STRICMP)
        MESSAGE(FATAL_ERROR "No case-insensitive compare function found, please report!")
    ENDIF()

    ADD_DEFINITIONS(-Dstrcasecmp=_stricmp)
ENDIF()

CHECK_FUNCTION_EXISTS(strncasecmp HAVE_STRNCASECMP)
IF(NOT HAVE_STRNCASECMP)
    CHECK_FUNCTION_EXISTS(_strnicmp HAVE__STRNICMP)
    IF(NOT HAVE__STRNICMP)
        MESSAGE(FATAL_ERROR "No case-insensitive size-limitted compare function found, please report!")
    ENDIF()

    ADD_DEFINITIONS(-Dstrncasecmp=_strnicmp)
ENDIF()

CHECK_FUNCTION_EXISTS(snprintf HAVE_SNPRINTF)
IF(NOT HAVE_SNPRINTF)
    CHECK_FUNCTION_EXISTS(_snprintf HAVE__SNPRINTF)
    IF(NOT HAVE__SNPRINTF)
        MESSAGE(FATAL_ERROR "No snprintf function found, please report!")
    ENDIF()

    ADD_DEFINITIONS(-Dsnprintf=_snprintf)
ENDIF()

CHECK_FUNCTION_EXISTS(vsnprintf HAVE_VSNPRINTF)
IF(NOT HAVE_VSNPRINTF)
    CHECK_FUNCTION_EXISTS(_vsnprintf HAVE__VSNPRINTF)
    IF(NOT HAVE__VSNPRINTF)
        MESSAGE(FATAL_ERROR "No vsnprintf function found, please report!")
    ENDIF()

    ADD_DEFINITIONS(-Dvsnprintf=_vsnprintf)
ENDIF()

CHECK_SYMBOL_EXISTS(isfinite math.h HAVE_ISFINITE)
IF(NOT HAVE_ISFINITE)
    CHECK_FUNCTION_EXISTS(finite HAVE_FINITE)
    IF(NOT HAVE_FINITE)
        CHECK_FUNCTION_EXISTS(_finite HAVE__FINITE)
        IF(NOT HAVE__FINITE)
            MESSAGE(FATAL_ERROR "No isfinite function found, please report!")
        ENDIF()
        ADD_DEFINITIONS(-Disfinite=_finite)
    ELSE()
        ADD_DEFINITIONS(-Disfinite=finite)
    ENDIF()
ENDIF()

CHECK_SYMBOL_EXISTS(isnan math.h HAVE_ISNAN)
IF(NOT HAVE_ISNAN)
    CHECK_FUNCTION_EXISTS(_isnan HAVE__ISNAN)
    IF(NOT HAVE__ISNAN)
        MESSAGE(FATAL_ERROR "No isnan function found, please report!")
    ENDIF()

    ADD_DEFINITIONS(-Disnan=_isnan)
ENDIF()


# Check for the dlopen API (for dynamicly loading backend libs)
IF(DLOPEN)
    CHECK_INCLUDE_FILE(dlfcn.h HAVE_DLFCN_H)
    IF(HAVE_DLFCN_H)
        CHECK_LIBRARY_EXISTS(dl dlopen "" HAVE_LIBDL)
        IF(HAVE_LIBDL)
            SET(EXTRA_LIBS dl ${EXTRA_LIBS})
        ENDIF()
    ENDIF()
ENDIF()

# Check if we have Windows headers
CHECK_INCLUDE_FILE(windows.h HAVE_WINDOWS_H -D_WIN32_WINNT=0x0500)
IF(NOT HAVE_WINDOWS_H)
    CHECK_FUNCTION_EXISTS(gettimeofday HAVE_GETTIMEOFDAY)
    IF(NOT HAVE_GETTIMEOFDAY)
        MESSAGE(FATAL_ERROR "No timing function found!")
    ENDIF()

    CHECK_FUNCTION_EXISTS(nanosleep HAVE_NANOSLEEP)
    IF(NOT HAVE_NANOSLEEP)
        MESSAGE(FATAL_ERROR "No sleep function found!")
    ENDIF()

    CHECK_C_COMPILER_FLAG(-pthread HAVE_PTHREAD)
    IF(HAVE_PTHREAD)
        ADD_DEFINITIONS(-pthread)
        SET(EXTRA_LIBS ${EXTRA_LIBS} -pthread)
    ENDIF()

    # We need pthreads outside of Windows
    CHECK_INCLUDE_FILE(pthread.h HAVE_PTHREAD_H)
    IF(NOT HAVE_PTHREAD_H)
        MESSAGE(FATAL_ERROR "PThreads is required for non-Windows builds!")
    ENDIF()
    # Some systems need pthread_np.h to get recursive mutexes
    CHECK_INCLUDE_FILES("pthread.h;pthread_np.h" HAVE_PTHREAD_NP_H)

    # _GNU_SOURCE is needed on some systems for extra attributes, and
    # _REENTRANT is needed for libc thread-safety
    ADD_DEFINITIONS(-D_GNU_SOURCE=1)
    CHECK_LIBRARY_EXISTS(pthread pthread_create "" HAVE_LIBPTHREAD)
    IF(HAVE_LIBPTHREAD)
        SET(EXTRA_LIBS pthread ${EXTRA_LIBS})
    ENDIF()

    CHECK_LIBRARY_EXISTS(pthread pthread_setschedparam "" HAVE_PTHREAD_SETSCHEDPARAM)

    CHECK_LIBRARY_EXISTS(rt clock_gettime "" HAVE_LIBRT)
    IF(HAVE_LIBRT)
        SET(EXTRA_LIBS rt ${EXTRA_LIBS})
    ENDIF()
ENDIF()

# Check for a 64-bit type
CHECK_INCLUDE_FILE(stdint.h HAVE_STDINT_H)
IF(NOT HAVE_STDINT_H)
    IF(HAVE_WINDOWS_H)
        CHECK_C_SOURCE_COMPILES("\#define _WIN32_WINNT 0x0500
                                 \#include <windows.h>
                                 __int64 foo;
                                 int main() {return 0;}" HAVE___INT64)
    ENDIF()
    IF(NOT HAVE___INT64)
        IF(NOT SIZEOF_LONG MATCHES "8")
            IF(NOT SIZEOF_LONG_LONG MATCHES "8")
                MESSAGE(FATAL_ERROR "No 64-bit types found, please report!")
            ENDIF()
        ENDIF()
    ENDIF()
ENDIF()

# Windows needs winmm for timeGetTime, even if the backend is disabled
CHECK_SHARED_FUNCTION_EXISTS(timeGetTime "windows.h;mmsystem.h" winmm "" HAVE_LIBWINMM)
IF(HAVE_LIBWINMM)
    SET(EXTRA_LIBS winmm ${EXTRA_LIBS})
    SET(PKG_CONFIG_LIBS ${PKG_CONFIG_LIBS} -lwinmm)
ENDIF()


SET(OPENAL_OBJS  OpenAL32/alAuxEffectSlot.c
                 OpenAL32/alBuffer.c
                 OpenAL32/alEffect.c
                 OpenAL32/alError.c
                 OpenAL32/alExtension.c
                 OpenAL32/alFilter.c
                 OpenAL32/alListener.c
                 OpenAL32/alSource.c
                 OpenAL32/alState.c
                 OpenAL32/alThunk.c
)
SET(ALC_OBJS  Alc/ALc.c
              Alc/ALu.c
              Alc/alcConfig.c
              Alc/alcDedicated.c
              Alc/alcEcho.c
              Alc/alcModulator.c
              Alc/alcReverb.c
              Alc/alcRing.c
              Alc/alcThread.c
              Alc/bs2b.c
              Alc/helpers.c
              Alc/hrtf.c
              Alc/mixer.c
              Alc/panning.c
              # Default backends, always available
              Alc/backends/loopback.c
              Alc/backends/null.c
)

SET(BACKENDS "")
SET(HAVE_ALSA       0)
SET(HAVE_OSS        0)
SET(HAVE_SOLARIS    0)
SET(HAVE_SNDIO      0)
SET(HAVE_DSOUND     0)
SET(HAVE_WINMM      0)
SET(HAVE_PORTAUDIO  0)
SET(HAVE_PULSEAUDIO 0)
SET(HAVE_COREAUDIO  0)
SET(HAVE_OPENSL     0)
SET(HAVE_WAVE       0)

# Check ALSA backend
IF(ALSA)
    CHECK_INCLUDE_FILE(alsa/asoundlib.h HAVE_ALSA_ASOUNDLIB_H)
    IF(HAVE_ALSA_ASOUNDLIB_H)
        CHECK_SHARED_FUNCTION_EXISTS(snd_pcm_open "alsa/asoundlib.h" asound "" HAVE_LIBASOUND)
        IF(HAVE_LIBASOUND OR HAVE_DLFCN_H OR WIN32)
            SET(HAVE_ALSA 1)
            SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/alsa.c)
            IF(HAVE_DLFCN_H OR WIN32)
                SET(BACKENDS  "${BACKENDS} ALSA,")
            ELSE()
                SET(BACKENDS  "${BACKENDS} ALSA \(linked\),")
                SET(EXTRA_LIBS asound ${EXTRA_LIBS})
            ENDIF()
        ENDIF()
    ENDIF()
ENDIF()
IF(REQUIRE_ALSA AND NOT HAVE_ALSA)
    MESSAGE(FATAL_ERROR "Failed to enabled required ALSA backend")
ENDIF()

# Check OSS backend
IF(OSS)
    CHECK_INCLUDE_FILE(sys/soundcard.h HAVE_SYS_SOUNDCARD_H)
    IF(HAVE_SYS_SOUNDCARD_H)
        SET(HAVE_OSS 1)
        SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/oss.c)
        SET(BACKENDS  "${BACKENDS} OSS,")
    ENDIF()
ENDIF()
IF(REQUIRE_OSS AND NOT HAVE_OSS)
    MESSAGE(FATAL_ERROR "Failed to enabled required OSS backend")
ENDIF()

# Check Solaris backend
IF(SOLARIS)
    CHECK_INCLUDE_FILE(sys/audioio.h HAVE_SYS_AUDIOIO_H)
    IF(HAVE_SYS_AUDIOIO_H)
        SET(HAVE_SOLARIS 1)
        SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/solaris.c)
        SET(BACKENDS  "${BACKENDS} Solaris,")
    ENDIF()
ENDIF()
IF(REQUIRE_SOLARIS AND NOT HAVE_SOLARIS)
    MESSAGE(FATAL_ERROR "Failed to enabled required Solaris backend")
ENDIF()

# Check SndIO backend
IF(SNDIO)
    CHECK_INCLUDE_FILE(sndio.h HAVE_SNDIO_H)
    IF(HAVE_SNDIO_H)
        CHECK_SHARED_FUNCTION_EXISTS(sio_open "sndio.h" sndio "" HAVE_LIBSNDIO)
        IF(HAVE_LIBSNDIO OR HAVE_DLFCN_H OR WIN32)
            SET(HAVE_SNDIO 1)
            SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/sndio.c)
            IF(HAVE_DLFCN_H OR WIN32)
                SET(BACKENDS  "${BACKENDS} SndIO,")
            ELSE()
                SET(BACKENDS  "${BACKENDS} SndIO \(linked\),")
                SET(EXTRA_LIBS sndio ${EXTRA_LIBS})
            ENDIF()
        ENDIF()
    ENDIF()
ENDIF()
IF(REQUIRE_SNDIO AND NOT HAVE_SNDIO)
    MESSAGE(FATAL_ERROR "Failed to enabled required SndIO backend")
ENDIF()

# Check for MMDevApi backend
IF(HAVE_WINDOWS_H)
    IF(MMDEVAPI)
        CHECK_INCLUDE_FILE(mmdeviceapi.h HAVE_MMDEVICEAPI_H)
        IF(HAVE_MMDEVICEAPI_H)
            SET(HAVE_MMDEVAPI 1)
            SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/mmdevapi.c)

            SET(BACKENDS  "${BACKENDS} MMDevApi,")
        ENDIF()
    ENDIF()
ENDIF()
IF(REQUIRE_MMDEVAPI AND NOT HAVE_MMDEVAPI)
    MESSAGE(FATAL_ERROR "Failed to enabled required MMDevApi backend")
ENDIF()

# Check DSound/MMSystem backend
IF(DSOUND)
    CHECK_INCLUDE_FILE(dsound.h HAVE_DSOUND_H)
    IF(HAVE_DSOUND_H)
        CHECK_SHARED_FUNCTION_EXISTS(DirectSoundCreate "dsound.h" dsound "" HAVE_LIBDSOUND)
        IF(HAVE_LIBDSOUND OR HAVE_DLFCN_H OR WIN32)
            SET(HAVE_DSOUND 1)
            SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/dsound.c)

            IF(HAVE_DLFCN_H OR WIN32)
                SET(BACKENDS  "${BACKENDS} DirectSound,")
            ELSE()
                SET(BACKENDS  "${BACKENDS} DirectSound \(linked\),")
                SET(EXTRA_LIBS dsound ${EXTRA_LIBS})
            ENDIF()
        ENDIF()
    ENDIF()
ENDIF()
IF(REQUIRE_DSOUND AND NOT HAVE_DSOUND)
    MESSAGE(FATAL_ERROR "Failed to enabled required DSound backend")
ENDIF()

IF(HAVE_WINDOWS_H)
    IF(WINMM)
        CHECK_INCLUDE_FILES("windows.h;mmsystem.h" HAVE_MMSYSTEM_H -D_WIN32_WINNT=0x0500)
        IF(HAVE_MMSYSTEM_H AND HAVE_LIBWINMM)
            SET(HAVE_WINMM 1)
            SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/winmm.c)
            SET(BACKENDS  "${BACKENDS} WinMM,")
        ENDIF()
    ENDIF()
ENDIF()
IF(REQUIRE_WINMM AND NOT HAVE_WINMM)
    MESSAGE(FATAL_ERROR "Failed to enabled required WinMM backend")
ENDIF()

# Check PortAudio backend
IF(PORTAUDIO)
    CHECK_INCLUDE_FILE(portaudio.h HAVE_PORTAUDIO_H)
    IF(HAVE_PORTAUDIO_H)
        CHECK_SHARED_FUNCTION_EXISTS(Pa_Initialize "portaudio.h" portaudio "" HAVE_LIBPORTAUDIO)
        IF(HAVE_LIBPORTAUDIO OR HAVE_DLFCN_H OR WIN32)
            SET(HAVE_PORTAUDIO 1)
            SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/portaudio.c)
            IF(HAVE_DLFCN_H OR WIN32)
                SET(BACKENDS  "${BACKENDS} PortAudio,")
            ELSE()
                SET(BACKENDS  "${BACKENDS} PortAudio \(linked\),")
                SET(EXTRA_LIBS portaudio ${EXTRA_LIBS})
            ENDIF()
        ENDIF()
    ENDIF()
ENDIF()
IF(REQUIRE_PORTAUDIO AND NOT HAVE_PORTAUDIO)
    MESSAGE(FATAL_ERROR "Failed to enabled required PortAudio backend")
ENDIF()

# Check PulseAudio backend
IF(PULSEAUDIO)
    CHECK_INCLUDE_FILE(pulse/pulseaudio.h HAVE_PULSE_PULSEAUDIO_H)
    IF(HAVE_PULSE_PULSEAUDIO_H)
        CHECK_SHARED_FUNCTION_EXISTS(pa_context_new "pulse/pulseaudio.h" pulse "" HAVE_LIBPULSE)
        IF(HAVE_LIBPULSE OR HAVE_DLFCN_H OR WIN32)
            SET(HAVE_PULSEAUDIO 1)
            SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/pulseaudio.c)
            IF(HAVE_DLFCN_H OR WIN32)
                SET(BACKENDS  "${BACKENDS} PulseAudio,")
            ELSE()
                SET(BACKENDS  "${BACKENDS} PulseAudio \(linked\),")
                SET(EXTRA_LIBS pulse ${EXTRA_LIBS})
            ENDIF()
        ENDIF()
    ENDIF()
ENDIF()
IF(REQUIRE_PULSEAUDIO AND NOT HAVE_PULSEAUDIO)
    MESSAGE(FATAL_ERROR "Failed to enabled required PulseAudio backend")
ENDIF()

# Check CoreAudio backend
IF(COREAUDIO)
    CHECK_INCLUDE_FILE(/System/Library/Frameworks/CoreAudio.framework/Headers/CoreAudio.h HAVE_COREAUDIO_FRAMEWORK)
    IF(HAVE_COREAUDIO_FRAMEWORK)
        SET(HAVE_COREAUDIO 1)
        SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/coreaudio.c)
        SET(BACKENDS  "${BACKENDS} CoreAudio,")
        SET(EXTRA_LIBS /System/Library/Frameworks/CoreAudio.framework ${EXTRA_LIBS})
        SET(EXTRA_LIBS /System/Library/Frameworks/AudioUnit.framework ${EXTRA_LIBS})
        SET(EXTRA_LIBS /System/Library/Frameworks/ApplicationServices.framework ${EXTRA_LIBS})

        # Some versions of OSX may need the AudioToolbox framework. Add it if
        # it's found.
        FIND_LIBRARY(AUDIOTOOLBOX_LIBRARY
                     NAMES AudioToolbox
                     PATHS ~/Library/Frameworks
                           /Library/Frameworks
                           /System/Library/Frameworks
                    )
        IF(AUDIOTOOLBOX_LIBRARY)
            SET(EXTRA_LIBS ${AUDIOTOOLBOX_LIBRARY} ${EXTRA_LIBS})
        ENDIF()
    ENDIF()
ENDIF()
IF(REQUIRE_COREAUDIO AND NOT HAVE_COREAUDIO)
    MESSAGE(FATAL_ERROR "Failed to enabled required CoreAudio backend")
ENDIF()

# Check for OpenSL (Android) backend
IF(OPENSL)
    CHECK_INCLUDE_FILES("SLES/OpenSLES.h;SLES/OpenSLES_Android.h" HAVE_SLES_OPENSLES_ANDROID_H)
    IF(HAVE_SLES_OPENSLES_ANDROID_H)
        CHECK_SHARED_FUNCTION_EXISTS(slCreateEngine "SLES/OpenSLES.h" OpenSLES "" HAVE_LIBOPENSLES)
        IF(HAVE_LIBOPENSLES)
            SET(HAVE_OPENSL 1)
            SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/opensl.c)
            SET(BACKENDS  "${BACKENDS} OpenSL,")
            SET(EXTRA_LIBS OpenSLES ${EXTRA_LIBS})
        ENDIF()
    ENDIF()
ENDIF()
IF(REQUIRE_OPENSL AND NOT HAVE_OPENSL)
    MESSAGE(FATAL_ERROR "Failed to enabled required OpenSL backend")
ENDIF()

# Optionally enable the Wave Writer backend
IF(WAVE)
    SET(HAVE_WAVE 1)
    SET(ALC_OBJS  ${ALC_OBJS} Alc/backends/wave.c)
    SET(BACKENDS  "${BACKENDS} WaveFile,")
ENDIF()

# This is always available
SET(BACKENDS  "${BACKENDS} Null")

IF(EXAMPLES)
    PKG_CHECK_MODULES(FFMPEG libavcodec libavformat)
ENDIF()

IF(LIBTYPE STREQUAL "STATIC")
    ADD_DEFINITIONS(-DAL_LIBTYPE_STATIC)
    SET(PKG_CONFIG_CFLAGS -DAL_LIBTYPE_STATIC ${PKG_CONFIG_CFLAGS})
ENDIF()

# Needed for openal.pc.in
SET(prefix ${CMAKE_INSTALL_PREFIX})
SET(exec_prefix "\${prefix}")
SET(libdir "\${exec_prefix}/lib${LIB_SUFFIX}")
SET(bindir "\${exec_prefix}/bin")
SET(includedir "\${prefix}/include")
SET(PACKAGE_VERSION "${LIB_VERSION}")

# End configuration
CONFIGURE_FILE(
    "${OpenAL_SOURCE_DIR}/config.h.in"
    "${OpenAL_BINARY_DIR}/config.h")
CONFIGURE_FILE(
    "${OpenAL_SOURCE_DIR}/openal.pc.in"
    "${OpenAL_BINARY_DIR}/openal.pc"
    @ONLY)

# Build a library
ADD_LIBRARY(${LIBNAME} ${LIBTYPE} ${OPENAL_OBJS} ${ALC_OBJS})
SET_TARGET_PROPERTIES(${LIBNAME} PROPERTIES DEFINE_SYMBOL AL_BUILD_LIBRARY
                                            COMPILE_FLAGS -DAL_ALEXT_PROTOTYPES
                                            VERSION ${LIB_VERSION}.0
                                            SOVERSION ${LIB_MAJOR_VERSION})
IF(WIN32 AND NOT LIBTYPE STREQUAL "STATIC")
    SET_TARGET_PROPERTIES(${LIBNAME} PROPERTIES PREFIX "")
ENDIF()

TARGET_LINK_LIBRARIES(${LIBNAME} ${EXTRA_LIBS})

# Add an install target here
INSTALL(TARGETS ${LIBNAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION "lib${LIB_SUFFIX}"
        ARCHIVE DESTINATION "lib${LIB_SUFFIX}"
)
INSTALL(FILES include/AL/al.h
              include/AL/alc.h
              include/AL/alext.h
              include/AL/efx.h
              include/AL/efx-creative.h
              include/AL/efx-presets.h
        DESTINATION include/AL
)
INSTALL(FILES "${OpenAL_BINARY_DIR}/openal.pc"
        DESTINATION "lib${LIB_SUFFIX}/pkgconfig")


MESSAGE(STATUS "")
MESSAGE(STATUS "Building OpenAL with support for the following backends:")
MESSAGE(STATUS "    ${BACKENDS}")
MESSAGE(STATUS "")

IF(WIN32)
    IF(NOT HAVE_DSOUND)
        MESSAGE(STATUS "WARNING: Building the Windows version without DirectSound output")
        MESSAGE(STATUS "         This is probably NOT what you want!")
        MESSAGE(STATUS "")
    ENDIF()
ENDIF()

# Install alsoft.conf configuration file
IF(ALSOFT_CONFIG)
    INSTALL(FILES alsoftrc.sample
            DESTINATION /etc/openal
            RENAME alsoft.conf
    )
    MESSAGE(STATUS "Installing sample alsoft.conf")
    MESSAGE(STATUS "")
ENDIF()

IF(UTILS)
    ADD_EXECUTABLE(openal-info utils/openal-info.c)
    TARGET_LINK_LIBRARIES(openal-info ${LIBNAME})
    INSTALL(TARGETS openal-info
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION "lib${LIB_SUFFIX}"
            ARCHIVE DESTINATION "lib${LIB_SUFFIX}"
    )
    MESSAGE(STATUS "Building utility programs")
    MESSAGE(STATUS "")
ENDIF()

IF(EXAMPLES)
    IF(FFMPEG_FOUND)
        ADD_EXECUTABLE(alstream examples/alhelpers.c examples/alffmpeg.c examples/alstream.c)
        TARGET_LINK_LIBRARIES(alstream ${FFMPEG_LIBRARIES} ${LIBNAME})
        SET_TARGET_PROPERTIES(alstream PROPERTIES COMPILE_FLAGS "${FFMPEG_CFLAGS}")
        INSTALL(TARGETS alstream
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION "lib${LIB_SUFFIX}"
                ARCHIVE DESTINATION "lib${LIB_SUFFIX}"
        )

        MESSAGE(STATUS "Building ffmpeg example programs")
        MESSAGE(STATUS "")
    ENDIF()
ENDIF()
