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

#import "UIKit/UIKit.h"
#import "UIKit/UITextInputTraits.h"
#import "QuartzCore/CATextLayer.h"
#import "CGContextInternal.h"
#import "NSTextStorageInternal.h"
#import "LoggingNative.h"
#import "UIFontInternal.h"
#import "StubReturn.h"
#import "UIResponderInternal.h"
#import "UIApplicationInternal.h"
#import <UIKit/UITextViewDelegate.h>

static const wchar_t* TAG = L"UITextView";

const float textViewLeftPadding = 12.5f;
const float textViewRightPadding = 12.5f;

//#define USE_TEXT_LAYER 1

NSString* const UITextViewTextDidBeginEditingNotification = @"UITextViewTextDidBeginEditingNotification";
NSString* const UITextViewTextDidChangeNotification = @"UITextViewTextDidChangeNotification";
NSString* const UITextViewTextDidEndEditingNotification = @"UITextViewTextDidEndEditingNotification";

extern float keyboardBaseHeight;
static const float INPUTVIEW_DEFAULT_HEIGHT = 200.f;

@interface NSString (CaretMeasurement)
- (CGSize)sizeWithFont:(UIFont*)font forWidth:(float)width lineBreakMode:(UILineBreakMode)lineBreakMode lastCharPos:(CGPoint*)lastCharPos;
@end

@interface UITextView ()
@property (nonatomic) NSString* _text;
@end

@implementation UITextView {
    float _marginSize;
    idretaintype(UIFont) _font;
    idretaintype(UIColor) _textColor;
    idretain _inputAccessoryView, _inputView;
    UITextAlignment _alignment;
    idretain _inputTraits;
    bool _isReadOnly, _isEditing;
    idretaintype(NSUndoManager) _undoManager;
    idretaintype(UIView) _cursorBlink;
    NSTimer* _cursorTimer;
    CGRect _cursorRect;
    id _delegate;
    bool _isResigning;
    UIKeyboardType _keyboardType;
    CGSize _curSize;
    NSTextContainer* _textContainer;
}

- (void)_setText:(NSString*)text {
    if (![[self _text] isEqualToString:text]) {
        [self _resetAttributedString:text];
    }
}

- (NSString*)_text {
    NSString* ret = [_layoutManager.textStorage string];
    if ([ret length] == 0) {
        return @"";
    }

    return ret;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];

    _textContainer = [[NSTextContainer alloc] initWithSize:CGSizeMake(self.frame.size.width, FLT_MAX)];
    _layoutManager = [NSLayoutManager new];
    [_layoutManager addTextContainer:_textContainer];
    _layoutManager.delegate = self;
    _layoutManager.textStorage = [NSTextStorage new];

    _textColor = [coder decodeObjectForKey:@"UITextColor"];
    if (_textColor == nil) {
        _textColor = [UIColor blackColor];
    }

    _font = [coder decodeObjectForKey:@"UIFont"];
    if (_font == nil) {
        _font = [UIFont defaultFont];
    }

    _alignment = (UITextAlignment)[coder decodeInt32ForKey:@"UITextAlignment"];
    _undoManager.attach([NSUndoManager new]);
    if ([coder containsValueForKey:@"UIEditable"]) {
        if ([coder decodeIntForKey:@"UIEditable"] == 0) {
            _isReadOnly = true;
        }
    }

    id image = [[UIImage imageNamed:@"/img/TextFieldCursor@2x.png"] stretchableImageWithLeftCapWidth:0 topCapHeight:8];
    _cursorBlink.attach([[UIImageView alloc] initWithImage:image]);
    [_cursorBlink setHidden:TRUE];
    [self addSubview:_cursorBlink];
    [super setDelegate:(id<UIScrollViewDelegate>)self];

    _marginSize = 10.0f;

    [self _adjustTextLayerSize:FALSE];

    // this will take care of regenerating the attributed string 
    [self _setText:[coder decodeObjectForKey:@"UIText"]];

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame textContainer:(NSTextContainer*)container {
    self = [self initWithFrame:frame];
    _textContainer = [container retain];
    _layoutManager = [container.layoutManager retain];
    _layoutManager.delegate = self;
    [self _adjustTextLayerSize:FALSE];

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    [super initWithFrame:frame];

    [self setOpaque:FALSE];

    _textContainer = [[NSTextContainer alloc] initWithSize:CGSizeMake(self.frame.size.width, FLT_MAX)];
    _layoutManager = [NSLayoutManager new];
    [_layoutManager addTextContainer:_textContainer];
    _layoutManager.delegate = self;
    _layoutManager.textStorage = [NSTextStorage new];

    _alignment = UITextAlignmentLeft;
    _font = [UIFont defaultFont];
    _textColor = [UIColor blackColor];
    [self setBackgroundColor:[UIColor whiteColor]];
    [self setContentMode:UIViewContentModeRedraw];

    [super setDelegate:(id<UIScrollViewDelegate>)self];

    _undoManager.attach([NSUndoManager new]);

    id image = [[UIImage imageNamed:@"/img/TextFieldCursor@2x.png"] stretchableImageWithLeftCapWidth:0 topCapHeight:8];
    _cursorBlink.attach([[UIImageView alloc] initWithImage:image]);
    [_cursorBlink setHidden:TRUE];
    [self addSubview:(id)_cursorBlink];
    _marginSize = 5.0f;

    [self _adjustTextLayerSize:FALSE];
    self.showsHorizontalScrollIndicator = FALSE;

    return self;
}


