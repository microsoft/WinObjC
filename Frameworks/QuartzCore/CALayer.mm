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

#include <math.h>
#include "CoreGraphics/CGContext.h"
#include "CGContextInternal.h"
#include "CoreFoundation/CFType.h"

#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSValue.h"
#include "Foundation/NSNull.h"

#include "UIKit/UIApplication.h"
#include "UIKit/UIColor.h"

#include "CALayerInternal.h"
#include "QuartzCore/CALayer.h"
#include "QuartzCore/CATransaction.h"
#include "QuartzCore/CAEAGLLayer.h"

#include "..\include\CACompositor.h"
#include "CAAnimationInternal.h"

@interface NSValue (CATransform3D)
// This is defined in Foundation/NSValue.mm
- (NSValue*)initWithCATransform3D:(CATransform3D)val;
@end

NSString* _opacityAction = @"opacity";
NSString* _positionAction = @"position";
NSString* _boundsAction = @"bounds";
NSString* _boundsOriginAction = @"bounds.origin";
NSString* _boundsSizeAction = @"bounds.size";
NSString* _transformAction = @"transform";
NSString* _orderInAction = @"onOrderIn";
NSString* _orderOutAction = @"orderOut";

CACompositorInterface* _globalCompositor;

template <class T>
class NodeList {
public:
    T** items;
    int count;
    int max;
    int curPos;

    NodeList() {
        items = NULL;
        count = 0;
        max = 0;
        curPos = 0;
    }

    ~NodeList() {
        if (items) {
            EbrFree(items);
        }
    }

    inline void AddNode(T* item) {
        if (count + 1 > max) {
            max += 64;
            items = (T**)EbrRealloc(items, max * sizeof(T*));
        }
        items[count++] = item;
    }
};

static void GetNeededLayouts(CAPrivateInfo* state, NodeList<CAPrivateInfo>* list, bool doAlwaysLayers) {
    CAPrivateInfo* cur = state;
    if (cur->needsLayout || (doAlwaysLayers && cur->alwaysLayout && !cur->didLayout)) {
        list->AddNode(cur);
    }

    cur = cur->lastChild;
    while (cur) {
        GetNeededLayouts(cur, list, doAlwaysLayers);
        cur = cur->prevSibling;
    }
}

void DoLayerLayouts(CALayer* window, bool doAlwaysLayers) {
    NodeList<CAPrivateInfo> list;
    for (;;) {
        GetNeededLayouts(window->priv, &list, doAlwaysLayers);

        if (list.curPos == list.count) {
            break;
        }
        while (list.curPos < list.count) {
            list.items[list.curPos]->needsLayout = FALSE;
            list.items[list.curPos]->didLayout = TRUE;
            [list.items[list.curPos]->self layoutSublayers];
            list.curPos++;
        }
    }

    for (int i = 0; i < list.count; i++) {
        list.items[i]->didLayout = FALSE;
    }
}

static void GetNeededDisplays(CAPrivateInfo* state, NodeList<CAPrivateInfo>* list) {
    CAPrivateInfo* cur = state;
    if (cur->needsDisplay || cur->hasNewContents) {
        list->AddNode(cur);
    }

    cur = cur->lastChild;
    while (cur) {
        GetNeededDisplays(cur, list);
        cur = cur->prevSibling;
    }
}

static void DoDisplayList(CALayer* layer) {
    NodeList<CAPrivateInfo> list;
    GetNeededDisplays(layer->priv, &list);

    while (list.curPos < list.count) {
        CAPrivateInfo* cur = list.items[list.curPos];

        if (!cur->_textureOverride) {
            if (cur->delegate) {
                EbrDebugLog("Getting new texture for %s\n", object_getClassName(cur->delegate));
            }
            DisplayTexture* newTexture = (DisplayTexture*)[cur->self _getDisplayTexture];
            cur->needsDisplay = FALSE;
            cur->hasNewContents = FALSE;

            if (cur->maskLayer) {
                CALayer* maskLayer = (CALayer*)cur->maskLayer;
                DisplayTexture* maskTexture = (DisplayTexture*)[cur->maskLayer _getDisplayTexture];
                GetCACompositor()->setNodeTexture((DisplayTransaction*)[CATransaction _currentDisplayTransaction],
                                                  maskLayer->priv->_presentationNode,
                                                  maskTexture,
                                                  maskLayer->priv->contentsSize,
                                                  maskLayer->priv->contentsScale);
                GetCACompositor()->setNodeMaskNode(cur->_presentationNode, maskLayer->priv->_presentationNode);
                if (maskTexture) {
                    GetCACompositor()->ReleaseDisplayTexture(maskTexture);
                }
            }

            GetCACompositor()->setNodeTexture((DisplayTransaction*)[CATransaction _currentDisplayTransaction],
                                              cur->_presentationNode,
                                              newTexture,
                                              cur->contentsSize,
                                              cur->contentsScale);
            if (newTexture) {
                GetCACompositor()->ReleaseDisplayTexture(newTexture);
            }
        } else {
            cur->needsDisplay = FALSE;
            cur->hasNewContents = FALSE;

            GetCACompositor()->setNodeTexture((DisplayTransaction*)[CATransaction _currentDisplayTransaction],
                                              cur->_presentationNode,
                                              cur->_textureOverride,
                                              cur->contentsSize,
                                              cur->contentsScale);
        }

        list.curPos++;
    }
}

static void DiscardLayerContents(CALayer* layer) {
    LLTREE_FOREACH(curLayer, layer->priv) {
        DiscardLayerContents(curLayer->self);

        if ([curLayer isKindOfClass:[CAEAGLLayer class]]) {
            [curLayer _unlockTexture];
        } else {
            [curLayer->self _releaseContents:TRUE];
        }
    }
}

CAPrivateInfo::CAPrivateInfo(CALayer* self, bool bPresentationLayer) {
    memset(this, 0, sizeof(CAPrivateInfo));
    setSelf(self);

    if (bPresentationLayer) {
        _isPresentationLayer = true;
    } else {
        _isPresentationLayer = false;
        memset(&bounds, 0, sizeof(bounds));
        memset(&position, 0, sizeof(position));
        zPosition = 0.0f;
        anchorPoint.x = 0.5f;
        anchorPoint.y = 0.5f;

        _animations = nil;

        contentsRect.origin.x = 0.0f;
        contentsRect.origin.y = 0.0f;
        contentsRect.size.width = 1.0f;
        contentsRect.size.height = 1.0f;

        contentsCenter.origin.x = 0.0f;
        contentsCenter.origin.y = 0.0f;
        contentsCenter.size.width = 1.0f;
        contentsCenter.size.height = 1.0f;

        contentsScale = 1.0f;

        superlayer = 0;
        opacity = 1.0f;
        hidden = FALSE;
        gravity = 0;
        contents = NULL;
        ownsContents = FALSE;
        savedContext = NULL;
        isOpaque = FALSE;
        delegate = 0;
        needsDisplay = TRUE;
        needsUpdate = FALSE;
        hasNewContents = FALSE;
        backgroundColor.r = 0.0f;
        backgroundColor.g = 0.0f;
        backgroundColor.b = 0.0f;
        backgroundColor.a = 0.0f;
        _backgroundColor = nil;
        contentColor.r = 1.0f;
        contentColor.g = 1.0f;
        contentColor.b = 1.0f;
        contentColor.a = 1.0f;
        transform = CATransform3DMakeTranslation(0, 0, 0);
        sublayerTransform = CATransform3DMakeTranslation(0, 0, 0);
        masksToBounds = FALSE;
        isRootLayer = FALSE;
        needsDisplayOnBoundsChange = FALSE;
        drewOpaque = FALSE;
        _name = nil;
        positionSet = FALSE;
        sizeSet = FALSE;
        originSet = FALSE;

        _presentationNode = GetCACompositor()->CreateDisplayNode();
    }

    GetCACompositor()->IncrementCounter("CALayer");
}

