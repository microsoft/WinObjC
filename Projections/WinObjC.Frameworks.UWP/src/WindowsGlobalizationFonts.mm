//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsGlobalizationFonts.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Globalization.Fonts.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGlobalizationFonts.h"
#include "WindowsGlobalizationFonts_priv.h"

@implementation WGFLanguageFont

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)fontFamily {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFont>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontFamily(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUTFontWeight*)fontWeight {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFont>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontWeight(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

- (WUTFontStretch)fontStretch {
    ABI::Windows::UI::Text::FontStretch unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFont>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontStretch(&unmarshalledReturn));
    return (WUTFontStretch)unmarshalledReturn;
}

- (WUTFontStyle)fontStyle {
    ABI::Windows::UI::Text::FontStyle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFont>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontStyle(&unmarshalledReturn));
    return (WUTFontStyle)unmarshalledReturn;
}

- (double)scaleFactor {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFont>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaleFactor(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGFLanguageFontGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFontGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFontGroupFactory> WGFILanguageFontGroupFactory_inst() {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFontGroupFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.Fonts.LanguageFontGroup").Get(),
                                                       &inst));
    return inst;
}

+ (WGFLanguageFontGroup*)makeLanguageFontGroup:(NSString*)languageTag {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFontGroup> unmarshalledReturn;
    auto _comInst = WGFILanguageFontGroupFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateLanguageFontGroup(nsStrToHstr(languageTag).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGFLanguageFontGroup>(unmarshalledReturn.Get()) retain];
}

- (WGFLanguageFont*)uITextFont {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_UITextFont(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)uIHeadingFont {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_UIHeadingFont(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)uITitleFont {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_UITitleFont(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)uICaptionFont {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_UICaptionFont(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)uINotificationHeadingFont {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_UINotificationHeadingFont(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)traditionalDocumentFont {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_TraditionalDocumentFont(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)modernDocumentFont {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModernDocumentFont(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)documentHeadingFont {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentHeadingFont(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)fixedWidthTextFont {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_FixedWidthTextFont(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)documentAlternate1Font {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentAlternate1Font(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

- (WGFLanguageFont*)documentAlternate2Font {
    ComPtr<ABI::Windows::Globalization::Fonts::ILanguageFont> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::Fonts::ILanguageFontGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentAlternate2Font(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGFLanguageFont>(unmarshalledReturn.Get());
}

@end
