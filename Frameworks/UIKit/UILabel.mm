//******************************************************************************
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

#import <UIKit/NSString+UIKitAdditions.h>
#import <UIKit/UIAccessibility.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIFont.h>
#import <UIKit/UILabel.h>
#import <UIKit/UIView.h>

#import <CoreGraphics/CGContext.h>

#import <Foundation/NSString.h>

#import "UIFontInternal.h"
#import "UILabelInternal.h"
#import "CGContextInternal.h"
#import "StarboardXaml/DisplayProperties.h"
#import "XamlControls.h"
#import "XamlUtilities.h"

static const wchar_t* TAG = L"UILabel";

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
    BOOL _useMinimumScaleFactor;
    float _minimumScaleFactor;
    int _numberOfLines;
    BOOL _isDisabled;
    BOOL _isHighlighted;
    UIBaselineAdjustment _baselineAdjustment;
    StrongId<WXCTextBlock> _textBlock;
}

// Helper searches max font size for a string that can fit into given rect using given font/linkbreak config .
// if no fit is found (e.g., to satisfy minimum font size requirement, nil is returned.
// Otherwise, it returns the maximum font size for that can fit
- (UIFont*)_findMaxFontSizeToFit:(CGRect)rect
                            Text:(NSString*)text
                            Font:(UIFont*)font
                   NumberOfLines:(int)numberOfLines
                 MinimumFontSize:(float)mininumFontSize
                StartingFontSize:(float)startingFontSize {
    // Use FLT_MAX as search upper bound and mininumFontSize as search lower bound
    float upperBound = FLT_MAX;
    float lowerBound = mininumFontSize;

    // Using max of lowerBound and current font size as search starting point
    float curFontSize = std::max(startingFontSize, mininumFontSize);
    StrongId<UIFont> _targetFont = [_font fontWithSize:curFontSize];

    // Do binary search on maximum font size that fits the bound
    do {
        // Caculating constrains for allowedHeight
        float lineHeight = [_targetFont ascender] - [_targetFont descender];
        float allowedHeight = (numberOfLines == 0) ? rect.size.height : std::min(lineHeight * self.numberOfLines, rect.size.height);

        CGSize size = CGSizeZero;
        if (numberOfLines == 1) {
            // In one line case, linebreak mode and allowed height really does not matter because we give it unlimited width for measure
            size = [text sizeWithFont:_targetFont constrainedToSize:CGSizeMake(0.0f, allowedHeight) lineBreakMode:UILineBreakModeClip];
        } else {
            // In multi-line case, we want the line to be wrapping during measure, in this case, we want to give allowed hight as unlimited
            size =
                [text sizeWithFont:_targetFont constrainedToSize:CGSizeMake(rect.size.width, 0.0f) lineBreakMode:UILineBreakModeWordWrap];
        }

        if (size.width <= rect.size.width && size.height <= allowedHeight) {
            // Find a fit, update lowerBound
            lowerBound = curFontSize;
            if (upperBound == FLT_MAX) {
                // No upper bound yet, retry with doubling current font size
                curFontSize *= 2.0f;
            } else {
                // retry with middle value between lower bound and upper bound
                curFontSize = (upperBound + lowerBound) / 2.0f;
            }
        } else {
            // Current font size does not fit, update upperBound
            upperBound = std::min(upperBound, curFontSize);
            if (curFontSize - lowerBound <= 1.0f) {
                // Distance between current font size which does not fit
                // and maximum font size which fits is less than 1.0, break out
                break;
            } else {
                // Retry with middle value between lowerBound and upper bound
                curFontSize = (lowerBound + upperBound) / 2.0f;
            }
        }

        _targetFont = [_targetFont fontWithSize:curFontSize];
    } while (true);

    if (lowerBound == mininumFontSize) {
        // If lowerBound is the same as minimum font size, it means no font size can be found to fit
        // In this case, should not adjust font, same as reference platform does
        return nil;
    }

    return [_targetFont fontWithSize:lowerBound];
}

- (void)_adjustFontSizeToFit {
    CGRect rect = [self bounds];

    if (rect.size.width == 0.0f || rect.size.height == 0.0f || [_text length] == 0) {
        return;
    }

    // Special:on reference platform, adjustFontSizeToFit is no-op when lineBreakMode is Wrapping
    if (_lineBreakMode != UILineBreakModeWordWrap && _lineBreakMode != UILineBreakModeCharacterWrap) {
        float minimumFontSize = _minimumFontSize;

        // if minimumScaleFactor is used, it should override _minimumFontSize which is deprecated
        if (_useMinimumScaleFactor) {
            if (_minimumScaleFactor > 0.0) {
                minimumFontSize = _minimumScaleFactor * _originalFontSize;
            } else {
                // per reference platform, if minimumScaleFactor is set and equal to 0.0
                // use current font size is used as smallest font size
                minimumFontSize = [_font pointSize];
            }
        }

        StrongId<UIFont> _targetFont = [self _findMaxFontSizeToFit:rect
                                                              Text:_text
                                                              Font:_font
                                                     NumberOfLines:_numberOfLines
                                                   MinimumFontSize:minimumFontSize
                                                  StartingFontSize:[_font pointSize]];
        if (_targetFont != nil) {
            // found a font that can be adjusted to fit, otherwise, do nothing
            _font = _targetFont;
        }
    }

    [self _updateXamlElement];
}

