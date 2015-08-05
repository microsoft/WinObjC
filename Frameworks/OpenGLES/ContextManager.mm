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
#include "EbrOpenglIncludes.h"

#include "EbrGLES.h"
#include "Platform/EbrPlatform.h"

#include "ContextManager.h"

#include "QuartzCore/CALayer.h"
#include "QuartzCore/CAEAGLLayer.h"
#include "Foundation/NSRunLoop.h"
#include "Etc.h"
#include "CACompositor.h"
#include <d3d11_1.h>

#include "GLES1122/OpenGLES20/OpenGLES20Context.h"

__declspec(thread) threadGLContext *tlsCurContext;

ContextManager  ctxManager;

pthread_t       global_currentOwner;
EbrLock         global_contextLock = EBRLOCK_INITIALIZE;

extern bool g_useKHRRenderbuffers;
extern EbrComPtr<ID3D11Device1> m_AngleD3dDevice;
extern EbrComPtr<ID3D11DeviceContext1> m_AngleD3dContext;

void LoadFunc(char *name, void *funcAddr); // TODO: hack.
#define LOAD_FUNC(x) LoadFunc(#x, (void *) &x)

void lockGlobalContext()
{
    EbrLockEnter(global_contextLock);
}

void unlockGlobalContext()
{
    EbrDebugLog("Unlocking global context\n");
    EbrLockLeave(global_contextLock);
}

DWORD ContextManager::emuTexToGL(DWORD emuTex)
{
    return emuTex;
}

DWORD ContextManager::glTexToEmu(DWORD glTex)
{
    return glTex;
}

DWORD ContextManager::genTexture()
{
    GLuint tex;
    ANGLE_glGenTextures(1, &tex);
    return tex;
}

void ContextManager::removeTexture(DWORD emuTex)
{
    return;
}

EAGLContext *ContextManager::getEAGLContext()
{
    threadGLContext *curThreadCtx = tlsCurContext;

    return (EAGLContext *) curThreadCtx->curEAGLContext;
}

bool ContextManager::lockContext()
{
    if ( tlsCurContext == NULL ) {
        EbrDebugLog("No GL context!\n");
        return false;
    }

    GetCACompositor()->LockD3DDisplayTexture(getEAGLContext()->eaglPriv->_drawingOutputTexture);
    return true;
}

void ContextManager::unlockContext()
{
    return;
}

void ContextManager::setContext(id newCtx, bool doRef)
{
    threadGLContext *curThreadCtx = tlsCurContext;
    EAGLContext* curCtx = curThreadCtx->curEAGLContext;
    EAGLContext* ctx = newCtx;

    if ( curCtx == ctx ) return;

    if ( doRef ) [newCtx retain];

    if ( curCtx != 0 ) {
        EbrGLESSetContext(0);
        curThreadCtx->curEAGLContext = nil;
        if ( doRef ) [curCtx release];
    }

    if ( ctx == 0 ) {
        curThreadCtx->curEAGLContext = nil;
        return;
    } else {
        EbrGLESSetContext(ctx->eaglPriv->contextHandle);
        curThreadCtx->curEAGLContext = ctx;
    }
}

#define GL_BGRA_EXT 0x80E1

extern int curDeviceOrientation;

