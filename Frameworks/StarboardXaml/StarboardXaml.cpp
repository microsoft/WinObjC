//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include <wrl.h>
#include <wrl/client.h>
#include <wincodec.h>
#include <memory>
#include <agile.h>
#include <concrt.h>
#include <thread>

#include <collection.h>
#include <ppltasks.h>
#include <wrl/client.h>

#include "LayerRegistration.h"

#define IWEXPORT __declspec(dllexport)
#include "winobjc\winobjc.h"

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::System;
using namespace Windows::System::Threading;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Graphics::Display;
using namespace Windows::ApplicationModel::Store;
using namespace Windows::UI;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Shapes;
using namespace Windows::ApplicationModel::Core;

__declspec(dllimport) wchar_t* __WideStringFromNSString(void* str);

Platform::String ^ principalClassName, ^delegateClassName;

ref class App : public ::Windows::UI::Xaml::Application, ::Windows::UI::Xaml::Markup::IXamlMetadataProvider {
    ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider ^ _provider;

public:
    virtual ::Windows::UI::Xaml::Markup::IXamlType ^
        GetXamlType(Windows::UI::Xaml::Interop::TypeName type) {
            if (_provider == nullptr) {
                _provider = ref new XamlTypeInfo::InfoProvider::XamlTypeInfoProvider();
            }
            return _provider->GetXamlTypeByType(type);
        }

        virtual ::Windows::UI::Xaml::Markup::IXamlType
        ^
        GetXamlType(::Platform::String ^ fullName) {
            if (_provider == nullptr) {
                _provider = ref new XamlTypeInfo::InfoProvider::XamlTypeInfoProvider();
            }
            return _provider->GetXamlTypeByName(fullName);
        }

        virtual ::Platform::Array<Windows::UI::Xaml::Markup::XmlnsDefinition> ^
        GetXmlnsDefinitions() { return ref new ::Platform::Array<Windows::UI::Xaml::Markup::XmlnsDefinition>(0); }

        void InitializeComponent() {
    }

    void Connect(int connectionId, ::Platform::Object ^ target) {
    }

    void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs ^ e) override {
        auto uiElem = ref new Grid();
        auto rootFrame = ref new Frame();
        rootFrame->Content = uiElem;

        IWSetXamlRoot(uiElem);

        Window::Current->Content = rootFrame;
        Window::Current->Activate();

        auto startupRect = Window::Current->Bounds;

        IWRunApplicationMain(principalClassName, delegateClassName, startupRect.Width, startupRect.Height);
    }
};

extern "C" __declspec(dllexport) int UIApplicationMain(int argc, char* argv[], void* pName, void* dName) {
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    principalClassName = pName ? ref new Platform::String((wchar_t*)__WideStringFromNSString(pName)) : nullptr;
    delegateClassName = dName ? ref new Platform::String((wchar_t*)__WideStringFromNSString(dName)) : nullptr;
    Windows::UI::Xaml::Application::Start(
        ref new Windows::UI::Xaml::ApplicationInitializationCallback([](Windows::UI::Xaml::ApplicationInitializationCallbackParams ^ p) {
            (void)p; // Unused parameter
            auto app = ref new App();
        }));

    return 0;
}
