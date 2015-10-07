/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
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

#ifndef _UITEXTVIEW_H_
#define _UITEXTVIEW_H_

#import "UIKitExport.h"
#import "UIStringDrawing.h"
#import "UIScrollView.h"
#import "UIDataDetectors.h"
#import "UITextInputTraits.h"
#import "NSTextContainer.h"
#import <UIKit/UITextInput.h>

UIKIT_EXPORT NSString *const UITextViewTextDidBeginEditingNotification;
UIKIT_EXPORT NSString *const UITextViewTextDidChangeNotification;
UIKIT_EXPORT NSString *const UITextViewTextDidEndEditingNotification;

@class UIColor, UIFont, UITextLayer, UITextView;

@protocol UITextViewDelegate <NSObject, UIScrollViewDelegate>
@optional
- (BOOL)textViewShouldBeginEditing:(UITextView *)textView;
- (void)textViewDidBeginEditing:(UITextView *)textView;
- (BOOL)textViewShouldEndEditing:(UITextView *)textView;
- (void)textViewDidEndEditing:(UITextView *)textView;
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)textViewDidChange:(UITextView *)textView;
- (void)textViewDidChangeSelection:(UITextView *)textView;
@end

UIKIT_EXPORT_CLASS
@interface UITextView : UIScrollView <UITextInputTraits, UITextInput>

- (void)scrollRangeToVisible:(NSRange)range;

@property (nonatomic) UITextAlignment textAlignment; // stub, not yet implemented!
@property (nonatomic) NSRange selectedRange;
@property (nonatomic, getter=isEditable) BOOL editable;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, retain) UIColor *textColor;
@property (nonatomic, retain) UIFont *font;
@property (nonatomic) UIDataDetectorTypes dataDetectorTypes;
@property (nonatomic, assign) id<UITextViewDelegate> delegate;

@property (nonatomic, readwrite, retain) UIView *inputAccessoryView;
@property (nonatomic, readwrite, retain) UIView *inputView;
@property (nonatomic, copy) NSAttributedString *attributedText;
@property (nonatomic, readonly) NSTextContainer *textContainer;
@property (nonatomic, assign) UIEdgeInsets textContainerInset;
@property(nonatomic, getter=isSelectable) BOOL selectable;

- (BOOL)hasText;

@end

#endif /* _UITEXTVIEW_H_ */
