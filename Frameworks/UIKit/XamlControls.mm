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
#include "XamlControls.h"

#include "../UIKit.Xaml/ObjCXamlControls.h"

#include "XamlUtilities.h"
#include "CppWinRTHelpers.h"

using namespace Microsoft::WRL;
using namespace winrt::Windows::UI::Xaml;

namespace XamlControls {

////////////////////////////////////////////////////////////////////////////////////
// ActivityIndicatorView
////////////////////////////////////////////////////////////////////////////////////
Controls::Grid CreateActivityIndicatorView() {
    ComPtr<IInspectable> inspectable;
    XamlCreateActivityIndicatorView(&inspectable);
    return objcwinrt::from_insp<Controls::Grid>(inspectable);
}

Controls::ProgressRing XamlGetInternalProgressRing(const Controls::Grid& activityIndicatorControl) {
    ComPtr<IInspectable> inspectable(XamlGetInternalProgressRing(objcwinrt::to_insp(activityIndicatorControl)));
    return objcwinrt::from_insp<Controls::ProgressRing>(inspectable);
}

bool GetActivityIndicatorViewIsActiveValue(const FrameworkElement& activityIndicatorControl) {
    return XamlGetActivityIndicatorViewIsActiveValue(objcwinrt::to_insp(activityIndicatorControl));
}

void SetActivityIndicatorViewIsActiveValue(const FrameworkElement& activityIndicatorControl, bool isActive) {
    XamlSetActivityIndicatorViewIsActiveValue(objcwinrt::to_insp(activityIndicatorControl), isActive);
}

Media::SolidColorBrush GetActivityIndicatorViewForegroundValue(const FrameworkElement& activityIndicatorControl) {
    ComPtr<IInspectable> inspectable(XamlGetActivityIndicatorViewForegroundValue(objcwinrt::to_insp(activityIndicatorControl)));
    return objcwinrt::from_insp<Media::SolidColorBrush>(inspectable);
}

void SetActivityIndicatorViewForegroundValue(const FrameworkElement& activityIndicatorControl,
                                             const Media::SolidColorBrush& foregroundColorBrush) {
    XamlSetActivityIndicatorViewForegroundValue(objcwinrt::to_insp(activityIndicatorControl), objcwinrt::to_insp(foregroundColorBrush));
}

void SetActivityIndicatorViewHeightValue(const FrameworkElement& activityIndicatorControl, double height) {
    XamlSetActivityIndicatorViewHeightValue(objcwinrt::to_insp(activityIndicatorControl), height);
}

void SetActivityIndicatorViewWidthValue(const FrameworkElement& activityIndicatorControl, double width) {
    XamlSetActivityIndicatorViewWidthValue(objcwinrt::to_insp(activityIndicatorControl), width);
}

////////////////////////////////////////////////////////////////////////////////////
// ProgressView
////////////////////////////////////////////////////////////////////////////////////
Controls::Grid CreateProgressView() {
    ComPtr<IInspectable> inspectable;
    XamlCreateProgressView(&inspectable);
    return objcwinrt::from_insp<Controls::Grid>(inspectable);
}

Controls::ProgressBar XamlGetInternalProgressBar(const Controls::Grid& progressViewControl) {
    ComPtr<IInspectable> inspectable(XamlGetInternalProgressBar(objcwinrt::to_insp(progressViewControl)));
    return objcwinrt::from_insp<Controls::ProgressBar>(inspectable);
}

double GetProgressViewValue(const FrameworkElement& progressViewControl) {
    return XamlGetProgressViewValue(objcwinrt::to_insp(progressViewControl));
}

void SetProgressViewValue(const FrameworkElement& progressViewControl, double value) {
    XamlSetProgressViewValue(objcwinrt::to_insp(progressViewControl), value);
}

void SetProgressViewForegroundValue(const FrameworkElement& progressViewControl, const Media::Brush& foregroundColorBrush) {
    XamlSetProgressViewForegroundValue(objcwinrt::to_insp(progressViewControl), objcwinrt::to_insp(foregroundColorBrush));
}

void SetProgressViewBackgroundValue(const FrameworkElement& progressViewControl, const Media::Brush& backgroundColorBrush) {
    XamlSetProgressViewBackgroundValue(objcwinrt::to_insp(progressViewControl), objcwinrt::to_insp(backgroundColorBrush));
}

////////////////////////////////////////////////////////////////////////////////////
// Button
////////////////////////////////////////////////////////////////////////////////////
Controls::Button CreateButton() {
    ComPtr<IInspectable> inspectable;
    XamlCreateButton(&inspectable);

    return objcwinrt::from_insp<Controls::Button>(inspectable);
}

FrameworkElement GetButtonLabel(const Controls::Button& button) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetButtonLabel(objcwinrt::to_insp(button)));
    return objcwinrt::from_insp<FrameworkElement>(inspectable);
}

