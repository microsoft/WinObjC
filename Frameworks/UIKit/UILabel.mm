//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#import "AssertARCEnabled.h"
#import "Starboard.h"
#import <StubReturn.h>

#import <UIKit/NSString+UIKitAdditions.h>
#import <UIKit/UIAccessibility.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIFont.h>
#import <UIKit/UILabel.h>
#import <UIKit/UIView.h>

#import <CoreGraphics/CGContext.h>

#import <Foundation/NSString.h>

#import "UIViewInternal.h"
#import "UIFontInternal.h"
#import "UILabelInternal.h"
#import "CGContextInternal.h"
#import "StarboardXaml/DisplayProperties.h"
#import "XamlControls.h"
#import "XamlUtilities.h"
#import "CppWinRTHelpers.h"

using namespace winrt::Windows::UI::Xaml;

static const wchar_t* TAG = L"UILabel";

@implementation UILabel {
    idretaintype(NSString) _text;
    idretaintype(UIFont) _font;
    idretaintype(UIColor) _textColor;
    idretaintype(UIColor) _highlightedTextColor;
    idretaintype(UIColor) _savedBackgroundColor;
    UITextAlignment _alignment;
    UILineBreakMode _lineBreakMode;
    BOOL _adjustFontSize;
    float _minimumFontSize;
    BOOL _useMinimumScaleFactor;
    float _minimumScaleFactor;
    int _numberOfLines;
    BOOL _isHighlighted;
    TrivialDefaultConstructor<Controls::TextBlock> _textBlock;
}

- (float)_searchAdjustedFontSizeToFit {
    CGRect rect = [self bounds];

    if (rect.size.width == 0.0f || rect.size.height == 0.0f || [_text length] == 0) {
        return -1.0f;
    }

    // Special:on reference platform, adjustFontSizeToFit is no-op when lineBreakMode is Wrapping
    if (_lineBreakMode != UILineBreakModeWordWrap && _lineBreakMode != UILineBreakModeCharacterWrap) {
        float minimumFontSize = _minimumFontSize;

        // if minimumScaleFactor is used, it should override _minimumFontSize which is deprecated
        if (_useMinimumScaleFactor) {
            if (_minimumScaleFactor > 0.0) {
                minimumFontSize = _minimumScaleFactor * [_font pointSize];
            } else {
                // per reference platform, if minimumScaleFactor is set and equal to 0.0
                // use current font size is used as smallest font size
                minimumFontSize = [_font pointSize];
            }
        }

        // findMaxFontSizeToFit return maximnum Font Size which should not exceed
        // original fontSize, thus never scale up. use original font size as upper bound
        // if not found, return minimumFontSize
        return XamlUtilities::FindMaxFontSizeToFit(rect, _text, _font, _numberOfLines, minimumFontSize, [_font pointSize]);
    }

    return -1.0f;
}