/**
 @Status Interoperable
*/
- (void)setShowsHorizontalScrollIndicator:(BOOL)show {
    [super setShowsHorizontalScrollIndicator:FALSE];
}


- (void)_adjustTextLayerSize:(BOOL)setContentPos {
    CGSize size;
    CGRect allText = [_layoutManager usedRectForTextContainer:_textContainer];

    [self setNeedsDisplay];

    size.width = self.bounds.size.width;
    size.height = allText.size.height + self->_marginSize * 2.0f;

    CGSize curSize;
    curSize = [self contentSize];
    if (memcmp(&size, &curSize, sizeof(CGSize)) != 0) {
        [self setContentSize:size];
    }

    if ([_layoutManager.textStorage length] > 0) {
        self->_cursorRect = _layoutManager.extraLineFragmentRect;
        [self->_cursorBlink setFrame:self->_cursorRect];
    }

    CGRect curBounds;
    curBounds = [self bounds];

    if (setContentPos) {
        CGPoint curOffset;
        curOffset = [self contentOffset];

        CGPoint cursorPos;
        cursorPos.x = 0;
        cursorPos.y = self->_cursorRect.origin.y + self->_cursorRect.size.height;
        cursorPos.y += 10.0f;
        cursorPos.y -= curBounds.size.height;
        if (cursorPos.y > curSize.height - curBounds.size.height) {
            cursorPos.y = curSize.height - curBounds.size.height;
        }
        if (cursorPos.y < 0.0f) {
            cursorPos.y = 0.0f;
        }

        if (curOffset.x != cursorPos.x || curOffset.y != cursorPos.y) {
            [self setContentOffset:CGPointMake(cursorPos.x, cursorPos.y) animated:TRUE];
        }
    }
}

/**
 @Status Interoperable
*/
- (CGRect)caretRectForPosition:(UITextPosition*)position {
    return _cursorRect;
}

/**
 @Status Stub
*/
- (id<UITextInputTraits>)textInputTraits {
    return (id<UITextInputTraits>)self;
}

- (void)_blinkCursor {
    if ([_cursorBlink isHidden]) {
        [_cursorBlink setHidden:FALSE];
    } else {
        [_cursorBlink setHidden:TRUE];
    }
}

- (void)scrollViewDidScroll:(UIScrollView*)scroller {
#if !USE_TEXT_LAYER
    [self _adjustTextLayerSize:FALSE];
#endif
}