CAPrivateInfo::~CAPrivateInfo() {
    GetCACompositor()->DecrementCounter("CALayer");

    _undefinedKeys = nil;
    _actions = nil;
    CGColorRelease(_backgroundColor);
    CGColorRelease(_borderColor);
    _name = nil;
    if (_animations) {
        [_animations release];
    }
    if (contents) {
        CGImageRelease(contents);
    }
    if (savedContext) {
        CGContextRelease(savedContext);
    }
    [maskLayer release];
    maskLayer = nil;

    GetCACompositor()->ReleaseNode(_presentationNode);
    _presentationNode = NULL;
}

class LockingBufferInterface : public DisplayTextureLocking {
public:
    void* LockWritableBitmapTexture(DisplayTexture* tex, int* stride) {
        return GetCACompositor()->LockWritableBitmapTexture(tex, stride);
    }
    void UnlockWritableBitmapTexture(DisplayTexture* tex) {
        GetCACompositor()->UnlockWritableBitmapTexture(tex);
    }

    void RetainDisplayTexture(DisplayTexture* tex) {
        GetCACompositor()->RetainDisplayTexture(tex);
    }

    void ReleaseDisplayTexture(DisplayTexture* tex) {
        GetCACompositor()->ReleaseDisplayTexture(tex);
    }
};

static LockingBufferInterface _globallockingBufferInterface;

CGContextRef CreateLayerContentsBitmapContext32(int width, int height) {
    DisplayTexture* tex = NULL;

    if ([NSThread isMainThread]) {
        tex = GetCACompositor()->CreateWritableBitmapTexture32(width, height);
    }
    CGContextRef ret = CGBitmapContextCreate32(width, height, tex, &_globallockingBufferInterface);
    if (tex) {
        _globallockingBufferInterface.ReleaseDisplayTexture(tex);
    }

    return ret;
}

@implementation CALayer {
    WXFrameworkElement* _contentsElement;
}

- (instancetype)init {
    assert(priv == NULL);
    priv = new CAPrivateInfo(self);

    return self;
}

- (void)setNeedsDisplay {
    if (priv->needsDisplay == FALSE) {
        priv->needsDisplay = TRUE;
    }

    GetCACompositor()->DisplayTreeChanged();
}

- (void)displayIfNeeded {
    if (priv->needsDisplay) {
        priv->needsDisplay = FALSE;
        [self display];
    }
}

- (void)renderInContext:(CGContextRef)ctx {
    if (priv->hidden) {
        return;
    }

    [self layoutIfNeeded];

    CGContextSaveGState(ctx);
    CGContextTranslateCTM(ctx, priv->position.x, priv->position.y);
    CGContextTranslateCTM(ctx, -priv->bounds.size.width * priv->anchorPoint.x, -priv->bounds.size.height * priv->anchorPoint.y);
    CGRect destRect;

    destRect.origin.x = 0;
    destRect.origin.y = 0;
    destRect.size.width = priv->bounds.size.width;
    destRect.size.height = priv->bounds.size.height;

    if (priv->masksToBounds) {
        CGContextClipToRect(ctx, destRect);
    }
    if (priv->contents == NULL) {
        if ([priv->delegate respondsToSelector:@selector(displayLayer:)]) {
            [priv->delegate displayLayer:self];
        }
    }

    if (priv->contents == NULL) {
        if (priv->_backgroundColor != nil) {
            [priv->_backgroundColor setFill];
            CGContextFillRect(ctx, destRect);
        }
        [self drawInContext:ctx];
        if (![priv->delegate respondsToSelector:@selector(displayLayer:)]) {
            [priv->delegate drawLayer:self inContext:ctx];
        }
    } else {
        CGRect rect;

        rect.origin.x = 0;
        rect.origin.y = priv->bounds.size.height * priv->contentsScale;
        rect.size.width = priv->bounds.size.width * priv->contentsScale;
        rect.size.height = -priv->bounds.size.height * priv->contentsScale;

        CGContextDrawImageRect(ctx, priv->contents, rect, destRect);
    }

    //  Draw sublayers
    LLTREE_FOREACH(curLayer, priv) {
        [curLayer->self renderInContext:ctx];
    }

    CGContextRestoreGState(ctx);
}

- (void)drawInContext:(CGContextRef)ctx {
}

- (WXFrameworkElement*)contentsElement {
    return _contentsElement;
}

- (void)setContentsElement:(WXFrameworkElement*)element {
    [element retain];
    [_contentsElement release];
    _contentsElement = element;

    if (priv->_textureOverride) {
        GetCACompositor()->ReleaseDisplayTexture(priv->_textureOverride);
    }
    priv->_textureOverride = GetCACompositor()->CreateDisplayTextureForElement(element);
    [self setContentsGravity:kCAGravityResize];
    priv->needsDisplay = TRUE;
}

- (void)display {
    EbrDebugLog("Displaying for 0x%08x (%s, %s)\n",
                priv->delegate,
                object_getClassName(self),
                priv->delegate ? object_getClassName(priv->delegate) : "nil");

    if (priv->savedContext != NULL) {
        CGContextRelease(priv->savedContext);
        priv->savedContext = NULL;
    }

    if (priv->contentsInset.origin.x != 0.0f || priv->contentsInset.origin.y != 0.0f || priv->contentsInset.size.width != 0.0f ||
        priv->contentsInset.size.height != 0.0f) {
        memset(&priv->contentsInset, 0, sizeof(CGRect));
    }

    if (priv->contents == NULL || priv->ownsContents || [self isKindOfClass:[CAShapeLayer class]]) {
        if (priv->contents) {
            if (priv->ownsContents) {
                EbrDebugLog("Freeing 0x%x with refcount %d\n", priv->contents, CFGetRetainCount((CFTypeRef)priv->contents));
                CGImageRelease(priv->contents);
            }
            priv->contents = NULL;
        }

        // Update content size, even in case of the early out below.
        int width = (int)(ceilf(priv->bounds.size.width) * priv->contentsScale);
        int height = (int)(ceilf(priv->bounds.size.height) * priv->contentsScale);

        if (width <= 0 || height <= 0) {
            return;
        }

        if (width > 2048) {
            width = 2048;
        }
        if (height > 2048) {
            height = 2048;
        }

        priv->contentsSize.width = (float)width;
        priv->contentsSize.height = (float)height;

        // nothing to do?
        bool hasDrawingMethod = false;
        if (priv->delegate != nil && (!object_isMethodFromClass(priv->delegate, @selector(drawRect:), "UIView") ||
                                      !object_isMethodFromClass(priv->delegate, @selector(drawLayer:inContext:), "UIView") ||
                                      [priv->delegate respondsToSelector:@selector(displayLayer:)])) {
            hasDrawingMethod = true;
        }
        if (!object_isMethodFromClass(self, @selector(drawInContext:), "CALayer")) {
            hasDrawingMethod = true;
        }
        if (!hasDrawingMethod) {
            return;
        }

        bool useVector = false;

        //  Create the contents
        CGImageRef target = NULL;
        CGContextRef drawContext = NULL;
        CGImageRef vectorTarget = NULL;

        if ((priv->isOpaque && priv->_backgroundColor == nil) || priv->backgroundColor.a == 1.0) {
            priv->drewOpaque = TRUE;
        } else {
            priv->drewOpaque = FALSE;
        }

        if (!target) {
            if ((priv->isOpaque && priv->_backgroundColor == nil) || priv->backgroundColor.a == 1.0 && 0) {
                /* CGVectorImage is currently in development - not ready for general use */
                if (useVector) {
                    // target = new CGVectorImage(width, height, _ColorRGB);
                } else {
                    drawContext = CGBitmapContextCreate24(width, height);
                }
                priv->drewOpaque = TRUE;
            } else {
                /* CGVectorImage is currently in development - not ready for general use */
                if (useVector) {
                    // target = new CGVectorImage(width, height, _ColorARGB);
                } else {
                    drawContext = CreateLayerContentsBitmapContext32(width, height);
                }
                priv->drewOpaque = FALSE;
            }
            priv->ownsContents = TRUE;
        }
        target = CGBitmapContextGetImage(drawContext);

        CGContextRetain(drawContext);
        CGImageRetain(target);
        priv->savedContext = drawContext;

        if (!vectorTarget) {
            if (priv->_backgroundColor == nil || (int)[priv->_backgroundColor _type] == solidBrush) {
                CGContextClearToColor(drawContext,
                                      priv->backgroundColor.r,
                                      priv->backgroundColor.g,
                                      priv->backgroundColor.b,
                                      priv->backgroundColor.a);
            } else {
                CGContextClearToColor(drawContext, 0, 0, 0, 0);

                CGContextSaveGState(drawContext);
                CGContextSetFillColorWithColor(drawContext, [priv->_backgroundColor CGColor]);

                CGRect wholeRect;

                wholeRect.origin.x = 0;
                wholeRect.origin.y = 0;
                wholeRect.size.width = float(width);
                wholeRect.size.height = float(height);

                CGContextFillRect(drawContext, wholeRect);
                CGContextRestoreGState(drawContext);
            }
        }

        if (target->Backing()->Height() != 0) {
            CGContextTranslateCTM(drawContext, 0, float(target->Backing()->Height()));
        }
        if (priv->contentsScale != 1.0f) {
            CGContextScaleCTM(drawContext, priv->contentsScale, priv->contentsScale);
        }

        CGContextScaleCTM(drawContext, 1.0f, -1.0f);
        CGContextTranslateCTM(drawContext, -priv->bounds.origin.x, -priv->bounds.origin.y);

        CGContextSetDirty(drawContext, false);
        [self drawInContext:drawContext];

        if (priv->delegate != 0) {
            // const char *name = ((id) priv->delegate).object_getClassName();
            if ([priv->delegate respondsToSelector:@selector(displayLayer:)]) {
                [priv->delegate displayLayer:self];
            } else {
                [priv->delegate drawLayer:self inContext:drawContext];
            }
        }

        CGContextReleaseLock(drawContext);
        CGContextRelease(drawContext);

        if (!CGContextIsDirty(drawContext)) {
            CGImageRelease(target);
            CGContextRelease(drawContext);
            priv->savedContext = NULL;
            priv->contents = NULL;
        } else {
            if (vectorTarget) {
                /*
                CGVectorImage *vecImg = (CGVectorImage *) target;

                priv->contents = vecImg->Rasterize(&priv->contentsInset);

                priv->contentsInset.origin.x /= priv->contentsScale;
                priv->contentsInset.origin.y /= priv->contentsScale;
                priv->contentsInset.size.width /= priv->contentsScale;
                priv->contentsInset.size.height /= priv->contentsScale;

                CGImageRelease(vecImg);
                */
            } else {
                priv->contents = target;
            }
        }
    } else {
        if (priv->contents) {
            priv->contentsSize.width = float(priv->contents->Backing()->Width());
            priv->contentsSize.height = float(priv->contents->Backing()->Height());

            /*
            if ( priv->contents->_cachedTexture ) {
            priv->contents->_cachedTexture->Release();
            priv->contents->_cachedTexture = NULL;
            }
            */
        }
    }

    //  To signal that we need our context converted into a texture and sent to NativeUI (checked in UIApplication.cpp)
    priv->hasNewContents = TRUE;
}

