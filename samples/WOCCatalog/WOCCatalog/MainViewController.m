//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import "MainViewController.h"
#import "ControlsViewController.h"
#import "TextDisplayViewController.h"
#import "TransitionsViewController.h"
#import "AlertsViewController.h"
#import "ToolbarsViewController.h"
#import "SegmentsViewController.h"
#import "WebViewController.h"
#import "SearchBarViewController.h"
#import "PickersViewController.h"
#import "ImagesViewController.h"
#import "OpenGLES11Controller.h"
#import "OpenGLES20Controller.h"
#import "GLKitExampleController.h"
#import "PhotogridViewController.h"
#import "BezierViewController.h"
#import "AutoLayoutViewController.h"
#import "PageViewController.h"
#import "ApplicationViewController.h"
#import "BasicAnimationViewController.h"
#import "AccelerateViewController.h"
#import "AccelerateViewController2.h"
#import "CoreMotionViewController.h"
#import "ShadowViewController.h"
#import "UIPasteboardViewController.h"
#import "AudioToolboxViewController.h"
#import "GeocodingViewController.h"
#import "CoreLocationViewController.h"
#import "GesturesViewController.h"
#import "LocalizationViewController.h"

#ifdef WINOBJC
#import "XamlViewController.h"
#import "DisplayModeViewController.h"
#endif

@interface MainViewController ()

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Geocoding
    [self addMenuItemViewController:[[GeocodingViewController alloc] init] andTitle:@"Geocoding"];

    // AudioToolbox
    [self addMenuItemViewController:[[AudioToolboxViewController alloc] init] andTitle:@"AudioToolbox"];

    // CoreMotion
    [self addMenuItemViewController:[[CoreMotionViewController alloc] init] andTitle:@"CoreMotion"];

    // CoreLocation
    [self addMenuItemViewController:[[CoreLocationViewController alloc] init] andTitle:@"CoreLocation"];

    // Controls
    [self addMenuItemViewController:[[ControlsViewController alloc] init] andTitle:@"Controls"];

    // Gestures
    [self addMenuItemViewController:[[GesturesViewController alloc] init] andTitle:@"Gestures"];

    // AutoLayout
    [self addMenuItemViewController:[[AutoLayoutViewController alloc] init] andTitle:@"Constraint Based Layout"];

#ifdef WINOBJC
    // Controls
    [self addMenuItemViewController:[[XamlViewController alloc] init] andTitle:@"XamlControls"];

    // Display mode
    [self addMenuItemViewController:[[SBDisplayModeViewController alloc] init] andTitle:@"Display Mode"];
#endif

    // SearchBar
    [self addMenuItemViewController:[[SearchBarViewController alloc] init] andTitle:@"SearchBar"];

    // OpenGL
    [self addMenuItemViewController:[[OpenGLES11ViewController alloc] init] andTitle:@"Open GLES 1.1"];

    // OpenGL 2.0
    [self addMenuItemViewController:[[OpenGLES20ViewController alloc] init] andTitle:@"Open GLES 2.0"];

    // GLKit
    [self addMenuItemViewController:[[GLKitExampleController alloc] init] andTitle:@"GLKit"];

    // Text Display
    [self addMenuItemViewController:[[TextDrawerController alloc] init] andTitle:@"Text Display"];

    // Pickers
    [self addMenuItemViewController:[[PickersViewController alloc] init] andTitle:@"Pickers"];

    // Images
    [self addMenuItemViewController:[[ImagesViewController alloc] init] andTitle:@"ImageView"];

    // Web
    [self addMenuItemViewController:[[WebViewController alloc] init] andTitle:@"WebView"];

    // Segment
    [self addMenuItemViewController:[[SegmentsViewController alloc] init] andTitle:@"Segments"];

    // Alerts
    [self addMenuItemViewController:[[AlertsViewController alloc] init] andTitle:@"Alerts"];

    // CollectionView
    [self addMenuItemViewController:[[PhotogridViewController alloc] init] andTitle:@"CollectionView"];

    // PageView
    [self addMenuItemViewController:[[PageViewController alloc] init] andTitle:@"Page View"];

    // Bezier
    [self addMenuItemViewController:[[BezierViewController alloc] init] andTitle:@"Bezier Paths / CAShapeLayer"];

    // Application
    [self addMenuItemViewController:[[ApplicationViewController alloc] init] andTitle:@"Application"];

    // Basic Animation
    [self addMenuItemViewController:[[BasicAnimationViewController alloc] init] andTitle:@"Animation"];

    // Accelerate 1
    [self addMenuItemViewController:[[AccelerateViewController alloc] init] andTitle:@"Accelerate 1"];

    // Accelerate 2
    [self addMenuItemViewController:[[AccelerateViewController2 alloc] init] andTitle:@"Accelerate 2"];

    // Shadow
    [self addMenuItemViewController:[[ShadowViewController alloc] init] andTitle:@"Shadow"];

    // UIPasteboard
    [self addMenuItemViewController:[[UIPasteboardViewController alloc] init] andTitle:@"Copy And Paste"];

    // Localization
    [self addMenuItemViewController:[[LocalizationViewController alloc] init] andTitle:@"Localization"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
