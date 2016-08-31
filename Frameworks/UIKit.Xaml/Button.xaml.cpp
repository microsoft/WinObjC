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
#include "Button.xaml.h"

using namespace Microsoft::WRL;
using namespace Windows::UI::Xaml::Input;

namespace UIKit {

Button::Button() {
    InitializeComponent();
}

//////////////////////////////////////////////////////
// TODO: Implement derived XAML control functionality
//////////////////////////////////////////////////////

void Button::OnPointerPressed(PointerRoutedEventArgs^ e) {
    // Call the pointer hook if it exists
    if (_pointerPressedHook) {
        _pointerPressedHook->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(e).Get());
    }

    // If the pointer hook didn't handle the event, call into our base class
    if (!e->Handled) {
        __super::OnPointerPressed(e);
    }
}

void Button::HookPointerEvents(
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerPressedHook,
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerMovedHook,
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerReleasedHook,
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerCanceledHook,
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerCaptureLostHook) {
    _pointerPressedHook = std::move(pointerPressedHook);
    _pointerMovedHook = std::move(pointerMovedHook);
    _pointerReleasedHook = std::move(pointerReleasedHook);
    _pointerCanceledHook = std::move(pointerCanceledHook);
    _pointerCaptureLostHook = std::move(pointerCaptureLostHook);
}

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////
UIKIT_XAML_EXPORT IInspectable* XamlCreateButton() {
    return InspectableFromObject(ref new UIKit::Button()).Detach();
}

UIKIT_XAML_EXPORT void XamlHookButtonPointerEvents(
    const ComPtr<IInspectable>& inspectableButton,
    const ComPtr<IInspectable>& pointerPressedHook,
    const ComPtr<IInspectable>& pointerMovedHook,
    const ComPtr<IInspectable>& pointerReleasedHook,
    const ComPtr<IInspectable>& pointerCanceledHook,
    const ComPtr<IInspectable>& pointerCaptureLostHook) {

    // Now subscribe to the events on the actual button object
    auto button = static_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    button->HookPointerEvents(
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerPressedHook),
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerMovedHook),
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerReleasedHook),
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerCanceledHook),
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerCaptureLostHook));
}

}
// clang-format on
