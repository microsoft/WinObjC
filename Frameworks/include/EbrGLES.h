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

#include "Starboard.h"

struct ID3D11Device;
struct ID3D11DeviceContext;

extern bool g_bNoSharedTextures;

int EbrGLESInit();

int EbrGLESCreateContext(int shared);
void EbrGLESDestroyContext(int context);
bool EbrGLESCreateDisplayWindow();
int EbrGLESResize(int width, int height);
int EbrGLESSetContext(int newContext);

enum EbrTextureFilter { EbrTextureFilterLinear, EbrTextureFilterNearest };

class EbrFastTexture;
EbrFastTexture* EbrCreateFastTexture(int x,
                                     int y,
                                     int width,
                                     int height,
                                     int sourceStride,
                                     void* data,
                                     surfaceFormat fmt,
                                     EbrTextureFilter minFilter = EbrTextureFilterLinear,
                                     EbrTextureFilter magFilter = EbrTextureFilterLinear);
void* EbrLockFastTexture(EbrFastTexture* buf, int* stride);
void EbrUnlockFastTexture(EbrFastTexture* buf);
int EbrGetFastTextureBindable(EbrFastTexture* buf);

// This returns void* because that's the internal type of EGLImageKHR according to the spec
// but we don't want to include gl deps this high up in the dep tree.
void* EbrFastTextureGetKHR(EbrFastTexture* buf);

void EbrRetainFastTexture(EbrFastTexture* buf);
void EbrReleaseFastTexture(EbrFastTexture* buf);

extern int glRenderContext, glDrawContext;

struct CAPoint3D;
struct CGPoint;

enum TextureMode { TM_DISABLED, TM_ENABLED, TM_FONT };

// These functions are pretty much set up just for NativeUI's rendering needs.
bool EbrGLESInitShaders(ID3D11Device* device);
void EbrGLESDestroyShaders();
void EbrGLESInitDraw();
void EbrGLESSetTexturing(TextureMode mode);
void EbrGLESSetArrays(CAPoint3D* verts, CGPoint* uvs, ColorQuad* colors, float* texNums);
void EbrGLESSet2DArrays(CGPoint* verts, CGPoint* uvs);
void EbrGLESSetColor(float* colorArray); // of size 4
void EbrGLESSetTransform(ID3D11DeviceContext* ctx, float* matrix); // of size 16, row-major.
void EbrGLESGetTransform(float* matrix);

inline void EbrGLESSetColor(float r, float g, float b, float a) {
    float color[4] = { r, g, b, a };
    EbrGLESSetColor(color);
}

struct android_app;
#if defined ANDROID
android_app* GetAndroidApp();
#else
inline android_app* GetAndroidApp() {
    return NULL;
}
#endif
