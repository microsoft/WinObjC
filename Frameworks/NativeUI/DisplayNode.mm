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
#include "CGContextInternal.h"
#include "UIKit/UIImage.h"

#include "NativeUI/NativeUI.h"
#include "EbrGLES.h"

#include <math.h>
#include <vector>

#if USE_GL
#include "EbrOpenglIncludes.h"
#endif

static int numLayers = 0;
int _totalDisplayNodes = 0;
extern BOOL refreshPending;

#define LOG_REFS(...)

DisplayNode::DisplayNode()
{
    refCount = 0;
    parentNode = NULL;
    numSubnodes = 0;
    subnodes = NULL;
    mutated = false;
    topMost = false;
    refreshOnDraw = false;
    isRootNode = false;
    topWindowLevel = 0;

    maskNode = nullptr;

    maxSubnodes = 16;
    subnodes = (DisplayNode **) realloc(subnodes, sizeof(DisplayNode *) * maxSubnodes);

    numLayers ++;
    memset(&originalPresentationProperties, 0, sizeof(CADisplayProperties));
    memset(&presentationProperties, 0, sizeof(CADisplayProperties));

    originalPresentationProperties.anchorPoint.x = 0.5f;
    originalPresentationProperties.anchorPoint.y = 0.5f;

    originalPresentationProperties.contentsRect.origin.x = 0.0f;
    originalPresentationProperties.contentsRect.origin.y = 0.0f;
    originalPresentationProperties.contentsRect.size.width = 1.0f;
    originalPresentationProperties.contentsRect.size.height = 1.0f;

    originalPresentationProperties.contentsCenter.origin.x = 0.0f;
    originalPresentationProperties.contentsCenter.origin.y = 0.0f;
    originalPresentationProperties.contentsCenter.size.width = 1.0f;
    originalPresentationProperties.contentsCenter.size.height = 1.0f;

    originalPresentationProperties.contentsScale = 1.0f;
    originalPresentationProperties.opacity = 1.0f;
    originalPresentationProperties.contentColor.r = 1.0f;
    originalPresentationProperties.contentColor.g = 1.0f;
    originalPresentationProperties.contentColor.b = 1.0f;
    originalPresentationProperties.contentColor.a = 1.0f;
    originalPresentationProperties.transform = CATransform3DMakeTranslation(0, 0, 0);
    originalPresentationProperties.sublayerTransform = CATransform3DMakeTranslation(0, 0, 0);
    
    visiblePresentationPropertiesSet = false;
    pTexture = NULL;
    pBackgroundTexture = NULL;

    animations = new DisplayAnimationRef();

    LOG_REFS("DisplayNode created\n");
    _totalDisplayNodes ++;
#ifdef LOG_OBJECT_COUNTS
    EbrDebugLog("Display nodes: %d\n", _totalDisplayNodes);
#endif
}

DisplayNode::DisplayNode(DisplayNode *node)
{
    assert(node->refCount > 0);
    refCount = 0;
    mutated = false;
    parentNode = NULL;
    numSubnodes = 0;
    subnodes = NULL;
    maskNode = nullptr;
    mutated = false;
    topMost = false;
    isRootNode = false;
    refreshOnDraw = false;
    topWindowLevel = node->topWindowLevel;

    maxSubnodes = 16;
    subnodes = (DisplayNode **) realloc(subnodes, sizeof(DisplayNode *) * maxSubnodes);

    for ( int i = 0; i < node->numSubnodes; i ++ ) {
        AddSubnode(node->subnodes[i]->Clone());
    }

    numLayers ++;
    originalPresentationProperties = node->originalPresentationProperties;
    presentationProperties = originalPresentationProperties;
    pTexture = node->pTexture;
    pBackgroundTexture = node->pBackgroundTexture;

    if ( pTexture ) {
        pTexture->AddRef();
    }
    if ( pBackgroundTexture ) {
        pBackgroundTexture->AddRef();
    }

    animations = new DisplayAnimationRef();
    LLTREE_FOREACH(curanimation, node->animations)
    {
        DisplayAnimation *cloned = curanimation->_animation->Clone();
        AddAnimation(cloned);
    }

    LOG_REFS("DisplayNode created\n");
    _totalDisplayNodes ++;
#ifdef LOG_OBJECT_COUNTS
    EbrDebugLog("Display nodes: %d\n", _totalDisplayNodes);
#endif
}

DisplayNode::~DisplayNode()
{
    numLayers --;

    for ( int i = 0; i < numSubnodes; i ++ ) {
        subnodes[i]->Release();
    }

    free(subnodes);

    if ( pTexture ) {
        pTexture->Release();
    }
    if ( pBackgroundTexture ) {
        pBackgroundTexture->Release();
    }
    if ( maskNode ) {
        maskNode->Release();
    }
    LLTREE_FOREACH(curanimation, animations)
    {
        curanimation->_animation->_ownerNode = NULL;
        curanimation->_animation->Release();
        delete curanimation;
    }
    delete animations;

    LOG_REFS("DisplayNode destroyed\n");
    _totalDisplayNodes --;
#ifdef LOG_OBJECT_COUNTS
    EbrDebugLog("Display nodes: %d\n", _totalDisplayNodes);
#endif
}

DisplayNode *DisplayNode::GetParentNode()
{
    return parentNode;
}

DisplayNode *DisplayNode::Clone()
{
    DisplayNode *ret = new DisplayNode(this);

    return ret;
}

void DisplayNode::AddSubnode(DisplayNode *pNode)
{
    if (pNode->refCount < 0) {
        assert(0);
    }
    mutated = true;
    pNode->AddRef();

    assert(pNode->parentNode == NULL);

    if ( numSubnodes >= maxSubnodes ) {
        maxSubnodes += 16;
        subnodes = (DisplayNode **) realloc(subnodes, sizeof(DisplayNode *) * maxSubnodes);
    }

    pNode->parentNode = this;
    subnodes[numSubnodes ++] = pNode;
}

void DisplayNode::AddSubnodeBefore(DisplayNode *pNode, DisplayNode *pBeforeNode)
{
    if (pNode->refCount < 0) {
        assert(0);
    }
    assert(pBeforeNode->refCount > 0);
    mutated = true;
    pNode->AddRef();

    if ( numSubnodes >= maxSubnodes ) {
        maxSubnodes += 16;
        subnodes = (DisplayNode **) realloc(subnodes, sizeof(DisplayNode *) * maxSubnodes);
    }

    pNode->parentNode = this;

    int i;
    for ( i = 0; i < numSubnodes; i ++ ) {
        if ( subnodes[i] == pBeforeNode ) {
            memmove(&subnodes[i + 1], &subnodes[i], sizeof(DisplayNode *) * (numSubnodes - i));
            subnodes[i] = pNode;
            numSubnodes ++;
            break;
        }
    }

    assert(i != numSubnodes);
}

