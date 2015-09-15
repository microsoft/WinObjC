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

// This is really crude.  Determine if an (unparsed) expression depends on a set of variables.
bool TempInfo::dependsOn(const StrSet& set) const
{
    for(const auto& s : set) {
        if (body.find(s) != string::npos) return true;
    }
    return false;
}

// Write out a series of vars such that calculations needed later are done first.
string ShaderContext::orderedTempVals(const TempMap& temps)
{
    string res;
    StrSet tnames;

    for(const auto& p : temps) tnames.insert(p.first);

    TempMap remainingTemps = temps;
    while(!remainingTemps.empty()) {
        bool foundOne = false;
        for(const auto& p : remainingTemps) {
            if (!p.second.dependsOn(tnames)) {
                res = res + "\t" + getTypeStr(p.second.type) + " " + p.first + " = " + p.second.body + ";\n";

                string name = p.first;
                remainingTemps.erase(name);
                tnames.erase(name);
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

string ShaderContext::generate(ShaderLayout& outputs, ShaderLayout& inputs, const ShaderDef& shader,
                               const string& desc, ShaderLayout* usedOutputs)
{
    string final;
    for(const auto& it : shader) {
        string res;
        if (usedOutputs) {
            auto used = usedOutputs->vars.find(it.first);
            if(it.first != "gl_Position") {
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
            final += "\t// " + desc + ": Cannot generate output for " + it.first + ", skipping...\n";
        }
    }
    
    return final;
}

void ShaderContext::addTempFunc(GLKShaderVarType type, const string& name, const string& body)
{
    if (vertexStage) {
        vsTemps[name] = TempInfo(type, body);
    } else {
        psTemps[name] = TempInfo(type, body);
    }
}

void ShaderContext::addTempVal(GLKShaderVarType type, const string& name, const string& body)
{
    if (vertexStage) {
        vsTempVals[name] = TempInfo(type, body);
    } else {
        psTempVals[name] = TempInfo(type, body);
    }
}

int ShaderContext::getIVar(const string& name, int def)
{
    auto i = inputMaterial->ivars.find(name);
    if (i == inputMaterial->ivars.end()) return def;

    return i->second;
}

GLKShaderPair* ShaderContext::generate(ShaderMaterial& inputs)
{
    ShaderLayout intermediates;
    ShaderLayout outputs;

    inputMaterial = &inputs;
    
    vertexStage = true;
    
    // Perform vertex shader generation.
    string outvert = generate(intermediates, inputs, vs, "VS");
    string vertinvars;
    for(auto vp : inputs.vars) {
        VarInfo& vd = vp.second;
        if (vd.used) {
            string res = (vd.vertexAttr) ? "attribute " : "uniform ";
            res += vd.vtype() + " " + vp.first + ";\n";
            vertinvars += res;
        }
    }
    if (!vertinvars.empty()) vertinvars += '\n';

    // Generate vars for VS outputs, tag them as intermediates.
    string vertoutvars;
    for(auto& vp : intermediates.vars) {
        if(vp.first != "gl_Position") {
            VarInfo& vd = vp.second;
            vd.intermediate = true;
            vd.used = false;
            string res = "varying " + vd.vtype() + " " + vp.first + ";\n";
            vertoutvars += res;
        }
    }
    if (!vertoutvars.empty()) vertoutvars += '\n';

    // Add constants available to the vertex shader program.
    for(auto vp : inputs.vars) {
        if (vp.second.vertexAttr) continue;
        VarInfo vd = vp.second;
        vd.intermediate = false;
        vd.used = false;
        intermediates.vars[vp.first] = vd;
    }

    vertexStage = false;
    
    // Perform pixel shader generation.
    string outpix = generate(outputs, intermediates, ps, "PS");
    string pixvars;
    for(auto vp : intermediates.vars) {
        if(vp.first != "gl_Position" ) {
            VarInfo& vd = vp.second;
            if (vd.used) {
                string res = vd.intermediate ? "varying " : "uniform ";
                if (!vd.isTexture()) res += "lowp ";
                res += vd.vtype() + " " + vp.first + ";\n";
                pixvars += res;
            }
        }
    }
    if (!pixvars.empty()) pixvars += '\n';

    // Regenerate the vertex shader based on the intermediates used in the pixel shader.
    // TODO: BK: This is a little messy.  I should just store the results in a dict and then
    // calculate them only once.  Also, the vertex inputs and intermediates should be regenerated.
    ShaderLayout unusedIntermediates;
    vertexStage = true;
    vsTemps.clear();
    vsTempVals.clear();
    outvert = generate(unusedIntermediates, inputs, vs, "VS", &intermediates);

    string vsTempFuncs;
    for(const auto& p : vsTemps) vsTempFuncs += p.second.body + '\n';
    string vsTempValsOut = orderedTempVals(vsTempVals);
    
    string psTempFuncs;
    for(const auto& p : psTemps) psTempFuncs += p.second.body + '\n';
    string psTempValsOut = orderedTempVals(psTempVals);
        
    // Perform final generation.
    outvert = vertinvars + vertoutvars + vsTempFuncs + "void main() {\n" + vsTempValsOut + outvert + "}\n";
    outpix = pixvars + psTempFuncs + "void main() {\n" + psTempValsOut + outpix + "}\n";

    GLKShaderPair* res = [[GLKShaderPair alloc] init];
    res.vertexShader = [NSString stringWithCString: outvert.c_str()];
    res.pixelShader = [NSString stringWithCString: outpix.c_str()];

    inputMaterial = NULL;

    return res;
}

bool ShaderVarRef::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    auto var = v.find(name);
    if(var) {
        type = var->type;
        out = name;
        return true;
    }
    if (constantResult.empty()) return false;
    out = constantResult;
    return true;
}

bool ShaderFallbackRef::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    auto v1 = v.find(first);
    if(v1) {
        type = v1->type;
        out = first;
        return true;
    }

    auto v2 = v.find(second);
    if (v2) {
        type = v2->type;
        out = second;
        return true;
    }

    if (constantResult.empty()) return false;
    out = constantResult;
    return true;
}

bool ShaderPosRef::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    auto pos = v.find(GLKSH_POS_NAME);
    auto mat = v.find(GLKSH_MVP_NAME);
    if (!pos || !mat) return false;

    out = GLKSH_MVP_NAME " * " GLKSH_POS_NAME;
    return true;
}

bool ShaderTexRef::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    GLKTextureEnvMode mode = c.getIVar(modeVar, GLKTextureEnvModeDecal);

    // Get what we need for the texture, just passthrough next if not there.
    string uv;
    auto v1 = v.find(texVar);
    if (!v1 || !uvRef->generate(uv, c, v)) {
        if (nextRef) nextRef->generate(out, c, v);
        return !out.empty();
    }

    // Do our texture lookup.
    out = "texture2D(" + texVar + ", vec2(" + uv + "))";
    if (mode == GLKTextureEnvModeReplace) return true;

    // Build result with next string.
    string next, tmpname;
    if (nextRef) nextRef->generate(next, c, v);
    if (!next.empty()) {
        switch(mode) {
        case GLKTextureEnvModeModulate:
            out = "(" + out + " * " + next + ")";
            break;

        case GLKTextureEnvModeAdditive:
            out = "(" + out + " + " + next + ")";
            break;

        case GLKTextureEnvModeSubtractive:
            out = "(" + out + " - " + next + ")";
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

bool ShaderAdditiveCombiner::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    int numGenerated = 0;
    for(auto n : subNodes) {
        string res;
        if (n->generate(res, c, v) && !res.empty()) {
            if (numGenerated == 0) {
                out = res;
                type = n->getType();
            } else if(numGenerated == 1) {
                out = '(' + out + " + " + res;
            } else {
                out += " + " + res;
            }
            numGenerated ++;
        }
    }
    if (numGenerated > 1) {
        out += ')';
    }

    return numGenerated >= 1;
}

bool ShaderOp::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    string res1, res2;
    bool a = n1->generate(res1, c, v);
    bool b = n2->generate(res2, c, v);
    if (needsAll) {
        // Too bad.
        if (!a || !b) return false;
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

bool ShaderTempRef::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    string res;
    if (!body->generate(res, c, v)) return false;
    type = body->getType();
    c.addTempVal(type, name, res);
    out = name;
    return true;
}

bool ShaderAttenuator::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    string lightStr, attenStr;

    if (!toLight->generate(lightStr, c, v) ||
        !atten->generate(attenStr, c, v)) return false;

    c.addTempFunc(GLKS_FLOAT, "performAttenuation",
                  "float performAttenuation(vec3 toLight, vec3 atten) {\n"
                  "    float dist = length(toLight);\n"
                  "    return min(1.0, 1.0 / (atten.x + atten.y * dist + atten.z * dist * dist));\n"
                  "}\n");

    out = "performAttenuation(" + lightStr + ", " + attenStr + ")";
    return true;
}

bool ShaderLighter::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    string ldStr, normStr, clrStr, attenStr;
    if (!lightDir->generate(ldStr, c, v) ||
        !normal->generate(normStr, c, v) ||
        !color->generate(clrStr, c, v) ||
        !atten->generate(attenStr, c, v)) return false;

    c.addTempFunc(GLKS_FLOAT4, "performLighting",
                  "vec4 performLighting(vec3 toLight, vec3 normal, vec4 color, float distAtten) {\n"
                  "    vec3 lightNorm = normalize(toLight);\n"
                  "    float intensity = max(0.0, dot(lightNorm, normal)) * distAtten;\n"
                  "    return vec4(color.xyz * intensity, 1.0);\n"
                  "}\n");

    out = "performLighting(" + ldStr + ", " + normStr + ", " + clrStr + ", " + attenStr + ")";
    return true;
}

bool ShaderSpecLighter::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    string ldStr, cdStr, normStr, clrStr, attenStr;
    if (!lightDir->generate(ldStr, c, v) ||
        !cameraDir->generate(cdStr, c, v) ||
        !normal->generate(normStr, c, v) ||
        !color->generate(clrStr, c, v) ||
        !atten->generate(attenStr, c, v)) return false;

    c.addTempFunc(GLKS_FLOAT4, "performSpecular",
                  "vec4 performSpecular(vec3 toLight, vec3 toCam, vec3 normal, vec4 color, float distAtten) {\n"
                  "    vec3 lightRefl = normalize(reflect(toLight, normal));\n"
                  "    vec3 camNorm = normalize(vec3(toCam));\n"
                  "    float specular = distAtten * pow(max(0.0, -dot(camNorm, lightRefl)), color.w);\n"
                  "    return vec4(color.xyz * specular, 1.0);\n"
                  "}\n");

    out = "performSpecular(" + ldStr + ", " + cdStr + ", " + normStr + ", " + clrStr + ", " + attenStr + ")";
    return true;
}
