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

// WindowsMediaClosedCaptioning.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.ClosedCaptioning.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaClosedCaptioning.h"
#include "WindowsMediaClosedCaptioning_priv.h"

@implementation WMCClosedCaptionProperties

ComPtr<ABI::Windows::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics> WMCIClosedCaptionPropertiesStatics_inst() {
    ComPtr<ABI::Windows::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.ClosedCaptioning.ClosedCaptionProperties").Get(), &inst));
    return inst;
}

+ (WMCClosedCaptionColor)fontColor {
    ABI::Windows::Media::ClosedCaptioning::ClosedCaptionColor unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontColor(&unmarshalledReturn));
    return (WMCClosedCaptionColor)unmarshalledReturn;
}

+ (WUColor*)computedFontColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ComputedFontColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WMCClosedCaptionOpacity)fontOpacity {
    ABI::Windows::Media::ClosedCaptioning::ClosedCaptionOpacity unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontOpacity(&unmarshalledReturn));
    return (WMCClosedCaptionOpacity)unmarshalledReturn;
}

+ (WMCClosedCaptionSize)fontSize {
    ABI::Windows::Media::ClosedCaptioning::ClosedCaptionSize unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontSize(&unmarshalledReturn));
    return (WMCClosedCaptionSize)unmarshalledReturn;
}

+ (WMCClosedCaptionStyle)fontStyle {
    ABI::Windows::Media::ClosedCaptioning::ClosedCaptionStyle unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontStyle(&unmarshalledReturn));
    return (WMCClosedCaptionStyle)unmarshalledReturn;
}

+ (WMCClosedCaptionEdgeEffect)fontEffect {
    ABI::Windows::Media::ClosedCaptioning::ClosedCaptionEdgeEffect unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontEffect(&unmarshalledReturn));
    return (WMCClosedCaptionEdgeEffect)unmarshalledReturn;
}

+ (WMCClosedCaptionColor)backgroundColor {
    ABI::Windows::Media::ClosedCaptioning::ClosedCaptionColor unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return (WMCClosedCaptionColor)unmarshalledReturn;
}

+ (WUColor*)computedBackgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ComputedBackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WMCClosedCaptionOpacity)backgroundOpacity {
    ABI::Windows::Media::ClosedCaptioning::ClosedCaptionOpacity unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BackgroundOpacity(&unmarshalledReturn));
    return (WMCClosedCaptionOpacity)unmarshalledReturn;
}

+ (WMCClosedCaptionColor)regionColor {
    ABI::Windows::Media::ClosedCaptioning::ClosedCaptionColor unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RegionColor(&unmarshalledReturn));
    return (WMCClosedCaptionColor)unmarshalledReturn;
}

+ (WUColor*)computedRegionColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ComputedRegionColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WMCClosedCaptionOpacity)regionOpacity {
    ABI::Windows::Media::ClosedCaptioning::ClosedCaptionOpacity unmarshalledReturn;
    auto _comInst = WMCIClosedCaptionPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RegionOpacity(&unmarshalledReturn));
    return (WMCClosedCaptionOpacity)unmarshalledReturn;
}

@end
