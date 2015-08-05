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

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#if USE_GL
#include "EbrOpenglIncludes.h"
#endif

#include "Starboard.h"

#include "EbrGLES.h"
#include "ShadersList.h"
#include "EbrShaderLib.h"

static CATransform3D curTransform;
static bool         _transformChanged;

static Shader *curShader = NULL;
static TextureMode texMode = TM_DISABLED;
 
bool EbrGLESInitShaders(ID3D11Device* device)
{
    EbrShaderInit(device);
    
    Shader::initShaders(device);
    return true;
}
 
void EbrGLESDestroyShaders()
{
    Shader::destroyShaders();
    EbrShaderDestroy();
}
 
void EbrGLESInitDraw()
{
#if USE_GL
    glEnableVertexAttribArray(POSITION_ATTRIBUTE_NUM);
    glEnableVertexAttribArray(COLOR_ATTRIBUTE_NUM);
    glEnableVertexAttribArray(TEXCOORD_ATTRIBUTE_NUM);
    
    glDisable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glColorMask(1, 1, 1, 1);        
#endif
}

void EbrGLESSetTexturing(TextureMode mode)
{
    texMode = mode;

    //curShader = EbrShaderSetActive(ES_COMBINED);
}

void EbrGLESSetArrays(CAPoint3D *verts, CGPoint *uvs, ColorQuad *colors, float *texNums)
{
#if USE_GL
    glEnableVertexAttribArray(POSITION_ATTRIBUTE_NUM);
    glEnableVertexAttribArray(TEXCOORD_ATTRIBUTE_NUM);
    glEnableVertexAttribArray(COLOR_ATTRIBUTE_NUM);
    glEnableVertexAttribArray(TEXNUM_ATTRIBUTE_NUM);
    glVertexAttribPointer(POSITION_ATTRIBUTE_NUM, 3, GL_FLOAT, GL_FALSE, 0, verts);
    glVertexAttribPointer(TEXCOORD_ATTRIBUTE_NUM, 2, GL_FLOAT, GL_FALSE, 0, uvs);
    glVertexAttribPointer(COLOR_ATTRIBUTE_NUM, 4, GL_FLOAT, GL_FALSE, 0, colors);
    glVertexAttribPointer(TEXNUM_ATTRIBUTE_NUM, 1, GL_FLOAT, GL_FALSE, 0, texNums);
#else
    assert(!"This function not supported on Direct3D!");
#endif
}

void EbrGLESSet2DArrays(CGPoint *verts, CGPoint *uvs)
{
#if USE_GL
    glVertexAttribPointer(POSITION_ATTRIBUTE_NUM, 2, GL_FLOAT, GL_FALSE, 0, verts);
    glVertexAttribPointer(TEXCOORD_ATTRIBUTE_NUM, 2, GL_FLOAT, GL_FALSE, 0, uvs);   
#endif
}

static void TransposeFrom(CATransform3D *fromMatrix, const float *matrix)
{
    fromMatrix->m11 = matrix[0];
    fromMatrix->m12 = matrix[4];
    fromMatrix->m13 = matrix[8];
    fromMatrix->m14 = matrix[12];
    fromMatrix->m21 = matrix[1];
    fromMatrix->m22 = matrix[5];
    fromMatrix->m23 = matrix[9];
    fromMatrix->m24 = matrix[13];
    fromMatrix->m31 = matrix[2];
    fromMatrix->m32 = matrix[6];
    fromMatrix->m33 = matrix[10];
    fromMatrix->m34 = matrix[14];
    fromMatrix->m41 = matrix[3];
    fromMatrix->m42 = matrix[7];
    fromMatrix->m43 = matrix[11];
    fromMatrix->m44 = matrix[15];
}

void EbrGLESSetTransform(ID3D11DeviceContext *ctx, float *matrix)
{
    TransposeFrom(&curTransform, matrix);
    _transformChanged = true;

    Shader::setMatrix(ctx, &curTransform.m11);
}

