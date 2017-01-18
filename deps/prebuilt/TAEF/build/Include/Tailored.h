//---------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Provides a helper API for tailored TAEF tests.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------------------------------------------------
#pragma once
#include "WexTestClass.h"

#pragma push_macro("ABI_NAMESPACE")
#undef ABI_NAMESPACE
#if defined(USE_PUBLIC_WINRT_SDK)
#define ABI_NAMESPACE ABI::
#else
#define ABI_NAMESPACE
#endif // #if defined(USE_PUBLIC_WINRT_SDK)

#if !defined(__cplusplus_winrt)
#include <windows.applicationmodel.core.h>

#include <wrl\client.h>
#include <wrl\event.h>
#include <wrl\ftm.h>
#include <wrl\implements.h>
#include <wrl\wrappers\corewrappers.h>
#else
#include <ppltasks.h> // Including as per https://osgwiki.com/wiki/Using_CX_in_Windows_Components. If compiling in the Windows Razzle environment, test files will need to include <pplx.cpp> 
#endif // #if !defined(__cplusplus_winrt)

#pragma warning(push)
#pragma warning(disable:4628)

#if !defined(__cplusplus_winrt)
extern "C" __declspec(dllimport) HRESULT __stdcall Thread_Wait_For(HANDLE handle, unsigned long milliseconds);
#endif // #if !defined(__cplusplus_winrt)

namespace WEX { namespace TestExecution { namespace Tailored
{
#if !defined(__cplusplus_winrt)
    namespace Private
    {
        class Event
        {
        public:
            Event()
                : m_handle(::CreateEvent(nullptr, FALSE, FALSE, nullptr))
            {
            }

            ~Event()
            {
                if (IsValid())
                {
                    ::CloseHandle(m_handle);
                }
            }

            void Set()
            {
                ::SetEvent(m_handle);
            }

            HRESULT Wait()
            {
                return Thread_Wait_For(m_handle, INFINITE);
            }

            bool IsValid()
            {
                return m_handle != nullptr;
            }

            HANDLE m_handle;
        };
    }
#endif // #if !defined(__cplusplus_winrt)

    template <typename TFunction>
    HRESULT RunOnUIThread(const TFunction& function)
    {
#if !defined(__cplusplus_winrt)
        // Get the ICoreApplication
        Microsoft::WRL::ComPtr<ABI_NAMESPACE Windows::ApplicationModel::Core::ICoreImmersiveApplication> spApplication;
        HRESULT hr = ABI_NAMESPACE Windows::Foundation::GetActivationFactory(
            Microsoft::WRL::Wrappers::HStringReference(RuntimeClass_Windows_ApplicationModel_Core_CoreApplication).Get(),
            &spApplication);
        if (FAILED(hr))
        {
            return hr;
        }

        // Get the ICoreApplicationView
        Microsoft::WRL::ComPtr<ABI_NAMESPACE Windows::ApplicationModel::Core::ICoreApplicationView> spView;
        hr = spApplication->get_MainView(&spView);
        if (FAILED(hr))
        {
            return hr;
        }

        // Get the ICoreWindow
        Microsoft::WRL::ComPtr<ABI_NAMESPACE Windows::UI::Core::ICoreWindow> spWindow;
        hr = spView->get_CoreWindow(&spWindow);
        if (FAILED(hr))
        {
            return hr;
        }

        // Get the dispatcher
        Microsoft::WRL::ComPtr<ABI_NAMESPACE Windows::UI::Core::ICoreDispatcher> spDispatcher;
        hr = spWindow->get_Dispatcher(&spDispatcher);
        if (FAILED(hr))
        {
            return hr;
        }

        // Create an event so we can wait for the callback to complete
        Private::Event completedEvent;
        if (!completedEvent.IsValid())
        {
            return HRESULT_FROM_WIN32(::GetLastError());
        }

        // Create the dispatch callback
        HRESULT invokeResult = E_FAIL;
        auto spDispatchCallback = Microsoft::WRL::Callback<Microsoft::WRL::Implements<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::ClassicCom>,
            ABI_NAMESPACE Windows::UI::Core::IDispatchedHandler,
            Microsoft::WRL::FtmBase>>([&]() -> HRESULT
        {
            invokeResult = WEX::SafeInvoke([&]() -> bool { function(); return true; });
            return S_OK;
        });
        if (!spDispatchCallback)
        {
            return E_OUTOFMEMORY;
        }

        // Create the completion callback
        auto spCompletionCallback = Microsoft::WRL::Callback<ABI_NAMESPACE Windows::Foundation::IAsyncActionCompletedHandler>(
            [&completedEvent](ABI_NAMESPACE Windows::Foundation::IAsyncAction*, AsyncStatus) -> HRESULT
        {
            completedEvent.Set();
            return S_OK;
        });
        if (!spCompletionCallback)
        {
            return E_OUTOFMEMORY;
        }

        // Dispatch the callback
        Microsoft::WRL::ComPtr<ABI_NAMESPACE Windows::Foundation::IAsyncAction> spAsyncAction;
        hr = spDispatcher->RunAsync(ABI_NAMESPACE Windows::UI::Core::CoreDispatcherPriority_Normal, spDispatchCallback.Get(), &spAsyncAction);
        if (FAILED(hr))
        {
            return hr;
        }

        // Subscribe to its completed event
        hr = spAsyncAction->put_Completed(spCompletionCallback.Get());
        if (FAILED(hr))
        {
            return hr;
        }

        // Wait for the callback to complete
        hr = completedEvent.Wait();
        if (FAILED(hr))
        {
            return hr;
        }

        return invokeResult;
#else
        try
        {
            Windows::UI::Core::CoreDispatcher^ dispatcher = Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher;

            HRESULT invokeResult = E_FAIL;
            concurrency::task_status status = concurrency::task_status::not_complete;

            auto task = concurrency::create_task(dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
                ref new Windows::UI::Core::DispatchedHandler([&]()
            {
                invokeResult = WEX::SafeInvoke([&]() -> bool {
                    function();
                    return true;
                });
            })));

            status = task.wait();

            switch (status)
            {
            case concurrency::task_status::canceled:
                return E_ABORT;
                break;
            case concurrency::task_status::not_complete:
                return E_FAIL;
                break;
            case concurrency::task_status::completed:
                return invokeResult;
                break; 
            default:
                return E_UNEXPECTED;
                break; 
            }
        }
        catch (Platform::Exception^ e)
        {
            return e->HResult;
        }
#endif // #if !defined(__cplusplus_winrt)
    }
}/* namespace Tailored */}/* namespace TestExecution */}/* namespace WEX */

#pragma warning(pop)

#undef ABI_NAMESPACE
#pragma pop_macro("ABI_NAMESPACE")
