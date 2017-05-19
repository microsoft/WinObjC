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
#pragma once

#include <wrl/client.h>

#include "ErrorHandling.h"
#include "UIKit.Xaml.Export.h"

// The values in this enum are copied from UIControl.h, use this enum for custom controls in C++ to compare state information
// passed from UIKit to XAML.
enum ControlStates { ControlStateNormal = 0, ControlStateHighlighted = 1 << 0, ControlStateDisabled = 1 << 1 };

////////////////////////////////////////////////////////////////////////////////////
// Button.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Button as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateButton(IInspectable** created);

// Retrieves the UIKit::Button's internal UIKit::Label as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetButtonLabel(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton);

// Retrieves the UIKit::Button's internal Xaml Image as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetButtonImage(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton);

UIKIT_XAML_EXPORT void XamlButtonApplyVisuals(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton,
                                              const Microsoft::WRL::ComPtr<IInspectable>& inspectableImage,
                                              const Microsoft::WRL::ComPtr<IInspectable>& inspectableBorderBackgroundBrush);

// Hooks pointer events on a UIKit::Button passed in as IInspectable
UIKIT_XAML_EXPORT void XamlHookButtonPointerEvents(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerPressedHook,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerMovedHook,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerReleasedHook,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerCanceledHook,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerCaptureLostHook);

UIKIT_XAML_EXPORT void XamlRemovePointerEvents(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton);

////////////////////////////////////////////////////////////////////////////////////
// Label.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Label as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateLabel(IInspectable** created);

// Retrieves the UIKit::Label's backing TextBlock as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetLabelTextBlock(const Microsoft::WRL::ComPtr<IInspectable>& label);

////////////////////////////////////////////////////////////////////////////////////
// Layer.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Initializes our library for use; registers dependency properties, etc.
UIKIT_XAML_EXPORT void UIKitXamlInitialize();

// Set one or more layer properties for the specified target xaml element
UIKIT_XAML_EXPORT void XamlSetFrameworkElementLayerProperties(const Microsoft::WRL::ComPtr<IInspectable>& targetElement,
                                                              const Microsoft::WRL::ComPtr<IInspectable>& sublayerCanvasProperty,
                                                              const Microsoft::WRL::ComPtr<IInspectable>& layerContentProperty);

// Get the layerContentProperty for the specified target xaml element
UIKIT_XAML_EXPORT IInspectable* XamlGetFrameworkElementLayerContentProperty(const Microsoft::WRL::ComPtr<IInspectable>& targetElement);

// Get the sublayerCanvasProperty for the specified target xaml element
UIKIT_XAML_EXPORT IInspectable* XamlGetFrameworkElementSublayerCanvasProperty(const Microsoft::WRL::ComPtr<IInspectable>& targetElement);

////////////////////////////////////////////////////////////////////////////////////
// ActivityIndicatorView.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Xaml::ActivityIndicatorView as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateActivityIndicatorView(IInspectable** created);

// Retrieves the UIKit::Xaml::ActivityIndicatorView's backing ProgressRing as an IInspetable
UIKIT_XAML_EXPORT IInspectable* XamlGetInternalProgressRing(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable);

// Retrieves the IsActive property value, denoting if the ActivityIndicatorView is currently animating
UIKIT_XAML_EXPORT bool XamlGetActivityIndicatorViewIsActiveValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable);

// Sets the IsActive property value to start or stop animation of the ActivityIndicatorView
UIKIT_XAML_EXPORT void XamlSetActivityIndicatorViewIsActiveValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable,
                                                                 bool isActive);

// Retrieves the Foreground property value, represending the color of the ActivityIndicatorView
UIKIT_XAML_EXPORT IInspectable* XamlGetActivityIndicatorViewForegroundValue(
    const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable);

// Sets the Foreground property value to set the color of the ActivityIndicatorView
UIKIT_XAML_EXPORT void XamlSetActivityIndicatorViewForegroundValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable,
                                                                   const Microsoft::WRL::ComPtr<IInspectable>& inspectableForegroundBrush);

// Sets the Height property value of the ActivityIndicatorView
UIKIT_XAML_EXPORT void XamlSetActivityIndicatorViewHeightValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable,
                                                               double height);

