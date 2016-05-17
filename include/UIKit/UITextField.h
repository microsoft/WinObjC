/*
* Copyright (c) 2016 Microsoft Corporation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of The Iconfactory nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#import <UIKit/UIKitTypes.h>
#import <UIKit/UITextInputTraits.h>
#import <UIKit/UITextInput.h>
#import <UIKit/UIControl.h>
#import <UIKit/UITextFieldDelegate.h>

UIKIT_EXPORT NSString* const UITextFieldTextDidBeginEditingNotification;
UIKIT_EXPORT NSString* const UITextFieldTextDidChangeNotification;
UIKIT_EXPORT NSString* const UITextFieldTextDidEndEditingNotification;

typedef NS_ENUM(NSInteger, UITextBorderStyle) {
    UITextBorderStyleNone = 0,
    UITextBorderStyleLine = 1,
    UITextBorderStyleBezel = 2,
    UITextBorderStyleRoundedRect = 3,
};

typedef NS_ENUM(NSInteger, UITextFieldViewMode) {
    UITextFieldViewModeNever,
    UITextFieldViewModeWhileEditing,
    UITextFieldViewModeUnlessEditing,
    UITextFieldViewModeAlways
};

@class UIFont, UIColor, UIImage;

UIKIT_EXPORT_CLASS
@interface UITextField : UIControl <UITextInputTraits,
                                    UIAppearance,
                                    UIAppearanceContainer,
                                    UICoordinateSpace,
                                    UIDynamicItem,
                                    UIFocusEnvironment,
                                    UITextInput,
                                    UITraitEnvironment>

// Accessing the Text Attributes
@property (nonatomic, copy) NSString* text;
@property (nonatomic, copy) NSAttributedString* attributedText STUB_PROPERTY;
@property (nonatomic, copy) NSString* placeholder;
@property (nonatomic, copy) NSAttributedString* attributedPlaceholder STUB_PROPERTY;
@property (nonatomic, copy) NSDictionary* defaultTextAttributes STUB_PROPERTY;
@property (nonatomic, strong) UIFont* font;
@property (nonatomic, strong) UIColor* textColor;
@property (nonatomic) NSTextAlignment textAlignment;
@property (nonatomic, copy) NSDictionary* typingAttributes STUB_PROPERTY;

// Sizing the Text Field’s Text
@property (nonatomic) BOOL adjustsFontSizeToFitWidth STUB_PROPERTY;
@property (nonatomic) CGFloat minimumFontSize STUB_PROPERTY;

// Managing the Editing Behavior
@property (nonatomic, readonly, getter=isEditing) BOOL editing STUB_PROPERTY;
@property (nonatomic) BOOL clearsOnBeginEditing STUB_PROPERTY;
@property (nonatomic) BOOL clearsOnInsertion STUB_PROPERTY;
@property (nonatomic) BOOL allowsEditingTextAttributes STUB_PROPERTY;

// Setting the View’s Background Appearance
@property (nonatomic) UITextBorderStyle borderStyle;
@property (nonatomic, strong) UIImage* background STUB_PROPERTY;
@property (nonatomic, strong) UIImage* disabledBackground STUB_PROPERTY;

// Managing Overlay Views
@property (nonatomic) UITextFieldViewMode clearButtonMode STUB_PROPERTY;
@property (nonatomic, strong) UIView* leftView STUB_PROPERTY;
@property (nonatomic) UITextFieldViewMode leftViewMode STUB_PROPERTY;
@property (nonatomic, strong) UIView* rightView STUB_PROPERTY;
@property (nonatomic) UITextFieldViewMode rightViewMode STUB_PROPERTY;

// Accessing the Delegate
@property (nonatomic, weak) id<UITextFieldDelegate> delegate;

// Drawing and positioning Overrides
- (CGRect)textRectForBounds:(CGRect)bounds STUB_METHOD;
- (void)drawTextInRect:(CGRect)rect STUB_METHOD;
- (CGRect)placeholderRectForBounds:(CGRect)bounds STUB_METHOD;
- (void)drawPlaceholderInRect:(CGRect)rect STUB_METHOD;
- (CGRect)borderRectForBounds:(CGRect)bounds STUB_METHOD;
- (CGRect)editingRectForBounds:(CGRect)bounds STUB_METHOD;
- (CGRect)clearButtonRectForBounds:(CGRect)bounds STUB_METHOD;
- (CGRect)leftViewRectForBounds:(CGRect)bounds STUB_METHOD;
- (CGRect)rightViewRectForBounds:(CGRect)bounds STUB_METHOD;

// Replacing the System Input Views
@property (readwrite, strong) UIView* inputView STUB_PROPERTY;
@property (readwrite, strong) UIView* inputAccessoryView STUB_PROPERTY;

// UITextInputTraits protocol defined properties,  Managing the Keyboard Behavior
@property (nonatomic) UITextAutocapitalizationType autocapitalizationType STUB_PROPERTY;
@property (nonatomic) UITextAutocorrectionType autocorrectionType;
@property (nonatomic) UITextSpellCheckingType spellCheckingType;
@property (nonatomic) BOOL enablesReturnKeyAutomatically;
@property (nonatomic) UIKeyboardAppearance keyboardAppearance STUB_PROPERTY;
@property (nonatomic) UIKeyboardType keyboardType;
@property (nonatomic) UIReturnKeyType returnKeyType STUB_PROPERTY;
@property (nonatomic, getter=isSecureTextEntry) BOOL secureTextEntry;

// UITextInput protocol properties
@property (nonatomic, readonly) UITextPosition* beginningOfDocument STUB_PROPERTY;
@property (nonatomic, readonly) UITextPosition* endOfDocument STUB_PROPERTY;
@property (readwrite, copy) UITextRange* selectedTextRange STUB_PROPERTY;

@end