- (void)_updateTextBlockWithFont:(UIFont*)font {
    _textBlock.FontSize([font pointSize]);
    _textBlock.LineHeight([font ascender] - [font descender]);

    winrt::Windows::UI::Text::FontWeight fontWeight;
    fontWeight.Weight = static_cast<unsigned short>([font _fontWeight]);
    _textBlock.FontWeight(fontWeight);
    _textBlock.FontStyle(static_cast<winrt::Windows::UI::Text::FontStyle>([font _fontStyle]));
    _textBlock.FontStretch(static_cast<winrt::Windows::UI::Text::FontStretch>([font _fontStretch]));
    _textBlock.FontFamily(Media::FontFamily(objcwinrt::string([font _compatibleFamilyName])));
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

        UIFont* font = [coder decodeObjectForKey:@"UIFont"];
        if (font != nil) {
            _font = font;
        }

        _alignment = (UITextAlignment)[coder decodeInt32ForKey:@"UITextAlignment"];

        if ([coder containsValueForKey:@"UINumberOfLines"]) {
            _numberOfLines = [coder decodeInt32ForKey:@"UINumberOfLines"];
        } else {
            _numberOfLines = 1;
        }

        // one of UIMinimumScaleFactor or UIMinimumFontSize or UIAdjustsFontSizeToFit has to be set
        // if UIAdjustsFontSizeToFit is set, it must be NO.
        // if UIMinimumScaleFactor or UIMinimumFontSize is set, UIAdjustsFontSizeToFit is dereived to be YES
        if ([coder containsValueForKey:@"UIMinimumScaleFactor"]) {
            _minimumScaleFactor = [coder decodeFloatForKey:@"UIMinimumScaleFactor"];
            _useMinimumScaleFactor = YES;
            _adjustFontSize = YES;
        } else if ([coder containsValueForKey:@"UIMinimumFontSize"]) {
            _minimumFontSize = [coder decodeFloatForKey:@"UIMinimumFontSize"];
            _adjustFontSize = YES;
        } else if ([coder containsValueForKey:@"UIAdjustsFontSizeToFit"]) {
            _adjustFontSize = [coder decodeInt32ForKey:@"UIAdjustsFontSizeToFit"];
            if (_adjustFontSize) {
                TraceWarning(TAG,
                             L"Invalid nib format, UIAdjustsFontSizeToFit should be set to FALSE if it is set, currently set as TRUE, "
                             L"overwritting with FALSE");
                _adjustFontSize = NO;
            }
        } else {
            TraceWarning(TAG,
                         L"Invalid nib format, None of UIMinimumScaleFactor/UIMinimumFontSize/UIAdjustsFontSizeToFit is set. Setting "
                         L"UIAdjustsFontSizeToFit to FALSE");
            _adjustFontSize = NO;
        }

        if ([coder containsValueForKey:@"UILineBreakMode"]) {
            _lineBreakMode = (UILineBreakMode)[coder decodeInt32ForKey:@"UILineBreakMode"];
        } else {
            _lineBreakMode = UILineBreakModeTailTruncation;
        }

        [self _applyPropertiesOnTextBlock];
    }

    return self;
}

// Returns access to the underlying TextBlock within the UILabel's Xaml representation
// Note: This is used for UX testing and won't be necessary when we are projecting
// UIKit.Label into ObjectiveC, as at that point we can just expose the TextBlock directly
// off of our UIKit.Label implementation.
- (Controls::TextBlock)_getXamlTextBlock {
    return _textBlock;
}

- (void)_initUILabel {
    ////////////////////////////////////////////////////////////////////
    // TODO: Ultimately this will be a UIKit.Label projected to us and
    // it will expose its backing TextBlock.  For now, we'll have to
    // know that it's truly backed by a Grid and we must reach down
    // to retrieve its TextBlock.
    auto labelGrid = [self _winrtXamlElement].try_as<Controls::Grid>();
    Controls::TextBlock textBlock = nullptr;
    if (labelGrid) {
        textBlock = XamlControls::GetLabelTextBlock(labelGrid);
    } else {
        // If we didn't get a UIKit.Label, that's ok - as long as
        // we've received a TextBlock directly.
        textBlock = [self _winrtXamlElement].as<Controls::TextBlock>();
    }

    if (!textBlock) {
        // Definitely didn't receive any supported backing xaml elements
        FAIL_FAST();
    }

    _textBlock = textBlock;
    _alignment = UITextAlignmentLeft;
    _lineBreakMode = UILineBreakModeTailTruncation;
    _textColor = [UIColor blackColor];

    // on reference platform, default minimum font size is zero but always slightly bigger than zero in reality acccording to the
    // documentation
    _adjustFontSize = NO;
    _minimumFontSize = 0.0001f;
    _minimumScaleFactor = 0.0;
    _useMinimumScaleFactor = NO;
    _numberOfLines = 1;
    [self setOpaque:FALSE];

    _font = [UIFont fontWithName:@"Segoe UI" size:[UIFont labelFontSize]];

    // TODO: Reevaluate whether or not this is the correct default mode for UILabels that are initialized via initWithFrame.
    //       Some of our test apps expect the initWithCoder path to default to UIViewContentModeScaleToFill (aka kCAGravityResize).
    [self setContentMode:UIViewContentModeRedraw];
}

