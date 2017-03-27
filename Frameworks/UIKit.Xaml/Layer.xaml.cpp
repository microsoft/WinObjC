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
// clang-format does not like C++/CX
// clang-format off
#include "pch.h"
#include "Layer.xaml.h"

#include "ObjCXamlControls.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

namespace UIKit {
namespace Xaml {
namespace Private {
namespace CoreAnimation {

DependencyProperty^ Layer::s_layerContentProperty = nullptr;
DependencyProperty^ Layer::s_sublayerCanvasProperty = nullptr;
bool Layer::s_dependencyPropertiesRegistered = false;

Layer::Layer() {
    InitializeComponent();

    // No-op if already registered
    _RegisterDependencyProperties();

    Name = L"Layer";

    // Default to a transparent background brush so we can accept pointer input
    static auto transparentBrush = ref new SolidColorBrush(Windows::UI::Colors::Transparent);
    Background = transparentBrush;
}

Windows::Foundation::Size Layer::ArrangeOverride(Windows::Foundation::Size finalSize) {
    // Keep our border dimensions in synch
    if (_border) {
        _border->Width = finalSize.Width;
        _border->Height = finalSize.Height;
    }

    return __super::ArrangeOverride(finalSize);
}

// Accessor for our Layer content
Image^ Layer::LayerContent::get() {
    if (!_content) {
        _content = ref new Image();
        _content->Name = "LayerContent";

        // Layer content is behind any sublayers
        Children->InsertAt(0, _content);
    }

    return _content;
}

// Accessor for our Layer content
bool Layer::HasLayerContent::get() {
    return _content != nullptr;
}

// Accessor for our SublayerCanvas
Canvas^ Layer::SublayerCanvas::get() {
    // We *are* the sublayer canvas
    return this;
}

void Layer::_EnsureBorder() {
    // If we don't have a border, create one and add it to our Children collection
    if (!_border) {
        _border = ref new Border();

        // Make sure the border is always in front of all other content
        _border->SetValue(Canvas::ZIndexProperty, 1000);

        Children->Append(_border);
    }
}

// Accessor for the LayerProperty that manages the BorderBrush of this layer
LayerProperty^ Layer::GetBorderBrushProperty() {
    _EnsureBorder();
    return ref new Private::CoreAnimation::LayerProperty(_border, _border->BorderBrushProperty);
}

// Accessor for the LayerProperty that manages the BorderThickness of this layer
LayerProperty^ Layer::GetBorderThicknessProperty() {
    _EnsureBorder();
    return ref new Private::CoreAnimation::LayerProperty(_border, _border->BorderThicknessProperty);
}

DependencyProperty^ Layer::LayerContentProperty::get() {
    return s_layerContentProperty;
}

DependencyProperty^ Layer::SublayerCanvasProperty::get() {
    return s_sublayerCanvasProperty;
}

void Layer::_RegisterDependencyProperties() {
    if (!s_dependencyPropertiesRegistered) {
        s_layerContentProperty = DependencyProperty::RegisterAttached("LayerContent",
            Image::typeid,
            FrameworkElement::typeid,
            nullptr);

        s_sublayerCanvasProperty = DependencyProperty::RegisterAttached("SublayerCanvas",
            Canvas::typeid,
            FrameworkElement::typeid,
            nullptr);

        s_dependencyPropertiesRegistered = true;
    }
}

} /* CoreAnimation */
} /* Private */
} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////

// Initializes our library for use; registers dependency properties, etc.
UIKIT_XAML_EXPORT void UIKitXamlInitialize() {
    UIKit::Xaml::Private::CoreAnimation::Layer::_RegisterDependencyProperties();
}

// Set one or more layer properties for the specified target xaml element
UIKIT_XAML_EXPORT void XamlSetFrameworkElementLayerProperties(
    const Microsoft::WRL::ComPtr<IInspectable>& targetElement,
    const Microsoft::WRL::ComPtr<IInspectable>& layerContentProperty,
    const Microsoft::WRL::ComPtr<IInspectable>& sublayerCanvasProperty) {

    auto frameworkElement = safe_cast<FrameworkElement^>(reinterpret_cast<Object^>(targetElement.Get()));
    if (layerContentProperty) {
        auto contentImage = safe_cast<Image^>(reinterpret_cast<Object^>(layerContentProperty.Get()));
        frameworkElement->SetValue(UIKit::Xaml::Private::CoreAnimation::Layer::LayerContentProperty, contentImage);
    }

    if (sublayerCanvasProperty) {
        auto sublayerCanvas = safe_cast<Canvas^>(reinterpret_cast<Object^>(sublayerCanvasProperty.Get()));
        frameworkElement->SetValue(UIKit::Xaml::Private::CoreAnimation::Layer::SublayerCanvasProperty, sublayerCanvas);
    }
}

// Get the layerContentProperty for the specified target xaml element
UIKIT_XAML_EXPORT IInspectable* XamlGetFrameworkElementLayerContentProperty(const Microsoft::WRL::ComPtr<IInspectable>& targetElement) {
    auto frameworkElement = safe_cast<FrameworkElement^>(reinterpret_cast<Object^>(targetElement.Get()));
    return InspectableFromObject(frameworkElement->GetValue(UIKit::Xaml::Private::CoreAnimation::Layer::LayerContentProperty)).Detach();
}

// Get the sublayerCanvasProperty for the specified target xaml element
UIKIT_XAML_EXPORT IInspectable* XamlGetFrameworkElementSublayerCanvasProperty(const Microsoft::WRL::ComPtr<IInspectable>& targetElement) {
    auto frameworkElement = safe_cast<FrameworkElement^>(reinterpret_cast<Object^>(targetElement.Get()));
    return InspectableFromObject(frameworkElement->GetValue(UIKit::Xaml::Private::CoreAnimation::Layer::SublayerCanvasProperty)).Detach();
}