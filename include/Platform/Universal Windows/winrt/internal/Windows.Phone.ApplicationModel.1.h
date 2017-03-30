// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Phone.ApplicationModel.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::ApplicationModel {

struct __declspec(uuid("d5008ab4-7e7a-11e1-a7f2-b0a14824019b")) __declspec(novtable) IApplicationProfileStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Modes(winrt::Windows::Phone::ApplicationModel::ApplicationProfileModes * value) = 0;
};

}

namespace ABI {


}

namespace Windows::Phone::ApplicationModel {

template <typename D>
struct WINRT_EBO impl_IApplicationProfileStatics
{
    Windows::Phone::ApplicationModel::ApplicationProfileModes Modes() const;
};

}

namespace impl {

template <> struct traits<Windows::Phone::ApplicationModel::IApplicationProfileStatics>
{
    using abi = ABI::Windows::Phone::ApplicationModel::IApplicationProfileStatics;
    template <typename D> using consume = Windows::Phone::ApplicationModel::impl_IApplicationProfileStatics<D>;
};

template <> struct traits<Windows::Phone::ApplicationModel::ApplicationProfile>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Phone.ApplicationModel.ApplicationProfile"; }
};

}

}
