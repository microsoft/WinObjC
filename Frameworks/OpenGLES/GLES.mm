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
#include <math.h>
#include <vector>

#define GL_GLEXT_PROTOTYPES
#include "EbrOpenglIncludes.h"

#include "Starboard.h"
#include "ContextManager.h"

#include "EbrGLES.h"
#include "Platform/EbrPlatform.h"

#include "Etc.h"
#include "Hash.h"
#include "MurmurHash3.h"
#include "CoreGraphics/CGImage.h"
#include "UIKit/UIImage.h"

#include "GLES1122/OpenGLES20/OpenGLES20Context.h"

#include <malloc.h>

#if defined( WINPHONE )
#undef WIN32
#endif

static void *normalPtr = NULL;
static int curBuf = 0;

static int totalTextures = 0;
static int curTexture;

extern bool g_useKHRRenderbuffers;

inline const GLvoid *BasicRemap(const GLvoid *pointer)
{
#ifdef WIN32
    GLint arrayBinding, elementBinding;

#ifndef BASIC_REMAP
    ANGLE_glGetIntegerv(GL_ARRAY_BUFFER_BINDING,  &arrayBinding);
    ANGLE_glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING,  &elementBinding);
    if ((arrayBinding != 0 || elementBinding != 0) && pointer != NULL )
#else
    if ((DWORD) pointer < 0x20000 )
#endif
        *((DWORD *) &pointer) -= BASE_REMAP;
#endif
    
    return pointer;
}

#ifdef WIN32
typedef  PROC  (WINAPI *tpwglGetProcAddress)(LPCSTR);

tpwglGetProcAddress pwglGetProcAddress;
void *proc_loader(void *h, const char *name)
{
    (void) h;
    PROC ret;
    ret = pwglGetProcAddress(name);

    if (ret == NULL) {
        HMODULE mod = GetModuleHandle("Opengl32.dll");
        ret = GetProcAddress(mod, name);
    }

    if (ret == NULL) {
        EbrDebugLog("Unable to load %s\n", name);
    }

    return ret;
}

void LoadFunc(char *name, void *funcAddr)
{
    *((DWORD *) funcAddr) = (DWORD) proc_loader(NULL, name);
}

#define LOAD_FUNC(x) LoadFunc(#x, (void *) &x)
#endif

DWORD _EAGLGetVersion(int *major, int *minor)
{
    if (major) *major = 2;
    if (minor) *minor = 0;

    return 0;
}

EAGL_EXPORT void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    if (ctxManager.lockContext() == false) return;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    *((*ctx->eaglPriv->_ownedFramebuffers)[(DWORD) ctx->eaglPriv->_curFramebufferBinding]) = texture;

    ANGLE_glFramebufferTexture2D(target, attachment, textarget,  texture, level);    

    int rc = glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glFramebufferTexture2DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    return glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

EAGL_EXPORT void glDiscardFramebufferEXT(GLenum target, GLsizei numAttachments, const GLenum *attachments)
{
    EbrDebugLog("glDiscardFramebufferEXT not supported\n");
}

EAGL_EXPORT void glGenFramebuffers(GLsizei n, GLuint* framebuffers)
{
    if (ctxManager.lockContext() == false) return;

    ANGLE_glGenFramebuffers(n, framebuffers);    
    EAGLContext *ctx = ctxManager.getEAGLContext();
    for (int i = 0; i < n; i ++) {
        ctx->eaglPriv->_ownedFramebuffers->insert((DWORD) framebuffers[i], (DWORD) 0);
    }

    int rc = glCheckError();

    ctxManager.unlockContext();

    return;
}

EAGL_EXPORT void glGenFramebuffersOES(GLsizei n, GLuint* framebuffers)
{
    glGenFramebuffers(n, framebuffers);
}

EAGL_EXPORT void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers)
{
    if (ctxManager.lockContext() == false) return;

    ANGLE_glGenRenderbuffers(n, renderbuffers);
    
    ctxManager.unlockContext();
}

EAGL_EXPORT void glGenRenderbuffersOES(GLsizei n, GLuint* renderbuffers)
{
    glGenRenderbuffers(n, renderbuffers);
}

EAGL_EXPORT void glDeleteFramebuffers(GLsizei n, GLuint* framebuffers)
{
    if (ctxManager.lockContext() == false) return;

    ANGLE_glDeleteFramebuffers(n, framebuffers);
    EAGLContext *ctx = ctxManager.getEAGLContext();
    for (int i = 0; i < n; i ++) {
        ctx->eaglPriv->_ownedFramebuffers->remove((DWORD) framebuffers[i]);
    }

    ctxManager.unlockContext();
}

EAGL_EXPORT void glDeleteFramebuffersOES(GLsizei n, GLuint* framebuffers)
{
    glDeleteFramebuffers(n, framebuffers);
}

EAGL_EXPORT void glDeleteRenderbuffers(GLsizei n, GLuint* framebuffers)
{
    if (ctxManager.lockContext() == false) return;

    ANGLE_glDeleteRenderbuffers(n, framebuffers);
    
    ctxManager.unlockContext();
}

EAGL_EXPORT void glDeleteRenderbuffersOES(GLsizei n, GLuint* framebuffers)
{
    glDeleteRenderbuffers(n, framebuffers);
}

EAGL_EXPORT void glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
    if (ctxManager.lockContext() == false) return;

    ctxManager.getEAGLContext()->eaglPriv->_curRenderbufferBinding = renderbuffer;
    ANGLE_glBindRenderbuffer(target, renderbuffer);
    
    int rc = glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glBindRenderbufferOES(GLenum target, GLuint renderbuffer)
{
    glBindRenderbuffer(target, renderbuffer);
}

