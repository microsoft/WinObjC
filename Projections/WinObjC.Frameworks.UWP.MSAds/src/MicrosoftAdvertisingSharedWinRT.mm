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

// MicrosoftAdvertisingSharedWinRT.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Microsoft.Advertising.Shared.WinRT.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "MicrosoftAdvertisingSharedWinRT.h"
#include "MicrosoftAdvertisingSharedWinRT_priv.h"

@implementation MASWAdvertisement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdvertisementPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.Advertisement").Get(), &out));
    return [_createRtProxy<MASWAdvertisement>(out.Get()) retain];
}

- (NSString*)guid {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdvertisementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Guid(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)payloadContent {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdvertisementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_PayloadContent(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isPoly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdvertisementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPoly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation MASWAdErrorEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsFactory> MASW__IAdErrorEventArgsFactory_inst() {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.AdErrorEventArgs").Get(),
                                                       &inst));
    return inst;
}

+ (MASWAdErrorEventArgs*)makeInstance1:(NSString*)msg code:(NSString*)code {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MASW__IAdErrorEventArgsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance1(nsStrToHstr(msg).Get(), nsStrToHstr(code).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<MASWAdErrorEventArgs>(unmarshalledReturn.Get()) retain];
}

- (NSString*)errorMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)errorCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (MAErrorCode)errorCodeEnum {
    ABI::Microsoft::Advertising::ErrorCode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCodeEnum(&unmarshalledReturn));
    return (MAErrorCode)unmarshalledReturn;
}

@end

@implementation MASWAdTagCollection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.AdTagCollection").Get(), &out));
    return [_createRtProxy<MASWAdTagCollection>(out.Get()) retain];
}

- (void)addAdTag:(NSString*)tagName tagValue:(NSString*)tagValue {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->AddAdTag(nsStrToHstr(tagName).Get(), nsStrToHstr(tagValue).Get()));
}

- (void)removeAdTag:(NSString*)tagName {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAdTag(nsStrToHstr(tagName).Get()));
}

- (void)clearAdTags {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->ClearAdTags());
}

- (NSString*)getAdTagsJson {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->GetAdTagsJson(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSMutableDictionary* /* NSString *, NSString * */)getAdTags {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->GetAdTags(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation MASWProjectedContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedContextPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.ProjectedContext").Get(), &out));
    return [_createRtProxy<MASWProjectedContext>(out.Get()) retain];
}

- (MASWProjectedIAdLogger*)getLogger {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedIAdLoggerPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedContextPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->GetLogger(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<MASWProjectedIAdLogger>(unmarshalledReturn.Get());
}

@end

@implementation MASWAdPlacement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementFactory> MASW__IAdPlacementFactory_inst() {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.AdPlacement").Get(),
                                                       &inst));
    return inst;
}

+ (MASWAdPlacement*)makeInstance3:(MASWSdkType)sdkType {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MASW__IAdPlacementFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance3((ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<MASWAdPlacement>(unmarshalledReturn.Get()) retain];
}

+ (MASWAdPlacement*)makeInstance2:(MASWSdkType)sdkType serviceUrl:(NSString*)serviceUrl {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MASW__IAdPlacementFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance2((ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType,
                                                 nsStrToHstr(serviceUrl).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<MASWAdPlacement>(unmarshalledReturn.Get()) retain];
}

+ (MASWAdPlacement*)makeInstance1:(MASWSdkType)sdkType applicationId:(NSString*)applicationId adUnitId:(NSString*)adUnitId {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MASW__IAdPlacementFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance1((ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType,
                                                 nsStrToHstr(applicationId).Get(),
                                                 nsStrToHstr(adUnitId).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<MASWAdPlacement>(unmarshalledReturn.Get()) retain];
}

- (NSString*)applicationId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setApplicationId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_ApplicationId(nsStrToHstr(value).Get()));
}

- (NSString*)adUnitId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdUnitId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAdUnitId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_AdUnitId(nsStrToHstr(value).Get()));
}

- (NSString*)serviceUrl {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceUrl(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setServiceUrl:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_ServiceUrl(nsStrToHstr(value).Get()));
}

- (MASWAdTagCollection*)adTags {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdTags(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<MASWAdTagCollection>(unmarshalledReturn.Get());
}

- (void)setAdTags:(MASWAdTagCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_AdTags(
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals>(value).Get()));
}

