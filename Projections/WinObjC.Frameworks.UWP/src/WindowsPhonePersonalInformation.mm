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

// WindowsPhonePersonalInformation.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.PersonalInformation.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhonePersonalInformation.h"
#include "WindowsPhonePersonalInformation_priv.h"

@implementation WPPIContactInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)familyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFamilyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_FamilyName(nsStrToHstr(value).Get()));
}

- (NSString*)givenName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_GivenName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setGivenName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_GivenName(nsStrToHstr(value).Get()));
}

- (NSString*)honorificPrefix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_HonorificPrefix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHonorificPrefix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_HonorificPrefix(nsStrToHstr(value).Get()));
}

- (NSString*)honorificSuffix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_HonorificSuffix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHonorificSuffix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_HonorificSuffix(nsStrToHstr(value).Get()));
}

- (void)getDisplayPictureAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetDisplayPictureAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)setDisplayPictureAsync:(RTObject<WSSIInputStream>*)stream {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->SetDisplayPictureAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStreamReference>*)displayPicture {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayPicture(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)getPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (void)toVcardAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->ToVcardAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (void)toVcardWithOptionsAsync:(WPPVCardFormat)format
                        success:(void (^)(RTObject<WSSIRandomAccessStream>*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ToVcardWithOptionsAsync((ABI::Windows::Phone::PersonalInformation::VCardFormat)format, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

@implementation WPPIContactInformation2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactInformation2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)displayPictureDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayPictureDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setDisplayPictureDate:(WFDateTime*)returnValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayPictureDate(*[returnValue internalStruct]));
}

@end

@implementation WPPContactAddress

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactAddress> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Phone.PersonalInformation.ContactAddress").Get(), &out));
    return [_createRtProxy<WPPContactAddress>(out.Get()) retain];
}

- (NSString*)country {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Country(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCountry:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_Country(nsStrToHstr(value).Get()));
}

- (NSString*)locality {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Locality(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLocality:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_Locality(nsStrToHstr(value).Get()));
}

- (NSString*)region {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Region(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRegion:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_Region(nsStrToHstr(value).Get()));
}

- (NSString*)postalCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostalCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPostalCode:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_PostalCode(nsStrToHstr(value).Get()));
}

- (NSString*)streetAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreetAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setStreetAddress:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactAddress>(self);
    THROW_NS_IF_FAILED(_comInst->put_StreetAddress(nsStrToHstr(value).Get()));
}

@end

@implementation WPPContactInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Phone.PersonalInformation.ContactInformation").Get(), &out));
    return [_createRtProxy<WPPContactInformation>(out.Get()) retain];
}

ComPtr<ABI::Windows::Phone::PersonalInformation::IContactInformationStatics> WPPIContactInformationStatics_inst() {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactInformationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.PersonalInformation.ContactInformation").Get(), &inst));
    return inst;
}

+ (void)parseVcardAsync:(RTObject<WSSIInputStream>*)vcard
                success:(void (^)(WPPContactInformation*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::ContactInformation*>> unmarshalledReturn;
    auto _comInst = WPPIContactInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ParseVcardAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(vcard).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Phone::PersonalInformation::ContactInformation*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::ContactInformation*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactInformation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPPContactInformation>(result.Get()));
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

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)familyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFamilyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_FamilyName(nsStrToHstr(value).Get()));
}

- (NSString*)givenName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_GivenName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setGivenName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_GivenName(nsStrToHstr(value).Get()));
}

- (NSString*)honorificPrefix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_HonorificPrefix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHonorificPrefix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_HonorificPrefix(nsStrToHstr(value).Get()));
}

- (NSString*)honorificSuffix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_HonorificSuffix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHonorificSuffix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_HonorificSuffix(nsStrToHstr(value).Get()));
}

