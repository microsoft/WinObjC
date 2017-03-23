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
#import "AssertARCEnabled.h"
#import "XamlUtilities.h"

#import <UIKit/UIActivityIndicatorView.h>
#import <UIKit/UIButton.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIImage.h>
#import <UIKit/UILabel.h>
#import <UIKit/UISlider.h>
#import <UIKit/NSString+UIKitAdditions.h>

#import "StarboardXaml/DisplayTexture.h"

#include <Windows.UI.Xaml.Media.h>

using namespace Microsoft::WRL;
using namespace Windows::Foundation;

using namespace XamlUtilities;

// cornerRadius when border style is set to round rectangle
static const int c_borderCornerRadius = 8;
static const wchar_t* TAG = L"XamlUtilities";

WUColor* XamlUtilities::ConvertUIColorToWUColor(UIColor* uiColor) {
    CGFloat r, g, b, a;
    [uiColor getRed:&r green:&g blue:&b alpha:&a];

    return
        [WUColorHelper fromArgb:(unsigned char)(a * 255) r:(unsigned char)(r * 255) g:(unsigned char)(g * 255) b:(unsigned char)(b * 255)];
}

UIColor* XamlUtilities::ConvertWUColorToUIColor(WUColor* wuColor) {
    CGFloat r = wuColor.r / 255.0;
    CGFloat g = wuColor.g / 255.0;
    CGFloat b = wuColor.b / 255.0;
    CGFloat a = wuColor.a / 255.0;
    return [UIColor colorWithRed:r green:g blue:b alpha:a];
}

WUXMImageBrush* XamlUtilities::ConvertUIImageToWUXMImageBrush(UIImage* image) {
    if (!image) {
        return nil;
    }

    CGImageRef cgImg = [image CGImage];
    Microsoft::WRL::ComPtr<IInspectable> inspectableNode(DisplayTexture::GetBitmapForCGImage(cgImg));
    WUXMIBitmapSource* bitmapImageSource = CreateRtProxy([WUXMIBitmapSource class], inspectableNode.Get());
    WUXMImageBrush* imageBrush = [WUXMImageBrush make];
    imageBrush.imageSource = bitmapImageSource;

    return imageBrush;
}

WUXMIBitmapSource* XamlUtilities::ConvertUIImageToWUXMIBitmapSource(UIImage* image) {
    if (!image) {
        return nil;
    }

    CGImageRef cgImg = [image CGImage];
    Microsoft::WRL::ComPtr<IInspectable> inspectableNode(DisplayTexture::GetBitmapForCGImage(cgImg));
    WUXMIBitmapSource* bitmapImageSource = CreateRtProxy([WUXMIBitmapSource class], inspectableNode.Get());

    return bitmapImageSource;
}

WXTextAlignment XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(UITextAlignment alignment) {
    switch (alignment) {
        case UITextAlignmentLeft:
            return WXTextAlignmentLeft;
            break;

        case UITextAlignmentCenter:
            return WXTextAlignmentCenter;
            break;

        case UITextAlignmentRight:
            return WXTextAlignmentRight;
            break;
    }

    return UITextAlignmentLeft;
}

UITextAlignment XamlUtilities::ConvertWXTextAlignmentToUITextAlignment(WXTextAlignment alignment) {
    switch (alignment) {
        case WXTextAlignmentLeft:
            return UITextAlignmentLeft;
            break;

        case WXTextAlignmentCenter:
            return UITextAlignmentCenter;
            break;

        case WXTextAlignmentRight:
            return UITextAlignmentRight;
            break;
    }

    return UITextAlignmentLeft;
}

WUXIInputScope* XamlUtilities::ConvertKeyboardTypeToInputScope(UIKeyboardType keyboardType, BOOL secureTextMode) {
    WUXIInputScopeName* inputScopeName = [WUXIInputScopeName make];
    inputScopeName.nameValue = WUXIInputScopeNameValueDefault;

    if (secureTextMode) {
        // passwordBox only supports NumbericPin and Password inputscope
        if (keyboardType == UIKeyboardTypeNumberPad) {
            inputScopeName.nameValue = WUXIInputScopeNameValueNumericPin;
        } else {
            inputScopeName.nameValue = WUXIInputScopeNameValuePassword;
        }
    } else {
        // normal textmode supports a lot more keyboardType
        switch (keyboardType) {
            case UIKeyboardTypeDefault:
                inputScopeName.nameValue = WUXIInputScopeNameValueDefault;
                break;

            case UIKeyboardTypeASCIICapable:
                inputScopeName.nameValue = WUXIInputScopeNameValueDefault;
                break;

            case UIKeyboardTypeNumbersAndPunctuation:
                inputScopeName.nameValue = WUXIInputScopeNameValueDigits;
                break;

            case UIKeyboardTypeURL:
                inputScopeName.nameValue = WUXIInputScopeNameValueUrl;
                break;

            case UIKeyboardTypeNumberPad:
                inputScopeName.nameValue = WUXIInputScopeNameValueDigits;
                break;

            case UIKeyboardTypePhonePad:
                inputScopeName.nameValue = WUXIInputScopeNameValueTelephoneNumber;
                break;

            case UIKeyboardTypeNamePhonePad:
                inputScopeName.nameValue = WUXIInputScopeNameValueNameOrPhoneNumber;
                break;

            case UIKeyboardTypeEmailAddress:
                inputScopeName.nameValue = WUXIInputScopeNameValueEmailNameOrAddress;
                break;

            case UIKeyboardTypeDecimalPad:
                inputScopeName.nameValue = WUXIInputScopeNameValueNumber;
                break;

            case UIKeyboardTypeTwitter:
                inputScopeName.nameValue = WUXIInputScopeNameValueDefault;
                break;

            case UIKeyboardTypeWebSearch:
                inputScopeName.nameValue = WUXIInputScopeNameValueSearch;
                break;
        }
    }

    WUXIInputScope* inputScope = [WUXIInputScope make];
    [inputScope.names addObject:inputScopeName];

    return inputScope;
}

