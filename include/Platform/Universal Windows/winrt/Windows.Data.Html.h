// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Data.Html.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Data::Html::IHtmlUtilities> : produce_base<D, Windows::Data::Html::IHtmlUtilities>
{
    HRESULT __stdcall abi_ConvertToText(impl::abi_arg_in<hstring> html, impl::abi_arg_out<hstring> text) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *text = detach_abi(this->shim().ConvertToText(*reinterpret_cast<const hstring *>(&html)));
            return S_OK;
        }
        catch (...)
        {
            *text = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Data::Html {

template <typename D> hstring impl_IHtmlUtilities<D>::ConvertToText(hstring_view html) const
{
    hstring text;
    check_hresult(WINRT_SHIM(IHtmlUtilities)->abi_ConvertToText(get_abi(html), put_abi(text)));
    return text;
}

inline hstring HtmlUtilities::ConvertToText(hstring_view html)
{
    return get_activation_factory<HtmlUtilities, IHtmlUtilities>().ConvertToText(html);
}

}

}
#pragma warning(pop)
