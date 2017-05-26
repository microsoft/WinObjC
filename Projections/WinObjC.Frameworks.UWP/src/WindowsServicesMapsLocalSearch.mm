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

// WindowsServicesMapsLocalSearch.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Services.Maps.LocalSearch.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsServicesMapsLocalSearch.h"
#include "WindowsServicesMapsLocalSearch_priv.h"

@implementation WSMLLocalLocation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSMMapAddress*)address {
    ComPtr<ABI::Windows::Services::Maps::IMapAddress> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMMapAddress>(unmarshalledReturn.Get());
}

- (NSString*)identifier {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Identifier(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDGGeopoint*)point {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (NSString*)phoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)dataAttribution {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataAttribution(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)category {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Category(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSMLLocalLocationRatingInfo*)ratingInfo {
    ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RatingInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMLLocalLocationRatingInfo>(unmarshalledReturn.Get());
}

- (NSArray* /* WSMLLocalLocationHoursOfOperationItem* */)hoursOfOperation {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_HoursOfOperation(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMLLocalLocationHoursOfOperationItem_create(unmarshalledReturn.Get());
}

@end

@implementation WSMLLocalLocationFinderResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WSMLLocalLocation* */)localLocations {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalLocations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMLLocalLocation_create(unmarshalledReturn.Get());
}

- (WSMLLocalLocationFinderStatus)status {
    ABI::Windows::Services::Maps::LocalSearch::LocalLocationFinderStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSMLLocalLocationFinderStatus)unmarshalledReturn;
}

@end

@implementation WSMLLocalLocationRatingInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* double */)aggregateRating {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AggregateRating(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (id /* int */)ratingCount {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_RatingCount(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (NSString*)providerIdentifier {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderIdentifier(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSMLLocalLocationHoursOfOperationItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGDayOfWeek)day {
    ABI::Windows::Globalization::DayOfWeek unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Day(&unmarshalledReturn));
    return (WGDayOfWeek)unmarshalledReturn;
}

- (WFTimeSpan*)start {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Start(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)span {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Span(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WSMLLocalLocationFinder

ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationFinderStatics> WSMLILocalLocationFinderStatics_inst() {
    ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationFinderStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Services.Maps.LocalSearch.LocalLocationFinder").Get(), &inst));
    return inst;
}

+ (void)findLocalLocationsAsync:(NSString*)searchTerm
                     searchArea:(WDGGeocircle*)searchArea
                  localCategory:(NSString*)localCategory
                     maxResults:(unsigned int)maxResults
                        success:(void (^)(WSMLLocalLocationFinderResult*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::LocalSearch::LocalLocationFinderResult*>>
        unmarshalledReturn;
    auto _comInst = WSMLILocalLocationFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindLocalLocationsAsync(nsStrToHstr(searchTerm).Get(),
                                                         _getRtInterface<ABI::Windows::Devices::Geolocation::IGeocircle>(searchArea).Get(),
                                                         nsStrToHstr(localCategory).Get(),
                                                         maxResults,
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::LocalSearch::LocalLocationFinderResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::LocalSearch::LocalLocationFinderResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSMLLocalLocationFinderResult>(result.Get()));
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

@implementation WSMLLocalCategories

ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalCategoriesStatics> WSMLILocalCategoriesStatics_inst() {
    ComPtr<ABI::Windows::Services::Maps::LocalSearch::ILocalCategoriesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.LocalSearch.LocalCategories").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)bankAndCreditUnions {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMLILocalCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BankAndCreditUnions(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)eatDrink {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMLILocalCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EatDrink(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hospitals {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMLILocalCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Hospitals(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hotelsAndMotels {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMLILocalCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HotelsAndMotels(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)all {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMLILocalCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_All(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)parking {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMLILocalCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Parking(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)seeDo {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMLILocalCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SeeDo(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)shop {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMLILocalCategoriesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Shop(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedNSArray_WSMLLocalLocation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocation*>,
                                         RTArrayObj<ABI::Windows::Services::Maps::LocalSearch::ILocalLocation*,
                                                    IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocation*>,
                                                    WSMLLocalLocation,
                                                    ABI::Windows::Services::Maps::LocalSearch::LocalLocation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSMLLocalLocationHoursOfOperationItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem*>,
                        RTArrayObj<ABI::Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem*,
                                   IVectorView<ABI::Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem*>,
                                   WSMLLocalLocationHoursOfOperationItem,
                                   ABI::Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
