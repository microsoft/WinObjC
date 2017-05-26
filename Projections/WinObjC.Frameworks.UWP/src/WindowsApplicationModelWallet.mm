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

// WindowsApplicationModelWallet.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Wallet.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelWallet.h"
#include "WindowsApplicationModelWallet_priv.h"

@implementation WAWWalletBarcode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletBarcode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletBarcodeFactory> WAWIWalletBarcodeFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletBarcodeFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Wallet.WalletBarcode").Get(),
                                                       &inst));
    return inst;
}

+ (WAWWalletBarcode*)makeWalletBarcode:(WAWWalletBarcodeSymbology)symbology value:(NSString*)value {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletBarcode> unmarshalledReturn;
    auto _comInst = WAWIWalletBarcodeFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWalletBarcode((ABI::Windows::ApplicationModel::Wallet::WalletBarcodeSymbology)symbology,
                                                     nsStrToHstr(value).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAWWalletBarcode>(unmarshalledReturn.Get()) retain];
}

+ (WAWWalletBarcode*)makeCustomWalletBarcode:(RTObject<WSSIRandomAccessStreamReference>*)streamToBarcodeImage {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletBarcode> unmarshalledReturn;
    auto _comInst = WAWIWalletBarcodeFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCustomWalletBarcode(
        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(streamToBarcodeImage).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAWWalletBarcode>(unmarshalledReturn.Get()) retain];
}

- (WAWWalletBarcodeSymbology)symbology {
    ABI::Windows::ApplicationModel::Wallet::WalletBarcodeSymbology unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletBarcode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Symbology(&unmarshalledReturn));
    return (WAWWalletBarcodeSymbology)unmarshalledReturn;
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletBarcode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)getImageAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamReference>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamReference*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletBarcode>(self);
    THROW_NS_IF_FAILED(_comInst->GetImageAsync(&unmarshalledReturn));

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

@end

@implementation WAWWalletTransaction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Wallet.WalletTransaction").Get(), &out));
    return [_createRtProxy<WAWWalletTransaction>(out.Get()) retain];
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

- (NSString*)displayAmount {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayAmount(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayAmount:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayAmount(nsStrToHstr(value).Get()));
}

- (BOOL)ignoreTimeOfDay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->get_IgnoreTimeOfDay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIgnoreTimeOfDay:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->put_IgnoreTimeOfDay((boolean)value));
}

- (NSString*)displayLocation {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayLocation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayLocation:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayLocation(nsStrToHstr(value).Get()));
}

- (id /* WFDateTime* */)transactionDate {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransactionDate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setTransactionDate:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransactionDate(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (BOOL)isLaunchable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLaunchable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsLaunchable:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsLaunchable((boolean)value));
}

@end

@implementation WAWWalletRelevantLocation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletRelevantLocation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Wallet.WalletRelevantLocation").Get(),
                                              &out));
    return [_createRtProxy<WAWWalletRelevantLocation>(out.Get()) retain];
}

- (WDGBasicGeoposition*)position {
    ABI::Windows::Devices::Geolocation::BasicGeoposition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletRelevantLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WDGBasicGeoposition_create(unmarshalledReturn);
}

- (void)setPosition:(WDGBasicGeoposition*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletRelevantLocation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(*[value internalStruct]));
}

- (NSString*)displayMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletRelevantLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayMessage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletRelevantLocation>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayMessage(nsStrToHstr(value).Get()));
}

@end

@implementation WAWWalletItemCustomProperty

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory> WAWIWalletItemCustomPropertyFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Wallet.WalletItemCustomProperty").Get(), &inst));
    return inst;
}

+ (WAWWalletItemCustomProperty*)makeWalletItemCustomProperty:(NSString*)name value:(NSString*)value {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty> unmarshalledReturn;
    auto _comInst = WAWIWalletItemCustomPropertyFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWalletItemCustomProperty(nsStrToHstr(name).Get(), nsStrToHstr(value).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAWWalletItemCustomProperty>(unmarshalledReturn.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(nsStrToHstr(value).Get()));
}

- (BOOL)autoDetectLinks {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoDetectLinks(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoDetectLinks:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoDetectLinks((boolean)value));
}

- (WAWWalletDetailViewPosition)detailViewPosition {
    ABI::Windows::ApplicationModel::Wallet::WalletDetailViewPosition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->get_DetailViewPosition(&unmarshalledReturn));
    return (WAWWalletDetailViewPosition)unmarshalledReturn;
}

- (void)setDetailViewPosition:(WAWWalletDetailViewPosition)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->put_DetailViewPosition((ABI::Windows::ApplicationModel::Wallet::WalletDetailViewPosition)value));
}

- (WAWWalletSummaryViewPosition)summaryViewPosition {
    ABI::Windows::ApplicationModel::Wallet::WalletSummaryViewPosition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->get_SummaryViewPosition(&unmarshalledReturn));
    return (WAWWalletSummaryViewPosition)unmarshalledReturn;
}

