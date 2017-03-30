// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Graphics.Display.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Display {

struct __declspec(uuid("dbdd8b01-f1a1-46d1-9ee3-543bcc995980")) __declspec(novtable) DisplayPropertiesEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender) = 0;
};

struct __declspec(uuid("bed112ae-adc3-4dc9-ae65-851f4d7d4799")) __declspec(novtable) IDisplayInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentOrientation(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
    virtual HRESULT __stdcall get_NativeOrientation(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
    virtual HRESULT __stdcall add_OrientationChanged(Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_OrientationChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_ResolutionScale(winrt::Windows::Graphics::Display::ResolutionScale * value) = 0;
    virtual HRESULT __stdcall get_LogicalDpi(float * value) = 0;
    virtual HRESULT __stdcall get_RawDpiX(float * value) = 0;
    virtual HRESULT __stdcall get_RawDpiY(float * value) = 0;
    virtual HRESULT __stdcall add_DpiChanged(Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DpiChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_StereoEnabled(bool * value) = 0;
    virtual HRESULT __stdcall add_StereoEnabledChanged(Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StereoEnabledChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetColorProfileAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> ** asyncInfo) = 0;
    virtual HRESULT __stdcall add_ColorProfileChanged(Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ColorProfileChanged(event_token token) = 0;
};

struct __declspec(uuid("4dcd0021-fad1-4b8e-8edf-775887b8bf19")) __declspec(novtable) IDisplayInformation2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RawPixelsPerViewPixel(double * value) = 0;
};

struct __declspec(uuid("db15011d-0f09-4466-8ff3-11de9a3c929a")) __declspec(novtable) IDisplayInformation3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DiagonalSizeInInches(Windows::Foundation::IReference<double> ** value) = 0;
};

struct __declspec(uuid("c972ce2f-1242-46be-b536-e1aafe9e7acf")) __declspec(novtable) IDisplayInformation4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ScreenWidthInRawPixels(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ScreenHeightInRawPixels(uint32_t * value) = 0;
};

struct __declspec(uuid("c6a02a6c-d452-44dc-ba07-96f3c6adf9d1")) __declspec(novtable) IDisplayInformationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::Graphics::Display::IDisplayInformation ** current) = 0;
    virtual HRESULT __stdcall get_AutoRotationPreferences(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
    virtual HRESULT __stdcall put_AutoRotationPreferences(winrt::Windows::Graphics::Display::DisplayOrientations value) = 0;
    virtual HRESULT __stdcall add_DisplayContentsInvalidated(Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DisplayContentsInvalidated(event_token token) = 0;
};

struct __declspec(uuid("6937ed8d-30ea-4ded-8271-4553ff02f68a")) __declspec(novtable) IDisplayPropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentOrientation(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
    virtual HRESULT __stdcall get_NativeOrientation(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
    virtual HRESULT __stdcall get_AutoRotationPreferences(winrt::Windows::Graphics::Display::DisplayOrientations * value) = 0;
    virtual HRESULT __stdcall put_AutoRotationPreferences(winrt::Windows::Graphics::Display::DisplayOrientations value) = 0;
    virtual HRESULT __stdcall add_OrientationChanged(Windows::Graphics::Display::DisplayPropertiesEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_OrientationChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_ResolutionScale(winrt::Windows::Graphics::Display::ResolutionScale * value) = 0;
    virtual HRESULT __stdcall get_LogicalDpi(float * value) = 0;
    virtual HRESULT __stdcall add_LogicalDpiChanged(Windows::Graphics::Display::DisplayPropertiesEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LogicalDpiChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_StereoEnabled(bool * value) = 0;
    virtual HRESULT __stdcall add_StereoEnabledChanged(Windows::Graphics::Display::DisplayPropertiesEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StereoEnabledChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetColorProfileAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> ** asyncInfo) = 0;
    virtual HRESULT __stdcall add_ColorProfileChanged(Windows::Graphics::Display::DisplayPropertiesEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ColorProfileChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_DisplayContentsInvalidated(Windows::Graphics::Display::DisplayPropertiesEventHandler * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DisplayContentsInvalidated(event_token token) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Graphics::Display::DisplayInformation> { using default_interface = Windows::Graphics::Display::IDisplayInformation; };

}

namespace Windows::Graphics::Display {

template <typename D>
struct WINRT_EBO impl_IDisplayInformation
{
    Windows::Graphics::Display::DisplayOrientations CurrentOrientation() const;
    Windows::Graphics::Display::DisplayOrientations NativeOrientation() const;
    event_token OrientationChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    using OrientationChanged_revoker = event_revoker<IDisplayInformation>;
    OrientationChanged_revoker OrientationChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    void OrientationChanged(event_token token) const;
    Windows::Graphics::Display::ResolutionScale ResolutionScale() const;
    float LogicalDpi() const;
    float RawDpiX() const;
    float RawDpiY() const;
    event_token DpiChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    using DpiChanged_revoker = event_revoker<IDisplayInformation>;
    DpiChanged_revoker DpiChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    void DpiChanged(event_token token) const;
    bool StereoEnabled() const;
    event_token StereoEnabledChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    using StereoEnabledChanged_revoker = event_revoker<IDisplayInformation>;
    StereoEnabledChanged_revoker StereoEnabledChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    void StereoEnabledChanged(event_token token) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> GetColorProfileAsync() const;
    event_token ColorProfileChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    using ColorProfileChanged_revoker = event_revoker<IDisplayInformation>;
    ColorProfileChanged_revoker ColorProfileChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    void ColorProfileChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IDisplayInformation2
{
    double RawPixelsPerViewPixel() const;
};

template <typename D>
struct WINRT_EBO impl_IDisplayInformation3
{
    Windows::Foundation::IReference<double> DiagonalSizeInInches() const;
};

template <typename D>
struct WINRT_EBO impl_IDisplayInformation4
{
    uint32_t ScreenWidthInRawPixels() const;
    uint32_t ScreenHeightInRawPixels() const;
};

template <typename D>
struct WINRT_EBO impl_IDisplayInformationStatics
{
    Windows::Graphics::Display::DisplayInformation GetForCurrentView() const;
    Windows::Graphics::Display::DisplayOrientations AutoRotationPreferences() const;
    void AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value) const;
    event_token DisplayContentsInvalidated(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    using DisplayContentsInvalidated_revoker = event_revoker<IDisplayInformationStatics>;
    DisplayContentsInvalidated_revoker DisplayContentsInvalidated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Display::DisplayInformation, Windows::Foundation::IInspectable> & handler) const;
    void DisplayContentsInvalidated(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IDisplayPropertiesStatics
{
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] Windows::Graphics::Display::DisplayOrientations CurrentOrientation() const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] Windows::Graphics::Display::DisplayOrientations NativeOrientation() const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] Windows::Graphics::Display::DisplayOrientations AutoRotationPreferences() const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] void AutoRotationPreferences(Windows::Graphics::Display::DisplayOrientations value) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] event_token OrientationChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    using OrientationChanged_revoker = event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] OrientationChanged_revoker OrientationChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] void OrientationChanged(event_token token) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] Windows::Graphics::Display::ResolutionScale ResolutionScale() const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] float LogicalDpi() const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] event_token LogicalDpiChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    using LogicalDpiChanged_revoker = event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] LogicalDpiChanged_revoker LogicalDpiChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] void LogicalDpiChanged(event_token token) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] bool StereoEnabled() const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] event_token StereoEnabledChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    using StereoEnabledChanged_revoker = event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] StereoEnabledChanged_revoker StereoEnabledChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] void StereoEnabledChanged(event_token token) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> GetColorProfileAsync() const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] event_token ColorProfileChanged(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    using ColorProfileChanged_revoker = event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] ColorProfileChanged_revoker ColorProfileChanged(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] void ColorProfileChanged(event_token token) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] event_token DisplayContentsInvalidated(const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    using DisplayContentsInvalidated_revoker = event_revoker<IDisplayPropertiesStatics>;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] DisplayContentsInvalidated_revoker DisplayContentsInvalidated(auto_revoke_t, const Windows::Graphics::Display::DisplayPropertiesEventHandler & handler) const;
    [[deprecated("DisplayProperties may be altered or unavailable for releases after Windows Phone 8.1. Instead, use DisplayInformation.")]] void DisplayContentsInvalidated(event_token token) const;
};

}