static void doRecursiveAction(CALayer* layer, NSString* actionName) {
    //  Notify all subviews
    LLTREE_FOREACH(obj, layer->priv) {
        doRecursiveAction(obj->self, actionName);
    }

    id<CAAction> action = [layer actionForKey:actionName];
    if (action != nil) {
        [action runActionForKey:actionName object:layer arguments:nil];
    }

    /* Note: This can causes unnecessary redraws - should be refactored such that the contents are only released
    when the layer is determined to have been removed from the drawing tree after an entire update cycle */
    if (actionName == (NSString*)_orderOutAction) {
        [layer _releaseContents:FALSE];

        if (layer->priv->savedContext) {
            CGContextRelease(layer->priv->savedContext);
            layer->priv->savedContext = NULL;
        }
    }
}

- (BOOL)_isPartOfViewHeiarchy {
    CALayer* curLayer = self;

    while (curLayer != nil) {
        if (curLayer->priv->isRootLayer) {
            return TRUE;
        }

        curLayer = curLayer->priv->superlayer;
    }

    return FALSE;
}

- (void)addSublayer:(CALayer*)subLayerAddr {
    if (subLayerAddr == self) {
        assert(0);
    }

    [self _setShouldLayout];
    [subLayerAddr _setShouldLayout];

    [subLayerAddr retain];
    [subLayerAddr removeFromSuperlayer];
    [subLayerAddr autorelease];

    //  If our layer is visible, order all subviews in
    bool isVisible = false;

    CALayer* curLayer = self;

    while (curLayer != nil) {
        if (curLayer->priv->isRootLayer) {
            isVisible = true;
            break;
        }

        curLayer = curLayer->priv->superlayer;
    }

    if (isVisible) {
        //  Order in subviews
        doRecursiveAction(subLayerAddr, _orderInAction);
    }

    priv->addChildAfter(subLayerAddr, nil);
    [subLayerAddr retain];

    CALayer* sublayer = (CALayer*)subLayerAddr;
    sublayer->priv->superlayer = self;

    [CATransaction _addSublayerToLayer:self sublayer:sublayer];
}

- (void)insertSublayer:(CALayer*)layer above:(CALayer*)aboveLayer {
    int curLayerPos = priv->indexOfChild(aboveLayer);
    if (curLayerPos == 0x7fffffff) {
        assert(0);
    }

    [self insertSublayer:layer atIndex:curLayerPos + 1];
}

- (void)insertSublayer:(CALayer*)layer below:(CALayer*)belowLayer {
    int curLayerPos = priv->indexOfChild(belowLayer);
    if (curLayerPos == 0x7fffffff) {
        assert(0);
    }

    [self insertSublayer:layer atIndex:curLayerPos];
}

- (void)insertSublayer:(CALayer*)subLayerAddr atIndex:(unsigned)index {
    if (subLayerAddr == self) {
        assert(0);
    }

    [self _setShouldLayout];
    [subLayerAddr _setShouldLayout];

    //  If our layer is visible, order all subviews in
    bool isVisible = false;

    CALayer* curLayer = self;

    while (curLayer != nil) {
        if (curLayer->priv->isRootLayer) {
            isVisible = true;
            break;
        }

        curLayer = curLayer->priv->superlayer;
    }

    if (isVisible) {
        //  Order in subviews
        doRecursiveAction(subLayerAddr, _orderInAction);
    }

    CALayer* insertBefore = nil;

    if (index < (unsigned)priv->childCount) {
        insertBefore = priv->childAtIndex(index)->self;
    } else {
        if (index > (unsigned)priv->childCount) {
            EbrDebugLog("Adding sublayer at index %d, count=%d!\n", index, priv->childCount);
            index = priv->childCount;
        }
    }

    priv->insertChildAtIndex(subLayerAddr, index);
    [subLayerAddr retain];

    CALayer* sublayer = (CALayer*)subLayerAddr;
    sublayer->priv->superlayer = self;

    if (insertBefore != nil) {
        [CATransaction _addSublayerToLayer:self sublayer:sublayer before:insertBefore];
    } else {
        [CATransaction _addSublayerToLayer:self sublayer:sublayer];
    }
}

- (void)replaceSublayer:(CALayer*)oldLayer with:(CALayer*)newLayer {
    // according to the docs, if oldLayer is not found the behaviour is undefined.
    int index = priv->indexOfChild(oldLayer);
    if (index == NSNotFound) {
        return;
    }

    [self _setShouldLayout];
    [newLayer _setShouldLayout];

    [oldLayer retain];
    [newLayer retain];

    priv->replaceChild(oldLayer, newLayer);

    [CATransaction _replaceInLayer:self sublayer:oldLayer withSublayer:newLayer];

    [oldLayer release];
    [newLayer release];
}