// Sets the Width property value of the ActivityIndicatorView
UIKIT_XAML_EXPORT void XamlSetActivityIndicatorViewWidthValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable,
                                                              double width);

////////////////////////////////////////////////////////////////////////////////////
// ProgressView.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Xaml::ProgressView as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateProgressView(IInspectable** created);

// Retrieves the UIKit::Xaml::ProgressView's backing ProgressBar as an IInspetable
UIKIT_XAML_EXPORT IInspectable* XamlGetInternalProgressBar(const Microsoft::WRL::ComPtr<IInspectable>& progressVewInspectable);

// Retrieves the Value property value, denoting the ProgressView's progress
UIKIT_XAML_EXPORT double XamlGetProgressViewValue(const Microsoft::WRL::ComPtr<IInspectable>& progressViewInspectable);

// Sets the Value property value to update the progress of the ProgressView
UIKIT_XAML_EXPORT void XamlSetProgressViewValue(const Microsoft::WRL::ComPtr<IInspectable>& progressViewInspectable, double value);

// Sets the Foreground property value to set the progress fill color of the ProgressView
UIKIT_XAML_EXPORT void XamlSetProgressViewForegroundValue(const Microsoft::WRL::ComPtr<IInspectable>& progressViewInspectable,
                                                          const Microsoft::WRL::ComPtr<IInspectable>& inspectableForegroundBrush);

// Sets the Background property value to set the track color of the ProgressView
UIKIT_XAML_EXPORT void XamlSetProgressViewBackgroundValue(const Microsoft::WRL::ComPtr<IInspectable>& progressViewInspectable,
                                                          const Microsoft::WRL::ComPtr<IInspectable>& inspectableForegroundBrush);

////////////////////////////////////////////////////////////////////////////////////
// ScrollView.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Xaml::ScrollView as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateScrollView(IInspectable** created);

// Retrieves the UIKit::Xaml::ScrollView's backing ScrollViewer as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlScrollViewGetScrollViewer(const Microsoft::WRL::ComPtr<IInspectable>& scrollView);

// Retrieves Canvas inside of UIKit::Xaml::ScrollView's backing ScrollViewer as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlScrollViewGetSubLayerCanvas(const Microsoft::WRL::ComPtr<IInspectable>& scrollView);

////////////////////////////////////////////////////////////////////////////////////
// Slider.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Slider as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateSlider(IInspectable** created);

////////////////////////////////////////////////////////////////////////////////////
// TextField.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Xaml::TextField as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateTextField(IInspectable** created);

// Returns the UIKit::Xaml::TextField's backing Canvas as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldSubLayerCanvas(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

// Retrieves the UIKit::Xaml::TextField's backing TextBox as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldTextBox(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

// Retrieves the UIKit::Xaml::TextField's backing PasswordBox as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldPasswordBox(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

// Toggle the secure text entry value allowing the switch to either the TextBox or PasswordBox backing element
UIKIT_XAML_EXPORT void XamlSetTextFieldSecureTextEntryValue(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField,
                                                            bool secureTextEntry);

