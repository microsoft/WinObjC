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
#include <set>

// Internal shader definitions, not exposed through GLKShaderDefs.h
#define Z_DEPTH                 "_posDepth"             // transformed depth.
#define POS_INPUT               "_vertexPos"            // vertex position (model coords).
#define NORM_INPUT              "_vertNorm"

class ShaderNode;

// Contains the definition of either a vertex or pixel shader program, as a map
// of shader program outputs to a tree of ShaderNode objects responsible for building
// that part of the program.
class ShaderDef {
    ShaderDef(const ShaderDef&) = delete; // no copy
    void operator=(const ShaderDef&) = delete;

    std::map<std::string, ShaderNode*> def;
public:
    ShaderDef(const std::map<std::string, ShaderNode*>& def) : def(def) {}
    inline const std::map<std::string, ShaderNode*>& getDef() const { return def; }
};

// Information on a temporary value for the shader program.  Contains its type and definition body.
struct TempInfo {
    inline TempInfo() : type(GLKS_INVALID) {}
    inline TempInfo(GLKShaderVarType type, const std::string& body) : type(type), body(body) {}

    bool dependsOn(const std::set<std::string>& variables) const;
    
    GLKShaderVarType type;
    std::string body;
};
typedef std::map<std::string, TempInfo> TempMap;

@class GLKShaderPair;

// Main class responsible for shader generation.  Tracks temporary data and builds the final
// output vertex/pixel shader program pair.
class ShaderContext {
    ShaderLayout            shaderVars;
    ShaderMaterial*         inputMaterial;

    const ShaderDef&        vs;
    const ShaderDef&        ps;

    bool                    vertexStage; // are we generating VS or PS code?

    TempMap                 vsTempFuncs;
    TempMap                 vsTempVals;

    TempMap                 psTempFuncs;
    TempMap                 psTempVals;
    
protected:
    std::string orderedTempVals(const TempMap& temps, bool usePrecision);
    
    std::string generate(ShaderLayout& outputs, ShaderLayout& inputs, const ShaderDef& shader,
                         const std::string& desc, ShaderLayout* usedOutputs = nullptr);
    
public:
    ShaderContext(const ShaderDef& vert, const ShaderDef& pixel) :
        inputMaterial(nullptr), vs(vert), ps(pixel), vertexStage(false) {}

    // Used by ShaderNodes to NOTE: neither of these check for overwriting.
    void addTempFunc(GLKShaderVarType type, const std::string& name, const std::string& body);
    void addTempVal(GLKShaderVarType type, const std::string& name, const std::string& body);

    int getInputVar(const std::string& name, int def = 0);

    // Main shader generation function.
    GLKShaderPair* generate(ShaderMaterial& inputs);

    // Accessors.
    inline bool isVertexStage() const { return vertexStage; }
    inline bool isPixelStage() const { return !vertexStage; }
};

// --------------------------------------------------------------------------------
// Shader nodes: a tree of nodes generates an output for a particular shader program.
// A tree of shader nodes can be thought of roughly as a parse tree, except less granular
// and more usable.

// The ShaderContext class goes to some effort to do dead code elimination based on shader inputs/outputs
// that are unused.  In general, ShaderNodes should not expect all their inputs to be their (or all their
// child classes to successfully generate code) and should fail intelligently when this happens.  For instance,
// the texture reference classes just pass through their inputs instead of modulating them if the texture
// is not present.  This allows a single set of nodes that can generate everything from a VS/PS pair
// consisting of a single instruction each, to a per-pixel lit shader with 3 input lights.  Maintaining
// this single node set is easier than dealing with a whole pile of shader programs.

// Base class.  Defines generation interface.
class ShaderNode {
    ShaderNode(const ShaderNode&) = delete; // no copy
    void operator=(const ShaderNode&) = delete;

protected:
    GLKShaderVarType type;
public:
    inline ShaderNode() : type(GLKS_FLOAT4) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) { return false; }
    inline GLKShaderVarType getType() const { return type; }
};

