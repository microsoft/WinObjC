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
#include "Dwrite_3.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Text;
using namespace Windows::UI::Xaml::Media;

namespace UIKit {
namespace Xaml {

DependencyProperty^ TextField::s_textProperty = nullptr;
unsigned int TextField::c_borderCornerRadius = 8;

Platform::Boolean TextField::s_dependencyPropertiesRegistered = false;

template <typename T>
static T FindTemplateChild(FrameworkElement^ source, Platform::String^ name) {
    T target = nullptr;
    if (source) {
        unsigned int count = VisualTreeHelper::GetChildrenCount(source);
        if (count > 0) {
            auto templateRoot = dynamic_cast<FrameworkElement^>(VisualTreeHelper::GetChild(source, 0));
            if (templateRoot) {
                target = dynamic_cast<T>(templateRoot->FindName(name));
            }
        }
    }

    return target;
}

TextField::TextField() {
    _RegisterDependencyProperties();

    InitializeComponent();

    // by default control is enabled
    _enabled = true;

    // by default control is Non-secure
    _secureEntry = false;

    // by default no border
    _borderStyle = TextBorderStyle::BorderStyleNone;

    // by default vertical center aligned
    _textVerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;

    // by default left aligned
    _textAlignment = Windows::UI::Xaml::TextAlignment::Left;

    // default inputScopeNameValue
    _inputScopeNameValue = Input::InputScopeNameValue::Default;
}

void TextField::_SwitchToMode(bool secure) {
    if (_backingControl) {
        _backingControl->GotFocus -= _gotFocusHandlerRegistrationToken;
        _backingControl->LostFocus -= _lostFocusHandlerRegistrationToken;
        _backingControl->KeyDown -= _keydownHandlerRegistrationToken;

        if (secure) {
            // switch to SecureMode, unhook textChanged event
            auto textBox = dynamic_cast<Controls::TextBox^>(_backingControl);
            if (textBox) {
                textBox->TextChanged -= _textChangedHandlerRegistrationToken;
            }
            
        } else {
            // switch to Non-SecureMode, unhook passwordChanged event
            auto passwordBox = dynamic_cast<Controls::PasswordBox^>(_backingControl);
            if (passwordBox) {
                PasswordBox->PasswordChanged -= _textChangedHandlerRegistrationToken;
            }
        }

        _textChangedHandlerRegistrationToken = {0};
        _gotFocusHandlerRegistrationToken = {0};
        _lostFocusHandlerRegistrationToken = {0};
        _keydownHandlerRegistrationToken = {0};
        
        // removing backing control from the visual
        unsigned int index = 0;
        if (Children->IndexOf(_backingControl, &index)) {
            Children->RemoveAt(index);
        }

        _backingControl = nullptr;
    }

    if (secure) {
        // switching to secure mode, create passowordbox as backingControl
        _backingControl = ref new Controls::PasswordBox();
    } else {
        // switch to Non-secure mode, create a textbox as backingControl
        _backingControl = ref new Controls::TextBox();
    }
    _backingControl->Loaded += ref new Windows::UI::Xaml::RoutedEventHandler(this, &UIKit::Xaml::TextField::OnBackingControlLoaded); 
    _gotFocusHandlerRegistrationToken = _backingControl->GotFocus += ref new Windows::UI::Xaml::RoutedEventHandler(this, &TextField::OnGotFocus);
    _lostFocusHandlerRegistrationToken = _backingControl->LostFocus += ref new Windows::UI::Xaml::RoutedEventHandler(this, &UIKit::Xaml::TextField::OnLostFocus);
    _keydownHandlerRegistrationToken = _backingControl->KeyDown += ref new Windows::UI::Xaml::Input::KeyEventHandler(this, &UIKit::Xaml::TextField::OnKeyDown);

    if (secure) {
        auto passwordBox = safe_cast<Controls::PasswordBox^>(_backingControl);
        _textChangedHandlerRegistrationToken = passwordBox->PasswordChanged += ref new Windows::UI::Xaml::RoutedEventHandler(this, &TextField::OnPasswordChanged);
        passwordBox->InputScope = _FindBestFitInputScope();
    } else {
        auto textBox = safe_cast<Controls::TextBox^>(_backingControl);
        _textChangedHandlerRegistrationToken = textBox->TextChanged += ref new Windows::UI::Xaml::Controls::TextChangedEventHandler(this, &TextField::OnTextChanged);
        textBox->InputScope = _FindBestFitInputScope();
    }

    // adding the new backing control to visual tree
    Children->Append(_backingControl);
}

Windows::UI::Xaml::Input::InputScope^ TextField::_FindBestFitInputScope() {
    Input::InputScopeNameValue targetInputScopeNameValue = _inputScopeNameValue;
    if (_secureEntry) {
        if (_inputScopeNameValue != Input::InputScopeNameValue::Password &&  _inputScopeNameValue != Input::InputScopeNameValue::NumericPin) {
            // passwordbox only allows these two inputScope, overwrite with password if inputScope isn't those two
            targetInputScopeNameValue = Input::InputScopeNameValue::Password;
        }
    } else {
        if (_inputScopeNameValue == Input::InputScopeNameValue::Password) {
            // textbox does not like Password inputScope, overwrite with default
            targetInputScopeNameValue = Input::InputScopeNameValue::Default;
        }
    }

    auto scopeName = ref new Windows::UI::Xaml::Input::InputScopeName();
    scopeName->NameValue = targetInputScopeNameValue;
    auto inputScope = ref new Windows::UI::Xaml::Input::InputScope();
    inputScope->Names->Append(scopeName);
    return inputScope;
}

void TextField::OnBackingControlLoaded(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e)
{
    if (_secureEntry) {
        //  two way bind passwordbox's password property to TextField's Text Property
        auto passwordBox = safe_cast<Controls::PasswordBox^>(_backingControl);
        Windows::UI::Xaml::Data::Binding^ binding = ref new Windows::UI::Xaml::Data::Binding();
        binding->Mode = Windows::UI::Xaml::Data::BindingMode::TwoWay;
        binding->ElementName = "Root";
        binding->Path = ref new Windows::UI::Xaml::PropertyPath("TextField_Text");
        binding->UpdateSourceTrigger = Windows::UI::Xaml::Data::UpdateSourceTrigger::PropertyChanged;
        passwordBox->SetBinding(Controls::PasswordBox::PasswordProperty, binding);

        // one way binding background to inner passwordbox background
        binding = ref new Windows::UI::Xaml::Data::Binding();
        binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
        binding->ElementName = "Root";
        binding->Path = ref new Windows::UI::Xaml::PropertyPath("Background");
        passwordBox->SetBinding(Controls::PasswordBox::BackgroundProperty, binding);

        passwordBox->PlaceholderText = _placeholder;
        passwordBox->InputScope = _FindBestFitInputScope();
    } else {
        // two way bind textbox's text property to TextField's Text Property
        auto textBox = safe_cast<Controls::TextBox^>(_backingControl);
        Windows::UI::Xaml::Data::Binding^ binding = ref new Windows::UI::Xaml::Data::Binding();
        binding->ElementName = "Root";
        binding->Path = ref new Windows::UI::Xaml::PropertyPath("TextField_Text");
        binding->Mode = Windows::UI::Xaml::Data::BindingMode::TwoWay;
        binding->UpdateSourceTrigger = Windows::UI::Xaml::Data::UpdateSourceTrigger::PropertyChanged;
        textBox->SetBinding(Controls::TextBox::TextProperty, binding);

        // one way binding background to inner textbox background
        binding = ref new Windows::UI::Xaml::Data::Binding();
        binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
        binding->ElementName = "Root";
        binding->Path = ref new Windows::UI::Xaml::PropertyPath("Background");
        textBox->SetBinding(Controls::TextBox::BackgroundProperty, binding);

        textBox->PlaceholderText = _placeholder;
        textBox->TextAlignment = _textAlignment;
        textBox->InputScope = _FindBestFitInputScope();
    }

    _backingControl->IsEnabled = _enabled;
    _backingControl->Foreground = _foreground;

    _SetTextVerticalAlignment();
    _SetBorderStyle();
}

// Hook pointer events
void TextField::RegisterEventsHandlers(
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler>& textChangedHandler,
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler>& gotFocusHandler,
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler>& lostFocusHanlder,
    const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IRoutedEventHandler>& enterKeyDownHandler) {
    _textChangedHandler = std::move(textChangedHandler);
    _gotFocusHandler = std::move(gotFocusHandler);
    _lostFocusHanlder = std::move(lostFocusHanlder);
    _enterKeyDownHandler = std::move(enterKeyDownHandler);
}

void TextField::UnregisterEventHandlers() {
    _textChangedHandler = nullptr;
    _gotFocusHandler = nullptr;
    _lostFocusHanlder = nullptr;
    _enterKeyDownHandler = nullptr;
}

void TextField::_RegisterDependencyProperties() {
    if (!s_dependencyPropertiesRegistered) {
        s_dependencyPropertiesRegistered = true;

        // TODO: These Dependency Properties should be attached to TextField instead of FrameworkElement once #2607 is fixed
        s_textProperty = DependencyProperty::RegisterAttached("TextField_Text",
            Platform::String::typeid,
            FrameworkElement::typeid,
            nullptr);
    }
}

// Accessor for our Layer content
Image^ TextField::LayerContent::get() {
    return nullptr;
}

// Accessor for our Layer content
bool TextField::HasLayerContent::get() {
    return false;
}

// Accessor for our SublayerCanvas
Canvas^ TextField::SublayerCanvas::get() {
    return nullptr;
}

// Accessor for the LayerProperty that manages the BorderBrush of this TextField
Private::CoreAnimation::LayerProperty^ TextField::GetBorderBrushProperty() {
    return nullptr;
}

// Accessor for the LayerProperty that manages the BorderThickness of this TextField
Private::CoreAnimation::LayerProperty^ TextField::GetBorderThicknessProperty() {
    return nullptr;
}

TextBox^ TextField::TextBox::get() {
    return dynamic_cast<Windows::UI::Xaml::Controls::TextBox^>(_backingControl);
}

PasswordBox^ TextField::PasswordBox::get() {
    return dynamic_cast<Windows::UI::Xaml::Controls::PasswordBox^>(_backingControl);
}

void TextField::KillFocus() {
    // TODO: this is still a hack to kill the focus on this control
    // Will switch to the Windows API when it is available.
    if (_backingControl) {
        _backingControl->IsEnabled = false;
        _backingControl->IsEnabled = true;
    }
}

bool TextField::BecomeFirstResponder() {
    if (_backingControl) {
        return _backingControl->Focus(FocusState::Programmatic);
    }

    return false;
}

void TextField::OnTextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{
    if (_textChangedHandler) {
        _textChangedHandler->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
    }
}

void TextField::OnPasswordChanged(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    if (_textChangedHandler) {
        _textChangedHandler->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
    }
}

void TextField::OnGotFocus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    if (_gotFocusHandler) {
        _gotFocusHandler->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
    }
}

void TextField::OnLostFocus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    if (_lostFocusHanlder) {
        _lostFocusHanlder->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
    }
}

