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

#import "ProgrammaticViewController.h"

#import "UIActionSheetViewController.h"
#import "UIActivityIndicatorViewController.h"
#import "UIButtonWithControlsViewController.h"
#import "UILabelViewController.h"
#import "UIProgressViewController.h"
#import "UIScrollViewController.h"
#import "UISliderViewController.h"
#import "UITextFieldViewController.h"
#import "UITextFieldViewController2.h"
#import "UIViewViewController.h"
#import "CustomTextControlViewController.h"
#import "MiscellaneousViewController.h"

@implementation ProgrammaticViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // UIActionSheet
    [self addMenuItemViewController:[[UIActionSheetViewController alloc] init] andTitle:@"UIActionSheet"];

    // UIActivityIndicatorView
    [self addMenuItemViewController:[[UIActivityIndicatorViewController alloc] init] andTitle:@"UIActivityIndicatorView"];
    
    // UIProgressView
    [self addMenuItemViewController:[[UIProgressViewController alloc] init] andTitle:@"UIProgressView"];

    // UIButton
    [self addMenuItemViewController:[[UIButtonWithControlsViewController alloc] init]
                           andTitle:@"UIButton with controls to change behavior and visual appearance"];

    // UILabel
    [self addMenuItemViewController:[[UILabelViewController alloc] init] andTitle:@"UILabel"];

    // UIScrollView
    [self addMenuItemViewController:[[UIScrollViewController alloc] init] andTitle:@"UIScrollView"];

    // UISlider
    [self addMenuItemViewController:[[UISliderViewController alloc] init] andTitle:@"UISlider"];

    // UITextField
    [self addMenuItemViewController:[[UITextFieldViewController alloc] init] andTitle:@"UITextField"];

    // UITextField2
    [self addMenuItemViewController:[[UITextFieldViewController2 alloc] init] andTitle : @"UITextField2"];

    // UIViewViewController
    [self addMenuItemViewController:[[UIViewViewController alloc] init] andTitle:@"UIView"];

    // CustomTextControlViewController
    [self addMenuItemViewController:[[CustomTextControlViewController alloc] init] andTitle:@"Custom Text View"];

    // MiscellaneousViewController
    [self addMenuItemViewController:[[MiscellaneousViewController alloc] init] andTitle:@"MiscellaneousViews"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
