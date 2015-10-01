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

#define FOG_BLEND "fogBlendFactor"
#define TRANSFORMED_POS "_xformPos"

using namespace std;

namespace {

// NOTE: This file dynamically allocates a fair amount of ShaderNode objects.  This occurs once as startup
// as part of the static constructors for the standardVsh/Psh and pixelVsh/Psh objects.  These allocations
// creates the master shader program from which all the individual shader programs are created.  ShaderNode
// objects are never (and should never) be allocated outside of this particular situation.  Technically, this
// is a memory leak, but we can revisit this and use smart pointers or statically allocate everything in
// this situation should it arise.

// --------------------------------------------------------------------------------
// The functions below are for creating standard, reused combinations of nodes.

// Returns a node that gets the untransformed position, whether in the vertex or pixel pass
// (provided POS_INPUT exists -- see final shader progs below).
ShaderNode* buildPosRef() {
    return new ShaderFallbackRef({ GLKSH_POS_NAME, POS_INPUT });
}

ShaderNode* buildNormRef() {
    return new ShaderFallbackRef({ GLKSH_NORMAL_NAME, NORM_INPUT });
}
 
// Vector from vertex to given position.
ShaderNode* buildToLight(const string& lightPos, const string& tmpName) {
    ShaderNode* toLight = new ShaderOp(new ShaderVarRef(lightPos), buildPosRef(), "-", true, true);
    return new ShaderTempRef(GLKS_FLOAT3, tmpName, toLight);
}
 
// NOTE: for the lighting nodes below, temps are used so that common diffuse/specular calculations
// are reused, and common calculations between lights are reused.

// Build final diffuse attenuation node.
ShaderNode* buildAtten(const string& attenName,
                       const string& spotParams,
                       const string& spotDir,
                       ShaderNode* toLight,
                       const string& tmpName) {
    auto baseAtten = new ShaderAttenuator(toLight, new ShaderVarRef(attenName));
    auto spotAtten = new ShaderSpotlightAtten(toLight, new ShaderVarRef(spotParams), new ShaderVarRef(spotDir));
    auto attenNode = new ShaderOp(baseAtten, spotAtten, "*", true);
    return new ShaderTempRef(GLKS_FLOAT, tmpName, attenNode);
}

// Build diffuse lighting node.  Two variants on input.
ShaderNode* buildLighter(ShaderNode* toLight,
                         const string& attenTemp,
                         const string& clr,
                         const string& attenName,
                         const string& spotParams,
                         const string& spotDir) {
    auto atten = buildAtten(attenName, spotParams, spotDir, toLight, attenTemp);
    return new ShaderLighter(toLight, buildNormRef(), new ShaderVarRef(clr), atten);
}

// Build a shader node returning the vector to camera.
ShaderNode* buildToCam() {
    ShaderNode* n = new ShaderOp(new ShaderVarRef(GLKSH_CAMERA), buildPosRef(), "-", true, true);
    return new ShaderTempRef(GLKS_FLOAT3, TO_CAM_TMP, n);
}

// Build the final specularity lighting node.
ShaderNode* buildSpecLighter(ShaderNode* toLight,
                             ShaderNode* toCam,
                             const string& attenTemp,
                             ShaderNode* specClrNode,
                             const string& attenName,
                             const string& spotParams,
                             const string& spotDir) {
    ShaderNode* atten = buildAtten(attenName, spotParams, spotDir, toLight, attenTemp);
    return new ShaderSpecLighter(toLight, toCam, buildNormRef(), specClrNode, atten);
}

// Build fog node, based on the type of fog desired.
ShaderNode* buildFog(ShaderNode* colorSrc) {
    return new ShaderAffineBlend(
        new ShaderTempRef(
            GLKS_FLOAT,
            FOG_BLEND,
            new ShaderFallbackNode({
                  new ShaderExpFog(new ShaderVarRef(Z_DEPTH), new ShaderVarRef(GLKSH_FOG_DENSITY2), true),
                  new ShaderExpFog(new ShaderVarRef(Z_DEPTH), new ShaderVarRef(GLKSH_FOG_DENSITY), false),
                  new ShaderLinearFog(new ShaderVarRef(Z_DEPTH), new ShaderVarRef(GLKSH_FOG_DISTANCES))
                })),
        new ShaderVarRef(GLKSH_FOG_COLOR),
        colorSrc);
}

// Combine all the diffuse, specular, and texture inputs into the final pixel color.
ShaderNode* buildStandardCombiner(ShaderNode* specularRef, ShaderNode* colorRef, ShaderNode* lightRef) {
    auto diffuseCombiner =
        new ShaderFallbackNode({ new ShaderInputVarCheck(GLKSH_LIGHTING_ENABLED, lightRef), colorRef });
    return buildFog(new ShaderOp(
        new ShaderInputVarCheck(GLKSH_LIGHTING_ENABLED, specularRef),
        new ShaderOp(diffuseCombiner,
                     new ShaderCubeRef(
                         GLKSH_TEXCUBE,
                         GLKSH_TEXCUBE_MODE,
                         new ShaderOp(new ShaderVarRef(GLKSH_REFL_ALPHA),
                                      new ShaderCustom(
                                          "", ".a", new ShaderTexRef(GLKSH_REFL_TEX, new ShaderVarRef("_texCoord0"))),
                                      "*",
                                      true),
                         new ShaderReflNode(buildNormRef(), new ShaderVarRef(GLKSH_CAMERA)),
                         new ShaderTexRef(GLKSH_TEX1_NAME,
                                          GLKSH_TEX1_MODE,
                                          new ShaderVarRef("_texCoord1"),
                                          new ShaderTexRef(GLKSH_TEX0_NAME, new ShaderVarRef("_texCoord0")))),
                     "*",
                     true),
        "+",
        true));
}

// Per-pixel diffuse lighter, with support for up to 3 lights.
auto ppdiffuseLighter = new ShaderOp(
    new ShaderFallbackNode({
        new ShaderAdditiveCombiner({
                buildLighter(buildToLight(GLKSH_LIGHT0_POS, TO_LIGHT0_TMP),
                             ATTEN_LIGHT0_TMP, GLKSH_LIGHT0_COLOR, GLKSH_LIGHT0_ATTEN,
                             GLKSH_LIGHT0_SPOT, GLKSH_LIGHT0_SPOTDIR),
                buildLighter(buildToLight(GLKSH_LIGHT1_POS, TO_LIGHT1_TMP),
                             ATTEN_LIGHT1_TMP, GLKSH_LIGHT1_COLOR, GLKSH_LIGHT1_ATTEN,
                             GLKSH_LIGHT1_SPOT, GLKSH_LIGHT1_SPOTDIR),
                buildLighter(buildToLight(GLKSH_LIGHT2_POS, TO_LIGHT2_TMP),
                             ATTEN_LIGHT2_TMP, GLKSH_LIGHT2_COLOR, GLKSH_LIGHT2_ATTEN,
                             GLKSH_LIGHT2_SPOT, GLKSH_LIGHT2_SPOTDIR)
            }),
        new ShaderPixelOnly(new ShaderCustom("vec4(0, 0, 0, 1)"))
        }),
    new ShaderTexRef(GLKSH_EMISSIVE_TEX, "", new ShaderVarRef("_texCoord0"), new ShaderVarRef(GLKSH_EMISSIVE)),
    "max",
    false);

// Per-pixel specular lighter, with support for up to 3 lights.
auto ppspecularLighter = new ShaderAdditiveCombiner({
        buildSpecLighter(buildToLight(GLKSH_LIGHT0_POS, TO_LIGHT0_TMP), buildToCam(), ATTEN_LIGHT0_TMP,
                         new ShaderSpecularTex(GLKSH_SPECULAR_TEX, new ShaderVarRef("_texCoord0"),
                                               new ShaderVarRef(GLKSH_LIGHT0_SPECULAR)),
                         GLKSH_LIGHT0_ATTEN, GLKSH_LIGHT0_SPOT, GLKSH_LIGHT0_SPOTDIR),
        buildSpecLighter(buildToLight(GLKSH_LIGHT1_POS, TO_LIGHT1_TMP), buildToCam(), ATTEN_LIGHT1_TMP,
                         new ShaderSpecularTex(GLKSH_SPECULAR_TEX, new ShaderVarRef("_texCoord0"),
                                               new ShaderVarRef(GLKSH_LIGHT1_SPECULAR)),
                         GLKSH_LIGHT1_ATTEN, GLKSH_LIGHT1_SPOT, GLKSH_LIGHT1_SPOTDIR),
        buildSpecLighter(buildToLight(GLKSH_LIGHT2_POS, TO_LIGHT2_TMP), buildToCam(), ATTEN_LIGHT2_TMP,
                         new ShaderSpecularTex(GLKSH_SPECULAR_TEX, new ShaderVarRef("_texCoord0"),
                                               new ShaderVarRef(GLKSH_LIGHT2_SPECULAR)),
                         GLKSH_LIGHT2_ATTEN, GLKSH_LIGHT2_SPOT, GLKSH_LIGHT2_SPOTDIR) });
} // namespace

