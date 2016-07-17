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

using namespace Microsoft::WRL;

namespace XamlControls {

////////////////////////////////////////////////////////////////////////////////////
// Button
////////////////////////////////////////////////////////////////////////////////////
WXCButton* CreateButton() {
    Microsoft::WRL::ComPtr<IInspectable> inspectable(XamlCreateButton());
    return _createRtProxy([WXCButton class], inspectable.Get());
}

void HookButtonPointerEvents(WXCButton* button,
                             WUXIPointerEventHandler pointerPressedHook,
                             WUXIPointerEventHandler pointerMovedHook,
                             WUXIPointerEventHandler pointerReleasedHook,
                             WUXIPointerEventHandler pointerCanceledHook,
                             WUXIPointerEventHandler pointerCaptureLostHook) {
    XamlHookButtonPointerEvents([button comObj],
                                pointerPressedHook ? Microsoft::WRL::Make<WUXIPointerEventHandler_shim>(pointerPressedHook) : nullptr,
                                pointerMovedHook ? Microsoft::WRL::Make<WUXIPointerEventHandler_shim>(pointerMovedHook) : nullptr,
                                pointerReleasedHook ? Microsoft::WRL::Make<WUXIPointerEventHandler_shim>(pointerReleasedHook) : nullptr,
                                pointerCanceledHook ? Microsoft::WRL::Make<WUXIPointerEventHandler_shim>(pointerCanceledHook) : nullptr,
                                pointerCaptureLostHook ? Microsoft::WRL::Make<WUXIPointerEventHandler_shim>(pointerCaptureLostHook) :
                                                         nullptr);
}

} // namespace XamlControls