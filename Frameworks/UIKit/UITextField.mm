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

#include "Starboard.h"

#include "CoreGraphics/CGContext.h"
#include "CGContextInternal.h"

#include "UIKit/UIView.h"
#include "UIKit/UIControl.h"
#include "Foundation/NSTimer.h"
#include "UIKit/UIViewController.h"
#include "Foundation/NSMutableString.h"
#include "Foundation/NSNotificationCenter.h"
#include "UIKit/UIFont.h"
#include "UIKit/UIColor.h"
#include "UIKit/UITextField.h"
#include "UIKit/UIImage.h"
#include "UIKit/UIImageView.h"
#include "UIKit/UITableViewCell.h"

void EbrSetKeyboardAccessory(id view);

extern float keyboardBaseHeight;
static const float INPUTVIEW_DEFAULT_HEIGHT = 200.f;

@implementation UITextField {
    idretaintype(NSString) _text;
    idretaintype(UIFont) _font;
    idretain _placeholder;
    idretain _background;
    idretaintype(UIColor) __textColor;
    idretaintype(UIColor) _tintColor;
    idretain _undoManager;
    idretaintype(UIImageView) _cursorBlink;
    idretain _popoverController, _inputController;
    NSTimer* _cursorTimer;
    id _delegate;
    UITextAlignment _alignment;
    idretaintype(UIView) _leftView, _rightView, _inputView, _inputAccessoryView;
    UITextBorderStyle _borderStyle;
    CGRect _leftViewRect;
    bool _notifiedBegin;
    UITextFieldViewMode _clearButtonMode;
    BOOL _isEditing;
    BOOL _secureTextMode;
    unsigned _returnKeyType;

    UIKeyboardType _keyboardType;
    int _showLastCharLen;
    int _showLastCharBlinkCount; //  Piggyback the disappearing password character on the cursor blink
}
- (void)setTextCentersHorizontally:(BOOL)center {
}

- (void)setText:(NSString*)text {
    if (text != nil) {
        _text = [text copy];
        [self setNeedsDisplay];
    } else {
        _text = nil;
    }
}

- (NSString*)text {
    return _text;
}

- (void)setFont:(UIFont*)font {
    _font = font;
}

- (UIFont*)font {
    return _font;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];
    _font = [coder decodeObjectForKey:@"UIFont"];
    _alignment = (UITextAlignment)[coder decodeInt32ForKey:@"UITextAlignment"];
    UITextBorderStyle borderStyle = (UITextBorderStyle)[coder decodeInt32ForKey:@"UIBorderStyle"];
    [self setBorderStyle:borderStyle];
    _keyboardType = (UIKeyboardType)[coder decodeInt32ForKey:@"UIKeyboardType"];
    _secureTextMode = [coder decodeInt32ForKey:@"UISecureTextEntry"];
    //[self setBackgroundColor:[UIColor whiteColor]];
    _text = [coder decodeObjectForKey:@"UIText"];
    __textColor = [coder decodeObjectForKey:@"UITextColor"];
    if (_text == nil)
        _text = @"";
    if (__textColor == nil)
        __textColor = [UIColor blackColor];
    _placeholder = [coder decodeObjectForKey:@"UIPlaceholder"];
    _undoManager.attach([NSUndoManager new]);

    id image =
        [[UIImage imageNamed:@"/img/TextFieldCursor@2x.png"] resizableImageWithCapInsets:UIEdgeInsetsMake(4, 0, 4, 0)];
    _cursorBlink.attach([[UIImageView alloc] initWithImage:image]);
    [_cursorBlink setHidden:TRUE];
    [self addSubview:_cursorBlink];
    [self setBackgroundColor:[UIColor clearColor]];
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
    [super initWithFrame:frame];
    _font = [UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]];
    __textColor = [UIColor blackColor];
    _text = @"";
    [self setOpaque:FALSE];
    _undoManager.attach([NSUndoManager new]);

    id image = [[UIImage imageNamed:@"/img/TextFieldCursor@2x.png"] stretchableImageWithLeftCapWidth:0 topCapHeight:8];
    _cursorBlink.attach([[UIImageView alloc] initWithImage:image]);
    [_cursorBlink setHidden:TRUE];
    [self addSubview:_cursorBlink];
    [self setBackgroundColor:[UIColor clearColor]];
    return self;
}

