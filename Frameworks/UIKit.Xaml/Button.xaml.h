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
#include "ILayer.h"
#include "Label.Xaml.h"
#include <windows.ui.xaml.input.h>
#include "ObjCXamlControls.h"

namespace UIKit {
namespace Xaml {

[Windows::Foundation::Metadata::WebHostHidden]
public ref class Button sealed : public Private::CoreAnimation::ILayer {
public:
    Button();
    void OnApplyTemplate() override;

    void OnPointerPressed(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerMoved(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerReleased(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerCanceled(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;
    void OnPointerCaptureLost(Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e) override;

    // Accessor for our Layer content; we create one on demand
    virtual property Windows::UI::Xaml::Controls::Image^ LayerContent {
        Windows::UI::Xaml::Controls::Image^ get();
    }

    // Accessor to check for exising Layer content
    virtual property bool HasLayerContent {
        bool get();
    }

    // Accessor for our SublayerCanvas; we create one on demand
    virtual property Windows::UI::Xaml::Controls::Canvas^ SublayerCanvas {
        Windows::UI::Xaml::Controls::Canvas^ get();
    }

    // Accessor for the LayerProperty that manages the BorderBrush of this button
    virtual Private::CoreAnimation::LayerProperty^ GetBorderBrushProperty();

    // Accessor for the LayerProperty that manages the BorderThickness of this button
    virtual Private::CoreAnimation::LayerProperty^ GetBorderThicknessProperty();

internal:
    void HookPointerEvents(
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerPressedHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerMovedHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerReleasedHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerCanceledHook,
        const Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler>& pointerCaptureLostHook);
    void RemovePointerEvents();

    Windows::UI::Xaml::Controls::Image^ _image;
    Windows::UI::Xaml::Controls::Border^ _border;
    Label^ _label;

private:
    Windows::UI::Xaml::Controls::Canvas^ _contentCanvas; // Contains pre-canned button content, as well as any sublayers added by CoreAnimation.
    Windows::UI::Xaml::Controls::Image^ _content; // Layer content element; created on demand for custom layer rendering.

    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerPressedHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerMovedHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerReleasedHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerCanceledHook;
    Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::Input::IPointerEventHandler> _pointerCaptureLostHook;

    // Property-changed notifications
    void LabelTextChanged(Windows::UI::Xaml::DependencyObject^ object, Windows::UI::Xaml::DependencyProperty^ property);
};

} /* Xaml*/
} /* UIKit*/
// clang-format on