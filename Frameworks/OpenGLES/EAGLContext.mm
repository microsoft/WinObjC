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

#include "LoggingNative.h"

__declspec(thread) EAGLContext* tlsCurContext;
static EGLDisplay eglDisplay = EGL_NO_DISPLAY;
static const wchar_t* TAG = L"EAGL";

@implementation EAGLContext {
    BOOL _useMultisampling;
    BOOL _multiThreaded;
}
+ (void)initialize {
    if (self == [EAGLContext class]) {
        // setup EGL
        const EGLint defaultDisplayAttributes[] = {
            // These are the default display attributes, used to request ANGLE's D3D11 renderer.
            // eglInitialize will only succeed with these attributes if the hardware supports D3D11 Feature Level 10_0+.
            EGL_PLATFORM_ANGLE_TYPE_ANGLE,
            EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,

            // EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER is an optimization that can have large performance benefits on mobile devices.
            // Its syntax is subject to change, though. Please update from the OpenGLES2 Visual Studio template if you experience
            // compilation issues with it.
            EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER,
            EGL_TRUE,

            // EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE is an option that enables ANGLE to automatically call
            // the IDXGIDevice3::Trim method on behalf of the application when it gets suspended.
            // Calling IDXGIDevice3::Trim when an application is suspended is a Windows Store application certification requirement.
            EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE,
            EGL_TRUE,
            EGL_NONE,
        };

        const EGLint fl9_3DisplayAttributes[] = {
            // These can be used to request ANGLE's D3D11 renderer, with D3D11 Feature Level 9_3.
            // These attributes are used if the call to eglInitialize fails with the default display attributes.
            EGL_PLATFORM_ANGLE_TYPE_ANGLE,
            EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
            EGL_PLATFORM_ANGLE_MAX_VERSION_MAJOR_ANGLE,
            9,
            EGL_PLATFORM_ANGLE_MAX_VERSION_MINOR_ANGLE,
            3,
            EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER,
            EGL_TRUE,
            EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE,
            EGL_TRUE,
            EGL_NONE,
        };

        const EGLint warpDisplayAttributes[] = {
            // These attributes can be used to request D3D11 WARP.
            // They are used if eglInitialize fails with both the default display attributes and the 9_3 display attributes.
            EGL_PLATFORM_ANGLE_TYPE_ANGLE,
            EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
            EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE,
            EGL_PLATFORM_ANGLE_DEVICE_TYPE_WARP_ANGLE,
            EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER,
            EGL_TRUE,
            EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE,
            EGL_TRUE,
            EGL_NONE,
        };

        EGLConfig config = NULL;

        // eglGetPlatformDisplayEXT is an alternative to eglGetDisplay. It allows us to pass in display attributes, used to configure D3D11.
        PFNEGLGETPLATFORMDISPLAYEXTPROC eglGetPlatformDisplayEXT =
            reinterpret_cast<PFNEGLGETPLATFORMDISPLAYEXTPROC>(eglGetProcAddress("eglGetPlatformDisplayEXT"));
        if (!eglGetPlatformDisplayEXT) {
            [NSException raiseWithLogging:@"eglGetPlatformDisplayEXTFailure" format:@"Failed to get function eglGetPlatformDisplayEXT"];
        }

        //
        // To initialize the display, we make three sets of calls to eglGetPlatformDisplayEXT and eglInitialize, with varying
        // parameters passed to eglGetPlatformDisplayEXT:
        // 1) The first calls uses "defaultDisplayAttributes" as a parameter. This corresponds to D3D11 Feature Level 10_0+.
        // 2) If eglInitialize fails for step 1 (e.g. because 10_0+ isn't supported by the default GPU), then we try again
        //    using "fl9_3DisplayAttributes". This corresponds to D3D11 Feature Level 9_3.
        // 3) If eglInitialize fails for step 2 (e.g. because 9_3+ isn't supported by the default GPU), then we try again
        //    using "warpDisplayAttributes".  This corresponds to D3D11 Feature Level 11_0 on WARP, a D3D11 software rasterizer.
        //

        // This tries to initialize EGL to D3D11 Feature Level 10_0+. See above comment for details.
        eglDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, defaultDisplayAttributes);
        if (eglDisplay == EGL_NO_DISPLAY) {
            [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglGetDisplay failed"];
        }

        if (eglInitialize(eglDisplay, NULL, NULL) == EGL_FALSE) {
            // This tries to initialize EGL to D3D11 Feature Level 9_3, if 10_0+ is unavailable (e.g. on some mobile devices).
            eglDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, fl9_3DisplayAttributes);
            if (eglDisplay == EGL_NO_DISPLAY) {
                [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglGetDisplay failed"];
            }

            if (eglInitialize(eglDisplay, NULL, NULL) == EGL_FALSE) {
                // This initializes EGL to D3D11 Feature Level 11_0 on WARP, if 9_3+ is unavailable on the default GPU.
                eglDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, warpDisplayAttributes);
                if (eglDisplay == EGL_NO_DISPLAY) {
                    [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglGetDisplay failed"];
                }

                if (eglInitialize(eglDisplay, NULL, NULL) == EGL_FALSE) {
                    // If all of the calls to eglInitialize returned EGL_FALSE then an error has occurred.
                    [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglInitialize failed"];
                }
            }
        }

        eglBindAPI(EGL_OPENGL_ES_API);
        if (eglGetError() != EGL_SUCCESS) {
            [NSException raiseWithLogging:@"EAGLContextFailure" format:@"eglBindAPI failed code=0x%x", eglGetError()];
        }
    }
}

/**
 @Status Caveat
 @Notes Only GLES 1.1 and 2.0 are supported
*/
- (instancetype)initWithAPI:(NSUInteger)api {
    return [self initWithAPI:api sharegroup:nil];
}

/**
 @Status Caveat
 @Notes Only GLES 1.1 and 2.0 are supported
*/
- (instancetype)initWithAPI:(NSUInteger)api sharegroup:(EAGLContext*)sharegroup {
    if (_initializedVersion != 0) {
        [NSException raiseWithLogging:@"EAGLContextFailure" format:@"EAGLContext already initialized"];
    }
    if (api != 1 && api != 2) {
        [NSException raiseWithLogging:@"EAGLContextFailure" format:@"Only OpenGL ES 1.x and OpenGL ES 2.0 are supported (api=0x%x)", api];
    }

    _useMultisampling = FALSE;
    _multiThreaded = FALSE;

    _eglSurface = EGL_NO_SURFACE;
    _eglContext = EGL_NO_CONTEXT;

    // These basically control the minimum acceptable configuration.
    const EGLint configAttributes[] = { EGL_RENDERABLE_TYPE,
                                        EGL_OPENGL_ES2_BIT,
                                        EGL_SURFACE_TYPE,
                                        EGL_PBUFFER_BIT | EGL_SWAP_BEHAVIOR_PRESERVED_BIT,
                                        EGL_BLUE_SIZE,
                                        5,
                                        EGL_GREEN_SIZE,
                                        6,
                                        EGL_RED_SIZE,
                                        5,
                                        EGL_ALPHA_SIZE,
                                        0,
                                        EGL_DEPTH_SIZE,
                                        16,
                                        EGL_NONE };

    EGLint configCount;
    EGLConfig configList[64];

    _rgb565Supported = false;
    _rgba8888Supported = false;

    if (!eglChooseConfig(eglDisplay, configAttributes, configList, 64, &configCount) || (configCount == 0)) {
        [NSException raiseWithLogging:@"EAGLContextFailure" format:@"Unable to find a valid EGL configuration"];
    }

    for (int i = 0; i < configCount; i++) {
        int redBits, greenBits, blueBits, alphaBits;

        eglGetConfigAttrib(eglDisplay, configList[i], EGL_RED_SIZE, &redBits);
        eglGetConfigAttrib(eglDisplay, configList[i], EGL_GREEN_SIZE, &greenBits);
        eglGetConfigAttrib(eglDisplay, configList[i], EGL_BLUE_SIZE, &blueBits);
        eglGetConfigAttrib(eglDisplay, configList[i], EGL_ALPHA_SIZE, &alphaBits);

        if ((redBits == 5) && (greenBits == 6) && (blueBits == 5) && (alphaBits == 0)) {
            _rgb565Supported = true;
        } else if ((redBits == 8) && (greenBits == 8) && (blueBits == 8) && (alphaBits == 8)) {
            _rgba8888Supported = true;
        }

        if (_rgb565Supported && _rgba8888Supported) {
            break;
        }
    }

    if (!_rgb565Supported && !_rgba8888Supported) {
        [NSException raiseWithLogging:@"EAGLContextFailure" format:@"Unable to find a valid EGL configuration"];
    }

    _mConfig = configList[0];

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

/**
 @Status Interoperable
*/
+ (instancetype)currentContext {
    return tlsCurContext;
}

- (NSUInteger)API {
    return _initializedVersion;
}

/**
 @Status Interoperable
*/
- (instancetype)sharegroup {
    return _sharegroup;
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (BOOL)renderbufferStorage:(int)target fromDrawable:(CAEAGLLayer*)surface {
    auto props = surface.drawableProperties;
    if ([props objectForKey:kEAGLMultisample4X] != nil) {
        _useMultisampling = TRUE;
    } else {
        _useMultisampling = FALSE;
    }

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

    IUnknown* pUnkRaw = (IUnknown*)[surface.swapChainPanel comObj].Get();

    IInspectable* pSwapChainInspectable;
    pUnkRaw->QueryInterface(__uuidof(pSwapChainInspectable), (void**)&pSwapChainInspectable);

    _eglSurface = eglCreateWindowSurface(eglDisplay, _mConfig, pSwapChainInspectable, surface_attribute_list);
    pSwapChainInspectable->Release();

    if (_eglSurface == EGL_NO_SURFACE) {
        return FALSE;
    }

    // Set up swap behavior.
    EGLint swapBehavior = EGL_BUFFER_DESTROYED;
    NSNumber* backingOption = (NSNumber*)[props objectForKey:kEAGLDrawablePropertyRetainedBacking];
    if ((backingOption != nil) && ([backingOption boolValue] == TRUE)) {
        swapBehavior = EGL_BUFFER_PRESERVED;
    }
    if (!eglSurfaceAttrib(eglDisplay, _eglSurface, EGL_SWAP_BEHAVIOR, swapBehavior)) {
        TraceWarning(TAG, L"Unable to set up backbuffer swap behavior, app may experience graphical glitches!");
    }

    // Pick desired format.
    GLenum renderBufferFormat = GL_BGRA8_EXT;
    NSString* formatString = [props objectForKey:kEAGLDrawablePropertyColorFormat];
    if (formatString != nil) {
        if ([formatString isEqualToString:kEAGLColorFormatRGBA8]) {
            renderBufferFormat = GL_BGRA8_EXT;
        } else if ([formatString isEqualToString:kEAGLColorFormatRGB565]) {
            renderBufferFormat = GL_RGB565_OES;
        }
    }

    // Test against reality.  NOTE: One of the two supported bools must be true to even get here.
    if (renderBufferFormat == GL_RGB565_OES && !_rgb565Supported) {
        renderBufferFormat = GL_BGRA8_EXT;
    }
    if (renderBufferFormat == GL_BGRA8_EXT && !_rgba8888Supported) {
        renderBufferFormat = GL_RGB565_OES;
    }

    if (_useMultisampling) {
        glRenderbufferStorageMultisampleANGLE(target, 4, renderBufferFormat, _rbWidth, _rbHeight);
    } else {
        glRenderbufferStorage(target, renderBufferFormat, _rbWidth, _rbHeight);
    }

    auto layerSize = surface.bounds.size;
    surface.swapChainPanel.width = layerSize.width;
    surface.swapChainPanel.height = layerSize.height;

    if (tlsCurContext == self) {
        eglMakeCurrent(eglDisplay, _eglSurface, _eglSurface, _eglContext);
    }

    return TRUE;
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (BOOL)isMultiThreaded {
    return _multiThreaded;
}

/**
 @Status Stub
*/
- (void)setMultiThreaded:(BOOL)multiThreaded {
    UNIMPLEMENTED();
    _multiThreaded = multiThreaded;
}

@end

NSString* const kEAGLColorFormatRGBA8 = (NSString * const) @"kEAGLColorFormatRGBA8";
NSString* const kEAGLColorFormatRGB565 = (NSString * const) @"kEAGLColorFormatRGB565";
NSString* const kEAGLDrawablePropertyColorFormat = (NSString * const) @"kEAGLDrawablePropertyColorFormat";
NSString* const kEAGLDrawablePropertyRetainedBacking = (NSString * const) @"kEAGLDrawablePropertyRetainedBacking";
NSString* const kEAGLMultisample4X = (NSString * const) @"kEAGLMultisample4X";