void DisplayNode::AddSubnodeAfter(DisplayNode *pNode, DisplayNode *pAfterNode)
{
    if (pNode->refCount < 0) {
        assert(0);
    }
    assert(pAfterNode->refCount > 0);
    mutated = true;
    pNode->AddRef();

    if ( numSubnodes >= maxSubnodes ) {
        maxSubnodes += 16;
        subnodes = (DisplayNode **) realloc(subnodes, sizeof(DisplayNode *) * maxSubnodes);
    }

    pNode->parentNode = this;

    int i;
    for ( i = 0; i < numSubnodes; i ++ ) {
        if ( subnodes[i] == pAfterNode ) {
            i ++;

            if ( i < numSubnodes ) {
                memmove(&subnodes[i + 1], &subnodes[i], sizeof(DisplayNode *) * (numSubnodes - i));
            }

            subnodes[i] = pNode;
            numSubnodes ++;
            break;
        }
    }

    assert(i != numSubnodes);
}

void DisplayNode::MoveSubnodeBefore(DisplayNode *pNode, DisplayNode *pBeforeNode)
{
    if (pNode->refCount < 0) {
        assert(0);
    }
    assert(pBeforeNode->refCount > 0);

    assert(pNode->parentNode == pBeforeNode->parentNode);
    if ( pNode == pBeforeNode ) return;

    //  Remove existing node
    bool found = false;
    for ( int i = 0; i < numSubnodes; i ++ ) {
        if ( subnodes[i] == pNode ) {
            memmove(&subnodes[i], &subnodes[i + 1], (numSubnodes - i) * sizeof(DisplayNode *));
            numSubnodes --;
            found = true;
            break;
        }
    }

    if (found == false ) {
        assert(0);
    }

    int i;
    for ( i = 0; i < numSubnodes; i ++ ) {
        if ( subnodes[i] == pBeforeNode ) {
            memmove(&subnodes[i + 1], &subnodes[i], sizeof(DisplayNode *) * (numSubnodes - i));
            subnodes[i] = pNode;
            numSubnodes ++;
            break;
        }
    }

    assert(i != numSubnodes);
}

void DisplayNode::MoveSubnodeAfter(DisplayNode *pNode, DisplayNode *pAfterNode)
{
    if (pNode->refCount < 0) {
        assert(0);
    }
    assert(pAfterNode->refCount > 0);

    assert(pNode->parentNode == pAfterNode->parentNode);
    if ( pNode == pAfterNode ) return;

    //  Remove existing node
    bool found = false;
    for ( int i = 0; i < numSubnodes; i ++ ) {
        if ( subnodes[i] == pNode ) {
            memmove(&subnodes[i], &subnodes[i + 1], (numSubnodes - i) * sizeof(DisplayNode *));
            numSubnodes --;
            found = true;
            break;
        }
    }

    if (found == false ) {
        assert(0);
    }

    int i;
    for ( i = 0; i < numSubnodes; i ++ ) {
        if ( subnodes[i] == pAfterNode ) {
            i ++;

            if ( i < numSubnodes ) {
                memmove(&subnodes[i + 1], &subnodes[i], sizeof(DisplayNode *) * (numSubnodes - i));
            }

            subnodes[i] = pNode;
            numSubnodes ++;
            break;
        }
    }

    assert(i != numSubnodes);
}

void DisplayNode::RemoveSubnode(DisplayNode *pNode)
{
    assert(pNode->refCount > 0);
    assert(refCount > 0);
    mutated = true;
    bool found = false;

    assert(pNode->parentNode == this);

    for ( int i = 0; i < numSubnodes; i ++ ) {
        if ( subnodes[i] == pNode ) {
            memmove(&subnodes[i], &subnodes[i + 1], (numSubnodes - i) * sizeof(DisplayNode *));
            numSubnodes --;
            found = true;
            break;
        }
    }

    if (found == false ) {
        assert(0);
    }

    pNode->parentNode = NULL;
    pNode->Release();
}

void DisplayNode::Release()
{
    if ( refCount == 0 ) {
        assert(0);
    }

    if ( EbrDecrement((int *) &refCount) == 0 ) {
        delete this;
    }
}

void DisplayNode::AddRef()
{
    EbrIncrement((int *) &refCount);
}

int compareZ(const void *a, const void *b)
{
    DisplayNode *node1 = *((DisplayNode **) a);
    DisplayNode *node2 = *((DisplayNode **) b);

    if ( node1->presentationProperties.zPosition == node2->presentationProperties.zPosition ) {
        if ( a > b ) return 1;

        return -1;
    } else if ( node1->presentationProperties.zPosition > node2->presentationProperties.zPosition ) {
        return 1;
    } else {
        return -1;
    }
}

void SortNodes(DisplayNode **nodes, int count)
{
    qsort(nodes, count, sizeof(DisplayNode *), compareZ);
}

