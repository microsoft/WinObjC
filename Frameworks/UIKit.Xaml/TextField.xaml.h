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

    property Platform::String^ Text
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
            return (Platform::Boolean)GetValue(s_secureEntryProperty);
        }
        void set(Platform::Boolean value)
        {
            SetValue(s_secureEntryProperty, value);
            if (SecureEntry) {
                // switch to Secure
                _SwitchToSecureMode();
            }
            else {
                // swtich to Non-Secure
                _SwitchToNonSecureMode();
            }
        }
    }

    property Platform::String^ Placeholder
    {
        Platform::String^ get()
        {
            return (Platform::String^)GetValue(s_placeholderProperty);
        }
        void set(Platform::String^ value)
        {
            SetValue(s_placeholderProperty, value);
        }
    }

    property Windows::UI::Xaml::Input::InputScope^ InputScope {
        Windows::UI::Xaml::Input::InputScope^ get() 
        {
            return (Windows::UI::Xaml::Input::InputScope^)GetValue(s_inputScopeProperty);
        }

        void set(Windows::UI::Xaml::Input::InputScope^ value)
        {
            SetValue(s_inputScopeProperty, value);
        }
    }

    property bool Enabled
    {
        Platform::Boolean get()
        {
            return (Platform::Boolean)GetValue(s_enabledProperty);
        }
        void set(Platform::Boolean value)
        {
            SetValue(s_enabledProperty, value);
        }
    }

    property Windows::UI::Xaml::Media::SolidColorBrush^ Foreground
    {
        Windows::UI::Xaml::Media::SolidColorBrush^ get()
        {
            return (Windows::UI::Xaml::Media::SolidColorBrush^)GetValue(s_foregroundProperty);
        }
        void set(Windows::UI::Xaml::Media::SolidColorBrush^ value)
        {
            SetValue(s_foregroundProperty, value);
        }
    }

    property Windows::UI::Xaml::TextAlignment TextAlignment
    {
        Windows::UI::Xaml::TextAlignment get()
        {
            return (Windows::UI::Xaml::TextAlignment)GetValue(s_textAlignmentProperty);
        }
        void set(Windows::UI::Xaml::TextAlignment value)
        {
            SetValue(s_textAlignmentProperty, value);
        }
    }

    property Platform::Boolean Editing
    {
        Platform::Boolean get()
        {
            if (SecureEntry) {
                return PasswordBox->FocusState != Windows::UI::Xaml::FocusState::Unfocused;
            } else {
                return TextBox->FocusState != Windows::UI::Xaml::FocusState::Unfocused;
            }
        }
    }

    property Windows::UI::Xaml::VerticalAlignment VerticalTextAlignment
    {
        Windows::UI::Xaml::VerticalAlignment get()
        {
            return (Windows::UI::Xaml::VerticalAlignment)GetValue(s_textVerticalAlignmentProperty);
        }
        void set(Windows::UI::Xaml::VerticalAlignment value)
        {
            SetValue(s_textVerticalAlignmentProperty, value);
            _SetTextVerticalAlignment();
        }
    }

    property UIKit::Xaml::TextBorderStyle BorderStyle
    {
        UIKit::Xaml::TextBorderStyle get()
        {
            return (UIKit::Xaml::TextBorderStyle)GetValue(s_borderStyleProperty);
        }
        void set(UIKit::Xaml::TextBorderStyle value)
        {
            SetValue(s_borderStyleProperty, value);
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

    // programatically set focus on this control
    void SetFocus();

    // programatically setting focus on this control
    bool BecomeFirstResponder();

private:
    static Windows::UI::Xaml::DependencyProperty^ s_textProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_secureEntryProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_placeholderProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_inputScopeProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_enabledProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_foregroundProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_textAlignmentProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_textVerticalAlignmentProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_borderStyleProperty;

    static Platform::Boolean s_dependencyPropertiesRegistered;
    static unsigned int c_borderCornerRadius;

    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler> _textChangedHandler;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler> _gotFocusHandler;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler> _lostFocusHanlder;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler> _enterKeyDownHandler;

    void _SwitchToSecureMode();
    void _SwitchToNonSecureMode();
    void _SetTextVerticalAlignment();
    void _SetBorderStyle();

    // Layer elements; created on demand
    Windows::UI::Xaml::Controls::Image^ _content;

    // events handler for internal controls
    void OnTextChanged(Platform::Object ^sender, Windows::UI::Xaml::Controls::TextChangedEventArgs ^e);
    void OnPasswordChanged(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e);
    void OnGotFocus(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e);
    void OnLostFocus(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e);
    void OnKeyDown(Platform::Object ^sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs ^e);

    // inneral backing control which is either textBox or passwordBox depending on the SecureEntry value
    Windows::UI::Xaml::Controls::Control^ _backingControl;

    Windows::Foundation::EventRegistrationToken _textChangedHandlerRegistrationToken;
    Windows::Foundation::EventRegistrationToken _gotFocusHandlerRegistrationToken;
    Windows::Foundation::EventRegistrationToken _lostFocusHandlerRegistrationToken;
    Windows::Foundation::EventRegistrationToken _keydownHandlerRegistrationToken;
    void OnTextBoxLoaded(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e);
    void OnPasswordBoxLoaded(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e);
};

} /* Xaml*/
} /* UIKit*/
