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
#include "TextField.xaml.h"

#include "ObjCXamlControls.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

namespace UIKit {
namespace Xaml {

TextField::TextField() {
    InitializeComponent();
}

// Accessor for our Layer content
Image^ TextField::LayerContent::get() {
    if (!_content) {
        _content = ref new Image();
        _content->Name = "LayerContent";

        // Layer content is behind any sublayers
        textFieldCanvas->Children->InsertAt(0, _content);
    }

    return _content;
}

// Accessor for our Layer content
bool TextField::HasLayerContent::get() {
    return _content != nullptr;
}

// Accessor for our SublayerCanvas
Canvas^ TextField::SublayerCanvas::get() {
    return textFieldCanvas;
}

// Accessor for the LayerProperty that manages the BorderBrush of this TextField
Private::CoreAnimation::LayerProperty^ TextField::GetBorderBrushProperty() {
    return nullptr;
}

// Accessor for the LayerProperty that manages the BorderThickness of this TextField
Private::CoreAnimation::LayerProperty^ TextField::GetBorderThicknessProperty() {
    return nullptr;
}

void TextField::SetSecureTextEntryValue(bool secureTextEntry) {
    // Need to remove const-ness while also converting it to Control^
    Control^ control = dynamic_cast<Control^>(this);
    if (control) {
        VisualStateManager::GoToState(control, secureTextEntry ? "PasswordBoxVisible" : "TextBoxVisible", false);
    }
}

TextBox^ TextField::TextBox::get() {
    return textFieldTB;
}

PasswordBox^ TextField::PasswordBox::get() {
    return textFieldPB;
}

} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Xaml::TextField as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateTextField(IInspectable** created) {
    ComPtr<IInspectable> inspectable = InspectableFromObject(ref new UIKit::Xaml::TextField());
    *created = inspectable.Detach();
}

// Returns a UIKit::Xaml::TextField's backing Canvas as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldSubLayerCanvas(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return InspectableFromObject(textField->SublayerCanvas).Detach();
}

// Retrieves the UIKit::Xaml::TextField's backing TextBox as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldTextBox(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return InspectableFromObject(textField->TextBox).Detach();
}

// Retrieves the UIKit::Xaml::TextField's backing PasswordBox as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldPasswordBox(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return InspectableFromObject(textField->PasswordBox).Detach();
}

// Set the UIKit::Xaml::TextField's secureTextEntry property
UIKIT_XAML_EXPORT void XamlSetTextFieldSecureTextEntryValue(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField, bool secureTextEntry) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->SetSecureTextEntryValue(secureTextEntry);
}