void DisplayNode::Render(ClippingRegion *clip, CGPoint origin, float alpha)
{
    assert(refCount > 0);

    if ( presentationProperties.forceOverrideBounds ) {
        presentationProperties.bounds.size = presentationProperties.overrideBounds.size;
    }

    memcpy(&visiblePresentationProperties, &presentationProperties, sizeof(CADisplayProperties));
    visiblePresentationPropertiesSet = true;

    if ( presentationProperties.hidden || alpha * presentationProperties.opacity <= 0.01f ) 
    {
        refreshOnDraw = false;
        return;
    }

    static int depth = 0;

    /*
    for ( int i = 0; i < depth; i ++ ) EbrDebugLog(" ");
    EbrDebugLog("{%f, %f}-{%f, %f} texNum=%d\n",
        presentationProperties.position.x, presentationProperties.position.y, 
        presentationProperties.bounds.size.width, presentationProperties.bounds.size.height, pTexture? pTexture->texNum : -1);
    */
    depth ++;

    _drawingList.PushMatrix();

    if ( parentNode != NULL ) {
        *_drawingList.curTransform = CATransform3DConcat(*_drawingList.curTransform, parentNode->presentationProperties.sublayerTransform);
    }

    CATransform3D transMatrix;
    transMatrix = CATransform3DMakeTranslation(presentationProperties.position.x - origin.x, presentationProperties.position.y - origin.y, 0.0f);

    if ( presentationProperties.forceOverrideBounds ) {
        transMatrix = CATransform3DTranslate(transMatrix, presentationProperties.overrideBounds.origin.x, presentationProperties.overrideBounds.origin.y, 0.0f);
    }

    *_drawingList.curTransform = CATransform3DConcat(transMatrix, *_drawingList.curTransform);
    *_drawingList.curTransform = CATransform3DConcat(presentationProperties.transform, *_drawingList.curTransform);

    bool didPushClip = false;
    bool didPushLocalClip = false;

    bool clipWorldRect = CalcWorldQuad();
    if ( presentationProperties.masksToBounds && numSubnodes > 0 ) {
        clip->PushClippingLayer(this);
        _drawingList.PushClip(worldQuad);
        didPushClip = true;
    }

    bool renderAfterChildren = false;

    if ( pTexture && pTexture->renderAfterChildren() ) renderAfterChildren = true;

    //  In some layout modes, the content may end up outside the world
    //  region, so we have to clip it
    if ( (clipWorldRect || pBackgroundTexture != NULL) && !didPushClip ) {
        clip->PushClippingLayer(this);
        _drawingList.PushClip(worldQuad);
        didPushLocalClip = true;
    }

    alpha *= presentationProperties.opacity;

    DrawingOperation *stencilCornerOp = NULL;
    if ( presentationProperties.cornerRadius > 0.0f ) {
        //stencilCornerOp = _drawingList.AddCornerStencilOperation(worldQuad, presentationProperties.cornerRadius, true);
    }

    if (maskNode) {
        _drawingList.PushMask();
        maskNode->Render(clip, origin, alpha);
        _drawingList.MaskConstructed();
    }

    if ( pTexture == NULL || presentationProperties.gravity != kGravityResize ) {
        RenderBackground(alpha);
    }
    
    if ( pTexture != NULL ) {
        Render(alpha);
    }
    RenderBorder(alpha);

    //  Pop any local cliping we did for the content region
    if ( didPushLocalClip ) {
        clip->PopClippingLayer();
        _drawingList.PopClip();
    }

    if ( renderAfterChildren ) _drawingList.PushMatrix();

    *_drawingList.curTransform = CATransform3DTranslate(*_drawingList.curTransform, -presentationProperties.bounds.origin.x, -presentationProperties.bounds.origin.y, 0);

    //glTranslatef(-presentationProperties.bounds.origin.x, -presentationProperties.bounds.origin.y, 0);

    origin.x = presentationProperties.bounds.size.width * presentationProperties.anchorPoint.x;
    origin.y = presentationProperties.bounds.size.height * presentationProperties.anchorPoint.y;

    //  Draw subnodes
    for ( int i = 0; i < numSubnodes; i ++ ) {
        subnodes[i]->Render(clip, origin, alpha);
    }

    if ( renderAfterChildren ) {
        _drawingList.PopMatrix();
        Render(alpha, true);
    }

    if (maskNode) {
        _drawingList.PopMask();
    }

    /*
    if ( stencilCornerOp ) {
        DrawingOperation *stencilCornerRemoveOp = _drawingList.AddCornerStencilOperation(worldQuad, presentationProperties.cornerRadius, false);
        int tmp = (int) stencilCornerOp->_opIdx;
        stencilCornerOp->_opIdx = stencilCornerRemoveOp->_opIdx;
        stencilCornerRemoveOp->_opIdx = (float) tmp;
    }*/

    if ( didPushClip ) {
        clip->PopClippingLayer();
        _drawingList.PopClip();
    }

    _drawingList.PopMatrix();
    refreshOnDraw = false;

    depth--;
}

void DisplayNode::Reset()
{
    presentationProperties = originalPresentationProperties;

    //  Reset subnodes
    for ( int i = 0; i < numSubnodes; i ++ ) {
        subnodes[i]->Reset();
    }

    if (maskNode) maskNode->Reset();
}

void DisplayNode::AddAnimation(DisplayAnimation *anim)
{
    anim->AddRef();

    assert(anim->_ownerNode == NULL);

    DisplayAnimationRef *newRef = new DisplayAnimationRef();
    newRef->_animation = anim;
    newRef->_appliedToNode = this;
    anim->_ownerNode = newRef;
    animations->addChildAfter(newRef, NULL);

    _activeAnimations.AddActiveAnimation(anim);
}

void DisplayNode::RemoveAnimation(DisplayAnimation *anim)
{    
    if ( anim->_ownerNode == NULL ) {
        EbrDebugLog("Warning: Animation %x already removed\n", anim);
        return;
    }
    if ( anim->_ownerNode->_appliedToNode != this ) {
        EbrDebugLog("Warning: Animation %x does not belong to %x (belongs to %x)\n", anim, this, anim->_ownerNode->_appliedToNode);
        return;
    }

    if ( !anim->_hasStopped ) {
        anim->_hasStopped = true;
        anim->Stopped(this);
        anim->_fireFinished = TRUE;
    }

    DisplayAnimationRef *animRef = anim->_ownerNode;
    animations->removeChild(animRef);
    anim->_ownerNode = NULL;
    delete animRef;

    anim->Release();
}

void DisplayNode::RenderStencil()
{
    CGPoint quad[4];

#if USE_GL
    EbrDisableTextures();
    glDisable(GL_BLEND);
    glColorMask(0, 0, 0, 0);
#endif

    quad[0].x = -presentationProperties.bounds.size.width * presentationProperties.anchorPoint.x;
    quad[0].y = -presentationProperties.bounds.size.height * presentationProperties.anchorPoint.y;
    quad[1].x = presentationProperties.bounds.size.width * (1.0f -  presentationProperties.anchorPoint.x);
    quad[1].y = -presentationProperties.bounds.size.height * presentationProperties.anchorPoint.y;
    quad[2].x = -presentationProperties.bounds.size.width * presentationProperties.anchorPoint.x;
    quad[2].y = presentationProperties.bounds.size.height * (1.0f - presentationProperties.anchorPoint.y);
    quad[3].x = presentationProperties.bounds.size.width * (1.0f - presentationProperties.anchorPoint.x);
    quad[3].y = presentationProperties.bounds.size.height * (1.0f - presentationProperties.anchorPoint.y);

    EbrGLESInitDraw();
    EbrGLESSetTexturing(TM_DISABLED);
    EbrGLESSet2DArrays(quad, NULL);

    g_numQuads ++;
#if USE_GL
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
#endif
}

