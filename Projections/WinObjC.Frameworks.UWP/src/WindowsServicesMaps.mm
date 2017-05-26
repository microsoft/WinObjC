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

// WindowsServicesMaps.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Services.Maps.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsServicesMaps.h"
#include "WindowsServicesMaps_priv.h"

@implementation WSMMapAddress

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::IMapAddress> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)buildingName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_BuildingName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)buildingFloor {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_BuildingFloor(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)buildingRoom {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_BuildingRoom(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)buildingWing {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_BuildingWing(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)streetNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreetNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)street {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Street(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)neighborhood {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Neighborhood(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)district {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_District(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)town {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Town(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)region {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Region(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)regionCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_RegionCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)country {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Country(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)countryCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_CountryCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)postCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)continent {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress>(self);
    THROW_NS_IF_FAILED(_comInst->get_Continent(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formattedAddress {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapAddress2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FormattedAddress(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSMMapLocation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::IMapLocation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGeopoint*)point {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Point(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSMMapAddress*)address {
    ComPtr<ABI::Windows::Services::Maps::IMapAddress> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMMapAddress>(unmarshalledReturn.Get());
}

@end

@implementation WSMMapRouteManeuver

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::IMapRouteManeuver> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGeopoint*)startingPoint {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartingPoint(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (double)lengthInMeters {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_LengthInMeters(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)instructionText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstructionText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSMMapRouteManeuverKind)kind {
    ABI::Windows::Services::Maps::MapRouteManeuverKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSMMapRouteManeuverKind)unmarshalledReturn;
}

- (NSString*)exitNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSMMapManeuverNotices)maneuverNotices {
    ABI::Windows::Services::Maps::MapManeuverNotices unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_ManeuverNotices(&unmarshalledReturn));
    return (WSMMapManeuverNotices)unmarshalledReturn;
}

- (double)startHeading {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteManeuver2>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartHeading(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)endHeading {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteManeuver2>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndHeading(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)streetName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteManeuver2>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreetName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSMMapRouteLeg

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::IMapRouteLeg> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGeoboundingBox*)boundingBox {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteLeg>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingBox(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get());
}

- (WDGGeopath*)path {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteLeg>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopath>(unmarshalledReturn.Get());
}

- (double)lengthInMeters {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteLeg>(self);
    THROW_NS_IF_FAILED(_comInst->get_LengthInMeters(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)estimatedDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteLeg>(self);
    THROW_NS_IF_FAILED(_comInst->get_EstimatedDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSArray* /* WSMMapRouteManeuver* */)maneuvers {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::MapRouteManeuver*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteLeg>(self);
    THROW_NS_IF_FAILED(_comInst->get_Maneuvers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMMapRouteManeuver_create(unmarshalledReturn.Get());
}

@end

@implementation WSMMapRoute

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::IMapRoute> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGeoboundingBox*)boundingBox {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingBox(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get());
}

- (double)lengthInMeters {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_LengthInMeters(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)estimatedDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_EstimatedDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WDGGeopath*)path {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopath>(unmarshalledReturn.Get());
}

- (NSArray* /* WSMMapRouteLeg* */)legs {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::MapRouteLeg*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Legs(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMMapRouteLeg_create(unmarshalledReturn.Get());
}

- (BOOL)isTrafficBased {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTrafficBased(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSMMapRouteRestrictions)violatedRestrictions {
    ABI::Windows::Services::Maps::MapRouteRestrictions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRoute2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViolatedRestrictions(&unmarshalledReturn));
    return (WSMMapRouteRestrictions)unmarshalledReturn;
}

- (BOOL)hasBlockedRoads {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRoute2>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasBlockedRoads(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSMMapLocationFinderResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WSMMapLocation* */)locations {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::MapLocation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapLocationFinderResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Locations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMMapLocation_create(unmarshalledReturn.Get());
}

- (WSMMapLocationFinderStatus)status {
    ABI::Windows::Services::Maps::MapLocationFinderStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapLocationFinderResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSMMapLocationFinderStatus)unmarshalledReturn;
}

@end

@implementation WSMMapRouteFinderResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSMMapRoute*)route {
    ComPtr<ABI::Windows::Services::Maps::IMapRoute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteFinderResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Route(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMMapRoute>(unmarshalledReturn.Get());
}

- (WSMMapRouteFinderStatus)status {
    ABI::Windows::Services::Maps::MapRouteFinderStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteFinderResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSMMapRouteFinderStatus)unmarshalledReturn;
}

- (NSArray* /* WSMMapRoute* */)alternateRoutes {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::MapRoute*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteFinderResult2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlternateRoutes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMMapRoute_create(unmarshalledReturn.Get());
}

@end

@implementation WSMMapRouteDrivingOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::IMapRouteDrivingOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Services.Maps.MapRouteDrivingOptions").Get(), &out));
    return [_createRtProxy<WSMMapRouteDrivingOptions>(out.Get()) retain];
}

- (unsigned int)maxAlternateRouteCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteDrivingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxAlternateRouteCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxAlternateRouteCount:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteDrivingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxAlternateRouteCount(value));
}

- (id /* double */)initialHeading {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteDrivingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialHeading(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (void)setInitialHeading:(id /* double */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteDrivingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_InitialHeading(BuildNullable<double>(value)));
}

- (WSMMapRouteOptimization)routeOptimization {
    ABI::Windows::Services::Maps::MapRouteOptimization unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteDrivingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_RouteOptimization(&unmarshalledReturn));
    return (WSMMapRouteOptimization)unmarshalledReturn;
}

- (void)setRouteOptimization:(WSMMapRouteOptimization)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteDrivingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_RouteOptimization((ABI::Windows::Services::Maps::MapRouteOptimization)value));
}

- (WSMMapRouteRestrictions)routeRestrictions {
    ABI::Windows::Services::Maps::MapRouteRestrictions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteDrivingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_RouteRestrictions(&unmarshalledReturn));
    return (WSMMapRouteRestrictions)unmarshalledReturn;
}

- (void)setRouteRestrictions:(WSMMapRouteRestrictions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::IMapRouteDrivingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_RouteRestrictions((ABI::Windows::Services::Maps::MapRouteRestrictions)value));
}

@end

@implementation WSMMapLocationFinder

ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderStatics2> WSMIMapLocationFinderStatics2_inst() {
    ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.MapLocationFinder").Get(), &inst));
    return inst;
}

+ (void)findLocationsAtWithAccuracyAsync:(WDGGeopoint*)queryPoint
                                accuracy:(WSMMapLocationDesiredAccuracy)accuracy
                                 success:(void (^)(WSMMapLocationFinderResult*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapLocationFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapLocationFinderStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindLocationsAtWithAccuracyAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(queryPoint).Get(),
                                                   (ABI::Windows::Services::Maps::MapLocationDesiredAccuracy)accuracy,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapLocationFinderResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapLocationFinderResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSMMapLocationFinderResult>(result.Get()));
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

ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderStatics> WSMIMapLocationFinderStatics_inst() {
    ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.MapLocationFinder").Get(), &inst));
    return inst;
}

+ (void)findLocationsAtAsync:(WDGGeopoint*)queryPoint
                     success:(void (^)(WSMMapLocationFinderResult*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapLocationFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapLocationFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindLocationsAtAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(queryPoint).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapLocationFinderResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapLocationFinderResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSMMapLocationFinderResult>(result.Get()));
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

+ (void)findLocationsAsync:(NSString*)searchText
            referencePoint:(WDGGeopoint*)referencePoint
                   success:(void (^)(WSMMapLocationFinderResult*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapLocationFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapLocationFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindLocationsAsync(nsStrToHstr(searchText).Get(),
                                                    _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(referencePoint).Get(),
                                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapLocationFinderResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapLocationFinderResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSMMapLocationFinderResult>(result.Get()));
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

+ (void)findLocationsWithMaxCountAsync:(NSString*)searchText
                        referencePoint:(WDGGeopoint*)referencePoint
                              maxCount:(unsigned int)maxCount
                               success:(void (^)(WSMMapLocationFinderResult*))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapLocationFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapLocationFinderStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindLocationsWithMaxCountAsync(nsStrToHstr(searchText).Get(),
                                                 _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(referencePoint).Get(),
                                                 maxCount,
                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapLocationFinderResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapLocationFinderResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSMMapLocationFinderResult>(result.Get()));
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

@implementation WSMMapRouteFinder

ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderStatics2> WSMIMapRouteFinderStatics2_inst() {
    ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.MapRouteFinder").Get(), &inst));
    return inst;
}

+ (void)getDrivingRouteWithOptionsAsync:(WDGGeopoint*)startPoint
                               endPoint:(WDGGeopoint*)endPoint
                                options:(WSMMapRouteDrivingOptions*)options
                                success:(void (^)(WSMMapRouteFinderResult*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDrivingRouteWithOptionsAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(startPoint).Get(),
                                                  _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(endPoint).Get(),
                                                  _getRtInterface<ABI::Windows::Services::Maps::IMapRouteDrivingOptions>(options).Get(),
                                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderStatics> WSMIMapRouteFinderStatics_inst() {
    ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.MapRouteFinder").Get(), &inst));
    return inst;
}

+ (void)getDrivingRouteAsync:(WDGGeopoint*)startPoint
                    endPoint:(WDGGeopoint*)endPoint
                     success:(void (^)(WSMMapRouteFinderResult*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDrivingRouteAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(startPoint).Get(),
                                                      _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(endPoint).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

+ (void)getDrivingRouteWithOptimizationAsync:(WDGGeopoint*)startPoint
                                    endPoint:(WDGGeopoint*)endPoint
                                optimization:(WSMMapRouteOptimization)optimization
                                     success:(void (^)(WSMMapRouteFinderResult*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDrivingRouteWithOptimizationAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(startPoint).Get(),
                                                       _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(endPoint).Get(),
                                                       (ABI::Windows::Services::Maps::MapRouteOptimization)optimization,
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

+ (void)getDrivingRouteWithOptimizationAndRestrictionsAsync:(WDGGeopoint*)startPoint
                                                   endPoint:(WDGGeopoint*)endPoint
                                               optimization:(WSMMapRouteOptimization)optimization
                                               restrictions:(WSMMapRouteRestrictions)restrictions
                                                    success:(void (^)(WSMMapRouteFinderResult*))success
                                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDrivingRouteWithOptimizationAndRestrictionsAsync(
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(startPoint).Get(),
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(endPoint).Get(),
        (ABI::Windows::Services::Maps::MapRouteOptimization)optimization,
        (ABI::Windows::Services::Maps::MapRouteRestrictions)restrictions,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

+ (void)getDrivingRouteWithOptimizationRestrictionsAndHeadingAsync:(WDGGeopoint*)startPoint
                                                          endPoint:(WDGGeopoint*)endPoint
                                                      optimization:(WSMMapRouteOptimization)optimization
                                                      restrictions:(WSMMapRouteRestrictions)restrictions
                                                  headingInDegrees:(double)headingInDegrees
                                                           success:(void (^)(WSMMapRouteFinderResult*))success
                                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDrivingRouteWithOptimizationRestrictionsAndHeadingAsync(
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(startPoint).Get(),
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(endPoint).Get(),
        (ABI::Windows::Services::Maps::MapRouteOptimization)optimization,
        (ABI::Windows::Services::Maps::MapRouteRestrictions)restrictions,
        headingInDegrees,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

+ (void)getDrivingRouteFromWaypointsAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                  success:(void (^)(WSMMapRouteFinderResult*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDrivingRouteFromWaypointsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                              ABI::Windows::Devices::Geolocation::IGeopoint*>>::type>*>(
            ConvertToIterable<WDGGeopoint,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                                                ABI::Windows::Devices::Geolocation::IGeopoint*>>(wayPoints)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

+ (void)getDrivingRouteFromWaypointsAndOptimizationAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                            optimization:(WSMMapRouteOptimization)optimization
                                                 success:(void (^)(WSMMapRouteFinderResult*))success
                                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDrivingRouteFromWaypointsAndOptimizationAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                              ABI::Windows::Devices::Geolocation::IGeopoint*>>::type>*>(
            ConvertToIterable<WDGGeopoint,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                                                ABI::Windows::Devices::Geolocation::IGeopoint*>>(wayPoints)
                .Get()),
        (ABI::Windows::Services::Maps::MapRouteOptimization)optimization,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

+ (void)getDrivingRouteFromWaypointsOptimizationAndRestrictionsAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                                        optimization:(WSMMapRouteOptimization)optimization
                                                        restrictions:(WSMMapRouteRestrictions)restrictions
                                                             success:(void (^)(WSMMapRouteFinderResult*))success
                                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDrivingRouteFromWaypointsOptimizationAndRestrictionsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                              ABI::Windows::Devices::Geolocation::IGeopoint*>>::type>*>(
            ConvertToIterable<WDGGeopoint,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                                                ABI::Windows::Devices::Geolocation::IGeopoint*>>(wayPoints)
                .Get()),
        (ABI::Windows::Services::Maps::MapRouteOptimization)optimization,
        (ABI::Windows::Services::Maps::MapRouteRestrictions)restrictions,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

+ (void)getDrivingRouteFromWaypointsOptimizationRestrictionsAndHeadingAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                                               optimization:(WSMMapRouteOptimization)optimization
                                                               restrictions:(WSMMapRouteRestrictions)restrictions
                                                           headingInDegrees:(double)headingInDegrees
                                                                    success:(void (^)(WSMMapRouteFinderResult*))success
                                                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDrivingRouteFromWaypointsOptimizationRestrictionsAndHeadingAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                              ABI::Windows::Devices::Geolocation::IGeopoint*>>::type>*>(
            ConvertToIterable<WDGGeopoint,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                                                ABI::Windows::Devices::Geolocation::IGeopoint*>>(wayPoints)
                .Get()),
        (ABI::Windows::Services::Maps::MapRouteOptimization)optimization,
        (ABI::Windows::Services::Maps::MapRouteRestrictions)restrictions,
        headingInDegrees,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

+ (void)getWalkingRouteAsync:(WDGGeopoint*)startPoint
                    endPoint:(WDGGeopoint*)endPoint
                     success:(void (^)(WSMMapRouteFinderResult*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetWalkingRouteAsync(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(startPoint).Get(),
                                                      _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(endPoint).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

+ (void)getWalkingRouteFromWaypointsAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                  success:(void (^)(WSMMapRouteFinderResult*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>> unmarshalledReturn;
    auto _comInst = WSMIMapRouteFinderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetWalkingRouteFromWaypointsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                              ABI::Windows::Devices::Geolocation::IGeopoint*>>::type>*>(
            ConvertToIterable<WDGGeopoint,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::Geolocation::Geopoint*,
                                                                                ABI::Windows::Devices::Geolocation::IGeopoint*>>(wayPoints)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Services::Maps::MapRouteFinderResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Services::Maps::MapRouteFinderResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSMMapRouteFinderResult>(result.Get()));
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

@implementation WSMMapService

ComPtr<ABI::Windows::Services::Maps::IMapServiceStatics3> WSMIMapServiceStatics3_inst() {
    ComPtr<ABI::Windows::Services::Maps::IMapServiceStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.MapService").Get(), &inst));
    return inst;
}

+ (NSString*)dataAttributions {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMIMapServiceStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_DataAttributions(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Services::Maps::IMapServiceStatics> WSMIMapServiceStatics_inst() {
    ComPtr<ABI::Windows::Services::Maps::IMapServiceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.MapService").Get(), &inst));
    return inst;
}

+ (void)setServiceToken:(NSString*)value {
    auto _comInst = WSMIMapServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_ServiceToken(nsStrToHstr(value).Get()));
}

+ (NSString*)serviceToken {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMIMapServiceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ServiceToken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Services::Maps::IMapServiceStatics2> WSMIMapServiceStatics2_inst() {
    ComPtr<ABI::Windows::Services::Maps::IMapServiceStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.MapService").Get(), &inst));
    return inst;
}

+ (NSString*)worldViewRegionCode {
    HSTRING unmarshalledReturn;
    auto _comInst = WSMIMapServiceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_WorldViewRegionCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSMMapManager

ComPtr<ABI::Windows::Services::Maps::IMapManagerStatics> WSMIMapManagerStatics_inst() {
    ComPtr<ABI::Windows::Services::Maps::IMapManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.MapManager").Get(), &inst));
    return inst;
}

+ (void)showDownloadedMapsUI {
    auto _comInst = WSMIMapManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowDownloadedMapsUI());
}

+ (void)showMapsUpdateUI {
    auto _comInst = WSMIMapManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowMapsUpdateUI());
}

@end

id RTProxiedIterableNSArray_WDGGeopoint_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Devices::Geolocation::Geopoint*>,
                                                 RTIterableObj<ABI::Windows::Devices::Geolocation::IGeopoint*,
                                                               IIterable<ABI::Windows::Devices::Geolocation::Geopoint*>,
                                                               WDGGeopoint,
                                                               ABI::Windows::Devices::Geolocation::Geopoint*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSMMapLocation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::MapLocation*>,
                                         RTArrayObj<ABI::Windows::Services::Maps::IMapLocation*,
                                                    IVectorView<ABI::Windows::Services::Maps::MapLocation*>,
                                                    WSMMapLocation,
                                                    ABI::Windows::Services::Maps::MapLocation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSMMapRoute_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::MapRoute*>,
                                         RTArrayObj<ABI::Windows::Services::Maps::IMapRoute*,
                                                    IVectorView<ABI::Windows::Services::Maps::MapRoute*>,
                                                    WSMMapRoute,
                                                    ABI::Windows::Services::Maps::MapRoute*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSMMapRouteLeg_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::MapRouteLeg*>,
                                         RTArrayObj<ABI::Windows::Services::Maps::IMapRouteLeg*,
                                                    IVectorView<ABI::Windows::Services::Maps::MapRouteLeg*>,
                                                    WSMMapRouteLeg,
                                                    ABI::Windows::Services::Maps::MapRouteLeg*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSMMapRouteManeuver_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::MapRouteManeuver*>,
                                         RTArrayObj<ABI::Windows::Services::Maps::IMapRouteManeuver*,
                                                    IVectorView<ABI::Windows::Services::Maps::MapRouteManeuver*>,
                                                    WSMMapRouteManeuver,
                                                    ABI::Windows::Services::Maps::MapRouteManeuver*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
