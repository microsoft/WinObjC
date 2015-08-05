//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include <wrl.h>
#include <wrl/client.h>
#include <d3d11_2.h>
#include <d2d1_2.h>
#include <d2d1effects_1.h>
#include <dwrite_2.h>
#include <wincodec.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <memory>
#include <agile.h>
#include <concrt.h>
#include <thread>

#include "DeviceResourcesXaml.h"
#include <collection.h>
#include <ppltasks.h>
#include <wrl/client.h>

#define IWEXPORT __declspec(dllexport)
#include "winobjc\winobjc.h"

using namespace StarboardSwapChain;
using namespace concurrency;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::System;
using namespace Windows::System::Threading;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Graphics::Display;
using namespace StarboardWinRT;
using namespace Windows::ApplicationModel::Store;
using namespace Windows::UI;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Shapes;
using namespace Windows::ApplicationModel::Core;

HANDLE _hNewFrameAvailable;
void IWHandleInput(float x, float y, float width, float height, int fingerID, int eventType, int64_t eventTime);
HANDLE IWConnectCompositor(ID3D11Device1 *device);
void IWRenderFrame(ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget, float width, float height);
HANDLE IWInitializeXamlCompositor(winobjc::Id root);
extern "C" void UIBecomeInactive();


#define EVENT_DOWN  0x64
#define EVENT_MOVE  0x65
#define EVENT_UP    0x66

ref class IWCompositor : Platform::Object
{
private:
    Windows::UI::Xaml::Controls::SwapChainPanel^ _panel;
    Windows::Foundation::Size _panelSize;
    std::shared_ptr<DeviceResourcesXaml> _resources;
    Concurrency::critical_section _renderLock;
    CoreIndependentInputSource ^_inputSource;
    IAsyncAction ^_inputTherad;

internal:
    void RunningUIThread()
    {
        for ( ;; ) {
            WaitForSingleObjectEx(_hNewFrameAvailable, INFINITE, TRUE);

            {
                critical_section::scoped_lock lock(_renderLock);

                float width = _resources->GetOutputSize().Width;
                float height = _resources->GetOutputSize().Height;

                auto context = _resources->GetD3DDeviceContext();

                // Reset render targets to the screen.
                ID3D11RenderTargetView *const targets[1] = { _resources->GetBackBufferRenderTargetView() };
                context->OMSetRenderTargets(1, targets, NULL);
                IWRenderFrame(context, targets[0], width, height);
                _resources->Present();
            }
        }
    }

    void OnSuspending(Platform::Object^, Windows::ApplicationModel::SuspendingEventArgs^) {
        UIBecomeInactive();
    }

    IWCompositor(Windows::UI::Xaml::Controls::SwapChainPanel^ panel) 
    {
        _panel = panel;
        _panelSize.Width = 0;
        _panelSize.Height = 0;
        _resources = std::make_shared<DeviceResourcesXaml>();
        _resources->SetSwapChainPanel(_panel);
        panel->SizeChanged +=
            ref new SizeChangedEventHandler(this, &IWCompositor::OnSwapChainPanelSizeChanged);
        _hNewFrameAvailable = IWConnectCompositor((ID3D11Device1*)_resources->GetD3DDevice());
        std::thread compositorThread([this] { this->RunningUIThread(); });
        compositorThread.detach();

        Application::Current->Suspending += ref new SuspendingEventHandler(this, &IWCompositor::OnSuspending);

        // Register our SwapChainPanel to get independent input pointer events
        auto workItemHandler = ref new WorkItemHandler([this] (IAsyncAction ^)
        {
            // The CoreIndependentInputSource will raise pointer events for the specified device types on whichever thread it's created on.
            _inputSource = _panel->CreateCoreIndependentInputSource(
                Windows::UI::Core::CoreInputDeviceTypes::Mouse |
                Windows::UI::Core::CoreInputDeviceTypes::Touch |
                Windows::UI::Core::CoreInputDeviceTypes::Pen
                );

            // Register for pointer events, which will be raised on the background thread.
            _inputSource->PointerPressed += ref new TypedEventHandler<Object^, PointerEventArgs^>(this, &IWCompositor::OnPointerPressed);
            _inputSource->PointerMoved += ref new TypedEventHandler<Object^, PointerEventArgs^>(this, &IWCompositor::OnPointerMoved);
            _inputSource->PointerReleased += ref new TypedEventHandler<Object^, PointerEventArgs^>(this, &IWCompositor::OnPointerReleased);

            // Begin processing input messages as they're delivered.
            _inputSource->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);
        });
        _inputTherad = ThreadPool::RunAsync(workItemHandler, WorkItemPriority::High, WorkItemOptions::TimeSliced);
    }

    void OnSwapChainPanelSizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e)
    {
        critical_section::scoped_lock lock(_renderLock);
        _resources->SetLogicalSize(e->NewSize);
        _panelSize = e->NewSize;
        SetEvent(_hNewFrameAvailable);
    }

    void OnPointerPressed(Object^ sender, Windows::UI::Core::PointerEventArgs^ e)
    {
        IWHandleInput(e->CurrentPoint->Position.X, e->CurrentPoint->Position.Y,
            _resources->GetLogicalSize().Width, _resources->GetLogicalSize().Height,
            e->CurrentPoint->PointerId,
            EVENT_DOWN,
            e->CurrentPoint->Timestamp * 1000);
    }

    void OnPointerMoved(Object^ sender, Windows::UI::Core::PointerEventArgs^ e)
    {
        IWHandleInput(e->CurrentPoint->Position.X, e->CurrentPoint->Position.Y,
            _resources->GetLogicalSize().Width, _resources->GetLogicalSize().Height,
            e->CurrentPoint->PointerId,
            EVENT_MOVE,
            e->CurrentPoint->Timestamp * 1000);
    }

    void OnPointerReleased(Object^ sender, Windows::UI::Core::PointerEventArgs^ e)
    {
        IWHandleInput(e->CurrentPoint->Position.X, e->CurrentPoint->Position.Y,
            _resources->GetLogicalSize().Width, _resources->GetLogicalSize().Height,
            e->CurrentPoint->PointerId,
            EVENT_UP,
            e->CurrentPoint->Timestamp * 1000);
    }
};

IWCompositor ^iwSingleton;

__declspec(dllexport)
Windows::UI::Xaml::Controls::SwapChainPanel^ IWSetSwapChainTarget(Windows::UI::Xaml::Controls::SwapChainPanel^ panel)
{
    if ( panel == nullptr ) {
        panel = ref new Windows::UI::Xaml::Controls::SwapChainPanel();
    }

    assert(iwSingleton == nullptr);
    iwSingleton = ref new IWCompositor(panel);

    return panel;
}
