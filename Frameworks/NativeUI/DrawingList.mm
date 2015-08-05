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

#include "Starboard.h"

#include <math.h>
#include <pthread.h>
#include <malloc.h>

#include <vector>
#include <algorithm>

#include "EbrGLES.h"
#include "Platform/EbrPlatform.h"
#include "EbrShaderLib.h"
#include "ShadersList.h"
#include "NativeUI/NativeUI.h"
#include "NativeUI/EbrTexture.h"
#include "NativeUI/Clipping.h"

#include "Etc.h"
#include "FontAtlas.h"

// Should correspond to DrawOperations::drawTypes array.
#define DRAWTYPE_STRIP      0
#define DRAWTYPE_FAN        1
#define DRAWTYPE_LIST       2
#define DRAWTYPE_CULLED     3

#define MAX_VERTICES    2048

DrawingList _drawingList;

static DWORD _numClipped = 0;
static DWORD _drewQuads = 0;
static DWORD _numCulled = 0;

static EbrComPtr<ID3D11BlendState> _srcAlphaBlend;
static EbrComPtr<ID3D11BlendState> _destAlphaCreate;
static EbrComPtr<ID3D11BlendState> _destAlphaCombine;
static EbrComPtr<ID3D11BlendState> _destAlphaUse;
static ID3D11DepthStencilState *_depthStencilDisabled = NULL;
static ID3D11DepthStencilState *_depthStencilWrite = NULL;
static ID3D11DepthStencilState *_depthStencilReadOnly = NULL;

void InitDrawingList(ID3D11Device1 *device)
{
    CD3D11_BLEND_DESC blendDesc = CD3D11_BLEND_DESC(CD3D11_DEFAULT());

    // For normal texturing.
    blendDesc.RenderTarget[0].BlendEnable = TRUE;

    blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
    blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
    blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

    blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
    blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
    blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

    blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

    HRESULT hr = device->CreateBlendState(&blendDesc, _srcAlphaBlend.ReleaseAndGetAddressOf());
    if (FAILED(hr)) {
        EbrThrowFatal(0, "ERROR: unable to create blend state!");
    }

    // Regular rendering, targeting alpha channel only.
    blendDesc.RenderTarget[0].BlendEnable = TRUE;

    blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;
    blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

    blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALPHA;

    hr = device->CreateBlendState(&blendDesc, _destAlphaCreate.ReleaseAndGetAddressOf());
    if (FAILED(hr)) {
        EbrThrowFatal(0, "ERROR: unable to create blend state!");
    }

    // Mask/overlay alpha combiner:
    blendDesc.RenderTarget[0].BlendEnable = TRUE;

    blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
    blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_SRC_ALPHA;
    blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

    blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALPHA;

    hr = device->CreateBlendState(&blendDesc, _destAlphaCombine.ReleaseAndGetAddressOf());
    if (FAILED(hr)) {
        EbrThrowFatal(0, "ERROR: unable to create blend state!");
    }

    // Overlay rendering:
    blendDesc.RenderTarget[0].BlendEnable = TRUE;

    blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_DEST_ALPHA;
    blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_DEST_ALPHA;
    blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

    blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_RED | D3D11_COLOR_WRITE_ENABLE_GREEN | D3D11_COLOR_WRITE_ENABLE_BLUE;
    
    hr = device->CreateBlendState(&blendDesc, _destAlphaUse.ReleaseAndGetAddressOf());
    if (FAILED(hr)) {
        EbrThrowFatal(0, "ERROR: unable to create blend state!");
    }
    
#if NATIVEUI_3D
    D3D11_DEPTH_STENCIL_DESC dsd;
    memset(&dsd, 0, sizeof(dsd));

    dsd.DepthEnable = FALSE;
    if (FAILED(device->CreateDepthStencilState(&dsd,&_depthStencilDisabled))) {
        EbrThrowFatal(0, "ERROR: unable to create depth stencil state object!\n");
    }
    
    dsd.DepthEnable = TRUE;
    dsd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
    dsd.DepthFunc = D3D11_COMPARISON_LESS;

    if (FAILED(device->CreateDepthStencilState(&dsd,&_depthStencilWrite))) {
        EbrThrowFatal(0, "ERROR: unable to create depth stencil state object!\n");
    }

    dsd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
    if (FAILED(device->CreateDepthStencilState(&dsd,&_depthStencilReadOnly))) {
        EbrThrowFatal(0, "ERROR: unable to create depth stencil state object!\n");
    }

#endif

#if USE_DYN_TEXTURE_ATLASING
    if (!_drawingList.init(device)) {
        EbrThrowFatal(0, "ERROR: dynamic texture atlas initialization failed!\n");
    }
#endif 
}