void DisplayNode::RenderBackground(float alpha)
{
    DrawingObserver *observer = refreshOnDraw ? this : NULL;

    CAPoint3D quad[4];

    quad[0].x = -presentationProperties.bounds.size.width * presentationProperties.anchorPoint.x;
    quad[0].y = -presentationProperties.bounds.size.height * presentationProperties.anchorPoint.y;
    quad[0].z = 0;
    quad[1].x = presentationProperties.bounds.size.width * (1.0f -  presentationProperties.anchorPoint.x);
    quad[1].y = -presentationProperties.bounds.size.height * presentationProperties.anchorPoint.y;
    quad[1].z = 0;
    quad[2].x = -presentationProperties.bounds.size.width * presentationProperties.anchorPoint.x;
    quad[2].y = presentationProperties.bounds.size.height * (1.0f - presentationProperties.anchorPoint.y);
    quad[2].z = 0;
    quad[3].x = presentationProperties.bounds.size.width * (1.0f - presentationProperties.anchorPoint.x);
    quad[3].y = presentationProperties.bounds.size.height * (1.0f - presentationProperties.anchorPoint.y);
    quad[3].z = 0;

    float aOut = presentationProperties.backgroundColor.a * alpha;

    if ( aOut != 0.0f || pBackgroundTexture != NULL ) {
        if ( pBackgroundTexture == NULL ) {
            _drawingList.AddOperation(quad, NULL, 1, NULL, alpha, ADM_NO_ALPHA, presentationProperties.backgroundColor.r,
                      presentationProperties.backgroundColor.g,
                      presentationProperties.backgroundColor.b,
                      aOut, observer);
        } else {
            CGPoint texquad[4];
            CGPoint topLeft, bottomRight;

            topLeft.x = quad[0].x;
            topLeft.y = quad[0].y;
            bottomRight.x = quad[3].x;
            bottomRight.y = quad[3].y;
            
            CGPoint startLeft = topLeft - presentationProperties.bounds.origin;
            float rollUp = presentationProperties.bounds.origin.y;
            if ( rollUp < 0 ) {
                while ( rollUp < 0 ) {
                    startLeft.y -= pBackgroundTexture->_height;
                    rollUp += pBackgroundTexture->_height;
                }
            } else {
                while ( rollUp > pBackgroundTexture->_height ) {
                    startLeft.y += pBackgroundTexture->_height;
                    rollUp -= pBackgroundTexture->_height;
                }
            }

            for ( float y = startLeft.y; y < bottomRight.y; y += pBackgroundTexture->_height ) {
                for ( float x = startLeft.x; x < bottomRight.x; x += pBackgroundTexture->_width ) {
                    quad[0].x = x;
                    quad[0].y = y;
                    quad[1].x = x + pBackgroundTexture->_width;
                    quad[1].y = y;
                    quad[2].x = x;
                    quad[2].y = y + pBackgroundTexture->_height;
                    quad[3].x = x + pBackgroundTexture->_width;
                    quad[3].y = y + pBackgroundTexture->_height;

                    texquad[0].x = 0; texquad[0].y = 0;
                    texquad[1].x = 1; texquad[1].y = 0;
                    texquad[2].x = 0; texquad[2].y = 1;
                    texquad[3].x = 1; texquad[3].y = 1;

                    pBackgroundTexture->addOperation(&presentationProperties, quad, texquad, 1, alpha, 1.0f, 1.0f, 1.0f, 1.0f, observer);
                }
            }
        }
    } else {
        //  Since animations apply to subnodes, it's possible to have a blank view that still has relevant
        //  animated subnodes to display, so we still need to know if it's clipped or not
        if ( observer ) {
            _drawingList.AddOperation(quad, NULL, 1, NULL, alpha, ADM_NO_ALPHA, presentationProperties.backgroundColor.r,
                      presentationProperties.backgroundColor.g,
                      presentationProperties.backgroundColor.b,
                      aOut, observer);
        }
    }
}

bool DisplayNode::CalcWorldQuad()
{
    memset(worldQuad, 0, sizeof(CAPoint3D) * 4);

    CGSize contentsScaledSize = presentationProperties.contentsSize;
    contentsScaledSize.width /= presentationProperties.contentsScale;
    contentsScaledSize.height /= presentationProperties.contentsScale;

    //  If the image is stretchable, set the content size to the full bounds of the node
    if ( presentationProperties.contentsCenter.origin.x != 0.0f || presentationProperties.contentsCenter.size.width != 1.0f ) {
        if ( presentationProperties.bounds.size.width > contentsScaledSize.width ) {
            contentsScaledSize.width = presentationProperties.bounds.size.width;
        }
    }
    if ( presentationProperties.contentsCenter.origin.y != 0.0f || presentationProperties.contentsCenter.size.height != 1.0f ) {
        if ( presentationProperties.bounds.size.height > contentsScaledSize.height ) {
            contentsScaledSize.height = presentationProperties.bounds.size.height;
        }
    }
    switch ( presentationProperties.contentsOrientation ) {
        case UIImageOrientationRight:
        case UIImageOrientationLeft: {
            //  Swap dimensions
            float temp = contentsScaledSize.width;
            contentsScaledSize.width = contentsScaledSize.height;
            contentsScaledSize.height = temp;
            break;
        }
    }

    worldQuad[0].x = -presentationProperties.bounds.size.width * presentationProperties.anchorPoint.x;
    worldQuad[0].y = -presentationProperties.bounds.size.height * presentationProperties.anchorPoint.y;
    worldQuad[1].x = presentationProperties.bounds.size.width * (1.0f -  presentationProperties.anchorPoint.x);
    worldQuad[1].y = -presentationProperties.bounds.size.height * presentationProperties.anchorPoint.y;
    worldQuad[2].x = -presentationProperties.bounds.size.width * presentationProperties.anchorPoint.x;
    worldQuad[2].y = presentationProperties.bounds.size.height * (1.0f - presentationProperties.anchorPoint.y);
    worldQuad[3].x = presentationProperties.bounds.size.width * (1.0f - presentationProperties.anchorPoint.x);
    worldQuad[3].y = presentationProperties.bounds.size.height * (1.0f - presentationProperties.anchorPoint.y);

    switch ( presentationProperties.gravity ) {
        case kGravityResize:
            memcpy(contentQuad, worldQuad, 4 * sizeof(CAPoint3D));
            break;

        case kGravityAspectFill: {
            float aspectX = presentationProperties.bounds.size.width / contentsScaledSize.width;
            float aspectY = presentationProperties.bounds.size.height / contentsScaledSize.height;
            float aspect = aspectX > aspectY ? aspectX : aspectY;

            float outWidth = contentsScaledSize.width * aspect;
            float outHeight = contentsScaledSize.height * aspect;

            contentQuad[0].x = -outWidth * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -outHeight * presentationProperties.anchorPoint.y;
            contentQuad[1].x = outWidth * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -outHeight * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -outWidth * presentationProperties.anchorPoint.x;
            contentQuad[2].y = outHeight * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = outWidth * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = outHeight * (1.0f - presentationProperties.anchorPoint.y);
        }
            break;

        case kGravityResizeAspect: {
            float aspectX = presentationProperties.bounds.size.width / contentsScaledSize.width;
            float aspectY = presentationProperties.bounds.size.height / contentsScaledSize.height;
            float aspect = aspectX < aspectY ? aspectX : aspectY;

            float outWidth = contentsScaledSize.width * aspect;
            float outHeight = contentsScaledSize.height * aspect;

            contentQuad[0].x = -outWidth * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -outHeight * presentationProperties.anchorPoint.y;
            contentQuad[1].x = outWidth * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -outHeight * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -outWidth * presentationProperties.anchorPoint.x;
            contentQuad[2].y = outHeight * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = outWidth * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = outHeight * (1.0f - presentationProperties.anchorPoint.y);
        }
            break;

        case kGravityCenter:
            contentQuad[0].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[1].x = contentsScaledSize.width * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[2].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = contentsScaledSize.width * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);
            break;

        case kGravityBottom:
        case kGravityTop:
            contentQuad[0].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[1].x = contentsScaledSize.width * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[2].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = contentsScaledSize.width * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);

            contentQuad[0].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[1].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[2].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[3].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            break;

        case kGravityLeft:
            contentQuad[0].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[1].x = contentsScaledSize.width * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[2].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = contentsScaledSize.width * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);

            contentQuad[0].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[1].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[2].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[3].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            break;

        case kGravityRight:
            contentQuad[0].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[1].x = contentsScaledSize.width * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[2].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = contentsScaledSize.width * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);

            contentQuad[0].x += (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[1].x += (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[2].x += (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[3].x += (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            break;

        case kGravityBottomRight:
            contentQuad[0].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[1].x = contentsScaledSize.width * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[2].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = contentsScaledSize.width * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);

            contentQuad[0].x += (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[1].x += (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[2].x += (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[3].x += (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            break;

        case kGravityTopLeft:
            contentQuad[0].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[1].x = contentsScaledSize.width * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[2].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = contentsScaledSize.width * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);

            contentQuad[0].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[1].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[2].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[3].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);

            contentQuad[0].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[1].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[2].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[3].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            break;

        case kGravityTopRight:
            contentQuad[0].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[1].x = contentsScaledSize.width * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[2].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = contentsScaledSize.width * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);

            contentQuad[0].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[1].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[2].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[3].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);

            contentQuad[0].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[1].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[2].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[3].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            break;


        case kGravityBottomLeft:
            contentQuad[0].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[0].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[1].x = contentsScaledSize.width * (1.0f -  presentationProperties.anchorPoint.x);
            contentQuad[1].y = -contentsScaledSize.height * presentationProperties.anchorPoint.y;
            contentQuad[2].x = -contentsScaledSize.width * presentationProperties.anchorPoint.x;
            contentQuad[2].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);
            contentQuad[3].x = contentsScaledSize.width * (1.0f - presentationProperties.anchorPoint.x);
            contentQuad[3].y = contentsScaledSize.height * (1.0f - presentationProperties.anchorPoint.y);

            contentQuad[0].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[1].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[2].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);
            contentQuad[3].y -= (presentationProperties.bounds.size.height / 2.0f) - (contentsScaledSize.height / 2.0f);

            contentQuad[0].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[1].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[2].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            contentQuad[3].x -= (presentationProperties.bounds.size.width / 2.0f) - (contentsScaledSize.width / 2.0f);
            break;

        default:
            assert(0);
            break;
    }

    contentQuad[0].x += presentationProperties.contentsInset.origin.x;
    contentQuad[0].y += presentationProperties.contentsInset.size.height;
    contentQuad[1].x -= presentationProperties.contentsInset.size.width;
    contentQuad[1].y += presentationProperties.contentsInset.size.height;
    contentQuad[2].x += presentationProperties.contentsInset.origin.x;
    contentQuad[2].y -= presentationProperties.contentsInset.origin.y;
    contentQuad[3].x -= presentationProperties.contentsInset.size.width;
    contentQuad[3].y -= presentationProperties.contentsInset.origin.y;

    CGRect r1, r2;

    r1.origin.x = contentQuad[0].x;
    r1.origin.y = contentQuad[0].y;
    r1.size.width = contentQuad[3].x - contentQuad[0].x;
    r1.size.height = contentQuad[3].y - contentQuad[0].y;

    r2.origin.x = worldQuad[0].x;
    r2.origin.y = worldQuad[0].y;
    r2.size.width = worldQuad[3].x - worldQuad[0].x;
    r2.size.height = worldQuad[3].y - worldQuad[0].y;

    if ( !CGRectContainsRect(r2, r1) ) {
        return true;
    } else {
        return false;
    }
}

