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

// WindowsApplicationModelContacts.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Contacts.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelContacts.h"
#include "WindowsApplicationModelContacts_priv.h"

@implementation WACIContactField

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactFieldType)type {
    ABI::Windows::ApplicationModel::Contacts::ContactFieldType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WACContactFieldType)unmarshalledReturn;
}

- (WACContactFieldCategory)category {
    ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return (WACContactFieldCategory)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACIContactFieldFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactField*)createField_Default:(NSString*)value type:(WACContactFieldType)type {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateField_Default(nsStrToHstr(value).Get(),
                                                     (ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type,
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactField>(unmarshalledReturn.Get());
}

- (WACContactField*)createField_Category:(NSString*)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateField_Category(nsStrToHstr(value).Get(),
                                                      (ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type,
                                                      (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactField>(unmarshalledReturn.Get());
}

- (WACContactField*)createField_Custom:(NSString*)name
                                 value:(NSString*)value
                                  type:(WACContactFieldType)type
                              category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateField_Custom(nsStrToHstr(name).Get(),
                                                    nsStrToHstr(value).Get(),
                                                    (ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type,
                                                    (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactField>(unmarshalledReturn.Get());
}

@end

@implementation WACIContactLocationFieldFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactLocationField*)createLocation_Default:(NSString*)unstructuredAddress {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLocation_Default(nsStrToHstr(unstructuredAddress).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactLocationField>(unmarshalledReturn.Get());
}

- (WACContactLocationField*)createLocation_Category:(NSString*)unstructuredAddress category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLocation_Category(nsStrToHstr(unstructuredAddress).Get(),
                                                         (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactLocationField>(unmarshalledReturn.Get());
}

- (WACContactLocationField*)createLocation_All:(NSString*)unstructuredAddress
                                      category:(WACContactFieldCategory)category
                                        street:(NSString*)street
                                          city:(NSString*)city
                                        region:(NSString*)region
                                       country:(NSString*)country
                                    postalCode:(NSString*)postalCode {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLocation_All(nsStrToHstr(unstructuredAddress).Get(),
                                                    (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                    nsStrToHstr(street).Get(),
                                                    nsStrToHstr(city).Get(),
                                                    nsStrToHstr(region).Get(),
                                                    nsStrToHstr(country).Get(),
                                                    nsStrToHstr(postalCode).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactLocationField>(unmarshalledReturn.Get());
}

@end

@implementation WACIContactInstantMessageFieldFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactInstantMessageField*)createInstantMessage_Default:(NSString*)userName {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateInstantMessage_Default(nsStrToHstr(userName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactInstantMessageField>(unmarshalledReturn.Get());
}

- (WACContactInstantMessageField*)createInstantMessage_Category:(NSString*)userName category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateInstantMessage_Category(nsStrToHstr(userName).Get(),
                                                               (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactInstantMessageField>(unmarshalledReturn.Get());
}

- (WACContactInstantMessageField*)createInstantMessage_All:(NSString*)userName
                                                  category:(WACContactFieldCategory)category
                                                   service:(NSString*)service
                                               displayText:(NSString*)displayText
                                                      verb:(WFUri*)verb {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateInstantMessage_All(nsStrToHstr(userName).Get(),
                                                          (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                          nsStrToHstr(service).Get(),
                                                          nsStrToHstr(displayText).Get(),
                                                          _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(verb).Get(),
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactInstantMessageField>(unmarshalledReturn.Get());
}

@end

@implementation WACContact

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.Contact").Get(), &out));
    return [_createRtProxy<WACContact>(out.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setThumbnail:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(self);
    THROW_NS_IF_FAILED(_comInst->put_Thumbnail(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (NSMutableArray* /* RTObject<WACIContactField>* */)fields {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::IContactField*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(self);
    THROW_NS_IF_FAILED(_comInst->get_Fields(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WACIContactField_create(unmarshalledReturn.Get());
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)notes {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Notes(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNotes:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Notes(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WACContactPhone* */)phones {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactPhone*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Phones(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactPhone_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WACContactEmail* */)emails {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactEmail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emails(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactEmail_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WACContactAddress* */)addresses {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactAddress*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Addresses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactAddress_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WACContactConnectedServiceAccount* */)connectedServiceAccounts {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectedServiceAccounts(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactConnectedServiceAccount_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WACContactDate* */)importantDates {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactDate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImportantDates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactDate_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)dataSuppliers {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataSuppliers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WACContactJobInfo* */)jobInfo {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactJobInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_JobInfo(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactJobInfo_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WACContactSignificantOther* */)significantOthers {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactSignificantOther*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignificantOthers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactSignificantOther_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WACContactWebsite* */)websites {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactWebsite*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Websites(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactWebsite_create(unmarshalledReturn.Get());
}

- (RTObject<WFCIPropertySet>*)providerProperties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (NSString*)firstName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFirstName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->put_FirstName(nsStrToHstr(value).Get()));
}

- (NSString*)lastName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLastName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastName(nsStrToHstr(value).Get()));
}

- (NSString*)middleName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->get_MiddleName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMiddleName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->put_MiddleName(nsStrToHstr(value).Get()));
}

- (NSString*)yomiGivenName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->get_YomiGivenName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setYomiGivenName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->put_YomiGivenName(nsStrToHstr(value).Get()));
}

- (NSString*)yomiFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->get_YomiFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setYomiFamilyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->put_YomiFamilyName(nsStrToHstr(value).Get()));
}

- (NSString*)honorificNameSuffix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->get_HonorificNameSuffix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHonorificNameSuffix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->put_HonorificNameSuffix(nsStrToHstr(value).Get()));
}

- (NSString*)honorificNamePrefix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->get_HonorificNamePrefix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHonorificNamePrefix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->put_HonorificNamePrefix(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)yomiDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactName>(self);
    THROW_NS_IF_FAILED(_comInst->get_YomiDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)contactListId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactListId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)displayPictureUserUpdateTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayPictureUserUpdateTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setDisplayPictureUserUpdateTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayPictureUserUpdateTime(*[value internalStruct]));
}

- (BOOL)isMe {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMe(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)aggregateId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AggregateId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (NSString*)ringToneToken {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_RingToneToken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRingToneToken:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->put_RingToneToken(nsStrToHstr(value).Get()));
}

- (BOOL)isDisplayPictureManuallySet {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDisplayPictureManuallySet(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WSSIRandomAccessStreamReference>*)largeDisplayPicture {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_LargeDisplayPicture(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStreamReference>*)smallDisplayPicture {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmallDisplayPicture(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStreamReference>*)sourceDisplayPicture {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceDisplayPicture(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setSourceDisplayPicture:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SourceDisplayPicture(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (NSString*)textToneToken {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextToneToken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTextToneToken:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->put_TextToneToken(nsStrToHstr(value).Get()));
}

- (BOOL)isAggregate {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAggregate(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)fullName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_FullName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayNameOverride {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayNameOverride(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayNameOverride:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayNameOverride(nsStrToHstr(value).Get()));
}

- (NSString*)nickname {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_Nickname(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNickname:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->put_Nickname(nsStrToHstr(value).Get()));
}

- (NSString*)sortName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContact3>(self);
    THROW_NS_IF_FAILED(_comInst->get_SortName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACContactCardDelayedDataLoader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setData:(WACContact*)contact {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader>(self);
    THROW_NS_IF_FAILED(_comInst->SetData(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WACContactStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)findContactsAsyncWithSuccess:(void (^)(NSArray* /* WACContact* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindContactsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContact_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findContactsWithSearchTextAsync:(NSString*)searchText
                                success:(void (^)(NSArray* /* WACContact* */))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindContactsWithSearchTextAsync(nsStrToHstr(searchText).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContact_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getContactAsync:(NSString*)contactId success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactAsync(nsStrToHstr(contactId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::Contact*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACContact>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WACContactChangeTracker*)changeTracker {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactChangeTracker> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeTracker(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactChangeTracker>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addContactChangedEvent:(void (^)(WACContactStore*, WACContactChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ContactChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactStore_Windows_ApplicationModel_Contacts_ContactChangedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeContactChangedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ContactChanged(value));
}

- (WACAggregateContactManager*)aggregateContactManager {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IAggregateContactManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AggregateContactManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACAggregateContactManager>(unmarshalledReturn.Get());
}

- (void)findContactListsAsyncWithSuccess:(void (^)(NSArray* /* WACContactList* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactList*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->FindContactListsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactList*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactList*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactList*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContactList_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getContactListAsync:(NSString*)contactListId success:(void (^)(WACContactList*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactList*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactListAsync(nsStrToHstr(contactListId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactList*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactList*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactList> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactList>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)createContactListAsync:(NSString*)displayName success:(void (^)(WACContactList*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactList*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateContactListAsync(nsStrToHstr(displayName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactList*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactList*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactList> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactList>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getMeContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetMeContactAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::Contact*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACContact>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WACContactReader*)getContactReader {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactReader>(unmarshalledReturn.Get());
}

- (WACContactReader*)getContactReaderWithOptions:(WACContactQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactReaderWithOptions(
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(options).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactReader>(unmarshalledReturn.Get());
}

- (void)createContactListInAccountAsync:(NSString*)displayName
                      userDataAccountId:(NSString*)userDataAccountId
                                success:(void (^)(WACContactList*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactList*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateContactListInAccountAsync(nsStrToHstr(displayName).Get(),
                                                                 nsStrToHstr(userDataAccountId).Get(),
                                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactList*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactList*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactList> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactList>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WACContactAnnotationStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)findContactIdsByEmailAsync:(NSString*)emailAddress
                           success:(void (^)(NSArray* /* NSString * */))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindContactIdsByEmailAsync(nsStrToHstr(emailAddress).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_NSString_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findContactIdsByPhoneNumberAsync:(NSString*)phoneNumber
                                 success:(void (^)(NSArray* /* NSString * */))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindContactIdsByPhoneNumberAsync(nsStrToHstr(phoneNumber).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_NSString_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAnnotationsForContactAsync:(WACContact*)contact
                               success:(void (^)(NSArray* /* WACContactAnnotation* */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindAnnotationsForContactAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContactAnnotation_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)disableAnnotationAsync:(WACContactAnnotation*)annotation {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableAnnotationAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(annotation).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)createAnnotationListAsyncWithSuccess:(void (^)(WACContactAnnotationList*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAnnotationListAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactAnnotationList>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)createAnnotationListInAccountAsync:(NSString*)userDataAccountId
                                   success:(void (^)(WACContactAnnotationList*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAnnotationListInAccountAsync(nsStrToHstr(userDataAccountId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactAnnotationList>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getAnnotationListAsync:(NSString*)annotationListId
                       success:(void (^)(WACContactAnnotationList*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetAnnotationListAsync(nsStrToHstr(annotationListId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactAnnotationList>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAnnotationListsAsyncWithSuccess:(void (^)(NSArray* /* WACContactAnnotationList* */))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindAnnotationListsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContactAnnotationList_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WACContactCardOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactCardOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactCardOptions").Get(), &out));
    return [_createRtProxy<WACContactCardOptions>(out.Get()) retain];
}

- (WACContactCardHeaderKind)headerKind {
    ABI::Windows::ApplicationModel::Contacts::ContactCardHeaderKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactCardOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderKind(&unmarshalledReturn));
    return (WACContactCardHeaderKind)unmarshalledReturn;
}

- (void)setHeaderKind:(WACContactCardHeaderKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactCardOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_HeaderKind((ABI::Windows::ApplicationModel::Contacts::ContactCardHeaderKind)value));
}

- (WACContactCardTabKind)initialTabKind {
    ABI::Windows::ApplicationModel::Contacts::ContactCardTabKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactCardOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialTabKind(&unmarshalledReturn));
    return (WACContactCardTabKind)unmarshalledReturn;
}

- (void)setInitialTabKind:(WACContactCardTabKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactCardOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_InitialTabKind((ABI::Windows::ApplicationModel::Contacts::ContactCardTabKind)value));
}

- (NSMutableArray* /* NSString * */)serverSearchContactListIds {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactCardOptions2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerSearchContactListIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WACFullContactCardOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IFullContactCardOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.FullContactCardOptions").Get(),
                                              &out));
    return [_createRtProxy<WACFullContactCardOptions>(out.Get()) retain];
}

- (WUVViewSizePreference)desiredRemainingView {
    ABI::Windows::UI::ViewManagement::ViewSizePreference unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IFullContactCardOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredRemainingView(&unmarshalledReturn));
    return (WUVViewSizePreference)unmarshalledReturn;
}

- (void)setDesiredRemainingView:(WUVViewSizePreference)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IFullContactCardOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredRemainingView((ABI::Windows::UI::ViewManagement::ViewSizePreference)value));
}

@end

@implementation WACContactManagerForUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)convertContactToVCardAsync:(WACContact*)contact
                           success:(void (^)(WSSRandomAccessStreamReference*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConvertContactToVCardAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSRandomAccessStreamReference>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)convertContactToVCardAsyncWithMaxBytes:(WACContact*)contact
                                      maxBytes:(unsigned int)maxBytes
                                       success:(void (^)(WSSRandomAccessStreamReference*))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConvertContactToVCardAsyncWithMaxBytes(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                         maxBytes,
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSRandomAccessStreamReference>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)convertVCardToContactAsync:(RTObject<WSSIRandomAccessStreamReference>*)vCard
                           success:(void (^)(WACContact*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->ConvertVCardToContactAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(vCard).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::Contact*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACContact>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)requestStoreAsync:(WACContactStoreAccessType)accessType
                  success:(void (^)(WACContactStore*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactStore*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestStoreAsync((ABI::Windows::ApplicationModel::Contacts::ContactStoreAccessType)accessType, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactStore>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)requestAnnotationStoreAsync:(WACContactAnnotationStoreAccessType)accessType
                            success:(void (^)(WACContactAnnotationStore*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationStore*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestAnnotationStoreAsync((ABI::Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType)accessType,
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationStore*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationStore*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactAnnotationStore>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WACContactNameOrder)systemDisplayNameOrder {
    ABI::Windows::ApplicationModel::Contacts::ContactNameOrder unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemDisplayNameOrder(&unmarshalledReturn));
    return (WACContactNameOrder)unmarshalledReturn;
}

- (void)setSystemDisplayNameOrder:(WACContactNameOrder)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->put_SystemDisplayNameOrder((ABI::Windows::ApplicationModel::Contacts::ContactNameOrder)value));
}

- (WACContactNameOrder)systemSortOrder {
    ABI::Windows::ApplicationModel::Contacts::ContactNameOrder unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemSortOrder(&unmarshalledReturn));
    return (WACContactNameOrder)unmarshalledReturn;
}

- (void)setSystemSortOrder:(WACContactNameOrder)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->put_SystemSortOrder((ABI::Windows::ApplicationModel::Contacts::ContactNameOrder)value));
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WACContactAnnotation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactAnnotation").Get(), &out));
    return [_createRtProxy<WACContactAnnotation>(out.Get()) retain];
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)annotationListId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_AnnotationListId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)contactId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContactId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContactId(nsStrToHstr(value).Get()));
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (WACContactAnnotationOperations)supportedOperations {
    ABI::Windows::ApplicationModel::Contacts::ContactAnnotationOperations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedOperations(&unmarshalledReturn));
    return (WACContactAnnotationOperations)unmarshalledReturn;
}

- (void)setSupportedOperations:(WACContactAnnotationOperations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->put_SupportedOperations((ABI::Windows::ApplicationModel::Contacts::ContactAnnotationOperations)value));
}

- (BOOL)isDisabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDisabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFCValueSet*)providerProperties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

@end

@implementation WACContactAnnotationList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)providerPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)userDataAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserDataAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)deleteAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)trySaveAnnotationAsync:(WACContactAnnotation*)annotation success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList>(self);
    THROW_NS_IF_FAILED(
        _comInst->TrySaveAnnotationAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(annotation).Get(),
                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getAnnotationAsync:(NSString*)annotationId success:(void (^)(WACContactAnnotation*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList>(self);
    THROW_NS_IF_FAILED(_comInst->GetAnnotationAsync(nsStrToHstr(annotationId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactAnnotation>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAnnotationsByRemoteIdAsync:(NSString*)remoteId
                               success:(void (^)(NSArray* /* WACContactAnnotation* */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList>(self);
    THROW_NS_IF_FAILED(_comInst->FindAnnotationsByRemoteIdAsync(nsStrToHstr(remoteId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContactAnnotation_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)findAnnotationsAsyncWithSuccess:(void (^)(NSArray* /* WACContactAnnotation* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList>(self);
    THROW_NS_IF_FAILED(_comInst->FindAnnotationsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContactAnnotation_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAnnotationAsync:(WACContactAnnotation*)annotation {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList>(self);
    THROW_NS_IF_FAILED(
        _comInst->DeleteAnnotationAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation>(annotation).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WACContactChangeTracker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactChangeTracker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Enable());
}

- (WACContactChangeReader*)getChangeReader {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactChangeReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->GetChangeReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactChangeReader>(unmarshalledReturn.Get());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

@end

@implementation WACContactChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactChangedDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactChangedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactChangedDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WACAggregateContactManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IAggregateContactManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)findRawContactsAsync:(WACContact*)contact
                     success:(void (^)(NSArray* /* WACContact* */))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IAggregateContactManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindRawContactsAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContact_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryLinkContactsAsync:(WACContact*)primaryContact
            secondaryContact:(WACContact*)secondaryContact
                     success:(void (^)(WACContact*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IAggregateContactManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryLinkContactsAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(primaryContact).Get(),
                                       _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(secondaryContact).Get(),
                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::Contact*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACContact>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)unlinkRawContactAsync:(WACContact*)contact {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IAggregateContactManager>(self);
    THROW_NS_IF_FAILED(_comInst->UnlinkRawContactAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)trySetPreferredSourceForPictureAsync:(WACContact*)aggregateContact
                                  rawContact:(WACContact*)rawContact
                                     success:(void (^)(BOOL))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IAggregateContactManager>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetPreferredSourceForPictureAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(aggregateContact).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(rawContact).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)setRemoteIdentificationInformationAsync:(NSString*)contactListId
                                                      remoteSourceId:(NSString*)remoteSourceId
                                                           accountId:(NSString*)accountId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IAggregateContactManager2>(self);
    THROW_NS_IF_FAILED(_comInst->SetRemoteIdentificationInformationAsync(nsStrToHstr(contactListId).Get(),
                                                                         nsStrToHstr(remoteSourceId).Get(),
                                                                         nsStrToHstr(accountId).Get(),
                                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WACContactList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)sourceDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isHidden {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHidden(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsHidden:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsHidden((boolean)value));
}

- (WACContactListOtherAppReadAccess)otherAppReadAccess {
    ABI::Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_OtherAppReadAccess(&unmarshalledReturn));
    return (WACContactListOtherAppReadAccess)unmarshalledReturn;
}

- (void)setOtherAppReadAccess:(WACContactListOtherAppReadAccess)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->put_OtherAppReadAccess((ABI::Windows::ApplicationModel::Contacts::ContactListOtherAppReadAccess)value));
}

- (WACContactListOtherAppWriteAccess)otherAppWriteAccess {
    ABI::Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_OtherAppWriteAccess(&unmarshalledReturn));
    return (WACContactListOtherAppWriteAccess)unmarshalledReturn;
}

- (void)setOtherAppWriteAccess:(WACContactListOtherAppWriteAccess)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->put_OtherAppWriteAccess((ABI::Windows::ApplicationModel::Contacts::ContactListOtherAppWriteAccess)value));
}

- (WACContactChangeTracker*)changeTracker {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactChangeTracker> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeTracker(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactChangeTracker>(unmarshalledReturn.Get());
}

- (WACContactListSyncManager*)syncManager {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_SyncManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactListSyncManager>(unmarshalledReturn.Get());
}

- (BOOL)supportsServerSearch {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsServerSearch(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)userDataAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserDataAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addContactChangedEvent:(void (^)(WACContactList*, WACContactChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->add_ContactChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactList_Windows_ApplicationModel_Contacts_ContactChangedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeContactChangedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ContactChanged(value));
}

- (RTObject<WFIAsyncAction>*)saveAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->SaveAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getContactFromRemoteIdAsync:(NSString*)remoteId success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactFromRemoteIdAsync(nsStrToHstr(remoteId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::Contact*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACContact>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getMeContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->GetMeContactAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::Contact*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACContact>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WACContactReader*)getContactReader {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactReader>(unmarshalledReturn.Get());
}

- (WACContactReader*)getContactReaderWithOptions:(WACContactQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactReaderWithOptions(
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(options).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactReader>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)saveContactAsync:(WACContact*)contact {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->SaveContactAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteContactAsync:(WACContact*)contact {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteContactAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getContactAsync:(NSString*)contactId success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactAsync(nsStrToHstr(contactId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::Contact*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACContact>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)registerSyncManagerAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList2>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterSyncManagerAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setSupportsServerSearch:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SupportsServerSearch((boolean)value));
}

- (WACContactListSyncConstraints*)syncConstraints {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactList2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SyncConstraints(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactListSyncConstraints>(unmarshalledReturn.Get());
}

@end

@implementation WACContactReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)readBatchAsyncWithSuccess:(void (^)(WACContactBatch*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactBatch*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactBatch*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactBatch*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactBatch> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactBatch>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSArray* /* WACContactMatchReason* */)getMatchingPropertiesWithMatchReason:(WACContact*)contact {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactMatchReason*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactReader>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetMatchingPropertiesWithMatchReason(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACContactMatchReason_create(unmarshalledReturn.Get());
}

@end

@implementation WACContactQueryOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactQueryOptions").Get(),
                                              &out));
    return [_createRtProxy<WACContactQueryOptions>(out.Get()) retain];
}

static ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptionsFactory> WACIContactQueryOptionsFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptionsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactQueryOptions").Get(), &inst));
    return inst;
}

+ (WACContactQueryOptions*)makeWithText:(NSString*)text {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions> unmarshalledReturn;
    auto _comInst = WACIContactQueryOptionsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithText(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactQueryOptions>(unmarshalledReturn.Get()) retain];
}

+ (WACContactQueryOptions*)makeWithTextAndFields:(NSString*)text fields:(WACContactQuerySearchFields)fields {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions> unmarshalledReturn;
    auto _comInst = WACIContactQueryOptionsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithTextAndFields(nsStrToHstr(text).Get(),
                                                         (ABI::Windows::ApplicationModel::Contacts::ContactQuerySearchFields)fields,
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactQueryOptions>(unmarshalledReturn.Get()) retain];
}

- (WACContactQueryTextSearch*)textSearch {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactQueryTextSearch> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextSearch(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactQueryTextSearch>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)contactListIds {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactListIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (BOOL)includeContactsFromHiddenLists {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeContactsFromHiddenLists(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIncludeContactsFromHiddenLists:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncludeContactsFromHiddenLists((boolean)value));
}

- (WACContactQueryDesiredFields)desiredFields {
    ABI::Windows::ApplicationModel::Contacts::ContactQueryDesiredFields unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredFields(&unmarshalledReturn));
    return (WACContactQueryDesiredFields)unmarshalledReturn;
}

- (void)setDesiredFields:(WACContactQueryDesiredFields)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredFields((ABI::Windows::ApplicationModel::Contacts::ContactQueryDesiredFields)value));
}

- (WACContactAnnotationOperations)desiredOperations {
    ABI::Windows::ApplicationModel::Contacts::ContactAnnotationOperations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredOperations(&unmarshalledReturn));
    return (WACContactAnnotationOperations)unmarshalledReturn;
}

- (void)setDesiredOperations:(WACContactAnnotationOperations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredOperations((ABI::Windows::ApplicationModel::Contacts::ContactAnnotationOperations)value));
}

- (NSMutableArray* /* NSString * */)annotationListIds {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_AnnotationListIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WACContactListSyncManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactListSyncStatus)status {
    ABI::Windows::ApplicationModel::Contacts::ContactListSyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WACContactListSyncStatus)unmarshalledReturn;
}

- (WFDateTime*)lastSuccessfulSyncTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastSuccessfulSyncTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)lastAttemptedSyncTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastAttemptedSyncTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)syncAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->SyncAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addSyncStatusChangedEvent:(void (^)(WACContactListSyncManager*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SyncStatusChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Contacts_ContactListSyncManager_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSyncStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SyncStatusChanged(token));
}

- (void)setStatus:(WACContactListSyncStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Status((ABI::Windows::ApplicationModel::Contacts::ContactListSyncStatus)value));
}

- (void)setLastSuccessfulSyncTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastSuccessfulSyncTime(*[value internalStruct]));
}

- (void)setLastAttemptedSyncTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastAttemptedSyncTime(*[value internalStruct]));
}

@end

@implementation WACContactListSyncConstraints

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)canSyncDescriptions {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSyncDescriptions(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanSyncDescriptions:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanSyncDescriptions((boolean)value));
}

- (id /* int */)maxHomePhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxHomePhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxHomePhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxHomePhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxMobilePhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxMobilePhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxMobilePhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxMobilePhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxWorkPhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxWorkPhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxWorkPhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxWorkPhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxOtherPhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxOtherPhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxOtherPhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxOtherPhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxPagerPhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPagerPhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxPagerPhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxPagerPhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxBusinessFaxPhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxBusinessFaxPhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxBusinessFaxPhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxBusinessFaxPhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxHomeFaxPhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxHomeFaxPhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxHomeFaxPhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxHomeFaxPhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxCompanyPhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxCompanyPhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxCompanyPhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxCompanyPhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxAssistantPhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxAssistantPhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxAssistantPhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxAssistantPhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxRadioPhoneNumbers {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxRadioPhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxRadioPhoneNumbers:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxRadioPhoneNumbers(BuildNullable<int>(value)));
}

- (id /* int */)maxPersonalEmailAddresses {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPersonalEmailAddresses(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxPersonalEmailAddresses:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxPersonalEmailAddresses(BuildNullable<int>(value)));
}

- (id /* int */)maxWorkEmailAddresses {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxWorkEmailAddresses(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxWorkEmailAddresses:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxWorkEmailAddresses(BuildNullable<int>(value)));
}

- (id /* int */)maxOtherEmailAddresses {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxOtherEmailAddresses(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxOtherEmailAddresses:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxOtherEmailAddresses(BuildNullable<int>(value)));
}

- (id /* int */)maxHomeAddresses {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxHomeAddresses(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxHomeAddresses:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxHomeAddresses(BuildNullable<int>(value)));
}

- (id /* int */)maxWorkAddresses {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxWorkAddresses(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxWorkAddresses:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxWorkAddresses(BuildNullable<int>(value)));
}

- (id /* int */)maxOtherAddresses {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxOtherAddresses(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxOtherAddresses:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxOtherAddresses(BuildNullable<int>(value)));
}

- (id /* int */)maxBirthdayDates {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxBirthdayDates(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxBirthdayDates:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxBirthdayDates(BuildNullable<int>(value)));
}

- (id /* int */)maxAnniversaryDates {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxAnniversaryDates(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxAnniversaryDates:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxAnniversaryDates(BuildNullable<int>(value)));
}

- (id /* int */)maxOtherDates {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxOtherDates(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxOtherDates:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxOtherDates(BuildNullable<int>(value)));
}

- (id /* int */)maxOtherRelationships {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxOtherRelationships(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxOtherRelationships:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxOtherRelationships(BuildNullable<int>(value)));
}

- (id /* int */)maxSpouseRelationships {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxSpouseRelationships(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxSpouseRelationships:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxSpouseRelationships(BuildNullable<int>(value)));
}

- (id /* int */)maxPartnerRelationships {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPartnerRelationships(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxPartnerRelationships:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxPartnerRelationships(BuildNullable<int>(value)));
}

- (id /* int */)maxSiblingRelationships {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxSiblingRelationships(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxSiblingRelationships:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxSiblingRelationships(BuildNullable<int>(value)));
}

- (id /* int */)maxParentRelationships {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxParentRelationships(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxParentRelationships:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxParentRelationships(BuildNullable<int>(value)));
}

- (id /* int */)maxChildRelationships {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxChildRelationships(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxChildRelationships:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxChildRelationships(BuildNullable<int>(value)));
}

- (id /* int */)maxJobInfo {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxJobInfo(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxJobInfo:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxJobInfo(BuildNullable<int>(value)));
}

- (id /* int */)maxWebsites {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxWebsites(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setMaxWebsites:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactListSyncConstraints>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxWebsites(BuildNullable<int>(value)));
}

@end

@implementation WACContactPhone

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactPhone> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactPhone").Get(), &out));
    return [_createRtProxy<WACContactPhone>(out.Get()) retain];
}

- (NSString*)number {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPhone>(self);
    THROW_NS_IF_FAILED(_comInst->get_Number(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumber:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPhone>(self);
    THROW_NS_IF_FAILED(_comInst->put_Number(nsStrToHstr(value).Get()));
}

- (WACContactPhoneKind)kind {
    ABI::Windows::ApplicationModel::Contacts::ContactPhoneKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPhone>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WACContactPhoneKind)unmarshalledReturn;
}

- (void)setKind:(WACContactPhoneKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPhone>(self);
    THROW_NS_IF_FAILED(_comInst->put_Kind((ABI::Windows::ApplicationModel::Contacts::ContactPhoneKind)value));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPhone>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPhone>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

@end

@implementation WACContactEmail

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactEmail> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactEmail").Get(), &out));
    return [_createRtProxy<WACContactEmail>(out.Get()) retain];
}

- (NSString*)address {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactEmail>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactEmail>(self);
    THROW_NS_IF_FAILED(_comInst->put_Address(nsStrToHstr(value).Get()));
}

- (WACContactEmailKind)kind {
    ABI::Windows::ApplicationModel::Contacts::ContactEmailKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactEmail>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WACContactEmailKind)unmarshalledReturn;
}

- (void)setKind:(WACContactEmailKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactEmail>(self);
    THROW_NS_IF_FAILED(_comInst->put_Kind((ABI::Windows::ApplicationModel::Contacts::ContactEmailKind)value));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactEmail>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactEmail>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

@end

@implementation WACContactAddress

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAddress> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactAddress").Get(), &out));
    return [_createRtProxy<WACContactAddress>(out.Get()) retain];
}

- (NSString*)streetAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreetAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setStreetAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_StreetAddress(nsStrToHstr(value).Get()));
}

- (NSString*)locality {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Locality(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLocality:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_Locality(nsStrToHstr(value).Get()));
}

- (NSString*)region {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Region(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRegion:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_Region(nsStrToHstr(value).Get()));
}

- (NSString*)country {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Country(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCountry:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_Country(nsStrToHstr(value).Get()));
}

- (NSString*)postalCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostalCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPostalCode:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_PostalCode(nsStrToHstr(value).Get()));
}

- (WACContactAddressKind)kind {
    ABI::Windows::ApplicationModel::Contacts::ContactAddressKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WACContactAddressKind)unmarshalledReturn;
}

- (void)setKind:(WACContactAddressKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_Kind((ABI::Windows::ApplicationModel::Contacts::ContactAddressKind)value));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

@end

@implementation WACContactConnectedServiceAccount

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactConnectedServiceAccount").Get(), &out));
    return [_createRtProxy<WACContactConnectedServiceAccount>(out.Get()) retain];
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)serviceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setServiceName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount>(self);
    THROW_NS_IF_FAILED(_comInst->put_ServiceName(nsStrToHstr(value).Get()));
}

@end

@implementation WACContactDate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactDate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactDate").Get(), &out));
    return [_createRtProxy<WACContactDate>(out.Get()) retain];
}

- (id /* unsigned int */)day {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Day(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setDay:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->put_Day(BuildNullable<unsigned int>(value)));
}

- (id /* unsigned int */)month {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Month(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setMonth:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->put_Month(BuildNullable<unsigned int>(value)));
}

- (id /* int */)year {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Year(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setYear:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->put_Year(BuildNullable<int>(value)));
}

- (WACContactDateKind)kind {
    ABI::Windows::ApplicationModel::Contacts::ContactDateKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WACContactDateKind)unmarshalledReturn;
}

- (void)setKind:(WACContactDateKind)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->put_Kind((ABI::Windows::ApplicationModel::Contacts::ContactDateKind)value));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactDate>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

@end

@implementation WACContactJobInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactJobInfo").Get(), &out));
    return [_createRtProxy<WACContactJobInfo>(out.Get()) retain];
}

