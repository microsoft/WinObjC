// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Perception.People.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Perception::People {

struct __declspec(uuid("7f5ac5a5-49db-379f-9429-32a2faf34fa6")) __declspec(novtable) IHeadPose : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_ForwardDirection(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_UpDirection(Windows::Foundation::Numerics::float3 * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Perception::People::HeadPose> { using default_interface = Windows::Perception::People::IHeadPose; };

}

namespace Windows::Perception::People {

template <typename D>
struct WINRT_EBO impl_IHeadPose
{
    Windows::Foundation::Numerics::float3 Position() const;
    Windows::Foundation::Numerics::float3 ForwardDirection() const;
    Windows::Foundation::Numerics::float3 UpDirection() const;
};

}

namespace impl {

template <> struct traits<Windows::Perception::People::IHeadPose>
{
    using abi = ABI::Windows::Perception::People::IHeadPose;
    template <typename D> using consume = Windows::Perception::People::impl_IHeadPose<D>;
};

template <> struct traits<Windows::Perception::People::HeadPose>
{
    using abi = ABI::Windows::Perception::People::HeadPose;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Perception.People.HeadPose"; }
};

}

}