- (void)exchangeSublayer:(CALayer*)layer1 withLayer:(CALayer*)layer2 {
    [layer1 retain];
    [layer2 retain];

    int index1 = priv->indexOfChild(layer1);
    int index2 = priv->indexOfChild(layer2);

    priv->exchangeChild(layer1, layer2);

    //  Special case: adjacent views
    if (index2 == index1 + 1) {
        [CATransaction _moveLayer:layer1 beforeLayer:nil afterLayer:layer2];
    } else if (index1 == index2 + 1) {
        [CATransaction _moveLayer:layer2 beforeLayer:nil afterLayer:layer1];
    } else {
        int dist = index1 - index2;

        dist = dist < 0 ? -dist : dist;

        if (dist > 1) {
            if (index1 > 0) {
                CALayer* node1Before = priv->childAtIndex(index1 - 1)->self;
                [CATransaction _moveLayer:layer2 beforeLayer:nil afterLayer:node1Before];
            } else {
                CALayer* node1After = priv->childAtIndex(index1 + 1)->self;
                [CATransaction _moveLayer:layer2 beforeLayer:node1After afterLayer:nil];
            }

            if (index2 > 0) {
                CALayer* node2Before = priv->childAtIndex(index2 - 1)->self;
                [CATransaction _moveLayer:layer1 beforeLayer:nil afterLayer:node2Before];
            } else {
                CALayer* node2After = priv->childAtIndex(index2 + 1)->self;
                [CATransaction _moveLayer:layer1 beforeLayer:node2After afterLayer:nil];
            }
        } else {
            assert(0);
        }
    }
}

- (void)bringSublayerToFront:(CALayer*)sublayer {
    if (sublayer == self) {
        assert(0);
    }

    if (priv->lastChild->self == sublayer) {
        return;
    }

    CALayer* insertAfter = priv->lastChild->self;
    priv->removeChild(sublayer);
    priv->addChildAfter(sublayer, nil);

    [CATransaction _moveLayer:sublayer beforeLayer:nil afterLayer:insertAfter];
}

- (void)sendSublayerToBack:(CALayer*)sublayer {
    if (sublayer == self) {
        assert(0);
    }

    CALayer* insertBefore = priv->firstChild->self;
    priv->removeChild(sublayer);
    priv->addChildBefore(sublayer, nil);

    [CATransaction _moveLayer:sublayer beforeLayer:insertBefore afterLayer:nil];
}

- (void)removeFromSuperlayer {
    if (priv->superlayer == 0) {
        return;
    }

    CALayer* oursuper = priv->superlayer;

    //  If our layer is visible, order all subviews out
    bool isVisible = false;

    CALayer* curLayer = self;
    CALayer* pSuper = (CALayer*)priv->superlayer;
    CALayer* nextSuper = curLayer->priv->superlayer;
    priv->superlayer = 0;

    while (curLayer != nil) {
        if (curLayer->priv->isRootLayer) {
            isVisible = true;
            break;
        }

        curLayer = nextSuper;

        if (curLayer) {
            nextSuper = curLayer->priv->superlayer;
        }
    }

    if (isVisible) {
        //  Order out subviews
        doRecursiveAction(self, _orderOutAction);
    }

    [CATransaction _removeLayer:self];

    pSuper->priv->removeChild(self);
    [self release];
}

- (BOOL)hidden {
    return priv->hidden;
}

- (CGRect)frame {
    CGRect ret;

    if (priv->_frameIsCached) {
        return priv->_cachedFrame;
    }

    //  Get transformed bounding box
    CGAffineTransform curTransform, translate, invTranslate;
    curTransform = [self affineTransform];

    translate = CGAffineTransformMakeTranslation(-priv->position.x, -priv->position.y);
    translate = CGAffineTransformConcat(translate, curTransform);
    invTranslate = CGAffineTransformMakeTranslation(priv->position.x, priv->position.y);
    translate = CGAffineTransformConcat(translate, invTranslate);

    ret.origin.x = priv->position.x - priv->bounds.size.width * priv->anchorPoint.x;
    ret.origin.y = priv->position.y - priv->bounds.size.height * priv->anchorPoint.y;
    ret.size = priv->bounds.size;

    ret = CGRectApplyAffineTransform(ret, translate);
    /*
    EbrDebugLog("%s: frame(%d, %d, %d, %d)\n", object_getClassName(self),
    (int) ret->origin.x, (int) ret->origin.y,
    (int) ret->size.width, (int) ret->size.height);
    */

    memcpy(&priv->_cachedFrame, &ret, sizeof(CGRect));
    priv->_frameIsCached = TRUE;

    return ret;
}

- (void)setFrame:(CGRect)frame {
    /*
    char szOut[512];
    sprintf(szOut, "%s: setFrame(%f, %f, %f, %f)\n", object_getClassName(self),
    frame.origin.x, frame.origin.y,
    frame.size.width, frame.size.height);
    EbrDebugLog("%s", szOut);
    */
    priv->_frameIsCached = FALSE;

    if (memcmp(&frame, &CGRectNull, sizeof(CGRect)) == 0) {
        [self setPosition:frame.origin];

        CGRect curBounds;
        curBounds = [self bounds];
        curBounds.size = frame.size;

        [self setBounds:curBounds];

        return;
    }

    //  Get transformed bounding box
    CGAffineTransform curTransform, translate, invTranslate;
    curTransform = [self affineTransform];

    CGPoint position;

    position.x = frame.origin.x + frame.size.width * priv->anchorPoint.x;
    position.y = frame.origin.y + frame.size.height * priv->anchorPoint.y;

    //  Get transformed bounding box
    translate = CGAffineTransformMakeTranslation(-position.x, -position.y);
    translate = CGAffineTransformConcat(translate, curTransform);
    invTranslate = CGAffineTransformMakeTranslation(position.x, position.y);
    translate = CGAffineTransformConcat(translate, invTranslate);

    translate = CGAffineTransformInvert(translate);
    frame = CGRectApplyAffineTransform(frame, translate);

    CGSize outSize;
    outSize.width = frame.size.width;
    outSize.height = frame.size.height;

    position.x = frame.origin.x + frame.size.width * priv->anchorPoint.x;
    position.y = frame.origin.y + frame.size.height * priv->anchorPoint.y;

    [self setPosition:position];

    CGRect outBounds = [self bounds];
    outBounds.size = outSize;
    [self setBounds:outBounds];
}

+ (CALayer*)layer {
    return [[self new] autorelease];
}

- (CGRect)bounds {
    return priv->bounds;
}

- (CALayer*)superlayer {
    return priv->superlayer;
}

- (CGAffineTransform)affineTransform {
    CGAffineTransform ret;

    ret.a = priv->transform.m[0][0];
    ret.b = priv->transform.m[0][1];
    ret.c = priv->transform.m[1][0];
    ret.d = priv->transform.m[1][1];
    ret.tx = priv->transform.m[3][0];
    ret.ty = priv->transform.m[3][1];

    return ret;
}

- (CGPoint)position {
    return priv->position;
}

- (CGPoint)anchorPoint {
    return priv->anchorPoint;
}

- (void)setPosition:(CGPoint)pos {
    if (priv->position.x == pos.x && priv->position.y == pos.y) {
        return;
    }

    id<CAAction> action = [self actionForKey:(id)_positionAction];

    priv->position.x = pos.x;
    priv->position.y = pos.y;
    priv->_frameIsCached = FALSE;

    NSValue* newPosValue = [[NSValue alloc] initWithCGPoint:priv->position];
    [CATransaction _setPropertyForLayer:self name:@"position" value:newPosValue];
    [newPosValue release];
    priv->positionSet = TRUE;

    if (action != nil) {
        [action runActionForKey:(id)_positionAction object:self arguments:nil];
    }
}