- (NSString*)companyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompanyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompanyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CompanyName(nsStrToHstr(value).Get()));
}

- (NSString*)companyYomiName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompanyYomiName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompanyYomiName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CompanyYomiName(nsStrToHstr(value).Get()));
}

- (NSString*)department {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Department(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDepartment:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Department(nsStrToHstr(value).Get()));
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSString*)manager {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Manager(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setManager:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Manager(nsStrToHstr(value).Get()));
}

- (NSString*)office {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Office(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setOffice:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Office(nsStrToHstr(value).Get()));
}

- (NSString*)companyAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompanyAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCompanyAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_CompanyAddress(nsStrToHstr(value).Get()));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

@end

@implementation WACContactSignificantOther

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactSignificantOther").Get(),
                                              &out));
    return [_createRtProxy<WACContactSignificantOther>(out.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

- (WACContactRelationship)relationship {
    ABI::Windows::ApplicationModel::Contacts::ContactRelationship unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Relationship(&unmarshalledReturn));
    return (WACContactRelationship)unmarshalledReturn;
}

- (void)setRelationship:(WACContactRelationship)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Relationship((ABI::Windows::ApplicationModel::Contacts::ContactRelationship)value));
}

@end

@implementation WACContactWebsite

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactWebsite> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactWebsite").Get(), &out));
    return [_createRtProxy<WACContactWebsite>(out.Get()) retain];
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactWebsite>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactWebsite>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactWebsite>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactWebsite>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