- (MASWAdErrorEventArgs*)lastError {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastError(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<MASWAdErrorEventArgs>(unmarshalledReturn.Get());
}

- (int)width {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setWidth:(int)__set_formal {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_Width(__set_formal));
}

- (int)height {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHeight:(int)__set_formal {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_Height(__set_formal));
}

- (NSString*)keywords {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Keywords(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setKeywords:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_Keywords(nsStrToHstr(value).Get()));
}

- (NSString*)countryOrRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_CountryOrRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCountryOrRegion:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_CountryOrRegion(nsStrToHstr(value).Get()));
}

- (NSString*)postalCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostalCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPostalCode:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->put_PostalCode(nsStrToHstr(value).Get()));
}

- (MASWSdkType)sdkType {
    ABI::Microsoft::Advertising::Shared::WinRT::SdkType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_SdkType(&unmarshalledReturn));
    return (MASWSdkType)unmarshalledReturn;
}

- (void)getAdAsync1:(unsigned int)timeoutInMilliseconds success:(void (^)(MASWAdvertisement*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::Advertisement*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->GetAdAsync1(timeoutInMilliseconds, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Microsoft::Advertising::Shared::WinRT::Advertisement*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::Advertisement*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdvertisementPublicNonVirtuals> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<MASWAdvertisement>(result.Get()));
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

- (void)reportEvent:(NSString*)eventName {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->ReportEvent(nsStrToHstr(eventName).Get()));
}

- (void)clearLastError {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->ClearLastError());
}

@end

@implementation MASWVideoResource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)delivery {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delivery(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)apiFramework {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApiFramework(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)uri {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)codec {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Codec(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)bitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)minBitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinBitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)maxBitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxBitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)maintainAspect {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaintainAspect(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)scalable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scalable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation MASWAdExtension

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdExtensionPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdExtensionFactory> MASW__IAdExtensionFactory_inst() {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdExtensionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.AdExtension").Get(),
                                                       &inst));
    return inst;
}

+ (MASWAdExtension*)makeInstance1:(NSString*)type xmlData:(NSString*)xmlData {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdExtensionPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MASW__IAdExtensionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance1(nsStrToHstr(type).Get(), nsStrToHstr(xmlData).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<MASWAdExtension>(unmarshalledReturn.Get()) retain];
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdExtensionPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)xmlData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdExtensionPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_XmlData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)jsonData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdExtensionPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_JsonData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation MASWActivityReporter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IActivityReporterPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)reportAsync2:(NSString*)activity
              macros:(NSDictionary* /* NSString *, NSString * */)macros
             success:(void (^)(unsigned int))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IActivityReporterPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportAsync2(nsStrToHstr(activity).Get(),
                               static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                                                    typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                   ConvertToMapView<NSString, HSTRING, NSString, HSTRING>(macros).Get()),
                               &unmarshalledReturn));

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

- (void)reportAsync1:(NSString*)activity
              macros:(NSDictionary* /* NSString *, RTObject* */)macros
             success:(void (^)(unsigned int))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IActivityReporterPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->ReportAsync1(
        nsStrToHstr(activity).Get(),
        static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                             typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                 ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>::type>*>(
            ConvertToMapView<NSString, HSTRING, RTObject, ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>(
                macros)
                .Get()),
        &unmarshalledReturn));

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

@end

@implementation MASWAdPackage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* MASWVideoResource* */)video {
    ComPtr<IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::VideoResource*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Video(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_MASWVideoResource_create(unmarshalledReturn.Get());
}

- (NSArray* /* MASWAdExtension* */)adExtensions {
    ComPtr<IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::AdExtension*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdExtensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_MASWAdExtension_create(unmarshalledReturn.Get());
}

- (NSString*)duration {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)adParameters {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdParameters(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)skipOffset {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_SkipOffset(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)clickThroughUrl {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClickThroughUrl(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)reportAsync3:(NSString*)activity success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->ReportAsync3(nsStrToHstr(activity).Get(), &unmarshalledReturn));

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

- (void)reportAsync2:(NSString*)activity
              macros:(NSDictionary* /* NSString *, NSString * */)macros
             success:(void (^)(unsigned int))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportAsync2(nsStrToHstr(activity).Get(),
                               static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                                                    typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                   ConvertToMapView<NSString, HSTRING, NSString, HSTRING>(macros).Get()),
                               &unmarshalledReturn));

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

- (void)reportAsync1:(NSString*)activity
              macros:(NSDictionary* /* NSString *, RTObject* */)macros
             success:(void (^)(unsigned int))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->ReportAsync1(
        nsStrToHstr(activity).Get(),
        static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                             typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                 ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>::type>*>(
            ConvertToMapView<NSString, HSTRING, RTObject, ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>(
                macros)
                .Get()),
        &unmarshalledReturn));

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

@end

