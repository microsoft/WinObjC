// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Globalization.Collation.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Globalization::Collation {

struct __declspec(uuid("fae761bb-805d-4bb0-95bb-c1f7c3e8eb8e")) __declspec(novtable) ICharacterGrouping : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_First(hstring * value) = 0;
    virtual HRESULT __stdcall get_Label(hstring * value) = 0;
};

struct __declspec(uuid("b8d20a75-d4cf-4055-80e5-ce169c226496")) __declspec(novtable) ICharacterGroupings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Lookup(hstring text, hstring * result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Globalization::Collation::CharacterGrouping> { using default_interface = Windows::Globalization::Collation::ICharacterGrouping; };
template <> struct traits<Windows::Globalization::Collation::CharacterGroupings> { using default_interface = Windows::Globalization::Collation::ICharacterGroupings; };

}

namespace Windows::Globalization::Collation {

template <typename D>
struct WINRT_EBO impl_ICharacterGrouping
{
    hstring First() const;
    hstring Label() const;
};

template <typename D>
struct WINRT_EBO impl_ICharacterGroupings
{
    hstring Lookup(hstring_view text) const;
};

}

namespace impl {

template <> struct traits<Windows::Globalization::Collation::ICharacterGrouping>
{
    using abi = ABI::Windows::Globalization::Collation::ICharacterGrouping;
    template <typename D> using consume = Windows::Globalization::Collation::impl_ICharacterGrouping<D>;
};

template <> struct traits<Windows::Globalization::Collation::ICharacterGroupings>
{
    using abi = ABI::Windows::Globalization::Collation::ICharacterGroupings;
    template <typename D> using consume = Windows::Globalization::Collation::impl_ICharacterGroupings<D>;
};

template <> struct traits<Windows::Globalization::Collation::CharacterGrouping>
{
    using abi = ABI::Windows::Globalization::Collation::CharacterGrouping;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.Collation.CharacterGrouping"; }
};

template <> struct traits<Windows::Globalization::Collation::CharacterGroupings>
{
    using abi = ABI::Windows::Globalization::Collation::CharacterGroupings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Globalization.Collation.CharacterGroupings"; }
};

}

}