static int BuildQuad(
    CGRect quadRect, 
    CGRect texRect, 
    float x1, float x2, 
    float y1, float y2,
    float quadX, float quadY,
    float quadX2, float quadY2,
    CAPoint3D *quadOut,
    CGPoint *texOut)
{
    quadOut[0].x = quadRect.origin.x + quadX;
    quadOut[0].y = quadRect.origin.y + quadY;
    quadOut[1].x = quadRect.origin.x + quadX2;
    quadOut[1].y = quadRect.origin.y + quadY;
    quadOut[2].x = quadRect.origin.x + quadX;
    quadOut[2].y = quadRect.origin.y + quadY2;
    quadOut[3].x = quadRect.origin.x + quadX2;
    quadOut[3].y = quadRect.origin.y + quadY2;

    texOut[0].x = texRect.origin.x + texRect.size.width * x1;
    texOut[0].y = texRect.origin.y + texRect.size.height * y1;
    texOut[1].x = texRect.origin.x + texRect.size.width * x2;
    texOut[1].y = texRect.origin.y + texRect.size.height * y1;
    texOut[2].x = texRect.origin.x + texRect.size.width * x1;
    texOut[2].y = texRect.origin.y + texRect.size.height * y2;
    texOut[3].x = texRect.origin.x + texRect.size.width * x2;
    texOut[3].y = texRect.origin.y + texRect.size.height * y2;

    return 1;
}

void DisplayNode::operationWasClipped()
{
}

void DisplayNode::drawingBegan()
{
}

void DisplayNode::drawingEnded()
{
}

void DisplayNode::operationDidDraw()
{
    //  We were not culled and have ongoing animations - issue another frame paint
    GetCACompositor()->RequestRedraw();
}

