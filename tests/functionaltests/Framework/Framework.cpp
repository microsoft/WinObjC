//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// Pull in GTest framework.
#include <gtest-api.h>
#include <src/gtest-all.cc>

#include "Framework.h"
#include <WexTestClass.h>

#include <windows.applicationmodel.core.h>
#include <windows.system.display.h>
#include <windows.h>
#include <windows.ui.core.h>
#include <wrl/async.h>
#include <wrl/client.h>
#include <wrl/implements.h>

#include <ErrorHandling.h>
#include <StringHelpers.h>
#include <VCInclude/winobjc/winobjc.h>

using namespace Microsoft::WRL;
using namespace ABI::Windows::ApplicationModel::Core;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::System::Display;
using namespace ABI::Windows::UI::Core;

#define MakeAgileDispatcherCallback Callback<Implements<RuntimeClassFlags<ClassicCom>, IDispatchedHandler, FtmBase>>

class Event {
public:
    Event() : m_handle(::CreateEvent(nullptr, FALSE, FALSE, nullptr)) {
    }

    ~Event() {
        if (IsValid()) {
            ::CloseHandle(m_handle);
            m_handle = INVALID_HANDLE_VALUE;
        }
    }

    void Set() {
        ::SetEvent(m_handle);
    }

    HRESULT Wait() {
        DWORD wait = ::WaitForMultipleObjects(1, &m_handle, TRUE, INFINITE);
        if (wait == WAIT_FAILED) {
            RETURN_IF_FAILED(HRESULT_FROM_WIN32(::GetLastError()));
        }

        return S_OK;
    }

    bool IsValid() {
        return (m_handle != INVALID_HANDLE_VALUE);
    }

    HANDLE m_handle;
};

namespace FrameworkHelper {

HRESULT RunOnUIThread(const std::function<void()>& func) {
    // Get the ICoreApplication
    ComPtr<ICoreImmersiveApplication> spApplication;
    RETURN_IF_FAILED(
        Windows::Foundation::GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_ApplicationModel_Core_CoreApplication)
                                                      .Get(),
                                                  &spApplication));

    // Get the ICoreApplicationView
    ComPtr<ICoreApplicationView> spView;
    RETURN_IF_FAILED(spApplication->get_MainView(&spView));

    // Get the ICoreWindow
    ComPtr<ICoreWindow> spWindow;
    RETURN_IF_FAILED(spView->get_CoreWindow(&spWindow));

    // Get the dispatcher
    ComPtr<ICoreDispatcher> spDispatcher;
    RETURN_IF_FAILED(spWindow->get_Dispatcher(&spDispatcher));

    // Create an event so we can wait for the callback to complete
    Event completedEvent;
    if (!completedEvent.IsValid()) {
        return HRESULT_FROM_WIN32(::GetLastError());
    }

    // Create the dispatch callback
    HRESULT invokeResult = E_FAIL;
    auto spDispatchCallback = MakeAgileDispatcherCallback([&]() -> HRESULT {
        invokeResult = WEX::SafeInvoke([&]() -> bool {
            func();
            return true;
        });
        return S_OK;
    });
    if (!spDispatchCallback) {
        return E_OUTOFMEMORY;
    }

    // Create the completion callback
    auto spCompletionCallback = Callback<IAsyncActionCompletedHandler>([&completedEvent](IAsyncAction*, AsyncStatus) -> HRESULT {
        completedEvent.Set();
        return S_OK;
    });
    if (!spCompletionCallback) {
        return E_OUTOFMEMORY;
    }

    // Dispatch the callback
    ComPtr<IAsyncAction> spAsyncAction;
    RETURN_IF_FAILED(spDispatcher->RunAsync(CoreDispatcherPriority_Normal, spDispatchCallback.Get(), &spAsyncAction));

    // Subscribe to its completed event
    RETURN_IF_FAILED(spAsyncAction->put_Completed(spCompletionCallback.Get()));

    // Wait for the callback to complete
    RETURN_IF_FAILED(completedEvent.Wait());

    return invokeResult;
}

ComPtr<IDisplayRequest> _CreateDisplayRequest() {
    ComPtr<IDisplayRequest> displayRequest;
    THROW_IF_FAILED(
        Windows::Foundation::ActivateInstance(Wrappers::HStringReference(RuntimeClass_Windows_System_Display_DisplayRequest).Get(),
                                              &displayRequest));
    return displayRequest;
}

ComPtr<IDisplayRequest> _GetDisplayRequestInstance() {
    static ComPtr<IDisplayRequest> s_displayRequest = _CreateDisplayRequest();
    return s_displayRequest;
}

void _DisplayRequestActive() {
    THROW_IF_FAILED(_GetDisplayRequestInstance()->RequestActive());
}

void _DisplayRequestRelease() {
    THROW_IF_FAILED(_GetDisplayRequestInstance()->RequestRelease());
}

// Helper method to request display to be active or inactive.
HRESULT DisplayRequest(bool keepActive) {
    // Note: DisplayRequest only works when run from the ASTA thread.
    if (keepActive) {
        return RunOnUIThread(&_DisplayRequestActive);
    } else {
        return RunOnUIThread(&_DisplayRequestRelease);
    }
}

} // namespace FrameworkHelper