// Check if an input variable is present and non-zero before generating the child node.
class ShaderInputVarCheck : public ShaderNode {
    std::string name;
    ShaderNode* node;

public:
    ShaderInputVarCheck(const std::string& name, ShaderNode* node) : name(name), node(node) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Generates a reference to a variable if the variable is present, nothing if not.
class ShaderVarRef : public ShaderNode {
    std::string name;
    std::string constantResult;
public:
    ShaderVarRef(const std::string& name, const std::string& constantResult = "") : name(name), constantResult(constantResult) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Use the first variable that's present in a list of variables, or fall back to a constant if
// none of them are present, or generate nothing if there's no constant.
class ShaderFallbackRef : public ShaderNode {
    std::vector<std::string> variables;
    std::string constantResult;
public:
    ShaderFallbackRef(const std::vector<std::string>& variables,
                      const std::string& constantResult = "") :
        variables(variables), constantResult(constantResult) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Use the first node in a list of nodes that generates code successfully.  This is a more general
// version of the FallbackRef above.
class ShaderFallbackNode : public ShaderNode {
    std::vector<ShaderNode*> nodes;
public:
    ShaderFallbackNode(std::vector<ShaderNode*> nodes) : nodes(nodes) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Use the position variable, applying the mvp matrix.
struct ShaderTransformedPosRef : public ShaderNode {
    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Texture lookup node.  This blends the texture lookup (if present) with the given child node
// using the blend mode specified in an input variable.  If the texture is not present, this node
// just passes through the child node's code.
class ShaderTexRef : public ShaderNode {
    std::string texVar;
    std::string modeVar;
    ShaderNode* uvRef;
    ShaderNode* nextRef;

protected:
    virtual std::string genTexLookup(std::string texVar, std::string uv, ShaderContext& c, ShaderLayout& v);

public:
    ShaderTexRef(const std::string& tex, const std::string& mode, ShaderNode* uvRef, ShaderNode* nextRef) :
        texVar(tex), modeVar(mode), uvRef(uvRef), nextRef(nextRef) {}
    ShaderTexRef(const std::string& tex, ShaderNode* uvRef) :
        texVar(tex), modeVar(""), uvRef(uvRef), nextRef(nullptr) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Cube map lookup node.  Same as for the texture node, but with cube maps.
class ShaderCubeRef : public ShaderTexRef {
    ShaderNode* reflAlphaNode;

protected:
    virtual std::string genTexLookup(std::string texVar, std::string uv, ShaderContext& c, ShaderLayout& v) override;

public:
    ShaderCubeRef(const std::string& tex, const std::string& mode, ShaderNode* reflAlphaNode, 
                  ShaderNode* uvRef, ShaderNode* nextRef) :
        reflAlphaNode(reflAlphaNode),
        ShaderTexRef(tex, mode, uvRef, nextRef) {}
};

// Modulate the specular parameters for a light with the given specular texture.  Passes through code
// if the specular texture is not present.  This works only with a light's specular parameter, which is
// a float4 of the form (r, g, b, shininess).
class ShaderSpecularTex : public ShaderNode {
    std::string texVar;
    ShaderNode* uvRef;
    ShaderNode* nextRef;

public:
    ShaderSpecularTex(const std::string& tex, ShaderNode* uvRef, ShaderNode* nextRef) :
        texVar(tex), uvRef(uvRef), nextRef(nextRef) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// All child nodes that generate code will be added together.
class ShaderAdditiveCombiner : public ShaderNode {
    std::vector<ShaderNode*> subNodes;

public:
    inline ShaderAdditiveCombiner() {}
    inline ShaderAdditiveCombiner(const std::vector<ShaderNode*>& n) : subNodes(n) {}