void TermDrawingList()
{
    _drawingList.disconnect();

    _srcAlphaBlend = nullptr;
#if NATIVEUI_3D
    if (_depthStencilDisabled) {
        _depthStencilDisabled->Release();
        _depthStencilDisabled = NULL;
    }
    if (_depthStencilWrite) {
        _depthStencilWrite->Release();
        _depthStencilWrite = NULL;
    }
    if(_depthStencilReadOnly) {
        _depthStencilReadOnly->Release();
        _depthStencilReadOnly = NULL;
    }
#endif 
}

void DrawingOperation::CalcSortKey()
{
    // Draw no-alpha ops first (front to back) alpha dest write operations next, and regular alpha operations last.

    if (_mode == ADM_ALPHA_DEST_BLEND) {
        _sortKey = 6 << 12;                          // alpha component
        _sortKey += (size_t)(_opIdx);                // order of ops.  back to front for alpha.
    } else if(_mode == ADM_ALPHA_WRITE) {
        _sortKey = 5 << 12;                          // alpha component
        _sortKey += (size_t)(_opIdx);                // order of ops.  back to front for alpha.
    } else if ((_mode == ADM_ALPHA_BLEND) || (_mode == ADM_FONT_BLEND)) {
        _sortKey = 3 << 12;                          // alpha component
        _sortKey += (size_t)(_opIdx);                // order of ops.  back to front for alpha.
    } else {
        _sortKey = 0;                                // alpha component (no alpha goes first)
        _sortKey += (((1 << 12) - 1) - ((size_t)(_opIdx))); // order of ops.  front to back for non-alpha.
    }
}

DrawingList::DrawingList()
{
    for(size_t i = 0; i < MAX_OPERATIONS; i ++) {
        _operations[i] = _operationArray + i;
    }
}

bool DrawingList::init(ID3D11Device* device)
{
    return true;
}

void DrawingList::disconnect()
{
#if USE_DYN_TEXTURE_ATLASING
    _atlas.disconnect();
#endif 
}

void DrawingList::Reset()
{
    _curState = 0;
    _curClipState = 0;
    _numOperations = 0;
    _curTransform[0] = CATransform3DMakeTranslation(0, 0, 0);
    _curClip[0].origin.x = 0;
    _curClip[0].origin.y = 0;
    _curClip[0].size.width = GetCACompositor()->screenWidth();
    _curClip[0].size.height = GetCACompositor()->screenHeight();
    curTransform = &_curTransform[0];
    curClip = &_curClip[0];
    _numQuads = 0;
    _numCounts = 0;
    _maskDepth = 0;
    _maskActive = false;
    _maskInConstruction = false;

#if USE_NATIVEUI_Z_OPTIMIZATION
    _doZOptimization = true;
    _doZSort = true;
    _doZCulling = true;
#else
    _doZOptimization = false;    
    _doZSort = false;
    _doZCulling = false;
#endif 

    _culler.Reset();

        
    // Keep the log spam to a minimum for the time being.
    // EbrDebugLog("Quads: %d, %d clipped, %dKB allocated\n",
    //         _drewQuads, _numClipped, totalAlloced / 1024);
    // EbrDebugLog("Z optimization was %s, Z sort %s, %d culled\n", _drawingList.didZOptimization() ? "on!" : "off :(",
    //         _drawingList.didZSort() ? "enabled" : "disabled", _numCulled);

    _drewQuads = 0; // TODO: resurrect old stats, we do the culling in AddOperation
    _numCulled = 0;
    _numClipped = 0;
}

int DrawingList::GetTransformedPosition(CAPoint3D *quad, int numQuads, CAPoint3D *outputQuads)
{
    if ( memcmp(curClip, &CGRectNull, sizeof(CGRect)) == 0) return 0;

    CAPoint3D *srcQuad = quad;
    CAPoint3D *destQuad = outputQuads;
    int ret = 0;

    for ( int i = 0; i < numQuads; i ++ ) {

        // Get next quad.
        memcpy(destQuad, srcQuad, 4 * sizeof(CAPoint3D));

        srcQuad += 4;

        CATransform3DTransformPoints(*curTransform, destQuad, 4);
        destQuad += 4;

        ret ++;
    }

    return ret;
}