- (void)setBounds:(CGRect)bounds {
    CGRect zero = { 0 };
    if (*((DWORD*)&bounds.size.width) == 0xCCCCCCCC) {
        assert(0);
    }

    if (bounds.origin.x != bounds.origin.x || bounds.origin.y != bounds.origin.y || bounds.size.width != bounds.size.width ||
        bounds.size.height != bounds.size.height) {
        EbrDebugLog("**** Warning: Bad bounds on CALayer - %f, %f, %f, %f *****\n",
                    bounds.origin.x,
                    bounds.origin.y,
                    bounds.size.width,
                    bounds.size.height);
        memset(&bounds, 0, sizeof(CGRect));
#if defined(_DEBUG) || !defined(WINPHONE)
        assert(0);
#endif
    }
    /*
    if ( bounds.size.height > 16384 || bounds.size.width > 16384 ) {
    EbrDebugLog("**** Warning: Bad bounds on CALayer - %d, %d, %d, %d *****\n", (int) bounds.origin.x, (int)
    bounds.origin.y,
    (int) bounds.size.width, (int) bounds.size.height);
    bounds.size.height = 32;
    bounds.size.width = 32;
    //*((char *) 0) = 0;
    //assert(0);
    }
    */
    id<CAAction> action = nil;

    if (priv->bounds.size.width != bounds.size.width || priv->bounds.size.height != bounds.size.height ||
        priv->bounds.origin.x != bounds.origin.x || priv->bounds.origin.y != bounds.origin.y) {
        action = [self actionForKey:_boundsAction];
    }

    if (priv->bounds.size.width != bounds.size.width || priv->bounds.size.height != bounds.size.height) {
        priv->bounds.size = bounds.size;

        if (priv->superlayer != 0 && priv->needsDisplayOnBoundsChange) {
            [self setNeedsDisplay];
        }
        [self _setShouldLayout];
        [priv->superlayer _setShouldLayout];

        NSValue* newSizeValue = [[NSValue alloc] initWithCGSize:priv->bounds.size];
        [CATransaction _setPropertyForLayer:self name:@"bounds.size" value:newSizeValue];
        [newSizeValue release];
        priv->_frameIsCached = FALSE;
    }

    if (priv->bounds.origin.x != bounds.origin.x || priv->bounds.origin.y != bounds.origin.y) {
        priv->bounds.origin = bounds.origin;

        NSValue* newOriginValue = [[NSValue alloc] initWithCGPoint:priv->bounds.origin];
        [CATransaction _setPropertyForLayer:self name:@"bounds.origin" value:newOriginValue];
        [newOriginValue release];
    }

    [action runActionForKey:(id)_boundsAction object:self arguments:nil];

    priv->sizeSet = TRUE;
    priv->originSet = TRUE;
}

- (void)setOrigin:(CGPoint)origin {
    if (origin.x != origin.x || origin.y != origin.y) {
        EbrDebugLog("**** Warning: Bad origin on CALayer - %f, %f *****\n", origin.x, origin.y);
        memset(&origin, 0, sizeof(CGPoint));
        assert(0);
    }

    if (priv->bounds.origin.x != origin.x || priv->bounds.origin.y != origin.y) {
        id<CAAction> action = nil;
        action = [self actionForKey:_boundsOriginAction];
        priv->bounds.origin = origin;
        [action runActionForKey:(id)_boundsOriginAction object:self arguments:nil];

        NSValue* newOriginValue = [[NSValue alloc] initWithCGPoint:priv->bounds.origin];
        [CATransaction _setPropertyForLayer:self name:@"bounds.origin" value:newOriginValue];
        [newOriginValue release];
        priv->originSet = TRUE;
    }
}

- (void)setAnchorPoint:(CGPoint)point {
    priv->anchorPoint = point;
    priv->_frameIsCached = FALSE;

    NSValue* newAnchorValue = [[NSValue alloc] initWithCGPoint:priv->anchorPoint];
    [CATransaction _setPropertyForLayer:self name:@"anchorPoint" value:newAnchorValue];
    [newAnchorValue release];
}

- (CGRect)contentsRect {
    return priv->contentsRect;
}

- (void)setContentsRect:(CGRect)rect {
    memcpy(&priv->contentsRect, &rect, sizeof(CGRect));

    NSValue* newRect = [[NSValue alloc] initWithCGRect:priv->contentsRect];
    [CATransaction _setPropertyForLayer:self name:@"contentsRect" value:newRect];
    [newRect release];
}

- (void)setContentsCenter:(CGRect)rect {
    memcpy(&priv->contentsCenter, &rect, sizeof(CGRect));

    NSValue* newRect = [[NSValue alloc] initWithCGRect:priv->contentsCenter];
    [CATransaction _setPropertyForLayer:self name:@"contentsCenter" value:newRect];
    [newRect release];
}

- (void)setContentsGravity:(NSString*)gravity {
    if ([gravity isEqual:kCAGravityCenter]) {
        priv->gravity = kGravityCenter;
    } else if ([gravity isEqual:kCAGravityResize]) {
        priv->gravity = kGravityResize;
    } else if ([gravity isEqual:kCAGravityTop]) {
        priv->gravity = kGravityTop;
    } else if ([gravity isEqual:kCAGravityResizeAspect]) {
        priv->gravity = kGravityResizeAspect;
    } else if ([gravity isEqual:kCAGravityTopLeft]) {
        priv->gravity = kGravityTopLeft;
    } else if ([gravity isEqual:kCAGravityTopRight]) {
        priv->gravity = kGravityTopRight;
    } else if ([gravity isEqual:kCAGravityBottomLeft]) {
        priv->gravity = kGravityBottomLeft;
    } else if ([gravity isEqual:kCAGravityLeft]) {
        priv->gravity = kGravityLeft;
    } else if ([gravity isEqual:kCAGravityResizeAspectFill]) {
        priv->gravity = kGravityAspectFill;
    } else if ([gravity isEqual:kCAGravityBottom]) {
        priv->gravity = kGravityBottom;
    } else if ([gravity isEqual:kCAGravityRight]) {
        priv->gravity = kGravityRight;
    } else if ([gravity isEqual:kCAGravityBottomRight]) {
        priv->gravity = kGravityBottomRight;
    } else {
        assert(0);
    }

    NSNumber* newGravity = [[NSNumber alloc] initWithInt:priv->gravity];
    [CATransaction _setPropertyForLayer:self name:@"gravity" value:newGravity];
    [newGravity release];
}

- (void)setHidden:(BOOL)hidden {
    if (priv->hidden == hidden) {
        return;
    }

    priv->hidden = hidden;

    NSNumber* newHidden = [[NSNumber alloc] initWithInt:priv->hidden];
    [CATransaction _setPropertyForLayer:self name:@"hidden" value:newHidden];
    [newHidden release];
}

- (BOOL)isHidden {
    return priv->hidden;
}

- (void)setDelegate:(id)delegateAddr {
    priv->delegate = delegateAddr;

    if ([delegateAddr respondsToSelector:@selector(drawRect:)]) {
        if (!object_isMethodFromClass(priv->delegate, @selector(drawRect:), "UIView") &&
            ![priv->delegate isKindOfClass:[CAEAGLLayer class]]) {
            priv->contentsScale = GetCACompositor()->screenScale();
        }
    }
}

- (id)delegate {
    return priv->delegate;
}

- (void)setContents:(CGImageRef)pImg {
    CGImageRef oldContents = priv->contents;

    if (pImg != NULL) {
        priv->contents = pImg;
        CGImageRetain(pImg);
        priv->ownsContents = FALSE;

        priv->contentsSize.width = float(priv->contents->Backing()->Width());
        priv->contentsSize.height = float(priv->contents->Backing()->Height());
    } else {
        priv->contents = NULL;
        priv->ownsContents = FALSE;
    }

    priv->needsDisplay = TRUE;

    if (oldContents) {
        CGImageRelease(oldContents);
    }
    if (priv->savedContext) {
        CGContextRelease(priv->savedContext);
        priv->savedContext = NULL;
    }

    GetCACompositor()->DisplayTreeChanged();
}

- (id)contents {
    if (!priv->ownsContents) {
        return (id)priv->contents;
    }

    return nil;
}

- (void)setContentsOrientation:(UIInterfaceOrientation)orientation {
    priv->contentsOrientation = orientation;
    NSNumber* newOrientation = [[NSNumber alloc] initWithInt:priv->contentsOrientation];
    [CATransaction _setPropertyForLayer:self name:@"contentsOrientation" value:newOrientation];
    [newOrientation release];
}

