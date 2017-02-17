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
#import <UIKit/UILabel.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIImageView.h>
#import <Foundation/NSString.h>
#include "CppWinRTHelpers.h"

// TOOD: Bug 8706843:Constructor or Helper to create FontFamily isn't projected - thus no way to create a FontFamily from Objective C side.
// remove this once 8706843 is resolved
#ifdef __OBJC__
#pragma push_macro("interface")
#ifndef interface
#define interface struct
#endif
#pragma push_macro("Nil")
#undef Nil
#endif
#include <UWP/RTHelpers.h>
#ifdef __OBJC__
#pragma pop_macro("Nil")
#pragma pop_macro("interface")
#endif

#import <CoreGraphics/CGContext.h>
#import <UIKit/UIView.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIColor.h>
#import "UIButtonProxies.h"
#import "UIFontInternal.h"

#import "XamlUtilities.h"

#import "Activation.h"

#include <Windows.UI.Xaml.Media.h>

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.h>
#import <winrt/Windows.UI.Xaml.Media.h>
#import <winrt/Windows.UI.Text.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::UI::Xaml;

static const wchar_t* tag = L"UIButtonProxies";

@implementation _MockObjectBase

+ (Class)_mockClass {
    return [NSObject class];
}

- (void)forwardInvocation:(NSInvocation*)invocation {
    TraceWarning(tag,
                 L"Warning: unsupported API or property is invoked on this class - %hs is currently a mock %hs and only supports a subset "
                 L"of its selectors",
                 class_getName([self class]),
                 class_getName([[self class] _mockClass]));
}

- (NSMethodSignature*)methodSignatureForSelector:(SEL)aSelector {
    if ([[[self class] _mockClass] instancesRespondToSelector:aSelector]) {
        return [[[self class] _mockClass] instanceMethodSignatureForSelector:aSelector];
    }
    return [super methodSignatureForSelector:aSelector];
}

@end

@implementation _UIView_Proxy {
    TrivialDefaultConstructor<FrameworkElement> _xamlElement;
}

+ (Class)_mockClass {
    return [UIView class];
}

- (instancetype)initWithXamlElement:(const FrameworkElement&)xamlElement {
    if (self = [super init]) {
        _xamlElement = xamlElement;
    }
    return self;
}

- (FrameworkElement)xamlElement {
    return _xamlElement;
}

- (void)setFrame:(CGRect)frame {
    // Only set canvas top/left values if we have a non-null frame.
    // Otherwise we set them to infinity, which causes touch input issues.
    if (!CGRectIsNull(frame)) {
        // We're assuming everything will be held in a Canvas
        Controls::Canvas::SetTop(_xamlElement, frame.origin.y);
        Controls::Canvas::SetTop(_xamlElement, frame.origin.x);
    }

    _xamlElement.Width(frame.size.width);
    _xamlElement.Height(frame.size.height);
}

- (CGRect)frame {
    CGRect ret = { 0 };

    // We're assuming everything will be held in a Canvas
    Controls::Canvas::GetTop(_xamlElement);
    Controls::Canvas::GetLeft(_xamlElement);

    ret.size.width = _xamlElement.Width();
    ret.size.height = _xamlElement.Height();

    return ret;
}

@end

<<<<<<< 17c9442ca7373bbb57c3f561cd59160aa9296832
=======
@implementation _UILabel_Proxy {
    StrongId<UIFont> _font;
    TrivialDefaultConstructor<Controls::TextBlock> _dummyTextBlock;

    // For convenience
    TrivialDefaultConstructor<Controls::TextBlock> _xamlTextBlock;
}

+ (Class)_mockClass {
    return [UILabel class];
}

- (void)setFrame:(CGRect)frame {
    // UILabels are vertically aligned
    [super setFrame:frame];
    _xamlTextBlock.Measure(SizeHelper::FromDimensions(frame.size.width, frame.size.height));

    float centerOffset = (frame.size.height - _xamlTextBlock.ActualHeight()) / 2.0f;
    _xamlTextBlock.Margin(ThicknessHelper::FromLengths(0, centerOffset, 0, 0));
}

- (instancetype)initWithXamlElement:(const FrameworkElement&)xamlElement font:(UIFont*)font {
    FAIL_FAST_IF_NULL(xamlElement);
    auto textBlock = xamlElement.try_as<Controls::TextBlock>();
    FAIL_FAST_IF_NULL(textBlock);

    if (self = [super initWithXamlElement:textBlock]) {
        _xamlTextBlock = textBlock;

        // TODO: Copy attributes from xamlElement?
        _dummyTextBlock = Controls::TextBlock();
        FAIL_FAST_IF_NULL(_dummyTextBlock);

        // set up default font
        if (font == nil) {
            [self setFont:[UIFont defaultFont]];
        } else {
            [self setFont:font];
        }
    }

    return self;
}

- (void)setNumberOfLines:(NSInteger)numberOfLines {
    _xamlTextBlock.MaxLines(numberOfLines);
}

- (NSInteger)numberOfLines {
    return _xamlTextBlock.MaxLines();
}

- (void)setTextAlignment:(UITextAlignment)alignment {
    _xamlTextBlock.TextAlignment(XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(alignment));
}