- (void)setSummaryViewPosition:(WAWWalletSummaryViewPosition)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->put_SummaryViewPosition((ABI::Windows::ApplicationModel::Wallet::WalletSummaryViewPosition)value));
}

@end

@implementation WAWWalletVerb

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletVerb> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletVerbFactory> WAWIWalletVerbFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletVerbFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Wallet.WalletVerb").Get(), &inst));
    return inst;
}

+ (WAWWalletVerb*)makeWalletVerb:(NSString*)name {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletVerb> unmarshalledReturn;
    auto _comInst = WAWIWalletVerbFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWalletVerb(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAWWalletVerb>(unmarshalledReturn.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletVerb>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletVerb>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

@end

@implementation WAWWalletItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemFactory> WAWIWalletItemFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Wallet.WalletItem").Get(), &inst));
    return inst;
}

+ (WAWWalletItem*)makeWalletItem:(WAWWalletItemKind)kind displayName:(NSString*)displayName {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItem> unmarshalledReturn;
    auto _comInst = WAWIWalletItemFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWalletItem((ABI::Windows::ApplicationModel::Wallet::WalletItemKind)kind,
                                                  nsStrToHstr(displayName).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WAWWalletItem>(unmarshalledReturn.Get()) retain];
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isAcknowledged {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAcknowledged(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsAcknowledged:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsAcknowledged((boolean)value));
}

- (NSString*)issuerDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_IssuerDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setIssuerDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_IssuerDisplayName(nsStrToHstr(value).Get()));
}

- (id /* WFDateTime* */)lastUpdated {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastUpdated(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setLastUpdated:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_LastUpdated(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (WAWWalletItemKind)kind {
    ABI::Windows::ApplicationModel::Wallet::WalletItemKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAWWalletItemKind)unmarshalledReturn;
}

- (WAWWalletBarcode*)barcode {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletBarcode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Barcode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAWWalletBarcode>(unmarshalledReturn.Get());
}

- (void)setBarcode:(WAWWalletBarcode*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Barcode(_getRtInterface<ABI::Windows::ApplicationModel::Wallet::IWalletBarcode>(value).Get()));
}

- (id /* WFDateTime* */)expirationDate {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationDate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setExpirationDate:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExpirationDate(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (RTObject<WSSIRandomAccessStreamReference>*)logo159x159 {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Logo159x159(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setLogo159x159:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Logo159x159(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)logo336x336 {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Logo336x336(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setLogo336x336:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Logo336x336(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)logo99x99 {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Logo99x99(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setLogo99x99:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_Logo99x99(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (NSString*)displayMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayMessage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayMessage(nsStrToHstr(value).Get()));
}

- (BOOL)isDisplayMessageLaunchable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDisplayMessageLaunchable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDisplayMessageLaunchable:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDisplayMessageLaunchable((boolean)value));
}

- (NSString*)logoText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_LogoText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLogoText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_LogoText(nsStrToHstr(value).Get()));
}

- (WUColor*)headerColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setHeaderColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_HeaderColor(*[value internalStruct]));
}

- (WUColor*)bodyColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_BodyColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBodyColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_BodyColor(*[value internalStruct]));
}

- (WUColor*)headerFontColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderFontColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setHeaderFontColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_HeaderFontColor(*[value internalStruct]));
}

- (WUColor*)bodyFontColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_BodyFontColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBodyFontColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_BodyFontColor(*[value internalStruct]));
}