// Per-vertex lighting.

ShaderDef standardVsh({
    { GL_INPUT_POS, new ShaderTempRef(GLKS_FLOAT4, TRANSFORMED_POS, new ShaderTransformedPosRef()) },
    { Z_DEPTH, new ShaderCustom(GLKS_FLOAT, TRANSFORMED_POS ".z") },
    { "_outColor", new ShaderVarRef(GLKSH_COLOR_NAME) },
    { "_texCoord0", new ShaderVarRef(GLKSH_UV0_NAME) },
    { "_texCoord1", new ShaderVarRef(GLKSH_UV1_NAME) },
    { "_lighting", new ShaderOp(new ShaderVarRef("_ambient"), ppdiffuseLighter, "+", true) },
    { "_specular", ppspecularLighter }
});

ShaderDef standardPsh({
    { "gl_FragColor", buildStandardCombiner(new ShaderVarRef("_specular"),
                                            new ShaderFallbackRef({"_outColor", GLKSH_CONSTCOLOR_NAME}, COLOR_WHITE),
                                            new ShaderVarRef("_lighting")) }
});

// Per-pixel lighting.

ShaderDef pixelVsh({
    { GL_INPUT_POS, new ShaderTempRef(GLKS_FLOAT4, TRANSFORMED_POS, new ShaderTransformedPosRef()) },
    { Z_DEPTH, new ShaderCustom(GLKS_FLOAT, TRANSFORMED_POS ".z") },
    { "_outColor", new ShaderVarRef(GLKSH_COLOR_NAME) },
    { "_texCoord0", new ShaderVarRef(GLKSH_UV0_NAME) },
    { "_texCoord1", new ShaderVarRef(GLKSH_UV1_NAME) },
    { NORM_INPUT, new ShaderVarRef(GLKSH_NORMAL_NAME) },
    { POS_INPUT, new ShaderVarRef(GLKSH_POS_NAME) }
});

ShaderDef pixelPsh({
    { "gl_FragColor", buildStandardCombiner(ppspecularLighter,
                                            new ShaderFallbackRef({"_outColor", GLKSH_CONSTCOLOR_NAME}, COLOR_WHITE),
                                            new ShaderOp(new ShaderVarRef("_ambient"), ppdiffuseLighter, "+", true)) }
});