void DisplayNode::Render(float alpha, float afterChildren)
{
    assert(refCount > 0);

    if ( !pTexture ) {
        return;
    }

    if ( pTexture->_shapeRenderer ) {
        pTexture->_shapeRenderer->RenderShape(&presentationProperties);
    }

    DrawingObserver *observer = refreshOnDraw ? this : NULL;

    assert(pTexture->refCount > 0);

    CGPoint texquad[4];

    if ( pTexture->flipped() ) {
        float origX = presentationProperties.contentsRect.origin.x;
        float origY = presentationProperties.contentsRect.origin.y;

        texquad[0].x = presentationProperties.contentsRect.origin.x;
        texquad[0].y = origY + presentationProperties.contentsRect.size.height;
        texquad[1].x = origX + presentationProperties.contentsRect.size.width;
        texquad[1].y = texquad[0].y;
        texquad[2].x = texquad[0].x;
        texquad[2].y = origY;
        texquad[3].x = texquad[1].x;
        texquad[3].y = texquad[2].y;
    } else {
        texquad[0].x = presentationProperties.contentsRect.origin.x;
        texquad[0].y = presentationProperties.contentsRect.origin.y;
        texquad[1].x = texquad[0].x + presentationProperties.contentsRect.size.width;
        texquad[1].y = texquad[0].y;
        texquad[2].x = texquad[0].x;
        texquad[2].y = texquad[0].y + presentationProperties.contentsRect.size.height;
        texquad[3].x = texquad[1].x;
        texquad[3].y = texquad[2].y;
    }

    switch ( presentationProperties.contentsOrientation ) {
        case UIImageOrientationUp:
            break;

        case UIImageOrientationDown: {
            CGPoint tmp;

            tmp = texquad[0];
            texquad[0] = texquad[3];
            texquad[3] = tmp;

            tmp = texquad[1];
            texquad[1] = texquad[2];
            texquad[2] = tmp;
        }
            break;

        case UIImageOrientationDownMirrored: {
            CGPoint tmp;

            tmp = texquad[0];
            texquad[0] = texquad[2];
            texquad[2] = tmp;

            tmp = texquad[1];
            texquad[1] = texquad[3];
            texquad[3] = tmp;
        }
            break;

        case UIImageOrientationRight: {
            CGPoint tmp;

            tmp = texquad[0];
            texquad[0] = texquad[2];
            texquad[2] = texquad[3];
            texquad[3] = texquad[1];
            texquad[1] = tmp;
            break;
        }

        case UIImageOrientationLeft: {
            CGPoint tmp;

            tmp = texquad[0];
            texquad[0] = texquad[1];
            texquad[1] = texquad[3];
            texquad[3] = texquad[2];
            texquad[2] = tmp;
            break;
        }

        default:
            EbrDebugLog("Unsupported image orientation: %d\n", presentationProperties.contentsOrientation);
            break;
    }

    if ( presentationProperties.contentsCenter.origin.x != 0.0f || presentationProperties.contentsCenter.origin.y != 0.0f ||
         presentationProperties.contentsCenter.size.width != 1.0f || presentationProperties.contentsCenter.size.height != 1.0f ) {
        CAPoint3D quads[36];
        CGPoint texquads[36];

        memset(quads, 0, sizeof(quads));

        CGRect quadRect;
        CGSize contentsSize = presentationProperties.contentsSize;
        contentsSize.width /= presentationProperties.contentsScale;
        contentsSize.height /= presentationProperties.contentsScale;

        quadRect.origin.x = contentQuad[0].x;
        quadRect.origin.y = contentQuad[0].y;
        quadRect.size.width = contentQuad[1].x - contentQuad[0].x;
        quadRect.size.height = contentQuad[2].y - contentQuad[0].y;

        CGRect texRect;
        texRect.origin.x = texquad[0].x;
        texRect.origin.y = texquad[0].y;
        texRect.size.width = texquad[1].x - texquad[0].x;
        texRect.size.height = texquad[2].y - texquad[0].y;

        int numQuads = 0;

        float texX1 = 0;
        float texX2 = presentationProperties.contentsCenter.origin.x;
        float texX3 = presentationProperties.contentsCenter.origin.x + presentationProperties.contentsCenter.size.width;
        float texX4 = 1.0f;

        float texY1 = 0;
        float texY2 = presentationProperties.contentsCenter.origin.y;
        float texY3 = presentationProperties.contentsCenter.origin.y + presentationProperties.contentsCenter.size.height;
        float texY4 = 1.0f;

        float quadX1 = 0;
        float quadX2 = min(contentsSize.width, quadRect.size.width) * presentationProperties.contentsCenter.origin.x;
        float quadX3 = quadRect.size.width - min(contentsSize.width, quadRect.size.width) * (1 - presentationProperties.contentsCenter.origin.x - presentationProperties.contentsCenter.size.width);
        float quadX4 = quadRect.size.width;

        float quadY1 = 0;
        float quadY2 = min(contentsSize.height, quadRect.size.height) * presentationProperties.contentsCenter.origin.y;
        float quadY3 = quadRect.size.height - min(contentsSize.height, quadRect.size.height) * (1 - presentationProperties.contentsCenter.origin.y - presentationProperties.contentsCenter.size.height);
        float quadY4 = quadRect.size.height;

        //assert(quadX1 <= quadX2 && quadX2 <= quadX3 && quadX3 <= quadX4);
        //assert(quadY1 <= quadY2 && quadY2 <= quadY3 && quadY3 <= quadY4);

        //  top left
        numQuads += BuildQuad(quadRect, texRect, 
            texX1, texX2, 
            texY1, texY2, 
            quadX1, quadY1,
            quadX2, quadY2,
            &quads[numQuads * 4],
            &texquads[numQuads * 4]);
        //  top middle
        numQuads += BuildQuad(quadRect, texRect, 
            texX2, texX3,
            texY1, texY2,
            quadX2, quadY1,
            quadX3, quadY2,
            &quads[numQuads * 4],
            &texquads[numQuads * 4]);

        //  top right
        numQuads += BuildQuad(quadRect, texRect, 
            texX3, texX4,
            texY1, texY2,
            quadX3, quadY1, 
            quadX4, quadY2,
            &quads[numQuads * 4],
            &texquads[numQuads * 4]);

        //  middle left
        numQuads += BuildQuad(quadRect, texRect, 
            texX1, texX2,
            texY2, texY3,
            quadX1, quadY2,
            quadX2, quadY3,
            &quads[numQuads * 4],
            &texquads[numQuads * 4]);
        //  middle middle
        numQuads += BuildQuad(quadRect, texRect, 
            texX2, texX3,
            texY2, texY3,
            quadX2, quadY2,
            quadX3, quadY3,
            &quads[numQuads * 4],
            &texquads[numQuads * 4]);
        //  middle right
        numQuads += BuildQuad(quadRect, texRect, 
            texX3, texX4,
            texY2, texY3,
            quadX3, quadY2,
            quadX4, quadY3,
            &quads[numQuads * 4],
            &texquads[numQuads * 4]);

        //  bottom left
        numQuads += BuildQuad(quadRect, texRect, 
            texX1, texX2,
            texY3, texY4,
            quadX1, quadY3,
            quadX2, quadY4,
            &quads[numQuads * 4],
            &texquads[numQuads * 4]);
        //  bottom middle
        numQuads += BuildQuad(quadRect, texRect, 
            texX2, texX3,
            texY3, texY4,
            quadX2, quadY3,
            quadX3, quadY4,
            &quads[numQuads * 4],
            &texquads[numQuads * 4]);
        //  bottom right
        numQuads += BuildQuad(quadRect, texRect, 
            texX3, texX4,
            texY3, texY4,
            quadX3, quadY3,
            quadX4, quadY4,
            &quads[numQuads * 4],
            &texquads[numQuads * 4]);

        if ( !afterChildren ) {
            pTexture->addOperation(&presentationProperties, quads, texquads, numQuads, alpha, presentationProperties.contentColor.r, presentationProperties.contentColor.g, presentationProperties.contentColor.b, presentationProperties.contentColor.a, observer);
        } else {
            pTexture->addOperationAfter(&presentationProperties, contentQuad, texquad, 1, alpha, presentationProperties.contentColor.r, presentationProperties.contentColor.g, presentationProperties.contentColor.b, presentationProperties.contentColor.a, observer);
        }
    } else {
        if ( !afterChildren ) {
            pTexture->addOperation(&presentationProperties, contentQuad, texquad, 1, alpha, presentationProperties.contentColor.r, presentationProperties.contentColor.g, presentationProperties.contentColor.b, presentationProperties.contentColor.a, observer);
        } else {
            pTexture->addOperationAfter(&presentationProperties, contentQuad, texquad, 1, alpha, presentationProperties.contentColor.r, presentationProperties.contentColor.g, presentationProperties.contentColor.b, presentationProperties.contentColor.a, observer);
        }
    }
}

