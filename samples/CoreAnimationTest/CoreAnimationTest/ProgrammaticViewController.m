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

#import "ProgrammaticViewController.h"

#import "CALayerViewController.h"
#import "CALayerAnimationViewController.h"
#import "CAShapeLayerViewController.h"

@implementation ProgrammaticViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    UIView* placeholderUIView = [[UIView alloc] init];

    // CALayer Basic
    [self addMenuItemViewController:[[CALayerViewController alloc] init] andTitle:@"CALayer Basic"];

    // CALayer Animation
    [self addMenuItemViewController:[[CALayerAnimationViewController alloc] init] andTitle:@"CALayer Animation (CAAnimation)"];

    // CAShapeLayer
    [self addMenuItemSegue:@"CAShapeLayer" andTitle:@"CAShapeLayer"];

    // CAScrollLayer
    [self addMenuItemSegue:@"CAScrollLayer" andTitle:@"CAScrollLayer"];

    // CAEmitterLayer
    [self addMenuItemSegue:@"CAEmitterLayer" andTitle:@"CAEmitterLayer"];

    // CALayer Transactions
    [self addMenuItemView:placeholderUIView andTitle:@"CALayer Transactions (CATransactions) - TBD"];

    // CALayer Transform2D
    [self addMenuItemView:placeholderUIView andTitle:@"CALayer Tranform2D - TBD"];

    // CALayer Transform3D
    [self addMenuItemView:placeholderUIView andTitle:@"CALayer Transform3D - TBD"];

    // AVPlayerLayer
    [self addMenuItemView:placeholderUIView andTitle:@"AVPlayerLayer - TBD"];

    // CAGradientLayer
    [self addMenuItemView:placeholderUIView andTitle:@"CAGradientLayer - TBD"];

    // CATextLayer
    [self addMenuItemView:placeholderUIView andTitle:@"CATextLayer - TBD"];

    // CATiledLayer
    [self addMenuItemView:placeholderUIView andTitle:@"CATiledLayer - TBD"];

    // CAEAGLLayer
    [self addMenuItemView:placeholderUIView andTitle:@"CAEAGLLayer - TBD"];

    // CAReplicatorLayer
    [self addMenuItemView:placeholderUIView andTitle:@"CAReplicatorLayer - TBD"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
