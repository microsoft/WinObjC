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
#import <GLKit/GLKit.h>
#import <GLKit/GLKShader.h>
#import <GLKit/GLKShaderDefs.h>
#include "ShaderInfo.h"
#include "ShaderGen.h"

using namespace std;
using namespace GLKitShader;

// TODO: clean up lowp references.

// This is really crude.  Determine if this (unparsed) expression depends on a set of variables
// by string searching the body for variables.  Beats parsing the entire thing though.
bool TempInfo::dependsOn(const std::set<std::string>& variables) const {
    for (const auto& var : variables) {
        if (body.find(var) != string::npos)
            return true;
    }
    return false;
}

// Write out a series of vars such that calculations needed later are done first.
string ShaderContext::orderedTempVals(const TempMap& tempDefs, bool usePrecision) {
    string res;
    std::set<std::string> tempNames;
    string precision = usePrecision ? "lowp " : "";

    for (const auto& def : tempDefs)
        tempNames.insert(def.first);

    TempMap remainingTemps = tempDefs;
    while (!remainingTemps.empty()) {
        bool foundOne = false;
        for (const auto& tempDef : remainingTemps) {
            if (!tempDef.second.dependsOn(tempNames)) {
                string name = tempDef.first;
                res = res + "\t" + precision + getTypeStr(tempDef.second.type) + " " + name + " = " + tempDef.second.body + ";\n";

                remainingTemps.erase(name);
                tempNames.erase(name);
                foundOne = true;
                break;
            }
        }

        if (!foundOne) {
            NSLog(@"Unable to generate temporary calculations for shader!");
            assert(0);
            break;
        }
    }

    return res;
}

string ShaderContext::generate(
    ShaderLayout& outputs, ShaderLayout& inputs, const ShaderDef& shader, const string& desc, ShaderLayout* usedOutputs) {
    string final;
    for (const auto& it : shader.getDef()) {
        string res;
        if (usedOutputs) {
            auto used = usedOutputs->vars.find(it.first);
            if (it.first != "gl_Position") {
                if (used != usedOutputs->vars.end() && !used->second.used) {
                    final += "\t// " + desc + ": Output for " + it.first + " skipped, unused later in program.\n";
                    continue;
                }
            }
        }
        if (it.second->generate(res, *this, inputs)) {
            outputs.vars[it.first] = VarInfo(it.second->getType());
            final += "\t" + it.first + " = " + res + ";\n";
        } else {
            final += "\t// " + desc + ": Inputs not found for " + it.first + ", skipping output calculation...\n";
        }
    }

    return final;
}

void ShaderContext::addTempFunc(GLKShaderVarType type, const string& name, const string& body) {
    if (vertexStage) {
        vsTempFuncs[name] = TempInfo(type, body);
    } else {
        psTempFuncs[name] = TempInfo(type, body);
    }
}

void ShaderContext::addTempVal(GLKShaderVarType type, const string& name, const string& body) {
    if (vertexStage) {
        vsTempVals[name] = TempInfo(type, body);
    } else {
        psTempVals[name] = TempInfo(type, body);
    }
}

int ShaderContext::getInputVar(const string& name, int defaultVal) {
    if (name.empty())
        return defaultVal;
    auto i = inputMaterial->inputVars.find(name);
    if (i == inputMaterial->inputVars.end())
        return defaultVal;

    return i->second;
}