void TextField::OnKeyDown(Platform::Object^ sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs^ e)
{
    if (_enterKeyDownHandler) {
        if (e->Key == Windows::System::VirtualKey::Enter) {
            _enterKeyDownHandler->Invoke(
                InspectableFromObject(this).Get(),
                ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
        } 
    }
}

void TextField::ApplyFont(Platform::String^ fontFamily, FontStretch strech, FontStyle fontStyle, double fontSize, FontWeight fontWeight) {
    if (_backingControl) {
        _backingControl->FontFamily = ref new FontFamily(fontFamily);
        _backingControl->FontStretch = strech;
        _backingControl->FontStyle = fontStyle;
        _backingControl->FontSize = fontSize;
        _backingControl->FontWeight = fontWeight;
    }
}

void TextField::_SetTextVerticalAlignment() {
    // Set vertical aligment of both content and placeholder to the same value
    // In TextBox/PasswordBox control templates, both have ContentElement and  PlaceholderTextContentPresenter
    // to hold normal text/password content and placeholder content
    // TextBox control template can be found at https://msdn.microsoft.com/en-us/library/windows/apps/mt299154.aspx
    // PasswordBox control template can be found at https://msdn.microsoft.com/en-us/library/dd334412(v=vs.95).aspx
    auto target = FindTemplateChild<FrameworkElement^>(_backingControl, "ContentElement");
    if (target) {
        target->VerticalAlignment = VerticalTextAlignment;
    }

    target = FindTemplateChild<FrameworkElement^>(_backingControl, "PlaceholderTextContentPresenter");
    if (target) {
        target->VerticalAlignment = VerticalTextAlignment;
    }
}

void TextField::_SetBorderStyle() {
    if (_backingControl) {
        switch (BorderStyle) {
        case TextBorderStyle::BorderStyleNone:
            _backingControl->BorderThickness = ThicknessHelper::FromUniformLength(0);
            break;

        case TextBorderStyle::BorderStyleLine:
            _backingControl->BorderThickness = ThicknessHelper::FromUniformLength(1);
            break;

        case TextBorderStyle::UITextBorderStyleBezel:
            UNIMPLEMENTED_WITH_MSG("UITextBorderStyleBezel not yet supported; treated as no border.");
            _backingControl->BorderThickness = ThicknessHelper::FromUniformLength(0);
            break;

        case TextBorderStyle::UITextBorderStyleRoundedRect:

            UNIMPLEMENTED_WITH_MSG("UITextBorderStyleBezel not yet supported; treated as no border.");
            _backingControl->BorderThickness = ThicknessHelper::FromUniformLength(0);
            break;
        }
    }
}

void TextField::_SetPlaceHolder() {
    if (_backingControl) {
        if (_secureEntry) {
            auto passwordBox = safe_cast<Controls::PasswordBox^>(_backingControl);
            passwordBox->PlaceholderText = _placeholder;
        } else {
            auto textBox = safe_cast<Controls::TextBox^>(_backingControl);
            textBox->PlaceholderText = _placeholder;
        }
    }
}

void TextField::_SetInputScope() {
    if (_backingControl) {
        if (_secureEntry) {
            auto passwordBox = safe_cast<Controls::PasswordBox^>(_backingControl);
            passwordBox->InputScope = _FindBestFitInputScope();
        }
        else {
            auto textBox = safe_cast<Controls::TextBox^>(_backingControl);
            textBox->InputScope = _FindBestFitInputScope();
        }
    }
}

void TextField::_SetEnabled() {
    if (_backingControl) {
        _backingControl->IsEnabled = _enabled;
    }
}

void TextField::_SetForeground() {
    if (_backingControl) {
        _backingControl->Foreground = _foreground;
    }
}

void TextField::_SetBackground() {
    if (_backingControl) {
        _backingControl->Background = Background;
    }
}

void TextField::_SetTextAlignment() {
    if (_backingControl) {
        if (!_secureEntry) {
            auto textBox = safe_cast<Controls::TextBox^>(_backingControl);
            textBox->TextAlignment = _textAlignment;
        } else {
            UNIMPLEMENTED_WITH_MSG("XAML passwordbox currently does not allow set TextAlignment properties");
        }
    }
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
    textField->SecureEntry = secureTextEntry;
}

// Get the UIKit::Xaml::TextField's secureTextEntry property
UIKIT_XAML_EXPORT bool XamlGetTextFieldSecureTextEntryValue(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return textField->SecureEntry;
}

// Set the UIKit::Xaml::TextField's Text property
UIKIT_XAML_EXPORT void XamlSetTextFieldText(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, const std::wstring& text) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->TextField_Text = Platform::StringReference(text.c_str());
    if (!textField->SecureEntry) {
        // this is to set the selection to the end of of text so that
        // to ensure when user tap into TextBox, the caret is at
        // the end of the TextBox. 
        textField->TextBox->SelectionStart = textField->TextField_Text->Length();
        textField->TextBox->SelectionLength = 0;
    } else {
        UNIMPLEMENTED_WITH_MSG("XAML passwordbox currently does not allow set selection programmatically");
    }
}

