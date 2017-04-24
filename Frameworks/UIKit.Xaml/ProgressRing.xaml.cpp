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
#include "ProgressRing.xaml.h"

#include "ObjCXamlControls.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

namespace UIKit {
	namespace Xaml {

		DependencyProperty^ ProgressRing::s_isActiveProperty = nullptr;
		DependencyProperty^ ProgressRing::s_foregroundProperty = nullptr;
		DependencyProperty^ ProgressRing::s_heightProperty = nullptr;
		DependencyProperty^ ProgressRing::s_widthProperty = nullptr;
		Platform::Boolean ProgressRing::s_dependencyPropertiesRegistered = false;

		ProgressRing::ProgressRing() {
			InitializeComponent();
			_RegisterDependencyProperties();
		}

		void ProgressRing::_RegisterDependencyProperties() {
			if (!s_dependencyPropertiesRegistered) {
				s_dependencyPropertiesRegistered = true;

				/* NOTE: Currently we must attach DependencyProperties to FrameworkElement for testing
						because type information for custom controls is not currently being exposed to
						the testing framework.
						See Issue #2607 for current status.
				*/
				// TODO: This DependencyProperty should be attached to UIKit::Xaml::ProgressRing
				s_isActiveProperty = DependencyProperty::RegisterAttached("ProgressRing_IsActive",
					Platform::Boolean::typeid,
					FrameworkElement::typeid,
					nullptr);
				// TODO: This DependencyProperty should be attached to UIKit::Xaml::ProgressRing
				s_foregroundProperty = DependencyProperty::RegisterAttached("ProgressRing_Foreground",
					Media::SolidColorBrush::typeid,
					FrameworkElement::typeid,
					nullptr);
				// TODO: This DependencyProperty should be attached to UIKit::Xaml::ProgressRing
				s_heightProperty = DependencyProperty::RegisterAttached("ProgressRing_Height",
					double::typeid,
					FrameworkElement::typeid,
					nullptr);
				// TODO: This DependencyProperty should be attached to UIKit::Xaml::ProgressRing
				s_widthProperty = DependencyProperty::RegisterAttached("ProgressRing_Width",
					double::typeid,
					FrameworkElement::typeid,
					nullptr);
			}
		}

		Windows::UI::Xaml::Controls::ProgressRing^ ProgressRing::InternalProgressRing::get() {
			return progressRing;
		}

	} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////
UIKIT_XAML_EXPORT void XamlCreateProgressRing(IInspectable** created) {
	Microsoft::WRL::ComPtr<IInspectable> inspectable = InspectableFromObject(ref new UIKit::Xaml::ProgressRing());
	*created = inspectable.Detach();
}

UIKIT_XAML_EXPORT IInspectable* XamlGetInternalProgressRing(const Microsoft::WRL::ComPtr<IInspectable>& progressRingInspectable) {
	auto progressRing = safe_cast<UIKit::Xaml::ProgressRing^>(reinterpret_cast<Platform::Object^>(progressRingInspectable.Get()));
	return InspectableFromObject(progressRing->InternalProgressRing).Detach();
}

UIKIT_XAML_EXPORT bool XamlGetProgressRingIsActiveValue(const Microsoft::WRL::ComPtr<IInspectable>& progressRingInspectable) {
	auto progressRing = safe_cast<UIKit::Xaml::ProgressRing^>(reinterpret_cast<Platform::Object^>(progressRingInspectable.Get()));
	return progressRing->ProgressRing_IsActive;
}

UIKIT_XAML_EXPORT void XamlSetProgressRingIsActiveValue(const Microsoft::WRL::ComPtr<IInspectable>& progressRingInspectable, bool isActive) {
	auto progressRing = safe_cast<UIKit::Xaml::ProgressRing^>(reinterpret_cast<Platform::Object^>(progressRingInspectable.Get()));
	progressRing->ProgressRing_IsActive = isActive;
}

UIKIT_XAML_EXPORT IInspectable* XamlGetProgressRingForegroundValue(const Microsoft::WRL::ComPtr<IInspectable>& progressRingInspectable) {
	auto progressRing = safe_cast<UIKit::Xaml::ProgressRing^>(reinterpret_cast<Platform::Object^>(progressRingInspectable.Get()));
	return InspectableFromObject(progressRing->ProgressRing_Foreground).Detach();
}

UIKIT_XAML_EXPORT void XamlSetProgressRingForegroundValue(
	const Microsoft::WRL::ComPtr<IInspectable>& progressRingInspectable,
	const Microsoft::WRL::ComPtr<IInspectable>& inspectableForegroundBrush) {

	auto progressRing = safe_cast<UIKit::Xaml::ProgressRing^>(reinterpret_cast<Platform::Object^>(progressRingInspectable.Get()));
	auto color = safe_cast<Media::SolidColorBrush^>(reinterpret_cast<Platform::Object^>(inspectableForegroundBrush.Get()));
	progressRing->ProgressRing_Foreground = color;
}

UIKIT_XAML_EXPORT double XamlGetProgressRingHeightValue(const Microsoft::WRL::ComPtr<IInspectable>& progressRingInspectable) {
	auto progressRing = safe_cast<UIKit::Xaml::ProgressRing^>(reinterpret_cast<Platform::Object^>(progressRingInspectable.Get()));
	return progressRing->ProgressRing_Height;
}

UIKIT_XAML_EXPORT void XamlSetProgressRingHeightValue(const Microsoft::WRL::ComPtr<IInspectable>& progressRingInspectable, double height) {
	auto progressRing = safe_cast<UIKit::Xaml::ProgressRing^>(reinterpret_cast<Platform::Object^>(progressRingInspectable.Get()));
	progressRing->ProgressRing_Height = height;
}

UIKIT_XAML_EXPORT double XamlGetProgressRingWidthValue(const Microsoft::WRL::ComPtr<IInspectable>& progressRingInspectable) {
	auto progressRing = safe_cast<UIKit::Xaml::ProgressRing^>(reinterpret_cast<Platform::Object^>(progressRingInspectable.Get()));
	return progressRing->ProgressRing_Width;
}

UIKIT_XAML_EXPORT void XamlSetProgressRingWidthValue(const Microsoft::WRL::ComPtr<IInspectable>& progressRingInspectable, double width) {
	auto progressRing = safe_cast<UIKit::Xaml::ProgressRing^>(reinterpret_cast<Platform::Object^>(progressRingInspectable.Get()));
	progressRing->ProgressRing_Width = width;
}

// clang-format on