static inline CGPoint _2dVertex(float x, float y)
{
    CGPoint ret;

    ret.x = x;
    ret.y = y;

    return ret;
}

void DrawRoundedSquare(float LineWidth, float x, float y, float radius, float width, float height, float r, float b, float g, float a) 
{  
#if 0
    const float PI = 3.1415926535897932384626433832795f; 
    EbrGLESSetColor(r, b, g, a); // OH GOD
    glLineWidth(LineWidth); 

    CGPoint points[128];
    int numPoints;

    numPoints = 0;
    points[numPoints ++] = _2dVertex(x, y + radius); 
    points[numPoints ++] = _2dVertex(x, y + height - radius);//Left Line 

    points[numPoints ++] = _2dVertex(x + radius, y); 
    points[numPoints ++] = _2dVertex(x + width - radius, y);//Top Line 

    points[numPoints ++] = _2dVertex(x + width, y + radius); 
    points[numPoints ++] = _2dVertex(x + width, y + height - radius);//Right Line 

    points[numPoints ++] = _2dVertex(x + radius, y + height); 
    points[numPoints ++] = _2dVertex(x + width - radius, y + height);//Bottom Line 

    EbrGLESSet2DArrays(points, NULL);
    g_numQuads += numPoints;
    glDrawArrays(GL_LINES, 0, numPoints);

    numPoints = 0;
    float ang=0; 
    float cX= x+radius, cY = y+radius; 
        for(ang = PI; ang <= (1.5*PI); ang = ang + 0.05f) 
        { 
            points[numPoints ++] = _2dVertex(radius* cos(ang) + cX, radius * sin(ang) + cY); //Top Left 
        }  
        cX = x+width-radius; 
    g_numQuads += numPoints;
    glDrawArrays(GL_LINE_STRIP, 0, numPoints);

    numPoints = 0;
        for(ang = (1.5f*PI); ang <= (2 * PI); ang = ang + 0.05f) 
        { 
            points[numPoints ++] = _2dVertex(radius* cos(ang) + cX, radius * sin(ang) + cY); //Top Right 
        } 
    g_numQuads += numPoints;
    glDrawArrays(GL_LINE_STRIP, 0, numPoints);

    numPoints = 0;
        cY = y+height-radius; 
        for(ang = 0; ang <= (0.5*PI); ang = ang + 0.05f) 
        { 
            points[numPoints ++] = _2dVertex(radius* cos(ang) + cX, radius * sin(ang) + cY); //Bottom Right 
        } 
    g_numQuads += numPoints;
    glDrawArrays(GL_LINE_STRIP, 0, numPoints);

    numPoints = 0;
        cX = x+radius; 
        for(ang = (0.5f*PI); ang <= PI; ang = ang + 0.05f) 
        { 
            points[numPoints ++] = _2dVertex(radius* cos(ang) + cX, radius * sin(ang) + cY);//Bottom Left 
        } 
    g_numQuads += numPoints;
    glDrawArrays(GL_LINE_STRIP, 0, numPoints);
#endif
}

typedef struct CAPoint3DLine : CAPoint3D
{
    CAPoint3DLine& operator =(CAPoint3D p)
    {
        x = p.x;
        y = p.y;
        z = p.z;

        return *this;
    }
    CAPoint3D normalize()
    {
        CAPoint3DLine ret;
        ret.x = x;
        ret.y = y;
        ret.z = z;

        float len = sqrt(ret.x * ret.x + ret.y * ret.y);
        ret.x /= len;
        ret.y /= len;

        return ret;
    }
    CAPoint3D normalCross() const
    {
        CAPoint3DLine ret;
        ret.x = y;
        ret.y = x;
        ret.z = z;

        float len = sqrt(ret.x * ret.x + ret.y * ret.y);
        ret.x /= len;
        ret.y /= len;

        return ret;
    }
} CAPoint3DLine;

void DisplayNode::RenderLine(CAPoint3D start, CAPoint3D end)
{
    float thickness = presentationProperties.borderWidth / 2.0f;
    CAPoint3DLine dir;
    
    dir = (end - start);
    if ( presentationProperties.cornerRadius > 0.0f ) {
        start = start + dir.normalize() * presentationProperties.cornerRadius;
        end = end - dir.normalize() * presentationProperties.cornerRadius;
    }
    dir = dir.normalCross();

    CAPoint3D line[4];
    line[0] = start - dir * thickness;
    line[1] = start + dir * thickness;
    line[2] = end - dir * thickness;
    line[3] = end + dir * thickness;

    _drawingList.AddOperation(line, NULL, 1, NULL, 1.0f, ADM_NO_ALPHA, 
        presentationProperties.borderColor.r,
        presentationProperties.borderColor.g, 
        presentationProperties.borderColor.b, 
        presentationProperties.borderColor.a, 
        NULL);
}

class RoundedCornerImages
{
private:
    class RoundedCornerImage
    {
    public:
        float radius, thickness;
        CGImageRef img;
    };
    typedef std::vector<RoundedCornerImage *> roundedCornerImagesList;
    roundedCornerImagesList _images;

public:
    DisplayTexture *getCornerTex(float radius, float lineThickness)
    {
        for ( roundedCornerImagesList::iterator curObj = _images.begin(); curObj != _images.end(); curObj ++ ) {
            RoundedCornerImage *cur = *curObj;
            if ( cur->radius == radius && cur->thickness == lineThickness ) {
                DisplayTextureTiled *pTex = (DisplayTextureTiled *) UIGetDisplayTextureForCGImage(cur->img, true);
                return pTex;
            }
        }

        int iRadius = (int) radius;
        CGContextRef context = CGBitmapContextCreate32((DWORD)(iRadius * GetCACompositor()->screenScale()), (DWORD)(iRadius * GetCACompositor()->screenScale()));
        CGImageRef roundedImage = CGBitmapContextGetImage(context);

        CGContextScaleCTM(context, GetCACompositor()->screenScale(), GetCACompositor()->screenScale());

        CGRect rect = CGRectMake(0.0f, 0.0f, (float)iRadius, (float)iRadius);

        CGContextClearRect(context, rect);
        float color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        CGContextSetStrokeColor(context, color);
        CGContextBeginPath(context);

        float halfWidth = lineThickness / 2.0f;

        CGContextMoveToPoint(context, 0, halfWidth);
        CGContextAddArc(context, 0, (float)iRadius, iRadius - halfWidth, kPi + kPi / 2.0f, kPi * 2.0f, 0);

        CGContextSetLineWidth(context, lineThickness);
        CGContextStrokePath(context);

        CGImageRetain(roundedImage);
        CGContextRelease(context);

        DisplayTextureTiled *pTex = (DisplayTextureTiled *) UIGetDisplayTextureForCGImage(roundedImage, true);

        RoundedCornerImage *roundedObj = new RoundedCornerImage();
        roundedObj->img = roundedImage;
        roundedObj->radius = radius;
        roundedObj->thickness = lineThickness;

        _images.push_back(roundedObj);

        return pTex;
    }
};

