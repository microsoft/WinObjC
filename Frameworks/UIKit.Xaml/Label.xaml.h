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

#include "Label.g.h"
#include "ILayer.h"

namespace UIKit {
namespace Xaml {

[Windows::Foundation::Metadata::WebHostHidden]
public ref class Label sealed : public Private::CoreAnimation::ILayer {
public:
    Label();
    Windows::Foundation::Size ArrangeOverride(Windows::Foundation::Size finalSize) override;

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

    // Accessor for the LayerProperty that manages the BorderBrush of this label
    virtual Private::CoreAnimation::LayerProperty^ GetBorderBrushProperty();

    // Accessor for the LayerProperty that manages the BorderThickness of this label
    virtual Private::CoreAnimation::LayerProperty^ GetBorderThicknessProperty();

internal:
    property Windows::UI::Xaml::Controls::TextBlock^ TextBlock {
        Windows::UI::Xaml::Controls::TextBlock^ get();
    }

private:
    Windows::UI::Xaml::Controls::Border^ _GetBorder();

    // Layer elements; created on demand
    Windows::UI::Xaml::Controls::Image^ _content;
    Windows::UI::Xaml::Controls::Canvas^ _sublayerCanvas;
    Windows::UI::Xaml::Controls::Border^ _border;
};

} /* Xaml*/
} /* UIKit*/

// clang-format on