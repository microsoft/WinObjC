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
#include "Foundation/NSString.h"
#include "CoreGraphics/CGContext.h"

#include "UIKit/UIView.h"
#include "UIKit/UIFont.h"
#include "UIKit/UIColor.h"
#include "UIKit/UILabel.h"

#include "CGContextInternal.h"

#include "QuartzCore/CATextLayer.h"
#define USE_TEXT_LAYER 1

@implementation UILabel {
    idretaintype(NSString) _text;
    idretaintype(UIFont) _font;
    idretaintype(UIColor) _textColor, _shadowColor, _highlightedTextColor;
    idretaintype(NSAttributedString) _attributedText;
    idretaintype(UIColor) _savedBackgroundColor;
    CATextLayer* _textLayer;
    CGSize _shadowOffset;
    UITextAlignment _alignment;
    UILineBreakMode _lineBreakMode;
    BOOL _adjustFontSize;
    float _minimumFontSize;
    float _originalFontSize;
    int _numberOfLines;
    BOOL _isDisabled;
    BOOL _isHighlighted;
    UIBaselineAdjustment _baselineAdjustment;
}
- (void)adjustFontSizeToFit {
    if (_numberOfLines != 1) {
        [self adjustTextLayerSize];
        return;
    }

    float curFontSize = _originalFontSize;
    _font = [_font fontWithSize:curFontSize];

    CGRect rect;
    rect = [self bounds];
    if (rect.size.width == 0.0f || rect.size.height == 0.0f)
        return;

    while (curFontSize > _minimumFontSize) {
        CGSize size;

        size = rect.size;
        size = [_text sizeWithFont:_font
                 constrainedToSize:CGSizeMake(rect.size.width, 0.0f)
                     lineBreakMode:UILineBreakModeClip];

        if (size.width <= rect.size.width && size.height <= rect.size.height) {
            break;
        }

        curFontSize -= 1.0f;
        _font = [_font fontWithSize:curFontSize];
    }

    if (curFontSize < _minimumFontSize) {
        curFontSize = _minimumFontSize;
    }

    _font = [_font fontWithSize:curFontSize];

    [self adjustTextLayerSize];
}

- (void)adjustTextLayerSize {
#if USE_TEXT_LAYER
    if ([self class] != [UILabel class]) {
        [[self layer] setShouldRasterize:TRUE];
    }
    UIColor* color = _textColor;
    if (_isHighlighted && _highlightedTextColor != nil)
        color = _highlightedTextColor;
    [[self layer] _setDisplayParams:(id)
                              _font:(id)
                              _text:
                              color:
                         _alignment:
                     _lineBreakMode:(id)
                       _shadowColor:
                      _shadowOffset:_numberOfLines];
#endif
    [self setNeedsDisplay];
}

#if USE_TEXT_LAYER
+ (id)layerClass {
    return [CATextLayer class];
}
#endif

- (id)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];

    _text = [coder decodeObjectForKey:@"UIText"];
    _textColor = [coder decodeObjectForKey:@"UITextColor"];
    _highlightedTextColor = [coder decodeObjectForKey:@"UIHighlightedColor"];
    _shadowColor = [coder decodeObjectForKey:@"UIShadowColor"];

    UIFont* font = [coder decodeObjectForKey:@"UIFont"];
    if (font == nil) {
        font = [UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]];
    }
    [self setFont:font];

    _alignment = (UITextAlignment)[coder decodeInt32ForKey:@"UITextAlignment"];
    _adjustFontSize = [coder decodeInt32ForKey:@"UIAdjustsFontSizeToFit"];

    if ([coder containsValueForKey:@"UINumberOfLines"]) {
        _numberOfLines = [coder decodeInt32ForKey:@"UINumberOfLines"];
    } else {
        _numberOfLines = 1;
    }

    _minimumFontSize = [coder decodeFloatForKey:@"UIMinimumFontSize"];

    if ([coder containsValueForKey:@"UILineBreakMode"]) {
        _lineBreakMode = (UILineBreakMode)[coder decodeInt32ForKey:@"UILineBreakMode"];
    } else {
        _lineBreakMode = UILineBreakModeTailTruncation;
    }
    if ([coder containsValueForKey:@"UIShadowOffset"]) {
        id obj = [coder decodeObjectForKey:@"UIShadowOffset"];
        CGSize size = { 0 };
        if ([obj isKindOfClass:[NSString class]]) {
            const char* str = (const char*)([obj UTF8String]);
            sscanf_s(str, "{%f, %f}", &_shadowOffset.width, &_shadowOffset.height);
        } else {
            CGSize* pSize = (CGSize*)((char*)[obj bytes] + 1);
            memcpy(&_shadowOffset, pSize, sizeof(CGSize));
        }
    }

    if (_adjustFontSize) {
        [self adjustFontSizeToFit];
    } else {
        [self adjustTextLayerSize];
    }

    return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
    [super initWithFrame:frame];

    _alignment = UITextAlignmentLeft;
    _lineBreakMode = UILineBreakModeTailTruncation;
    [self setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]]];
    _textColor = [UIColor blackColor];
    [self setBackgroundColor:[UIColor whiteColor]];
    _shadowColor = _textColor;
    _minimumFontSize = 8.0f;
    _numberOfLines = 1;
    [self setOpaque:FALSE];

    [self setUserInteractionEnabled:FALSE];
    [self setContentMode:UIViewContentModeRedraw];

    [self adjustTextLayerSize];

    return self;
}