- (void)_applyPropertiesOnTextBlock {
    _textBlock.Text(objcwinrt::string(_text));
    _textBlock.TextAlignment(XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(_alignment));
    XamlUtilities::ApplyLineBreakModeOnTextBlock(_textBlock, _lineBreakMode, self.numberOfLines);
    _textBlock.MaxLines(_numberOfLines);
    UIColor* color = _textColor;
    if (_isHighlighted && _highlightedTextColor != nil) {
        color = _highlightedTextColor;
    }
    _textBlock.Foreground(Media::SolidColorBrush(XamlUtilities::ConvertUIColorToWUColor(color)));
    [self _updateTextBlockWithFont:_font];

    if (_adjustFontSize) {
        // search for font that can fit - but it might not exist, in which case it return -1.0f
        float adjustedFontSize = [self _searchAdjustedFontSizeToFit];
        if (adjustedFontSize != -1.0f && adjustedFontSize != [_font pointSize]) {
            _textBlock.FontSize(adjustedFontSize);
            UIFont* adjustFont = [_font fontWithSize:adjustedFontSize];

            // when updating font size, also need update lineheight
            _textBlock.LineHeight([adjustFont ascender] - [adjustFont descender]);
        }
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _initUILabel];
        [self _applyPropertiesOnTextBlock];
    }

    return self;
}