// Get the UIKit::Xaml::TextField's Text property
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldText(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    Platform::Object^ propVal = Windows::Foundation::PropertyValue::CreateString(textField->TextField_Text);
    return InspectableFromObject(propVal).Detach();
}

// Set the UIKit::Xaml::TextField's PlaceHolder property
UIKIT_XAML_EXPORT void XamlSetTextFieldPlaceholder(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, const std::wstring& text) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->Placeholder = Platform::StringReference(text.c_str());
}

// Get the UIKit::Xaml::TextField's PlaceHolder property
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldPlaceholder(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    Platform::Object^ propVal = Windows::Foundation::PropertyValue::CreateString(textField->Placeholder);
    return InspectableFromObject(propVal).Detach();
}

// Set the UIKit::Xaml::TextField's InputScope property
UIKIT_XAML_EXPORT void XamlSetTextFieldInputScope(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, int inputScopeNameValue) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    auto inputScopeNameValueToUse = static_cast<Input::InputScopeNameValue>(inputScopeNameValue);
    textField->InputScopeNameValue = inputScopeNameValueToUse;
}

// Set the UIKit::Xaml::TextField's Enabled property
UIKIT_XAML_EXPORT void XamlSetTextFieldEnabled(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, bool enabled) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->Enabled = enabled;
}