EAGL_EXPORT void glBindFramebuffer(GLenum target, GLuint framebuffer)
{
    if (ctxManager.lockContext() == false) return;
    
    ctxManager.getEAGLContext()->eaglPriv->_curFramebufferBinding = framebuffer;
    ANGLE_glBindFramebuffer(target, framebuffer);

    int rc = glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glBindFramebufferOES(GLenum target, GLuint framebuffer)
{
    return glBindFramebuffer(target, framebuffer);
}

EAGL_EXPORT void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params)
{
    if (ctxManager.lockContext() == false) return;

    ANGLE_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);

    int rc = glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    if (ctxManager.lockContext() == false) return;

    ANGLE_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);

    int rc = glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glFramebufferRenderbufferOES(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    return glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

EAGL_EXPORT void glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    if (ctxManager.lockContext() == false) return;

    ANGLE_glRenderbufferStorage(target, internalformat, width, height);
    
    int rc = glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glRenderbufferStorageOES (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    return glRenderbufferStorage(target, internalformat, width, height);
}

#define GL_RENDERBUFFER_WIDTH_OES                               0x8D42
#define GL_RENDERBUFFER_HEIGHT_OES                              0x8D43
#define GL_FRAMEBUFFER_COMPLETE_OES                             0x8CD5
#define     GL_RENDERBUFFER_RED_SIZE_EXT   0x8D50
#define     GL_RENDERBUFFER_GREEN_SIZE_EXT   0x8D51
#define     GL_RENDERBUFFER_BLUE_SIZE_EXT   0x8D52
#define     GL_RENDERBUFFER_ALPHA_SIZE_EXT   0x8D53

#define     GL_RENDERBUFFER_DEPTH_SIZE_EXT   0x8D54
#define     GL_RENDERBUFFER_STENCIL_SIZE_EXT   0x8D55

#define     GL_RENDERBUFFER_INTERNAL_FORMAT_EXT   0x8D44

EAGL_EXPORT void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params)
{
    if (ctxManager.lockContext() == false) return;

    //  Retrieve the current drawing layer
    CAEAGLLayer *drawLayer = (CAEAGLLayer *) (id) ((EAGLContext*)tlsCurContext->curEAGLContext)->eaglPriv->presentationLayer;

    ANGLE_glGetRenderbufferParameteriv(target, pname, params);
    
    glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glGetRenderbufferParameterivOES(GLenum target, GLenum pname, GLint* params)
{
     glGetRenderbufferParameteriv(target, pname, params);
}

EAGL_EXPORT DWORD glCheckFramebufferStatus(GLenum target)
{
    if (ctxManager.lockContext() == false) return 0;

    GLenum ret = ANGLE_glCheckFramebufferStatus(target);
    ctxManager.unlockContext();

    return ret;
}

EAGL_EXPORT DWORD glCheckFramebufferStatusOES(GLenum target)
{
    return glCheckFramebufferStatus(target);
}

EAGL_EXPORT DWORD glBindBuffer(GLenum target, GLuint buffer)
{
    if (ctxManager.lockContext() == false) return 0;

    if (target == GL_ARRAY_BUFFER) curBuf = buffer;
    ANGLE_glBindBuffer(target, buffer);

    int rc = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glViewport(x, y, width, height);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glClearColor(float red, float green, float blue, float alpha)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glClearColor(red, green, blue, alpha);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glEnable(GLenum cap)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    if ( !ctx->eaglPriv->_gl11Ctx ) {
        ANGLE_glEnable(cap);
    } else {
        if ( cap != GL_FOG ) {
            ctx->eaglPriv->_gl11Ctx->glEnable(cap);
        }
    }

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glDisable(GLenum cap)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    if ( !ctx->eaglPriv->_gl11Ctx ) {
        ANGLE_glDisable(cap);
    } else {
        ctx->eaglPriv->_gl11Ctx->glDisable(cap);
    }

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT const GLubyte *glGetString(GLenum name)
{
    if (ctxManager.lockContext() == false) return 0;

    const GLubyte *ret = ANGLE_glGetString(name);

    int err = glCheckError();

    if (name == GL_EXTENSIONS) {
        if (ret) {
            static char *added;
            
            if (!added) {
                added = (char *) EbrMalloc(strlen((char *) ret) + 1024);

                sprintf(added, 
                        "%s GL_EXT_texture_filter_anisotropic GL_EXT_texture_lod_bias GL_IMG_read_format GL_IMG_texture_compression_pvrtc "
                        "GL_IMG_texture_format_BGRA8888 GL_OES_blend_subtract GL_OES_compressed_paletted_texture GL_OES_depth24 GL_OES_draw_texture "
                        "GL_OES_framebuffer_object GL_OES_mapbuffer GL_OES_matrix_palette GL_OES_point_size_array GL_OES_point_sprite GL_OES_read_format "
                        "GL_OES_rgb8_rgba8 GL_OES_texture_mirrored_repeat\r\n", ret);
            }
            ret = (const GLubyte *) added;

            EbrDebugLog("%s\n", ret);
        } else {
            ret = (const GLubyte *) "GL_EXT_texture_filter_anisotropic GL_EXT_texture_lod_bias GL_IMG_read_format GL_IMG_texture_compression_pvrtc "
        "GL_IMG_texture_format_BGRA8888 GL_OES_blend_subtract GL_OES_compressed_paletted_texture GL_OES_depth24 GL_OES_draw_texture "
        "GL_OES_framebuffer_object GL_OES_mapbuffer GL_OES_matrix_palette GL_OES_point_size_array GL_OES_point_sprite GL_OES_read_format "
        "GL_OES_rgb8_rgba8 GL_OES_texture_mirrored_repeat\r\n";
        }
    }

    ctxManager.unlockContext();

    return ret;
}

EAGL_EXPORT DWORD glActiveTexture(GLenum texture)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    if ( !ctx->eaglPriv->_gl11Ctx ) {
        ANGLE_glActiveTexture(texture);
    } else {
        ctx->eaglPriv->_gl11Ctx->glActiveTexture(texture);
    }

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glMatrixMode(GLenum mode)
{
    if (ctxManager.lockContext() == false) return 0;
    EAGLContext *ctx = ctxManager.getEAGLContext();

    ctx->eaglPriv->_gl11Ctx->glMatrixMode(mode);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glLoadIdentity()
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();

    ctx->eaglPriv->_gl11Ctx->glLoadIdentity();

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glFrustumf(float left, float right, float bottom, float top, float zNear, float zFar)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();

    ctx->eaglPriv->_gl11Ctx->glFrustumf(left, right, bottom, top, zNear, zFar);
    
    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glMultMatrixf(const GLfloat *m)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();

    ctx->eaglPriv->_gl11Ctx->glMultMatrixf(m);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glTranslatef (float x, float y, float z)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glTranslatef(x, y, z);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glRotatef (float angle, float x, float y, float z)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glRotatef(angle, x, y, z);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glScalef(float x, float y, float z)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glScalef(x, y, z);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT void glMaterialf(GLenum face, GLenum pname, GLfloat param)
{
    if (ctxManager.lockContext() == false) return;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glMaterialf(face, pname, param);

    glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params)
{
    if (ctxManager.lockContext() == false) return;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glMaterialfv(face, pname, params);

    glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glMaterialx(GLenum face, GLenum pname, GLfixed param)
{
    if (ctxManager.lockContext() == false) return;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glMaterialx(face, pname, param);

    glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT void glMaterialxv(GLenum face, GLenum pname, const GLfixed *params)
{
    if (ctxManager.lockContext() == false) return;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glMaterialxv(face, pname, params);

    glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT DWORD glOrthof(float left, float right, float bottom, float top, float zNear, float zFar)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glOrthof(left, right, bottom, top, zNear, zFar);
    
    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glPushMatrix()
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glPushMatrix();

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glPopMatrix()
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glPopMatrix();

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glEnableClientState(GLenum cap)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glEnableClientState(cap);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glDisableClientState(GLenum cap)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glDisableClientState(cap);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

float *vertexPtr;
float *texPointer;

EAGL_EXPORT DWORD glVertexPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    threadGLContext *curThreadCtx = tlsCurContext;
    if (!curThreadCtx) {
        EbrDebugLog("No GL context!\n");
        return 0;
    }
    EAGLContext* curCtx = curThreadCtx->curEAGLContext;
    int contextHandle = curCtx->eaglPriv->contextHandle;

    if (ctxManager.lockContext() == false) return 0;

    pointer = BasicRemap(pointer);
    
    vertexPtr = (float *) pointer;
    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glVertexPointer(size, type, stride, pointer);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glTexCoordPointer (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    threadGLContext *curThreadCtx = tlsCurContext;
    if (!curThreadCtx) {
        EbrDebugLog("No GL context!\n");
        return 0;
    }
    EAGLContext* curCtx = curThreadCtx->curEAGLContext;
    int contextHandle = curCtx->eaglPriv->contextHandle;

    if (ctxManager.lockContext() == false) return 0;

    pointer = BasicRemap(pointer);
    
    texPointer = (float *) pointer;
    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glTexCoordPointer(size, type, stride, pointer);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    if (ctxManager.lockContext() == false) return 0;

    pointer = BasicRemap(pointer);
    EAGLContext *ctx = ctxManager.getEAGLContext();

    ctx->eaglPriv->_gl11Ctx->glColorPointer(size, type, stride, pointer);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
    if (ctxManager.lockContext() == false) return 0;

    pointer = BasicRemap(pointer);

    normalPtr = (void *) pointer;
    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glNormalPointer(type, stride, pointer);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}


EAGL_EXPORT DWORD glTexEnvf(GLenum target, GLenum pname, float param)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glTexEnvf(target, pname, param);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glTexEnvi(GLenum target, GLenum pname, GLint param)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glTexEnvi(target, pname, param);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glColor4f(float r, float g, float b, float a)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glColor4f(r, g, b, a);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glColor4ub(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glColor4ub(r, g, b, a);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT void glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer)
{
    if (ctxManager.lockContext() == false) return;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glPointSizePointerOES(type, stride, pointer);

    int ret = glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT DWORD glPointSize(float size)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glPointSize(size);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glShadeModel(DWORD model)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glShadeModel(model);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glLightf(DWORD light, DWORD name, float param)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glLightf(light, name, param);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glLightfv(DWORD light, DWORD name, GLfloat *params)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glLightfv(light, name, params);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glClientActiveTexture(GLenum texture)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glClientActiveTexture(texture);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glAlphaFunc(GLenum func, float ref)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glAlphaFunc(func, ref);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glLoadMatrixf(const GLfloat * m)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glLoadMatrixf(m);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glFogfv(GLenum pname, const GLfloat * params)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    //ctx->eaglPriv->_gl11Ctx->glFogfv(pname, params);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glFogf(GLenum pname, float param)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    //ctx->eaglPriv->_gl11Ctx->glFogf(pname, param);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glFogx(GLenum pname, GLfixed param)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    //ctx->eaglPriv->_gl11Ctx->glFogx(pname, param);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glNormal3f(float nx, float ny, float nz)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    ctx->eaglPriv->_gl11Ctx->glNormal3f(nx, ny, nz);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glDepthFunc(DWORD func)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glDepthFunc(func);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glStencilFunc(func, ref, mask);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glStencilOp(fail, zfail, zpass);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glDepthRangef(float znear, float zfar)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glDepthRangef(znear, zfar);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glClearDepthf(float depth)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glClearDepthf(depth);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glStencilMask(GLuint mask)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glStencilMask(mask);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glClearStencil(GLint s)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glClearStencil(s);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glGenTextures(GLsizei n, GLuint *textures)
{
    if (ctxManager.lockContext() == false) return 0;

	ANGLE_glGenTextures(n, textures);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glDeleteTextures(GLsizei n, GLuint *textures)
{
    if (ctxManager.lockContext() == false) return 0;

    if (!textures) return 0;
    ANGLE_glDeleteTextures(n, textures);

    int ret = glCheckError();
    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glBindTexture(GLenum target, GLuint texture)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    if ( !ctx || !ctx->eaglPriv->_gl11Ctx ) {
        ANGLE_glBindTexture(target, texture);
    } else {
        ctx->eaglPriv->_gl11Ctx->glBindTexture(target, texture);
    }
    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glCullFace (GLenum mode)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glCullFace(mode);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glClear (GLbitfield mask)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glClear(mask);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glIsTexture (GLuint tex)
{
    if (ctxManager.lockContext() == false) return 0;

    int ret = ANGLE_glIsTexture(tex);

    ctxManager.unlockContext();

    return ret;
}

EAGL_EXPORT DWORD glIsRenderbufferOES (GLuint buffer)
{
    if (ctxManager.lockContext() == false) return 0;

#ifdef WIN32
    ANGLE_glboolean (WINAPI *glIsRenderbuffer)(GLuint buffer);
    LOAD_FUNC(glIsRenderbuffer);
    DWORD ret = ANGLE_glIsRenderbuffer(buffer);
#else
    assert(0);
    DWORD ret = 0;
#endif

    ctxManager.unlockContext();

    return ret;
}

EAGL_EXPORT DWORD glIsBuffer (GLuint buf)
{
    if (ctxManager.lockContext() == false) return 0;

    int ret = ANGLE_glIsBuffer(buf);

    ctxManager.unlockContext();

    return ret;
}

int totalTextureSize;

EAGL_EXPORT DWORD glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
    if (ctxManager.lockContext() == false) return 0;

    totalTextureSize += width * height * 4;

#ifdef NO_TEX2D_ON_SHARED
    EAGLContext *ctx = ctxManager.getEAGLContext();
    if (ctx->_sharegroup != nil) {
        GLint curTex;
        ANGLE_glGetIntegerv(GL_TEXTURE_BINDING_2D, &curTex);
        ctxManager.setContext(ctx->_sharegroup);
        GLint oldTex;
        ANGLE_glGetIntegerv(GL_TEXTURE_BINDING_2D, &oldTex);
        ANGLE_glBindTexture(GL_TEXTURE_2D, curTex);
        ANGLE_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
        ANGLE_glBindTexture(GL_TEXTURE_2D, oldTex);
        ctxManager.setContext(ctx);
        ctxManager.unlockContext();

        return 0;
    }
#else
    EAGLContext *ctx = ctxManager.getEAGLContext();
#endif

#ifndef WIN32
    if (format == GL_BGRA_EXT && internalformat != GL_BGRA_EXT) {
        EbrDebugLog("Warning: Forcing internal format to GL_BGRA\n");
        internalformat = GL_BGRA_EXT;
    }
#endif
    if ( !ctx->eaglPriv->_gl11Ctx ) {
        ANGLE_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
    } else {
        ctx->eaglPriv->_gl11Ctx->glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
    }
    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT void glCompressedTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *pixels)
{
    if (!pixels) {
        EbrDebugLog("NULL passed to glCompressedTexImage2D\n");
        return;
    }

    if (ctxManager.lockContext() == false) return;

    ANGLE_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, pixels);
    
    int ret = glCheckError();

    ctxManager.unlockContext();
}

EAGL_EXPORT DWORD glDrawTexiOES (GLint x, GLint y, GLint z, GLint width, GLint height)
{
    EbrDebugLog("glDrawTexi not supported\n");

    return 0;
}

EAGL_EXPORT void *glMapBufferOES (GLenum target, GLenum access)
{   
    EbrDebugLog("glMapBufferOES not supported\n");
    assert(0);  //  Must return valid pointer

    return 0;
}

EAGL_EXPORT GLboolean glUnmapBufferOES (GLenum target)
{   
    EbrDebugLog("glUnmapBufferOES not supported\n");
    assert(0);  //  Must return valid pointer

    return 0;
}

EAGL_EXPORT DWORD glDrawArrays (GLenum mode, GLint first, GLsizei count)
{   
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    if ( !ctx->eaglPriv->_gl11Ctx ) {
        ANGLE_glDrawArrays(mode, first, count);
    } else {
        ctx->eaglPriv->_gl11Ctx->glDrawArrays(mode, first, count);
    }

    ANGLE_glDrawArrays(mode, first, count);
    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glDrawElements (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{   
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    if ( !ctx->eaglPriv->_gl11Ctx ) {
        ANGLE_glDrawElements(mode, count, type, indices);
    } else {
        ctx->eaglPriv->_gl11Ctx->glDrawElements(mode, count, type, indices);
    }

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glGetIntegerv(GLenum pname, GLint *params)
{
    if (ctxManager.lockContext() == false) return 0;

    if (!params) {
        EbrDebugLog("glGetIntegerv: params = NULL!\n");
        return 0;
    }

    static GLint extraTextures[] = {
        0x8c01,
        0x8c03,
        0x8c00,
        0x8c02,
        0x8d64
    };

    if (pname == GL_TEXTURE_BINDING_2D) {
        GLint curTex;

        ANGLE_glGetIntegerv(pname, &curTex);
        if (curTex != 0) {
            *params = curTex;
        } else {
            *params = 0;
        }
    } else if (pname == GL_NUM_COMPRESSED_TEXTURE_FORMATS) {
        ANGLE_glGetIntegerv(pname, params);
#ifdef WIN32
        (*params) += sizeof(extraTextures) / sizeof(GLint);
#endif
    } else if (pname == GL_COMPRESSED_TEXTURE_FORMATS ){
        GLint num = 0;
        ANGLE_glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &num);

        ANGLE_glGetIntegerv(pname, params);

#ifdef WIN32
        for (int i = 0; i < sizeof(extraTextures) / sizeof(GLint); i ++) {
            params[num ++] = extraTextures[i];
        }
#endif
#ifdef USE_KHR_RENDERBUFFERS
    } else if (pname == GL_RENDERBUFFER_BINDING_OES && g_useKHRRenderbuffers ) {
        *params = ctxManager.getEAGLContext()->eaglPriv->_curRenderbufferBinding;
    } else if (pname == GL_FRAMEBUFFER_BINDING_OES && g_useKHRRenderbuffers ) {
        *params = ctxManager.getEAGLContext()->eaglPriv->_curFramebufferBinding;
#endif
    } else if (pname == 0x8D57) {   //  GL_MAX_SAMPLES
        *params = 0;
    } else {
        ANGLE_glGetIntegerv(pname, params);
    }

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glGetBooleanv(GLenum pname, GLboolean *params)
{
    if (ctxManager.lockContext() == false) return 0;

    if (!params) {
        EbrDebugLog("glGetBooleanv: params = NULL!\n");
        return 0;
    }

    ANGLE_glGetBooleanv(pname, params);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glGetFloatv(GLenum pname, GLfloat *params)
{
    if (ctxManager.lockContext() == false) return 0;

    EAGLContext *ctx = ctxManager.getEAGLContext();
    if ( !ctx->eaglPriv->_gl11Ctx ) {
        ANGLE_glGetFloatv(pname, params);
    } else {
        ctx->eaglPriv->_gl11Ctx->glGetFloatv(pname, params);
    }

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glScissor(x, y, width, height);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glBlendFunc(GLenum sfactor, GLenum dfactor)
{
    if (ctxManager.lockContext() == false) return 0;

    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ANGLE_glBlendFunc(sfactor, dfactor);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glBlendFuncSeparateOES(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha)
{
    if (ctxManager.lockContext() == false) return 0;

#ifdef WIN32
    assert(0);
#else
    typedef void (*GLBLENDFUNCSEPARATEOES)(int srcRGB, int dstRGB, int srcAlpha, int dstAlpha);
    LOADOES(GLBLENDFUNCSEPARATEOES, glBlendFuncSeparateOES);
    glBlendFuncSeparateOES(srcRGB, dstRGB, srcAlpha, dstAlpha);
#endif
    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glBlendEquation(GLenum mode)
{
    if (ctxManager.lockContext() == false) return 0;

#ifdef WIN32
    void (WINAPI *glBlendEquation)(GLenum mode);
    LOAD_FUNC(glBlendEquation);
    ANGLE_glBlendEquation(mode);
#else
#if USE_GLES
    ANGLE_glBlendEquation(mode);
#endif
#endif

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glTexParameterf(GLenum target, GLenum pname, float param)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glTexParameterf(target, pname, param);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glTexParameteri(GLenum target, GLenum pname, GLint param)
{
    if (ctxManager.lockContext() == false) return 0;

    if (param == GL_LINEAR_MIPMAP_LINEAR) {
        param = GL_LINEAR;
        EbrDebugLog("Forcing GL_LINEAR_MIPMAP_LINEAR TO GL_LINEAR");
    }
    ANGLE_glTexParameteri(target, pname, param);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glTexParameteriv(target, pname, params);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glGetTexParameteriv(GLenum target, GLenum pname, GLint* params)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetTexParameteriv(target, pname, params);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glColorMask(red, green, blue, alpha);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glFrontFace(GLenum mode)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glFrontFace(mode);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glHint(GLenum target, GLenum mode)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glHint(target, mode);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glFinish()
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glFinish();

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glLineWidth(float width)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glLineWidth(width);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glDepthMask(GLboolean flag)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glDepthMask(flag);

    int ret = glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glGetError()
{
    if (ctxManager.lockContext() == false) return 0;

    int ret = ANGLE_glGetError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glIsEnabled(GLenum cap)
{
    if (ctxManager.lockContext() == false) return 0;

    int ret = ANGLE_glIsEnabled(cap);

    glCheckError();

    ctxManager.unlockContext();

    return ret;
}

EAGL_EXPORT DWORD glFlush()
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glFlush();

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glPixelStorei(GLenum pname, GLint param)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glPixelStorei(pname, param);

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glGenBuffers(GLsizei n, GLuint *buffers)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGenBuffers(n, buffers);

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glDeleteBuffers(GLsizei n, GLuint *buffers)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glDeleteBuffers(n, buffers);

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glBufferData(target, size, data, usage);

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glBufferSubData(target, offset, size, data);

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glBlendEquationOES(GLenum type)
{
    if (ctxManager.lockContext() == false) return 0;

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glReadPixels(x, y, width, height, format, type, pixels);

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glPolygonOffset(float factor, float units)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glPolygonOffset(factor, units);

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glGenerateMipmapOES(GLenum target)
{
    if (ctxManager.lockContext() == false) return 0;

#ifdef WIN32
    void (WINAPI *glGenerateMipmapEXT)(GLenum target);
    LOAD_FUNC(glGenerateMipmapEXT);
    ANGLE_glGenerateMipmapEXT(target);
#else
    //LOADOES(PFNGLGENERATEMIPMAPOESPROC, glGenerateMipmapOES);

    //glGenerateMipmapOES(target);
#endif

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);

    glCheckError();

    ctxManager.unlockContext();

    return 0;
}

EAGL_EXPORT DWORD glAttachShader(GLuint program, GLuint shader)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glAttachShader(program, shader);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glBindAttribLocation(GLuint program, GLuint index, const GLchar* name)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glBindAttribLocation(program, index, name);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glBlendColor(float red, float green, float blue, float alpha)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glBlendColor(red, green, blue, alpha);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glBlendEquationSeparate(modeRGB, modeAlpha);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glCompileShader(GLuint shader)
{
    if (ctxManager.lockContext() == false) return 0;

#if !defined( WINPHONE )
    ANGLE_glCompileShader(shader);
    
    GLint success = 0;
    ANGLE_glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        /* apparently this doesn't work on Android.
           GLint errLen = 0;
           ANGLE_glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errLen); */

        char buf[4096];
        buf[0] = 0;
        ANGLE_glGetShaderInfoLog(shader, sizeof(buf), NULL, buf);
        EbrDebugLog("User shader compile failure: %s\n", buf);
    }
#endif
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glCreateProgram()
{
    if (ctxManager.lockContext() == false) return 0;

    DWORD res = ANGLE_glCreateProgram();
    glCheckError();
    
    ctxManager.unlockContext();
    return res;
}

EAGL_EXPORT DWORD glCreateShader(GLenum type)
{
    if (ctxManager.lockContext() == false) return 0;

    DWORD res = ANGLE_glCreateShader(type);
    glCheckError();
    
    ctxManager.unlockContext();
    return res;
}

EAGL_EXPORT DWORD glDeleteProgram(GLuint program)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glDeleteProgram(program);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glDeleteShader(GLuint shader)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glDeleteShader(shader);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glDetachShader(GLuint program, GLuint shader)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glDetachShader(program, shader);
    glCheckError();

    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glDisableVertexAttribArray(GLuint index)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glDisableVertexAttribArray(index);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glEnableVertexAttribArray(GLuint index)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glEnableVertexAttribArray(index);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGenerateMipmap(GLenum target)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGenerateMipmap(target);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length,
                         GLint *size, GLenum *type, GLchar *name)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetActiveAttrib(program, index, bufsize, length, size, type, name);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length,
                          GLint *size, GLenum *type, GLchar *name)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetActiveUniform(program, index, bufsize, length, size, type, name);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei *count, GLuint *shaders)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetAttachedShaders(program, maxcount, count, shaders);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetAttribLocation(GLuint program, const GLchar *name)
{
    if (ctxManager.lockContext() == false) return 0;

    DWORD res = (DWORD)ANGLE_glGetAttribLocation(program, name);
    glCheckError();
    
    ctxManager.unlockContext();
    return res;
}

EAGL_EXPORT DWORD glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetBufferParameteriv(target, pname, params);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetProgramiv(program, pname, params);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei *length, GLchar *infolog)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetProgramInfoLog(program, bufsize, length, infolog);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
    if (ctxManager.lockContext() == false) return 0;

#if defined( WINPHONE )
    if ( pname == GL_LINK_STATUS || pname == GL_COMPILE_STATUS ) {
        *params = 1;

        ctxManager.unlockContext();
        return 0;
    }
#endif
    ANGLE_glGetShaderiv(shader, pname, params);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *infolog)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetShaderInfoLog(shader, bufsize, length, infolog);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range,
                                  GLint *precision)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *source)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetShaderSource(shader, bufsize, length, source);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetTexParameterfv(target, pname, params);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetUniformfv(GLuint program, GLint location, GLfloat *params)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetUniformfv(program, location, params);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetUniformiv(GLuint program, GLint location, GLint *params)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetUniformiv(program, location, params);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetUniformLocation(GLuint program, const GLchar *name)
{
    if (ctxManager.lockContext() == false) return 0;

    DWORD res = ANGLE_glGetUniformLocation(program, name);
    glCheckError();
    
    ctxManager.unlockContext();
    return res;
}

EAGL_EXPORT DWORD glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetVertexAttribfv(index, pname, params);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetVertexAttribiv(index, pname, params);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid **pointer)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glGetVertexAttribPointerv(index, pname, pointer); 
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glIsFramebuffer(GLuint framebuffer)
{
    if (ctxManager.lockContext() == false) return 0;

    DWORD res = (DWORD)ANGLE_glIsFramebuffer(framebuffer);
    glCheckError();
    
    ctxManager.unlockContext();
    return res;
}

EAGL_EXPORT DWORD glIsProgram(GLuint program)
{
    if (ctxManager.lockContext() == false) return 0;

    DWORD res = (DWORD)ANGLE_glIsProgram(program);
    glCheckError();
    
    ctxManager.unlockContext();
    return res;
}

EAGL_EXPORT DWORD glIsRenderbuffer(GLuint renderbuffer)
{
    if (ctxManager.lockContext() == false) return 0;

    DWORD res = (DWORD)ANGLE_glIsRenderbuffer(renderbuffer);
    glCheckError();
    
    ctxManager.unlockContext();
    return res;
}

EAGL_EXPORT DWORD glIsShader(GLuint shader)
{
    if (ctxManager.lockContext() == false) return 0;

    DWORD res = (DWORD)ANGLE_glIsShader(shader);
    glCheckError();
    
    ctxManager.unlockContext();
    return res;
}

class PrecompiledPrograms
{
    class PrecompiledProgram
    {
    public:
        char *shaderSrc;
        int shaderSrcLen;

        char *fragmentSrc;
        int fragmentSrcLen;

        void *programBin;
        int         programBinLen;

        PrecompiledProgram(const unsigned char *shader, int shaderLen,
            const unsigned char *fragment, int fragmentLen,
            const unsigned char *program, int programLen)
        {
            shaderSrc = (char *) malloc(shaderLen);
            memcpy(shaderSrc, shader, shaderLen);
            shaderSrcLen = shaderLen;

            fragmentSrc = (char *) malloc(fragmentLen);
            memcpy(fragmentSrc, fragment, fragmentLen);
            fragmentSrcLen = fragmentLen;

            programBin = (void *) malloc(programLen);
            memcpy(programBin, program, programLen);
            programBinLen = programLen;
        }
    };
    std::vector<PrecompiledProgram *> _programs;

public:
    PrecompiledPrograms()
    {
    }

    void AddPrecompiledProgram(unsigned char *vertexShaderSrc, int vertexShaderSrcLen,
        unsigned char *fragmentShaderSrc, int fragmentShaderSrcLen,
        unsigned char *programBinary, int programBinaryLen)
    {
        _programs.push_back(new PrecompiledProgram(vertexShaderSrc, vertexShaderSrcLen, fragmentShaderSrc, fragmentShaderSrcLen,
            programBinary, programBinaryLen));
    }

    void findAndLoadProgram(GLuint program)
    {
        GLuint shaders[255];
        GLsizei count = 0;
        ANGLE_glGetAttachedShaders(program, 255, &count, shaders);
    
        GLsizei vertexLen = 0;
        GLchar vertexSource[65536];

        GLsizei fragmentLen = 0;
        GLchar fragmentSource[65536];

        assert(count == 2);

        int i;
        for ( i = 0; i < count; i ++ ) {
            GLint type;
            ANGLE_glGetShaderiv(shaders[i], GL_SHADER_TYPE, &type);

            switch ( type ) {
                case GL_VERTEX_SHADER:
                    assert(vertexLen == 0);
                    ANGLE_glGetShaderSource(shaders[i], 65536, &vertexLen, vertexSource);
                    break;

                case GL_FRAGMENT_SHADER:
                    assert(fragmentLen == 0);
                    ANGLE_glGetShaderSource(shaders[i], 65536, &fragmentLen, fragmentSource);
                    break;

                default:
                    assert(0);
                    break;
            }
        }

        PrecompiledProgram *useShader = NULL;

        for ( i = 0; i < _programs.size(); i ++ ) {
            PrecompiledProgram *cur = _programs[i];

            if ( cur->shaderSrcLen == vertexLen &&
                 cur->fragmentSrcLen == fragmentLen &&
                 memcmp(cur->shaderSrc, vertexSource, vertexLen) == 0 &&
                 memcmp(cur->fragmentSrc, fragmentSource, fragmentLen) == 0 ) {
                useShader = cur;
                break;
            }
        }

        if ( useShader ) {
            glProgramBinaryOES(program, GL_PROGRAM_BINARY_ANGLE, useShader->programBin, useShader->programBinLen);
        } else {
            fatal_printf("Unknown shader vert=%d frag=%d\n", vertexLen, fragmentLen);
            char szTmp[255];
            static int cnt = 0;
            sprintf(szTmp, "/Documents/shader%d.vert", cnt);
            EbrFile *fpOut = EbrFopen(szTmp, "wb");
            EbrFwrite(vertexSource, 1, vertexLen, fpOut);
            EbrFclose(fpOut);
            sprintf(szTmp, "/Documents/shader%d.frag", cnt);
                fpOut = EbrFopen(szTmp, "wb");
            EbrFwrite(fragmentSource, 1, fragmentLen, fpOut);
            EbrFclose(fpOut);
            //assert(0);

            cnt++;

            unsigned char *vSrc = (unsigned char *)malloc(vertexLen);
            memcpy(vSrc, vertexSource, vertexLen);
            unsigned char *fSrc = (unsigned char *)malloc(fragmentLen);
            memcpy(fSrc, fragmentSource, fragmentLen);
            _programs.push_back(new PrecompiledProgram((const unsigned char *)vSrc, vertexLen, 
                (const unsigned char *)fSrc, fragmentLen,
                (const unsigned char *) _programs[0]->programBin, _programs[0]->programBinLen));
            glProgramBinaryOES(program, GL_PROGRAM_BINARY_ANGLE, _programs[0]->programBin, _programs[0]->programBinLen);
        }
    }
};

PrecompiledPrograms _precompiledPrograms;

#define SAR_MAGIC   "SAR10\0\0\0"
#define SAR_SHADER  'sENT'

typedef struct
{
    unsigned int type;
    unsigned int vertexShaderLen;
    unsigned int pixelShaderLen;
    unsigned int binaryShaderLen;
    /*
    unsigned char vertexShaderSrc[vertexShaderLen];
    unsigned char pixelShaderSrc[pixelShaderLen];
    unsigned char binaryShaderSrc[binaryShaderLen];
    */
} CompiledShader;

typedef struct
{
    unsigned char magic[8];
    /*
    CompiledShader Shaders[];
    */
} SARchive;

void EbrLoadSAR(const char *path)
{
    EbrFile *fpIn = EbrFopen(path, "rb");
    if (!fpIn) {
        assert(0);
        return;
    }

    SARchive header = { 0 };
    EbrFread(&header, 1, sizeof(header), fpIn);
    if (memcmp(header.magic, SAR_MAGIC, sizeof(header.magic)) != 0)
    {
        assert(0);
        return;
    }

    while (!EbrFeof(fpIn)) {
        CompiledShader shaderHdr = { 0 };
        EbrFread(&shaderHdr, 1, sizeof(CompiledShader), fpIn);
        if (EbrFeof(fpIn)) break;
        if (shaderHdr.type != SAR_SHADER) {
            assert(0);
            return;
        }

        unsigned char *vertexSrc = (unsigned char *)malloc(shaderHdr.vertexShaderLen);
        unsigned char *pixelSrc = (unsigned char *)malloc(shaderHdr.pixelShaderLen);
        unsigned char *binary = (unsigned char *)malloc(shaderHdr.binaryShaderLen);

        EbrFread(vertexSrc, 1, shaderHdr.vertexShaderLen, fpIn);
        EbrFread(pixelSrc, 1, shaderHdr.pixelShaderLen, fpIn);
        EbrFread(binary, 1, shaderHdr.binaryShaderLen, fpIn);

        _precompiledPrograms.AddPrecompiledProgram(vertexSrc, shaderHdr.vertexShaderLen,
            pixelSrc, shaderHdr.pixelShaderLen,
            binary, shaderHdr.binaryShaderLen);
        free(vertexSrc);
        free(pixelSrc);
        free(binary);
    }

    EbrFclose(fpIn);
}

EAGL_EXPORT DWORD glLinkProgram(GLuint program)
{
    if (ctxManager.lockContext() == false) return 0;

#if defined( WINPHONE )
    _precompiledPrograms.findAndLoadProgram(program);
#else
    ANGLE_glLinkProgram(program);
    glCheckError();
#endif
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glReleaseShaderCompiler(void)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glReleaseShaderCompiler();
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glSampleCoverage(float value, GLboolean invert)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glSampleCoverage(value, invert);
    glCheckError();

    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glShaderBinary(GLsizei n, const GLuint *shaders, GLenum binaryformat,
                      const GLvoid* binary, GLsizei length)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glShaderBinary(n, shaders, binaryformat, binary, length);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glShaderSource(GLuint shader, GLsizei count, const GLchar **strings, const GLint *length)
{
    if (ctxManager.lockContext() == false) return 0;

    const GLchar **adjustedStrings = (const GLchar **)alloca(count * sizeof(const GLchar **));
    for (GLsizei i = 0; i < count; i++) {
        adjustedStrings[i] = (const GLchar *)strings[i];
    }
    
    ANGLE_glShaderSource(shader, count, adjustedStrings, length);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glStencilFuncSeparate(face, func, ref, mask);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glStencilMaskSeparate(GLenum face, GLuint mask)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glStencilMaskSeparate(face, mask);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glStencilOpSeparate(face, fail, zfail, zpass);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform1f(GLint location, float x)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform1f(location, x);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform1fv(GLint location, GLsizei count, const GLfloat *v)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform1fv(location, count, v);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform1i(GLint location, GLint x)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform1i(location, x);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform1iv(GLint location, GLsizei count, const GLint *v)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform1iv(location, count, v);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform2f(GLint location, float x, float y)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform2f(location, x, y);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform2fv(GLint location, GLsizei count, const GLfloat *v)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform2fv(location, count, v);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform2i(GLint location, GLint x, GLint y)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform2i(location, x, y);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform2iv(GLint location, GLsizei count, const GLint *v)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform2iv(location, count, v);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform3f(GLint location, float x, float y, float z)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform3f(location, x, y, z);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform3fv(GLint location, GLsizei count, const GLfloat *v)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform3fv(location, count, v);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform3i(GLint location, GLint x, GLint y, GLint z)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform3i(location, x, y, z);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform3iv(GLint location, GLsizei count, const GLint *v)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform3iv(location, count, v);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform4f(GLint location, float x, float y, float z, float w)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform4f(location, x, y, z, w);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform4fv(GLint location, GLsizei count, const GLfloat *v)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform4fv(location, count, v);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform4i(location, x, y, z, w);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniform4iv(GLint location, GLsizei count, const GLint *v)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniform4iv(location, count, v);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose,
                          const GLfloat *value)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniformMatrix2fv(location, count, transpose, value);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose,
                          const GLfloat *value)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniformMatrix3fv(location, count, transpose, value);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose,
                          const GLfloat *value)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUniformMatrix4fv(location, count, transpose, value);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glUseProgram(GLuint program)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glUseProgram(program);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glValidateProgram(GLuint program)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glValidateProgram(program);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glVertexAttrib1f(GLuint indx, float x)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glVertexAttrib1f(indx, x);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glVertexAttrib1fv(GLuint indx, const GLfloat *values)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glVertexAttrib1fv(indx, values);
    glCheckError();

    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glVertexAttrib2f(GLuint indx, float x, float y)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glVertexAttrib2f(indx, x, y);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glVertexAttrib2fv(GLuint indx, const GLfloat *values)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glVertexAttrib2fv(indx, values);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glVertexAttrib3f(GLuint indx, float x, float y, float z)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glVertexAttrib3f(indx, x, y, z);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glVertexAttrib3fv(GLuint indx, const GLfloat *values)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glVertexAttrib3fv(indx, values);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glVertexAttrib4f(GLuint indx, float x, float y, float z, float w)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glVertexAttrib4f(indx, x, y, z, w);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT DWORD glVertexAttrib4fv(GLuint indx, const GLfloat *values)
{
    if (ctxManager.lockContext() == false) return 0;

    ANGLE_glVertexAttrib4fv(indx, values);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

// The last arg is deliberately ArgTypeWord because it's sometimes an offset into a buffer,
// otherwise an actual pointer.
EAGL_EXPORT DWORD glVertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized,
                             GLsizei stride, const GLvoid* ptr)
{
    if (ctxManager.lockContext() == false) return 0;

    if (curBuf == NULL) ptr = ptr;
    ANGLE_glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
    glCheckError();
    
    ctxManager.unlockContext();
    return 0;
}

EAGL_EXPORT void glResolveMultisampleFramebufferAPPLE (void)
{
}

EAGL_EXPORT void glRenderbufferStorageMultisampleAPPLE (GLenum, GLsizei, GLenum, GLsizei, GLsizei)
{
}
