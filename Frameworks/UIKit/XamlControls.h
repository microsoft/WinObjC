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

#import "Starboard.h"
#include <COMIncludes.h>
#import <DWrite_3.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#import <windows.ui.xaml.input.h>
#import <winrt/Windows.UI.Xaml.h>
#import <winrt/Windows.UI.Xaml.Controls.h>
#import <winrt/Windows.UI.Xaml.Input.h>
#include <COMIncludes_end.h>

#import "UIKit/UITextInputTraits.h"
#import "UIkit/UIKitTypes.h"
#import "UIKit/UIColor.h"
#import "UIkit/UIImage.h"
#import "UIkit/UITextField.h"
#import "StarboardXaml/DisplayTexture.h"

namespace XamlControls {

////////////////////////////////////////////////////////////////////////////////////
// Shared Helpers
////////////////////////////////////////////////////////////////////////////////////
#if !__has_feature(objc_arc)
// TODO: Remove when we move our controls over to actual XAML-build control implementations
class WUXIPointerEventHandler_shim
    : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::WinRtClassicComMix>,
                                          ABI::Windows::UI::Xaml::Input::IPointerEventHandler> {
    winrt::Windows::UI::Xaml::Input::PointerEventHandler _handler;

public:
    WUXIPointerEventHandler_shim(const winrt::Windows::UI::Xaml::Input::PointerEventHandler& handler) : _handler(handler) {
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* arg1) override {
        winrt::Windows::Foundation::IInspectable sender = nullptr;
        winrt::copy_from_abi(sender, reinterpret_cast<winrt::ABI::Windows::Foundation::IInspectable*>(arg0));

        winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs args = nullptr;
        winrt::copy_from_abi(args, reinterpret_cast<winrt::ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs*>(arg1));

        NSAutoreleasePool* p = [NSAutoreleasePool new];
        _handler(sender, args);
        [p release];

        return 0;
    }
};

class WUXRoutedEventHandler_shim
    : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::WinRtClassicComMix>,
                                          ABI::Windows::UI::Xaml::IRoutedEventHandler> {
    winrt::Windows::UI::Xaml::RoutedEventHandler _handler;

public:
    WUXRoutedEventHandler_shim(const winrt::Windows::UI::Xaml::RoutedEventHandler& handler) : _handler(handler) {
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IRoutedEventArgs* arg1) override {
        winrt::Windows::Foundation::IInspectable sender = nullptr;
        winrt::copy_from_abi(sender, reinterpret_cast<winrt::ABI::Windows::Foundation::IInspectable*>(arg0));

        winrt::Windows::UI::Xaml::RoutedEventArgs args = nullptr;
        winrt::copy_from_abi(args, reinterpret_cast<winrt::ABI::Windows::UI::Xaml::IRoutedEventArgs*>(arg1));

        NSAutoreleasePool* p = [NSAutoreleasePool new];
        _handler(sender, args);
        [p release];

        return 0;
    }
};

#endif // __has_feature(objc_arc)

////////////////////////////////////////////////////////////////////////////////////
// ActivityIndicatorView
////////////////////////////////////////////////////////////////////////////////////
winrt::Windows::UI::Xaml::Controls::Grid CreateActivityIndicatorView();

winrt::Windows::UI::Xaml::Controls::ProgressRing XamlGetInternalProgressRing(
    const winrt::Windows::UI::Xaml::Controls::Grid& activityIndicatorInspectable);

bool GetActivityIndicatorViewIsActiveValue(const winrt::Windows::UI::Xaml::FrameworkElement& activityIndicatorInspectable);

void SetActivityIndicatorViewIsActiveValue(const winrt::Windows::UI::Xaml::FrameworkElement& activityIndicatorInspectable, bool isActive);

winrt::Windows::UI::Xaml::Media::SolidColorBrush GetActivityIndicatorViewForegroundValue(
    const winrt::Windows::UI::Xaml::FrameworkElement& activityIndicatorInspectable);

void SetActivityIndicatorViewForegroundValue(const winrt::Windows::UI::Xaml::FrameworkElement& activityIndicatorInspectable,
                                             const winrt::Windows::UI::Xaml::Media::SolidColorBrush& foregroundColorBrush);

void SetActivityIndicatorViewHeightValue(const winrt::Windows::UI::Xaml::FrameworkElement& activityIndicatorInspectable, double height);
void SetActivityIndicatorViewWidthValue(const winrt::Windows::UI::Xaml::FrameworkElement& activityIndicatorInspectable, double width);

////////////////////////////////////////////////////////////////////////////////////
// ProgressView
////////////////////////////////////////////////////////////////////////////////////
winrt::Windows::UI::Xaml::Controls::Grid CreateProgressView();

winrt::Windows::UI::Xaml::Controls::ProgressBar XamlGetInternalProgressBar(
    const winrt::Windows::UI::Xaml::Controls::Grid& progressViewInspectable);

double GetProgressViewValue(const winrt::Windows::UI::Xaml::FrameworkElement& progressViewInspectable);

void SetProgressViewValue(const winrt::Windows::UI::Xaml::FrameworkElement& progressViewInspectable, double value);

void SetProgressViewForegroundValue(const winrt::Windows::UI::Xaml::FrameworkElement& progressViewInspectable,
                                    const winrt::Windows::UI::Xaml::Media::Brush& foregroundColorBrush);

void SetProgressViewBackgroundValue(const winrt::Windows::UI::Xaml::FrameworkElement& progressViewInspectable,
                                    const winrt::Windows::UI::Xaml::Media::Brush& backgroundColorBrush);

////////////////////////////////////////////////////////////////////////////////////
// Button
////////////////////////////////////////////////////////////////////////////////////
winrt::Windows::UI::Xaml::Controls::Button CreateButton();
winrt::Windows::UI::Xaml::FrameworkElement GetButtonLabel(const winrt::Windows::UI::Xaml::Controls::Button& button);
winrt::Windows::UI::Xaml::Controls::Image GetButtonImage(const winrt::Windows::UI::Xaml::Controls::Button& button);

void HookButtonPointerEvents(const winrt::Windows::UI::Xaml::Controls::Button& button,
                             const winrt::Windows::UI::Xaml::Input::PointerEventHandler& pointerPressedHook,
                             const winrt::Windows::UI::Xaml::Input::PointerEventHandler& pointerMovedHook,
                             const winrt::Windows::UI::Xaml::Input::PointerEventHandler& pointerReleasedHook,
                             const winrt::Windows::UI::Xaml::Input::PointerEventHandler& pointerCanceledHook,
                             const winrt::Windows::UI::Xaml::Input::PointerEventHandler& pointerCaptureLostHook);

////////////////////////////////////////////////////////////////////////////////////
// ContentDialog
////////////////////////////////////////////////////////////////////////////////////
winrt::Windows::UI::Xaml::Controls::ContentDialog CreateContentDialog();

int XamlContentDialogPressedIndex(const winrt::Windows::UI::Xaml::Controls::ContentDialog& contentDialog);

unsigned int XamlContentDialogAddButtonWithTitle(const winrt::Windows::UI::Xaml::Controls::ContentDialog& contentDialog,
                                                 NSString* buttonTitle);

NSString* XamlContentDialogButtonTitleAtIndex(const winrt::Windows::UI::Xaml::Controls::ContentDialog& contentDialog,
                                              unsigned int buttonIndex);

unsigned int XamlContentDialogNumberOfButtons(const winrt::Windows::UI::Xaml::Controls::ContentDialog& contentDialog);

void XamlContentDialogSetCancelButtonIndex(const winrt::Windows::UI::Xaml::Controls::ContentDialog& contentDialog,
                                           unsigned int cancelButtonIndex);

void XamlContentDialogSetDestructiveButtonIndex(const winrt::Windows::UI::Xaml::Controls::ContentDialog& contentDialog,
                                                unsigned int destructiveButtonIndex);

////////////////////////////////////////////////////////////////////////////////////
// Label
////////////////////////////////////////////////////////////////////////////////////
winrt::Windows::UI::Xaml::Controls::Grid CreateLabel();
winrt::Windows::UI::Xaml::Controls::TextBlock GetLabelTextBlock(const winrt::Windows::UI::Xaml::Controls::Grid& labelGrid);

////////////////////////////////////////////////////////////////////////////////////
// TextField
////////////////////////////////////////////////////////////////////////////////////
winrt::Windows::UI::Xaml::FrameworkElement CreateTextField();
winrt::Windows::UI::Xaml::Controls::Canvas GetTextFieldSubLayerCanvas(const winrt::Windows::UI::Xaml::FrameworkElement& textField);
winrt::Windows::UI::Xaml::Controls::TextBox GetTextFieldTextBox(const winrt::Windows::UI::Xaml::FrameworkElement& textField);
winrt::Windows::UI::Xaml::Controls::PasswordBox GetTextFieldPasswordBox(const winrt::Windows::UI::Xaml::FrameworkElement& textField);

// setter and getter for properties
void SetTextFieldSecureTextEntryValue(const winrt::Windows::UI::Xaml::FrameworkElement& textField, bool secureTextEntry);
bool GetTextFieldSecureTextEntryValue(const winrt::Windows::UI::Xaml::FrameworkElement& textField);

void SetTextFieldText(const winrt::Windows::UI::Xaml::FrameworkElement& textField, NSString* buttonTitle);
NSString* GetTextFieldText(const winrt::Windows::UI::Xaml::FrameworkElement& textField);

void SetTextFieldPlaceholder(const winrt::Windows::UI::Xaml::FrameworkElement& textField, NSString* placeholder);
NSString* GetTextFieldPlaceholder(const winrt::Windows::UI::Xaml::FrameworkElement& textField);

void SetTextFieldInputScope(const winrt::Windows::UI::Xaml::FrameworkElement& textField, UIKeyboardType keyboardType);

void SetTextFieldEnabled(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, BOOL enabled);
bool GetTextFieldEnabled(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);

void TextFieldKillFocus(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);
bool TextFieldBecomeFirstResponder(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);

void SetTextFieldTextColor(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UIColor* color);
UIColor* GetTextFieldTextColor(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);

void SetTextFieldBackgroundColor(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UIColor* backgroundColor);
UIColor* GetTextFieldBackgroundColor(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);

void SetTextFieldBackgroundImage(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UIImage* backgroundImage);

void SetTextFieldTextAlignment(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UITextAlignment alignment);
UITextAlignment GetTextFieldTextAlignment(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);

bool GetTextFieldEditingState(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);

void TextFieldRegisterEventHandlers(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField,
                                    const winrt::Windows::UI::Xaml::RoutedEventHandler& textChangedHandler,
                                    const winrt::Windows::UI::Xaml::RoutedEventHandler& gotFocusHandler,
                                    const winrt::Windows::UI::Xaml::RoutedEventHandler& lostFocusHanlder,
                                    const winrt::Windows::UI::Xaml::RoutedEventHandler& enterKeyDownHandler);

void TextFieldUnregisterEventHandlers(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);

void SetTextFieldVerticalTextAlignment(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField,
                                       UIControlContentVerticalAlignment verticalTextAlignment);

int GetTextFieldVerticalTextAlignment(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);

void SetTextFieldBorderStyle(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UITextBorderStyle borderStyle);

UITextBorderStyle GetTextFieldBorderStyle(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField);

void TextFieldApplyFont(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField,
                        NSString* fontFamilyname,
                        DWRITE_FONT_STRETCH fontStrech,
                        DWRITE_FONT_STYLE fontStyle,
                        double fontSize,
                        DWRITE_FONT_WEIGHT fontWeight);

////////////////////////////////////////////////////////////////////////////////////
// ScrollView
////////////////////////////////////////////////////////////////////////////////////
winrt::Windows::UI::Xaml::FrameworkElement CreateScrollView();

winrt::Windows::UI::Xaml::Controls::ScrollViewer ScrollViewGetInnerScrollViewer(
    const winrt::Windows::UI::Xaml::FrameworkElement& scrollView);

winrt::Windows::UI::Xaml::Controls::Canvas ScrollViewGetSubLayerCanvas(const winrt::Windows::UI::Xaml::FrameworkElement& scrollView);

////////////////////////////////////////////////////////////////////////////////////
// CoreAnimation Layer Support
////////////////////////////////////////////////////////////////////////////////////

// Set one or more layer properties for the specified target xaml element
void SetFrameworkElementLayerProperties(const winrt::Windows::UI::Xaml::FrameworkElement& targetElement,
                                        const winrt::Windows::UI::Xaml::Controls::Image& layerContentProperty,
                                        const winrt::Windows::UI::Xaml::Controls::Canvas& sublayerCanvasProperty);

// Get the layerContentProperty for the specified target xaml element
winrt::Windows::UI::Xaml::Controls::Image GetFrameworkElementLayerContentProperty(
    const winrt::Windows::UI::Xaml::FrameworkElement& targetElement);

// Get the sublayerCanvasProperty for the specified target xaml element
winrt::Windows::UI::Xaml::Controls::Canvas GetFrameworkElementSublayerCanvasProperty(
    const winrt::Windows::UI::Xaml::FrameworkElement& targetElement);

} // namespace XamlControls