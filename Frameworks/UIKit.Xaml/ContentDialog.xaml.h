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

#include "ContentDialog.g.h"
#include "ObjCXamlControls.h"

#include <windows.ui.xaml.h>

namespace UIKit {

[Windows::Foundation::Metadata::WebHostHidden]
public ref class ContentDialog sealed {
public:
    ContentDialog();

    // Getter that returns the index of the last button pressed
    property int PressedIndex {
        int get() { return _buttonPressedIndex; }
    }

private:
    int _buttonPressedIndex;

    // Event handler
    void OnSelectionChanged(Platform::Object ^sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs ^e);
};

}
// clang-format on