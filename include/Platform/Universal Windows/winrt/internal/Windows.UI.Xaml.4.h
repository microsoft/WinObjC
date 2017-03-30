// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml {

template <typename D, typename A = ABI::Windows::UI::Xaml::IApplicationOverrides>
class IApplicationOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IApplicationOverrides = winrt::Windows::UI::Xaml::IApplicationOverrides;

    void OnActivated(const Windows::ApplicationModel::Activation::IActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnActivated(args);
    }

    void OnLaunched(const Windows::ApplicationModel::Activation::LaunchActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnLaunched(args);
    }

    void OnFileActivated(const Windows::ApplicationModel::Activation::FileActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnFileActivated(args);
    }

    void OnSearchActivated(const Windows::ApplicationModel::Activation::SearchActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnSearchActivated(args);
    }

    void OnShareTargetActivated(const Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnShareTargetActivated(args);
    }

    void OnFileOpenPickerActivated(const Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnFileOpenPickerActivated(args);
    }

    void OnFileSavePickerActivated(const Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnFileSavePickerActivated(args);
    }

    void OnCachedFileUpdaterActivated(const Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnCachedFileUpdaterActivated(args);
    }

    void OnWindowCreated(const Windows::UI::Xaml::WindowCreatedEventArgs & args)
    {
        shim().as<IApplicationOverrides>().OnWindowCreated(args);
    }

    HRESULT __stdcall abi_OnActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::IActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnLaunched(impl::abi_arg_in<Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnLaunched(*reinterpret_cast<const Windows::ApplicationModel::Activation::LaunchActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnFileActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IFileActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnFileActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnSearchActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::ISearchActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnSearchActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::SearchActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnShareTargetActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnShareTargetActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnFileOpenPickerActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnFileOpenPickerActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnFileSavePickerActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnFileSavePickerActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnCachedFileUpdaterActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnCachedFileUpdaterActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnWindowCreated(impl::abi_arg_in<Windows::UI::Xaml::IWindowCreatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnWindowCreated(*reinterpret_cast<const Windows::UI::Xaml::WindowCreatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IApplicationOverrides2>
class IApplicationOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IApplicationOverrides2 = winrt::Windows::UI::Xaml::IApplicationOverrides2;

    void OnBackgroundActivated(const Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs & args)
    {
        shim().as<IApplicationOverrides2>().OnBackgroundActivated(args);
    }

    HRESULT __stdcall abi_OnBackgroundActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnBackgroundActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IFrameworkElementOverrides>
class IFrameworkElementOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IFrameworkElementOverrides = winrt::Windows::UI::Xaml::IFrameworkElementOverrides;

    Windows::Foundation::Size MeasureOverride(const Windows::Foundation::Size & availableSize)
    {
        return shim().as<IFrameworkElementOverrides>().MeasureOverride(availableSize);
    }

    Windows::Foundation::Size ArrangeOverride(const Windows::Foundation::Size & finalSize)
    {
        return shim().as<IFrameworkElementOverrides>().ArrangeOverride(finalSize);
    }

    void OnApplyTemplate()
    {
        shim().as<IFrameworkElementOverrides>().OnApplyTemplate();
    }

    HRESULT __stdcall abi_MeasureOverride(impl::abi_arg_in<Windows::Foundation::Size> availableSize, impl::abi_arg_out<Windows::Foundation::Size> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MeasureOverride(*reinterpret_cast<const Windows::Foundation::Size *>(&availableSize)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ArrangeOverride(impl::abi_arg_in<Windows::Foundation::Size> finalSize, impl::abi_arg_out<Windows::Foundation::Size> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ArrangeOverride(*reinterpret_cast<const Windows::Foundation::Size *>(&finalSize)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnApplyTemplate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnApplyTemplate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IFrameworkElementOverrides2>
class IFrameworkElementOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IFrameworkElementOverrides2 = winrt::Windows::UI::Xaml::IFrameworkElementOverrides2;

    bool GoToElementStateCore(hstring_view stateName, bool useTransitions)
    {
        return shim().as<IFrameworkElementOverrides2>().GoToElementStateCore(stateName, useTransitions);
    }

    HRESULT __stdcall abi_GoToElementStateCore(impl::abi_arg_in<hstring> stateName, bool useTransitions, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GoToElementStateCore(*reinterpret_cast<const hstring *>(&stateName), useTransitions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IUIElementOverrides>
class IUIElementOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IUIElementOverrides = winrt::Windows::UI::Xaml::IUIElementOverrides;

    Windows::UI::Xaml::Automation::Peers::AutomationPeer OnCreateAutomationPeer()
    {
        return shim().as<IUIElementOverrides>().OnCreateAutomationPeer();
    }

    void OnDisconnectVisualChildren()
    {
        shim().as<IUIElementOverrides>().OnDisconnectVisualChildren();
    }

    Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>> FindSubElementsForTouchTargeting(const Windows::Foundation::Point & point, const Windows::Foundation::Rect & boundingRect)
    {
        return shim().as<IUIElementOverrides>().FindSubElementsForTouchTargeting(point, boundingRect);
    }

    HRESULT __stdcall abi_OnCreateAutomationPeer(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().OnCreateAutomationPeer());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDisconnectVisualChildren() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDisconnectVisualChildren();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindSubElementsForTouchTargeting(impl::abi_arg_in<Windows::Foundation::Point> point, impl::abi_arg_in<Windows::Foundation::Rect> boundingRect, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindSubElementsForTouchTargeting(*reinterpret_cast<const Windows::Foundation::Point *>(&point), *reinterpret_cast<const Windows::Foundation::Rect *>(&boundingRect)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::IVisualStateManagerOverrides>
class IVisualStateManagerOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IVisualStateManagerOverrides = winrt::Windows::UI::Xaml::IVisualStateManagerOverrides;

    bool GoToStateCore(const Windows::UI::Xaml::Controls::Control & control, const Windows::UI::Xaml::FrameworkElement & templateRoot, hstring_view stateName, const Windows::UI::Xaml::VisualStateGroup & group, const Windows::UI::Xaml::VisualState & state, bool useTransitions)
    {
        return shim().as<IVisualStateManagerOverrides>().GoToStateCore(control, templateRoot, stateName, group, state, useTransitions);
    }

    HRESULT __stdcall abi_GoToStateCore(impl::abi_arg_in<Windows::UI::Xaml::Controls::IControl> control, impl::abi_arg_in<Windows::UI::Xaml::IFrameworkElement> templateRoot, impl::abi_arg_in<hstring> stateName, impl::abi_arg_in<Windows::UI::Xaml::IVisualStateGroup> group, impl::abi_arg_in<Windows::UI::Xaml::IVisualState> state, bool useTransitions, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GoToStateCore(*reinterpret_cast<const Windows::UI::Xaml::Controls::Control *>(&control), *reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&templateRoot), *reinterpret_cast<const hstring *>(&stateName), *reinterpret_cast<const Windows::UI::Xaml::VisualStateGroup *>(&group), *reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&state), useTransitions));
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