- (void)setMinimumFontSize:(float)size {
}

- (void)setTextColor:(UIColor*)color {
    __textColor = color;
    [self setNeedsDisplay];
}

- (void)setDelegate:(id)delegate {
    _delegate = delegate;
}

- (id)delegate {
    return _delegate;
}

- (void)setEditingDelegate:(id)delegate {
}

- (void)setClearButtonMode:(UITextFieldViewMode)mode {
    _clearButtonMode = mode;
}

- (UITextFieldViewMode)clearButtonMode {
    return _clearButtonMode;
}

- (void)setTextAlignment:(UITextAlignment)alignment {
}

- (void)setBorderStyle:(UITextBorderStyle)style {
    _borderStyle = style;
    [self setNeedsDisplay];
}

- (UITextBorderStyle)borderStyle {
    return _borderStyle;
}

- (void)setAutocapitalizationType:(UITextAutocapitalizationType)type {
}

- (void)setKeyboardType:(UIKeyboardType)type {
    _keyboardType = type;
}

- (UIKeyboardType)keyboardType {
    return _keyboardType;
}

- (void)setKeyboardAppearance:(UIKeyboardAppearance)appearance {
}

- (void)setReturnKeyType:(UIReturnKeyType)type {
    _returnKeyType = type;
}

- (UIReturnKeyType)returnKeyType {
    return (UIReturnKeyType)_returnKeyType;
}

- (void)setSpellCheckingType:(UITextSpellCheckingType)type {
}

- (void)setPlaceholder:(NSString*)str {
    _placeholder = [str copy];
}

- (NSString*)placeholder {
    return _placeholder;
}

- (void)setEnablesReturnKeyAutomatically:(BOOL)type {
}

- (void)setClearsOnBeginEditing:(BOOL)type {
}

- (void)setAutocorrectionType:(UITextAutocorrectionType)type {
}

- (void)setSecureTextEntry:(BOOL)secure {
    _secureTextMode = secure;
}

- (void)setBackground:(UIImage*)image {
    _background = image;
}

- (UIImage*)background {
    return _background;
}

