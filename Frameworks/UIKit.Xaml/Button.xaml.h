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

#include "Button.g.h"
#include <windows.ui.xaml.input.h>
#include "ObjCXamlControls.h"

namespace UIKit {

[Windows::Foundation::Metadata::WebHostHidden]
public ref class Button sealed {
public:
    Button();
    Windows::Foundation::Size ArrangeOverride(Windows::Foundation::Size finalSize) override;
    void OnPointerPressed(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerMoved(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerReleased(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerCanceled(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerCaptureLost(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;

    // Dependency properties for backing button image for different states
    static property Windows::UI::Xaml::DependencyProperty^ ButtonImageSourceNormalProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_buttonImageSourceNormalProperty;
        }
    }

    static property Windows::UI::Xaml::DependencyProperty^ ButtonImageSourcePressedProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_buttonImageSourcePressedProperty;
        }
    }

    static property Windows::UI::Xaml::DependencyProperty^ ButtonImageSourceDisabledProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_buttonImageSourceDisabledProperty;
        }
    }

    static property Windows::UI::Xaml::DependencyProperty^ ButtonBackgroundInsetsProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_buttonBackgroundInsetsProperty;
        }
    }

    // Button image for all states : Normal, Pressed and Disabled
    property Windows::UI::Xaml::Media::Imaging::BitmapSource^ ButtonImageSourceNormal {
        Windows::UI::Xaml::Media::Imaging::BitmapSource^ get();
        void set(Windows::UI::Xaml::Media::Imaging::BitmapSource^ value);
    }

    property Windows::UI::Xaml::Media::Imaging::BitmapSource^ ButtonImageSourcePressed {
        Windows::UI::Xaml::Media::Imaging::BitmapSource^ get();
        void set(Windows::UI::Xaml::Media::Imaging::BitmapSource^ value);
    }

    property Windows::UI::Xaml::Media::Imaging::BitmapSource^ ButtonImageSourceDisabled {
        Windows::UI::Xaml::Media::Imaging::BitmapSource^ get();
        void set(Windows::UI::Xaml::Media::Imaging::BitmapSource^ value);
    }

    property Windows::UI::Xaml::Thickness ButtonBackgroundInsets {
        Windows::UI::Xaml::Thickness get();
        void set(Windows::UI::Xaml::Thickness value);
    }

    // Dependency properties for backing background image for different states
    static property Windows::UI::Xaml::DependencyProperty^ PressedBackgroundProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_pressedBackgroundProperty;
        }
    }

    static property Windows::UI::Xaml::DependencyProperty^ DisabledBackgroundProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_disabledBackgroundProperty;
        }
    }

    static property Windows::UI::Xaml::DependencyProperty^ NormalBackgroundProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_normalBackgroundProperty;
        }
    }

    // Background for all states : Pressed, Normal and Disabled
    property Windows::UI::Xaml::Media::ImageSource^ PressedBackground {
        Windows::UI::Xaml::Media::ImageSource^ get();
        void set(Windows::UI::Xaml::Media::ImageSource^ value);
    }

    property Windows::UI::Xaml::Media::ImageSource^ DisabledBackground {
        Windows::UI::Xaml::Media::ImageSource^ get();
        void set(Windows::UI::Xaml::Media::ImageSource^ value);
    }

    property Windows::UI::Xaml::Media::ImageSource^ NormalBackground {
        Windows::UI::Xaml::Media::ImageSource^ get();
        void set(Windows::UI::Xaml::Media::ImageSource^ value);
    }

    // Dependency properties for backing text for different states
    static property Windows::UI::Xaml::DependencyProperty^ PressedTextProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_pressedTextProperty;
        }
    }

    static property Windows::UI::Xaml::DependencyProperty^ NormalTextProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_normalTextProperty;
        }
    }

    static property Windows::UI::Xaml::DependencyProperty^ DisabledTextProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_disabledTextProperty;
        }
    }

    // Text for all states : Pressed, Normal and Disabled
    property Platform::String^ PressedText {
        Platform::String^ get();
        void set(Platform::String^ value);
    }

    property Platform::String^ NormalText {
        Platform::String^ get();
        void set(Platform::String^ value);
    }

    property Platform::String^ DisabledText {
        Platform::String^ get();
        void set(Platform::String^ value);
    }

    // Dependency properties for backing text color for different states
    static property Windows::UI::Xaml::DependencyProperty^ NormalForegroundProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_normalTextColorProperty;
        }
    }

    static property Windows::UI::Xaml::DependencyProperty^ PressedForegroundProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_pressedTextColorProperty;
        }
    }

    static property Windows::UI::Xaml::DependencyProperty^ DisabledForegroundProperty {
        Windows::UI::Xaml::DependencyProperty^ get() {
            return s_disabledTextColorProperty;
        }
    }

    // TextColor for all states : Pressed, Normal and Disabled
    property Windows::UI::Xaml::Media::Brush^ NormalForeground {
        Windows::UI::Xaml::Media::Brush^ get();
        void set(Windows::UI::Xaml::Media::Brush^ value);
    }

    property Windows::UI::Xaml::Media::Brush^ PressedForeground {
        Windows::UI::Xaml::Media::Brush^ get();
        void set(Windows::UI::Xaml::Media::Brush^ value);
    }

    property Windows::UI::Xaml::Media::Brush^ DisabledForeground {
        Windows::UI::Xaml::Media::Brush^ get();
        void set(Windows::UI::Xaml::Media::Brush^ value);
    }

internal:
    // Setting the image width and height to 0. This will be updated once setImage:forState is called in UIButton
    // This data will be used for the calculation of intrinsicContentSize of UIButton.
    Windows::Foundation::Size imageSizeNormal = { 0, 0 };
    Windows::Foundation::Size imageSizePressed = { 0, 0 };
    Windows::Foundation::Size imageSizeDisabled = { 0, 0 };

    // Setting the background width and height to 0. This will be updated once setBackgroundImage:forState is called in UIButton
    // This data will be used for the calculation of intrinsicContentSize of UIButton.
    Windows::Foundation::Size backgroundSizeNormal = { 0, 0 };
    Windows::Foundation::Size backgroundSizePressed = { 0, 0 };
    Windows::Foundation::Size backgroundSizeDisabled = { 0, 0 };

    void HookPointerEvents(
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerPressedHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerMovedHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerReleasedHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerCanceledHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerCaptureLostHook);

    void HookLayoutEvent(
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& layoutHook);

    // methods for removing registered events
    void RemovePointerEvents();
    void RemoveLayoutEvent();

private:

    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerPressedHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerMovedHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerReleasedHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerCanceledHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerCaptureLostHook;

    // Auto Layout hook, change name and type later
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _layoutHook;

    // DependencyProperties for background image
    static void _registerDependencyProperties();
    static Windows::UI::Xaml::DependencyProperty^ s_pressedBackgroundProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_disabledBackgroundProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_normalBackgroundProperty;
    
    // TODO: This will move to UIKit::Image when that becomes available
    static Windows::UI::Xaml::DependencyProperty^ s_buttonBackgroundInsetsProperty;

    // DependencyProperties for text
    static Windows::UI::Xaml::DependencyProperty^ s_pressedTextProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_normalTextProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_disabledTextProperty;

    // DependencyProperties for text color
    static Windows::UI::Xaml::DependencyProperty^ s_pressedTextColorProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_normalTextColorProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_disabledTextColorProperty;

    // DependencyProperties for Button image
    static Windows::UI::Xaml::DependencyProperty^ s_buttonImageSourceNormalProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_buttonImageSourcePressedProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_buttonImageSourceDisabledProperty;
};

}
// clang-format on