Controls::Image GetButtonImage(const Controls::Button& button) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetButtonImage(objcwinrt::to_insp(button)));
    return objcwinrt::from_insp<Controls::Image>(inspectable);
}

void HookButtonPointerEvents(const Controls::Button& button,
                             const Input::PointerEventHandler& pointerPressedHook,
                             const Input::PointerEventHandler& pointerMovedHook,
                             const Input::PointerEventHandler& pointerReleasedHook,
                             const Input::PointerEventHandler& pointerCanceledHook,
                             const Input::PointerEventHandler& pointerCaptureLostHook) {
    XamlHookButtonPointerEvents(objcwinrt::to_insp(button),
                                pointerPressedHook ? Make<WUXIPointerEventHandler_shim>(pointerPressedHook) : nullptr,
                                pointerMovedHook ? Make<WUXIPointerEventHandler_shim>(pointerMovedHook) : nullptr,
                                pointerReleasedHook ? Make<WUXIPointerEventHandler_shim>(pointerReleasedHook) : nullptr,
                                pointerCanceledHook ? Make<WUXIPointerEventHandler_shim>(pointerCanceledHook) : nullptr,
                                pointerCaptureLostHook ? Make<WUXIPointerEventHandler_shim>(pointerCaptureLostHook) : nullptr);
}

////////////////////////////////////////////////////////////////////////////////////
// ContentDialog
////////////////////////////////////////////////////////////////////////////////////
Controls::ContentDialog CreateContentDialog() {
    ComPtr<IInspectable> inspectable;
    XamlCreateContentDialog(&inspectable);

    return objcwinrt::from_insp<Controls::ContentDialog>(inspectable);
}

int XamlContentDialogPressedIndex(const Controls::ContentDialog& contentDialog) {
    return XamlContentDialogPressedIndex(objcwinrt::to_insp(contentDialog));
}

unsigned int XamlContentDialogAddButtonWithTitle(const Controls::ContentDialog& contentDialog, NSString* buttonTitle) {
    ComPtr<IInspectable> inspectable(objcwinrt::to_insp(contentDialog));

    auto title = Strings::NarrowToWide<std::wstring>([buttonTitle UTF8String]);
    return XamlContentDialogAddButtonWithTitle(inspectable, title);
}

NSString* XamlContentDialogButtonTitleAtIndex(const Controls::ContentDialog& contentDialog, unsigned int buttonIndex) {
    ComPtr<IInspectable> inspectable(objcwinrt::to_insp(contentDialog));

    ComPtr<IInspectable> inspPropVal(XamlContentDialogButtonTitleAtIndex(inspectable, buttonIndex));
    return XamlUtilities::NSStringFromPropertyValue(inspPropVal);
}

unsigned int XamlContentDialogNumberOfButtons(const Controls::ContentDialog& contentDialog) {
    ComPtr<IInspectable> inspectable(objcwinrt::to_insp(contentDialog));
    return XamlContentDialogNumberOfButtons(inspectable);
}

void XamlContentDialogSetCancelButtonIndex(const Controls::ContentDialog& contentDialog, unsigned int cancelButtonIndex) {
    ComPtr<IInspectable> inspectable(objcwinrt::to_insp(contentDialog));
    XamlContentDialogSetCancelButtonIndex(inspectable, cancelButtonIndex);
}

void XamlContentDialogSetDestructiveButtonIndex(const Controls::ContentDialog& contentDialog, unsigned int destructiveButtonIndex) {
    ComPtr<IInspectable> inspectable(objcwinrt::to_insp(contentDialog));
    XamlContentDialogSetDestructiveButtonIndex(inspectable, destructiveButtonIndex);
}

