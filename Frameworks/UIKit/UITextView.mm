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

#include "UIKit/UIKit.h"
#include "QuartzCore/CATextLayer.h"
#include "UIKit/UITextInputTraits.h"
#include "CGContextInternal.h"

const float textViewLeftPadding = 12.5f;
const float textViewRightPadding = 12.5f;

#define USE_TEXT_LAYER      1

extern float keyboardBaseHeight;
static const float INPUTVIEW_DEFAULT_HEIGHT = 200.f;

@interface NSString(CaretMeasurement)
    -(CGSize) sizeWithFont:(UIFont*)font  forWidth:(float)width  lineBreakMode:(UILineBreakMode)lineBreakMode  lastCharPos:(CGPoint *)lastCharPos;
@end

@implementation UITextView {
    float    _marginSize;
    idretaintype(NSString) _text;
    idretaintype(UIFont) _font;
    idretaintype(UIColor) _textColor;
    idretain _inputAccessoryView, _inputView;
    UITextAlignment _alignment;
    idretain _inputTraits;
    bool _isReadOnly, _isEditing;
    idretaintype(NSUndoManager) _undoManager;
    idretaintype(UIView) _cursorBlink;
    NSTimer *_cursorTimer;
    CGRect _cursorRect;
    id _delegate;
    bool _isResigning;
    UIKeyboardType _keyboardType;
    CGSize _curSize;
}
    -(instancetype) initWithCoder:(NSCoder *)coder {
        [super initWithCoder:coder];

        _text = [coder decodeObjectForKey:@"UIText"];
        _textColor = [coder decodeObjectForKey:@"UITextColor"];
        if ( _textColor == nil ) {
            _textColor = [UIColor blackColor];
        }

        _font = [coder decodeObjectForKey:@"UIFont"];
        _alignment = (UITextAlignment) [coder decodeInt32ForKey:@"UITextAlignment"];
        _undoManager.attach([NSUndoManager new]);
        if ( [coder containsValueForKey:@"UIEditable"] ) {
            if ( [coder decodeIntForKey:@"UIEditable"] == 0 ) {
                _isReadOnly = true;
            }
        }

        id image = [[UIImage imageNamed:@"/img/TextFieldCursor@2x.png"] stretchableImageWithLeftCapWidth:0 topCapHeight:8];
        _cursorBlink.attach([[UIImageView alloc] initWithImage:image]);
        [_cursorBlink setHidden:TRUE];
        [self addSubview: _cursorBlink];
        [super setDelegate: (id<UIScrollViewDelegate>) self];

        _marginSize = 10.0f;

        adjustTextLayerSize(self);

        return self;
    }

    -(instancetype) initWithFrame:(CGRect)frame {
        [super initWithFrame:frame];

        [self setOpaque:FALSE];
        _alignment = UITextAlignmentLeft;
        _font = [UIFont defaultFont];
        _textColor = [UIColor blackColor];
        [self setBackgroundColor:[UIColor whiteColor]];
        [self setContentMode:UIViewContentModeRedraw];

        [super setDelegate: (id<UIScrollViewDelegate>) self];

        _undoManager.attach([NSUndoManager new]);

        id image = [[UIImage imageNamed:@"/img/TextFieldCursor@2x.png"] stretchableImageWithLeftCapWidth:0 topCapHeight:8];
        _cursorBlink.attach([[UIImageView alloc] initWithImage:image]);
        [_cursorBlink setHidden:TRUE];
        [self addSubview:(id) _cursorBlink];
        _marginSize = 5.0f;

        adjustTextLayerSize(self);

        return self;
    }

#if USE_TEXT_LAYER
    +(Class) layerClass {
        return [CATextLayer class];
    }
