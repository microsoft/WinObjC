//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include "pch.h"
#include "ScrollView.xaml.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

namespace UIKit {
namespace Xaml {

// clang-format does not like C++/CX
// clang-format off

ScrollView::ScrollView()
{
    InitializeComponent();
}

// Accessor for our Layer content
Image^ ScrollView::LayerContent::get() {
    if (layerContentImage == nullptr) {
        layerContentImage = safe_cast<Image^>(FindName(L"layerContentImage"));
        FAIL_FAST_IF(layerContentImage == nullptr);
    }

    return layerContentImage;
}

bool ScrollView::HasLayerContent::get() {
    return true;
}

Canvas^ ScrollView::SublayerCanvas::get() {
    return contentCanvas;
}

Private::CoreAnimation::LayerProperty^ ScrollView::GetBorderBrushProperty() {
    return nullptr;
}

Private::CoreAnimation::LayerProperty^ ScrollView::GetBorderThicknessProperty() {
    return nullptr;
}

ScrollViewer^ ScrollView::InnerScrollViewer::get() {
    return scrollViewer;
}

} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Xaml::ScrollView as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateScrollView(IInspectable** created) {
    ComPtr<IInspectable> inspectable = InspectableFromObject(ref new UIKit::Xaml::ScrollView());
    *created = inspectable.Detach();
}

// Retrieves the UIKit::Xaml::ScrollView as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlScrollViewGetScrollViewer(const Microsoft::WRL::ComPtr<IInspectable>& scrollView) {
    auto scrollViewGrid = safe_cast<UIKit::Xaml::ScrollView^>(reinterpret_cast<Platform::Object^>(scrollView.Get()));
    return InspectableFromObject(scrollViewGrid->InnerScrollViewer).Detach();
}

UIKIT_XAML_EXPORT IInspectable* XamlScrollViewGetSubLayerCanvas(const Microsoft::WRL::ComPtr<IInspectable>& scrollView) {
    auto scrollViewGrid = safe_cast<UIKit::Xaml::ScrollView^>(reinterpret_cast<Platform::Object^>(scrollView.Get()));
    return InspectableFromObject(scrollViewGrid->SublayerCanvas).Detach();
}

// clang-format on
