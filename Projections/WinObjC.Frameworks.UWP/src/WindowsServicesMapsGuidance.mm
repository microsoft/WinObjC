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

// WindowsServicesMapsGuidance.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Services.Maps.Guidance.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsServicesMapsGuidance.h"
#include "WindowsServicesMapsGuidance_priv.h"

@implementation WSMGGuidanceRoadSignpost

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSignpost> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)exitNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSignpost>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)exit {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSignpost>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exit(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUColor*)backgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSignpost>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (WUColor*)foregroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSignpost>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (NSArray* /* NSString * */)exitDirections {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSignpost>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitDirections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSMGGuidanceManeuver

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGeopoint*)startLocation {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartLocation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (int)distanceFromRouteStart {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_DistanceFromRouteStart(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)distanceFromPreviousManeuver {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_DistanceFromPreviousManeuver(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)departureRoadName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_DepartureRoadName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)nextRoadName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextRoadName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)departureShortRoadName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_DepartureShortRoadName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)nextShortRoadName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextShortRoadName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSMGGuidanceManeuverKind)kind {
    ABI::Windows::Services::Maps::Guidance::GuidanceManeuverKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSMGGuidanceManeuverKind)unmarshalledReturn;
}

- (int)startAngle {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)endAngle {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSMGGuidanceRoadSignpost*)roadSignpost {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSignpost> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoadSignpost(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceRoadSignpost>(unmarshalledReturn.Get());
}

- (NSString*)instructionText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstructionText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSMGGuidanceRoute

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRouteStatics> WSMGIGuidanceRouteStatics_inst() {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRouteStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.Guidance.GuidanceRoute").Get(),
                                                       &inst));
    return inst;
}

