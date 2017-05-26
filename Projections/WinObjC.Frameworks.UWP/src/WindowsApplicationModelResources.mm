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

// WindowsApplicationModelResources.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Resources.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelResources.h"
#include "WindowsApplicationModelResources_priv.h"

@implementation WARResourceLoader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Resources.ResourceLoader").Get(), &out));
    return [_createRtProxy<WARResourceLoader>(out.Get()) retain];
}

static ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoaderFactory> WARIResourceLoaderFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoaderFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Resources.ResourceLoader").Get(),
                                                       &inst));
    return inst;
}

+ (WARResourceLoader*)makeResourceLoaderByName:(NSString*)name {
    ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoader> unmarshalledReturn;
    auto _comInst = WARIResourceLoaderFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateResourceLoaderByName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WARResourceLoader>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoaderStatics2> WARIResourceLoaderStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoaderStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Resources.ResourceLoader").Get(),
                                                       &inst));
    return inst;
}

+ (WARResourceLoader*)getForCurrentView {
    ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoader> unmarshalledReturn;
    auto _comInst = WARIResourceLoaderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARResourceLoader>(unmarshalledReturn.Get());
}

+ (WARResourceLoader*)getForCurrentViewWithName:(NSString*)name {
    ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoader> unmarshalledReturn;
    auto _comInst = WARIResourceLoaderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentViewWithName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARResourceLoader>(unmarshalledReturn.Get());
}

+ (WARResourceLoader*)getForViewIndependentUse {
    ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoader> unmarshalledReturn;
    auto _comInst = WARIResourceLoaderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForViewIndependentUse(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARResourceLoader>(unmarshalledReturn.Get());
}

+ (WARResourceLoader*)getForViewIndependentUseWithName:(NSString*)name {
    ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoader> unmarshalledReturn;
    auto _comInst = WARIResourceLoaderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForViewIndependentUseWithName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WARResourceLoader>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoaderStatics> WARIResourceLoaderStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Resources::IResourceLoaderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Resources.ResourceLoader").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)getStringForReference:(WFUri*)uri {
    HSTRING unmarshalledReturn;
    auto _comInst = WARIResourceLoaderStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStringForReference(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getString:(NSString*)resource {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::IResourceLoader>(self);
    THROW_NS_IF_FAILED(_comInst->GetString(nsStrToHstr(resource).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)getStringForUri:(WFUri*)uri {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Resources::IResourceLoader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetStringForUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end
