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

#include "TextField.g.h"
#include "Layer.xaml.h"
#include <windows.ui.xaml.h>

namespace UIKit {
namespace Xaml {

public enum class TextBorderStyle {
    BorderStyleNone,
    BorderStyleLine,
    UITextBorderStyleBezel,
    UITextBorderStyleRoundedRect
};

[Windows::Foundation::Metadata::WebHostHidden]
public ref class TextField sealed : public Private::CoreAnimation::ILayer {
public:
    TextField();

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

    // Accessor for the LayerProperty that manages the BorderBrush of this TextField
    virtual Private::CoreAnimation::LayerProperty^ GetBorderBrushProperty();

    // Accessor for the LayerProperty that manages the BorderThickness of this TextField
    virtual Private::CoreAnimation::LayerProperty^ GetBorderThicknessProperty();

    property Platform::String^ TextField_Text
    {
        Platform::String^ get()
        {
            return (Platform::String^)GetValue(s_textProperty);
        }
        void set(Platform::String^ value)
        {
            SetValue(s_textProperty, value);
        }
    }

    property bool SecureEntry
    {
        Platform::Boolean get()
        {
            return _secureEntry;
        }
        void set(Platform::Boolean value)
        {
            _secureEntry = value;
            _SwitchToMode(_secureEntry);
        }
    }

    property Platform::String^ Placeholder
    {
        Platform::String^ get()
        {
            return _placeholder;
        }
        void set(Platform::String^ value)
        {
            _placeholder = value;
            _SetPlaceHolder();
        }
    }

    property Windows::UI::Xaml::Input::InputScopeNameValue InputScopeNameValue {
        Windows::UI::Xaml::Input::InputScopeNameValue get()
        {
            return _inputScopeNameValue;
        }

        void set(Windows::UI::Xaml::Input::InputScopeNameValue value)
        {
            _inputScopeNameValue = value;
            _SetInputScope();
        }
    }

    property bool Enabled
    {
        Platform::Boolean get()
        {
            return _enabled;
        }
        void set(Platform::Boolean value)
        {
            _enabled = value;
            _SetEnabled();
        }
    }

    property Windows::UI::Xaml::Media::SolidColorBrush^ Foreground
    {
        Windows::UI::Xaml::Media::SolidColorBrush^ get()
        {
            return _foreground;
        }
        void set(Windows::UI::Xaml::Media::SolidColorBrush^ value)
        {
            _foreground = value;
            _SetForeground();
        }
    }

    property Windows::UI::Xaml::TextAlignment TextAlignment
    {
        Windows::UI::Xaml::TextAlignment get()
        {
            return _textAlignment;
        }
        void set(Windows::UI::Xaml::TextAlignment value)
        {
            _textAlignment = value;
            _SetTextAlignment();
        }
    }

    property Platform::Boolean Editing
    {
        Platform::Boolean get()
        {
            if (_backingControl) {
                return (_backingControl->FocusState != Windows::UI::Xaml::FocusState::Unfocused);
            }

            return false;
        }
    }

    property Windows::UI::Xaml::VerticalAlignment VerticalTextAlignment
    {
        Windows::UI::Xaml::VerticalAlignment get()
        {
            return _textVerticalAlignment;
        }
        void set(Windows::UI::Xaml::VerticalAlignment value)
        {
            _textVerticalAlignment = value;
            _SetTextVerticalAlignment();
        }
    }

    property UIKit::Xaml::TextBorderStyle BorderStyle
    {
        UIKit::Xaml::TextBorderStyle get()
        {
            return _borderStyle;
        }
        void set(UIKit::Xaml::TextBorderStyle value)
        {
            _borderStyle = value;
            _SetBorderStyle();
        }
    }

    void ApplyFont(Platform::String^ fontFamily, Windows::UI::Text::FontStretch strech, Windows::UI::Text::FontStyle fontStyle, double fontSize, Windows::UI::Text::FontWeight fontWeight);

internal:
    property Windows::UI::Xaml::Controls::TextBox^ TextBox {
        Windows::UI::Xaml::Controls::TextBox^ get();
    }

    property Windows::UI::Xaml::Controls::PasswordBox^ PasswordBox {
        Windows::UI::Xaml::Controls::PasswordBox^ get();
    }

    // Static entry point to register our dependency properties
    static void _RegisterDependencyProperties();

    // Hook pointer events
    void RegisterEventsHandlers(
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler>& textChangedHandler,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler>& gotFocusHandler,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler>& lostFocusHanlder,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler>& enterKeyDownHandler);

    void UnregisterEventHandlers();

    // programatically kills the focus on this control
    void KillFocus();

    // programatically setting focus on this control
    bool BecomeFirstResponder();

private:
    // depdency properties for two way binding
    static Windows::UI::Xaml::DependencyProperty^ s_textProperty;

    // variables backing normal properties
    bool _secureEntry;
    Platform::String^ _placeholder;
    Windows::UI::Xaml::Input::InputScopeNameValue _inputScopeNameValue;
    bool _enabled;
    Windows::UI::Xaml::Media::SolidColorBrush^ _foreground;
    Windows::UI::Xaml::TextAlignment _textAlignment;
    Windows::UI::Xaml::VerticalAlignment _textVerticalAlignment;
    UIKit::Xaml::TextBorderStyle _borderStyle;

    static Platform::Boolean s_dependencyPropertiesRegistered;
    static unsigned int c_borderCornerRadius;

    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler> _textChangedHandler;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler> _gotFocusHandler;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler> _lostFocusHanlder;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler> _enterKeyDownHandler;

    void _SwitchToMode(bool secure);
    void _SetTextVerticalAlignment();
    void _SetBorderStyle();
    void _SetPlaceHolder();
    void _SetInputScope();
    void _SetEnabled();
    void _SetForeground();
    void _SetBackground();
    void _SetTextAlignment();

    // Find the best inputScope given current security entry mode and inputscope
    Windows::UI::Xaml::Input::InputScope^ _FindBestFitInputScope();

    // events handler for internal controls
    void OnTextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
    void OnPasswordChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    void OnGotFocus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    void OnLostFocus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    void OnKeyDown(Platform::Object^ sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs^ e);

    // inneral backing control which is either textBox or passwordBox depending on the SecureEntry value
    Windows::UI::Xaml::Controls::Control^ _backingControl;

    Windows::Foundation::EventRegistrationToken _textChangedHandlerRegistrationToken;
    Windows::Foundation::EventRegistrationToken _gotFocusHandlerRegistrationToken;
    Windows::Foundation::EventRegistrationToken _lostFocusHandlerRegistrationToken;
    Windows::Foundation::EventRegistrationToken _keydownHandlerRegistrationToken;
    void OnBackingControlLoaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
};

} /* Xaml*/
} /* UIKit*/
