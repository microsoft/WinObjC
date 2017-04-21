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
DependencyProperty^ TextField::s_secureEntryProperty = nullptr;
DependencyProperty^ TextField::s_placeholderProperty = nullptr;
DependencyProperty^ TextField::s_inputScopeProperty = nullptr;
DependencyProperty^ TextField::s_enabledProperty = nullptr;
DependencyProperty^ TextField::s_foregroundProperty = nullptr;
DependencyProperty^ TextField::s_textAlignmentProperty = nullptr;
DependencyProperty^ TextField::s_textVerticalAlignmentProperty = nullptr;
DependencyProperty^ TextField::s_borderStyleProperty = nullptr;

unsigned int TextField::c_borderCornerRadius = 8;

Platform::Boolean TextField::s_dependencyPropertiesRegistered = false;
// TOOD: 
template <typename T>
T TextField::FindTemplateChild(FrameworkElement^ source, Platform::String^ name) {
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
    Enabled = true;

    // by default control is Non-secure
    SecureEntry = false;

    // by default no border
    BorderStyle = TextBorderStyle::BorderStyleNone;

    // by default vertical center aligned
    VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
}

void TextField::_SwitchToSecureMode() {
    if (_backingControl) {
        // switch to SecureMode, check if backingControl is a textBox
        // remove all listeners before we re-assign a password to it
        auto textBox = dynamic_cast<Controls::TextBox^>(_backingControl);
        if (textBox) {
            textBox->TextChanged -= _textChangedHandlerRegistrationToken;
            textBox->GotFocus -= _gotFocusHandlerRegistrationToken;
            textBox->LostFocus -= _lostFocusHandlerRegistrationToken;
            textBox->KeyDown -= _keydownHandlerRegistrationToken;
        }

        _textChangedHandlerRegistrationToken = {0};
        _gotFocusHandlerRegistrationToken = {0};
        _lostFocusHandlerRegistrationToken = {0};
        _keydownHandlerRegistrationToken = {0};
        
        unsigned int index = 0;
        if (Children->IndexOf(_backingControl, &index)) {
            Children->RemoveAt(index);
        }

        _backingControl = nullptr;
    }

    // assign a passowordbox to backingControl
    _backingControl = ref new Controls::PasswordBox();
    auto passwordBox = safe_cast<Controls::PasswordBox^>(_backingControl);

    // hooking up event handlers with passwordBox
    _textChangedHandlerRegistrationToken = passwordBox->PasswordChanged += ref new Windows::UI::Xaml::RoutedEventHandler(this, &TextField::OnPasswordChanged);
    _gotFocusHandlerRegistrationToken = PasswordBox->GotFocus += ref new Windows::UI::Xaml::RoutedEventHandler(this, &TextField::OnGotFocus);
    _lostFocusHandlerRegistrationToken =PasswordBox->LostFocus += ref new Windows::UI::Xaml::RoutedEventHandler(this, &UIKit::Xaml::TextField::OnLostFocus);
    _keydownHandlerRegistrationToken = PasswordBox->KeyDown += ref new Windows::UI::Xaml::Input::KeyEventHandler(this, &UIKit::Xaml::TextField::OnKeyDown);

    passwordBox->Loaded += ref new Windows::UI::Xaml::RoutedEventHandler(this, &UIKit::Xaml::TextField::OnPasswordBoxLoaded);

    Children->Append(_backingControl);
}