    inline void addNode(ShaderNode* n) { subNodes.push_back(n); }
    
    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Perform a binary operation on two subnodes.  Can also generate a function with two params if
// isOperator is null.
class ShaderOp : public ShaderNode {
    ShaderNode* n1;
    ShaderNode* n2;
    std::string op;
    bool isOperator;
    bool needsAll;

public:
    inline ShaderOp(ShaderNode* n1, ShaderNode* n2, const std::string& op, bool isOperator, bool needsAll = false) :
        n1(n1), n2(n2), op(op), isOperator(isOperator), needsAll(needsAll) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Used to save an expression off to a temporary variable, which prevents repeating the expression
// multiple times in the shader program.  The code generated is just the temporary variable name,
// but the child node's expression will be added to the shader as a temporary value.
class ShaderTempRef : public ShaderNode {
    std::string name;
    ShaderNode* body;

public:
    inline ShaderTempRef(GLKShaderVarType t, const std::string& name, ShaderNode* n) :
        name(name), body(n) { type = t; }

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Perform diffuse attenuation given a vector to a light, and the light's diffuse attenuation parameters.
class ShaderAttenuator : public ShaderNode {
    ShaderNode* toLight;
    ShaderNode* atten;
public:
    inline ShaderAttenuator(ShaderNode* toLight, ShaderNode* atten) :
        toLight(toLight), atten(atten) { type = GLKS_FLOAT; }

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Calculate a normalized reflection vector given a source vector and a normal about which to reflect.
class ShaderReflNode : public ShaderNode {
    ShaderNode* norm;
    ShaderNode* src;
public:
    inline ShaderReflNode(ShaderNode* norm, ShaderNode* src) : norm(norm), src(src) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Adds custom code to the child node's code.  Useful for debugging and other catch-all code that
// doesn't need its own node type.
class ShaderCustom : public ShaderNode {
    std::string before, after;
    ShaderNode* inner;
    bool useInner;
public:
    inline ShaderCustom(const std::string& before, const std::string& after = "", ShaderNode* inner = nullptr, bool useInner = true) :
        before(before), after(after), inner(inner), useInner(useInner) {}
    inline ShaderCustom(GLKShaderVarType t, const std::string& before) :
        before(before), after(""), inner(nullptr), useInner(false) { type = t; }

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Perform the diffuse lighting calculations for a light.
class ShaderLighter : public ShaderNode {
    ShaderNode* lightDir;
    ShaderNode* normal;
    ShaderNode* color;
    ShaderNode* atten;

public:
    inline ShaderLighter(ShaderNode* lightDir, ShaderNode* normal, ShaderNode* color, ShaderNode* atten) :
        lightDir(lightDir), normal(normal), color(color), atten(atten) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Perform the specular calculations for a light.
class ShaderSpecLighter : public ShaderNode {
    ShaderNode* lightDir;
    ShaderNode* cameraDir;
    ShaderNode* normal;
    ShaderNode* color;
    ShaderNode* atten;

public:
    inline ShaderSpecLighter(ShaderNode* lightDir, ShaderNode* cameraDir, ShaderNode* normal,
                             ShaderNode* color, ShaderNode* atten) :
        lightDir(lightDir), cameraDir(cameraDir), normal(normal), color(color), atten(atten) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Perform spotlight attenuation for a light.
class ShaderSpotlightAtten : public ShaderNode {
    ShaderNode* lightDir;
    ShaderNode* params;
    ShaderNode* dir;

public:
    inline ShaderSpotlightAtten(ShaderNode* lightDir, ShaderNode* params, ShaderNode* dir) :
        lightDir(lightDir), params(params), dir(dir) { type = GLKS_FLOAT; }

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Combine n1 and n2, if blend/n1 is not found, only n2 is used.
class ShaderAffineBlend : public ShaderNode {
    ShaderNode* blendNode;
    ShaderNode* n1;
    ShaderNode* n2;

public:
    inline ShaderAffineBlend(ShaderNode* blendNode, ShaderNode* n1, ShaderNode* n2) :
        blendNode(blendNode), n1(n1), n2(n2) {}

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Calculate a linear fog blend value, given a depth and the fog parameters.  See the
// GLES 1.1 or GLKit docs for the exact calculations.
class ShaderLinearFog : public ShaderNode {
    ShaderNode* depthRef;
    ShaderNode* fogParams;

public:
    inline ShaderLinearFog(ShaderNode* depthRef, ShaderNode* fogParams) :
        depthRef(depthRef), fogParams(fogParams) { type = GLKS_FLOAT; }

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

// Calculate an exponentialfog blend value, given a depth and the fog parameters.  See the
// GLES 1.1 or GLKit docs for the exact calculations.
class ShaderExpFog : public ShaderNode {
    ShaderNode* depthRef;
    ShaderNode* densityRef;
    bool squared;

public:
    inline ShaderExpFog(ShaderNode* depthRef, ShaderNode* densityRef, bool squared) :
        depthRef(depthRef), densityRef(densityRef), squared(squared) { type = GLKS_FLOAT; }

    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

class ShaderVertexOnly : public ShaderNode {
    ShaderNode* inner;
public:
    inline ShaderVertexOnly(ShaderNode* inner) : inner(inner) { type = inner->getType(); }
    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};

class ShaderPixelOnly : public ShaderNode {
    ShaderNode* inner;
public:
    inline ShaderPixelOnly(ShaderNode* inner) : inner(inner) { type = inner->getType(); }
    virtual bool generate(std::string& out, ShaderContext& c, ShaderLayout& v) override;
};
