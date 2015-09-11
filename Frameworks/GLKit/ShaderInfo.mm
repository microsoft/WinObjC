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

string getTypeStr(GLKShaderVarType t)
{
    static const char* types[] = {
        "void",
        "sampler2D",
        "samplerCUBE",
        "float",
        "vec2",
        "vec3",
        "vec4",
        "mat4"
    };

    return string(types[t]);
}

void ShaderMaterial::addvar(const string& var, GLKShaderVarType type, float* data)
{
    assert(vars.find(var) == vars.end());
    assert(type != GLKS_SAMPLER2D && type != GLKS_SAMPLERCUBE);
    
    VarInfo v;
    v.type = type;
    v.loc = values.size();

    const size_t size = GLKShaderVarSizes[type];
    
    for(int i = 0; i < size; i ++) {
        values.push_back(data[i]);
    }
    vars[var] = v;
}

void ShaderMaterial::addtex(const string& var, GLuint name, GLKShaderVarType type)
{
    assert(vars.find(var) == vars.end());
    assert(type == GLKS_SAMPLER2D || type == GLKS_SAMPLERCUBE);

    VarInfo v;
    v.type = type;
    v.loc = name;

    vars[var] = v;
}
