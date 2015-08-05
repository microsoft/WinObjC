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

#include "DeviceResources.h"
#include <windows.ui.xaml.media.dxinterop.h>

namespace StarboardSwapChain
{
    class DeviceResourcesXaml : public StarboardWinRT::DeviceResources
    {
    public:
        void SetSwapChainPanel(Windows::UI::Xaml::Controls::SwapChainPanel^ panel);
        void SetCompositionScale(float compositionScaleX, float compositionScaleY);
        void CreateWindowSizeDependentResources();
        void SetDpi(float dpi);

    private:
        // Cached reference to the XAML panel.
        Windows::UI::Xaml::Controls::SwapChainPanel^    m_swapChainPanel;
        float                                           m_compositionScaleX;
        float                                           m_compositionScaleY;
    };
}