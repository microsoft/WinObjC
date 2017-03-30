// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::ClosedCaptioning {

struct IClosedCaptionPropertiesStatics;

}

namespace Windows::Media::ClosedCaptioning {

struct IClosedCaptionPropertiesStatics;
struct ClosedCaptionProperties;

}

namespace Windows::Media::ClosedCaptioning {

template <typename T> struct impl_IClosedCaptionPropertiesStatics;

}

namespace Windows::Media::ClosedCaptioning {

enum class ClosedCaptionColor
{
    Default = 0,
    White = 1,
    Black = 2,
    Red = 3,
    Green = 4,
    Blue = 5,
    Yellow = 6,
    Magenta = 7,
    Cyan = 8,
};

enum class ClosedCaptionEdgeEffect
{
    Default = 0,
    None = 1,
    Raised = 2,
    Depressed = 3,
    Uniform = 4,
    DropShadow = 5,
};

enum class ClosedCaptionOpacity
{
    Default = 0,
    OneHundredPercent = 1,
    SeventyFivePercent = 2,
    TwentyFivePercent = 3,
    ZeroPercent = 4,
};

enum class ClosedCaptionSize
{
    Default = 0,
    FiftyPercent = 1,
    OneHundredPercent = 2,
    OneHundredFiftyPercent = 3,
    TwoHundredPercent = 4,
};

enum class ClosedCaptionStyle
{
    Default = 0,
    MonospacedWithSerifs = 1,
    ProportionalWithSerifs = 2,
    MonospacedWithoutSerifs = 3,
    ProportionalWithoutSerifs = 4,
    Casual = 5,
    Cursive = 6,
    SmallCapitals = 7,
};

}

}
