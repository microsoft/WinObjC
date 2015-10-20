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

#include "Starboard.h"

#include <COMIncludes.h>
#include "Windows.ui.xaml.media.dxinterop.h"
#define GL_GLEXT_PROTOTYPES

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <EGL/EGL.h>
#include <EGL/eglext.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <COMIncludes_End.h>

#include "CALayerInternal.h"
#include "EAGLContextInternal.h"
#include "UWP/InteropBase.h"
#include "UWP/WindowsUIXamlControls.h"

#include "QuartzCore/CALayer.h"
#include "QuartzCore/CAEAGLLayer.h"
#include "Foundation/NSRunLoop.h"

#include "GLES1122/OpenGLES20/OpenGLES20Context.h"

__declspec(thread) EAGLContext* tlsCurContext;
static EGLDisplay eglDisplay = EGL_NO_DISPLAY;

@implementation EAGLContext {
}
+ (void)initialize {
    if (self == [EAGLContext class]) {
        // setup EGL
        EGLint majorVersion;
        EGLint minorVersion;

        eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (eglDisplay == EGL_NO_DISPLAY) {
            [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglGetDisplay failed"];
        }

        if (!eglInitialize(eglDisplay, &majorVersion, &minorVersion)) {
            [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglInitialize failed"];
        }

        eglBindAPI(EGL_OPENGL_ES_API);
        if (eglGetError() != EGL_SUCCESS) {
            [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglBindAPI failed code=0x%x", eglGetError()];
        }
    }
}

- (instancetype)initWithAPI:(NSUInteger)api {
    return [self initWithAPI:api sharegroup:nil];
}

- (instancetype)initWithAPI:(NSUInteger)api sharegroup:(EAGLContext*)sharegroup {
    if (_initializedVersion != 0) {
        [NSException raiseWithLogging:@"EAGLContextFailure" format:@"EAGLContext already initialized"];
    }
    if (api != 1 && api != 2) {
        [NSException raiseWithLogging:@"EAGLContextFailure" format:@"Only OpenGL ES 1.x and OpenGL ES 2.0 are supported (api=0x%x)", api];
    }

    _eglSurface = EGL_NO_SURFACE;
    _eglContext = EGL_NO_CONTEXT;

    const EGLint configAttributes[] = { EGL_RENDERABLE_TYPE,
                                        EGL_OPENGL_ES2_BIT,
                                        EGL_SURFACE_TYPE,
                                        EGL_PBUFFER_BIT,
                                        EGL_BLUE_SIZE,
                                        8,
                                        EGL_GREEN_SIZE,
                                        8,
                                        EGL_RED_SIZE,
                                        8,
                                        EGL_ALPHA_SIZE,
                                        8,
                                        EGL_DEPTH_SIZE,
                                        24,
                                        EGL_STENCIL_SIZE,
                                        8,
                                        EGL_NONE };

    EGLint configCount;
    if (!eglChooseConfig(eglDisplay, configAttributes, &_mConfig, 1, &configCount) || (configCount != 1)) {
        [NSException raiseWithLogging:@"EAGLContextFailure" format:@"Unable to find a valid EGL configuration"];
    }

    EGLContext shareContext = EGL_NO_CONTEXT;
    if (sharegroup != nil) {
        shareContext = sharegroup->_eglContext;
    }

    const EGLint createContextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
    _eglContext = eglCreateContext(eglDisplay, _mConfig, shareContext, createContextAttribs);
    if (_eglContext == EGL_NO_CONTEXT) {
        [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglCreateContext failed err=0x%08x", eglGetError()];
    }

    //  Create a temporary surface so that we can make the context current prior to creating the
    //  renderbuffer surface
    EGLint pbuffer_attribute_list[] = { EGL_WIDTH, 32, EGL_HEIGHT, 32, EGL_NONE };

    _eglSurface = eglCreatePbufferSurface(eglDisplay, _mConfig, pbuffer_attribute_list);
    if (_eglSurface == EGL_NO_SURFACE) {
        [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglCreatePbufferSurface failed err=0x%08x", eglGetError()];
    }

    _initializedVersion = api;

    if (api == 1) {
        _gles11EmulationMode = true;

        EAGLContext* oldCtx = [EAGLContext currentContext];
        [EAGLContext setCurrentContext:self];
        _gl11Ctx = new OpenGLES::OpenGLES2::OpenGLES20Context();
        [EAGLContext setCurrentContext:oldCtx];
    }

    return self;
}

+ (instancetype)currentContext {
    return tlsCurContext;
}

- (NSUInteger)API {
    return _initializedVersion;
}

- (instancetype)sharegroup {
    return _sharegroup;
}

+ (BOOL)setCurrentContext:(EAGLContext*)context {
    EGLSurface eglSurface = EGL_NO_SURFACE;
    EGLContext eglContext = EGL_NO_CONTEXT;

    if (context) {
        eglSurface = context->_eglSurface;
        eglContext = context->_eglContext;
    }

    BOOL ret = eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
    if (ret == TRUE) {
        tlsCurContext = context;
    }

    return ret;
}

- (BOOL)renderbufferStorage:(int)target fromDrawable:(CAEAGLLayer*)surface {
    //  Delete any existing surface
    if (_eglSurface != EGL_NO_SURFACE) {
        eglDestroySurface(eglDisplay, _eglSurface);
        _eglSurface = EGL_NO_SURFACE;
    }

    _targetLayer = surface;

    _rbWidth = (int)[surface _pixelWidth];
    _rbHeight = (int)[surface _pixelHeight];

    if (_rbWidth == 0 || _rbHeight == 0) {
        _rbWidth = 320;
        _rbHeight = 480;
    }

    //  Create a temporary surface so that we can make the context current
    EGLint surface_attribute_list[] =
        { EGL_WIDTH, _rbWidth, EGL_HEIGHT, _rbHeight, EGL_ANGLE_SURFACE_RENDER_TO_BACK_BUFFER, EGL_TRUE, EGL_FIXED_SIZE_ANGLE,
          EGL_TRUE,  EGL_NONE };

    IUnknown* pUnkRaw = (IUnknown*)[surface.swapChainPanel internalObject];

    IInspectable* pSwapChainInspectable;
    pUnkRaw->QueryInterface(__uuidof(pSwapChainInspectable), (void**)&pSwapChainInspectable);

    _eglSurface = eglCreateWindowSurface(eglDisplay, _mConfig, pSwapChainInspectable, surface_attribute_list);
    pSwapChainInspectable->Release();

    if (_eglSurface == EGL_NO_SURFACE) {
        return FALSE;
    }

    glRenderbufferStorage(target, GL_BGRA8_EXT, _rbWidth, _rbHeight);

    surface.swapChainPanel.width = _rbWidth;
    surface.swapChainPanel.height = _rbHeight;

    if (tlsCurContext == self) {
        eglMakeCurrent(eglDisplay, _eglSurface, _eglSurface, _eglContext);
    }

    return TRUE;
}

- (BOOL)presentRenderbuffer:(int)target {
    int curFB;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &curFB);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER_ANGLE, 0);
    glBindFramebuffer(GL_READ_FRAMEBUFFER_ANGLE, curFB);
    glBlitFramebufferANGLE(0, 0, _rbWidth, _rbHeight, 0, 0, _rbWidth, _rbHeight, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER_ANGLE, curFB);
    glBindFramebuffer(GL_READ_FRAMEBUFFER_ANGLE, curFB);

    return eglSwapBuffers(eglDisplay, _eglSurface);
}

- (void)dealloc {
    [super dealloc];
}
@end

NSString* const kEAGLColorFormatRGBA8 = (NSString * const) @"kEAGLColorFormatRGBA8";
NSString* const kEAGLColorFormatRGB565 = (NSString * const) @"kEAGLColorFormatRGB565";
NSString* const kEAGLDrawablePropertyColorFormat = (NSString * const) @"kEAGLDrawablePropertyColorFormat";
NSString* const kEAGLDrawablePropertyRetainedBacking = (NSString * const) @"kEAGLDrawablePropertyRetainedBacking";