// Main shader program generation.  Returns a full vertex/pixel shader pair corresponding
// to the shader definition for the given material.
GLKShaderPair* ShaderContext::generate(ShaderMaterial& inputs) {
    ShaderLayout intermediates;
    ShaderLayout outputs;

    inputMaterial = &inputs;

    vertexStage = true;

    // These should not persist between generations.
    vsTempFuncs.clear();
    vsTempVals.clear();
    psTempFuncs.clear();
    psTempVals.clear();

    // Perform vertex shader generation.
    string outvert = generate(intermediates, inputs, vs, "VS");
    string vertinvars;
    for (auto vp : inputs.vars) {
        VarInfo& vd = vp.second;
        if (vd.used) {
            string res = (vd.vertexAttr) ? "attribute " : "uniform ";
            res += vd.getTypeStr() + " " + vp.first + ";\n";
            vertinvars += res;
        }
    }
    if (!vertinvars.empty())
        vertinvars += '\n';

    // Generate vars for VS outputs, tag them as intermediates.
    string vertoutvars;
    for (auto& vp : intermediates.vars) {
        if (vp.first != "gl_Position") {
            VarInfo& vd = vp.second;
            vd.intermediate = true;
            vd.used = false;
            string res = "varying " + vd.getTypeStr() + " " + vp.first + ";\n";
            vertoutvars += res;
        }
    }
    if (!vertoutvars.empty())
        vertoutvars += '\n';

    // Add constants available to the vertex shader program.
    for (auto vp : inputs.vars) {
        if (vp.second.vertexAttr) {
            continue;
        }
        VarInfo vd = vp.second;
        vd.intermediate = false;
        vd.used = false;
        intermediates.vars[vp.first] = vd;
    }

    vertexStage = false;

    // Perform pixel shader generation.
    string outpix = generate(outputs, intermediates, ps, "PS");
    string pixvars;
    for (auto vp : intermediates.vars) {
        if (vp.first != "gl_Position") {
            VarInfo& vd = vp.second;
            if (vd.used) {
                string res = vd.intermediate ? "varying " : "uniform ";
                if (!vd.isTexture())
                    res += "highp ";
                res += vd.getTypeStr() + " " + vp.first + ";\n";
                pixvars += res;
            }
        }
    }
    if (!pixvars.empty())
        pixvars += '\n';

    // Regenerate the vertex shader based on the intermediates used in the pixel shader.
    // TODO: BK: This is a little messy.  I should just store the results in a dict and then
    // calculate them only once.
    ShaderLayout unusedIntermediates;
    vertexStage = true;

    vsTempFuncs.clear();
    vsTempVals.clear();

    outvert = generate(unusedIntermediates, inputs, vs, "VS", &intermediates);

    string vsTempFuncsOut;
    for (const auto& p : vsTempFuncs)
        vsTempFuncsOut += p.second.body + '\n';
    string vsTempValsOut = orderedTempVals(vsTempVals, false);

    string psTempFuncsOut;
    for (const auto& p : psTempFuncs)
        psTempFuncsOut += p.second.body + '\n';
    string psTempValsOut = orderedTempVals(psTempVals, true);

    // Perform final generation.
    outvert = vertinvars + vertoutvars + vsTempFuncsOut + "void main() {\n" + vsTempValsOut + outvert + "}\n";
    outpix = "precision lowp float;\n\n" + pixvars + psTempFuncsOut + "void main() {\n" + psTempValsOut + outpix + "}\n";

    GLKShaderPair* res = [[GLKShaderPair alloc] init];
    res.vertexShader = [NSString stringWithCString:outvert.c_str()];
    res.pixelShader = [NSString stringWithCString:outpix.c_str()];

    inputMaterial = nullptr;

    return res;
}

bool ShaderInputVarCheck::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    if (!c.getInputVar(name))
        return false;
    return node->generate(out, c, v);
}

bool ShaderVarRef::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    type = v.findVariable(name, c.isPixelStage());
    if (type) {
        out = name;
        return true;
    }

    out = constantResult;
    return !out.empty();
}

bool ShaderFallbackRef::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    for (const auto& var : variables) {
        type = v.findVariable(var, c.isPixelStage());
        if (type) {
            out = var;
            return true;
        }
    }

    out = constantResult;
    return !out.empty();
}

bool ShaderFallbackNode::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    for (auto n : nodes) {
        if (n->generate(out, c, v))
            return true;
    }
    return false;
}

bool ShaderTransformedPosRef::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    if (!v.findVariable(GLKSH_POS_NAME) || !v.findVariable(GLKSH_MVP_NAME)) {
        return false;
    }

    out = GLKSH_MVP_NAME " * " GLKSH_POS_NAME;
    return true;
}

string ShaderTexRef::genTexLookup(string texVar, string uv, ShaderContext& c, ShaderLayout& v) {
    return "texture2D(" + texVar + ", vec2(" + uv + "))";
}

bool ShaderTexRef::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    GLKTextureEnvMode mode = c.getInputVar(modeVar, GLKTextureEnvModeDecal);

    // Get what we need for the texture, just passthrough next if not there, or if this
    // is a vertex stage.
    string uv;
    if (c.isVertexStage() || !v.findVariable(texVar) || !uvRef->generate(uv, c, v)) {
        if (nextRef) {
            nextRef->generate(out, c, v);
        }
        return !out.empty();
    }

    // Do our texture lookup.
    out = genTexLookup(texVar, uv, c, v);
    if (mode == GLKTextureEnvModeReplace)
        return true;

    // Build result with next string.
    string next, tmpname;
    if (nextRef)
        nextRef->generate(next, c, v);
    if (!next.empty()) {
        switch (mode) {
            case GLKTextureEnvModeModulate:
                out = "(" + out + " * " + next + ")";
                break;

            case GLKTextureEnvModeAdditive:
                out = "(" + out + " + " + next + ")";
                break;

            case GLKTextureEnvModeSubtractive:
                out = "(" + next + " - " + out + ")";
                break;

            case GLKTextureEnvModeDecal:
                tmpname = texVar + "_val";
                c.addTempVal(type, tmpname, out);
                out = "mix(" + next + ", " + tmpname + ", " + tmpname + ".a)";
                break;
        }
    }
    return true;
}

