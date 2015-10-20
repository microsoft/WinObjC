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

#include "DXAppMain.h"
#include "DirectXHelper.h"

using namespace StarboardWinRT;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Concurrency;

void EbrConnectCompositor(ID3D11Device1* device);
void EbrDisconnectCompositor();
bool EbrComposite(ID3D11Device1* device, ID3D11DeviceContext* context, ID3D11RenderTargetView* renderTarget);
void RenderFrame(ID3D11Device1* device, ID3D11DeviceContext* context, ID3D11RenderTargetView* renderTarget);
void StartNativeUI();
extern HANDLE compositorReady;
extern float windowWidth, windowHeight;

// XAML Interop -- not really needed here, should be left null.
ID3D11Device2* existingDevice = NULL;
ID3D11DeviceContext2* existingContext = NULL;
IDXGISwapChain* existingChain = NULL;
ID3D11RenderTargetView* existingRtv = NULL;

// Loads and initializes application assets when the application is loaded.
DXAppMain::DXAppMain(const std::shared_ptr<StarboardWinRT::DeviceResources>& deviceResources) : m_deviceResources(deviceResources) {
    // Register to be notified if the Device is lost or recreated
    m_deviceResources->RegisterDeviceNotify(this);

    // TODO: Change the timer settings if you want something other than the default variable timestep mode.
    // e.g. for 60 FPS fixed timestep update logic, call:
    /*
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    */
}

DXAppMain::~DXAppMain() {
    // Deregister device notification
    m_deviceResources->RegisterDeviceNotify(nullptr);
}

// Updates application state when the window size changes (e.g. device orientation change)
void DXAppMain::CreateWindowSizeDependentResources() {
    auto size = m_deviceResources->GetOutputSize();
    windowWidth = size.Width;
    windowHeight = size.Height;
}

// Updates the application state once per frame.
void DXAppMain::Update() {
    // Update scene objects.
    m_timer.Tick([&]() {
        // TODO: Replace this with your app's content update functions.
    });
}

extern bool dxLandscape;

// Renders the current frame according to the current application state.
// Returns true if the frame was rendered and is ready to be displayed.
bool DXAppMain::Render() {
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0) {
        return false;
    }

    auto context = m_deviceResources->GetD3DDeviceContext();
    // dxLandscape = false;

    // Reset render targets to the screen.
    ID3D11RenderTargetView* const targets[1] = { m_deviceResources->GetBackBufferRenderTargetView() };
    context->OMSetRenderTargets(1, targets, NULL);

    static bool bInitialized = false;
    if (!bInitialized) {
        auto size = m_deviceResources->GetOutputSize();
        windowWidth = size.Width;
        windowHeight = size.Height;
        StartNativeUI();
        EbrConnectCompositor((ID3D11Device1*)m_deviceResources->GetD3DDevice());
        SetEvent(compositorReady);
    }
    RenderFrame((ID3D11Device1*)m_deviceResources->GetD3DDevice(), context, targets[0]);

    // Render the scene objects.
    // TODO: Replace this with your app's content rendering functions.

    return true;
}

// Notifies renderers that device resources need to be released.
void DXAppMain::OnDeviceLost() {
}

// Notifies renderers that device resources may now be recreated.
void DXAppMain::OnDeviceRestored() {
    CreateWindowSizeDependentResources();
}

#define EVENT_DOWN 0x64
#define EVENT_MOVE 0x65
#define EVENT_UP 0x66

void HandleInput(float x, float y, int fingerID, int eventType, float surfaceWidth, float surfaceHeight, int64_t eventTime);

void DXAppMain::OnPointerPressed(Windows::UI::Core::CoreWindow ^ sender, Windows::UI::Core::PointerEventArgs ^ e) {
    HandleInput(e->CurrentPoint->Position.X,
                e->CurrentPoint->Position.Y,
                e->CurrentPoint->PointerId,
                EVENT_DOWN,
                sender->Bounds.Width,
                sender->Bounds.Height,
                0);
}

void DXAppMain::OnPointerMoved(Windows::UI::Core::CoreWindow ^ sender, Windows::UI::Core::PointerEventArgs ^ e) {
    HandleInput(e->CurrentPoint->Position.X,
                e->CurrentPoint->Position.Y,
                e->CurrentPoint->PointerId,
                EVENT_MOVE,
                sender->Bounds.Width,
                sender->Bounds.Height,
                0);
}

void DXAppMain::OnPointerReleased(Windows::UI::Core::CoreWindow ^ sender, Windows::UI::Core::PointerEventArgs ^ e) {
    HandleInput(e->CurrentPoint->Position.X,
                e->CurrentPoint->Position.Y,
                e->CurrentPoint->PointerId,
                EVENT_UP,
                sender->Bounds.Width,
                sender->Bounds.Height,
                0);
}

typedef void* EbrEvent;
struct SocketWait;

int EbrEventTimedMultipleWait(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets);
