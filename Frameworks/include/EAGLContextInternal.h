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

#include <COMIncludes.h>
#include <EGL/EGL.h>
#include <COMIncludes_End.h>

namespace OpenGLES {
class OpenGLESContext;
};

@interface EAGLContext () {
    int _initializedVersion;
    bool _gles11EmulationMode;

    EAGLContext* _sharegroup;

    EGLSurface _eglSurface;
    EGLContext _eglContext;
    EGLConfig _mConfig;
    GLuint _boundDrawingFramebuffer;

    int _rbWidth, _rbHeight;

    CALayer* _targetLayer;
@public
    OpenGLES::OpenGLESContext* _gl11Ctx;
}
@end

extern __declspec(thread) EAGLContext* tlsCurContext;
