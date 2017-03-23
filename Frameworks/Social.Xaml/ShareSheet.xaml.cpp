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

// The Content Dialog item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

ShareSheet::ShareSheet(Platform::String^ token) {
    InitializeComponent();
    _token = token;
}

void ShareSheet::ShareSheet_Post(ContentDialog^ sender, ContentDialogButtonClickEventArgs^ args) {
    Platform::String^ urlStr = "https://graph.facebook.com/v2.8/me/feed"
        "?link=http://www.microsoft.com"
        "&message=" + Uri::EscapeComponent(Message->Text) +
        "&privacy=" + Uri::EscapeComponent("{\"value\":\"ALL_FRIENDS\"}") +
        "&access_token=" + Uri::EscapeComponent(_token);

    Uri^ url = ref new Uri(urlStr);
    IHttpContent^ content = ref new HttpStringContent("");
    HttpClient^ client = ref new HttpClient;

    auto post = create_task(client->PostAsync(url, content));
    post.then([](task<HttpResponseMessage^> t) {
        try {
            HttpResponseMessage^ response = t.get();

            create_task(response->Content->ReadAsStringAsync()).then([=] (Platform::String^ str) {
                Platform::String^ output = "code: " + response->StatusCode.ToString() + ", content = " + str + "\n";
                OutputDebugString(L"HttpRequestMessage succeeded\n");
                OutputDebugString(output->Data());
            });
        } catch (Platform::COMException^ e) {
            OutputDebugString(L"HttpRequestMessage failed\n");
        }
    });
    
}

void ShareSheet::ShareSheet_Cancel(ContentDialog^ sender, ContentDialogButtonClickEventArgs^ args) {
}

void ShareSheet::addLink(Platform::String^ url) {
    // What we should do here is to download a preview of the URL
    // and render it into the Preview image. But that seems like work,
    // so instead we'll just display the text of the URL.

    TextBlock^ text = ref new TextBlock;
    text->Text = url;

    Preview->Children->Append(text);
}

void ShareSheet::addImage(ImageSource^ imageSource) {
    Image^ image = ref new Image;
    image->Source = imageSource;
    Preview->Children->Append(image);
}

class ShareSheetImpl : public RuntimeClass<RuntimeClassFlags<ClassicCom>, ShareSheetControl> {
    ShareSheet^ _shareSheet;

public:
    ShareSheetImpl(const wchar_t* token) {
        _shareSheet = ref new ShareSheet(Platform::StringReference(token));
    }

    void addLink(const wchar_t* url) override {
        _shareSheet->addLink(Platform::StringReference(url));
    }

    void addImage(IInspectable* image) override {
        _shareSheet->addImage(reinterpret_cast<ImageSource^>(image));
    }

    void show() override {
        _shareSheet->ShowAsync();
    }
};

SOCIAL_XAML_EXPORT ShareSheetControl* XamlCreateShareSheet(const wchar_t* token)
{
    ComPtr<ShareSheetImpl> sheet = Make<ShareSheetImpl>(token);
    return sheet.Detach();
}

