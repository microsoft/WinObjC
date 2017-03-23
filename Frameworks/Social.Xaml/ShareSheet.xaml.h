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

#pragma once

#include "ShareSheet.g.h"

namespace Social {
namespace Xaml {

    [Windows::Foundation::Metadata::WebHostHidden]
    public ref class ShareSheet sealed
    {
    public:
        ShareSheet(Platform::String^ token);

        void addLink(Platform::String^ url);
        void addImage(Windows::UI::Xaml::Media::ImageSource^ image);

    private:
        void ShareSheet_Post(Windows::UI::Xaml::Controls::ContentDialog^ sender, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs^ args);
        void ShareSheet_Cancel(Windows::UI::Xaml::Controls::ContentDialog^ sender, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs^ args);

        Platform::String^ _token;
        Platform::String^ _linkToShare;
        Windows::UI::Xaml::Controls::Image^ _imageToShare;
    };

}
}