@implementation EAGLContext : NSObject {
    bool _gles11EmulationMode;
}
    -(instancetype) initWithAPI:(NSUInteger)api {
        if ( api != 2 ) {
            EbrDebugLog("Using GLES 1.1 emulation\n");
            _gles11EmulationMode = true;
        } else {
            EbrDebugLog("Creating GLES 2 context\n");
        }
        if ( api == 2 && _gles11EmulationMode == true ) {
            return nil;
        }
        eaglPriv = (EAGLContextPrivateData *) calloc(1, sizeof(EAGLContextPrivateData));

        if ( g_bNoSharedTextures ) {
            lockGlobalContext();
        }
        eaglPriv->contextHandle = EbrGLESCreateContext(0);
        if ( g_bNoSharedTextures ) {
            unlockGlobalContext();
        }

        eaglPriv->_ownedFramebuffers = new HashMap<DWORD, DWORD>();
        EbrLockInit(&eaglPriv->contextLock);

        if ( _gles11EmulationMode ) {
            id oldCtx = [EAGLContext currentContext];
            [EAGLContext setCurrentContext:self];
            eaglPriv->_gl11Ctx = new OpenGLES::OpenGLES2::OpenGLES20Context();
            [EAGLContext setCurrentContext:oldCtx];
        }
        return self;
    }

    -(instancetype) initWithAPI:(NSUInteger)api sharegroup:(EAGLContext*)sharegroup {
        if ( api != 1 ) {
            EbrDebugLog("initWithAPI: Only opengl es 1.1 is supported\n");
            return nil;
        }

        eaglPriv = (EAGLContextPrivateData *) calloc(1, sizeof(EAGLContextPrivateData));

        eaglPriv->contextHandle = EbrGLESCreateContext(sharegroup->eaglPriv->contextHandle);

        EbrLockInit(&eaglPriv->contextLock);

        eaglPriv->_ownedFramebuffers = new HashMap<DWORD, DWORD>();
        eaglPriv->_sharegroup = sharegroup;

        return self;
    }

    +(instancetype) currentContext {
        threadGLContext *curCtx = tlsCurContext;
        if ( !curCtx ) return 0;

        return curCtx->curEAGLContext;
    }

    -(NSUInteger) API {
        return 2;
    }

    -(instancetype) sharegroup {
        return self;
    }

    +(BOOL) setCurrentContext:(EAGLContext*)context {
        EAGLContext* ctx = context;
        if ( ctx != nil && ctx->eaglPriv->sharedContext != nil ) context = ctx->eaglPriv->sharedContext;

        threadGLContext *curCtx = tlsCurContext;
        if ( !curCtx ) {
            curCtx = new threadGLContext();
            memset(curCtx, 0, sizeof(threadGLContext));
            tlsCurContext = curCtx;
        }

        ctxManager.setContext(context);

        return TRUE;
    }