void TextField::_SwitchToNonSecureMode() {
    if (_backingControl) {
        // switch to NonSecureMode, check if backingControl is a passwordbox
        // remove all listeners before we re-assign a textBox to it
        auto textBox = dynamic_cast<Controls::PasswordBox^>(_backingControl);
        if (textBox) {
            PasswordBox->PasswordChanged -= _textChangedHandlerRegistrationToken;
            PasswordBox->GotFocus -= _gotFocusHandlerRegistrationToken;
            PasswordBox->LostFocus -= _lostFocusHandlerRegistrationToken;
            PasswordBox->KeyDown -= _keydownHandlerRegistrationToken;
            _textChangedHandlerRegistrationToken = {0};
            _gotFocusHandlerRegistrationToken = {0};
            _lostFocusHandlerRegistrationToken = {0};
            _keydownHandlerRegistrationToken = {0};
        }

        unsigned int index = 0;
        if (Children->IndexOf(_backingControl, &index)) {
            Children->RemoveAt(index);
        }

        _backingControl = nullptr;
    }

    // assign a passowordbox to backingControl
    _backingControl = ref new Controls::TextBox();
    auto textBox = safe_cast<Controls::TextBox^>(_backingControl);
    textBox->Loaded += ref new Windows::UI::Xaml::RoutedEventHandler(this, &UIKit::Xaml::TextField::OnTextBoxLoaded);

    // hooking up event handlers with passwordBox
    _textChangedHandlerRegistrationToken = textBox->TextChanged += ref new Windows::UI::Xaml::Controls::TextChangedEventHandler(this, &TextField::OnTextChanged);
    _gotFocusHandlerRegistrationToken = textBox->GotFocus += ref new Windows::UI::Xaml::RoutedEventHandler(this, &TextField::OnGotFocus);
    _lostFocusHandlerRegistrationToken = textBox->LostFocus += ref new Windows::UI::Xaml::RoutedEventHandler(this, &UIKit::Xaml::TextField::OnLostFocus);
    _keydownHandlerRegistrationToken = textBox->KeyDown += ref new Windows::UI::Xaml::Input::KeyEventHandler(this, &UIKit::Xaml::TextField::OnKeyDown);

    Children->Append(_backingControl);
}

void TextField::OnTextBoxLoaded(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e)
{
    // setting up property bindings for textbox
    // bind textbox's text property to TextField's Text Property
    auto textBox = safe_cast<Controls::TextBox^>(_backingControl);

    Windows::UI::Xaml::Data::Binding^ binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Text");
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::TwoWay;
    binding->UpdateSourceTrigger = Windows::UI::Xaml::Data::UpdateSourceTrigger::PropertyChanged;
    textBox->SetBinding(Controls::TextBox::TextProperty, binding);

    // bind textbox's placeholderText property to TextField's placeholder Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Placeholder");
    textBox->SetBinding(Controls::TextBox::PlaceholderTextProperty, binding);

    // bind textbox's IsEnabled property to TextField's Enabled Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Enabled");
    textBox->SetBinding(Controls::TextBox::IsEnabledProperty, binding);

    // bind textbox's foreground property to TextField's Foreground Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Foreground");
    textBox->SetBinding(Controls::TextBox::ForegroundProperty, binding);

    // bind textbox's background property to TextField's Background Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Background");
    textBox->SetBinding(Controls::TextBox::BackgroundProperty, binding);

    // bind textbox's TextAlignment property to TextField's Alignment Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("TextAlignment");
    textBox->SetBinding(Controls::TextBox::TextAlignmentProperty, binding);

    // bind textbox's Input property to TextField's InputScope Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("InputScope");
    textBox->SetBinding(Controls::TextBox::InputScopeProperty, binding);

    _SetTextVerticalAlignment();
    _SetBorderStyle();
}

