// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.System.Profile.SystemManufacturers.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Profile::SystemManufacturers {

struct __declspec(uuid("080cca7c-637c-48c4-b728-f9273812db8e")) __declspec(novtable) ISmbiosInformationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SerialNumber(hstring * value) = 0;
};

}

namespace ABI {


}

namespace Windows::System::Profile::SystemManufacturers {

template <typename D>
struct WINRT_EBO impl_ISmbiosInformationStatics
{
    hstring SerialNumber() const;
};

}

namespace impl {

template <> struct traits<Windows::System::Profile::SystemManufacturers::ISmbiosInformationStatics>
{
    using abi = ABI::Windows::System::Profile::SystemManufacturers::ISmbiosInformationStatics;
    template <typename D> using consume = Windows::System::Profile::SystemManufacturers::impl_ISmbiosInformationStatics<D>;
};

template <> struct traits<Windows::System::Profile::SystemManufacturers::SmbiosInformation>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Profile.SystemManufacturers.SmbiosInformation"; }
};

}

}
