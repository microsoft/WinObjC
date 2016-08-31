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

// DependencyProperties for Button Image
DependencyProperty^ Button::s_buttonImageSourceNormalProperty = nullptr;
DependencyProperty^ Button::s_buttonImageSourcePressedProperty = nullptr;
DependencyProperty^ Button::s_buttonImageSourceDisabledProperty = nullptr;

// DependencyProperties for Button Image insets
DependencyProperty^ Button::s_buttonBackgroundInsetsProperty = nullptr;

// DependencyProperties for background Image
DependencyProperty^ Button::s_pressedBackgroundProperty = nullptr;
DependencyProperty^ Button::s_disabledBackgroundProperty = nullptr;
DependencyProperty^ Button::s_normalBackgroundProperty = nullptr;

// DependencyProperties for button text
DependencyProperty^ Button::s_normalTextProperty = nullptr;
DependencyProperty^ Button::s_pressedTextProperty = nullptr;
DependencyProperty^ Button::s_disabledTextProperty = nullptr;

// DependencyProperties for button text color
DependencyProperty^ Button::s_normalTextColorProperty = nullptr;
DependencyProperty^ Button::s_pressedTextColorProperty = nullptr;
DependencyProperty^ Button::s_disabledTextColorProperty = nullptr;

static const float button_padding = 20.0f;

// Method to get default text Foreground brush
Brush^ GetDefaultWhiteForegroundBrush() {
    static auto ret = ref new SolidColorBrush(Windows::UI::Colors::White);
    return ret;
}

