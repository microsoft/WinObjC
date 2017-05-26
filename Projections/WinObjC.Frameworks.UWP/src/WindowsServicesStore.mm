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

// WindowsServicesStore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Services.Store.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsServicesStore.h"
#include "WindowsServicesStore_priv.h"

@implementation WSSStoreProduct

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreProduct> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)storeId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_StoreId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)productKind {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductKind(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)hasDigitalDownload {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasDigitalDownload(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* NSString * */)keywords {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_Keywords(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSSStoreImage* */)images {
    ComPtr<IVectorView<ABI::Windows::Services::Store::StoreImage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_Images(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSSStoreImage_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSSStoreVideo* */)videos {
    ComPtr<IVectorView<ABI::Windows::Services::Store::StoreVideo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_Videos(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSSStoreVideo_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSSStoreSku* */)skus {
    ComPtr<IVectorView<ABI::Windows::Services::Store::StoreSku*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_Skus(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSSStoreSku_create(unmarshalledReturn.Get());
}

- (BOOL)isInUserCollection {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInUserCollection(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSSStorePrice*)price {
    ComPtr<ABI::Windows::Services::Store::IStorePrice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_Price(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorePrice>(unmarshalledReturn.Get());
}

- (NSString*)extendedJsonData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedJsonData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)linkUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinkUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)getIsAnySkuInstalledAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->GetIsAnySkuInstalledAsync(&unmarshalledReturn));

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

- (void)requestPurchaseAsyncWithSuccess:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPurchaseAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StorePurchaseResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStorePurchaseResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStorePurchaseResult>(result.Get()));
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

- (void)requestPurchaseWithPurchasePropertiesAsync:(WSSStorePurchaseProperties*)storePurchaseProperties
                                           success:(void (^)(WSSStorePurchaseResult*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPurchaseWithPurchasePropertiesAsync(
        _getRtInterface<ABI::Windows::Services::Store::IStorePurchaseProperties>(storePurchaseProperties).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StorePurchaseResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStorePurchaseResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStorePurchaseResult>(result.Get()));
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

- (NSString*)inAppOfferToken {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProduct>(self);
    THROW_NS_IF_FAILED(_comInst->get_InAppOfferToken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSStoreProductPagedQueryResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreProductPagedQueryResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSDictionary* /* NSString *, WSSStoreProduct* */)products {
    ComPtr<IMapView<HSTRING, ABI::Windows::Services::Store::StoreProduct*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProductPagedQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Products(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WSSStoreProduct_create(unmarshalledReturn.Get());
}

- (BOOL)hasMoreResults {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProductPagedQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasMoreResults(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProductPagedQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)getNextAsyncWithSuccess:(void (^)(WSSStoreProductPagedQueryResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductPagedQueryResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProductPagedQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetNextAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreProductPagedQueryResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductPagedQueryResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreProductPagedQueryResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreProductPagedQueryResult>(result.Get()));
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

@implementation WSSStorePurchaseProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStorePurchaseProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Services::Store::IStorePurchasePropertiesFactory> WSSIStorePurchasePropertiesFactory_inst() {
    ComPtr<ABI::Windows::Services::Store::IStorePurchasePropertiesFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Store.StorePurchaseProperties").Get(),
                                                       &inst));
    return inst;
}

+ (WSSStorePurchaseProperties*)make:(NSString*)name {
    ComPtr<ABI::Windows::Services::Store::IStorePurchaseProperties> unmarshalledReturn;
    auto _comInst = WSSIStorePurchasePropertiesFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSSStorePurchaseProperties>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Services.Store.StorePurchaseProperties").Get(), &out));
    return [_createRtProxy<WSSStorePurchaseProperties>(out.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePurchaseProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePurchaseProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)extendedJsonData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePurchaseProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedJsonData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setExtendedJsonData:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePurchaseProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExtendedJsonData(nsStrToHstr(value).Get()));
}

@end

@implementation WSSStoreLicense

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreLicense> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)skuStoreId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_SkuStoreId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isActive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDateTime*)expirationDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)extendedJsonData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedJsonData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)inAppOfferToken {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_InAppOfferToken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSStoreImage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreImage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreImage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)imagePurposeTag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreImage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImagePurposeTag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreImage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreImage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)caption {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreImage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Caption(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSStoreVideo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreVideo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreVideo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)videoPurposeTag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreVideo>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoPurposeTag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreVideo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreVideo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)caption {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreVideo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Caption(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSSStoreImage*)previewImage {
    ComPtr<ABI::Windows::Services::Store::IStoreImage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreVideo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviewImage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStoreImage>(unmarshalledReturn.Get());
}

@end

@implementation WSSStoreSku

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreSku> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)storeId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_StoreId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isTrial {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTrial(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)customDeveloperData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomDeveloperData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WSSStoreImage* */)images {
    ComPtr<IVectorView<ABI::Windows::Services::Store::StoreImage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_Images(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSSStoreImage_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSSStoreVideo* */)videos {
    ComPtr<IVectorView<ABI::Windows::Services::Store::StoreVideo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_Videos(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSSStoreVideo_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSSStoreAvailability* */)availabilities {
    ComPtr<IVectorView<ABI::Windows::Services::Store::StoreAvailability*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_Availabilities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSSStoreAvailability_create(unmarshalledReturn.Get());
}

- (WSSStorePrice*)price {
    ComPtr<ABI::Windows::Services::Store::IStorePrice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_Price(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorePrice>(unmarshalledReturn.Get());
}

- (NSString*)extendedJsonData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedJsonData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isInUserCollection {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInUserCollection(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* NSString * */)bundledSkus {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_BundledSkus(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (WSSStoreCollectionData*)collectionData {
    ComPtr<ABI::Windows::Services::Store::IStoreCollectionData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_CollectionData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStoreCollectionData>(unmarshalledReturn.Get());
}

- (void)getIsInstalledAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->GetIsInstalledAsync(&unmarshalledReturn));

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

- (void)requestPurchaseAsyncWithSuccess:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPurchaseAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StorePurchaseResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStorePurchaseResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStorePurchaseResult>(result.Get()));
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

- (void)requestPurchaseWithPurchasePropertiesAsync:(WSSStorePurchaseProperties*)storePurchaseProperties
                                           success:(void (^)(WSSStorePurchaseResult*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPurchaseWithPurchasePropertiesAsync(
        _getRtInterface<ABI::Windows::Services::Store::IStorePurchaseProperties>(storePurchaseProperties).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StorePurchaseResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStorePurchaseResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStorePurchaseResult>(result.Get()));
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

- (BOOL)isSubscription {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSubscription(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSSStoreSubscriptionInfo*)subscriptionInfo {
    ComPtr<ABI::Windows::Services::Store::IStoreSubscriptionInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSku>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubscriptionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStoreSubscriptionInfo>(unmarshalledReturn.Get());
}

@end

@implementation WSSStorePrice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStorePrice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)formattedBasePrice {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePrice>(self);
    THROW_NS_IF_FAILED(_comInst->get_FormattedBasePrice(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formattedPrice {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePrice>(self);
    THROW_NS_IF_FAILED(_comInst->get_FormattedPrice(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isOnSale {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePrice>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOnSale(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDateTime*)saleEndDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePrice>(self);
    THROW_NS_IF_FAILED(_comInst->get_SaleEndDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)currencyCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePrice>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrencyCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formattedRecurrencePrice {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePrice>(self);
    THROW_NS_IF_FAILED(_comInst->get_FormattedRecurrencePrice(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSStorePurchaseResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStorePurchaseResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSSStorePurchaseStatus)status {
    ABI::Windows::Services::Store::StorePurchaseStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePurchaseResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSSStorePurchaseStatus)unmarshalledReturn;
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePurchaseResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WSSStoreAvailability

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreAvailability> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)storeId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAvailability>(self);
    THROW_NS_IF_FAILED(_comInst->get_StoreId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)endDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAvailability>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WSSStorePrice*)price {
    ComPtr<ABI::Windows::Services::Store::IStorePrice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAvailability>(self);
    THROW_NS_IF_FAILED(_comInst->get_Price(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorePrice>(unmarshalledReturn.Get());
}

- (NSString*)extendedJsonData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAvailability>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedJsonData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)requestPurchaseAsyncWithSuccess:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAvailability>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPurchaseAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StorePurchaseResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStorePurchaseResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStorePurchaseResult>(result.Get()));
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

- (void)requestPurchaseWithPurchasePropertiesAsync:(WSSStorePurchaseProperties*)storePurchaseProperties
                                           success:(void (^)(WSSStorePurchaseResult*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAvailability>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPurchaseWithPurchasePropertiesAsync(
        _getRtInterface<ABI::Windows::Services::Store::IStorePurchaseProperties>(storePurchaseProperties).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StorePurchaseResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStorePurchaseResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStorePurchaseResult>(result.Get()));
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

@implementation WSSStoreCollectionData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreCollectionData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isTrial {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreCollectionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTrial(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)campaignId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreCollectionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_CampaignId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)developerOfferId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreCollectionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeveloperOfferId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)acquiredDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreCollectionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_AcquiredDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)startDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreCollectionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)endDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreCollectionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)trialTimeRemaining {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreCollectionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrialTimeRemaining(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSString*)extendedJsonData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreCollectionData>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedJsonData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSStoreSubscriptionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreSubscriptionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)billingPeriod {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSubscriptionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_BillingPeriod(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSSStoreDurationUnit)billingPeriodUnit {
    ABI::Windows::Services::Store::StoreDurationUnit unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSubscriptionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_BillingPeriodUnit(&unmarshalledReturn));
    return (WSSStoreDurationUnit)unmarshalledReturn;
}

- (BOOL)hasTrialPeriod {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSubscriptionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasTrialPeriod(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)trialPeriod {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSubscriptionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrialPeriod(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSSStoreDurationUnit)trialPeriodUnit {
    ABI::Windows::Services::Store::StoreDurationUnit unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSubscriptionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrialPeriodUnit(&unmarshalledReturn));
    return (WSSStoreDurationUnit)unmarshalledReturn;
}

@end

@implementation WSSStoreContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Services::Store::IStoreContextStatics> WSSIStoreContextStatics_inst() {
    ComPtr<ABI::Windows::Services::Store::IStoreContextStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Store.StoreContext").Get(), &inst));
    return inst;
}

+ (WSSStoreContext*)getDefault {
    ComPtr<ABI::Windows::Services::Store::IStoreContext> unmarshalledReturn;
    auto _comInst = WSSIStoreContextStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStoreContext>(unmarshalledReturn.Get());
}

+ (WSSStoreContext*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::Services::Store::IStoreContext> unmarshalledReturn;
    auto _comInst = WSSIStoreContextStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStoreContext>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addOfflineLicensesChangedEvent:(void (^)(WSSStoreContext*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_OfflineLicensesChanged(Make<ITypedEventHandler_Windows_Services_Store_StoreContext_System_Object>(handler).Get(),
                                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOfflineLicensesChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OfflineLicensesChanged(token));
}

- (void)getCustomerPurchaseIdAsync:(NSString*)serviceTicket
                   publisherUserId:(NSString*)publisherUserId
                           success:(void (^)(NSString*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetCustomerPurchaseIdAsync(nsStrToHstr(serviceTicket).Get(), nsStrToHstr(publisherUserId).Get(), &unmarshalledReturn));

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

- (void)getCustomerCollectionsIdAsync:(NSString*)serviceTicket
                      publisherUserId:(NSString*)publisherUserId
                              success:(void (^)(NSString*))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetCustomerCollectionsIdAsync(nsStrToHstr(serviceTicket).Get(), nsStrToHstr(publisherUserId).Get(), &unmarshalledReturn));

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

- (void)getAppLicenseAsyncWithSuccess:(void (^)(WSSStoreAppLicense*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreAppLicense*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->GetAppLicenseAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreAppLicense*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreAppLicense*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStoreAppLicense> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStoreAppLicense>(result.Get()));
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

- (void)getStoreProductForCurrentAppAsyncWithSuccess:(void (^)(WSSStoreProductResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->GetStoreProductForCurrentAppAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreProductResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStoreProductResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStoreProductResult>(result.Get()));
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

- (void)getStoreProductsAsync:(id<NSFastEnumeration> /* NSString * */)productKinds
                     storeIds:(id<NSFastEnumeration> /* NSString * */)storeIds
                      success:(void (^)(WSSStoreProductQueryResult*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductQueryResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetStoreProductsAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                            ConvertToIterable<NSString, HSTRING>(productKinds).Get()),
                                        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                            ConvertToIterable<NSString, HSTRING>(storeIds).Get()),
                                        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreProductQueryResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductQueryResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreProductQueryResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreProductQueryResult>(result.Get()));
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

- (void)getAssociatedStoreProductsAsync:(id<NSFastEnumeration> /* NSString * */)productKinds
                                success:(void (^)(WSSStoreProductQueryResult*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductQueryResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->GetAssociatedStoreProductsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(productKinds).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreProductQueryResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductQueryResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreProductQueryResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreProductQueryResult>(result.Get()));
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

- (void)getAssociatedStoreProductsWithPagingAsync:(id<NSFastEnumeration> /* NSString * */)productKinds
                        maxItemsToRetrievePerPage:(unsigned int)maxItemsToRetrievePerPage
                                          success:(void (^)(WSSStoreProductPagedQueryResult*))success
                                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductPagedQueryResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->GetAssociatedStoreProductsWithPagingAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(productKinds).Get()),
        maxItemsToRetrievePerPage,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreProductPagedQueryResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductPagedQueryResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreProductPagedQueryResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreProductPagedQueryResult>(result.Get()));
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

- (void)getUserCollectionAsync:(id<NSFastEnumeration> /* NSString * */)productKinds
                       success:(void (^)(WSSStoreProductQueryResult*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductQueryResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->GetUserCollectionAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(productKinds).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreProductQueryResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductQueryResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreProductQueryResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreProductQueryResult>(result.Get()));
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

- (void)getUserCollectionWithPagingAsync:(id<NSFastEnumeration> /* NSString * */)productKinds
               maxItemsToRetrievePerPage:(unsigned int)maxItemsToRetrievePerPage
                                 success:(void (^)(WSSStoreProductPagedQueryResult*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductPagedQueryResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->GetUserCollectionWithPagingAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(productKinds).Get()),
        maxItemsToRetrievePerPage,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreProductPagedQueryResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreProductPagedQueryResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreProductPagedQueryResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreProductPagedQueryResult>(result.Get()));
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

- (void)reportConsumableFulfillmentAsync:(NSString*)productStoreId
                                quantity:(unsigned int)quantity
                              trackingId:(WFGUID*)trackingId
                                 success:(void (^)(WSSStoreConsumableResult*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreConsumableResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportConsumableFulfillmentAsync(nsStrToHstr(productStoreId).Get(), quantity, trackingId.guidValue, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreConsumableResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreConsumableResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreConsumableResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreConsumableResult>(result.Get()));
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

- (void)getConsumableBalanceRemainingAsync:(NSString*)productStoreId
                                   success:(void (^)(WSSStoreConsumableResult*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreConsumableResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->GetConsumableBalanceRemainingAsync(nsStrToHstr(productStoreId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreConsumableResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreConsumableResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreConsumableResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreConsumableResult>(result.Get()));
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

- (void)acquireStoreLicenseForOptionalPackageAsync:(WAPackage*)optionalPackage
                                           success:(void (^)(WSSStoreAcquireLicenseResult*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreAcquireLicenseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->AcquireStoreLicenseForOptionalPackageAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::IPackage>(optionalPackage).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreAcquireLicenseResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreAcquireLicenseResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreAcquireLicenseResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreAcquireLicenseResult>(result.Get()));
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

- (void)requestPurchaseAsync:(NSString*)storeId success:(void (^)(WSSStorePurchaseResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPurchaseAsync(nsStrToHstr(storeId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StorePurchaseResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStorePurchaseResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStorePurchaseResult>(result.Get()));
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

- (void)requestPurchaseWithPurchasePropertiesAsync:(NSString*)storeId
                           storePurchaseProperties:(WSSStorePurchaseProperties*)storePurchaseProperties
                                           success:(void (^)(WSSStorePurchaseResult*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPurchaseWithPurchasePropertiesAsync(
        nsStrToHstr(storeId).Get(),
        _getRtInterface<ABI::Windows::Services::Store::IStorePurchaseProperties>(storePurchaseProperties).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StorePurchaseResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StorePurchaseResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Store::IStorePurchaseResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSStorePurchaseResult>(result.Get()));
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

- (void)getAppAndOptionalStorePackageUpdatesAsyncWithSuccess:(void (^)(NSArray* /* WSSStorePackageUpdate* */))success
                                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Services::Store::StorePackageUpdate*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->GetAppAndOptionalStorePackageUpdatesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Services::Store::StorePackageUpdate*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Services::Store::StorePackageUpdate*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Services::Store::StorePackageUpdate*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSSStorePackageUpdate_create(result.Get()));
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

- (void)requestDownloadStorePackageUpdatesAsync:(id<NSFastEnumeration> /* WSSStorePackageUpdate* */)storePackageUpdates
                                        success:(void (^)(WSSStorePackageUpdateResult*))success
                                       progress:(void (^)(WSSStorePackageUpdateStatus*))progress
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                 ABI::Windows::Services::Store::StorePackageUpdateStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->RequestDownloadStorePackageUpdatesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Services::Store::StorePackageUpdate*,
                                                              ABI::Windows::Services::Store::IStorePackageUpdate*>>::type>*>(
            ConvertToIterable<WSSStorePackageUpdate,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Services::Store::StorePackageUpdate*,
                                                                                ABI::Windows::Services::Store::IStorePackageUpdate*>>(
                storePackageUpdates)
                .Get()),
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                     ABI::Windows::Services::Store::StorePackageUpdateStatus>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                               ABI::Windows::Services::Store::StorePackageUpdateStatus>* op,
                         ABI::Windows::Services::Store::StorePackageUpdateStatus status) {
                @autoreleasepool {
                    progressRc(WSSStorePackageUpdateStatus_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                              ABI::Windows::Services::Store::StorePackageUpdateStatus>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                          ABI::Windows::Services::Store::StorePackageUpdateStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStorePackageUpdateResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStorePackageUpdateResult>(result.Get()));
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

- (void)requestDownloadAndInstallStorePackageUpdatesAsync:(id<NSFastEnumeration> /* WSSStorePackageUpdate* */)storePackageUpdates
                                                  success:(void (^)(WSSStorePackageUpdateResult*))success
                                                 progress:(void (^)(WSSStorePackageUpdateStatus*))progress
                                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                 ABI::Windows::Services::Store::StorePackageUpdateStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->RequestDownloadAndInstallStorePackageUpdatesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Services::Store::StorePackageUpdate*,
                                                              ABI::Windows::Services::Store::IStorePackageUpdate*>>::type>*>(
            ConvertToIterable<WSSStorePackageUpdate,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Services::Store::StorePackageUpdate*,
                                                                                ABI::Windows::Services::Store::IStorePackageUpdate*>>(
                storePackageUpdates)
                .Get()),
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                     ABI::Windows::Services::Store::StorePackageUpdateStatus>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                               ABI::Windows::Services::Store::StorePackageUpdateStatus>* op,
                         ABI::Windows::Services::Store::StorePackageUpdateStatus status) {
                @autoreleasepool {
                    progressRc(WSSStorePackageUpdateStatus_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                              ABI::Windows::Services::Store::StorePackageUpdateStatus>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                          ABI::Windows::Services::Store::StorePackageUpdateStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStorePackageUpdateResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStorePackageUpdateResult>(result.Get()));
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

- (void)requestDownloadAndInstallStorePackagesAsync:(id<NSFastEnumeration> /* NSString * */)storeIds
                                            success:(void (^)(WSSStorePackageUpdateResult*))success
                                           progress:(void (^)(WSSStorePackageUpdateStatus*))progress
                                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                 ABI::Windows::Services::Store::StorePackageUpdateStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreContext>(self);
    THROW_NS_IF_FAILED(_comInst->RequestDownloadAndInstallStorePackagesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(storeIds).Get()),
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                     ABI::Windows::Services::Store::StorePackageUpdateStatus>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                               ABI::Windows::Services::Store::StorePackageUpdateStatus>* op,
                         ABI::Windows::Services::Store::StorePackageUpdateStatus status) {
                @autoreleasepool {
                    progressRc(WSSStorePackageUpdateStatus_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                              ABI::Windows::Services::Store::StorePackageUpdateStatus>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Services::Store::StorePackageUpdateResult*,
                                                                          ABI::Windows::Services::Store::StorePackageUpdateStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStorePackageUpdateResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStorePackageUpdateResult>(result.Get()));
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

@implementation WSSStoreSendRequestResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreSendRequestResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)response {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSendRequestResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Response(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreSendRequestResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WSSStoreAppLicense

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreAppLicense> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)skuStoreId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAppLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_SkuStoreId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isActive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAppLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isTrial {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAppLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTrial(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDateTime*)expirationDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAppLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)extendedJsonData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAppLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedJsonData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSDictionary* /* NSString *, WSSStoreLicense* */)addOnLicenses {
    ComPtr<IMapView<HSTRING, ABI::Windows::Services::Store::StoreLicense*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAppLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_AddOnLicenses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WSSStoreLicense_create(unmarshalledReturn.Get());
}

- (WFTimeSpan*)trialTimeRemaining {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAppLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrialTimeRemaining(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (BOOL)isTrialOwnedByThisUser {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAppLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTrialOwnedByThisUser(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)trialUniqueId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAppLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrialUniqueId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSStoreProductResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreProductResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSSStoreProduct*)product {
    ComPtr<ABI::Windows::Services::Store::IStoreProduct> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProductResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Product(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStoreProduct>(unmarshalledReturn.Get());
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProductResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WSSStoreProductQueryResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreProductQueryResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSDictionary* /* NSString *, WSSStoreProduct* */)products {
    ComPtr<IMapView<HSTRING, ABI::Windows::Services::Store::StoreProduct*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProductQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Products(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WSSStoreProduct_create(unmarshalledReturn.Get());
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreProductQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WSSStoreConsumableResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreConsumableResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSSStoreConsumableStatus)status {
    ABI::Windows::Services::Store::StoreConsumableStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreConsumableResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSSStoreConsumableStatus)unmarshalledReturn;
}

- (WFGUID*)trackingId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreConsumableResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrackingId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (unsigned int)balanceRemaining {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreConsumableResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_BalanceRemaining(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreConsumableResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WSSStoreAcquireLicenseResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStoreAcquireLicenseResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSSStorePackageLicense*)storePackageLicense {
    ComPtr<ABI::Windows::Services::Store::IStorePackageLicense> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAcquireLicenseResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_StorePackageLicense(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorePackageLicense>(unmarshalledReturn.Get());
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStoreAcquireLicenseResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WSSStorePackageUpdate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStorePackageUpdate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePackageUpdate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (BOOL)mandatory {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePackageUpdate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mandatory(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSSStorePackageUpdateResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStorePackageUpdateResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSSStorePackageUpdateState)overallState {
    ABI::Windows::Services::Store::StorePackageUpdateState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePackageUpdateResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverallState(&unmarshalledReturn));
    return (WSSStorePackageUpdateState)unmarshalledReturn;
}

- (NSArray* /* WSSStorePackageUpdateStatus* */)storePackageUpdateStatuses {
    ComPtr<IVectorView<ABI::Windows::Services::Store::StorePackageUpdateStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePackageUpdateResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_StorePackageUpdateStatuses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSSStorePackageUpdateStatus_create(unmarshalledReturn.Get());
}

@end

@implementation WSSStorePackageLicense

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Store::IStorePackageLicense> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addLicenseLostEvent:(void (^)(WSSStorePackageLicense*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePackageLicense>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_LicenseLost(Make<ITypedEventHandler_Windows_Services_Store_StorePackageLicense_System_Object>(handler).Get(),
                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLicenseLostEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePackageLicense>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LicenseLost(token));
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePackageLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (BOOL)isValid {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePackageLicense>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsValid(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)releaseLicense {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Store::IStorePackageLicense>(self);
    THROW_NS_IF_FAILED(_comInst->ReleaseLicense());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSStoreRequestHelper

ComPtr<ABI::Windows::Services::Store::IStoreRequestHelperStatics> WSSIStoreRequestHelperStatics_inst() {
    ComPtr<ABI::Windows::Services::Store::IStoreRequestHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Store.StoreRequestHelper").Get(), &inst));
    return inst;
}

+ (void)sendRequestAsync:(WSSStoreContext*)context
             requestKind:(unsigned int)requestKind
        parametersAsJson:(NSString*)parametersAsJson
                 success:(void (^)(WSSStoreSendRequestResult*))success
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreSendRequestResult*>> unmarshalledReturn;
    auto _comInst = WSSIStoreRequestHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SendRequestAsync(_getRtInterface<ABI::Windows::Services::Store::IStoreContext>(context).Get(),
                                                  requestKind,
                                                  nsStrToHstr(parametersAsJson).Get(),
                                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Store::StoreSendRequestResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Store::StoreSendRequestResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Store::IStoreSendRequestResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSStoreSendRequestResult>(result.Get()));
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

@implementation WSSStorePackageUpdateStatus {
    ABI::Windows::Services::Store::StorePackageUpdateStatus structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Services::Store::StorePackageUpdateStatus)s {
    WSSStorePackageUpdateStatus* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Services::Store::StorePackageUpdateStatus*)internalStruct {
    return &structVal;
}
- (NSString*)packageFamilyName {
    return hstrToNSStr(structVal.PackageFamilyName);
}
- (void)setPackageFamilyName:(NSString*)val {
    structVal.PackageFamilyName = nsStrToHstr(val).Detach();
}
- (uint64_t)packageDownloadSizeInBytes {
    return structVal.PackageDownloadSizeInBytes;
}
- (void)setPackageDownloadSizeInBytes:(uint64_t)val {
    structVal.PackageDownloadSizeInBytes = val;
}
- (uint64_t)packageBytesDownloaded {
    return structVal.PackageBytesDownloaded;
}
- (void)setPackageBytesDownloaded:(uint64_t)val {
    structVal.PackageBytesDownloaded = val;
}
- (double)packageDownloadProgress {
    return structVal.PackageDownloadProgress;
}
- (void)setPackageDownloadProgress:(double)val {
    structVal.PackageDownloadProgress = val;
}
- (double)totalDownloadProgress {
    return structVal.TotalDownloadProgress;
}
- (void)setTotalDownloadProgress:(double)val {
    structVal.TotalDownloadProgress = val;
}
- (WSSStorePackageUpdateState)packageUpdateState {
    return (WSSStorePackageUpdateState)structVal.PackageUpdateState;
}
- (void)setPackageUpdateState:(WSSStorePackageUpdateState)val {
    structVal.PackageUpdateState = (ABI::Windows::Services::Store::StorePackageUpdateState)val;
}
@end
id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WSSStorePackageUpdate_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Services::Store::StorePackageUpdate*>,
                                                 RTIterableObj<ABI::Windows::Services::Store::IStorePackageUpdate*,
                                                               IIterable<ABI::Windows::Services::Store::StorePackageUpdate*>,
                                                               WSSStorePackageUpdate,
                                                               ABI::Windows::Services::Store::StorePackageUpdate*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSSStoreAvailability_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Store::StoreAvailability*>,
                                         RTArrayObj<ABI::Windows::Services::Store::IStoreAvailability*,
                                                    IVectorView<ABI::Windows::Services::Store::StoreAvailability*>,
                                                    WSSStoreAvailability,
                                                    ABI::Windows::Services::Store::StoreAvailability*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSSStoreImage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Store::StoreImage*>,
                                         RTArrayObj<ABI::Windows::Services::Store::IStoreImage*,
                                                    IVectorView<ABI::Windows::Services::Store::StoreImage*>,
                                                    WSSStoreImage,
                                                    ABI::Windows::Services::Store::StoreImage*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSSStorePackageUpdate_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Store::StorePackageUpdate*>,
                                         RTArrayObj<ABI::Windows::Services::Store::IStorePackageUpdate*,
                                                    IVectorView<ABI::Windows::Services::Store::StorePackageUpdate*>,
                                                    WSSStorePackageUpdate,
                                                    ABI::Windows::Services::Store::StorePackageUpdate*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSSStorePackageUpdateStatus_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Store::StorePackageUpdateStatus>,
                                         RTArrayObj<ABI::Windows::Services::Store::StorePackageUpdateStatus,
                                                    IVectorView<ABI::Windows::Services::Store::StorePackageUpdateStatus>,
                                                    WSSStorePackageUpdateStatus,
                                                    ABI::Windows::Services::Store::StorePackageUpdateStatus,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSSStoreSku_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Store::StoreSku*>,
                                         RTArrayObj<ABI::Windows::Services::Store::IStoreSku*,
                                                    IVectorView<ABI::Windows::Services::Store::StoreSku*>,
                                                    WSSStoreSku,
                                                    ABI::Windows::Services::Store::StoreSku*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSSStoreVideo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Store::StoreVideo*>,
                                         RTArrayObj<ABI::Windows::Services::Store::IStoreVideo*,
                                                    IVectorView<ABI::Windows::Services::Store::StoreVideo*>,
                                                    WSSStoreVideo,
                                                    ABI::Windows::Services::Store::StoreVideo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WSSStoreLicense_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::Services::Store::StoreLicense*>,
        DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Services::Store::StoreLicense*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::Services::Store::StoreLicense*,
                     ABI::Windows::Services::Store::IStoreLicense*,
                     NSString,
                     WSSStoreLicense,
                     IMapView<HSTRING, ABI::Windows::Services::Store::StoreLicense*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WSSStoreProduct_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::Services::Store::StoreProduct*>,
        DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Services::Store::StoreProduct*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::Services::Store::StoreProduct*,
                     ABI::Windows::Services::Store::IStoreProduct*,
                     NSString,
                     WSSStoreProduct,
                     IMapView<HSTRING, ABI::Windows::Services::Store::StoreProduct*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
