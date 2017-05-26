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

// WindowsUIInputSpatial.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Input.Spatial.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIInputSpatial.h"
#include "WindowsUIInputSpatial_priv.h"

@implementation WUISSpatialInteractionSourceLocation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceLocation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFNVector3* */)position {
    ComPtr<IReference<ABI::Windows::Foundation::Numerics::Vector3>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFNVector3, ABI::Windows::Foundation::Numerics::Vector3>::convert(unmarshalledReturn.Get());
}

- (id /* WFNVector3* */)velocity {
    ComPtr<IReference<ABI::Windows::Foundation::Numerics::Vector3>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Velocity(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFNVector3, ABI::Windows::Foundation::Numerics::Vector3>::convert(unmarshalledReturn.Get());
}

- (id /* WFNQuaternion* */)orientation {
    ComPtr<IReference<ABI::Windows::Foundation::Numerics::Quaternion>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceLocation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFNQuaternion, ABI::Windows::Foundation::Numerics::Quaternion>::convert(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialPointerPose

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPoseStatics> WUISISpatialPointerPoseStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPoseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.Spatial.SpatialPointerPose").Get(),
                                                       &inst));
    return inst;
}

+ (WUISSpatialPointerPose*)tryGetAtTimestamp:(WPSSpatialCoordinateSystem*)coordinateSystem timestamp:(WPPerceptionTimestamp*)timestamp {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose> unmarshalledReturn;
    auto _comInst = WUISISpatialPointerPoseStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryGetAtTimestamp(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                    _getRtInterface<ABI::Windows::Perception::IPerceptionTimestamp>(timestamp).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialPointerPose>(unmarshalledReturn.Get());
}

- (WPPerceptionTimestamp*)timestamp {
    ComPtr<ABI::Windows::Perception::IPerceptionTimestamp> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPPerceptionTimestamp>(unmarshalledReturn.Get());
}

- (WPPHeadPose*)head {
    ComPtr<ABI::Windows::Perception::People::IHeadPose> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose>(self);
    THROW_NS_IF_FAILED(_comInst->get_Head(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPPHeadPose>(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialInteractionSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUISSpatialInteractionSourceKind)kind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

@end

@implementation WUISSpatialInteractionSourceProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFNVector3* */)tryGetSourceLossMitigationDirection:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<IReference<ABI::Windows::Foundation::Numerics::Vector3>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceProperties>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetSourceLossMitigationDirection(
        _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
        unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFNVector3, ABI::Windows::Foundation::Numerics::Vector3>::convert(unmarshalledReturn.Get());
}

- (double)sourceLossRisk {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceLossRisk(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUISSpatialInteractionSourceLocation*)tryGetLocation:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceLocation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceProperties>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetLocation(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialInteractionSourceLocation>(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialManipulationDelta

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialManipulationDelta> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector3*)translation {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialManipulationDelta>(self);
    THROW_NS_IF_FAILED(_comInst->get_Translation(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

@end

@implementation WUISSpatialInteractionSourceState

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceState> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSource*)source {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceState>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialInteractionSource>(unmarshalledReturn.Get());
}

- (WUISSpatialInteractionSourceProperties*)properties {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceState>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialInteractionSourceProperties>(unmarshalledReturn.Get());
}

- (BOOL)isPressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceState>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WPPerceptionTimestamp*)timestamp {
    ComPtr<ABI::Windows::Perception::IPerceptionTimestamp> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceState>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPPerceptionTimestamp>(unmarshalledReturn.Get());
}

- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceState>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetPointerPose(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialPointerPose>(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialGestureRecognizer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizerFactory> WUISISpatialGestureRecognizerFactory_inst() {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.Spatial.SpatialGestureRecognizer").Get(),
                                                       &inst));
    return inst;
}

+ (WUISSpatialGestureRecognizer*)make:(WUISSpatialGestureSettings)settings {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer> unmarshalledReturn;
    auto _comInst = WUISISpatialGestureRecognizerFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::UI::Input::Spatial::SpatialGestureSettings)settings, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUISSpatialGestureRecognizer>(unmarshalledReturn.Get()) retain];
}

- (EventRegistrationToken)addRecognitionStartedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                               WUISSpatialRecognitionStartedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_RecognitionStarted(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionStartedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRecognitionStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RecognitionStarted(token));
}

- (EventRegistrationToken)addRecognitionEndedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialRecognitionEndedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_RecognitionEnded(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionEndedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRecognitionEndedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RecognitionEnded(token));
}

- (EventRegistrationToken)addTappedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialTappedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_Tapped(
        Make<ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialTappedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTappedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Tapped(token));
}

- (EventRegistrationToken)addHoldStartedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialHoldStartedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_HoldStarted(
        Make<ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldStartedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHoldStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HoldStarted(token));
}

