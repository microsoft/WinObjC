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
#import "CppWinRTHelpers.h"

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
namespace WF = winrt::Windows::Foundation;
namespace WU = winrt::Windows::UI;
namespace WX = winrt::Windows::UI::Xaml;

using namespace XamlUtilities;

// cornerRadius when border style is set to round rectangle
static const int c_borderCornerRadius = 8;
static const wchar_t* TAG = L"XamlUtilities";

WU::Color XamlUtilities::ConvertUIColorToWUColor(UIColor* uiColor) {
    CGFloat r, g, b, a;
    [uiColor getRed:&r green:&g blue:&b alpha:&a];

    WU::Color color;
    color.R = (unsigned char)(r * 255);
    color.G = (unsigned char)(g * 255);
    color.B = (unsigned char)(b * 255);
    color.A = (unsigned char)(a * 255);

    return color;
}

UIColor* XamlUtilities::ConvertWUColorToUIColor(const WU::Color& color) {
    CGFloat r = color.R / 255.0;
    CGFloat g = color.G / 255.0;
    CGFloat b = color.B / 255.0;
    CGFloat a = color.A / 255.0;
    return [UIColor colorWithRed:r green:g blue:b alpha:a];
}

WX::Media::ImageBrush XamlUtilities::ConvertUIImageToWUXMImageBrush(UIImage* image) {
    if (!image) {
        return nullptr;
    }

    WX::Media::ImageBrush imageBrush;
    imageBrush.ImageSource(ConvertUIImageToWUXMIBitmapSource(image));

    return imageBrush;
}

WX::Media::Imaging::BitmapSource XamlUtilities::ConvertUIImageToWUXMIBitmapSource(UIImage* image) {
    if (!image) {
        return nullptr;
    }

    CGImageRef cgImg = [image CGImage];
    Microsoft::WRL::ComPtr<IInspectable> inspectableNode(DisplayTexture::GetBitmapForCGImage(cgImg));
    auto bitmapImageSource = objcwinrt::from_insp<WX::Media::Imaging::BitmapSource>(inspectableNode);

    return bitmapImageSource;
}

WX::TextAlignment XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(UITextAlignment alignment) {
    switch (alignment) {
        case UITextAlignmentLeft:
            return WX::TextAlignment::Left;
            break;

        case UITextAlignmentCenter:
            return WX::TextAlignment::Center;
            break;

        case UITextAlignmentRight:
            return WX::TextAlignment::Right;
            break;
    }

    return WX::TextAlignment::Left;
}

UITextAlignment XamlUtilities::ConvertWXTextAlignmentToUITextAlignment(WX::TextAlignment alignment) {
    switch (alignment) {
        case WX::TextAlignment::Left:
            return UITextAlignmentLeft;
            break;

        case WX::TextAlignment::Center:
            return UITextAlignmentCenter;
            break;

        case WX::TextAlignment::Right:
            return UITextAlignmentRight;
            break;

        default:
            break;
    }

    return UITextAlignmentLeft;
}

WX::Input::InputScopeNameValue XamlUtilities::ConvertKeyboardTypeToInputScopeNameValue(UIKeyboardType keyboardType, BOOL secureTextMode) {
    if (secureTextMode) {
        // passwordBox only supports NumbericPin and Password inputscope
        if (keyboardType == UIKeyboardTypeNumberPad) {
            return WX::Input::InputScopeNameValue::NumericPin;
        } else {
            return WX::Input::InputScopeNameValue::Password;
        }
    } else {
        // normal textmode supports a lot more keyboardType
        switch (keyboardType) {
            case UIKeyboardTypeDefault:
                return WX::Input::InputScopeNameValue::Default;

            case UIKeyboardTypeASCIICapable:
                return WX::Input::InputScopeNameValue::Default;

            case UIKeyboardTypeNumbersAndPunctuation:
                return WX::Input::InputScopeNameValue::Digits;

            case UIKeyboardTypeURL:
                return WX::Input::InputScopeNameValue::Url;

            case UIKeyboardTypeNumberPad:
                return WX::Input::InputScopeNameValue::Digits;

            case UIKeyboardTypePhonePad:
                return WX::Input::InputScopeNameValue::TelephoneNumber;

            case UIKeyboardTypeNamePhonePad:
                return WX::Input::InputScopeNameValue::NameOrPhoneNumber;

            case UIKeyboardTypeEmailAddress:
                return WX::Input::InputScopeNameValue::EmailNameOrAddress;

            case UIKeyboardTypeDecimalPad:
                return WX::Input::InputScopeNameValue::Number;

            case UIKeyboardTypeTwitter:
                return WX::Input::InputScopeNameValue::Default;

            case UIKeyboardTypeWebSearch:
                return WX::Input::InputScopeNameValue::Search;
        }
    }

    return WX::Input::InputScopeNameValue::Default;
}

