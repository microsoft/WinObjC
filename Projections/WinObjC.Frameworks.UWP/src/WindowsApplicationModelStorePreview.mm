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

// WindowsApplicationModelStorePreview.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Store.Preview.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelStorePreview.h"
#include "WindowsApplicationModelStorePreview_priv.h"

@implementation WASPStorePreviewSkuInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)productId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)skuId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SkuId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)skuType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SkuType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)customDeveloperData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomDeveloperData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)currencyCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrencyCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formattedListPrice {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_FormattedListPrice(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)extendedData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WASPStorePreviewPurchaseResults

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASPStorePreviewProductPurchaseStatus)productPurchaseStatus {
    ABI::Windows::ApplicationModel::Store::Preview::StorePreviewProductPurchaseStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductPurchaseStatus(&unmarshalledReturn));
    return (WASPStorePreviewProductPurchaseStatus)unmarshalledReturn;
}

@end

@implementation WASPStorePreviewProductInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)productId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)productType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WASPStorePreviewSkuInfo* */)skuInfoList {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SkuInfoList(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WASPStorePreviewSkuInfo_create(unmarshalledReturn.Get());
}

@end

@implementation WASPStoreHardwareManufacturerInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)hardwareManufacturerId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareManufacturerId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)storeContentModifierId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_StoreContentModifierId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)modelName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ModelName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)manufacturerName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ManufacturerName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WASPStorePreview

ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStorePreview> WASPIStorePreview_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStorePreview> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Store.Preview.StorePreview").Get(),
                                                       &inst));
    return inst;
}

+ (void)requestProductPurchaseByProductIdAndSkuIdAsync:(NSString*)productId
                                                 skuId:(NSString*)skuId
                                               success:(void (^)(WASPStorePreviewPurchaseResults*))success
                                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults*>>
        unmarshalledReturn;
    auto _comInst = WASPIStorePreview_inst();
    THROW_NS_IF_FAILED(_comInst->RequestProductPurchaseByProductIdAndSkuIdAsync(nsStrToHstr(productId).Get(),
                                                                                nsStrToHstr(skuId).Get(),
                                                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewPurchaseResults*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewPurchaseResults> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPStorePreviewPurchaseResults>(result.Get()));
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

+ (void)loadAddOnProductInfosAsyncWithSuccess:(void (^)(NSArray* /* WASPStorePreviewProductInfo* */))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<
        ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo*>*>>
        unmarshalledReturn;
    auto _comInst = WASPIStorePreview_inst();
    THROW_NS_IF_FAILED(_comInst->LoadAddOnProductInfosAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WASPStorePreviewProductInfo_create(result.Get()));
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

@implementation WASPStoreConfiguration

ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics> WASPIStoreConfigurationStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Store.Preview.StoreConfiguration").Get(), &inst));
    return inst;
}

+ (void)setSystemConfiguration:(NSString*)catalogHardwareManufacturerId
    catalogStoreContentModifierId:(NSString*)catalogStoreContentModifierId
    systemConfigurationExpiration:(WFDateTime*)systemConfigurationExpiration
        catalogHardwareDescriptor:(NSString*)catalogHardwareDescriptor {
    auto _comInst = WASPIStoreConfigurationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetSystemConfiguration(nsStrToHstr(catalogHardwareManufacturerId).Get(),
                                                        nsStrToHstr(catalogStoreContentModifierId).Get(),
                                                        *[systemConfigurationExpiration internalStruct],
                                                        nsStrToHstr(catalogHardwareDescriptor).Get()));
}

+ (void)setMobileOperatorConfiguration:(NSString*)mobileOperatorId
           appDownloadLimitInMegabytes:(unsigned int)appDownloadLimitInMegabytes
        updateDownloadLimitInMegabytes:(unsigned int)updateDownloadLimitInMegabytes {
    auto _comInst = WASPIStoreConfigurationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetMobileOperatorConfiguration(nsStrToHstr(mobileOperatorId).Get(),
                                                                appDownloadLimitInMegabytes,
                                                                updateDownloadLimitInMegabytes));
}

+ (void)setStoreWebAccountId:(NSString*)webAccountId {
    auto _comInst = WASPIStoreConfigurationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetStoreWebAccountId(nsStrToHstr(webAccountId).Get()));
}

