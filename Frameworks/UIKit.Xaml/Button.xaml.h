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
#pragma once

#include "Button.g.h"
#include <windows.ui.xaml.input.h>
#include "ObjCXamlControls.h"

namespace UIKit {

[Windows::Foundation::Metadata::WebHostHidden]
public ref class Button sealed {
public:
    Button();
    void OnApplyTemplate() override;
    Windows::Foundation::Size ArrangeOverride(Windows::Foundation::Size finalSize) override;
    void OnPointerPressed(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerMoved(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerReleased(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerCanceled(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerCaptureLost(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;

internal:
    void HookPointerEvents(
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerPressedHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerMovedHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerReleasedHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerCanceledHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerCaptureLostHook);

    void HookLayoutEvent(
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& layoutHook);

    // methods for removing registered events
    void RemovePointerEvents();
    void RemoveLayoutEvent();

    Windows::UI::Xaml::Controls::TextBlock^ _textBlock;
    Windows::UI::Xaml::Controls::Image^ _image;
    Windows::UI::Xaml::Controls::Image^ _backgroundImage;

private:

    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerPressedHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerMovedHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerReleasedHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerCanceledHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerCaptureLostHook;

    // Auto Layout hook, change name and type later
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _layoutHook;
};

}
// clang-format on