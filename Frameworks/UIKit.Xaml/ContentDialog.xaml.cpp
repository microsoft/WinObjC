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
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;

namespace UIKit {

ContentDialog::ContentDialog() : _buttonPressedIndex(-1) {
    InitializeComponent();

    ObservableItems = ref new Platform::Collections::Vector<Item^>();

    // Bind the list view source to our vector of items
    ActionsListView->ItemsSource = ObservableItems;
}

//////////////////////////////////////////////////////
// Implement derived XAML control functionality
//////////////////////////////////////////////////////

void ContentDialog::OnSelectionChanged(Platform::Object ^sender, SelectionChangedEventArgs ^e) {
    auto listView = safe_cast<ListView^>(sender);
    if (listView) {
        Item^ selectedItem = safe_cast<Item^>(listView->SelectedItem);
        _buttonPressedIndex = selectedItem->Index;
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
    auto contentDialog = safe_cast<UIKit::ContentDialog^>(reinterpret_cast<Platform::Object^>(inspectableContentDialog.Get()));
    return contentDialog->PressedIndex;
}

UIKIT_XAML_EXPORT unsigned int XamlContentDialogAddButtonWithTitle(const ComPtr<IInspectable>& inspectableContentDialog, const std::wstring& buttonTitle) {
    auto contentDialog = safe_cast<UIKit::ContentDialog^>(reinterpret_cast<Platform::Object^>(inspectableContentDialog.Get()));

    // Append a new item to the listview
    unsigned int newIndex = contentDialog->NumberOfItems;
    Item^ newItem = ref new Item(Platform::StringReference(buttonTitle.c_str()), newIndex);
    contentDialog->ObservableItems->Append(newItem);

    return newIndex;
}

UIKIT_XAML_EXPORT IInspectable* XamlContentDialogButtonTitleAtIndex(const ComPtr<IInspectable>& inspectableContentDialog, unsigned int buttonIndex) {
    auto contentDialog = safe_cast<UIKit::ContentDialog^>(reinterpret_cast<Platform::Object^>(inspectableContentDialog.Get()));

    // Strings are passed via PropertyValues to Objective-C
    Platform::Object^ propVal;
    for (Item^ item : contentDialog->ObservableItems) {
        if (item->Index == buttonIndex) {
            propVal = PropertyValue::CreateString(item->Title);
            break;
        }
    }

    return InspectableFromObject(propVal).Detach();
}

UIKIT_XAML_EXPORT unsigned int XamlContentDialogNumberOfButtons(const ComPtr<IInspectable>& inspectableContentDialog) {
    auto contentDialog = safe_cast<UIKit::ContentDialog^>(reinterpret_cast<Platform::Object^>(inspectableContentDialog.Get()));
    return contentDialog->NumberOfItems;
}

UIKIT_XAML_EXPORT void XamlContentDialogSetCancelButtonIndex(const ComPtr<IInspectable>& inspectableContentDialog, unsigned int cancelButtonIndex) {
    auto contentDialog = safe_cast<UIKit::ContentDialog^>(reinterpret_cast<Platform::Object^>(inspectableContentDialog.Get()));

    // Remove the cancel button from its current position because we're going to append it to the end of the list
    for (Item^ item : contentDialog->ObservableItems) {
        if (item->Index == cancelButtonIndex) {
            // There is a single listview that holds all our buttons. The cancel button is the only button that has defined position i.e. end of the list
            // In the scenarios where buttons are dynamically added (e.g. not using initWithTitle:...) we need to remove and re-append the cancel button
            unsigned int itemToRemoveIndex;
            contentDialog->ObservableItems->IndexOf(item, &itemToRemoveIndex);
            contentDialog->ObservableItems->RemoveAt(itemToRemoveIndex);
            contentDialog->ObservableItems->Append(item);

            // TODO: Change the style to match the design guidelines

            break;
        }
    }
}

UIKIT_XAML_EXPORT void XamlContentDialogSetDestructiveButtonIndex(const ComPtr<IInspectable>& inspectableContentDialog, unsigned int destructiveButtonIndex) {
    auto contentDialog = safe_cast<UIKit::ContentDialog^>(reinterpret_cast<Platform::Object^>(inspectableContentDialog.Get()));

    // TODO: Change the style to match the design guidelines
}

}
// clang-format on