- (void)getDisplayPictureAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetDisplayPictureAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)setDisplayPictureAsync:(RTObject<WSSIInputStream>*)stream {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->SetDisplayPictureAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStreamReference>*)displayPicture {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayPicture(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)getPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (void)toVcardAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->ToVcardAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (void)toVcardWithOptionsAsync:(WPPVCardFormat)format
                        success:(void (^)(RTObject<WSSIRandomAccessStream>*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ToVcardWithOptionsAsync((ABI::Windows::Phone::PersonalInformation::VCardFormat)format, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

@implementation WPPContactStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Phone::PersonalInformation::IContactStoreStatics> WPPIContactStoreStatics_inst() {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactStoreStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.PersonalInformation.ContactStore").Get(),
                                                       &inst));
    return inst;
}

+ (void)createOrOpenAsyncWithSuccess:(void (^)(WPPContactStore*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::ContactStore*>> unmarshalledReturn;
    auto _comInst = WPPIContactStoreStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateOrOpenAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Phone::PersonalInformation::ContactStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::ContactStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPPContactStore>(result.Get()));
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

+ (void)createOrOpenWithOptionsAsync:(WPPContactStoreSystemAccessMode)access
                             sharing:(WPPContactStoreApplicationAccessMode)sharing
                             success:(void (^)(WPPContactStore*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::ContactStore*>> unmarshalledReturn;
    auto _comInst = WPPIContactStoreStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateOrOpenWithOptionsAsync((ABI::Windows::Phone::PersonalInformation::ContactStoreSystemAccessMode)access,
                                               (ABI::Windows::Phone::PersonalInformation::ContactStoreApplicationAccessMode)sharing,
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Phone::PersonalInformation::ContactStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::ContactStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPPContactStore>(result.Get()));
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

- (void)findContactByRemoteIdAsync:(NSString*)id success:(void (^)(WPPStoredContact*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::StoredContact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindContactByRemoteIdAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Phone::PersonalInformation::StoredContact*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::StoredContact*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::PersonalInformation::IStoredContact> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPPStoredContact>(result.Get()));
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

- (void)findContactByIdAsync:(NSString*)id success:(void (^)(WPPStoredContact*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::StoredContact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->FindContactByIdAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Phone::PersonalInformation::StoredContact*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::StoredContact*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::PersonalInformation::IStoredContact> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPPStoredContact>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)deleteContactAsync:(NSString*)id {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteContactAsync(nsStrToHstr(id).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WPPContactQueryResult*)createContactQueryDefault {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->CreateContactQueryDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPPContactQueryResult>(unmarshalledReturn.Get());
}

- (WPPContactQueryResult*)createContactQueryWithOptions:(WPPContactQueryOptions*)options {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->CreateContactQueryWithOptions(
        _getRtInterface<ABI::Windows::Phone::PersonalInformation::IContactQueryOptions>(options).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPPContactQueryResult>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (uint64_t)revisionNumber {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->get_RevisionNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getChangesAsync:(uint64_t)baseRevisionNumber
                success:(void (^)(NSArray* /* WPPContactChangeRecord* */))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Phone::PersonalInformation::ContactChangeRecord*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetChangesAsync(baseRevisionNumber, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Phone::PersonalInformation::ContactChangeRecord*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Phone::PersonalInformation::ContactChangeRecord*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Phone::PersonalInformation::ContactChangeRecord*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WPPContactChangeRecord_create(result.Get()));
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

- (void)loadExtendedPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->LoadExtendedPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)saveExtendedPropertiesAsync:(NSDictionary* /* NSString *, RTObject* */)data {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(self);
    THROW_NS_IF_FAILED(_comInst->SaveExtendedPropertiesAsync(
        static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                             typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                 ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>::type>*>(
            ConvertToMapView<NSString, HSTRING, RTObject, ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>(
                data)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)createMeContactAsync:(NSString*)id success:(void (^)(WPPStoredContact*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::StoredContact*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactStore2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateMeContactAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Phone::PersonalInformation::StoredContact*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::PersonalInformation::StoredContact*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::PersonalInformation::IStoredContact> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPPStoredContact>(result.Get()));
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

@implementation WPPStoredContact

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IStoredContact> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Phone::PersonalInformation::IStoredContactFactory> WPPIStoredContactFactory_inst() {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IStoredContactFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.PersonalInformation.StoredContact").Get(),
                                                       &inst));
    return inst;
}

+ (WPPStoredContact*)makeStoredContact:(WPPContactStore*)store {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IStoredContact> unmarshalledReturn;
    auto _comInst = WPPIStoredContactFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateStoredContact(_getRtInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(store).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WPPStoredContact>(unmarshalledReturn.Get()) retain];
}

+ (WPPStoredContact*)makeStoredContactFromInformation:(WPPContactStore*)store contact:(WPPContactInformation*)contact {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IStoredContact> unmarshalledReturn;
    auto _comInst = WPPIStoredContactFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateStoredContactFromInformation(
        _getRtInterface<ABI::Windows::Phone::PersonalInformation::IContactStore>(store).Get(),
        _getRtInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(contact).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WPPStoredContact>(unmarshalledReturn.Get()) retain];
}

- (WPPContactStore*)store {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactStore> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IStoredContact>(self);
    THROW_NS_IF_FAILED(_comInst->get_Store(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPPContactStore>(unmarshalledReturn.Get());
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IStoredContact>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IStoredContact>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IStoredContact>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteId(nsStrToHstr(value).Get()));
}

- (void)getExtendedPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IStoredContact>(self);
    THROW_NS_IF_FAILED(_comInst->GetExtendedPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)saveAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IStoredContact>(self);
    THROW_NS_IF_FAILED(_comInst->SaveAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)replaceExistingContactAsync:(NSString*)id {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IStoredContact>(self);
    THROW_NS_IF_FAILED(_comInst->ReplaceExistingContactAsync(nsStrToHstr(id).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)familyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFamilyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_FamilyName(nsStrToHstr(value).Get()));
}

- (NSString*)givenName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_GivenName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setGivenName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_GivenName(nsStrToHstr(value).Get()));
}

- (NSString*)honorificPrefix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_HonorificPrefix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHonorificPrefix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_HonorificPrefix(nsStrToHstr(value).Get()));
}

- (NSString*)honorificSuffix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_HonorificSuffix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setHonorificSuffix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->put_HonorificSuffix(nsStrToHstr(value).Get()));
}

- (void)getDisplayPictureAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetDisplayPictureAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)setDisplayPictureAsync:(RTObject<WSSIInputStream>*)stream {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->SetDisplayPictureAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStreamReference>*)displayPicture {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayPicture(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)getPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->GetPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (void)toVcardAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(_comInst->ToVcardAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (void)toVcardWithOptionsAsync:(WPPVCardFormat)format
                        success:(void (^)(RTObject<WSSIRandomAccessStream>*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ToVcardWithOptionsAsync((ABI::Windows::Phone::PersonalInformation::VCardFormat)format, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (WFDateTime*)displayPictureDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayPictureDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setDisplayPictureDate:(WFDateTime*)returnValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactInformation2>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayPictureDate(*[returnValue internalStruct]));
}

@end

@implementation WPPKnownContactProperties

ComPtr<ABI::Windows::Phone::PersonalInformation::IKnownContactPropertiesStatics> WPPIKnownContactPropertiesStatics_inst() {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IKnownContactPropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.PersonalInformation.KnownContactProperties").Get(), &inst));
    return inst;
}

+ (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)familyName {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)givenName {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GivenName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)honorificPrefix {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HonorificPrefix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)honorificSuffix {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HonorificSuffix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)additionalName {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AdditionalName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)address {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Address(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)otherAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OtherAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)email {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Email(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)workAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WorkAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)workTelephone {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WorkTelephone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)jobTitle {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JobTitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)birthdate {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Birthdate(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)anniversary {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Anniversary(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)telephone {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Telephone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mobileTelephone {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MobileTelephone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)url {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Url(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)notes {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Notes(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)workFax {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WorkFax(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)children {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Children(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)significantOther {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SignificantOther(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)companyName {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CompanyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)companyTelephone {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CompanyTelephone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)homeFax {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HomeFax(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)alternateTelephone {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlternateTelephone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)manager {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Manager(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nickname {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Nickname(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)officeLocation {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OfficeLocation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)workEmail {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WorkEmail(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)yomiGivenName {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_YomiGivenName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)yomiFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_YomiFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)yomiCompanyName {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_YomiCompanyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)otherEmail {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OtherEmail(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)alternateMobileTelephone {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlternateMobileTelephone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)alternateWorkTelephone {
    HSTRING unmarshalledReturn;
    auto _comInst = WPPIKnownContactPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlternateWorkTelephone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WPPContactQueryOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactQueryOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Phone.PersonalInformation.ContactQueryOptions").Get(),
                                              &out));
    return [_createRtProxy<WPPContactQueryOptions>(out.Get()) retain];
}

- (NSMutableArray* /* NSString * */)desiredFields {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredFields(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WPPContactQueryResultOrdering)orderBy {
    ABI::Windows::Phone::PersonalInformation::ContactQueryResultOrdering unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_OrderBy(&unmarshalledReturn));
    return (WPPContactQueryResultOrdering)unmarshalledReturn;
}

- (void)setOrderBy:(WPPContactQueryResultOrdering)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_OrderBy((ABI::Windows::Phone::PersonalInformation::ContactQueryResultOrdering)value));
}

@end

@implementation WPPContactQueryResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactQueryResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getContactCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactCountAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (void)getContactsAsyncWithSuccess:(void (^)(NSArray* /* WPPStoredContact* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WPPStoredContact_create(result.Get()));
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

- (void)getContactsAsyncInRange:(unsigned int)startIndex
               maxNumberOfItems:(unsigned int)maxNumberOfItems
                        success:(void (^)(NSArray* /* WPPStoredContact* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetContactsAsyncInRange(startIndex, maxNumberOfItems, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WPPStoredContact_create(result.Get()));
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

- (WPPContactQueryOptions*)getCurrentQueryOptions {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactQueryOptions> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentQueryOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPPContactQueryOptions>(unmarshalledReturn.Get());
}

@end

@implementation WPPContactChangeRecord

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::PersonalInformation::IContactChangeRecord> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WPPContactChangeType)changeType {
    ABI::Windows::Phone::PersonalInformation::ContactChangeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactChangeRecord>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeType(&unmarshalledReturn));
    return (WPPContactChangeType)unmarshalledReturn;
}

- (uint64_t)revisionNumber {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactChangeRecord>(self);
    THROW_NS_IF_FAILED(_comInst->get_RevisionNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactChangeRecord>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)remoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::PersonalInformation::IContactChangeRecord>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedNSArray_WPPContactChangeRecord_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Phone::PersonalInformation::ContactChangeRecord*>,
                                         RTArrayObj<ABI::Windows::Phone::PersonalInformation::IContactChangeRecord*,
                                                    IVectorView<ABI::Windows::Phone::PersonalInformation::ContactChangeRecord*>,
                                                    WPPContactChangeRecord,
                                                    ABI::Windows::Phone::PersonalInformation::ContactChangeRecord*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WPPStoredContact_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>,
                                         RTArrayObj<ABI::Windows::Phone::PersonalInformation::IStoredContact*,
                                                    IVectorView<ABI::Windows::Phone::PersonalInformation::StoredContact*>,
                                                    WPPStoredContact,
                                                    ABI::Windows::Phone::PersonalInformation::StoredContact*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
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

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, IInspectable*>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             IInspectable*,
                                             IInspectable*,
                                             NSString,
                                             RTObject,
                                             IMap<HSTRING, IInspectable*>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
