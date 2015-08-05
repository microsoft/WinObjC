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

#include "Platform\EbrDirectX.h"

class Shader;

enum EbrShader {
    ES_SOLID,
    ES_TEXTURED,
    ES_TEXCOLOR,
    ES_FONT,
    ES_FONT_SDF,

    ES_NONE
};

/* Not currently used -- it's much easier to use a single vertex type, and
   we're not vertex rate bound anyway.
   
struct PositionColorVertex
{
    float x, y;
#if NATIVEUI_3D
    float z;
#endif 
    float r, g, b, a;
};

struct PositionTexCoordVertex
{
    float x, y;
#if NATIVEUI_3D
    float z;
#endif 
    float u, v;
};
*/

struct PositionTexColorVertex
{
    float x, y;
#if NATIVEUI_3D
    float z;
#endif 
    float u, v;
    float r, g, b, a;
};

struct ID3D11Device;

bool EbrShaderInit(ID3D11Device *device);
bool EbrShaderDestroy();

void EbrShaderNewFrame();

Shader *EbrShaderGet(EbrShader shader);