- (void)_resetAttributedString:(NSString *)newString {
    // re-generate attributed string using current style-reatled properties
    NSMutableDictionary* attributes = [NSMutableDictionary dictionary];
    attributes[NSFontAttributeName] = _font;
    attributes[NSForegroundColorAttributeName] = _textColor;

    // more style-related properties should be included here as we adding support for them
    // currently supported properties include font, text and textColor.

    NSAttributedString* attributedString;
    if (newString == nil) {
        attributedString = [[NSAttributedString alloc] initWithString:[self _text] attributes:attributes];
    } else {
        attributedString = [[NSAttributedString alloc] initWithString:newString attributes:attributes];
    }

    [self setAttributedText:attributedString];
}

/**
 @Status Interoperable
*/
- (void)setTextColor:(UIColor*)color {
    if (![_textColor isEqual:color]) {
        _textColor = color;
        [self.textStorage setDefaultAttribute:color forKey:NSForegroundColorAttributeName];
        [self _adjustTextLayerSize:FALSE];
        [self _resetAttributedString:nil];
    }
}

/**
 @Status Interoperable
*/
- (UIColor*)textColor {
    return _textColor;
}

/**
 @Status Interoperable
*/
- (void)setFont:(UIFont*)font {
    if (![_font isEqual:font]) {
        _font = font;
        [self.textStorage setDefaultAttribute:font forKey:NSFontAttributeName];
        [self _adjustTextLayerSize:FALSE];
        [self _resetAttributedString:nil];
    }
}

/**
 @Status Interoperable
*/
- (UIFont*)font {
    return _font;
}

/**
 @Status Interoperable
*/
- (void)setText:(NSString*)text {
    [self _setText:text];
}

/**
 @Status Interoperable
*/
- (void)setAttributedText:(NSAttributedString*)text {
    [_layoutManager.textStorage beginEditing];
    [_layoutManager.textStorage setAttributedString:text];
    [_layoutManager.textStorage endEditing];
}

/**
 @Status Interoperable
*/
- (NSAttributedString*)attributedText {
    return _layoutManager.textStorage;
}

/**
 @Status Interoperable
*/
- (NSString*)text {
    if ([self _text] == nil) {
        return @"";
    }
    return [self _text];
}

/**
 @Status Interoperable
*/
- (BOOL)hasText {
    return [[self _text] length] > 0;
}

/**
 @Status Interoperable
*/
- (void)setTextAlignment:(UITextAlignment)alignment {
    _alignment = alignment;
    [self _adjustTextLayerSize:FALSE];
}

/**
 @Status Interoperable
*/
- (UITextAlignment)textAlignment {
    return _alignment;
}

/**
 @Status Interoperable
*/
- (void)setEditable:(BOOL)editable {
    if (editable) {
        _isReadOnly = false;
    } else {
        _isReadOnly = true;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isEditable {
    if (_isReadOnly) {
        return FALSE;
    }

    return TRUE;
}

/**
 @Status Stub
*/
- (void)setSpellCheckingType:(UITextSpellCheckingType)spellType {
}

/**
 @Status Interoperable
*/
- (void)drawRect:(CGRect)rect {
    CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), [_textColor CGColor]);

    NSRange range;
    range.location = 0;
    range.length = INT_MAX;
    [_layoutManager drawBackgroundForGlyphRange:range atPoint:CGPointMake(_textContainerInset.top, _textContainerInset.left)];
    [_layoutManager drawGlyphsForGlyphRange:range atPoint:CGPointMake(_textContainerInset.top, _textContainerInset.left)];
}

/**
 @Status Interoperable
*/
- (NSTextStorage*)textStorage {
    return _layoutManager.textStorage;
}

/**
 @Status Interoperable
*/
- (void)layoutManagerDidInvalidateLayout:(NSLayoutManager*)sender {
    [self _adjustTextLayerSize:FALSE];
    [self setNeedsDisplay];
}

/**
 @Status Stub
*/
- (void)setAutocapitalizationType:(UITextAutocapitalizationType)type {
}

/**
 @Status Stub
*/
- (void)setKeyboardType:(UIKeyboardType)type {
    _keyboardType = type;
}

/**
 @Status Stub
*/
- (UIKeyboardType)keyboardType {
    return _keyboardType;
}