bool DrawingList::GetClippedPosition(CAPoint3D *quad, int numQuads, CAPoint3D *screenPos)
{
    if ( memcmp(curClip, &CGRectNull, sizeof(CGRect)) == 0) return false;

    CAPoint3D *srcQuad = quad;
    CAPoint3D *destQuad = screenPos;

    for ( int i = 0; i < numQuads; i ++ ) {
        // Get next quad.
        memcpy(destQuad, srcQuad, 4 * sizeof(CAPoint3D));

        srcQuad += 4;

        CATransform3DTransformPoints(*curTransform, destQuad, 4);

        // Perform clip code testing, we'll need this in any case.
        int clipCodes[4] = {
            CalcClipCodes(curClip, destQuad[0]),
            CalcClipCodes(curClip, destQuad[1]),
            CalcClipCodes(curClip, destQuad[2]),
            CalcClipCodes(curClip, destQuad[3])
        };

        int combinedClip = clipCodes[0] | clipCodes[1] | clipCodes[2] | clipCodes[3];
        if (combinedClip) // ie, needs clipping.
        {
            // Completely outside region?
            if (clipCodes[0] & clipCodes[1] & clipCodes[2] & clipCodes[3]) {
                return false;
            }

            // TODO: null checks for the texturing stuff, there's not even a reason to
            // redo UVs if we are untextured.
            
            //  Can only do simple clipping for native controls, just a bounding box
            for ( int j = 0; j < 4; j ++ ) {
                int curCC = clipCodes[j];
                if ( curCC & CC_OFF_TOP ) destQuad[j].y = curClip->origin.y;
                if ( curCC & CC_OFF_BOTTOM ) destQuad[j].y = curClip->origin.y + curClip->size.height;
                if ( curCC & CC_OFF_LEFT ) destQuad[j].x = curClip->origin.x;
                if ( curCC & CC_OFF_RIGHT ) destQuad[j].x = curClip->origin.x + curClip->size.width;
            }
        }

        destQuad += 4;
    }

    return true;
}

void DrawingList::PushMask()
{
    assert(_maskInConstruction == false);

    _maskDepth ++;
    _maskActive = false;
    _maskInConstruction = true;
}

void DrawingList::MaskConstructed()
{
    _maskActive = true;
    _maskInConstruction = false;
}

void DrawingList::PopMask()
{
    if (_maskDepth <= 0) {
        EbrDebugLog("WARNING: popping a mask that doesn't exist!");
        return;
    }

    _maskDepth --;
    _maskActive = false;
    _maskInConstruction = false;
}

extern DisplayTextureTiled *g_cornerTex;

