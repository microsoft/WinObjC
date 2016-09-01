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

#import "XamlUtilities.h"
#import "UIViewInternal+Xaml.h"

// cornerRadius when border style is set to round rectangle
static const int c_borderCornerRadius = 8;
static const wchar_t* TAG = L"XamlUtilities";

WUColor* ConvertUIColorToWUColor(UIColor* uiColor) {
    CGFloat r, g, b, a;
    [uiColor getRed:&r green:&g blue:&b alpha:&a];

    return
        [WUColorHelper fromArgb:(unsigned char)(a * 255) r:(unsigned char)(r * 255) g:(unsigned char)(g * 255) b:(unsigned char)(b * 255)];
}

WXTextAlignment ConvertUITextAlignmentToWXTextAlignment(UITextAlignment alignment) {
    WXTextAlignment ret = UITextAlignmentLeft;
    switch (alignment) {
        case UITextAlignmentLeft:
            ret = WXTextAlignmentLeft;
            break;
        case UITextAlignmentCenter:
            ret = WXTextAlignmentCenter;
            break;
        case UITextAlignmentRight:
            ret = WXTextAlignmentRight;
            break;
    }

    return ret;
}

WUXIInputScope* ConvertKeyboardTypeToInputScope(UIKeyboardType keyboardType, BOOL secureTextMode) {
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

WXVerticalAlignment ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(UIControlContentVerticalAlignment alignment) {
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

WXFrameworkElement* FindTemplateChild(WXCControl* control, NSString* name) {
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

// Setup control border style
void SetControlBorderStyle(WXCControl* control, UITextBorderStyle style) {
    switch (style) {
        case UITextBorderStyleNone:
            control.borderThickness = [WXThicknessHelper fromUniformLength:0];
            break;

        case UITextBorderStyleLine:
            control.borderThickness = [WXThicknessHelper fromUniformLength:1];
            break;

        case UITextBorderStyleBezel:
            UNIMPLEMENTED();
            // we don't support UITextBorderStyleBezel, treat it as no border
            control.borderThickness = [WXThicknessHelper fromUniformLength:0];
            break;

        case UITextBorderStyleRoundedRect:
            [control applyTemplate];
            WXFrameworkElement* elem = FindTemplateChild(control, @"BorderElement");

            // if the control template has not been loaded yet, it can return nullptr for borderElement
            if (elem != nullptr) {
                WXCBorder* border = rt_dynamic_cast<WXCBorder>(elem);
                border.cornerRadius = [WXCornerRadiusHelper fromUniformRadius:c_borderCornerRadius];
            }
            break;
    }
}

ComPtr<Markup::IXamlType> ReturnXamlType(NSString* xamlClassName) {
    static ComPtr<Markup::IXamlMetadataProvider> xamlMetaProvider = nullptr;

    if (!xamlMetaProvider) {
        auto inspApplicationCurrent = [WXApplication.current comObj];
        inspApplicationCurrent.As(&xamlMetaProvider);
    }

    ComPtr<Markup::IXamlType> xamlType = nullptr;
    auto className = Strings::NarrowToWide<HSTRING>(xamlClassName);
    HRESULT hr = xamlMetaProvider->GetXamlTypeByFullName(className.Get(), xamlType.GetAddressOf());
    if (SUCCEEDED(hr) && xamlType.Get() != nullptr) {
        return xamlType;
    }

    return nullptr;
}

UIView* GenerateUIKitControlFromXamlType(RTObject* xamlObject) {
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
                if ([controlClass instancesRespondToSelector:@selector(_initWithFrame:xamlElement:)]) {
                    control = [[controlClass alloc] _initWithFrame:CGRectZero xamlElement:xamlElement];
                }
                break;
            }
        } catch (...) {
            // TODO: ARM throws an exception when we try to pass NSException instead of ... - compiler update needed
            continue;
        }
    }

    return control;
}

id CreateRtProxy(Class cls, IInspectable* iface) {
    // Oddly, WinRT can hand us back NULL objects from successful function calls. Plumb these through as nil.
    if (!iface) {
        return nil;
    }

    RTObject* ret = [NSAllocateObject(cls, 0, 0) init];
    [ret setComObj:iface];

    return ret;
}
