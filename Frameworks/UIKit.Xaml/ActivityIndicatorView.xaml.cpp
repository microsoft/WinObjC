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
#include "ActivityIndicatorView.xaml.h"

#include "ObjCXamlControls.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

namespace UIKit {
namespace Xaml {

DependencyProperty^ ActivityIndicatorView::s_isActiveProperty = nullptr;
DependencyProperty^ ActivityIndicatorView::s_foregroundProperty = nullptr;
DependencyProperty^ ActivityIndicatorView::s_heightProperty = nullptr;
DependencyProperty^ ActivityIndicatorView::s_widthProperty = nullptr;
Platform::Boolean ActivityIndicatorView::s_dependencyPropertiesRegistered = false;

ActivityIndicatorView::ActivityIndicatorView() {
    InitializeComponent();
    _RegisterDependencyProperties();
}

void ActivityIndicatorView::_RegisterDependencyProperties() {
    if (!s_dependencyPropertiesRegistered) {
        s_dependencyPropertiesRegistered = true;

        // TODO: These Dependency Properties should be attached to ActivityIndicatorView once type info is exposed to the tests. See #2607
        s_isActiveProperty = DependencyProperty::RegisterAttached("ActivityIndicatorView_IsActive",
            Platform::Boolean::typeid,
            FrameworkElement::typeid,
            nullptr);

        s_foregroundProperty = DependencyProperty::RegisterAttached("ActivityIndicatorView_Foreground",
            Media::SolidColorBrush::typeid,
            FrameworkElement::typeid,
            nullptr);

        s_heightProperty = DependencyProperty::RegisterAttached("ActivityIndicatorView_Height",
            double::typeid,
            FrameworkElement::typeid,
            nullptr);

        s_widthProperty = DependencyProperty::RegisterAttached("ActivityIndicatorView_Width",
            double::typeid,
            FrameworkElement::typeid,
            nullptr);
    }
}

Windows::UI::Xaml::Controls::ProgressRing^ ActivityIndicatorView::InternalProgressRing::get() {
    return progressRing;
}

} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////
UIKIT_XAML_EXPORT void XamlCreateActivityIndicatorView(IInspectable** created) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable = InspectableFromObject(ref new UIKit::Xaml::ActivityIndicatorView());
    *created = inspectable.Detach();
}

UIKIT_XAML_EXPORT IInspectable* XamlGetInternalProgressRing(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable) {
    auto activityIndicator = safe_cast<UIKit::Xaml::ActivityIndicatorView^>(reinterpret_cast<Platform::Object^>(activityIndicatorInspectable.Get()));
    return InspectableFromObject(activityIndicator->InternalProgressRing).Detach();
}

UIKIT_XAML_EXPORT bool XamlGetActivityIndicatorViewIsActiveValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable) {
    auto activityIndicator = safe_cast<UIKit::Xaml::ActivityIndicatorView^>(reinterpret_cast<Platform::Object^>(activityIndicatorInspectable.Get()));
    return activityIndicator->ActivityIndicatorView_IsActive;
}

UIKIT_XAML_EXPORT void XamlSetActivityIndicatorViewIsActiveValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable, bool isActive) {
    auto activityIndicator = safe_cast<UIKit::Xaml::ActivityIndicatorView^>(reinterpret_cast<Platform::Object^>(activityIndicatorInspectable.Get()));
    activityIndicator->ActivityIndicatorView_IsActive = isActive;
}

UIKIT_XAML_EXPORT IInspectable* XamlGetActivityIndicatorViewForegroundValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable) {
    auto activityIndicator = safe_cast<UIKit::Xaml::ActivityIndicatorView^>(reinterpret_cast<Platform::Object^>(activityIndicatorInspectable.Get()));
    return InspectableFromObject(activityIndicator->ActivityIndicatorView_Foreground).Detach();
}

UIKIT_XAML_EXPORT void XamlSetActivityIndicatorViewForegroundValue(
    const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable,
    const Microsoft::WRL::ComPtr<IInspectable>& inspectableForegroundBrush) {

    auto activityIndicator = safe_cast<UIKit::Xaml::ActivityIndicatorView^>(reinterpret_cast<Platform::Object^>(activityIndicatorInspectable.Get()));
    auto color = safe_cast<Media::SolidColorBrush^>(reinterpret_cast<Platform::Object^>(inspectableForegroundBrush.Get()));
    activityIndicator->ActivityIndicatorView_Foreground = color;
}

UIKIT_XAML_EXPORT void XamlSetActivityIndicatorViewHeightValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable, double height) {
    auto activityIndicator = safe_cast<UIKit::Xaml::ActivityIndicatorView^>(reinterpret_cast<Platform::Object^>(activityIndicatorInspectable.Get()));
    activityIndicator->ActivityIndicatorView_Height = height;
}

UIKIT_XAML_EXPORT void XamlSetActivityIndicatorViewWidthValue(const Microsoft::WRL::ComPtr<IInspectable>& activityIndicatorInspectable, double width) {
    auto activityIndicator = safe_cast<UIKit::Xaml::ActivityIndicatorView^>(reinterpret_cast<Platform::Object^>(activityIndicatorInspectable.Get()));
    activityIndicator->ActivityIndicatorView_Width = width;
}

// clang-format on