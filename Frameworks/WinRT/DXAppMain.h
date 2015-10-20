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

#include "StepTimer.h"
#include "DeviceResources.h"

// Renders Direct2D and 3D content on the screen.
namespace StarboardWinRT {
class DXAppMain : public StarboardWinRT::IDeviceNotify {
public:
    DXAppMain(const std::shared_ptr<StarboardWinRT::DeviceResources>& deviceResources);
    ~DXAppMain();
    void CreateWindowSizeDependentResources();
    void Update();
    bool Render();
    void OnPointerPressed(Windows::UI::Core::CoreWindow ^ sender, Windows::UI::Core::PointerEventArgs ^ e);
    void OnPointerMoved(Windows::UI::Core::CoreWindow ^ sender, Windows::UI::Core::PointerEventArgs ^ e);
    void OnPointerReleased(Windows::UI::Core::CoreWindow ^ sender, Windows::UI::Core::PointerEventArgs ^ e);

    // IDeviceNotify
    virtual void OnDeviceLost();
    virtual void OnDeviceRestored();

private:
    // Cached pointer to device resources.
    std::shared_ptr<StarboardWinRT::DeviceResources> m_deviceResources;

    // Rendering loop timer.
    DX::StepTimer m_timer;
};
}