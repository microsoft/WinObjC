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

// WindowsPerceptionSpatial.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Perception.Spatial.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPerceptionSpatial.h"
#include "WindowsPerceptionSpatial_priv.h"

@implementation WPSSpatialCoordinateSystem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFNMatrix4x4* */)tryGetTransformTo:(WPSSpatialCoordinateSystem*)target {
    ComPtr<IReference<ABI::Windows::Foundation::Numerics::Matrix4x4>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetTransformTo(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(target).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFNMatrix4x4, ABI::Windows::Foundation::Numerics::Matrix4x4>::convert(unmarshalledReturn.Get());
}

@end

@implementation WPSSpatialAnchor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorStatics> WPSISpatialAnchorStatics_inst() {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Perception.Spatial.SpatialAnchor").Get(), &inst));
    return inst;
}

+ (WPSSpatialAnchor*)tryCreateRelativeTo:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchor> unmarshalledReturn;
    auto _comInst = WPSISpatialAnchorStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryCreateRelativeTo(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialAnchor>(unmarshalledReturn.Get());
}

+ (WPSSpatialAnchor*)tryCreateWithPositionRelativeTo:(WPSSpatialCoordinateSystem*)coordinateSystem position:(WFNVector3*)position {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchor> unmarshalledReturn;
    auto _comInst = WPSISpatialAnchorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryCreateWithPositionRelativeTo(
        _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
        *[position internalStruct],
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialAnchor>(unmarshalledReturn.Get());
}

+ (WPSSpatialAnchor*)tryCreateWithPositionAndOrientationRelativeTo:(WPSSpatialCoordinateSystem*)coordinateSystem
                                                          position:(WFNVector3*)position
                                                       orientation:(WFNQuaternion*)orientation {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchor> unmarshalledReturn;
    auto _comInst = WPSISpatialAnchorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryCreateWithPositionAndOrientationRelativeTo(
        _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
        *[position internalStruct],
        *[orientation internalStruct],
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialAnchor>(unmarshalledReturn.Get());
}

- (WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchor>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoordinateSystem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialCoordinateSystem>(unmarshalledReturn.Get());
}

- (WPSSpatialCoordinateSystem*)rawCoordinateSystem {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchor>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawCoordinateSystem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialCoordinateSystem>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addRawCoordinateSystemAdjustedEvent:(void (^)(WPSSpatialAnchor*,
                                                                        WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchor>(self);
    THROW_NS_IF_FAILED(_comInst->add_RawCoordinateSystemAdjusted(
        Make<
            ITypedEventHandler_Windows_Perception_Spatial_SpatialAnchor_Windows_Perception_Spatial_SpatialAnchorRawCoordinateSystemAdjustedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRawCoordinateSystemAdjustedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RawCoordinateSystemAdjusted(cookie));
}

- (BOOL)removedByUser {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchor2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemovedByUser(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WPSSpatialAnchorRawCoordinateSystemAdjustedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNMatrix4x4*)oldRawCoordinateSystemToNewRawCoordinateSystemTransform {
    ABI::Windows::Foundation::Numerics::Matrix4x4 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldRawCoordinateSystemToNewRawCoordinateSystemTransform(&unmarshalledReturn));
    return WFNMatrix4x4_create(unmarshalledReturn);
}

@end

@implementation WPSSpatialAnchorStore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorStore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSDictionary* /* NSString *, WPSSpatialAnchor* */)getAllSavedAnchors {
    ComPtr<IMapView<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchorStore>(self);
    THROW_NS_IF_FAILED(_comInst->GetAllSavedAnchors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WPSSpatialAnchor_create(unmarshalledReturn.Get());
}

- (BOOL)trySave:(NSString*)id anchor:(WPSSpatialAnchor*)anchor {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchorStore>(self);
    THROW_NS_IF_FAILED(_comInst->TrySave(nsStrToHstr(id).Get(),
                                         _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialAnchor>(anchor).Get(),
                                         &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)remove:(NSString*)id {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchorStore>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(nsStrToHstr(id).Get()));
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialAnchorStore>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

@end

@implementation WPSSpatialLocator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocatorStatics> WPSISpatialLocatorStatics_inst() {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocatorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Perception.Spatial.SpatialLocator").Get(), &inst));
    return inst;
}

+ (WPSSpatialLocator*)getDefault {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocator> unmarshalledReturn;
    auto _comInst = WPSISpatialLocatorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialLocator>(unmarshalledReturn.Get());
}

- (WPSSpatialLocatability)locatability {
    ABI::Windows::Perception::Spatial::SpatialLocatability unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->get_Locatability(&unmarshalledReturn));
    return (WPSSpatialLocatability)unmarshalledReturn;
}

- (EventRegistrationToken)addLocatabilityChangedEvent:(void (^)(WPSSpatialLocator*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_LocatabilityChanged(Make<ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_System_Object>(handler).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLocatabilityChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LocatabilityChanged(cookie));
}

- (EventRegistrationToken)addPositionalTrackingDeactivatingEvent:
    (void (^)(WPSSpatialLocator*, WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->add_PositionalTrackingDeactivating(
        Make<
            ITypedEventHandler_Windows_Perception_Spatial_SpatialLocator_Windows_Perception_Spatial_SpatialLocatorPositionalTrackingDeactivatingEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePositionalTrackingDeactivatingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PositionalTrackingDeactivating(cookie));
}

- (WPSSpatialLocation*)tryLocateAtTimestamp:(WPPerceptionTimestamp*)timestamp
                           coordinateSystem:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryLocateAtTimestamp(_getRtInterface<ABI::Windows::Perception::IPerceptionTimestamp>(timestamp).Get(),
                                       _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialLocation>(unmarshalledReturn.Get());
}

- (WPSSpatialLocatorAttachedFrameOfReference*)createAttachedFrameOfReferenceAtCurrentHeading {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAttachedFrameOfReferenceAtCurrentHeading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialLocatorAttachedFrameOfReference>(unmarshalledReturn.Get());
}

- (WPSSpatialLocatorAttachedFrameOfReference*)createAttachedFrameOfReferenceAtCurrentHeadingWithPosition:(WFNVector3*)relativePosition {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAttachedFrameOfReferenceAtCurrentHeadingWithPosition(*[relativePosition internalStruct],
                                                                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialLocatorAttachedFrameOfReference>(unmarshalledReturn.Get());
}

- (WPSSpatialLocatorAttachedFrameOfReference*)
createAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientation:(WFNVector3*)relativePosition
                                                     relativeOrientation:(WFNQuaternion*)relativeOrientation {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientation(*[relativePosition internalStruct],
                                                                                           *[relativeOrientation internalStruct],
                                                                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialLocatorAttachedFrameOfReference>(unmarshalledReturn.Get());
}

- (WPSSpatialLocatorAttachedFrameOfReference*)
createAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientationAndRelativeHeading:(WFNVector3*)relativePosition
                                                                       relativeOrientation:(WFNQuaternion*)relativeOrientation
                                                                  relativeHeadingInRadians:(double)relativeHeadingInRadians {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientationAndRelativeHeading(
        *[relativePosition internalStruct],
        *[relativeOrientation internalStruct],
        relativeHeadingInRadians,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialLocatorAttachedFrameOfReference>(unmarshalledReturn.Get());
}

- (WPSSpatialStationaryFrameOfReference*)createStationaryFrameOfReferenceAtCurrentLocation {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->CreateStationaryFrameOfReferenceAtCurrentLocation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialStationaryFrameOfReference>(unmarshalledReturn.Get());
}

- (WPSSpatialStationaryFrameOfReference*)createStationaryFrameOfReferenceAtCurrentLocationWithPosition:(WFNVector3*)relativePosition {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->CreateStationaryFrameOfReferenceAtCurrentLocationWithPosition(*[relativePosition internalStruct],
                                                                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialStationaryFrameOfReference>(unmarshalledReturn.Get());
}

- (WPSSpatialStationaryFrameOfReference*)
createStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientation:(WFNVector3*)relativePosition
                                                        relativeOrientation:(WFNQuaternion*)relativeOrientation {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientation(*[relativePosition internalStruct],
                                                                                              *[relativeOrientation internalStruct],
                                                                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialStationaryFrameOfReference>(unmarshalledReturn.Get());
}

- (WPSSpatialStationaryFrameOfReference*)
createStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientationAndRelativeHeading:(WFNVector3*)relativePosition
                                                                          relativeOrientation:(WFNQuaternion*)relativeOrientation
                                                                     relativeHeadingInRadians:(double)relativeHeadingInRadians {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocator>(self);
    THROW_NS_IF_FAILED(_comInst->CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientationAndRelativeHeading(
        *[relativePosition internalStruct],
        *[relativeOrientation internalStruct],
        relativeHeadingInRadians,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialStationaryFrameOfReference>(unmarshalledReturn.Get());
}

@end

@implementation WPSSpatialLocatorPositionalTrackingDeactivatingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)canceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Canceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanceled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Canceled((boolean)value));
}

@end

@implementation WPSSpatialLocation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector3*)position {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (WFNQuaternion*)orientation {
    ABI::Windows::Foundation::Numerics::Quaternion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return WFNQuaternion_create(unmarshalledReturn);
}

- (WFNVector3*)absoluteLinearVelocity {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_AbsoluteLinearVelocity(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (WFNVector3*)absoluteLinearAcceleration {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_AbsoluteLinearAcceleration(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (WFNQuaternion*)absoluteAngularVelocity {
    ABI::Windows::Foundation::Numerics::Quaternion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_AbsoluteAngularVelocity(&unmarshalledReturn));
    return WFNQuaternion_create(unmarshalledReturn);
}

- (WFNQuaternion*)absoluteAngularAcceleration {
    ABI::Windows::Foundation::Numerics::Quaternion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_AbsoluteAngularAcceleration(&unmarshalledReturn));
    return WFNQuaternion_create(unmarshalledReturn);
}

@end

@implementation WPSSpatialLocatorAttachedFrameOfReference

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector3*)relativePosition {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativePosition(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setRelativePosition:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelativePosition(*[value internalStruct]));
}

- (WFNQuaternion*)relativeOrientation {
    ABI::Windows::Foundation::Numerics::Quaternion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeOrientation(&unmarshalledReturn));
    return WFNQuaternion_create(unmarshalledReturn);
}

- (void)setRelativeOrientation:(WFNQuaternion*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelativeOrientation(*[value internalStruct]));
}

- (void)adjustHeading:(double)headingOffsetInRadians {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference>(self);
    THROW_NS_IF_FAILED(_comInst->AdjustHeading(headingOffsetInRadians));
}

- (WPSSpatialCoordinateSystem*)getStationaryCoordinateSystemAtTimestamp:(WPPerceptionTimestamp*)timestamp {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetStationaryCoordinateSystemAtTimestamp(_getRtInterface<ABI::Windows::Perception::IPerceptionTimestamp>(timestamp).Get(),
                                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialCoordinateSystem>(unmarshalledReturn.Get());
}

- (id /* double */)tryGetRelativeHeadingAtTimestamp:(WPPerceptionTimestamp*)timestamp {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetRelativeHeadingAtTimestamp(_getRtInterface<ABI::Windows::Perception::IPerceptionTimestamp>(timestamp).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

@end

@implementation WPSSpatialStationaryFrameOfReference

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::ISpatialStationaryFrameOfReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoordinateSystem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialCoordinateSystem>(unmarshalledReturn.Get());
}

@end

@implementation WPSSpatialAnchorManager

ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorManagerStatics> WPSISpatialAnchorManagerStatics_inst() {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Perception.Spatial.SpatialAnchorManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)requestStoreAsyncWithSuccess:(void (^)(WPSSpatialAnchorStore*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::SpatialAnchorStore*>> unmarshalledReturn;
    auto _comInst = WPSISpatialAnchorManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStoreAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Perception::Spatial::SpatialAnchorStore*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::SpatialAnchorStore*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorStore> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPSSpatialAnchorStore>(result.Get()));
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

@implementation WPSSpatialAnchorTransferManager

ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorTransferManagerStatics> WPSISpatialAnchorTransferManagerStatics_inst() {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialAnchorTransferManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Perception.Spatial.SpatialAnchorTransferManager").Get(), &inst));
    return inst;
}

+ (void)tryImportAnchorsAsync:(RTObject<WSSIInputStream>*)stream
                      success:(void (^)(NSDictionary* /* NSString *, WPSSpatialAnchor* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMapView<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*>>
        unmarshalledReturn;
    auto _comInst = WPSISpatialAnchorTransferManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryImportAnchorsAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMapView<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IMapView<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMapView<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSDictionary_NSString_WPSSpatialAnchor_create(result.Get()));
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

+ (void)tryExportAnchorsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, WPSSpatialAnchor* > */)anchors
                       stream:(RTObject<WSSIOutputStream>*)stream
                      success:(void (^)(BOOL))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WPSISpatialAnchorTransferManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryExportAnchorsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            IKeyValuePair<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*,
            IKeyValuePair<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  IKeyValuePair<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*,
                                  IKeyValuePair<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*>,
                              RTProxiedKeyValuePair_NSString_WPSSpatialAnchor_create>(anchors)
                .Get()),
        _getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(stream).Get(),
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

+ (void)requestAccessAsyncWithSuccess:(void (^)(WPSSpatialPerceptionAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::SpatialPerceptionAccessStatus>> unmarshalledReturn;
    auto _comInst = WPSISpatialAnchorTransferManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Perception::Spatial::SpatialPerceptionAccessStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::SpatialPerceptionAccessStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Perception::Spatial::SpatialPerceptionAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WPSSpatialPerceptionAccessStatus)result);
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

@implementation WPSSpatialBoundingVolume

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialBoundingVolume> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Perception::Spatial::ISpatialBoundingVolumeStatics> WPSISpatialBoundingVolumeStatics_inst() {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialBoundingVolumeStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Perception.Spatial.SpatialBoundingVolume").Get(),
                                                       &inst));
    return inst;
}

+ (WPSSpatialBoundingVolume*)fromBox:(WPSSpatialCoordinateSystem*)coordinateSystem box:(WPSSpatialBoundingBox*)box {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialBoundingVolume> unmarshalledReturn;
    auto _comInst = WPSISpatialBoundingVolumeStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromBox(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                          *[box internalStruct],
                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialBoundingVolume>(unmarshalledReturn.Get());
}

+ (WPSSpatialBoundingVolume*)fromOrientedBox:(WPSSpatialCoordinateSystem*)coordinateSystem box:(WPSSpatialBoundingOrientedBox*)box {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialBoundingVolume> unmarshalledReturn;
    auto _comInst = WPSISpatialBoundingVolumeStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromOrientedBox(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                  *[box internalStruct],
                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialBoundingVolume>(unmarshalledReturn.Get());
}

+ (WPSSpatialBoundingVolume*)fromSphere:(WPSSpatialCoordinateSystem*)coordinateSystem sphere:(WPSSpatialBoundingSphere*)sphere {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialBoundingVolume> unmarshalledReturn;
    auto _comInst = WPSISpatialBoundingVolumeStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromSphere(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                             *[sphere internalStruct],
                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialBoundingVolume>(unmarshalledReturn.Get());
}

+ (WPSSpatialBoundingVolume*)fromFrustum:(WPSSpatialCoordinateSystem*)coordinateSystem frustum:(WPSSpatialBoundingFrustum*)frustum {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialBoundingVolume> unmarshalledReturn;
    auto _comInst = WPSISpatialBoundingVolumeStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromFrustum(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                              *[frustum internalStruct],
                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialBoundingVolume>(unmarshalledReturn.Get());
}

@end

@implementation WPSSpatialBoundingFrustum {
    ABI::Windows::Perception::Spatial::SpatialBoundingFrustum structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Perception::Spatial::SpatialBoundingFrustum)s {
    WPSSpatialBoundingFrustum* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Perception::Spatial::SpatialBoundingFrustum*)internalStruct {
    return &structVal;
}
- (WFNPlane*)near {
    return WFNPlane_create(structVal.Near);
}
- (void)setNear:(WFNPlane*)val {
    structVal.Near = *[val internalStruct];
}
- (WFNPlane*)far {
    return WFNPlane_create(structVal.Far);
}
- (void)setFar:(WFNPlane*)val {
    structVal.Far = *[val internalStruct];
}
- (WFNPlane*)right {
    return WFNPlane_create(structVal.Right);
}
- (void)setRight:(WFNPlane*)val {
    structVal.Right = *[val internalStruct];
}
- (WFNPlane*)left {
    return WFNPlane_create(structVal.Left);
}
- (void)setLeft:(WFNPlane*)val {
    structVal.Left = *[val internalStruct];
}
- (WFNPlane*)top {
    return WFNPlane_create(structVal.Top);
}
- (void)setTop:(WFNPlane*)val {
    structVal.Top = *[val internalStruct];
}
- (WFNPlane*)bottom {
    return WFNPlane_create(structVal.Bottom);
}
- (void)setBottom:(WFNPlane*)val {
    structVal.Bottom = *[val internalStruct];
}
@end
@implementation WPSSpatialBoundingBox {
    ABI::Windows::Perception::Spatial::SpatialBoundingBox structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Perception::Spatial::SpatialBoundingBox)s {
    WPSSpatialBoundingBox* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Perception::Spatial::SpatialBoundingBox*)internalStruct {
    return &structVal;
}
- (WFNVector3*)center {
    return WFNVector3_create(structVal.Center);
}
- (void)setCenter:(WFNVector3*)val {
    structVal.Center = *[val internalStruct];
}
- (WFNVector3*)extents {
    return WFNVector3_create(structVal.Extents);
}
- (void)setExtents:(WFNVector3*)val {
    structVal.Extents = *[val internalStruct];
}
@end
@implementation WPSSpatialBoundingOrientedBox {
    ABI::Windows::Perception::Spatial::SpatialBoundingOrientedBox structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Perception::Spatial::SpatialBoundingOrientedBox)s {
    WPSSpatialBoundingOrientedBox* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Perception::Spatial::SpatialBoundingOrientedBox*)internalStruct {
    return &structVal;
}
- (WFNVector3*)center {
    return WFNVector3_create(structVal.Center);
}
- (void)setCenter:(WFNVector3*)val {
    structVal.Center = *[val internalStruct];
}
- (WFNVector3*)extents {
    return WFNVector3_create(structVal.Extents);
}
- (void)setExtents:(WFNVector3*)val {
    structVal.Extents = *[val internalStruct];
}
- (WFNQuaternion*)orientation {
    return WFNQuaternion_create(structVal.Orientation);
}
- (void)setOrientation:(WFNQuaternion*)val {
    structVal.Orientation = *[val internalStruct];
}
@end
@implementation WPSSpatialBoundingSphere {
    ABI::Windows::Perception::Spatial::SpatialBoundingSphere structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Perception::Spatial::SpatialBoundingSphere)s {
    WPSSpatialBoundingSphere* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Perception::Spatial::SpatialBoundingSphere*)internalStruct {
    return &structVal;
}
- (WFNVector3*)center {
    return WFNVector3_create(structVal.Center);
}
- (void)setCenter:(WFNVector3*)val {
    structVal.Center = *[val internalStruct];
}
- (float)radius {
    return structVal.Radius;
}
- (void)setRadius:(float)val {
    structVal.Radius = val;
}
@end
id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_WPSSpatialAnchor_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<IKeyValuePair_HSTRING_Perception_Spatial_SpatialAnchorPtr_Ptr>,
        RTIterableObj<IKeyValuePair_HSTRING_Perception_Spatial_SpatialAnchorPtr_Ptr,
                      IIterable<IKeyValuePair_HSTRING_Perception_Spatial_SpatialAnchorPtr_Ptr>,
                      RTProxiedKeyValuePair,
                      IKeyValuePair_HSTRING_Perception_Spatial_SpatialAnchorPtr_Ptr,
                      RTProxiedKeyValuePair_NSString_WPSSpatialAnchor_create,
                      ConvertToIterable<RTProxiedKeyValuePair,
                                        ABI::Windows::Foundation::Internal::AggregateType<
                                            IKeyValuePair<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*,
                                            IKeyValuePair<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>*>,
                                        RTProxiedKeyValuePair_NSString_WPSSpatialAnchor_create>>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedKeyValuePair_NSString_WPSSpatialAnchor_create(IInspectable* val) {
    std::unique_ptr<KeyValuePairAdapter> adapter =
        std::make_unique<KeyValuePairAdapterObj<RTKeyValuePairObj<HSTRING,
                                                                  HSTRING,
                                                                  ABI::Windows::Perception::Spatial::ISpatialAnchor*,
                                                                  ABI::Windows::Perception::Spatial::SpatialAnchor*,
                                                                  NSString,
                                                                  WPSSpatialAnchor,
                                                                  dummyObjCCreator,
                                                                  dummyObjCCreator>>>();
    return _createRtProxyWithAdapter<RTProxiedKeyValuePair, KeyValuePairAdapter>(val, std::move(adapter));
    ;
}

id RTProxiedNSDictionary_NSString_WPSSpatialAnchor_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>,
                             DictionaryKeyEnumeratorAdapterObj<
                                 RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Perception::Spatial::SpatialAnchor*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          ABI::Windows::Perception::Spatial::SpatialAnchor*,
                                          ABI::Windows::Perception::Spatial::ISpatialAnchor*,
                                          NSString,
                                          WPSSpatialAnchor,
                                          IMapView<HSTRING, ABI::Windows::Perception::Spatial::SpatialAnchor*>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
