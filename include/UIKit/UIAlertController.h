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

#pragma once

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIViewController.h>

@class NSString;
@class UIAlertAction;
@class NSArray;
@class UITextField;

typedef enum UIAlertControllerStyle : NSInteger {
    UIAlertControllerStyleActionSheet = 0,
    UIAlertControllerStyleAlert,
} UIAlertControllerStyle;

UIKIT_EXPORT_CLASS
@interface UIAlertController
    : UIViewController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>

@property (copy, nonatomic) NSString* title;
@property (copy, nonatomic) NSString* message STUB_PROPERTY;
@property (readonly, nonatomic) UIAlertControllerStyle preferredStyle STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* actions STUB_PROPERTY;
@property (nonatomic, strong) UIAlertAction* preferredAction STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* textFields STUB_PROPERTY;

- (void)addTextFieldWithConfigurationHandler:(void (^)(UITextField*))configurationHandler STUB_METHOD;
- (void)addAction:(UIAlertAction*)action STUB_METHOD;
+ (instancetype)alertControllerWithTitle:(NSString*)title
                                 message:(NSString*)message
                          preferredStyle:(UIAlertControllerStyle)preferredStyle STUB_METHOD;
@end