+ (BOOL)canCreateFromMapRoute:(WSMMapRoute*)mapRoute {
    boolean unmarshalledReturn;
    auto _comInst = WSMGIGuidanceRouteStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CanCreateFromMapRoute(_getRtInterface<ABI::Windows::Services::Maps::IMapRoute>(mapRoute).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WSMGGuidanceRoute*)tryCreateFromMapRoute:(WSMMapRoute*)mapRoute {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute> unmarshalledReturn;
    auto _comInst = WSMGIGuidanceRouteStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryCreateFromMapRoute(_getRtInterface<ABI::Windows::Services::Maps::IMapRoute>(mapRoute).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceRoute>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (int)distance {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Distance(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* WSMGGuidanceManeuver* */)maneuvers {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::Guidance::GuidanceManeuver*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Maneuvers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMGGuidanceManeuver_create(unmarshalledReturn.Get());
}

- (WDGGeoboundingBox*)boundingBox {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBox> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingBox(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoboundingBox>(unmarshalledReturn.Get());
}

- (WDGGeopath*)path {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopath>(unmarshalledReturn.Get());
}

- (NSArray* /* WSMGGuidanceRoadSegment* */)roadSegments {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::Guidance::GuidanceRoadSegment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoadSegments(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMGGuidanceRoadSegment_create(unmarshalledReturn.Get());
}

- (WSMMapRoute*)convertToMapRoute {
    ComPtr<ABI::Windows::Services::Maps::IMapRoute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute>(self);
    THROW_NS_IF_FAILED(_comInst->ConvertToMapRoute(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMMapRoute>(unmarshalledReturn.Get());
}

@end

@implementation WSMGGuidanceMapMatchedCoordinate

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGeopoint*)location {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Location(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopoint>(unmarshalledReturn.Get());
}

- (double)currentHeading {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentHeading(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)currentSpeed {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentSpeed(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isOnStreet {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOnStreet(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSMGGuidanceRoadSegment*)road {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate>(self);
    THROW_NS_IF_FAILED(_comInst->get_Road(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceRoadSegment>(unmarshalledReturn.Get());
}

@end

@implementation WSMGGuidanceLaneInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceLaneInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSMGGuidanceLaneMarkers)laneMarkers {
    ABI::Windows::Services::Maps::Guidance::GuidanceLaneMarkers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceLaneInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_LaneMarkers(&unmarshalledReturn));
    return (WSMGGuidanceLaneMarkers)unmarshalledReturn;
}

- (BOOL)isOnRoute {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceLaneInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOnRoute(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSMGGuidanceUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSMGGuidanceMode)mode {
    ABI::Windows::Services::Maps::Guidance::GuidanceMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WSMGGuidanceMode)unmarshalledReturn;
}

- (WSMGGuidanceManeuver*)nextManeuver {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextManeuver(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceManeuver>(unmarshalledReturn.Get());
}

- (int)nextManeuverDistance {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextManeuverDistance(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSMGGuidanceManeuver*)afterNextManeuver {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AfterNextManeuver(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceManeuver>(unmarshalledReturn.Get());
}

- (int)afterNextManeuverDistance {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AfterNextManeuverDistance(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)distanceToDestination {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DistanceToDestination(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)elapsedDistance {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElapsedDistance(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)elapsedTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElapsedTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)timeToDestination {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeToDestination(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSString*)roadName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoadName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSMGGuidanceRoute*)route {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Route(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceRoute>(unmarshalledReturn.Get());
}

- (WSMGGuidanceMapMatchedCoordinate*)currentLocation {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentLocation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceMapMatchedCoordinate>(unmarshalledReturn.Get());
}

- (BOOL)isNewManeuver {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsNewManeuver(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WSMGGuidanceLaneInfo* */)laneInfo {
    ComPtr<IVectorView<ABI::Windows::Services::Maps::Guidance::GuidanceLaneInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LaneInfo(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSMGGuidanceLaneInfo_create(unmarshalledReturn.Get());
}

@end

@implementation WSMGGuidanceReroutedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceReroutedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSMGGuidanceRoute*)route {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceReroutedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Route(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceRoute>(unmarshalledReturn.Get());
}

@end

@implementation WSMGGuidanceAudioNotificationRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSMGGuidanceAudioNotificationKind)audioNotification {
    ABI::Windows::Services::Maps::Guidance::GuidanceAudioNotificationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioNotification(&unmarshalledReturn));
    return (WSMGGuidanceAudioNotificationKind)unmarshalledReturn;
}

- (NSArray* /* NSString * */)audioFilePaths {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioFilePaths(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)audioText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSMGGuidanceNavigator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics2> WSMGIGuidanceNavigatorStatics2_inst() {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.Guidance.GuidanceNavigator").Get(),
                                                       &inst));
    return inst;
}

+ (BOOL)useAppProvidedVoice {
    boolean unmarshalledReturn;
    auto _comInst = WSMGIGuidanceNavigatorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_UseAppProvidedVoice(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics> WSMGIGuidanceNavigatorStatics_inst() {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigatorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Services.Maps.Guidance.GuidanceNavigator").Get(),
                                                       &inst));
    return inst;
}

+ (WSMGGuidanceNavigator*)getCurrent {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator> unmarshalledReturn;
    auto _comInst = WSMGIGuidanceNavigatorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceNavigator>(unmarshalledReturn.Get());
}

- (void)startNavigating:(WSMGGuidanceRoute*)route {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->StartNavigating(_getRtInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute>(route).Get()));
}

- (void)startSimulating:(WSMGGuidanceRoute*)route speedInMetersPerSecond:(int)speedInMetersPerSecond {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->StartSimulating(_getRtInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoute>(route).Get(),
                                                 speedInMetersPerSecond));
}

- (void)startTracking {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->StartTracking());
}

- (void)pause {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->Pause());
}

- (void)resume {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->Resume());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)repeatLastAudioNotification {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->RepeatLastAudioNotification());
}

- (WSMGGuidanceAudioMeasurementSystem)audioMeasurementSystem {
    ABI::Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioMeasurementSystem(&unmarshalledReturn));
    return (WSMGGuidanceAudioMeasurementSystem)unmarshalledReturn;
}

- (void)setAudioMeasurementSystem:(WSMGGuidanceAudioMeasurementSystem)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioMeasurementSystem((ABI::Windows::Services::Maps::Guidance::GuidanceAudioMeasurementSystem)value));
}

- (WSMGGuidanceAudioNotifications)audioNotifications {
    ABI::Windows::Services::Maps::Guidance::GuidanceAudioNotifications unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioNotifications(&unmarshalledReturn));
    return (WSMGGuidanceAudioNotifications)unmarshalledReturn;
}

- (void)setAudioNotifications:(WSMGGuidanceAudioNotifications)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioNotifications((ABI::Windows::Services::Maps::Guidance::GuidanceAudioNotifications)value));
}

- (EventRegistrationToken)addGuidanceUpdatedEvent:(void (^)(WSMGGuidanceNavigator*, WSMGGuidanceUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->add_GuidanceUpdated(
        Make<ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeGuidanceUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_GuidanceUpdated(token));
}

- (EventRegistrationToken)addDestinationReachedEvent:(void (^)(WSMGGuidanceNavigator*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->add_DestinationReached(
        Make<ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDestinationReachedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DestinationReached(token));
}

- (EventRegistrationToken)addReroutingEvent:(void (^)(WSMGGuidanceNavigator*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Rerouting(Make<ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object>(handler).Get(),
                                &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReroutingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Rerouting(token));
}

- (EventRegistrationToken)addReroutedEvent:(void (^)(WSMGGuidanceNavigator*, WSMGGuidanceReroutedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->add_Rerouted(
        Make<ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceReroutedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReroutedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Rerouted(token));
}

- (EventRegistrationToken)addRerouteFailedEvent:(void (^)(WSMGGuidanceNavigator*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_RerouteFailed(Make<ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object>(handler).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRerouteFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RerouteFailed(token));
}

- (EventRegistrationToken)addUserLocationLostEvent:(void (^)(WSMGGuidanceNavigator*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->add_UserLocationLost(
        Make<ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUserLocationLostEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UserLocationLost(token));
}

- (EventRegistrationToken)addUserLocationRestoredEvent:(void (^)(WSMGGuidanceNavigator*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->add_UserLocationRestored(
        Make<ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUserLocationRestoredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UserLocationRestored(token));
}

- (void)setGuidanceVoice:(int)voiceId voiceFolder:(NSString*)voiceFolder {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->SetGuidanceVoice(voiceId, nsStrToHstr(voiceFolder).Get()));
}

- (void)updateUserLocation:(WDGGeocoordinate*)userLocation {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(
        _comInst->UpdateUserLocation(_getRtInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(userLocation).Get()));
}

- (void)updateUserLocationWithPositionOverride:(WDGGeocoordinate*)userLocation positionOverride:(WDGBasicGeoposition*)positionOverride {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateUserLocationWithPositionOverride(
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeocoordinate>(userLocation).Get(), *[positionOverride internalStruct]));
}

- (EventRegistrationToken)addAudioNotificationRequestedEvent:(void (^)(WSMGGuidanceNavigator*,
                                                                       WSMGGuidanceAudioNotificationRequestedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator2>(self);
    THROW_NS_IF_FAILED(_comInst->add_AudioNotificationRequested(
        Make<
            ITypedEventHandler_Windows_Services_Maps_Guidance_GuidanceNavigator_Windows_Services_Maps_Guidance_GuidanceAudioNotificationRequestedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAudioNotificationRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AudioNotificationRequested(token));
}

- (BOOL)isGuidanceAudioMuted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGuidanceAudioMuted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsGuidanceAudioMuted:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceNavigator2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsGuidanceAudioMuted((boolean)value));
}

@end

@implementation WSMGGuidanceRoadSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)roadName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoadName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)shortRoadName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShortRoadName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (double)speedLimit {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpeedLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)travelTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_TravelTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WDGGeopath*)path {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeopath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeopath>(unmarshalledReturn.Get());
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isHighway {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHighway(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isTunnel {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTunnel(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isTollRoad {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTollRoad(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSMGGuidanceTelemetryCollector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollectorStatics> WSMGIGuidanceTelemetryCollectorStatics_inst() {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollectorStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Services.Maps.Guidance.GuidanceTelemetryCollector").Get(), &inst));
    return inst;
}

+ (WSMGGuidanceTelemetryCollector*)getCurrent {
    ComPtr<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector> unmarshalledReturn;
    auto _comInst = WSMGIGuidanceTelemetryCollectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSMGGuidanceTelemetryCollector>(unmarshalledReturn.Get());
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

- (void)clearLocalData {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector>(self);
    THROW_NS_IF_FAILED(_comInst->ClearLocalData());
}

- (double)speedTrigger {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpeedTrigger(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSpeedTrigger:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpeedTrigger(value));
}

- (int)uploadFrequency {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector>(self);
    THROW_NS_IF_FAILED(_comInst->get_UploadFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setUploadFrequency:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector>(self);
    THROW_NS_IF_FAILED(_comInst->put_UploadFrequency(value));
}

@end

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSMGGuidanceLaneInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::Guidance::GuidanceLaneInfo*>,
                                         RTArrayObj<ABI::Windows::Services::Maps::Guidance::IGuidanceLaneInfo*,
                                                    IVectorView<ABI::Windows::Services::Maps::Guidance::GuidanceLaneInfo*>,
                                                    WSMGGuidanceLaneInfo,
                                                    ABI::Windows::Services::Maps::Guidance::GuidanceLaneInfo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSMGGuidanceManeuver_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::Guidance::GuidanceManeuver*>,
                                         RTArrayObj<ABI::Windows::Services::Maps::Guidance::IGuidanceManeuver*,
                                                    IVectorView<ABI::Windows::Services::Maps::Guidance::GuidanceManeuver*>,
                                                    WSMGGuidanceManeuver,
                                                    ABI::Windows::Services::Maps::Guidance::GuidanceManeuver*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSMGGuidanceRoadSegment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Services::Maps::Guidance::GuidanceRoadSegment*>,
                                         RTArrayObj<ABI::Windows::Services::Maps::Guidance::IGuidanceRoadSegment*,
                                                    IVectorView<ABI::Windows::Services::Maps::Guidance::GuidanceRoadSegment*>,
                                                    WSMGGuidanceRoadSegment,
                                                    ABI::Windows::Services::Maps::Guidance::GuidanceRoadSegment*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