void DrawingList::AddOperation(CAPoint3D *quad, CGPoint *texquad, int numQuads, 
                               EbrTexture *texture, float alpha, AlphaDrawMode mode, 
                               float r, float g, float b, float a, 
                               DrawingObserver *observer, bool sdfFont)
{
    if ((_numOperations >= MAX_OPERATIONS) ||
        (_numQuads + 4 * numQuads >= MAX_QUADS)) {
        EbrThrowFatal(0, "MAX_OPERATIONS or MAX_QUADS exceeded!\n");
    }
    if ( memcmp(curClip, &CGRectNull, sizeof(CGRect)) == 0) return;

#if USE_DYN_TEXTURE_ATLASING
    float uvScales[4];
    EbrTexture* atlas = NULL;
    if (texture) {
        atlas = _atlas.lookup(texture, uvScales);
        if (atlas) texture = atlas;
    }
#endif 
    
    DrawingOperation *cur = _operations[_numOperations];

    alpha = a * alpha; // combine two alpha components.

    cur->_type = DOT_DrawQuad;
    cur->_quadIdx = _numQuads;
    cur->_countIdx = _numCounts;

    cur->_texture = texture;
    if (mode == ADM_NO_ALPHA && alpha < 1.f) mode = ADM_ALPHA_BLEND;

    // Adjust alpha mode for masking operations.
    if (mode == ADM_ALPHA_BLEND) {
        if (_maskInConstruction) {
            mode = ADM_ALPHA_WRITE;
        } else if (_maskActive) {
            mode = ADM_ALPHA_DEST_BLEND;
        }
    }

    cur->_mode = mode;
    
    cur->_stencilMode = SDM_NONE;
    
    cur->_skip = false;
    cur->_numQuads = 0;
    if (mode == ADM_FONT_BLEND) {
        cur->_shader = sdfFont ? ES_FONT_SDF : ES_FONT;
    } else {
        if (texture == NULL) {
            cur->_shader = ES_SOLID;
        } else if((r == 1.f) && (g == 1.f) && (b == 1.f) && (alpha == 1.f)) {
            cur->_shader = ES_TEXTURED;
        } else {
            cur->_shader = ES_TEXCOLOR;
        }
    }

    /* No premultiply */
    cur->_clr[0] = r;
    cur->_clr[1] = g;
    cur->_clr[2] = b;
    cur->_clr[3] = alpha;
    cur->_observer = observer;

    cur->_opIdx = static_cast<float>(_numOperations);

    cur->CalcSortKey();
    
    CAPoint3D *srcQuad = quad;
    CGPoint *srcTexQuad = texquad;
    CAPoint3D *destQuad = _drawQuads + _numQuads;
    CAPoint3D *origDestQuad = destQuad;
    CGPoint *destTexQuad = texquad ? (_texQuads + _numQuads) : NULL;
    short int *destCount = _drawCounts + _numCounts;
    int8 *destType = _drawTypes + _numCounts;

    for ( int i = 0; i < numQuads; i ++ ) {

        // Get next quad.
        memcpy(destQuad, srcQuad, 4 * sizeof(CAPoint3D));
        if (texquad) {
#if !USE_DYN_TEXTURE_ATLASING
            memcpy(destTexQuad, srcTexQuad, 4 * sizeof(CGPoint));
#else
            if (!atlas) {
                memcpy(destTexQuad, srcTexQuad, 4 * sizeof(CGPoint));                
            } else {
                for (int j = 0; j < 4; j++) {
                    destTexQuad[j].x = srcTexQuad[j].x * uvScales[0] + uvScales[2];
                    destTexQuad[j].y = srcTexQuad[j].y * uvScales[1] + uvScales[3];
                }
            }
#endif 
        }

        srcQuad += 4;
        srcTexQuad += 4;

        CATransform3DTransformPoints(*curTransform, destQuad, 4); // TODO: roll in with shader?

        // if the caller starts specifying z values then we cannot monkey with them.
        if( destQuad[0].z > 0.f || destQuad[1].z > 0.f || destQuad[2].z > 0.f || destQuad[3].z > 0.f ) {
            _doZOptimization = false;
            _doZSort = false;
            _doZCulling = false;
        }

        // Perform clip code testing, we'll need this in any case.
        int clipCodes[4] = {
            CalcClipCodes(curClip, destQuad[0]),
            CalcClipCodes(curClip, destQuad[1]),
            CalcClipCodes(curClip, destQuad[2]),
            CalcClipCodes(curClip, destQuad[3])
        };

        int combinedClip = clipCodes[0] | clipCodes[1] | clipCodes[2] | clipCodes[3];
        if (combinedClip) // ie, needs clipping.
        {
            // Completely outside region?
            if (clipCodes[0] & clipCodes[1] & clipCodes[2] & clipCodes[3]) {
                _numClipped ++;
                continue;
            }

            // TODO: null checks for the texturing stuff, there's not even a reason to
            // redo UVs if we are untextured.
            
            // Do we need to take the slow route?
            if (!QuadIsAxisAligned(destQuad)) {
                *destType = DRAWTYPE_FAN;
                *destCount = QuadClip(curClip, clipCodes, combinedClip, destQuad,
                                      (texture != NULL) ? destTexQuad : NULL);
                if (!*destCount) {
                    _numClipped ++;
                    continue;
                }
            } else {
                *destType = DRAWTYPE_STRIP;
                *destCount = 4;

                if (texture == NULL) {
                    for ( int j = 0; j < 4; j ++ ) {
                        int curCC = clipCodes[j];
                        if ( curCC & CC_OFF_TOP ) destQuad[j].y = curClip->origin.y;
                        if ( curCC & CC_OFF_BOTTOM ) destQuad[j].y = curClip->origin.y + curClip->size.height;
                        if ( curCC & CC_OFF_LEFT ) destQuad[j].x = curClip->origin.x;
                        if ( curCC & CC_OFF_RIGHT ) destQuad[j].x = curClip->origin.x + curClip->size.width;
                    }                   
                } else {
                    CAPoint3D p1 = destQuad[0];
                    CAPoint3D p2 = destQuad[1];
                    CAPoint3D p3 = destQuad[2];

                    CGPoint uv1 = destTexQuad[0];
                    CGPoint uv2 = destTexQuad[1];
                    CGPoint uv3 = destTexQuad[2];

                    CAPoint3D v0 = p3 - p1;
                    CAPoint3D v1 = p2 - p1;

                    float dot00 = v0.dot(v0);
                    float dot01 = v0.dot(v1);
                    float dot11 = v1.dot(v1);

                    for ( int j = 0; j < 4; j ++ ) {

                        int curCC = clipCodes[j];
                        if ( curCC & CC_OFF_TOP ) destQuad[j].y = curClip->origin.y;
                        if ( curCC & CC_OFF_BOTTOM ) destQuad[j].y = curClip->origin.y + curClip->size.height;
                        if ( curCC & CC_OFF_LEFT ) destQuad[j].x = curClip->origin.x;
                        if ( curCC & CC_OFF_RIGHT ) destQuad[j].x = curClip->origin.x + curClip->size.width;

                        if ( curCC ) {
                            CAPoint3D v2 = destQuad[j] - p1;

                            // Compute dot products
                            float dot02 = v0.dot(v2);
                            float dot12 = v1.dot(v2);

                            // Compute barycentric coordinates
                            float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
                            float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
                            float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

                            CGPoint t2 = uv2-uv1;
                            CGPoint t1 = uv3-uv1;

                            CGPoint newuv = uv1 + t1*u + t2*v;

                            destTexQuad[j].x = newuv.x;
                            destTexQuad[j].y = newuv.y;
                        }
                    }
                }
            }
        } else {
            *destType = DRAWTYPE_STRIP;
            *destCount = 4;
        }

        if ( *destType == DRAWTYPE_STRIP && *destCount == 4 ) {
            //  If there is more than 1 quad, use a triangle list so that they can
            //  all be drawn at once
            destQuad[5] = destQuad[3];
            destQuad[4] = destQuad[2];
            destQuad[3] = destQuad[1];

            if ( texquad ) {
                destTexQuad[5] = destTexQuad[3];
                destTexQuad[4] = destTexQuad[2];
                destTexQuad[3] = destTexQuad[1];
            }

            *destType = DRAWTYPE_LIST;
            *destCount = 6;
        }

        cur->_numQuads ++;
        destQuad += *destCount;
        destTexQuad += *destCount;
        destType ++;
        destCount ++;
    }

    if(cur->_numQuads) {
        _numOperations ++;
        _numQuads += (destQuad - origDestQuad);
        _numCounts += cur->_numQuads;
    } else {
        cur->_skip = true;
        if ( observer ) observer->operationWasClipped();
    }
}

