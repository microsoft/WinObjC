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

#include "ActivityIndicatorView.g.h"
#include "ObjCXamlControls.h"

namespace UIKit {
namespace Xaml {

[Windows::Foundation::Metadata::WebHostHidden]
public ref class ActivityIndicatorView sealed {
public:
    ActivityIndicatorView();

    // TODO: Properties should be renamed to eliminate the name prefix once their corresponding Dependency Properties are fixed. See #2607
    property Platform::Boolean ActivityIndicatorView_IsActive {
        Platform::Boolean get() {
            return (Platform::Boolean)GetValue(s_isActiveProperty);
        }
        void set(Platform::Boolean value) {
            SetValue(s_isActiveProperty, value);
        }
    }

    property Windows::UI::Xaml::Media::SolidColorBrush^ ActivityIndicatorView_Foreground {
        Windows::UI::Xaml::Media::SolidColorBrush^ get() {
            return (Windows::UI::Xaml::Media::SolidColorBrush^)GetValue(s_foregroundProperty);
        }
        void set(Windows::UI::Xaml::Media::SolidColorBrush^ value) {
            SetValue(s_foregroundProperty, value);
        }
    }

    property double ActivityIndicatorView_Height {
        double get() {
            return (double)GetValue(s_heightProperty);
        }
        void set(double value) {
            SetValue(s_heightProperty, value);
        }
    }

    property double ActivityIndicatorView_Width {
        double get() {
            return (double)GetValue(s_widthProperty);
        }
        void set(double value) {
            SetValue(s_widthProperty, value);
        }
    }

internal:
    property Windows::UI::Xaml::Controls::ProgressRing^ InternalProgressRing {
        Windows::UI::Xaml::Controls::ProgressRing^ get();
    }

    static void _RegisterDependencyProperties();

private:
    static Windows::UI::Xaml::DependencyProperty^ s_isActiveProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_foregroundProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_heightProperty;
    static Windows::UI::Xaml::DependencyProperty^ s_widthProperty;
    static Platform::Boolean s_dependencyPropertiesRegistered;
};

} /* Xaml*/
} /* UIKit*/
// clang-format on