UIKIT_XAML_EXPORT bool XamlGetTextFieldSecureTextEntryValue(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlSetTextFieldText(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField, const std::wstring& text);

UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldText(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlSetTextFieldPlaceholder(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField,
                                                   const std::wstring& text);

UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldPlaceholder(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlSetTextFieldInputScope(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField,
                                                  int inputScopeNameValue);

UIKIT_XAML_EXPORT void XamlSetTextFieldEnabled(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField, bool enabled);

UIKIT_XAML_EXPORT bool XamlGetTextFieldEnabled(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlTextFieldKillFocus(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlSetTextFieldTextColor(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField,
                                                 const Microsoft::WRL::ComPtr<IInspectable>& foreground);

UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldTextColor(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlSetTextFieldBackgroundColor(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField,
                                                       const Microsoft::WRL::ComPtr<IInspectable>& backgroundColorBrush);

UIKIT_XAML_EXPORT IInspectable* XamlGetTextFieldBackgroundColor(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlSetTextFieldBackgroundImage(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField,
                                                       const Microsoft::WRL::ComPtr<IInspectable>& backgroundImageBrush);

UIKIT_XAML_EXPORT void XamlSetTextFieldTextAlignment(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField, int textAlignment);

UIKIT_XAML_EXPORT int XamlGetTextFieldTextAlignment(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT bool XamlGetTextFieldEditing(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT bool XamlTextFieldBecomeFirstResponder(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlTextFieldRegisterEventHandlers(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField,
                                                          const Microsoft::WRL::ComPtr<IInspectable>& textChangedHandler,
                                                          const Microsoft::WRL::ComPtr<IInspectable>& gotFocusHandler,
                                                          const Microsoft::WRL::ComPtr<IInspectable>& lostFocusHanlder,
                                                          const Microsoft::WRL::ComPtr<IInspectable>& enterKeyDownHandler);

UIKIT_XAML_EXPORT void XamlTextFieldUnregisterEventHandlers(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlSetTextFieldVerticalTextAlignment(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField,
                                                             int verticalTextAlignment);

UIKIT_XAML_EXPORT int XamlGetTextFieldVerticalTextAlignment(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlSetTextFieldBorderStyle(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField, int borderStyle);

UIKIT_XAML_EXPORT int XamlGetTextFieldBorderStyle(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField);

UIKIT_XAML_EXPORT void XamlTextFieldApplyFont(const Microsoft::WRL::ComPtr<IInspectable>& inspectableTextField,
                                              const std::wstring& fontFamilyname,
                                              int fontStrech,
                                              int fontStyle,
                                              double fontSize,
                                              int fontWeight);

////////////////////////////////////////////////////////////////////////////////////
// ContentDialog.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::ContentDialog as an IInspectable
UIKIT_XAML_EXPORT void XamlCreateContentDialog(IInspectable** created);

// Get the index of the button pressed
UIKIT_XAML_EXPORT int XamlContentDialogPressedIndex(const Microsoft::WRL::ComPtr<IInspectable>& inspectableContentDialog);

// Append a new button to the list
UIKIT_XAML_EXPORT unsigned int XamlContentDialogAddButtonWithTitle(const Microsoft::WRL::ComPtr<IInspectable>& inspectableContentDialog,
                                                                   const std::wstring& buttonTitle);

// Get the title for the button at the specified index
UIKIT_XAML_EXPORT IInspectable* XamlContentDialogButtonTitleAtIndex(const Microsoft::WRL::ComPtr<IInspectable>& inspectableContentDialog,
                                                                    unsigned int buttonIndex);

// Get the total number of buttons in the list
UIKIT_XAML_EXPORT unsigned int XamlContentDialogNumberOfButtons(const Microsoft::WRL::ComPtr<IInspectable>& inspectableContentDialog);

// Set the cancel button index and apply the appropriate theme
UIKIT_XAML_EXPORT void XamlContentDialogSetCancelButtonIndex(const Microsoft::WRL::ComPtr<IInspectable>& inspectableContentDialog,
                                                             unsigned int cancelButtonIndex);

// Set the destructive button index and apply the appropriate theme
UIKIT_XAML_EXPORT void XamlContentDialogSetDestructiveButtonIndex(const Microsoft::WRL::ComPtr<IInspectable>& inspectableContentDialog,
                                                                  unsigned int destructiveButtonIndex);

////////////////////////////////////////////////////////////////////////////////////
// Shared Helpers
////////////////////////////////////////////////////////////////////////////////////
#ifndef __OBJC__

// Converts a Platform::Object^ to a ComPtr<IInspectable>; throws on failure.
inline Microsoft::WRL::ComPtr<IInspectable> InspectableFromObject(Platform::Object ^ object) {
    Microsoft::WRL::ComPtr<IUnknown> unknown(reinterpret_cast<IUnknown*>(object));
    Microsoft::WRL::ComPtr<IInspectable> inspectable;
    THROW_IF_FAILED(unknown.As(&inspectable));
    return inspectable;
}

template <typename T>
Microsoft::WRL::ComPtr<T> InspectableToType(const Microsoft::WRL::ComPtr<IInspectable>& inspectable) {
    Microsoft::WRL::ComPtr<T> to;
    if (inspectable) {
        THROW_IF_FAILED(inspectable.As(&to));
    }
    return to;
}

template <typename T>
Microsoft::WRL::ComPtr<T> ObjectToType(Platform::Object ^ object) {
    return InspectableToType<T>(InspectableFromObject(object));
}

#endif