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

namespace {

ShaderNode* mkToLight(const string& pos, const string& tmpName = "")
{
    ShaderNode* toLight = new ShaderOp(new ShaderVarRef(pos), new ShaderVarRef(GLKSH_POS_NAME), "-", true, true);
    if (tmpName.empty()) return toLight;
    return new ShaderTempRef(GLKS_FLOAT4, tmpName, toLight);
}

ShaderNode* mkAtten(const string& attenName, ShaderNode* toLight, const string& tmpName = "")
{
    ShaderNode* attenNode = new ShaderAttenuator(toLight, new ShaderVarRef(attenName));
    if (tmpName.empty()) return attenNode;
    return new ShaderTempRef(GLKS_FLOAT, tmpName, attenNode);
}

ShaderNode* mkLighter(const string& toLightTemp, const string& attenTemp, const string& pos,
                      const string& clr, const string& attenName)
{
    ShaderNode* toLight = mkToLight(pos, toLightTemp);
    ShaderNode* atten = mkAtten(attenName, toLight, attenTemp);

    return new ShaderLighter(toLight, new ShaderVarRef(GLKSH_NORMAL_NAME), new ShaderVarRef(clr), atten);
}

ShaderNode* mkSpecLighter(const string& toLightTemp, const string& attenTemp, const string& pos,
                          const string& clr, const string& attenName)
{
    // These two nodes will reuse the temps created in mklighter above.
    ShaderNode* toLight = mkToLight(pos, toLightTemp);
    ShaderNode* atten = mkAtten(attenName, toLight, attenTemp);

    // This gets reused across the 3 active lights.
    ShaderNode* toCam = new ShaderTempRef(GLKS_FLOAT4, TO_CAM_TMP, new ShaderOp(new ShaderVarRef(GLKSH_CAMERA), new ShaderVarRef(GLKSH_POS_NAME), "-", true, true));
    return new ShaderSpecLighter(toLight, toCam, new ShaderVarRef(GLKSH_NORMAL_NAME), new ShaderVarRef(clr), atten);
}

ShaderNode* mkStandardCombiner(ShaderNode* specularRef, ShaderNode* colorRef, ShaderNode* lightRef)
{
    return new ShaderOp(
               specularRef,
               new ShaderOp(
                   new ShaderTexRef(GLKSH_TEX1_NAME, GLKSH_TEX1_MODE, new ShaderVarRef("_texCoord1"),
                       new ShaderTexRef(GLKSH_TEX0_NAME, GLKSH_TEX0_MODE, new ShaderVarRef("_texCoord0"), colorRef)),
                   lightRef, "*", true),
               "+", true);
}

// Per-vertex lighting.

auto diffuseLighter =
    new ShaderOp(
        new ShaderAdditiveCombiner({
            mkLighter(TO_LIGHT0_TMP, ATTEN_LIGHT0_TMP, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_COLOR, GLKSH_LIGHT0_ATTEN),
            mkLighter(TO_LIGHT1_TMP, ATTEN_LIGHT1_TMP, GLKSH_LIGHT1_POS, GLKSH_LIGHT1_COLOR, GLKSH_LIGHT1_ATTEN),
            mkLighter(TO_LIGHT2_TMP, ATTEN_LIGHT2_TMP, GLKSH_LIGHT2_POS, GLKSH_LIGHT2_COLOR, GLKSH_LIGHT2_ATTEN)}),
      new ShaderVarRef(GLKSH_EMISSIVE), "max", false);

auto specularLighter =
    new ShaderAdditiveCombiner({
        mkSpecLighter(TO_LIGHT0_TMP, ATTEN_LIGHT0_TMP, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_SPECULAR, GLKSH_LIGHT0_ATTEN),
        mkSpecLighter(TO_LIGHT0_TMP, ATTEN_LIGHT0_TMP, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_SPECULAR, GLKSH_LIGHT0_ATTEN),
        mkSpecLighter(TO_LIGHT0_TMP, ATTEN_LIGHT0_TMP, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_SPECULAR, GLKSH_LIGHT0_ATTEN)});

}
 
ShaderDef standardVsh{
    {GL_INPUT_POS,  new ShaderPosRef() },
    {"_outColor",   new ShaderVarRef(GLKSH_COLOR_NAME) },
    {"_texCoord0",  new ShaderVarRef(GLKSH_UV0_NAME) },
    {"_texCoord1",  new ShaderVarRef(GLKSH_UV1_NAME) },
    {"_lighting",   new ShaderOp(new ShaderVarRef("_ambient"), diffuseLighter, "+", true) },
    {"_specular",   specularLighter }
};

ShaderDef standardPsh{
    {"gl_FragColor", mkStandardCombiner(new ShaderVarRef("_specular"),
                                        new ShaderFallbackRef("_outColor", GLKSH_CONSTCOLOR_NAME, COLOR_WHITE),
                                        new ShaderVarRef("_lighting"))}
};
 
ShaderDef pixelVsh{
    {GL_INPUT_POS,  new ShaderPosRef() },
    {"_outColor",   new ShaderVarRef(GLKSH_COLOR_NAME) },
    {"_texCoord0",  new ShaderVarRef(GLKSH_UV0_NAME) },
    {"_texCoord1",  new ShaderVarRef(GLKSH_UV1_NAME) },
    {"_lighting",   new ShaderOp(new ShaderVarRef("_ambient"), diffuseLighter, "+", true) },
    {"_specular",   specularLighter }
};

ShaderDef pixelPsh{
    {"gl_FragColor", mkStandardCombiner(new ShaderVarRef("_specular"),
                                        new ShaderFallbackRef("_outColor", GLKSH_CONSTCOLOR_NAME, COLOR_WHITE),
                                        new ShaderVarRef("_lighting"))}
};