////////////////////////////////////////////////////////////////////////////////////
// Label
////////////////////////////////////////////////////////////////////////////////////
Controls::Grid CreateLabel() {
    Microsoft::WRL::ComPtr<IInspectable> inspectable;
    XamlCreateLabel(&inspectable);

    return objcwinrt::from_insp<Controls::Grid>(inspectable);
}

Controls::TextBlock GetLabelTextBlock(const Controls::Grid& labelGrid) {
    ComPtr<IInspectable> inspectable(XamlGetLabelTextBlock(objcwinrt::to_insp(labelGrid)));
    return objcwinrt::from_insp<Controls::TextBlock>(inspectable);
}

////////////////////////////////////////////////////////////////////////////////////
// TextField
////////////////////////////////////////////////////////////////////////////////////
FrameworkElement CreateTextField() {
    Microsoft::WRL::ComPtr<IInspectable> inspectable;
    XamlCreateTextField(&inspectable);
    return objcwinrt::from_insp<FrameworkElement>(inspectable);
}

Controls::Canvas GetTextFieldSubLayerCanvas(const FrameworkElement& textField) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldSubLayerCanvas(objcwinrt::to_insp(textField)));
    return objcwinrt::from_insp<Controls::Canvas>(inspectable);
}

Controls::TextBox GetTextFieldTextBox(const FrameworkElement& textField) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldTextBox(objcwinrt::to_insp(textField)));
    return objcwinrt::from_insp<Controls::TextBox>(inspectable);
}

Controls::PasswordBox GetTextFieldPasswordBox(const FrameworkElement& textField) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetTextFieldPasswordBox(objcwinrt::to_insp(textField)));
    return objcwinrt::from_insp<Controls::PasswordBox>(inspectable);
}

void SetTextFieldSecureTextEntryValue(const FrameworkElement& textField, bool secureTextEntry) {
    XamlSetTextFieldSecureTextEntryValue(objcwinrt::to_insp(textField), secureTextEntry);
}

bool GetTextFieldSecureTextEntryValue(const FrameworkElement& textField) {
    return XamlGetTextFieldSecureTextEntryValue(objcwinrt::to_insp(textField));
}

void SetTextFieldText(const winrt::Windows::UI::Xaml::FrameworkElement& textField, NSString* text) {
    auto textToSet = Strings::NarrowToWide<std::wstring>([text UTF8String]);
    XamlSetTextFieldText(objcwinrt::to_insp(textField), textToSet);
}

NSString* GetTextFieldText(const winrt::Windows::UI::Xaml::FrameworkElement& textField) {
    ComPtr<IInspectable> inspPropVal(XamlGetTextFieldText(objcwinrt::to_insp(textField)));
    return XamlUtilities::NSStringFromPropertyValue(inspPropVal);
}

void SetTextFieldPlaceholder(const winrt::Windows::UI::Xaml::FrameworkElement& textField, NSString* placeholder) {
    auto placeholderText = Strings::NarrowToWide<std::wstring>([placeholder UTF8String]);
    XamlSetTextFieldPlaceholder(objcwinrt::to_insp(textField), placeholderText);
}

NSString* GetTextFieldPlaceholder(const winrt::Windows::UI::Xaml::FrameworkElement& textField) {
    ComPtr<IInspectable> inspPropVal(XamlGetTextFieldPlaceholder(objcwinrt::to_insp(textField)));
    return XamlUtilities::NSStringFromPropertyValue(inspPropVal);
}

void SetTextFieldInputScope(const winrt::Windows::UI::Xaml::FrameworkElement& textField, UIKeyboardType keyboardType) {
    auto inputScopeNameValue =
        XamlUtilities::ConvertKeyboardTypeToInputScopeNameValue(keyboardType, GetTextFieldSecureTextEntryValue(textField));
    XamlSetTextFieldInputScope(objcwinrt::to_insp(textField), static_cast<int>(inputScopeNameValue));
}

void SetTextFieldEnabled(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, BOOL enabled) {
    XamlSetTextFieldEnabled(objcwinrt::to_insp(inspectableTextField), enabled);
}

