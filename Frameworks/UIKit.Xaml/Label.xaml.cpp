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
#include "Label.xaml.h"

#include "ObjCXamlControls.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

namespace UIKit {
namespace Xaml {

Label::Label() {
    InitializeComponent();
}

// Accessor for our Layer content
Image^ Label::LayerContent::get() {
    if (!_content) {
        _content = ref new Image();
        _content->Name = "LayerContent";
        Children->InsertAt(1, _content);
    }

    return _content;
}

// Accessor for our Layer content
bool Label::HasLayerContent::get() {
    return _content != nullptr;
}

// Accessor for our SublayerCanvas
Canvas^ Label::SublayerCanvas::get() {
    if (!_sublayerCanvas) {
        _sublayerCanvas = ref new Canvas();
        _sublayerCanvas->Name = "Sublayers";

        // If we have a border make sure the sublayer canvas is inserted before it
        if (_border) {
            unsigned int insertIndex = 0;
            Children->IndexOf(_border, &insertIndex);
            Children->InsertAt(insertIndex, _sublayerCanvas);
        } else {
            // Just add the sublayer canvas to the end because we don't yet have a border on this element
            Children->Append(_sublayerCanvas);
        }
    }

    return _sublayerCanvas;
}

Border^ Label::_GetBorder() {
    if (!_border) {
        // We always want the border added to the end of the Children collection
        _border = ref new Border();
        Children->Append(_border);
    }

    return _border;
}

// Accessor for the LayerProperty that manages the BorderBrush of this label
Private::CoreAnimation::LayerProperty^ Label::GetBorderBrushProperty() {
    // Make sure we have a border element, and return it along with its associated border property
    Border^ border = _GetBorder();
    return ref new Private::CoreAnimation::LayerProperty(border, border->BorderBrushProperty);
}

// Accessor for the LayerProperty that manages the BorderThickness of this label
Private::CoreAnimation::LayerProperty^ Label::GetBorderThicknessProperty() {
    // Make sure we have a border element, and return it along with its associated border property
    Border^ border = _GetBorder();
    return ref new Private::CoreAnimation::LayerProperty(border, border->BorderThicknessProperty);
}

Windows::Foundation::Size Label::ArrangeOverride(Windows::Foundation::Size finalSize) {
    // Make sure we render vertically-centered text if possible, else cap at the containing layer's height.
    // TODO: Issue #1946: Do we actually need this call to Measure?
    TextBlock->Measure(finalSize);
    if (TextBlock->DesiredSize.Height >= finalSize.Height) {
        TextBlock->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Top;
    } else {
        TextBlock->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
    }

    return __super::ArrangeOverride(finalSize);
}

TextBlock^ Label::TextBlock::get() {
    return safe_cast<Windows::UI::Xaml::Controls::TextBlock^>(Children->GetAt(0));
}

} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Label as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateLabel(IInspectable** created) {
    ComPtr<IInspectable> inspectable = InspectableFromObject(ref new UIKit::Xaml::Label());
    *created = inspectable.Detach();
}

// Retrieves the UIKit::Label's backing TextBlock as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetLabelTextBlock(const Microsoft::WRL::ComPtr<IInspectable>& label) {
    auto labelGrid = safe_cast<UIKit::Xaml::Label^>(reinterpret_cast<Platform::Object^>(label.Get()));
    return InspectableFromObject(labelGrid->TextBlock).Detach();
}

// clang-format on