WX::VerticalAlignment XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(
    UIControlContentVerticalAlignment alignment) {
    WX::VerticalAlignment ret = WX::VerticalAlignment::Top;

    switch (alignment) {
        case UIControlContentVerticalAlignmentCenter:
            ret = WX::VerticalAlignment::Center;
            break;
        case UIControlContentVerticalAlignmentTop:
            ret = WX::VerticalAlignment::Top;
            break;
        case UIControlContentVerticalAlignmentBottom:
            ret = WX::VerticalAlignment::Bottom;
            break;
        case UIControlContentVerticalAlignmentFill:
            ret = WX::VerticalAlignment::Stretch;
            break;
    }

    return ret;
}

WX::FrameworkElement XamlUtilities::FindTemplateChild(const WX::Controls::Control& control, NSString* name) {
    WX::FrameworkElement target = nullptr;
    unsigned int count = WX::Media::VisualTreeHelper::GetChildrenCount(control);
    if (count > 0) {
        auto templateRoot = WX::Media::VisualTreeHelper::GetChild(control, 0).try_as<WX::FrameworkElement>();
        if (templateRoot) {
            target = templateRoot.FindName(objcwinrt::string(name)).try_as<WX::FrameworkElement>();
        }
    }

    return target;
}

NSString* XamlUtilities::NSStringFromPropertyValue(const WF::IInspectable& rtPropertyValue) {
    // BUGBUG:8791977 - WFIPropertyValue is not publicly exposed via projections so we used a workaround
    ComPtr<IInspectable> inspPropVal = objcwinrt::to_insp(rtPropertyValue);
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
void XamlUtilities::SetControlBorderStyle(const WX::Controls::Control& control, UITextBorderStyle style) {
    switch (style) {
        case UITextBorderStyleNone:
            control.BorderThickness(WX::ThicknessHelper::FromUniformLength(0));
            break;

        case UITextBorderStyleLine:
            control.BorderThickness(WX::ThicknessHelper::FromUniformLength(1));
            break;

        case UITextBorderStyleBezel:
            UNIMPLEMENTED_WITH_MSG("UITextBorderStyleBezel not yet supported; treated as no border.");
            // we don't support UITextBorderStyleBezel, treat it as no border
            control.BorderThickness(WX::ThicknessHelper::FromUniformLength(0));
            break;

        case UITextBorderStyleRoundedRect:
            WX::FrameworkElement elem = FindTemplateChild(control, @"BorderElement");

            // if the control template has not been loaded yet, it can return nullptr for borderElement
            if (elem) {
                auto border = elem.as<WX::Controls::Border>();
                border.CornerRadius(WX::CornerRadiusHelper::FromUniformRadius(c_borderCornerRadius));
            }
            break;
    }
}

ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> XamlUtilities::ReturnXamlType(NSString* xamlClassName) {
    static ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider> xamlMetaProvider;

    if (!xamlMetaProvider) {
        auto inspApplicationCurrent = objcwinrt::to_insp(WX::Application::Current());
        (void)inspApplicationCurrent->QueryInterface(IID_PPV_ARGS(&xamlMetaProvider));
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

UIView* XamlUtilities::GenerateUIKitControlFromXamlType(const WF::IInspectable& xamlObject) {
    if (!xamlObject) {
        return nil;
    }

    UIView* control = nil;

    // TODO: For prototyping, this will suffice but it would be better to consolidate with Xib2Xaml in the long term
    std::vector<std::pair<IID, id>> xamlSupportedControls{
        { __uuidof(winrt::ABI::default_interface<winrt::abi<WX::Controls::TextBlock>>), [UILabel class] },
        { __uuidof(winrt::ABI::default_interface<winrt::abi<WX::Controls::TextBox>>), [UITextField class] },
        { __uuidof(winrt::ABI::default_interface<winrt::abi<WX::Controls::Button>>), [UIButton class] },
        { __uuidof(winrt::ABI::default_interface<winrt::abi<WX::Controls::ProgressRing>>), [UIActivityIndicatorView class] },
        { __uuidof(winrt::ABI::default_interface<winrt::abi<WX::Controls::Slider>>), [UISlider class] }
    };

    // Create the UIKit control based on the XAML type and return it to the caller
    for (auto&& xamlControl : xamlSupportedControls) {
        WX::FrameworkElement xamlElement = nullptr;

        if (SUCCEEDED(
                winrt::get_abi(xamlObject)->QueryInterface(xamlControl.first, reinterpret_cast<void**>(winrt::put_abi(xamlElement))))) {
            Class controlClass = xamlControl.second;
            control = [[controlClass alloc] initWithFrame:CGRectZero xamlElement:objcwinrt::to_rtobj(xamlElement)];
            break;
        }
    }

    return control;
}

void XamlUtilities::ApplyLineBreakModeOnTextBlock(const WX::Controls::TextBlock& textBlock, UILineBreakMode mode, int numberOfLines) {
    // wrapping or not on reference platform is ultimatly decided by numberofLines of UILabel
    // e.g., if nubmerOfLines is 1, even though lineBreakMode can be set as UILineBreakModeWordWrap etc, no wrapping is happening.
    if (numberOfLines == 1) {
        textBlock.TextWrapping(WX::TextWrapping::NoWrap);
    } else {
        textBlock.TextWrapping(WX::TextWrapping::Wrap);
    }

    switch (mode) {
        case UILineBreakModeWordWrap:
            // when wrapping is allowed, no text trimming is happening
            textBlock.TextTrimming(WX::TextTrimming::None);
            break;

        case UILineBreakModeCharacterWrap:
            // GAP: currently textblock don't support UILineBreakModeCharacterWrap
            UNIMPLEMENTED_WITH_MSG("UILineBreakModeCharacterWrap unsupported, using UILineBreakModeWordWrap instead");

            // when wrapping is allowed, no text trimming is happening
            textBlock.TextTrimming(WX::TextTrimming::None);
            break;

        case UILineBreakModeClip:
            textBlock.TextTrimming(WX::TextTrimming::Clip);
            break;

        case UILineBreakModeHeadTruncation:
            // GAP: currently textblock don't support UILineBreakModeHeadTruncation
            UNIMPLEMENTED_WITH_MSG("UILineBreakModeHeadTruncation unsupported, using UILineBreakModeTailTruncation instead");
            textBlock.TextTrimming(WX::TextTrimming::CharacterEllipsis);
            break;

        case UILineBreakModeMiddleTruncation:
            // GAP currently textblock don't support UILineBreakModeMiddleTruncation
            UNIMPLEMENTED_WITH_MSG("UILineBreakModeMiddleTruncation unsupported, using UILineBreakModeTailTruncation instead");
            textBlock.TextTrimming(WX::TextTrimming::CharacterEllipsis);
            break;

        case UILineBreakModeTailTruncation:
            // this is only truncation supported
            textBlock.TextTrimming(WX::TextTrimming::CharacterEllipsis);
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
