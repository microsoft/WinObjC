// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Controls {

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides>
class IAppBarOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAppBarOverrides = winrt::Windows::UI::Xaml::Controls::IAppBarOverrides;

    void OnClosed(const Windows::Foundation::IInspectable & e)
    {
        shim().as<IAppBarOverrides>().OnClosed(e);
    }

    void OnOpened(const Windows::Foundation::IInspectable & e)
    {
        shim().as<IAppBarOverrides>().OnOpened(e);
    }

    HRESULT __stdcall abi_OnClosed(impl::abi_arg_in<Windows::Foundation::IInspectable> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnClosed(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnOpened(impl::abi_arg_in<Windows::Foundation::IInspectable> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnOpened(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides3>
class IAppBarOverrides3T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAppBarOverrides3 = winrt::Windows::UI::Xaml::Controls::IAppBarOverrides3;

    void OnClosing(const Windows::Foundation::IInspectable & e)
    {
        shim().as<IAppBarOverrides3>().OnClosing(e);
    }

    void OnOpening(const Windows::Foundation::IInspectable & e)
    {
        shim().as<IAppBarOverrides3>().OnOpening(e);
    }

    HRESULT __stdcall abi_OnClosing(impl::abi_arg_in<Windows::Foundation::IInspectable> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnClosing(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnOpening(impl::abi_arg_in<Windows::Foundation::IInspectable> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnOpening(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IComboBoxOverrides>
class IComboBoxOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IComboBoxOverrides = winrt::Windows::UI::Xaml::Controls::IComboBoxOverrides;

    void OnDropDownClosed(const Windows::Foundation::IInspectable & e)
    {
        shim().as<IComboBoxOverrides>().OnDropDownClosed(e);
    }

    void OnDropDownOpened(const Windows::Foundation::IInspectable & e)
    {
        shim().as<IComboBoxOverrides>().OnDropDownOpened(e);
    }

    HRESULT __stdcall abi_OnDropDownClosed(impl::abi_arg_in<Windows::Foundation::IInspectable> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDropDownClosed(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDropDownOpened(impl::abi_arg_in<Windows::Foundation::IInspectable> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDropDownOpened(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IContentControlOverrides>
class IContentControlOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IContentControlOverrides = winrt::Windows::UI::Xaml::Controls::IContentControlOverrides;

    void OnContentChanged(const Windows::Foundation::IInspectable & oldContent, const Windows::Foundation::IInspectable & newContent)
    {
        shim().as<IContentControlOverrides>().OnContentChanged(oldContent, newContent);
    }

    void OnContentTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldContentTemplate, const Windows::UI::Xaml::DataTemplate & newContentTemplate)
    {
        shim().as<IContentControlOverrides>().OnContentTemplateChanged(oldContentTemplate, newContentTemplate);
    }

    void OnContentTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldContentTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newContentTemplateSelector)
    {
        shim().as<IContentControlOverrides>().OnContentTemplateSelectorChanged(oldContentTemplateSelector, newContentTemplateSelector);
    }

    HRESULT __stdcall abi_OnContentChanged(impl::abi_arg_in<Windows::Foundation::IInspectable> oldContent, impl::abi_arg_in<Windows::Foundation::IInspectable> newContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnContentChanged(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&newContent));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnContentTemplateChanged(impl::abi_arg_in<Windows::UI::Xaml::IDataTemplate> oldContentTemplate, impl::abi_arg_in<Windows::UI::Xaml::IDataTemplate> newContentTemplate) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnContentTemplateChanged(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&oldContentTemplate), *reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&newContentTemplate));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnContentTemplateSelectorChanged(impl::abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> oldContentTemplateSelector, impl::abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> newContentTemplateSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnContentTemplateSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&oldContentTemplateSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&newContentTemplateSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IContentPresenterOverrides>
class IContentPresenterOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IContentPresenterOverrides = winrt::Windows::UI::Xaml::Controls::IContentPresenterOverrides;

    void OnContentTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldContentTemplate, const Windows::UI::Xaml::DataTemplate & newContentTemplate)
    {
        shim().as<IContentPresenterOverrides>().OnContentTemplateChanged(oldContentTemplate, newContentTemplate);
    }

    void OnContentTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldContentTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newContentTemplateSelector)
    {
        shim().as<IContentPresenterOverrides>().OnContentTemplateSelectorChanged(oldContentTemplateSelector, newContentTemplateSelector);
    }

    HRESULT __stdcall abi_OnContentTemplateChanged(impl::abi_arg_in<Windows::UI::Xaml::IDataTemplate> oldContentTemplate, impl::abi_arg_in<Windows::UI::Xaml::IDataTemplate> newContentTemplate) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnContentTemplateChanged(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&oldContentTemplate), *reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&newContentTemplate));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnContentTemplateSelectorChanged(impl::abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> oldContentTemplateSelector, impl::abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> newContentTemplateSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnContentTemplateSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&oldContentTemplateSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&newContentTemplateSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IControlOverrides>
class IControlOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IControlOverrides = winrt::Windows::UI::Xaml::Controls::IControlOverrides;

    void OnPointerEntered(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerEntered(e);
    }

    void OnPointerPressed(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerPressed(e);
    }

    void OnPointerMoved(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerMoved(e);
    }

    void OnPointerReleased(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerReleased(e);
    }

    void OnPointerExited(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerExited(e);
    }

    void OnPointerCaptureLost(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerCaptureLost(e);
    }

    void OnPointerCanceled(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerCanceled(e);
    }

    void OnPointerWheelChanged(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnPointerWheelChanged(e);
    }

    void OnTapped(const Windows::UI::Xaml::Input::TappedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnTapped(e);
    }

    void OnDoubleTapped(const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDoubleTapped(e);
    }

    void OnHolding(const Windows::UI::Xaml::Input::HoldingRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnHolding(e);
    }

    void OnRightTapped(const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnRightTapped(e);
    }

    void OnManipulationStarting(const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationStarting(e);
    }

    void OnManipulationInertiaStarting(const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationInertiaStarting(e);
    }

    void OnManipulationStarted(const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationStarted(e);
    }

    void OnManipulationDelta(const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationDelta(e);
    }

    void OnManipulationCompleted(const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnManipulationCompleted(e);
    }

    void OnKeyUp(const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnKeyUp(e);
    }

    void OnKeyDown(const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnKeyDown(e);
    }

    void OnGotFocus(const Windows::UI::Xaml::RoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnGotFocus(e);
    }

    void OnLostFocus(const Windows::UI::Xaml::RoutedEventArgs & e)
    {
        shim().as<IControlOverrides>().OnLostFocus(e);
    }

    void OnDragEnter(const Windows::UI::Xaml::DragEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDragEnter(e);
    }

    void OnDragLeave(const Windows::UI::Xaml::DragEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDragLeave(e);
    }

    void OnDragOver(const Windows::UI::Xaml::DragEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDragOver(e);
    }

    void OnDrop(const Windows::UI::Xaml::DragEventArgs & e)
    {
        shim().as<IControlOverrides>().OnDrop(e);
    }

    HRESULT __stdcall abi_OnPointerEntered(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnPointerEntered(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerPressed(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnPointerPressed(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerMoved(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnPointerMoved(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerReleased(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnPointerReleased(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerExited(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnPointerExited(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerCaptureLost(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnPointerCaptureLost(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerCanceled(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnPointerCanceled(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnPointerWheelChanged(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnPointerWheelChanged(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnTapped(impl::abi_arg_in<Windows::UI::Xaml::Input::ITappedRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::TappedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDoubleTapped(impl::abi_arg_in<Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDoubleTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnHolding(impl::abi_arg_in<Windows::UI::Xaml::Input::IHoldingRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnHolding(*reinterpret_cast<const Windows::UI::Xaml::Input::HoldingRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnRightTapped(impl::abi_arg_in<Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnRightTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationStarting(impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnManipulationStarting(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationInertiaStarting(impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnManipulationInertiaStarting(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationStarted(impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnManipulationStarted(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationDelta(impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnManipulationDelta(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnManipulationCompleted(impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnManipulationCompleted(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnKeyUp(impl::abi_arg_in<Windows::UI::Xaml::Input::IKeyRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnKeyUp(*reinterpret_cast<const Windows::UI::Xaml::Input::KeyRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnKeyDown(impl::abi_arg_in<Windows::UI::Xaml::Input::IKeyRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnKeyDown(*reinterpret_cast<const Windows::UI::Xaml::Input::KeyRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnGotFocus(impl::abi_arg_in<Windows::UI::Xaml::IRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnGotFocus(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnLostFocus(impl::abi_arg_in<Windows::UI::Xaml::IRoutedEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnLostFocus(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDragEnter(impl::abi_arg_in<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDragEnter(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDragLeave(impl::abi_arg_in<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDragLeave(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDragOver(impl::abi_arg_in<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDragOver(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDrop(impl::abi_arg_in<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDrop(*reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides>
class IDataTemplateSelectorOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IDataTemplateSelectorOverrides = winrt::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides;

    Windows::UI::Xaml::DataTemplate SelectTemplateCore(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container)
    {
        return shim().as<IDataTemplateSelectorOverrides>().SelectTemplateCore(item, container);
    }

    HRESULT __stdcall abi_SelectTemplateCore(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> container, impl::abi_arg_out<Windows::UI::Xaml::IDataTemplate> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().SelectTemplateCore(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&container)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2>
class IDataTemplateSelectorOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IDataTemplateSelectorOverrides2 = winrt::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2;

    Windows::UI::Xaml::DataTemplate SelectTemplateCore(const Windows::Foundation::IInspectable & item)
    {
        return shim().as<IDataTemplateSelectorOverrides2>().SelectTemplateCore(item);
    }

    HRESULT __stdcall abi_SelectTemplateForItemCore(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_out<Windows::UI::Xaml::IDataTemplate> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().SelectTemplateCore(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides>
class IGroupStyleSelectorOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IGroupStyleSelectorOverrides = winrt::Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides;

    Windows::UI::Xaml::Controls::GroupStyle SelectGroupStyleCore(const Windows::Foundation::IInspectable & group, uint32_t level)
    {
        return shim().as<IGroupStyleSelectorOverrides>().SelectGroupStyleCore(group, level);
    }

    HRESULT __stdcall abi_SelectGroupStyleCore(impl::abi_arg_in<Windows::Foundation::IInspectable> group, uint32_t level, impl::abi_arg_out<Windows::UI::Xaml::Controls::IGroupStyle> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().SelectGroupStyleCore(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&group), level));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverrides>
class IInkToolbarCustomPenOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IInkToolbarCustomPenOverrides = winrt::Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverrides;

    Windows::UI::Input::Inking::InkDrawingAttributes CreateInkDrawingAttributesCore(const Windows::UI::Xaml::Media::Brush & brush, double strokeWidth)
    {
        return shim().as<IInkToolbarCustomPenOverrides>().CreateInkDrawingAttributesCore(brush, strokeWidth);
    }

    HRESULT __stdcall abi_CreateInkDrawingAttributesCore(impl::abi_arg_in<Windows::UI::Xaml::Media::IBrush> brush, double strokeWidth, impl::abi_arg_out<Windows::UI::Input::Inking::IInkDrawingAttributes> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateInkDrawingAttributesCore(*reinterpret_cast<const Windows::UI::Xaml::Media::Brush *>(&brush), strokeWidth));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IItemsControlOverrides>
class IItemsControlOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IItemsControlOverrides = winrt::Windows::UI::Xaml::Controls::IItemsControlOverrides;

    bool IsItemItsOwnContainerOverride(const Windows::Foundation::IInspectable & item)
    {
        return shim().as<IItemsControlOverrides>().IsItemItsOwnContainerOverride(item);
    }

    Windows::UI::Xaml::DependencyObject GetContainerForItemOverride()
    {
        return shim().as<IItemsControlOverrides>().GetContainerForItemOverride();
    }

    void ClearContainerForItemOverride(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::IInspectable & item)
    {
        shim().as<IItemsControlOverrides>().ClearContainerForItemOverride(element, item);
    }

    void PrepareContainerForItemOverride(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::IInspectable & item)
    {
        shim().as<IItemsControlOverrides>().PrepareContainerForItemOverride(element, item);
    }

    void OnItemsChanged(const Windows::Foundation::IInspectable & e)
    {
        shim().as<IItemsControlOverrides>().OnItemsChanged(e);
    }

    void OnItemContainerStyleChanged(const Windows::UI::Xaml::Style & oldItemContainerStyle, const Windows::UI::Xaml::Style & newItemContainerStyle)
    {
        shim().as<IItemsControlOverrides>().OnItemContainerStyleChanged(oldItemContainerStyle, newItemContainerStyle);
    }

    void OnItemContainerStyleSelectorChanged(const Windows::UI::Xaml::Controls::StyleSelector & oldItemContainerStyleSelector, const Windows::UI::Xaml::Controls::StyleSelector & newItemContainerStyleSelector)
    {
        shim().as<IItemsControlOverrides>().OnItemContainerStyleSelectorChanged(oldItemContainerStyleSelector, newItemContainerStyleSelector);
    }

    void OnItemTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldItemTemplate, const Windows::UI::Xaml::DataTemplate & newItemTemplate)
    {
        shim().as<IItemsControlOverrides>().OnItemTemplateChanged(oldItemTemplate, newItemTemplate);
    }

    void OnItemTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldItemTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newItemTemplateSelector)
    {
        shim().as<IItemsControlOverrides>().OnItemTemplateSelectorChanged(oldItemTemplateSelector, newItemTemplateSelector);
    }

    void OnGroupStyleSelectorChanged(const Windows::UI::Xaml::Controls::GroupStyleSelector & oldGroupStyleSelector, const Windows::UI::Xaml::Controls::GroupStyleSelector & newGroupStyleSelector)
    {
        shim().as<IItemsControlOverrides>().OnGroupStyleSelectorChanged(oldGroupStyleSelector, newGroupStyleSelector);
    }

    HRESULT __stdcall abi_IsItemItsOwnContainerOverride(impl::abi_arg_in<Windows::Foundation::IInspectable> item, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsItemItsOwnContainerOverride(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetContainerForItemOverride(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetContainerForItemOverride());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearContainerForItemOverride(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, impl::abi_arg_in<Windows::Foundation::IInspectable> item) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearContainerForItemOverride(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&item));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareContainerForItemOverride(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, impl::abi_arg_in<Windows::Foundation::IInspectable> item) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrepareContainerForItemOverride(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&item));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemsChanged(impl::abi_arg_in<Windows::Foundation::IInspectable> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnItemsChanged(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemContainerStyleChanged(impl::abi_arg_in<Windows::UI::Xaml::IStyle> oldItemContainerStyle, impl::abi_arg_in<Windows::UI::Xaml::IStyle> newItemContainerStyle) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnItemContainerStyleChanged(*reinterpret_cast<const Windows::UI::Xaml::Style *>(&oldItemContainerStyle), *reinterpret_cast<const Windows::UI::Xaml::Style *>(&newItemContainerStyle));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemContainerStyleSelectorChanged(impl::abi_arg_in<Windows::UI::Xaml::Controls::IStyleSelector> oldItemContainerStyleSelector, impl::abi_arg_in<Windows::UI::Xaml::Controls::IStyleSelector> newItemContainerStyleSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnItemContainerStyleSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::StyleSelector *>(&oldItemContainerStyleSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::StyleSelector *>(&newItemContainerStyleSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemTemplateChanged(impl::abi_arg_in<Windows::UI::Xaml::IDataTemplate> oldItemTemplate, impl::abi_arg_in<Windows::UI::Xaml::IDataTemplate> newItemTemplate) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnItemTemplateChanged(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&oldItemTemplate), *reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&newItemTemplate));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnItemTemplateSelectorChanged(impl::abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> oldItemTemplateSelector, impl::abi_arg_in<Windows::UI::Xaml::Controls::IDataTemplateSelector> newItemTemplateSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnItemTemplateSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&oldItemTemplateSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::DataTemplateSelector *>(&newItemTemplateSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnGroupStyleSelectorChanged(impl::abi_arg_in<Windows::UI::Xaml::Controls::IGroupStyleSelector> oldGroupStyleSelector, impl::abi_arg_in<Windows::UI::Xaml::Controls::IGroupStyleSelector> newGroupStyleSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnGroupStyleSelectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Controls::GroupStyleSelector *>(&oldGroupStyleSelector), *reinterpret_cast<const Windows::UI::Xaml::Controls::GroupStyleSelector *>(&newGroupStyleSelector));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IPageOverrides>
class IPageOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IPageOverrides = winrt::Windows::UI::Xaml::Controls::IPageOverrides;

    void OnNavigatedFrom(const Windows::UI::Xaml::Navigation::NavigationEventArgs & e)
    {
        shim().as<IPageOverrides>().OnNavigatedFrom(e);
    }

    void OnNavigatedTo(const Windows::UI::Xaml::Navigation::NavigationEventArgs & e)
    {
        shim().as<IPageOverrides>().OnNavigatedTo(e);
    }

    void OnNavigatingFrom(const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs & e)
    {
        shim().as<IPageOverrides>().OnNavigatingFrom(e);
    }

    HRESULT __stdcall abi_OnNavigatedFrom(impl::abi_arg_in<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnNavigatedFrom(*reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnNavigatedTo(impl::abi_arg_in<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnNavigatedTo(*reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnNavigatingFrom(impl::abi_arg_in<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnNavigatingFrom(*reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IStyleSelectorOverrides>
class IStyleSelectorOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IStyleSelectorOverrides = winrt::Windows::UI::Xaml::Controls::IStyleSelectorOverrides;

    Windows::UI::Xaml::Style SelectStyleCore(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container)
    {
        return shim().as<IStyleSelectorOverrides>().SelectStyleCore(item, container);
    }

    HRESULT __stdcall abi_SelectStyleCore(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> container, impl::abi_arg_out<Windows::UI::Xaml::IStyle> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().SelectStyleCore(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&container)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IToggleSwitchOverrides>
class IToggleSwitchOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IToggleSwitchOverrides = winrt::Windows::UI::Xaml::Controls::IToggleSwitchOverrides;

    void OnToggled()
    {
        shim().as<IToggleSwitchOverrides>().OnToggled();
    }

    void OnOnContentChanged(const Windows::Foundation::IInspectable & oldContent, const Windows::Foundation::IInspectable & newContent)
    {
        shim().as<IToggleSwitchOverrides>().OnOnContentChanged(oldContent, newContent);
    }

    void OnOffContentChanged(const Windows::Foundation::IInspectable & oldContent, const Windows::Foundation::IInspectable & newContent)
    {
        shim().as<IToggleSwitchOverrides>().OnOffContentChanged(oldContent, newContent);
    }

    void OnHeaderChanged(const Windows::Foundation::IInspectable & oldContent, const Windows::Foundation::IInspectable & newContent)
    {
        shim().as<IToggleSwitchOverrides>().OnHeaderChanged(oldContent, newContent);
    }

    HRESULT __stdcall abi_OnToggled() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnToggled();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnOnContentChanged(impl::abi_arg_in<Windows::Foundation::IInspectable> oldContent, impl::abi_arg_in<Windows::Foundation::IInspectable> newContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnOnContentChanged(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&newContent));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnOffContentChanged(impl::abi_arg_in<Windows::Foundation::IInspectable> oldContent, impl::abi_arg_in<Windows::Foundation::IInspectable> newContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnOffContentChanged(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&newContent));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnHeaderChanged(impl::abi_arg_in<Windows::Foundation::IInspectable> oldContent, impl::abi_arg_in<Windows::Foundation::IInspectable> newContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnHeaderChanged(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&oldContent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&newContent));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>
class IVirtualizingPanelOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IVirtualizingPanelOverrides = winrt::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides;

    void OnItemsChanged(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs & args)
    {
        shim().as<IVirtualizingPanelOverrides>().OnItemsChanged(sender, args);
    }

    void OnClearChildren()
    {
        shim().as<IVirtualizingPanelOverrides>().OnClearChildren();
    }

    void BringIndexIntoView(int32_t index)
    {
        shim().as<IVirtualizingPanelOverrides>().BringIndexIntoView(index);
    }

    HRESULT __stdcall abi_OnItemsChanged(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnItemsChanged(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnClearChildren() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnClearChildren();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_BringIndexIntoView(int32_t index) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BringIndexIntoView(index);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides>
class IVirtualizingStackPanelOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IVirtualizingStackPanelOverrides = winrt::Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides;

    void OnCleanUpVirtualizedItem(const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs & e)
    {
        shim().as<IVirtualizingStackPanelOverrides>().OnCleanUpVirtualizedItem(e);
    }

    HRESULT __stdcall abi_OnCleanUpVirtualizedItem(impl::abi_arg_in<Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs> e) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnCleanUpVirtualizedItem(*reinterpret_cast<const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

}
