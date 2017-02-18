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
#pragma once

#include "Layer.g.h"

namespace UIKit {
namespace Xaml {
namespace Private {
namespace CoreAnimation {

// Pairs a DependencyProperty and its associated DependencyObject for setting/getting values on objects within an ILayer instance.
// For example, can wrap an internal FrameworkElement and its associated BorderBrushProperty.
[Windows::Foundation::Metadata::WebHostHidden]
public ref class LayerProperty sealed {
public:
    LayerProperty(Windows::UI::Xaml::DependencyObject^ target, Windows::UI::Xaml::DependencyProperty^ property);

    void SetValue(Platform::Object^ value);
    Platform::Object^ GetValue();

private:
    Windows::UI::Xaml::DependencyObject^ _target;
    Windows::UI::Xaml::DependencyProperty^ _property;
};

[Windows::Foundation::Metadata::WebHostHidden]
public interface class ILayer {
public:
    // Accessor for our Layer content; we create one on demand
    property Windows::UI::Xaml::Controls::Image^ LayerContent {
        Windows::UI::Xaml::Controls::Image^ get();
    }

    // Accessor to check for exising Layer content
    property bool HasLayerContent {
        bool get();
    }

    // Accessor for our SublayerCanvas; we create one on demand
    property Windows::UI::Xaml::Controls::Canvas^ SublayerCanvas {
        Windows::UI::Xaml::Controls::Canvas^ get();
    }

    // Accessor for the LayerProperty that manages the BorderBrush of this layer
    LayerProperty^ GetBorderBrushProperty();

    // Accessor for the LayerProperty that manages the BorderThickness of this layer
    LayerProperty^ GetBorderThicknessProperty();
};

[Windows::Foundation::Metadata::WebHostHidden]
public ref class Layer sealed : public ILayer {
public:
    Layer();

    // Accessor for our Layer content; we create one on demand
    virtual property Windows::UI::Xaml::Controls::Image^ LayerContent {
        Windows::UI::Xaml::Controls::Image^ get();
    }

    // Accessor to check for exising Layer content
    virtual property bool HasLayerContent {
        bool get();
    }

    // Accessor for our SublayerCanvas; we create one on demand
    virtual property Windows::UI::Xaml::Controls::Canvas^ SublayerCanvas {
        Windows::UI::Xaml::Controls::Canvas^ get();
    }

    // Accessor for the LayerProperty that manages the BorderBrush of this layer
    virtual LayerProperty^ GetBorderBrushProperty();

    // Accessor for the LayerProperty that manages the BorderThickness of this layer
    virtual LayerProperty^ GetBorderThicknessProperty();

    // Allows arbitrary framework elements to opt-into hosting layer content
    static property Windows::UI::Xaml::DependencyProperty^ LayerContentProperty {
        Windows::UI::Xaml::DependencyProperty^ get();
    }

    // Allows arbitrary framework elements to opt-into hosting sublayers
    static property Windows::UI::Xaml::DependencyProperty^ SublayerCanvasProperty {
        Windows::UI::Xaml::DependencyProperty^ get();
    }

internal:
    // Static entry point to register our dependency properties
    static void _RegisterDependencyProperties();

private:
    // Layer elements; created on demand
    Windows::UI::Xaml::Controls::Image^ _content;

    // Dependency properties for adding layer-like functionality to any FrameworkElement
    static bool s_dependencyPropertiesRegistered;
    static Windows::UI::Xaml::DependencyProperty^ s_layerContentProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_sublayerCanvasProperty;
};

} /* CoreAnimation */
} /* Private */
} /* Xaml*/
} /* UIKit*/
