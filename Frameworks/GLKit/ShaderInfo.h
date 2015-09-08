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
#import <GLKit/GLKShader.h>

#include <assert.h>
#include <map>
#include <vector>

using namespace std;

struct VarInfo {
    VarInfo() : loc(-1), size(1), vertexAttr(false), intermediate(false), used(false) {}

    // when in a layout, used for variable location.
    // when in a shader mat, used for constant location in the array.
    int loc;
    int size;
    bool vertexAttr;
    bool intermediate;
    bool used;

    inline string vtype() const {
        if (size == 1) return "vec4";
        if (size == 4) return "mat4";
        assert(!"unknown size!");
        return "";
    }
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

    inline void add(const string& var, int loc, int size, bool attr) {
        if (vars.find(var) != vars.end()) return;

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

struct ShaderMaterial : public ShaderLayout {
    vector<float> values;

    void addvar(const string& var, float* data, int size = 4);

    inline void reset() {
        vars.clear();
        values.resize(0);
    }
};