#define GL_FRAMEBUFFER_EXT 0x8D40 
#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_RENDERBUFFER_EXT 0x8D41
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_FRAMEBUFFER_OES                                      0x8D40
#define GL_COLOR_ATTACHMENT0_OES                                0x8CE0

    static DWORD nextPow2(DWORD v)
    {
        return 1 << log2Ceil(v);
    }

    -(BOOL) renderbufferStorage:(int)target fromDrawable:(CAEAGLLayer*)surface {
        CAEAGLLayer* drawableSurface = surface;
        GLint oldName;

        if ( drawableSurface == nil ) {
            EbrDebugLog("No surface!\n");
            return FALSE;
        }

        id format = [[drawableSurface drawableProperties] objectForKey:@"kEAGLDrawablePropertyColorFormat"];
        eaglPriv->_rbWidth = (int)[drawableSurface _pixelWidth];
        eaglPriv->_rbHeight = (int)[drawableSurface _pixelHeight];

        if ( eaglPriv->_rbWidth == 0 || eaglPriv->_rbHeight == 0 ) {
            eaglPriv->_rbWidth = 320;
            eaglPriv->_rbHeight = 480;
        }

        ctxManager.lockContext();

        ANGLE_glRenderbufferStorage(target, GL_BGRA8_EXT, eaglPriv->_rbWidth, eaglPriv->_rbHeight);
        glCheckError();
        void *ptr = NULL;
        
        glGetRenderbufferStorageNATIVE(&ptr);
        eaglPriv->presentationLayer = drawableSurface;
        eaglPriv->_drawingOutputTexture = GetCACompositor()->GetDisplayTextureForD3D(m_AngleD3dDevice.Get(), m_AngleD3dContext.Get(), (ID3D11Texture2D *) ptr, eaglPriv->_rbWidth, eaglPriv->_rbHeight);

        [eaglPriv->presentationLayer _setDisplayTexture:eaglPriv->_drawingOutputTexture];

        eaglPriv->_opaque = [drawableSurface opaque] ? true : false;
        if ( [format isEqual:@"kEAGLColorFormatRGBA8"] || format == nil ) eaglPriv->_opaque = false;

        ctxManager.unlockContext();
        
        return TRUE;
    }

    -(BOOL) presentRenderbuffer:(int)target {
        bool isMainThread;
        id mainRunLoop = [NSRunLoop mainRunLoop];
        id currentRunLoop = [NSRunLoop currentRunLoop];
        if ( mainRunLoop != currentRunLoop ) {
            isMainThread = false;
        } else {
            isMainThread = true;
        }

        if (eaglPriv->presentationLayer == nil) {
            return FALSE;
        }

        EbrSignalsSafe();
        ctxManager.lockContext();

        glCheckError();
        GLint oldName;

        //glClearColor(1.0f, 0, 0, 1);

        glReleaseTargets();

        ctxManager.unlockContext();
        GetCACompositor()->UnlockD3DDisplayTexture(eaglPriv->_drawingOutputTexture);
        EbrSignalsUnsafe();

        return TRUE;
    }

    -(void) dealloc {
        threadGLContext *curCtx = tlsCurContext;

        if ( curCtx ) {
            ctxManager.lockContext();
            ctxManager.setContext(self, false);
#if 0
            size_t it = -1;

            while ( _ownedFramebuffers->nextHandle(it, it) ) {
                DWORD frameBufferId = _ownedFramebuffers->keyAtHandle(it);
                /*
                DWORD &textureBindId = _ownedFramebuffers->valueAtHandle(it);

                if ( textureBindId != 0 ) {
                    void (WINAPI *glFramebufferTexture2DEXT)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
                    LOAD_FUNC(glFramebufferTexture2DEXT);
                    glFramebufferTexture2DEXT(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_TEXTURE_2D,  0, 0);
                    glCheckError();
                    glDeleteTextures(1, (GLuint *) &textureBindId);
                    glCheckError();
                }
                */
                void (WINAPI *glBindFramebufferEXT)(GLenum, GLuint);
                LOAD_FUNC(glBindFramebufferEXT);
                //glBindFramebufferEXT(GL_FRAMEBUFFER_OES, 0);
                //glCheckError();
                void (WINAPI *glDeleteFramebuffersEXT)(GLsizei n, GLuint *framebuffers);
                LOAD_FUNC(glDeleteFramebuffersEXT);
                glDeleteFramebuffersEXT(1, (GLuint *) &frameBufferId);
                glCheckError();
            }
#endif

#ifdef ANDROID
typedef EGLSyncKHR (EGLAPIENTRYP _PFNEGLCREATESYNCKHRPROC) (EGLDisplay dpy, EGLenum type, const EGLint *attrib_list);
typedef EGLBoolean (EGLAPIENTRYP _PFNEGLDESTROYSYNCKHRPROC) (EGLDisplay dpy, EGLSyncKHR sync);
typedef EGLint (EGLAPIENTRYP _PFNEGLCLIENTWAITSYNCKHRPROC) (EGLDisplay dpy, EGLSyncKHR sync, EGLint flags, EGLTimeKHR timeout);

            EGLSyncKHR sync;
            EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

            LOADOES(_PFNEGLCREATESYNCKHRPROC, _eglCreateSyncKHR);
            LOADOES(_PFNEGLCLIENTWAITSYNCKHRPROC, _eglClientWaitSyncKHR);
            LOADOES(_PFNEGLDESTROYSYNCKHRPROC, _eglDestroySyncKHR);

            sync = _eglCreateSyncKHR(display, EGL_SYNC_FENCE_KHR, NULL);
            _eglClientWaitSyncKHR(display, sync, EGL_SYNC_FLUSH_COMMANDS_BIT_KHR, EGL_FOREVER_KHR);
            _eglDestroySyncKHR(display, sync);
#endif

            EbrGLESDestroyContext(eaglPriv->contextHandle);

            if ( curCtx->curEAGLContext != self ) {
                ctxManager.setContext(curCtx->curEAGLContext, false);
            } else {
                ctxManager.setContext(nil, false);
            }
            ctxManager.unlockContext();
        }
        delete eaglPriv->_ownedFramebuffers;
        if ( eaglPriv ) free(eaglPriv);

        [super dealloc];
    }
@end

NSString * const kEAGLColorFormatRGBA8 = (NSString * const) @"kEAGLColorFormatRGBA8";
NSString * const kEAGLColorFormatRGB565 = (NSString * const) @"kEAGLColorFormatRGB565";
NSString * const kEAGLDrawablePropertyColorFormat = (NSString * const) @"kEAGLDrawablePropertyColorFormat";
NSString * const kEAGLDrawablePropertyRetainedBacking = (NSString * const) @"kEAGLDrawablePropertyRetainedBacking";
