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
#import <Foundation/NSString.h>

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

#import <UWP/WindowsUIXamlControls.h>
#import "XamlUtilities.h"

#import "Activation.h"

#include <Windows.UI.Xaml.Media.h>

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

@implementation _UIView_Proxy

+ (Class)_mockClass {
    return [UIView class];
}

- (instancetype)initWithXamlElement:(WXFrameworkElement*)xamlElement {
    if (self = [super init]) {
        _xamlElement = xamlElement;
    }
    return self;
}

- (void)setFrame:(CGRect)frame {
    // Only set canvas top/left values if we have a non-null frame.
    // Otherwise we set them to infinity, which causes touch input issues.
    if (!CGRectIsNull(frame)) {
        // We're assuming everything will be held in a Canvas
        [WXCCanvas setTop:_xamlElement length:frame.origin.y];
        [WXCCanvas setLeft:_xamlElement length:frame.origin.x];
    }

    _xamlElement.width = frame.size.width;
    _xamlElement.height = frame.size.height;
}

- (CGRect)frame {
    CGRect ret = { 0 };

    // We're assuming everything will be held in a Canvas
    [WXCCanvas getTop:_xamlElement];
    [WXCCanvas getLeft:_xamlElement];

    ret.size.width = _xamlElement.width;
    ret.size.height = _xamlElement.height;

    return ret;
}

@end

@implementation _UILabel_Proxy {
    StrongId<UIFont> _font;
    StrongId<WXCTextBlock> _dummyTextBlock;

    // For convenience
    WXCTextBlock* _xamlTextBlock;
}

+ (Class)_mockClass {
    return [UILabel class];
}

- (void)setFrame:(CGRect)frame {
    // UILabels are vertically aligned
    [super setFrame:frame];
    [_xamlTextBlock measure:[WXSizeHelper fromDimensions:frame.size.width height:frame.size.height]];

    float centerOffset = (frame.size.height - _xamlTextBlock.actualHeight) / 2.0f;
    _xamlTextBlock.margin = [WXThicknessHelper fromLengths:0 top:centerOffset right:0 bottom:0];
}