- (void)drawRect:(CGRect)rect {
    id text = _text;
    id textColor = __textColor;
    bool _isPlaceholder = false;
    if (_text == nil || [_text length] == 0) {
        text = _placeholder;
        textColor = [UIColor lightGrayColor];
        _isPlaceholder = true;
    } else {
        if (_secureTextMode) {
            WORD* chars = (WORD*)malloc(([text length] + 1) * sizeof(WORD));
            [text getCharacters:chars];
            for (unsigned i = 0; i < [text length] - _showLastCharLen; i++)
                chars[i] = '*';
            text = [NSString stringWithCharacters:chars length:[text length]];
            free(chars);
        }
    }

    if (_borderStyle != UITextBorderStyleNone) {
        if ([[self layer] borderWidth] == 0.0f || _borderStyle == UITextBorderStyleRoundedRect) {
            switch (_borderStyle) {
                case UITextBorderStyleLine: {
                    rect = [self bounds];
                    rect.origin.x += 1.0f;
                    rect.origin.y += 1.0f;
                    rect.size.width -= 2.0f;
                    rect.size.height -= 2.0f;

                    CGContextRef curContext = UIGraphicsGetCurrentContext();

                    if ([self isFirstResponder]) {
                        CGContextSetStrokeColorWithColor(
                            curContext, (CGColorRef)(_tintColor ? [_tintColor CGColor] : [[UIColor redColor] CGColor]));
                    } else {
                        CGContextSetStrokeColorWithColor(curContext, (CGColorRef)[UIColor blackColor]);
                    }
                    CGContextStrokeRect(curContext, rect);
                    break;
                }

                case UITextBorderStyleRoundedRect: {
                    rect = [self bounds];
                    id image = [[UIImage imageNamed:@"/img/TextFieldRounded@2x.png"]
                        resizableImageWithCapInsets:UIEdgeInsetsMake(16, 16, 16, 16)];
                    rect = [self bounds];
                    [image drawInRect:rect];
                    break;
                }

                case UITextBorderStyleBezel: {
                    rect = [self bounds];
                    id image = [[UIImage imageNamed:@"/img/TextFieldBezel@2x.png"]
                        resizableImageWithCapInsets:UIEdgeInsetsMake(8, 8, 8, 8)];
                    rect = [self bounds];
                    [image drawInRect:rect];
                } break;
            }
        }
    }

    CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)textColor);

    CGSize size;

    rect = [self bounds];
    rect.origin.x += 5.0f;
    rect.size.width -= 10.0f;
    size = rect.size;

    if (text != nil) {
        size = [text sizeWithFont:_font
                constrainedToSize:CGSizeMake(size.width, size.height)
                    lineBreakMode:UILineBreakModeClip];
    } else {
        size = [@"" sizeWithFont:_font
                constrainedToSize:CGSizeMake(size.width, size.height)
                    lineBreakMode:UILineBreakModeClip];
    }

    rect.origin.x += _leftViewRect.size.width;
    EbrCenterTextInRectVertically(&rect, &size, _font);
    size = [text drawInRect:rect withFont:_font lineBreakMode:UILineBreakModeClip alignment:_alignment];

    if (text == nil) {
        size.width = 0;
    }
    switch (_alignment) {
        case UITextAlignmentCenter:
            rect.origin.x = rect.origin.x + rect.size.width / 2.0f - size.width / 2.0f;
            break;

        case UITextAlignmentRight:
            rect.origin.x = rect.origin.x + rect.size.width - size.width;
            break;
    }

    if (!_isPlaceholder)
        rect.origin.x += size.width;
    rect.size.width = 2;
    [_cursorBlink setFrame:rect];
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    if (_curState & UIControlStateDisabled) {
        return;
    }

    [self becomeFirstResponder];
}

- (void)deleteBackward {
    NSRange range;
    bool proceed = false;

    _showLastCharLen = 0;
    if (_text == nil) {
        _text = [NSMutableString new];
    }

    id oldString = [_text copy];
    id newString = [NSMutableString new];
    [newString setString:_text];

    id newChar = @"";

    range.location = [newString length];
    if (range.location > 0) {
        range.length = 1;
        range.location--;
        [newString deleteCharactersInRange:range];
        proceed = true;
    }

    if (proceed) {
        bool setText = true;
        if ([_delegate respondsToSelector:@selector(textField:shouldChangeCharactersInRange:replacementString:)]) {
            setText = [_delegate textField:self shouldChangeCharactersInRange:range replacementString:newChar] != FALSE;
        }

        if (setText) {
            _text = newString;
            [self sendEvent:self mask:UIControlEventEditingChanged];
            [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextFieldTextDidChangeNotification"
                                                                object:self];
            [self setNeedsDisplay];
        }
    }
}

- (void)_deleteRange:(NSNumber*)num {
    int numToDelete = [num intValue];

    for (int i = 0; i < numToDelete; i++) {
        [self deleteBackward];
    }
}