- (EventRegistrationToken)addHoldCompletedEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialHoldCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_HoldCompleted(
        Make<ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHoldCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HoldCompleted(token));
}

- (EventRegistrationToken)addHoldCanceledEvent:(void (^)(WUISSpatialGestureRecognizer*, WUISSpatialHoldCanceledEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_HoldCanceled(
        Make<ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCanceledEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHoldCanceledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HoldCanceled(token));
}

- (EventRegistrationToken)addManipulationStartedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                WUISSpatialManipulationStartedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationStarted(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationStartedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationStarted(token));
}

- (EventRegistrationToken)addManipulationUpdatedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                WUISSpatialManipulationUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationUpdated(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationUpdated(token));
}

- (EventRegistrationToken)addManipulationCompletedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                  WUISSpatialManipulationCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationCompleted(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationCompleted(token));
}

- (EventRegistrationToken)addManipulationCanceledEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                 WUISSpatialManipulationCanceledEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ManipulationCanceled(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCanceledEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeManipulationCanceledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ManipulationCanceled(token));
}

- (EventRegistrationToken)addNavigationStartedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                              WUISSpatialNavigationStartedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_NavigationStarted(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationStartedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNavigationStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NavigationStarted(token));
}

- (EventRegistrationToken)addNavigationUpdatedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                              WUISSpatialNavigationUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_NavigationUpdated(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNavigationUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NavigationUpdated(token));
}

- (EventRegistrationToken)addNavigationCompletedEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                                WUISSpatialNavigationCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_NavigationCompleted(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNavigationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NavigationCompleted(token));
}

- (EventRegistrationToken)addNavigationCanceledEvent:(void (^)(WUISSpatialGestureRecognizer*,
                                                               WUISSpatialNavigationCanceledEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_NavigationCanceled(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCanceledEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNavigationCanceledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NavigationCanceled(token));
}

- (void)captureInteraction:(WUISSpatialInteraction*)interaction {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(
        _comInst->CaptureInteraction(_getRtInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteraction>(interaction).Get()));
}

- (void)cancelPendingGestures {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->CancelPendingGestures());
}

