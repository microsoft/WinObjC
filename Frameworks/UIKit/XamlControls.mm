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
    ComPtr<IInspectable> inspectable(XamlCreateButton());
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

void HookLayoutEvent(WXCButton* button, WUXIPointerEventHandler layoutHook) {
    XamlHookLayoutEvent([button comObj], layoutHook ? Make<WUXIPointerEventHandler_shim>(layoutHook) : nullptr);
}

////////////////////////////////////////////////////////////////////////////////////
// ContentDialog
////////////////////////////////////////////////////////////////////////////////////
WXCContentDialog* CreateContentDialog() {
    ComPtr<IInspectable> inspectable(XamlCreateContentDialog());
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
    return NSStringFromPropertyValue(inspPropVal);
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

} // namespace XamlControls