void DrawingList::PushClip(CAPoint3D *quad)
{
    _curClipState ++;
    _curClip[_curClipState] = _curClip[_curClipState - 1];
    curClip = &_curClip[_curClipState];

    CAPoint3D transformed[4];
    memcpy(transformed, quad, 4 * sizeof(CAPoint3D));
    CATransform3DTransformPoints(*curTransform, (CAPoint3D *) transformed, 4);
    CGRect clipRect;
    clipRect.origin.x = min(min(min(transformed[0].x, transformed[1].x), transformed[2].x), transformed[3].x);
    clipRect.origin.y = min(min(min(transformed[0].y, transformed[1].y), transformed[2].y), transformed[3].y);
    clipRect.size.width = max(max(max(transformed[0].x, transformed[1].x), transformed[2].x), transformed[3].x) - clipRect.origin.x;
    clipRect.size.height = max(max(max(transformed[0].y, transformed[1].y), transformed[2].y), transformed[3].y) - clipRect.origin.y;
    clipRect = CGRectStandardize(clipRect);
    *curClip = CGRectIntersection(*curClip, clipRect);
}

void DrawingList::PopClip()
{
    _curClipState --;
    curClip = &_curClip[_curClipState];
}

void DrawingList::PushMatrix()
{
    _curState ++;
    if ( _curState >= 32 ) {
        *((char *) 0) = 0;
    }
    _curTransform[_curState] = _curTransform[_curState - 1];
    curTransform = &_curTransform[_curState];
}

void DrawingList::PopMatrix()
{
    _curState --;
    curTransform = &_curTransform[_curState];
}

struct CompareOp {
    inline bool operator()(const DrawingOperation* op1, const DrawingOperation* op2)
    {
        return (op1->SortKey() < op2->SortKey());
    }
};