- (void)keyPressed:(unsigned short)key {
    _showLastCharLen = 0;

    if (key != 13) {
        if (key == 8) {
            [self deleteBackward];
            return;
        }

        NSRange range;

        id newChar = [NSString stringWithCharacters:&key length:1];

        if (_text == nil) {
            _text = [NSMutableString new];
        }

        id oldString = [_text copy];
        id newString = [NSMutableString new];
        [newString setString:_text];

        [newString appendString:newChar];

        range.location = [newString length] - 1;
        range.length = 1;

        bool setText = true;
        if ([_delegate respondsToSelector:@selector(textField:shouldChangeCharactersInRange:replacementString:)]) {
            setText = [_delegate textField:self shouldChangeCharactersInRange:range replacementString:newChar] != FALSE;
        }

        if (setText) {
            _text = newString;
            [self sendEvent:self mask:UIControlEventEditingChanged];
            [self setNeedsDisplay];
        }
        _showLastCharLen = 1;
        _showLastCharBlinkCount = 3;
    } else {
        BOOL dismiss = TRUE;

        if ([_delegate respondsToSelector:@selector(textFieldShouldReturn:)]) {
            dismiss = FALSE;
            if ([_delegate textFieldShouldReturn:self]) {
                dismiss = TRUE;
            }
        }

        if (dismiss) {
            if ([_delegate respondsToSelector:@selector(textFieldDidEndEditing:)]) {
                [_delegate textFieldDidEndEditing:self];
            }
            [self sendEvent:self mask:UIControlEventEditingDidEndOnExit];
            [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextFieldTextDidEndEditingNotification"
                                                                object:self];

            [self resignFirstResponder];
        }
    }
}

- (void)setAdjustsFontSizeToFitWidth:(BOOL)adjust {
}

- (void)setLeftView:(UIView*)view {
    _leftView = view;
    [self setNeedsLayout];
    [self setNeedsDisplay];
}

- (void)setInputAccessoryView:(UIView*)view {
    _inputAccessoryView = view;
    [self setNeedsLayout];
}

- (UIView*)inputAccessoryView {
    return _inputAccessoryView;
}

- (void)setInputView:(UIView*)view {
    keyboardBaseHeight = INPUTVIEW_DEFAULT_HEIGHT;
    _inputView = view;
    [self setNeedsLayout];
    [[UIApplication sharedApplication] _keyboardChanged];
}

- (UIView*)inputView {
    return _inputView;
}

- (UIView*)leftView {
    return _leftView;
}

- (void)setLeftViewMode:(UITextFieldViewMode)mode {
}

- (void)setRightView:(UIView*)view {
    _rightView = view;
    [self setNeedsLayout];
    [self setNeedsDisplay];
}

- (UIView*)rightView {
    return _rightView;
}

- (void)setRightViewMode:(UITextFieldViewMode)mode {
}

- (void)dealloc {
    _text = nil;
    _font = nil;
    _placeholder = nil;
    __textColor = nil;
    _background = nil;
    _undoManager = nil;
    _cursorBlink = nil;
    [_cursorTimer invalidate];
    _leftView = nil;
    _rightView = nil;
    _inputAccessoryView = nil;
    _inputView = nil;
    _inputController = nil;
    _tintColor = nil;
    [super dealloc];
}

- (void)layoutSubviews {
    [self setNeedsDisplay];
    if (_leftView != nil) {
        CGRect ourBounds;
        ourBounds = [self bounds];

        CGSize viewSize = { 0.0f, 0.0f };
        viewSize = [_leftView sizeThatFits:ourBounds.size];
        _leftViewRect.origin.x = 5.0f;
        _leftViewRect.size = viewSize;
        _leftViewRect.origin.y = ourBounds.size.height / 2.0f - _leftViewRect.size.height / 2.0f;
        [_leftView setFrame:_leftViewRect];
        [self addSubview:_leftView];
    }
}

- (void)_blinkCursor {
    if ([_cursorBlink isHidden]) {
        [_cursorBlink setHidden:FALSE];
    } else {
        [_cursorBlink setHidden:TRUE];
    }
    if (_showLastCharBlinkCount > 0) {
        _showLastCharBlinkCount--;
    } else {
        if (_showLastCharLen != 0) {
            _showLastCharLen = 0;
            [self setNeedsDisplay];
        }
    }
}

