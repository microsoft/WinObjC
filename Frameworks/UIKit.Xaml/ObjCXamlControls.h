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
UIKIT_XAML_EXPORT IInspectable* XamlCreateButton();

UIKIT_XAML_EXPORT void XamlButtonApplyVisuals(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton,
                                              const Microsoft::WRL::ComPtr<IInspectable>& inspectableText,
                                              const Microsoft::WRL::ComPtr<IInspectable>& inspectableImage,
                                              const Microsoft::WRL::ComPtr<IInspectable>& inspectableBackgroundImage,
                                              const RECT insets,
                                              const Microsoft::WRL::ComPtr<IInspectable>& inspectableTitleColor);

// Hooks pointer events on a UIKit::Button passed in as IInspectable
UIKIT_XAML_EXPORT void XamlHookButtonPointerEvents(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerPressedHook,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerMovedHook,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerReleasedHook,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerCanceledHook,
                                                   const Microsoft::WRL::ComPtr<IInspectable>& pointerCaptureLostHook);

// Hooks other events on a UIKit::Button passed in as IInspectable
UIKIT_XAML_EXPORT void XamlHookLayoutEvent(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton,
                                           const Microsoft::WRL::ComPtr<IInspectable>& layoutHook);

UIKIT_XAML_EXPORT void XamlRemovePointerEvents(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton);

UIKIT_XAML_EXPORT void XamlRemoveLayoutEvent(const Microsoft::WRL::ComPtr<IInspectable>& inspectableButton);

////////////////////////////////////////////////////////////////////////////////////
// ProgressRing.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::ProgressRing as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlCreateProgressRing();

////////////////////////////////////////////////////////////////////////////////////
// ScrollViewer.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::ScrollViewer as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlCreateScrollViewer();

////////////////////////////////////////////////////////////////////////////////////
// Slider.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::Slider as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlCreateSlider();

////////////////////////////////////////////////////////////////////////////////////
// TextBox.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::TextBox as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlCreateTextBox();

////////////////////////////////////////////////////////////////////////////////////
// ContentDialog.xaml.cpp
////////////////////////////////////////////////////////////////////////////////////

// Returns a UIKit::ContentDialog as an IInspectable
UIKIT_XAML_EXPORT IInspectable* XamlCreateContentDialog();

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