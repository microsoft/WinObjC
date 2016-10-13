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
    [_viewForLayer.layer addSublayer:_layer];

    // CALayer
    [self addMenuItemView:_viewForLayer andTitle:@""];

    // Hidden
    [self addMenuItemView:[[UISwitch alloc] init] andTitle:@"Hidden"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)setupLayer {
    _layer = [[CALayer alloc] init];
    _layer.frame = _viewForLayer.bounds;
    _layer.contents = (__bridge id)[UIImage imageNamed:@"safe"].CGImage;
    _layer.contentsGravity = kCAGravityCenter;
    _layer.geometryFlipped = NO;
    _layer.cornerRadius = 100.0;
    _layer.borderWidth = 12.0;
    _layer.borderColor = [UIColor whiteColor].CGColor;
    _layer.backgroundColor = [UIColor orangeColor].CGColor;
    _layer.shadowOpacity = 0.75;
    _layer.shadowOffset = CGSizeMake(0, 3);
    _layer.shadowRadius = 3.0;
    _layer.magnificationFilter = kCAFilterLinear;
}

@end
