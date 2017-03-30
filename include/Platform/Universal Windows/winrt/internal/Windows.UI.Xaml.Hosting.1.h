// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Hosting.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.Composition.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Controls.0.h"
#include "Windows.UI.Xaml.Controls.Primitives.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Hosting {

struct __declspec(uuid("b6f1a676-cfe6-46ac-acf6-c4687bb65e60")) __declspec(novtable) IElementCompositionPreview : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("08c92b38-ec99-4c55-bc85-a1c180b27646")) __declspec(novtable) IElementCompositionPreviewStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetElementVisual(Windows::UI::Xaml::IUIElement * element, Windows::UI::Composition::IVisual ** result) = 0;
    virtual HRESULT __stdcall abi_GetElementChildVisual(Windows::UI::Xaml::IUIElement * element, Windows::UI::Composition::IVisual ** result) = 0;
    virtual HRESULT __stdcall abi_SetElementChildVisual(Windows::UI::Xaml::IUIElement * element, Windows::UI::Composition::IVisual * visual) = 0;
    virtual HRESULT __stdcall abi_GetScrollViewerManipulationPropertySet(Windows::UI::Xaml::Controls::IScrollViewer * scrollViewer, Windows::UI::Composition::ICompositionPropertySet ** result) = 0;
};

struct __declspec(uuid("a714944a-1619-4fc6-b31b-89512ef022a2")) __declspec(novtable) IXamlUIPresenter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RootElement(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_RootElement(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_ThemeKey(hstring * value) = 0;
    virtual HRESULT __stdcall put_ThemeKey(hstring value) = 0;
    virtual HRESULT __stdcall get_ThemeResourcesXaml(hstring * value) = 0;
    virtual HRESULT __stdcall put_ThemeResourcesXaml(hstring value) = 0;
    virtual HRESULT __stdcall abi_SetSize(int32_t width, int32_t height) = 0;
    virtual HRESULT __stdcall abi_Render() = 0;
    virtual HRESULT __stdcall abi_Present() = 0;
};

struct __declspec(uuid("aafb84cd-9f6d-4f80-ac2c-0e6cb9f31659")) __declspec(novtable) IXamlUIPresenterHost : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ResolveFileResource(hstring path, hstring * returnValue) = 0;
};

struct __declspec(uuid("61595672-7ca4-4a21-b56a-88f4812388ca")) __declspec(novtable) IXamlUIPresenterHost2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetGenericXamlFilePath(hstring * returnValue) = 0;
};

struct __declspec(uuid("b14292bf-7320-41bb-9f26-4d6fd34db45a")) __declspec(novtable) IXamlUIPresenterHost3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ResolveDictionaryResource(Windows::UI::Xaml::IResourceDictionary * dictionary, Windows::Foundation::IInspectable * dictionaryKey, Windows::Foundation::IInspectable * suggestedValue, Windows::Foundation::IInspectable ** returnValue) = 0;
};

struct __declspec(uuid("71eaeac8-45e1-4192-85aa-3a422edd23cf")) __declspec(novtable) IXamlUIPresenterStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CompleteTimelinesAutomatically(bool * value) = 0;
    virtual HRESULT __stdcall put_CompleteTimelinesAutomatically(bool value) = 0;
    virtual HRESULT __stdcall abi_SetHost(Windows::UI::Xaml::Hosting::IXamlUIPresenterHost * host) = 0;
    virtual HRESULT __stdcall abi_NotifyWindowSizeChanged() = 0;
};

