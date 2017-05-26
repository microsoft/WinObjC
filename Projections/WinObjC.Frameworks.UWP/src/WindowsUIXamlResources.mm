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

// WindowsUIXamlResources.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Resources.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlResources.h"
#include "WindowsUIXamlResources_priv.h"

@implementation WUXRCustomXamlResourceLoader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Resources.CustomXamlResourceLoader").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXRICustomXamlResourceLoaderOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXRICustomXamlResourceLoaderOverrides)]) {
        typedOuter = Make<WUXRICustomXamlResourceLoaderOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXRCustomXamlResourceLoader* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics> WUXRICustomXamlResourceLoaderStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Resources.CustomXamlResourceLoader").Get(),
                                                       &inst));
    return inst;
}

+ (WUXRCustomXamlResourceLoader*)current {
    ComPtr<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoader> unmarshalledReturn;
    auto _comInst = WUXRICustomXamlResourceLoaderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXRCustomXamlResourceLoader>(unmarshalledReturn.Get());
}

+ (void)setCurrent:(WUXRCustomXamlResourceLoader*)value {
    auto _comInst = WUXRICustomXamlResourceLoaderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_Current(_getRtInterface<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoader>(value).Get()));
}

- (RTObject*)getResource:(NSString*)resourceId
              objectType:(NSString*)objectType
            propertyName:(NSString*)propertyName
            propertyType:(NSString*)propertyType {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->GetResource(nsStrToHstr(resourceId).Get(),
                                             nsStrToHstr(objectType).Get(),
                                             nsStrToHstr(propertyName).Get(),
                                             nsStrToHstr(propertyType).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end
