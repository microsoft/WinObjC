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
            outputs.vars[it.first] = VarInfo();
            final += "\t" + it.first + " = " + res + ";\n";
        } else {
            final += "\t// " + desc + ": Cannot generate output for " + it.first + ", skipping...\n";
        }
    }
    
    return final;
}

void ShaderContext::addTempFunc(const string& name, const string& body)
{
    if (vertexStage) {
        vsTemps[name] = body;
    } else {
        psTemps[name] = body;
    }
}

GLKShaderPair* ShaderContext::generate(ShaderLayout& inputs)
{
    ShaderLayout intermediates;
    ShaderLayout outputs;

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
        VarInfo& vd = vp.second;
        if (vd.vertexAttr) continue;
        if (vd.texture) {
            intermediates.texture(vp.first);
        } else {
            intermediates.constant(vp.first);
        }
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
                if (vd.texture == false) res += "lowp ";
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
    outvert = generate(unusedIntermediates, inputs, vs, "VS", &intermediates);

    string vsTempFuncs;
    for(const auto& p : vsTemps) vsTempFuncs += p.second + '\n';

    string psTempFuncs;
    for(const auto& p : psTemps) psTempFuncs += p.second + '\n';
        
    // Perform final generation.
    outvert = vertinvars + vertoutvars + vsTempFuncs + "void main() {\n" + outvert + "}\n";
    outpix = pixvars + psTempFuncs + "void main() {\n" + outpix + "}\n";

    GLKShaderPair* res = [[GLKShaderPair alloc] init];
    res.vertexShader = [NSString stringWithCString: outvert.c_str()];
    res.pixelShader = [NSString stringWithCString: outpix.c_str()];    
    return res;
}

bool ShaderVarRef::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    auto var = v.find(name);
    if(var) {
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
        out = first;
        return true;
    }

    auto v2 = v.find(second);
    if (v2) {
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
    // TODO: BK: texture2D + "*" should be params.

    string next;
    if (nextRef) nextRef->generate(next, c, v);

    string uv;
    auto v1 = v.find(texVar);
    if (!v1 || !uvRef || !uvRef->generate(uv, c, v)) {
        out = next;
        return !next.empty();
    }

    out = "texture2D(" + texVar + ", vec2(" + uv + "))";
    if (!next.empty()) {
        out = "(" + out + " * " + next + ")";
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
    if (!a) {
        if (b) {
            out = res2;
            return true;
        }
        return false;
    }

    if (!b) {
        out = res1;
        return true;
    }
            
    if (isOperator) {
        out = '(' + res1 + ' ' + op + ' ' + res2 + ')';
    } else {
        out = op + '(' + res1 + ", " + res2 + ')';
    }
    return true;
}

bool ShaderLighter::generate(string& out, ShaderContext& c, ShaderLayout& v)
{
    string ldStr, normStr, clrStr, attenStr;
    if (!lightDir->generate(ldStr, c, v) ||
        !normal->generate(normStr, c, v) ||
        !color->generate(clrStr, c, v) ||
        !atten->generate(attenStr, c, v)) return false;

    c.addTempFunc("performLighting",
                  "vec4 performLighting(vec4 toLight, vec4 normal, vec4 color, vec4 atten) {\n"
                  "    float dist = length(vec3(toLight));\n"
                  "    float distAtten = 1.0 / (atten.x + atten.y * dist + atten.z * dist * dist);\n"
                  "    vec3 lightNorm = normalize(vec3(toLight));\n"
                  "    float intensity = max(0.0, dot(lightNorm, vec3(normal))) * distAtten;\n"
                  "    return vec4(color.xyz * intensity, 1.0);\n"
                  "}\n");

    out = "performLighting(" + ldStr + ", " + normStr + ", " + clrStr + ", " + attenStr + ")";
    return true;
}