namespace impl {

template <> struct traits<Windows::Graphics::Display::DisplayPropertiesEventHandler>
{
    using abi = ABI::Windows::Graphics::Display::DisplayPropertiesEventHandler;
};

template <> struct traits<Windows::Graphics::Display::IDisplayInformation>
{
    using abi = ABI::Windows::Graphics::Display::IDisplayInformation;
    template <typename D> using consume = Windows::Graphics::Display::impl_IDisplayInformation<D>;
};

template <> struct traits<Windows::Graphics::Display::IDisplayInformation2>
{
    using abi = ABI::Windows::Graphics::Display::IDisplayInformation2;
    template <typename D> using consume = Windows::Graphics::Display::impl_IDisplayInformation2<D>;
};

template <> struct traits<Windows::Graphics::Display::IDisplayInformation3>
{
    using abi = ABI::Windows::Graphics::Display::IDisplayInformation3;
    template <typename D> using consume = Windows::Graphics::Display::impl_IDisplayInformation3<D>;
};

template <> struct traits<Windows::Graphics::Display::IDisplayInformation4>
{
    using abi = ABI::Windows::Graphics::Display::IDisplayInformation4;
    template <typename D> using consume = Windows::Graphics::Display::impl_IDisplayInformation4<D>;
};

template <> struct traits<Windows::Graphics::Display::IDisplayInformationStatics>
{
    using abi = ABI::Windows::Graphics::Display::IDisplayInformationStatics;
    template <typename D> using consume = Windows::Graphics::Display::impl_IDisplayInformationStatics<D>;
};

template <> struct traits<Windows::Graphics::Display::IDisplayPropertiesStatics>
{
    using abi = ABI::Windows::Graphics::Display::IDisplayPropertiesStatics;
    template <typename D> using consume = Windows::Graphics::Display::impl_IDisplayPropertiesStatics<D>;
};

template <> struct traits<Windows::Graphics::Display::DisplayInformation>
{
    using abi = ABI::Windows::Graphics::Display::DisplayInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Display.DisplayInformation"; }
};

template <> struct traits<Windows::Graphics::Display::DisplayProperties>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Display.DisplayProperties"; }
};

}

}