@implementation MASWAdPod

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPodPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)time {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPodPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Time(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPodPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)repeatAfter {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPodPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_RepeatAfter(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* MASWAdPackage* */)packages {
    ComPtr<IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::AdPackage*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPodPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Packages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_MASWAdPackage_create(unmarshalledReturn.Get());
}

- (void)reportAsync3:(NSString*)activity success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPodPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->ReportAsync3(nsStrToHstr(activity).Get(), &unmarshalledReturn));

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

- (void)reportAsync2:(NSString*)activity
              macros:(NSDictionary* /* NSString *, NSString * */)macros
             success:(void (^)(unsigned int))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPodPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportAsync2(nsStrToHstr(activity).Get(),
                               static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                                                    typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                   ConvertToMapView<NSString, HSTRING, NSString, HSTRING>(macros).Get()),
                               &unmarshalledReturn));

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

- (void)reportAsync1:(NSString*)activity
              macros:(NSDictionary* /* NSString *, RTObject* */)macros
             success:(void (^)(unsigned int))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPodPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->ReportAsync1(
        nsStrToHstr(activity).Get(),
        static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                             typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                 ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>::type>*>(
            ConvertToMapView<NSString, HSTRING, RTObject, ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>(
                macros)
                .Get()),
        &unmarshalledReturn));

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

@end