void DrawingList::SortOperations()
{
    if (_doZOptimization && _numOperations > 1) {

        // sort ops.
        if (_doZSort || _doZCulling) {
            auto sorter = [](const DrawingOperation* lhs, const DrawingOperation* rhs) {
                // We want to render things without alpha first:
                if (lhs->_mode == ADM_NO_ALPHA) {
                    if (rhs->_mode == ADM_NO_ALPHA) {
                        // Draw non-alpha front-to-back:
                        return lhs->_opIdx > rhs->_opIdx;
                    }
                    return true;
                }
                if (rhs->_mode == ADM_NO_ALPHA) return false;
                // Draw alpha stuff back-to-front:
                return lhs->_opIdx < rhs->_opIdx;
            };
            std::sort(_operations, _operations + _numOperations, sorter);
        }
    }

    // adjust z coord by operation number.  we want the ones that occurred first to have
    // a higher z value.
    // NOTE: this can probably be done in the shader.
    float zscale = 0.95f / (static_cast<float>(_numOperations) + 1);  // avoid putting things at the very start and end of the z buffer
    for ( int i = 0; i < _numOperations; i ++ ) {
        DrawingOperation *cur = _operations[i];
        CAPoint3D *quad = _drawQuads + cur->_quadIdx;

        int quadCount = 0;
        short int *counts = _drawCounts + cur->_countIdx;
        for ( int j = 0; j < cur->_numQuads; j ++ ) quadCount += counts[j];         

        float z = zscale * ((_numOperations - cur->_opIdx) + 1);
        for ( int j = 0; j < quadCount; j ++ ) {
            quad[j].z = z;
        }
    }

    if (!_doZOptimization || _numOperations == 1) {
        return;
    }
    
    // set up Z culler.
    if (_doZCulling) {
        for (int i = 0; i < _numOperations; i ++) {
            DrawingOperation *cur = _operations[i];
            CAPoint3D *quad = _drawQuads + cur->_quadIdx;
            CAPoint3D *quadEnd = _drawQuads + cur->_quadIdx + cur->_numQuads;           
            int8 *types = _drawTypes + cur->_countIdx;
            short int *counts = _drawCounts + cur->_countIdx;

            if ( cur->_type != DOT_DrawQuad ) continue;
            
            CGPoint mn = CGPoint::point(min(quad[0].x, quad[3].x), min(quad[0].y, quad[3].y)); // TODO: BK: assumes axis alignment.
            CGPoint mx = CGPoint::point(max(quad[0].x, quad[3].x), max(quad[0].y, quad[3].y)); // TODO: BK: assumes axis alignment.

            if (!cur->isAlphaOp()) {
                for (int j = 0; j < cur->_numQuads;) {
                    if ((*types == DRAWTYPE_STRIP) && QuadIsAxisAligned(quad) &&
                        !_culler.InsertQuad(mn, mx, cur->_opIdx)) {

                        // Opaque ops sorted front to back, should work with culler.
                        *types = DRAWTYPE_CULLED;
                        _numCulled ++;
                    }
                    
                    quad += *counts;
                    j ++; // next!
                    types ++;
                    counts ++;
                }
            } else {
                for (int j = 0; j < cur->_numQuads;) {
                    // TODO: BK: test non-aligned quads here with a conservative bbox.
                    if ((*types == DRAWTYPE_STRIP) && QuadIsAxisAligned(quad) &&
                        !_culler.TestAlpha(mn, mx, cur->_opIdx)) {

                        *types = DRAWTYPE_CULLED;
                        _numCulled ++;
                    }
                    
                    quad += *counts;
                    j ++; // next!
                    types ++;
                    counts ++;
                }
            }
            if (!cur->_numQuads) cur->_skip = true;
        }
    }
}

extern bool dxLandscape;

#if NATIVEUI_3D
    #define INVERT(x)
#else 
    #define INVERT(point) if ( dxLandscape ) { float tmp = (point).y; (point).y = (point).x; (point).x = tmp; } else { ((point).y = -(point).y); }
#endif 

