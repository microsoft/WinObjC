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

#include "NativeUIBase.h"
#include "CullTree.h"
#include "EbrShaderLib.h"
#include "DynTextureAtlas.h"

#define MAX_OPERATIONS  8192
#define MAX_QUADS       32768

enum DrawingOperationType
{
    DOT_DrawQuad
};

class EbrTexture;
struct ID3D11DeviceContext;
struct ID3D11RenderTargetView;
struct ID3D11DepthStencilView;
struct ID3D11Device1;

class DrawingOperation
{
public:
    DrawingOperationType    _type;
    size_t                  _sortKey;
    EbrTexture*             _texture;
    void*                   texture;
    AlphaDrawMode           _mode;
    StencilDrawMode         _stencilMode;
    EbrShader               _shader;
    bool                    _skip;
        
    int                     _numQuads;
    float                   _clr[4];
    int                     _quadIdx;
    float                   _opIdx;
    int                     _countIdx;
    DrawingObserver*        _observer;
        
    inline size_t           SortKey() const         { return _sortKey; }
    inline AlphaDrawMode    AlphaMode() const       { return _mode; }
    inline StencilDrawMode  StencilMode() const     { return _stencilMode; }
    inline EbrShader        ShaderType() const      { return _shader; }
    inline bool             isAlphaOp() const       { return _mode != ADM_NO_ALPHA; }

    void CalcSortKey();
};

class DrawingList
{
    DrawingOperation _operationArray[MAX_OPERATIONS];
    DrawingOperation* _operations[MAX_OPERATIONS];

    CGPoint _texQuads[MAX_QUADS];
    CAPoint3D _drawQuads[MAX_QUADS];
    int _numQuads;

    int _numOperations;

    short int _drawCounts[MAX_QUADS];
    int8 _drawTypes[MAX_QUADS];
    int _numCounts; // for both drawTypes and drawCounts.

    CATransform3D _curTransform[128];
    CGRect        _curClip[128];
    int _curState, _curClipState;

    bool        _doZOptimization;
    bool        _doZSort;      // should be false for PowerVR stuff, they do tile-based deferred rendering.
    bool        _doZCulling;    // requires Z sort on.

    CullTree    _culler;

    int         _maskDepth;
    bool        _maskActive;
    bool        _maskInConstruction;
    
public:
#if USE_DYN_TEXTURE_ATLASING
    DynTextureAtlas _atlas;
#endif 

    DrawingList();

    bool init(ID3D11Device* device);
    void disconnect();
    
    CATransform3D *curTransform;
    CGRect        *curClip;

    void Reset();
    void PushClip(CAPoint3D *quad);
    void PopClip();
    void PushMatrix();
    void PopMatrix();
    void SortOperations();
    void DrawOperations(ID3D11Device1 *device, ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget, ID3D11DepthStencilView *depthTarget);
    void AddOperation(CAPoint3D *quad, CGPoint *texquad, int numQuads, EbrTexture *texture, float alpha, AlphaDrawMode mode, float r, float g, float b, float a, DrawingObserver *observer, bool sdfFont = false);
    int GetTransformedPosition(CAPoint3D *quad, int numQuads, CAPoint3D *screenPos);
    bool GetClippedPosition(CAPoint3D *quad, int numQuads, CAPoint3D *screenPos);

    // Masking operations.
    void PushMask();
    void MaskConstructed();
    void PopMask();
    
    inline bool didZOptimization() const    { return _doZOptimization; } // used for debug status.
    inline bool didZSort() const            { return _doZSort; }
};

void InitDrawingList(ID3D11Device1 *device);
void TermDrawingList();

#if USE_DYN_TEXTURE_ATLASING
void DrawingListUnreferenceTexture(EbrTexture* t);
#else
inline void DrawingListUnreferenceTexture(EbrTexture* t) {}
#endif 

extern DrawingList _drawingList;

