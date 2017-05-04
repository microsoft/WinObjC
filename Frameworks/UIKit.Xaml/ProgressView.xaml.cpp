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
#include "pch.h"
#include "ProgressView.xaml.h"

#include "ObjCXamlControls.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

namespace UIKit {
namespace Xaml {

DependencyProperty^ ProgressView::s_valueProperty = nullptr;
DependencyProperty^ ProgressView::s_foregroundProperty = nullptr;
DependencyProperty^ ProgressView::s_backgroundProperty = nullptr;
Platform::Boolean ProgressView::s_dependencyPropertiesRegistered = false;

ProgressView::ProgressView() {
    InitializeComponent();
    _RegisterDependencyProperties();
}

void ProgressView::_RegisterDependencyProperties() {
    if (!s_dependencyPropertiesRegistered) {
        s_dependencyPropertiesRegistered = true;

        // TODO: These Dependency Properties should be attached to ProgressView once type info is exposed to the tests. See #2607
        s_valueProperty = DependencyProperty::RegisterAttached("ProgressView_Value",
            double::typeid,
            FrameworkElement::typeid,
            nullptr);

        s_foregroundProperty = DependencyProperty::RegisterAttached("ProgressView_Foreground",
            Media::Brush::typeid,
            FrameworkElement::typeid,
            nullptr);

        s_backgroundProperty = DependencyProperty::RegisterAttached("ProgressView_Background",
            Media::Brush::typeid,
            FrameworkElement::typeid,
            nullptr);
    }
}

Windows::UI::Xaml::Controls::ProgressBar^ ProgressView::InternalProgressBar::get() {
    return progressBar;
}

} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////
UIKIT_XAML_EXPORT void XamlCreateProgressView(IInspectable** created) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable = InspectableFromObject(ref new UIKit::Xaml::ProgressView());
    *created = inspectable.Detach();
}

UIKIT_XAML_EXPORT IInspectable* XamlGetInternalProgressBar(const Microsoft::WRL::ComPtr<IInspectable>& progressViewInspectable) {
    auto progressView = safe_cast<UIKit::Xaml::ProgressView^>(reinterpret_cast<Platform::Object^>(progressViewInspectable.Get()));
    return InspectableFromObject(progressView->InternalProgressBar).Detach();
}

UIKIT_XAML_EXPORT double XamlGetProgressViewValue(const Microsoft::WRL::ComPtr<IInspectable>& progressViewInspectable) {
    auto progressView = safe_cast<UIKit::Xaml::ProgressView^>(reinterpret_cast<Platform::Object^>(progressViewInspectable.Get()));
    return progressView->ProgressView_Value;
}

UIKIT_XAML_EXPORT void XamlSetProgressViewValue(const Microsoft::WRL::ComPtr<IInspectable>& progressViewInspectable, double value) {
    auto progressView = safe_cast<UIKit::Xaml::ProgressView^>(reinterpret_cast<Platform::Object^>(progressViewInspectable.Get()));
    progressView->ProgressView_Value = value;
}

UIKIT_XAML_EXPORT void XamlSetProgressViewForegroundValue(
    const Microsoft::WRL::ComPtr<IInspectable>& progressViewInspectable,
    const Microsoft::WRL::ComPtr<IInspectable>& inspectableForegroundBrush) {

    auto progressView = safe_cast<UIKit::Xaml::ProgressView^>(reinterpret_cast<Platform::Object^>(progressViewInspectable.Get()));
    auto color = safe_cast<Media::Brush^>(reinterpret_cast<Platform::Object^>(inspectableForegroundBrush.Get()));
    progressView->ProgressView_Foreground = color;
}

UIKIT_XAML_EXPORT void XamlSetProgressViewBackgroundValue(
    const Microsoft::WRL::ComPtr<IInspectable>& progressViewInspectable,
    const Microsoft::WRL::ComPtr<IInspectable>& inspectableForegroundBrush) {

    auto progressView = safe_cast<UIKit::Xaml::ProgressView^>(reinterpret_cast<Platform::Object^>(progressViewInspectable.Get()));
    auto color = safe_cast<Media::Brush^>(reinterpret_cast<Platform::Object^>(inspectableForegroundBrush.Get()));
    progressView->ProgressView_Background = color;
}

// clang-format on