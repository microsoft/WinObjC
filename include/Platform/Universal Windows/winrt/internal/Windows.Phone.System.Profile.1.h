// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.System.Profile.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::System::Profile {

struct __declspec(uuid("d7ded029-fdda-43e7-93fb-e53ab6e89ec3")) __declspec(novtable) IRetailModeStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RetailModeEnabled(bool * value) = 0;
};

}

namespace ABI {


}

namespace Windows::Phone::System::Profile {

template <typename D>
struct WINRT_EBO impl_IRetailModeStatics
{
    [[deprecated("Use Windows.System.Profile.IRetailInfoStatics instead.")]] bool RetailModeEnabled() const;
};

}

namespace impl {

template <> struct traits<Windows::Phone::System::Profile::IRetailModeStatics>
{
    using abi = ABI::Windows::Phone::System::Profile::IRetailModeStatics;
    template <typename D> using consume = Windows::Phone::System::Profile::impl_IRetailModeStatics<D>;
};

template <> struct traits<Windows::Phone::System::Profile::RetailMode>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.System.Profile.RetailMode"; }
};

}

}
