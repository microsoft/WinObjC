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

@implementation ProgrammaticViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // CALayer Basic
    [self addMenuItemViewController:[[CALayerViewController alloc] init] andTitle:@"CALayer Basic"];

    // CALayer Animation
    [self addMenuItemViewController:[[CALayerAnimationViewController alloc] init] andTitle : @"CALayer Animation (CAAnimation)"];

    // CALayer Transactions
    [self addMenuItemViewController:[[CALayerViewController alloc] init] andTitle : @"CALayer Transactions (CATransactions)"];

    // CALayer Transform2D
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CALayer Tranform2D"];

    // CALayer Transform3D
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CALayer Transform3D - TBD"];

    // AVPlayerLayer
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"AVPlayerLayer - TBD"];

    // CAShapeLayer
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CAShapeLayer - TBD"];

    // CAGradientLayer
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CAGradientLayer - TBD"];

    // CATextLayer
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CATextLayer - TBD"];

    // CATiledLayer
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CATiledLayer - TBD"];

    // CAEAGLLayer
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CAEAGLLayer - TBD"];

    // CAScrollLayer
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CAScrollLayer - TBD"];

    // CAEmitterLayer
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CAEmitterLayer - TBD"];

    // CAReplicatorLayer
    [self addMenuItemViewController:[[UIViewController alloc] init] andTitle : @"CAReplicatorLayer - TBD"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
