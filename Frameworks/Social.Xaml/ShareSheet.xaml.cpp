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

#include "pch.h"
#include <wrl/client.h>
#include <wrl/implements.h>
#include <ppltasks.h>
#include "ShareSheet.xaml.h"
#include "ShareSheetControl.h"
#include "ErrorHandling.h"

using namespace Social::Xaml;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::Web::Http;
using namespace concurrency;

ShareSheet::ShareSheet(Platform::String^ token) {
    InitializeComponent();
    _userName->Text = "User Name";  // TODO: Actually fetch user name
    _token = token;
}

void ShareSheet::Post(ContentDialog^ sender, ContentDialogButtonClickEventArgs^ args) {
    // Rudimentary implementation of posting logic

    // TODO: Allow user to choose privacy setting
    Platform::String^ privacy = "{\"value\":\"ALL_FRIENDS\"}";

    Platform::String^ urlStr = "https://graph.facebook.com/v2.8/me/feed"
        "?message=" + Uri::EscapeComponent(_message->Text) +
        "&privacy=" + Uri::EscapeComponent(privacy) +
        "&access_token=" + Uri::EscapeComponent(_token);

    if (!_linkToShare->IsEmpty()) {
        urlStr += "&link=" + Uri::EscapeComponent(_linkToShare);
    }

    if (_imagesToShare != nullptr) {
        // TODO: Share images
    }

    Uri^ url = ref new Uri(urlStr);
    IHttpContent^ content = ref new HttpStringContent("");
    HttpClient^ client = ref new HttpClient;

    auto post = create_task(client->PostAsync(url, content));
    post.then([] (HttpResponseMessage^ response) {
        // TODO: Notify client of the result
    });
    
}

void ShareSheet::Cancel(ContentDialog^ sender, ContentDialogButtonClickEventArgs^ args) {
    // TODO: Notify client of cancellation
}

void ShareSheet::AddLink(Platform::String^ url) {
    if (_imagesToShare != nullptr) {
        THROW_HR_MSG(E_UNEXPECTED, "Can't share both links and images");
    }

    if (!_linkToShare->IsEmpty()) {
        THROW_HR_MSG(E_UNEXPECTED, "Can't share more than one link");
    }

    // What we should do here is to download a preview of the URL
    // and render it into the Preview image. But that seems like work,
    // so instead we'll just display the text of the URL.

    TextBlock^ text = ref new TextBlock;
    text->Text = url;

    _preview->Children->Append(text);
    _linkToShare = url;
}

void ShareSheet::AddImage(ImageSource^ imageSource) {
    if (!_linkToShare->IsEmpty()) {
        THROW_HR_MSG(E_UNEXPECTED, "Can't share both links and images");
    }

    Image^ image = ref new Image;
    image->Source = imageSource;

    // Build a StackPanel to house the images, if one has not yet been created
    if (_imagesToShare == nullptr) {
        _imagesToShare = ref new StackPanel;
        _imagesToShare->Orientation = Orientation::Horizontal;
        _preview->Children->Append(_imagesToShare);
    }

    _imagesToShare->Children->Append(image);
}

void ShareSheet::SetInitialText(Platform::String^ text) {
    _message->Text = text;
}

//
// ShareSheetControl implementation to wrap the ShareSheet for exposure to non-CX clients
//
class ShareSheetImpl : public RuntimeClass<RuntimeClassFlags<ClassicCom>, ShareSheetControl> {
    ShareSheet^ _shareSheet;

public:
    ShareSheetImpl(const wchar_t* token) {
        _shareSheet = ref new ShareSheet(Platform::StringReference(token));
    }

    STDMETHODIMP addLink(const wchar_t* url) override {
        try {
            _shareSheet->AddLink(Platform::StringReference(url));
        } CATCH_RETURN()

        return S_OK;
    }

    STDMETHODIMP addImage(IInspectable* image) override {
        try {
            _shareSheet->AddImage(safe_cast<ImageSource^>(reinterpret_cast<Platform::Object^>(image)));
        } CATCH_RETURN()

        return S_OK;
    }

    STDMETHODIMP setInitialText(const wchar_t* text) override {
        try {
            _shareSheet->SetInitialText(Platform::StringReference(text));
        } CATCH_RETURN()

        return S_OK;
    }

    STDMETHODIMP show() override {
        try {
            _shareSheet->ShowAsync();
        } CATCH_RETURN()

        return S_OK;
    }
};

SOCIAL_XAML_EXPORT HRESULT XamlCreateShareSheet(const wchar_t* token, ShareSheetControl** sheet)
{
    ComPtr<ShareSheetControl> ss;

    try {
        *sheet = nullptr;
        ss = Make<ShareSheetImpl>(token);
    } CATCH_RETURN()

    *sheet = ss.Detach();
    return S_OK;
}

