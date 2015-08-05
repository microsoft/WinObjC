//
// Copyright (c) 2002-2012 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// main.cpp: DLL entry point and management of thread-local data.

#include "libEGL/main.h"

#include "common/debug.h"
#include "common/winrtplatform.h"


#if defined(ANGLE_PLATFORM_WINRT)
#include "TLSWinrt.h"
static DWORD currentTLS = TLS_OUT_OF_INDEXES;
#else
static DWORD currentTLS = TLS_OUT_OF_INDEXES;
#endif // #if defined(ANGLE_PLATFORM_WINRT)


extern "C" BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
        {
#if !defined(ANGLE_DISABLE_TRACE)
            FILE *debug = fopen(TRACE_OUTPUT_FILE, "rt");

            if (debug)
            {
                fclose(debug);
                debug = fopen(TRACE_OUTPUT_FILE, "wt");   // Erase
                
                if (debug)
                {
                    fclose(debug);
                }
            }
#endif

            currentTLS = AngleTlsAlloc();

            if (currentTLS == TLS_OUT_OF_INDEXES)
            {
                return FALSE;
            }
        }
        // Fall throught to initialize index
      case DLL_THREAD_ATTACH:
        {
            egl::Current *current = (egl::Current*)LocalAlloc(LPTR, sizeof(egl::Current));

            if (current)
            {
				AngleTlsSetValue(currentTLS, current);

                current->error = EGL_SUCCESS;
                current->API = EGL_OPENGL_ES_API;
                current->display = EGL_NO_DISPLAY;
                current->drawSurface = EGL_NO_SURFACE;
                current->readSurface = EGL_NO_SURFACE;
            }
        }
        break;
      case DLL_THREAD_DETACH:
        {
            void *current = AngleTlsGetValue(currentTLS);

            if (current)
            {
                LocalFree((HLOCAL)current);
            }
        }
        break;
      case DLL_PROCESS_DETACH:
        {
            void *current = AngleTlsGetValue(currentTLS);

            if (current)
            {
                LocalFree((HLOCAL)current);
            }

			AngleTlsFree(currentTLS);
        }
        break;
      default:
        break;
    }

    return TRUE;
}

namespace egl
{
void setCurrentError(EGLint error)
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    current->error = error;
}

EGLint getCurrentError()
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    return current->error;
}

void setCurrentAPI(EGLenum API)
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    current->API = API;
}

EGLenum getCurrentAPI()
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    return current->API;
}

void setCurrentDisplay(EGLDisplay dpy)
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    current->display = dpy;
}

EGLDisplay getCurrentDisplay()
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    return current->display;
}

void setCurrentDrawSurface(EGLSurface surface)
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    current->drawSurface = surface;
}

EGLSurface getCurrentDrawSurface()
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    return current->drawSurface;
}

void setCurrentReadSurface(EGLSurface surface)
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    current->readSurface = surface;
}

EGLSurface getCurrentReadSurface()
{
    Current *current = (Current*)AngleTlsGetValue(currentTLS);

    return current->readSurface;
}

void error(EGLint errorCode)
{
    egl::setCurrentError(errorCode);
}

}
