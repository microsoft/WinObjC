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

// Method to get default text Foreground brush
Brush^ GetDefaultWhiteForegroundBrush() {
    static auto ret = ref new SolidColorBrush(Windows::UI::Colors::White);
    return ret;
}

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

// Hook other events
void Button::HookLayoutEvent(
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& layoutHook) {
    _layoutHook = std::move(layoutHook);
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

void Button::RemoveLayoutEvent() {
    _layoutHook = nullptr;
}

UIKIT_XAML_EXPORT void XamlRemovePointerEvents(const ComPtr<IInspectable>& inspectableButton) {
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    button->RemovePointerEvents();
}

UIKIT_XAML_EXPORT void XamlRemoveLayoutEvent(const ComPtr<IInspectable>& inspectableButton) {
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    button->RemoveLayoutEvent();
}

// This method is called multiple times by XAML, and we call back to UIButton to layout the views.
// This will be used by autolayout to get the intrinsic content size when XAML has done calculating the elements final desired size.
Windows::Foundation::Size Button::ArrangeOverride(Windows::Foundation::Size finalSize) {
    __super::ArrangeOverride(finalSize);
	if (_layoutHook) {
		_layoutHook->Invoke(nullptr, nullptr);
	}

    return finalSize;
}

void Button::OnApplyTemplate() {
    // Call GetTemplateChild to grab references to UIElements in our custom control template
    _textBlock = safe_cast<TextBlock^>(GetTemplateChild("buttonText"));
    _image = safe_cast<Image^>(GetTemplateChild("buttonImage"));
    _backgroundImage = safe_cast<Image^>(GetTemplateChild("backgroundImage"));
}

UIKIT_XAML_EXPORT void XamlButtonApplyVisuals(const ComPtr<IInspectable>& inspectableButton,
    const ComPtr<IInspectable>& inspectableText,
    const ComPtr<IInspectable>& inspectableButtonImage,
    const ComPtr<IInspectable>& inspectableBackgroundImage,
    const RECT insets,
    const ComPtr<IInspectable>& inspectableTitleColor) {

    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    auto title = safe_cast<Platform::String^>(reinterpret_cast<Platform::Object^>(inspectableText.Get()));
    auto titleColor = safe_cast<Brush^>(reinterpret_cast<Platform::Object^>(inspectableTitleColor.Get()));
    if (!titleColor) {
        titleColor = GetDefaultWhiteForegroundBrush();
    }

    // Set the Textblock's title and Foreground Brush color
    button->_textBlock->Text = title;
    button->_textBlock->Foreground = titleColor;

    // Set the background Image and its nine grid
    auto backgroundImage = safe_cast<Brush^>(reinterpret_cast<Platform::Object^>(inspectableBackgroundImage.Get()));
    if (backgroundImage) {
        ImageBrush^ backgroundImageBrush = safe_cast<ImageBrush^>(backgroundImage);
        button->_backgroundImage->Source = safe_cast<BitmapSource^>(backgroundImageBrush->ImageSource);;

        // Set the NineGrid on the Button's background image which is actually a XAML Image in the Control Template
        button->_backgroundImage->NineGrid = ThicknessHelper::FromLengths(insets.left, insets.top, insets.right, insets.bottom);
    }

    // Set the Button's Image
    auto image = safe_cast<Brush^>(reinterpret_cast<Platform::Object^>(inspectableButtonImage.Get()));
    if (image) {
        ImageBrush^ imageBrush = safe_cast<ImageBrush^>(image);
        button->_image->Source = safe_cast<BitmapSource^>(imageBrush->ImageSource);
    }
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

UIKIT_XAML_EXPORT void XamlHookLayoutEvent(const ComPtr<IInspectable>& inspectableButton,
                                                   const ComPtr<IInspectable>&  layoutHook) {
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    button->HookLayoutEvent(
        InspectableToType<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>(layoutHook));
    
}

}
// clang-format on