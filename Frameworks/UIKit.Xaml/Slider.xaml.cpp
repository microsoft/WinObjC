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
#include "Slider.xaml.h"

namespace UIKit {
namespace Xaml {

Slider::Slider() {
    InitializeComponent();
}

void Slider::OnApplyTemplate() {
    // TODO: Call GetTemplateChild to grab references to new objects in our custom control template.
    // TODO: Add support for min / max images, and to expose it as needed to UIKit.
}

} /* Xaml*/
} /* UIKit*/

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////
UIKIT_XAML_EXPORT void XamlCreateSlider(IInspectable** created) {
    Microsoft::WRL::ComPtr<IInspectable> inspectable = InspectableFromObject(ref new UIKit::Xaml::Slider());
    *created = inspectable.Detach();
}

// clang-format on