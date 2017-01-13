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

#import <UIKit/NSString+UIKitAdditions.h>
#import <UIKit/UIAccessibility.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIFont.h>
#import <UIKit/UILabel.h>
#import <UIKit/UIView.h>

#import <CoreGraphics/CGContext.h>

#import <Foundation/NSString.h>

#import "UIFontInternal.h"
#import "CGContextInternal.h"
#import "StarboardXaml/DisplayProperties.h"
#import "XamlControls.h"
#import "XamlUtilities.h"

@implementation UILabel {
    idretaintype(NSString) _text;
    idretaintype(UIFont) _font;
    idretaintype(UIColor) _textColor, _shadowColor, _highlightedTextColor;
    idretaintype(NSAttributedString) _attributedText;
    idretaintype(UIColor) _savedBackgroundColor;
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
    StrongId<WXCTextBlock> _textBlock;
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
    [_textBlock setText:_text];
    [_textBlock setFontSize:[_font pointSize]];

    StrongId<WUTFontWeight> fontWeight;
    fontWeight.attach([WUTFontWeight new]);
    fontWeight.get().weight = static_cast<unsigned short>([_font _fontWeight]);
    [_textBlock setFontWeight:fontWeight];
    [_textBlock setFontStyle:static_cast<WUTFontStyle>([_font _fontStyle])];
    [_textBlock setFontStretch:static_cast<WUTFontStretch>([_font _fontStretch])];

    [_textBlock setFontFamily:[WUXMFontFamily makeInstanceWithName:[_font _compatibleFamilyName]]];

    [_textBlock setTextAlignment:ConvertUITextAlignmentToWXTextAlignment(_alignment)];

    [_textBlock setLineHeight:[_font ascender] - [_font descender]];

    ApplyLineBreakModeOnTextBlock(_textBlock, _lineBreakMode, self.numberOfLines);
    [_textBlock setLineStackingStrategy:WXLineStackingStrategyBlockLineHeight];

    UIColor* color = _textColor;
    if (_isHighlighted && _highlightedTextColor != nil) {
        color = _highlightedTextColor;
    }
    [_textBlock setForeground:[WUXMSolidColorBrush makeInstanceWithColor:ConvertUIColorToWUColor(color)]];

    [self invalidateIntrinsicContentSize];
    [self setNeedsDisplay];
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _initUILabel];

        _text = [coder decodeObjectForKey:@"UIText"];
        _textColor = [coder decodeObjectForKey:@"UITextColor"];
        _highlightedTextColor = [coder decodeObjectForKey:@"UIHighlightedColor"];
        _shadowColor = [coder decodeObjectForKey:@"UIShadowColor"];

        UIFont* font = [coder decodeObjectForKey:@"UIFont"];
        if (font == nil) {
            font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];
        }
        _font = font;

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
    }

    return self;
}

- (void)_initUILabel {
    ////////////////////////////////////////////////////////////////////
    // TODO: Ultimately this will be a UIKit.Label projected to us and
    // it will expose its backing TextBlock.  For now, we'll have to
    // know that it's truly backed by a Grid and we must reach down
    // to retrieve its TextBlock.
    WXCGrid* labelGrid = rt_dynamic_cast<WXCGrid>([self xamlElement]);
    WXCTextBlock* textBlock = nil;
    if (labelGrid) {
        textBlock = XamlControls::GetLabelTextBlock(labelGrid);
    } else {
        // If we didn't get a UIKit.Label, that's ok - as long as
        // we've received a TextBlock directly.
        textBlock = rt_dynamic_cast<WXCTextBlock>([self xamlElement]);
    }

    if (!textBlock) {
        // Definitely didn't receive any supported backing xaml elements
        FAIL_FAST();
    }

    _textBlock = textBlock;

    _alignment = UITextAlignmentLeft;
    _lineBreakMode = UILineBreakModeTailTruncation;
    _textColor = [UIColor blackColor];
    _shadowColor = _textColor;
    _minimumFontSize = 8.0f;
    _numberOfLines = 1;
    [self setOpaque:FALSE];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _initUILabel];

        // TODO: Reevaluate whether or not this is the correct default mode for UILabels that are initialized via initWithFrame.
        //       Some of our test apps expect the initWithCoder path to default to UIViewContentModeScaleToFill (aka kCAGravityResize).
        [self setContentMode:UIViewContentModeRedraw];

        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];

        [self adjustTextLayerSize];
    }

    return self;
}

/**
 Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(WXFrameworkElement*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        [self _initUILabel];

        // TODO: Reevaluate whether or not this is the correct default mode for UILabels that are initialized via initWithFrame.
        //       Some of our test apps expect the initWithCoder path to default to UIViewContentModeScaleToFill (aka kCAGravityResize).
        [self setContentMode:UIViewContentModeRedraw];

        _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];

        [self adjustTextLayerSize];
    }

    return self;
}

/**
 Microsoft Extension
*/
+ (WXFrameworkElement*)createXamlElement {
    // No autorelease needed because CreateLabel is autoreleased
    return XamlControls::CreateLabel();
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
    return _font;
}

/**
 @Status Interoperable
*/
- (void)setText:(NSString*)newStr {
    if (newStr == nil && _text == nil) {
        return;
    }
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
    if (color == nil && _textColor == nil) {
        return;
    }
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
@Status Stub
*/
- (void)drawTextInRect:(CGRect)rect {
    UNIMPLEMENTED();
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
        //  Grab the font at the original point size set in setFont:
        UIFont* measurementFont = [_font fontWithSize:_originalFontSize];

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
                 constrainedToSize:CGSizeMake(DisplayProperties::ScreenWidth(), bounds.size.height)
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

@end
