//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#pragma once

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>

#undef WIN32

#define LOADOES(type, name) type name; { name = (type) eglGetProcAddress(#name); }

#define PERFORM_ERROR_CHECKS 0
#if PERFORM_ERROR_CHECKS

inline int glCheckError()
{
    int ret = glGetError();

    if ( ret != 0 ) {
        err_printf("glError: %x\n", ret);
        //*((char *) 0) = 0;
    }

    return 0;
}

#else

inline int glCheckError()
{
    return 0;
}

#endif 

void RegisterEGL();

inline void EbrEnableTextures() {}
inline void EbrDisableTextures() {}

#define GL_RENDERBUFFER_OES GL_RENDERBUFFER
#define GL_RENDERBUFFER_BINDING_OES GL_RENDERBUFFER_BINDING
#define GL_FRAMEBUFFER_BINDING_OES GL_FRAMEBUFFER_BINDING
