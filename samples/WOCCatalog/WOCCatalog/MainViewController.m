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
#import "ButtonsViewController.h"
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
#import "FoundationsViewController.h"
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
    [self addMenuItemViewControllerClass:[GeocodingViewController class] andTitle:@"Geocoding"];

    // AudioToolbox
    [self addMenuItemViewControllerClass:[AudioToolboxViewController class] andTitle:@"AudioToolbox"];

    // CoreMotion
    [self addMenuItemViewControllerClass:[CoreMotionViewController class] andTitle:@"CoreMotion"];

    // CoreLocation
    [self addMenuItemViewControllerClass:[CoreLocationViewController class] andTitle:@"CoreLocation"];

    // Foundations tests
    [self addMenuItemViewControllerClass:[FoundationsViewController class] andTitle:@"Foundation Tests"];

    // Controls
    [self addMenuItemViewControllerClass:[ControlsViewController class] andTitle:@"Controls"];

    // Gestures
    [self addMenuItemViewControllerClass:[GesturesViewController class] andTitle:@"Gestures"];
    
    // Buttons
    [self addMenuItemViewControllerClass:[ButtonsViewController class] andTitle:@"ButtonsViewController"];

    // AutoLayout
    [self addMenuItemViewControllerClass:[AutoLayoutViewController class] andTitle:@"Constraint Based Layout"];

#ifdef WINOBJC
    // Controls
    [self addMenuItemViewControllerClass:[XamlViewController class] andTitle:@"XamlControls"];

    // Display mode
    [self addMenuItemViewControllerClass:[SBDisplayModeViewController class] andTitle:@"Display Mode"];
#endif

    // SearchBar
    [self addMenuItemViewControllerClass:[SearchBarViewController class] andTitle:@"SearchBar"];

    // OpenGL
    [self addMenuItemViewControllerClass:[OpenGLES11ViewController class] andTitle:@"Open GLES 1.1"];

    // OpenGL 2.0
    [self addMenuItemViewControllerClass:[OpenGLES20ViewController class] andTitle:@"Open GLES 2.0"];

    // GLKit
    [self addMenuItemViewControllerClass:[GLKitExampleController class] andTitle:@"GLKit"];

    // Text Display
    [self addMenuItemViewControllerClass:[TextDrawerController class] andTitle:@"Text Display"];

    // Pickers
    [self addMenuItemViewControllerClass:[PickersViewController class] andTitle:@"Pickers"];

    // Images
    [self addMenuItemViewControllerClass:[ImagesViewController class] andTitle:@"ImageView"];

    // Web
    [self addMenuItemViewControllerClass:[WebViewController class] andTitle:@"WebView"];

    // Segment
    [self addMenuItemViewControllerClass:[SegmentsViewController class] andTitle:@"Segments"];

    // Alerts
    [self addMenuItemViewControllerClass:[AlertsViewController class] andTitle:@"Alerts"];

    // CollectionView
    [self addMenuItemViewControllerClass:[PhotogridViewController class] andTitle:@"CollectionView"];

    // PageView
    [self addMenuItemViewControllerClass:[PageViewController class] andTitle:@"Page View"];

    // Bezier
    [self addMenuItemViewControllerClass:[BezierViewController class] andTitle:@"Bezier Paths"];

    // Application
    [self addMenuItemViewControllerClass:[ApplicationViewController class] andTitle:@"Application"];

    // Basic Animation
    [self addMenuItemViewControllerClass:[BasicAnimationViewController class] andTitle:@"Animation"];

    // Accelerate 1
    [self addMenuItemViewControllerClass:[AccelerateViewController class] andTitle:@"Accelerate 1"];

    // Accelerate 2
    [self addMenuItemViewControllerClass:[AccelerateViewController2 class] andTitle:@"Accelerate 2"];
    
    // Shadow
    [self addMenuItemViewControllerClass:[ShadowViewController class] andTitle:@"Shadow"];

    // UIPasteboard
    [self addMenuItemViewControllerClass:[UIPasteboardViewController class] andTitle:@"Copy And Paste"];
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
