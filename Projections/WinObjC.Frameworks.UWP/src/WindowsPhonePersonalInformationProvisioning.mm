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

// WindowsPhonePersonalInformationProvisioning.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.PersonalInformation.Provisioning.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhonePersonalInformationProvisioning.h"
#include "WindowsPhonePersonalInformationProvisioning_priv.h"

@implementation WPPPContactPartnerProvisioningManager

ComPtr<ABI::Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics2>
WPPPIContactPartnerProvisioningManagerStatics2_inst() {
    ComPtr<ABI::Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.PersonalInformation.Provisioning.ContactPartnerProvisioningManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)associateSocialNetworkAccountAsync:(WPPContactStore*)store
                                                    networkName:(NSString*)networkName
                                               networkAccountId:(NSString*)networkAccountId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WPPPIContactPartnerProvisioningManagerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->AssociateSocialNetworkAccountAsync(_getRtInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(store).Get(),
                                                     nsStrToHstr(networkName).Get(),
                                                     nsStrToHstr(networkAccountId).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics>
WPPPIContactPartnerProvisioningManagerStatics_inst() {
    ComPtr<ABI::Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.PersonalInformation.Provisioning.ContactPartnerProvisioningManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)associateNetworkAccountAsync:(WPPContactStore*)store
                                              networkName:(NSString*)networkName
                                         networkAccountId:(NSString*)networkAccountId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WPPPIContactPartnerProvisioningManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->AssociateNetworkAccountAsync(_getRtInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(store).Get(),
                                               nsStrToHstr(networkName).Get(),
                                               nsStrToHstr(networkAccountId).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)importVcardToSystemAsync:(RTObject<WSSIInputStream>*)stream {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WPPPIContactPartnerProvisioningManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ImportVcardToSystemAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get(),
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WPPPMessagePartnerProvisioningManager

ComPtr<ABI::Windows::Phone::PersonalInformation::Provisioning::IMessagePartnerProvisioningManagerStatics>
WPPPIMessagePartnerProvisioningManagerStatics_inst() {
    ComPtr<ABI::Windows::Phone::PersonalInformation::Provisioning::IMessagePartnerProvisioningManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.PersonalInformation.Provisioning.MessagePartnerProvisioningManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)importSmsToSystemAsync:(BOOL)incoming
                                               read:(BOOL)read
                                               body:(NSString*)body
                                             sender:(NSString*)sender
                                         recipients:(NSArray* /* NSString * */)recipients
                                       deliveryTime:(WFDateTime*)deliveryTime {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WPPPIMessagePartnerProvisioningManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ImportSmsToSystemAsync(
        (boolean)incoming,
        (boolean)read,
        nsStrToHstr(body).Get(),
        nsStrToHstr(sender).Get(),
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToVectorView<NSString, HSTRING>(recipients).Get()),
        *[deliveryTime internalStruct],
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)importMmsToSystemAsync:(BOOL)incoming
                                               read:(BOOL)read
                                            subject:(NSString*)subject
                                             sender:(NSString*)sender
                                         recipients:(NSArray* /* NSString * */)recipients
                                       deliveryTime:(WFDateTime*)deliveryTime
                                        attachments:(NSArray* /* NSDictionary* < NSString *, RTObject* > */)attachments {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WPPPIMessagePartnerProvisioningManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ImportMmsToSystemAsync(
        (boolean)incoming,
        (boolean)read,
        nsStrToHstr(subject).Get(),
        nsStrToHstr(sender).Get(),
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToVectorView<NSString, HSTRING>(recipients).Get()),
        *[deliveryTime internalStruct],
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IMapView<HSTRING, IInspectable*>*,
                                                              IMapView<HSTRING, IInspectable*>*>>::type>*>(
            ConvertToVectorView<
                RTProxiedNSDictionary,
                ABI::Windows::Foundation::Internal::AggregateType<IMapView<HSTRING, IInspectable*>*, IMapView<HSTRING, IInspectable*>*>,
                RTProxiedNSDictionary_NSString_RTObject_create>(attachments)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<IMapView_HSTRING_IInspectablePtr_Ptr>,
                        RTArrayObj<IMapView_HSTRING_IInspectablePtr_Ptr,
                                   IVectorView<IMapView_HSTRING_IInspectablePtr_Ptr>,
                                   RTProxiedNSDictionary,
                                   IMapView_HSTRING_IInspectablePtr_Ptr,
                                   RTProxiedNSDictionary_NSString_RTObject_create,
                                   ConvertToVectorView<RTProxiedNSDictionary,
                                                       ABI::Windows::Foundation::Internal::AggregateType<IMapView<HSTRING, IInspectable*>*,
                                                                                                         IMapView<HSTRING, IInspectable*>*>,
                                                       RTProxiedNSDictionary_NSString_RTObject_create>>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, IInspectable*>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          IInspectable*,
                                          IInspectable*,
                                          NSString,
                                          RTObject,
                                          IMapView<HSTRING, IInspectable*>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
