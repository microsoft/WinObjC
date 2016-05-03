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

#include <Starboard.h>
#include "XamlUtilities.h"

// cornerRadius when border style is set to round rectangle
static const int c_borderCornerRadius = 8;

@implementation XamlUtilities

+ (WUColor*)convertUIColorToWUColor:(UIColor*)uiColor {
    CGFloat r, g, b, a;
    [uiColor getRed:&r green:&g blue:&b alpha:&a];
    return
        [WUColorHelper fromArgb:(unsigned char)(a * 255) r:(unsigned char)(r * 255) g:(unsigned char)(g * 255) b:(unsigned char)(b * 255)];
}

+ (WXTextAlignment)convertUITextAlignmentToWXTextAlignment:(UITextAlignment)alignment {
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

+ (WUXIInputScope*)convertKeyboardTypeToInputScope:(UIKeyboardType)keyboardType secureTextMode:(BOOL)secureTextMode {
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

+ (WXFrameworkElement*)findTemplateChild:(WXCControl*)control name:(NSString*)name {
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
+ (void)setControlBorderStyle:(WXCControl*)control borderStyle:(UITextBorderStyle)style {
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
            WXFrameworkElement* elem = [XamlUtilities findTemplateChild:control name:@"BorderElement"];

            // if the control template has not been loaded yet, it can return nullptr for borderElement
            if (elem != nullptr) {
                WXCBorder* border = rt_dynamic_cast<WXCBorder>(elem);
                border.cornerRadius = [WXCornerRadiusHelper fromUniformRadius:c_borderCornerRadius];
            }
            break;
    }
}

@end
