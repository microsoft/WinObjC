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
#pragma once

#import "MenuTableViewController.h"
#import "TestEnabledUITextField.h"

@interface UILabelViewController : UIViewController <UITextFieldDelegate>

//
// get/set label in the VC
//
// this is UILabel that this VC is manipulating through the the controls below
@property (nonatomic) UILabel* label;

//
// getting/setting the config that impact UILabel
//
// config the text that the UILabel display
@property (nonatomic) TestEnabledUITextField* text;

// slide us to config font size
@property (nonatomic) UISlider* fontSize;

// fontSizeLabel to show current current font size
@property (nonatomic) UILabel* fontSizeLabel;

// config x/y/width/height for bounding rect
@property (nonatomic) TestEnabledUITextField* x;
@property (nonatomic) TestEnabledUITextField* y;
@property (nonatomic) TestEnabledUITextField* w;
@property (nonatomic) TestEnabledUITextField* h;

// config number of lines
@property (nonatomic) TestEnabledUITextField* numberOfLines;

// config lineBreakMode
@property (nonatomic) TestEnabledUITextField* lineBreakMode;

// switch to turn on/off setAdjustFontSizeToFitWidth
@property (nonatomic) UISwitch* autoShrink;

// config when setAdjustFontSizeToFitWidth to YES
// the minimumFontSize or minimumScaleFactor to use
@property (nonatomic) TestEnabledUITextField* minimumFontSize;
@property (nonatomic) TestEnabledUITextField* minimumScaleFactor;

//
// Start test / update or log test result
//
// start button to start enumeration of different config
// within VC

// default label text used for automatically test generation or comparsion in VC
@property (nonatomic) NSString* defaultLabelText;

@property (nonatomic) UIButton* start;

// textView to visulize the result
@property (nonatomic) UITextView* log;

// test result for one particular config
// this is mostly for logging out and debugging purpose
@property (nonatomic) NSString* result;

// textRectForBounds invoke result for one particular config
@property (nonatomic) CGRect textRect;

// sizeThatFits invoke result for one particular config
@property (nonatomic) CGSize sizeThatFits;

// intrinsicContentSize invoke result for one particular config
@property (nonatomic) CGSize intrinsicContentSize;

@end
