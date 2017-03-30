// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Controls::Primitives {

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides>
class IFlyoutBaseOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IFlyoutBaseOverrides = winrt::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides;

    Windows::UI::Xaml::Controls::Control CreatePresenter()
    {
        return shim().as<IFlyoutBaseOverrides>().CreatePresenter();
    }

    HRESULT __stdcall abi_CreatePresenter(impl::abi_arg_out<Windows::UI::Xaml::Controls::IControl> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreatePresenter());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>
class IPickerFlyoutBaseOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IPickerFlyoutBaseOverrides = winrt::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides;

    void OnConfirmed()
    {
        shim().as<IPickerFlyoutBaseOverrides>().OnConfirmed();
    }

    bool ShouldShowConfirmationButtons()
    {
        return shim().as<IPickerFlyoutBaseOverrides>().ShouldShowConfirmationButtons();
    }

    HRESULT __stdcall abi_OnConfirmed() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnConfirmed();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShouldShowConfirmationButtons(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ShouldShowConfirmationButtons());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>
class IRangeBaseOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IRangeBaseOverrides = winrt::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides;

    void OnMinimumChanged(double oldMinimum, double newMinimum)
    {
        shim().as<IRangeBaseOverrides>().OnMinimumChanged(oldMinimum, newMinimum);
    }

    void OnMaximumChanged(double oldMaximum, double newMaximum)
    {
        shim().as<IRangeBaseOverrides>().OnMaximumChanged(oldMaximum, newMaximum);
    }

    void OnValueChanged(double oldValue, double newValue)
    {
        shim().as<IRangeBaseOverrides>().OnValueChanged(oldValue, newValue);
    }

    HRESULT __stdcall abi_OnMinimumChanged(double oldMinimum, double newMinimum) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnMinimumChanged(oldMinimum, newMinimum);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnMaximumChanged(double oldMaximum, double newMaximum) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnMaximumChanged(oldMaximum, newMaximum);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnValueChanged(double oldValue, double newValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnValueChanged(oldValue, newValue);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides>
class IToggleButtonOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IToggleButtonOverrides = winrt::Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides;

    void OnToggle()
    {
        shim().as<IToggleButtonOverrides>().OnToggle();
    }

    HRESULT __stdcall abi_OnToggle() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnToggle();
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
