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
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::UI::Xaml::Controls;

namespace UIKit {

static const float button_padding = 20.0f;

Button::Button() {
    InitializeComponent();
}

void Button::OnPointerPressed(PointerRoutedEventArgs^ e) {
    // Call the pointer hook if it exists
    if (_pointerPressedHook) {
        CapturePointer(e->Pointer);
        _pointerPressedHook->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(e).Get());
    }

    // If the pointer hook didn't handle the event, call into our base class
    if (!e->Handled) {
        __super::OnPointerPressed(e);
    }
}

void Button::OnPointerMoved(PointerRoutedEventArgs^ e) {
    // Call the pointer hook if it exists
    if (_pointerMovedHook) {
        _pointerMovedHook->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(e).Get());
    }

    // If the pointer hook didn't handle the event, call into our base class
    if (!e->Handled) {
        __super::OnPointerMoved(e);
    }
}

void Button::OnPointerReleased(PointerRoutedEventArgs^ e) {
    // Call the pointer hook if it exists
    if (_pointerReleasedHook) {
        _pointerReleasedHook->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(e).Get());
    }

    // If the pointer hook didn't handle the event, call into our base class
    if (!e->Handled) {
        __super::OnPointerReleased(e);
    }
}

void Button::OnPointerCanceled(PointerRoutedEventArgs^ e) {
    // Call the pointer hook if it exists
    if (_pointerCanceledHook) {
        _pointerCanceledHook->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(e).Get());
    }

    // Call into our base class regardless of whether or not the UIKit subclass, etc. 'handled' the event
    __super::OnPointerCanceled(e);
}

void Button::OnPointerCaptureLost(PointerRoutedEventArgs^ e) {
    // Call the pointer hook if it exists
    if (_pointerCaptureLostHook) {
        _pointerCaptureLostHook->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs>(e).Get());
    }

    // Call into our base class regardless of whether or not the UIKit subclass, etc. 'handled' the event
    __super::OnPointerCaptureLost(e);
}

// Hook pointer events
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
    UIKit::Button^ button = ref new UIKit::Button();
    return InspectableFromObject(button).Detach();
}

void Button::RemovePointerEvents() {
    _pointerPressedHook = nullptr;
    _pointerMovedHook = nullptr;
    _pointerReleasedHook =  nullptr;
    _pointerCanceledHook = nullptr;
    _pointerCaptureLostHook = nullptr;
}

UIKIT_XAML_EXPORT void XamlRemovePointerEvents(const ComPtr<IInspectable>& inspectableButton) {
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    button->RemovePointerEvents();
}

UIKIT_XAML_EXPORT void XamlHookButtonPointerEvents(
    const ComPtr<IInspectable>& inspectableButton,
    const ComPtr<IInspectable>& pointerPressedHook,
    const ComPtr<IInspectable>& pointerMovedHook,
    const ComPtr<IInspectable>& pointerReleasedHook,
    const ComPtr<IInspectable>& pointerCanceledHook,
    const ComPtr<IInspectable>& pointerCaptureLostHook) {

    // Now subscribe to the events on the actual button object
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    button->HookPointerEvents(
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerPressedHook),
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerMovedHook),
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerReleasedHook),
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerCanceledHook),
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(pointerCaptureLostHook));
}

}
// clang-format on