- (void)_updateXamlElement {
    [_textBlock setText:_text];
    [_textBlock setFontSize:[_font pointSize]];

    WUTFontWeight* fontWeight = [WUTFontWeight new];
    fontWeight.weight = static_cast<unsigned short>([_font _fontWeight]);
    [_textBlock setFontWeight:fontWeight];
    [_textBlock setFontStyle:static_cast<WUTFontStyle>([_font _fontStyle])];
    [_textBlock setFontStretch:static_cast<WUTFontStretch>([_font _fontStretch])];

    [_textBlock setFontFamily:[WUXMFontFamily makeInstanceWithName:[_font _compatibleFamilyName]]];

    [_textBlock setTextAlignment:XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(_alignment)];

    [_textBlock setLineHeight:[_font ascender] - [_font descender]];

    XamlUtilities::ApplyLineBreakModeOnTextBlock(_textBlock, _lineBreakMode, self.numberOfLines);
    [_textBlock setLineStackingStrategy:WXLineStackingStrategyBlockLineHeight];

    UIColor* color = _textColor;
    if (_isHighlighted && _highlightedTextColor != nil) {
        color = _highlightedTextColor;
    }
    [_textBlock setForeground:[WUXMSolidColorBrush makeInstanceWithColor:XamlUtilities::ConvertUIColorToWUColor(color)]];

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
        }  else if ([coder containsValueForKey:@"UIAdjustsFontSizeToFit"]) {
            _adjustFontSize = [coder decodeInt32ForKey:@"UIAdjustsFontSizeToFit"];
            if(_adjustFontSize) {
                TraceWarning(TAG, L"Invalid nib format, UIAdjustsFontSizeToFit should be set to FALSE if it is set, currently set as TRUE, overwritting with FALSE");
                _adjustFontSize = NO;
            }
        } else {
            TraceWarning(TAG, L"Invalid nib format, None of UIMinimumScaleFactor/UIMinimumFontSize/UIAdjustsFontSizeToFit is set. default UIAdjustsFontSizeToFit to FALSE");
            _adjustFontSize = NO;
        }

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
            [self _adjustFontSizeToFit];
        } else {
            [self _updateXamlElement];
        }
    }

    return self;
}

// Returns access to the underlying TextBlock within the UILabel's Xaml representation
// Note: This is used for UX testing and won't be necessary when we are projecting
// UIKit.Label into ObjectiveC, as at that point we can just expose the TextBlock directly
// off of our UIKit.Label implementation.
- (WXCTextBlock*)_getXamlTextBlock {
    return _textBlock;
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

    // on reference platform, default minimum font size is zero but always slightly bigger than zero in reality acccording to the
    // documentation
    _minimumFontSize = 0.0001f;
    _minimumScaleFactor = 0.0;
    _useMinimumScaleFactor = NO;
    _numberOfLines = 1;
    [self setOpaque:FALSE];

    _originalFontSize = [UIFont labelFontSize];
    _font = [UIFont fontWithName:@"Segoe UI" size:_originalFontSize];

    // TODO: Reevaluate whether or not this is the correct default mode for UILabels that are initialized via initWithFrame.
    //       Some of our test apps expect the initWithCoder path to default to UIViewContentModeScaleToFill (aka kCAGravityResize).
    [self setContentMode:UIViewContentModeRedraw];
    [self _updateXamlElement];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self _initUILabel];
    }

    return self;
}

/**
 Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(WXFrameworkElement*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        [self _initUILabel];
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
            [self _adjustFontSizeToFit];
        } else {
            [self _updateXamlElement];
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

        if (_adjustFontSize) {
            [self _adjustFontSizeToFit];
        } else {
            [self _updateXamlElement];
        }

        self.accessibilityValue = newStr;
    }
}

/**
 @Status Stub
*/
- (void)setAttributedText:(NSAttributedString*)newStr {
    UNIMPLEMENTED();
    _attributedText = [newStr copy];
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
        [self _updateXamlElement];
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
        _textColor = color;
        [self _updateXamlElement];
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
    _useMinimumScaleFactor = NO;
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
    [self _updateXamlElement];
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
    [self _updateXamlElement];
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
        [self _adjustFontSizeToFit];
    }
}

/**
 @Status Interoperable
*/
- (void)setMinimumScaleFactor:(float)scale {
    _minimumScaleFactor = scale;
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
            // for fixed number of lines, use hinted size as contraints for height
            CGFloat lineHeight = [_font ascender] - [_font descender];
            curSize.height = std::min(lineHeight * self.numberOfLines, curSize.height);
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
- (void)layoutSubviews {
    if (_adjustFontSize) {
        [self _adjustFontSizeToFit];
    } else {
        [self _updateXamlElement];
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