- (NSString*)rawValue {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactWebsite2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawValue(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRawValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactWebsite2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RawValue(nsStrToHstr(value).Get()));
}

@end

@implementation WACContactChangedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactChangedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChangedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WACContactChange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactChange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactChangeType)changeType {
    ABI::Windows::ApplicationModel::Contacts::ContactChangeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeType(&unmarshalledReturn));
    return (WACContactChangeType)unmarshalledReturn;
}

- (WACContact*)contact {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContact>(unmarshalledReturn.Get());
}

@end

@implementation WACContactChangeReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactChangeReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)acceptChanges {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptChanges());
}

- (void)acceptChangesThrough:(WACContactChange*)lastChangeToAccept {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptChangesThrough(
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContactChange>(lastChangeToAccept).Get()));
}

- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WACContactChange* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactChange*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactChange*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactChange*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactChange*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContactChange_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WACContactBatch

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactBatch> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WACContact* */)contacts {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contacts(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACContact_create(unmarshalledReturn.Get());
}

- (WACContactBatchStatus)status {
    ABI::Windows::ApplicationModel::Contacts::ContactBatchStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WACContactBatchStatus)unmarshalledReturn;
}

@end

@implementation WACContactMatchReason

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactMatchReason> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactMatchReasonKind)field {
    ABI::Windows::ApplicationModel::Contacts::ContactMatchReasonKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactMatchReason>(self);
    THROW_NS_IF_FAILED(_comInst->get_Field(&unmarshalledReturn));
    return (WACContactMatchReasonKind)unmarshalledReturn;
}

