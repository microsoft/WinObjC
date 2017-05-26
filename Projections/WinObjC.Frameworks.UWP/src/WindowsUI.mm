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

// WindowsUI.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUI.h"
#include "WindowsUI_priv.h"

@implementation WUColorHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::IColorHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::IColorHelperStatics> WUIColorHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::IColorHelperStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ColorHelper").Get(), &inst));
    return inst;
}

+ (WUColor*)fromArgb:(uint8_t)a r:(uint8_t)r g:(uint8_t)g b:(uint8_t)b {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromArgb(a, r, g, b, &unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

@end

@implementation WUColors

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::IColors> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::IColorsStatics> WUIColorsStatics_inst() {
    ComPtr<ABI::Windows::UI::IColorsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Colors").Get(), &inst));
    return inst;
}

+ (WUColor*)aliceBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AliceBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)antiqueWhite {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AntiqueWhite(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)aqua {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Aqua(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)aquamarine {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Aquamarine(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)azure {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Azure(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)beige {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Beige(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)bisque {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bisque(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)black {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Black(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)blanchedAlmond {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BlanchedAlmond(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)blue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Blue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)blueViolet {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BlueViolet(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)brown {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Brown(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)burlyWood {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BurlyWood(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)cadetBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CadetBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)chartreuse {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Chartreuse(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)chocolate {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Chocolate(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)coral {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Coral(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)cornflowerBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CornflowerBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)cornsilk {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Cornsilk(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)crimson {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Crimson(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)cyan {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Cyan(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkCyan {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkCyan(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkGoldenrod {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkGoldenrod(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkGray {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkGray(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkKhaki {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkKhaki(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkMagenta {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkMagenta(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkOliveGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkOliveGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkOrange {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkOrange(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkOrchid {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkOrchid(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkRed {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkRed(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkSalmon {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkSalmon(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkSeaGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkSeaGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkSlateBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkSlateBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkSlateGray {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkSlateGray(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkTurquoise {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkTurquoise(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)darkViolet {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DarkViolet(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)deepPink {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DeepPink(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)deepSkyBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DeepSkyBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)dimGray {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DimGray(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)dodgerBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DodgerBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)firebrick {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Firebrick(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)floralWhite {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FloralWhite(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)forestGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ForestGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)fuchsia {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Fuchsia(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)gainsboro {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gainsboro(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)ghostWhite {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GhostWhite(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)gold {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gold(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)goldenrod {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Goldenrod(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)gray {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gray(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)green {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Green(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)greenYellow {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GreenYellow(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)honeydew {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Honeydew(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)hotPink {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HotPink(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)indianRed {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IndianRed(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)indigo {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Indigo(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)ivory {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ivory(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)khaki {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Khaki(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lavender {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Lavender(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lavenderBlush {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LavenderBlush(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lawnGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LawnGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lemonChiffon {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LemonChiffon(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightCoral {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightCoral(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightCyan {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightCyan(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightGoldenrodYellow {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightGoldenrodYellow(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightGray {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightGray(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightPink {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightPink(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightSalmon {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightSalmon(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightSeaGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightSeaGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightSkyBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightSkyBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightSlateGray {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightSlateGray(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightSteelBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightSteelBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lightYellow {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightYellow(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)lime {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Lime(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)limeGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LimeGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)linen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Linen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)magenta {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Magenta(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)maroon {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Maroon(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mediumAquamarine {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediumAquamarine(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mediumBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediumBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mediumOrchid {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediumOrchid(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mediumPurple {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediumPurple(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mediumSeaGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediumSeaGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mediumSlateBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediumSlateBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mediumSpringGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediumSpringGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mediumTurquoise {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediumTurquoise(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mediumVioletRed {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediumVioletRed(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)midnightBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MidnightBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mintCream {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MintCream(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)mistyRose {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MistyRose(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)moccasin {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Moccasin(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)navajoWhite {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NavajoWhite(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)navy {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Navy(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)oldLace {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OldLace(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)olive {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Olive(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)oliveDrab {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OliveDrab(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)orange {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Orange(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)orangeRed {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OrangeRed(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)orchid {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Orchid(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)paleGoldenrod {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PaleGoldenrod(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)paleGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PaleGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)paleTurquoise {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PaleTurquoise(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)paleVioletRed {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PaleVioletRed(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)papayaWhip {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PapayaWhip(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)peachPuff {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PeachPuff(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)peru {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Peru(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)pink {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pink(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)plum {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Plum(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)powderBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PowderBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)purple {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Purple(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)red {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Red(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)rosyBrown {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RosyBrown(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)royalBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RoyalBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)saddleBrown {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SaddleBrown(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)salmon {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Salmon(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)sandyBrown {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SandyBrown(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)seaGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SeaGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)seaShell {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SeaShell(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)sienna {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sienna(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)silver {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Silver(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)skyBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SkyBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)slateBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SlateBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)slateGray {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SlateGray(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)snow {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Snow(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)springGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SpringGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)steelBlue {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SteelBlue(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)tan {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Tan(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)teal {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Teal(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)thistle {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Thistle(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)tomato {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Tomato(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)transparent {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Transparent(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)turquoise {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Turquoise(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)violet {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Violet(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)wheat {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wheat(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)white {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_White(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)whiteSmoke {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WhiteSmoke(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)yellow {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Yellow(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

+ (WUColor*)yellowGreen {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = WUIColorsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_YellowGreen(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

@end

@implementation WUColor {
    ABI::Windows::UI::Color structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Color)s {
    WUColor* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Color*)internalStruct {
    return &structVal;
}
- (uint8_t)a {
    return structVal.A;
}
- (void)setA:(uint8_t)val {
    structVal.A = val;
}
- (uint8_t)r {
    return structVal.R;
}
- (void)setR:(uint8_t)val {
    structVal.R = val;
}
- (uint8_t)g {
    return structVal.G;
}
- (void)setG:(uint8_t)val {
    structVal.G = val;
}
- (uint8_t)b {
    return structVal.B;
}
- (void)setB:(uint8_t)val {
    structVal.B = val;
}
@end
