// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI {

struct WINRT_EBO ColorHelper :
    Windows::UI::IColorHelper
{
    ColorHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Color FromArgb(uint8_t a, uint8_t r, uint8_t g, uint8_t b);
};

struct WINRT_EBO Colors :
    Windows::UI::IColors
{
    Colors(std::nullptr_t) noexcept {}
    static Windows::UI::Color AliceBlue();
    static Windows::UI::Color AntiqueWhite();
    static Windows::UI::Color Aqua();
    static Windows::UI::Color Aquamarine();
    static Windows::UI::Color Azure();
    static Windows::UI::Color Beige();
    static Windows::UI::Color Bisque();
    static Windows::UI::Color Black();
    static Windows::UI::Color BlanchedAlmond();
    static Windows::UI::Color Blue();
    static Windows::UI::Color BlueViolet();
    static Windows::UI::Color Brown();
    static Windows::UI::Color BurlyWood();
    static Windows::UI::Color CadetBlue();
    static Windows::UI::Color Chartreuse();
    static Windows::UI::Color Chocolate();
    static Windows::UI::Color Coral();
    static Windows::UI::Color CornflowerBlue();
    static Windows::UI::Color Cornsilk();
    static Windows::UI::Color Crimson();
    static Windows::UI::Color Cyan();
    static Windows::UI::Color DarkBlue();
    static Windows::UI::Color DarkCyan();
    static Windows::UI::Color DarkGoldenrod();
    static Windows::UI::Color DarkGray();
    static Windows::UI::Color DarkGreen();
    static Windows::UI::Color DarkKhaki();
    static Windows::UI::Color DarkMagenta();
    static Windows::UI::Color DarkOliveGreen();
    static Windows::UI::Color DarkOrange();
    static Windows::UI::Color DarkOrchid();
    static Windows::UI::Color DarkRed();
    static Windows::UI::Color DarkSalmon();
    static Windows::UI::Color DarkSeaGreen();
    static Windows::UI::Color DarkSlateBlue();
    static Windows::UI::Color DarkSlateGray();
    static Windows::UI::Color DarkTurquoise();
    static Windows::UI::Color DarkViolet();
    static Windows::UI::Color DeepPink();
    static Windows::UI::Color DeepSkyBlue();
    static Windows::UI::Color DimGray();
    static Windows::UI::Color DodgerBlue();
    static Windows::UI::Color Firebrick();
    static Windows::UI::Color FloralWhite();
    static Windows::UI::Color ForestGreen();
    static Windows::UI::Color Fuchsia();
    static Windows::UI::Color Gainsboro();
    static Windows::UI::Color GhostWhite();
    static Windows::UI::Color Gold();
    static Windows::UI::Color Goldenrod();
    static Windows::UI::Color Gray();
    static Windows::UI::Color Green();
    static Windows::UI::Color GreenYellow();
    static Windows::UI::Color Honeydew();
    static Windows::UI::Color HotPink();
    static Windows::UI::Color IndianRed();
    static Windows::UI::Color Indigo();
    static Windows::UI::Color Ivory();
    static Windows::UI::Color Khaki();
    static Windows::UI::Color Lavender();
    static Windows::UI::Color LavenderBlush();
    static Windows::UI::Color LawnGreen();
    static Windows::UI::Color LemonChiffon();
    static Windows::UI::Color LightBlue();
    static Windows::UI::Color LightCoral();
    static Windows::UI::Color LightCyan();
    static Windows::UI::Color LightGoldenrodYellow();
    static Windows::UI::Color LightGreen();
    static Windows::UI::Color LightGray();
    static Windows::UI::Color LightPink();
    static Windows::UI::Color LightSalmon();
    static Windows::UI::Color LightSeaGreen();
    static Windows::UI::Color LightSkyBlue();
    static Windows::UI::Color LightSlateGray();
    static Windows::UI::Color LightSteelBlue();
    static Windows::UI::Color LightYellow();
    static Windows::UI::Color Lime();
    static Windows::UI::Color LimeGreen();
    static Windows::UI::Color Linen();
    static Windows::UI::Color Magenta();
    static Windows::UI::Color Maroon();
    static Windows::UI::Color MediumAquamarine();
    static Windows::UI::Color MediumBlue();
    static Windows::UI::Color MediumOrchid();
    static Windows::UI::Color MediumPurple();
    static Windows::UI::Color MediumSeaGreen();
    static Windows::UI::Color MediumSlateBlue();
    static Windows::UI::Color MediumSpringGreen();
    static Windows::UI::Color MediumTurquoise();
    static Windows::UI::Color MediumVioletRed();
    static Windows::UI::Color MidnightBlue();
    static Windows::UI::Color MintCream();
    static Windows::UI::Color MistyRose();
    static Windows::UI::Color Moccasin();
    static Windows::UI::Color NavajoWhite();
    static Windows::UI::Color Navy();
    static Windows::UI::Color OldLace();
    static Windows::UI::Color Olive();
    static Windows::UI::Color OliveDrab();
    static Windows::UI::Color Orange();
    static Windows::UI::Color OrangeRed();
    static Windows::UI::Color Orchid();
    static Windows::UI::Color PaleGoldenrod();
    static Windows::UI::Color PaleGreen();
    static Windows::UI::Color PaleTurquoise();
    static Windows::UI::Color PaleVioletRed();
    static Windows::UI::Color PapayaWhip();
    static Windows::UI::Color PeachPuff();
    static Windows::UI::Color Peru();
    static Windows::UI::Color Pink();
    static Windows::UI::Color Plum();
    static Windows::UI::Color PowderBlue();
    static Windows::UI::Color Purple();
    static Windows::UI::Color Red();
    static Windows::UI::Color RosyBrown();
    static Windows::UI::Color RoyalBlue();
    static Windows::UI::Color SaddleBrown();
    static Windows::UI::Color Salmon();
    static Windows::UI::Color SandyBrown();
    static Windows::UI::Color SeaGreen();
    static Windows::UI::Color SeaShell();
    static Windows::UI::Color Sienna();
    static Windows::UI::Color Silver();
    static Windows::UI::Color SkyBlue();
    static Windows::UI::Color SlateBlue();
    static Windows::UI::Color SlateGray();
    static Windows::UI::Color Snow();
    static Windows::UI::Color SpringGreen();
    static Windows::UI::Color SteelBlue();
    static Windows::UI::Color Tan();
    static Windows::UI::Color Teal();
    static Windows::UI::Color Thistle();
    static Windows::UI::Color Tomato();
    static Windows::UI::Color Transparent();
    static Windows::UI::Color Turquoise();
    static Windows::UI::Color Violet();
    static Windows::UI::Color Wheat();
    static Windows::UI::Color White();
    static Windows::UI::Color WhiteSmoke();
    static Windows::UI::Color Yellow();
    static Windows::UI::Color YellowGreen();
};

}

}
