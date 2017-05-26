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

// MicrosoftAdvertisingMicrosoftAdvertising_XamlTypeInfo.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Microsoft.Advertising.MicrosoftAdvertising_XamlTypeInfo.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "MicrosoftAdvertisingMicrosoftAdvertising_XamlTypeInfo.h"
#include "MicrosoftAdvertisingMicrosoftAdvertising_XamlTypeInfo_priv.h"

@implementation MAMXamlMetaDataProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::MicrosoftAdvertising_XamlTypeInfo::__IXamlMetaDataProviderPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Microsoft.Advertising.MicrosoftAdvertising_XamlTypeInfo.XamlMetaDataProvider").Get(), &out));
    return [_createRtProxy<MAMXamlMetaDataProvider>(out.Get()) retain];
}

- (RTObject<WUXMIXamlType>*)getXamlType:(WUXITypeName*)type {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetXamlType(*[type internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlType>(unmarshalledReturn.Get());
}

- (RTObject<WUXMIXamlType>*)getXamlTypeByFullName:(NSString*)fullName {
    ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetXamlTypeByFullName(nsStrToHstr(fullName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMIXamlType>(unmarshalledReturn.Get());
}

- (NSArray* /* WUXMXmlnsDefinition* */)getXmlnsDefinitions {
    ABI::Windows::UI::Xaml::Markup::XmlnsDefinition* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetXmlnsDefinitions(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXMXmlnsDefinition_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

id RTProxiedNSArray_C_WUXMXmlnsDefinition_create(UINT32 size, ABI::Windows::UI::Xaml::Markup::XmlnsDefinition* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::UI::Xaml::Markup::XmlnsDefinition,
                         RTCArrayObj<ABI::Windows::UI::Xaml::Markup::XmlnsDefinition, WUXMXmlnsDefinition, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