WXVerticalAlignment XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(
    UIControlContentVerticalAlignment alignment) {
    WXVerticalAlignment ret = WXVerticalAlignmentTop;

    switch (alignment) {
        case UIControlContentVerticalAlignmentCenter:
            ret = WXVerticalAlignmentCenter;
            break;
        case UIControlContentVerticalAlignmentTop:
            ret = WXVerticalAlignmentTop;
            break;
        case UIControlContentVerticalAlignmentBottom:
            ret = WXVerticalAlignmentBottom;
            break;
        case UIControlContentVerticalAlignmentFill:
            ret = WXVerticalAlignmentStretch;
            break;
    }

    return ret;
}

WXFrameworkElement* XamlUtilities::FindTemplateChild(WXCControl* control, NSString* name) {
    WXFrameworkElement* target = nullptr;
    unsigned int count = [WUXMVisualTreeHelper getChildrenCount:control];
    if (count > 0) {
        WXFrameworkElement* templateRoot = rt_dynamic_cast<WXFrameworkElement>([WUXMVisualTreeHelper getChild:control childIndex:0]);
        if (templateRoot != nullptr) {
            target = rt_dynamic_cast<WXFrameworkElement>([templateRoot findName:name]);
        }
    }

    return target;
}

NSString* XamlUtilities::NSStringFromPropertyValue(RTObject* rtPropertyValue) {
    // BUGBUG:8791977 - WFIPropertyValue is not publicly exposed via projections so we used a workaround
    ComPtr<IInspectable> inspPropVal = [rtPropertyValue comObj];
    return NSStringFromPropertyValue(inspPropVal);
}

NSString* XamlUtilities::NSStringFromPropertyValue(const ComPtr<IInspectable>& inspPropertyValue) {
    ComPtr<ABI::Windows::Foundation::IPropertyValue> propVal;
    HRESULT hr = inspPropertyValue.As(&propVal);
    if (SUCCEEDED(hr)) {
        HSTRING str;
        auto freeHSTRING = wil::ScopeExit([&]() { WindowsDeleteString(str); });

        hr = propVal->GetString(&str);
        if (SUCCEEDED(hr)) {
            return Strings::WideToNSString<HSTRING>(str);
        }
    }

    return nil;
}

// Setup control border style
void XamlUtilities::SetControlBorderStyle(WXCControl* control, UITextBorderStyle style) {
    switch (style) {
        case UITextBorderStyleNone:
            control.borderThickness = [WXThicknessHelper fromUniformLength:0];
            break;

        case UITextBorderStyleLine:
            control.borderThickness = [WXThicknessHelper fromUniformLength:1];
            break;

        case UITextBorderStyleBezel:
            UNIMPLEMENTED_WITH_MSG("UITextBorderStyleBezel not yet supported; treated as no border.");
            // we don't support UITextBorderStyleBezel, treat it as no border
            control.borderThickness = [WXThicknessHelper fromUniformLength:0];
            break;

        case UITextBorderStyleRoundedRect:
            WXFrameworkElement* elem = FindTemplateChild(control, @"BorderElement");

            // if the control template has not been loaded yet, it can return nullptr for borderElement
            if (elem != nullptr) {
                WXCBorder* border = rt_dynamic_cast<WXCBorder>(elem);
                border.cornerRadius = [WXCornerRadiusHelper fromUniformRadius:c_borderCornerRadius];
            }
            break;
    }
}

ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> XamlUtilities::ReturnXamlType(NSString* xamlClassName) {
    static ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider> xamlMetaProvider;

    if (!xamlMetaProvider) {
        auto inspApplicationCurrent = [WXApplication.current comObj];
        inspApplicationCurrent.As(&xamlMetaProvider);
    }

    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> xamlType;
    auto className = Strings::NarrowToWide<HSTRING>(xamlClassName);
    if (xamlMetaProvider) {
        HRESULT hr = xamlMetaProvider->GetXamlTypeByFullName(className.Get(), xamlType.GetAddressOf());
        if (SUCCEEDED(hr) && xamlType.Get() != nullptr) {
            return xamlType;
        }
    }

    return nullptr;
}

