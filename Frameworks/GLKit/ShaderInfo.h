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

#pragma once

#import <Foundation/NSDictionary.h>
#import <GLKit/GLKit.h>
#import <GLKit/GLKShader.h>

#include <assert.h>
#include <map>
#include <vector>

using namespace std;

string getTypeStr(GLKShaderVarType t);

struct VarInfo {
    VarInfo() : type(GLKS_INVALID), loc(-1), vertexAttr(false), intermediate(false), used(false) {}
    explicit VarInfo(GLKShaderVarType vt) : type(vt), loc(-1), vertexAttr(false), intermediate(false), used(false) {}

    // when in a layout, used for variable location.
    // when in a shader mat, used for constant location in the array.
    GLKShaderVarType type;
    int loc;
    bool vertexAttr;
    bool intermediate;
    bool used;

    inline string vtype() const { return getTypeStr(type); }
    inline bool isTexture() const { return (type == GLKS_SAMPLER2D || type == GLKS_SAMPLERCUBE); }
};

struct ShaderLayout {
    map<string, VarInfo> vars;
    inline void clear() { for(auto it : vars) it.second.used = false; }

    inline VarInfo* find(const string& name) {
        auto it = vars.find(name);
        if (it == vars.end()) return NULL;
        it->second.used = true;
        return &it->second;
    }

    inline void defvar(const string& var, GLKShaderVarType type, int loc, bool attr = false) {
        if (type == GLKS_INVALID) return;
        if (vars.find(var) != vars.end()) return;

        VarInfo v;
        v.type = type;
        v.loc = loc;
        v.vertexAttr = attr;
        vars[var] = v;
    }

    inline void defvattr(const string& var)                         { defvar(var, GLKS_FLOAT4, -1, true); }
    inline void defvattr3(const string& var)                        { defvar(var, GLKS_FLOAT3, -1, true); }
    inline void defvattr2(const string& var)                        { defvar(var, GLKS_FLOAT2, -1, true); }
    inline void defmat(const string& var)                           { defvar(var, GLKS_MAT4, -1, false); }    
};

struct ShaderMaterial : public ShaderLayout {
    vector<float> values;
    map<string, unsigned int> ivars;

    void addvar(const string& var, GLKShaderVarType type, float* data);
    inline void addvar(const string& var, const GLKVector4& vec)    { addvar(var, GLKS_FLOAT4, (float*)&vec); }
    inline void addvar(const string& var, const GLKVector3& vec)    { addvar(var, GLKS_FLOAT3, (float*)&vec); }
    inline void addvar(const string& var, const GLKVector2& vec)    { addvar(var, GLKS_FLOAT2, (float*)&vec); }
    inline void addvar(const string& var, float val)                { addvar(var, GLKS_FLOAT, &val); }
    inline void addvar3(const string& var, const GLKVector4& vec)   { addvar(var, GLKS_FLOAT3, (float*)&vec); }
    void addtex(const string& var, GLuint name, GLKShaderVarType type = GLKS_SAMPLER2D);
    inline void addtexcube(const string& var, GLuint name)          { addtex(var, name, GLKS_SAMPLERCUBE); }

    inline void addivar(const string& var, unsigned int val)        { ivars[var] = val; }
    
    inline void reset() {
        vars.clear();
        values.resize(0);
    }
};