Button::Button() {
    InitializeComponent();
    _registerDependencyProperties(); // No-op if already registered

    // Set the default Background image for all states as DefaultTransparentBackgroundImage.
    // Also, by default the values of PressedBackground and DisabledBackground is same as NormalBackground. This is the default on ios.
    NormalBackground = nullptr;
    PressedBackground = NormalBackground;
    DisabledBackground = NormalBackground;

    // Set the Title color to be DefaultWhiteForeground(white) by default. This is the default on ios.
    // Also, by default the values of PressedForeground and DisabledForeground is same as NormalForeground. This is the default on ios.
    NormalForeground = GetDefaultWhiteForegroundBrush();
    PressedForeground = NormalForeground;
    DisabledForeground = NormalForeground;
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

void Button::_registerDependencyProperties() {
    // Register DependencyProperties for Background Image
    if (!s_pressedBackgroundProperty) {
        s_pressedBackgroundProperty = DependencyProperty::Register(
            "PressedBackground",
            ImageSource::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_disabledBackgroundProperty) {
        s_disabledBackgroundProperty = DependencyProperty::Register(
            "DisabledBackground",
            ImageSource::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_normalBackgroundProperty) {
        s_normalBackgroundProperty = DependencyProperty::Register(
            "NormalBackground",
            ImageSource::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    // Register DependencyProperties for text color
    if (!s_normalTextColorProperty) {
        s_normalTextColorProperty = DependencyProperty::Register(
            "NormalForeground",
            Brush::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_pressedTextColorProperty) {
        s_pressedTextColorProperty = DependencyProperty::Register(
            "PressedForeground",
            Brush::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_disabledTextColorProperty) {
        s_disabledTextColorProperty = DependencyProperty::Register(
            "DisabledForeground",
            Brush::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    // Register DependencyProperties for text
    if (!s_normalTextProperty) {
        s_normalTextProperty = DependencyProperty::Register(
            "NormalText",
            String::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_pressedTextProperty) {
        s_pressedTextProperty = DependencyProperty::Register(
            "PressedText",
            String::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_disabledTextProperty) {
        s_disabledTextProperty = DependencyProperty::Register(
            "DisabledText",
            String::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_buttonImageSourceNormalProperty) {
        s_buttonImageSourceNormalProperty = DependencyProperty::Register(
            "ButtonImageSourceNormal",
            Windows::UI::Xaml::Media::Imaging::BitmapSource::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_buttonImageSourcePressedProperty) {
        s_buttonImageSourcePressedProperty = DependencyProperty::Register(
            "ButtonImageSourcePressed",
            Windows::UI::Xaml::Media::Imaging::BitmapSource::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_buttonImageSourceDisabledProperty) {
        s_buttonImageSourceDisabledProperty = DependencyProperty::Register(
            "ButtonImageSourceDisabled",
            Windows::UI::Xaml::Media::Imaging::BitmapSource::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }

    if (!s_buttonBackgroundInsetsProperty) {
        s_buttonBackgroundInsetsProperty = DependencyProperty::Register(
            "ButtonBackgroundInsets",
            Windows::UI::Xaml::Thickness::typeid,
            Windows::UI::Xaml::Controls::Button::typeid,
            nullptr);
    }
}

// Implementing getter and setters for button image for all states
Windows::UI::Xaml::Media::Imaging::BitmapSource^ Button::ButtonImageSourceNormal::get() {
    return dynamic_cast<Windows::UI::Xaml::Media::Imaging::BitmapSource^>(GetValue(ButtonImageSourceNormalProperty));
}

void Button::ButtonImageSourceNormal::set(Windows::UI::Xaml::Media::Imaging::BitmapSource^ value) {
    SetValue(ButtonImageSourceNormalProperty, value);
}

Windows::UI::Xaml::Media::Imaging::BitmapSource^ Button::ButtonImageSourcePressed::get() {
    return dynamic_cast<Windows::UI::Xaml::Media::Imaging::BitmapSource^>(GetValue(ButtonImageSourcePressedProperty));
}

void Button::ButtonImageSourcePressed::set(Windows::UI::Xaml::Media::Imaging::BitmapSource^ value) {
    SetValue(ButtonImageSourcePressedProperty, value);
}

Windows::UI::Xaml::Media::Imaging::BitmapSource^ Button::ButtonImageSourceDisabled::get() {
    return dynamic_cast<Windows::UI::Xaml::Media::Imaging::BitmapSource^>(GetValue(ButtonImageSourceDisabledProperty));
}

void Button::ButtonImageSourceDisabled::set(Windows::UI::Xaml::Media::Imaging::BitmapSource^ value) {
    SetValue(ButtonImageSourceDisabledProperty, value);
}

Windows::UI::Xaml::Thickness Button::ButtonBackgroundInsets::get() {
    return static_cast<Windows::UI::Xaml::Thickness>(GetValue(ButtonBackgroundInsetsProperty));
}

void Button::ButtonBackgroundInsets::set(Windows::UI::Xaml::Thickness value) {
    SetValue(ButtonBackgroundInsetsProperty, value);
}

// Implementing getter and setters for background image for all states
ImageSource^ Button::PressedBackground::get() {
    return dynamic_cast<ImageSource^>(GetValue(PressedBackgroundProperty));
}

void Button::PressedBackground::set(ImageSource^ value) {
    SetValue(PressedBackgroundProperty, value);
}


ImageSource^ Button::DisabledBackground::get() {
    return dynamic_cast<ImageSource^>(GetValue(DisabledBackgroundProperty));
}

void Button::DisabledBackground::set(ImageSource^ value) {
    SetValue(DisabledBackgroundProperty, value);
}

ImageSource^ Button::NormalBackground::get() {
    return dynamic_cast<ImageSource^>(GetValue(NormalBackgroundProperty));
}

void Button::NormalBackground::set(ImageSource^ value) {
    SetValue(NormalBackgroundProperty, value);
}

// Implementing getter and setters for text for all states
String^ Button::PressedText::get() {
    return dynamic_cast<String^>(GetValue(PressedTextProperty));
}

void Button::PressedText::set(String^ value) {
    SetValue(PressedTextProperty, value);
}

String^ Button::NormalText::get() {
    return dynamic_cast<String^>(GetValue(NormalTextProperty));
}

void Button::NormalText::set(String^ value) {
    SetValue(NormalTextProperty, value);
}

String^ Button::DisabledText::get() {
    return dynamic_cast<String^>(GetValue(DisabledTextProperty));
}

void Button::DisabledText::set(String^ value) {
    SetValue(DisabledTextProperty, value);
}

// Implementing getter and setters for text color for all states
Brush^ Button::NormalForeground::get() {
    return dynamic_cast<Brush^>(GetValue(NormalForegroundProperty));
}

void Button::NormalForeground::set(Brush^ value) {
    SetValue(NormalForegroundProperty, value);
}

Brush^ Button::PressedForeground::get() {
    return dynamic_cast<Brush^>(GetValue(PressedForegroundProperty));
}

void Button::PressedForeground::set(Brush^ value) {
    SetValue(PressedForegroundProperty, value);
}

Brush^ Button::DisabledForeground::get() {
    return dynamic_cast<Brush^>(GetValue(DisabledForegroundProperty));
}

void Button::DisabledForeground::set(Brush^ value) {
    SetValue(DisabledForegroundProperty, value);
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
    _layoutHook->Invoke(nullptr, nullptr);

    return finalSize;
}

// In ArrangeOverride we explicitly ask UIKit to invalidate the intrinsic content sizeof the UIButton.
// This method is then called by UIButton to get the intrinsic content size.
UIKIT_XAML_EXPORT SIZE XamlGetIntrinsicContentSizeFromXaml(const ComPtr<IInspectable>& inspectableButton) {
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));

    // get the size of image based on current state
    float imageWidth = button->imageSizeNormal.Width;
    float imageHeight = button->imageSizeNormal.Height;
    float backgroundWidth = button->backgroundSizeNormal.Width;
    float backgroundHeight = button->backgroundSizeNormal.Height;
    Platform::String^ text = button->NormalText;

    if (button->IsPressed) {
        imageWidth = button->imageSizePressed.Width;
        imageHeight = button->imageSizePressed.Height;
        text = button->PressedText;
        backgroundWidth = button->backgroundSizePressed.Width;
        backgroundHeight = button->backgroundSizePressed.Height;
    } else if (!button->IsEnabled) {
        imageWidth = button->imageSizeDisabled.Width;
        imageHeight = button->imageSizeDisabled.Height;
        text = button->DisabledText;
        backgroundWidth = button->backgroundSizeDisabled.Width;
        backgroundHeight = button->backgroundSizeDisabled.Height;
    }

    // XAML TextBlock uses the constraints set on the TextBlock to give its desired size. Rather we want
    // the textblock's desired size without any constraints for UIButton.
    // The sole purpose of this textblock is size calculation for UIButton without any constraints.
    static TextBlock^ textBlock = ref new TextBlock();
    textBlock->Text = text;
    static Windows::Foundation::Size infinity(FLT_MAX, FLT_MAX);
    textBlock->Measure(infinity);

    SIZE ret = { 0 };
    ret.cx = (LONG)(textBlock->DesiredSize.Width + imageWidth + button_padding);
    ret.cy = (LONG)(textBlock->DesiredSize.Height + imageHeight);

    if (backgroundWidth > ret.cx) {
        ret.cx = (LONG)backgroundWidth;
    }
    if (backgroundHeight > ret.cy) {
        ret.cy = (LONG)backgroundHeight;
    }

    return ret;
}

// Only UIControlStateNormal, UIControlStateHighlighted and UIControlStateDisabled states are supported
UIKIT_XAML_EXPORT void XamlSetButtonImage(const ComPtr<IInspectable>& inspectableButton,
    const ComPtr<IInspectable>& inspectableImage, int state, float width, float height) {
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    auto image = safe_cast<Brush^>(reinterpret_cast<Platform::Object^>(inspectableImage.Get()));

    Windows::UI::Xaml::Media::Imaging::BitmapSource^ bitmapSource = nullptr;
    if (image) {
        Windows::UI::Xaml::Media::ImageBrush^ imageBrush = (Windows::UI::Xaml::Media::ImageBrush^)image;
        bitmapSource = (Windows::UI::Xaml::Media::Imaging::BitmapSource^)(imageBrush->ImageSource);
    }

    switch(state) {
        case ControlStateNormal :
            button->imageSizeNormal.Width = width;
            button->imageSizeNormal.Height = height;

            button->ButtonImageSourceNormal = bitmapSource;

            // If image source for Pressed and Disabled states are nil, we use image source for normal state as fallback value.
            if (!button->ButtonImageSourcePressed) {
                button->ButtonImageSourcePressed = button->ButtonImageSourceNormal;
                button->imageSizePressed.Width = button->imageSizeNormal.Width;
                button->imageSizePressed.Height = button->imageSizeNormal.Height;
            }

            if (!button->ButtonImageSourceDisabled) {
                button->ButtonImageSourceDisabled = button->ButtonImageSourceNormal;
                button->imageSizeDisabled.Width = button->imageSizeNormal.Width;
                button->imageSizeDisabled.Height = button->imageSizeNormal.Height;
            }
            break;
        case ControlStateHighlighted :
            if (!bitmapSource) {
                button->ButtonImageSourcePressed = button->ButtonImageSourceNormal;
                button->imageSizePressed.Width = button->imageSizeNormal.Width;
                button->imageSizePressed.Height = button->imageSizeNormal.Height;
            } else {
                button->ButtonImageSourcePressed = bitmapSource;
                button->imageSizePressed.Width = width;
                button->imageSizePressed.Height = height;
            }
            break;
        case ControlStateDisabled :
            if (!bitmapSource) {
                button->ButtonImageSourceDisabled = button->ButtonImageSourceNormal;
                button->imageSizeDisabled.Width = button->imageSizeNormal.Width;
                button->imageSizeDisabled.Height = button->imageSizeNormal.Height;
            } else {
                button->ButtonImageSourceDisabled = bitmapSource;
                button->imageSizeDisabled.Width = width;
                button->imageSizeDisabled.Height = height;
            }
            break;
        default:
            break;
    }
}

// Only UIControlStateNormal, UIControlStateHighlighted and UIControlStateDisabled states are supported
// TODO: insets only get set once on Normal state, all others are assumed to have the same insets, this 
// will be ameliorated when UIKit::Image work completes
UIKIT_XAML_EXPORT void XamlSetBackgroundImage(const ComPtr<IInspectable>& inspectableButton,
    const ComPtr<IInspectable>& inspectableBackground, int state, float width, float height, const RECT insets) {
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    auto backgroundImage = safe_cast<ImageSource^>(reinterpret_cast<Platform::Object^>(inspectableBackground.Get()));

    switch(state) {
        case ControlStateNormal :
            button->NormalBackground = backgroundImage;
            button->backgroundSizeNormal.Width = width;
            button->backgroundSizeNormal.Height = height;
            button->ButtonBackgroundInsets = ThicknessHelper::FromLengths(insets.left, insets.top, insets.right, insets.bottom);

            // If PressedBackground or DisabledBackground is transparent, which is equivalent to nil for iOS, we use NormalBackground as fallback value.
            // This is the default behavior on iOS platform.
            // The background width and height are used for intrinsic content size calculation of UIButton
            if (!button->PressedBackground) {
                button->PressedBackground = button->NormalBackground;
                button->backgroundSizePressed.Width = button->backgroundSizeNormal.Width;
                button->backgroundSizePressed.Height = button->backgroundSizeNormal.Height;
            }

            if (!button->DisabledBackground) {
                button->DisabledBackground = button->NormalBackground;
                button->backgroundSizeDisabled.Width = button->backgroundSizeNormal.Width;
                button->backgroundSizeDisabled.Height = button->backgroundSizeNormal.Height;
            }
            break;
        case ControlStateHighlighted :
            if (!backgroundImage) {
                button->PressedBackground = button->NormalBackground;
                button->backgroundSizePressed.Width = button->backgroundSizeNormal.Width;
                button->backgroundSizePressed.Height = button->backgroundSizeNormal.Height;
            } else {
                button->PressedBackground = backgroundImage;
                button->backgroundSizePressed.Width = width;
                button->backgroundSizePressed.Height = height;
            }
            break;
        case ControlStateDisabled :
            if (!backgroundImage) {
                button->DisabledBackground = button->NormalBackground;
                button->backgroundSizeDisabled.Width = button->backgroundSizeNormal.Width;
                button->backgroundSizeDisabled.Height = button->backgroundSizeNormal.Height;
            } else {
                button->DisabledBackground = backgroundImage;
                button->backgroundSizeDisabled.Width = width;
                button->backgroundSizeDisabled.Height = height;
            }
            break;
        default:
            break;
    }
}

// Only UIControlStateNormal, UIControlStateHighlighted and UIControlStateDisabled states are supported
UIKIT_XAML_EXPORT void XamlSetTitleForState(const ComPtr<IInspectable>& inspectableButton,
    const ComPtr<IInspectable>& inspectableText, int state) {
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    auto title = safe_cast<Platform::String^>(reinterpret_cast<Platform::Object^>(inspectableText.Get()));

    switch(state) {
        case ControlStateNormal :
            button->NormalText = title;

            // If no other Title is set for other states, then NormalText will be used, this is the behavior on ios platform
            if (!button->PressedText) {
                button->PressedText = title;
            }

            if (!button->DisabledText) {
                button->DisabledText = title;
            }
            break;
        case ControlStateHighlighted :
            button->PressedText = title;
            break;
        case ControlStateDisabled :
            button->DisabledText = title;
            break;
        default:
            break;
    }
}

// Only UIControlStateNormal, UIControlStateHighlighted and UIControlStateDisabled states are supported
UIKIT_XAML_EXPORT void XamlSetTitleColorForState(const ComPtr<IInspectable>& inspectableButton,
    const ComPtr<IInspectable>& inspectableTitleColor, int state) {
    auto button = safe_cast<UIKit::Button^>(reinterpret_cast<Platform::Object^>(inspectableButton.Get()));
    auto titleColor = safe_cast<Brush^>(reinterpret_cast<Platform::Object^>(inspectableTitleColor.Get()));
    
    if (!titleColor) {
        titleColor = GetDefaultWhiteForegroundBrush();
    }

    switch(state) {
        case ControlStateNormal :
            button->NormalForeground = titleColor;

            // If no other title color is set for other states, then NormalForeground will be used
            if (button->PressedForeground == GetDefaultWhiteForegroundBrush()) {
                button->PressedForeground = titleColor;
            }

            if (button->DisabledForeground == GetDefaultWhiteForegroundBrush()) {
                button->DisabledForeground = titleColor;
            }
            break;
        case ControlStateHighlighted :
            button->PressedForeground = titleColor;
            break;
        case ControlStateDisabled :
            button->DisabledForeground = titleColor;
            break;
        default:
            break;
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