UIView* XamlUtilities::GenerateUIKitControlFromXamlType(RTObject* xamlObject) {
    if (xamlObject == nil) {
        return nil;
    }

    UIView* control = nil;

    // TODO: For prototyping, this will suffice but it would be better to consolidate with Xib2Xaml in the long term
    NSDictionary* xamlSupportedControls = @{
            [WXCTextBlock class] : [UILabel class],
            [WXCTextBox class] : [UITextField class],
            [WXCButton class] : [UIButton class],
            [WXCProgressRing class] : [UIActivityIndicatorView class],
            [WXCSlider class] : [UISlider class],
    };

    // Create the UIKit control based on the XAML type and return it to the caller
    for (NSObject* classType in [xamlSupportedControls allKeys]) {
        try {
            WXFrameworkElement* xamlElement = rt_dynamic_cast(classType, xamlObject);
            if (xamlElement != nil) {
                Class controlClass = xamlSupportedControls[classType];
                control = [[controlClass alloc] initWithFrame:CGRectZero xamlElement:xamlElement];
                break;
            }
        } catch (...) {
            // TODO: ARM throws an exception when we try to pass NSException instead of ... - compiler update needed
            continue;
        }
    }

    return control;
}

id XamlUtilities::CreateRtProxy(Class cls, IInspectable* iface) {
    // Oddly, WinRT can hand us back NULL objects from successful function calls. Plumb these through as nil.
    if (!iface) {
        return nil;
    }

    RTObject* ret = [NSAllocateObject(cls, 0, 0) init];
    [ret setComObj:iface];

    return ret;
}

void XamlUtilities::ApplyLineBreakModeOnTextBlock(WXCTextBlock* textBlock, UILineBreakMode mode, int numberOfLines) {
    // wrapping or not on reference platform is ultimatly decided by numberofLines of UILabel
    // e.g., if nubmerOfLines is 1, even though lineBreakMode can be set as UILineBreakModeWordWrap etc, no wrapping is happening.
    if (numberOfLines == 1) {
        textBlock.textWrapping = WXTextWrappingNoWrap;
    } else {
        textBlock.textWrapping = WXTextWrappingWrap;
    }

    switch (mode) {
        case UILineBreakModeWordWrap:
            // when wrapping is allowed, no text trimming is happening
            textBlock.textTrimming = WXTextTrimmingNone;
            break;

        case UILineBreakModeCharacterWrap:
            // GAP: currently textblock don't support UILineBreakModeCharacterWrap
            UNIMPLEMENTED_WITH_MSG("UILineBreakModeCharacterWrap unsupported, using UILineBreakModeWordWrap instead");

            // when wrapping is allowed, no text trimming is happening
            textBlock.textTrimming = WXTextTrimmingNone;
            break;

        case UILineBreakModeClip:
            textBlock.textTrimming = WXTextTrimmingClip;
            break;

        case UILineBreakModeHeadTruncation:
            // GAP: currently textblock don't support UILineBreakModeHeadTruncation
            UNIMPLEMENTED_WITH_MSG("UILineBreakModeHeadTruncation unsupported, using UILineBreakModeTailTruncation instead");
            textBlock.textTrimming = WXTextTrimmingCharacterEllipsis;
            break;

        case UILineBreakModeMiddleTruncation:
            // GAP currently textblock don't support UILineBreakModeMiddleTruncation
            UNIMPLEMENTED_WITH_MSG("UILineBreakModeMiddleTruncation unsupported, using UILineBreakModeTailTruncation instead");
            textBlock.textTrimming = WXTextTrimmingCharacterEllipsis;
            break;

        case UILineBreakModeTailTruncation:
            // this is only truncation supported
            textBlock.textTrimming = WXTextTrimmingCharacterEllipsis;
            break;
    }
}

float XamlUtilities::FindMaxFontSizeToFit(
    CGRect rect, NSString* text, UIFont* font, int numberOfLines, float mininumFontSize, float maximumFontSize) {
    float upperBound = maximumFontSize;
    float lowerBound = mininumFontSize;

    // start searching using current font size
    float curFontSize = [font pointSize];
    StrongId<UIFont> _targetFont = font;

    // Do binary search on maximum font size that fits the bound
    do {
        // Caculating constrains for allowedHeight
        float lineHeight = [_targetFont ascender] - [_targetFont descender];
        float allowedHeight = (numberOfLines == 0) ? rect.size.height : std::min(lineHeight * numberOfLines, rect.size.height);

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
            // Find a fit, update lowerBound and continue the search, don't scale up
            lowerBound = curFontSize;

            if (upperBound - lowerBound <= 1.0f) {
                // Distance between current font size and upper bound is less than 1.0, break out
                break;
            }

            curFontSize = (upperBound + lowerBound) / 2.0f;
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

    return lowerBound;
}
