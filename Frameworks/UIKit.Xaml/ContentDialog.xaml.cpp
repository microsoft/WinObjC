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

#include "ContentDialog.xaml.h"

using namespace Microsoft::WRL;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;

namespace UIKit {

ContentDialog::ContentDialog() : _buttonPressedIndex(-1) {
    InitializeComponent();
}

//////////////////////////////////////////////////////
// Implement derived XAML control functionality
//////////////////////////////////////////////////////

void ContentDialog::OnSelectionChanged(Platform::Object ^sender, SelectionChangedEventArgs ^e) {
    auto listView = safe_cast<ListView^>(sender);
    if (listView) {
        _buttonPressedIndex = listView->SelectedIndex;
    }

    // This triggers the showAsync event handler where we can process the index for the button pressed through its getter, ContentDialogCustomResult
    Hide();
}

////////////////////////////////////////////////////////////////////////////////////
// ObjectiveC Interop
////////////////////////////////////////////////////////////////////////////////////
UIKIT_XAML_EXPORT IInspectable* XamlCreateContentDialog() {
    return InspectableFromObject(ref new UIKit::ContentDialog()).Detach();
}

UIKIT_XAML_EXPORT int XamlContentDialogPressedIndex(const ComPtr<IInspectable>& inspectableContentDialog) {
    auto contentDialog = static_cast<UIKit::ContentDialog^>(reinterpret_cast<Platform::Object^>(inspectableContentDialog.Get()));
    return contentDialog->PressedIndex;
}

}
// clang-format on