- (void)_releaseContents:(BOOL)immediately {
    if (priv->ownsContents) {
        if (priv->contents) {
            CGImageRelease(priv->contents);
            priv->contents = NULL;
            priv->needsDisplay = TRUE;
        }
        if (priv->savedContext) {
            CGContextRelease(priv->savedContext);
            priv->savedContext = NULL;
        }
    }
    GetCACompositor()->setNodeTexture((DisplayTransaction*)[CATransaction _currentDisplayTransaction],
                                      priv->_presentationNode,
                                      NULL,
                                      CGSizeMake(0, 0),
                                      0.0f);
    priv->needsDisplay = TRUE;

    GetCACompositor()->DisplayTreeChanged();
}

- (BOOL)isOpaque {
    return priv->isOpaque;
}

- (BOOL)opaque {
    return priv->isOpaque;
}

- (void)setOpaque:(BOOL)isOpaque {
    priv->isOpaque = isOpaque;
}

- (void)setZPosition:(float)pos {
    priv->zPosition = pos;

    NSNumber* newZPos = [[NSNumber alloc] initWithFloat:priv->zPosition];
    [CATransaction _setPropertyForLayer:self name:@"zPosition" value:newZPos];
    [newZPos release];
}

- (float)zPosition {
    return priv->zPosition;
}

- (void)setMasksToBounds:(BOOL)mask {
    priv->masksToBounds = mask;

    NSNumber* newMask = [[NSNumber alloc] initWithInt:priv->masksToBounds];
    [CATransaction _setPropertyForLayer:self name:@"masksToBounds" value:newMask];
    [newMask release];
}

- (BOOL)masksToBounds {
    return priv->masksToBounds;
}

- (void)addAnimation:(CAAnimation*)anim forKey:(NSString*)key {
    if (priv->_animations == nil) {
        priv->_animations = [NSMutableDictionary new];
    }

    if (key == nil) {
        static int curId = 0;
        char szName[255];
        sprintf(szName, "Undefined_%d", curId);
        curId++;
        key = [NSString stringWithCString:szName];
    }

    CAAnimation* curAnim = [priv->_animations objectForKey:key];
    if (curAnim == anim) {
        return;
    }

    if (curAnim != nil) {
        [curAnim _abortAnimation];
    }

    CAAnimation* animCopy = [anim copy];
    animCopy->_keyName = [key copy];
    [priv->_animations setObject:(id)animCopy forKey:(id)animCopy->_keyName];
    [animCopy release];

    [CATransaction _addAnimationToLayer:self animation:animCopy forKey:key];
}

- (void)_removeAnimation:(CAAnimation*)animation {
    CAAnimation* objForKey = [priv->_animations objectForKey:animation->_keyName];
    [priv->_animations setObject:nil forKey:animation->_keyName];
}

- (void)animationForKey:(NSString*)key {
    if (priv->_animations == nil) {
        priv->_animations = [NSMutableDictionary new];
    }

    if (key == nil) {
        key = @"";
    }

    [priv->_animations objectForKey:key];
}

- (NSArray*)animationKeys {
    if (priv->_animations == nil) {
        priv->_animations = [NSMutableDictionary new];
    }

    return [priv->_animations allKeys];
}

- (void)removeAllAnimations {
    if (priv->_animations) {
        int count = CFDictionaryGetCount((CFDictionaryRef)priv->_animations);
        id* vals = (id*)malloc(sizeof(id) * count);
        CFDictionaryGetKeysAndValues((CFDictionaryRef)priv->_animations, NULL, (const void**)vals);
        for (int i = 0; i < count; i++) {
            [vals[i] _removeAnimationsFromLayer];
        }
        free(vals);

        [priv->_animations removeAllObjects];
    }
}

- (void)removeAnimationForKey:(NSString*)key {
    CAAnimation* anim = [priv->_animations objectForKey:key];

    if (anim != nil) {
        [anim _removeAnimationsFromLayer];
    }
    [priv->_animations removeObjectForKey:key];
}

- (void)setAffineTransform:(CGAffineTransform)transform {
    CATransform3D newTransform;

    newTransform = CATransform3DMakeTranslation(0, 0, 0);
    newTransform.m[0][0] = transform.a;
    newTransform.m[0][1] = transform.b;
    newTransform.m[1][0] = transform.c;
    newTransform.m[1][1] = transform.d;
    newTransform.m[3][0] = transform.tx;
    newTransform.m[3][1] = transform.ty;

    if (memcmp(priv->transform.m, newTransform.m, sizeof(newTransform.m)) == 0) {
        return;
    }

    id<CAAction> action = [self actionForKey:_transformAction];

    memcpy(&priv->transform, &newTransform, sizeof(CATransform3D));
    priv->_frameIsCached = FALSE;

    [action runActionForKey:(id)_transformAction object:self arguments:nil];

    NSValue* transformValue = [[NSValue alloc] initWithCATransform3D:priv->transform];
    [CATransaction _setPropertyForLayer:self name:@"transform" value:transformValue];
    [transformValue release];
}

- (void)setTransform:(CATransform3D)transform {
    if (memcmp(priv->transform.m, transform.m, sizeof(transform.m)) == 0) {
        return;
    }

    id<CAAction> action = [self actionForKey:_transformAction];

    memcpy(priv->transform.m, transform.m, sizeof(transform.m));
    priv->_frameIsCached = FALSE;

    [action runActionForKey:(id)_transformAction object:self arguments:nil];

    NSValue* transformValue = [[NSValue alloc] initWithCATransform3D:priv->transform];
    [CATransaction _setPropertyForLayer:self name:@"transform" value:transformValue];
    [transformValue release];
}

- (void)setSublayerTransform:(CATransform3D)transform {
    memcpy(priv->sublayerTransform.m, transform.m, sizeof(transform.m));

    NSValue* newTransform = [[NSValue alloc] initWithCATransform3D:priv->sublayerTransform];
    [CATransaction _setPropertyForLayer:self name:@"sublayerTransform" value:newTransform];
    [newTransform release];
}

- (CATransform3D)sublayerTransform {
    return priv->sublayerTransform;
}

- (CATransform3D)transform {
    return priv->transform;
}

- (void)setDoubleSided:(BOOL)doubleSided {
}

- (void)setGeometryFlipped:(BOOL)flipped {
    EbrDebugLog("setGeometryFlipped not supported\n");
}

- (void)setBackgroundColor:(CGColorRef)color {
    if (color != nil) {
        [color getColors:&priv->backgroundColor];
    } else {
        priv->backgroundColor.r = 0.0f;
        priv->backgroundColor.g = 0.0f;
        priv->backgroundColor.b = 0.0f;
        priv->backgroundColor.a = 0.0f;
    }

    [CATransaction _setPropertyForLayer:self name:@"backgroundColor" value:(NSObject*)color];
    CGColorRef old = priv->_backgroundColor;
    priv->_backgroundColor = CGColorRetain(color);
    CGColorRelease(old);

    [self setNeedsDisplay];
}

- (void)_setContentColor:(CGColorRef)newColor {
    [newColor getColors:&priv->contentColor];
    [CATransaction _setPropertyForLayer:self name:@"contentColor" value:newColor];
}

- (void)setBorderColor:(CGColorRef)color {
    if (color != nil) {
        [color getColors:&priv->borderColor];
    } else {
        priv->borderColor.r = 0.0f;
        priv->borderColor.g = 0.0f;
        priv->borderColor.b = 0.0f;
        priv->borderColor.a = 0.0f;
    }

    CGColorRef old = priv->_borderColor;
    priv->_borderColor = CGColorRetain(color);
    CGColorRelease(old);
}

- (CGColorRef)borderColor {
    return priv->_borderColor;
}

- (void)setBorderWidth:(float)width {
    priv->borderWidth = width;
}

- (float)borderWidth {
    return priv->borderWidth;
}

- (void)setCornerRadius:(float)radius {
    priv->cornerRadius = radius;
}

- (float)cornerRadius {
    return priv->cornerRadius;
}

- (void)setContentsScale:(float)scale {
    priv->contentsScale = scale;

    NSNumber* newScale = [[NSNumber alloc] initWithFloat:priv->contentsScale];
    [CATransaction _setPropertyForLayer:self name:@"contentsScale" value:newScale];
    [newScale release];
}

