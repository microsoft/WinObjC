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

#include "ProgressView.g.h"
#include "ObjCXamlControls.h"

namespace UIKit {
namespace Xaml {

[Windows::Foundation::Metadata::WebHostHidden]
public ref class ProgressView sealed {
public:
    ProgressView();

    // TODO: Properties should be renamed to eliminate the name prefix once their corresponding Dependency Properties are fixed. See #2607
    property double ProgressView_Value {
        double get() {
            return (double)GetValue(s_valueProperty);
        }
        void set(double value) {
            SetValue(s_valueProperty, value);
        }
    }

    property Windows::UI::Xaml::Media::Brush^ ProgressView_Foreground {
        Windows::UI::Xaml::Media::Brush^ get() {
            return (Windows::UI::Xaml::Media::Brush^)GetValue(s_foregroundProperty);
        }
        void set(Windows::UI::Xaml::Media::Brush^ value) {
            SetValue(s_foregroundProperty, value);
        }
    }

    property Windows::UI::Xaml::Media::Brush^ ProgressView_Background {
        Windows::UI::Xaml::Media::Brush^ get() {
            return (Windows::UI::Xaml::Media::Brush^)GetValue(s_backgroundProperty);
        }
        void set(Windows::UI::Xaml::Media::Brush^ value) {
            SetValue(s_backgroundProperty, value);
        }
    }

internal:
    property Windows::UI::Xaml::Controls::ProgressBar^ InternalProgressBar {
        Windows::UI::Xaml::Controls::ProgressBar^ get();
    }

    static void _RegisterDependencyProperties();

private:
    static Windows::UI::Xaml::DependencyProperty^ s_valueProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_foregroundProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_backgroundProperty;
    static Platform::Boolean s_dependencyPropertiesRegistered;
};

} /* Xaml*/
} /* UIKit*/
// clang-format on
