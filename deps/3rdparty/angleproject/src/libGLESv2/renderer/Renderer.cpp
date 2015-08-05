#include "precompiled.h"
//
// Copyright (c) 2012-2013 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// Renderer.cpp: Implements EGL dependencies for creating and destroying Renderer instances.

#include <EGL/eglext.h>
#include "libGLESv2/main.h"
#include "libGLESv2/Program.h"
#include "libGLESv2/renderer/Renderer.h"
#include "libGLESv2/renderer/Renderer11.h"
#include "libGLESv2/utilities.h"
#include "third_party/trace_event/trace_event.h"

#if !defined(ANGLE_ENABLE_D3D11)
// Enables use of the Direct3D 11 API for a default display, when available
#define ANGLE_ENABLE_D3D11 1
#endif

#if !defined(D3DCOMPILER_DLL)
#define D3DCOMPILER_DLL "NO_COMPILER"
#endif

// d3dcompiler is available to Windows Store Apps (winrt) in Windows 8.1
// using Visual Studio 2013
#if defined(ANGLE_PLATFORM_WP8)
    #pragma message("Warning: d3dcompiler dll is not available for Windows Phone 8.0. Must use precompiled shaders.")
#elif defined(ANGLE_PLATFORM_WINRT)
#if (_MSC_VER >= 1800)
    #pragma comment(lib,"d3dcompiler.lib")
#else
    #pragma message("Warning: Visual Studio 2013 and Windows 8.1 required for Windows Store App certification")
    #pragma message("Warning: Visual Studio 2012 d3dcompiler dll is available only for development of a Windows Store App.")
    #pragma message("Warning: d3dcompiler dll is not available for Windows 8.0 Store Apps. Must use precompiled shaders.")
#endif // (_MSC_VER >= 1800)
#else 
#include "libGLESv2/renderer/Renderer9.h"
#endif // #if defined(ANGLE_PLATFORM_WINRT)