+ (BOOL)isStoreWebAccountId:(NSString*)webAccountId {
    boolean unmarshalledReturn;
    auto _comInst = WASPIStoreConfigurationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsStoreWebAccountId(nsStrToHstr(webAccountId).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WASPStoreHardwareManufacturerInfo*)hardwareManufacturerInfo {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreHardwareManufacturerInfo> unmarshalledReturn;
    auto _comInst = WASPIStoreConfigurationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HardwareManufacturerInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASPStoreHardwareManufacturerInfo>(unmarshalledReturn.Get());
}

+ (void)filterUnsupportedSystemFeaturesAsync:(id<NSFastEnumeration> /* WASPStoreSystemFeature */)systemFeatures
                                     success:(void (^)(NSArray* /* WASPStoreSystemFeature */))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>*>>
        unmarshalledReturn;
    auto _comInst = WASPIStoreConfigurationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FilterUnsupportedSystemFeaturesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>::type>*>(
            ConvertToIterable<WASPStoreSystemFeature, ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>(systemFeatures)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WASPStoreSystemFeature_create(result.Get()));
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

ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3> WASPIStoreConfigurationStatics3_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Store.Preview.StoreConfiguration").Get(), &inst));
    return inst;
}

+ (BOOL)hasStoreWebAccount {
    boolean unmarshalledReturn;
    auto _comInst = WASPIStoreConfigurationStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->HasStoreWebAccount(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)hasStoreWebAccountForUser:(WSUser*)user {
    boolean unmarshalledReturn;
    auto _comInst = WASPIStoreConfigurationStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->HasStoreWebAccountForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)getStoreLogDataAsync:(WASPStoreLogOptions)options
                     success:(void (^)(RTObject<WSSIRandomAccessStreamReference>*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamReference*>> unmarshalledReturn;
    auto _comInst = WASPIStoreConfigurationStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStoreLogDataAsync((ABI::Windows::ApplicationModel::Store::Preview::StoreLogOptions)options, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStreamReference*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamReference*>* op,
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
                            successRc(_createRtProxy<WSSIRandomAccessStreamReference>(result.Get()));
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

+ (void)setStoreWebAccountIdForUser:(WSUser*)user webAccountId:(NSString*)webAccountId {
    auto _comInst = WASPIStoreConfigurationStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStoreWebAccountIdForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), nsStrToHstr(webAccountId).Get()));
}

+ (BOOL)isStoreWebAccountIdForUser:(WSUser*)user webAccountId:(NSString*)webAccountId {
    boolean unmarshalledReturn;
    auto _comInst = WASPIStoreConfigurationStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->IsStoreWebAccountIdForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                            nsStrToHstr(webAccountId).Get(),
                                                            &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (id /* unsigned int */)getPurchasePromptingPolicyForUser:(WSUser*)user {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = WASPIStoreConfigurationStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GetPurchasePromptingPolicyForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                   unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

+ (void)setPurchasePromptingPolicyForUser:(WSUser*)user value:(id /* unsigned int */)value {
    auto _comInst = WASPIStoreConfigurationStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->SetPurchasePromptingPolicyForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                   BuildNullable<unsigned int>(value)));
}

ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2> WASPIStoreConfigurationStatics2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Store.Preview.StoreConfiguration").Get(), &inst));
    return inst;
}

+ (id /* unsigned int */)purchasePromptingPolicy {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = WASPIStoreConfigurationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PurchasePromptingPolicy(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

+ (void)setPurchasePromptingPolicy:(id /* unsigned int */)value {
    auto _comInst = WASPIStoreConfigurationStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->put_PurchasePromptingPolicy(BuildNullable<unsigned int>(value)));
}

@end

id RTProxiedIterableNSArray_WASPStoreSystemFeature_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>,
                                RTIterableObj<ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature,
                                              IIterable<ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>,
                                              WASPStoreSystemFeature,
                                              ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WASPStorePreviewProductInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewProductInfo*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo*>,
                                                    WASPStorePreviewProductInfo,
                                                    ABI::Windows::ApplicationModel::Store::Preview::StorePreviewProductInfo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WASPStorePreviewSkuInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Store::Preview::IStorePreviewSkuInfo*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo*>,
                                                    WASPStorePreviewSkuInfo,
                                                    ABI::Windows::ApplicationModel::Store::Preview::StorePreviewSkuInfo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WASPStoreSystemFeature_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature,
                                                    IVectorView<ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature>,
                                                    WASPStoreSystemFeature,
                                                    ABI::Windows::ApplicationModel::Store::Preview::StoreSystemFeature,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
