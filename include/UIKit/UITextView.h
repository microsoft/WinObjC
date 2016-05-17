/*
* Copyright (c) 2011, The Iconfactory. All rights reserved.
*
* Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIKitExport.h>
#import <UIKit/UIScrollView.h>
#import <UIKit/UIDataDetectors.h>
#import <UIKit/UITextInputTraits.h>
#import <UIKit/NSTextContainer.h>
#import <UIKit/UITextInput.h>
#import <UIKit/NSLayoutManager.h>
#import <UIKit/UITextViewDelegate.h>

UIKIT_EXPORT NSString* const UITextViewTextDidBeginEditingNotification;
UIKIT_EXPORT NSString* const UITextViewTextDidChangeNotification;
UIKIT_EXPORT NSString* const UITextViewTextDidEndEditingNotification;

@class UIColor, UIFont, NSLayoutManager;

UIKIT_EXPORT_CLASS
@interface UITextView : UIScrollView <UITextInputTraits, UITextInput, NSLayoutManagerDelegate>

- (instancetype)initWithFrame:(CGRect)frame textContainer:(NSTextContainer*)container;
- (void)scrollRangeToVisible:(NSRange)range STUB_METHOD;

@property (nonatomic) UITextAlignment textAlignment;
@property (nonatomic) NSRange selectedRange STUB_PROPERTY;
@property (nonatomic, getter=isEditable) BOOL editable;
@property (nonatomic, copy) NSString* text;
@property (nonatomic, retain) UIColor* textColor;
@property (nonatomic, retain) UIFont* font;
@property (nonatomic) UIDataDetectorTypes dataDetectorTypes STUB_PROPERTY;
@property (nonatomic, assign) id<UITextViewDelegate> delegate;
@property (nonatomic, readonly) NSLayoutManager* layoutManager;
@property (nonatomic, readonly) NSTextStorage* textStorage;

@property (nonatomic, readwrite, retain) UIView* inputAccessoryView STUB_PROPERTY;
@property (nonatomic, readwrite, retain) UIView* inputView STUB_PROPERTY;
@property (nonatomic, copy) NSAttributedString* attributedText;
@property (nonatomic, readonly) NSTextContainer* textContainer;
@property (nonatomic, assign) UIEdgeInsets textContainerInset;
@property (nonatomic, getter=isSelectable) BOOL selectable;

- (BOOL)hasText;

@property (nonatomic) UITextAutocapitalizationType autocapitalizationType STUB_PROPERTY;
@property (nonatomic) UITextAutocorrectionType autocorrectionType STUB_PROPERTY;
@property (nonatomic) BOOL enablesReturnKeyAutomatically STUB_PROPERTY;
@property (nonatomic) UIKeyboardAppearance keyboardAppearance STUB_PROPERTY;
@property (nonatomic, getter=isSecureTextEntry) BOOL secureTextEntry STUB_PROPERTY;
@property (nonatomic) UITextSpellCheckingType spellCheckingType STUB_PROPERTY;
@property (nonatomic) UIReturnKeyType returnKeyType STUB_PROPERTY;

@property (nonatomic, readonly) UITextPosition* beginningOfDocument STUB_PROPERTY;
@property (nonatomic, readonly) UITextPosition* endOfDocument STUB_PROPERTY;
@property (readwrite, copy) UITextRange* selectedTextRange STUB_PROPERTY;

@end
