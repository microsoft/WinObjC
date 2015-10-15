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

#include "DeviceResources.h"
#include "DirectXHelper.h"

using namespace D2D1;
using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml::Controls;
using namespace Platform;

// Constructor for DeviceResources.
StarboardWinRT::DeviceResources::DeviceResources()
    : m_screenViewport(),
      m_d3dFeatureLevel(D3D_FEATURE_LEVEL_9_1),
      m_d3dRenderTargetSize(),
      m_outputSize(),
      m_logicalSize(),
      m_nativeOrientation(DisplayOrientations::None),
      m_currentOrientation(DisplayOrientations::None),
      m_dpi(-1.0f),
      m_deviceNotify(nullptr) {
    CreateDeviceIndependentResources();
    CreateDeviceResources();
}

// Configures resources that don't depend on the Direct3D device.
void StarboardWinRT::DeviceResources::CreateDeviceIndependentResources() {
}

// Configures the Direct3D device, and stores handles to it and the device context.
void StarboardWinRT::DeviceResources::CreateDeviceResources() {
    // This flag adds support for surfaces with a different color channel ordering
    // than the API default. It is required for compatibility with Direct2D.
    UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

#if defined(_DEBUG)
    if (StarboardWinRT::SdkLayersAvailable()) {
        // If the project is in a debug build, enable debugging via SDK Layers with this flag.
        creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
    }
#endif

    // This array defines the set of DirectX hardware feature levels this app will support.
    // Note the ordering should be preserved.
    // Don't forget to declare your application's minimum required feature level in its
    // description.  All applications are assumed to support 9.1 unless otherwise stated.
    D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0,
                                          D3D_FEATURE_LEVEL_9_3,  D3D_FEATURE_LEVEL_9_2,  D3D_FEATURE_LEVEL_9_1 };

    // Create the Direct3D 11 API device object and a corresponding context.
    ComPtr<ID3D11Device> device;
    ComPtr<ID3D11DeviceContext> context;

    HRESULT hr = D3D11CreateDevice(nullptr, // Specify nullptr to use the default adapter.
                                   D3D_DRIVER_TYPE_HARDWARE, // Create a device using the hardware graphics driver.
                                   0, // Should be 0 unless the driver is D3D_DRIVER_TYPE_SOFTWARE.
                                   creationFlags, // Set debug and Direct2D compatibility flags.
                                   featureLevels, // List of feature levels this app can support.
                                   ARRAYSIZE(featureLevels), // Size of the list above.
                                   D3D11_SDK_VERSION, // Always set this to D3D11_SDK_VERSION for Windows Store apps.
                                   &device, // Returns the Direct3D device created.
                                   &m_d3dFeatureLevel, // Returns feature level of device created.
                                   &context // Returns the device immediate context.
                                   );

    if (FAILED(hr)) {
        // If the initialization fails, fall back to the WARP device.
        // For more information on WARP, see:
        // http://go.microsoft.com/fwlink/?LinkId=286690
        StarboardWinRT::ThrowIfFailed(D3D11CreateDevice(nullptr,
                                                        D3D_DRIVER_TYPE_WARP, // Create a WARP device instead of a hardware device.
                                                        0,
                                                        creationFlags,
                                                        featureLevels,
                                                        ARRAYSIZE(featureLevels),
                                                        D3D11_SDK_VERSION,
                                                        &device,
                                                        &m_d3dFeatureLevel,
                                                        &context));
    }

    // Store pointers to the Direct3D 11.1 API device and immediate context.
    StarboardWinRT::ThrowIfFailed(device.As(&m_d3dDevice));

    StarboardWinRT::ThrowIfFailed(context.As(&m_d3dContext));
}

// This method is called in the event handler for the SizeChanged event.
void StarboardWinRT::DeviceResources::SetLogicalSize(Windows::Foundation::Size logicalSize) {
    if (m_logicalSize != logicalSize) {
        m_logicalSize = logicalSize;
        CreateWindowSizeDependentResources();
    }
}

// This method is called in the event handler for the OrientationChanged event.
void StarboardWinRT::DeviceResources::SetCurrentOrientation(DisplayOrientations currentOrientation) {
    if (m_currentOrientation != currentOrientation) {
        m_currentOrientation = currentOrientation;
        CreateWindowSizeDependentResources();
    }
}

