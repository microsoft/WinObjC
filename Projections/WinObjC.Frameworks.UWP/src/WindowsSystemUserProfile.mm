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

// WindowsSystemUserProfile.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.UserProfile.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemUserProfile.h"
#include "WindowsSystemUserProfile_priv.h"

@implementation WSUAdvertisingManagerForUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::UserProfile::IAdvertisingManagerForUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)advertisingId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::UserProfile::IAdvertisingManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdvertisingId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::UserProfile::IAdvertisingManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WSUAdvertisingManager

ComPtr<ABI::Windows::System::UserProfile::IAdvertisingManagerStatics2> WSUIAdvertisingManagerStatics2_inst() {
    ComPtr<ABI::Windows::System::UserProfile::IAdvertisingManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.UserProfile.AdvertisingManager").Get(),
                                                       &inst));
    return inst;
}

+ (WSUAdvertisingManagerForUser*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::System::UserProfile::IAdvertisingManagerForUser> unmarshalledReturn;
    auto _comInst = WSUIAdvertisingManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUAdvertisingManagerForUser>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::System::UserProfile::IAdvertisingManagerStatics> WSUIAdvertisingManagerStatics_inst() {
    ComPtr<ABI::Windows::System::UserProfile::IAdvertisingManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.UserProfile.AdvertisingManager").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)advertisingId {
    HSTRING unmarshalledReturn;
    auto _comInst = WSUIAdvertisingManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AdvertisingId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSUUserProfilePersonalizationSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::UserProfile::IUserProfilePersonalizationSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::System::UserProfile::IUserProfilePersonalizationSettingsStatics> WSUIUserProfilePersonalizationSettingsStatics_inst() {
    ComPtr<ABI::Windows::System::UserProfile::IUserProfilePersonalizationSettingsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.System.UserProfile.UserProfilePersonalizationSettings").Get(), &inst));
    return inst;
}

+ (WSUUserProfilePersonalizationSettings*)current {
    ComPtr<ABI::Windows::System::UserProfile::IUserProfilePersonalizationSettings> unmarshalledReturn;
    auto _comInst = WSUIUserProfilePersonalizationSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUUserProfilePersonalizationSettings>(unmarshalledReturn.Get());
}

+ (BOOL)isSupported {
    boolean unmarshalledReturn;
    auto _comInst = WSUIUserProfilePersonalizationSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)trySetLockScreenImageAsync:(WSStorageFile*)imageFile success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::UserProfile::IUserProfilePersonalizationSettings>(self);
    THROW_NS_IF_FAILED(
        _comInst->TrySetLockScreenImageAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(imageFile).Get(), &unmarshalledReturn));

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

- (void)trySetWallpaperImageAsync:(WSStorageFile*)imageFile success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::UserProfile::IUserProfilePersonalizationSettings>(self);
    THROW_NS_IF_FAILED(
        _comInst->TrySetWallpaperImageAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(imageFile).Get(), &unmarshalledReturn));

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

@end

@implementation WSUGlobalizationPreferences

ComPtr<ABI::Windows::System::UserProfile::IGlobalizationPreferencesStatics> WSUIGlobalizationPreferencesStatics_inst() {
    ComPtr<ABI::Windows::System::UserProfile::IGlobalizationPreferencesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.UserProfile.GlobalizationPreferences").Get(),
                                                       &inst));
    return inst;
}

