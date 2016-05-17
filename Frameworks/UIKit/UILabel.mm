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

#import "Starboard.h"
#import "Foundation/NSString.h"
#import "CoreGraphics/CGContext.h"
#import "UIKit/UIView.h"
#import "UIKit/UIFont.h"
#import "UIKit/UIColor.h"
#import "UIKit/UILabel.h"
#import "UIKit/UIAccessibility.h"
#import "UIFontInternal.h"
#import "CGContextInternal.h"
#import "CATextLayerInternal.h"
#import "QuartzCore/CATextLayer.h"

#import "CACompositor.h"

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
    if (_numberOfLines == 0) {
        [self adjustTextLayerSize];
        return;
    }

    float curFontSize = _originalFontSize;
    _font = [_font fontWithSize:curFontSize];

    CGRect rect;
    rect = [self bounds];
    if (rect.size.width == 0.0f || rect.size.height == 0.0f) {
        return;
    }

    while (curFontSize > _minimumFontSize && curFontSize > 0.0f) {
        CGSize size = CGSizeZero;

        //  A single line of text should be clipped
        if (_numberOfLines == 1) {
            size = [_text sizeWithFont:_font constrainedToSize:CGSizeMake(rect.size.width, 0.0f) lineBreakMode:UILineBreakModeClip];
        } else {
            //  Multiple lines of text should be wrapped
            size = [_text sizeWithFont:_font constrainedToSize:CGSizeMake(rect.size.width, 0.0f) lineBreakMode:UILineBreakModeWordWrap];
        }

        if (size.width < rect.size.width && size.height <= rect.size.height) {
            break;
        }

        curFontSize -= 1.0f;
        _font = [_font fontWithSize:curFontSize];
    }

    if (curFontSize < _minimumFontSize) {
        curFontSize = _minimumFontSize;
    }
    if (curFontSize < 0.0f) {
        curFontSize = 1.0f;
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
    if (_isHighlighted && _highlightedTextColor != nil) {
        color = _highlightedTextColor;
    }
    [static_cast<CATextLayer*>([self layer]) _setDisplayParams:(id)_font
                                                          text:(id)_text
                                                         color:color
                                                     alignment:_alignment
                                                     lineBreak:_lineBreakMode
                                                   shadowColor:(id)_shadowColor
                                                  shadowOffset:_shadowOffset
                                                      numLines:_numberOfLines];
#endif
    [self invalidateIntrinsicContentSize];
    [self setNeedsDisplay];
}

#if USE_TEXT_LAYER
/**
 @Status Interoperable
*/
+ (Class)layerClass {
    return [CATextLayer class];
}
#endif

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
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

/**
 @Status Interoperable
*/
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

/**
 @Public No
*/
- (void)initAccessibility {
    [super initAccessibility];
    self.accessibilityTraits = UIAccessibilityTraitStaticText;
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (UIFont*)font {
    if (_font == nil) {
        _font = [UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]];
    }
    return _font;
}

/**
 @Status Interoperable
*/
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

        self.accessibilityValue = newStr;
    }
}

/**
 @Status Stub
*/
- (void)setAttributedText:(NSAttributedString*)newStr {
    UNIMPLEMENTED();
    _attributedText.attach([newStr copy]);
    [self setText:[_attributedText string]];
}

/**
 @Status Stub
*/
- (NSAttributedString*)attributedText {
    UNIMPLEMENTED();
    return _attributedText;
}

/**
 @Status Interoperable
*/
- (void)setEnabled:(BOOL)enable {
    _isDisabled = !enable;
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    return _isDisabled;
}

/**
 @Status Interoperable
*/
- (NSString*)text {
    return _text;
}