// This method is called in the event handler for the DisplayContentsInvalidated event.
void StarboardWinRT::DeviceResources::ValidateDevice() {
    // The D3D Device is no longer valid if the default adapter changed since the device
    // was created or if the device has been removed.

    // First, get the information for the default adapter from when the device was created.

    ComPtr<IDXGIDevice3> dxgiDevice;
    StarboardWinRT::ThrowIfFailed(m_d3dDevice.As(&dxgiDevice));

    ComPtr<IDXGIAdapter> deviceAdapter;
    StarboardWinRT::ThrowIfFailed(dxgiDevice->GetAdapter(&deviceAdapter));

    ComPtr<IDXGIFactory2> deviceFactory;
    StarboardWinRT::ThrowIfFailed(deviceAdapter->GetParent(IID_PPV_ARGS(&deviceFactory)));

    ComPtr<IDXGIAdapter1> previousDefaultAdapter;
    StarboardWinRT::ThrowIfFailed(deviceFactory->EnumAdapters1(0, &previousDefaultAdapter));

    DXGI_ADAPTER_DESC previousDesc;
    StarboardWinRT::ThrowIfFailed(previousDefaultAdapter->GetDesc(&previousDesc));

    // Next, get the information for the current default adapter.

    ComPtr<IDXGIFactory2> currentFactory;
    StarboardWinRT::ThrowIfFailed(CreateDXGIFactory1(IID_PPV_ARGS(&currentFactory)));

    ComPtr<IDXGIAdapter1> currentDefaultAdapter;
    StarboardWinRT::ThrowIfFailed(currentFactory->EnumAdapters1(0, &currentDefaultAdapter));

    DXGI_ADAPTER_DESC currentDesc;
    StarboardWinRT::ThrowIfFailed(currentDefaultAdapter->GetDesc(&currentDesc));

    // If the adapter LUIDs don't match, or if the device reports that it has been removed,
    // a new D3D device must be created.

    if (previousDesc.AdapterLuid.LowPart != currentDesc.AdapterLuid.LowPart ||
        previousDesc.AdapterLuid.HighPart != currentDesc.AdapterLuid.HighPart || FAILED(m_d3dDevice->GetDeviceRemovedReason())) {
        // Release references to resources related to the old device.
        dxgiDevice = nullptr;
        deviceAdapter = nullptr;
        deviceFactory = nullptr;
        previousDefaultAdapter = nullptr;

        // Create a new device and swap chain.
        HandleDeviceLost();
    }
}

// Recreate all device resources and set them back to the current state.
void StarboardWinRT::DeviceResources::HandleDeviceLost() {
    m_swapChain = nullptr;

    if (m_deviceNotify != nullptr) {
        m_deviceNotify->OnDeviceLost();
    }

    CreateDeviceResources();
    CreateWindowSizeDependentResources();

    if (m_deviceNotify != nullptr) {
        m_deviceNotify->OnDeviceRestored();
    }
}

// Register our DeviceNotify to be informed on device lost and creation.
void StarboardWinRT::DeviceResources::RegisterDeviceNotify(StarboardWinRT::IDeviceNotify* deviceNotify) {
    m_deviceNotify = deviceNotify;
}

// Call this method when the app suspends. It provides a hint to the driver that the app
// is entering an idle state and that temporary buffers can be reclaimed for use by other apps.
void StarboardWinRT::DeviceResources::Trim() {
    ComPtr<IDXGIDevice3> dxgiDevice;
    m_d3dDevice.As(&dxgiDevice);

    dxgiDevice->Trim();
}

// Present the contents of the swap chain to the screen.
void StarboardWinRT::DeviceResources::Present() {
    // The first argument instructs DXGI to block until VSync, putting the application
    // to sleep until the next VSync. This ensures we don't waste any cycles rendering
    // frames that will never be displayed to the screen.
    HRESULT hr = m_swapChain->Present(1, 0);

    // Discard the contents of the render target.
    // This is a valid operation only when the existing contents will be entirely
    // overwritten. If dirty or scroll rects are used, this call should be removed.
    m_d3dContext->DiscardView(m_d3dRenderTargetView.Get());

    // If the device was removed either by a disconnection or a driver upgrade, we
    // must recreate all device resources.
    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET) {
        HandleDeviceLost();
    } else {
        StarboardWinRT::ThrowIfFailed(hr);
    }
}

// This method determines the rotation between the display device's native Orientation and the
// current display orientation.
DXGI_MODE_ROTATION StarboardWinRT::DeviceResources::ComputeDisplayRotation() {
    DXGI_MODE_ROTATION rotation = DXGI_MODE_ROTATION_UNSPECIFIED;

    // Note: NativeOrientation can only be Landscape or Portrait even though
    // the DisplayOrientations enum has other values.
    switch (m_nativeOrientation) {
        case DisplayOrientations::Landscape:
            switch (m_currentOrientation) {
                case DisplayOrientations::Landscape:
                    rotation = DXGI_MODE_ROTATION_IDENTITY;
                    break;

                case DisplayOrientations::Portrait:
                    rotation = DXGI_MODE_ROTATION_ROTATE270;
                    break;

                case DisplayOrientations::LandscapeFlipped:
                    rotation = DXGI_MODE_ROTATION_ROTATE180;
                    break;

                case DisplayOrientations::PortraitFlipped:
                    rotation = DXGI_MODE_ROTATION_ROTATE90;
                    break;
            }
            break;

        case DisplayOrientations::Portrait:
            switch (m_currentOrientation) {
                case DisplayOrientations::Landscape:
                    rotation = DXGI_MODE_ROTATION_ROTATE90;
                    break;

                case DisplayOrientations::Portrait:
                    rotation = DXGI_MODE_ROTATION_IDENTITY;
                    break;

                case DisplayOrientations::LandscapeFlipped:
                    rotation = DXGI_MODE_ROTATION_ROTATE270;
                    break;

                case DisplayOrientations::PortraitFlipped:
                    rotation = DXGI_MODE_ROTATION_ROTATE180;
                    break;
            }
            break;
    }
    return rotation;
}