void TextField::OnPasswordBoxLoaded(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e)
{
    auto passwordBox = safe_cast<Controls::PasswordBox^>(_backingControl);

    // setting up property bindings for passwordBox
    // bind passwordbox's password property to TextField's Text Property
    Windows::UI::Xaml::Data::Binding^ binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::TwoWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Text");
    binding->UpdateSourceTrigger = Windows::UI::Xaml::Data::UpdateSourceTrigger::PropertyChanged;
    passwordBox->SetBinding(Controls::PasswordBox::PasswordProperty, binding);

    // bind passwordbox's placeholderText property to TextField's placeHolder Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Placeholder");
    passwordBox->SetBinding(Controls::PasswordBox::PlaceholderTextProperty, binding);

    // bind passwordbox's IsEnabled property to TextField's Enabled Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Enabled");
    passwordBox->SetBinding(Controls::PasswordBox::IsEnabledProperty, binding);

    // bind passwordbox's foreground property to TextField's Foreground Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Foreground");
    passwordBox->SetBinding(Controls::PasswordBox::ForegroundProperty, binding);

    // bind passwordbox's Background property to TextField's Background Property
    binding = ref new Windows::UI::Xaml::Data::Binding();
    binding->Mode = Windows::UI::Xaml::Data::BindingMode::OneWay;
    binding->ElementName = "Root";
    binding->Path = ref new Windows::UI::Xaml::PropertyPath("Background");
    passwordBox->SetBinding(Controls::PasswordBox::BackgroundProperty, binding);

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

        s_textProperty = DependencyProperty::RegisterAttached("Text",
            Platform::String::typeid,
            TextField::typeid,
            nullptr);

        s_secureEntryProperty = DependencyProperty::RegisterAttached("SecureEntry",
            Platform::Boolean::typeid,
            TextField::typeid,
            nullptr);

        s_placeholderProperty = DependencyProperty::RegisterAttached("Placeholder",
            Platform::String::typeid,
            TextField::typeid,
            nullptr);

        s_inputScopeProperty = DependencyProperty::RegisterAttached("InputScope",
            Input::InputScope::typeid,
            TextField::typeid,
            nullptr);

        s_enabledProperty = DependencyProperty::RegisterAttached("Enabled",
            Platform::Boolean::typeid,
            TextField::typeid,
            nullptr);

        s_foregroundProperty = DependencyProperty::RegisterAttached("Foreground",
            Media::SolidColorBrush::typeid,
            TextField::typeid,
            nullptr);

        s_textAlignmentProperty = DependencyProperty::RegisterAttached("TextAlignment",
            Windows::UI::Xaml::TextAlignment::typeid,
            TextField::typeid,
            nullptr);

        s_textVerticalAlignmentProperty = DependencyProperty::RegisterAttached("TextVerticalAlignment",
            Windows::UI::Xaml::VerticalAlignment::typeid,
            TextField::typeid,
            nullptr);

        s_borderStyleProperty = DependencyProperty::RegisterAttached("BorderStyle",
            UIKit::Xaml::TextBorderStyle::typeid,
            TextField::typeid,
            nullptr);
    }
}

// Accessor for our Layer content
Image^ TextField::LayerContent::get() {
    return nullptr;
}

// Accessor for our Layer content
bool TextField::HasLayerContent::get() {
    return _content != nullptr;
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
    return safe_cast<Windows::UI::Xaml::Controls::TextBox^>(_backingControl);
}

PasswordBox^ TextField::PasswordBox::get() {
    return safe_cast<Windows::UI::Xaml::Controls::PasswordBox^>(_backingControl);
}

void TextField::KillFocus() {
    if (SecureEntry) {
        PasswordBox->IsEnabled = false;
        PasswordBox->IsEnabled = true;
    } else {
        TextBox->IsEnabled = false;
        TextBox->IsEnabled = true;
    }
}

void TextField::SetFocus() {
    if (SecureEntry) {
        PasswordBox->Focus(FocusState::Programmatic);
    } else {
        TextBox->Focus(FocusState::Programmatic);
    }
}

bool TextField::BecomeFirstResponder() {
    if (SecureEntry) {
        return PasswordBox->Focus(FocusState::Programmatic);
    } else {
        return TextBox->Focus(FocusState::Programmatic);
    }
}

void TextField::OnTextChanged(Platform::Object ^sender, Windows::UI::Xaml::Controls::TextChangedEventArgs ^e)
{
    if (_textChangedHandler) {
        _textChangedHandler->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
    }
}

