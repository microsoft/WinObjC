//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Foundation/Foundation.h>

#import "CALayerViewController.h"

@implementation CALayerViewController {
    CALayer* _layer;
    UIView* _viewForLayer;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    _viewForLayer = [[UIView alloc] init];
    _viewForLayer.frame = CGRectMake(0, 0, 200, 200);
    _viewForLayer.backgroundColor = [UIColor whiteColor];

    [self setupLayer];
    [_viewForLayer.layer addSublayer : _layer];

    // CALayer
    [self addMenuItemView:_viewForLayer andTitle : @""];

    // Hidden
    [self addMenuItemView:[[UISwitch alloc] init] andTitle : @"Hidden"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

/*
 Supported CALayer properties 10/14/16
    "contentsCenter"
    "anchorPoint"
    "position"
    "bounds.origin"
    "bounds.size"
    "opacity"
    "hidden"
    "masksToBounds"
    "transform"
    "contentsOrientation"
    "zIndex"
    "gravity"
    "backgroundColor"
*/

- (void)setupLayer {
    _layer = [[CALayer alloc] init];

    _layer.contents = (__bridge id)[UIImage imageNamed:@"safe.png"].CGImage;
    // _layer.contentsRect
    // _layer.contentsCenter
    // _layer.display
    // _layer.drawInContext

    _layer.contentsGravity = kCAGravityCenter;
    // _layer.opacity
    // _layer.hidden
    // _layer.masksToBounds
    // _layer.mask
    // _layer.doubleSided

    _layer.cornerRadius = 100.0;
    _layer.borderWidth = 12.0;
    _layer.borderColor = [UIColor whiteColor].CGColor;

    _layer.backgroundColor = [UIColor orangeColor].CGColor;

    _layer.shadowOpacity = 0.75;
    _layer.shadowRadius = 3.0;
    _layer.shadowOffset = CGSizeMake(0, 3);
    // _layer.shadowPath
    // _layer.style
    // _layer.allowsEdgeAntiAliasing
    // _layer.allowsGroupOpacity

    // _layer.filters
    // _layer.compositingFilter
    // _layer.backgroundFilters
    // _layer.minificationFilter
    // _layer.minificationFilterBias
    _layer.magnificationFilter = kCAFilterLinear;

    // _layer.opaque
    // _layer.edgeAntiAliasingMask
    // _layer.contentsAreFlipped
    _layer.geometryFlipped = NO;
    // _layer.drawsAsynchronously
    // _layer.shouldRasterize
    // _layer.rasterizationScale
    // _layer.renderInContext

    _layer.frame = _viewForLayer.bounds;
    // _layer.bounds
    // _layer.position
    // _layer.zPosition
    // _layer.anchorPointZ
    // _layer.anchorPoint
    // _layer.contentsScale

    // _layer.transfrom
    // _layer.sublayerTransform
    // _layer.affineTransform
    // _layer.setAffineTransform

    // _layer.sublayers
    // _layer.superlayer
    // _layer.addSublayer
    // _layer.removeFromSuperLayer
    // _layer.insertSublayer:atIndex
    // _layer.insertSublayer:below
    // _layer.insertSublayer:above
    // _layer.replaceSublayer:with

    // _layer.setNeedsDisplay
    // _layer.setNeedsDisplayInRect
    // _layer.needsDisplayOnBoundsChange
    // _layer.displayIfNeeded
    // _layer.needsDisplay
    // _layer.needsDisplayForKey

    // _layer.addAnimation:forKey
    // _layer.animationForKey
    // _layer.removeAllAnimations
    // _layer.removeAnimationForKey
    // _layer.animationKeys

    //....
}

@end