namespace rx
{

Renderer::Renderer(egl::Display *display) : mDisplay(display)
{
    mD3dCompilerModule = NULL;
    mD3DCompileFunc = NULL;
    mHasCompiler = TRUE;
}

Renderer::~Renderer()
{
    if (mD3dCompilerModule)
    {
        FreeLibrary(mD3dCompilerModule);
        mD3dCompilerModule = NULL;
    }
}

bool Renderer::initializeCompiler()
{
    TRACE_EVENT0("gpu", "initializeCompiler");
#if defined(ANGLE_PLATFORM_WP8)
    mD3dCompilerModule = NULL;
    mD3DCompileFunc = NULL;
    mHasCompiler = false;
    return true;
#endif //#if defined(ANGLE_PLATFORM_WP8)

#if defined(ANGLE_PLATFORM_WINRT) && (_MSC_VER >= 1800)
    ERR("No D3D compiler module available - must use precompiled shaders\n");
    mD3dCompilerModule = NULL;
    mD3DCompileFunc = reinterpret_cast<pCompileFunc>(D3DCompile);
    mHasCompiler = true;
    return true;
#endif // #if defined(ANGLE_PLATFORM_WINRT) && (_MSC_VER >= 1800)

#if defined(ANGLE_PRELOADED_D3DCOMPILER_MODULE_NAMES)
    // Find a D3DCompiler module that had already been loaded based on a predefined list of versions.
    static TCHAR* d3dCompilerNames[] = ANGLE_PRELOADED_D3DCOMPILER_MODULE_NAMES;

    for (size_t i = 0; i < ArraySize(d3dCompilerNames); ++i)
    {
        if (GetModuleHandleEx(0, d3dCompilerNames[i], &mD3dCompilerModule))
        {
            break;
        }
    }
#else
    // Load the version of the D3DCompiler DLL associated with the Direct3D version ANGLE was built with.
#if defined(ANGLE_PLATFORM_WINRT)
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    mD3dCompilerModule = LoadLibrary(D3DCOMPILER_DLL);
#else
    mD3dCompilerModule = LoadPackagedLibrary((LPCWSTR)D3DCOMPILER_DLL, 0);
#endif
    if (!mD3dCompilerModule)
    {
        ERR("No D3D compiler module found - must use precompiled shaders\n");
        mD3DCompileFunc = NULL;
        mHasCompiler = false;
        return true;
    }
#else
    mD3dCompilerModule = LoadLibrary(D3DCOMPILER_DLL);
#endif //
#endif  // ANGLE_PRELOADED_D3DCOMPILER_MODULE_NAMES

    if (!mD3dCompilerModule)
    {
        ERR("No D3D compiler module found - aborting!\n");
        mHasCompiler = FALSE;
        return false;
    }

    mD3DCompileFunc = reinterpret_cast<pCompileFunc>(GetProcAddress(mD3dCompilerModule, "D3DCompile"));
    ASSERT(mD3DCompileFunc);

    return mD3DCompileFunc != NULL;
}

#if !defined(ANGLE_PLATFORM_WP8)
// Compiles HLSL code into executable binaries
ShaderBlob *Renderer::compileToBinary(gl::InfoLog &infoLog, const char *hlsl, const char *profile, UINT optimizationFlags, bool alternateFlags)
{
    if (!hlsl)
    {
        return NULL;
    }

    HRESULT result = S_OK;
    UINT flags = 0;
    std::string sourceText;
    if (gl::perfActive())
    {
        flags |= D3DCOMPILE_DEBUG;

#ifdef NDEBUG
        flags |= optimizationFlags;
#else
        flags |= D3DCOMPILE_SKIP_OPTIMIZATION;
#endif

        std::string sourcePath = getTempPath();
        sourceText = std::string("#line 2 \"") + sourcePath + std::string("\"\n\n") + std::string(hlsl);
        writeFile(sourcePath.c_str(), sourceText.c_str(), sourceText.size());
    }
    else
    {
        flags |= optimizationFlags;
        sourceText = hlsl;
    }

    // Sometimes D3DCompile will fail with the default compilation flags for complicated shaders when it would otherwise pass with alternative options.
    // Try the default flags first and if compilation fails, try some alternatives.
    const static UINT extraFlags[] =
    {
        0,
        D3DCOMPILE_AVOID_FLOW_CONTROL,
        D3DCOMPILE_PREFER_FLOW_CONTROL
    };

    const static char * const extraFlagNames[] =
    {
        "default",
        "avoid flow control",
        "prefer flow control"
    };

    int attempts = alternateFlags ? ArraySize(extraFlags) : 1;
    pD3DCompile compileFunc = reinterpret_cast<pD3DCompile>(mD3DCompileFunc);
    for (int i = 0; i < attempts; ++i)
    {
        ID3DBlob *errorMessage = NULL;
        ID3DBlob *binary = NULL;

        result = compileFunc(hlsl, strlen(hlsl), gl::g_fakepath, NULL, NULL,
                             "main", profile, flags | extraFlags[i], 0, &binary, &errorMessage);
        if (errorMessage)
        {
            const char *message = (const char*)errorMessage->GetBufferPointer();

            infoLog.appendSanitized(message);
            TRACE("\n%s", hlsl);
            TRACE("\n%s", message);

            errorMessage->Release();
            errorMessage = NULL;
        }

        if (SUCCEEDED(result))
        {
            return (ShaderBlob*)binary;
        }
        else
        {
#if defined(ANGLE_PLATFORM_WINRT)
            if (result == E_OUTOFMEMORY)
#else
            if (result == D3DERR_OUTOFVIDEOMEMORY || result == E_OUTOFMEMORY)
#endif // #if defined(ANGLE_PLATFORM_WINRT)
            {
                return gl::error(GL_OUT_OF_MEMORY, (ShaderBlob*) NULL);
            }

            infoLog.append("Warning: D3D shader compilation failed with ");
            infoLog.append(extraFlagNames[i]);
            infoLog.append(" flags.");
            if (i + 1 < attempts)
            {
                infoLog.append(" Retrying with ");
                infoLog.append(extraFlagNames[i + 1]);
                infoLog.append(".\n");
            }
        }
    }
    return NULL;
}
#endif // #if !defined(ANGLE_PLATFORM_WP8)

}

extern "C"
{

rx::Renderer *glCreateRenderer(egl::Display *display, AngleNativeWindowHDC hDc, EGLNativeDisplayType displayId)
{
    rx::Renderer *renderer = NULL;
    EGLint status = EGL_BAD_ALLOC;
    
#if defined(ANGLE_PLATFORM_WINRT)
	renderer = new rx::Renderer11(display, hDc);
	if (renderer)
	{
		status = renderer->initialize();
	}

	return status == EGL_SUCCESS ? renderer : NULL;
#else
    if (ANGLE_ENABLE_D3D11 ||
        displayId == EGL_D3D11_ELSE_D3D9_DISPLAY_ANGLE ||
        displayId == EGL_D3D11_ONLY_DISPLAY_ANGLE)
    {
        renderer = new rx::Renderer11(display, hDc);
    
        if (renderer)
        {
            status = renderer->initialize();
        }

        if (status == EGL_SUCCESS)
        {
            return renderer;
        }
        else if (displayId == EGL_D3D11_ONLY_DISPLAY_ANGLE)
        {
            return NULL;
        }

        // Failed to create a D3D11 renderer, try creating a D3D9 renderer
        delete renderer;
    }
#endif

#if 0 // !defined(ANGLE_PLATFORM_WINRT)
    bool softwareDevice = (displayId == EGL_SOFTWARE_DISPLAY_ANGLE);
    renderer = new rx::Renderer9(display, hDc, softwareDevice);
#endif //#if !defined(ANGLE_PLATFORM_WINRT)
    
    if (renderer)
    {
        status = renderer->initialize();
    }

    if (status == EGL_SUCCESS)
    {
        return renderer;
    }

    return NULL;
}

void glDestroyRenderer(rx::Renderer *renderer)
{
    delete renderer;
}

}