- (void)setRasterizationScale:(float)scale {
    EbrDebugLog("setRasterizationScale not supported\n");
}

- (void)setShadowOffset:(CGSize)size {
}

- (CGSize)shadowOffset {
    CGSize ret;
    ret.width = 0.0f;
    ret.height = -3.0f;
    return ret;
}

- (void)setShadowOpacity:(float)opacity {
}

- (float)shadowOpacity {
    return 0.0f;
}

- (void)setShadowColor:(CGColorRef)color {
}

- (CGColorRef)shadowColor {
    return CGColorGetConstantColor((CFStringRef) @"BLACK");
}

- (void)setShadowRadius:(float)radius {
}

- (float)shadowRadius {
    return 3.0f;
}

- (void)setShouldRasterize:(BOOL)shouldRasterize {
}

- (float)contentsScale {
    return priv->contentsScale;
}

- (void)setMagnificationFilter:(NSString*)filter {
}

- (void)setEdgeAntialiasingMask:(unsigned)mask {
}

- (void)setMinificationFilter:(NSString*)filter {
}

- (void)setOpacity:(float)value {
    if (priv->opacity == value) {
        return;
    }

    id<CAAction> action = [self actionForKey:_opacityAction];

    priv->opacity = value;

    if (action != nil) {
        [action runActionForKey:(id)_opacityAction object:self arguments:nil];
    }

    NSNumber* newOpacity = [[NSNumber alloc] initWithFloat:priv->opacity];
    [CATransaction _setPropertyForLayer:self name:@"opacity" value:newOpacity];
    [newOpacity release];
}

- (float)opacity {
    return priv->opacity;
}

- (void)setName:(NSString*)name {
    priv->_name.attach([name copy]);
}

- (NSString*)name {
    return priv->_name;
}

- (NSArray*)sublayers {
    return priv->subnodesArray();
}

- (id<CAAction>)actionForKey:(NSString*)key {
    id<CAAction> ret = nil;

    if ([priv->delegate respondsToSelector:@selector(actionForLayer:forKey:)]) {
        ret = [priv->delegate actionForLayer:self forKey:key];
    }

    if (ret == nil) {
        ret = (id<CAAction>)[priv->_actions objectForKey:key];
    }

    if (ret == nil) {
        ret = (id<CAAction>)[[self class] defaultActionForKey:key];
    }

    if (ret == nil) {
        //  Implicit animation
        bool shouldAnimate = false;

        if (key == _positionAction) {
            if (priv->positionSet) {
                shouldAnimate = true;
            }
        } else if (key == _boundsOriginAction) {
            if (priv->originSet) {
                shouldAnimate = true;
            }
        } else if (key == _boundsSizeAction) {
            if (priv->sizeSet) {
                shouldAnimate = true;
            }
        } else if (key == _boundsAction) {
            if (priv->sizeSet) {
                shouldAnimate = true;
            }
        } else if (key == _transformAction) {
            shouldAnimate = true;
        } else if (key == _opacityAction) {
            shouldAnimate = true;
        }

        if (priv->superlayer == nil) {
            shouldAnimate = false;
        }

        if (shouldAnimate) {
            ret = [CATransaction _implicitAnimationForKey:key];
            if (ret != nil) {
                NSObject* value = GetCACompositor()->getDisplayProperty(priv->_presentationNode, [key UTF8String]);
                [ret setFromValue:value];
            }
        }
    }

    if ([ret isKindOfClass:[NSNull class]]) {
        return nil;
    }

    return ret;
}

+ (id<CAAction>)defaultActionForKey:(NSString*)key {
    return nil;
}

- (DisplayTexture*)_getDisplayTexture {
    //  Update if needed
    [self displayIfNeeded];

    DisplayTexture* ourTexture = NULL;

    //  Create a texture
    if (priv->contents) {
        ourTexture = GetCACompositor()->GetDisplayTextureForCGImage(priv->contents, true);
    }

    return ourTexture;
}

- (CALayer*)presentationLayer {
    return nil;
}

- (instancetype)initWithLayer:(CALayer*)layerToCopy {
    return self;
}

- (void)setNeedsDisplayOnBoundsChange:(BOOL)needsDisplayOnBoundsChange {
    priv->needsDisplayOnBoundsChange = needsDisplayOnBoundsChange;
}

- (CALayer*)hitTest:(CGPoint)point {
    if (priv->opacity <= 0.01f || priv->hidden == 1) {
        return nil;
    }

    //  Convert point to our locality
    CAPoint3D pt;
    pt.x = point.x;
    pt.y = point.y;
    pt.z = 0.0f;

    CATransform3D curTransform;
    curTransform = CATransform3DMakeTranslation(0, 0, 0);

    curTransform = CATransform3DTranslate(curTransform,
                                          -(priv->position.x - priv->bounds.size.width * priv->anchorPoint.x),
                                          -(priv->position.y - priv->bounds.size.height * priv->anchorPoint.y),
                                          0.0f);
    curTransform = CATransform3DConcat(curTransform, priv->transform);
    // curTransform.Translate(-priv->bounds.origin.x, -priv->bounds.origin.y, 0.0f);

    CATransform3DTransformPoints(curTransform, &pt, 1);

    point.x = pt.x;
    point.y = pt.y;

    //  Check sublayers
    LLTREE_FOREACH_REVERSE(curSublayer, priv) {
        CALayer* ret = [curSublayer->self hitTest:point];

        if (ret != nil) {
            return ret;
        }
    }

    if (point.x >= priv->bounds.origin.x && point.y >= priv->bounds.origin.y && point.x < priv->bounds.origin.x + priv->bounds.size.width &&
        point.y < priv->bounds.origin.x + priv->bounds.size.height) {
        return self;
    }

    return nil;
}

- (BOOL)containsPoint:(CGPoint)point {
    if (point.x >= priv->bounds.origin.x && point.y >= priv->bounds.origin.y && point.x < priv->bounds.origin.x + priv->bounds.size.width &&
        point.y < priv->bounds.origin.x + priv->bounds.size.height) {
        return TRUE;
    }

    return FALSE;
}

- (void)dealloc {
    EbrDebugLog("CALayer dealloced\n");
    [self removeAllAnimations];
    [self removeFromSuperlayer];
    while (priv->firstChild) {
        [priv->firstChild->self removeFromSuperlayer];
    }

    [_contentsElement release];

    delete priv;
    priv = NULL;
    [super dealloc];
}

- (instancetype)retain {
    return [super retain];
}

- (void)release {
    [super release];
}

- (id)valueForUndefinedKey:(NSString*)keyPath {
    char* pPath = (char*)[keyPath UTF8String];
    if (strcmp(pPath, "position.y") == 0) {
        return [NSNumber numberWithFloat:priv->position.y];
    } else if (strcmp(pPath, "transform.rotation.z") == 0) {
        CATransform3D curTransform = [self transform];
        EbrDebugLog("Should get rotation\n");
        return [NSNumber numberWithFloat:0.0f];
    } else if (strcmp(pPath, "transform.rotation") == 0) {
        CATransform3D curTransform = [self transform];

        EbrDebugLog("Should get rotation\n");
        return [NSNumber numberWithFloat:0.0f];
    } else if (strcmp(pPath, "transform.scale") == 0) {
        CATransform3D curTransform = [self transform];

        float scale[3];

        CATransform3DGetScale(curTransform, scale);
        return [NSNumber numberWithFloat:(scale[0] + scale[1] + scale[2]) / 3.0f];
    } else if (strcmp(pPath, "bounds.origin") == 0) {
        CGRect bounds = [self bounds];

        return [NSValue valueWithCGPoint:bounds.origin];
    } else if (strcmp(pPath, "bounds.size") == 0) {
        CGRect bounds = [self bounds];

        return [NSValue valueWithCGSize:bounds.size];
    } else {
        id ret = [priv->_undefinedKeys valueForKey:keyPath];
        if (ret == nil) {
            assert(0);
        }

        return ret;
    }

    return nil;
}

