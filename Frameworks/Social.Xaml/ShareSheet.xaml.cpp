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
#include <ppltasks.h>
#include "ShareSheet.xaml.h"
#include "ShareSheetControl.h"
#include "ErrorHandling.h"

using namespace Social::Xaml;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Web::Http;
using namespace concurrency;

// The Content Dialog item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

ShareSheet::ShareSheet(Platform::String^ token)
{
    InitializeComponent();
    _token = token;
}

void ShareSheet::ShareSheet_Post(ContentDialog^ sender, ContentDialogButtonClickEventArgs^ args)
{
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

void ShareSheet::ShareSheet_Cancel(ContentDialog^ sender, ContentDialogButtonClickEventArgs^ args)
{
}

SOCIAL_XAML_EXPORT void XamlCreateShareSheet(const wchar_t* token, IInspectable** created)
{
    ShareSheet^ sheet = ref new ShareSheet(Platform::StringReference(token));

    ComPtr<IUnknown> unknown(reinterpret_cast<IUnknown*>(sheet));
    ComPtr<IInspectable> inspectable;
    THROW_IF_FAILED(unknown.As(&inspectable));

    *created = inspectable.Detach();
}