- (NSArray* /* WDTTextSegment* */)segments {
    ComPtr<IVectorView<ABI::Windows::Data::Text::TextSegment>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactMatchReason>(self);
    THROW_NS_IF_FAILED(_comInst->get_Segments(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDTTextSegment_create(unmarshalledReturn.Get());
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactMatchReason>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACContactQueryTextSearch

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactQueryTextSearch> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACContactQuerySearchFields)fields {
    ABI::Windows::ApplicationModel::Contacts::ContactQuerySearchFields unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Fields(&unmarshalledReturn));
    return (WACContactQuerySearchFields)unmarshalledReturn;
}

- (void)setFields:(WACContactQuerySearchFields)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->put_Fields((ABI::Windows::ApplicationModel::Contacts::ContactQuerySearchFields)value));
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (WACContactQuerySearchScope)searchScope {
    ABI::Windows::ApplicationModel::Contacts::ContactQuerySearchScope unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchScope(&unmarshalledReturn));
    return (WACContactQuerySearchScope)unmarshalledReturn;
}

- (void)setSearchScope:(WACContactQuerySearchScope)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactQueryTextSearch>(self);
    THROW_NS_IF_FAILED(_comInst->put_SearchScope((ABI::Windows::ApplicationModel::Contacts::ContactQuerySearchScope)value));
}

