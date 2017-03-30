// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Perception.Automation.Core.0.h"
#include "Windows.Foundation.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Perception::Automation::Core {

struct __declspec(uuid("0bb04541-4ce2-4923-9a76-8187ecc59112")) __declspec(novtable) ICorePerceptionAutomationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetActivationFactoryProvider(Windows::Foundation::IGetActivationFactory * provider) = 0;
};

}

namespace ABI {


}

namespace Windows::Perception::Automation::Core {

template <typename D>
struct WINRT_EBO impl_ICorePerceptionAutomationStatics
{
    void SetActivationFactoryProvider(const Windows::Foundation::IGetActivationFactory & provider) const;
};

}

namespace impl {

template <> struct traits<Windows::Perception::Automation::Core::ICorePerceptionAutomationStatics>
{
    using abi = ABI::Windows::Perception::Automation::Core::ICorePerceptionAutomationStatics;
    template <typename D> using consume = Windows::Perception::Automation::Core::impl_ICorePerceptionAutomationStatics<D>;
};

template <> struct traits<Windows::Perception::Automation::Core::CorePerceptionAutomation>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Perception.Automation.Core.CorePerceptionAutomation"; }
};

}

}