// Get the UIKit::Xaml::TextField's Enabled property
UIKIT_XAML_EXPORT bool XamlGetTextFieldEnabled(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return textField->Enabled;
}

// kill the focus if TextFiled has the editing focus
UIKIT_XAML_EXPORT void XamlTextFieldKillFocus(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->KillFocus();
}

// Set the UIKit::Xaml::TextField's textColor property
UIKIT_XAML_EXPORT void XamlSetTextFieldTextColor(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, const Microsoft::WRL::ComPtr<IInspectable>&  textCOlor) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    auto textColorBrush = safe_cast<Media::SolidColorBrush^>(reinterpret_cast<Platform::Object^>(textCOlor.Get()));
    textField->Foreground = textColorBrush;
}

// Get the UIKit::Xaml::TextField's Forground property
UIKIT_XAML_EXPORT  IInspectable* XamlGetTextFieldTextColor(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return InspectableFromObject(textField->Foreground).Detach();
}

// Set the UIKit::Xaml::TextField's Background property
UIKIT_XAML_EXPORT void XamlSetTextFieldBackgroundColor(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, const Microsoft::WRL::ComPtr<IInspectable>&  backgroundColorBrush) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    auto background = safe_cast<Media::SolidColorBrush^>(reinterpret_cast<Platform::Object^>(backgroundColorBrush.Get()));
    textField->Background = background;
}