- (UITextAlignment)textAlignment {
    return XamlUtilities::ConvertWXTextAlignmentToUITextAlignment(_xamlTextBlock.TextAlignment());
}

- (void)setText:(NSString*)text {
    auto str = Strings::NarrowToWide<HSTRING>(text);
    _xamlTextBlock.Text(winrt::hstring_ref(str.Get()));
}

- (NSString*)text {
    return objcwinrt::string(_xamlTextBlock.Text());
}

- (void)setFont:(UIFont*)font {
    if ([font isEqual:_font]) {
        return;
    }

    _font = font;
    _xamlTextBlock.FontSize([_font pointSize]);

    Media::FontFamily fontFamily = winrt::hstring_ref(objcwinrt::string([_font fontName]));
    _xamlTextBlock.FontFamily(fontFamily);

    _xamlTextBlock.LineStackingStrategy(LineStackingStrategy::BlockLineHeight);
    _xamlTextBlock.LineHeight([_font ascender] - [_font descender]);

    int mask = [_font fontDescriptor].symbolicTraits;
    if ((mask & UIFontDescriptorTraitBold) > 0) {
        _xamlTextBlock.FontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
    } else {
        _xamlTextBlock.FontWeight(winrt::Windows::UI::Text::FontWeights::Normal());
    }

    if ((mask & UIFontDescriptorTraitItalic) > 0) {
        _xamlTextBlock.FontStyle(winrt::Windows::UI::Text::FontStyle::Italic);
    } else {
        _xamlTextBlock.FontStyle(winrt::Windows::UI::Text::FontStyle::Normal);
    }
}

- (UIFont*)font {
    return _font;
}

- (UIColor*)textColor {
    auto brush = _xamlTextBlock.Foreground().try_as<Media::SolidColorBrush>();

    if (brush) {
        return [UIColor colorWithRed:brush.Color().R green:brush.Color().G blue:brush.Color().B alpha:brush.Color().A];
    } else {
        return nil;
    }
}

- (void)setLineBreakMode:(UILineBreakMode)mode {
    XamlUtilities::ApplyLineBreakModeOnTextBlock(_xamlTextBlock, mode, self.numberOfLines);
}

- (UILineBreakMode)lineBreakMode {
    switch (_xamlTextBlock.TextWrapping()) {
        case TextWrapping::WrapWholeWords:
            return UILineBreakModeWordWrap;

        case TextWrapping::Wrap:
            return UILineBreakModeCharacterWrap;

        case TextWrapping::NoWrap:
            if (_xamlTextBlock.TextTrimming() == TextTrimming::Clip) {
                return UILineBreakModeClip;
            }
    }

    return UILineBreakModeWordWrap;
}

- (CGSize)intrinsicContentSize {
    auto inf = SizeHelper::FromDimensions(FLT_MAX, FLT_MAX);
    [self _updateDummyTextBlock];
    _dummyTextBlock.Measure(inf);
    return CGSizeMake(_dummyTextBlock.DesiredSize().Width, _dummyTextBlock.DesiredSize().Height);
}

- (void)_updateDummyTextBlock {
    // When a TextBlock is in the scene graph, it may have implicit constraints on it keeping it from being
    // correctly Measured. To ensure an unbounded Measure we replicate the TextBlock, but never add it to
    // the graph; it's used solely for measurement.
    _dummyTextBlock.TextWrapping(_xamlTextBlock.TextWrapping());
    _dummyTextBlock.TextTrimming(_xamlTextBlock.TextTrimming());
    _dummyTextBlock.LineStackingStrategy(_xamlTextBlock.LineStackingStrategy());
    _dummyTextBlock.LineHeight(_xamlTextBlock.LineHeight());
    _dummyTextBlock.FontStyle(_xamlTextBlock.FontStyle());
    _dummyTextBlock.FontFamily(_xamlTextBlock.FontFamily());
    _dummyTextBlock.FontSize(_xamlTextBlock.FontSize());
    _dummyTextBlock.TextAlignment(_xamlTextBlock.TextAlignment());
    _dummyTextBlock.Text(_xamlTextBlock.Text());
}

@end

>>>>>>> Switch UIKit from projections to C++/WinRT (rough draft)
@implementation _UIImageView_Proxy {
    // For convenience
    TrivialDefaultConstructor<Controls::Image> _xamlImage;
}

+ (Class)_mockClass {
    return [UIImageView class];
}

- (instancetype)initWithXamlElement:(const FrameworkElement&)xamlElement {
    FAIL_FAST_IF_NULL(xamlElement);
    auto image = xamlElement.try_as<Controls::Image>();
    FAIL_FAST_IF_NULL(image);

    if (self = [super initWithXamlElement:xamlElement]) {
        _xamlImage = image;
    }

    return self;
}

- (CGSize)intrinsicContentSize {
    if (self.image) {
        // TODO: Do we have to care about cap insets?
        return self.image.size;
    } else {
        return CGSizeMake(UIViewNoIntrinsicMetric, UIViewNoIntrinsicMetric);
    }
}

- (CGSize)sizeThatFits:(CGSize)curSize {
    if (self.image) {
        // TODO: Do we have to care about cap insets?
        return self.image.size;
    } else {
        return CGSizeMake(0, 0);
    }
}

@end