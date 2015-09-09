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

// Per-vertex lighting.

static auto diffuseLighter =
    new ShaderOp(
      new ShaderAdditiveCombiner({
              new ShaderLighter(new ShaderOp(new ShaderVarRef(GLKSH_LIGHT0_POS), new ShaderVarRef(GLKSH_POS_NAME), "-", true),
                                new ShaderVarRef("_normal"), new ShaderVarRef(GLKSH_LIGHT0_COLOR), new ShaderVarRef(GLKSH_LIGHT0_ATTEN)),
              new ShaderLighter(new ShaderOp(new ShaderVarRef(GLKSH_LIGHT1_POS), new ShaderVarRef(GLKSH_POS_NAME), "-", true),
                                new ShaderVarRef("_normal"), new ShaderVarRef(GLKSH_LIGHT1_COLOR), new ShaderVarRef(GLKSH_LIGHT1_ATTEN)),
              new ShaderLighter(new ShaderOp(new ShaderVarRef(GLKSH_LIGHT2_POS), new ShaderVarRef(GLKSH_POS_NAME), "-", true),
                                new ShaderVarRef("_normal"), new ShaderVarRef(GLKSH_LIGHT2_COLOR), new ShaderVarRef(GLKSH_LIGHT2_ATTEN))}),
      new ShaderVarRef(GLKSH_EMISSIVE), "max", false);

static auto specularLighter =
    new ShaderAdditiveCombiner();

ShaderDef standardVsh{
    {GL_INPUT_POS,  new ShaderPosRef() },
    {"_outColor",   new ShaderVarRef(GLKSH_COLOR_NAME) },
    {"_texCoord",   new ShaderVarRef(GLKSH_UV0_NAME) },
    {"_lighting",   new ShaderOp(new ShaderVarRef("_ambient"), diffuseLighter, "+", true) },
  //    {"_specular",   specularLighter }
};

ShaderDef standardPsh{
    {"gl_FragColor", new ShaderOp(new ShaderVarRef("_specular"), 
                                  new ShaderTexRef(GLKSH_TEX0_NAME, new ShaderVarRef("_texCoord"),
                                      new ShaderOp(new ShaderFallbackRef("_outColor", GLKSH_CONSTCOLOR_NAME, COLOR_WHITE),
                                                   new ShaderVarRef("_lighting"), "*", true)),
                                  "+", true)}
};

// Per-pixel lighting.
