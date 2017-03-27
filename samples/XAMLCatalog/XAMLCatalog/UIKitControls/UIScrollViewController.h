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

#import <UIKit/UIKit.h>

@interface UIScrollViewController : UIViewController <UITextFieldDelegate, UIScrollViewDelegate>
@property (nonatomic) UIScrollView* scrollView;

@property (nonatomic) UITextField* contentSize;
@property (nonatomic) UITextField* contentOffset;
@property (nonatomic) UITextField* contentInsets;

@property (nonatomic) UISwitch* scrollEnabled;

@property (nonatomic) UISwitch* directionalLockEnabled;
@property (nonatomic) UISwitch* showHorizontalIndicator;
@property (nonatomic) UISwitch* showVerticalIndicator;

@property (nonatomic) UITextField* maxZoomScale;
@property (nonatomic) UITextField* minmumZoomScale;
@property (nonatomic) UISlider* zoomScale;

@property (nonatomic) UIView* subView;
@end
