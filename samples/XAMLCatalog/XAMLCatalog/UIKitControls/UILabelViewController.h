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

@interface UILabelViewController : UIViewController <UITextFieldDelegate>
@property (nonatomic) UITextField* text;
@property (nonatomic) UISlider* fontSize;
@property (nonatomic) UITextField* x;
@property (nonatomic) UITextField* y;
@property (nonatomic) UITextField* w;
@property (nonatomic) UITextField* h;
@property (nonatomic) UITextField* numberOfLines;
@property (nonatomic) UITextField* lineBreakMode;
@property (nonatomic) UISwitch* autoShrink;
@property (nonatomic) UITextField* minimumFontSize;
@property (nonatomic) UITextField* minimumScaleFactor;
@property (nonatomic) UILabel* label;

@property (nonatomic) UILabel* fontSizeLabel;
@property (nonatomic) UIButton* start;
@property (nonatomic) UITextView* log;

@property (nonatomic) UIButton* logResult;

@property (nonatomic) NSString* result;

@property (nonatomic) CGRect textRect;
@property (nonatomic) CGSize sizeThatFits;
@property (nonatomic) CGSize intrinsicContentSize;

@end