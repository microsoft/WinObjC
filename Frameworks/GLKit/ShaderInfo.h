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

#include <vector>
#include <map>
#include <assert.h>

using namespace std;

struct ShaderNode;
typedef map<string, ShaderNode*> ShaderDef;

typedef pair<string, string> StrPair;

struct VarInfo {
    VarInfo() : loc(-1), size(1), vertexAttr(false), used(false) {}

    int loc;
    int size;
    bool vertexAttr;
    bool used;

    inline string vtype() const {
        if (size == 1) return "vec4";
        if (size == 4) return "mat4";
        assert(!"unknown size!");
        return "";
    }
};

struct VarInfos {
    map<string, VarInfo> vars;
    void clear();

    VarInfo* find(const string& name) {
        auto it = vars.find(name);
        if (it == vars.end()) return NULL;
        it->second.used = true;
        return &it->second;
    }

    inline void add(const string& var, int loc, int size, bool attr) {
        VarInfo v;
        v.loc = loc;
        v.size = size;
        v.vertexAttr = attr;
        vars[var] = v;
    }

    inline void vertattr(const string& var) { add(var, -1, 1, true); }
    inline void constant(const string& var) { add(var, -1, 1, false); }
    inline void mat(const string& var) { add(var, -1, 4, false); }
};

class ShaderContext {
    VarInfos    shaderVars;

    ShaderDef   vs;
    ShaderDef   ps;

    string      temporaries;
    int         nextTemp;
    
protected:
    string generate(VarInfos& outputs, VarInfos& inputs, const ShaderDef& shader,
                    const string& desc);
    
public:
    ShaderContext(const ShaderDef& vert, const ShaderDef& pixel) :
        vs(vert), ps(pixel), nextTemp(0) {}

    string addTempExpr(string valExpr);
    
    StrPair generate(VarInfos& inputs);
};

// --------------------------------------------------------------------------------

struct ShaderNode {
    virtual bool generate(string& out, ShaderContext& c, VarInfos& v) { return false; }
};

struct ShaderVarRef : public ShaderNode {    
    string name;
public:
    ShaderVarRef(const string& name) : name(name) {}

    virtual bool generate(string& out, ShaderContext& c, VarInfos& v) override;
};

struct ShaderFallbackRef : public ShaderNode {
    string first;
    string second;
public:
    ShaderFallbackRef(const string& first, const string& second) : first(first), second(second) {}

    virtual bool generate(string& out, ShaderContext& c, VarInfos& v) override;
};

struct ShaderPosRef : public ShaderNode {
public:
    inline ShaderPosRef() {}
    
    virtual bool generate(string& out, ShaderContext& c, VarInfos& v) override;
};

