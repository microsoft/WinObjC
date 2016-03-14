/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
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

typedef enum {
    UITextBorderStyleNone,
    UITextBorderStyleLine,
    UITextBorderStyleBezel,
    UITextBorderStyleRoundedRect,
} UITextBorderStyle;

typedef enum {
    UITextFieldViewModeNever,
    UITextFieldViewModeWhileEditing,
    UITextFieldViewModeUnlessEditing,
    UITextFieldViewModeAlways
} UITextFieldViewMode;

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
- (CGRect)borderRectForBounds:(CGRect)bounds;
- (CGRect)clearButtonRectForBounds:(CGRect)bounds;
- (CGRect)editingRectForBounds:(CGRect)bounds;
- (CGRect)leftViewRectForBounds:(CGRect)bounds;
- (CGRect)placeholderRectForBounds:(CGRect)bounds;
- (CGRect)rightViewRectForBounds:(CGRect)bounds;
- (CGRect)textRectForBounds:(CGRect)bounds;

- (void)drawPlaceholderInRect:(CGRect)rect;
- (void)drawTextInRect:(CGRect)rect;

@property (nonatomic, assign) id<UITextFieldDelegate> delegate;
@property (nonatomic, assign) UITextAlignment textAlignment;
@property (nonatomic, copy) NSString* placeholder;
@property (nonatomic, copy) NSAttributedString* attributedPlaceholder;
@property (nonatomic, copy) NSString* text;
@property (nonatomic, copy) NSAttributedString* attributedText;
@property (copy, nonatomic) NSDictionary* defaultTextAttributes STUB_PROPERTY;
@property (nonatomic, retain) UIFont* font;
@property (copy, nonatomic) NSDictionary* typingAttributes STUB_PROPERTY;
@property (nonatomic) UITextBorderStyle borderStyle;
@property (nonatomic, retain) UIColor* textColor;
@property (nonatomic, readonly, getter=isEditing) BOOL editing;
@property (nonatomic) BOOL clearsOnBeginEditing STUB_PROPERTY;
@property (nonatomic) BOOL clearsOnInsertion STUB_PROPERTY;
@property (nonatomic) BOOL adjustsFontSizeToFitWidth STUB_PROPERTY;
@property (nonatomic) BOOL allowsEditingTextAttributes STUB_PROPERTY;
@property (nonatomic) CGFloat minimumFontSize STUB_PROPERTY;

@property (nonatomic, retain) UIImage* background;
@property (nonatomic, retain) UIImage* disabledBackground;

@property (nonatomic) UITextFieldViewMode clearButtonMode STUB_PROPERTY;
@property (nonatomic, retain) UIView* leftView STUB_PROPERTY;
@property (nonatomic) UITextFieldViewMode leftViewMode STUB_PROPERTY;
@property (nonatomic, retain) UIView* rightView STUB_PROPERTY;
@property (nonatomic) UITextFieldViewMode rightViewMode STUB_PROPERTY;

@property (nonatomic, readwrite, retain) UIView* inputAccessoryView STUB_PROPERTY;
@property (nonatomic, readwrite, retain) UIView* inputView STUB_PROPERTY;

@end