inline void EbrDXSetBlending(ID3D11DeviceContext *context, AlphaDrawMode mode, int numOps)
{
    switch (mode) {
      case ADM_NO_ALPHA:
      {
          static FLOAT mix[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
          context->OMSetBlendState(NULL, mix, 0xFFFFFFFF);
      }
      break;

      case ADM_ALPHA_BLEND:
      case ADM_FONT_BLEND:
      {
          context->OMSetBlendState(_srcAlphaBlend.Get(), NULL, 0xFFFFFFFF);
      }
      break;

      case ADM_ALPHA_WRITE:
      {
          static FLOAT mix[4] = { 1.f, 1.f, 1.f, 1.f };
          context->OMSetBlendState(_destAlphaCreate.Get(), mix, 0xFFFFFFFF);
      }
      break;

      case ADM_ALPHA_DEST_BLEND:
      {
          static FLOAT mix[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
          context->OMSetBlendState(_destAlphaUse.Get(), mix, 0xFFFFFFFF);
      }
      break;
    };

#if NATIVEUI_3D
    if (mode == ADM_ALPHA_WRITE || mode == ADM_ALPHA_DEST_BLEND) {
        context->OMSetDepthStencilState(_depthStencilDisabled, 0);
    } else {
        // If there's only one operation (ie, a fullscreen quad from an opengl app), don't enable
        // depth testing since it'll only be a waste of fillrate.
        if (numOps > 1) {
            context->OMSetDepthStencilState(_depthStencilWrite, 0);
        }
        else {
            context->OMSetDepthStencilState(_depthStencilDisabled, 0);
        }
    }
#endif 
}
 
extern int g_numVerts;
 
void DrawingList::DrawOperations(ID3D11Device1 *device, ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget, ID3D11DepthStencilView *depthTarget)
{
    EbrShaderNewFrame();
    //EbrAlwaysLog("--------------------------------------------------------------------------------\n");

#if USE_DYN_TEXTURE_ATLASING
    _atlas.update(device, context);
#endif

    int i = 0;

    AlphaDrawMode curMode = ADM_NO_ALPHA;
    StencilDrawMode curStencilMode = SDM_NONE;
    EbrShader curShader = ES_NONE;
    EbrDXSetBlending(context, curMode, _numOperations);

    for ( ;; ) {
        static PositionTexColorVertex vertices[MAX_VERTICES];
        int numVertices = 0;

        EbrTexture *bindTexture = NULL;
        bool first = true;
        for ( ; i < _numOperations; i ++ ) {
            DrawingOperation *cur = _operations[i];
            EbrTexture *curTexture = NULL;
            if (cur->_skip) {
                if ( cur->_observer ) cur->_observer->operationWasClipped();
                continue;
            }

            // Ignore stencil ops for now.
            if (cur->_type != DOT_DrawQuad ) continue;

            const short int *counts = _drawCounts + cur->_countIdx;
            const int8 *types = _drawTypes + cur->_countIdx;
            int quad = cur->_quadIdx;
            EbrShader requestedShader = cur->ShaderType();

            curTexture = cur->_texture;

            if (!first && ((curTexture != bindTexture) || (curShader != requestedShader))) break;
            first = false;
            curShader = requestedShader;

            AlphaDrawMode alphaMode = cur->AlphaMode();
            if (alphaMode != curMode) {
                EbrDXSetBlending(context, alphaMode, _numOperations);
                curMode = alphaMode;
            }

            StencilDrawMode stencilMode = cur->StencilMode();
            if (stencilMode != curStencilMode) {
                // TODO: code goes here!
                curStencilMode = stencilMode;
            }

            bindTexture = curTexture;

            int j = 0;
            bool didDraw = false;

            while (j < cur->_numQuads) {
                switch ( *types ) {
                  case DRAWTYPE_LIST:
                      didDraw = true;
                      if ( cur->_clr[3] > 0.0f ) {
                          for ( int k = 0; k < *counts; k ++ ) {
#if NATIVEUI_3D
                              vertices[numVertices].x = _drawQuads[quad + k].x;
                              vertices[numVertices].y = _drawQuads[quad + k].y;
                              vertices[numVertices].z = _drawQuads[quad + k].z;
#else 
                              vertices[numVertices].x = (_drawQuads[quad + k].x / GetCACompositor()->screenWidth() * 2.0f) - 1.0f;
                              vertices[numVertices].y = (_drawQuads[quad + k].y / GetCACompositor()->screenHeight() * 2.0f) - 1.0f;
#endif
                              vertices[numVertices].r = cur->_clr[0];
                              vertices[numVertices].g = cur->_clr[1];
                              vertices[numVertices].b = cur->_clr[2];
                              vertices[numVertices].a = cur->_clr[3];

                              if ( curTexture != NULL ) {
                                  vertices[numVertices].u = _texQuads[quad + k].x;
                                  vertices[numVertices].v = _texQuads[quad + k].y;
                              } else {
                                  vertices[numVertices].u = 0.0f;
                                  vertices[numVertices].v = 0.0f;
                              }
                              INVERT(vertices[numVertices]);
                              numVertices ++;
                              assert(numVertices < MAX_VERTICES);
                          }
                      }
                      break;

                  case DRAWTYPE_FAN:
                      didDraw = true;
                      if ( cur->_clr[3] > 0.0f ) {
                          PositionTexColorVertex root;
                          PositionTexColorVertex last;

#if NATIVEUI_3D
                          root.x = _drawQuads[quad].x;
                          root.y = _drawQuads[quad].y;
                          root.z = _drawQuads[quad].z;
#else
                          root.x = (_drawQuads[quad].x / GetCACompositor()->screenWidth() * 2.0f) - 1.0f;
                          root.y = (_drawQuads[quad].y / GetCACompositor()->screenHeight() * 2.0f) - 1.0f;
#endif 
                          root.r = cur->_clr[0];
                          root.g = cur->_clr[1];
                          root.b = cur->_clr[2];
                          root.a = cur->_clr[3];
                          if ( curTexture != NULL ) {
                              root.u = _texQuads[quad].x;
                              root.v = _texQuads[quad].y;
                          }
                          else {
                              root.u = 0.0f;
                              root.v = 0.0f;
                          }
                          INVERT(root);

#if NATIVEUI_3D
                          last.x = _drawQuads[quad + 1].x;
                          last.y = _drawQuads[quad + 1].y;
                          last.z = _drawQuads[quad + 1].z;
#else
                          last.x = (_drawQuads[quad + 1].x / GetCACompositor()->screenWidth() * 2.0f) - 1.0f;
                          last.y = (_drawQuads[quad + 1].y / GetCACompositor()->screenHeight() * 2.0f) - 1.0f;
#endif
                          last.r = cur->_clr[0];
                          last.g = cur->_clr[1];
                          last.b = cur->_clr[2];
                          last.a = cur->_clr[3];
                          if (curTexture != NULL) {
                              last.u = _texQuads[quad + 1].x;
                              last.v = _texQuads[quad + 1].y;
                          }
                          else {
                              last.u = 0.0f;
                              last.v = 0.0f;
                          }
                          INVERT(last);

                          for (int k = 2; k < *counts; k++) {
                              vertices[numVertices] = root;
                              numVertices ++;

                              vertices[numVertices] = last;
                              numVertices++;

#if NATIVEUI_3D
                              vertices[numVertices].x = _drawQuads[quad + k].x;
                              vertices[numVertices].y = _drawQuads[quad + k].y;
                              vertices[numVertices].z = _drawQuads[quad + k].z;
#else
                              vertices[numVertices].x = (_drawQuads[quad + k].x / GetCACompositor()->screenWidth() * 2.0f) - 1.0f;
                              vertices[numVertices].y = (_drawQuads[quad + k].y / GetCACompositor()->screenHeight() * 2.0f) - 1.0f;
#endif 
                              vertices[numVertices].r = cur->_clr[0];
                              vertices[numVertices].g = cur->_clr[1];
                              vertices[numVertices].b = cur->_clr[2];
                              vertices[numVertices].a = cur->_clr[3];

                              if (curTexture != NULL) {
                                  vertices[numVertices].u = _texQuads[quad + k].x;
                                  vertices[numVertices].v = _texQuads[quad + k].y;
                              }
                              else {
                                  vertices[numVertices].u = 0.0f;
                                  vertices[numVertices].v = 0.0f;
                              }
                              INVERT(vertices[numVertices]);
                              last = vertices[numVertices];
                              numVertices++;
                          }
                      }
                      break;
                } // end switch
                quad += *counts;
                counts ++;
                types ++;
                j ++;
            }            

            if ( cur->_observer ) {
                if ( !didDraw ) {
                    cur->_observer->operationWasClipped();
                } else {
                    cur->_observer->operationDidDraw();
                }
            }
        }

        g_numVerts += numVertices;

        if (numVertices > 0) {
            //ScopedTimer t("drawOp");
            
            static char* alphaNames[] = {
                "ADM_NO_ALPHA",
                "ADM_ALPHA_BLEND",
                "ADM_FONT_BLEND",
                "ADM_ALPHA_WRITE",
                "ADM_ALPHA_DEST_BLEND"
            };

            static char* shaderNames[] = {
                "ES_SOLID",
                "ES_TEXTURED",
                "ES_TEXCOLOR",
                "ES_FONT"
            };

#if NATIVEUI_3D
            //EbrAlwaysLog("    Draw %d verts, shader=%s tex=0x%x, alpha mode %s, depth %f\n", numVertices, shaderNames[curShader], bindTexture, alphaNames[curMode], vertices[numVertices - 1].z);
#else
            //EbrAlwaysLog("    Draw %d verts, shader=%s tex=0x%x, alpha mode %s\n", numVertices, shaderNames[curShader], bindTexture, alphaNames[curMode]);
#endif
            
            Shader *s = EbrShaderGet(curShader);
            EbrDXSetBlending(context, curMode, _numOperations);
            if ( bindTexture ) {
                bindTexture->AcquireDeviceLock(device);
                ID3D11ShaderResourceView* srv = bindTexture->GetSRV(device);

                if (curMode == ADM_ALPHA_DEST_BLEND) {
                    context->OMSetBlendState(_destAlphaCombine.Get(), nullptr, 0xFFFFFFFF);
                    s->draw(context, renderTarget, depthTarget, srv, vertices, numVertices);
                    context->OMSetBlendState(_destAlphaUse.Get(), nullptr, 0xFFFFFFFF);
                }

                s->draw(context, renderTarget, depthTarget, srv, vertices, numVertices);

                bindTexture->ReleaseDeviceLock(device);
            } else {
                s->draw(context, renderTarget, depthTarget, NULL, vertices, numVertices);                
            }
        }

        if ( i >= _numOperations ) break;
    }

#if USE_DYN_TEXTURE_ATLASING
    _atlas.report();
#endif 
}

#if USE_DYN_TEXTURE_ATLASING
void DrawingListUnreferenceTexture(EbrTexture* t)
{
    _drawingList._atlas.remove(t);
}
#endif 