- (instancetype)initWithXamlElement:(WXFrameworkElement*)xamlElement font:(UIFont*)font {
    FAIL_FAST_IF_NULL(xamlElement);
    WXCTextBlock* textBlock = rt_dynamic_cast<WXCTextBlock>(xamlElement);
    FAIL_FAST_IF_NULL(textBlock);

    if (self = [super initWithXamlElement:textBlock]) {
        _xamlTextBlock = textBlock;

        // TODO: Copy attributes from xamlElement?
        _dummyTextBlock = [WXCTextBlock make];
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
    _xamlTextBlock.maxLines = numberOfLines;
}

- (NSInteger)numberOfLines {
    return _xamlTextBlock.maxLines;
}

- (void)setTextAlignment:(UITextAlignment)alignment {
    _xamlTextBlock.textAlignment = ConvertUITextAlignmentToWXTextAlignment(alignment);
}

- (UITextAlignment)textAlignment {
    return ConvertWXTextAlignmentToUITextAlignment(_xamlTextBlock.textAlignment);
}

- (void)setText:(NSString*)text {
    _xamlTextBlock.text = text;
}

- (NSString*)text {
    return _xamlTextBlock.text;
}

- (void)setFont:(UIFont*)font {
    if ([font isEqual:_font]) {
        return;
    }

    _font = font;
    _xamlTextBlock.fontSize = [_font pointSize];

    // TOOD: Bug 8706843:Constructor or Helper to create FontFamily isn't projected - thus no way to create a FontFamily from Objective C
    // side. we can remove all WRL related stuff and use projection API directly when it is ready
    ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamilyFactory> fontFamilyFactory;
    ABI::Windows::Foundation::GetActivationFactory(
        Microsoft::WRL::Wrappers::HString::MakeReference(L"Windows.UI.Xaml.Media.FontFamily").Get(), &fontFamilyFactory);

    ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamily> fontFamily;
    auto fontName = Strings::NarrowToWide<HSTRING>([_font fontName]);
    fontFamilyFactory->CreateInstanceWithName(fontName.Get(), nullptr, nullptr, fontFamily.GetAddressOf());
    _xamlTextBlock.fontFamily = [WUXMFontFamily createWith:fontFamily.Get()];

    _xamlTextBlock.lineStackingStrategy = WXLineStackingStrategyBlockLineHeight;
    _xamlTextBlock.lineHeight = [_font ascender] - [_font descender];

    int mask = [_font fontDescriptor].symbolicTraits;
    if ((mask & UIFontDescriptorTraitBold) > 0) {
        _xamlTextBlock.fontWeight = [WUTFontWeights bold];
    } else {
        _xamlTextBlock.fontWeight = [WUTFontWeights normal];
    }

    if ((mask & UIFontDescriptorTraitItalic) > 0) {
        _xamlTextBlock.fontStyle = WUTFontStyleItalic;
    } else {
        _xamlTextBlock.fontStyle = WUTFontStyleNormal;
    }
}

- (UIFont*)font {
    return _font;
}

- (UIColor*)textColor {
    WUXMSolidColorBrush* brush = rt_dynamic_cast([WUXMSolidColorBrush class], _xamlTextBlock.foreground);

    if (brush) {
        return [UIColor colorWithRed:brush.color.r green:brush.color.g blue:brush.color.b alpha:brush.color.a];
    } else {
        return nil;
    }
}

- (void)setLineBreakMode:(UILineBreakMode)mode {
    switch (mode) {
        case UILineBreakModeWordWrap:
            _xamlTextBlock.textTrimming = WXTextTrimmingNone;
            _xamlTextBlock.textWrapping = WXTextWrappingWrapWholeWords;
            break;

        case UILineBreakModeCharacterWrap:
            _xamlTextBlock.textTrimming = WXTextTrimmingNone;
            _xamlTextBlock.textWrapping = WXTextWrappingWrap;
            break;

        case UILineBreakModeClip:
            _xamlTextBlock.textWrapping = WXTextWrappingNoWrap;
            _xamlTextBlock.textTrimming = WXTextTrimmingClip;
            break;

        case UILineBreakModeHeadTruncation:
            // GAP: currently textblock don't support UILineBreakModeHeadTruncation
            UNIMPLEMENTED_WITH_MSG("UILineBreakModeHeadTruncation unsupported");
            break;

        case UILineBreakModeMiddleTruncation:
            // GAP currently textblock don't support UILineBreakModeMiddleTruncation
            UNIMPLEMENTED_WITH_MSG("UILineBreakModeMiddleTruncation unsupported");
            break;

        case UILineBreakModeTailTruncation:
            _xamlTextBlock.textWrapping = WXTextWrappingNoWrap;
            _xamlTextBlock.textTrimming = WXTextTrimmingCharacterEllipsis;
            break;
    }
}

- (UILineBreakMode)lineBreakMode {
    switch (_xamlTextBlock.textWrapping) {
        case WXTextWrappingWrapWholeWords:
            return UILineBreakModeWordWrap;

        case WXTextWrappingWrap:
            return UILineBreakModeCharacterWrap;

        case WXTextWrappingNoWrap:
            if (_xamlTextBlock.textTrimming == WXTextTrimmingClip) {
                return UILineBreakModeClip;
            }
    }

    return WXTextTrimmingCharacterEllipsis;
}

- (CGSize)intrinsicContentSize {
    WFSize* inf = [WXSizeHelper fromDimensions:FLT_MAX height:FLT_MAX];
    [self _updateDummyTextBlock];
    [_dummyTextBlock measure:inf];
    return CGSizeMake(_dummyTextBlock.desiredSize.width, _dummyTextBlock.desiredSize.height);
}

- (void)_updateDummyTextBlock {
    // When a TextBlock is in the scene graph, it may have implicit constraints on it keeping it from being
    // correctly Measured. To ensure an unbounded Measure we replicate the TextBlock, but never add it to
    // the graph; it's used solely for measurement.
    _dummyTextBlock.textWrapping = _xamlTextBlock.textWrapping;
    _dummyTextBlock.textTrimming = _xamlTextBlock.textTrimming;
    _dummyTextBlock.lineStackingStrategy = _xamlTextBlock.lineStackingStrategy;
    _dummyTextBlock.lineHeight = _xamlTextBlock.lineHeight;
    _dummyTextBlock.fontStyle = _xamlTextBlock.fontStyle;
    _dummyTextBlock.fontFamily = _xamlTextBlock.fontFamily;
    _dummyTextBlock.fontSize = _xamlTextBlock.fontSize;
    _dummyTextBlock.textAlignment = _xamlTextBlock.textAlignment;
    _dummyTextBlock.text = _xamlTextBlock.text;
}

@end

@implementation _UIImageView_Proxy {
    // For convenience
    WXCImage* _xamlImage;
}

+ (Class)_mockClass {
    return [UIImageView class];
}

- (instancetype)initWithXamlElement:(WXFrameworkElement*)xamlElement {
    FAIL_FAST_IF_NULL(xamlElement);
    WXCImage* image = rt_dynamic_cast<WXCImage>(xamlElement);
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