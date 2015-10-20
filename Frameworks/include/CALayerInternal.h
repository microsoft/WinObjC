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

#ifndef _CALAYERPRIVATE_H_
#define _CALAYERPRIVATE_H_

#import <LinkedList.h>

@class CAAnimation, CALayerContext;

class CADisplayProperties {
public:
    BOOL hidden;
    CGRect bounds;
    CGRect contentsRect, contentsCenter;
    CGRect contentsInset; //  Texture insets
    uint32_t contentsOrientation;
    CGPoint position;
    float zPosition;
    CGPoint anchorPoint;
    CGSize contentsSize;
    float contentsScale;
    uint32_t gravity;
    BOOL masksToBounds;
    BOOL isOpaque;
    BOOL drewOpaque;
    BOOL positionSet, sizeSet, originSet;

    CATransform3D transform;
    CATransform3D sublayerTransform;
    ColorQuad backgroundColor, borderColor, contentColor;
    float borderWidth, cornerRadius;
    float opacity;
};

class DisplayNode;
class DisplayTexture;
@class CALayer;

class CAPrivateInfo : public CADisplayProperties, public LLTreeNode<CAPrivateInfo, CALayer> {
public:
    id delegate;
    NSArray* sublayers;
    CALayer* superlayer;
    CGImageRef contents;
    BOOL ownsContents;
    CGContextRef savedContext;
    BOOL isRootLayer;
    BOOL needsDisplay;
    BOOL hasNewContents;
    BOOL needsUpdate;
    idretain _name;
    NSMutableDictionary* _animations;
    CGColorRef _backgroundColor, _borderColor;
    BOOL needsDisplayOnBoundsChange;

    BOOL _isPresentationLayer;

    DisplayNode* _presentationNode;
    idretain _undefinedKeys;
    idretain _actions;

    bool _frameIsCached;
    CGRect _cachedFrame;

    BOOL needsLayout;
    BOOL didLayout;
    BOOL alwaysLayout;

    CALayer* maskLayer;

    DisplayTexture* _textureOverride;

    CAPrivateInfo(CALayer* self, bool bPresentationLayer = false);
    ~CAPrivateInfo();
};

@interface CALayer (Internal)
- (NSObject*)presentationValueForKey:(NSString*)key;

- (int)_pixelWidth;
- (int)_pixelHeight;

- (void)setOrigin:(CGPoint)origin;
- (void)_setShouldLayout;

- (void)_releaseContents:(BOOL)immediately;

// Some additional non-standard layer swapping functionality:
- (void)exchangeSublayer:(CALayer*)layer1 withLayer:(CALayer*)layer2;
- (void)exchangeSubviewAtIndex:(int)index1 withSubviewAtIndex:(int)index2;
- (void)sendSublayerToBack:(CALayer*)sublayer;
- (void)bringSublayerToFront:(CALayer*)sublayer;
@end
#endif /* _CALAYERPRIVATE_H_ */