@end

@implementation WACContactStoreNotificationTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WACContactManager

ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics3> WACIContactManagerStatics3_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)convertContactToVCardAsync:(WACContact*)contact
                           success:(void (^)(WSSRandomAccessStreamReference*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>> unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->ConvertContactToVCardAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSRandomAccessStreamReference>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)convertContactToVCardAsyncWithMaxBytes:(WACContact*)contact
                                      maxBytes:(unsigned int)maxBytes
                                       success:(void (^)(WSSRandomAccessStreamReference*))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>> unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->ConvertContactToVCardAsyncWithMaxBytes(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                         maxBytes,
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::RandomAccessStreamReference*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSRandomAccessStreamReference>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)convertVCardToContactAsync:(RTObject<WSSIRandomAccessStreamReference>*)vCard
                           success:(void (^)(WACContact*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->ConvertVCardToContactAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(vCard).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::Contact*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACContact>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)requestStoreAsyncWithAccessType:(WACContactStoreAccessType)accessType
                                success:(void (^)(WACContactStore*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactStore*>> unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->RequestStoreAsyncWithAccessType((ABI::Windows::ApplicationModel::Contacts::ContactStoreAccessType)accessType,
                                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactStore>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)requestAnnotationStoreAsync:(WACContactAnnotationStoreAccessType)accessType
                            success:(void (^)(WACContactAnnotationStore*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationStore*>> unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->RequestAnnotationStoreAsync((ABI::Windows::ApplicationModel::Contacts::ContactAnnotationStoreAccessType)accessType,
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationStore*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationStore*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactAnnotationStore>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (BOOL)isShowContactCardSupported {
    boolean unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->IsShowContactCardSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)showContactCardWithOptions:(WACContact*)contact
                         selection:(WFRect*)selection
                preferredPlacement:(WUPPlacement)preferredPlacement
                contactCardOptions:(WACContactCardOptions*)contactCardOptions {
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->ShowContactCardWithOptions(
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
        *[selection internalStruct],
        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContactCardOptions>(contactCardOptions).Get()));
}

+ (BOOL)isShowDelayLoadedContactCardSupported {
    boolean unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->IsShowDelayLoadedContactCardSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCardWithOptions:(WACContact*)contact
                                                                selection:(WFRect*)selection
                                                       preferredPlacement:(WUPPlacement)preferredPlacement
                                                       contactCardOptions:(WACContactCardOptions*)contactCardOptions {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader> unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->ShowDelayLoadedContactCardWithOptions(
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
        *[selection internalStruct],
        (ABI::Windows::UI::Popups::Placement)preferredPlacement,
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContactCardOptions>(contactCardOptions).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactCardDelayedDataLoader>(unmarshalledReturn.Get());
}

+ (void)showFullContactCard:(WACContact*)contact fullContactCardOptions:(WACFullContactCardOptions*)fullContactCardOptions {
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->ShowFullContactCard(
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IFullContactCardOptions>(fullContactCardOptions).Get()));
}

+ (WACContactNameOrder)systemDisplayNameOrder {
    ABI::Windows::ApplicationModel::Contacts::ContactNameOrder unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_SystemDisplayNameOrder(&unmarshalledReturn));
    return (WACContactNameOrder)unmarshalledReturn;
}

+ (void)setSystemDisplayNameOrder:(WACContactNameOrder)value {
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->put_SystemDisplayNameOrder((ABI::Windows::ApplicationModel::Contacts::ContactNameOrder)value));
}

+ (WACContactNameOrder)systemSortOrder {
    ABI::Windows::ApplicationModel::Contacts::ContactNameOrder unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_SystemSortOrder(&unmarshalledReturn));
    return (WACContactNameOrder)unmarshalledReturn;
}

+ (void)setSystemSortOrder:(WACContactNameOrder)value {
    auto _comInst = WACIContactManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->put_SystemSortOrder((ABI::Windows::ApplicationModel::Contacts::ContactNameOrder)value));
}

ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics4> WACIContactManagerStatics4_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics4> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactManager").Get(),
                                                       &inst));
    return inst;
}

