// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.ClosedCaptioning.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::ClosedCaptioning {

struct ClosedCaptionProperties
{
    ClosedCaptionProperties() = delete;
    static Windows::Media::ClosedCaptioning::ClosedCaptionColor FontColor();
    static Windows::UI::Color ComputedFontColor();
    static Windows::Media::ClosedCaptioning::ClosedCaptionOpacity FontOpacity();
    static Windows::Media::ClosedCaptioning::ClosedCaptionSize FontSize();
    static Windows::Media::ClosedCaptioning::ClosedCaptionStyle FontStyle();
    static Windows::Media::ClosedCaptioning::ClosedCaptionEdgeEffect FontEffect();
    static Windows::Media::ClosedCaptioning::ClosedCaptionColor BackgroundColor();
    static Windows::UI::Color ComputedBackgroundColor();
    static Windows::Media::ClosedCaptioning::ClosedCaptionOpacity BackgroundOpacity();
    static Windows::Media::ClosedCaptioning::ClosedCaptionColor RegionColor();
    static Windows::UI::Color ComputedRegionColor();
    static Windows::Media::ClosedCaptioning::ClosedCaptionOpacity RegionOpacity();
};

}

}