- (void)setFont:(UIFont*)font {
    if (![_font isEqual:font]) {
        _font = font;
        _originalFontSize = [_font pointSize];

        if (_adjustFontSize) {
            [self adjustFontSizeToFit];
        } else {
            [self adjustTextLayerSize];
        }
    }
}

- (UIFont*)font {
    if (_font == nil) {
        _font = [UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]];
    }
    return _font;
}

- (void)setText:(NSString*)newStr {
    if (![newStr isKindOfClass:[NSString class]]) {
        newStr = [newStr description];
    }
    if (newStr == nil || ![_text isEqual:newStr]) {
        _text.attach([newStr copy]);
        if (_adjustFontSize) {
            [self adjustFontSizeToFit];
        } else {
            [self adjustTextLayerSize];
        }
    }
}

- (void)setAttributedText:(NSAttributedString*)newStr {
    _attributedText.attach([newStr copy]);
    [self setText:[_attributedText string]];
}

- (NSAttributedString*)attributedText {
    return _attributedText;
}

- (void)setEnabled:(BOOL)enable {
    _isDisabled = !enable;
}

- (BOOL)isEnabled {
    return _isDisabled;
}

- (NSString*)text {
    return _text;
}

- (void)setTextAlignment:(UITextAlignment)alignment {
    if (alignment != _alignment) {
        _alignment = alignment;
        [self adjustTextLayerSize];
    }
}

- (UITextAlignment)textAlignment {
    return _alignment;
}

- (void)setTextColor:(UIColor*)color {
    if (![_textColor isEqual:color]) {
        _textColor = color;
        [self adjustTextLayerSize];
    }
}

- (UIColor*)textColor {
    return _textColor;
}

- (void)setShadowColor:(UIColor*)colorref {
    _shadowColor = colorref;
}

- (UIColor*)shadowColor {
    return _shadowColor;
}

- (void)setShadowOffset:(CGSize)offset {
    _shadowOffset = offset;
}

- (CGSize)shadowOffset {
    return _shadowOffset;
}

- (void)setBackgroundColor:(UIColor*)colorref {
    if (_textLayer != nil)
        [_textLayer setBackgroundColor:(CGColorRef)colorref];
    if (!_isHighlighted)
        _savedBackgroundColor = colorref;
    [super setBackgroundColor:colorref];
}

- (void)setNumberOfLines:(NSInteger)numberOfLines {
    _numberOfLines = numberOfLines;
}

- (NSInteger)numberOfLines {
    return _numberOfLines;
}

- (void)setMinimumFontSize:(float)size {
    _minimumFontSize = size;
}

- (float)minimumFontSize {
    return _minimumFontSize;
}

- (void)setBaselineAdjustment:(UIBaselineAdjustment)adjustment {
    _baselineAdjustment = adjustment;
}

- (UIBaselineAdjustment)baselineAdjustment {
    return _baselineAdjustment;
}

- (void)setLineBreakMode:(UILineBreakMode)mode {
    _lineBreakMode = mode;
    [self adjustTextLayerSize];
}

- (UILineBreakMode)lineBreakMode {
    return _lineBreakMode;
}

- (void)setHighlighted:(BOOL)highlighted {
    _isHighlighted = highlighted;
    if (highlighted) {
        [self setBackgroundColor:nil];
    } else {
        [self setBackgroundColor:_savedBackgroundColor];
    }
    [self adjustTextLayerSize];
}

- (BOOL)isHighlighted {
    return _isHighlighted;
}

- (void)setHighlightedTextColor:(UIColor*)color {
    _highlightedTextColor = color;
}

- (UIColor*)highlightedTextColor {
    return _highlightedTextColor;
}

- (void)drawRect:(CGRect)rect {
    CGRect bounds = self.bounds;
    CGRect drawArea = CGRectMake(0, 0, bounds.size.width, bounds.size.height);
    [self drawTextInRect:drawArea];
}