// Get the UIKit::Xaml::TextField's Background property
UIKIT_XAML_EXPORT  IInspectable* XamlGetTextFieldBackgroundColor(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));

    // try convert the background (Brush) to SolidColorBrush to retrieve the background color
    auto backgroundColorBrush = dynamic_cast<Media::SolidColorBrush^>(textField->Background);
    if (backgroundColorBrush) {
        return InspectableFromObject(backgroundColorBrush).Detach();
    }

    return nullptr;
}

// Set the UIKit::Xaml::TextField's BackgroundImage property
UIKIT_XAML_EXPORT  void XamlSetTextFieldBackgroundImage(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField, const Microsoft::WRL::ComPtr<IInspectable>&  backgroundImageBrush) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    auto background = safe_cast<Media::ImageBrush^>(reinterpret_cast<Platform::Object^>(backgroundImageBrush.Get()));
    textField->Background = background;
}

// Set the UIKit::Xaml::TextField's TextAlignment property
UIKIT_XAML_EXPORT void XamlSetTextFieldTextAlignment(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, int textAlignment) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->TextAlignment = static_cast<Windows::UI::Xaml::TextAlignment>(textAlignment);
}

// Get the UIKit::Xaml::TextField's TextAlignment property
UIKIT_XAML_EXPORT int XamlGetTextFieldTextAlignment(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return static_cast<int>(textField->TextAlignment);
}

// Get the UIKit::Xaml::TextField's Editing property
UIKIT_XAML_EXPORT Platform::Boolean XamlGetTextFieldEditing(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return textField->Editing;
}