- (BOOL)becomeFirstResponder {
    if (_curState & UIControlStateDisabled) {
        return FALSE;
    }

    if ([self isFirstResponder]) {
        EbrRefreshKeyboard();

        return TRUE;
    }

    if ([super becomeFirstResponder] == FALSE) {
        return FALSE;
    }

    if ([_delegate respondsToSelector:@selector(textFieldShouldBeginEditing:)]) {
        if (![_delegate textFieldShouldBeginEditing:self]) {
            return FALSE;
        }
    }

    if (_inputView && [_inputView respondsToSelector:@selector(sendEvent:mask:)]) {
        [_inputView sendEvent:(id)_inputView mask:UIControlEventValueChanged];
    }

    [[UIApplication sharedApplication] _keyboardChanged];

    _cursorTimer = [NSTimer scheduledTimerWithTimeInterval:0.5
                                                    target:self
                                                  selector:@selector(_blinkCursor)
                                                  userInfo:0
                                                   repeats:TRUE];
    [_cursorBlink setHidden:FALSE];

    EbrShowKeyboard();
    _isEditing = TRUE;

    [self sendEvent:self mask:UIControlEventEditingDidBegin];
    if ([_delegate respondsToSelector:@selector(textFieldDidBeginEditing:)]) {
        [_delegate textFieldDidBeginEditing:self];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextFieldTextDidBeginEditingNotification"
                                                        object:self];
    [self setNeedsDisplay];

    return TRUE;
}

- (BOOL)resignFirstResponder {
    if (![self isFirstResponder])
        return TRUE;

    if (_isEditing) {
        if ([_delegate respondsToSelector:@selector(textFieldShouldEndEditing:)]) {
            if ([_delegate textFieldShouldEndEditing:self] == FALSE) {
                return FALSE;
            }
        }
    }
    [_cursorTimer invalidate];
    _cursorTimer = nil;

    [_cursorBlink setHidden:TRUE];

    if (_isEditing) {
        _showLastCharLen = 0;
        [self setNeedsDisplay];

        EbrHideKeyboard();

        _isEditing = FALSE;
        [self sendEvent:self mask:UIControlEventEditingDidEnd];
        if ([_delegate respondsToSelector:@selector(textFieldDidEndEditing:)]) {
            [_delegate textFieldDidEndEditing:self];
        }
        [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextFieldTextDidEndEditingNotification"
                                                            object:self];
    }
    [super resignFirstResponder];

    [[UIApplication sharedApplication] _keyboardChanged];

    return TRUE;
}

- (NSUndoManager*)undoManager {
    return _undoManager;
}

- (BOOL)isEditing {
    return _isEditing;
}

- (void)setTintColor:(UIColor*)color {
    _tintColor = color;
}

- (UIColor*)tintColor {
    return _tintColor;
}

- (CGSize)sizeThatFits:(CGSize)curSize {
    CGSize ret = { 0, 0 };

    if (_font == nil) {
        [self setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]]];
    }

    CGSize textSize = { 0 }, placeholderSize = { 0 };
    if (_text != nil) {
        textSize = [_text sizeWithFont:_font
                     constrainedToSize:CGSizeMake(curSize.width, curSize.height)
                         lineBreakMode:UILineBreakModeClip];
    }
    if (_placeholder != nil) {
        placeholderSize = [_placeholder sizeWithFont:_font
                                   constrainedToSize:CGSizeMake(curSize.width, curSize.height)
                                       lineBreakMode:UILineBreakModeClip];
    }

    if (textSize.width > placeholderSize.width) {
        ret = textSize;
    } else {
        ret = placeholderSize;
    }
    if (ret.height == 0.0f) {
        CGSize size;

        size = [@" " sizeWithFont:_font
                constrainedToSize:CGSizeMake(curSize.width, curSize.height)
                    lineBreakMode:UILineBreakModeClip];
        ret.height = size.height;
    }

    return ret;
}
@end
