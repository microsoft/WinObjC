//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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
#include "pch.h"
#include "ILayer.h"

using namespace Windows::UI::Xaml;

namespace UIKit {
namespace Xaml {
namespace Private {
namespace CoreAnimation {

LayerProperty::LayerProperty(DependencyObject^ target, DependencyProperty^ property) : _target(target), _property(property) {
}

void LayerProperty::SetValue(Platform::Object^ value) {
    // Set the specified value on our underlying target/property pair
    _target->SetValue(_property, value);
}

Platform::Object^ LayerProperty::GetValue() {
    // Retrieve the current value from our underlying target/property pair
    return _target->GetValue(_property);
}

} /* CoreAnimation */
} /* Private */
} /* Xaml*/
} /* UIKit*/

// clang-format on