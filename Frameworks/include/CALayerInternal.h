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

#import <LinkedList.h>
#import <AccessibilityInternal.h>
#import <UIKit/UIImage.h>
#import "UIColorInternal.h"

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.h>
#include "COMIncludes_End.h"

@class CAAnimation;
@class CALayer;
struct ILayerProxy;
struct IDisplayTexture;

class CADisplayProperties {
public:
    BOOL hidden;
    CGRect bounds;
    CGRect contentsRect, contentsCenter;
    uint32_t contentsOrientation; // Not a formal layer property; internally used by UIImage
    CGPoint position;
    CGPoint anchorPoint;
    CGSize contentsSize;
    float contentsScale;
    uint32_t gravity;
    BOOL masksToBounds;
    BOOL isOpaque;

    CATransform3D transform;
    __CGColorQuad backgroundColor;
    float opacity;
};

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
    BOOL needsUpdate;
    idretain _name;
    NSMutableDictionary* _animations;
    CGColorRef _backgroundColor;
    BOOL needsDisplayOnBoundsChange;

    BOOL _shouldRasterize;

    std::shared_ptr<ILayerProxy> _layerProxy;

    // The Xaml element backing this CALayer
    winrt::Windows::UI::Xaml::FrameworkElement _xamlElement;

    // The Xaml element used for hosting this layer's sublayer element
    winrt::Windows::UI::Xaml::FrameworkElement _sublayerXamlElement;

    idretain _undefinedKeys;
    idretain _actions;

    bool _frameIsCached;
    CGRect _cachedFrame;

    BOOL needsLayout;
    BOOL didLayout;
    bool _displayPending;

    CAPrivateInfo(CALayer* self, const winrt::Windows::UI::Xaml::FrameworkElement& xamlElement);
    ~CAPrivateInfo();
};

@interface CALayer (Internal)
// Xaml interop
- (instancetype)_initWithXamlElement:(const winrt::Windows::UI::Xaml::FrameworkElement&)xamlElement;
@property (nonatomic, readonly) winrt::Windows::UI::Xaml::FrameworkElement _xamlElement;

- (NSObject*)_presentationValueForKey:(NSString*)key;

- (int)_pixelWidth;
- (int)_pixelHeight;

- (void)_setOrigin:(CGPoint)origin;
- (void)_setShouldLayout;
- (void)setContentsOrientation:(UIImageOrientation)orientation;
- (UIImageOrientation)contentsOrientation;
- (std::shared_ptr<ILayerProxy>)_layerProxy;
- (void)_releaseContents:(BOOL)immediately;

// Some additional non-standard layer swapping functionality:
- (void)exchangeSublayer:(CALayer*)layer1 withLayer:(CALayer*)layer2;
- (void)exchangeSubviewAtIndex:(int)index1 withSubviewAtIndex:(int)index2;
- (void)sendSublayerToBack:(CALayer*)sublayer;
- (void)bringSublayerToFront:(CALayer*)sublayer;

// Kicks off an update to the layer's layout and display hierarchy if needed
- (void)_displayChanged;

+ (CGPoint)convertPoint:(CGPoint)point fromLayer:(CALayer*)layer toLayer:(CALayer*)layer;

- (void)_removeAnimation:(CAAnimation*)animation;
- (std::shared_ptr<IDisplayTexture>)_getDisplayTexture;

- (CAPrivateInfo*)_priv;
- (void)_setRootLayer:(BOOL)isRootLayer;

- (void)_setZIndex:(int)zIndex;

@end