- (void)drawTextInRect:(CGRect)rect {
    if (_text != nil) {
        if (_font == nil) {
            [self setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]]];
        }

        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), [_textColor CGColor]);

        CGSize size = rect.size;
        if (_numberOfLines == 1) {
            CGSize fontHeight;

            fontHeight = [@" " sizeWithFont:_font];
            size.height = fontHeight.height;
        }
        size = [_text sizeWithFont:_font
                 constrainedToSize:CGSizeMake(size.width, size.height)
                     lineBreakMode:_lineBreakMode];

        EbrCenterTextInRectVertically(&rect, &size, _font);

        if ((_shadowOffset.width != 0.0f || _shadowOffset.height != 0.0f) && _shadowColor != nil) {
            CGRect shadowRect = rect;

            switch (_alignment) {
                case UITextAlignmentLeft:
                    shadowRect.origin.x += _shadowOffset.width;
                    shadowRect.origin.y += _shadowOffset.height;
                    break;

                case UITextAlignmentCenter:
                    shadowRect.origin.x += _shadowOffset.width;
                    shadowRect.origin.y += _shadowOffset.height;
                    break;

                case UITextAlignmentRight:
                    rect.origin.x -= _shadowOffset.width;
                    shadowRect.origin.y += _shadowOffset.height;
                    break;
            }

            CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), [_shadowColor CGColor]);
            size = [_text drawInRect:shadowRect withFont:_font lineBreakMode:_lineBreakMode alignment:_alignment];
        }

        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), [_textColor CGColor]);
        size = [_text drawInRect:rect withFont:_font lineBreakMode:_lineBreakMode alignment:_alignment];
    }
}

- (void)setAdjustsFontSizeToFitWidth:(BOOL)adjusts {
    _adjustFontSize = adjusts;

    if (_adjustFontSize) {
        [self adjustFontSizeToFit];
    }
}

- (void)setMinimumScaleFactor:(float)scale {
}

- (BOOL)adjustsFontSizeToFitWidth {
    return _adjustFontSize;
}

- (CGSize)sizeThatFits:(CGSize)curSize {
    CGSize ret = { 0 };

    if (_text != nil) {
        if (_font == nil) {
            [self setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]]];
        }

        ret = [_text sizeWithFont:_font
                constrainedToSize:CGSizeMake(curSize.width, curSize.height)
                    lineBreakMode:_lineBreakMode];

        if (_numberOfLines == 1) {
            CGSize fontHeight;

            fontHeight = [@" " sizeWithFont:_font];
            ret.height = fontHeight.height;
        }
    }

    return ret;
}

- (CGRect)textRectForBounds:(CGRect)bounds limitedToNumberOfLines:(NSInteger)maxLines {
    CGRect ret = { 0 };

    if (_text != nil) {
        CGSize size;

        if (_font == nil) {
            _font = [UIFont defaultFont];
        }

        size = [_text sizeWithFont:_font
                 constrainedToSize:CGSizeMake(GetCACompositor()->screenWidth(), bounds.size.height)
                     lineBreakMode:_lineBreakMode];
        size.height -= [_font descender];

        ret.origin = bounds.origin;
        ret.size = size;
    }

    return ret;
}

- (void)sizeToFit {
    CGRect idealSize;

    idealSize = [self frame];

    if (idealSize.size.width == 0.0f) {
        idealSize.size.width = GetCACompositor()->screenWidth();
        idealSize.size = [self sizeThatFits:idealSize.size];
    } else {
        idealSize.size = [self sizeThatFits:idealSize.size];

        CGRect superSize = CGRectMake(0.0f, 0.0f, GetCACompositor()->screenWidth(), GetCACompositor()->screenHeight());
        UIView* superview = [self superview];

        if (superview != nil)
            superSize = [superview bounds];

        if (idealSize.size.width > superSize.size.width && superSize.size.width > 0.0f) {
            idealSize.size.width = superSize.size.width;
        }
        if (idealSize.size.height > superSize.size.height && superSize.size.height > 0.0f) {
            idealSize.size.height = superSize.size.height;
        }
    }

    [self setFrame:idealSize];
}

- (void)dealloc {
    _text = nil;
    _font = nil;
    _textColor = nil;
    _shadowColor = nil;
    _highlightedTextColor = nil;
    _textLayer = nil;
    _savedBackgroundColor = nil;
    _attributedText = nil;

    [super dealloc];
}

- (void)layoutSubviews {
    if (_adjustFontSize) {
        [self adjustFontSizeToFit];
    } else {
        [self adjustTextLayerSize];
    }
    [self setNeedsDisplay];
}

- (CGSize)intrinsicContentSize {
    CGSize ret;

    if (_text != nil) {
        if (_font == nil) {
            [self setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]]];
        }

        ret = [_text sizeWithFont:_font];

        if (_numberOfLines == 1) {
            CGSize fontHeight;

            fontHeight = [@" " sizeWithFont:_font];
            ret.height = fontHeight.height;
        }
    } else {
        CGSize fontHeight;
        fontHeight = [@" " sizeWithFont:_font];
        ret.width = UIViewNoIntrinsicMetric;
        ret.height = fontHeight.height;
    }

    return ret;
}

#if USE_TEXT_LAYER
#endif

@end
