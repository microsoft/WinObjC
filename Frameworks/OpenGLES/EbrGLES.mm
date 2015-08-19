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

#include <pthread.h>
#include <process.h>
#include <time.h>

#include "EGL/egl.h"
#include "EGL/eglext.h"
#include "EGL/eglplatform.h"
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"

#include "winrtangle.h"
#include "Starboard.h"

#include "QuartzCore/CALayer.h"

#include "CoreGraphics/CGContext.h"
#include "UIKit/UIDevice.h"
#include "Foundation/NSString.h"
#include "UIKit/UIApplication.h"
#include "Foundation/NSString.h"

#include "EbrGLES.h"
#include "Platform/EbrPlatform.h"
#include "EbrOpenglIncludes.h"

#include <process.h>

bool g_bNoSharedTextures = false;
bool g_useKHRRenderbuffers = true;

static EGLDisplay eglDisplay = NULL;
EbrComPtr<ID3D11Device1> m_AngleD3dDevice;
EbrComPtr<ID3D11DeviceContext1> m_AngleD3dContext;

typedef struct {
    int used;
    EGLContext glCtx;
    EGLSurface glSurface;
    EGLDisplay glDisplay;
} EbrGLContext;

#define EBR_MAX_CONTEXTS    128
EbrGLContext contexts[128];

static int getFreeContext()
{
    for ( int i = 0; i < EBR_MAX_CONTEXTS; i ++ ) {
        if ( EbrCompareExchange((volatile int *) &contexts[i].used, 1, 0) == 0 ) {
            return i;
        }
    }

    EbrDebugLog("Out of contexts!\n");
    assert(0);
    *((char *) 0) = 0;
    return -1;
}

void ThrowIfFailed(HRESULT hr)
{
    if ( hr != S_OK ) {
        assert(0);
    }
}

void InitializeAngleDevice();

int EbrGLESSetContext(int newContext)
{
    int good;

    if ( newContext != 0 ) {
        //EbrDebugLog("Thread %x taking control of context %d\n", pthread_self(), newContext);
        //fflush(stdout);

        int i = 0;
        for ( i = 0; i < 10; i ++ ) {
            good = eglMakeCurrent(contexts[newContext - 1].glDisplay,
                                  contexts[newContext - 1].glSurface,
                                  contexts[newContext - 1].glSurface,
                                  contexts[newContext - 1].glCtx);
            if ( good ) break;

            EbrDebugLog("*** FAILED, retrying ****\n");
            fflush(stdout);
            assert(0);
        }
    } else {
        //EbrDebugLog("Thread %x releasing\n", pthread_self());
        //fflush(stdout);
        good = eglMakeCurrent(eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        EbrDebugLog("good = %d\n", good);
    }
    return 0;
}

static const EGLint createContextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };

int EbrGLESCreateContext(int shareCtx)
{
    InitializeAngleDevice();

    const EGLint attribs[] = {
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
            EGL_BLUE_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_RED_SIZE, 8,
            EGL_ALPHA_SIZE, 8,
            EGL_DEPTH_SIZE, 24,
            EGL_STENCIL_SIZE, 8,
            EGL_NONE
    };
    EGLint numConfigs;
    EGLConfig config;
    int contextNum = getFreeContext();

    /* Here, the application chooses the configuration it desires. In this
     * sample, we have a very simplified selection process, where we pick
     * the first EGLConfig that matches our criteria */
    if (!eglChooseConfig(eglDisplay, attribs, &config, 1, &numConfigs)) {
        EbrDebugLog("WARNING: eglChooseConfig failed!\n");
    } else {
        int depthBufferSize = -1;
        eglGetConfigAttrib(eglDisplay, config, EGL_DEPTH_SIZE, &depthBufferSize);
        EbrDebugLog("Depth buffer size: %d bits\n", depthBufferSize);
    }

    EGLContext eglCtx = 0;

    eglCtx = eglCreateContext(eglDisplay, config, shareCtx == 0 ? EGL_NO_CONTEXT : contexts[shareCtx - 1].glCtx, createContextAttribs);

    contexts[contextNum].glCtx = eglCtx;
    contexts[contextNum].glDisplay = eglDisplay;

    static int count = 0;
    count ++;
    if ( eglCtx == EGL_NO_CONTEXT ) {
        EbrDebugLog("%x\n", eglGetError());
        EbrDebugLog("%d\n", count);
        assert(0);
    }

    EGLint attribute_list[] = {
            EGL_WIDTH, 32,
            EGL_HEIGHT, 32,
            EGL_NONE

    };
    EGLSurface surf = eglCreatePbufferSurface(eglDisplay, config, attribute_list);

    assert(surf != EGL_NO_SURFACE);
    contexts[contextNum].glSurface = surf;

    return contextNum + 1;
}

