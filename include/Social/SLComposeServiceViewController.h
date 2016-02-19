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

#import <Social/SocialExport.h>

#import <Foundation/NSObject.h>

#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITextViewDelegate.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIViewController.h>

@class NSNumber;
@class UIView;
@class NSArray;
@class NSString;
@class UITextView;

SOCIAL_EXPORT_CLASS
@interface SLComposeServiceViewController
    : UIViewController <NSCoding, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITextViewDelegate, UITraitEnvironment>
- (void)presentationAnimationDidFinish STUB_METHOD;
- (void)cancel STUB_METHOD;
- (void)didSelectCancel STUB_METHOD;
- (void)didSelectPost STUB_METHOD;
- (BOOL)isContentValid STUB_METHOD;
- (void)validateContent STUB_METHOD;
- (UIView*)loadPreviewView STUB_METHOD;
- (NSArray*)configurationItems STUB_METHOD;
- (void)popConfigurationViewController STUB_METHOD;
- (void)pushConfigurationViewController:(UIViewController*)viewController STUB_METHOD;
- (void)reloadConfigurationItems STUB_METHOD;

@property (nonatomic, strong) NSNumber* charactersRemaining STUB_PROPERTY;
@property (nonatomic, strong) UIViewController* autoCompletionViewController STUB_PROPERTY;
@property (readonly, nonatomic) NSString* contentText STUB_PROPERTY;
@property (copy, nonatomic) NSString* placeholder STUB_PROPERTY;
@property (readonly, nonatomic) UITextView* textView STUB_PROPERTY;
@property (nonatomic, retain, readonly) UIView* preferredFocusedView STUB_PROPERTY;
@property (nonatomic, readonly) UITraitCollection* traitCollection;
@end
