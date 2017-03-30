// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Display.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::Display {

template <typename H> struct impl_DisplayPropertiesEventHandler : implements<impl_DisplayPropertiesEventHandler<H>, abi<DisplayPropertiesEventHandler>>, H
{
    impl_DisplayPropertiesEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Graphics::Display {

struct WINRT_EBO DisplayInformation :
    Windows::Graphics::Display::IDisplayInformation,
    impl::require<DisplayInformation, Windows::Graphics::Display::IDisplayInformation2, Windows::Graphics::Display::IDisplayInformation3, Windows::Graphics::Display::IDisplayInformation4>
{
    DisplayInformation(std::nullptr_t) noexcept {}
    static Windows::Graphics::Display::DisplayInformation GetForCurrentView();
    static Windows::Graphics::Display::DisplayOrientations AutoRotationPreferences();
    static void AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value);
    static event_token DisplayContentsInvalidated(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler);
    using DisplayContentsInvalidated_revoker = factory_event_revoker<IDisplayInformationStatics>;
    static DisplayContentsInvalidated_revoker DisplayContentsInvalidated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler);
    static void DisplayContentsInvalidated(event_token token);
};

struct [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] DisplayProperties
{
    DisplayProperties() = delete;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static Windows::Graphics::Display::DisplayOrientations CurrentOrientation();
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static Windows::Graphics::Display::DisplayOrientations NativeOrientation();
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static Windows::Graphics::Display::DisplayOrientations AutoRotationPreferences();
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static void AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static event_token OrientationChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    using OrientationChanged_revoker = factory_event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static OrientationChanged_revoker OrientationChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static void OrientationChanged(event_token token);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static Windows::Graphics::Display::ResolutionScale ResolutionScale();
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static float LogicalDpi();
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static event_token LogicalDpiChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    using LogicalDpiChanged_revoker = factory_event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static LogicalDpiChanged_revoker LogicalDpiChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static void LogicalDpiChanged(event_token token);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static bool StereoEnabled();
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static event_token StereoEnabledChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    using StereoEnabledChanged_revoker = factory_event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static StereoEnabledChanged_revoker StereoEnabledChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static void StereoEnabledChanged(event_token token);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> GetColorProfileAsync();
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static event_token ColorProfileChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    using ColorProfileChanged_revoker = factory_event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static ColorProfileChanged_revoker ColorProfileChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static void ColorProfileChanged(event_token token);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static event_token DisplayContentsInvalidated(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    using DisplayContentsInvalidated_revoker = factory_event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static DisplayContentsInvalidated_revoker DisplayContentsInvalidated(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler);
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] static void DisplayContentsInvalidated(event_token token);
};

}

}