bool GetTextFieldEnabled(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    return XamlGetTextFieldEnabled(objcwinrt::to_insp(inspectableTextField));
}

void TextFieldKillFocus(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    XamlTextFieldKillFocus(objcwinrt::to_insp(inspectableTextField));
}

void SetTextFieldTextColor(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UIColor* textColor) {
    auto convertedColor = XamlUtilities::ConvertUIColorToWUColor(textColor);
    Media::SolidColorBrush brush(convertedColor);
    XamlSetTextFieldTextColor(objcwinrt::to_insp(inspectableTextField), objcwinrt::to_insp(brush));
}

UIColor* GetTextFieldTextColor(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    auto foregroundBrush =
        objcwinrt::from_insp<Media::SolidColorBrush>(XamlGetTextFieldTextColor(objcwinrt::to_insp(inspectableTextField)));
    if (foregroundBrush) {
        return XamlUtilities::ConvertWUColorToUIColor(foregroundBrush.Color());
    }

    return nil;
}

void SetTextFieldBackgroundColor(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UIColor* backgroundColor) {
    auto convertedColor = XamlUtilities::ConvertUIColorToWUColor(backgroundColor);
    Media::SolidColorBrush brush(convertedColor);
    XamlSetTextFieldBackgroundColor(objcwinrt::to_insp(inspectableTextField), objcwinrt::to_insp(brush));
}

UIColor* GetTextFieldBackgroundColor(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    auto foregroundBrush =
        objcwinrt::from_insp<Media::SolidColorBrush>(XamlGetTextFieldBackgroundColor(objcwinrt::to_insp(inspectableTextField)));
    if (foregroundBrush) {
        return XamlUtilities::ConvertWUColorToUIColor(foregroundBrush.Color());
    }

    return nil;
}

void SetTextFieldBackgroundImage(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UIImage* backgroundImage) {
    CGImageRef cgImg = [backgroundImage CGImage];
    if (cgImg == NULL) {
        return;
    }

    Microsoft::WRL::ComPtr<IInspectable> inspectableNode(DisplayTexture::GetBitmapForCGImage(cgImg));
    auto bitmapImageSource = objcwinrt::from_insp<Media::Imaging::BitmapSource>(inspectableNode);
    Media::ImageBrush imageBrush;
    imageBrush.ImageSource(bitmapImageSource);

    XamlSetTextFieldBackgroundImage(objcwinrt::to_insp(inspectableTextField), objcwinrt::to_insp(imageBrush));
}

void SetTextFieldTextAlignment(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UITextAlignment alignment) {
    auto textAlignment = XamlUtilities::ConvertUITextAlignmentToWXTextAlignment(alignment);
    XamlSetTextFieldTextAlignment(objcwinrt::to_insp(inspectableTextField), (int)textAlignment);
}

UITextAlignment GetTextFieldTextAlignment(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    auto textAlignment = XamlGetTextFieldTextAlignment(objcwinrt::to_insp(inspectableTextField));
    return XamlUtilities::ConvertWXTextAlignmentToUITextAlignment(static_cast<winrt::Windows::UI::Xaml::TextAlignment>(textAlignment));
}

bool GetTextFieldEditingState(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    return XamlGetTextFieldEditing(objcwinrt::to_insp(inspectableTextField));
}

bool TextFieldBecomeFirstResponder(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    return XamlTextFieldBecomeFirstResponder(objcwinrt::to_insp(inspectableTextField));
}

void TextFieldRegisterEventHandlers(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField,
                                    const RoutedEventHandler& textChangedHandler,
                                    const RoutedEventHandler& gotFocusHandler,
                                    const RoutedEventHandler& lostFocusHanlder,
                                    const RoutedEventHandler& enterKeyDownHandler) {
    XamlTextFieldRegisterEventHandlers(objcwinrt::to_insp(inspectableTextField),
                                       textChangedHandler ? Make<WUXRoutedEventHandler_shim>(textChangedHandler) : nullptr,
                                       gotFocusHandler ? Make<WUXRoutedEventHandler_shim>(gotFocusHandler) : nullptr,
                                       lostFocusHanlder ? Make<WUXRoutedEventHandler_shim>(lostFocusHanlder) : nullptr,
                                       enterKeyDownHandler ? Make<WUXRoutedEventHandler_shim>(enterKeyDownHandler) : nullptr);
}

