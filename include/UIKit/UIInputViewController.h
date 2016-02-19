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
#import <UIKit/UITextInput.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIViewController.h>

@class UIInputView;
@protocol UITextDocumentProxy;
@class UILexicon;
@class NSString;

UIKIT_EXPORT_CLASS
@interface UIInputViewController : UIViewController <NSCoding,
                                                     NSObject,
                                                     UIAppearanceContainer,
                                                     UIContentContainer,
                                                     UIFocusEnvironment,
                                                     UITextInputDelegate,
                                                     UITraitEnvironment>
@property (nonatomic, strong) UIInputView* inputView STUB_PROPERTY;
- (void)advanceToNextInputMode STUB_METHOD;
- (void)dismissKeyboard STUB_METHOD;
@property (readonly, nonatomic) id<UITextDocumentProxy> textDocumentProxy STUB_PROPERTY;
- (void)requestSupplementaryLexiconWithCompletion:(void (^)(UILexicon*))completionHandler STUB_METHOD;
@property (copy, nonatomic) NSString* primaryLanguage STUB_PROPERTY;
@end
