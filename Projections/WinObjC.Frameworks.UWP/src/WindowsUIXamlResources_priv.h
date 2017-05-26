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

// WindowsUIXamlResources_priv.h
// Forward decls for private object generation
#pragma once

ComPtr<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics> WUXRICustomXamlResourceLoaderStatics_inst();

class WUXRICustomXamlResourceLoaderOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides, ComposableBase<>> {
    InspectableClass(L"WUXRICustomXamlResourceLoaderOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WUXRICustomXamlResourceLoaderOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE GetResource(
        HSTRING resourceId_in, HSTRING objectType_in, HSTRING propertyName_in, HSTRING propertyType_in, IInspectable** ret) override {
        auto unmarshaledRet = [_inner getResource:hstrToNSStr(resourceId_in)
                                       objectType:hstrToNSStr(objectType_in)
                                     propertyName:hstrToNSStr(propertyName_in)
                                     propertyType:hstrToNSStr(propertyType_in)];
        *ret = [unmarshaledRet comObj].Detach();
        return 0;
    }
};