void EbrGLESDestroyContext(int contextNum)
{
    return;
}

class EbrFastTexture
{
public:
    void *khr;
    GLuint texNum;
};

EGLImageKHR EbrFastTextureGetKHR(EbrFastTexture *buf)
{
    return (EGLImageKHR) buf->khr;
}

void EbrRetainFastTexture(EbrFastTexture *buf)
{
}

void EbrReleaseFastTexture(EbrFastTexture *buf)
{
}

int EbrGetFastTextureBindable(EbrFastTexture *buf)
{
    return buf->texNum;
}

void *EbrLockFastTexture(EbrFastTexture *buf, int *stride)
{
    return NULL;
}

void EbrUnlockFastTexture(EbrFastTexture *buf)
{
}


void EbrSignalsSafe()
{
}

void EbrSignalsUnsafe()
{
}

static D3D_FEATURE_LEVEL m_featureLevel;
static EbrComPtr<IWinPhone8XamlD3DWindow> m_eglPhoneWindow;
static EbrComPtr<IWinrtEglWindow> m_eglWindow;

// These are the resources that depend on the device.
void InitializeAngleDevice()
{
    static bool initialized = false;
    if ( initialized ) return;

    initialized = true;

    // This flag adds support for surfaces with a different color channel ordering
    // than the API default. It is required for compatibility with Direct2D.
    UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

#if defined(_DEBUG)
    // If the project is in a debug build, enable debugging via SDK Layers with this flag.
    //creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    // This array defines the set of DirectX hardware feature levels this app will support.
    // Note the ordering should be preserved.
    // Don't forget to declare your application's minimum required feature level in its
    // description.  All applications are assumed to support 9.3 unless otherwise stated.
    D3D_FEATURE_LEVEL featureLevels[] = 
    {
        D3D_FEATURE_LEVEL_9_3
    };

    // Create the Direct3D 11 API device object and a corresponding context.
    EbrComPtr<ID3D11Device> device;
    EbrComPtr<ID3D11DeviceContext> context;
    ThrowIfFailed(
        D3D11CreateDevice(
            NULL, // Specify nullptr to use the default adapter.
            D3D_DRIVER_TYPE_HARDWARE,
            NULL,
            creationFlags, // Set set debug and Direct2D compatibility flags.
            featureLevels, // List of feature levels this app can support.
            ARRAYSIZE(featureLevels),
            D3D11_SDK_VERSION, // Always set this to D3D11_SDK_VERSION.
            device.GetAddressOf(), // Returns the Direct3D device created.
            &m_featureLevel, // Returns feature level of device created.
            context.GetAddressOf() // Returns the device immediate context.
            )
        );

    // Get the Direct3D 11.1 API device and context interfaces.
    ThrowIfFailed(
        device.As(&m_AngleD3dDevice)
        );

    ThrowIfFailed(
        context.As(&m_AngleD3dContext)
        );

    // setup EGL
    EGLint majorVersion;
    EGLint minorVersion;

    // we need to select the correct DirectX feature level depending on the platform
    // default is D3D_FEATURE_LEVEL_9_3 Windows Phone 8.0
    ANGLE_D3D_FEATURE_LEVEL featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_3;

    switch(m_featureLevel)
    {
    case ANGLE_D3D_FEATURE_LEVEL_9_3:
        featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_3;
        break;
                
    case ANGLE_D3D_FEATURE_LEVEL_9_2:
        featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_2;
        break;
                    
    case ANGLE_D3D_FEATURE_LEVEL_9_1:
        featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_1;
        break;
    }       

    eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if(eglDisplay == EGL_NO_DISPLAY){
        return;
    }

    if(!eglInitialize(eglDisplay, &majorVersion, &minorVersion)){
        return;
    }
}
