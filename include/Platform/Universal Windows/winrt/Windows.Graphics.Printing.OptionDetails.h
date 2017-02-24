// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Graphics.Printing.3.h"
#include "internal/Windows.Graphics.Printing.OptionDetails.3.h"
#include "Windows.Graphics.Printing.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails>
{
    HRESULT __stdcall get_ItemId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ItemDisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemDisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemDisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails>
{
    HRESULT __stdcall abi_AddItem(impl::abi_arg_in<hstring> itemId, impl::abi_arg_in<hstring> displayName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddItem(*reinterpret_cast<const hstring *>(&itemId), *reinterpret_cast<const hstring *>(&displayName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>
{
    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails>
{
    HRESULT __stdcall put_MaxCharacters(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxCharacters(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxCharacters(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxCharacters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    HRESULT __stdcall get_Items(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Items());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails>
{
    HRESULT __stdcall get_MinValue(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxValue(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>
{
    HRESULT __stdcall get_OptionId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OptionId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OptionType(Windows::Graphics::Printing::OptionDetails::PrintOptionType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OptionType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ErrorText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ErrorText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_State(Windows::Graphics::Printing::OptionDetails::PrintOptionStates value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().State(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(Windows::Graphics::Printing::OptionDetails::PrintOptionStates * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetValue(impl::abi_arg_in<Windows::Foundation::IInspectable> value, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TrySetValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs>
{
    HRESULT __stdcall get_OptionId(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OptionId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>
{
    HRESULT __stdcall get_Options(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Options());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateItemListOption(impl::abi_arg_in<hstring> optionId, impl::abi_arg_in<hstring> displayName, impl::abi_arg_out<Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> itemListOption) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *itemListOption = detach_abi(this->shim().CreateItemListOption(*reinterpret_cast<const hstring *>(&optionId), *reinterpret_cast<const hstring *>(&displayName)));
            return S_OK;
        }
        catch (...)
        {
            *itemListOption = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTextOption(impl::abi_arg_in<hstring> optionId, impl::abi_arg_in<hstring> displayName, impl::abi_arg_out<Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> textOption) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *textOption = detach_abi(this->shim().CreateTextOption(*reinterpret_cast<const hstring *>(&optionId), *reinterpret_cast<const hstring *>(&displayName)));
            return S_OK;
        }
        catch (...)
        {
            *textOption = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_OptionChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().OptionChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_OptionChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OptionChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BeginValidation(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Foundation::IInspectable>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().BeginValidation(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Foundation::IInspectable> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BeginValidation(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BeginValidation(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic>
{
    HRESULT __stdcall abi_GetFromPrintTaskOptions(impl::abi_arg_in<Windows::Graphics::Printing::IPrintTaskOptionsCore> printTaskOptions, impl::abi_arg_out<Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails> printTaskOptionDetails) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *printTaskOptionDetails = detach_abi(this->shim().GetFromPrintTaskOptions(*reinterpret_cast<const Windows::Graphics::Printing::PrintTaskOptions *>(&printTaskOptions)));
            return S_OK;
        }
        catch (...)
        {
            *printTaskOptionDetails = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing::OptionDetails::IPrintTextOptionDetails> : produce_base<D, Windows::Graphics::Printing::OptionDetails::IPrintTextOptionDetails>
{
    HRESULT __stdcall get_MaxCharacters(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxCharacters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Graphics::Printing::OptionDetails {

template <typename D> hstring impl_IPrintOptionDetails<D>::OptionId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrintOptionDetails)->get_OptionId(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Printing::OptionDetails::PrintOptionType impl_IPrintOptionDetails<D>::OptionType() const
{
    Windows::Graphics::Printing::OptionDetails::PrintOptionType value {};
    check_hresult(WINRT_SHIM(IPrintOptionDetails)->get_OptionType(&value));
    return value;
}

template <typename D> void impl_IPrintOptionDetails<D>::ErrorText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPrintOptionDetails)->put_ErrorText(get_abi(value)));
}

template <typename D> hstring impl_IPrintOptionDetails<D>::ErrorText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrintOptionDetails)->get_ErrorText(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrintOptionDetails<D>::State(Windows::Graphics::Printing::OptionDetails::PrintOptionStates value) const
{
    check_hresult(WINRT_SHIM(IPrintOptionDetails)->put_State(value));
}

template <typename D> Windows::Graphics::Printing::OptionDetails::PrintOptionStates impl_IPrintOptionDetails<D>::State() const
{
    Windows::Graphics::Printing::OptionDetails::PrintOptionStates value {};
    check_hresult(WINRT_SHIM(IPrintOptionDetails)->get_State(&value));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IPrintOptionDetails<D>::Value() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IPrintOptionDetails)->get_Value(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPrintOptionDetails<D>::TrySetValue(const Windows::Foundation::IInspectable & value) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IPrintOptionDetails)->abi_TrySetValue(get_abi(value), &succeeded));
    return succeeded;
}

template <typename D> uint32_t impl_IPrintNumberOptionDetails<D>::MinValue() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrintNumberOptionDetails)->get_MinValue(&value));
    return value;
}

template <typename D> uint32_t impl_IPrintNumberOptionDetails<D>::MaxValue() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrintNumberOptionDetails)->get_MaxValue(&value));
    return value;
}

template <typename D> uint32_t impl_IPrintTextOptionDetails<D>::MaxCharacters() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrintTextOptionDetails)->get_MaxCharacters(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Foundation::IInspectable> impl_IPrintItemListOptionDetails<D>::Items() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IPrintItemListOptionDetails)->get_Items(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrintCustomOptionDetails<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPrintCustomOptionDetails)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IPrintCustomOptionDetails<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrintCustomOptionDetails)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrintCustomTextOptionDetails<D>::MaxCharacters(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPrintCustomTextOptionDetails)->put_MaxCharacters(value));
}

template <typename D> uint32_t impl_IPrintCustomTextOptionDetails<D>::MaxCharacters() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrintCustomTextOptionDetails)->get_MaxCharacters(&value));
    return value;
}

template <typename D> hstring impl_IPrintCustomItemDetails<D>::ItemId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrintCustomItemDetails)->get_ItemId(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrintCustomItemDetails<D>::ItemDisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPrintCustomItemDetails)->put_ItemDisplayName(get_abi(value)));
}

template <typename D> hstring impl_IPrintCustomItemDetails<D>::ItemDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrintCustomItemDetails)->get_ItemDisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrintCustomItemListOptionDetails<D>::AddItem(hstring_view itemId, hstring_view displayName) const
{
    check_hresult(WINRT_SHIM(IPrintCustomItemListOptionDetails)->abi_AddItem(get_abi(itemId), get_abi(displayName)));
}

template <typename D> Windows::Foundation::IInspectable impl_IPrintTaskOptionChangedEventArgs<D>::OptionId() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IPrintTaskOptionChangedEventArgs)->get_OptionId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> impl_IPrintTaskOptionDetails<D>::Options() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> value;
    check_hresult(WINRT_SHIM(IPrintTaskOptionDetails)->get_Options(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Printing::OptionDetails::PrintCustomItemListOptionDetails impl_IPrintTaskOptionDetails<D>::CreateItemListOption(hstring_view optionId, hstring_view displayName) const
{
    Windows::Graphics::Printing::OptionDetails::PrintCustomItemListOptionDetails itemListOption { nullptr };
    check_hresult(WINRT_SHIM(IPrintTaskOptionDetails)->abi_CreateItemListOption(get_abi(optionId), get_abi(displayName), put_abi(itemListOption)));
    return itemListOption;
}

template <typename D> Windows::Graphics::Printing::OptionDetails::PrintCustomTextOptionDetails impl_IPrintTaskOptionDetails<D>::CreateTextOption(hstring_view optionId, hstring_view displayName) const
{
    Windows::Graphics::Printing::OptionDetails::PrintCustomTextOptionDetails textOption { nullptr };
    check_hresult(WINRT_SHIM(IPrintTaskOptionDetails)->abi_CreateTextOption(get_abi(optionId), get_abi(displayName), put_abi(textOption)));
    return textOption;
}

template <typename D> event_token impl_IPrintTaskOptionDetails<D>::OptionChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrintTaskOptionDetails)->add_OptionChanged(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrintTaskOptionDetails> impl_IPrintTaskOptionDetails<D>::OptionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrintTaskOptionDetails>(this, &ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails::remove_OptionChanged, OptionChanged(eventHandler));
}

template <typename D> void impl_IPrintTaskOptionDetails<D>::OptionChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrintTaskOptionDetails)->remove_OptionChanged(eventCookie));
}

template <typename D> event_token impl_IPrintTaskOptionDetails<D>::BeginValidation(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Foundation::IInspectable> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrintTaskOptionDetails)->add_BeginValidation(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrintTaskOptionDetails> impl_IPrintTaskOptionDetails<D>::BeginValidation(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Foundation::IInspectable> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrintTaskOptionDetails>(this, &ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails::remove_BeginValidation, BeginValidation(eventHandler));
}

template <typename D> void impl_IPrintTaskOptionDetails<D>::BeginValidation(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrintTaskOptionDetails)->remove_BeginValidation(eventCookie));
}

template <typename D> Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails impl_IPrintTaskOptionDetailsStatic<D>::GetFromPrintTaskOptions(const Windows::Graphics::Printing::PrintTaskOptions & printTaskOptions) const
{
    Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails printTaskOptionDetails { nullptr };
    check_hresult(WINRT_SHIM(IPrintTaskOptionDetailsStatic)->abi_GetFromPrintTaskOptions(get_abi(printTaskOptions), put_abi(printTaskOptionDetails)));
    return printTaskOptionDetails;
}

inline Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails PrintTaskOptionDetails::GetFromPrintTaskOptions(const Windows::Graphics::Printing::PrintTaskOptions & printTaskOptions)
{
    return get_activation_factory<PrintTaskOptionDetails, IPrintTaskOptionDetailsStatic>().GetFromPrintTaskOptions(printTaskOptions);
}

}

}
#pragma warning(pop)