void TextField::OnPasswordChanged(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e)
{
    if (_textChangedHandler) {
        _textChangedHandler->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
    }
}

void TextField::OnGotFocus(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e)
{
    if (_gotFocusHandler) {
        _gotFocusHandler->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
    }
}

void TextField::OnLostFocus(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e)
{
    if (_lostFocusHanlder) {
        _lostFocusHanlder->Invoke(
            InspectableFromObject(this).Get(),
            ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
    }
}

void TextField::OnKeyDown(Platform::Object ^sender, Windows::UI::Xaml::Input::KeyRoutedEventArgs ^e)
{
    if (_enterKeyDownHandler) {
        if (e->Key == Windows::System::VirtualKey::Enter) {
            _enterKeyDownHandler->Invoke(
                InspectableFromObject(this).Get(),
                ObjectToType<ABI::Windows::UI::Xaml::IRoutedEventArgs>(e).Get());
            e->Handled = true;
        } else {
            e->Handled = false;
        }
    }
}

void TextField::ApplyFont(Platform::String^ fontFamily, FontStretch strech, FontStyle fontStyle, double fontSize, FontWeight fontWeight) {
    if (SecureEntry) {
        PasswordBox->FontFamily = ref new FontFamily(fontFamily);
        PasswordBox->FontStretch = strech;
        PasswordBox->FontStyle = fontStyle;
        PasswordBox->FontSize = fontSize;
        PasswordBox->FontWeight = fontWeight;
    }
    else {
        TextBox->FontFamily = ref new FontFamily(fontFamily);
        TextBox->FontStretch = strech;
        TextBox->FontStyle = fontStyle;
        TextBox->FontSize = fontSize;
        TextBox->FontWeight = fontWeight;
    }
}

void TextField::_SetTextVerticalAlignment() {
    // Set vertical aligment of both content and placeholder to the same value
    FrameworkElement^ target = FindTemplateChild<FrameworkElement^>(_backingControl, "ContentElement");
    if (target) {
        target->VerticalAlignment = VerticalTextAlignment;
    }

    target = FindTemplateChild<FrameworkElement^>(_backingControl, "PlaceholderTextContentPresenter");;
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
    textField->Text = Platform::StringReference(text.c_str());
    if (!textField->SecureEntry) {
        textField->TextBox->SelectionStart = textField->Text->Length();
        textField->TextBox->SelectionLength = 0;
    } 
}

// Get the UIKit::Xaml::TextField's Text property
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldText(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    Platform::Object^ propVal = Windows::Foundation::PropertyValue::CreateString(textField->Text);
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
UIKIT_XAML_EXPORT void XamlSetTextFieldInputScope(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, const Microsoft::WRL::ComPtr<IInspectable>& inputScope) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    auto inputScopeToUse = safe_cast<Input::InputScope^>(reinterpret_cast<Platform::Object^>(inputScope.Get()));
    textField->InputScope = inputScopeToUse;
}

// Get the UIKit::Xaml::TextField's Input property
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldInputScope(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    return InspectableFromObject(textField->InputScope).Detach();
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

// Set focus on TextField
UIKIT_XAML_EXPORT void XamlTextFieldSetFocus(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));
    textField->SetFocus();
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
UIKIT_XAML_EXPORT void XamlTextFieldApplyFont(const Microsoft::WRL::ComPtr<IInspectable>&  inspectableTextField, const std::wstring& fontFmailyname, int fontStrech, int fontStyle, double fontSize, int fontWeight) {
    auto textField = safe_cast<UIKit::Xaml::TextField^>(reinterpret_cast<Platform::Object^>(inspectableTextField.Get()));

    textField->ApplyFont(Platform::StringReference(fontFmailyname.c_str()), safe_cast<FontStretch>(fontStrech), safe_cast<FontStyle>(fontStyle), fontSize, ConvertToFontWeight(safe_cast<DWRITE_FONT_WEIGHT>(fontWeight)));
}

