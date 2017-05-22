//******************************************************************************
//
// Copyright Microsoft Corporation. All rights reserved.
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

@interface UITextFieldViewController2 : UIViewController <UITextFieldDelegate>

//
// get/set label in the VC
//
// this is UITextFeild that this VC is manipulating through the the controls below
@property (nonatomic) UITextField* textField;

//
// getting/setting the config that impact UITextField
//
// config the text that the UITextField display
@property (nonatomic) TestEnabledUITextField* text;

// config the Placeholder that the UITextField display
@property (nonatomic) TestEnabledUITextField* placeholder;

// slide us to config font size
@property (nonatomic) UISlider* fontSize;

// fontSizeLabel to show current current font size
@property (nonatomic) UILabel* fontSizeLabel;

// config x/y/width/height for bounding rect
@property (nonatomic) TestEnabledUITextField* x;
@property (nonatomic) TestEnabledUITextField* y;
@property (nonatomic) TestEnabledUITextField* w;
@property (nonatomic) TestEnabledUITextField* h;

// config the text alignment
@property (nonatomic) TestEnabledUITextField* textAlignment;

// config borderStyle for UITextField
@property (nonatomic) TestEnabledUITextField* borderStyle;

// config Input for UITextField
@property (nonatomic) TestEnabledUITextField* keyboardType;

// config r/g/b component for foreground
@property (nonatomic) UISlider* fr;
@property (nonatomic) UISlider* fg;
@property (nonatomic) UISlider* fb;

// config r/g/b component for background
@property (nonatomic) UISlider* br;
@property (nonatomic) UISlider* bg;
@property (nonatomic) UISlider* bb;

// switch to turn on/off secureEntry Mode
@property (nonatomic) UISwitch* secureEntry;

// switch to turn on/off setAdjustFontSizeToFitWidth
@property (nonatomic) UISwitch* autoShrink;

// config the minimumFontSize when setAdjustFontSizeToFitWidth to YES
@property (nonatomic) TestEnabledUITextField* minimumFontSize;

@end