void TextFieldUnregisterEventHandlers(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    XamlTextFieldUnregisterEventHandlers(objcwinrt::to_insp(inspectableTextField));
}

void SetTextFieldVerticalTextAlignment(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField,
                                       UIControlContentVerticalAlignment verticalTextAlignment) {
    auto verticalAlignment = XamlUtilities::ConvertUIControlContentVerticalAlignmentToWXVerticalAlignment(verticalTextAlignment);
    XamlSetTextFieldVerticalTextAlignment(objcwinrt::to_insp(inspectableTextField), static_cast<int>(verticalAlignment));
}

int GetTextFieldVerticalTextAlignment(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    return static_cast<UITextBorderStyle>(XamlGetTextFieldVerticalTextAlignment(objcwinrt::to_insp(inspectableTextField)));
}

// Set the UIKit::Xaml::TextField's Border property
void SetTextFieldBorderStyle(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField, UITextBorderStyle borderStyle) {
    XamlSetTextFieldBorderStyle(objcwinrt::to_insp(inspectableTextField), static_cast<int>(borderStyle));
}

// Get the UIKit::Xaml::TextField's Border property
UITextBorderStyle GetTextFieldBorderStyle(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField) {
    return static_cast<UITextBorderStyle>(XamlGetTextFieldBorderStyle(objcwinrt::to_insp(inspectableTextField)));
}

void TextFieldApplyFont(const winrt::Windows::UI::Xaml::FrameworkElement& inspectableTextField,
                        NSString* fontFamilyname,
                        DWRITE_FONT_STRETCH fontStrech,
                        DWRITE_FONT_STYLE fontStyle,
                        double fontSize,
                        DWRITE_FONT_WEIGHT fontWeight) {
    XamlTextFieldApplyFont(objcwinrt::to_insp(inspectableTextField),
                           Strings::NarrowToWide<std::wstring>([fontFamilyname UTF8String]),
                           static_cast<int>(fontStrech),
                           static_cast<int>(fontStyle),
                           fontSize,
                           static_cast<int>(fontWeight));
}

////////////////////////////////////////////////////////////////////////////////////
// ScrollView
////////////////////////////////////////////////////////////////////////////////////
FrameworkElement CreateScrollView() {
    Microsoft::WRL::ComPtr<IInspectable> inspectable;
    XamlCreateScrollView(&inspectable);
    return objcwinrt::from_insp<FrameworkElement>(inspectable);
}

Controls::ScrollViewer ScrollViewGetInnerScrollViewer(const FrameworkElement& scrollView) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer(objcwinrt::to_insp(scrollView)));
    return objcwinrt::from_insp<Controls::ScrollViewer>(inspectable);
}

Controls::Canvas ScrollViewGetSubLayerCanvas(const FrameworkElement& scrollView) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetSubLayerCanvas(objcwinrt::to_insp(scrollView)));
    return objcwinrt::from_insp<Controls::Canvas>(inspectable);
}

////////////////////////////////////////////////////////////////////////////////////
// CoreAnimation Layer Support
////////////////////////////////////////////////////////////////////////////////////
void SetFrameworkElementLayerProperties(const FrameworkElement& targetElement,
                                        const Controls::Image& layerContentProperty,
                                        const Controls::Canvas& sublayerCanvasProperty) {
    XamlSetFrameworkElementLayerProperties(objcwinrt::to_insp(targetElement),
                                           objcwinrt::to_insp(layerContentProperty),
                                           objcwinrt::to_insp(sublayerCanvasProperty));
}

Controls::Image GetFrameworkElementLayerContentProperty(const FrameworkElement& targetElement) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetFrameworkElementLayerContentProperty(objcwinrt::to_insp(targetElement)));
    return objcwinrt::from_insp<Controls::Image>(inspectable);
}

Controls::Canvas GetFrameworkElementSublayerCanvasProperty(const FrameworkElement& targetElement) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetFrameworkElementSublayerCanvasProperty(objcwinrt::to_insp(targetElement)));
    return objcwinrt::from_insp<Controls::Canvas>(inspectable);
}

} // namespace XamlControls