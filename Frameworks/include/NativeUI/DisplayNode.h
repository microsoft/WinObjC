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

#include "DrawingList.h"
#include "QuartzCore/CALayer.h"

class ClippingRegion;
class DrawingOperation;

class DisplayAnimationRef;
class DisplayTexture;
class DisplayAnimation;

class DisplayNode : private DrawingObserver
{
public:
    DisplayNode  *parentNode;
    DisplayNode **subnodes;
    int           numSubnodes;
    int           maxSubnodes;

    DisplayNode  *maskNode;

    DisplayTexture     *pTexture, *pBackgroundTexture;

    DisplayAnimationRef *animations;

    bool                refreshOnDraw;

    CAPoint3D           worldQuad[4], contentQuad[4];

    bool                visiblePresentationPropertiesSet;
    CADisplayProperties visiblePresentationProperties;
    CADisplayProperties presentationProperties;
    CADisplayProperties originalPresentationProperties;

    uint32_t      refCount;
    BOOL          topMost;
    bool          isRootNode;
    float         topWindowLevel;

public:
    bool mutated;
    DisplayNode();
    DisplayNode(DisplayNode *cloneNode);
    ~DisplayNode();

    void AddAnimation(DisplayAnimation *anim);
    void RemoveAnimation(DisplayAnimation *anim);
    bool CalcWorldQuad();
    void RenderStencil();
    void RenderBackground(float alpha);
    void RenderBorder(float alpha);
    void Render(float alpha, float afterChildren = false);
    void RenderLine(CAPoint3D start, CAPoint3D end);
    void RenderCorner(CAPoint3D pt, int orientation);

    void AddSubnode(DisplayNode *pNode);
    void AddSubnodeBefore(DisplayNode *pNode, DisplayNode *pBeforeNode);
    void AddSubnodeAfter(DisplayNode *pNode, DisplayNode *pAfterNode);
    void MoveSubnodeBefore(DisplayNode *pNode, DisplayNode *pBeforeNode);
    void MoveSubnodeAfter(DisplayNode *pNode, DisplayNode *pAfterNode);
    void RemoveSubnode(DisplayNode *pNode);
    void Render(ClippingRegion *clip, CGPoint origin, float alpha = 1.0f);
    void Reset();
    DisplayNode *Clone();
    DisplayNode *GetParentNode();

    void Release();
    void AddRef();

    //  Listener events
    virtual void operationWasClipped();
    virtual void drawingBegan();
    virtual void drawingEnded();
    virtual void operationDidDraw();
};

