// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI {

struct Color
{
    uint8_t A;
    uint8_t R;
    uint8_t G;
    uint8_t B;
};

}

namespace Windows::UI {

using Color = ABI::Windows::UI::Color;

}

namespace ABI::Windows::UI {

struct __declspec(uuid("193cfbe7-65c7-4540-ad08-6283ba76879a")) __declspec(novtable) IColorHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("8504dbea-fb6a-4144-a6c2-33499c9284f5")) __declspec(novtable) IColorHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromArgb(uint8_t a, uint8_t r, uint8_t g, uint8_t b, Windows::UI::Color * returnValue) = 0;
};

struct __declspec(uuid("9b8c9326-4ca6-4ce5-8994-9eff65cabdcc")) __declspec(novtable) IColors : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("cff52e04-cca6-4614-a17e-754910c84a99")) __declspec(novtable) IColorsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AliceBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_AntiqueWhite(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Aqua(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Aquamarine(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Azure(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Beige(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Bisque(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Black(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_BlanchedAlmond(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Blue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_BlueViolet(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Brown(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_BurlyWood(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_CadetBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Chartreuse(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Chocolate(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Coral(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_CornflowerBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Cornsilk(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Crimson(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Cyan(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkCyan(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkGoldenrod(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkGray(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkKhaki(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkMagenta(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkOliveGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkOrange(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkOrchid(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkRed(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkSalmon(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkSeaGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkSlateBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkSlateGray(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkTurquoise(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DarkViolet(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DeepPink(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DeepSkyBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DimGray(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_DodgerBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Firebrick(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_FloralWhite(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_ForestGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Fuchsia(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Gainsboro(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_GhostWhite(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Gold(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Goldenrod(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Gray(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Green(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_GreenYellow(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Honeydew(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_HotPink(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_IndianRed(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Indigo(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Ivory(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Khaki(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Lavender(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LavenderBlush(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LawnGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LemonChiffon(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightCoral(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightCyan(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightGoldenrodYellow(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightGray(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightPink(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightSalmon(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightSeaGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightSkyBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightSlateGray(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightSteelBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LightYellow(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Lime(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_LimeGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Linen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Magenta(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Maroon(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MediumAquamarine(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MediumBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MediumOrchid(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MediumPurple(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MediumSeaGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MediumSlateBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MediumSpringGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MediumTurquoise(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MediumVioletRed(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MidnightBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MintCream(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_MistyRose(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Moccasin(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_NavajoWhite(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Navy(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_OldLace(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Olive(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_OliveDrab(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Orange(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_OrangeRed(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Orchid(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_PaleGoldenrod(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_PaleGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_PaleTurquoise(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_PaleVioletRed(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_PapayaWhip(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_PeachPuff(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Peru(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Pink(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Plum(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_PowderBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Purple(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Red(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_RosyBrown(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_RoyalBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_SaddleBrown(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Salmon(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_SandyBrown(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_SeaGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_SeaShell(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Sienna(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Silver(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_SkyBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_SlateBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_SlateGray(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Snow(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_SpringGreen(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_SteelBlue(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Tan(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Teal(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Thistle(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Tomato(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Transparent(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Turquoise(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Violet(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Wheat(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_White(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_WhiteSmoke(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_Yellow(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_YellowGreen(Windows::UI::Color * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::ColorHelper> { using default_interface = Windows::UI::IColorHelper; };
template <> struct traits<Windows::UI::Colors> { using default_interface = Windows::UI::IColors; };

}

namespace Windows::UI {

template <typename D>
struct WINRT_EBO impl_IColorHelper
{
};

template <typename D>
struct WINRT_EBO impl_IColorHelperStatics
{
    Windows::UI::Color FromArgb(uint8_t a, uint8_t r, uint8_t g, uint8_t b) const;
};

template <typename D>
struct WINRT_EBO impl_IColors
{
};

template <typename D>
struct WINRT_EBO impl_IColorsStatics
{
    Windows::UI::Color AliceBlue() const;
    Windows::UI::Color AntiqueWhite() const;
    Windows::UI::Color Aqua() const;
    Windows::UI::Color Aquamarine() const;
    Windows::UI::Color Azure() const;
    Windows::UI::Color Beige() const;
    Windows::UI::Color Bisque() const;
    Windows::UI::Color Black() const;
    Windows::UI::Color BlanchedAlmond() const;
    Windows::UI::Color Blue() const;
    Windows::UI::Color BlueViolet() const;
    Windows::UI::Color Brown() const;
    Windows::UI::Color BurlyWood() const;
    Windows::UI::Color CadetBlue() const;
    Windows::UI::Color Chartreuse() const;
    Windows::UI::Color Chocolate() const;
    Windows::UI::Color Coral() const;
    Windows::UI::Color CornflowerBlue() const;
    Windows::UI::Color Cornsilk() const;
    Windows::UI::Color Crimson() const;
    Windows::UI::Color Cyan() const;
    Windows::UI::Color DarkBlue() const;
    Windows::UI::Color DarkCyan() const;
    Windows::UI::Color DarkGoldenrod() const;
    Windows::UI::Color DarkGray() const;
    Windows::UI::Color DarkGreen() const;
    Windows::UI::Color DarkKhaki() const;
    Windows::UI::Color DarkMagenta() const;
    Windows::UI::Color DarkOliveGreen() const;
    Windows::UI::Color DarkOrange() const;
    Windows::UI::Color DarkOrchid() const;
    Windows::UI::Color DarkRed() const;
    Windows::UI::Color DarkSalmon() const;
    Windows::UI::Color DarkSeaGreen() const;
    Windows::UI::Color DarkSlateBlue() const;
    Windows::UI::Color DarkSlateGray() const;
    Windows::UI::Color DarkTurquoise() const;
    Windows::UI::Color DarkViolet() const;
    Windows::UI::Color DeepPink() const;
    Windows::UI::Color DeepSkyBlue() const;
    Windows::UI::Color DimGray() const;
    Windows::UI::Color DodgerBlue() const;
    Windows::UI::Color Firebrick() const;
    Windows::UI::Color FloralWhite() const;
    Windows::UI::Color ForestGreen() const;
    Windows::UI::Color Fuchsia() const;
    Windows::UI::Color Gainsboro() const;
    Windows::UI::Color GhostWhite() const;
    Windows::UI::Color Gold() const;
    Windows::UI::Color Goldenrod() const;
    Windows::UI::Color Gray() const;
    Windows::UI::Color Green() const;
    Windows::UI::Color GreenYellow() const;
    Windows::UI::Color Honeydew() const;
    Windows::UI::Color HotPink() const;
    Windows::UI::Color IndianRed() const;
    Windows::UI::Color Indigo() const;
    Windows::UI::Color Ivory() const;
    Windows::UI::Color Khaki() const;
    Windows::UI::Color Lavender() const;
    Windows::UI::Color LavenderBlush() const;
    Windows::UI::Color LawnGreen() const;
    Windows::UI::Color LemonChiffon() const;
    Windows::UI::Color LightBlue() const;
    Windows::UI::Color LightCoral() const;
    Windows::UI::Color LightCyan() const;
    Windows::UI::Color LightGoldenrodYellow() const;
    Windows::UI::Color LightGreen() const;
    Windows::UI::Color LightGray() const;
    Windows::UI::Color LightPink() const;
    Windows::UI::Color LightSalmon() const;
    Windows::UI::Color LightSeaGreen() const;
    Windows::UI::Color LightSkyBlue() const;
    Windows::UI::Color LightSlateGray() const;
    Windows::UI::Color LightSteelBlue() const;
    Windows::UI::Color LightYellow() const;
    Windows::UI::Color Lime() const;
    Windows::UI::Color LimeGreen() const;
    Windows::UI::Color Linen() const;
    Windows::UI::Color Magenta() const;
    Windows::UI::Color Maroon() const;
    Windows::UI::Color MediumAquamarine() const;
    Windows::UI::Color MediumBlue() const;
    Windows::UI::Color MediumOrchid() const;
    Windows::UI::Color MediumPurple() const;
    Windows::UI::Color MediumSeaGreen() const;
    Windows::UI::Color MediumSlateBlue() const;
    Windows::UI::Color MediumSpringGreen() const;
    Windows::UI::Color MediumTurquoise() const;
    Windows::UI::Color MediumVioletRed() const;
    Windows::UI::Color MidnightBlue() const;
    Windows::UI::Color MintCream() const;
    Windows::UI::Color MistyRose() const;
    Windows::UI::Color Moccasin() const;
    Windows::UI::Color NavajoWhite() const;
    Windows::UI::Color Navy() const;
    Windows::UI::Color OldLace() const;
    Windows::UI::Color Olive() const;
    Windows::UI::Color OliveDrab() const;
    Windows::UI::Color Orange() const;
    Windows::UI::Color OrangeRed() const;
    Windows::UI::Color Orchid() const;
    Windows::UI::Color PaleGoldenrod() const;
    Windows::UI::Color PaleGreen() const;
    Windows::UI::Color PaleTurquoise() const;
    Windows::UI::Color PaleVioletRed() const;
    Windows::UI::Color PapayaWhip() const;
    Windows::UI::Color PeachPuff() const;
    Windows::UI::Color Peru() const;
    Windows::UI::Color Pink() const;
    Windows::UI::Color Plum() const;
    Windows::UI::Color PowderBlue() const;
    Windows::UI::Color Purple() const;
    Windows::UI::Color Red() const;
    Windows::UI::Color RosyBrown() const;
    Windows::UI::Color RoyalBlue() const;
    Windows::UI::Color SaddleBrown() const;
    Windows::UI::Color Salmon() const;
    Windows::UI::Color SandyBrown() const;
    Windows::UI::Color SeaGreen() const;
    Windows::UI::Color SeaShell() const;
    Windows::UI::Color Sienna() const;
    Windows::UI::Color Silver() const;
    Windows::UI::Color SkyBlue() const;
    Windows::UI::Color SlateBlue() const;
    Windows::UI::Color SlateGray() const;
    Windows::UI::Color Snow() const;
    Windows::UI::Color SpringGreen() const;
    Windows::UI::Color SteelBlue() const;
    Windows::UI::Color Tan() const;
    Windows::UI::Color Teal() const;
    Windows::UI::Color Thistle() const;
    Windows::UI::Color Tomato() const;
    Windows::UI::Color Transparent() const;
    Windows::UI::Color Turquoise() const;
    Windows::UI::Color Violet() const;
    Windows::UI::Color Wheat() const;
    Windows::UI::Color White() const;
    Windows::UI::Color WhiteSmoke() const;
    Windows::UI::Color Yellow() const;
    Windows::UI::Color YellowGreen() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::IColorHelper>
{
    using abi = ABI::Windows::UI::IColorHelper;
    template <typename D> using consume = Windows::UI::impl_IColorHelper<D>;
};

template <> struct traits<Windows::UI::IColorHelperStatics>
{
    using abi = ABI::Windows::UI::IColorHelperStatics;
    template <typename D> using consume = Windows::UI::impl_IColorHelperStatics<D>;
};

template <> struct traits<Windows::UI::IColors>
{
    using abi = ABI::Windows::UI::IColors;
    template <typename D> using consume = Windows::UI::impl_IColors<D>;
};

template <> struct traits<Windows::UI::IColorsStatics>
{
    using abi = ABI::Windows::UI::IColorsStatics;
    template <typename D> using consume = Windows::UI::impl_IColorsStatics<D>;
};

template <> struct traits<Windows::UI::ColorHelper>
{
    using abi = ABI::Windows::UI::ColorHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ColorHelper"; }
};

template <> struct traits<Windows::UI::Colors>
{
    using abi = ABI::Windows::UI::Colors;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Colors"; }
};

}

}
