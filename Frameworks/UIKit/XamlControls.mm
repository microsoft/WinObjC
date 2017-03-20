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

using namespace Microsoft::WRL;

namespace XamlControls {

////////////////////////////////////////////////////////////////////////////////////
// Button
////////////////////////////////////////////////////////////////////////////////////
WXCButton* CreateButton() {
    ComPtr<IInspectable> inspectable;
    XamlCreateButton(&inspectable);
    return _createRtProxy([WXCButton class], inspectable.Get());
}

void HookButtonPointerEvents(WXCButton* button,
                             WUXIPointerEventHandler pointerPressedHook,
                             WUXIPointerEventHandler pointerMovedHook,
                             WUXIPointerEventHandler pointerReleasedHook,
                             WUXIPointerEventHandler pointerCanceledHook,
                             WUXIPointerEventHandler pointerCaptureLostHook) {
    XamlHookButtonPointerEvents([button comObj],
                                pointerPressedHook ? Make<WUXIPointerEventHandler_shim>(pointerPressedHook) : nullptr,
                                pointerMovedHook ? Make<WUXIPointerEventHandler_shim>(pointerMovedHook) : nullptr,
                                pointerReleasedHook ? Make<WUXIPointerEventHandler_shim>(pointerReleasedHook) : nullptr,
                                pointerCanceledHook ? Make<WUXIPointerEventHandler_shim>(pointerCanceledHook) : nullptr,
                                pointerCaptureLostHook ? Make<WUXIPointerEventHandler_shim>(pointerCaptureLostHook) : nullptr);
}

////////////////////////////////////////////////////////////////////////////////////
// ContentDialog
////////////////////////////////////////////////////////////////////////////////////
WXCContentDialog* CreateContentDialog() {
    ComPtr<IInspectable> inspectable;
    XamlCreateContentDialog(&inspectable);
    return _createRtProxy([WXCContentDialog class], inspectable.Get());
}

int XamlContentDialogPressedIndex(WXCContentDialog* contentDialog) {
    ComPtr<IInspectable> inspectable([contentDialog comObj]);
    return XamlContentDialogPressedIndex(inspectable);
}

unsigned int XamlContentDialogAddButtonWithTitle(WXCContentDialog* contentDialog, NSString* buttonTitle) {
    ComPtr<IInspectable> inspectable([contentDialog comObj]);

    auto title = Strings::NarrowToWide<std::wstring>([buttonTitle UTF8String]);
    return XamlContentDialogAddButtonWithTitle(inspectable, title);
}

NSString* XamlContentDialogButtonTitleAtIndex(WXCContentDialog* contentDialog, unsigned int buttonIndex) {
    ComPtr<IInspectable> inspectable([contentDialog comObj]);

    ComPtr<IInspectable> inspPropVal(XamlContentDialogButtonTitleAtIndex(inspectable, buttonIndex));
    return XamlUtilities::NSStringFromPropertyValue(inspPropVal);
}

unsigned int XamlContentDialogNumberOfButtons(WXCContentDialog* contentDialog) {
    ComPtr<IInspectable> inspectable([contentDialog comObj]);
    return XamlContentDialogNumberOfButtons(inspectable);
}

void XamlContentDialogSetCancelButtonIndex(WXCContentDialog* contentDialog, unsigned int cancelButtonIndex) {
    ComPtr<IInspectable> inspectable([contentDialog comObj]);
    XamlContentDialogSetCancelButtonIndex(inspectable, cancelButtonIndex);
}

void XamlContentDialogSetDestructiveButtonIndex(WXCContentDialog* contentDialog, unsigned int destructiveButtonIndex) {
    ComPtr<IInspectable> inspectable([contentDialog comObj]);
    XamlContentDialogSetDestructiveButtonIndex(inspectable, destructiveButtonIndex);
}

////////////////////////////////////////////////////////////////////////////////////
// Label
////////////////////////////////////////////////////////////////////////////////////
WXCGrid* CreateLabel() {
    Microsoft::WRL::ComPtr<IInspectable> inspectable;
    XamlCreateLabel(&inspectable);
    return _createRtProxy([WXCGrid class], inspectable.Get());
}

WXCTextBlock* GetLabelTextBlock(WXCGrid* labelGrid) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetLabelTextBlock([labelGrid comObj]));
    return _createRtProxy([WXCTextBlock class], inspectable.Get());
}

////////////////////////////////////////////////////////////////////////////////////
// ScrollView
////////////////////////////////////////////////////////////////////////////////////
WXFrameworkElement* CreateScrollView() {
    Microsoft::WRL::ComPtr<IInspectable> inspectable;
    XamlCreateScrollView(&inspectable);
    return _createRtProxy([WXFrameworkElement class], inspectable.Get());
}

WXCScrollViewer* ScrollViewGetInnerScrollViewer(WXFrameworkElement* scrollView) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetScrollViewer([scrollView comObj]));
    return _createRtProxy([WXCScrollViewer class], inspectable.Get());
}

WXCCanvas* ScrollViewGetSubLayerCanvas(WXFrameworkElement* scrollView) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlScrollViewGetSubLayerCanvas([scrollView comObj]));
    return _createRtProxy([WXCCanvas class], inspectable.Get());
}

////////////////////////////////////////////////////////////////////////////////////
// CoreAnimation Layer Support
////////////////////////////////////////////////////////////////////////////////////
void SetFrameworkElementLayerProperties(WXFrameworkElement* targetElement,
                                        WXCImage* layerContentProperty,
                                        WXCCanvas* sublayerCanvasProperty) {
    XamlSetFrameworkElementLayerProperties([targetElement comObj],
                                           layerContentProperty ? [layerContentProperty comObj] : nullptr,
                                           sublayerCanvasProperty ? [sublayerCanvasProperty comObj] : nullptr);
}

WXCImage* GetFrameworkElementLayerContentProperty(WXFrameworkElement* targetElement) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetFrameworkElementLayerContentProperty([targetElement comObj]));
    return _createRtProxy([WXCImage class], inspectable.Get());
}

WXCCanvas* GetFrameworkElementSublayerCanvasProperty(WXFrameworkElement* targetElement) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlGetFrameworkElementSublayerCanvasProperty([targetElement comObj]));
    return _createRtProxy([WXCCanvas class], inspectable.Get());
}

} // namespace XamlControls