@implementation MASWAdSchedule

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdSchedulePublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* MASWAdPod* */)pods {
    ComPtr<IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::AdPod*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdSchedulePublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pods(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_MASWAdPod_create(unmarshalledReturn.Get());
}

@end

@implementation MASWProjectedMediaConstraints

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsFactory>
MASW__IProjectedMediaConstraintsFactory_inst() {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.ProjectedMediaConstraints").Get(), &inst));
    return inst;
}

+ (MASWProjectedMediaConstraints*)makeInstance1:(NSArray* /* NSString * */)supportedMimeTypes {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MASW__IProjectedMediaConstraintsFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance1(static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                      ConvertToVectorView<NSString, HSTRING>(supportedMimeTypes).Get()),
                                  unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<MASWProjectedMediaConstraints>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsStatics> MASW__IProjectedMediaConstraintsStatics_inst() {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.ProjectedMediaConstraints").Get(), &inst));
    return inst;
}

+ (MASWProjectedMediaConstraints*)defaultMediaConstraints {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = MASW__IProjectedMediaConstraintsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DefaultMediaConstraints(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<MASWProjectedMediaConstraints>(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)supportedMimeTypes {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedMimeTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation MASWAdScheduleResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdScheduleResultPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (MASWAdErrorEventArgs*)error {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsPublicNonVirtuals> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdScheduleResultPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<MASWAdErrorEventArgs>(unmarshalledReturn.Get());
}

- (MASWAdSchedule*)value {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdSchedulePublicNonVirtuals> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdScheduleResultPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<MASWAdSchedule>(unmarshalledReturn.Get());
}

@end

@implementation MASWAdScheduler

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdSchedulerPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.AdScheduler").Get(), &out));
    return [_createRtProxy<MASWAdScheduler>(out.Get()) retain];
}

ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdSchedulerStatics> MASW__IAdSchedulerStatics_inst() {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdSchedulerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.AdScheduler").Get(),
                                                       &inst));
    return inst;
}

+ (void)getScheduleAsync2:(NSString*)appId
                     adId:(NSString*)adId
                timeoutMS:(unsigned int)timeoutMS
                  sdkType:(MASWSdkType)sdkType
                   adTags:(MASWAdTagCollection*)adTags
                  success:(void (^)(MASWAdScheduleResult*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>> unmarshalledReturn;
    auto _comInst = MASW__IAdSchedulerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetScheduleAsync2(
        nsStrToHstr(appId).Get(),
        nsStrToHstr(adId).Get(),
        timeoutMS,
        (ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType,
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals>(adTags).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdScheduleResultPublicNonVirtuals> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<MASWAdScheduleResult>(result.Get()));
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

+ (void)getScheduleAsync1:(NSString*)serviceUrl
                timeoutMS:(unsigned int)timeoutMS
                  sdkType:(MASWSdkType)sdkType
                  success:(void (^)(MASWAdScheduleResult*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>> unmarshalledReturn;
    auto _comInst = MASW__IAdSchedulerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetScheduleAsync1(nsStrToHstr(serviceUrl).Get(),
                                                   timeoutMS,
                                                   (ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdScheduleResultPublicNonVirtuals> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<MASWAdScheduleResult>(result.Get()));
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

+ (void)getScheduleStrictAsync4:(NSString*)appId
                           adId:(NSString*)adId
                      timeoutMS:(unsigned int)timeoutMS
                        sdkType:(MASWSdkType)sdkType
                         adTags:(MASWAdTagCollection*)adTags
               mediaConstraints:(MASWProjectedMediaConstraints*)mediaConstraints
                        success:(void (^)(MASWAdScheduleResult*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>> unmarshalledReturn;
    auto _comInst = MASW__IAdSchedulerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetScheduleStrictAsync4(
        nsStrToHstr(appId).Get(),
        nsStrToHstr(adId).Get(),
        timeoutMS,
        (ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType,
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals>(adTags).Get(),
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsPublicNonVirtuals>(mediaConstraints).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdScheduleResultPublicNonVirtuals> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<MASWAdScheduleResult>(result.Get()));
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

+ (void)getScheduleStrictAsync3:(NSString*)appId
                           adId:(NSString*)adId
                      timeoutMS:(unsigned int)timeoutMS
                        sdkType:(MASWSdkType)sdkType
                         adTags:(MASWAdTagCollection*)adTags
               projectedContext:(MASWProjectedContext*)projectedContext
               mediaConstraints:(MASWProjectedMediaConstraints*)mediaConstraints
                        success:(void (^)(MASWAdScheduleResult*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>> unmarshalledReturn;
    auto _comInst = MASW__IAdSchedulerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetScheduleStrictAsync3(
        nsStrToHstr(appId).Get(),
        nsStrToHstr(adId).Get(),
        timeoutMS,
        (ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType,
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IAdTagCollectionPublicNonVirtuals>(adTags).Get(),
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedContextPublicNonVirtuals>(projectedContext).Get(),
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsPublicNonVirtuals>(mediaConstraints).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdScheduleResultPublicNonVirtuals> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<MASWAdScheduleResult>(result.Get()));
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

+ (void)getScheduleStrictAsync2:(NSString*)serviceUrl
                      timeoutMS:(unsigned int)timeoutMS
                        sdkType:(MASWSdkType)sdkType
               mediaConstraints:(MASWProjectedMediaConstraints*)mediaConstraints
                        success:(void (^)(MASWAdScheduleResult*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>> unmarshalledReturn;
    auto _comInst = MASW__IAdSchedulerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetScheduleStrictAsync2(
        nsStrToHstr(serviceUrl).Get(),
        timeoutMS,
        (ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType,
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsPublicNonVirtuals>(mediaConstraints).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdScheduleResultPublicNonVirtuals> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<MASWAdScheduleResult>(result.Get()));
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

+ (void)getScheduleStrictAsync1:(NSString*)serviceUrl
                      timeoutMS:(unsigned int)timeoutMS
                        sdkType:(MASWSdkType)sdkType
               projectedContext:(MASWProjectedContext*)projectedContext
               mediaConstraints:(MASWProjectedMediaConstraints*)mediaConstraints
                        success:(void (^)(MASWAdScheduleResult*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>> unmarshalledReturn;
    auto _comInst = MASW__IAdSchedulerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetScheduleStrictAsync1(
        nsStrToHstr(serviceUrl).Get(),
        timeoutMS,
        (ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType,
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedContextPublicNonVirtuals>(projectedContext).Get(),
        _getRtInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsPublicNonVirtuals>(mediaConstraints).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Microsoft::Advertising::Shared::WinRT::AdScheduleResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdScheduleResultPublicNonVirtuals> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<MASWAdScheduleResult>(result.Get()));
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

@implementation MASWSdkInfoProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__ISdkInfoProviderPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.SdkInfoProvider").Get(), &out));
    return [_createRtProxy<MASWSdkInfoProvider>(out.Get()) retain];
}

ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__ISdkInfoProviderStatics> MASW__ISdkInfoProviderStatics_inst() {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__ISdkInfoProviderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.SdkInfoProvider").Get(),
                                                       &inst));
    return inst;
}

+ (MASWSdkInfo*)getSdkInfo {
    ABI::Microsoft::Advertising::Shared::WinRT::SdkInfo unmarshalledReturn;
    auto _comInst = MASW__ISdkInfoProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSdkInfo(&unmarshalledReturn));
    return MASWSdkInfo_create(unmarshalledReturn);
}

@end

@implementation MASWEventLogging

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IEventLoggingPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.EventLogging").Get(), &out));
    return [_createRtProxy<MASWEventLogging>(out.Get()) retain];
}

ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IEventLoggingStatics> MASW__IEventLoggingStatics_inst() {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IEventLoggingStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.EventLogging").Get(),
                                                       &inst));
    return inst;
}

+ (unsigned int)adRendererPageAction {
    unsigned int unmarshalledReturn;
    auto _comInst = MASW__IEventLoggingStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AdRendererPageAction(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)adRendererPageView {
    unsigned int unmarshalledReturn;
    auto _comInst = MASW__IEventLoggingStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AdRendererPageView(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation MASWProjectedIAdLogger

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedIAdLoggerPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)logError:(unsigned int)code message:(NSString*)message {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedIAdLoggerPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->LogError(code, nsStrToHstr(message).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setPublisherId:(NSString*)publisherId {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedIAdLoggerPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->SetPublisherId(nsStrToHstr(publisherId).Get()));
}

- (void)setAdUnitId:(NSString*)adUnitId {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedIAdLoggerPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->SetAdUnitId(nsStrToHstr(adUnitId).Get()));
}

- (void)setSourceUrl:(NSString*)sourceUrl {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedIAdLoggerPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->SetSourceUrl(nsStrToHstr(sourceUrl).Get()));
}

- (void)setSdkType:(MASWSdkType)sdkType {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedIAdLoggerPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->SetSdkType((ABI::Microsoft::Advertising::Shared::WinRT::SdkType)sdkType));
}

- (void)setASID:(NSString*)asid {
    auto _comInst = _getInnerInterface<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedIAdLoggerPublicNonVirtuals>(self);
    THROW_NS_IF_FAILED(_comInst->SetASID(nsStrToHstr(asid).Get()));
}

@end

@implementation MASWPlatformDependency

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IPlatformDependencyPublicNonVirtuals> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IPlatformDependencyStatics> MASW__IPlatformDependencyStatics_inst() {
    ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IPlatformDependencyStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Microsoft.Advertising.Shared.WinRT.PlatformDependency").Get(), &inst));
    return inst;
}

+ (NSString*)getBootstrapZoomStyle {
    HSTRING unmarshalledReturn;
    auto _comInst = MASW__IPlatformDependencyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetBootstrapZoomStyle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (BOOL)isMobile {
    boolean unmarshalledReturn;
    auto _comInst = MASW__IPlatformDependencyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsMobile(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isWindows {
    boolean unmarshalledReturn;
    auto _comInst = MASW__IPlatformDependencyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsWindows(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation MASWSdkInfo {
    ABI::Microsoft::Advertising::Shared::WinRT::SdkInfo structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Microsoft::Advertising::Shared::WinRT::SdkInfo)s {
    MASWSdkInfo* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Microsoft::Advertising::Shared::WinRT::SdkInfo*)internalStruct {
    return &structVal;
}
- (NSString*)sdkVersion {
    return hstrToNSStr(structVal.sdkVersion);
}
- (void)setSdkVersion:(NSString*)val {
    structVal.sdkVersion = nsStrToHstr(val).Detach();
}
- (NSString*)client {
    return hstrToNSStr(structVal.client);
}
- (void)setClient:(NSString*)val {
    structVal.client = nsStrToHstr(val).Detach();
}
- (NSString*)runtimeType {
    return hstrToNSStr(structVal.runtimeType);
}
- (void)setRuntimeType:(NSString*)val {
    structVal.runtimeType = nsStrToHstr(val).Detach();
}
@end
id RTProxiedNSArray_MASWAdExtension_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::AdExtension*>,
                                         RTArrayObj<ABI::Microsoft::Advertising::Shared::WinRT::__IAdExtensionPublicNonVirtuals*,
                                                    IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::AdExtension*>,
                                                    MASWAdExtension,
                                                    ABI::Microsoft::Advertising::Shared::WinRT::AdExtension*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_MASWAdPackage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::AdPackage*>,
                                         RTArrayObj<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPackagePublicNonVirtuals*,
                                                    IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::AdPackage*>,
                                                    MASWAdPackage,
                                                    ABI::Microsoft::Advertising::Shared::WinRT::AdPackage*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_MASWAdPod_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::AdPod*>,
                                         RTArrayObj<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPodPublicNonVirtuals*,
                                                    IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::AdPod*>,
                                                    MASWAdPod,
                                                    ABI::Microsoft::Advertising::Shared::WinRT::AdPod*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_MASWVideoResource_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::VideoResource*>,
                                         RTArrayObj<ABI::Microsoft::Advertising::Shared::WinRT::__IVideoResourcePublicNonVirtuals*,
                                                    IVectorView<ABI::Microsoft::Advertising::Shared::WinRT::VideoResource*>,
                                                    MASWVideoResource,
                                                    ABI::Microsoft::Advertising::Shared::WinRT::VideoResource*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, HSTRING>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          NSString,
                                          NSString,
                                          IMapView<HSTRING, HSTRING>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
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

id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, HSTRING>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             NSString,
                                             NSString,
                                             IMap<HSTRING, HSTRING>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
