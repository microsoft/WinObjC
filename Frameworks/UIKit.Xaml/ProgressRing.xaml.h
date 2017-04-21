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

#include "ProgressRing.g.h"
#include "ObjCXamlControls.h"

namespace UIKit {
	namespace Xaml {

		[Windows::Foundation::Metadata::WebHostHidden]
		public ref class ProgressRing sealed {
		public:
			ProgressRing();

			// TODO: This should be renamed to eliminate the naming prefix once the DependencyProperty is fixed
			property Platform::Boolean ProgressRing_IsActive {
				Platform::Boolean get() {
					return (Platform::Boolean)GetValue(s_isActiveProperty);
				}
				void set(Platform::Boolean value) {
					SetValue(s_isActiveProperty, value);
				}
			}

		internal:
			property Windows::UI::Xaml::Controls::ProgressRing^ InternalProgressRing {
				Windows::UI::Xaml::Controls::ProgressRing^ get();
			}

			static void _RegisterDependencyProperties();

		private:
			static Windows::UI::Xaml::DependencyProperty^ s_isActiveProperty;
			static Platform::Boolean s_dependencyPropertiesRegistered;
		};

	} /* Xaml*/
} /* UIKit*/
// clang-format on
