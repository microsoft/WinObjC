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

#import "MenuTableViewController.h"
#import "TestEnabledUITextField.h"

@interface UIButtonWithControlsViewController : UIViewController

@property (nonatomic, readonly) UIButton* defaultButton;
@property (nonatomic, readonly) UIButton* customButton;
@property (nonatomic, readonly) UIButton* systemButton;
@property (nonatomic, readonly) UIButton* roundedRectButton;

@property (nonatomic, readonly) UISegmentedControl* segmentButtonType;

@property (nonatomic, readonly) UISwitch* switchHighlighted;
@property (nonatomic, readonly) UISwitch* switchEnabled;
@property (nonatomic, readonly) UISwitch* switchSelected;

@property (nonatomic, readonly) UISwitch* switchAdjustsImageWhenHighlighted;
@property (nonatomic, readonly) UISwitch* switchAdjustsImageWhenDisabled;

@property (nonatomic, readonly) TestEnabledUITextField* textContentEdgeInsets;
@property (nonatomic, readonly) TestEnabledUITextField* textTitleEdgeInsets;
@property (nonatomic, readonly) TestEnabledUITextField* textImageEdgeInsets;

@property (nonatomic, readonly) UIControlState titleControlState;
@property (nonatomic, readonly) TestEnabledUITextField* textTitleStateField;
@property (nonatomic, readonly) TestEnabledUITextField* textTitle;

@property (nonatomic, readonly) UIControlState titleColorControlState;
@property (nonatomic, readonly) TestEnabledUITextField* textTitleColorStateField;
@property (nonatomic, readonly) TestEnabledUITextField* textTitleColor;

@property (nonatomic, readonly) UIControlState imageControlState;
@property (nonatomic, readonly) TestEnabledUITextField* textImageStateField;
@property (nonatomic, readonly) TestEnabledUITextField* textImage;

@property (nonatomic, readonly) UIControlState backgroundImageControlState;
@property (nonatomic, readonly) TestEnabledUITextField* textBackgroundImageStateField;
@property (nonatomic, readonly) TestEnabledUITextField* textBackgroundImage;

// Public properties that represent the last assigned values for the selected button
@property (nonatomic, readonly) UIColor* titleColor;
@property (nonatomic, readonly) UIImage* image;
@property (nonatomic, readonly) UIImage* backgroundImage;

- (UIButton*)selectButton:(UIButtonType)buttonType;

@end