/**
 @Status Stub
*/
- (void)setKeyboardAppearance:(UIKeyboardAppearance)appearance {
}

/**
 @Status Stub
*/
- (void)setEnablesReturnKeyAutomatically:(BOOL)type {
}

/**
 @Status Stub
*/
- (void)setDataDetectorTypes:(UIDataDetectorTypes)type {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setClearsOnBeginEditing:(BOOL)type {
}

/**
 @Status Stub
*/
- (void)setAutocorrectionType:(UITextAutocorrectionType)type {
}

/**
 @Status Stub
*/
- (void)setSecureTextEntry:(BOOL)secure {
}

/**
 @Status Stub
*/
- (NSRange)selectedRange {
    UNIMPLEMENTED();
    NSRange ret;

    ret.location = 0;
    ret.length = 0;

    return ret;
}

/**
 @Status Stub
*/
- (void)setReturnKeyType:(UIReturnKeyType)type {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    if (!_isReadOnly) {
        [self becomeFirstResponder];
    }
}

/**
 @Status Stub
*/
- (void)scrollRangeToVisible:(NSRange)range {
    UNIMPLEMENTED_WITH_MSG("scrollRangeToVisible not implemented");
}

- (void)_keyPressed:(unsigned short)key {
    NSRange range;
    bool proceed = false;

    if (key == 13) {
        key = 10;
    }

    bool insertCharacters = true;
    NSString* character = [NSString stringWithCharacters:(unichar*)&key length:1];

    if (key == 8) {
        range.location = [[self attributedText] length];
        if (range.location > 0) {
            range.length = 1;
            range.location--;
            character = @"";
            proceed = true;
            insertCharacters = false;
        }
    } else {
        range.location = [[self attributedText] length];
        range.length = 1;
        proceed = true;
    }

    if (proceed) {
        bool setText = true;

        if (setText) {
            if ([_delegate respondsToSelector:@selector(textView:shouldChangeTextInRange:replacementText:)]) {
                setText = [_delegate textView:self shouldChangeTextInRange:range replacementText:character] != 0;
            }
        }

        if (setText) {
            [_layoutManager.textStorage beginEditing];
            if (insertCharacters) {
                NSDictionary* attrs = [_layoutManager.textStorage attributesAtIndex:range.location - 1 effectiveRange:NULL];
                NSAttributedString* newString = [[[NSAttributedString alloc] initWithString:character attributes:attrs] autorelease];
                [_layoutManager.textStorage insertAttributedString:newString atIndex:range.location];
            } else {
                [_layoutManager.textStorage deleteCharactersInRange:range];
            }

            [_layoutManager.textStorage endEditing];
            [self _adjustTextLayerSize:TRUE];

            if ([_delegate respondsToSelector:@selector(textViewDidChange:)]) {
                [_delegate textViewDidChange:self];
            }
            [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextViewTextDidChangeNotification" object:self];
        }
    }
}

/**
 @Status Interoperable
*/
- (BOOL)becomeFirstResponder {
    if (_isReadOnly) {
        return FALSE;
    }
    if ([self isFirstResponder]) {
        return TRUE;
    }

    if ([_delegate respondsToSelector:@selector(textViewShouldBeginEditing:)]) {
        if (![_delegate textViewShouldBeginEditing:self]) {
            return FALSE;
        }
    }

    if ([super becomeFirstResponder] == FALSE) {
        return FALSE;
    }

    _isEditing = TRUE;
    _cursorTimer = [NSTimer scheduledTimerWithTimeInterval:0.5 target:self selector:@selector(_blinkCursor) userInfo:0 repeats:TRUE];
    [_cursorBlink setHidden:FALSE];

    if ([_delegate respondsToSelector:@selector(textViewDidBeginEditing:)]) {
        [_delegate textViewDidBeginEditing:self];
    }
    [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextViewTextDidBeginEditingNotification" object:self];

    return TRUE;
}

/**
 @Status Interoperable
*/
- (BOOL)resignFirstResponder {
    if (![self isFirstResponder]) {
        return TRUE;
    }

    [_cursorTimer invalidate];
    _cursorTimer = nil;
    [_cursorBlink setHidden:TRUE];

    if (_isEditing) {
        [self _adjustTextLayerSize:FALSE];

        _isEditing = FALSE;
        if ([_delegate respondsToSelector:@selector(textViewDidEndEditing:)]) {
            [_delegate textViewDidEndEditing:self];
        }
        [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextViewTextDidEndEditingNotification" object:self];
    }
    [super resignFirstResponder];

    return TRUE;
}

/**
 @Status Stub
*/
- (NSUndoManager*)undoManager {
    return _undoManager;
}

/**
 @Status Stub
*/
- (void)setInputAccessoryView:(UIView*)view {
    UNIMPLEMENTED();
    _inputAccessoryView = view;
}

/**
 @Status Stub
*/
- (UIView*)inputAccessoryView {
    UNIMPLEMENTED();
    return _inputAccessoryView;
}

/**
 @Status Stub
*/
- (void)setInputView:(UIView*)view {
    UNIMPLEMENTED();
    keyboardBaseHeight = INPUTVIEW_DEFAULT_HEIGHT;
    _inputView = view;
    [self setNeedsLayout];
    [[UIApplication sharedApplication] _keyboardChanged];
}

/**
 @Status Stub
*/
- (UIView*)inputView {
    UNIMPLEMENTED();
    return _inputView;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_cursorTimer invalidate];
    _font = nil;
    _textColor = nil;
    _inputTraits = nil;
    _undoManager = nil;
    _cursorBlink = nil;
    _inputAccessoryView = nil;
    _inputView = nil;
    [_textContainer release];
    [_layoutManager release];

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (NSTextContainer*)textContainer {
    return _textContainer;
}

/**
 @Status Interoperable
*/

/**
 @Status Interoperable
*/
- (void)setDelegate:(id)delegate {
    _delegate = delegate;
}

/**
 @Status Interoperable
*/
- (void)layoutSubviews {
    if (self.bounds.size.width != _curSize.width) {
        _curSize = self.bounds.size;
        _textContainer.size = CGSizeMake(self.bounds.size.width, FLT_MAX);
    }
#if !USE_TEXT_LAYER
    [self _adjustTextLayerSize:FALSE];
#endif
    [super layoutSubviews];
}

/**
 @Status Interoperable
*/
- (void)setContentOffset:(CGPoint)offset {
    if (offset.y < 0.0f) {
        offset.y = 0.0f;
    }

    [super setContentOffset:offset];
}

/**
 @Status Interoperable
*/
- (CGSize)sizeThatFits:(CGSize)fitSize {
    CGSize ret;

    CGRect rect;

    rect.origin.x = 0.0f;
    rect.origin.y = 0.0f;
    rect.size = fitSize;
    CGRect ourRect = rect;

    rect.origin.y = _marginSize;
    rect.origin.x = textViewLeftPadding;
    rect.size.width -= textViewLeftPadding + textViewRightPadding;
    rect.size.height -= _marginSize * 2.0f;

    CGSize fontExtent = { 0, 0 };
    CGPoint cursorPos = { 0, 0 };

    fontExtent =
        [[self _text] sizeWithFont:(id)_font forWidth:rect.size.width lineBreakMode:UILineBreakModeWordWrap lastCharPos:&cursorPos];

    CGRect centerRect;
    centerRect.origin.x = 0;
    centerRect.origin.y = 0;
    centerRect.size = fontExtent;
    EbrCenterTextInRectVertically(&centerRect, &fontExtent, _font);
    rect.origin.y += centerRect.origin.y;

    ret.width = ourRect.size.width;
    ret.height = fontExtent.height + _marginSize * 2.0f;

    return ret;
}

/**
 @Status Stub
*/
- (void)insertText:(NSString*)text {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)deleteBackward {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (UITextPosition*)positionFromPosition:(UITextPosition*)position offset:(NSInteger)offset {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UITextRange*)textRangeFromPosition:(UITextPosition*)fromPosition toPosition:(UITextPosition*)toPosition {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes Method from UITextInput protocol.
*/
- (CGRect)firstRectForRange:(UITextRange*)range {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
