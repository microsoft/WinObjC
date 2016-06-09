//---------------------------------------------------------------------------------------------------------------------
/// \file
/// <summary>Provides a helper API for tailored TAEF tests.</summary>
// Copyright (c) Microsoft Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------------------------------------------------
#pragma once
#include "WexTestClass.h"

#include <windows.applicationmodel.core.h>
#include <windows.ui.core.corewindow.h>
#include <windowsstringp.h>
#include <wrl\client.h>
#include <wrl\event.h>
#include <wrl\ftm.h>
#include <wrl\implements.h>

#pragma warning(push)
#pragma warning(disable:4628)

extern "C" __declspec(dllimport) HRESULT __stdcall Thread_Wait_For(HANDLE handle, unsigned long milliseconds);

namespace WEX { namespace TestExecution { namespace Tailored
{
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

    template <typename TFunction>
    HRESULT RunOnUIThread(const TFunction& function)
    {
        // Get the ICoreApplication
        Microsoft::WRL::ComPtr<Windows::ApplicationModel::Core::ICoreImmersiveApplication> spApplication;
        HRESULT hr = Windows::Foundation::GetActivationFactory(Windows::Internal::StringReference(RuntimeClass_Windows_ApplicationModel_Core_CoreApplication).Get(), 
                                                               &spApplication);
        if (FAILED(hr))
        {
            return hr;
        }

        // Get the ICoreApplicationView
        Microsoft::WRL::ComPtr<Windows::ApplicationModel::Core::ICoreApplicationView> spView;
        hr = spApplication->get_MainView(&spView);
        if (FAILED(hr))
        {
            return hr;
        }

        // Get the ICoreWindow
        Microsoft::WRL::ComPtr<Windows::UI::Core::ICoreWindow> spWindow;
        hr = spView->get_CoreWindow(&spWindow);
        if (FAILED(hr))
        {
            return hr;
        }

        // Get the dispatcher
        Microsoft::WRL::ComPtr<Windows::UI::Core::ICoreDispatcher> spDispatcher;
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
        auto spDispatchCallback = MakeAgileDispatcherCallback([&] () -> HRESULT
                                                              {
                                                                  invokeResult = WEX::SafeInvoke([&] () -> bool { function(); return true; });
                                                                  return S_OK;
                                                              });
        if (!spDispatchCallback)
        {
            return E_OUTOFMEMORY;
        }

        // Create the completion callback
        auto spCompletionCallback = Microsoft::WRL::Callback<Windows::Foundation::IAsyncActionCompletedHandler>(
            [&completedEvent] (Windows::Foundation::IAsyncAction*, AsyncStatus) -> HRESULT 
            {
                completedEvent.Set();
                return S_OK;
            });
        if (!spCompletionCallback)
        {
            return E_OUTOFMEMORY;
        }

        // Dispatch the callback
        Microsoft::WRL::ComPtr<Windows::Foundation::IAsyncAction> spAsyncAction;
        hr = spDispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority_Normal, spDispatchCallback.Get(), &spAsyncAction);
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
    }
}/* namespace Tailored */}/* namespace TestExecution */}/* namespace WEX */

#pragma warning(pop)