#endif

    static void adjustTextLayerSize(UITextView *self, bool setContentPos = false)
    {
#if USE_TEXT_LAYER
        id layer = [self layer];
        [layer _setDisplayParams:(id) self->_font :(id)self->_text : (id)self->_textColor :self->_alignment :UILineBreakModeWordWrap :nil :CGPointMake(0.0f, 0.0f) :0];

        UIEdgeInsets insets;
        insets.left = textViewLeftPadding;
        insets.top = self->_marginSize;
        insets.right = textViewRightPadding;
        insets.bottom = self->_marginSize;
        [layer _setEdgeInsets:insets];
        [layer _setCenterVertically:false];
#endif 
        CGSize size;
        CGRect rect;

        rect = [self bounds];
        CGRect ourRect = rect;

        rect.origin.y = self->_marginSize;
        rect.origin.x = textViewLeftPadding;
        rect.size.width -= textViewLeftPadding + textViewRightPadding;
        rect.size.height -= self->_marginSize * 2.0f;

        CGSize fontExtent;
        CGPoint cursorPos = { 0, 0 };

        CGSize fontHeight = { 0 };
        fontHeight = [@" " sizeWithFont:(id) self->_font];
        fontExtent = [self->_text sizeWithFont: (UIFont *) self->_font forWidth:rect.size.width lineBreakMode:UILineBreakModeWordWrap lastCharPos:&cursorPos];
        
        CGRect centerRect;
        centerRect.origin.x = 0;
        centerRect.origin.y = 0;
        centerRect.size = fontExtent;
        EbrCenterTextInRectVertically(&centerRect, &fontExtent, (UIFont *) self->_font);
        rect.origin.y += centerRect.origin.y;

        cursorPos.x += rect.origin.x;
        cursorPos.y += rect.origin.y;

        rect.origin = cursorPos;
        rect.size.width = 2;
        rect.size.height = fontHeight.height;
        self->_cursorRect = rect;
        [self->_cursorBlink setFrame:rect];

        size.width = ourRect.size.width;
        size.height = fontExtent.height + self->_marginSize * 2.0f;

        CGSize curSize;
        curSize = [self contentSize];
        if ( memcmp(&size, &curSize, sizeof(CGSize)) != 0 ) [self setContentSize:size];

        [self setNeedsDisplay];

        CGRect curBounds;
        curBounds = [self bounds];

        if ( setContentPos ) {
            CGPoint curOffset;
            curOffset = [self contentOffset];

            cursorPos.x = 0;
            cursorPos.y += fontHeight.height;
            cursorPos.y += 10.0f;
            cursorPos.y -= curBounds.size.height;
            if ( cursorPos.y > size.height - curBounds.size.height ) cursorPos.y = size.height - curBounds.size.height;
            if ( cursorPos.y < 0.0f ) cursorPos.y = 0.0f;

            if ( curOffset.x != cursorPos.x ||
                 curOffset.y != cursorPos.y ) {
                [self setContentOffset:CGPointMake(cursorPos.x, cursorPos.y) animated:TRUE];
            }
        }
    }
    
    -(CGRect) caretRectForPosition:(CGPoint)position {
        return _cursorRect;
    }

    -(id<UITextInputTraits>) textInputTraits {
        return (id<UITextInputTraits>) self;
    }

    -(void) _blinkCursor {
        if ( [_cursorBlink isHidden] ) {
            [_cursorBlink setHidden:FALSE];
        } else {
            [_cursorBlink setHidden:TRUE];
        }
    }

    -(void) scrollViewDidScroll: (UIScrollView *)scroller {
#if !USE_TEXT_LAYER
        adjustTextLayerSize(self);
#endif
    }

    -(void) setTextColor:(UIColor *)color {
        _textColor = color;
        adjustTextLayerSize(self);
    }

    -(UIColor *) textColor {
        return _textColor;
    }

    -(void) setFont:(UIFont *)font {
        _font = font;
        adjustTextLayerSize(self);
    }

    -(UIFont *) font {
        return _font;
    }

    -(void) setText:(id)text {
        _text.attach([text copy]);
        adjustTextLayerSize(self);
    }

    -(void) setAttributedText:(NSAttributedString *)text {
        id attributes = [text attributesAtIndex:0 effectiveRange:NULL];
        id font = [attributes objectForKey:@"kCTFontAttributeName"];
        if ( font ) {
            [self setFont:font];
        }

        [self setText:[text string]];
    }

    -(NSString *) text {
        if ( _text == nil ) {
            _text = @"";
        }
        return _text;
    }

    -(BOOL) hasText {
        return [_text length] > 0;
    }

    -(void) setTextAlignment:(UITextAlignment)alignment {
        _alignment = alignment;
        adjustTextLayerSize(self);
    }

    -(UITextAlignment) textAlignment {
        return _alignment;
    }

    -(void) setEditable:(BOOL)editable {
        if ( editable ) {
            _isReadOnly = false;
        } else {
            _isReadOnly = true;
        }
    }

    -(BOOL) isEditable {
        if ( _isReadOnly ) return FALSE;

        return TRUE;
    }

    -(void) setSpellCheckingType:(UITextSpellCheckingType)spellType {
    }

    -(void) drawRect:(CGRect)rect {
        id text = _text;

        if ( text == nil ) text = @"";

        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), [_textColor CGColor]);

        rect = [self bounds];

        CGRect wholeRect = rect;
        rect.origin.x = textViewLeftPadding;
        rect.origin.y = 10.0f;
        rect.size.width -= textViewLeftPadding + textViewRightPadding;
        rect.size.height -= 20.0f;

        CGSize fontExtent;
        fontExtent = [text sizeWithFont:(id) _font forWidth:rect.size.width lineBreakMode:UILineBreakModeWordWrap];
        
        CGRect centerRect;
        centerRect.origin.x = 0;
        centerRect.origin.y = 0;
        centerRect.size = fontExtent;
        EbrCenterTextInRectVertically(&centerRect, &fontExtent, _font);
        rect.origin.y += centerRect.origin.y;
        rect.size.height = fontExtent.height;

        fontExtent = [text drawInRect:rect withFont:(id) _font lineBreakMode:UILineBreakModeWordWrap];
    }

    -(void) setAutocapitalizationType:(UITextAutocapitalizationType)type {
    }

    -(void) setKeyboardType:(UIKeyboardType)type {
        _keyboardType = type;
    }

    -(UIKeyboardType) keyboardType {
        return _keyboardType;
    }

    -(void) setKeyboardAppearance:(UIKeyboardAppearance)appearance {
    }

    -(void) setEnablesReturnKeyAutomatically:(BOOL)type {
    }

    -(void) setDataDetectorTypes:(UIDataDetectorTypes)type {
    }

    -(void) setClearsOnBeginEditing:(BOOL)type {
    }

    -(void) setAutocorrectionType:(UITextAutocorrectionType)type {
    }

    -(void) setSecureTextEntry:(BOOL)secure {
    }

    -(NSRange) selectedRange {
        NSRange ret;

        ret.location = 0;
        ret.length = 0;

        return ret;
    }

    -(void) setReturnKeyType:(UIReturnKeyType)type {
    }

    -(void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
        if ( !_isReadOnly ) [self becomeFirstResponder];
    }

    -(void) scrollRangeToVisible:(NSRange)range {
        EbrDebugLog("scrollRangeToVisible not implemented\n");
    }

    -(void) keyPressed:(uint32_t)key {
        NSRange range;
        bool proceed = false;

        if ( key == 13 ) key = 10;

        id newChar = [NSString stringWithCharacters:(unichar *) &key length:1];

        if ( _text == nil ) {
            _text.attach([NSMutableString new]);
        }

        NSString *oldString = [_text copy];
        NSString *newString = [NSMutableString new];
        [newString setString:(id) _text];

        if ( key == 8 ) {
            range.location = [newString length];
            if ( range.location > 0 ) {
                range.length = 1;
                range.location --;
                [newString deleteCharactersInRange:range];
                newChar = @"";
                proceed = true;
            }
        } else {
            [newString appendString:newChar];

            range.location = [newString length] - 1;
            range.length = 1;
            proceed = true;
        }

        if ( proceed ) {
            bool setText = true;
            if ( [_delegate respondsToSelector:@selector(textView:shouldChangeCharactersInRange:replacementText:)] ) {
                setText = [_delegate textView:self shouldChangeCharactersInRange:range replacementText:newChar] != 0;
            }
            if ( setText ) {
                if ( [_delegate respondsToSelector:@selector(textView:shouldChangeTextInRange:replacementText:)] ) {
                    setText = [_delegate textView:self shouldChangeTextInRange:range replacementText:newChar] != 0;
                }
            }

            if ( setText ) {
                _text = newString;
                adjustTextLayerSize(self, false);
                
                if ( [_delegate respondsToSelector:@selector(textViewDidChange:)] ) {
                    [_delegate textViewDidChange:self];
                }
                [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextViewTextDidChangeNotification" object:self];

                adjustTextLayerSize(self, true);
            }
        }
    }

    -(void) _deleteRange:(NSNumber *)num {
        NSRange range;
        int numToDelete = [num intValue];
        bool proceed = false;

        if ( _text == nil ) {
            _text.attach([NSMutableString new]);
        }

        NSString *oldString = [_text copy];
        NSString *newString = [NSMutableString new];
        [newString setString:(id) _text];
        NSString *newChar;

        range.location = [newString length];
        if ( range.location > 0 ) {
            range.length = numToDelete;
            range.location -= numToDelete;
            [newString deleteCharactersInRange:range];
            newChar = @"";
            proceed = true;
        }

        if ( proceed ) {
            bool setText = true;
            if ( [_delegate respondsToSelector:@selector(textView:shouldChangeCharactersInRange:replacementText:)] ) {
                setText = [_delegate textView:self shouldChangeCharactersInRange:range replacementText:newChar] != 0;
            }
            if ( setText ) {
                if ( [_delegate respondsToSelector:@selector(textView:shouldChangeTextInRange:replacementText:)] ) {
                    setText = [_delegate textView:self shouldChangeTextInRange:range replacementText:newChar] != 0;
                }
            }

            if ( setText ) {
                _text = newString;
                adjustTextLayerSize(self, false);
                
                if ( [_delegate respondsToSelector:@selector(textViewDidChange:)] ) {
                    [_delegate textViewDidChange:self];
                }
                [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextViewTextDidChangeNotification" object:self];

                adjustTextLayerSize(self, true);
            }
        }
    }

    -(BOOL) becomeFirstResponder {
        if ( _isReadOnly ) return FALSE;
        if ( [self isFirstResponder] ) {
            EbrRefreshKeyboard();
            return TRUE;
        }

        if ( [_delegate respondsToSelector:@selector(textViewShouldBeginEditing:)] ) {
            if ( ![_delegate textViewShouldBeginEditing:self] ) {
                return FALSE;
            }
        }

        if ( [super becomeFirstResponder] == FALSE ) return FALSE;
        EbrShowKeyboard();
        _isEditing = TRUE;
        _cursorTimer = [NSTimer scheduledTimerWithTimeInterval:0.5 target:self selector:@selector(_blinkCursor) userInfo:0 repeats:TRUE];
        [_cursorBlink setHidden:FALSE];

        if ( [_delegate respondsToSelector:@selector(textViewDidBeginEditing:)] ) {
            [_delegate textViewDidBeginEditing:self];
        }
        [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextViewTextDidBeginEditingNotification" object:self];

        return TRUE;
    }

    -(BOOL) resignFirstResponder {
        if ( ![self isFirstResponder] ) return TRUE;

        [_cursorTimer invalidate];
        _cursorTimer = nil;
        [_cursorBlink setHidden:TRUE];

        if ( _isEditing ) {
            adjustTextLayerSize(self);

            EbrHideKeyboard();
            _isEditing = FALSE;
            if ( [_delegate respondsToSelector:@selector(textViewDidEndEditing:)] ) {
                [_delegate textViewDidEndEditing:self];
            }
            [[NSNotificationCenter defaultCenter] postNotificationName:@"UITextViewTextDidEndEditingNotification" object:self];
        }
        [super resignFirstResponder];

        return TRUE;
    }

    -(NSUndoManager *) undoManager {
        return _undoManager;
    }

    -(void) setInputAccessoryView:(UIView *)view {
        _inputAccessoryView = view;
    }

    -(UIView *) inputAccessoryView {
        return _inputAccessoryView;
    }

    -(void) setInputView:(UIView *)view {
        keyboardBaseHeight = INPUTVIEW_DEFAULT_HEIGHT;
        _inputView = view;
        [self setNeedsLayout];
        [[UIApplication sharedApplication] _keyboardChanged];
    }

    -(UIView *) inputView {
        return _inputView;
    }

    -(void) dealloc {
        [_cursorTimer invalidate];
        _text = nil;
        _font = nil;
        _textColor = nil;
        _inputTraits = nil;
        _undoManager = nil;
        _cursorBlink = nil;
        _inputAccessoryView = nil;
        _inputView = nil;

        [super dealloc];
    }

    -(void) setDelegate:(id)delegate {
        _delegate = delegate;
    }

    -(void) layoutSubviews {
#if !USE_TEXT_LAYER
        adjustTextLayerSize(self);
#endif
        [super layoutSubviews];
    }

    -(void) setContentOffset:(CGPoint)offset {
        if ( offset.y < 0.0f ) offset.y = 0.0f;

        [super setContentOffset:offset];
    }
        
    -(CGSize) sizeThatFits:(CGSize)fitSize {
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

        fontExtent = [_text sizeWithFont:(id) _font forWidth:rect.size.width lineBreakMode:UILineBreakModeWordWrap lastCharPos:&cursorPos];
        
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

    -(UITextRange *) selectedTextRange {
        return [UITextRange textRangeWithPositon:[_text length] length:0];
    }
       
@end

