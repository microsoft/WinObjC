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

#include "ShaderInfo.h"

struct ShaderNode;
typedef map<string, ShaderNode*> ShaderDef;

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
    
    GLKShaderPair* generate(VarInfos& inputs);
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
    string constantResult;
public:
    ShaderFallbackRef(const string& first, const string& second, const string& constantResult) :
        first(first), second(second), constantResult(constantResult) {}

    virtual bool generate(string& out, ShaderContext& c, VarInfos& v) override;
};

struct ShaderPosRef : public ShaderNode {
public:
    inline ShaderPosRef() {}
    
    virtual bool generate(string& out, ShaderContext& c, VarInfos& v) override;
};
