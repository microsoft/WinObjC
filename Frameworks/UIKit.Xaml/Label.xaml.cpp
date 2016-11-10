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
        Children->Append(_sublayerCanvas);
    }

    return _sublayerCanvas;
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
UIKIT_XAML_EXPORT IInspectable* XamlCreateLabel() {
    return InspectableFromObject(ref new UIKit::Xaml::Label()).Detach();
}

// Retrieves the UIKit::Label's backing TextBlock as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetLabelTextBox(const Microsoft::WRL::ComPtr<IInspectable>& label) {
    auto labelGrid = safe_cast<UIKit::Xaml::Label^>(reinterpret_cast<Platform::Object^>(label.Get()));
    return InspectableFromObject(labelGrid->TextBlock).Detach();
}