RoundedCornerImages _roundedCornerImgs;

void DisplayNode::RenderCorner(CAPoint3D pt, int orientation)
{
    DisplayTexture *pRoundedCornerTex = _roundedCornerImgs.getCornerTex(presentationProperties.cornerRadius, presentationProperties.borderWidth);
    CAPoint3D img[4];
    CGPoint tex[4];

    switch ( orientation ) {
        case 0:
            img[0] = pt;
            img[1] = pt + CAPoint3D(presentationProperties.cornerRadius, 0, 0);
            img[2] = pt + CAPoint3D(0, presentationProperties.cornerRadius, 0);
            img[3] = pt + CAPoint3D(presentationProperties.cornerRadius, presentationProperties.cornerRadius, 0);
            tex[0] = CGPoint::point(1.0, 1.0);
            tex[1] = CGPoint::point(0.0, 1.0);
            tex[2] = CGPoint::point(1.0, 0.0);
            tex[3] = CGPoint::point(0.0, 0.0);
            break;

        case 1:
            img[0] = pt + CAPoint3D(-presentationProperties.cornerRadius, 0, 0);
            img[1] = pt + CAPoint3D(0, 0, 0);
            img[2] = pt + CAPoint3D(-presentationProperties.cornerRadius, presentationProperties.cornerRadius, 0);
            img[3] = pt + CAPoint3D(0, presentationProperties.cornerRadius, 0);
            tex[0] = CGPoint::point(0.0, 1.0);
            tex[1] = CGPoint::point(1.0, 1.0);
            tex[2] = CGPoint::point(0.0, 0.0);
            tex[3] = CGPoint::point(1.0, 0.0);
            break;

        case 2:
            img[0] = pt + CAPoint3D(0, -presentationProperties.cornerRadius, 0);
            img[1] = pt + CAPoint3D(presentationProperties.cornerRadius, -presentationProperties.cornerRadius, 0);
            img[2] = pt + CAPoint3D(0, 0, 0);
            img[3] = pt + CAPoint3D(presentationProperties.cornerRadius, 0, 0);
            tex[0] = CGPoint::point(1.0, 0.0);
            tex[1] = CGPoint::point(0.0, 0.0);
            tex[2] = CGPoint::point(1.0, 1.0);
            tex[3] = CGPoint::point(0.0, 1.0);
            break;

        case 3:
            img[0] = pt + CAPoint3D(-presentationProperties.cornerRadius, -presentationProperties.cornerRadius, 0);
            img[1] = pt + CAPoint3D(0, -presentationProperties.cornerRadius, 0);
            img[2] = pt + CAPoint3D(-presentationProperties.cornerRadius, 0, 0);
            img[3] = pt + CAPoint3D(0, 0, 0);
            tex[0] = CGPoint::point(0.0, 0.0);
            tex[1] = CGPoint::point(1.0, 0.0);
            tex[2] = CGPoint::point(0.0, 1.0);
            tex[3] = CGPoint::point(1.0, 1.0);
            break;
    }

    pRoundedCornerTex->addOperation(&presentationProperties, img, tex, 1, 
        1.0f,
        presentationProperties.borderColor.r,
        presentationProperties.borderColor.g,
        presentationProperties.borderColor.b,
        presentationProperties.borderColor.a,
        NULL);
}

void DisplayNode::RenderBorder(float alpha)
{
    if ( presentationProperties.borderWidth <= 0.0f ) return;

    float aOut = presentationProperties.borderColor.a * alpha;

    if ( aOut != 0.0f ) {
        CAPoint3D tl = contentQuad[0];
        CAPoint3D tr = contentQuad[1];
        CAPoint3D bl = contentQuad[2];
        CAPoint3D br = contentQuad[3];

        if ( presentationProperties.cornerRadius > 0.0f ) {
            RenderCorner(tl, 0);
            RenderCorner(tr, 1);
            RenderCorner(bl, 2);
            RenderCorner(br, 3);
        }

        //  Inset slightly
        float inset = presentationProperties.borderWidth / 2.0f;
        RenderLine(tl + CAPoint3D(0.0f, inset, 0), tr + CAPoint3D(0.0f, inset, 0));
        RenderLine(tr + CAPoint3D(-inset, 0, 0),   br + CAPoint3D(-inset, 0, 0));
        RenderLine(br + CAPoint3D(0, -inset, 0), bl + CAPoint3D(0, -inset, 0));
        RenderLine(bl + CAPoint3D(inset, 0, 0), tl + CAPoint3D(inset, 0, 0));

        /*
        _drawingList.AddOperation(contentQuad, NULL, 1, -1, alpha, ADM_NO_ALPHA, 
            presentationProperties.contentColor.r, 
            presentationProperties.contentColor.g, 
            presentationProperties.contentColor.b, 
            presentationProperties.contentColor.a, 
            NULL);
            */
        /*
        _drawingList.AddOperation(contentQuad, NULL, 1, -1, alpha, ADM_NO_ALPHA, 
            0.0f, 
            0.0f, 
            1.0f, 
            1.0f, 
            NULL);
            */
        /*
        glColor4f(presentationProperties.borderColor.r * aOut,
                  presentationProperties.borderColor.g * aOut,
                  presentationProperties.borderColor.b * aOut,
                  aOut);
                  */
        //glLineWidth(presentationProperties.borderWidth);
        /*
        DrawRoundedSquare(presentationProperties.borderWidth,
            -presentationProperties.bounds.size.width * presentationProperties.anchorPoint.x,
            -presentationProperties.bounds.size.height * presentationProperties.anchorPoint.y,
            presentationProperties.cornerRadius, 
            presentationProperties.bounds.size.width, presentationProperties.bounds.size.height,
            presentationProperties.borderColor.r * aOut,
            presentationProperties.borderColor.g * aOut,
            presentationProperties.borderColor.b * aOut,
            aOut);
            */
        //glDrawArrays(GL_LINE_STRIP, 0, 5);
    }
}
