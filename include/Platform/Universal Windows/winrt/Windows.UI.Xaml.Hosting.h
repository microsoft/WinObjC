// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.UI.Composition.3.h"
#include "internal/Windows.UI.Xaml.Controls.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.Controls.Primitives.3.h"
#include "internal/Windows.UI.Xaml.Hosting.3.h"
#include "Windows.UI.Xaml.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IElementCompositionPreview> : produce_base<D, Windows::UI::Xaml::Hosting::IElementCompositionPreview>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics> : produce_base<D, Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
{
    HRESULT __stdcall abi_GetElementVisual(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, impl::abi_arg_out<Windows::UI::Composition::IVisual> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetElementVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementChildVisual(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, impl::abi_arg_out<Windows::UI::Composition::IVisual> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetElementChildVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetElementChildVisual(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, impl::abi_arg_in<Windows::UI::Composition::IVisual> visual) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetElementChildVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element), *reinterpret_cast<const Windows::UI::Composition::Visual *>(&visual));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetScrollViewerManipulationPropertySet(impl::abi_arg_in<Windows::UI::Xaml::Controls::IScrollViewer> scrollViewer, impl::abi_arg_out<Windows::UI::Composition::ICompositionPropertySet> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetScrollViewerManipulationPropertySet(*reinterpret_cast<const Windows::UI::Xaml::Controls::ScrollViewer *>(&scrollViewer)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IXamlUIPresenter> : produce_base<D, Windows::UI::Xaml::Hosting::IXamlUIPresenter>
{
    HRESULT __stdcall get_RootElement(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RootElement());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RootElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RootElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThemeKey(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ThemeKey());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ThemeKey(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ThemeKey(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThemeResourcesXaml(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ThemeResourcesXaml());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ThemeResourcesXaml(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ThemeResourcesXaml(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSize(int32_t width, int32_t height) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSize(width, height);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Render() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Render();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Present() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Present();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterHost> : produce_base<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterHost>
{
    HRESULT __stdcall abi_ResolveFileResource(impl::abi_arg_in<hstring> path, impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ResolveFileResource(*reinterpret_cast<const hstring *>(&path)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterHost2> : produce_base<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterHost2>
{
    HRESULT __stdcall abi_GetGenericXamlFilePath(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetGenericXamlFilePath());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterHost3> : produce_base<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterHost3>
{
    HRESULT __stdcall abi_ResolveDictionaryResource(impl::abi_arg_in<Windows::UI::Xaml::IResourceDictionary> dictionary, impl::abi_arg_in<Windows::Foundation::IInspectable> dictionaryKey, impl::abi_arg_in<Windows::Foundation::IInspectable> suggestedValue, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ResolveDictionaryResource(*reinterpret_cast<const Windows::UI::Xaml::ResourceDictionary *>(&dictionary), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&dictionaryKey), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&suggestedValue)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics> : produce_base<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics>
{
    HRESULT __stdcall get_CompleteTimelinesAutomatically(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompleteTimelinesAutomatically());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CompleteTimelinesAutomatically(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompleteTimelinesAutomatically(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetHost(impl::abi_arg_in<Windows::UI::Xaml::Hosting::IXamlUIPresenterHost> host) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetHost(*reinterpret_cast<const Windows::UI::Xaml::Hosting::IXamlUIPresenterHost *>(&host));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NotifyWindowSizeChanged() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyWindowSizeChanged();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics2> : produce_base<D, Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics2>
{
    HRESULT __stdcall abi_GetFlyoutPlacementTargetInfo(impl::abi_arg_in<Windows::UI::Xaml::IFrameworkElement> placementTarget, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode preferredPlacement, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode * targetPreferredPlacement, bool * allowFallbacks, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFlyoutPlacementTargetInfo(*reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&placementTarget), preferredPlacement, *targetPreferredPlacement, *allowFallbacks));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFlyoutPlacement(impl::abi_arg_in<Windows::Foundation::Rect> placementTargetBounds, impl::abi_arg_in<Windows::Foundation::Size> controlSize, impl::abi_arg_in<Windows::Foundation::Size> minControlSize, impl::abi_arg_in<Windows::Foundation::Rect> containerRect, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode targetPreferredPlacement, bool allowFallbacks, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode * chosenPlacement, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFlyoutPlacement(*reinterpret_cast<const Windows::Foundation::Rect *>(&placementTargetBounds), *reinterpret_cast<const Windows::Foundation::Size *>(&controlSize), *reinterpret_cast<const Windows::Foundation::Size *>(&minControlSize), *reinterpret_cast<const Windows::Foundation::Rect *>(&containerRect), targetPreferredPlacement, allowFallbacks, *chosenPlacement));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Hosting {

template <typename D> Windows::UI::Composition::Visual impl_IElementCompositionPreviewStatics<D>::GetElementVisual(const Windows::UI::Xaml::UIElement & element) const
{
    Windows::UI::Composition::Visual result { nullptr };
    check_hresult(WINRT_SHIM(IElementCompositionPreviewStatics)->abi_GetElementVisual(get_abi(element), put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Composition::Visual impl_IElementCompositionPreviewStatics<D>::GetElementChildVisual(const Windows::UI::Xaml::UIElement & element) const
{
    Windows::UI::Composition::Visual result { nullptr };
    check_hresult(WINRT_SHIM(IElementCompositionPreviewStatics)->abi_GetElementChildVisual(get_abi(element), put_abi(result)));
    return result;
}

template <typename D> void impl_IElementCompositionPreviewStatics<D>::SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual) const
{
    check_hresult(WINRT_SHIM(IElementCompositionPreviewStatics)->abi_SetElementChildVisual(get_abi(element), get_abi(visual)));
}

template <typename D> Windows::UI::Composition::CompositionPropertySet impl_IElementCompositionPreviewStatics<D>::GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer) const
{
    Windows::UI::Composition::CompositionPropertySet result { nullptr };
    check_hresult(WINRT_SHIM(IElementCompositionPreviewStatics)->abi_GetScrollViewerManipulationPropertySet(get_abi(scrollViewer), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IXamlUIPresenterHost<D>::ResolveFileResource(hstring_view path) const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IXamlUIPresenterHost)->abi_ResolveFileResource(get_abi(path), put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IXamlUIPresenterHost2<D>::GetGenericXamlFilePath() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IXamlUIPresenterHost2)->abi_GetGenericXamlFilePath(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IXamlUIPresenterHost3<D>::ResolveDictionaryResource(const Windows::UI::Xaml::ResourceDictionary & dictionary, const Windows::Foundation::IInspectable & dictionaryKey, const Windows::Foundation::IInspectable & suggestedValue) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IXamlUIPresenterHost3)->abi_ResolveDictionaryResource(get_abi(dictionary), get_abi(dictionaryKey), get_abi(suggestedValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::UIElement impl_IXamlUIPresenter<D>::RootElement() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IXamlUIPresenter)->get_RootElement(put_abi(value)));
    return value;
}

template <typename D> void impl_IXamlUIPresenter<D>::RootElement(const Windows::UI::Xaml::UIElement & value) const
{
    check_hresult(WINRT_SHIM(IXamlUIPresenter)->put_RootElement(get_abi(value)));
}

template <typename D> hstring impl_IXamlUIPresenter<D>::ThemeKey() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXamlUIPresenter)->get_ThemeKey(put_abi(value)));
    return value;
}

template <typename D> void impl_IXamlUIPresenter<D>::ThemeKey(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IXamlUIPresenter)->put_ThemeKey(get_abi(value)));
}

template <typename D> hstring impl_IXamlUIPresenter<D>::ThemeResourcesXaml() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXamlUIPresenter)->get_ThemeResourcesXaml(put_abi(value)));
    return value;
}

template <typename D> void impl_IXamlUIPresenter<D>::ThemeResourcesXaml(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IXamlUIPresenter)->put_ThemeResourcesXaml(get_abi(value)));
}

template <typename D> void impl_IXamlUIPresenter<D>::SetSize(int32_t width, int32_t height) const
{
    check_hresult(WINRT_SHIM(IXamlUIPresenter)->abi_SetSize(width, height));
}

template <typename D> void impl_IXamlUIPresenter<D>::Render() const
{
    check_hresult(WINRT_SHIM(IXamlUIPresenter)->abi_Render());
}

template <typename D> void impl_IXamlUIPresenter<D>::Present() const
{
    check_hresult(WINRT_SHIM(IXamlUIPresenter)->abi_Present());
}

template <typename D> bool impl_IXamlUIPresenterStatics<D>::CompleteTimelinesAutomatically() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlUIPresenterStatics)->get_CompleteTimelinesAutomatically(&value));
    return value;
}

template <typename D> void impl_IXamlUIPresenterStatics<D>::CompleteTimelinesAutomatically(bool value) const
{
    check_hresult(WINRT_SHIM(IXamlUIPresenterStatics)->put_CompleteTimelinesAutomatically(value));
}

template <typename D> void impl_IXamlUIPresenterStatics<D>::SetHost(const Windows::UI::Xaml::Hosting::IXamlUIPresenterHost & host) const
{
    check_hresult(WINRT_SHIM(IXamlUIPresenterStatics)->abi_SetHost(get_abi(host)));
}

template <typename D> void impl_IXamlUIPresenterStatics<D>::NotifyWindowSizeChanged() const
{
    check_hresult(WINRT_SHIM(IXamlUIPresenterStatics)->abi_NotifyWindowSizeChanged());
}

template <typename D> Windows::Foundation::Rect impl_IXamlUIPresenterStatics2<D>::GetFlyoutPlacementTargetInfo(const Windows::UI::Xaml::FrameworkElement & placementTarget, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode preferredPlacement, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode & targetPreferredPlacement, bool & allowFallbacks) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IXamlUIPresenterStatics2)->abi_GetFlyoutPlacementTargetInfo(get_abi(placementTarget), preferredPlacement, &targetPreferredPlacement, &allowFallbacks, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IXamlUIPresenterStatics2<D>::GetFlyoutPlacement(const Windows::Foundation::Rect & placementTargetBounds, const Windows::Foundation::Size & controlSize, const Windows::Foundation::Size & minControlSize, const Windows::Foundation::Rect & containerRect, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode targetPreferredPlacement, bool allowFallbacks, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode & chosenPlacement) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IXamlUIPresenterStatics2)->abi_GetFlyoutPlacement(get_abi(placementTargetBounds), get_abi(controlSize), get_abi(minControlSize), get_abi(containerRect), targetPreferredPlacement, allowFallbacks, &chosenPlacement, put_abi(returnValue)));
    return returnValue;
}

inline Windows::UI::Composition::Visual ElementCompositionPreview::GetElementVisual(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>().GetElementVisual(element);
}

inline Windows::UI::Composition::Visual ElementCompositionPreview::GetElementChildVisual(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>().GetElementChildVisual(element);
}

inline void ElementCompositionPreview::SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual)
{
    get_activation_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>().SetElementChildVisual(element, visual);
}

inline Windows::UI::Composition::CompositionPropertySet ElementCompositionPreview::GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer)
{
    return get_activation_factory<ElementCompositionPreview, IElementCompositionPreviewStatics>().GetScrollViewerManipulationPropertySet(scrollViewer);
}

inline bool XamlUIPresenter::CompleteTimelinesAutomatically()
{
    return get_activation_factory<XamlUIPresenter, IXamlUIPresenterStatics>().CompleteTimelinesAutomatically();
}

inline void XamlUIPresenter::CompleteTimelinesAutomatically(bool value)
{
    get_activation_factory<XamlUIPresenter, IXamlUIPresenterStatics>().CompleteTimelinesAutomatically(value);
}

inline void XamlUIPresenter::SetHost(const Windows::UI::Xaml::Hosting::IXamlUIPresenterHost & host)
{
    get_activation_factory<XamlUIPresenter, IXamlUIPresenterStatics>().SetHost(host);
}

inline void XamlUIPresenter::NotifyWindowSizeChanged()
{
    get_activation_factory<XamlUIPresenter, IXamlUIPresenterStatics>().NotifyWindowSizeChanged();
}

inline Windows::Foundation::Rect XamlUIPresenter::GetFlyoutPlacementTargetInfo(const Windows::UI::Xaml::FrameworkElement & placementTarget, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode preferredPlacement, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode & targetPreferredPlacement, bool & allowFallbacks)
{
    return get_activation_factory<XamlUIPresenter, IXamlUIPresenterStatics2>().GetFlyoutPlacementTargetInfo(placementTarget, preferredPlacement, targetPreferredPlacement, allowFallbacks);
}

inline Windows::Foundation::Rect XamlUIPresenter::GetFlyoutPlacement(const Windows::Foundation::Rect & placementTargetBounds, const Windows::Foundation::Size & controlSize, const Windows::Foundation::Size & minControlSize, const Windows::Foundation::Rect & containerRect, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode targetPreferredPlacement, bool allowFallbacks, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode & chosenPlacement)
{
    return get_activation_factory<XamlUIPresenter, IXamlUIPresenterStatics2>().GetFlyoutPlacement(placementTargetBounds, controlSize, minControlSize, containerRect, targetPreferredPlacement, allowFallbacks, chosenPlacement);
}

}

}
#pragma warning(pop)