struct __declspec(uuid("5c6b68d2-cf1c-4f53-bf09-6a745f7a9703")) __declspec(novtable) IXamlUIPresenterStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetFlyoutPlacementTargetInfo(Windows::UI::Xaml::IFrameworkElement * placementTarget, winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode preferredPlacement, winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode * targetPreferredPlacement, bool * allowFallbacks, Windows::Foundation::Rect * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetFlyoutPlacement(Windows::Foundation::Rect placementTargetBounds, Windows::Foundation::Size controlSize, Windows::Foundation::Size minControlSize, Windows::Foundation::Rect containerRect, winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode targetPreferredPlacement, bool allowFallbacks, winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode * chosenPlacement, Windows::Foundation::Rect * returnValue) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Hosting::ElementCompositionPreview> { using default_interface = Windows::UI::Xaml::Hosting::IElementCompositionPreview; };
template <> struct traits<Windows::UI::Xaml::Hosting::XamlUIPresenter> { using default_interface = Windows::UI::Xaml::Hosting::IXamlUIPresenter; };

}

namespace Windows::UI::Xaml::Hosting {

template <typename D>
struct WINRT_EBO impl_IElementCompositionPreview
{
};

template <typename D>
struct WINRT_EBO impl_IElementCompositionPreviewStatics
{
    Windows::UI::Composition::Visual GetElementVisual(const Windows::UI::Xaml::UIElement & element) const;
    Windows::UI::Composition::Visual GetElementChildVisual(const Windows::UI::Xaml::UIElement & element) const;
    void SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual) const;
    Windows::UI::Composition::CompositionPropertySet GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlUIPresenter
{
    Windows::UI::Xaml::UIElement RootElement() const;
    void RootElement(const Windows::UI::Xaml::UIElement & value) const;
    hstring ThemeKey() const;
    void ThemeKey(hstring_view value) const;
    hstring ThemeResourcesXaml() const;
    void ThemeResourcesXaml(hstring_view value) const;
    void SetSize(int32_t width, int32_t height) const;
    void Render() const;
    void Present() const;
};

template <typename D>
struct WINRT_EBO impl_IXamlUIPresenterHost
{
    hstring ResolveFileResource(hstring_view path) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlUIPresenterHost2
{
    hstring GetGenericXamlFilePath() const;
};

template <typename D>
struct WINRT_EBO impl_IXamlUIPresenterHost3
{
    Windows::Foundation::IInspectable ResolveDictionaryResource(const Windows::UI::Xaml::ResourceDictionary & dictionary, const Windows::Foundation::IInspectable & dictionaryKey, const Windows::Foundation::IInspectable & suggestedValue) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlUIPresenterStatics
{
    bool CompleteTimelinesAutomatically() const;
    void CompleteTimelinesAutomatically(bool value) const;
    void SetHost(const Windows::UI::Xaml::Hosting::IXamlUIPresenterHost & host) const;
    void NotifyWindowSizeChanged() const;
};

template <typename D>
struct WINRT_EBO impl_IXamlUIPresenterStatics2
{
    Windows::Foundation::Rect GetFlyoutPlacementTargetInfo(const Windows::UI::Xaml::FrameworkElement & placementTarget, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode preferredPlacement, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode & targetPreferredPlacement, bool & allowFallbacks) const;
    Windows::Foundation::Rect GetFlyoutPlacement(const Windows::Foundation::Rect & placementTargetBounds, const Windows::Foundation::Size & controlSize, const Windows::Foundation::Size & minControlSize, const Windows::Foundation::Rect & containerRect, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode targetPreferredPlacement, bool allowFallbacks, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode & chosenPlacement) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Hosting::IElementCompositionPreview>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IElementCompositionPreview;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IElementCompositionPreview<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IElementCompositionPreviewStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::IXamlUIPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IXamlUIPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::IXamlUIPresenterHost>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IXamlUIPresenterHost<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::IXamlUIPresenterHost2>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost2;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IXamlUIPresenterHost2<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::IXamlUIPresenterHost3>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost3;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IXamlUIPresenterHost3<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IXamlUIPresenterStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Hosting::impl_IXamlUIPresenterStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Hosting::ElementCompositionPreview>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::ElementCompositionPreview;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Hosting.ElementCompositionPreview"; }
};

template <> struct traits<Windows::UI::Xaml::Hosting::XamlUIPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Hosting::XamlUIPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Hosting.XamlUIPresenter"; }
};

}

}
