// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.ClosedCaptioning.0.h"
#include "Windows.UI.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::ClosedCaptioning {

struct __declspec(uuid("10aa1f84-cc30-4141-b503-5272289e0c20")) __declspec(novtable) IClosedCaptionPropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FontColor(winrt::Windows::Media::ClosedCaptioning::ClosedCaptionColor * value) = 0;
    virtual HRESULT __stdcall get_ComputedFontColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_FontOpacity(winrt::Windows::Media::ClosedCaptioning::ClosedCaptionOpacity * value) = 0;
    virtual HRESULT __stdcall get_FontSize(winrt::Windows::Media::ClosedCaptioning::ClosedCaptionSize * value) = 0;
    virtual HRESULT __stdcall get_FontStyle(winrt::Windows::Media::ClosedCaptioning::ClosedCaptionStyle * value) = 0;
    virtual HRESULT __stdcall get_FontEffect(winrt::Windows::Media::ClosedCaptioning::ClosedCaptionEdgeEffect * value) = 0;
    virtual HRESULT __stdcall get_BackgroundColor(winrt::Windows::Media::ClosedCaptioning::ClosedCaptionColor * value) = 0;
    virtual HRESULT __stdcall get_ComputedBackgroundColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_BackgroundOpacity(winrt::Windows::Media::ClosedCaptioning::ClosedCaptionOpacity * value) = 0;
    virtual HRESULT __stdcall get_RegionColor(winrt::Windows::Media::ClosedCaptioning::ClosedCaptionColor * value) = 0;
    virtual HRESULT __stdcall get_ComputedRegionColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall get_RegionOpacity(winrt::Windows::Media::ClosedCaptioning::ClosedCaptionOpacity * value) = 0;
};

}

namespace ABI {


}

namespace Windows::Media::ClosedCaptioning {

template <typename D>
struct WINRT_EBO impl_IClosedCaptionPropertiesStatics
{
    Windows::Media::ClosedCaptioning::ClosedCaptionColor FontColor() const;
    Windows::UI::Color ComputedFontColor() const;
    Windows::Media::ClosedCaptioning::ClosedCaptionOpacity FontOpacity() const;
    Windows::Media::ClosedCaptioning::ClosedCaptionSize FontSize() const;
    Windows::Media::ClosedCaptioning::ClosedCaptionStyle FontStyle() const;
    Windows::Media::ClosedCaptioning::ClosedCaptionEdgeEffect FontEffect() const;
    Windows::Media::ClosedCaptioning::ClosedCaptionColor BackgroundColor() const;
    Windows::UI::Color ComputedBackgroundColor() const;
    Windows::Media::ClosedCaptioning::ClosedCaptionOpacity BackgroundOpacity() const;
    Windows::Media::ClosedCaptioning::ClosedCaptionColor RegionColor() const;
    Windows::UI::Color ComputedRegionColor() const;
    Windows::Media::ClosedCaptioning::ClosedCaptionOpacity RegionOpacity() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics>
{
    using abi = ABI::Windows::Media::ClosedCaptioning::IClosedCaptionPropertiesStatics;
    template <typename D> using consume = Windows::Media::ClosedCaptioning::impl_IClosedCaptionPropertiesStatics<D>;
};

template <> struct traits<Windows::Media::ClosedCaptioning::ClosedCaptionProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.ClosedCaptioning.ClosedCaptionProperties"; }
};

}

}