string ShaderCubeRef::genTexLookup(string texVar, string uv, ShaderContext& c, ShaderLayout& v) {
    std::string transform;
    if (transformNode) {
        transformNode->generate(transform, c, v);
    }

    std::string texLookup;
    if (!transform.empty()) {
        texLookup = "textureCube(" + texVar + ", vec3(" + transform + " * vec4(vec3(" + uv + ") * vec3(1.0, -1.0, 1.0), 0.0)))";
    } else {
        texLookup = "textureCube(" + texVar + ", vec3(" + uv + ") * vec3(1.0, -1.0, 1.0))";
    }

    std::string modulus;
    if (!reflAlphaNode || !reflAlphaNode->generate(modulus, c, v))
        return texLookup;

    if (reflAlphaNode->getType() == GLKS_FLOAT) {
        return "(" + modulus + " * " + texLookup + ")";
    }
    return "(" + modulus + ".a * " + texLookup + ")";
}

bool ShaderSpecularTex::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    if (nextRef) {
        nextRef->generate(out, c, v);
    }

    // No texture?  just do passthrough.
    string uv;
    if (c.isVertexStage() || !v.findVariable(texVar) || !uvRef->generate(uv, c, v)) {
        return !out.empty();
    }

    // Do our texture lookup.
    string texVarTmp = texVar + "_specTmp";
    string texMod = "texture2D(" + texVar + ", vec2(" + uv + ")).a"; // TODO: parameterize this & refl tex for alpha vs rgb.
    c.addTempVal(GLKS_FLOAT, texVarTmp, texMod);

    // shininess stored in .a of input.
    out = "vec4(" + texVarTmp + " * " + out + ".rgb, max(1.0, " + texVarTmp + " * " + out + ".a))";
    return true;
}

bool ShaderAdditiveCombiner::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    int numGenerated = 0;
    for (auto n : subNodes) {
        string res;
        if (n->generate(res, c, v) && !res.empty()) {
            if (numGenerated == 0) {
                out = res;
                type = n->getType();
            } else if (numGenerated == 1) {
                out = '(' + out + " + " + res;
            } else {
                out += " + " + res;
            }
            numGenerated++;
        }
    }
    if (numGenerated > 1) {
        out += ')';
    }

    return numGenerated >= 1;
}

bool ShaderOp::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string res1, res2;
    bool a = n1->generate(res1, c, v);
    bool b = n2->generate(res2, c, v);
    if (needsAll) {
        // Too bad.
        if (!a || !b)
            return false;
    } else {
        // Recover nicely if something is missing.
        if (!a) {
            if (b) {
                out = res2;
                type = n2->getType();
                return true;
            }
            return false;
        }

        if (!b) {
            out = res1;
            type = n1->getType();
            return true;
        }
    }

    // cast second result if need be.  assume this rule will always magically work out.  (hint: it won't).
    if (n2->getType() != n1->getType()) {
        res2 = getTypeStr(n1->getType()) + '(' + res2 + ')';
    }

    if (isOperator) {
        out = '(' + res1 + ' ' + op + ' ' + res2 + ')';
    } else {
        out = op + '(' + res1 + ", " + res2 + ')';
    }
    type = n1->getType();
    return true;
}

bool ShaderTempRef::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string res;
    if (!body->generate(res, c, v))
        return false;
    c.addTempVal(type, name, res);
    out = name;
    return true;
}

bool ShaderAttenuator::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string lightStr, attenStr;

    if (!toLight->generate(lightStr, c, v) || !atten->generate(attenStr, c, v))
        return false;

    c.addTempFunc(GLKS_FLOAT,
                  "performAttenuation",
                  "float performAttenuation(vec3 toLight, vec3 atten) {\n"
                  "    float dist = length(toLight);\n"
                  "    return min(1.0, 1.0 / (atten.x + atten.y * dist + atten.z * dist * dist));\n"
                  "}\n");

    out = "performAttenuation(" + lightStr + ", " + attenStr + ")";
    return true;
}

bool ShaderReflNode::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string normStr, srcStr;
    if (!norm->generate(normStr, c, v) || !src->generate(srcStr, c, v))
        return false;

    out = "normalize(reflect(" + srcStr + ", " + normStr + "))";
    return true;
}

bool ShaderCustom::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    if (!inner || !useInner) {
        out = before + after;
    } else {
        string innerStr;
        if (!inner->generate(innerStr, c, v))
            return false;
        out = before + innerStr + after;
    }
    return true;
}

