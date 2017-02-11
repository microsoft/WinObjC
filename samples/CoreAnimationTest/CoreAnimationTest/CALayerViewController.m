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
    MenuTableViewController* _menuTVC;

    CALayer* _layer;
    UIView* _viewForLayer;

    UIImage* _safeImage;
    NSArray* _contentsGravityValues;

    UISwitch* _switchDisplayContents;
    UISwitch* _switchHidden;

    UISlider* _sliderGravity;
    UISlider* _sliderOpacity;
    UISlider* _sliderBackgroundColor;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    _safeImage = (__bridge id)[UIImage imageNamed:@"safe.png"].CGImage;
    _contentsGravityValues = @[
        kCAGravityCenter,
        kCAGravityTop,
        kCAGravityBottom,
        kCAGravityLeft,
        kCAGravityRight,
        kCAGravityTopLeft,
        kCAGravityTopRight,
        kCAGravityBottomLeft,
        kCAGravityBottomRight,
        kCAGravityResize,
        kCAGravityResizeAspect,
        kCAGravityResizeAspectFill
    ];

    // Give the layer its initial values and add it as a sublayer to the current UIView.layer
    _viewForLayer = self.view;
    _viewForLayer.frame = CGRectMake(0, 100, 200, 200);
    _viewForLayer.backgroundColor = [UIColor whiteColor];

    [self setupLayer];
    [_viewForLayer.layer addSublayer:_layer];

    // Add controls to modify the layer's appearance and behavior
    _menuTVC = [[MenuTableViewController alloc] init];
    _menuTVC.view.frame = CGRectMake(0, 350, 200, 0 /* setting it to 0 allows vertical scrolling */);
    [self.view addSubview:_menuTVC.view];

    _sliderGravity = [[UISlider alloc] initWithFrame:CGRectMake(0.0, 0.0, 100.0, 38.0)];
    _sliderGravity.minimumValue = 0;
    _sliderGravity.maximumValue = 11;
    _sliderGravity.continuous = YES;
    _sliderGravity.value = 0;
    [_sliderGravity addTarget:self action:@selector(gravityValueChanged) forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_sliderGravity andTitle:@"Gravity"];

    _switchDisplayContents = [[UISwitch alloc] init];
    [_switchDisplayContents setOn:YES animated:NO];
    [_switchDisplayContents addTarget:self action:@selector(displayContentsToggle) forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_switchDisplayContents andTitle:@"Display Contents"];

    _switchHidden = [[UISwitch alloc] init];
    [_switchHidden addTarget:self action:@selector(hiddenToggle) forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_switchHidden andTitle:@"Hidden"];

    _sliderOpacity = [[UISlider alloc] initWithFrame:CGRectMake(0.0, 0.0, 100.0, 38.0)];
    _sliderOpacity.minimumValue = 0.0f;
    _sliderOpacity.maximumValue = 1.0f;
    _sliderOpacity.continuous = YES;
    _sliderOpacity.value = 1.0f;
    [_sliderOpacity addTarget:self action:@selector(opacityValueChanged) forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_sliderOpacity andTitle:@"Opacity"];

    _sliderBackgroundColor = [[UISlider alloc] initWithFrame:CGRectMake(0.0, 0.0, 100.0, 38.0)];
    _sliderBackgroundColor.minimumValue = 0.0f;
    _sliderBackgroundColor.maximumValue = 360.0f;
    _sliderBackgroundColor.continuous = YES;
    _sliderBackgroundColor.value = 360.0f;
    [_sliderBackgroundColor addTarget:self action:@selector(backgroundColorValueChanged) forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_sliderBackgroundColor andTitle:@"Background color"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)displayContentsToggle {
    _layer.contents = _switchDisplayContents.on ? _safeImage : nil;
}

- (void)hiddenToggle {
    _layer.hidden = _switchHidden.on;
}

- (void)gravityValueChanged {
    _layer.contentsGravity = _contentsGravityValues[(int)_sliderGravity.value];
}

- (void)opacityValueChanged {
    _layer.opacity = _sliderOpacity.value;
}

- (void)backgroundColorValueChanged {
    CGFloat hue = _sliderBackgroundColor.value / 359.0f;
    UIColor* color = [UIColor colorWithHue:hue saturation:hue brightness:0.4f alpha:1.0f];
    _layer.backgroundColor = color.CGColor;
}

- (void)setupLayer {
    _layer = [[CALayer alloc] init];

    _layer.contents = _safeImage;
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
    _layer.backgroundColor = [UIColor orangeColor].CGColor;

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