+ (NSArray* /* NSString * */)calendars {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = WSUIGlobalizationPreferencesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Calendars(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

+ (NSArray* /* NSString * */)clocks {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = WSUIGlobalizationPreferencesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Clocks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

+ (NSArray* /* NSString * */)currencies {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = WSUIGlobalizationPreferencesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Currencies(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

+ (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = WSUIGlobalizationPreferencesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

+ (NSString*)homeGeographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = WSUIGlobalizationPreferencesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HomeGeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WGDayOfWeek)weekStartsOn {
    ABI::Windows::Globalization::DayOfWeek unmarshalledReturn;
    auto _comInst = WSUIGlobalizationPreferencesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WeekStartsOn(&unmarshalledReturn));
    return (WGDayOfWeek)unmarshalledReturn;
}

@end

@implementation WSUFirstSignInSettings {
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
                 dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAPVIEW(
    self.comObj, RTProxiedNSDictionary_NSString_RTObject, HSTRING, HSTRING, IInspectable*, IInspectable*, NSString, RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::UserProfile::IFirstSignInSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::System::UserProfile::IFirstSignInSettingsStatics> WSUIFirstSignInSettingsStatics_inst() {
    ComPtr<ABI::Windows::System::UserProfile::IFirstSignInSettingsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.UserProfile.FirstSignInSettings").Get(),
                                                       &inst));
    return inst;
}

+ (WSUFirstSignInSettings*)getDefault {
    ComPtr<ABI::Windows::System::UserProfile::IFirstSignInSettings> unmarshalledReturn;
    auto _comInst = WSUIFirstSignInSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUFirstSignInSettings>(unmarshalledReturn.Get());
}

@end

@implementation WSUUserInformation

ComPtr<ABI::Windows::System::UserProfile::IUserInformationStatics> WSUIUserInformationStatics_inst() {
    ComPtr<ABI::Windows::System::UserProfile::IUserInformationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.UserProfile.UserInformation").Get(), &inst));
    return inst;
}

+ (BOOL)accountPictureChangeEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AccountPictureChangeEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)nameAccessAllowed {
    boolean unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NameAccessAllowed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (RTObject<WSIStorageFile>*)getAccountPicture:(WSUAccountPictureKind)kind {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetAccountPicture((ABI::Windows::System::UserProfile::AccountPictureKind)kind, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSIStorageFile>(unmarshalledReturn.Get());
}

+ (void)setAccountPictureAsync:(RTObject<WSIStorageFile>*)image
                       success:(void (^)(WSUSetAccountPictureResult))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetAccountPictureResult>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetAccountPictureAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(image).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::UserProfile::SetAccountPictureResult>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetAccountPictureResult>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::UserProfile::SetAccountPictureResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSUSetAccountPictureResult)result);
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

+ (void)setAccountPicturesAsync:(RTObject<WSIStorageFile>*)smallImage
                     largeImage:(RTObject<WSIStorageFile>*)largeImage
                          video:(RTObject<WSIStorageFile>*)video
                        success:(void (^)(WSUSetAccountPictureResult))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetAccountPictureResult>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetAccountPicturesAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(smallImage).Get(),
                                                         _getRtInterface<ABI::Windows::Storage::IStorageFile>(largeImage).Get(),
                                                         _getRtInterface<ABI::Windows::Storage::IStorageFile>(video).Get(),
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::UserProfile::SetAccountPictureResult>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetAccountPictureResult>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::UserProfile::SetAccountPictureResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSUSetAccountPictureResult)result);
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

+ (void)setAccountPictureFromStreamAsync:(RTObject<WSSIRandomAccessStream>*)image
                                 success:(void (^)(WSUSetAccountPictureResult))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetAccountPictureResult>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetAccountPictureFromStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(image).Get(),
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::UserProfile::SetAccountPictureResult>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetAccountPictureResult>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::UserProfile::SetAccountPictureResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSUSetAccountPictureResult)result);
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

+ (void)setAccountPicturesFromStreamsAsync:(RTObject<WSSIRandomAccessStream>*)smallImage
                                largeImage:(RTObject<WSSIRandomAccessStream>*)largeImage
                                     video:(RTObject<WSSIRandomAccessStream>*)video
                                   success:(void (^)(WSUSetAccountPictureResult))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetAccountPictureResult>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetAccountPicturesFromStreamsAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(smallImage).Get(),
                                                     _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(largeImage).Get(),
                                                     _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(video).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::UserProfile::SetAccountPictureResult>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetAccountPictureResult>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::UserProfile::SetAccountPictureResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSUSetAccountPictureResult)result);
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

+ (EventRegistrationToken)addAccountPictureChangedEvent:(void (^)(RTObject*, RTObject*))changeHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_AccountPictureChanged(Make<EventHandler_System_Object>(changeHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeAccountPictureChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_AccountPictureChanged(token));
}

+ (void)getDisplayNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDisplayNameAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (void)getFirstNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetFirstNameAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (void)getLastNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetLastNameAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (void)getPrincipalNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetPrincipalNameAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (void)getSessionInitiationProtocolUriAsyncWithSuccess:(void (^)(WFUri*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Uri*>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSessionInitiationProtocolUriAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Foundation::Uri*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Uri*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WFUri>(result.Get()));
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

+ (void)getDomainNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSUIUserInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDomainNameAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

@implementation WSULockScreen

ComPtr<ABI::Windows::System::UserProfile::ILockScreenStatics> WSUILockScreenStatics_inst() {
    ComPtr<ABI::Windows::System::UserProfile::ILockScreenStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.UserProfile.LockScreen").Get(), &inst));
    return inst;
}

+ (WFUri*)originalImageFile {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = WSUILockScreenStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OriginalImageFile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

+ (RTObject<WSSIRandomAccessStream>*)getImageStream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = WSUILockScreenStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetImageStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)setImageFileAsync:(RTObject<WSIStorageFile>*)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSUILockScreenStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetImageFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(value).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)setImageStreamAsync:(RTObject<WSSIRandomAccessStream>*)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSUILockScreenStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetImageStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::System::UserProfile::ILockScreenImageFeedStatics> WSUILockScreenImageFeedStatics_inst() {
    ComPtr<ABI::Windows::System::UserProfile::ILockScreenImageFeedStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.UserProfile.LockScreen").Get(), &inst));
    return inst;
}

+ (void)requestSetImageFeedAsync:(WFUri*)syndicationFeedUri
                         success:(void (^)(WSUSetImageFeedResult))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetImageFeedResult>> unmarshalledReturn;
    auto _comInst = WSUILockScreenImageFeedStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->RequestSetImageFeedAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(syndicationFeedUri).Get(),
                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::UserProfile::SetImageFeedResult>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::UserProfile::SetImageFeedResult>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::UserProfile::SetImageFeedResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSUSetImageFeedResult)result);
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

+ (BOOL)tryRemoveImageFeed {
    boolean unmarshalledReturn;
    auto _comInst = WSUILockScreenImageFeedStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryRemoveImageFeed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