/**
 Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(RTObject*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        [self _initUILabel];
        [self _applyPropertiesOnTextBlock];
    }

    return self;
}

/**
 Microsoft Extension
*/
+ (RTObject*)createXamlElement {
    return objcwinrt::to_rtobj(XamlControls::CreateLabel());
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
    if (_font == nil && font == nil) {
        return;
    }

    if (![_font isEqual:font]) {
        _font = font;
        [self _updateTextBlockWithFont:_font];
        if (![self _adjustTextBlockFontSizeIfNecessary]) {
            [self invalidateIntrinsicContentSize];
            [self setNeedsDisplay];
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
        _text = [newStr copy];
        _textBlock.Text(objcwinrt::string(_text));

        self.accessibilityValue = newStr;
        [self _adjustTextBlockFontSizeIfNecessary];
    }
}

/**
  @Status NotInPlan
  @Notes Attributed text is not easily supported by Xaml.
*/
- (void)setAttributedText:(NSAttributedString*)newStr {
    UNIMPLEMENTED_WITH_MSG("Attributed text is not easily supported by Xaml.");
}

/**
  @Status NotInPlan
  @Notes Attributed text is not easily supported by Xaml.
*/
- (NSAttributedString*)attributedText {
    UNIMPLEMENTED_WITH_MSG("Attributed text is not easily supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes this isn't a property that XAML has available for TextBlock
*/
- (void)setEnabled:(BOOL)enable {
    UNIMPLEMENTED_WITH_MSG("enabled is not a property that XAML has available for TextBlock");
}

/**
 @Status NotInPlan
 @Notes this isn't a property that XAML has available for TextBlock
*/
- (BOOL)isEnabled {
    UNIMPLEMENTED_WITH_MSG("enabled is not a  property that XAML has available for TextBlock");
    return StubReturn();
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
        _textBlock.TextAlignment(XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(_alignment));

        [self setNeedsDisplay];
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
        // update textColor for label normal state
        _textColor = color;

        // if label is not in highlighted state or it is in highlighted state but without highlighted Color
        // both cases need use normal text color to update the foreground
        if (!_isHighlighted || _highlightedTextColor == nil) {
            _textBlock.Foreground(Media::SolidColorBrush(XamlUtilities::ConvertUIColorToWUColor(_textColor)));
            [self setNeedsDisplay];
        }
    }
}

/**
 @Status Interoperable
*/
- (UIColor*)textColor {
    return _textColor;
}

/**
  @Status NotInPlan
  @Notes ShadowColor is not currently supported by Xaml.
*/
- (void)setShadowColor:(UIColor*)colorref {
    UNIMPLEMENTED_WITH_MSG("ShadowColor is not a feature currently supported by Xaml.");
}

/**
  @Status NotInPlan
  @Notes ShadowColor is not currently supported by Xaml.
*/
- (UIColor*)shadowColor {
    UNIMPLEMENTED_WITH_MSG("ShadowColor is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes shadowOffset is not currently supported by Xaml.
*/
- (void)setShadowOffset:(CGSize)offset {
    UNIMPLEMENTED_WITH_MSG("ShadowOffset is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
 @Notes shadowOffset is not currently supported by Xaml.
*/
- (CGSize)shadowOffset {
    UNIMPLEMENTED_WITH_MSG("ShadowOffset is not a feature currently supported by Xaml.");
    return StubReturn();
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
    if (numberOfLines != _numberOfLines) {
        _numberOfLines = numberOfLines;
        _textBlock.MaxLines(self.numberOfLines);
        XamlUtilities::ApplyLineBreakModeOnTextBlock(_textBlock, _lineBreakMode, self.numberOfLines);
        [self _adjustTextBlockFontSizeIfNecessary];
    }
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
    if (_minimumFontSize != size) {
        _minimumFontSize = size;
        [self _adjustTextBlockFontSizeIfNecessary];
    }

    _useMinimumScaleFactor = NO;
}

/**
 @Status Interoperable
*/
- (float)minimumFontSize {
    return _minimumFontSize;
}

/**
 @Status NotInPlan
 @Notes baselineAdjustment is not currently supported by Xaml.
*/
- (void)setBaselineAdjustment:(UIBaselineAdjustment)adjustment {
    UNIMPLEMENTED_WITH_MSG("baselineAdjustment is not a feature currently supported by Xaml.");
}

/**
 @Status NotInPlan
 @Notes baselineAdjustment is not currently supported by Xaml.
*/
- (UIBaselineAdjustment)baselineAdjustment {
    UNIMPLEMENTED_WITH_MSG("baselineAdjustment is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status Caveat
 @Notes NSLineBreakByCharWrapping/NSLineBreakByTruncatingHead/NSLineBreakByTruncatingMiddle
 are not supported. NSLineBreakByCharWrapping is using NSLineBreakByWordWrapping instead.
 NSLineBreakByTruncatingHead/NSLineBreakByTruncatingMiddle is using NSLineBreakByTruncatingTail instead
*/
- (void)setLineBreakMode:(UILineBreakMode)mode {
    if (_lineBreakMode != mode) {
        _lineBreakMode = mode;
        XamlUtilities::ApplyLineBreakModeOnTextBlock(_textBlock, _lineBreakMode, self.numberOfLines);
        [self _adjustTextBlockFontSizeIfNecessary];
    }
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
    if (highlighted != _isHighlighted) {
        _isHighlighted = highlighted;
        if (_isHighlighted) {
            [self setBackgroundColor:nil];
        } else {
            [self setBackgroundColor:_savedBackgroundColor];
        }

        // update textblock foreground when highlighted color is different from textcolor
        if (![_highlightedTextColor isEqual:_textColor]) {
            UIColor* color = _isHighlighted ? _highlightedTextColor : _textColor;
            _textBlock.Foreground(Media::SolidColorBrush(XamlUtilities::ConvertUIColorToWUColor(color)));

            [self setNeedsDisplay];
        }
    }
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
    if (color == nil && _highlightedTextColor == nil) {
        return;
    }

    if (![color isEqual:_highlightedTextColor]) {
        _highlightedTextColor = color;
        if (_isHighlighted) {
            _textBlock.Foreground(Media::SolidColorBrush(XamlUtilities::ConvertUIColorToWUColor(_highlightedTextColor)));
            [self setNeedsDisplay];
        }
    }
}

/**
 @Status Interoperable
*/
- (UIColor*)highlightedTextColor {
    return _highlightedTextColor;
}

/**
@Status NotInPlan
@Notes drawTextInRect is not currently supported by Xaml.
*/
- (void)drawTextInRect:(CGRect)rect {
    UNIMPLEMENTED_WITH_MSG("drawTextInRect is not a feature currently supported by Xaml.");
}

/**
@Status Stub
*/
- (void)setClipsToBounds:(BOOL)value {
    UNIMPLEMENTED();
}

/**
@Status Stub
*/
- (BOOL)clipsToBounds {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
- (void)setAdjustsLetterSpacingToFitWidth:(BOOL)value {
    UNIMPLEMENTED();
}

/**
@Status Stub
*/
- (BOOL)adjustsLetterSpacingToFitWidth {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
*/
- (void)setPreferredMaxLayoutWidth:(CGFloat)value {
    UNIMPLEMENTED();
}

/**
@Status Stub
*/
- (CGFloat)preferredMaxLayoutWidth {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status NotInPlan
@Notes allowsDefaultTighteningForTruncation is not supported by xaml
*/
- (void)setAllowsDefaultTighteningForTruncation:(BOOL)value {
    UNIMPLEMENTED_WITH_MSG("setAllowsDefaultTighteningForTruncation is not a feature currently supported by Xaml.");
}

/**
@Status NotInPlan
@Notes allowsDefaultTighteningForTruncation is not supported by xaml
*/
- (BOOL)allowsDefaultTighteningForTruncation {
    UNIMPLEMENTED_WITH_MSG("allowsDefaultTighteningForTruncation is not a feature currently supported by Xaml.");
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (void)setAdjustsFontSizeToFitWidth:(BOOL)adjusts {
    if (adjusts != _adjustFontSize) {
        _adjustFontSize = adjusts;
        [self _adjustTextBlockFontSizeIfNecessary];
    }
}

- (BOOL)_adjustTextBlockFontSizeIfNecessary {
    BOOL textBlockFontSizeUpdated = NO;
    float curTextBlockFontSize = _textBlock.FontSize();
    if (_adjustFontSize) {
        // search for font that can fit - but it might not exist, in which case it return -1.0f
        float adjustedFontSize = [self _searchAdjustedFontSizeToFit];
        if (adjustedFontSize != -1.0f && adjustedFontSize != curTextBlockFontSize) {
            _textBlock.FontSize(adjustedFontSize);
            UIFont* adjustFont = [_font fontWithSize:adjustedFontSize];

            // when updating font size, also need update lineheight
            _textBlock.LineHeight([adjustFont ascender] - [adjustFont descender]);
            textBlockFontSizeUpdated = YES;
        }
    } else {
        // in NO adjustment mode, check if textblock fontsize is different from current font size
        // if so, textBlock fontsize was adjusted, need to swich it back
        float curFontSize = [_font pointSize];
        if (curTextBlockFontSize != curFontSize) {
            _textBlock.FontSize(curFontSize);

            // when updating font size, also need update lineheight
            _textBlock.LineHeight([_font ascender] - [_font descender]);
            textBlockFontSizeUpdated = YES;
        }
    }

    if (textBlockFontSizeUpdated) {
        [self invalidateIntrinsicContentSize];
        [self setNeedsDisplay];
    }

    // return YES/NO to indicate whether layout has been triggered
    // so that caller can avoid calling layout again if necessary
    return textBlockFontSizeUpdated;
}

/**
 @Status Interoperable
*/
- (void)setMinimumScaleFactor:(float)scale {
    if (_minimumScaleFactor != scale) {
        _minimumScaleFactor = scale;
        [self _adjustTextBlockFontSizeIfNecessary];
    }

    _useMinimumScaleFactor = YES;
}

/**
 @Status Interoperable
*/
- (float)minimumScaleFactor {
    return _minimumScaleFactor;
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
    CGSize ret = CGSizeZero;

    if ([_text length] != 0) {
        if (self.numberOfLines != 0) {
            CGFloat lineHeight = [_font ascender] - [_font descender];
            curSize.height = lineHeight * self.numberOfLines;

            if (self.numberOfLines == 1) {
                curSize.width = 0;
            }
        } else {
            curSize.height = 0;
        }

        //  Calculate the size of the text set in our label
        ret = [_text sizeWithFont:_font constrainedToSize:CGSizeMake(curSize.width, curSize.height) lineBreakMode:self.lineBreakMode];
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