bool ShaderLighter::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string ldStr, normStr, clrStr, attenStr;
    if (!lightDir->generate(ldStr, c, v) || !normal->generate(normStr, c, v) || !color->generate(clrStr, c, v) ||
        !atten->generate(attenStr, c, v))
        return false;

    c.addTempFunc(GLKS_FLOAT4,
                  "performLighting",
                  "vec4 performLighting(vec3 toLight, vec3 normal, vec4 color, float distAtten) {\n"
                  "    vec3 lightNorm = normalize(toLight);\n"
                  "    float intensity = max(0.0, dot(lightNorm, normal)) * distAtten;\n"
                  "    return vec4(color.xyz * intensity, 1.0);\n"
                  "}\n");

    out = "performLighting(" + ldStr + ", " + normStr + ", " + clrStr + ", " + attenStr + ")";
    return true;
}

bool ShaderSpecLighter::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string ldStr, cdStr, normStr, clrStr, attenStr;
    if (!lightDir->generate(ldStr, c, v) || !cameraDir->generate(cdStr, c, v) || !normal->generate(normStr, c, v) ||
        !color->generate(clrStr, c, v) || !atten->generate(attenStr, c, v))
        return false;

    c.addTempFunc(GLKS_FLOAT4,
                  "performSpecular",
                  "vec4 performSpecular(vec3 toLight, vec3 toCam, vec3 normal, vec4 color, float distAtten) {\n"
                  "    vec3 lightRefl = normalize(reflect(toLight, normal));\n"
                  "    vec3 camNorm = normalize(vec3(toCam));\n"
                  "    float specular = distAtten * pow(max(0.0, -dot(camNorm, lightRefl)), color.w);\n"
                  "    return vec4(color.xyz * specular, 1.0);\n"
                  "}\n");

    out = "performSpecular(" + ldStr + ", " + cdStr + ", " + normStr + ", " + clrStr + ", " + attenStr + ")";
    return true;
}

bool ShaderSpotlightAtten::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string ldStr;
    string paramRef;
    string dirRef;

    if (!lightDir->generate(ldStr, c, v) || !params->generate(paramRef, c, v) || !dir->generate(dirRef, c, v))
        return false;

    c.addTempFunc(GLKS_FLOAT,
                  "spotlightAtten",
                  "float spotlightAtten(vec3 toLight, vec3 spotDir, vec3 spotAtten) {"
                  "    float dp = -dot(normalize(toLight), spotDir);\n"
                  "    float intens = max(0.0, min(dp, spotAtten.y) - spotAtten.x) * spotAtten.z;\n"
                  "    return intens;\n"
                  "}\n");

    out = "spotlightAtten(" + ldStr + ", " + dirRef + ", " + paramRef + ")";
    return true;
}

bool ShaderAffineBlend::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string blend;
    string n1src;
    string n2src;

    // Can we even blend?
    if (!blendNode->generate(blend, c, v) || !n1->generate(n1src, c, v)) {
        return n2->generate(out, c, v);
    }

    if (!n2->generate(n2src, c, v)) {
        out = n1src;
        return true;
    }

    // Blend!
    out = "(((1.0 - " + blend + ") * (" + n1src + ")) + " + blend + " * (" + n2src + "))";
    return true;
}

// fogParams.x = end distance, fogParams.y = 1 / (end - start).
bool ShaderLinearFog::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string params, depth;
    if (!fogParams->generate(params, c, v))
        return false;
    if (!depthRef->generate(depth, c, v))
        return false;

    out = "clamp((" + params + ".x - " + depth + ") * " + params + ".y, 0.0, 1.0)";
    return true;
}

bool ShaderExpFog::generate(string& out, ShaderContext& c, ShaderLayout& v) {
    string dens, depth;
    if (!densityRef->generate(dens, c, v))
        return false;
    if (!depthRef->generate(depth, c, v))
        return false;

    if (squared) {
        out = "clamp(exp(" + depth + " * " + depth + " * " + dens + "), 0.0, 1.0)";
    } else {
        out = "clamp(exp(" + depth + " * " + dens + "), 0.0, 1.0)";
    }

    return true;
}

bool ShaderVertexOnly::generate(std::string& out, ShaderContext& c, ShaderLayout& v) {
    if (c.isVertexStage()) {
        return inner->generate(out, c, v);
    }
    return false;
}

bool ShaderPixelOnly::generate(std::string& out, ShaderContext& c, ShaderLayout& v) {
    if (c.isPixelStage()) {
        return inner->generate(out, c, v);
    }
    return false;
}
