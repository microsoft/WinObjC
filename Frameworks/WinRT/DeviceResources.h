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

#pragma once

namespace StarboardWinRT {
// Provides an interface for an application that owns DeviceResources to be notified of the device being lost or
// created.
interface IDeviceNotify {
    virtual void OnDeviceLost() = 0;
    virtual void OnDeviceRestored() = 0;
};

// Controls all the DirectX device resources.
class DeviceResources {
public:
    DeviceResources();
    void SetLogicalSize(Windows::Foundation::Size logicalSize);
    void SetCurrentOrientation(Windows::Graphics::Display::DisplayOrientations currentOrientation);
    virtual void SetDpi(float dpi) = 0;
    void ValidateDevice();
    void HandleDeviceLost();
    void RegisterDeviceNotify(IDeviceNotify* deviceNotify);
    void Trim();
    void Present();

    // Device Accessors.
    Windows::Foundation::Size GetOutputSize() const {
        return m_outputSize;
    }
    Windows::Foundation::Size GetLogicalSize() const {
        return m_logicalSize;
    }

    // D3D Accessors.
    ID3D11Device2* GetD3DDevice() const {
        return m_d3dDevice.Get();
    }
    ID3D11DeviceContext2* GetD3DDeviceContext() const {
        return m_d3dContext.Get();
    }
    IDXGISwapChain1* GetSwapChain() const {
        return m_swapChain.Get();
    }
    D3D_FEATURE_LEVEL GetDeviceFeatureLevel() const {
        return m_d3dFeatureLevel;
    }
    ID3D11RenderTargetView* GetBackBufferRenderTargetView() const {
        return m_d3dRenderTargetView.Get();
    }
    D3D11_VIEWPORT GetScreenViewport() const {
        return m_screenViewport;
    }
    DirectX::XMFLOAT4X4 GetOrientationTransform3D() const {
        return m_orientationTransform3D;
    }

protected:
    void CreateDeviceIndependentResources();
    void CreateDeviceResources();
    virtual void CreateWindowSizeDependentResources() = 0;
    DXGI_MODE_ROTATION ComputeDisplayRotation();

    // Direct3D objects.
    Microsoft::WRL::ComPtr<ID3D11Device2> m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext2> m_d3dContext;
    Microsoft::WRL::ComPtr<IDXGISwapChain1> m_swapChain;

    // Direct3D rendering objects. Required for 3D.
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_d3dRenderTargetView;
    D3D11_VIEWPORT m_screenViewport;

    // Cached device properties.
    D3D_FEATURE_LEVEL m_d3dFeatureLevel;
    Windows::Foundation::Size m_d3dRenderTargetSize;
    Windows::Foundation::Size m_outputSize;
    Windows::Foundation::Size m_logicalSize;
    Windows::Graphics::Display::DisplayOrientations m_nativeOrientation;
    Windows::Graphics::Display::DisplayOrientations m_currentOrientation;
    float m_dpi;

    // Transforms used for display orientation.
    DirectX::XMFLOAT4X4 m_orientationTransform3D;

    // The IDeviceNotify can be held directly as it owns the DeviceResources.
    IDeviceNotify* m_deviceNotify;
};
}