// Get the UIKit::Xaml::TextField's Editing property
UIKIT_XAML_EXPORT Platform::Boolean XamlTextFieldBecomeFirstResponder(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return textField->BecomeFirstResponder();
}

UIKIT_XAML_EXPORT void XamlTextFieldRegisterEventHandlers(
    const ComPtr<IInspectable>& inspectableTextField,
    const ComPtr<IInspectable>& textChangedHandler,
    const ComPtr<IInspectable>& gotFocusHandler,
    const ComPtr<IInspectable>& lostFocusHanlder,
    const ComPtr<IInspectable>& enterKeyDownHandler) {
    
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->RegisterEventsHandlers(InspectableToType<ABI::Windows::UI::Xaml::IRoutedEventHandler>(textChangedHandler),
        InspectableToType<ABI::Windows::UI::Xaml::IRoutedEventHandler>(gotFocusHandler),
        InspectableToType<ABI::Windows::UI::Xaml::IRoutedEventHandler>(lostFocusHanlder),
        InspectableToType<ABI::Windows::UI::Xaml::IRoutedEventHandler>(enterKeyDownHandler));
}

UIKIT_XAML_EXPORT void XamlTextFieldUnregisterEventHandlers(const ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->UnregisterEventHandlers();
}

// Set the UIKit::Xaml::TextField's TextAlignment property
UIKIT_XAML_EXPORT void XamlSetTextFieldVerticalTextAlignment(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, int verticalTextAlignment) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->VerticalTextAlignment = static_cast<Windows::UI::Xaml::VerticalAlignment>(verticalTextAlignment);
}

// Get the UIKit::Xaml::TextField's TextAlignment property
UIKIT_XAML_EXPORT int XamlGetTextFieldVerticalTextAlignment(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return static_cast<int>(textField->VerticalTextAlignment);
}

// Set the UIKit::Xaml::TextField's Border property
UIKIT_XAML_EXPORT void XamlSetTextFieldBorderStyle(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, int borderStyle) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->BorderStyle = static_cast<UIKit::Xaml::TextBorderStyle>(borderStyle);
}

// Get the UIKit::Xaml::TextField's Border property
UIKIT_XAML_EXPORT int XamlGetTextFieldBorderStyle(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return static_cast<int>(textField->BorderStyle);
}

FontWeight ConvertToFontWeight(DWRITE_FONT_WEIGHT fontWeight) {
    switch (fontWeight) {
        case DWRITE_FONT_WEIGHT_THIN:
            return FontWeights::Thin;

        case DWRITE_FONT_WEIGHT_ULTRA_LIGHT:
            return FontWeights::ExtraLight;

        case DWRITE_FONT_WEIGHT_LIGHT:
            return FontWeights::Light;

        case DWRITE_FONT_WEIGHT_SEMI_LIGHT:
            return FontWeights::SemiLight;

        case DWRITE_FONT_WEIGHT_REGULAR:
            return FontWeights::Normal;

        case DWRITE_FONT_WEIGHT_MEDIUM:
            return FontWeights::Medium;

        case DWRITE_FONT_WEIGHT_SEMI_BOLD:
            return FontWeights::SemiBold;

        case DWRITE_FONT_WEIGHT_BOLD:
            return FontWeights::Bold;

        case DWRITE_FONT_WEIGHT_ULTRA_BOLD:
            return FontWeights::ExtraBold;

        case DWRITE_FONT_WEIGHT_HEAVY:
            return FontWeights::Black;

        case DWRITE_FONT_WEIGHT_ULTRA_BLACK:
            return FontWeights::ExtraBlack;
    }

    return FontWeights::Normal;
}

// ApplyFont
UIKIT_XAML_EXPORT void XamlTextFieldApplyFont(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, const std::wstring& fontFamilyname, int fontStrech, int fontStyle, double fontSize, int fontWeight) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));

    textField->ApplyFont(Platform::StringReference(fontFamilyname.c_str()), safe_cast<FontStretch>(fontStrech), safe_cast<FontStyle>(fontStyle), fontSize, ConvertToFontWeight(safe_cast<DWRITE_FONT_WEIGHT>(fontWeight)));
}

