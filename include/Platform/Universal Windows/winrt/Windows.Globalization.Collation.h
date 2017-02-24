// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Globalization.Collation.3.h"
#include "Windows.Globalization.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Globalization::Collation::ICharacterGrouping> : produce_base<D, Windows::Globalization::Collation::ICharacterGrouping>
{
    HRESULT __stdcall get_First(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().First());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Label(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Label());
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
struct produce<D, Windows::Globalization::Collation::ICharacterGroupings> : produce_base<D, Windows::Globalization::Collation::ICharacterGroupings>
{
    HRESULT __stdcall abi_Lookup(impl::abi_arg_in<hstring> text, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Lookup(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Globalization::Collation {

template <typename D> hstring impl_ICharacterGrouping<D>::First() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICharacterGrouping)->get_First(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICharacterGrouping<D>::Label() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICharacterGrouping)->get_Label(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICharacterGroupings<D>::Lookup(hstring_view text) const
{
    hstring result;
    check_hresult(WINRT_SHIM(ICharacterGroupings)->abi_Lookup(get_abi(text), put_abi(result)));
    return result;
}

inline CharacterGroupings::CharacterGroupings() :
    CharacterGroupings(activate_instance<CharacterGroupings>())
{}

}

}
#pragma warning(pop)
