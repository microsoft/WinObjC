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