- (RTObject<WSSIRandomAccessStreamReference>*)headerBackgroundImage {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderBackgroundImage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setHeaderBackgroundImage:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_HeaderBackgroundImage(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)bodyBackgroundImage {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_BodyBackgroundImage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setBodyBackgroundImage:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_BodyBackgroundImage(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)logoImage {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_LogoImage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setLogoImage:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_LogoImage(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)promotionalImage {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_PromotionalImage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setPromotionalImage:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_PromotionalImage(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (id /* WFDateTime* */)relevantDate {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelevantDate(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setRelevantDate:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelevantDate(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (NSString*)relevantDateDisplayMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelevantDateDisplayMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRelevantDateDisplayMessage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelevantDateDisplayMessage(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, WAWWalletTransaction* */)transactionHistory {
    ComPtr<IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletTransaction*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransactionHistory(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_WAWWalletTransaction_create(unmarshalledReturn.Get());
}

- (NSMutableDictionary* /* NSString *, WAWWalletRelevantLocation* */)relevantLocations {
    ComPtr<IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletRelevantLocation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelevantLocations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_WAWWalletRelevantLocation_create(unmarshalledReturn.Get());
}

- (BOOL)isMoreTransactionHistoryLaunchable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMoreTransactionHistoryLaunchable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsMoreTransactionHistoryLaunchable:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsMoreTransactionHistoryLaunchable((boolean)value));
}

- (NSMutableDictionary* /* NSString *, WAWWalletItemCustomProperty* */)displayProperties {
    ComPtr<IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletItemCustomProperty*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_WAWWalletItemCustomProperty_create(unmarshalledReturn.Get());
}

- (NSMutableDictionary* /* NSString *, WAWWalletVerb* */)verbs {
    ComPtr<IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletVerb*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Verbs(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_WAWWalletVerb_create(unmarshalledReturn.Get());
}

@end

@implementation WAWWalletItemStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)addAsync:(NSString*)id item:(WAWWalletItem*)item {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(_comInst->AddAsync(nsStrToHstr(id).Get(),
                                          _getRtInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(item).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(_comInst->ClearAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getWalletItemAsync:(NSString*)id success:(void (^)(WAWWalletItem*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::WalletItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetWalletItemAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Wallet::WalletItem*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::WalletItem*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAWWalletItem>(result.Get()));
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

- (void)getItemsAsyncWithSuccess:(void (^)(NSArray* /* WAWWalletItem* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAWWalletItem_create(result.Get()));
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

- (void)getItemsWithKindAsync:(WAWWalletItemKind)kind
                      success:(void (^)(NSArray* /* WAWWalletItem* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemsWithKindAsync((ABI::Windows::ApplicationModel::Wallet::WalletItemKind)kind, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAWWalletItem_create(result.Get()));
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

- (void)importItemAsync:(RTObject<WSSIRandomAccessStreamReference>*)stream
                success:(void (^)(WAWWalletItem*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::WalletItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(
        _comInst->ImportItemAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(stream).Get(),
                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Wallet::WalletItem*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::WalletItem*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAWWalletItem>(result.Get()));
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

- (RTObject<WFIAsyncAction>*)deleteAsync:(NSString*)id {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(nsStrToHstr(id).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)showAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)showItemAsync:(NSString*)id {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(_comInst->ShowItemAsync(nsStrToHstr(id).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)updateAsync:(WAWWalletItem*)item {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateAsync(_getRtInterface<ABI::Windows::ApplicationModel::Wallet::IWalletItem>(item).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAWWalletManager

ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletManagerStatics> WAWIWalletManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Wallet.WalletManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)requestStoreAsyncWithSuccess:(void (^)(WAWWalletItemStore*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::WalletItemStore*>> unmarshalledReturn;
    auto _comInst = WAWIWalletManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::Wallet::WalletItemStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Wallet::WalletItemStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAWWalletItemStore>(result.Get()));
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

id RTProxiedNSArray_WAWWalletItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Wallet::IWalletItem*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Wallet::WalletItem*>,
                                                    WAWWalletItem,
                                                    ABI::Windows::ApplicationModel::Wallet::WalletItem*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_WAWWalletItemCustomProperty_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<MutableDictionaryAdapterObj<
        IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletItemCustomProperty*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::ApplicationModel::Wallet::WalletItemCustomProperty*>>,
        RTMapObj<HSTRING,
                 HSTRING,
                 ABI::Windows::ApplicationModel::Wallet::WalletItemCustomProperty*,
                 ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomProperty*,
                 NSString,
                 WAWWalletItemCustomProperty,
                 IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletItemCustomProperty*>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_WAWWalletRelevantLocation_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<MutableDictionaryAdapterObj<
        IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletRelevantLocation*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::ApplicationModel::Wallet::WalletRelevantLocation*>>,
        RTMapObj<HSTRING,
                 HSTRING,
                 ABI::Windows::ApplicationModel::Wallet::WalletRelevantLocation*,
                 ABI::Windows::ApplicationModel::Wallet::IWalletRelevantLocation*,
                 NSString,
                 WAWWalletRelevantLocation,
                 IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletRelevantLocation*>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_WAWWalletTransaction_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<MutableDictionaryAdapterObj<
        IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletTransaction*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::ApplicationModel::Wallet::WalletTransaction*>>,
        RTMapObj<HSTRING,
                 HSTRING,
                 ABI::Windows::ApplicationModel::Wallet::WalletTransaction*,
                 ABI::Windows::ApplicationModel::Wallet::IWalletTransaction*,
                 NSString,
                 WAWWalletTransaction,
                 IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletTransaction*>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_WAWWalletVerb_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<MutableDictionaryAdapterObj<
        IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletVerb*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::ApplicationModel::Wallet::WalletVerb*>>,
        RTMapObj<HSTRING,
                 HSTRING,
                 ABI::Windows::ApplicationModel::Wallet::WalletVerb*,
                 ABI::Windows::ApplicationModel::Wallet::IWalletVerb*,
                 NSString,
                 WAWWalletVerb,
                 IMap<HSTRING, ABI::Windows::ApplicationModel::Wallet::WalletVerb*>,
                 dummyObjCCreator,
                 dummyObjCCreator,
                 dummyWRLCreator,
                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
