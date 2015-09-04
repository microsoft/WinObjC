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
#include "ShaderInfo.h"
#include "ShaderGen.h"

string ShaderContext::addTempExpr(string valExpr)
{
    char name[64];
    sprintf(name, "_temp%d", nextTemp);
    nextTemp ++;

    temporaries += "\tvec4 " + string(name) + " = " + valExpr + ";\n";
    
    return string(name);
}

string ShaderContext::generate(VarInfos& outputs, VarInfos& inputs, const ShaderDef& shader,
                               const string& desc)
{
    nextTemp = 0;

    string final;
    for(const auto& it : shader) {
        string res;
        temporaries = "";
        if (it.second->generate(res, *this, inputs)) {
            outputs.vars[it.first] = VarInfo();
            if (!temporaries.empty()) final += temporaries;
            final += "\t" + it.first + " = " + res + ";\n";
        } else {
            final += "\t// " + desc + ": Cannot generate output for " + it.first + ", skipping...\n";
        }
    }
    
    return final;
}

GLKShaderPair* ShaderContext::generate(VarInfos& inputs)
{
    VarInfos intermediates;
    VarInfos outputs;

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

    string vertoutvars;
    for(auto vp : intermediates.vars) {
        if(vp.first != "gl_Position") {
            VarInfo& vd = vp.second;
            string res = "varying " + vd.vtype() + " " + vp.first + ";\n";
            vertoutvars += res;
        }
    }

    string outpix = generate(outputs, intermediates, ps, "PS");

    string pixvars;
    for(auto vp : intermediates.vars) {
        if(vp.first != "gl_Position") {        
            VarInfo& vd = vp.second;
            string res = "varying lowp " + vd.vtype() + " " + vp.first + ";\n";
            pixvars += res;
        }
    }

    outvert = vertinvars + "\n" + vertoutvars + "\nvoid main() {\n" + outvert + "}\n";
    outpix = pixvars + "\nvoid main() {\n" + outpix + "}\n";

    GLKShaderPair* res = [[GLKShaderPair alloc] init];
    res.vertexShader = [NSString stringWithCString: outvert.c_str()];
    res.pixelShader = [NSString stringWithCString: outpix.c_str()];
    
    return res;
}

bool ShaderVarRef::generate(string& out, ShaderContext& c, VarInfos& v)
{
    auto var = v.find(name);
    if(var) {
        out = name;
        return true;
    }
    return false;
}

bool ShaderFallbackRef::generate(string& out, ShaderContext& c, VarInfos& v)
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

bool ShaderPosRef::generate(string& out, ShaderContext& c, VarInfos& v)
{
    auto pos = v.find(GLKSH_POS_NAME);
    auto mat = v.find(GLKSH_MVP_NAME);
    if (!pos || !mat) return false;

    out = GLKSH_MVP_NAME " * " GLKSH_POS_NAME;
    return true;
}