- (void)setValue:(id)value forUndefinedKey:(NSString*)key {
    if (priv->_undefinedKeys == nil) {
        priv->_undefinedKeys.attach([NSMutableDictionary new]);
    }
    [priv->_undefinedKeys setObject:value forKey:key];
}

- (void)setValue:(id)value forKeyPath:(NSString*)keyPath {
    if ([keyPath isEqual:@"transform.scale"]) {
        CATransform3D curTransform;
        float scale = [value floatValue];

        curTransform = [self transform];

        curTransform.m11 = scale;
        curTransform.m22 = scale;
        curTransform.m33 = 1.0f;
        curTransform.m44 = 1.0f;

        [self setTransform:curTransform];
    } else {
        [super setValue:value forKeyPath:keyPath];
    }
}

- (void)setMask:(CALayer*)mask {
    id oldLayer = priv->maskLayer;
    priv->maskLayer = [mask retain];
    [oldLayer release];
    [mask removeFromSuperlayer];
    priv->hasNewContents = TRUE;
}

- (CALayer*)mask {
    EbrDebugLog("mask not supported\n");
    return nil;
}

- (void)setFillMode:(NSString*)mode {
    EbrDebugLog("setFillMode not supported\n");
}

- (void)setShadowPath:(CGPathRef)path {
    EbrDebugLog("setShadowPath not supported\n");
}

- (CGPathRef)shadowPath {
    return nil;
}

- (NSArray*)actions {
    return priv->_actions;
}

- (void)setActions:(NSArray*)actions {
    priv->_actions.attach([actions copy]);
}

- (CGPoint)convertPoint:(CGPoint)point toLayer:(CALayer*)toLayer {
    return [CALayer convertPoint:point fromLayer:self toLayer:toLayer];
}

- (CGRect)convertRect:(CGRect)rect toLayer:(CALayer*)toLayer {
    return [CALayer convertRect:rect fromLayer:self toLayer:toLayer];
}

- (CGPoint)convertPoint:(CGPoint)point fromLayer:(CALayer*)fromLayer {
    return [CALayer convertPoint:point fromLayer:fromLayer toLayer:self];
}

- (CGRect)convertRect:(CGRect)rect fromLayer:(CALayer*)fromLayer {
    return [CALayer convertRect:rect fromLayer:fromLayer toLayer:self];
}

- (void)layoutIfNeeded {
    CALayer* curLayer = self;

    while (curLayer != nil) {
        if (curLayer->priv->superlayer == nil || ((CALayer*)curLayer->priv->superlayer)->priv->needsLayout == FALSE) {
            DoLayerLayouts(curLayer, false);
            return;
        }

        curLayer = curLayer->priv->superlayer;
    }
}

- (void)validateDisplayHierarchy {
    DoLayerLayouts(self, true);
    DoDisplayList(self);
}

- (void)discardDisplayHierarchy {
    DiscardLayerContents(self);
}

- (void)setNeedsLayout {
    priv->needsLayout = TRUE;
    GetCACompositor()->DisplayTreeChanged();
}

- (void)_setShouldLayout {
    //  Ensure that we don't repeatedly call layoutSubviews if view sizes start arguing
    if (priv->didLayout) {
        return;
    }
    [self setNeedsLayout];
}

- (void)layoutSublayers {
    if ([priv->delegate respondsToSelector:@selector(layoutSublayersOfLayer:)]) {
        [priv->delegate layoutSublayersOfLayer:self];
    }
}

- (DisplayNode*)_presentationNode {
    return priv->_presentationNode;
}

- (int)_pixelWidth {
    return (int)priv->bounds.size.width * priv->contentsScale;
}

- (int)_pixelHeight {
    return (int)priv->bounds.size.height * priv->contentsScale;
}

- (void)_setRootLayer:(BOOL)isRootLayer {
    priv->isRootLayer = isRootLayer;
}

#define MAX_DEPTH 32

void GetLayerTransform(CALayer* layer, CGAffineTransform* outTransform) {
    //  Work backwards to its root layer
    CALayer* layerList[MAX_DEPTH];
    int layerListLen = 0;

    CALayer* curLayer = (CALayer*)layer;

    while (curLayer != nil) {
        assert(layerListLen < MAX_DEPTH);
        layerList[layerListLen++] = curLayer;

        curLayer = (CALayer*)curLayer->priv->superlayer;
    }

    //  Build transform
    CGPoint origin;

    *outTransform = CGAffineTransformMakeTranslation(0.0f, 0.0f);

    origin.x = 0;
    origin.y = 0;

    for (int i = layerListLen - 1; i >= 0; i--) {
        curLayer = layerList[i];

        *outTransform =
            CGAffineTransformTranslate(*outTransform, curLayer->priv->position.x - origin.x, curLayer->priv->position.y - origin.y);

        CGAffineTransform transform;

        transform.a = curLayer->priv->transform.m[0][0];
        transform.b = curLayer->priv->transform.m[0][1];
        transform.c = curLayer->priv->transform.m[1][0];
        transform.d = curLayer->priv->transform.m[1][1];
        transform.tx = curLayer->priv->transform.m[3][0];
        transform.ty = curLayer->priv->transform.m[3][1];

        *outTransform = CGAffineTransformConcat(transform, *outTransform);
        *outTransform = CGAffineTransformTranslate(*outTransform, -curLayer->priv->bounds.origin.x, -curLayer->priv->bounds.origin.y);

        //  Calculate new center point
        origin.x = curLayer->priv->bounds.size.width * curLayer->priv->anchorPoint.x;
        origin.y = curLayer->priv->bounds.size.height * curLayer->priv->anchorPoint.y;
    }
}

+ (CGPoint)convertPoint:(CGPoint)point fromLayer:(CALayer*)fromLayer toLayer:(CALayer*)toLayer {
    CALayer* pToLayer = (CALayer*)toLayer;

    if (fromLayer != nil) {
        CALayer* pFromLayer = (CALayer*)(id)fromLayer;

        //  Convert the point to center-based position
        point.x -= pFromLayer->priv->bounds.size.width * pFromLayer->priv->anchorPoint.x;
        point.y -= pFromLayer->priv->bounds.size.height * pFromLayer->priv->anchorPoint.y;

        //  Convert to world-view
        CGAffineTransform fromTransform;
        GetLayerTransform(fromLayer, &fromTransform);
        point = CGPointApplyAffineTransform(point, fromTransform);
    }

    if (pToLayer != NULL) {
        CGAffineTransform toTransform;
        GetLayerTransform(toLayer, &toTransform);
        toTransform = CGAffineTransformInvert(toTransform);
        point = CGPointApplyAffineTransform(point, toTransform);

        //  Convert the point from center-based position
        point.x += pToLayer->priv->bounds.size.width * pToLayer->priv->anchorPoint.x;
        point.y += pToLayer->priv->bounds.size.height * pToLayer->priv->anchorPoint.y;
    }

    return point;
}

+ (CGRect)convertRect:(CGRect)pos fromLayer:(CALayer*)fromLayer toLayer:(CALayer*)toLayer {
    CGRect ret;

    CGPoint pt1 = pos.origin;
    CGPoint pt2;

    pt2 = pos.origin;
    pt2.x += pos.size.width;
    pt2.y += pos.size.height;

    pt1 = [self convertPoint:pt1 fromLayer:fromLayer toLayer:toLayer];
    pt2 = [self convertPoint:pt2 fromLayer:fromLayer toLayer:toLayer];

    ret.origin.x = pt1.x < pt2.x ? pt1.x : pt2.x;
    ret.origin.y = pt1.y < pt2.y ? pt1.y : pt2.y;
    ret.size.width = fabsf(pt1.x - pt2.x);
    ret.size.height = fabsf(pt1.y - pt2.y);

    return ret;
}

- (NSObject*)presentationValueForKey:(NSString*)key {
    return GetCACompositor()->getDisplayProperty(priv->_presentationNode, [key UTF8String]);
}
@end

void SetCACompositor(CACompositorInterface* compositorInterface) {
    _globalCompositor = compositorInterface;
}

CACompositorInterface* GetCACompositor() {
    return _globalCompositor;
}
