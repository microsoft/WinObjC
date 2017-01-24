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

#import "UIButtonWithControlsViewController.h"
#import <UIKit/UIButton.h>

@implementation UIButtonWithControlsViewController {
    MenuTableViewController* _menuTVC;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // Set up the stage for the UIButton that will be manipulated
    self.title = @"UIButton with controls";
    self.view.backgroundColor = [UIColor whiteColor];
    self.view.frame = CGRectMake(0.0f, 0.0f, 200.0f, 200.0f);

    // Configure the button
    [self setupButton];

    // TableViewController hosting the controls that manipulate UIButton
    _menuTVC = [[MenuTableViewController alloc] init];
    _menuTVC.view.frame = CGRectMake(0.0f, 200.0f, 200.0f, 0.0f /* setting it to 0 allows vertical scrolling */);
    _menuTVC.tableView.allowsSelection = NO;
    [self.view addSubview:_button];
    [self.view addSubview:_menuTVC.view];

    // UITextField that changes the text on UIButton.titleLabel for normal state
    _textButtonNormal = [[UITextField alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 150.0f, 40.0f)];
    _textButtonNormal.textColor = [UIColor blackColor];
    _textButtonNormal.backgroundColor = [UIColor lightGrayColor];
    _textButtonNormal.textAlignment = UITextAlignmentCenter;
    _textButtonNormal.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    _textButtonNormal.borderStyle = UITextBorderStyleLine;
    _textButtonNormal.font = [UIFont systemFontOfSize:15.0f];
    _textButtonNormal.adjustsFontSizeToFitWidth = YES;
    _textButtonNormal.delegate = self;
    [_textButtonNormal addTarget:self action:@selector(onTextChanged:) forControlEvents:UIControlEventEditingChanged];
    [_menuTVC addMenuItemView:_textButtonNormal andTitle:@"Text - normal state"];

    // UISlider that changes the text color on UIButton titleLabel for normal state
    _sliderTitleColorNormal = [[UISlider alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 100.0f, 40.0f)];
    _sliderTitleColorNormal.minimumValue = 0.0f;
    _sliderTitleColorNormal.maximumValue = 360.0f;
    _sliderTitleColorNormal.continuous = YES;
    _sliderTitleColorNormal.value = 0.0f;
    [_sliderTitleColorNormal addTarget:self action:@selector(titleColorNormalValueChanged) forControlEvents:UIControlEventValueChanged];
    [_menuTVC addMenuItemView:_sliderTitleColorNormal andTitle:@"Background color - normal state"];
}

// Initial configuration parameters for the UIButton
- (void)setupButton {
    _button = [[UIButton alloc] initWithFrame:self.view.bounds];
    [_button setTitle:@"Button Normal" forState:UIControlStateNormal];
    [_button setTitle:@"Button Highlighted" forState:UIControlStateHighlighted];
    [_button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [_button setTitleColor:[UIColor blueColor] forState:UIControlStateHighlighted];

    _button.backgroundColor = [UIColor lightGrayColor];
}

// Delegate to set the UIButton.titleLabel text
- (void)onTextChanged:(UITextField*)textField {
    [_button setTitle:textField.text forState:UIControlStateNormal];
}

// Delegate to dismiss the keyboard
- (BOOL)textFieldShouldReturn:(UITextField*)textField {
    [textField resignFirstResponder];

    return YES;
}

// Delegate triggererd if slider is changed for UIButton in the normal state
- (void)titleColorNormalValueChanged {
    CGFloat hue = _sliderTitleColorNormal.value / 359.0f;
    _titleColorNormal = [UIColor colorWithHue:hue saturation:hue brightness:0.4f alpha:1.0f];
    [_button setTitleColor:_titleColorNormal forState:UIControlStateNormal];
}

@end
