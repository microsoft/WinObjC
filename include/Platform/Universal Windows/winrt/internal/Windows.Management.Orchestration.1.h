// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Management.Orchestration.0.h"
#include "Windows.Foundation.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Orchestration {

struct __declspec(uuid("cff49929-e352-4ff4-bf46-786197a99112")) __declspec(novtable) ICurrentAppOrchestration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartSingleAppMode(Windows::Management::Orchestration::ISingleAppModeContext ** result) = 0;
};

struct __declspec(uuid("0ee337f8-63c5-46d6-ac61-5093e4af6db3")) __declspec(novtable) ICurrentAppOrchestrationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::Management::Orchestration::ICurrentAppOrchestration ** result) = 0;
};

struct __declspec(uuid("87739739-6756-498b-8f1b-3ed4b59d7c9e")) __declspec(novtable) ISingleAppModeContext : Windows::Foundation::IInspectable
{
};

}

namespace ABI {

template <> struct traits<Windows::Management::Orchestration::CurrentAppOrchestration> { using default_interface = Windows::Management::Orchestration::ICurrentAppOrchestration; };
template <> struct traits<Windows::Management::Orchestration::SingleAppModeContext> { using default_interface = Windows::Management::Orchestration::ISingleAppModeContext; };

}

namespace Windows::Management::Orchestration {

template <typename D>
struct WINRT_EBO impl_ICurrentAppOrchestration
{
    Windows::Management::Orchestration::SingleAppModeContext StartSingleAppMode() const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentAppOrchestrationStatics
{
    Windows::Management::Orchestration::CurrentAppOrchestration GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_ISingleAppModeContext
{
};

}

namespace impl {

template <> struct traits<Windows::Management::Orchestration::ICurrentAppOrchestration>
{
    using abi = ABI::Windows::Management::Orchestration::ICurrentAppOrchestration;
    template <typename D> using consume = Windows::Management::Orchestration::impl_ICurrentAppOrchestration<D>;
};

template <> struct traits<Windows::Management::Orchestration::ICurrentAppOrchestrationStatics>
{
    using abi = ABI::Windows::Management::Orchestration::ICurrentAppOrchestrationStatics;
    template <typename D> using consume = Windows::Management::Orchestration::impl_ICurrentAppOrchestrationStatics<D>;
};

template <> struct traits<Windows::Management::Orchestration::ISingleAppModeContext>
{
    using abi = ABI::Windows::Management::Orchestration::ISingleAppModeContext;
    template <typename D> using consume = Windows::Management::Orchestration::impl_ISingleAppModeContext<D>;
};

template <> struct traits<Windows::Management::Orchestration::CurrentAppOrchestration>
{
    using abi = ABI::Windows::Management::Orchestration::CurrentAppOrchestration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Orchestration.CurrentAppOrchestration"; }
};

template <> struct traits<Windows::Management::Orchestration::SingleAppModeContext>
{
    using abi = ABI::Windows::Management::Orchestration::SingleAppModeContext;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Orchestration.SingleAppModeContext"; }
};

}

}