+ (WACContactManagerForUser*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerForUser> unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactManagerForUser>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics> WACIContactManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)showContactCard:(WACContact*)contact selection:(WFRect*)selection {
    auto _comInst = WACIContactManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowContactCard(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                 *[selection internalStruct]));
}

+ (void)showContactCardWithPlacement:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement {
    auto _comInst = WACIContactManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ShowContactCardWithPlacement(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                               *[selection internalStruct],
                                               (ABI::Windows::UI::Popups::Placement)preferredPlacement));
}

+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCard:(WACContact*)contact
                                                     selection:(WFRect*)selection
                                            preferredPlacement:(WUPPlacement)preferredPlacement {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactCardDelayedDataLoader> unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ShowDelayLoadedContactCard(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                             *[selection internalStruct],
                                             (ABI::Windows::UI::Popups::Placement)preferredPlacement,
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactCardDelayedDataLoader>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics2> WACIContactManagerStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)requestStoreAsyncWithSuccess:(void (^)(WACContactStore*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactStore*>> unmarshalledReturn;
    auto _comInst = WACIContactManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactStore>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WACContactLaunchActionVerbs

ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics> WACIContactLaunchActionVerbsStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactLaunchActionVerbs").Get(), &inst));
    return inst;
}

+ (NSString*)call {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIContactLaunchActionVerbsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Call(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIContactLaunchActionVerbsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)map {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIContactLaunchActionVerbsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Map(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)post {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIContactLaunchActionVerbsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Post(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)videoCall {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIContactLaunchActionVerbsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VideoCall(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACContactField

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory> WACIContactFieldFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactField").Get(),
                                                       &inst));
    return inst;
}

+ (WACContactField*)makeField_Default:(NSString*)value type:(WACContactFieldType)type {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> unmarshalledReturn;
    auto _comInst = WACIContactFieldFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateField_Default(nsStrToHstr(value).Get(),
                                                     (ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type,
                                                     unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactField>(unmarshalledReturn.Get()) retain];
}

+ (WACContactField*)makeField_Category:(NSString*)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> unmarshalledReturn;
    auto _comInst = WACIContactFieldFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateField_Category(nsStrToHstr(value).Get(),
                                                      (ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type,
                                                      (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                      unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactField>(unmarshalledReturn.Get()) retain];
}

+ (WACContactField*)makeField_Custom:(NSString*)name
                               value:(NSString*)value
                                type:(WACContactFieldType)type
                            category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> unmarshalledReturn;
    auto _comInst = WACIContactFieldFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateField_Custom(nsStrToHstr(name).Get(),
                                                    nsStrToHstr(value).Get(),
                                                    (ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type,
                                                    (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                    unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactField>(unmarshalledReturn.Get()) retain];
}

- (WACContactFieldType)type {
    ABI::Windows::ApplicationModel::Contacts::ContactFieldType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WACContactFieldType)unmarshalledReturn;
}

- (WACContactFieldCategory)category {
    ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return (WACContactFieldCategory)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACContactLocationField

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory> WACIContactLocationFieldFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactLocationField").Get(), &inst));
    return inst;
}

+ (WACContactLocationField*)makeLocation_Default:(NSString*)unstructuredAddress {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> unmarshalledReturn;
    auto _comInst = WACIContactLocationFieldFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateLocation_Default(nsStrToHstr(unstructuredAddress).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactLocationField>(unmarshalledReturn.Get()) retain];
}

+ (WACContactLocationField*)makeLocation_Category:(NSString*)unstructuredAddress category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> unmarshalledReturn;
    auto _comInst = WACIContactLocationFieldFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateLocation_Category(nsStrToHstr(unstructuredAddress).Get(),
                                                         (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactLocationField>(unmarshalledReturn.Get()) retain];
}

+ (WACContactLocationField*)makeLocation_All:(NSString*)unstructuredAddress
                                    category:(WACContactFieldCategory)category
                                      street:(NSString*)street
                                        city:(NSString*)city
                                      region:(NSString*)region
                                     country:(NSString*)country
                                  postalCode:(NSString*)postalCode {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> unmarshalledReturn;
    auto _comInst = WACIContactLocationFieldFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateLocation_All(nsStrToHstr(unstructuredAddress).Get(),
                                                    (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                    nsStrToHstr(street).Get(),
                                                    nsStrToHstr(city).Get(),
                                                    nsStrToHstr(region).Get(),
                                                    nsStrToHstr(country).Get(),
                                                    nsStrToHstr(postalCode).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactLocationField>(unmarshalledReturn.Get()) retain];
}

- (NSString*)unstructuredAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationField>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnstructuredAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)street {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Street(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)city {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationField>(self);
    THROW_NS_IF_FAILED(_comInst->get_City(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)region {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Region(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)country {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Country(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)postalCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationField>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostalCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACContactFieldType)type {
    ABI::Windows::ApplicationModel::Contacts::ContactFieldType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WACContactFieldType)unmarshalledReturn;
}

- (WACContactFieldCategory)category {
    ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return (WACContactFieldCategory)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACContactInstantMessageField

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory> WACIContactInstantMessageFieldFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactInstantMessageField").Get(), &inst));
    return inst;
}

+ (WACContactInstantMessageField*)makeInstantMessage_Default:(NSString*)userName {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> unmarshalledReturn;
    auto _comInst = WACIContactInstantMessageFieldFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstantMessage_Default(nsStrToHstr(userName).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactInstantMessageField>(unmarshalledReturn.Get()) retain];
}

+ (WACContactInstantMessageField*)makeInstantMessage_Category:(NSString*)userName category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> unmarshalledReturn;
    auto _comInst = WACIContactInstantMessageFieldFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstantMessage_Category(nsStrToHstr(userName).Get(),
                                                               (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                               unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactInstantMessageField>(unmarshalledReturn.Get()) retain];
}

+ (WACContactInstantMessageField*)makeInstantMessage_All:(NSString*)userName
                                                category:(WACContactFieldCategory)category
                                                 service:(NSString*)service
                                             displayText:(NSString*)displayText
                                                    verb:(WFUri*)verb {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> unmarshalledReturn;
    auto _comInst = WACIContactInstantMessageFieldFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstantMessage_All(nsStrToHstr(userName).Get(),
                                                          (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                          nsStrToHstr(service).Get(),
                                                          nsStrToHstr(displayText).Get(),
                                                          _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(verb).Get(),
                                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WACContactInstantMessageField>(unmarshalledReturn.Get()) retain];
}

- (NSString*)userName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)service {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Service(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)launchUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField>(self);
    THROW_NS_IF_FAILED(_comInst->get_LaunchUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WACContactFieldType)type {
    ABI::Windows::ApplicationModel::Contacts::ContactFieldType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WACContactFieldType)unmarshalledReturn;
}

- (WACContactFieldCategory)category {
    ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return (WACContactFieldCategory)unmarshalledReturn;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactField>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACKnownContactField

ComPtr<ABI::Windows::ApplicationModel::Contacts::IKnownContactFieldStatics> WACIKnownContactFieldStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IKnownContactFieldStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Contacts.KnownContactField").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)email {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIKnownContactFieldStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Email(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)phoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIKnownContactFieldStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)location {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIKnownContactFieldStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Location(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)instantMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIKnownContactFieldStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InstantMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WACContactFieldType)convertNameToType:(NSString*)name {
    ABI::Windows::ApplicationModel::Contacts::ContactFieldType unmarshalledReturn;
    auto _comInst = WACIKnownContactFieldStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertNameToType(nsStrToHstr(name).Get(), &unmarshalledReturn));
    return (WACContactFieldType)unmarshalledReturn;
}

+ (NSString*)convertTypeToName:(WACContactFieldType)type {
    HSTRING unmarshalledReturn;
    auto _comInst = WACIKnownContactFieldStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertTypeToName((ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACContactInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)getThumbnailAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStreamWithContentType>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSArray* /* WACContactField* */)emails {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactField*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emails(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACContactField_create(unmarshalledReturn.Get());
}

- (NSArray* /* WACContactField* */)phoneNumbers {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactField*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneNumbers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACContactField_create(unmarshalledReturn.Get());
}

- (NSArray* /* WACContactLocationField* */)locations {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactLocationField*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Locations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACContactLocationField_create(unmarshalledReturn.Get());
}

- (NSArray* /* WACContactInstantMessageField* */)instantMessages {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactInstantMessageField*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstantMessages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACContactInstantMessageField_create(unmarshalledReturn.Get());
}

- (NSArray* /* WACContactField* */)customFields {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactField*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomFields(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACContactField_create(unmarshalledReturn.Get());
}

- (NSArray* /* WACContactField* */)queryCustomFields:(NSString*)customName {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactField*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->QueryCustomFields(nsStrToHstr(customName).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACContactField_create(unmarshalledReturn.Get());
}

@end

@implementation WACContactFieldFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactFieldFactory").Get(),
                                              &out));
    return [_createRtProxy<WACContactFieldFactory>(out.Get()) retain];
}

- (WACContactField*)createField_Default:(NSString*)value type:(WACContactFieldType)type {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateField_Default(nsStrToHstr(value).Get(),
                                                     (ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type,
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactField>(unmarshalledReturn.Get());
}

- (WACContactField*)createField_Category:(NSString*)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateField_Category(nsStrToHstr(value).Get(),
                                                      (ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type,
                                                      (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactField>(unmarshalledReturn.Get());
}

- (WACContactField*)createField_Custom:(NSString*)name
                                 value:(NSString*)value
                                  type:(WACContactFieldType)type
                              category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateField_Custom(nsStrToHstr(name).Get(),
                                                    nsStrToHstr(value).Get(),
                                                    (ABI::Windows::ApplicationModel::Contacts::ContactFieldType)type,
                                                    (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactField>(unmarshalledReturn.Get());
}

- (WACContactLocationField*)createLocation_Default:(NSString*)unstructuredAddress {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLocation_Default(nsStrToHstr(unstructuredAddress).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactLocationField>(unmarshalledReturn.Get());
}

- (WACContactLocationField*)createLocation_Category:(NSString*)unstructuredAddress category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLocation_Category(nsStrToHstr(unstructuredAddress).Get(),
                                                         (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactLocationField>(unmarshalledReturn.Get());
}

- (WACContactLocationField*)createLocation_All:(NSString*)unstructuredAddress
                                      category:(WACContactFieldCategory)category
                                        street:(NSString*)street
                                          city:(NSString*)city
                                        region:(NSString*)region
                                       country:(NSString*)country
                                    postalCode:(NSString*)postalCode {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactLocationField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactLocationFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLocation_All(nsStrToHstr(unstructuredAddress).Get(),
                                                    (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                    nsStrToHstr(street).Get(),
                                                    nsStrToHstr(city).Get(),
                                                    nsStrToHstr(region).Get(),
                                                    nsStrToHstr(country).Get(),
                                                    nsStrToHstr(postalCode).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactLocationField>(unmarshalledReturn.Get());
}

- (WACContactInstantMessageField*)createInstantMessage_Default:(NSString*)userName {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateInstantMessage_Default(nsStrToHstr(userName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactInstantMessageField>(unmarshalledReturn.Get());
}

- (WACContactInstantMessageField*)createInstantMessage_Category:(NSString*)userName category:(WACContactFieldCategory)category {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateInstantMessage_Category(nsStrToHstr(userName).Get(),
                                                               (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactInstantMessageField>(unmarshalledReturn.Get());
}

- (WACContactInstantMessageField*)createInstantMessage_All:(NSString*)userName
                                                  category:(WACContactFieldCategory)category
                                                   service:(NSString*)service
                                               displayText:(NSString*)displayText
                                                      verb:(WFUri*)verb {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateInstantMessage_All(nsStrToHstr(userName).Get(),
                                                          (ABI::Windows::ApplicationModel::Contacts::ContactFieldCategory)category,
                                                          nsStrToHstr(service).Get(),
                                                          nsStrToHstr(displayText).Get(),
                                                          _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(verb).Get(),
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactInstantMessageField>(unmarshalledReturn.Get());
}

@end

@implementation WACContactPicker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactPicker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Contacts.ContactPicker").Get(), &out));
    return [_createRtProxy<WACContactPicker>(out.Get()) retain];
}

- (NSString*)commitButtonText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommitButtonText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCommitButtonText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_CommitButtonText(nsStrToHstr(value).Get()));
}

- (WACContactSelectionMode)selectionMode {
    ABI::Windows::ApplicationModel::Contacts::ContactSelectionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionMode(&unmarshalledReturn));
    return (WACContactSelectionMode)unmarshalledReturn;
}

- (void)setSelectionMode:(WACContactSelectionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectionMode((ABI::Windows::ApplicationModel::Contacts::ContactSelectionMode)value));
}

- (NSMutableArray* /* NSString * */)desiredFields {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredFields(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (void)pickSingleContactAsyncWithSuccess:(void (^)(WACContactInformation*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactInformation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleContactAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::ContactInformation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::ContactInformation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactInformation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WACContactInformation>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)pickMultipleContactsAsyncWithSuccess:(void (^)(NSArray* /* WACContactInformation* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactInformation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickMultipleContactsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Contacts::ContactInformation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactInformation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACContactInformation_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSMutableArray* /* WACContactFieldType */)desiredFieldsWithContactFieldType {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactFieldType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredFieldsWithContactFieldType(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactFieldType_create(unmarshalledReturn.Get());
}

- (void)pickContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker2>(self);
    THROW_NS_IF_FAILED(_comInst->PickContactAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Contacts::Contact*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Contacts::Contact*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Contacts::IContact> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WACContact>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)pickContactsAsyncWithSuccess:(void (^)(NSMutableArray* /* WACContact* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVector<ABI::Windows::ApplicationModel::Contacts::Contact*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::IContactPicker2>(self);
    THROW_NS_IF_FAILED(_comInst->PickContactsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVector<ABI::Windows::ApplicationModel::Contacts::Contact*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVector<ABI::Windows::ApplicationModel::Contacts::Contact*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::Contact*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableArray_WACContact_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

id RTProxiedNSArray_WACContact_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContact*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::Contact*>,
                                                    WACContact,
                                                    ABI::Windows::ApplicationModel::Contacts::Contact*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACContactAnnotation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactAnnotation*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*>,
                                                    WACContactAnnotation,
                                                    ABI::Windows::ApplicationModel::Contacts::ContactAnnotation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACContactAnnotationList_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactAnnotationList*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*>,
                                                    WACContactAnnotationList,
                                                    ABI::Windows::ApplicationModel::Contacts::ContactAnnotationList*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACContactChange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactChange*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactChange*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactChange*>,
                                                    WACContactChange,
                                                    ABI::Windows::ApplicationModel::Contacts::ContactChange*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACContactField_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactField*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactField*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactField*>,
                                                    WACContactField,
                                                    ABI::Windows::ApplicationModel::Contacts::ContactField*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACContactInformation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactInformation*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactInformation*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactInformation*>,
                                                    WACContactInformation,
                                                    ABI::Windows::ApplicationModel::Contacts::ContactInformation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACContactInstantMessageField_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactInstantMessageField*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactInstantMessageField*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactInstantMessageField*>,
                                                    WACContactInstantMessageField,
                                                    ABI::Windows::ApplicationModel::Contacts::ContactInstantMessageField*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACContactList_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactList*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactList*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactList*>,
                                                    WACContactList,
                                                    ABI::Windows::ApplicationModel::Contacts::ContactList*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACContactLocationField_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactLocationField*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactLocationField*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactLocationField*>,
                                                    WACContactLocationField,
                                                    ABI::Windows::ApplicationModel::Contacts::ContactLocationField*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WACContactMatchReason_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactMatchReason*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactMatchReason*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Contacts::ContactMatchReason*>,
                                                    WACContactMatchReason,
                                                    ABI::Windows::ApplicationModel::Contacts::ContactMatchReason*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDTTextSegment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Data::Text::TextSegment>,
                                                                             RTArrayObj<ABI::Windows::Data::Text::TextSegment,
                                                                                        IVectorView<ABI::Windows::Data::Text::TextSegment>,
                                                                                        WDTTextSegment,
                                                                                        ABI::Windows::Data::Text::TextSegment,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WACIContactField_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::IContactField*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactField*,
                                                                  IVector<ABI::Windows::ApplicationModel::Contacts::IContactField*>,
                                                                  RTObject<WACIContactField>,
                                                                  ABI::Windows::ApplicationModel::Contacts::IContactField*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContact_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::Contact*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContact*,
                                                                  IVector<ABI::Windows::ApplicationModel::Contacts::Contact*>,
                                                                  WACContact,
                                                                  ABI::Windows::ApplicationModel::Contacts::Contact*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContactAddress_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::ContactAddress*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactAddress*,
                                                                  IVector<ABI::Windows::ApplicationModel::Contacts::ContactAddress*>,
                                                                  WACContactAddress,
                                                                  ABI::Windows::ApplicationModel::Contacts::ContactAddress*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContactConnectedServiceAccount_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount*>,
                               RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactConnectedServiceAccount*,
                                                 IVector<ABI::Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount*>,
                                                 WACContactConnectedServiceAccount,
                                                 ABI::Windows::ApplicationModel::Contacts::ContactConnectedServiceAccount*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContactDate_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::ContactDate*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactDate*,
                                                                  IVector<ABI::Windows::ApplicationModel::Contacts::ContactDate*>,
                                                                  WACContactDate,
                                                                  ABI::Windows::ApplicationModel::Contacts::ContactDate*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContactEmail_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::ContactEmail*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactEmail*,
                                                                  IVector<ABI::Windows::ApplicationModel::Contacts::ContactEmail*>,
                                                                  WACContactEmail,
                                                                  ABI::Windows::ApplicationModel::Contacts::ContactEmail*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContactFieldType_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::ContactFieldType>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::ContactFieldType,
                                                                  IVector<ABI::Windows::ApplicationModel::Contacts::ContactFieldType>,
                                                                  WACContactFieldType,
                                                                  ABI::Windows::ApplicationModel::Contacts::ContactFieldType,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContactJobInfo_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::ContactJobInfo*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactJobInfo*,
                                                                  IVector<ABI::Windows::ApplicationModel::Contacts::ContactJobInfo*>,
                                                                  WACContactJobInfo,
                                                                  ABI::Windows::ApplicationModel::Contacts::ContactJobInfo*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContactPhone_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::ContactPhone*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactPhone*,
                                                                  IVector<ABI::Windows::ApplicationModel::Contacts::ContactPhone*>,
                                                                  WACContactPhone,
                                                                  ABI::Windows::ApplicationModel::Contacts::ContactPhone*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContactSignificantOther_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::ContactSignificantOther*>,
                               RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactSignificantOther*,
                                                 IVector<ABI::Windows::ApplicationModel::Contacts::ContactSignificantOther*>,
                                                 WACContactSignificantOther,
                                                 ABI::Windows::ApplicationModel::Contacts::ContactSignificantOther*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WACContactWebsite_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Contacts::ContactWebsite*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::Contacts::IContactWebsite*,
                                                                  IVector<ABI::Windows::ApplicationModel::Contacts::ContactWebsite*>,
                                                                  WACContactWebsite,
                                                                  ABI::Windows::ApplicationModel::Contacts::ContactWebsite*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
