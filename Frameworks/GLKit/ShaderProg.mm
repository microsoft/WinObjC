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

#import <Starboard.h>
#import <GLKit/GLKShaderDefs.h>

#include "ShaderGen.h"
#include "ShaderProg.h"

#define GL_INPUT_POS "gl_Position"

#define COLOR_WHITE "vec4(1, 1, 1, 1)"
#define COLOR_BLACK "vec4(0, 0, 0, 1)"

#define TO_LIGHT0_TMP "toLight0"
#define TO_LIGHT1_TMP "toLight1"
#define TO_LIGHT2_TMP "toLight2"

#define TO_CAM_TMP "toCam"

#define ATTEN_LIGHT0_TMP "attenLight0"
#define ATTEN_LIGHT1_TMP "attenLight1"
#define ATTEN_LIGHT2_TMP "attenLight2"

ShaderNode* mklighter(const string& toLightTemp, const string& attenTemp, const string& pos,
                      const string& clr, const string& attenName)
{
    ShaderNode* toLight = new ShaderTempRef(GLKS_FLOAT4, toLightTemp, new ShaderOp(new ShaderVarRef(pos), new ShaderVarRef(GLKSH_POS_NAME), "-", true, true));
    ShaderNode* atten = new ShaderTempRef(GLKS_FLOAT, attenTemp, new ShaderAttenuator(toLight, new ShaderVarRef(attenName)));
  
    return new ShaderLighter(toLight, new ShaderVarRef(GLKSH_NORMAL_NAME), new ShaderVarRef(clr), atten);
}

ShaderNode* mkspeclighter(const string& toLightTemp, const string& attenTemp, const string& pos,
                          const string& clr, const string& attenName)
{
    // These two nodes will reuse the temps created in mklighter above.
    ShaderNode* toLight = new ShaderTempRef(GLKS_FLOAT4, toLightTemp, new ShaderOp(new ShaderVarRef(pos), new ShaderVarRef(GLKSH_POS_NAME), "-", true, true));
    ShaderNode* atten = new ShaderTempRef(GLKS_FLOAT, attenTemp, new ShaderAttenuator(toLight, new ShaderVarRef(attenName)));

    // This gets reused across the 3 active lights.
    ShaderNode* toCam = new ShaderTempRef(GLKS_FLOAT4, TO_CAM_TMP, new ShaderOp(new ShaderVarRef(GLKSH_CAMERA), new ShaderVarRef(GLKSH_POS_NAME), "-", true, true));
    return new ShaderSpecLighter(toLight, toCam, new ShaderVarRef(GLKSH_NORMAL_NAME), new ShaderVarRef(clr), atten);
}

// Per-vertex lighting.

static auto diffuseLighter =
    new ShaderOp(
        new ShaderAdditiveCombiner({
            mklighter(TO_LIGHT0_TMP, ATTEN_LIGHT0_TMP, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_COLOR, GLKSH_LIGHT0_ATTEN),
            mklighter(TO_LIGHT1_TMP, ATTEN_LIGHT1_TMP, GLKSH_LIGHT1_POS, GLKSH_LIGHT1_COLOR, GLKSH_LIGHT1_ATTEN),
            mklighter(TO_LIGHT2_TMP, ATTEN_LIGHT2_TMP, GLKSH_LIGHT2_POS, GLKSH_LIGHT2_COLOR, GLKSH_LIGHT2_ATTEN)}),
      new ShaderVarRef(GLKSH_EMISSIVE), "max", false);

static auto specularLighter =
    new ShaderAdditiveCombiner({
        mkspeclighter(TO_LIGHT0_TMP, ATTEN_LIGHT0_TMP, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_SPECULAR, GLKSH_LIGHT0_ATTEN),
        mkspeclighter(TO_LIGHT0_TMP, ATTEN_LIGHT0_TMP, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_SPECULAR, GLKSH_LIGHT0_ATTEN),
        mkspeclighter(TO_LIGHT0_TMP, ATTEN_LIGHT0_TMP, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_SPECULAR, GLKSH_LIGHT0_ATTEN)});

ShaderDef standardVsh{
    {GL_INPUT_POS,  new ShaderPosRef() },
    {"_outColor",   new ShaderVarRef(GLKSH_COLOR_NAME) },
    {"_texCoord",   new ShaderVarRef(GLKSH_UV0_NAME) },
    {"_lighting",   new ShaderOp(new ShaderVarRef("_ambient"), diffuseLighter, "+", true) },
    {"_specular",   specularLighter }
};

ShaderDef standardPsh{
    {"gl_FragColor", new ShaderOp(
                         new ShaderVarRef("_specular"),
                         new ShaderOp(
                             new ShaderTexRef(GLKSH_TEX1_NAME, GLKSH_TEX1_MODE, new ShaderVarRef("_texCoord"),
                                 new ShaderTexRef(GLKSH_TEX0_NAME, GLKSH_TEX0_MODE, new ShaderVarRef("_texCoord"),
                                     new ShaderFallbackRef("_outColor", GLKSH_CONSTCOLOR_NAME, COLOR_WHITE))),
                             new ShaderVarRef("_lighting"),
                             "*", true),
                         "+", true)}
};

// Per-pixel lighting (SOMEDAY)
