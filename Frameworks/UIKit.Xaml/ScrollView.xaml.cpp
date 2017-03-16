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

    SetValue(UIKit::Xaml::Private::CoreAnimation::Layer::LayerContentProperty, LayerContentImage);
    SetValue(UIKit::Xaml::Private::CoreAnimation::Layer::SublayerCanvasProperty, ContentCanvas);

    Name = L"ScrollView";
}

// Accessor for our Layer content
Image^ ScrollView::LayerContent::get() {
    return LayerContentImage;
}

// Accessor for our Layer content
bool ScrollView::HasLayerContent::get() {
    return true;
}

// Accessor for our SublayerCanvas
Canvas^ ScrollView::SublayerCanvas::get() {
    return ContentCanvas;
}

// Accessor for the LayerProperty that manages the BorderBrush of this label
Private::CoreAnimation::LayerProperty^ ScrollView::GetBorderBrushProperty() {
    return nullptr;
}

// Accessor for the LayerProperty that manages the BorderThickness of this label
Private::CoreAnimation::LayerProperty^ ScrollView::GetBorderThicknessProperty() {
    return nullptr;
}

ScrollViewer^ ScrollView::scrollViewer::get() {
    return this->ScrollViewer;
}

} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Xaml::ScrollView as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateScrollViewer(IInspectable** created) {
    ComPtr<IInspectable> inspectable = InspectableFromObject(ref new UIKit::Xaml::ScrollView());
    *created = inspectable.Detach();
}

// Retrieves the UIKit::Label's backing ScrollViewer as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetScrollViewer(const Microsoft::WRL::ComPtr<IInspectable>& scrollView) {
    auto scrollViewGrid = safe_cast<UIKit::Xaml::ScrollView^>(reinterpret_cast<Platform::Object^>(scrollView.Get()));
    return InspectableFromObject(scrollViewGrid->scrollViewer).Detach();
}

// clang-format on
