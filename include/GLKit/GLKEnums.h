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

enum _GLKLightingType {
    GLKLightingTypePerVertex = 0,
    GLKLightingTypePerPixel
};
typedef unsigned int GLKLightingType;

enum _GLKFogMode {
    GLKFogModeExp = 0,
    GLKFogModeExp2,
    GLKFogModeLinear
};
typedef unsigned int GLKFogMode;

enum _GLKTextureEnvMode {
    GLKTextureEnvModeReplace = 0,
    GLKTextureEnvModeModulate,
    GLKTextureEnvModeDecal,
    GLKTextureEnvModeAdditive,
    GLKTextureEnvModeSubtractive
};
typedef unsigned int GLKTextureEnvMode;

enum _GLKTextureTarget {
    GLKTextureTarget2D = GL_TEXTURE_2D,
    GLKTextureTargetCubeMap = GL_TEXTURE_CUBE_MAP,
    GLKTextureTargetCt = 2
};
typedef unsigned int GLKTextureTarget;

enum _GLKVertexAttrib {
    GLKVertexAttribPosition = 0,
    GLKVertexAttribNormal,
    GLKVertexAttribColor,
    GLKVertexAttribTexCoord0,
    GLKVertexAttribTexCoord1
};
typedef unsigned int GLKVertexAttrib;

enum _GLKTextureInfoAlphaState {
    GLKTextureInfoAlphaStateNone = 0,
    GLKTextureInfoAlphaStateNonPremultiplied = 1,
    GLKTextureInfoAlphaStatePremultiplied = 2
};
typedef GLuint GLKTextureInfoAlphaState;

enum _GLKTextureInfoOrigin {
    GLKTextureInfoOriginUnknown = 0,
    GLKTextureInfoOriginTopLeft = 1,
    GLKTextureInfoOriginBottomLeft = 2,
};
typedef GLuint GLKTextureInfoOrigin;

enum _GLKViewDrawableColorFormat {
    GLKViewDrawableColorFormatRGBA8888 = 0,
    GLKViewDrawableColorFormatRGB565,
    GLKViewDrawableColorFormatSRGBA8888,
    GLKViewDrawableColorFormatWindow
};
typedef GLuint GLKViewDrawableColorFormat;

enum _GLKViewDrawableDepthFormat {
    GLKViewDrawableDepthFormatNone = 0,
    GLKViewDrawableDepthFormat16,
    GLKViewDrawableDepthFormat24
};
typedef GLuint GLKViewDrawableDepthFormat;

enum _GLKViewDrawableStencilFormat {
    GLKViewDrawableStencilFormatNone = 0,
    GLKViewDrawableStencilFormat8
};
typedef GLuint GLKViewDrawableStencilFormat;

