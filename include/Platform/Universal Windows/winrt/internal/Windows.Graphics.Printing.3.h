// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Printing.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::Printing {

template <typename H> struct impl_PrintTaskSourceRequestedHandler : implements<impl_PrintTaskSourceRequestedHandler<H>, abi<PrintTaskSourceRequestedHandler>>, H
{
    impl_PrintTaskSourceRequestedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Graphics::Printing::PrintTaskSourceRequestedArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Graphics::Printing {

struct WINRT_EBO PrintManager :
    Windows::Graphics::Printing::IPrintManager
{
    PrintManager(std::nullptr_t) noexcept {}
    static Windows::Graphics::Printing::PrintManager GetForCurrentView();
    static Windows::Foundation::IAsyncOperation<bool> ShowPrintUIAsync();
    static bool IsSupported();
};

struct WINRT_EBO PrintPageInfo :
    Windows::Graphics::Printing::IPrintPageInfo
{
    PrintPageInfo(std::nullptr_t) noexcept {}
    PrintPageInfo();
};

struct WINRT_EBO PrintTask :
    Windows::Graphics::Printing::IPrintTask,
    impl::require<PrintTask, Windows::Graphics::Printing::IPrintTaskTargetDeviceSupport, Windows::Graphics::Printing::IPrintTask2>
{
    PrintTask(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskCompletedEventArgs :
    Windows::Graphics::Printing::IPrintTaskCompletedEventArgs
{
    PrintTaskCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskOptions :
    Windows::Graphics::Printing::IPrintTaskOptionsCore,
    impl::require<PrintTaskOptions, Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties, Windows::Graphics::Printing::IPrintTaskOptions, Windows::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration>
{
    PrintTaskOptions(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskProgressingEventArgs :
    Windows::Graphics::Printing::IPrintTaskProgressingEventArgs
{
    PrintTaskProgressingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskRequest :
    Windows::Graphics::Printing::IPrintTaskRequest
{
    PrintTaskRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskRequestedDeferral :
    Windows::Graphics::Printing::IPrintTaskRequestedDeferral
{
    PrintTaskRequestedDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskRequestedEventArgs :
    Windows::Graphics::Printing::IPrintTaskRequestedEventArgs
{
    PrintTaskRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskSourceRequestedArgs :
    Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs
{
    PrintTaskSourceRequestedArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskSourceRequestedDeferral :
    Windows::Graphics::Printing::IPrintTaskSourceRequestedDeferral
{
    PrintTaskSourceRequestedDeferral(std::nullptr_t) noexcept {}
};

struct StandardPrintTaskOptions
{
    StandardPrintTaskOptions() = delete;
    static hstring MediaSize();
    static hstring MediaType();
    static hstring Orientation();
    static hstring PrintQuality();
    static hstring ColorMode();
    static hstring Duplex();
    static hstring Collation();
    static hstring Staple();
    static hstring HolePunch();
    static hstring Binding();
    static hstring Copies();
    static hstring NUp();
    static hstring InputBin();
    static hstring Bordering();
};

}

}