- (BOOL)trySetGestureSettings:(WUISSpatialGestureSettings)settings {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(
        _comInst->TrySetGestureSettings((ABI::Windows::UI::Input::Spatial::SpatialGestureSettings)settings, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUISSpatialGestureSettings)gestureSettings {
    ABI::Windows::UI::Input::Spatial::SpatialGestureSettings unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_GestureSettings(&unmarshalledReturn));
    return (WUISSpatialGestureSettings)unmarshalledReturn;
}

@end

@implementation WUISSpatialRecognitionStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialRecognitionStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialRecognitionStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialRecognitionStartedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetPointerPose(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialPointerPose>(unmarshalledReturn.Get());
}

- (BOOL)isGesturePossible:(WUISSpatialGestureSettings)gesture {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialRecognitionStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->IsGesturePossible((ABI::Windows::UI::Input::Spatial::SpatialGestureSettings)gesture, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUISSpatialRecognitionEndedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialRecognitionEndedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialRecognitionEndedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

@end

@implementation WUISSpatialTappedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialTappedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialTappedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetPointerPose(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialPointerPose>(unmarshalledReturn.Get());
}

- (unsigned int)tapCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialTappedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TapCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUISSpatialHoldStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialHoldStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialHoldStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialHoldStartedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetPointerPose(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialPointerPose>(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialHoldCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialHoldCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialHoldCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

@end

@implementation WUISSpatialHoldCanceledEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialHoldCanceledEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialHoldCanceledEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

@end

@implementation WUISSpatialManipulationStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialManipulationStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialManipulationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialManipulationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetPointerPose(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialPointerPose>(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialManipulationUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialManipulationUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialManipulationUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WUISSpatialManipulationDelta*)tryGetCumulativeDelta:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialManipulationDelta> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialManipulationUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetCumulativeDelta(
        _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialManipulationDelta>(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialManipulationCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialManipulationCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialManipulationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WUISSpatialManipulationDelta*)tryGetCumulativeDelta:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialManipulationDelta> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialManipulationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetCumulativeDelta(
        _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialManipulationDelta>(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialManipulationCanceledEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialManipulationCanceledEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialManipulationCanceledEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

@end

@implementation WUISSpatialNavigationStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialNavigationStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetPointerPose(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialPointerPose>(unmarshalledReturn.Get());
}

- (BOOL)isNavigatingX {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsNavigatingX(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isNavigatingY {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsNavigatingY(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isNavigatingZ {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsNavigatingZ(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUISSpatialNavigationUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialNavigationUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WFNVector3*)normalizedOffset {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NormalizedOffset(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

@end

@implementation WUISSpatialNavigationCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialNavigationCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WFNVector3*)normalizedOffset {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NormalizedOffset(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

@end

@implementation WUISSpatialNavigationCanceledEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialNavigationCanceledEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialNavigationCanceledEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

@end

@implementation WUISSpatialInteraction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteraction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceState*)sourceState {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceState> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteraction>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceState(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialInteractionSourceState>(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialInteractionManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManagerStatics> WUISISpatialInteractionManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Input.Spatial.SpatialInteractionManager").Get(),
                                                       &inst));
    return inst;
}

+ (WUISSpatialInteractionManager*)getForCurrentView {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager> unmarshalledReturn;
    auto _comInst = WUISISpatialInteractionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialInteractionManager>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addSourceDetectedEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceDetected(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceDetectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceDetected(token));
}

- (EventRegistrationToken)addSourceLostEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceLost(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceLostEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceLost(token));
}

- (EventRegistrationToken)addSourceUpdatedEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceUpdated(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceUpdated(token));
}

- (EventRegistrationToken)addSourcePressedEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourcePressed(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourcePressedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourcePressed(token));
}

- (EventRegistrationToken)addSourceReleasedEvent:(void (^)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceReleased(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceReleasedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceReleased(token));
}

- (EventRegistrationToken)addInteractionDetectedEvent:(void (^)(WUISSpatialInteractionManager*,
                                                                WUISSpatialInteractionDetectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_InteractionDetected(
        Make<
            ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionDetectedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeInteractionDetectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_InteractionDetected(token));
}

- (NSArray* /* WUISSpatialInteractionSourceState* */)getDetectedSourcesAtTimestamp:(WPPerceptionTimestamp*)timeStamp {
    ComPtr<IVectorView<ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceState*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetDetectedSourcesAtTimestamp(_getRtInterface<ABI::Windows::Perception::IPerceptionTimestamp>(timeStamp).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUISSpatialInteractionSourceState_create(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialInteractionSourceEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceState*)state {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceState> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialInteractionSourceState>(unmarshalledReturn.Get());
}

@end

@implementation WUISSpatialInteractionDetectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionDetectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUISSpatialInteractionSourceKind)interactionSourceKind {
    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionDetectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionSourceKind(&unmarshalledReturn));
    return (WUISSpatialInteractionSourceKind)unmarshalledReturn;
}

- (WUISSpatialPointerPose*)tryGetPointerPose:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPose> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionDetectedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetPointerPose(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialPointerPose>(unmarshalledReturn.Get());
}

- (WUISSpatialInteraction*)interaction {
    ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteraction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Input::Spatial::ISpatialInteractionDetectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Interaction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUISSpatialInteraction>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WUISSpatialInteractionSourceState_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceState*>,
                                         RTArrayObj<ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceState*,
                                                    IVectorView<ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceState*>,
                                                    WUISSpatialInteractionSourceState,
                                                    ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceState*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