/**
 @Status Interoperable
*/
- (void)setTextAlignment:(UITextAlignment)alignment {
    if (alignment != _alignment) {
        _alignment = alignment;
        [self adjustTextLayerSize];
    }
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
- (void)setTextColor:(UIColor*)color {
    if (![_textColor isEqual:color]) {
        [[_textColor retain] autorelease];
        _textColor = color;
        [self adjustTextLayerSize];
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
- (void)setShadowColor:(UIColor*)colorref {
    _shadowColor = colorref;
}

/**
 @Status Interoperable
*/
- (UIColor*)shadowColor {
    return _shadowColor;
}

/**
 @Status Interoperable
*/
- (void)setShadowOffset:(CGSize)offset {
    _shadowOffset = offset;
}

/**
 @Status Interoperable
*/
- (CGSize)shadowOffset {
    return _shadowOffset;
}

/**
 @Status Interoperable
*/
- (void)setBackgroundColor:(UIColor*)colorref {
    if (_textLayer != nil) {
        [_textLayer setBackgroundColor:(CGColorRef)colorref];
    }
    if (!_isHighlighted) {
        _savedBackgroundColor = colorref;
    }
    [super setBackgroundColor:colorref];
}

/**
 @Status Interoperable
*/
- (void)setNumberOfLines:(NSInteger)numberOfLines {
    _numberOfLines = numberOfLines;
}

/**
 @Status Interoperable
*/
- (NSInteger)numberOfLines {
    return _numberOfLines;
}

/**
 @Status Interoperable
*/
- (void)setMinimumFontSize:(float)size {
    _minimumFontSize = size;
}

/**
 @Status Interoperable
*/
- (float)minimumFontSize {
    return _minimumFontSize;
}

/**
 @Status Stub
*/
- (void)setBaselineAdjustment:(UIBaselineAdjustment)adjustment {
    UNIMPLEMENTED();
    _baselineAdjustment = adjustment;
}

/**
 @Status Stub
*/
- (UIBaselineAdjustment)baselineAdjustment {
    UNIMPLEMENTED();
    return _baselineAdjustment;
}

/**
 @Status Interoperable
*/
- (void)setLineBreakMode:(UILineBreakMode)mode {
    _lineBreakMode = mode;
    [self adjustTextLayerSize];
}

/**
 @Status Interoperable
*/
- (UILineBreakMode)lineBreakMode {
    return _lineBreakMode;
}

/**
 @Status Interoperable
*/
- (void)setHighlighted:(BOOL)highlighted {
    _isHighlighted = highlighted;
    if (highlighted) {
        [self setBackgroundColor:nil];
    } else {
        [self setBackgroundColor:_savedBackgroundColor];
    }
    [self adjustTextLayerSize];
}

/**
 @Status Interoperable
*/
- (BOOL)isHighlighted {
    return _isHighlighted;
}

/**
 @Status Interoperable
*/
- (void)setHighlightedTextColor:(UIColor*)color {
    _highlightedTextColor = color;
}

/**
 @Status Interoperable
*/
- (UIColor*)highlightedTextColor {
    return _highlightedTextColor;
}

/**
 @Status Interoperable
*/
- (void)drawRect:(CGRect)rect {
    CGRect bounds = self.bounds;
    CGRect drawArea = CGRectMake(0, 0, bounds.size.width, bounds.size.height);
    [self drawTextInRect:drawArea];
}

/**
 @Status Interoperable
*/
- (void)drawTextInRect:(CGRect)rect {
    if (_text != nil) {
        if (_font == nil) {
            [self setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]]];
        }

        CGContextRef currentCtx = UIGraphicsGetCurrentContext();

        CGContextSetFillColorWithColor(currentCtx, [_textColor CGColor]);
        CGContextSetStrokeColorWithColor(currentCtx, [_textColor CGColor]);

        CGSize size = rect.size;
        if (_numberOfLines == 1) {
            CGSize fontHeight;

            fontHeight = [@" " sizeWithFont:_font];
            size.height = fontHeight.height;
        }

        size = [_text sizeWithFont:_font constrainedToSize:CGSizeMake(size.width, size.height) lineBreakMode:_lineBreakMode];

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

            CGContextSetFillColorWithColor(currentCtx, [_shadowColor CGColor]);
            CGContextSetStrokeColorWithColor(currentCtx, [_shadowColor CGColor]);
            size = [_text drawInRect:shadowRect withFont:_font lineBreakMode:_lineBreakMode alignment:_alignment];
        }

        CGContextSetFillColorWithColor(currentCtx, [_textColor CGColor]);
        CGContextSetStrokeColorWithColor(currentCtx, [_textColor CGColor]);
        size = [_text drawInRect:rect withFont:_font lineBreakMode:_lineBreakMode alignment:_alignment];
    }
}

/**
 @Status Interoperable
*/
- (void)setAdjustsFontSizeToFitWidth:(BOOL)adjusts {
    _adjustFontSize = adjusts;

    if (_adjustFontSize) {
        [self adjustFontSizeToFit];
    }
}

/**
 @Status Stub
*/
- (void)setMinimumScaleFactor:(float)scale {
}

/**
 @Status Interoperable
*/
- (BOOL)adjustsFontSizeToFitWidth {
    return _adjustFontSize;
}

/**
 @Status Interoperable
*/
- (CGSize)sizeThatFits:(CGSize)curSize {
    CGSize ret = { 0 };

    if (_text != nil) {
        UIFont* measurementFont = nil;
        if (_font == nil) {
            [self setFont:[UIFont fontWithName:@"Helvetica" size:[UIFont labelFontSize]]];
        }

        //  Grab the font at the original point size set in setFont:
        measurementFont = [_font fontWithSize:_originalFontSize];

        //  Measure the height of a single line of text of this font
        CGSize fontHeight = [@" " sizeWithFont:measurementFont];

        //  If we have to fit everything on one line, or if the current width
        //  is incalculable (we can't wrap to a width of 0), set the
        //  fit width to inifinite
        if (curSize.width == 0 || self.numberOfLines == 1) {
            curSize.width = FLT_MAX;
        }

        if ((self.numberOfLines == 0) || (self.numberOfLines == 1)) {
            curSize.height = FLT_MAX;
        } else {
            curSize.height = fontHeight.height * self.numberOfLines;
        }

        //  Calculate the size of the text set in our label
        ret = [_text sizeWithFont:measurementFont
                constrainedToSize:CGSizeMake(curSize.width, curSize.height)
                    lineBreakMode:self.lineBreakMode];

        //  The returned height to 1 line if the number of lines is 1
        if (self.numberOfLines == 1) {
            ret.height = fontHeight.height;
        }
    }

    return ret;
}

/**
 @Status Caveat
 @Notes limitedToNumberOfLines parameter not supported
*/
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

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (void)layoutSubviews {
    if (_adjustFontSize) {
        [self adjustFontSizeToFit];
    } else {
        [self adjustTextLayerSize];
    }
    [self setNeedsDisplay];
}

/**
 @Status Interoperable
*/
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
